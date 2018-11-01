---
title: Enumeração FactoryCacheFlags
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::FactoryCacheFlags
ms.assetid: 6f54258f-0144-4264-9608-414e5905f6fb
ms.openlocfilehash: 8320563991981f7a49d4775a2bad9c487124d907
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50595644"
---
# <a name="factorycacheflags-enumeration"></a>Enumeração FactoryCacheFlags

Determina se os objetos de fábrica são armazenados em cache.

## <a name="syntax"></a>Sintaxe

```cpp
enum FactoryCacheFlags;
```

## <a name="remarks"></a>Comentários

Por padrão, a política de cache de fábrica é especificada como o [ModuleType](../windows/moduletype-enumeration.md) parâmetro de modelo quando você cria um [módulo](../windows/module-class.md) objeto. Para substituir essa política, especifique um **FactoryCacheFlags** valor quando você cria um objeto de fábrica.

|||
|-|-|
|`FactoryCacheDefault`|A política de cache do `Module` objeto é usado.|
|`FactoryCacheEnabled`|Habilita o cache de fábrica independentemente do `ModuleType` parâmetro de modelo que é usado para criar um `Module` objeto.|
|`FactoryCacheDisabled`|Desabilita o cache de fábrica independentemente do `ModuleType` parâmetro de modelo que é usado para criar um `Module` objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)