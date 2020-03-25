---
title: Instrução continue (C++)
ms.date: 11/04/2016
f1_keywords:
- continue_cpp
helpviewer_keywords:
- continue keyword [C++]
ms.assetid: 3c94ee57-f732-4c1d-8537-d0ce5382bfd4
ms.openlocfilehash: b3790ecfde0af958b3244cfdaa61524ba78d6267
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180271"
---
# <a name="continue-statement-c"></a>Instrução continue (C++)

Força a transferência de controle para a expressão de controle do [loop do menor delimitador](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), ou [while](../cpp/while-statement-cpp.md) .

## <a name="syntax"></a>Sintaxe

```
continue;
```

## <a name="remarks"></a>Comentários

As instruções restantes na iteração atual não são executadas. A próxima iteração do loop é determinada da seguinte maneira:

- Em um loop **do** ou **while** , a próxima iteração começa reavaliando a expressão de controle da instrução **do ou** **while** .

- Em um loop **for** (usando a sintaxe `for`(`init-expr`; `cond-expr`; `loop-expr`)), a cláusula `loop-expr` é executada. A cláusula `cond-expr` é reavaliada e, dependendo do resultado, o loop é encerrado ou ocorre outra iteração.

O exemplo a seguir mostra como a instrução **continue** pode ser usada para ignorar seções de código e iniciar a próxima iteração de um loop.

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
