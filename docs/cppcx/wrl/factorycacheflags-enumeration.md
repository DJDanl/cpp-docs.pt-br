---
title: Enumeração FactoryCacheFlags
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::FactoryCacheFlags
ms.assetid: 6f54258f-0144-4264-9608-414e5905f6fb
ms.openlocfilehash: 3381b2bcfcbf298270b547199ae614291855a2f7
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88843268"
---
# <a name="factorycacheflags-enumeration"></a>Enumeração FactoryCacheFlags

Determina se os objetos de fábrica são armazenados em cache.

## <a name="syntax"></a>Sintaxe

```cpp
enum FactoryCacheFlags;
```

## <a name="remarks"></a>Comentários

Por padrão, a política de cache de fábrica é especificada como o parâmetro de modelo de [módulotype](moduletype-enumeration.md) quando você cria um objeto de [módulo](module-class.md) . Para substituir essa política, especifique um valor de **FactoryCacheFlags** ao criar um objeto de fábrica.

| Política | Descrição |
|-|-|
|`FactoryCacheDefault`|A política de cache do `Module` objeto é usada.|
|`FactoryCacheEnabled`|Habilita o Caching de fábrica, independentemente do `ModuleType` parâmetro de modelo usado para criar um `Module` objeto.|
|`FactoryCacheDisabled`|Desabilita o Caching de fábrica, independentemente do `ModuleType` parâmetro de modelo usado para criar um `Module` objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft:: WRL](microsoft-wrl-namespace.md)
