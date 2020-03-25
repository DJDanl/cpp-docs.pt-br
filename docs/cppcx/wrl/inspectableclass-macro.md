---
title: Macro InspectableClass
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::InspectableClass
ms.assetid: ff390b26-58cc-424f-87ac-1fe3cc692b59
ms.openlocfilehash: 755a8f58ffc290d73d6060b0b0924905ecbf6028
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213870"
---
# <a name="inspectableclass-macro"></a>Macro InspectableClass

Define o nome da classe de tempo de execução e o nível de confiança.

## <a name="syntax"></a>Sintaxe

```cpp
InspectableClass(
   runtimeClassName,
   trustLevel)
```

### <a name="parameters"></a>parâmetros

*runtimeClassName*<br/>
O nome textual completo da classe Runtime.

*trustLevel*<br/>
Um dos valores enumerados do [TrustLevel](/windows/win32/api/inspectable/ne-inspectable-trustlevel) .

## <a name="remarks"></a>Comentários

A macro **InspectableClass** pode ser usada somente com tipos de Windows Runtime.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Classe RuntimeClass](runtimeclass-class.md)
