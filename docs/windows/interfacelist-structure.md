---
title: Estrutura InterfaceList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceList
dev_langs:
- C++
helpviewer_keywords:
- InterfaceList structure
ms.assetid: 6ec3228d-eb3e-4b7e-aef1-7dcf17bdf61a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7ce497c621f116c4755e8b47d148e24a9043b46b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46374732"
---
# <a name="interfacelist-structure"></a>Estrutura InterfaceList

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename T,
   typename U
>
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

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)