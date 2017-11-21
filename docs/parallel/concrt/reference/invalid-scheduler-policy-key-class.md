---
title: Classe invalid_scheduler_policy_key | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- invalid_scheduler_policy_key
- CONCRT/concurrency::invalid_scheduler_policy_key
- CONCRT/concurrency::invalid_scheduler_policy_key::invalid_scheduler_policy_key
dev_langs: C++
helpviewer_keywords: invalid_scheduler_policy_key class
ms.assetid: 6a7c42fe-9bc4-4a02-bebb-99fe9ef9817d
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e260306a896c39f070be6794cf2f63a307b7cd99
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="invalidschedulerpolicykey-class"></a>Classe invalid_scheduler_policy_key
Esta classe descreve uma exceção gerada quando um inválido ou desconhecido de chave é passada para um `SchedulerPolicy` construtor do objeto, ou o `SetPolicyValue` método de um `SchedulerPolicy` objeto é passado a uma chave que deve ser alterada usando outros meios, como o `SetConcurrencyLimits` método.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_scheduler_policy_key : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[invalid_scheduler_policy_key](#ctor)|Sobrecarregado. Constrói uma `invalid_scheduler_policy_key` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_scheduler_policy_key`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>invalid_scheduler_policy_key 

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
