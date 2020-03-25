---
title: Enumeração ModuleType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ModuleType
helpviewer_keywords:
- ModuleType enumeration
ms.assetid: 61a763af-a5a4-451d-8b40-815af507fcde
ms.openlocfilehash: 8425a15d594f7b8b30027d3576ee86015b656130
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213714"
---
# <a name="moduletype-enumeration"></a>Enumeração ModuleType

Especifica se um módulo deve dar suporte a um servidor em processo ou a um servidor fora do processo.

## <a name="syntax"></a>Sintaxe

```cpp
enum ModuleType;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`InProc`|Um servidor em processo.|
|`OutOfProc`|Um servidor fora do processo.|
|`DisableCaching`|Desabilitar o mecanismo de cache no módulo.|
|`InProcDisableCaching`|Combinação de `InProc` e `DisableCaching`.|
|`OutOfProcDisableCaching`|Combinação de `OutOfProc` e `DisableCaching`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
