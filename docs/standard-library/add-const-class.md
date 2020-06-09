---
title: Classe add_const
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::add_const
helpviewer_keywords:
- add_const class
- add_const
ms.assetid: 1262a1eb-8c9c-4dd6-9f43-88ba280182f1
ms.openlocfilehash: c82a3fac8ef95da9e226ca3e2e9122b3c8774cbf
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620839"
---
# <a name="add_const-class"></a>Classe add_const

Cria o tipo const do tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct add_const;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

Uma instância do modificador de tipo contém um tipo modificado que é *Ty* se *Ty* for uma referência, uma função ou um tipo qualificado por const, caso contrário `const Ty` .

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

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](type-traits.md)\
[Classe remove_const](remove-const-class.md)
