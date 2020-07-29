---
title: Aviso do compilador (nível 1) C4750
description: Descreve o C4750 de aviso do compilador MSVC sobre um possível estouro de pilha.
ms.date: 07/08/2020
f1_keywords:
- C4750
helpviewer_keywords:
- C4750
ms.assetid: b0b2c938-7d2a-4c36-8270-7daee15ffee3
ms.openlocfilehash: a02b69981d3cf1d35a6700261fc5142cfa8ec8e6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225352"
---
# <a name="compiler-warning-level-1-c4750"></a>Aviso do compilador (nível 1) C4750

> '*Identifier*': função com _alloca () embutida em um loop

## <a name="remarks"></a>Comentários

A função '*Identifier*' força a expansão embutida da [`_alloca`](../../c-runtime-library/reference/alloca.md) função dentro de um loop, o que pode causar um estouro de pilha quando o loop é executado.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Certifique-se de que a função '*Identifier*' não seja modificada com o [`__forceinline`](../../cpp/inline-functions-cpp.md) especificador.

1. Certifique-se de que a função '*Identifier*' não contenha uma [`_alloca`](../../c-runtime-library/reference/alloca.md) função que esteja contida em um loop.

1. Não especifique a [`/O1`](../../build/reference/o1-o2-minimize-size-maximize-speed.md) opção de compilação,, [`/O2`](../../build/reference/o1-o2-minimize-size-maximize-speed.md) [`/Ox`](../../build/reference/ox-full-optimization.md) ou [`/Og`](../../build/reference/og-global-optimizations.md) .

1. Coloque a [`_alloca`](../../c-runtime-library/reference/alloca.md) função em uma [instrução try-Except](../../cpp/try-except-statement.md) que irá capturar um estouro de pilha.

## <a name="example"></a>Exemplo

O exemplo de código a seguir chama `MyFunction` um loop e `MyFunction` chama a `_alloca` função. O **`__forceinline`** modificador faz a expansão embutida da `_alloca` função.

```cpp
// c4750.cpp
// compile with: /O2 /W1 /c
#include <intrin.h>

char * volatile newstr;

__forceinline void myFunction(void) // C4750 warning
{
// The _alloca function does not require a __try/__except
// block because the example uses compiler option /c.
    newstr = (char * volatile) _alloca(1000);
}

int main(void)
{
    for (int i=0; i<50000; i++)
       myFunction();
    return 0;
}
```

## <a name="see-also"></a>Confira também

[_alloca](../../c-runtime-library/reference/alloca.md)
