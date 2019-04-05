---
title: Enumeração AsyncResultType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncResultType
helpviewer_keywords:
- AsyncResultType enumeration
ms.assetid: 4195d234-3f3f-4363-9118-6ad2a7551cf2
ms.openlocfilehash: d3f99fa85a777ae8361ed6f7cb82fe97ddd8d667
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59028046"
---
# <a name="asyncresulttype-enumeration"></a>Enumeração AsyncResultType

Especifica o tipo de resultado retornado pelo `GetResults()` método.

## <a name="syntax"></a>Sintaxe

```cpp
enum AsyncResultType;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`MultipleResults`|Um conjunto de vários resultados, que são apresentadas progressivamente entre `Start` estado e antes de `Close()` é chamado.|
|`SingleResult`|Um único resultado é apresentado após o `Complete` evento ocorre.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)