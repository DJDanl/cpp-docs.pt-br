---
title: Classe is_nothrow_constructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- type_traits/std::is_nothrow_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_nothrow_constructible
ms.assetid: 8be3f927-283e-4d67-95a5-8bf5dc4e7a3d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 112da495673517f86a00437672ccc52429fbd251
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33842736"
---
# <a name="isnothrowconstructible-class"></a>Classe is_nothrow_constructible

Testa se um tipo pode ser construído e não efetua lançamentos quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_nothrow_constructible;
```

### <a name="parameters"></a>Parâmetros

`T` O tipo de consulta.

`Args` Tipos de argumento para corresponder em um construtor de `T`.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `T` puder ser construído usando os tipos de argumento em `Args` e se o compilador tiver conhecimento de que o construtor não efetua lançamentos; caso contrário, será falsa. O tipo `T` poderá ser construído se a definição da variável `T t(std::declval<Args>()...);` estiver bem formada. `T` e todos os tipos em `Args` devem ser tipos completos, `void` ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
