---
title: Estrutura IUMSScheduler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IUMSScheduler
- CONCRTRM/concurrency::IUMSScheduler
- CONCRTRM/concurrency::IUMSScheduler::IUMSScheduler::SetCompletionList
dev_langs: C++
helpviewer_keywords: IUMSScheduler structure
ms.assetid: 3a500225-4e02-4849-bb56-d744865f5870
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f45f8f2f152cdbfee1ee1ca3c3acfdb93a249d7a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iumsscheduler-structure"></a>Estrutura IUMSScheduler
Uma interface para uma abstração de um agendador de trabalho que deseja Gerenciador de recursos do tempo de execução de simultaneidade entregá-threads do modo de usuário agendáveis (UMS). O Gerenciador de recursos usa essa interface para se comunicar com os agendadores do thread UMS. A interface `IUMSScheduler` herda da interface `IScheduler`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IUMSScheduler : public IScheduler;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[: Setcompletionlist](#setcompletionlist)|Atribui um `IUMSCompletionList` interface para um agendador de thread UMS.|  
  
## <a name="remarks"></a>Comentários  
 Se você estiver implementando um agendador personalizado que se comunica com o Gerenciador de recursos, e você desejar threads UMS a serem passadas para o Agendador em vez de threads de Win32 comuns, você deve fornecer uma implementação de `IUMSScheduler` interface. Além disso, você deve definir o valor de política para a chave de política do Agendador `SchedulerKind` ser `UmsThreadDefault`. Se a política especifica o thread UMS o `IScheduler` interface que é passado como um parâmetro para o [: Registerscheduler](iresourcemanager-structure.md#registerscheduler) método deve ser um `IUMSScheduler` interface.  
  
 O Gerenciador de recursos é capaz de distribuir a você threads UMS apenas em sistemas operacionais que têm o recurso UMS. suporte a sistemas operacionais de 64 bits com a versão do Windows 7 e superior threads UMS. Se você criar uma política de Agendador com o `SchedulerKind` chave definida para o valor `UmsThreadDefault` e a plataforma subjacente não oferece suporte a UMS, o valor da `SchedulerKind` chave na diretiva será alterado para o valor `ThreadScheduler`. Você deve sempre ler novamente esse valor de política antes esperando receber threads UMS.  
  
 O `IUMSScheduler` interface é uma extremidade de um canal bidirecional de comunicação entre um agendador e o Gerenciador de recursos. A outra extremidade é representada pelo `IResourceManager` e `ISchedulerProxy` interfaces, que são implementados pelo Gerenciador de recursos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [IScheduler](ischeduler-structure.md)  
  
 `IUMSScheduler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="setcompletionlist"></a>Método: Setcompletionlist  
 Atribui um `IUMSCompletionList` interface para um agendador de thread UMS.  
  
```
virtual void SetCompletionList(_Inout_ IUMSCompletionList* pCompletionList) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCompletionList`  
 A interface de lista de conclusão para o Agendador. Há uma única lista por Agendador.  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de recursos irá chamar este método em um agendador que especifica a que ele deseja threads UMS, depois que o Agendador solicitou uma alocação inicial de recursos. O Agendador pode usar o `IUMSCompletionList` interface para determinar quando os proxies de thread UMS tem desbloqueado. Ele é válido somente para acessar essa interface de um proxy de thread em execução em uma raiz de processador virtual atribuída ao Agendador UMS.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [PolicyElementKey](concurrency-namespace-enums.md)   
 [Estrutura IScheduler](ischeduler-structure.md)   
 [Estrutura IUMSCompletionList](iumscompletionlist-structure.md)   
 [Estrutura IResourceManager](iresourcemanager-structure.md)
