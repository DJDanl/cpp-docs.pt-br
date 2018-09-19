---
title: Estrutura IUMSScheduler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- IUMSScheduler
- CONCRTRM/concurrency::IUMSScheduler
- CONCRTRM/concurrency::IUMSScheduler::IUMSScheduler::SetCompletionList
dev_langs:
- C++
helpviewer_keywords:
- IUMSScheduler structure
ms.assetid: 3a500225-4e02-4849-bb56-d744865f5870
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 46ed7dac35dce4b5df51cd4c218a1a70a84d21df
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079057"
---
# <a name="iumsscheduler-structure"></a>Estrutura IUMSScheduler
Uma interface para uma abstração de um agendador de trabalho que deseja o Gerenciador de recursos do tempo de execução de simultaneidade entregá-lo a threads agendáveis no modo de usuário (UMS). O Gerenciador de recursos usa essa interface para se comunicar com os agendadores de thread UMS. A interface `IUMSScheduler` herda da interface `IScheduler`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IUMSScheduler : public IScheduler;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Iumsscheduler:: Setcompletionlist](#setcompletionlist)|Atribui um `IUMSCompletionList` interface para um agendador de thread UMS.|  
  
## <a name="remarks"></a>Comentários  
 Se você estiver implementando um agendador personalizado que se comunica com o Gerenciador de recursos, e você desejar threads UMS a serem passadas para o Agendador em vez de threads de Win32 comuns, você deve fornecer uma implementação do `IUMSScheduler` interface. Além disso, você deve definir o valor da política para a chave de política de Agendador `SchedulerKind` ser `UmsThreadDefault`. Se a diretiva especifica thread UMS, o `IScheduler` interface que é passado como um parâmetro para o [iresourcemanager:: Registerscheduler](iresourcemanager-structure.md#registerscheduler) método deve ser um `IUMSScheduler` interface.  
  
 O Gerenciador de recursos é capaz de entregar threads UMS apenas em sistemas operacionais que têm o recurso UMS. sistemas operacionais de 64 bits com a versão do Windows 7 e posteriores dão suporte a threads UMS. Se você criar uma política de Agendador com o `SchedulerKind` chave definida como o valor `UmsThreadDefault` e a plataforma subjacente não oferece suporte a UMS, o valor da `SchedulerKind` chave nessa diretiva será alterado para o valor `ThreadScheduler`. Você deve sempre ler novamente esse valor de política antes que espera receber threads UMS.  
  
 O `IUMSScheduler` interface é uma extremidade de um canal bidirecional de comunicação entre um agendador e o Gerenciador de recursos. A outra extremidade é representada pela `IResourceManager` e `ISchedulerProxy` interfaces, que são implementados pelo Gerenciador de recursos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [IScheduler](ischeduler-structure.md)  
  
 `IUMSScheduler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="setcompletionlist"></a>  Método iumsscheduler:: Setcompletionlist  
 Atribui um `IUMSCompletionList` interface para um agendador de thread UMS.  
  
```
virtual void SetCompletionList(_Inout_ IUMSCompletionList* pCompletionList) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
*pCompletionList*<br/>
A interface de lista de conclusão para o Agendador. Há uma única lista por Agendador.  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de recursos será invocar esse método em um agendador que especifica que ele deseja threads UMS, depois que o Agendador solicitou uma alocação inicial de recursos. O Agendador pode usar o `IUMSCompletionList` interface para determinar quando os proxies de thread UMS tiveram desbloqueado. Ele é válido somente para acessar essa interface de um proxy de thread em execução em uma raiz de processador virtual atribuída ao Agendador UMS.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [PolicyElementKey](concurrency-namespace-enums.md)   
 [Estrutura IScheduler](ischeduler-structure.md)   
 [Estrutura IUMSCompletionList](iumscompletionlist-structure.md)   
 [Estrutura IResourceManager](iresourcemanager-structure.md)
