---
title: Classe is_nothrow_move_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_nothrow_move_assignable
helpviewer_keywords:
- is_nothrow_move_assignable
ms.assetid: 000baa02-cbba-49de-9870-af730033348e
ms.openlocfilehash: 92e3364843b5614c9fa108d33605b35962726aa2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217734"
---
# <a name="is_nothrow_move_assignable-class"></a>Classe is_nothrow_move_assignable

Testa se o tipo tem um **`nothrow`** operador de atribuição de movimentação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_nothrow_move_assignable;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* tiver um operador de atribuição de movimentação nothrow; caso contrário, ele será false.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
