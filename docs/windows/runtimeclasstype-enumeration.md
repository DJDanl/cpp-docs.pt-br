---
title: Enumeração RuntimeClassType | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassType
dev_langs:
- C++
helpviewer_keywords:
- RuntimeClassType enumeration
ms.assetid: d380712d-672e-4ea9-b7c5-cf9fa7dbb770
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a3358455755ec4c00ebea85fc13fe0022c7b6697
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42595448"
---
# <a name="runtimeclasstype-enumeration"></a>Enumeração RuntimeClassType

Especifica o tipo de [RuntimeClass](../windows/runtimeclass-class.md) instância com suporte.

## <a name="syntax"></a>Sintaxe

```cpp
enum RuntimeClassType;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ClassicCom`|Uma classe de tempo de execução do COM clássico.|
|`Delegate`|Equivalente a `ClassicCom`.|
|`InhibitFtmBase`|Desabilita `FtmBase` suporte enquanto `__WRL_CONFIGURATION_LEGACY__` não está definido.|
|`InhibitWeakReference`|Desabilita o suporte a referência fraca.|
|`WinRt`|Uma classe de tempo de execução do Windows.|
|`WinRtClassicComMix`|Uma combinação de `WinRt` e `ClassicCom`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)