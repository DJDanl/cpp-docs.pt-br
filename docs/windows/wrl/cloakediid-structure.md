---
title: Estrutura CloakedIid
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::CloakedIid
helpviewer_keywords:
- CloakedIid structure
ms.assetid: 82e0e377-ca3a-46bc-b850-ae2c46c15bb5
ms.openlocfilehash: a47b9e5fdb4a6e7f49b9704244b4e62e3647a04e
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335456"
---
# <a name="cloakediid-structure"></a>Estrutura CloakedIid

Indica para o `RuntimeClass`, `Implements` e `ChainInterfaces` que a interface especificada não está acessível na lista de IID de modelos.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
struct CloakedIid : T;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
A interface que está oculto (encoberta).

## <a name="remarks"></a>Comentários

A seguir está um exemplo de como **CloakedIid** é usado: `struct MyRuntimeClass : RuntimeClass<CloakedIid<IMyCloakedInterface>> {}`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`CloakedIid`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)