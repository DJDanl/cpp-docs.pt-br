---
title: Classe missing_wait | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- missing_wait
- CONCRT/concurrency::missing_wait
- CONCRT/concurrency::missing_wait::missing_wait
dev_langs: C++
helpviewer_keywords: missing_wait class
ms.assetid: ff981875-bd43-47e3-806f-b03c9f418b18
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ab27107ad76e77601286b77ad28e90b69fa0411e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="missingwait-class"></a>Classe missing_wait
Esta classe descreve uma exceção gerada quando há tarefas ainda está agendadas para ser um `task_group` ou `structured_task_group` do objeto no momento em que esse objeto destruidor é executado. Essa exceção será lançada nunca se o destruidor é atingido devido a uma pilha de desenrolamento como resultado de uma exceção.  
  
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
 Ausência de fluxo de exceção, você é responsável por chamar o `wait` ou `run_and_wait` método de um `task_group` ou `structured_task_group` objeto antes de permitir que esse objeto destruct. O tempo de execução lança esta exceção como uma indicação de que você esqueceu de chamar o `wait` ou `run_and_wait` método.  
  
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
