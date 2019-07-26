---
title: Classe is_convertible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_convertible
helpviewer_keywords:
- is_convertible class
- is_convertible
ms.assetid: 75614008-1894-42ea-bd57-974399628536
ms.openlocfilehash: c90fe5687992e4df49e8655387cfdd14b40aa529
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454617"
---
# <a name="isconvertible-class"></a>Classe is_convertible

Testa se um tipo pode ser convertido em outro.

## <a name="syntax"></a>Sintaxe

```cpp
template <class From, class To>
struct is_convertible;
```

### <a name="parameters"></a>Parâmetros

*De*\
O tipo do qual converter.

*Ty*\
O tipo para o qual converter.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se a expressão `To to = from;`, em que `from` é um objeto do tipo `From`, estiver bem formada.

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__is_convertible.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

struct trivial
    {
    int val;
    };

int main()
    {
    std::cout << "is_convertible<trivial, int> == " << std::boolalpha
        << std::is_convertible<trivial, int>::value << std::endl;
    std::cout << "is_convertible<trivial, trivial> == " << std::boolalpha
        << std::is_convertible<trivial, trivial>::value << std::endl;
    std::cout << "is_convertible<char, int> == " << std::boolalpha
        << std::is_convertible<char, int>::value << std::endl;

    return (0);
    }
```

```Output
is_convertible<trivial, int> == false
is_convertible<trivial, trivial> == true
is_convertible<char, int> == true
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe is_base_of](../standard-library/is-base-of-class.md)
