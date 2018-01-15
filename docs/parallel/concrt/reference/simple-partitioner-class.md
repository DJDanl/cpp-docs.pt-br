---
title: Classe simple_partitioner | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- simple_partitioner
- PPL/concurrency::simple_partitioner
- PPL/concurrency::simple_partitioner::simple_partitioner
dev_langs: C++
helpviewer_keywords: simple_partitioner class
ms.assetid: d7e997af-54d1-43f5-abe0-def72df6edb3
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f1d509afd9cddd8ac119d12ce2a0cb88906e83aa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="simplepartitioner-class"></a>Classe simple_partitioner
O `simple_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em partes, de modo que cada parte tem pelo menos o número de iterações especificado pelo tamanho do bloco.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class simple_partitioner;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[simple_partitioner](#ctor)|Constrói um objeto `simple_partitioner`.|  
|[~ simple_partitioner destruidor](#dtor)|Destrói um objeto `simple_partitioner`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `simple_partitioner`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="dtor"></a>~ simple_partitioner 

 Destrói um objeto `simple_partitioner`.  
  
```
~simple_partitioner();
```  
  
##  <a name="ctor"></a>simple_partitioner 

 Constrói um objeto `simple_partitioner`.  
  
```
explicit simple_partitioner(_Size_type _Chunk_size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Chunk_size`  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
