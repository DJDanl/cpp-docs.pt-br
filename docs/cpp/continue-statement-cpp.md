---
title: Instrução continue (C++)
ms.date: 11/04/2016
f1_keywords:
- continue_cpp
helpviewer_keywords:
- continue keyword [C++]
ms.assetid: 3c94ee57-f732-4c1d-8537-d0ce5382bfd4
ms.openlocfilehash: 6fbc4af6a9a56f3406582ea9ba59f4d5759b88a1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50607474"
---
# <a name="continue-statement-c"></a>Instrução continue (C++)

Força a transferência de controle para a expressão de controle de fechamento menor [fazer](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), ou [enquanto](../cpp/while-statement-cpp.md) loop.

## <a name="syntax"></a>Sintaxe

```
continue;
```

## <a name="remarks"></a>Comentários

As instruções restantes na iteração atual não são executadas. A próxima iteração do loop é determinada da seguinte maneira:

- Em um **fazer** ou **enquanto** loop, a próxima iteração começa com a reavaliação da expressão controladora dos **fazer** ou **enquanto** instrução.

- Em um **para** loop (usando a sintaxe `for`(`init-expr`; `cond-expr`; `loop-expr`)), o `loop-expr` cláusula é executada. A cláusula `cond-expr` é reavaliada e, dependendo do resultado, o loop é encerrado ou ocorre outra iteração.

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

[Instruções de atalho](../cpp/jump-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)