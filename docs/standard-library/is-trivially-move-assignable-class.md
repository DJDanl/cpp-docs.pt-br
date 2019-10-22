---
title: Classe is_trivially_move_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_move_assignable
helpviewer_keywords:
- is_trivially_move_assignable
ms.assetid: 374f7322-0706-4bc1-a1a5-4191d0315e28
ms.openlocfilehash: 4b349d328da995105a6217f4ab597da5d7eafc38
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689488"
---
# <a name="is_trivially_move_assignable-class"></a>Classe is_trivially_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_trivially_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty* \
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um operador de atribuição de movimento trivial, caso contrário, ela mantém false.

Um operador de atribuição de movimentação para uma classe *Ty* é trivial se:

- for fornecido implicitamente
- a classe *Ty* não tem nenhuma função virtual
- a classe *Ty* não tem bases virtuais
- as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição de movimentação trivial
- as classes de todos os membros de dados não estáticos da matriz de tipo da classe tiverem operadores de atribuição de movimentação trivial

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
