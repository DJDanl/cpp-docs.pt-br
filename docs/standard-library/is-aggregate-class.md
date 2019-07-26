---
title: Classe is_aggregate
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_aggregate
helpviewer_keywords:
- is_aggregate
ms.openlocfilehash: 89749e2b4c0e6aaf00de074718cfb598333bc739
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456700"
---
# <a name="isaggregate-class"></a>Classe is_aggregate

Testa se o tipo é um tipo de classe marcado como `aggregate`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_aggregate;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá true se o tipo *T* for `aggregate`um tipo de classe marcado, caso contrário, será false. Se *T* for um tipo de classe, ele deverá ser um tipo completo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
