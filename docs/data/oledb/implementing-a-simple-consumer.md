---
title: "Implementando um consumidor simples | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "clientes, criando"
  - "Consumidores OLE DB, implementando"
ms.assetid: 13828167-23a4-4e94-8b6c-878262fda464
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando um consumidor simples
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os tópicos a seguir mostram como editar os arquivos criados pelo assistente do assistente de aplicativo MFC e do consumidor de ATL OLE DB para criar um consumidor simples.  Este exemplo tem as seguintes partes:  
  
-   “Recuperando dados com o consumidor” a seguir mostra como implementar o código no consumidor que ler todos os dados, linha por linha, de uma tabela base de dados.  
  
-   “Adicionando suporte do medidor para o consumidor” mostra como adicionar suporte ao medidor para o consumidor.  
  
-   “Adicionando suporte a XML para o consumidor” mostra como alterar o código do consumidor para gerar os dados recuperados do conjunto de linhas como dados XML.  
  
> [!NOTE]
>  Você pode usar o aplicativo do consumidor descrito nesta seção para testar os provedores de exemplo de MyProv e o provedor.  
  
> [!NOTE]
>  Para criar um aplicativo do consumidor testar MyProv \(o mesmo provedor descrito em [Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)\), você deverá incluir suporte do medidor conforme descrito em “adicionar suporte ao medidor para o consumidor.”  
  
> [!NOTE]
>  Para criar um aplicativo do consumidor testar o provedor, deixe do suporte do medidor descrito em “adicionar suporte ao medidor para o consumidor” e “ignore adicionando suporte a XML para o consumidor.”  
  
## Recuperando dados com o consumidor  
  
#### Para alterar o aplicativo de console usar o consumidor OLE DB  
  
1.  Em MyCons.cpp, altere o código principal inserindo o texto em negrito como segue:  
  
    ```  
    // MyCons.cpp : Defines the entry point for the console application.  
    //  
    #include "stdafx.h"  
    #include "Products.h"  
    ...  
    int main(int argc, char* argv[])  
    {  
       HRESULT hr = CoInitialize(NULL);        // Instantiate rowset    CProducts rs;        hr = rs.OpenAll();    ATLASSERT( SUCCEEDED( hr ) );    hr = rs.MoveFirst();        // Iterate through the rowset    while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )    {       // Print out the column information for each row       printf("Product ID: %d, Name: %s, Unit Price: %d, Quantity per Unit: %d, Units in Stock %d, Reorder Level %d\n",              rs.m_ProductID, rs.m_ProductName, rs.m_UnitPrice, rs.m_QuantityPerUnit, rs.m_UnitsInStock, rs.m_ReorderLevel );       hr = rs.MoveNext();    }        rs.Close();    rs.ReleaseCommand();        CoUninitialize();  
  
       return 0;  
    }  
    ```  
  
## Adicionando suporte do medidor para o consumidor  
 Um medidor é uma coluna que identifica exclusivamente linhas na tabela.  Normalmente é a coluna de chave, mas não sempre; é específica do provedor.  Esta seção mostra como adicionar o suporte do medidor.  Para fazer isso, você precisa fazer o seguinte na classe de registro do usuário:  
  
-   Para instanciar os indicadores.  Esses objetos são do tipo [CBookmark](../../data/oledb/cbookmark-class.md).  
  
-   Solicita uma coluna de indicador do provedor definindo a propriedade de **DBPROP\_IRowsetLocate** .  
  
-   Adicione uma entrada do medidor no mapa da coluna usando a macro de [BOOKMARK\_ENTRY](../../data/oledb/bookmark-entry.md) .  
  
 As etapas anteriores oferecem suporte do medidor e um objeto do medidor com a qual trabalhar.  Este exemplo de código a seguir demonstra um indicador como segue:  
  
-   Abrir um arquivo para gravação.  
  
-   Os dados do conjunto de linhas de saída para o arquivo linha por linha.  
  
-   Mova o cursor de conjunto de linhas chamando [MoveToBookmark](../../data/oledb/crowset-movetobookmark.md)ao medidor.  
  
-   Saída a linha com indicador, anexando à o final do arquivo.  
  
> [!NOTE]
>  Se você usar esse aplicativo do consumidor testar o aplicativo do provedor de exemplo do provedor, deixe do suporte do medidor descrito nesta seção.  
  
#### Para criar uma instância do medidor  
  
1.  O acessador precisa conter um objeto de tipo [CBookmark](../../data/oledb/cbookmark-class.md).  O parâmetro de `nSize` especifica o tamanho do buffer do medidor em bytes \(normalmente 4 para plataformas de 32 bits e 8 para plataformas de 64 bits\).  Adicione a seguinte declaração para os membros de dados da coluna na classe de registro do usuário:  
  
    ```  
    //////////////////////////////////////////////////////////////////////  
    // Products.h  
    class CProductsAccessor  
    {  
    public:  
       CBookmark<4> m_bookmark;   // Add bookmark declaration  
       LONG m_ProductID;  
       ...  
    ```  
  
#### Para solicitar uma coluna de indicador do provedor  
  
1.  Adicione o seguinte código no método na classe de `GetRowsetProperties` de registro do usuário:  
  
    ```  
    // Set the DBPROP_IRowsetLocate property.  
    void GetRowsetProperties(CDBPropSet* pPropSet)  
    {  
       pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
       pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
       // Add DBPROP_IRowsetLocate property to support bookmarks    pPropSet->AddProperty(DBPROP_IRowsetLocate, true);  
    }  
    ```  
  
#### Para adicionar uma entrada do medidor no mapa da coluna  
  
1.  Adicione a seguinte entrada para mapa da coluna na classe de registro do usuário:  
  
    ```  
    // Set a bookmark entry in the column map.  
    BEGIN_COLUMN_MAP(CProductsAccessor)  
       BOOKMARK_ENTRY(m_bookmark)   // Add bookmark entry  
       COLUMN_ENTRY_LENGTH_STATUS(1, m_ProductID, m_dwProductIDLength, m_dwProductIDStatus)  
       COLUMN_ENTRY_LENGTH_STATUS(2, m_ProductName, m_dwProductNameLength, m_dwProductNameStatus)  
    ...  
    END_COLUMN_MAP()  
    ```  
  
#### Para usar um indicador em seu código principal  
  
1.  No arquivo de MyCons.cpp do aplicativo de console que você criou anteriormente, altera o código principal para ler a seguinte maneira.  Para usar medidores, as necessidades de código principais de criar uma instância seu próprio objeto do medidor \(`myBookmark`\); este é um indicador diferente de aquele no acessador \(`m_bookmark`\).  
  
    ```  
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
       while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )  
       {  
          nCounter++;  
          if( nCounter == 5 )  
             myBookmark = rs.bookmark;  
          // Output the column information for each row:  
          outfile << rs.m_ProductID << rs.m_ProductName << lPrice << rs.m_QuantityPerUnit << rs.m_UnitsInStock << rs.m_ReorderLevel << endl;  
          hr = rs.MoveNext();  
       }  
  
       // Move cursor to bookmark  
       hr = rs.MoveToBookmark(myBookmark);  
  
       // Iterate through the rowset and output column data to output.txt row by row  
       // In the file, mark the beginning of this set of data:  
       outfile << "row dump starting from bookmarked row" << endl;  
       while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )  
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
  
 Para obter mais informações sobre os indicadores, consulte [Usando indicadores](../../data/oledb/using-bookmarks.md).  Exemplos dos indicadores também são mostradas em [Atualizando conjuntos de linhas](../../data/oledb/updating-rowsets.md).  
  
## Adicionando suporte a XML para o consumidor  
 Como discutido em [Acessando dados XML](../../data/oledb/accessing-xml-data.md), há duas maneiras de recuperar dados XML de uma fonte de dados: usando [CStreamRowset](../../data/oledb/cstreamrowset-class.md) ou o uso de [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md).  Este exemplo usa `CStreamRowset`, que é mais eficiente, mas exige que você tenha o SQL Server 2000 que é executado no computador no qual você executa este aplicativo de exemplo.  
  
#### Para alterar o comando classe para herdar de CStreamRowset  
  
1.  No aplicativo do consumidor que você criou anteriormente, altera sua declaração de `CCommand` para especificar `CStreamRowset` como a classe do conjunto de linhas como segue:  
  
    ```  
    class CProducts : public CCommand<CAccessor<CProductsAccessor>, CStreamRowset >  
    ```  
  
#### Para alterar o código principal para recuperar e gera os dados XML  
  
1.  No arquivo de MyCons.cpp do aplicativo de console que você criou anteriormente, altera o código principal para ler a seguinte maneira:  
  
    ```  
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
  
## Consulte também  
 [Criando um consumidor de banco de dados OLE sem usar um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)