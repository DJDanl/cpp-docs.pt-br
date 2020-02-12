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
ms.openlocfilehash: 503f36b90c5eb3319f9aa2d56528172ffa95bb11
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142506"
---
# <a name="simple_partitioner-class"></a>Classe simple_partitioner

A classe `simple_partitioner` representa um particionamento estático do intervalo iterado por `parallel_for`. O particionador divide o intervalo em partes de forma que cada parte tenha pelo menos o número de iterações especificado pelo tamanho da parte.

## <a name="syntax"></a>Sintaxe

```cpp
class simple_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[simple_partitioner](#ctor)|Constrói um objeto `simple_partitioner`.|
|[~ simple_partitioner destruidor](#dtor)|Destrói um objeto `simple_partitioner`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`simple_partitioner`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ simple_partitioner

Destrói um objeto `simple_partitioner`.

```cpp
~simple_partitioner();
```

## <a name="ctor"></a>simple_partitioner

Constrói um objeto `simple_partitioner`.

```cpp
explicit simple_partitioner(_Size_type _Chunk_size);
```

### <a name="parameters"></a>Parâmetros

*_Chunk_size*<br/>
O tamanho mínimo da partição.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
