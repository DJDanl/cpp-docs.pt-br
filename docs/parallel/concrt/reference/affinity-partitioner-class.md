---
title: Classe affinity_partitioner
ms.date: 11/04/2016
f1_keywords:
- affinity_partitioner
- PPL/concurrency::affinity_partitioner
- PPL/concurrency::affinity_partitioner::affinity_partitioner
helpviewer_keywords:
- affinity_partitioner class
ms.assetid: 31bf7bb1-bd01-491c-9760-d9d60edfccad
ms.openlocfilehash: 0ae6bbee49d1b8873190a7054e55f65b40b31b13
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142883"
---
# <a name="affinity_partitioner-class"></a>Classe affinity_partitioner

A classe `affinity_partitioner` é semelhante à classe `static_partitioner`, mas melhora a afinidade de cache por sua escolha de mapear subintervalos para threads de trabalho. Ele pode melhorar significativamente o desempenho quando um loop é executado novamente no mesmo conjunto de dados e os dados se ajustam ao cache. Observe que o mesmo objeto `affinity_partitioner` deve ser usado com iterações subsequentes de um loop paralelo executado em um conjunto de dados específico, para se beneficiar da localidade de dados.

## <a name="syntax"></a>Sintaxe

```cpp
class affinity_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[affinity_partitioner](#ctor)|Constrói um objeto `affinity_partitioner`.|
|[~ affinity_partitioner destruidor](#dtor)|Destrói um objeto `affinity_partitioner`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`affinity_partitioner`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ affinity_partitioner

Destrói um objeto `affinity_partitioner`.

```cpp
~affinity_partitioner();
```

## <a name="ctor"></a>affinity_partitioner

Constrói um objeto `affinity_partitioner`.

```cpp
affinity_partitioner();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
