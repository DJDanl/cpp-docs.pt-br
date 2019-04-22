---
title: Estrutura InterfaceList
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceList
helpviewer_keywords:
- InterfaceList structure
ms.assetid: 6ec3228d-eb3e-4b7e-aef1-7dcf17bdf61a
ms.openlocfilehash: 745348e81888b5a87c57fbb99d397fcd423c3ee1
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59025543"
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