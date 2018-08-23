---
title: Classe alignment_of | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::alignment_of
dev_langs:
- C++
helpviewer_keywords:
- alignment_of class
- alignment_of
ms.assetid: 4141c59a-f94e-41c4-93fd-9ea578b27387
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eb492c1c804aacd79f1552afb5293b8b40a8b648
ms.sourcegitcommit: e9ce38decc9f986edab5543de3464b11ebccb123
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2018
ms.locfileid: "42540532"
---
# <a name="alignmentof-class"></a>Classe alignment_of

Obtém o alinhamento do tipo especificado. Este struct é implementado em termos de [alignof](../cpp/alignof-and-alignas-cpp.md). Use `alignof` diretamente quando você apenas precisar consultar um valor de alinhamento. Use alignment_of quando precisar de uma constante integral, por exemplo, ao fazer expedição de marcação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct alignment_of;
```

### <a name="parameters"></a>Parâmetros

*Ty* o tipo de consulta.

## <a name="remarks"></a>Comentários

A consulta de tipo contém o valor do alinhamento do tipo *Ty*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Classe aligned_storage](../standard-library/aligned-storage-class.md)<br/>
