---
title: Enumeração RuntimeClassType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassType
helpviewer_keywords:
- RuntimeClassType enumeration
ms.assetid: d380712d-672e-4ea9-b7c5-cf9fa7dbb770
ms.openlocfilehash: 80e8a120f7e3666721ff839a2a696388a64d734e
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59035952"
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