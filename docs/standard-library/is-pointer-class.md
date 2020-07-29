---
title: Classe is_pointer
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_pointer
helpviewer_keywords:
- is_pointer class
- is_pointer
ms.assetid: 44e0a403-7241-4e0a-8922-32877bcb9a4c
ms.openlocfilehash: 3429875f53d65de0161c4d6f87fde7a335bb369e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222336"
---
# <a name="is_pointer-class"></a>Classe is_pointer

Testa se o tipo é um ponteiro.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_pointer;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* é um ponteiro para **`void`** , um ponteiro para um objeto ou um ponteiro para uma função, ou uma `cv-qualified` forma de um deles, caso contrário, ele mantém false. Observe que `is_pointer` é false se *Ty* é um ponteiro para membro ou um ponteiro para uma função membro.

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__is_pointer.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

struct trivial
    {
    int val;
    };

int main()
    {
    std::cout << "is_pointer<trivial> == " << std::boolalpha
        << std::is_pointer<trivial>::value << std::endl;
    std::cout << "is_pointer<int trivial::*> == " << std::boolalpha
        << std::is_pointer<int trivial::*>::value << std::endl;
    std::cout << "is_pointer<trivial *> == " << std::boolalpha
        << std::is_pointer<trivial *>::value << std::endl;
    std::cout << "is_pointer<int> == " << std::boolalpha
        << std::is_pointer<int>::value << std::endl;
    std::cout << "is_pointer<int *> == " << std::boolalpha
        << std::is_pointer<int *>::value << std::endl;

    return (0);
    }
```

```Output
is_pointer<trivial> == false
is_pointer<int trivial::*> == false
is_pointer<trivial *> == true
is_pointer<int> == false
is_pointer<int *> == true
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)\
[Classe is_member_pointer](../standard-library/is-member-pointer-class.md)\
[Classe is_reference](../standard-library/is-reference-class.md)
