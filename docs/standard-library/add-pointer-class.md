---
title: Classe add_pointer
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::add_pointer
helpviewer_keywords:
- add_pointer class
- add_pointer
ms.assetid: d8095cb0-6578-4143-b78f-87f82485298c
ms.openlocfilehash: 8adeffd0352d04fe844b286ea7456c66e907a0a7
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619256"
---
# <a name="add_pointer-class"></a>Classe add_pointer

Cria um ponteiro para tipo de um tipo especificado.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct add_pointer;

template <class T>
using add_pointer_t = typename add_pointer<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

O **typedef** do membro `type` nomeia o mesmo tipo de `remove_reference<T>::type*` . O alias `add_pointer_t` é um atalho para acessar o **typedef** do membro `type` .

Uma vez que não é válido criar um ponteiro de uma referência, `add_pointer` remove a referência, se houver, do tipo especificado antes de criar um ponteiro para tipo. Consequentemente, você pode usar um tipo com `add_pointer` sem se preocupar se o tipo é uma referência.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra que `add_pointer` de um tipo é o mesmo que um ponteiro para esse tipo.

```cpp
#include <type_traits>
#include <iostream>

int main()
{
    std::add_pointer_t<int> *p = (int **)0;

    p = p;  // to quiet "unused" warning
    std::cout << "add_pointer_t<int> == "
        << typeid(*p).name() << std::endl;

    return (0);
}
```

```Output
add_pointer_t<int> == int *
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](type-traits.md)\
[Classe remove_pointer](remove-pointer-class.md)
