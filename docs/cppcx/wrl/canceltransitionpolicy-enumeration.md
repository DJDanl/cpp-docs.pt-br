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
ms.openlocfilehash: cfd8e25f98ec1001a8fbd287eaec12408b9f240e
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783720"
---
# <a name="canceltransitionpolicy-enumeration"></a>Enumeração CancelTransitionPolicy

Indica como uma operação assíncrona de tentar fazer a transição para um estado terminal de concluído ou erro deve se comportar em relação a um estado cancelado solicitado pelo cliente.

## <a name="syntax"></a>Sintaxe

```cpp
enum CancelTransitionPolicy;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`RemainCanceled`|Se a operação assíncrona está atualmente em um estado cancelado solicitado pelo cliente, isso indica que ele permanecerá no estado cancelado em vez de fazer a transição para um estado de erro ou de terminal concluída.|
|`TransitionFromCanceled`|Se a operação assíncrona está atualmente em um estado cancelado solicitado pelo cliente, isso indica que estado deve fazer a transição do estado cancelado para o estado terminal de concluído ou erro, conforme determinado pela chamada que utiliza esse sinalizador.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)