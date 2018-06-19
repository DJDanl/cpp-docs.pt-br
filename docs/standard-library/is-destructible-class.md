---
title: Classe is_destructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- type_traits/std::is_destructible
dev_langs:
- C++
helpviewer_keywords:
- is_destructible
ms.assetid: 3bb9b718-1ad5-49ae-93cc-92b93b546b4d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 41a5da108c082dc4199a216d36f51d41e1748ada
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33844283"
---
# <a name="isdestructible-class"></a>Classe is_destructible

Testa se o tipo é destrutível.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_destructible;
```

### <a name="parameters"></a>Parâmetros

`T` O tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `T` for um tipo destrutível; caso contrário, será falsa. Tipos destrutíveis são tipos de referência, tipos de objeto e tipos em que, para algum tipo `U` igual a `remove_all_extents_t<T>`, o operando não avaliado `std::declval<U&>.~U()` estará bem formado. Outros tipos, incluindo tipos incompletos, `void` e tipos de função, não são tipos destrutíveis.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
