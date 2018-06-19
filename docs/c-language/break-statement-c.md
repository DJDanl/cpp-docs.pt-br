---
title: Instrução break (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- break
dev_langs:
- C++
helpviewer_keywords:
- break keyword [C]
ms.assetid: 015627c7-0924-49b2-a4d1-c77edf5eae6a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 194e4c836f0423e20bb747cc6c3b06645c38a5fd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32381344"
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