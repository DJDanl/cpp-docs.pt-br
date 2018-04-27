---
title: Classe is_trivially_constructible | Microsoft Docs
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
- type_traits/std::is_trivially_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_constructible
ms.assetid: 3fa918c1-e66f-4d0e-a11b-be1fb2c02e7b
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f564ae5970f56690f493e26cbefebbdc34cfec61
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="istriviallyconstructible-class"></a>Classe is_trivially_constructible

Testa se um tipo pode ser construído de forma trivial quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_trivially_constructible;
```

### <a name="parameters"></a>Parâmetros

`T` O tipo de consulta.

`Args` Tipos de argumento para corresponder em um construtor de `T`.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `T` puder ser construído de forma trivial usando os tipos de argumento em `Args`; caso contrário, será falsa. O tipo `T` poderá ser construído de forma trivial se a definição da variável `T t(std::declval<Args>()...);` estiver bem formada e não chamar operações não triviais. `T` e todos os tipos em `Args` devem ser tipos completos, `void` ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
