---
title: Classe missing_wait | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- missing_wait
- CONCRT/concurrency::missing_wait
- CONCRT/concurrency::missing_wait::missing_wait
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 70b1c77660992b33de2204fd4f4221ed6e957e21
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

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
|[missing_wait](#ctor)|Sobrecarregado. Constrói um objeto `missing_wait`.|  
  
## <a name="remarks"></a>Comentários  
 Ausência de fluxo de exceção, você é responsável por chamar o `wait` ou `run_and_wait` método de um `task_group` ou `structured_task_group` objeto antes de permitir que esse objeto para destruct. O tempo de execução lança esta exceção como uma indicação de que você se esqueceu de chamar o `wait` ou `run_and_wait` método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `missing_wait`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>missing_wait 

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
 [Aguarde](task-group-class.md)   
 [run_and_wait](task-group-class.md)   
 [Classe structured_task_group](structured-task-group-class.md)

