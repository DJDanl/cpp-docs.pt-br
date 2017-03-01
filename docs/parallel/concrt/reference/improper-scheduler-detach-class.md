---
title: Classe improper_scheduler_detach | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::improper_scheduler_detach
dev_langs:
- C++
helpviewer_keywords:
- improper_scheduler_detach class
ms.assetid: 30132102-c900-4951-a470-b63b4e3aa2d2
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
ms.openlocfilehash: 6a4bb4be90966f3abed8792bfbef086e7b399922
ms.lasthandoff: 02/25/2017

---
# <a name="improperschedulerdetach-class"></a>Classe improper_scheduler_detach
Esta classe descreve uma exceção gerada quando o `CurrentScheduler::Detach` método for chamado em um contexto que não foi anexado a qualquer Agendador usando o `Attach` método de um `Scheduler` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class improper_scheduler_detach : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor improper_scheduler_detach](#ctor)|Sobrecarregado. Constrói uma `improper_scheduler_detach` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `improper_scheduler_detach`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-improperschedulerdetach"></a><a name="ctor"></a>improper_scheduler_detach 

 Constrói uma `improper_scheduler_detach` objeto.  
  
```
explicit _CRTIMP improper_scheduler_detach(_In_z_ const char* _Message) throw();

improper_scheduler_detach() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe de Agendador](scheduler-class.md)

