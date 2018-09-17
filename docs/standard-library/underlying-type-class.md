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
ms.openlocfilehash: 6e9c1ab3ceb4965450f89de3b483915d693b5100
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45711640"
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
