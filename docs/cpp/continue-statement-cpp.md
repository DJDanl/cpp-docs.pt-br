---
title: Instrução continue (C++)
ms.date: 11/04/2016
f1_keywords:
- continue_cpp
helpviewer_keywords:
- continue keyword [C++]
ms.assetid: 3c94ee57-f732-4c1d-8537-d0ce5382bfd4
ms.openlocfilehash: 55a81338f1a0f9036a6d42c4bac7c99489c18d64
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228993"
---
# <a name="continue-statement-c"></a>Instrução continue (C++)

Força a transferência de controle para a expressão de controle do [loop do menor delimitador](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), ou [while](../cpp/while-statement-cpp.md) .

## <a name="syntax"></a>Sintaxe

```
continue;
```

## <a name="remarks"></a>Comentários

As instruções restantes na iteração atual não são executadas. A próxima iteração do loop é determinada da seguinte maneira:

- Em um **`do`** **`while`** loop ou, a próxima iteração começa reavaliando a expressão de controle **`do`** da **`while`** instrução or.

- Em um **`for`** loop (usando a sintaxe `for( <init-expr> ; <cond-expr> ; <loop-expr> )` ), a `<loop-expr>` cláusula é executada. A cláusula `<cond-expr>` é reavaliada e, dependendo do resultado, o loop é encerrado ou ocorre outra iteração.

O exemplo a seguir mostra como a **`continue`** instrução pode ser usada para ignorar seções de código e começar a próxima iteração de um loop.

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

## <a name="see-also"></a>Confira também

[Instruções de atalho](../cpp/jump-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
