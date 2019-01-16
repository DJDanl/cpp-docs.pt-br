---
title: Estrutura MixIn
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::MixIn
helpviewer_keywords:
- MixIn structure
ms.assetid: 47e2df9b-3a2e-4ae8-8ba3-b1fd3aa73566
ms.openlocfilehash: d0306f4c497dd26e782b1ef2c012cb7d348db07f
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335502"
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
Um tipo derivado de [implementa](implements-structure.md) estrutura.

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

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)