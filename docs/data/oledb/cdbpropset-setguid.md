---
title: "CDBPropSet::SetGUID | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL.CDBPropSet.SetGUID"
  - "CDBPropSet.SetGUID"
  - "ATL::CDBPropSet::SetGUID"
  - "SetGUID"
  - "CDBPropSet::SetGUID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AddProperty"
  - "Método SetGUID"
ms.assetid: a4cce036-cf1f-4897-9712-7b01eaf887ff
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDBPropSet::SetGUID
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o campo de **guidPropertySet** na estrutura de **DBPROPSET** .  
  
## Sintaxe  
  
```  
  
      void SetGUID(   
   const GUID& guid    
) throw( );  
```  
  
#### Parâmetros  
 `guid`  
 \[in\] GUID usado para definir o campo de **guidPropertySet** da estrutura de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) .  
  
## Comentários  
 Esse campo pode ser definido por [construtor](../Topic/CDBPropSet::CDBPropSet.md) também.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDBPropSet](../Topic/CDBPropSet%20Class.md)