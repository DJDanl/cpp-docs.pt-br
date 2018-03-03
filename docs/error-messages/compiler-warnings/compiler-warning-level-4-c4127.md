---
title: "Compilador (nível 4) de aviso C4127 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4127
dev_langs:
- C++
helpviewer_keywords:
- C4127
ms.assetid: f59ded9e-5227-45bd-ac43-2aa861581363
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d1a5bbd86b6197907f043478df225dceb79679f7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4127"></a>Compilador C4127 de aviso (nível 4)
expressão condicional é constante  
  
 A expressão de controle de um `if` instrução ou `while` loop é avaliada como uma constante. Devido ao seu uso idiomática comum, constantes triviais, como 1 ou `true` não disparam o aviso, a menos que eles são o resultado de uma operação em uma expressão. Se a expressão de controle de um `while` loop for uma constante porque a saída do loop no meio, considere substituir o `while` loop com um `for` loop. Você pode omitir a inicialização, o teste de encerramento e loop incremento de uma `for` loop, o que faz com que o loop infinito, assim como `while(1)`, e você pode sair do loop do corpo do `for` instrução.  
  
 O exemplo a seguir mostra duas maneiras C4127 é gerado e mostra como usar um loop evitar o aviso for:  
  
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