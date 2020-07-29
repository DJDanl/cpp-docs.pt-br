---
title: Estrutura MixIn
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::MixIn
helpviewer_keywords:
- MixIn structure
ms.assetid: 47e2df9b-3a2e-4ae8-8ba3-b1fd3aa73566
ms.openlocfilehash: cfa03706bc6030b337009f7228466a26e242aa6b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221530"
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

*Derivado*<br/>
Um tipo derivado da estrutura [Implements](implements-structure.md) .

*MixInType*<br/>
Um tipo base.

*hasImplements*<br/>
**`true`** Se *MixInType* for derivado da implementação atual, o tipo base; **`false`** caso contrário.

## <a name="remarks"></a>Comentários

Se uma classe for derivada de Windows Runtime e de interfaces COM de classe, a lista de declaração de classe deverá primeiro listar as interfaces de Windows Runtime e, em seguida, as interfaces COM clássicas. **Mescla** garante que as interfaces sejam especificadas na ordem correta.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MixIn`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft:: WRL](microsoft-wrl-namespace.md)
