---
title: Classe is_nothrow_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- type_traits/std::is_nothrow_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_nothrow_assignable
ms.assetid: aa3aca92-308b-4b1d-b3f3-c54216c48fe7
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7f9b162ad4f0ff932314bcc8cb01183eb12a55f0
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="isnothrowassignable-class"></a>Classe is_nothrow_assignable

Testa se um valor do tipo `From` pode ser atribuído ao tipo `To` e se é sabido que a atribuição não efetua lançamentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class To, class From>
struct is_nothrow_assignable;
```

### <a name="parameters"></a>Parâmetros

Para o tipo do objeto que recebe a atribuição.

O tipo de objeto que fornece o valor.

## <a name="remarks"></a>Comentários

A expressão `declval<To>() = declval<From>()` deve ser bem formada e o compilador deve ter o conhecimento de que ela não efetua lançamentos. `From` e `To` devem ser tipos completos, `void` ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
