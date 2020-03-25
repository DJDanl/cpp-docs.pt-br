---
title: Enumeração FactoryCacheFlags
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::FactoryCacheFlags
ms.assetid: 6f54258f-0144-4264-9608-414e5905f6fb
ms.openlocfilehash: 250c8c8e7ade72bd1a9cd63f0b515774058f0723
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214000"
---
# <a name="factorycacheflags-enumeration"></a>Enumeração FactoryCacheFlags

Determina se os objetos de fábrica são armazenados em cache.

## <a name="syntax"></a>Sintaxe

```cpp
enum FactoryCacheFlags;
```

## <a name="remarks"></a>Comentários

Por padrão, a política de cache de fábrica é especificada como o parâmetro de modelo de [módulotype](moduletype-enumeration.md) quando você cria um objeto de [módulo](module-class.md) . Para substituir essa política, especifique um valor de **FactoryCacheFlags** ao criar um objeto de fábrica.

|||
|-|-|
|`FactoryCacheDefault`|A política de cache do objeto `Module` é usada.|
|`FactoryCacheEnabled`|Habilita o Caching de fábrica, independentemente do parâmetro de modelo de `ModuleType` usado para criar um objeto de `Module`.|
|`FactoryCacheDisabled`|Desabilita o Caching de fábrica, independentemente do parâmetro de modelo de `ModuleType` usado para criar um objeto de `Module`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
