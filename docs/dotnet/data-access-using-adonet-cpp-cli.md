---
title: Acesso a dados usando ADO.NET (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- ADO.NET [C++]
- .NET Framework [C++], data access
- databases [C++], accessing in C++
- data access [C++], ADO.NET
- data [C++], ADO.NET
- native strings [C++]
- ADO.NET [C++], marshaling ANSI strings
- strings [C++], ADO.NET
- BSTRs, strings
- ADO.NET [C++], marshaling BSTR strings
- strings [C++], marshaling BSTR strings
- ADO.NET [C++], marshaling Unicode strings
- Unicode [C++], strings
- strings [C++], Unicode
- VARIANT, marshaling
- ADO.NET [C++], marshaling VARIANT types
- VARIANT
- SAFEARRAY, marshaling
- ADO.NET [C++], marshaling SAFEARRAY types
ms.assetid: b0cd987d-1ea7-4f76-ba01-cbd52503d06d
ms.openlocfilehash: 3f3980c98890382e77d9d89db2944bebf7b12319
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211054"
---
# <a name="data-access-using-adonet-ccli"></a>Acesso a dados usando ADO.NET (C++/CLI)

O ADO.NET é a API de .NET Framework para acesso a dados e fornece energia e facilidade de uso sem igual nas soluções de acesso a dados anteriores. Esta seção descreve alguns dos problemas que envolvem ADO.NET que são exclusivos para Visual C++ usuários, como o empacotamento de tipos nativos.

O ADO.NET é executado no CLR (Common Language Runtime). Portanto, qualquer aplicativo que interage com ADO.NET também deve ter como alvo o CLR. No entanto, isso não significa que os aplicativos nativos não podem usar ADO.NET. Esses exemplos demonstram como interagir com um banco de dados ADO.NET do código nativo.

## <a name="marshal-ansi-strings-for-adonet"></a><a name="marshal_ansi"></a>Empacotar cadeias de caracteres ANSI para ADO.NET

Demonstra como adicionar uma cadeia de caracteres nativa ( `char *` ) a um banco de dados e como realizar marshaling de um <xref:System.String?displayProperty=fullName> de um banco de dados para uma cadeia de caracteres nativa.

### <a name="example"></a>Exemplo

Neste exemplo, a classe DatabaseClass é criada para interagir com um objeto ADO.NET <xref:System.Data.DataTable> . Observe que essa classe é um C++ nativo **`class`** (em comparação a um **`ref class`** ou **`value class`** ). Isso é necessário porque queremos usar essa classe do código nativo e você não pode usar tipos gerenciados em código nativo. Essa classe será compilada para direcionar o CLR, como é indicado pela `#pragma managed` diretiva que precede a declaração de classe. Para obter mais informações sobre essa diretiva, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).

Observe o membro privado da classe DatabaseClass: `gcroot<DataTable ^> table` . Como os tipos nativos não podem conter tipos gerenciados, a `gcroot` palavra-chave é necessária. Para obter mais informações sobre `gcroot` o, consulte [como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).

O restante do código neste exemplo é o código C++ nativo, como é indicado pela `#pragma unmanaged` diretiva anterior `main` . Neste exemplo, estamos criando uma nova instância de DatabaseClass e chamando seus métodos para criar uma tabela e preencher algumas linhas na tabela. Observe que as cadeias de caracteres C++ nativas estão sendo passadas como valores para a coluna de banco de dados StringCol. Dentro de DatabaseClass, essas cadeias de caracteres são empacotadas para cadeias de caracteres gerenciadas usando a funcionalidade de marshaling encontrada no <xref:System.Runtime.InteropServices?displayProperty=fullName> namespace. Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.PtrToStringAnsi%2A> é usado para empacotar um `char *` para um <xref:System.String> , e o método <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalAnsi%2A> é usado para realizar marshaling de um <xref:System.String> para um `char *` .

> [!NOTE]
> A memória alocada por <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalAnsi%2A> deve ser desalocada chamando um <xref:System.Runtime.InteropServices.Marshal.FreeHGlobal%2A> ou `GlobalFree` .

```cpp
// adonet_marshal_string_native.cpp
// compile with: /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll
#include <comdef.h>
#include <gcroot.h>
#include <iostream>
using namespace std;

#using <System.Data.dll>
using namespace System;
using namespace System::Data;
using namespace System::Runtime::InteropServices;

#define MAXCOLS 100

#pragma managed
class DatabaseClass
{
public:
    DatabaseClass() : table(nullptr) { }

    void AddRow(char *stringColValue)
    {
        // Add a row to the table.
        DataRow ^row = table->NewRow();
        row["StringCol"] = Marshal::PtrToStringAnsi(
            (IntPtr)stringColValue);
        table->Rows->Add(row);
    }

    void CreateAndPopulateTable()
    {
        // Create a simple DataTable.
        table = gcnew DataTable("SampleTable");

        // Add a column of type String to the table.
        DataColumn ^column1 = gcnew DataColumn("StringCol",
            Type::GetType("System.String"));
        table->Columns->Add(column1);
    }

    int GetValuesForColumn(char *dataColumn, char **values,
        int valuesLength)
    {
        // Marshal the name of the column to a managed
        // String.
        String ^columnStr = Marshal::PtrToStringAnsi(
                (IntPtr)dataColumn);

        // Get all rows in the table.
        array<DataRow ^> ^rows = table->Select();
        int len = rows->Length;
        len = (len > valuesLength) ? valuesLength : len;
        for (int i = 0; i < len; i++)
        {
            // Marshal each column value from a managed string
            // to a char *.
            values[i] = (char *)Marshal::StringToHGlobalAnsi(
                (String ^)rows[i][columnStr]).ToPointer();
        }

        return len;
    }

private:
    // Using gcroot, you can use a managed type in
    // a native class.
    gcroot<DataTable ^> table;
};

#pragma unmanaged
int main()
{
    // Create a table and add a few rows to it.
    DatabaseClass *db = new DatabaseClass();
    db->CreateAndPopulateTable();
    db->AddRow("This is string 1.");
    db->AddRow("This is string 2.");

    // Now retrieve the rows and display their contents.
    char *values[MAXCOLS];
    int len = db->GetValuesForColumn(
        "StringCol", values, MAXCOLS);
    for (int i = 0; i < len; i++)
    {
        cout << "StringCol: " << values[i] << endl;

        // Deallocate the memory allocated using
        // Marshal::StringToHGlobalAnsi.
        GlobalFree(values[i]);
    }

    delete db;

    return 0;
}
```

```Output
StringCol: This is string 1.
StringCol: This is string 2.
```

### <a name="compiling-the-code"></a>Compilando o código

- Para compilar o código da linha de comando, salve o exemplo de código em um arquivo chamado adonet_marshal_string_native. cpp e insira a seguinte instrução:

    ```
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_string_native.cpp
    ```

## <a name="marshal-bstr-strings-for-adonet"></a><a name="marshal_bstr"></a>Empacotar cadeias de caracteres BSTR para ADO.NET

Demonstra como adicionar uma cadeia de caracteres COM ( `BSTR` ) a um banco de dados e como realizar marshaling de um <xref:System.String?displayProperty=fullName> de um banco de dados para um `BSTR` .

### <a name="example"></a>Exemplo

Neste exemplo, a classe DatabaseClass é criada para interagir com um objeto ADO.NET <xref:System.Data.DataTable> . Observe que essa classe é um C++ nativo **`class`** (em comparação a um **`ref class`** ou **`value class`** ). Isso é necessário porque queremos usar essa classe do código nativo e você não pode usar tipos gerenciados em código nativo. Essa classe será compilada para direcionar o CLR, como é indicado pela `#pragma managed` diretiva que precede a declaração de classe. Para obter mais informações sobre essa diretiva, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).

Observe o membro privado da classe DatabaseClass: `gcroot<DataTable ^> table` . Como os tipos nativos não podem conter tipos gerenciados, a `gcroot` palavra-chave é necessária. Para obter mais informações sobre `gcroot` o, consulte [como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).

O restante do código neste exemplo é o código C++ nativo, como é indicado pela `#pragma unmanaged` diretiva anterior `main` . Neste exemplo, estamos criando uma nova instância de DatabaseClass e chamando seus métodos para criar uma tabela e preencher algumas linhas na tabela. Observe que as cadeias de caracteres COM estão sendo passadas como valores para a coluna de banco de dados StringCol. Dentro de DatabaseClass, essas cadeias de caracteres são empacotadas para cadeias de caracteres gerenciadas usando a funcionalidade de marshaling encontrada no <xref:System.Runtime.InteropServices?displayProperty=fullName> namespace. Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.PtrToStringBSTR%2A> é usado para empacotar um `BSTR` para um <xref:System.String> , e o método <xref:System.Runtime.InteropServices.Marshal.StringToBSTR%2A> é usado para realizar marshaling de um <xref:System.String> para um `BSTR` .

> [!NOTE]
> A memória alocada por <xref:System.Runtime.InteropServices.Marshal.StringToBSTR%2A> deve ser desalocada chamando um <xref:System.Runtime.InteropServices.Marshal.FreeBSTR%2A> ou `SysFreeString` .

``` cpp
// adonet_marshal_string_bstr.cpp
// compile with: /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll
#include <comdef.h>
#include <gcroot.h>
#include <iostream>
using namespace std;

#using <System.Data.dll>
using namespace System;
using namespace System::Data;
using namespace System::Runtime::InteropServices;

#define MAXCOLS 100

#pragma managed
class DatabaseClass
{
public:
    DatabaseClass() : table(nullptr) { }

    void AddRow(BSTR stringColValue)
    {
        // Add a row to the table.
        DataRow ^row = table->NewRow();
        row["StringCol"] = Marshal::PtrToStringBSTR(
            (IntPtr)stringColValue);
        table->Rows->Add(row);
    }

    void CreateAndPopulateTable()
    {
        // Create a simple DataTable.
        table = gcnew DataTable("SampleTable");

        // Add a column of type String to the table.
        DataColumn ^column1 = gcnew DataColumn("StringCol",
            Type::GetType("System.String"));
        table->Columns->Add(column1);
    }

    int GetValuesForColumn(BSTR dataColumn, BSTR *values,
        int valuesLength)
    {
        // Marshal the name of the column to a managed
        // String.
        String ^columnStr = Marshal::PtrToStringBSTR(
                (IntPtr)dataColumn);

        // Get all rows in the table.
        array<DataRow ^> ^rows = table->Select();
        int len = rows->Length;
        len = (len > valuesLength) ? valuesLength : len;
        for (int i = 0; i < len; i++)
        {
            // Marshal each column value from a managed string
            // to a BSTR.
            values[i] = (BSTR)Marshal::StringToBSTR(
                (String ^)rows[i][columnStr]).ToPointer();
        }

        return len;
    }

private:
    // Using gcroot, you can use a managed type in
    // a native class.
    gcroot<DataTable ^> table;
};

#pragma unmanaged
int main()
{
    // Create a table and add a few rows to it.
    DatabaseClass *db = new DatabaseClass();
    db->CreateAndPopulateTable();

    BSTR str1 = SysAllocString(L"This is string 1.");
    db->AddRow(str1);

    BSTR str2 = SysAllocString(L"This is string 2.");
    db->AddRow(str2);

    // Now retrieve the rows and display their contents.
    BSTR values[MAXCOLS];
    BSTR str3 = SysAllocString(L"StringCol");
    int len = db->GetValuesForColumn(
        str3, values, MAXCOLS);
    for (int i = 0; i < len; i++)
    {
        wcout << "StringCol: " << values[i] << endl;

        // Deallocate the memory allocated using
        // Marshal::StringToBSTR.
        SysFreeString(values[i]);
    }

    SysFreeString(str1);
    SysFreeString(str2);
    SysFreeString(str3);
    delete db;

    return 0;
}
```

```Output
StringCol: This is string 1.
StringCol: This is string 2.
```

### <a name="compiling-the-code"></a>Compilando o código

- Para compilar o código da linha de comando, salve o exemplo de código em um arquivo chamado adonet_marshal_string_native. cpp e insira a seguinte instrução:

    ```
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_string_native.cpp
    ```

## <a name="marshal-unicode-strings-for-adonet"></a><a name="marshal_unicode"></a>Empacotar cadeias de caracteres Unicode para ADO.NET

Demonstra como adicionar uma cadeia de caracteres Unicode nativa ( `wchar_t *` ) a um banco de dados e como realizar marshaling de um <xref:System.String?displayProperty=fullName> de um banco de dados para uma cadeia de caracteres Unicode nativa.

### <a name="example"></a>Exemplo

Neste exemplo, a classe DatabaseClass é criada para interagir com um objeto ADO.NET <xref:System.Data.DataTable> . Observe que essa classe é um C++ nativo **`class`** (em comparação a um **`ref class`** ou **`value class`** ). Isso é necessário porque queremos usar essa classe do código nativo e você não pode usar tipos gerenciados em código nativo. Essa classe será compilada para direcionar o CLR, como é indicado pela `#pragma managed` diretiva que precede a declaração de classe. Para obter mais informações sobre essa diretiva, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).

Observe o membro privado da classe DatabaseClass: `gcroot<DataTable ^> table` . Como os tipos nativos não podem conter tipos gerenciados, a `gcroot` palavra-chave é necessária. Para obter mais informações sobre `gcroot` o, consulte [como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).

O restante do código neste exemplo é o código C++ nativo, como é indicado pela `#pragma unmanaged` diretiva anterior `main` . Neste exemplo, estamos criando uma nova instância de DatabaseClass e chamando seus métodos para criar uma tabela e preencher algumas linhas na tabela. Observe que as cadeias de caracteres Unicode do C++ estão sendo passadas como valores para a coluna de banco de dados StringCol. Dentro de DatabaseClass, essas cadeias de caracteres são empacotadas para cadeias de caracteres gerenciadas usando a funcionalidade de marshaling encontrada no <xref:System.Runtime.InteropServices?displayProperty=fullName> namespace. Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.PtrToStringUni%2A> é usado para empacotar um `wchar_t *` para um <xref:System.String> , e o método <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalUni%2A> é usado para realizar marshaling de um <xref:System.String> para um `wchar_t *` .

> [!NOTE]
> A memória alocada por <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalUni%2A> deve ser desalocada chamando um <xref:System.Runtime.InteropServices.Marshal.FreeHGlobal%2A> ou `GlobalFree` .

```cpp
// adonet_marshal_string_wide.cpp
// compile with: /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll
#include <comdef.h>
#include <gcroot.h>
#include <iostream>
using namespace std;

#using <System.Data.dll>
using namespace System;
using namespace System::Data;
using namespace System::Runtime::InteropServices;

#define MAXCOLS 100

#pragma managed
class DatabaseClass
{
public:
    DatabaseClass() : table(nullptr) { }

    void AddRow(wchar_t *stringColValue)
    {
        // Add a row to the table.
        DataRow ^row = table->NewRow();
        row["StringCol"] = Marshal::PtrToStringUni(
            (IntPtr)stringColValue);
        table->Rows->Add(row);
    }

    void CreateAndPopulateTable()
    {
        // Create a simple DataTable.
        table = gcnew DataTable("SampleTable");

        // Add a column of type String to the table.
        DataColumn ^column1 = gcnew DataColumn("StringCol",
            Type::GetType("System.String"));
        table->Columns->Add(column1);
    }

    int GetValuesForColumn(wchar_t *dataColumn, wchar_t **values,
        int valuesLength)
    {
        // Marshal the name of the column to a managed
        // String.
        String ^columnStr = Marshal::PtrToStringUni(
                (IntPtr)dataColumn);

        // Get all rows in the table.
        array<DataRow ^> ^rows = table->Select();
        int len = rows->Length;
        len = (len > valuesLength) ? valuesLength : len;
        for (int i = 0; i < len; i++)
        {
            // Marshal each column value from a managed string
            // to a wchar_t *.
            values[i] = (wchar_t *)Marshal::StringToHGlobalUni(
                (String ^)rows[i][columnStr]).ToPointer();
        }

        return len;
    }

private:
    // Using gcroot, you can use a managed type in
    // a native class.
    gcroot<DataTable ^> table;
};

#pragma unmanaged
int main()
{
    // Create a table and add a few rows to it.
    DatabaseClass *db = new DatabaseClass();
    db->CreateAndPopulateTable();
    db->AddRow(L"This is string 1.");
    db->AddRow(L"This is string 2.");

    // Now retrieve the rows and display their contents.
    wchar_t *values[MAXCOLS];
    int len = db->GetValuesForColumn(
        L"StringCol", values, MAXCOLS);
    for (int i = 0; i < len; i++)
    {
        wcout << "StringCol: " << values[i] << endl;

        // Deallocate the memory allocated using
        // Marshal::StringToHGlobalUni.
        GlobalFree(values[i]);
    }

    delete db;

    return 0;
}
```

```Output
StringCol: This is string 1.
StringCol: This is string 2.
```

### <a name="compiling-the-code"></a>Compilando o código

- Para compilar o código da linha de comando, salve o exemplo de código em um arquivo chamado adonet_marshal_string_wide. cpp e insira a seguinte instrução:

    ```
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_string_wide.cpp
    ```

## <a name="marshal-a-variant-for-adonet"></a><a name="marshal_variant"></a>Realizar marshaling de uma variante para ADO.NET

Demonstra como adicionar um nativo `VARIANT` a um banco de dados e como realizar marshaling de um <xref:System.Object?displayProperty=fullName> de um banco de dados para um nativo `VARIANT` .

### <a name="example"></a>Exemplo

Neste exemplo, a classe DatabaseClass é criada para interagir com um objeto ADO.NET <xref:System.Data.DataTable> . Observe que essa classe é um C++ nativo **`class`** (em comparação a um **`ref class`** ou **`value class`** ). Isso é necessário porque queremos usar essa classe do código nativo e você não pode usar tipos gerenciados em código nativo. Essa classe será compilada para direcionar o CLR, como é indicado pela `#pragma managed` diretiva que precede a declaração de classe. Para obter mais informações sobre essa diretiva, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).

Observe o membro privado da classe DatabaseClass: `gcroot<DataTable ^> table` . Como os tipos nativos não podem conter tipos gerenciados, a `gcroot` palavra-chave é necessária. Para obter mais informações sobre `gcroot` o, consulte [como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).

O restante do código neste exemplo é o código C++ nativo, como é indicado pela `#pragma unmanaged` diretiva anterior `main` . Neste exemplo, estamos criando uma nova instância de DatabaseClass e chamando seus métodos para criar uma tabela e preencher algumas linhas na tabela. Observe que `VARIANT` os tipos nativos estão sendo passados como valores para a coluna de banco de dados ObjectCol. Dentro de DatabaseClass, esses `VARIANT` tipos são empacotados para objetos gerenciados usando a funcionalidade de marshaling encontrada no <xref:System.Runtime.InteropServices?displayProperty=fullName> namespace. Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.GetObjectForNativeVariant%2A> é usado para realizar marshaling de um `VARIANT` para um <xref:System.Object> , e o método <xref:System.Runtime.InteropServices.Marshal.GetNativeVariantForObject%2A> é usado para realizar marshaling de um <xref:System.Object> para um `VARIANT` .

```cpp
// adonet_marshal_variant.cpp
// compile with: /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll
#include <comdef.h>
#include <gcroot.h>
#include <iostream>
using namespace std;

#using <System.Data.dll>
using namespace System;
using namespace System::Data;
using namespace System::Runtime::InteropServices;

#define MAXCOLS 100

#pragma managed
class DatabaseClass
{
public:
    DatabaseClass() : table(nullptr) { }

    void AddRow(VARIANT *objectColValue)
    {
        // Add a row to the table.
        DataRow ^row = table->NewRow();
        row["ObjectCol"] = Marshal::GetObjectForNativeVariant(
            IntPtr(objectColValue));
        table->Rows->Add(row);
    }

    void CreateAndPopulateTable()
    {
        // Create a simple DataTable.
        table = gcnew DataTable("SampleTable");

        // Add a column of type String to the table.
        DataColumn ^column1 = gcnew DataColumn("ObjectCol",
            Type::GetType("System.Object"));
        table->Columns->Add(column1);
    }

    int GetValuesForColumn(wchar_t *dataColumn, VARIANT *values,
        int valuesLength)
    {
        // Marshal the name of the column to a managed
        // String.
        String ^columnStr = Marshal::PtrToStringUni(
                (IntPtr)dataColumn);

        // Get all rows in the table.
        array<DataRow ^> ^rows = table->Select();
        int len = rows->Length;
        len = (len > valuesLength) ? valuesLength : len;
        for (int i = 0; i < len; i++)
        {
            // Marshal each column value from a managed object
            // to a VARIANT.
            Marshal::GetNativeVariantForObject(
                rows[i][columnStr], IntPtr(&values[i]));
        }

        return len;
    }

private:
    // Using gcroot, you can use a managed type in
    // a native class.
    gcroot<DataTable ^> table;
};

#pragma unmanaged
int main()
{
    // Create a table and add a few rows to it.
    DatabaseClass *db = new DatabaseClass();
    db->CreateAndPopulateTable();

    BSTR bstr1 = SysAllocString(L"This is a BSTR in a VARIANT.");
    VARIANT v1;
    v1.vt = VT_BSTR;
    v1.bstrVal = bstr1;
    db->AddRow(&v1);

    int i = 42;
    VARIANT v2;
    v2.vt = VT_I4;
    v2.lVal = i;
    db->AddRow(&v2);

    // Now retrieve the rows and display their contents.
    VARIANT values[MAXCOLS];
    int len = db->GetValuesForColumn(
        L"ObjectCol", values, MAXCOLS);
    for (int i = 0; i < len; i++)
    {
        switch (values[i].vt)
        {
            case VT_BSTR:
                wcout << L"ObjectCol: " << values[i].bstrVal << endl;
                break;
            case VT_I4:
                cout << "ObjectCol: " << values[i].lVal << endl;
                break;
            default:
                break;
        }

    }

    SysFreeString(bstr1);
    delete db;

    return 0;
}
```

```Output
ObjectCol: This is a BSTR in a VARIANT.
ObjectCol: 42
```

### <a name="compiling-the-code"></a>Compilando o código

- Para compilar o código da linha de comando, salve o exemplo de código em um arquivo chamado adonet_marshal_variant. cpp e insira a seguinte instrução:

    ```
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_variant.cpp
    ```

## <a name="marshal-a-safearray-for-adonet"></a><a name="marshal_safearray"></a>Empacotar um SAFEARRAY para ADO.NET

Demonstra como adicionar um nativo `SAFEARRAY` a um banco de dados e como realizar marshaling de uma matriz gerenciada de um banco de dados para um nativo `SAFEARRAY` .

### <a name="example"></a>Exemplo

Neste exemplo, a classe DatabaseClass é criada para interagir com um objeto ADO.NET <xref:System.Data.DataTable> . Observe que essa classe é um C++ nativo **`class`** (em comparação a um **`ref class`** ou **`value class`** ). Isso é necessário porque queremos usar essa classe do código nativo e você não pode usar tipos gerenciados em código nativo. Essa classe será compilada para direcionar o CLR, como é indicado pela `#pragma managed` diretiva que precede a declaração de classe. Para obter mais informações sobre essa diretiva, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).

Observe o membro privado da classe DatabaseClass: `gcroot<DataTable ^> table` . Como os tipos nativos não podem conter tipos gerenciados, a `gcroot` palavra-chave é necessária. Para obter mais informações sobre `gcroot` o, consulte [como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).

O restante do código neste exemplo é o código C++ nativo, como é indicado pela `#pragma unmanaged` diretiva anterior `main` . Neste exemplo, estamos criando uma nova instância de DatabaseClass e chamando seus métodos para criar uma tabela e preencher algumas linhas na tabela. Observe que `SAFEARRAY` os tipos nativos estão sendo passados como valores para a coluna de banco de dados ArrayIntsCol. Dentro de DatabaseClass, esses `SAFEARRAY` tipos são empacotados para objetos gerenciados usando a funcionalidade de marshaling encontrada no <xref:System.Runtime.InteropServices?displayProperty=fullName> namespace. Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.Copy%2A> é usado para realizar marshaling de um `SAFEARRAY` para uma matriz gerenciada de inteiros e o método <xref:System.Runtime.InteropServices.Marshal.Copy%2A> é usado para realizar marshaling de uma matriz gerenciada de inteiros para um `SAFEARRAY` .

```cpp
// adonet_marshal_safearray.cpp
// compile with: /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll
#include <comdef.h>
#include <gcroot.h>
#include <iostream>
using namespace std;

#using <System.Data.dll>
using namespace System;
using namespace System::Data;
using namespace System::Runtime::InteropServices;

#define MAXCOLS 100

#pragma managed
class DatabaseClass
{
public:
    DatabaseClass() : table(nullptr) { }

    void AddRow(SAFEARRAY *arrayIntsColValue)
    {
        // Add a row to the table.
        DataRow ^row = table->NewRow();
        int len = arrayIntsColValue->rgsabound[0].cElements;
        array<int> ^arr = gcnew array<int>(len);

        int *pData;
        SafeArrayAccessData(arrayIntsColValue, (void **)&pData);
        Marshal::Copy(IntPtr(pData), arr, 0, len);
        SafeArrayUnaccessData(arrayIntsColValue);

        row["ArrayIntsCol"] = arr;
        table->Rows->Add(row);
    }

    void CreateAndPopulateTable()
    {
        // Create a simple DataTable.
        table = gcnew DataTable("SampleTable");

        // Add a column of type String to the table.
        DataColumn ^column1 = gcnew DataColumn("ArrayIntsCol",
            Type::GetType("System.Int32[]"));
        table->Columns->Add(column1);
    }

    int GetValuesForColumn(wchar_t *dataColumn, SAFEARRAY **values,
        int valuesLength)
    {
        // Marshal the name of the column to a managed
        // String.
        String ^columnStr = Marshal::PtrToStringUni(
                (IntPtr)dataColumn);

        // Get all rows in the table.
        array<DataRow ^> ^rows = table->Select();
        int len = rows->Length;
        len = (len > valuesLength) ? valuesLength : len;
        for (int i = 0; i < len; i++)
        {
            // Marshal each column value from a managed array
            // of Int32s to a SAFEARRAY of type VT_I4.
            values[i] = SafeArrayCreateVector(VT_I4, 0, 10);
            int *pData;
            SafeArrayAccessData(values[i], (void **)&pData);
            Marshal::Copy((array<int> ^)rows[i][columnStr], 0,
                IntPtr(pData), 10);
            SafeArrayUnaccessData(values[i]);
        }

        return len;
    }

private:
    // Using gcroot, you can use a managed type in
    // a native class.
    gcroot<DataTable ^> table;
};

#pragma unmanaged
int main()
{
    // Create a table and add a few rows to it.
    DatabaseClass *db = new DatabaseClass();
    db->CreateAndPopulateTable();

    // Create a standard array.
    int originalArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Create a SAFEARRAY.
    SAFEARRAY *psa;
    psa = SafeArrayCreateVector(VT_I4, 0, 10);

    // Copy the data from the original array to the SAFEARRAY.
    int *pData;
    HRESULT hr = SafeArrayAccessData(psa, (void **)&pData);
    memcpy(pData, &originalArray, 40);
    SafeArrayUnaccessData(psa);
    db->AddRow(psa);

    // Now retrieve the rows and display their contents.
    SAFEARRAY *values[MAXCOLS];
    int len = db->GetValuesForColumn(
        L"ArrayIntsCol", values, MAXCOLS);
    for (int i = 0; i < len; i++)
    {
        int *pData;
        SafeArrayAccessData(values[i], (void **)&pData);
        for (int j = 0; j < 10; j++)
        {
            cout << pData[j] << " ";
        }
        cout << endl;
        SafeArrayUnaccessData(values[i]);

        // Deallocate the memory allocated using
        // SafeArrayCreateVector.
        SafeArrayDestroy(values[i]);
    }

    SafeArrayDestroy(psa);
    delete db;

    return 0;
}
```

```Output
0 1 2 3 4 5 6 7 8 9
```

### <a name="compiling-the-code"></a>Compilando o código

- Para compilar o código da linha de comando, salve o exemplo de código em um arquivo chamado adonet_marshal_safearray. cpp e insira a seguinte instrução:

    ```
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_safearray.cpp
    ```

## <a name="net-framework-security"></a>Segurança do .NET Framework

Para obter informações sobre problemas de segurança que envolvem ADO.NET, consulte [protegendo aplicativos ADO.net](/dotnet/framework/data/adonet/securing-ado-net-applications).

## <a name="related-sections"></a>Seções relacionadas

|Seção|Descrição|
|-------------|-----------------|
|[ADO.NET](/dotnet/framework/data/adonet/index)|Fornece uma visão geral do ADO.NET, um conjunto de classes que expõe serviços de acesso a dados para o programador do .NET.|

## <a name="see-also"></a>Confira também

[Programação .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)

[Interoperabilidade entre nativo e .NET](../dotnet/native-and-dotnet-interoperability.md)

<xref:System.Runtime.InteropServices>

[Interoperabilidade](/dotnet/framework/interop/index)
