---
title: Classe is_nothrow_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_nothrow_assignable
helpviewer_keywords:
- is_nothrow_assignable
ms.assetid: aa3aca92-308b-4b1d-b3f3-c54216c48fe7
ms.openlocfilehash: c59c3623f9c9548a7b7e59d0c56a2acd4d3883a3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383614"
---
# <a name="isnothrowassignable-class"></a>Classe is_nothrow_assignable

Testa se um valor de *partir* tipo pode ser atribuído a *para* tipo e a atribuição não efetua lançamentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class To, class From>
struct is_nothrow_assignable;
```

### <a name="parameters"></a>Parâmetros

*To*<br/>
O tipo do objeto que recebe a atribuição.

*From*<br/>
O tipo do objeto que fornece o valor.

## <a name="remarks"></a>Comentários

A expressão `declval<To>() = declval<From>()` deve ser bem formada e o compilador deve ter o conhecimento de que ela não efetua lançamentos. Ambos *partir* e *à* devem ser tipos completos, **void**, ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
