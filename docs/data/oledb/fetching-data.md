---
title: Buscar dados
ms.date: 10/19/2018
helpviewer_keywords:
- data [C++], fetching
- rowsets [C++], fetching
- fetching
- OLE DB consumer templates [C++], fetching data
ms.assetid: b07f747f-9855-4f27-a03d-b1d5b10fa284
ms.openlocfilehash: 919eb059f5d3f29d491bf7a6598b0c77163bd783
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87184638"
---
# <a name="fetching-data"></a>Buscar dados

Depois de abrir a fonte de dados, a sessão e os objetos de conjunto de linhas, você pode buscar dados. Dependendo do tipo de acessador que você estiver usando, talvez seja necessário associar colunas.

## <a name="to-fetch-data"></a>Para buscar dados

1. Abra o conjunto de linhas usando o comando **abrir** apropriado.

1. Se você estiver usando `CManualAccessor` o, associe as colunas de saída se ainda não tiver feito isso. O exemplo a seguir é extraído do exemplo [DBViewer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/dbviewer) . Para associar as colunas, chame `GetColumnInfo` e, em seguida, crie um acessador com as associações, conforme mostrado no exemplo a seguir:

    ```cpp
    // From the DBViewer Sample CDBTreeView::OnQueryEdit
    // Get the column information
    ULONG ulColumns       = 0;
    DBCOLUMNINFO* pColumnInfo  = NULL;
    LPOLESTR pStrings      = NULL;
    if (rs.GetColumnInfo(&ulColumns, &pColumnInfo, &pStrings) != S_OK)
        ThrowMyOLEDBException(rs.m_pRowset, IID_IColumnsInfo);
    struct MYBIND* pBind = new MYBIND[ulColumns];
    rs.CreateAccessor(ulColumns, &pBind[0], sizeof(MYBIND)*ulColumns);
    for (ULONG l=0; l<ulColumns; l++)
    rs.AddBindEntry(l+1, DBTYPE_STR, sizeof(TCHAR)*40, &pBind[l].szValue, NULL, &pBind[l].dwStatus);
    rs.Bind();
    ```

1. Escreva um **`while`** loop para recuperar os dados. No loop, chame `MoveNext` para avançar o cursor e teste o valor de retorno em relação a S_OK, conforme mostrado no exemplo a seguir:

    ```cpp
    while (rs.MoveNext() == S_OK)
    {
        // Add code to fetch data here
        // If you are not using an auto accessor, call rs.GetData()
    }
    ```

1. Dentro do **`while`** loop, você pode buscar os dados de acordo com o tipo de acessador.

   - Se você usar a classe [CAccessor](../../data/oledb/caccessor-class.md) , deverá ter um registro de usuário que contenha membros de dados. Você pode acessar seus dados usando esses membros de dados, conforme mostrado no exemplo a seguir:

        ```cpp
        while (rs.MoveNext() == S_OK)
        {
            // Use the data members directly. In this case, m_nFooID
            // is declared in a user record that derives from
            // CAccessor
            wsprintf_s("%d", rs.m_nFooID);
        }
        ```

   - Se você usar a `CDynamicAccessor` `CDynamicParameterAccessor` classe ou, poderá buscar dados usando as funções de acesso `GetValue` e `GetColumn` , conforme mostrado no exemplo a seguir. Se você quiser determinar o tipo de dados que está usando, use `GetType` .

        ```cpp
        while (rs.MoveNext() == S_OK)
        {
            // Use the dynamic accessor functions to retrieve your data.

            ULONG ulColumns = rs.GetColumnCount();
            for (ULONG i=0; i<ulColumns; i++)
            {
                rs.GetValue(i);
            }
        }
        ```

   - Se você usar `CManualAccessor` o, deverá especificar seus próprios membros de dados, associá-los por conta própria e acessá-los diretamente, conforme mostrado no exemplo a seguir:

        ```cpp
        while (rs.MoveNext() == S_OK)
        {
            // Use the data members you specified in the calls to
            // AddBindEntry.

            wsprintf_s("%s", szFoo);
        }
        ```

## <a name="see-also"></a>Confira também

[Trabalhando com modelos de consumidor OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)
