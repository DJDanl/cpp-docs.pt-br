---
title: Enumeração FactoryCacheFlags
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::FactoryCacheFlags
ms.assetid: 6f54258f-0144-4264-9608-414e5905f6fb
ms.openlocfilehash: 6fecacd6038d1c41e57515307c1b810d0623d16f
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335509"
---
# <a name="factorycacheflags-enumeration"></a>Enumeração FactoryCacheFlags

Determina se os objetos de fábrica são armazenados em cache.

## <a name="syntax"></a>Sintaxe

```cpp
enum FactoryCacheFlags;
```

## <a name="remarks"></a>Comentários

Por padrão, a política de cache de fábrica é especificada como o [ModuleType](moduletype-enumeration.md) parâmetro de modelo quando você cria um [módulo](module-class.md) objeto. Para substituir essa política, especifique um **FactoryCacheFlags** valor quando você cria um objeto de fábrica.

|||
|-|-|
|`FactoryCacheDefault`|A política de cache do `Module` objeto é usado.|
|`FactoryCacheEnabled`|Habilita o cache de fábrica independentemente do `ModuleType` parâmetro de modelo que é usado para criar um `Module` objeto.|
|`FactoryCacheDisabled`|Desabilita o cache de fábrica independentemente do `ModuleType` parâmetro de modelo que é usado para criar um `Module` objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)