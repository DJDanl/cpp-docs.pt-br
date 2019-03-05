---
title: Classe static_partitioner
ms.date: 11/04/2016
f1_keywords:
- static_partitioner
- PPL/concurrency::static_partitioner
- PPL/concurrency::static_partitioner::static_partitioner
helpviewer_keywords:
- static_partitioner class
ms.assetid: 2b3dbdf0-6eb9-49f6-8639-03df1d974143
ms.openlocfilehash: 5120e3c53dc00ba9d5c3a4218efe1dcfb8f92e28
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287630"
---
# <a name="staticpartitioner-class"></a>Classe static_partitioner

O `static_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em quantos blocos há trabalhadores disponíveis para o Agendador underyling.

## <a name="syntax"></a>Sintaxe

```
class static_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[static_partitioner](#ctor)|Constrói um objeto `static_partitioner`.|
|[~ static_partitioner destruidor](#dtor)|Destrói um objeto `static_partitioner`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`static_partitioner`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~static_partitioner

Destrói um objeto `static_partitioner`.

```
~static_partitioner();
```

##  <a name="ctor"></a> static_partitioner

Constrói um objeto `static_partitioner`.

```
static_partitioner();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
