---
title: "Classe de CMemoryException | Microsoft Docs"
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
  - "CMemoryException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Manipulação de exceção C++, memória"
  - "Classe de CMemoryException"
  - "exceções, tipo de memória"
  - "exceções de memória"
  - "memória, tratamento de exceção"
ms.assetid: 9af0ed57-d12a-45ca-82b5-c910a60f7edf
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMemoryException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma condição de exceção de para fora de memória.  
  
## Sintaxe  
  
```  
class CMemoryException : public CSimpleException  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMemoryException::CMemoryException](../Topic/CMemoryException::CMemoryException.md)|Constrói um objeto de `CMemoryException` .|  
  
## Comentários  
 Nenhuma restrição adicional é necessária ou possível.  Exceções de memória são geradas automaticamente por **new**.  Se você criar suas próprias funções de memória, usando `malloc`, por exemplo, o é responsável por lançar exceções de memória.  
  
 Para obter mais informações sobre `CMemoryException`, consulte o artigo [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CMemoryException`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)