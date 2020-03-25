---
title: Estrutura CloakedIid
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::CloakedIid
helpviewer_keywords:
- CloakedIid structure
ms.assetid: 82e0e377-ca3a-46bc-b850-ae2c46c15bb5
ms.openlocfilehash: 1cc9e79384bbf4aae44199c2f35331e3afd8fd8f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214104"
---
# <a name="cloakediid-structure"></a>Estrutura CloakedIid

Indica para os modelos de `RuntimeClass`, `Implements` e `ChainInterfaces` que a interface especificada não está acessível na lista de IID.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
struct CloakedIid : T;
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
A interface que está oculta (encoberta).

## <a name="remarks"></a>Comentários

Veja a seguir um exemplo de como o **CloakedIid** é usado: `struct MyRuntimeClass : RuntimeClass<CloakedIid<IMyCloakedInterface>> {}`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`CloakedIid`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
