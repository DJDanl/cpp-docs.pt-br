---
title: Classe is_constructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- type_traits/std::is_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_constructible
ms.assetid: 7cdec5ff-73cf-4f78-a9db-ced2e9c0fd7f
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b030d50861a207828b406bd683f02089070755be
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="isconstructible-class"></a>Classe is_constructible

Testa se um tipo pode ser construído quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_constructible;
```

### <a name="parameters"></a>Parâmetros

`T` O tipo de consulta.

`Args` Tipos de argumento para corresponder em um construtor de `T`.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `T` puder ser construído usando os tipos de argumento em `Args`; caso contrário, será falsa. O tipo `T` poderá ser construído se a definição da variável `T t(std::declval<Args>()...);` estiver bem formada. `T` e todos os tipos em `Args` devem ser tipos completos, `void` ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
