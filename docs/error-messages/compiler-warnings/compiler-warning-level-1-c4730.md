---
title: "Aviso C4730 (compilador) (n&#237;vel 1) | Microsoft Docs"
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
  - "C4730"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4730"
ms.assetid: 11303e3f-162b-4b19-970a-479686123a68
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso C4730 (compilador) (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“main”: as expressões de combinação de \_m64 e de ponto flutuante podem resultar em código incorreta  
  
 Uma função usa [\_\_m64](../../cpp/m64.md) e **float**\/tipos de**double** .  Como o MMX e os registros de ponto flutuante compartilham o mesmo espaço físico de registro \(não pode ser usado simultaneamente\), usando `__m64` e **float**\/**double** na mesma função pode haver corrompimento dos dados, pois possivelmente uma exceção.  
  
 Para usar com segurança tipos de `__m64` e de ponto flutuante na mesma função, cada instrução que usa um dos tipos devem ser separados por **\_m\_empty\(\)** \(para MMX\) ou por intrínsecas de **\_m\_femms\(\)** \(para 3DNow\!\).  
  
 O seguinte exemplo gera C4730:  
  
```  
// C4730.cpp  
// compile with: /W1  
// processor: x86  
#include "mmintrin.h"  
  
void func(double)  
{  
}  
  
int main(__m64 a, __m64 b)  
{  
   __m64 m;  
   double f;  
   f = 1.0;  
   m = _m_paddb(a, b);  
   // uncomment the next line to resolve C4730  
   // _m_empty();  
   func(f * 3.0);   // C4730  
}  
```