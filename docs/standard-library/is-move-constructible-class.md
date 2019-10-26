---
title: Classe is_move_constructible
ms.date: 10/24/2019
f1_keywords:
- type_traits/std::is_move_constructible
helpviewer_keywords:
- is_move_constructible
ms.assetid: becdf076-7419-488d-a335-78adf2478b9b
ms.openlocfilehash: 9585a932a34a24769201aaa379525a9b4c181e41
ms.sourcegitcommit: 33a898bf976c65f998b4e88a84765a0cef4193a8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2019
ms.locfileid: "72920097"
---
# <a name="is_move_constructible-class"></a>Classe is_move_constructible

Testa se o tipo pode ser construído usando uma operação de movimentação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_move_constructible;
```

### <a name="parameters"></a>Parâmetros

*T* \
O tipo a ser avaliado.

## <a name="remarks"></a>Comentários

Um predicado de tipo que será avaliado como **true** se o tipo *T* puder ser construído usando uma operação de movimentação. Esse predicado é equivalente a `is_constructible<T, T&&>`. Um tipo *T* que não tem um construtor de movimentação, mas tem um construtor de cópia que aceita um argumento de `const T&`, satisfaz `std::is_move_constructible`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
