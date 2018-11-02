---
title: Classe simple_partitioner
ms.date: 11/04/2016
f1_keywords:
- simple_partitioner
- PPL/concurrency::simple_partitioner
- PPL/concurrency::simple_partitioner::simple_partitioner
helpviewer_keywords:
- simple_partitioner class
ms.assetid: d7e997af-54d1-43f5-abe0-def72df6edb3
ms.openlocfilehash: f3c5792a13d9e63a05ce6710dea77828f2510f0d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50522441"
---
# <a name="simplepartitioner-class"></a>Classe simple_partitioner

O `simple_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em partes, de modo que cada parte tem pelo menos o número de iterações especificado pelo tamanho do bloco.

## <a name="syntax"></a>Sintaxe

```
class simple_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[simple_partitioner](#ctor)|Constrói um objeto `simple_partitioner`.|
|[~ simple_partitioner destruidor](#dtor)|Destrói um objeto `simple_partitioner`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`simple_partitioner`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~ simple_partitioner

Destrói um objeto `simple_partitioner`.

```
~simple_partitioner();
```

##  <a name="ctor"></a> simple_partitioner

Constrói um objeto `simple_partitioner`.

```
explicit simple_partitioner(_Size_type _Chunk_size);
```

### <a name="parameters"></a>Parâmetros

*_Chunk_size*<br/>
O tamanho mínimo da partição.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
