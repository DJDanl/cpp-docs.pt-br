---
title: Estrutura scheduler_interface | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- scheduler_interface
- PPLINTERFACE/concurrency::scheduler_interface
- PPLINTERFACE/concurrency::scheduler_interface::scheduler_interface::schedule
dev_langs: C++
ms.assetid: 4de61c78-a2c6-4698-bd47-964baf7fa287
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 69fa7e0bb33139aa512d163b252957abf8d72000
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="schedulerinterface-structure"></a>Estrutura scheduler_interface
Interface do Agendador  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct __declspec(novtable) scheduler_interface;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_interface:: Schedule](#schedule)||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `scheduler_interface`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** pplinterface.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="schedule"></a>scheduler_interface:: método Schedule  
  
```
virtual void schedule(
    TaskProc_t,
 void*) = 0;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
