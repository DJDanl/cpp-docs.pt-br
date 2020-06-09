---
title: Classe alignment_of
ms.date: 12/11/2019
f1_keywords:
- type_traits/std::alignment_of
helpviewer_keywords:
- alignment_of class
- alignment_of
ms.assetid: 4141c59a-f94e-41c4-93fd-9ea578b27387
ms.openlocfilehash: c2af00ac32b3013820a3109783c4bf7eb42ec445
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623725"
---
# <a name="alignment_of-class"></a>Classe alignment_of

Obtém o alinhamento do tipo especificado. Este struct é implementado em termos de [alignof](../cpp/alignment-cpp-declarations.md). Use **alignof** diretamente quando precisar consultar apenas um valor de alinhamento. Use alignment_of quando precisar de uma constante integral, por exemplo, ao fazer expedição de marcação.

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

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](type-traits.md)\
[Classe aligned_storage](aligned-storage-class.md)
