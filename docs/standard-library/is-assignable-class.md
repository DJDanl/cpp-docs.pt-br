---
title: Classe is_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_assignable
helpviewer_keywords:
- is_assignable
ms.assetid: 53444287-c8be-4ad2-9487-a85c066a4f84
ms.openlocfilehash: b1357bf8c5ad4dfd5035855e34a8fd6a7ed73d15
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50605953"
---
# <a name="isassignable-class"></a>Classe is_assignable

Testa se um valor do tipo `From` pode ser atribuído a um tipo `To`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class To, class From>
struct is_assignable;
```

### <a name="parameters"></a>Parâmetros

*To*<br/>
O tipo do objeto que recebe a atribuição.

*From*<br/>
O tipo do objeto que fornece o valor.

## <a name="remarks"></a>Comentários

A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formada. Ambos `From` e `To` devem ser tipos completos, **void**, ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
