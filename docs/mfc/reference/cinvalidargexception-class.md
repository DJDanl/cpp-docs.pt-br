---
title: "Classe de CInvalidArgException | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CInvalidArgException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CInvalidArgException"
ms.assetid: e43d7c67-1157-47f8-817a-804083e8186e
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CInvalidArgException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa uma condição de exceção inválido do argumento.  
  
## Sintaxe  
  
```  
  
class CInvalidArgException : public CSimpleException  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInvalidArgException::CInvalidArgException](../Topic/CInvalidArgException::CInvalidArgException.md)|o construtor.|  
  
## Comentários  
 Um objeto de `CInvalidArgException` representa uma condição de exceção inválido do argumento.  
  
 Para obter mais informações sobre manipulação de exceção, consulte o tópico e [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md)de [classe de CException](../../mfc/reference/cexception-class.md) .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CInvalidArgException`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CSimpleException](../../mfc/reference/csimpleexception-class.md)