---
title: Classe is_standard_layout
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_standard_layout
helpviewer_keywords:
- is_standard_layout class
- is_standard_layout
ms.assetid: 15ccf111-f537-45ef-b552-59152a7ba312
ms.openlocfilehash: 4f999eaa4a5c1ea7e9672a5efdc6000a4d3d9759
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68457409"
---
# <a name="isstandardlayout-class"></a>Classe is_standard_layout

Testa se o tipo é um layout padrão.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_standard_layout;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ty*|O tipo a ser consultado|

## <a name="remarks"></a>Comentários

Uma instância desse predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um layout padrão de objetos de membro na memória, caso contrário, ela mantém false.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
