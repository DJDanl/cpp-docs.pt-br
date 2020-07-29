---
title: Classe is_move_constructible
ms.date: 10/24/2019
f1_keywords:
- type_traits/std::is_move_constructible
helpviewer_keywords:
- is_move_constructible
ms.assetid: becdf076-7419-488d-a335-78adf2478b9b
ms.openlocfilehash: 5495ac39a98f5c194f19d28ba85a1d59f47dfbb4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222375"
---
# <a name="is_move_constructible-class"></a>Classe is_move_constructible

Testa se o tipo pode ser construído usando uma operação de movimentação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_move_constructible;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser avaliado.

## <a name="remarks"></a>Comentários

Um predicado de tipo que é avaliado como **`true`** se o tipo *T* pode ser construído usando uma operação de movimentação. Esse predicado é equivalente a `is_constructible<T, T&&>`. Um tipo *T* que não tem um construtor de movimentação, mas tem um construtor de cópia que aceita um `const T&` argumento, satisfaz `std::is_move_constructible` .

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
