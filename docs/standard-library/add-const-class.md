---
title: Classe add_const
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::add_const
helpviewer_keywords:
- add_const class
- add_const
ms.assetid: 1262a1eb-8c9c-4dd6-9f43-88ba280182f1
ms.openlocfilehash: dc457fd4efba538e96200f7f42f84a73fc1b5228
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50438640"
---
# <a name="addconst-class"></a>Classe add_const

Cria o tipo const do tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct add_const;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

Uma instância do modificador de tipo mantém um tipo modificado que é *Ty* se *Ty* é uma referência, uma função ou um tipo qualificado como const, caso contrário, `const Ty`.

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__add_const.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

int main()
{
    std::add_const<int>::type *p = (const int *)0;

    p = p;  // to quiet "unused" warning
    std::cout << "add_const<int> == "
        << typeid(*p).name() << std::endl;

    return (0);
}
```

```Output
add_const<int> == int
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Classe remove_const](../standard-library/remove-const-class.md)<br/>
