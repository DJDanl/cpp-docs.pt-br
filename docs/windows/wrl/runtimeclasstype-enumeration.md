---
title: Enumeração RuntimeClassType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassType
helpviewer_keywords:
- RuntimeClassType enumeration
ms.assetid: d380712d-672e-4ea9-b7c5-cf9fa7dbb770
ms.openlocfilehash: 3b869be00cdc405569b82bdf3730f8d4ca4f3aab
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335500"
---
# <a name="runtimeclasstype-enumeration"></a>Enumeração RuntimeClassType

Especifica o tipo de [RuntimeClass](runtimeclass-class.md) instância com suporte.

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

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)