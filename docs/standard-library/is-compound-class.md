---
title: Classe is_compound
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_compound
helpviewer_keywords:
- is_compound class
- is_compound
ms.assetid: bdad1167-cf3f-4f37-8321-62a5df159ead
ms.openlocfilehash: ae2e3c66b3abf22bbefbcb0fcd3292f0a3dbdbe2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215706"
---
# <a name="is_compound-class"></a>Classe is_compound

Testa se o tipo especificado não é fundamental.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_compound;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância de um predicado de tipo mantém **`false`** se o tipo de *Ty* é um tipo fundamental (ou seja, se [is_fundamental](../standard-library/is-fundamental-class.md) é \<Ty> mantida **`true`** ); caso contrário, ele mantém **`true`** . Assim, o predicado mantém **`true`** se *Ty* é um tipo de matriz, um tipo de função, um ponteiro para **`void`** ou um objeto ou uma função, uma referência, uma classe, uma União, uma enumeração ou um ponteiro para um membro de classe não estático ou uma forma *qualificada por CV* de um deles.

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__is_compound.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

struct trivial
    {
    int val;
    };

int main()
    {
    std::cout << "is_compound<trivial> == " << std::boolalpha
        << std::is_compound<trivial>::value << std::endl;
    std::cout << "is_compound<int[]> == " << std::boolalpha
        << std::is_compound<int[]>::value << std::endl;
    std::cout << "is_compound<int()> == " << std::boolalpha
        << std::is_compound<int()>::value << std::endl;
    std::cout << "is_compound<int&> == " << std::boolalpha
        << std::is_compound<int&>::value << std::endl;
    std::cout << "is_compound<void *> == " << std::boolalpha
        << std::is_compound<void *>::value << std::endl;
    std::cout << "is_compound<int> == " << std::boolalpha
        << std::is_compound<int>::value << std::endl;

    return (0);
    }
```

```Output
is_compound<trivial> == true
is_compound<int[]> == true
is_compound<int()> == true
is_compound<int&> == true
is_compound<void *> == true
is_compound<int> == false
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)\
[Classe is_class](../standard-library/is-class-class.md)
