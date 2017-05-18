---
title: Classe affinity_partitioner | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- affinity_partitioner
- PPL/concurrency::affinity_partitioner
- PPL/concurrency::affinity_partitioner::affinity_partitioner
dev_langs:
- C++
helpviewer_keywords:
- affinity_partitioner class
ms.assetid: 31bf7bb1-bd01-491c-9760-d9d60edfccad
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 066557d522bc18237ccc484be8b59dc53b7e2905
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="affinitypartitioner-class"></a>Classe affinity_partitioner
O `affinity_partitioner` classe é semelhante de `static_partitioner` classe, mas ele melhora a afinidade de cache, sua escolha de mapeamento de subintervalos para threads de trabalho. Ele pode melhorar significativamente o desempenho quando um loop é executado novamente o mesmo conjunto de dados e os dados couberem no cache. Observe que o mesmo `affinity_partitioner` objeto deve ser usado com as iterações subsequentes de um loop paralelo é executado em um conjunto de dados específico, para se beneficiar de localidade dos dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class affinity_partitioner;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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

