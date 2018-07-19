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
ms.openlocfilehash: e5b2c9237c7f17217d28e489edef4ab65863b54b
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38964101"
---
# <a name="isdestructible-class"></a>Classe is_destructible

Testa se o tipo é destrutível.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_destructible;
```

### <a name="parameters"></a>Parâmetros

*T* o tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é um tipo destrutível, de outra forma, será falsa. Tipos destrutíveis são tipos de referência, tipos de objeto e tipos em que, para algum tipo `U` igual a `remove_all_extents_t<T>`, o operando não avaliado `std::declval<U&>.~U()` estará bem formado. Outros tipos, incluindo tipos incompletos, **void**e tipos de função, não são tipos destrutíveis.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
