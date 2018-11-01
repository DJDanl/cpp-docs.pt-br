---
title: Atributo Platform::Metadata::DefaultMemberAttribute
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Metadata::DefaultMemberAttribute
helpviewer_keywords:
- Platform::Metadata::DefaultMemberAttribute Attribute
ms.assetid: d8abda01-c257-4371-aec4-541d4825e0af
ms.openlocfilehash: a4b3d5e8ab5d6ce254560bc84daceac74e2c9ca1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50486652"
---
# <a name="platformmetadatadefaultmemberattribute-attribute"></a>Atributo Platform::Metadata::DefaultMemberAttribute

Indica a função preferencial a ser invocada dentre várias funções sobrecarregadas possíveis.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class DefaultMember abstract : Attribute
```

## <a name="inheritance"></a>Herança

[Platform::Object](../cppcx/platform-object-class.md)

[Platform::Metadata::Attribute](../cppcx/platform-metadata-attribute-attribute.md)

### <a name="remarks"></a>Comentários

Aplique o atributo DefaultMember a um método que será consumido por um aplicativo JavaScript.

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform::Metadata

**Metadados:** platform.winmd

## <a name="see-also"></a>Consulte também

[Namespace Platform::Metadata](../cppcx/platform-metadata-namespace.md)