---
title: Classe invalid_scheduler_policy_key | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- invalid_scheduler_policy_key
- CONCRT/concurrency::invalid_scheduler_policy_key
- CONCRT/concurrency::invalid_scheduler_policy_key::invalid_scheduler_policy_key
dev_langs:
- C++
helpviewer_keywords:
- invalid_scheduler_policy_key class
ms.assetid: 6a7c42fe-9bc4-4a02-bebb-99fe9ef9817d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b78bc955b43f3b6650f7a2fe654e5920c9cac971
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33705166"
---
# <a name="invalidschedulerpolicykey-class"></a>Classe invalid_scheduler_policy_key
Esta classe descreve uma exceção gerada quando um inválido ou desconhecido de chave é passada para um `SchedulerPolicy` construtor do objeto, ou o `SetPolicyValue` método de um `SchedulerPolicy` objeto é passado a uma chave que deve ser alterada usando outros meios, como o `SetConcurrencyLimits` método.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_scheduler_policy_key : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[invalid_scheduler_policy_key](#ctor)|Sobrecarregado. Constrói uma `invalid_scheduler_policy_key` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_scheduler_policy_key`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> invalid_scheduler_policy_key 

 Constrói uma `invalid_scheduler_policy_key` objeto.  
  
```
explicit _CRTIMP invalid_scheduler_policy_key(_In_z_ const char* _Message) throw();

invalid_scheduler_policy_key() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe SchedulerPolicy](schedulerpolicy-class.md)
