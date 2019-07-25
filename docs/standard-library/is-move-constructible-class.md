---
title: Classe is_move_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_move_constructible
helpviewer_keywords:
- is_move_constructible
ms.assetid: becdf076-7419-488d-a335-78adf2478b9b
ms.openlocfilehash: c83ed4365fd0e73a7daa8b9894c5e85f20387a79
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456112"
---
# <a name="ismoveconstructible-class"></a>Classe is_move_constructible

Testa se o tipo tem um construtor de movimentação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_move_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser avaliado

## <a name="remarks"></a>Comentários

Um predicado de tipo que será avaliado como true se o tipo *T* puder ser construído usando uma operação de movimentação. Esse predicado é equivalente a `is_constructible<T, T&&>`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
