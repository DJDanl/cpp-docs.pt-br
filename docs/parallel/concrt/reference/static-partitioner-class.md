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
ms.openlocfilehash: a0d06326b2ecbf3c427ae24b45751f7053778a0b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50500887"
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

##  <a name="dtor"></a> ~ static_partitioner

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
