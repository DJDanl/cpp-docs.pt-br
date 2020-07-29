---
title: Classe is_default_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_default_constructible
helpviewer_keywords:
- is_default_constructible
ms.assetid: dd8f1c44-dae5-4258-891f-c5e048d94092
ms.openlocfilehash: 6e31220fa6b15d958e94e82322467cd73e1c3a6f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215693"
---
# <a name="is_default_constructible-class"></a>Classe is_default_constructible

Testa se o tipo tem um construtor padrão.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_default_constructible;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo fica true se o tipo *T* é um tipo de classe que tem um construtor padrão, caso contrário, ele mantém false. Isso é equivalente ao predicado `is_constructible<T>`. O tipo *T* deve ser um tipo completo, **`void`** ou uma matriz de limite desconhecido.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

struct Simple
{
    Simple() : val(0) {}
    int val;
};

struct Simple2
{
    Simple2(int v) : val(v) {}
    int val;
};

int main()
{
    std::cout << "is_default_constructible<Simple> == " << std::boolalpha
        << std::is_default_constructible<Simple>::value << std::endl;
    std::cout << "is_default_constructible<Simple2> == " << std::boolalpha
        << std::is_default_constructible<Simple2>::value << std::endl;

    return (0);
}
```

```Output
is_default_constructible<Simple> == true
is_default_constructible<Simple2> == false
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
