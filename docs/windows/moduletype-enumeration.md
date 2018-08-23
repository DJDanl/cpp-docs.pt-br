---
title: Enumeração ModuleType | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ModuleType
dev_langs:
- C++
helpviewer_keywords:
- ModuleType enumeration
ms.assetid: 61a763af-a5a4-451d-8b40-815af507fcde
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fe8d41aded38db7cde5316e04cfa1689845aa4e7
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42595466"
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