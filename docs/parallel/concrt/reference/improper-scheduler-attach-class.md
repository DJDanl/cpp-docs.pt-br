---
title: Classe improper_scheduler_attach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- improper_scheduler_attach
- CONCRT/concurrency::improper_scheduler_attach
- CONCRT/concurrency::improper_scheduler_attach::improper_scheduler_attach
dev_langs:
- C++
helpviewer_keywords:
- improper_scheduler_attach class
ms.assetid: 5a76da0a-091b-4748-8f62-b3a28f674f9e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 46f676bbe61784adab40f90e329b87aa1c1aae52
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46026746"
---
# <a name="improperschedulerattach-class"></a>Classe improper_scheduler_attach
Esta classe descreve uma exceção gerada quando o `Attach` método é chamado em um `Scheduler` objeto que já está anexado ao contexto atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class improper_scheduler_attach : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[improper_scheduler_attach](#ctor)|Sobrecarregado. Constrói um `improper_scheduler_attach` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `improper_scheduler_attach`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> improper_scheduler_attach 

 Constrói um `improper_scheduler_attach` objeto.  
  
```
explicit _CRTIMP improper_scheduler_attach(_In_z_ const char* _Message) throw();

improper_scheduler_attach() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
*Mensagem*<br/>
Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe Scheduler](scheduler-class.md)
