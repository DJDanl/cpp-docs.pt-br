---
title: Classe is_standard_layout
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_standard_layout
helpviewer_keywords:
- is_standard_layout class
- is_standard_layout
ms.assetid: 15ccf111-f537-45ef-b552-59152a7ba312
ms.openlocfilehash: fba77be22796f3cb5495543d262dd270ac13d598
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88560589"
---
# <a name="is_standard_layout-class"></a>Classe is_standard_layout

Testa se o tipo é um layout padrão.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_standard_layout;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado

## <a name="remarks"></a>Comentários

Uma instância desse predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um layout padrão de objetos de membro na memória, caso contrário, ela mantém false.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
