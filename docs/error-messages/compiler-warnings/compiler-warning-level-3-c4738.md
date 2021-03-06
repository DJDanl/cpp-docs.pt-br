---
title: Aviso do compilador (nível 3) C4738
ms.date: 11/04/2016
f1_keywords:
- C4738
helpviewer_keywords:
- C4738
ms.assetid: 9094895f-7eec-46c2-83d3-249b761d585e
ms.openlocfilehash: 639fb14fc409a9954315184bab7ae1127460ea0d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214406"
---
# <a name="compiler-warning-level-3-c4738"></a>Aviso do compilador (nível 3) C4738

armazenando o resultado float de 32 bits na memória, possível perda de desempenho

O C4738 avisa que o resultado de uma atribuição, conversão, argumento passado ou outra operação pode precisar ser arredondado ou que a operação ficou sem registros e precisa usar a memória (despejo). Isso pode resultar em perda de desempenho.

Para resolver esse aviso e evitar o arredondamento, compile com [/fp: Fast](../../build/reference/fp-specify-floating-point-behavior.md) ou use **`double`** em vez de **`float`** .

Para resolver esse aviso e evitar a ausência de registros, altere a ordem de computação e modifique o uso de inlining

Esse aviso está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4738:

```cpp
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
