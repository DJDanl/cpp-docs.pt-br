---
title: Classe underlying_type
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::underlying_type
helpviewer_keywords:
- underlying_type
ms.assetid: 691ddce3-2677-4480-bd35-d933fab85d3e
ms.openlocfilehash: 23e5e9bc5406265f49fca2ed220c597cb32e2a9a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399351"
---
# <a name="underlyingtype-class"></a>Classe underlying_type

Produz o tipo integral subjacente para um tipo de enumeração.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct underlying_type;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

O `type` typedef do membro da classe modelo nomeia o tipo integral subjacente de *T*, quando *T* é um tipo de enumeração, caso contrário, não há nenhum membro typedef `type`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
