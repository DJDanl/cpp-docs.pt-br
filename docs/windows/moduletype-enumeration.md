---
title: Enumeração ModuleType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ModuleType
helpviewer_keywords:
- ModuleType enumeration
ms.assetid: 61a763af-a5a4-451d-8b40-815af507fcde
ms.openlocfilehash: d822d214d9bad564286cd2c7494c9f480abdcf00
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50524742"
---
# <a name="moduletype-enumeration"></a>Enumeração ModuleType

Especifica se um módulo deve dar suporte a um servidor em processo ou um servidor fora do processo.

## <a name="syntax"></a>Sintaxe

```cpp
enum ModuleType;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`InProc`|Um servidor em processo.|
|`OutOfProc`|Um servidor de out-of-process.|
|`DisableCaching`|Desabilite o mecanismo de cache no módulo.|
|`InProcDisableCaching`|Combinação de `InProc` e `DisableCaching`.|
|`OutOfProcDisableCaching`|Combinação de `OutOfProc` e `DisableCaching`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)