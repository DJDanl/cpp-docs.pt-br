---
title: Classe is_copy_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_copy_constructible
helpviewer_keywords:
- is_copy_constructible
ms.assetid: d8db9d4c-21ed-4884-bead-0b0b562de007
ms.openlocfilehash: c85d036efda2509885a079cf59a130a63c0389bc
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51521161"
---
# <a name="iscopyconstructible-class"></a>Classe is_copy_constructible

Testa se o tipo tem um construtor de cópia.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_copy_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* é uma classe que tem um construtor de cópia, caso contrário, será falsa.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

struct Copyable
{
    int val;
};

struct NotCopyable
{
   NotCopyable(const NotCopyable&) = delete;
   int val;

};

int main()
{
    std::cout << "is_copy_constructible<Copyable> == " << std::boolalpha
        << std::is_copy_constructible<Copyable>::value << std::endl;
    std::cout << "is_copy_constructible<NotCopyable> == " << std::boolalpha
        << std::is_copy_constructible<NotCopyable>::value << std::endl;

    return (0);
}
```

```Output
is_copy_constructible<Copyable> == true
is_copy_constructible<NotCopyable > == false
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
