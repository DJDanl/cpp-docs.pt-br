---
title: "Estrutura ABC | Microsoft Docs"
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
  - "ABC"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura ABC"
ms.assetid: 32663839-c3b7-4f47-896c-b15329c96bc8
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura ABC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de **ABC** contém a largura de um caractere em uma fonte de TrueType.  
  
## Sintaxe  
  
```  
  
      typedef struct _ABC { /* abc */  
   int abcA;  
   UINT abcB;  
   int abcC;  
} ABC;  
```  
  
#### Parâmetros  
 *abcA*  
 Especifica o espaçamento do caractere.  Espaçamento de é a distância a ser adicionado à posição atual antes de chamar o glifo do caractere.  
  
 *abcB*  
 Especifica o espaçamento de B de caractere.  O espaçamento de B é a largura da parte desenhada de glifo de caractere.  
  
 *abcC*  
 Especifica espaço C de caractere.  Espaço C é a distância a ser adicionado à posição atual fornecer espaço em branco à direita do glifo de caractere.  
  
## Comentários  
 A largura total de um caractere é a soma dos espaços da, B, c e 2.0.  O ou Ao espaço de C podem ser negativo indicar underhangs ou saliências.  
  
## Requisitos  
 **Header:** wingdi.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetCharABCWidths](../Topic/CDC::GetCharABCWidths.md)