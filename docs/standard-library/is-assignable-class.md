---
title: Classe is_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_assignable
ms.assetid: 53444287-c8be-4ad2-9487-a85c066a4f84
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bd8b757ab46d462bd5d6a596f7dbbfdd18061a8d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33842993"
---
# <a name="isassignable-class"></a>Classe is_assignable

Testa se um valor do tipo `From` pode ser atribuído a um tipo `To`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class To, class From>
struct is_assignable;
```

### <a name="parameters"></a>Parâmetros

Para o tipo do objeto que recebe a atribuição.

O tipo de objeto que fornece o valor.

## <a name="remarks"></a>Comentários

A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formada. `From` e `To` devem ser tipos completos, `void` ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
