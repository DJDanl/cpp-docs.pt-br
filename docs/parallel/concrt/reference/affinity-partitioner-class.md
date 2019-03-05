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
ms.openlocfilehash: dac25755c388e5297ce671da09b7938f09f1ef03
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57262786"
---
# <a name="affinitypartitioner-class"></a>Classe affinity_partitioner

O `affinity_partitioner` classe é semelhante ao `static_partitioner` classe, mas ele melhora a afinidade de cache, sua opção de mapeamento de subintervalos para threads de trabalho. Ele pode melhorar o desempenho significativamente quando um loop é executado novamente no mesmo conjunto de dados e os dados se encaixa no cache. Observe que o mesmo `affinity_partitioner` objeto deve ser usado com as iterações subsequentes de um loop paralelo que é executado em um conjunto de dados específico, para se beneficiar de localidade dos dados.

## <a name="syntax"></a>Sintaxe

```
class affinity_partitioner;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[affinity_partitioner](#ctor)|Constrói um `affinity_partitioner` objeto.|
|[~ affinity_partitioner destruidor](#dtor)|Destrói um `affinity_partitioner` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`affinity_partitioner`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~affinity_partitioner

Destrói um `affinity_partitioner` objeto.

```
~affinity_partitioner();
```

##  <a name="ctor"></a> affinity_partitioner

Constrói um `affinity_partitioner` objeto.

```
affinity_partitioner();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
