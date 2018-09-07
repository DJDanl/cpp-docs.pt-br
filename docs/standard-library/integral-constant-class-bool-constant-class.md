---
title: Classe integral_constant, Classe bool_constant | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::integral_constant
- XTR1COMMON/std::integral_constant
- type_traits/std::bool_constant
- XTR1COMMON/std::bool_constant
dev_langs:
- C++
helpviewer_keywords:
- std::integral_constant [C++]
- std::bool_constant [C++]
ms.assetid: 11c002c6-4d31-4042-9341-f2543f43e108
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 053816fcf18ec29b5e405f84b545432e848d2b59
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44104004"
---
# <a name="integralconstant-class-boolconstant-class"></a>Classe integral_constant, classe bool_constant

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

*T*<br/>
O tipo da constante.

*v*<br/>
O valor da constante.

## <a name="remarks"></a>Comentários

A classe de modelo `integral_constant`, quando especializada com um tipo integral *T* e um valor *v* desse tipo, representa um objeto que contém uma constante desse tipo integral com o valor especificado. O membro denominado `type` é um alias para o tipo da especialização de modelo gerada e o membro `value` contém o valor *v* usado para criar a especialização.

O `bool_constant` classe de modelo é uma especialização parcial explícita de `integral_constant` que usa **bool** como o *T* argumento.

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

[<type_traits>](../standard-library/type-traits.md)<br/>
[false_type](../standard-library/type-traits-typedefs.md#false_type)<br/>
[true_type](../standard-library/type-traits-typedefs.md#true_type)<br/>
