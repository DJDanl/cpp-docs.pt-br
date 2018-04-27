---
title: Classe underlying_type | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- type_traits/std::underlying_type
dev_langs:
- C++
helpviewer_keywords:
- underlying_type
ms.assetid: 691ddce3-2677-4480-bd35-d933fab85d3e
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 52bf41cdcb40c88f32adc6d0384bea60f5997286
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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
