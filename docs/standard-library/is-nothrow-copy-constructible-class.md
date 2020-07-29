---
title: Classe is_nothrow_copy_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_nothrow_copy_constructible
helpviewer_keywords:
- is_nothrow_copy_constructible
ms.assetid: f13a0bea-63b1-492a-9a45-d445df35c282
ms.openlocfilehash: ff88eacc8b692436bc5c7dfa3a01340527862809
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222349"
---
# <a name="is_nothrow_copy_constructible-class"></a>Classe is_nothrow_copy_constructible

Testa se o tipo tem um **`nothrow`** Construtor de cópia.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_nothrow_copy_constructible;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* tiver um construtor de cópia nothrow, caso contrário, ele será false.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
