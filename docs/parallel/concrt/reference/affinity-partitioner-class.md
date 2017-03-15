---
title: Classe affinity_partitioner | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ppl/concurrency::affinity_partitioner
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
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 92da56fd5b84537c2fa01a252dfee202c729cc96
ms.lasthandoff: 02/25/2017

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
|[Construtor affinity_partitioner](#ctor)|Constrói uma `affinity_partitioner` objeto.|  
|[~ affinity_partitioner destruidor](#dtor)|Destrói um `affinity_partitioner` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `affinity_partitioner`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namedtora-affinitypartitioner"></a><a name="dtor"></a>~ affinity_partitioner 

 Destrói um `affinity_partitioner` objeto.  
  
```
~affinity_partitioner();
```  
  
##  <a name="a-namectora-affinitypartitioner"></a><a name="ctor"></a>affinity_partitioner 

 Constrói uma `affinity_partitioner` objeto.  
  
```
affinity_partitioner();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

