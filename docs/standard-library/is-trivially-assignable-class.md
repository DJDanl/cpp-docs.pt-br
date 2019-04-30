---
title: Classe is_trivially_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_assignable
helpviewer_keywords:
- is_trivially_assignable
ms.assetid: 1284a8f7-4093-426d-9c9a-dabb46f90d6d
ms.openlocfilehash: eeef85a0b26c25eb745258c7e0e35394f0cab979
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413483"
---
# <a name="istriviallyassignable-class"></a>Classe is_trivially_assignable

Testa se um valor do tipo `From` pode ser atribuído trivialmente ao tipo `To`

## <a name="syntax"></a>Sintaxe

```cpp
template <class To, class From>
struct is_trivially_assignable;
```

### <a name="parameters"></a>Parâmetros

*To*<br/>
O tipo do objeto que recebe a atribuição.

*From*<br/>
O tipo do objeto que fornece o valor.

## <a name="remarks"></a>Comentários

A expressão `declval<To>() = declval<From>()` deve ser bem formada e o compilador deve ter o conhecimento de que ela não requer operações não triviais. Ambos `From` e `To` devem ser tipos completos, **void**, ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
