---
title: Classe is_trivially_copy_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_copy_assignable
helpviewer_keywords:
- is_trivially_copy_assignable
ms.assetid: 7410133e-f367-493f-92a7-e34e3ec5e879
ms.openlocfilehash: 831e7c5afdd39980876a8e8284a68fec2084a4e5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413457"
---
# <a name="istriviallycopyassignable-class"></a>Classe is_trivially_copy_assignable

Testa se o tipo tem uma cópia trivial do operador de atribuição.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_trivially_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é uma classe que tem um cópia trivial operador de atribuição, caso contrário, será falsa.

Um construtor de atribuição para uma classe *T* será trivial se for implicitamente fornecido, a classe *T* não tiver funções virtuais, a classe *T* não tiver bases virtuais, as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição triviais e as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem operadores de atribuição trivial.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
