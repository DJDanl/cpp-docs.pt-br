---
title: Classe is_move_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- type_traits/std::is_move_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_move_assignable
ms.assetid: f33137f2-0639-4912-8745-bc0f9fd18d28
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cd47437ad673a928817a7698b58099ba0b9f4607
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ismoveassignable-class"></a>Classe is_move_assignable

Testa se o tipo pode ser atribuído a uma movimentação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_move_assignable;
```

### <a name="parameters"></a>Parâmetros

`T` O tipo de consulta.

## <a name="remarks"></a>Comentários

Um tipo poderá ser atribuído a uma movimentação se uma referência rvalue ao tipo puder ser atribuída a uma referência ao tipo. O predicado de tipo é equivalente a `is_assignable<T&, T&&>`. Tipos atribuíveis a movimentação incluem tipos escalares referenciáveis e tipos de classe que tenham operadores de atribuição de movimentação definidos pelo usuário ou gerados pelo compilador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
