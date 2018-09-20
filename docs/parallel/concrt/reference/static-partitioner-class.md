---
title: Classe static_partitioner | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- static_partitioner
- PPL/concurrency::static_partitioner
- PPL/concurrency::static_partitioner::static_partitioner
dev_langs:
- C++
helpviewer_keywords:
- static_partitioner class
ms.assetid: 2b3dbdf0-6eb9-49f6-8639-03df1d974143
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: de1b63cf24fbc84130302fcbae2cb965e8d00597
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46376014"
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
