---
title: Classe is_copy_assignable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_copy_assignable
helpviewer_keywords:
- is_copy_assignable
ms.assetid: 3ae6bca1-85fb-4829-9ee9-0183b081ff50
ms.openlocfilehash: 5fedd32f026828e49ea29cb2975a2529ca28c862
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68452834"
---
# <a name="iscopyassignable-class"></a>Classe is_copy_assignable

Teste se o tipo pode ser copiado na atribuição.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um operador de atribuição de cópia, caso contrário, ela mantém false. Equivalente a is_assignable\<Ty&, const Ty&>.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
