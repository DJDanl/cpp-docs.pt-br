---
title: Classe nested_scheduler_missing_detach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- nested_scheduler_missing_detach
- CONCRT/concurrency::nested_scheduler_missing_detach
- CONCRT/concurrency::nested_scheduler_missing_detach::nested_scheduler_missing_detach
dev_langs:
- C++
helpviewer_keywords:
- nested_scheduler_missing_detach class
ms.assetid: 65d3f277-6d43-4160-97ef-caf8b26c1641
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 26027693209bc5b4687686efeae5d190ed374607
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33687355"
---
# <a name="nestedschedulermissingdetach-class"></a>Classe nested_scheduler_missing_detach
Esta classe descreve uma exceção gerada quando o tempo de execução de simultaneidade detecta que você não chamou o `CurrentScheduler::Detach` método em um contexto que é anexado a um segundo Agendador usando o `Attach` método o `Scheduler` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class nested_scheduler_missing_detach : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[nested_scheduler_missing_detach](#ctor)|Sobrecarregado. Constrói um objeto `nested_scheduler_missing_detach`.|  
  
## <a name="remarks"></a>Comentários  
 Essa exceção é gerada apenas quando você aninhar um agendador dentro de outro chamando o `Attach` método de um `Scheduler` objeto em um contexto que já é de propriedade ou anexado a outro Agendador. O tempo de execução de simultaneidade lança esta exceção oportunamente quando ele pode detectar o cenário como um auxílio para localizar o problema. Nem toda instância de negligenciando chamar o `CurrentScheduler::Detach` método é garantido para gerar essa exceção.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `nested_scheduler_missing_detach`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> nested_scheduler_missing_detach 

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
 [Classe Scheduler](scheduler-class.md)
