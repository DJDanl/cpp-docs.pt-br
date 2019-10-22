---
title: Classe integral_constant, classe bool_constant
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::integral_constant
- XTR1COMMON/std::integral_constant
- type_traits/std::bool_constant
- XTR1COMMON/std::bool_constant
helpviewer_keywords:
- std::integral_constant [C++]
- std::bool_constant [C++]
ms.assetid: 11c002c6-4d31-4042-9341-f2543f43e108
ms.openlocfilehash: 9577ce51d4b0773f7b309fe3dc6dcb5820693dcb
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689528"
---
# <a name="integral_constant-class-bool_constant-class"></a>Classe integral_constant, classe bool_constant

Cria uma constante integral de um tipo e um valor.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T, T v>
struct integral_constant {
   static constexpr T value = v;
   typedef T value_type;
   typedef integral_constant<T, v> type;
   constexpr operator value_type() const noexcept;
   constexpr value_type operator()() const noexcept;
   };
```

### <a name="parameters"></a>Parâmetros

*T* \
O tipo da constante.

*v* \
O valor da constante.

## <a name="remarks"></a>Comentários

O modelo de classe `integral_constant`, quando especializado com um tipo integral *t* e um valor *v* desse tipo, representa um objeto que mantém uma constante desse tipo integral com o valor especificado. O membro denominado `type` é um alias para o tipo da especialização de modelo gerada e o membro `value` contém o valor *v* usado para criar a especialização.

O modelo de classe `bool_constant` é uma especialização parcial explícita de `integral_constant` que usa **bool** como o argumento *t* .

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__integral_constant.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

int main()
    {
    std::cout << "integral_constant<int, 5> == "
        << std::integral_constant<int, 5>::value << std::endl;
    std::cout << "integral_constant<bool, false> == " << std::boolalpha
        << std::integral_constant<bool, false>::value << std::endl;

    return (0);
    }
```

```Output
integral_constant<int, 5> == 5
integral_constant<bool, false> == false
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
\ [false_type](../standard-library/type-traits-typedefs.md#false_type)
[true_type](../standard-library/type-traits-typedefs.md#true_type)
