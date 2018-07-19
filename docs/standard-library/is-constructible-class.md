---
title: Classe is_constructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- type_traits/std::is_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_constructible
ms.assetid: 7cdec5ff-73cf-4f78-a9db-ced2e9c0fd7f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8f9e3f71a0d8647000f77863ecc9243b069f0521
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38955806"
---
# <a name="isconstructible-class"></a>Classe is_constructible

Testa se um tipo pode ser construído quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_constructible;
```

### <a name="parameters"></a>Parâmetros

*T* o tipo de consulta.

*Args* os tipos de argumento para corresponder a um construtor de *T*.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é construível usando os tipos de argumento na *Args*, caso contrário, será falsa. Tipo de *T* pode ser construído se a definição da variável `T t(std::declval<Args>()...);` está bem formado. Ambos *T* e todos os tipos *Args* devem ser tipos completos, **void**, ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
