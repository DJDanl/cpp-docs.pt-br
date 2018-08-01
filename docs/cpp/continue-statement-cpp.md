---
title: Instrução Continue (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- continue_cpp
dev_langs:
- C++
helpviewer_keywords:
- continue keyword [C++]
ms.assetid: 3c94ee57-f732-4c1d-8537-d0ce5382bfd4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d0ab1e052b3e6d843813c33e5444fc3c08796d00
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402085"
---
# <a name="continue-statement-c"></a>Instrução continue (C++)
Força a transferência de controle para a expressão de controle de fechamento menor [fazer](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), ou [enquanto](../cpp/while-statement-cpp.md) loop.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
continue;  
```  
  
## <a name="remarks"></a>Comentários  
 As instruções restantes na iteração atual não são executadas. A próxima iteração do loop é determinada da seguinte maneira:  
  
-   Em um **fazer** ou **enquanto** loop, a próxima iteração começa com a reavaliação da expressão controladora dos **fazer** ou **enquanto** instrução.  
  
-   Em um **para** loop (usando a sintaxe `for`(`init-expr`; `cond-expr`; `loop-expr`)), o `loop-expr` cláusula é executada. A cláusula `cond-expr` é reavaliada e, dependendo do resultado, o loop é encerrado ou ocorre outra iteração.  
  
 A exemplo a seguir mostra como o **continuar** instrução pode ser usada para ignorar seções de código e começar a próxima iteração de um loop.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
// continue_statement.cpp  
#include <stdio.h>  
int main()  
{  
    int i = 0;  
    do  
    {  
        i++;  
        printf_s("before the continue\n");  
        continue;  
        printf("after the continue, should never print\n");  
     } while (i < 3);  
  
     printf_s("after the do loop\n");  
}  
```  
  
```Output  
before the continue  
before the continue  
before the continue  
after the do loop  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de Hiperlink](../cpp/jump-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)