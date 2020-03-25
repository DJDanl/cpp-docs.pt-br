---
title: Enumeração CancelTransitionPolicy
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::CancelTransitionPolicy::TransitionFromCanceled
- module/Microsoft::WRL::CancelTransitionPolicy::RemainCanceled
- module/Microsoft::WRL::CancelTransitionPolicy
helpviewer_keywords:
- CancelTransitionPolicy Enumeration
ms.assetid: 5de49f7d-e5e3-43e9-bbca-666caf226cef
ms.openlocfilehash: e820b3fffb4a00e95a1210a5c0beb3229c6d1657
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214117"
---
# <a name="canceltransitionpolicy-enumeration"></a>Enumeração CancelTransitionPolicy

Indica como uma operação assíncrona tenta fazer a transição para um estado de terminal de concluído ou o erro deve se comportar com relação a um estado cancelado solicitado pelo cliente.

## <a name="syntax"></a>Sintaxe

```cpp
enum CancelTransitionPolicy;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`RemainCanceled`|Se a operação assíncrona estiver atualmente em um estado cancelado solicitado pelo cliente, isso indica que ele permanecerá no estado cancelado em vez de fazer a transição para um terminal concluído ou estado de erro.|
|`TransitionFromCanceled`|Se a operação assíncrona estiver atualmente em um estado cancelado solicitado pelo cliente, isso indicará que o estado deve fazer a transição desse estado cancelado para o estado do terminal de concluído ou erro, conforme determinado pela chamada que utiliza esse sinalizador.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Async. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
