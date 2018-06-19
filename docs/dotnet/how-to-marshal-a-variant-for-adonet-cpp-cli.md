---
title: 'Como: marshaling de um VARIANT para ADO.NET (C++ /CLI CLI) | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- VARIANT, marshaling
- ADO.NET [C++], marshaling VARIANT types
- VARIANT
ms.assetid: 67a180a7-5691-48ab-8d85-7f75a68dde91
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: b442dcce2cdde28de8db1610971dd72dba84ab52
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33134422"
---
# <a name="how-to-marshal-a-variant-for-adonet-ccli"></a>Como realizar marshaling de um VARIANT para ADO.NET (C++/CLI)
Demonstra como adicionar um nativo `VARIANT` para um banco de dados e como realizar marshaling de uma <xref:System.Object?displayProperty=fullName> de um banco de dados para um nativo `VARIANT`.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, a classe DatabaseClass é criada para interagir com um ADO.NET <xref:System.Data.DataTable> objeto. Observe que essa classe é um C++ nativo `class` (em comparação com um `ref class` ou `value class`). Isso é necessário porque queremos usar essa classe de código nativo, e você não pode usar os tipos gerenciados em código nativo. Essa classe será compilada para direcionar o CLR, conforme indicado pelo `#pragma managed` diretiva antes da declaração de classe. Para obter mais informações sobre essa diretiva, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).  
  
 Observe o membro privado da classe DatabaseClass: `gcroot<DataTable ^> table`. Como tipos nativos não podem conter tipos gerenciados, o `gcroot` palavra-chave é necessária. Para obter mais informações sobre `gcroot`, consulte [como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).  
  
 O restante do código neste exemplo é o código C++ nativo, conforme indicado pelo `#pragma unmanaged` diretiva anterior `main`. Neste exemplo, estamos criando uma nova instância de DatabaseClass e chamar seus métodos para criar uma tabela e preencher linhas na tabela. Observe que nativo `VARIANT` tipos estão sendo passados como valores para a coluna de banco de dados ObjectCol. Dentro de DatabaseClass, essas `VARIANT` tipos são empacotados para objetos gerenciados, usando a funcionalidade de marshaling encontrada no <xref:System.Runtime.InteropServices?displayProperty=fullName> namespace. Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.GetObjectForNativeVariant%2A> é usado para empacotar um `VARIANT` para um <xref:System.Object>e o método <xref:System.Runtime.InteropServices.Marshal.GetNativeVariantForObject%2A> é usado para empacotar um <xref:System.Object> para um `VARIANT`.  
  
```  
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
  
## <a name="compiling-the-code"></a>Compilando o código  
  
-   Para compilar o código da linha de comando, salve o exemplo de código em um arquivo chamado adonet_marshal_variant.cpp e digite a seguinte instrução:  
  
    ```  
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_variant.cpp  
    ```  
  
## <a name="net-framework-security"></a>Segurança do .NET Framework  
 Para obter informações sobre problemas de segurança que envolvem ADO.NET, consulte [Protegendo aplicativos ADO.NET](/dotnet/framework/data/adonet/securing-ado-net-applications).  
  
## <a name="see-also"></a>Consulte também  
 <xref:System.Runtime.InteropServices>   
 [Acesso a dados usando ADO.NET (C++ /CLI CLI)](../dotnet/data-access-using-adonet-cpp-cli.md)   
 [ADO.NET](/dotnet/framework/data/adonet/index)   
 [Interoperabilidade](http://msdn.microsoft.com/en-us/afcc2e7d-3f32-48d2-8141-1c42acf29084)   
 [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)