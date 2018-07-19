---
title: Classe is_trivially_copy_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_trivially_copy_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_copy_assignable
ms.assetid: 7410133e-f367-493f-92a7-e34e3ec5e879
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9f7c4c748d7328f534aebfb2133c72635bbdc36f
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38953960"
---
# <a name="istriviallycopyassignable-class"></a>Classe is_trivially_copy_assignable

Testa se o tipo tem uma cópia trivial do operador de atribuição.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_trivially_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*T* o tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é uma classe que tem um cópia trivial operador de atribuição, caso contrário, será falsa.

Um construtor de atribuição para uma classe *T* será trivial se for implicitamente fornecido, a classe *T* não tiver funções virtuais, a classe *T* não tiver bases virtuais, as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição triviais e as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem operadores de atribuição trivial.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
