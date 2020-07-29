---
title: Classe alignment_of
ms.date: 12/11/2019
f1_keywords:
- type_traits/std::alignment_of
helpviewer_keywords:
- alignment_of class
- alignment_of
ms.assetid: 4141c59a-f94e-41c4-93fd-9ea578b27387
ms.openlocfilehash: 5a90f481c33431d92f0f28405e6226863d2b3913
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87205009"
---
# <a name="alignment_of-class"></a>Classe alignment_of

Obtém o alinhamento do tipo especificado. Essa estrutura é implementada em termos de [`alignof`](../cpp/alignment-cpp-declarations.md) . Use **`alignof`** diretamente quando precisar consultar apenas um valor de alinhamento. Use `alignment_of` quando precisar de uma constante integral, por exemplo, ao fazer a expedição de marca.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct alignment_of;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

A consulta de tipo contém o valor do alinhamento do tipo *Ty*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[`<type_traits>`](type-traits.md)\
[`aligned_storage`Classes](aligned-storage-class.md)
