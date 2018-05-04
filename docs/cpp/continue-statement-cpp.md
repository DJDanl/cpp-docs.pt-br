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
ms.openlocfilehash: b153c9f5dfae93f1a5cb83dc2b9bcfc09e77af07
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="continue-statement-c"></a>Instrução continue (C++)
Força a transferência de controle para a expressão de controle de circunscrição menor [fazer](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), ou [enquanto](../cpp/while-statement-cpp.md) loop.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
continue;  
```  
  
## <a name="remarks"></a>Comentários  
 As instruções restantes na iteração atual não são executadas. A próxima iteração do loop é determinada da seguinte maneira:  
  
-   Em um loop `do` ou `while`, a próxima iteração começa com a reavaliação da expressão controladora da instrução `do` ou `while`.  
  
-   Em um loop `for` (usando a sintaxe `for`(`init-expr`; `cond-expr`; `loop-expr`)), a cláusula `loop-expr` é executada. A cláusula `cond-expr` é reavaliada e, dependendo do resultado, o loop é encerrado ou ocorre outra iteração.  
  
 O exemplo a seguir mostra como a instrução `continue` pode ser usada para ignorar seções de código e iniciar a próxima iteração de um loop.  
  
## <a name="example"></a>Exemplo  
  
```  
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