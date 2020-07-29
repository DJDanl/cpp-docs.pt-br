---
title: Classe is_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_assignable
helpviewer_keywords:
- is_assignable
ms.assetid: 53444287-c8be-4ad2-9487-a85c066a4f84
ms.openlocfilehash: 2137f6bfb63e93da2c1367a21f608c113e80d196
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215719"
---
# <a name="is_assignable-class"></a>Classe is_assignable

Testa se um valor do tipo `From` pode ser atribuído a um tipo `To`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class To, class From>
struct is_assignable;
```

### <a name="parameters"></a>parâmetros

*Para*\
O tipo do objeto que recebe a atribuição.

*De*\
O tipo do objeto que fornece o valor.

## <a name="remarks"></a>Comentários

A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formada. Ambos `From` e `To` devem ser tipos completos, **`void`** ou matrizes de associação desconhecida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
