---
title: Compilador aviso (nível 1) C4750 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4750
dev_langs:
- C++
helpviewer_keywords:
- C4750
ms.assetid: b0b2c938-7d2a-4c36-8270-7daee15ffee3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5c77c46daf30b6e0238345d9b2be3c6c5362c192
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46026615"
---
# <a name="compiler-warning-level-1-c4750"></a>Compilador aviso (nível 1) C4750

'identifier': função com alloca () embutida em um loop

A função 'identifier' força a expansão embutida do [alloca](../../c-runtime-library/reference/alloca.md) função dentro de um loop, o que pode causar um estouro de pilha quando o loop é executado.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Certifique-se de que a função 'identifier' não será modificada com a [forceinline](../../cpp/inline-functions-cpp.md) especificador.

1. Certifique-se de que a função 'identifier' não contém um [alloca](../../c-runtime-library/reference/alloca.md) função que está contida em um loop.

1. Não especifique a [/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/Ox](../../build/reference/ox-full-optimization.md), ou [/Og](../../build/reference/og-global-optimizations.md) comutador de compilação.

1. Local de [alloca](../../c-runtime-library/reference/alloca.md) funcionar em um [tente-exceto instrução](../../cpp/try-except-statement.md) que vai capturar um estouro de pilha.

## <a name="example"></a>Exemplo

O seguinte exemplo de código chama `MyFunction` em um loop, e `MyFunction` chamadas a `_alloca` função. O `__forceinline` modificador faz com que a expansão embutida do `_alloca` função.

```
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