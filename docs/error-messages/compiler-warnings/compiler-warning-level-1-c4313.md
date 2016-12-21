---
title: "Aviso do compilador (n&#237;vel 1) C4313 | Microsoft Docs"
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
  - "C4313"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4313"
ms.assetid: bcf64191-e2cf-452e-97b4-423fcec2d07c
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4313
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'function': 'especificador de formato' no formato de cadeia de caracteres está em conflito com o número de argumento de tipo 'type'  
  
 Há um conflito entre o formato especificado e o valor que você está passando.  Por exemplo, você passou um parâmetro de 64 bits para um especificador de formato %d não qualificado, que espera um parâmetro de número inteiro de 32 bits.  Esse aviso tem efeito somente quando o código é compilado para destinos de 64 bits.  
  
## Exemplo  
 O exemplo de código a seguir gera C4313 quando ele é compilado para um destino de 64 bits.  
  
```  
// C4313.cpp  
// Compile by using: cl /W1 C4313.cpp  
#include <stdio.h>  
int main() {  
   int * pI = 0;  
   printf("%d", pI);   // C4313 on 64-bit platform code  
   // Try one of the following lines instead:  
   // printf("%p\n", pI);  
   // printf("%Id\n", pI);   // %I64d expects 64-bits of information  
}  
```