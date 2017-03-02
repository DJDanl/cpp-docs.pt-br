---
title: Classe nested_scheduler_missing_detach | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::nested_scheduler_missing_detach
dev_langs:
- C++
helpviewer_keywords:
- nested_scheduler_missing_detach class
ms.assetid: 65d3f277-6d43-4160-97ef-caf8b26c1641
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
ms.openlocfilehash: 0079fea0b157e194947931f88d1cb500167cb6e2
ms.lasthandoff: 02/25/2017

---
# <a name="nestedschedulermissingdetach-class"></a>Classe nested_scheduler_missing_detach
Esta classe descreve uma exceção gerada quando o tempo de execução de simultaneidade detecta que você não chamou o `CurrentScheduler::Detach` método em um contexto que é anexado a um segundo Agendador usando o `Attach` método o `Scheduler` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class nested_scheduler_missing_detach : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor nested_scheduler_missing_detach](#ctor)|Sobrecarregado. Constrói um objeto `nested_scheduler_missing_detach`.|  
  
## <a name="remarks"></a>Comentários  
 Essa exceção é lançada apenas quando você aninhar um agendador dentro de outro chamando o `Attach` método de um `Scheduler` objeto em um contexto que já é de propriedade ou anexado a outro Agendador. O tempo de execução de simultaneidade gerará esta exceção oportunamente quando ele pode detectar o cenário como um auxílio para localizar o problema. Nem toda instância de negligenciar chamar o `CurrentScheduler::Detach` método é garantido para gerar essa exceção.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `nested_scheduler_missing_detach`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-nestedschedulermissingdetach"></a><a name="ctor"></a>nested_scheduler_missing_detach 

 Constrói um objeto `nested_scheduler_missing_detach`.  
  
```
explicit _CRTIMP nested_scheduler_missing_detach(_In_z_ const char* _Message) throw();

nested_scheduler_missing_detach() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe de Agendador](scheduler-class.md)

