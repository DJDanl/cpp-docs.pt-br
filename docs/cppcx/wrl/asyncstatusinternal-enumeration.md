---
title: Enumeração AsyncStatusInternal
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::Details::AsyncStatusInternal
helpviewer_keywords:
- AsyncStatusInternal enumeration
ms.assetid: b783923f-3f1c-4487-9384-be572cbc62d7
ms.openlocfilehash: 0eadd1e3a287feecd36b00b231b42c31218352c1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214143"
---
# <a name="asyncstatusinternal-enumeration"></a>Enumeração AsyncStatusInternal

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
enum AsyncStatusInternal;
```

## <a name="remarks"></a>Comentários

Especifica um mapeamento entre enumerações internas para o estado de operações assíncronas e a enumeração de `Windows::Foundation::AsyncStatus`.

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

**Cabeçalho:** Async. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
