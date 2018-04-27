---
title: Classe is_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- type_traits/std::is_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_assignable
ms.assetid: 53444287-c8be-4ad2-9487-a85c066a4f84
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9e8ee756ce98e1476f10c04c10da1c6bce486513
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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
