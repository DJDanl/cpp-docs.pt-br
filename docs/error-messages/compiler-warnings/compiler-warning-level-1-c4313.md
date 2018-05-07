---
title: Compilador (nível 1) de aviso C4313 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4313
dev_langs:
- C++
helpviewer_keywords:
- C4313
ms.assetid: bcf64191-e2cf-452e-97b4-423fcec2d07c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e42bd8f19ac9a70f93a26265af6e310fb51e7229
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4313"></a>Compilador C4313 de aviso (nível 1)
'function': 'especificador de formato' em formato de cadeia de caracteres está em conflito com o número de argumento de tipo 'type'  
  
 Há um conflito entre o formato especificado e o valor que você está passando. Por exemplo, você passou um parâmetro de 64 bits para um especificador de formato %d não qualificado, que espera um parâmetro de número inteiro de 32 bits. Esse aviso tem efeito somente quando o código é compilado para destinos de 64 bits.  
  
## <a name="example"></a>Exemplo  
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