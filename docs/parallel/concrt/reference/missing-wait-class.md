---
title: Classe missing_wait | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::missing_wait
dev_langs:
- C++
helpviewer_keywords:
- missing_wait class
ms.assetid: ff981875-bd43-47e3-806f-b03c9f418b18
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
ms.openlocfilehash: 7d29294f4ddce571451a72bf637526e5af283cff
ms.lasthandoff: 02/25/2017

---
# <a name="missingwait-class"></a>Classe missing_wait
Esta classe descreve uma exceção gerada quando há tarefas ainda está agendadas para ser um `task_group` ou `structured_task_group` do objeto no momento do objeto destruidor é executado. Essa exceção nunca será gerada se o destruidor for atingido devido a uma pilha de desenrolamento como resultado de uma exceção.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class missing_wait : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor missing_wait](#ctor)|Sobrecarregado. Constrói um objeto `missing_wait`.|  
  
## <a name="remarks"></a>Comentários  
 Ausência de fluxo de exceção, você é responsável por chamar o `wait` ou `run_and_wait` método de um `task_group` ou `structured_task_group` objeto antes de permitir que esse objeto para destruct. O tempo de execução lança esta exceção como uma indicação de que você se esqueceu de chamar o `wait` ou `run_and_wait` método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `missing_wait`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-missingwait"></a><a name="ctor"></a>missing_wait 

 Constrói um objeto `missing_wait`.  
  
```
explicit _CRTIMP missing_wait(_In_z_ const char* _Message) throw();

missing_wait() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe task_group](task-group-class.md)   
 [Método Wait](task-group-class.md)   
 [Método run_and_wait](task-group-class.md)   
 [Classe structured_task_group](structured-task-group-class.md)

