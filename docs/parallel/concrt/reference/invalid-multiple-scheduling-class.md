---
title: Classe invalid_multiple_scheduling | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- invalid_multiple_scheduling
- CONCRT/concurrency::invalid_multiple_scheduling
- CONCRT/concurrency::invalid_multiple_scheduling::invalid_multiple_scheduling
dev_langs: C++
helpviewer_keywords: invalid_multiple_scheduling class
ms.assetid: e9a47cb7-a778-4df7-92b0-3752119fd4c7
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: aa021ec655162cb75837ac1475e5cb9094f79fa8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="invalidmultiplescheduling-class"></a>Classe invalid_multiple_scheduling
Esta classe descreve uma exceção lançada quando um `task_handle` objeto é agendada várias vezes usando o `run` método de um `task_group` ou `structured_task_group` objeto sem uma chamada intermediário para o `wait` ou `run_and_wait` métodos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_multiple_scheduling : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[invalid_multiple_scheduling](#ctor)|Sobrecarregado. Constrói uma `invalid_multiple_scheduling` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_multiple_scheduling`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>invalid_multiple_scheduling 

 Constrói uma `invalid_multiple_scheduling` objeto.  
  
```
explicit _CRTIMP invalid_multiple_scheduling(_In_z_ const char* _Message) throw();

invalid_multiple_scheduling() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe task_handle](task-handle-class.md)   
 [Classe task_group](task-group-class.md)   
 [executar](task-group-class.md)   
 [Aguarde](task-group-class.md)   
 [run_and_wait](task-group-class.md)   
 [Classe structured_task_group](structured-task-group-class.md)
