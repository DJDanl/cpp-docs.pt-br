---
title: Classe is_trivially_copy_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_copy_assignable
helpviewer_keywords:
- is_trivially_copy_assignable
ms.assetid: 7410133e-f367-493f-92a7-e34e3ec5e879
ms.openlocfilehash: c0019257a032d3becc268513336ed59e58a2e1d5
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68448003"
---
# <a name="istriviallycopyassignable-class"></a>Classe is_trivially_copy_assignable

Testa se o tipo tem uma cópia trivial do operador de atribuição.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_trivially_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo fica true se o tipo *T* é uma classe que tem um operador de atribuição de cópia trivial, caso contrário, ela mantém false.

Um construtor de atribuição para uma classe *t* é trivial se for fornecido implicitamente, a classe *t* não tem nenhuma função virtual, a classe *t* não tem bases virtuais, as classes de todos os membros de dados não estáticos do tipo de classe têm atribuição trivial os operadores e as classes de todos os membros de dados não estáticos do tipo matriz de classe têm operadores de atribuição triviais.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
