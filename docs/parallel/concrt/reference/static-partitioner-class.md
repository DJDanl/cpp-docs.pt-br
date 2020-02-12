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
ms.openlocfilehash: 7a58daa27bc7a2f51f78a3068a2f152979ffdd72
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142689"
---
# <a name="static_partitioner-class"></a>Classe static_partitioner

A classe `static_partitioner` representa um particionamento estático do intervalo iterado por `parallel_for`. O particionador divide o intervalo em tantas partes quanto há trabalhadores disponíveis para o Agendador subjacente.

## <a name="syntax"></a>Sintaxe

```cpp
class static_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[static_partitioner](#ctor)|Constrói um objeto `static_partitioner`.|
|[~ static_partitioner destruidor](#dtor)|Destrói um objeto `static_partitioner`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`static_partitioner`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ static_partitioner

Destrói um objeto `static_partitioner`.

```cpp
~static_partitioner();
```

## <a name="ctor"></a>static_partitioner

Constrói um objeto `static_partitioner`.

```cpp
static_partitioner();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
