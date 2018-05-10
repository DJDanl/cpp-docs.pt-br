---
title: Classe underlying_type | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- type_traits/std::underlying_type
dev_langs:
- C++
helpviewer_keywords:
- underlying_type
ms.assetid: 691ddce3-2677-4480-bd35-d933fab85d3e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4f45af807b37294b87920b6fabac18647f170025
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="underlyingtype-class"></a>Classe underlying_type

Produz o tipo integral subjacente para um tipo de enumeração.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct underlying_type;
```

### <a name="parameters"></a>Parâmetros

`T` Digite para modificar.

## <a name="remarks"></a>Comentários

O `type` membro typedef da classe modelo nomeia o tipo integral subjacente de `T`, quando `T` é um tipo de enumeração, caso contrário, não há nenhum membro typedef `type`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
