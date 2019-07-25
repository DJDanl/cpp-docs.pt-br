---
title: Classe is_destructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_destructible
helpviewer_keywords:
- is_destructible
ms.assetid: 3bb9b718-1ad5-49ae-93cc-92b93b546b4d
ms.openlocfilehash: 80592a6fca274533a798b2f5a2459d336ee2c301
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68452727"
---
# <a name="isdestructible-class"></a>Classe is_destructible

Testa se o tipo é destrutível.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_destructible;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá true se o tipo *T* for um tipo destrutíveis, caso contrário, será false. Tipos destrutíveis são tipos de referência, tipos de objeto e tipos em que, para algum tipo `U` igual a `remove_all_extents_t<T>`, o operando não avaliado `std::declval<U&>.~U()` estará bem formado. Outros tipos, incluindo tipos incompletos, **void**e tipos de função, não são tipos destrutíveis.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
