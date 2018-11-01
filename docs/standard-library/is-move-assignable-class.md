---
title: Classe is_move_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_move_assignable
helpviewer_keywords:
- is_move_assignable
ms.assetid: f33137f2-0639-4912-8745-bc0f9fd18d28
ms.openlocfilehash: da4734507bac14ecf0278117deb7668518305be0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50610360"
---
# <a name="ismoveassignable-class"></a>Classe is_move_assignable

Testa se o tipo pode ser atribuído a uma movimentação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Um tipo poderá ser atribuído a uma movimentação se uma referência rvalue ao tipo puder ser atribuída a uma referência ao tipo. O predicado de tipo é equivalente a `is_assignable<T&, T&&>`. Tipos atribuíveis a movimentação incluem tipos escalares referenciáveis e tipos de classe que tenham operadores de atribuição de movimentação definidos pelo usuário ou gerados pelo compilador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
