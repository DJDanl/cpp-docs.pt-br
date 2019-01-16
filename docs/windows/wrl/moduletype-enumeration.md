---
title: Enumeração ModuleType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ModuleType
helpviewer_keywords:
- ModuleType enumeration
ms.assetid: 61a763af-a5a4-451d-8b40-815af507fcde
ms.openlocfilehash: 937649eada481f7c45359fa0816266f62dc03875
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335455"
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

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)