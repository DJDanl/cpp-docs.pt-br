---
title: "Classe de CResourceException | Microsoft Docs"
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
  - "CResourceException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CResourceException"
  - "exceções, recurso"
  - "atribuição dos recursos de exceção"
  - "exceções de recurso"
  - "recursos [C++], alocando"
ms.assetid: af6ae043-d124-4bfd-b35e-7bb0db67d289
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CResourceException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerado quando as janelas não pode localizar ou atribuir um recurso solicitado.  
  
## Sintaxe  
  
```  
class CResourceException : public CSimpleException  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CResourceException::CResourceException](../Topic/CResourceException::CResourceException.md)|Constrói um objeto de `CResourceException` .|  
  
## Comentários  
 Nenhuma restrição adicional é necessária ou possível.  
  
 Para obter mais informações sobre como usar `CResourceException`, consulte o artigo [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CResourceException`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)