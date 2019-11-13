---
title: Aviso do compilador (nível 1) C4750
ms.date: 11/04/2016
f1_keywords:
- C4750
helpviewer_keywords:
- C4750
ms.assetid: b0b2c938-7d2a-4c36-8270-7daee15ffee3
ms.openlocfilehash: 35b57cf88bf9f9a170a05af890632316b7030838
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052394"
---
# <a name="compiler-warning-level-1-c4750"></a>Aviso do compilador (nível 1) C4750

' identifier ': função com _alloca () embutida em um loop

A função ' identifier ' força a expansão embutida da função [_alloca](../../c-runtime-library/reference/alloca.md) dentro de um loop, o que pode causar um estouro de pilha quando o loop é executado.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Certifique-se de que a função ' identifier ' não seja modificada com o especificador de [__forceinline](../../cpp/inline-functions-cpp.md) .

1. Verifique se a função ' identifier ' não contém uma função [_alloca](../../c-runtime-library/reference/alloca.md) que esteja contida em um loop.

1. Não especifique a opção de compilação [/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/Ox](../../build/reference/ox-full-optimization.md)ou [/og](../../build/reference/og-global-optimizations.md) .

1. Coloque a função [_alloca](../../c-runtime-library/reference/alloca.md) em uma [instrução try-Except](../../cpp/try-except-statement.md) que irá capturar um estouro de pilha.

## <a name="example"></a>Exemplo

O exemplo de código a seguir chama `MyFunction` em um loop e `MyFunction` chama a função `_alloca`. O modificador de `__forceinline` faz com que a expansão embutida da função `_alloca`.

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

## <a name="see-also"></a>Consulte também

[_alloca](../../c-runtime-library/reference/alloca.md)