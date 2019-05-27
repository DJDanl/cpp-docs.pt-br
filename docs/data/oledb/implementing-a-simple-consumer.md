---
title: Implementando um consumidor simples
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB consumers, implementing
ms.assetid: 13828167-23a4-4e94-8b6c-878262fda464
ms.openlocfilehash: 67bce55a19a2aaaf3a8cbb62d7db228513e93c91
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707526"
---
# <a name="implementing-a-simple-consumer"></a>Implementando um consumidor simples

::: moniker range="vs-2019"

O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente. Saiba mais em [Criação de um consumidor sem usar um assistente](creating-a-consumer-without-using-a-wizard.md).

::: moniker-end

::: moniker range="<=vs-2017"

Os tópicos a seguir mostram como editar os arquivos criados pelo **Assistente para Aplicativo do MFC** e **Assistente de Cliente OLE DB da ATL** para criar um consumidor simples. Este exemplo tem as seguintes partes:

- [Recuperação de dados com o consumidor](#retrieve) mostra como implementar o código no consumidor que lê todos os dados, linha por linha, de uma tabela de banco de dados.

- [Adição de suporte a indicadores ao consumidor](#bookmark) mostra como adicionar suporte a indicadores ao consumidor.

> [!NOTE]
> O aplicativo do consumidor descrito nesta seção pode ser usado para testar a amostra de provedores `MyProv` e `Provider`.

> [!NOTE]
> Para criar um aplicativo de consumidor para teste `MyProv` (o mesmo provedor descrito em [Melhoria do provedor simples somente leitura](../../data/oledb/enhancing-the-simple-read-only-provider.md)), você deve incluir suporte a indicadores, conforme descrito em [Adição de suporte a indicadores ao consumidor](#bookmark).

## <a name="retrieve" ></a> Recuperação de dados com o consumidor

### <a name="to-modify-the-console-application-to-use-the-ole-db-consumer"></a>Para modificar o aplicativo de console para usar o consumidor do OLE DB

1. Em `MyCons.cpp`, altere o código principal inserindo o texto em negrito da seguinte maneira:

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

## <a name="bookmark" ></a> Adição de suporte a indicadores ao consumidor

Um indicador é uma coluna que identifica exclusivamente linhas na tabela. Geralmente, é a coluna de chave, mas nem sempre; ela é específica do provedor. Esta seção mostra como adicionar suporte a indicadores. Para fazer isso, siga as etapas abaixo na classe de registro do usuário:

- Crie uma instância de indicadores. Esses são objetos do tipo [CBookmark](../../data/oledb/cbookmark-class.md).

- Solicite uma coluna de indicadores do provedor configurando a propriedade `DBPROP_IRowsetLocate`.

- Adicione uma entrada de indicador ao mapa de coluna usando a macro [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).

As etapas anteriores dão suporte a indicadores e a um objeto de indicador com o qual trabalhar. Este exemplo de código demonstra um indicador da seguinte maneira:

- Abra um arquivo para gravação.

- Gere dados do conjunto de linhas para o arquivo linha por linha.

- Mova o cursor do conjunto de linhas para o indicador chamando [MoveToBookmark](../../data/oledb/crowset-movetobookmark.md).

- Gere a linha marcada com indicador, acrescendo-a ao fim do arquivo.

> [!NOTE]
> Se você usar esse aplicativo de consumidor para testar a amostra de aplicativo do provedor `Provider`, omita o suporte a indicadores descrito nesta seção.

### <a name="to-instantiate-the-bookmark"></a>Criação de uma instância do indicador

1. O acessador precisa manter um objeto do tipo [CBookmark](../../data/oledb/cbookmark-class.md). O parâmetro *nSize* especifica o tamanho do buffer de indicadores em bytes (normalmente 4 para plataformas de 32 bits e 8 para plataformas de 64 bits). Adicione a seguinte declaração aos membros de dados da coluna na classe de registro do usuário:

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

### <a name="to-request-a-bookmark-column-from-the-provider"></a>Solicitação de uma coluna de indicadores do provedor

1. Adicione o seguinte código ao método `GetRowsetProperties` da classe de registro do usuário:

    ```cpp
    // Set the DBPROP_IRowsetLocate property.
    void GetRowsetProperties(CDBPropSet* pPropSet)
    {
       pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
       pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
       // Add DBPROP_IRowsetLocate property to support bookmarks   pPropSet->AddProperty(DBPROP_IRowsetLocate, true);
    }
    ```

### <a name="to-add-a-bookmark-entry-to-the-column-map"></a>Adição de uma entrada de indicador ao mapa de coluna

1. Adicione a seguinte entrada ao mapa de coluna na classe de registro do usuário:

    ```cpp
    // Set a bookmark entry in the column map.
    BEGIN_COLUMN_MAP(CProductsAccessor)
       BOOKMARK_ENTRY(m_bookmark)   // Add bookmark entry
       COLUMN_ENTRY_LENGTH_STATUS(1, m_ProductID, m_dwProductIDLength, m_dwProductIDStatus)
       COLUMN_ENTRY_LENGTH_STATUS(2, m_ProductName, m_dwProductNameLength, m_dwProductNameStatus)
    ...
    END_COLUMN_MAP()
    ```

### <a name="to-use-a-bookmark-in-your-main-code"></a>Uso de um indicador em seu código principal

1. No arquivo `MyCons.cpp` do aplicativo de console anteriormente criado, altere o código principal para ler como se segue. Para usar indicadores, o código principal precisa criar uma instância de seu próprio objeto de indicador (`myBookmark`); esse é um indicador diferente daquele no acessador (`m_bookmark`).

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

Saiba mais sobre os indicadores em [Uso de indicadores](../../data/oledb/using-bookmarks.md). Exemplos de indicadores também são mostrados em [Atualizando conjuntos de linhas](../../data/oledb/updating-rowsets.md).

::: moniker-end

## <a name="see-also"></a>Consulte também

[Criando um consumidor do OLE DB usando um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)
