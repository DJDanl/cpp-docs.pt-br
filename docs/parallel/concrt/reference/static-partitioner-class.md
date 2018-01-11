---
title: Classe static_partitioner | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- static_partitioner
- PPL/concurrency::static_partitioner
- PPL/concurrency::static_partitioner::static_partitioner
dev_langs: C++
helpviewer_keywords: static_partitioner class
ms.assetid: 2b3dbdf0-6eb9-49f6-8639-03df1d974143
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2c7f41a2d2a592bff5e1f2217b39b6047d5093ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="staticpartitioner-class"></a>Classe static_partitioner
O `static_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em blocos há trabalhadores disponíveis para o Agendador underyling.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class static_partitioner;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[static_partitioner](#ctor)|Constrói um objeto `static_partitioner`.|  
|[~ static_partitioner destruidor](#dtor)|Destrói um objeto `static_partitioner`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `static_partitioner`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="dtor"></a>~ static_partitioner 

 Destrói um objeto `static_partitioner`.  
  
```
~static_partitioner();
```  
  
##  <a name="ctor"></a>static_partitioner 

 Constrói um objeto `static_partitioner`.  
  
```
static_partitioner();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
