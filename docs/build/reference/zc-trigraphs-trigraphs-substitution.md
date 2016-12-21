---
title: "/Zc:trigraphs (substitui&#231;&#227;o de tr&#237;grafos) | Microsoft Docs"
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
  - "/Zc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "opções de compilador /Zc (C++)"
  - "Opções de compilador de conformidade"
  - "opções de compilador Zc (C++)"
  - "opções de compilador -Zc (C++)"
ms.assetid: e3d6058f-400d-4966-a3aa-800cfdf69cbf
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zc:trigraphs (substitui&#231;&#227;o de tr&#237;grafos)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando **\/Zc:trigraphs** for especificado, o compilador substitui uma sequência de caracteres de trigraph usando um caractere de pontuação correspondente.  Para desativar a substituição de trigraph, especifique **\/Zc:trigraphs\-**.  Por padrão, **\/Zc:trigraphs** está desativado.  
  
## Sintaxe  
  
```  
/Zc:trigraphs[-]  
```  
  
## Comentários  
 Um trigraph consiste em dois pontos consecutivos de interrogação \(?? “"\) seguido por um terceiro caractere exclusivo.  Por exemplo, o compilador substitui “?? \=” trigraph usando “\#” caractere.  Use trigraphs nos arquivos de origem de C que usam um conjunto de caracteres que não contém representações gráficas convenientes para alguns caracteres de pontuação.  
  
 Para obter uma lista de trigraphs C\/C\+\+, e um exemplo que mostra como usar trigraphs, consulte a [Trígrafos](../Topic/Trigraphs.md).  
  
## Consulte também  
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)   
 [Trígrafos](../Topic/Trigraphs.md)