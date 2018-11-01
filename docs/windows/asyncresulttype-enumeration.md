---
title: Enumeração AsyncResultType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncResultType
helpviewer_keywords:
- AsyncResultType enumeration
ms.assetid: 4195d234-3f3f-4363-9118-6ad2a7551cf2
ms.openlocfilehash: df91b80fe21ecddabc7062b040387b8c2b2c1bb7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50551366"
---
# <a name="asyncresulttype-enumeration"></a>Enumeração AsyncResultType

Especifica o tipo de resultado retornado pelo `GetResults()` método.

## <a name="syntax"></a>Sintaxe

```cpp
enum AsyncResultType;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`MultipleResults`|Um conjunto de vários resultados, que são apresentadas progressivamente entre `Start` estado e antes de `Close()` é chamado.|
|`SingleResult`|Um único resultado é apresentado após o `Complete` evento ocorre.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)