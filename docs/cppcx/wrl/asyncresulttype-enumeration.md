---
title: Enumeração AsyncResultType
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncResultType
helpviewer_keywords:
- AsyncResultType enumeration
ms.assetid: 4195d234-3f3f-4363-9118-6ad2a7551cf2
ms.openlocfilehash: b8a2a9ec803fba1be0012fcb58bf3b42e78f9071
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214156"
---
# <a name="asyncresulttype-enumeration"></a>Enumeração AsyncResultType

Especifica o tipo de resultado retornado pelo método `GetResults()`.

## <a name="syntax"></a>Sintaxe

```cpp
enum AsyncResultType;
```

## <a name="members"></a>Membros

### <a name="values"></a>Valores

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`MultipleResults`|Um conjunto de vários resultados, que são apresentados progressivamente entre `Start` estado e antes de `Close()` ser chamado.|
|`SingleResult`|Um único resultado, que é apresentado após a ocorrência do evento `Complete`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Async. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
