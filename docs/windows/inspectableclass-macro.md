---
title: Macro InspectableClass
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::InspectableClass
ms.assetid: ff390b26-58cc-424f-87ac-1fe3cc692b59
ms.openlocfilehash: 55d5aed96ff7c8b01142f8d4de81a431fdfcc2d5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50631582"
---
# <a name="inspectableclass-macro"></a>Macro InspectableClass

Define o nível de confiança e o nome de classe do tempo de execução.

## <a name="syntax"></a>Sintaxe

```cpp
InspectableClass(
   runtimeClassName,
   trustLevel)
```

### <a name="parameters"></a>Parâmetros

*runtimeClassName*<br/>
O nome textual completo da classe de tempo de execução.

*trustLevel*<br/>
Um dos [TrustLevel](https://msdn.microsoft.com/library/br224625.aspx) valores enumerados.

## <a name="remarks"></a>Comentários

O **InspectableClass** macro pode ser usada somente com tipos de tempo de execução do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe RuntimeClass](../windows/runtimeclass-class.md)