---
title: Classe is_trivially_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- type_traits/std::is_trivially_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_assignable
ms.assetid: 1284a8f7-4093-426d-9c9a-dabb46f90d6d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 47fabb7120cc13eeca38bc9d06428f686fc9f1b9
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38955560"
---
# <a name="istriviallyassignable-class"></a>Classe is_trivially_assignable

Testa se um valor do tipo `From` pode ser atribuído trivialmente ao tipo `To`

## <a name="syntax"></a>Sintaxe

```cpp
template <class To, class From>
struct is_trivially_assignable;
```

### <a name="parameters"></a>Parâmetros

Para o tipo do objeto que recebe a atribuição.

O tipo de objeto que fornece o valor.

## <a name="remarks"></a>Comentários

A expressão `declval<To>() = declval<From>()` deve ser bem formada e o compilador deve ter o conhecimento de que ela não requer operações não triviais. Ambos `From` e `To` devem ser tipos completos, **void**, ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
