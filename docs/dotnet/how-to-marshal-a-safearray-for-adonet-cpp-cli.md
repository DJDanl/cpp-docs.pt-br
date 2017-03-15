---
title: "Como realizar marshaling de um SAFEARRAY para ADO.NET (C++/CLI) | Microsoft Docs"
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
  - "ADO.NET [C++], realizando marshaling em tipos SAFEARRAY"
  - "SAFEARRAY, marshaling"
ms.assetid: 1034b9d7-ecf1-40f7-a9ee-53180e87a58c
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de um SAFEARRAY para ADO.NET (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Demonstra como adicionar `SAFEARRAY` nativo para um base de dados e como o marshaling uma matriz gerenciado de um base de dados a `SAFEARRAY`nativo.  
  
## Exemplo  
 Neste exemplo, a classe DatabaseClass é criada para interagir com um objeto do ADO.NET <xref:System.Data.DataTable> .  Observe que essa classe é um `class` C\+\+ nativo \(em relação a `ref class` ou a `value class`\).  Isso é necessário porque nós desejamos para usar essa classe de código nativo, e você não pode usar gerenciado em código nativo.  Esta classe será criada para atingir CLR, como é indicado por `#pragma managed` diretivo precedendo a declaração da classe.  Para obter mais informações sobre essa política, consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md).  
  
 Observe o membro particular da classe de DatabaseClass: `gcroot<DataTable ^> table`.  Como os tipos nativos não podem conter tipos gerenciados, a palavra\-chave de `gcroot` é necessário.  Para obter mais informações sobre `gcroot`, consulte: [Como declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).  
  
 O restante do código neste exemplo é código C\+\+ nativo, como é indicado por `#pragma unmanaged``main`acima diretivo.  Neste exemplo, estamos criando uma nova instância de DatabaseClass e estamos chamar os métodos para criar uma tabela e popular algumas linhas na tabela.  Observe que os tipos de `SAFEARRAY` nativos estão sendo passados como valores para a coluna ArrayIntsCol da base de dados.  Dentro de DatabaseClass, esses tipos de `SAFEARRAY` marshaling para objetos gerenciados usando a funcionalidade marshaling localizada no namespace de <xref:System.Runtime.InteropServices?displayProperty=fullName> .  Especificamente, o método <xref:System.Runtime.InteropServices.Marshal.Copy%2A> é usado ao marshaling `SAFEARRAY` a uma matriz de inteiros gerenciado, e o método <xref:System.Runtime.InteropServices.Marshal.Copy%2A> é usado ao marshaling uma matriz de inteiros gerenciado a `SAFEARRAY`.  
  
```  
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
  
  **0 1 2 3 4 5 6 7 8 9**    
## Compilando o código  
  
-   Para compilar o código de linha de comando, salve o exemplo de código em um arquivo chamado adonet\_marshal\_safearray.cpp e digite a seguinte instrução:  
  
    ```  
    cl /clr /FU System.dll /FU System.Data.dll /FU System.Xml.dll adonet_marshal_safearray.cpp  
    ```  
  
## Segurança do .NET Framework  
 Para obter informações sobre problemas de segurança que envolvem o ADO.NET, consulte [Protegendo aplicativos ADO.NET](../Topic/Securing%20ADO.NET%20Applications.md).  
  
## Consulte também  
 <xref:System.Runtime.InteropServices>   
 [Acesso a dados](../dotnet/data-access-using-adonet-cpp-cli.md)   
 [ADO.NET](../Topic/ADO.NET.md)   
 [Interoperability](http://msdn.microsoft.com/pt-br/afcc2e7d-3f32-48d2-8141-1c42acf29084)   
 [Nativo e interoperabilidade .NET](../Topic/Native%20and%20.NET%20Interoperability.md)