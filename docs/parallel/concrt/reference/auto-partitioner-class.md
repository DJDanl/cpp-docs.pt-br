---
title: Classe auto_partitioner
ms.date: 11/04/2016
f1_keywords:
- auto_partitioner
- PPL/concurrency::auto_partitioner
- PPL/concurrency::auto_partitioner::auto_partitioner
helpviewer_keywords:
- auto_partitioner class
ms.assetid: 7cc08e5d-20b4-47a4-b4b5-c214a78f5a9e
ms.openlocfilehash: 4d1d8f19069412240de8e9d69cdcfb34618f2796
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142859"
---
# <a name="auto_partitioner-class"></a>Classe auto_partitioner

A classe `auto_partitioner` representa o método padrão `parallel_for`, `parallel_for_each` e `parallel_transform` usado para particionar o intervalo no qual itera. Esse método de particionamento emprega o furto de intervalo para balanceamento de carga, bem como o cancelamento por iteração.

## <a name="syntax"></a>Sintaxe

```cpp
class auto_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[auto_partitioner](#ctor)|Constrói um objeto `auto_partitioner`.|
|[~ auto_partitioner destruidor](#dtor)|Destrói um objeto `auto_partitioner`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`auto_partitioner`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ auto_partitioner

Destrói um objeto `auto_partitioner`.

```cpp
~auto_partitioner();
```

## <a name="ctor"></a>auto_partitioner

Constrói um objeto `auto_partitioner`.

```cpp
auto_partitioner();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
