---
title: Buscando dados | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- data [C++], fetching
- rowsets [C++], fetching
- fetching
- OLE DB consumer templates [C++], fetching data
ms.assetid: b07f747f-9855-4f27-a03d-b1d5b10fa284
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b18847666d4f0f57d23e9b179e3e186a1b3ff736
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fetching-data"></a>Recuperando dados
Depois de abrir a fonte de dados, sessão e objetos de conjunto de linhas, você pode buscar dados. Dependendo do tipo de acessador que você está usando, talvez seja necessário associar colunas.  
  
### <a name="to-fetch-data"></a>Para buscar dados  
  
1.  Abra o conjunto de linhas usando apropriada **abrir** comando.  
  
2.  Se você estiver usando `CManualAccessor`, associar as colunas de saída, se você ainda não tiver feito isso. Para associar as colunas, chame `GetColumnInfo`e, em seguida, crie um acessador com associações, conforme mostrado no exemplo a seguir:  
  
    ```  
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
  
3.  Gravar um `while` loop para recuperar os dados. No loop, chame `MoveNext` para avançar o cursor e testar o valor de retorno com S_OK, conforme mostrado no exemplo a seguir:  
  
    ```  
    while (rs.MoveNext() == S_OK)  
    {  
        // Add code to fetch data here  
        // If you are not using an auto accessor, call rs.GetData()  
    }  
    ```  
  
4.  Dentro de `while` loop, você pode buscar os dados de acordo com seu tipo de acessador.  
  
    -   Se você usar o [CAccessor](../../data/oledb/caccessor-class.md) classe, você deve ter um registro de usuário que contém membros de dados. Você pode acessar seus dados usando os membros de dados, conforme mostrado no exemplo a seguir:  
  
        ```  
        while (rs.MoveNext() == S_OK)  
        {  
            // Use the data members directly. In this case, m_nFooID  
            // is declared in a user record that derives from  
            // CAccessor  
            wsprintf_s("%d", rs.m_nFooID);   
        }  
        ```  
  
    -   Se você usar o `CDynamicAccessor` ou `CDynamicParameterAccessor` classe, você pode buscar dados usando as funções acessa `GetValue` e `GetColumn`, conforme mostrado no exemplo a seguir. Se você quiser determinar o tipo de dados você está usando, use `GetType`.  
  
        ```  
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
  
    -   Se você usar `CManualAccessor`, você deve especificar seus próprios membros de dados, associá-las e acessá-los diretamente, conforme mostrado no exemplo a seguir:  
  
        ```  
        while (rs.MoveNext() == S_OK)  
        {  
            // Use the data members you specified in the calls to  
            // AddBindEntry.  
  
            wsprintf_s("%s", szFoo);  
        }  
        ```  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)