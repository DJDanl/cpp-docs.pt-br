---
title: Compilador aviso (nível 3) C4738
ms.date: 11/04/2016
f1_keywords:
- C4738
helpviewer_keywords:
- C4738
ms.assetid: 9094895f-7eec-46c2-83d3-249b761d585e
ms.openlocfilehash: 833546d20454e6104a2d5fcb272bf5bb9518ea44
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50460938"
---
# <a name="compiler-warning-level-3-c4738"></a>Compilador aviso (nível 3) C4738

armazenando o resultado float de 32 bits na memória, possível perda de desempenho

C4738 avisa que o resultado de uma atribuição, converter, passou um argumento ou outra operação talvez precise ser arredondados ou que a operação ficou sem registros e precisava usar memória (liberação). Isso pode resultar em perda de desempenho.

Para resolver este aviso e evitar o arredondamento, compilar com [Fast](../../build/reference/fp-specify-floating-point-behavior.md) ou use `double` em vez de `float`.

Para resolver este aviso e evitar ficar sem registros, alterar a ordem de computação e modificar seu uso do inlining

Esse aviso é desativado por padrão. Para obter mais informações, consulte [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4738:

```
// C4738.cpp
// compile with: /c /fp:precise /O2 /W3
// processor: x86
#include <stdio.h>

#pragma warning(default : 4738)

float func(float f)
{
    return f;
}

int main()
{
    extern float f, f1, f2;
    double d = 0.0;

    f1 = func(d);
    f2 = (float) d;
    f = f1 + f2;   // C4738
    printf_s("%f\n", f);
}
```