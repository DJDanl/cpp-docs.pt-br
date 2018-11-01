---
title: Classe is_move_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_move_constructible
helpviewer_keywords:
- is_move_constructible
ms.assetid: becdf076-7419-488d-a335-78adf2478b9b
ms.openlocfilehash: 1b1e450338a123c51b80f40f2369207c8b987cd6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508986"
---
# <a name="ismoveconstructible-class"></a>Classe is_move_constructible

Testa se o tipo tem um construtor de movimentação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_move_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser avaliado

## <a name="remarks"></a>Comentários

Um predicado de tipo que é avaliada como true se o tipo *T* podem ser construídos por meio de uma operação de movimentação. Esse predicado é equivalente a `is_constructible<T, T&&>`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
