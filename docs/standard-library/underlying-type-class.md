---
title: Classe underlying_type
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::underlying_type
helpviewer_keywords:
- underlying_type
ms.assetid: 691ddce3-2677-4480-bd35-d933fab85d3e
ms.openlocfilehash: ea4768d78047112a7584ca49b0e4487fad55a970
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688837"
---
# <a name="underlying_type-class"></a>Classe underlying_type

Produz o tipo integral subjacente para um tipo de enumeração.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct underlying_type;
```

### <a name="parameters"></a>Parâmetros

*T* \
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

O `type` typedef do membro do modelo de classe nomeia o tipo integral subjacente *t*, quando *t* é um tipo de enumeração, caso contrário, não há nenhum typedef de membro `type`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
