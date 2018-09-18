---
title: Enumeração AsyncStatusInternal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::Details::AsyncStatusInternal
dev_langs:
- C++
helpviewer_keywords:
- AsyncStatusInternal enumeration
ms.assetid: b783923f-3f1c-4487-9384-be572cbc62d7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4c7751929a55993876034bb3c1918b82193681fc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016878"
---
# <a name="asyncstatusinternal-enumeration"></a>Enumeração AsyncStatusInternal

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
enum AsyncStatusInternal;
```

## <a name="remarks"></a>Comentários

Especifica um mapeamento entre enumerações internos para o estado das operações assíncronas e o `Windows::Foundation::AsyncStatus` enumeração.

## <a name="members"></a>Membros

`_Created`<br/>
Equivalente a `::Windows::Foundation::AsyncStatus::Created`

`_Started`<br/>
Equivalente a `::Windows::Foundation::AsyncStatus::Started`

`_Completed`<br/>
Equivalente a `::Windows::Foundation::AsyncStatus::Completed`

`_Cancelled`<br/>
Equivalente a `::Windows::Foundation::AsyncStatus::Cancelled`

`_Error`<br/>
Equivalente a `::Windows::Foundation::AsyncStatus::Error`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)