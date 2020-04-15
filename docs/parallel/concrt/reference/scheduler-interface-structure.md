---
title: Estrutura scheduler_interface
ms.date: 11/04/2016
f1_keywords:
- scheduler_interface
- PPLINTERFACE/concurrency::scheduler_interface
- PPLINTERFACE/concurrency::scheduler_interface::scheduler_interface::schedule
ms.assetid: 4de61c78-a2c6-4698-bd47-964baf7fa287
ms.openlocfilehash: da2ebc2f9c2878baefcfa792bac08f420dbbb281
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358786"
---
# <a name="scheduler_interface-structure"></a>Estrutura scheduler_interface

Interface do agendador

## <a name="syntax"></a>Sintaxe

```cpp
struct __declspec(novtable) scheduler_interface;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_interface::programação](#schedule)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`scheduler_interface`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** pplinterface.h

**Namespace:** concurrency

## <a name="scheduler_interfaceschedule-method"></a><a name="schedule"></a>scheduler_interface::método de agendamento

```cpp
virtual void schedule(
    TaskProc_t,
void*) = 0;
```

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
