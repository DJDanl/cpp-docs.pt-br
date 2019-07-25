---
title: Classe alignment_of
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::alignment_of
helpviewer_keywords:
- alignment_of class
- alignment_of
ms.assetid: 4141c59a-f94e-41c4-93fd-9ea578b27387
ms.openlocfilehash: 5222e70965db69d33ec62039bf9013a52d145705
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456446"
---
# <a name="alignmentof-class"></a>Classe alignment_of

Obtém o alinhamento do tipo especificado. Este struct é implementado em termos de [alignof](../cpp/alignof-and-alignas-cpp.md). Use `alignof` diretamente quando você apenas precisar consultar um valor de alinhamento. Use alignment_of quando precisar de uma constante integral, por exemplo, ao fazer expedição de marcação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct alignment_of;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

A consulta de tipo contém o valor do alinhamento do tipo *Ty*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe aligned_storage](../standard-library/aligned-storage-class.md)
