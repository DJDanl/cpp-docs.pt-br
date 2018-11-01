---
title: Classe is_nothrow_move_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_nothrow_move_assignable
helpviewer_keywords:
- is_nothrow_move_assignable
ms.assetid: 000baa02-cbba-49de-9870-af730033348e
ms.openlocfilehash: eb1ddcace7a68bf60154a15117a1c16a438d263d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50535922"
---
# <a name="isnothrowmoveassignable-class"></a>Classe is_nothrow_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação **nothrow**.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_nothrow_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* tem um nothrow mover operador de atribuição, caso contrário, será falsa.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
