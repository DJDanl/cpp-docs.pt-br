---
title: Macro InspectableClass
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::InspectableClass
ms.assetid: ff390b26-58cc-424f-87ac-1fe3cc692b59
ms.openlocfilehash: cedf395ae98a423e0335851327b5fdda1a4bc7d6
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783964"
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
Um dos [TrustLevel](/windows/desktop/api/inspectable/ne-inspectable-trustlevel) valores enumerados.

## <a name="remarks"></a>Comentários

O **InspectableClass** macro pode ser usada somente com tipos de tempo de execução do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe RuntimeClass](runtimeclass-class.md)