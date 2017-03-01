---
title: "Compilador aviso (nível 1) C4313 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4313
dev_langs:
- C++
helpviewer_keywords:
- C4313
ms.assetid: bcf64191-e2cf-452e-97b4-423fcec2d07c
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b5610cebf8d5050b2365d36528035aa74e76b33c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4313"></a>Compilador C4313 de aviso (nível 1)
'function': 'especificador de formato' no formato de cadeia de caracteres está em conflito com o número de argumento de tipo 'type'  
  
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
