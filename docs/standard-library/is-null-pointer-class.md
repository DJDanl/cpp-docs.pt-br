---
title: Classe is_null_pointer
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_null_pointer
helpviewer_keywords:
- is_null_pointer
ms.assetid: f3b3601b-f162-4803-a6e9-dabf5c3876cc
ms.openlocfilehash: b306753146a51bde842b55e4f36d3c1afa82591d
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68455842"
---
# <a name="isnullpointer-class"></a>Classe is_null_pointer

Testa se o tipo é std::nullptr_t.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_null_pointer;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá  true se `std::nullptr_t`o tipo T for, caso contrário, será false.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
