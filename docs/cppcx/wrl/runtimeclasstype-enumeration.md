---
title: Enumeração RuntimeClassType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassType
helpviewer_keywords:
- RuntimeClassType enumeration
ms.assetid: d380712d-672e-4ea9-b7c5-cf9fa7dbb770
ms.openlocfilehash: 53f0172968c28762bb1305e274bbd47494cdaf4c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213571"
---
# <a name="runtimeclasstype-enumeration"></a>Enumeração RuntimeClassType

Especifica o tipo de instância de [RuntimeClass](runtimeclass-class.md) com suporte.

## <a name="syntax"></a>Sintaxe

```cpp
enum RuntimeClassType;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`ClassicCom`|Uma classe clássica de tempo de execução COM.|
|`Delegate`|Equivalente a `ClassicCom`.|
|`InhibitFtmBase`|Desabilita o suporte a `FtmBase` enquanto `__WRL_CONFIGURATION_LEGACY__` não está definido.|
|`InhibitWeakReference`|Desabilita o suporte de referência fraca.|
|`WinRt`|Uma classe Windows Runtime.|
|`WinRtClassicComMix`|Uma combinação de `WinRt` e `ClassicCom`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
