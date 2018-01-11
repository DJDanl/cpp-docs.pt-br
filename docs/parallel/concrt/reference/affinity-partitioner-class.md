---
title: Classe affinity_partitioner | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- affinity_partitioner
- PPL/concurrency::affinity_partitioner
- PPL/concurrency::affinity_partitioner::affinity_partitioner
dev_langs: C++
helpviewer_keywords: affinity_partitioner class
ms.assetid: 31bf7bb1-bd01-491c-9760-d9d60edfccad
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 25d6edb53a291c7b3a86f8583b78ab3efdce7842
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="affinitypartitioner-class"></a>Classe affinity_partitioner
O `affinity_partitioner` classe é semelhante de `static_partitioner` classe, mas ele melhora a afinidade de cache por sua opção de mapeamento de subintervalos para threads de trabalho. Ela pode melhorar o desempenho significativamente quando um loop é executado novamente em um mesmo conjunto de dados, e os dados se encaixa no cache. Observe que o mesmo `affinity_partitioner` objeto deve ser usado com iterações subsequentes de um loop paralelo que é executado em um conjunto de dados específico, para se beneficiar com a localidade dos dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class affinity_partitioner;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[affinity_partitioner](#ctor)|Constrói uma `affinity_partitioner` objeto.|  
|[~ affinity_partitioner destruidor](#dtor)|Destrói um `affinity_partitioner` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `affinity_partitioner`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="dtor"></a>~ affinity_partitioner 

 Destrói um `affinity_partitioner` objeto.  
  
```
~affinity_partitioner();
```  
  
##  <a name="ctor"></a>affinity_partitioner 

 Constrói uma `affinity_partitioner` objeto.  
  
```
affinity_partitioner();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
