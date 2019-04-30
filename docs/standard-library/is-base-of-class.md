---
title: Classe is_base_of
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_base_of
helpviewer_keywords:
- is_base_of class
- is_base_of
ms.assetid: 436f6213-1d4c-4ffc-a588-fc7c4887dd86
ms.openlocfilehash: 345301b5eeed7b66f18a54e56b9bee6346078634
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383666"
---
# <a name="isbaseof-class"></a>Classe is_base_of

Testa se um tipo é a base de outro.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Base, class Derived>
struct is_base_of;
```

### <a name="parameters"></a>Parâmetros

*Base*<br/>
A classe base com relação à qual testar.

*Derivado*<br/>
O tipo derivado com relação ao qual testar.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Base* é uma classe base do tipo *derivada*, caso contrário, será falsa.

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

[<type_traits>](../standard-library/type-traits.md)<br/>
[Classe is_convertible](../standard-library/is-convertible-class.md)<br/>
