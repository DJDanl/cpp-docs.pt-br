---
title: Classe invalid_scheduler_policy_value | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::invalid_scheduler_policy_value
dev_langs:
- C++
helpviewer_keywords:
- invalid_scheduler_policy_value class
ms.assetid: 8c533e3f-2774-4192-8616-b2313b859bf7
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
ms.openlocfilehash: ff5b07b62923a289da1b47de08b527da212e4a2d
ms.lasthandoff: 02/25/2017

---
# <a name="invalidschedulerpolicyvalue-class"></a>Classe invalid_scheduler_policy_value
Esta classe descreve uma exceção gerada quando uma chave de política de uma `SchedulerPolicy` objeto é definido como um valor inválido para essa chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_scheduler_policy_value : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[construtor invalid_scheduler_policy_value] (invalid-scheduler-policy-thread-specification-class.md#ctor|Sobrecarregado. Constrói uma `invalid_scheduler_policy_value` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_scheduler_policy_value`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
    
##  <a name="a-namectora-invalidschedulerpolicyvalue"></a><a name="ctor"></a>invalid_scheduler_policy_value 

 Constrói uma `invalid_scheduler_policy_value` objeto.  
  
```
explicit _CRTIMP invalid_scheduler_policy_value(_In_z_ const char* _Message) throw();

invalid_scheduler_policy_value() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  

## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe SchedulerPolicy](schedulerpolicy-class.md)

