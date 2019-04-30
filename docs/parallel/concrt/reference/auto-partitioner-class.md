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
ms.openlocfilehash: 2d8bbb8e8af17dd19953487c47e5fd40343fe349
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391082"
---
# <a name="autopartitioner-class"></a>Classe auto_partitioner

O `auto_partitioner` classe representa o método padrão `parallel_for`, `parallel_for_each` e `parallel_transform` usar para particionar o intervalo que itera em. Esse método de particionamento utiliza uma variam de roubo de balanceamento de carga, bem como por-iterar cancelamento.

## <a name="syntax"></a>Sintaxe

```
class auto_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[auto_partitioner](#ctor)|Constrói um objeto `auto_partitioner`.|
|[~auto_partitioner Destructor](#dtor)|Destrói um objeto `auto_partitioner`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`auto_partitioner`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~auto_partitioner

Destrói um objeto `auto_partitioner`.

```
~auto_partitioner();
```

##  <a name="ctor"></a> auto_partitioner

Constrói um objeto `auto_partitioner`.

```
auto_partitioner();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
