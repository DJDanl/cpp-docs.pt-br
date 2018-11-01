---
title: Classe is_bind_expression
ms.date: 11/04/2016
f1_keywords:
- functional/std::is_bind_expression
helpviewer_keywords:
- is_bind_expression class
ms.assetid: 0715f9e9-2239-4778-a1cf-2c21f49dfd47
ms.openlocfilehash: f547b6f74a86612174cb0f510870171158678f7a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519412"
---
# <a name="isbindexpression-class"></a>Classe is_bind_expression

Testa se o tipo é gerado chamando `bind`.

## <a name="syntax"></a>Sintaxe

modelo<class Ty> struct is_bind_expression {valor booliano const estático;};

## <a name="remarks"></a>Comentários

O membro constante `value` será verdadeiro se o tipo `Ty` for um tipo retornado por uma chamada para `bind`; caso contrário, será falso.

## <a name="example"></a>Exemplo

```cpp
// std__functional__is_bind_expression.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

void square(double x)
{
    std::cout << x << "^2 == " << x * x << std::endl;
}

template<class Expr>
void test_for_bind(const Expr&)
{
    std::cout << std::is_bind_expression<Expr>::value << std::endl;
}

int main()
{
    test_for_bind(3.0 * 3.0);
    test_for_bind(std::bind(square, 3));

    return (0);
}
```

```Output
0
1
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[bind](../standard-library/functional-functions.md#bind)<br/>
