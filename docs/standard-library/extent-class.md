---
title: Classe extent
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::extent
helpviewer_keywords:
- extent class
- extent
ms.assetid: 6d16263d-90b2-4330-9ec7-b59ed898792d
ms.openlocfilehash: 0cd53ba8537e706a68ffdcf08df998108266ad20
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68457789"
---
# <a name="extent-class"></a>Classe extent

Obtém uma dimensão de matriz.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty, unsigned I = 0>
struct extent;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

*ENCONTREI*\
A matriz associada à consulta.

## <a name="remarks"></a>Comentários

Se *Ty* é um tipo de matriz que tem pelo menos *I* dimensões, a consulta de tipo contém o número de elementos na dimensão especificada por *I*. Se *Ty* não for um tipo de matriz ou se sua classificação for menor que *I*, ou se *eu* for zero e *Ty* for do tipo "matriz de limite `U`desconhecido de", a consulta de tipo conterá o valor 0.

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__extent.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

int main()
    {
    std::cout << "extent 0 == "
        << std::extent<int[5][10]>::value << std::endl;
    std::cout << "extent 1 == "
        << std::extent<int[5][10], 1>::value << std::endl;

    return (0);
    }
```

```Output
extent 0 == 5
extent 1 == 10
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe remove_all_extents](../standard-library/remove-all-extents-class.md)\
[Classe remove_extent](../standard-library/remove-extent-class.md)
