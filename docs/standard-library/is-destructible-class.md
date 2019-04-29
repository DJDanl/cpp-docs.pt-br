---
title: Classe is_destructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_destructible
helpviewer_keywords:
- is_destructible
ms.assetid: 3bb9b718-1ad5-49ae-93cc-92b93b546b4d
ms.openlocfilehash: 1036a3756a736ee3916ed9fca84aa935bb0ba2cf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62336823"
---
# <a name="isdestructible-class"></a>Classe is_destructible

Testa se o tipo é destrutível.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_destructible;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é um tipo destrutível, de outra forma, será falsa. Tipos destrutíveis são tipos de referência, tipos de objeto e tipos em que, para algum tipo `U` igual a `remove_all_extents_t<T>`, o operando não avaliado `std::declval<U&>.~U()` estará bem formado. Outros tipos, incluindo tipos incompletos, **void**e tipos de função, não são tipos destrutíveis.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
