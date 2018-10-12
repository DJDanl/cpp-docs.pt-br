---
title: Implementando um consumidor simples | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- clients, creating
- OLE DB consumers, implementing
ms.assetid: 13828167-23a4-4e94-8b6c-878262fda464
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ce6f57846a0dcad79eead500286525e94c66a8e6
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49162289"
---
# <a name="implementing-a-simple-consumer"></a>Implementando um consumidor simples

Os tópicos a seguir mostram como editar os arquivos criados pelo Assistente de aplicativo do MFC e ATL OLE DB Assistente de consumidor para criar um consumidor simples. Este exemplo tem as seguintes partes:  
  
- "Recuperação de dados com o consumidor" mostra como implementar o código no consumidor que lê todos os dados, linha por linha, de uma tabela de banco de dados.  
  
- "Adicionando suporte de indicador para o consumidor" mostra como adicionar suporte a indicadores para o consumidor.  
  
- "Adicionando suporte a XML para o consumidor" mostra como modificar o código de consumidor para os dados recuperados do conjunto de linhas como dados XML de saída.  
  
> [!NOTE]
> Você pode usar o aplicativo do consumidor descrito nesta seção para testar os provedores de exemplo MyProv e provedor.  
  
> [!NOTE]
> Para criar um aplicativo de consumidor para testar MyProv (o mesmo provedor descrito em [melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)), você deve incluir suporte a indicadores, conforme descrito em "Adicionando suporte de indicador para o consumidor".  
  
> [!NOTE]
> Para criar um aplicativo de consumidor para testar o provedor, deixe de fora o suporte a indicadores descrito em "Adicionar indicador dão suporte para o consumidor" e vá para "Adicionando suporte a XML para o consumidor".  
  
## <a name="retrieving-data-with-the-consumer"></a>Recuperando dados com o consumidor  
  
### <a name="to-modify-the-console-application-to-use-the-ole-db-consumer"></a>Para modificar o aplicativo de console para usar o consumidor do OLE DB  
  
1. No MyCons.cpp, altere o código principal inserindo o texto em negrito, da seguinte maneira:  
  
    ```cpp  
    // MyCons.cpp : Defines the entry point for the console application.  
    //  
    #include "stdafx.h"  
    #include "Products.h"  
    ...  
    int main(int argc, char* argv[])  
    {  
       HRESULT hr = CoInitialize(NULL);   // Instantiate rowset   
       CProducts rs;   
       hr = rs.OpenAll();   
       ATLASSERT(SUCCEEDED(hr ) );   
       hr = rs.MoveFirst();   // Iterate through the rowset   
       while(SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )   {      // Print out the column information for each row      
         printf("Product ID: %d, Name: %s, Unit Price: %d, Quantity per Unit: %d, Units in Stock %d, Reorder Level %d\n",             
           rs.m_ProductID, rs.m_ProductName, rs.m_UnitPrice, rs.m_QuantityPerUnit, rs.m_UnitsInStock, rs.m_ReorderLevel );      
         hr = rs.MoveNext();   }   
       rs.Close();   
       rs.ReleaseCommand();   
       CoUninitialize();  
  
       return 0;  
    }  
    ```  
  
## <a name="adding-bookmark-support-to-the-consumer"></a>Adicionando suporte a indicadores ao consumidor  

Um indicador é uma coluna que identifica exclusivamente linhas na tabela. Geralmente é a coluna de chave, mas nem sempre; ele é específico do provedor. Esta seção mostra como adicionar suporte a indicadores. Para fazer isso, você precisa fazer o seguinte na classe de registro de usuário:  
  
- Criar uma instância de indicadores. Esses são objetos do tipo [CBookmark](../../data/oledb/cbookmark-class.md).  
  
- Solicitar uma coluna de indicador do provedor definindo o `DBPROP_IRowsetLocate` propriedade.  
  
- Adicionar uma entrada de indicador no mapa coluna usando o [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md) macro.  
  
As etapas anteriores oferecem suporte a indicadores e um objeto de indicador com o qual trabalhar. Este exemplo de código demonstra um indicador da seguinte maneira:  
  
- Abra um arquivo para gravação.  
  
- Dados do conjunto de linhas de saída para o arquivo linha por linha.  
  
- Mover o cursor de conjunto de linhas para o indicador chamando [MoveToBookmark](../../data/oledb/crowset-movetobookmark.md).  
  
- A linha marcada com indicador, acrescentando-o ao final do arquivo de saída.  
  
> [!NOTE]
> Se você usar esse aplicativo de consumidor para testar o aplicativo de provedor de exemplo do provedor, deixe o suporte a indicadores descrito nesta seção.  
  
### <a name="to-instantiate-the-bookmark"></a>Para instanciar o indicador  
  
1. O acessador deve conter um objeto do tipo [CBookmark](../../data/oledb/cbookmark-class.md). O *nSize* parâmetro especifica o tamanho do buffer indicador em bytes (normalmente 4 para plataformas de 32 bits) e 8 para plataformas de 64 bits. Adicione a seguinte declaração para os membros de dados de coluna na classe de registro de usuário:  
  
    ```cpp  
    //////////////////////////////////////////////////////////////////////  
    // Products.h  
    class CProductsAccessor  
    {  
    public:  
       CBookmark<4> m_bookmark;   // Add bookmark declaration  
       LONG m_ProductID;  
       ...  
    ```  
  
### <a name="to-request-a-bookmark-column-from-the-provider"></a>Para solicitar uma coluna de indicador do provedor  
  
1. Adicione o seguinte código no `GetRowsetProperties` método na classe de registro de usuário:  
  
    ```cpp  
    // Set the DBPROP_IRowsetLocate property.  
    void GetRowsetProperties(CDBPropSet* pPropSet)  
    {  
       pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
       pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
       // Add DBPROP_IRowsetLocate property to support bookmarks   pPropSet->AddProperty(DBPROP_IRowsetLocate, true);  
    }  
    ```  
  
### <a name="to-add-a-bookmark-entry-to-the-column-map"></a>Para adicionar uma entrada de indicador para o mapa de coluna  
  
1. Adicione a seguinte entrada no mapa de coluna na classe de registro de usuário:  
  
    ```cpp  
    // Set a bookmark entry in the column map.  
    BEGIN_COLUMN_MAP(CProductsAccessor)  
       BOOKMARK_ENTRY(m_bookmark)   // Add bookmark entry  
       COLUMN_ENTRY_LENGTH_STATUS(1, m_ProductID, m_dwProductIDLength, m_dwProductIDStatus)  
       COLUMN_ENTRY_LENGTH_STATUS(2, m_ProductName, m_dwProductNameLength, m_dwProductNameStatus)  
    ...  
    END_COLUMN_MAP()  
    ```  
  
### <a name="to-use-a-bookmark-in-your-main-code"></a>Para usar um indicador em seu código principal  
  
1. No arquivo MyCons.cpp do aplicativo de console que você criou anteriormente, altere o código principal para ler o seguinte. Para usar indicadores, o código principal precisa instanciar seu próprio objeto de indicador (`myBookmark`); isso é um indicador diferente no acessador (`m_bookmark`).  
  
    ```cpp  
    ///////////////////////////////////////////////////////////////////////  
    // MyCons.cpp : Defines the entry point for the console application.  
    //  
  
    #include "stdafx.h"  
    #include "Products.h"   
    #include <iostream>  
    #include <fstream>  
    using namespace std;  
  
    int _tmain(int argc, _TCHAR* argv[])  
    {  
       HRESULT hr = CoInitialize(NULL);  
  
       // Instantiate rowset  
       CProducts rs;  
  
       hr = rs.OpenAll();  
       hr = rs.MoveFirst();  
  
       // Cast CURRENCY m_UnitPrice to a long value  
       LONGLONG lPrice = rs.m_UnitPrice.int64;  
  
       // Open file output.txt for writing in overwrite mode  
       ofstream outfile( "C:\\output.txt", ios::out );  
  
       if (!outfile)      // Test for invalid file  
          return -1;  
  
       // Instantiate a bookmark object myBookmark for the main code  
       CBookmark<4> myBookmark;  
       int nCounter = 0;  
  
       // Iterate through the rowset and output column data to output.txt row by row  
       // In the file, mark the beginning of this set of data:  
       outfile << "initial row dump" << endl;  
       while(SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )  
       {  
          nCounter++;  
          if(nCounter == 5 )  
             myBookmark = rs.m_bookmark;  
          // Output the column information for each row:  
          outfile << rs.m_ProductID << rs.m_ProductName << lPrice << rs.m_QuantityPerUnit << rs.m_UnitsInStock << rs.m_ReorderLevel << endl;  
          hr = rs.MoveNext();  
       }  
  
       // Move cursor to bookmark  
       hr = rs.MoveToBookmark(myBookmark);  
  
       // Iterate through the rowset and output column data to output.txt row by row  
       // In the file, mark the beginning of this set of data:  
       outfile << "row dump starting from bookmarked row" << endl;  
       while(SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )  
       {  
          // Output the column information for each row  
          outfile << rs.m_ProductID << rs.m_ProductName << lPrice << rs.m_QuantityPerUnit << rs.m_UnitsInStock << rs.m_ReorderLevel << endl;  
          hr = rs.MoveNext();  
       }  
  
       rs.CloseAll();  
       CoUninitialize();  
  
       return 0;  
    }  
    ```  
  
Para obter mais informações sobre os indicadores, consulte [usando indicadores](../../data/oledb/using-bookmarks.md). Exemplos de indicadores também são mostrados na [atualizando conjuntos de linhas](../../data/oledb/updating-rowsets.md).  
  
## <a name="adding-xml-support-to-the-consumer"></a>Adicionando suporte a XML para o consumidor  

Conforme discutido em [acessando os dados XML](../../data/oledb/accessing-xml-data.md), para recuperar dados XML de uma fonte de dados de duas maneiras: usando [CStreamRowset](../../data/oledb/cstreamrowset-class.md) ou usando [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md). Este exemplo usa `CStreamRowset`, que é mais eficiente, mas exige que você tenha o SQL Server 2000 em execução no computador no qual você executa esse aplicativo de exemplo.  
  
### <a name="to-modify-the-command-class-to-inherit-from-cstreamrowset"></a>Para modificar a classe de comando para herdar de CStreamRowset  
  
1. No aplicativo de consumidor que você criou anteriormente, altere sua `CCommand` declaração para especificar `CStreamRowset` como o conjunto de linhas de classe da seguinte maneira:  
  
    ```cpp  
    class CProducts : public CCommand<CAccessor<CProductsAccessor>, CStreamRowset >  
    ```  
  
### <a name="to-modify-the-main-code-to-retrieve-and-output-the-xml-data"></a>Para modificar o código principal para recuperar e os dados XML de saída  
  
1. No arquivo MyCons.cpp do aplicativo de console que você criou anteriormente, altere o código principal para ler o seguinte:  
  
    ```cpp  
    ///////////////////////////////////////////////////////////////////////  
    // MyCons.cpp : Defines the entry point for the console application.  
    //  
  
    #include "stdafx.h"  
    #include "Products.h"   
    #include <iostream>  
    #include <fstream>  
    using namespace std;  
  
    int _tmain(int argc, _TCHAR* argv[])  
    {  
       HRESULT hr = CoInitialize(NULL);  
  
       // Instantiate rowset  
       CProducts rs;  
  
       // Add variable declarations for the Read method to handle sequential stream data  
       CHAR buffer[1001];  // Pointer to buffer into which data stream is read  
       ULONG cbRead;       // Actual number of bytes read from the data stream  
  
       hr = rs.OpenAll();  
  
       // Open file output.txt for writing in overwrite mode  
       ofstream outfile( "C:\\output.txt", ios::out );  
  
       if (!outfile)      // Test for invalid file  
          return -1;  
  
       // The following loop reads 1000 bytes of the data stream at a time   
       // until it reaches the end of the data stream  
       for (;;)  
       {  
          // Read sequential stream data into buffer  
          HRESULT hr = rs.m_spStream->Read(buffer, 1000, &cbRead);  
          if (FAILED (hr))  
             break;  
          // Output buffer to file  
          buffer[cbRead] = 0;  
          outfile << buffer;  
          // Test for end of data stream  
          if (cbRead < 1000)  
             break;  
       }  
  
       rs.CloseAll();  
       CoUninitialize();  
  
       return 0;  
    }  
    ```  
  
## <a name="see-also"></a>Consulte também  

[Criando um consumidor do OLE DB usando um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)