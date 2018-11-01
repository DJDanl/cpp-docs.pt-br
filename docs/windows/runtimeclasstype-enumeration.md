---
title: Enumeração RuntimeClassType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassType
helpviewer_keywords:
- RuntimeClassType enumeration
ms.assetid: d380712d-672e-4ea9-b7c5-cf9fa7dbb770
ms.openlocfilehash: 62a82d5fab9fd22e23a5244d4fda3b7f5202304c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50626805"
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