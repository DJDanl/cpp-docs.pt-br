---
title: Classe affinity_partitioner | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- affinity_partitioner
- PPL/concurrency::affinity_partitioner
- PPL/concurrency::affinity_partitioner::affinity_partitioner
dev_langs:
- C++
helpviewer_keywords:
- affinity_partitioner class
ms.assetid: 31bf7bb1-bd01-491c-9760-d9d60edfccad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9b1254b316a52bd3e61b3cafd81ba2e89ee88b62
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444639"
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

##  <a name="dtor"></a> ~ affinity_partitioner

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
