---
title: Classe invalid_multiple_scheduling | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::invalid_multiple_scheduling
dev_langs:
- C++
helpviewer_keywords:
- invalid_multiple_scheduling class
ms.assetid: e9a47cb7-a778-4df7-92b0-3752119fd4c7
caps.latest.revision: 19
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
ms.openlocfilehash: 762648e65a7fcbda29daf31412e42bbd0e63f3d6
ms.lasthandoff: 02/25/2017

---
# <a name="invalidmultiplescheduling-class"></a>Classe invalid_multiple_scheduling
Esta classe descreve uma exceção gerada quando uma `task_handle` objeto é agendada várias vezes usando o `run` método de um `task_group` ou `structured_task_group` objeto sem uma chamada intermediária para o `wait` ou `run_and_wait` métodos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_multiple_scheduling : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor invalid_multiple_scheduling](#ctor)|Sobrecarregado. Constrói uma `invalid_multiple_scheduling` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_multiple_scheduling`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-invalidmultiplescheduling"></a><a name="ctor"></a>invalid_multiple_scheduling 

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
 [o método Run](task-group-class.md)   
 [Método Wait](task-group-class.md)   
 [Método run_and_wait](task-group-class.md)   
 [Classe structured_task_group](structured-task-group-class.md)

