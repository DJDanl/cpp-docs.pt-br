---
title: 'Como: empacotar cadeias de caracteres Unicode para ADO.NET (C++ /CLI CLI) | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ADO.NET [C++], marshaling Unicode strings
- Unicode [C++], strings
- strings [C++], Unicode
ms.assetid: 1da090ff-6b53-40be-841f-dc79dfe8ba10
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 15cf9e9806c0820ea5a410a93419016c2f678c65
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33137368"
---
# <a name="how-to-marshal-unicode-strings-for-adonet-ccli"></a>Como realizar marshaling de cadeias de caracteres Unicode para ADO.NET (C++/CLI)
Demonstra como adicionar uma cadeia de caracteres Unicode nativo (`wchar_t *`) para um banco de dados e como realizar marshaling de uma <xref:System.String?displayProperty=fullName> de um banco de dados em uma cadeia de caracteres Unicode nativo.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, a classe DatabaseClass é criada para interagir com um ADO.NET <xref:System.Data.DataTable> objeto. Observe que essa classe é um C++ nativo `class` (em comparação com um `ref class` ou `value class`). Isso é necessário porque queremos usar essa classe de código nativo, e você não pode usar os tipos gerenciados em código nativo. Essa classe será compilada para direcionar o CLR, conforme indicado pelo `#pragma managed` diretiva antes da declaração de classe. Para obter mais informações sobre essa diretiva, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).  
  
 Observe o membro privado da classe DatabaseClass: `gcroot<DataTable ^> table`. Como tipos nativos não podem conter tipos gerenciados, o `gcroot` palavra-chave é necessária. Para obter mais informações sobre `gcroot`, consulte [como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).  
  
 O restante do código neste exemplo é o código C++ nativo, conforme indicado pelo `#pragma unmanaged` diretiva anterior `main`. Neste exemplo, estamos criando uma nova instância de DatabaseClass e chamar seus métodos para criar uma tabela e preencher linhas na tabela. Observe que as cadeias de caracteres Unicode C++ estão sendo passadas como valores para a coluna de banco de dados StringCol. Dentro de DatabaseClass, essas cadeias de caracteres são empacotadas em gerenciado cadeias de caracteres usando a funcionalidade de marshaling encontrada no <xref:System.Runtime.InteropServices?displayProperty=fullName> namespace. Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.PtrToStringUni%2A> é usado para empacotar um `wchar_t *` para um <xref:System.String>e o método <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalUni%2A> é usado para empacotar um <xref:System.String> para um `wchar_t *`.  
  
> [!NOTE]
>  A memória alocada por <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalUni%2A> deve ser desalocada chamando <xref:System.Runtime.InteropServices.Marshal.FreeHGlobal%2A> ou `GlobalFree`.  
  
```  
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
  
## <a name="compiling-the-code"></a>Compilando o código  
  
-   Para compilar o código da linha de comando, salve o exemplo de código em um arquivo chamado adonet_marshal_string_wide.cpp e digite a seguinte instrução:  
  
    ```  
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_string_wide.cpp  
    ```  
  
## <a name="net-framework-security"></a>Segurança do .NET Framework  
 Para obter informações sobre problemas de segurança que envolvem ADO.NET, consulte [Protegendo aplicativos ADO.NET](/dotnet/framework/data/adonet/securing-ado-net-applications).  
  
## <a name="see-also"></a>Consulte também  
 <xref:System.Runtime.InteropServices>   
 [Acesso a dados usando ADO.NET (C++ /CLI CLI)](../dotnet/data-access-using-adonet-cpp-cli.md)   
 [ADO.NET](/dotnet/framework/data/adonet/index)   
 [Interoperabilidade](http://msdn.microsoft.com/en-us/afcc2e7d-3f32-48d2-8141-1c42acf29084)   
 [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)