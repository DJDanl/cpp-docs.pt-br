---
title: Estrutura MixIn
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::MixIn
helpviewer_keywords:
- MixIn structure
ms.assetid: 47e2df9b-3a2e-4ae8-8ba3-b1fd3aa73566
ms.openlocfilehash: b302d6e08e401a24b465508d5ddabcae8b16bd8f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213688"
---
# <a name="mixin-structure"></a>Estrutura MixIn

Garante que uma classe de tempo de execução derive de interfaces Windows Runtime, se houver, e as interfaces COM clássicas.

## <a name="syntax"></a>Sintaxe

```cpp
template<
    typename Derived,
    typename MixInType,
    bool hasImplements = __is_base_of(Details::ImplementsBase, MixInType)
>
struct MixIn;
```

### <a name="parameters"></a>parâmetros

*Gerados*<br/>
Um tipo derivado da estrutura [Implements](implements-structure.md) .

*MixInType*<br/>
Um tipo base.

*hasImplements*<br/>
**true** se *MixInType* for derivado da implementação atual do tipo base; caso contrário, **false** .

## <a name="remarks"></a>Comentários

Se uma classe for derivada de Windows Runtime e de interfaces COM de classe, a lista de declaração de classe deverá primeiro listar as interfaces de Windows Runtime e, em seguida, as interfaces COM clássicas. **Mescla** garante que as interfaces sejam especificadas na ordem correta.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MixIn`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
