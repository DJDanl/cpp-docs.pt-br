---
title: Classe remove_volatile
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::remove_volatile
helpviewer_keywords:
- remove_volatile class
- remove_volatile
ms.assetid: 8b87e2c2-a581-4eb3-8691-c5603910d61d
ms.openlocfilehash: 19514d1839fa6e0afcecb690dcb12657a85f3c2e
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68451257"
---
# <a name="removevolatile-class"></a>Classe remove_volatile

Cria tipo não volátil do tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct remove_volatile;

template <class T>
using remove_volatile_t = typename remove_volatile<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

Uma instância de `remove_volatile<T>` contém um tipo modificado que é `T1` quando *t* está no formato `volatile T1`, caso contrário, *t*.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

int main()
    {
    int *p = (std::remove_volatile_t<volatile int> *)0;

    p = p;  // to quiet "unused" warning
    std::cout << " remove_volatile_t<volatile int> == "
        << typeid(*p).name() << std::endl;

    return (0);
    }
```

```Output
remove_volatile_t<volatile int> == int
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe add_volatile](../standard-library/add-volatile-class.md)
