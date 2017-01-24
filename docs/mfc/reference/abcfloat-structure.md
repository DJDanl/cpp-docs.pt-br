---
title: "Estrutura ABCFLOAT | Microsoft Docs"
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
  - "ABCFLOAT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura ABCFLOAT"
ms.assetid: 338e7e15-9d2c-42d0-aa80-273acfde5cc5
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura ABCFLOAT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `ABCFLOAT` contém as larguras da, B, c e 2.0 de um caractere da fonte.  
  
## Sintaxe  
  
```  
  
      typedef struct _ABCFLOAT { /* abcf */  
   FLOAT abcfA;  
   FLOAT abcfB;  
   FLOAT abcfC;  
} ABCFLOAT;  
```  
  
#### Parâmetros  
 *abcfA*  
 Especifica o espaçamento do caractere.  Espaçamento de é a distância a ser adicionado à posição atual antes de chamar o glifo do caractere.  
  
 *abcfB*  
 Especifica o espaçamento de B de caractere.  O espaçamento de B é a largura da parte desenhada de glifo de caractere.  
  
 *abcfC*  
 Especifica espaço C de caractere.  Espaço C é a distância a ser adicionado à posição atual fornecer espaço em branco à direita do glifo de caractere.  
  
## Comentários  
 As larguras da, B, c e 2.0 são medidas ao longo da linha de base da fonte.  O incremento de caractere \(largura total\) de um caractere é a soma dos espaços da, B, c e 2.0.  O ou Ao espaço de C podem ser negativo indicar underhangs ou saliências.  
  
## Requisitos  
 **Header:** wingdi.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetCharABCWidths](../Topic/CDC::GetCharABCWidths.md)