---
title: C2131 de erro do compilador
ms.date: 02/28/2019
f1_keywords:
- C2131
helpviewer_keywords:
- C2131
ms.openlocfilehash: 19bdf73efa82e624382446c94642ceddac00bf2e
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426950"
---
# <a name="compiler-error-c2131"></a>C2131 de erro do compilador

> expressão não foi avaliada como uma constante

Uma expressão é declarado como **const** ou **constexpr** não foi avaliada como uma constante em tempo de compilação. O compilador deve ser capaz de determinar o valor da expressão no ponto em que ele é usado.

## <a name="example"></a>Exemplo

Este exemplo mostra uma maneira de fazer com que o erro C2131 e como corrigi-lo.

```cpp
// c2131.cpp
// compile by using: cl /EHsc /W4 /c c2131.cpp

struct test
{
    static const int array_size; // To fix, init array_size here.
    int size_array[array_size];  // C2131
};

const int test::array_size = 42;
```

```Output
c2131.cpp
c2131.cpp(7): error C2131: expression did not evaluate to a constant
c2131.cpp(7): note: failure was caused by non-constant arguments or reference to a non-constant symbol
c2131.cpp(7): note: see usage of 'array_size'
```

## <a name="see-also"></a>Consulte também

[const](../../cpp/const-cpp.md)<br/>
[constexpr](../../cpp/constexpr-cpp.md)<br/>
