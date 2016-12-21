---
title: "Aviso do compilador (n&#237;vel 1) C4556 | Microsoft Docs"
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
  - "xml"
  - "C4556"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4556"
ms.assetid: e4c0e296-b747-4db1-9608-30b8b74feac2
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4556
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o valor do argumento imediata intrínseco “valor” está fora do intervalo “lowerbound \- upperbound”  
  
 Um intrínseco corresponde a uma instrução de hardware.  A instrução de hardware tiver um número fixo de bit para codificar a constante.  Se ***value*** está fora do intervalo, não codificará corretamente.  O compilador trunca os bits adicionais.  
  
 O seguinte exemplo gera C4556:  
  
```  
// C4556.cpp  
// compile with: /W1  
// processor: x86 IPF  
#include <xmmintrin.h>  
void test()  
{  
   __m64 m;  
   _m_pextrw(m, 5);   // C4556  
}  
int main()  
{  
}  
```