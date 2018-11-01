---
title: Recuperando dados
ms.date: 10/19/2018
helpviewer_keywords:
- data [C++], fetching
- rowsets [C++], fetching
- fetching
- OLE DB consumer templates [C++], fetching data
ms.assetid: b07f747f-9855-4f27-a03d-b1d5b10fa284
ms.openlocfilehash: 441f036d1677806e81bc419ec6a45e810e63a34f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50651903"
---
# <a name="fetching-data"></a>Recuperando dados

Depois de abrir a fonte de dados, sessão e objetos de conjunto de linhas, você pode buscar dados. Dependendo do tipo de acessador que você está usando, você precisará associar colunas.

## <a name="to-fetch-data"></a>Para buscar dados

1. Abra o conjunto de linhas usando apropriado **abrir** comando.

1. Se você estiver usando `CManualAccessor`, associar as colunas de saída, se você ainda não fez isso. O exemplo a seguir é retirado do [DBViewer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/dbviewer) exemplo. Para associar as colunas, chame `GetColumnInfo`e, em seguida, crie um acessador com as associações, conforme mostrado no exemplo a seguir:

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

1. Gravar uma **enquanto** loop para recuperar os dados. No loop, chame `MoveNext` para avançar o cursor e testar o valor de retorno com S_OK, conforme mostrado no exemplo a seguir:

    ```cpp
    while (rs.MoveNext() == S_OK)
    {
        // Add code to fetch data here
        // If you are not using an auto accessor, call rs.GetData()
    }
    ```

1. Dentro de **enquanto** loop, você pode buscar os dados de acordo com seu tipo de acessador.

   - Se você usar o [CAccessor](../../data/oledb/caccessor-class.md) classe, você deve ter um registro de usuário que contém membros de dados. Você pode acessar seus dados usando os membros de dados, conforme mostrado no exemplo a seguir:

        ```cpp
        while (rs.MoveNext() == S_OK)
        {
            // Use the data members directly. In this case, m_nFooID
            // is declared in a user record that derives from
            // CAccessor
            wsprintf_s("%d", rs.m_nFooID);
        }
        ```

   - Se você usar o `CDynamicAccessor` ou `CDynamicParameterAccessor` classe, você pode buscar dados usando as funções de acesso `GetValue` e `GetColumn`, conforme mostrado no exemplo a seguir. Se você quiser determinar o tipo de dados você está usando, use `GetType`.

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

   - Se você usar `CManualAccessor`, você deve especificar seus próprios membros de dados, ligá-los e acessá-los diretamente, conforme mostrado no exemplo a seguir:

        ```cpp
        while (rs.MoveNext() == S_OK)
        {
            // Use the data members you specified in the calls to
            // AddBindEntry.

            wsprintf_s("%s", szFoo);
        }
        ```

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)
