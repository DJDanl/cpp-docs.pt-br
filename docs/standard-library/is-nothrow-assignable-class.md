---
title: Classe is_nothrow_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_nothrow_assignable
helpviewer_keywords:
- is_nothrow_assignable
ms.assetid: aa3aca92-308b-4b1d-b3f3-c54216c48fe7
ms.openlocfilehash: 7130079ff58820ec5a8893fd248c5b98fc10c93c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222362"
---
# <a name="is_nothrow_assignable-class"></a>Classe is_nothrow_assignable

Testa se um valor de *do* tipo pode ser atribuído ao *tipo e* a atribuição é conhecida como não acionada.

## <a name="syntax"></a>Sintaxe

```cpp
template <class To, class From>
struct is_nothrow_assignable;
```

### <a name="parameters"></a>parâmetros

*Para*\
O tipo do objeto que recebe a atribuição.

*De*\
O tipo do objeto que fornece o valor.

## <a name="remarks"></a>Comentários

A expressão `declval<To>() = declval<From>()` deve ser bem formada e o compilador deve ter o conhecimento de que ela não efetua lançamentos. Tanto *de* e *para* devem ser tipos completos, **`void`** , ou matrizes de associação desconhecida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
