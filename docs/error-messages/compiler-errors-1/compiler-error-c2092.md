---
title: "Erro do Compilador C2092 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2092"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2092"
ms.assetid: 037e44ae-16c8-489a-a512-dcdf7f7795a6
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2092
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“do tipo de elemento da matriz de matriz nome” não pode ser função  
  
 As matrizes de funções não são permitidas.  Use uma matriz dos ponteiros às funções.  
  
## Exemplo  
 O seguinte exemplo gera C2092:  
  
```  
// C2092.cpp  
typedef void (F) ();  
typedef F AT[10];   // C2092  
```  
  
## Exemplo  
 Solução possível:  
  
```  
// C2092b.cpp  
// compile with: /c  
typedef void (F) ();  
typedef F * AT[10];  
```