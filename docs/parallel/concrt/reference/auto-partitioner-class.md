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
ms.openlocfilehash: 9e4701c39512613bd7525c2cc0e3d24a57e7689d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50644919"
---
# <a name="autopartitioner-class"></a>Classe auto_partitioner

O `auto_partitioner` classe representa o método padrão `parallel_for`, `parallel_for_each` e `parallel_transform` usar para particionar o intervalo que itera em. Esse método de particionamento utiliza uma variam de roubo de balanceamento de carga, bem como por-iterar cancelamento.

## <a name="syntax"></a>Sintaxe

```
class auto_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[auto_partitioner](#ctor)|Constrói um objeto `auto_partitioner`.|
|[~ auto_partitioner destruidor](#dtor)|Destrói um objeto `auto_partitioner`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`auto_partitioner`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~ auto_partitioner

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
