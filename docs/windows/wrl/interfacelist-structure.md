---
title: Estrutura InterfaceList
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceList
helpviewer_keywords:
- InterfaceList structure
ms.assetid: 6ec3228d-eb3e-4b7e-aef1-7dcf17bdf61a
ms.openlocfilehash: 70565081338f953abb65d2cdc7c5f1eb869f75e5
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335668"
---
# <a name="interfacelist-structure"></a>Estrutura InterfaceList

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T, typename U>
struct InterfaceList;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um nome de interface; a primeira interface na lista recursiva.

*U*<br/>
Um nome de interface; as interfaces restantes na lista recursiva.

## <a name="remarks"></a>Comentários

Usado para criar uma lista recursiva de interfaces.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`FirstT`|Sinônimo do parâmetro de modelo *T*.|
|`RestT`|Sinônimo do parâmetro de modelo *U*.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InterfaceList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)