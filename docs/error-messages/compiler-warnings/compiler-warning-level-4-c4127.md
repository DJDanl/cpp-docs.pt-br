---
title: "Compilador aviso (nível 4) C4127 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4127
dev_langs:
- C++
helpviewer_keywords:
- C4127
ms.assetid: f59ded9e-5227-45bd-ac43-2aa861581363
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6197f0018ebb6f23b4608e376282b32cd030ba30
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4127"></a>Compilador C4127 de aviso (nível 4)
expressão condicional é constante  
  
 A expressão de controle de um `if` instrução ou `while` loop é avaliada como uma constante. Por causa do uso de expressões idiomática comuns, constantes triviais, como 1 ou `true` não disparam o aviso, a menos que eles são o resultado de uma operação em uma expressão. Se a expressão de controle de um `while` loop é uma constante porque o loop é encerrado no meio, considere substituir o `while` loop com um `for` loop. Você pode omitir a inicialização, o teste de encerramento e loop incremento de uma `for` loop, o que faz com que o loop infinita, assim como `while(1)`, e você pode sair do loop do corpo do `for` instrução.  
  
 O exemplo a seguir mostra duas maneiras C4127 é gerado e mostra como usar um loop evitar o aviso:  
  
```  
// C4127.cpp  
// compile with: /W4  
#include <stdio.h>  
int main() {  
   if (1 == 1) {}   // C4127  
   while (42) { break; }   // C4127  
  
   // OK  
   for ( ; ; ) {  
      printf("test\n");  
      break;  
   }  
}  
```
