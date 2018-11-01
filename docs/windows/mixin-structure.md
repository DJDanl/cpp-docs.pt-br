---
title: Estrutura MixIn
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::MixIn
helpviewer_keywords:
- MixIn structure
ms.assetid: 47e2df9b-3a2e-4ae8-8ba3-b1fd3aa73566
ms.openlocfilehash: e6c4fb2abd6c27f8feec4357e17ef71b385cb7a2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50464919"
---
# <a name="mixin-structure"></a>Estrutura MixIn

Garante que uma classe de tempo de execução deriva de interfaces do COM clássico, em seguida e as interfaces de tempo de execução do Windows, se houver.

## <a name="syntax"></a>Sintaxe

```cpp
template<
    typename Derived,
    typename MixInType,
    bool hasImplements = __is_base_of(Details::ImplementsBase, MixInType)
>
struct MixIn;
```

### <a name="parameters"></a>Parâmetros

*Derivado*<br/>
Um tipo derivado de [implementa](../windows/implements-structure.md) estrutura.

*MixInType*<br/>
Um tipo base.

*hasImplements*<br/>
**Verdadeiro** se *MixInType* é derivado do tipo base; a implementação atual **falsos** caso contrário.

## <a name="remarks"></a>Comentários

Se uma classe é derivada de tempo de execução do Windows e interfaces de classe COM, a lista de declarações de classe deve primeiro liste qualquer interface de tempo de execução do Windows e, em seguida, interfaces de qualquer COM clássico. **Mescla** garante que as interfaces são especificadas na ordem correta.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MixIn`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)