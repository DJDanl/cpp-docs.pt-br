---
title: "Erro do Compilador C2164 | Microsoft Docs"
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
  - "C2164"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2164"
ms.assetid: 55df5024-68a8-45a8-ae6c-e6dba35318a2
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2164
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: função intrínseca não declarada  
  
 Um pragma de `intrinsic` usa uma função não declarados \(só ocorre com **\/Oi**\).  Ou, um dos intrinsics do compilador foi usado sem incluir o arquivo de cabeçalho.  
  
 O seguinte exemplo gera C2164:  
  
```  
// C2164.c  
// compile with: /c  
// processor: x86  
// Uncomment the following line to resolve.  
// #include "xmmintrin.h"  
void b(float *p) {  
   _mm_load_ss(p);   // C2164  
}  
```