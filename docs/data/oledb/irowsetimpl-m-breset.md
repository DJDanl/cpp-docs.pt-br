---
title: "IRowsetImpl::m_bReset | Microsoft Docs"
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
  - "ATL.IRowsetImpl.m_bReset"
  - "IRowsetImpl.m_bReset"
  - "m_bReset"
  - "IRowsetImpl::m_bReset"
  - "ATL::IRowsetImpl::m_bReset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "m_bReset"
ms.assetid: d423f9f3-4d48-4d0c-b152-684c81a0b34e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetImpl::m_bReset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um sinalizador de bit usado para determinar se a posição do cursor é definida no conjunto de linhas.  
  
## Sintaxe  
  
```  
  
unsigned m_bReset:1;  
  
```  
  
## Comentários  
 Se o consumidor chama [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) com `lOffset` negativo ou *os corvos* e `m_bReset` são true, `GetNextRows` passa para o final do conjunto de linhas.  Se `m_bReset` for false, o consumidor recebe um código de erro, de acordo com a especificação OLE DB.  O sinalizador de `m_bReset` obtém o conjunto a **true** quando o conjunto de linhas é criado e quando o consumidor chama [IRowsetImpl::RestartPosition](../../data/oledb/irowsetimpl-restartposition.md).  Obtém o conjunto a **false** quando você chama `GetNextRows`.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetImpl](../Topic/IRowsetImpl%20Class.md)