---
title: Estrutura scheduler_interface
ms.date: 11/04/2016
f1_keywords:
- scheduler_interface
- PPLINTERFACE/concurrency::scheduler_interface
- PPLINTERFACE/concurrency::scheduler_interface::scheduler_interface::schedule
ms.assetid: 4de61c78-a2c6-4698-bd47-964baf7fa287
ms.openlocfilehash: 99a3ea8b6ad1f23b4f3d54b7f2f406a3d115b374
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283365"
---
# <a name="schedulerinterface-structure"></a>Estrutura scheduler_interface

Interface de Agendador

## <a name="syntax"></a>Sintaxe

```
struct __declspec(novtable) scheduler_interface;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_interface::schedule](#schedule)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`scheduler_interface`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** pplinterface. h

**Namespace:** simultaneidade

##  <a name="schedule"></a>  scheduler_interface:: Schedule método

```
virtual void schedule(
    TaskProc_t,
void*) = 0;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
