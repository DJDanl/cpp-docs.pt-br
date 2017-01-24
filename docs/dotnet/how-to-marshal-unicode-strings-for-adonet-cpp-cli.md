---
title: "Como realizar marshaling de cadeias de caracteres Unicode para ADO.NET (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ADO.NET [C++], realizando marshaling em cadeias de caracteres Unicode"
  - "cadeias de caracteres [C++], Unicode"
  - "Unicode [C++], cadeias de caracteres"
ms.assetid: 1da090ff-6b53-40be-841f-dc79dfe8ba10
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de cadeias de caracteres Unicode para ADO.NET (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Demonstra como adicionar uma cadeia de caracteres Unicode nativo \(`wchar_t *`\) a um base de dados e como o marshaling <xref:System.String?displayProperty=fullName> de um base de dados a uma cadeia de caracteres Unicode nativo.  
  
## Exemplo  
 Neste exemplo, a classe DatabaseClass é criada para interagir com um objeto do ADO.NET <xref:System.Data.DataTable> .  Observe que essa classe é um `class` C\+\+ nativo \(em relação a `ref class` ou a `value class`\).  Isso é necessário porque nós desejamos para usar essa classe de código nativo, e você não pode usar gerenciado em código nativo.  Esta classe será criada para atingir CLR, como é indicado por `#pragma managed` diretivo precedendo a declaração da classe.  Para obter mais informações sobre essa política, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).  
  
 Observe o membro particular da classe de DatabaseClass: `gcroot<DataTable ^> table`.  Como os tipos nativos não podem conter tipos gerenciados, a palavra\-chave de `gcroot` é necessário.  Para obter mais informações sobre `gcroot`, consulte: [Como declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).  
  
 O restante do código neste exemplo é código C\+\+ nativo, como é indicado por `#pragma unmanaged``main`acima diretivo.  Neste exemplo, estamos criando uma nova instância de DatabaseClass e estamos chamar os métodos para criar uma tabela e popular algumas linhas na tabela.  Observe que as cadeias de caracteres Unicode C\+\+ são transmitidas como valores para a coluna StringCol da base de dados.  Dentro de DatabaseClass, essas cadeias de caracteres marshaling em cadeias de caracteres gerenciados usando a funcionalidade marshaling localizada no namespace de <xref:System.Runtime.InteropServices?displayProperty=fullName> .  Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.PtrToStringUni%2A> é usado ao marshaling `wchar_t *` a <xref:System.String>, e o método <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalUni%2A> é usado ao marshaling <xref:System.String> a `wchar_t *`.  
  
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
  
  **StringCol: Esta é a cadeia de caracteres 1.**  
**StringCol: Esta é a cadeia de caracteres 2.**   
## Compilando o código  
  
-   Para compilar o código de linha de comando, salve o exemplo de código em um arquivo chamado adonet\_marshal\_string\_wide.cpp e digite a seguinte instrução:  
  
    ```  
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_string_wide.cpp  
    ```  
  
## Segurança do .NET Framework  
 Para obter informações sobre problemas de segurança que envolvem o ADO.NET, consulte [Protegendo aplicativos ADO.NET](../Topic/Securing%20ADO.NET%20Applications.md).  
  
## Consulte também  
 <xref:System.Runtime.InteropServices>   
 [Acesso a dados](../dotnet/data-access-using-adonet-cpp-cli.md)   
 [ADO.NET](../Topic/ADO.NET.md)   
 [Interoperability](http://msdn.microsoft.com/pt-br/afcc2e7d-3f32-48d2-8141-1c42acf29084)   
 [Nativo e interoperabilidade .NET](../Topic/Native%20and%20.NET%20Interoperability.md)