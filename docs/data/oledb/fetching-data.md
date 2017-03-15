---
title: "Recuperando dados | Microsoft Docs"
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
  - "dados [C++], buscando"
  - "buscando"
  - "Modelos de consumidor OLE DB [C++], buscando dados"
  - "conjuntos de linhas [C++], buscando"
ms.assetid: b07f747f-9855-4f27-a03d-b1d5b10fa284
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Recuperando dados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Depois que você abre a fonte de dados, a sessão, e os objetos do conjunto de linhas, você pode buscar dados.  Dependendo do tipo de acessador que você está usando, você pode precisar associar colunas.  
  
### Para buscar dados  
  
1.  Abra o conjunto de linhas usando o comando apropriado de **Abrir** .  
  
2.  Se você estiver usando `CManualAccessor`, associe as colunas de saída se ainda não tiver feito isso.  Para associar as colunas, chame `GetColumnInfo`, e criar um acessador com associações, conforme mostrado no seguinte exemplo:  
  
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
  
3.  Grave um loop de `while` para recuperar os dados.  No loop `MoveNext` , chame para avançar o cursor e para testar o valor de retorno em S\_OK, conforme mostrado no seguinte exemplo:  
  
    ```  
    while (rs.MoveNext() == S_OK)  
    {  
        // Add code to fetch data here  
        // If you are not using an auto accessor, call rs.GetData()  
    }  
    ```  
  
4.  Dentro do loop de `while` , você pode buscar os dados de acordo com seu tipo de acessador.  
  
    -   Se você usar a classe de [CAccessor](../Topic/CAccessor%20Class.md) , você deve ter um registro de usuário que contenha os membros de dados.  Você pode acessar os dados usando esses membros de dados, conforme mostrado no seguinte exemplo:  
  
        ```  
        while (rs.MoveNext() == S_OK)  
        {  
            // Use the data members directly. In this case, m_nFooID  
            // is declared in a user record that derives from  
            // CAccessor  
            wsprintf_s("%d", rs.m_nFooID);   
        }  
        ```  
  
    -   Se você usar a classe de `CDynamicAccessor` ou de `CDynamicParameterAccessor` , você pode buscar dados usando as funções `GetValue` acessando e `GetColumn`, conforme mostrado no exemplo a seguir.  Se você quiser determinar o tipo de dados que você está usando, use `GetType`.  
  
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
  
    -   Se você usar `CManualAccessor`, você deve especificar seus próprios membros de dados, associá\-los você mesmo, e acessar diretamente, conforme mostrado no seguinte exemplo:  
  
        ```  
        while (rs.MoveNext() == S_OK)  
        {  
            // Use the data members you specified in the calls to  
            // AddBindEntry.  
  
            wsprintf_s("%s", szFoo);  
        }  
        ```  
  
## Consulte também  
 [Trabalhando com modelos de consumidor de banco de dados OLE](../../data/oledb/working-with-ole-db-consumer-templates.md)