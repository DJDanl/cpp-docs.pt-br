---
title: "ICommandImpl::m_bCancelWhenExecuting | Microsoft Docs"
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
  - "ICommandImpl::m_bCancelWhenExecuting"
  - "ICommandImpl.m_bCancelWhenExecuting"
  - "ATL::ICommandImpl::m_bCancelWhenExecuting"
  - "m_bCancelWhenExecuting"
  - "ATL.ICommandImpl.m_bCancelWhenExecuting"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "m_bCancelWhenExecuting"
ms.assetid: d7d33e4c-a862-4e6d-a9a1-4400bfe45b88
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ICommandImpl::m_bCancelWhenExecuting
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Indica se o comando pode ser cancelado durante a execução.  
  
## Sintaxe  
  
```  
  
unsigned m_bCancelWhenExecuting:1;  
  
```  
  
## Comentários  
 Opções a **true** \(pode ser cancelado\).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe ICommandImpl](../Topic/ICommandImpl%20Class.md)   
 [ICommandImpl::m\_bCancel](../../data/oledb/icommandimpl-m-bcancel.md)