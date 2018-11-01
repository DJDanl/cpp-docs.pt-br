---
title: Objeto _1
ms.date: 11/04/2016
f1_keywords:
- _1
- std::_1
- functional/std::_1
helpviewer_keywords:
- _1 object
ms.assetid: 30c3c480-ff31-4708-94be-7d0d65f243c9
ms.openlocfilehash: 248bb4733849b231ee4ff9180dd04e288412af3b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50666356"
---
# <a name="1-object"></a>Objeto _1

Espaços reservados para argumentos substituíveis.

## <a name="syntax"></a>Sintaxe

```cpp
namespace placeholders {
    extern unspecified _1,
    _2, ... _M
} // namespace placeholders (within std)
```

## <a name="remarks"></a>Comentários

Os objetos `_1, _2, ... _M` são espaços reservados para designar o primeiro, segundo,..., milionésimo argumento, respectivamente em uma chamada de função para um objeto retornado por [associar](../standard-library/functional-functions.md#bind). Use `_N` para especificar onde o enésimo argumento deverá ser inserido quando a expressão bind for avaliada.

Nesta implementação, o valor de `M` é 20.

## <a name="example"></a>Exemplo

```cpp
// std__functional_placeholder.cpp
// compile with: /EHsc
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std::placeholders;

void square(double x)
    {
    std::cout << x << "^2 == " << x * x << std::endl;
    }

void product(double x, double y)
    {
    std::cout << x << "*" << y << " == " << x * y << std::endl;
    }

int main()
    {
    double arg[] = {1, 2, 3};

    std::for_each(&arg[0], &arg[3], square);
    std::cout << std::endl;

    std::for_each(&arg[0], &arg[3], std::bind(product, _1, 2));
    std::cout << std::endl;

    std::for_each(&arg[0], &arg[3], std::bind(square, _1));

    return (0);
    }

```

```Output
1^2 == 1
2^2 == 4
3^2 == 9

1*2 == 2
2*2 == 4
3*2 == 6

1^2 == 1
2^2 == 4
3^2 == 9
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[bind](../standard-library/functional-functions.md#bind)<br/>
[Classe is_placeholder](../standard-library/is-placeholder-class.md)<br/>
