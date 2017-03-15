---
title: "Usando um conjunto de registros ADO existente | Microsoft Docs"
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
  - "Conjuntos de registros ADO [C++]"
  - "Modelos de consumidor OLE DB, Conjunto de registros ADO"
  - "conjunto de registros [C++], usando em OLE DB"
ms.assetid: a9b1de8a-d379-49b1-a26e-578741e9f6a8
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando um conjunto de registros ADO existente
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para mesclar modelos do consumidor OLE DB e objetos de dados ativos \(ADO\), usa ADO para abrir um conjunto de registros \(que corresponde a um conjunto de linhas em modelos do consumidor OLE DB\).  Quando você tem um conjunto de registros, faça o seguinte para se conectar ao OLE DB um conjunto de linhas:  
  
1.  Chame `QueryInterface` para os ponteiros de `IRowset` e de `IAccessor` .  
  
    ```  
    IRowset* lpRowset = NULL;  
    IAccessor* lpAccessor = NULL;  
    lpUnk->QueryInterface(IID_IRowset, (void**)&lpRowset);  
    lpUnk->QueryInterface(IID_IAccessor, (void**)&lpAccessor);  
    ```  
  
    > [!NOTE]
    >  pontos*de lpUnk* ao objeto de **IUnknown** do conjunto de registros ADO.  
  
2.  Anexe o acessador e o conjunto de linhas em suas classes apropriadas do modelo do consumidor OLE DB.  
  
    ```  
    CRowset rs;  
    CAccessor accessor;  
  
    accessor.AddAccessorInfo(0ul);      // 0 is the ordinal of an ADO accessor  
    rs.m_spRowset.Attach(lpRowset);      // use the Attach method of CComPtr<>  
    rs.SetAccessor(accessor);  
    ```  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)