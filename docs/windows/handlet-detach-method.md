---
title: 'Método handlet:: Detach | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT::Detach
dev_langs:
- C++
helpviewer_keywords:
- Detach method
ms.assetid: f7df0f90-fafb-4d1b-a215-a6c62941f6b0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7b66d5c65dd084da564067cd62242b315f6da182
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42591368"
---
# <a name="handletdetach-method"></a>Método HandleT::Detach

Desassocia o atual **HandleT** objeto a partir de seu identificador subjacente.

## <a name="syntax"></a>Sintaxe

```cpp
typename HandleTraits::Type Detach();
```

## <a name="return-value"></a>Valor de retorno

O identificador subjacente.

## <a name="remarks"></a>Comentários

Quando essa operação for concluída, o atual **HandleT** é definido como o estado inválido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HandleT](../windows/handlet-class.md)