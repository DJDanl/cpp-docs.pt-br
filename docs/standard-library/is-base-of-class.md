---
title: Classe is_base_of
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_base_of
helpviewer_keywords:
- is_base_of class
- is_base_of
ms.assetid: 436f6213-1d4c-4ffc-a588-fc7c4887dd86
ms.openlocfilehash: d56222f218033d00583e5e3def9790720ef7bb94
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456619"
---
# <a name="isbaseof-class"></a>Classe is_base_of

Testa se um tipo é a base de outro.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Base, class Derived>
struct is_base_of;
```

### <a name="parameters"></a>Parâmetros

*Polybase*\
A classe base com relação à qual testar.

*Gerados*\
O tipo derivado com relação ao qual testar.

## <a name="remarks"></a>Comentários

Uma instância do tipo de predicado é verdadeira se o tipo *base* é uma classe base do tipo *derivado*, caso contrário, ele mantém false.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

struct base
    {
    int val;
    };

struct derived
    : public base
    {
    };

int main()
    {
    std::cout << "is_base_of<base, base> == " << std::boolalpha
        << std::is_base_of<base, base>::value << std::endl;
    std::cout << "is_base_of<base, derived> == " << std::boolalpha
        << std::is_base_of<base, derived>::value << std::endl;
    std::cout << "is_base_of<derived, base> == " << std::boolalpha
        << std::is_base_of<derived, base>::value << std::endl;

    return (0);
    }
```

```Output
is_base_of<base, base> == true
is_base_of<base, derived> == true
is_base_of<derived, base> == false
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe is_convertible](../standard-library/is-convertible-class.md)
