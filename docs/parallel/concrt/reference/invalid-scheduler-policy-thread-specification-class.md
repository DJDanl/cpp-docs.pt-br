---
title: Classe invalid_scheduler_policy_thread_specification | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::invalid_scheduler_policy_thread_specification
dev_langs:
- C++
helpviewer_keywords:
- invalid_scheduler_policy_thread_specification class
ms.assetid: 2d0fafb2-18f8-4284-8040-3db640d33303
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
ms.openlocfilehash: c09719412e38a4f056eabc39a66a684caa0659d4
ms.lasthandoff: 02/25/2017

---
# <a name="invalidschedulerpolicythreadspecification-class"></a>Classe invalid_scheduler_policy_thread_specification
Esta classe descreve uma exceção lançada quando é feita uma tentativa de definir os limites de simultaneidade de um `SchedulerPolicy` objeto, de modo que o valor da `MinConcurrency` chave é menor que o valor da `MaxConcurrency` chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_scheduler_policy_thread_specification : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[construtor invalid_scheduler_policy_thread_specification] (inválido-Agendador-política-valor-class.md #ctor|Sobrecarregado. Constrói uma `invalid_scheduler_policy_value` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_scheduler_policy_thread_specification`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
##  <a name="a-namectora-invalidschedulerpolicythreadspecification"></a><a name="ctor"></a>invalid_scheduler_policy_thread_specification 

 Constrói uma `invalid_scheduler_policy_value` objeto.  
  
```
explicit _CRTIMP invalid_scheduler_policy_thread_specification(_In_z_ const char* _Message) throw();

invalid_scheduler_policy_thread_specification() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  

## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe SchedulerPolicy](schedulerpolicy-class.md)

