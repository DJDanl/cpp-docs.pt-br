---
title: Classe add_volatile
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::add_volatile
helpviewer_keywords:
- add_volatile class
- add_volatile
ms.assetid: cde57277-d764-402d-841e-97611ebaab14
ms.openlocfilehash: becea4ff52342a79d0b87ffe0022e2cf84c47949
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456524"
---
# <a name="addvolatile-class"></a>Classe add_volatile

Torna um tipo **volátil** a partir do tipo especificado.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct add_volatile;

template <class T>
using add_volatile_t = typename add_volatile<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

Uma instância do `add_volatile<T>` tem um **typedef** `type` de membro que é *t* se *t* for uma referência, uma função ou um tipo qualificado para volátil, caso contrário, **volátil** *.* O alias `add_volatile_t` é um atalho para acessar o **typedef** `type`do membro.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

int main()
{
    std::add_volatile_t<int> *p = (volatile int *)0;

    p = p;  // to quiet "unused" warning
    std::cout << "add_volatile<int> == "
        << typeid(*p).name() << std::endl;

    return (0);
}
```

```Output
add_volatile<int> == int
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe remove_volatile](../standard-library/remove-volatile-class.md)
