---
title: Classe static_partitioner | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- static_partitioner
- PPL/concurrency::static_partitioner
- PPL/concurrency::static_partitioner::static_partitioner
dev_langs:
- C++
helpviewer_keywords:
- static_partitioner class
ms.assetid: 2b3dbdf0-6eb9-49f6-8639-03df1d974143
caps.latest.revision: 8
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
ms.openlocfilehash: 84cdbb30068f8dd9d2a1130e53d06d9b718b0c02
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="staticpartitioner-class"></a>Classe static_partitioner
O `static_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em quantos blocos há trabalhadores disponíveis para o Agendador underyling.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class static_partitioner;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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

