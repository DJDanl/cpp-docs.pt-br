---
title: "Instrução break (C) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- break
dev_langs:
- C++
helpviewer_keywords:
- break keyword [C]
ms.assetid: 015627c7-0924-49b2-a4d1-c77edf5eae6a
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 544b4cf95e36b3b1c0c2d4d64dd022b28cc6b57a
ms.lasthandoff: 02/25/2017

---
# <a name="break-statement-c"></a>Instrução break (C)
A instrução `break` encerra a execução da instrução delimitadora `do`, `for`, `switch` ou `while` mais próxima em que aparece. O controle passa para a instrução que segue a instrução encerrada.  
  
## <a name="syntax"></a>Sintaxe  
 *jump-statement*:  
 `break;`  
  
 A instrução `break` é frequentemente usada para encerrar o processamento de um caso específico dentro de uma instrução `switch`. A falta de uma instrução interativa delimitadora ou `switch` gera um erro.  
  
 Em instruções aninhadas, a instrução `break` encerra apenas a instrução `do`, `for`, `switch` ou `while` que a delimita imediatamente. Você pode usar uma instrução `return` ou `goto` para transferir o controle para outro lugar fora da estrutura aninhada.  
  
 Este exemplo ilustra a instrução `break`:  
  
```  
#include <stdio.h>  
int main() {  
   char c;  
   for(;;) {  
      printf_s( "\nPress any key, Q to quit: " );  
  
      // Convert to character value  
      scanf_s("%c", &c);  
      if (c == 'Q')  
          break;  
   }  
} // Loop exits only when 'Q' is pressed  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instrução Break](../cpp/break-statement-cpp.md)
