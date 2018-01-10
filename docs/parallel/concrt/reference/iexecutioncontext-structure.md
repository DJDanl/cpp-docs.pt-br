---
title: Estrutura IExecutionContext | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IExecutionContext
- CONCRTRM/concurrency::IExecutionContext
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::Dispatch
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::GetId
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::GetProxy
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::GetScheduler
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::SetProxy
dev_langs: C++
helpviewer_keywords: IExecutionContext structure
ms.assetid: f3108089-ecda-4b07-86db-3efae60c31e0
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9e3edffb10aad7b5793907c8c95ad5028f4d1d23
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iexecutioncontext-structure"></a>Estrutura IExecutionContext
Uma interface para um contexto de execução que pode executar em um determinado processador virtual e ser trabalhem de forma alternado do contexto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IExecutionContext;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Iexecutioncontext](#dispatch)|O método é chamado quando um proxy de thread inicia a execução de um contexto de execução específica. Isso deve ser a rotina de trabalho principal para o Agendador.|  
|[Iexecutioncontext](#getid)|Retorna um identificador exclusivo para o contexto de execução.|  
|[Iexecutioncontext](#getproxy)|Retorna uma interface para o proxy de thread que está em execução neste contexto.|  
|[: Getscheduler](#getscheduler)|Retorna uma interface para o Agendador neste contexto de execução pertence.|  
|[: Setproxy](#setproxy)|Associa um proxy de thread neste contexto de execução. O proxy de thread associado chama esse direito método antes de começar a execução do contexto `Dispatch` método.|  
  
## <a name="remarks"></a>Comentários  
 Se você estiver implementando um agendador personalizado que faz interface com o Gerenciador de recursos do tempo de execução de simultaneidade, você precisará implementar o `IExecutionContext` interface. Os threads criados pelo Gerenciador de recursos executam o trabalho em nome de seu Agendador executando o `IExecutionContext::Dispatch` método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IExecutionContext`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="dispatch"></a>Método Iexecutioncontext:  
 O método é chamado quando um proxy de thread inicia a execução de um contexto de execução específica. Isso deve ser a rotina de trabalho principal para o Agendador.  
  
```
virtual void Dispatch(_Inout_ DispatchState* pDispatchState) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDispatchState`  
 Um ponteiro para o estado sob a qual este contexto de execução está sendo enviado. Para obter mais informações sobre o estado de expedição, consulte [DispatchState](dispatchstate-structure.md).  
  
##  <a name="getid"></a>Método Iexecutioncontext:  
 Retorna um identificador exclusivo para o contexto de execução.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador inteiro exclusivo.  
  
### <a name="remarks"></a>Comentários  
 Você deve usar o método `GetExecutionContextId` para obter um identificador exclusivo para o objeto que implementa o `IExecutionContext` interface, antes de você usar a interface como um parâmetro para métodos fornecidos pelo Gerenciador de recursos. Você deve retornar o mesmo identificador quando a `GetId` função é invocada.  
  
 Um identificador obtido de uma fonte diferente pode resultar em um comportamento indefinido.  
  
##  <a name="getproxy"></a>Método Iexecutioncontext:  
 Retorna uma interface para o proxy de thread que está em execução neste contexto.  
  
```
virtual IThreadProxy* GetProxy() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface `IThreadProxy`. Se o proxy de thread do contexto de execução não foi inicializada com uma chamada para `SetProxy`, a função deve retornar `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Invocará o Gerenciador de recursos de `SetProxy` método em um contexto de execução, com um `IThreadProxy` interface como um parâmetro, antes de entrar no `Dispatch` método no no contexto. Você deve armazenar esse argumento e retorná-la em chamadas para `GetProxy()`.  
  
##  <a name="getscheduler"></a>Método: Getscheduler  
 Retorna uma interface para o Agendador neste contexto de execução pertence.  
  
```
virtual IScheduler* GetScheduler() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface `IScheduler`.  
  
### <a name="remarks"></a>Comentários  
 Você deve inicializar o contexto de execução com uma validade `IScheduler` interface antes de usá-lo como um parâmetro para métodos fornecidos pelo Gerenciador de recursos.  
  
##  <a name="setproxy"></a>Método: Setproxy  
 Associa um proxy de thread neste contexto de execução. O proxy de thread associado chama esse direito método antes de começar a execução do contexto `Dispatch` método.  
  
```
virtual void SetProxy(_Inout_ IThreadProxy* pThreadProxy) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pThreadProxy`  
 Uma interface para o proxy de thread que está prestes a entrar o `Dispatch` método neste contexto de execução.  
  
### <a name="remarks"></a>Comentários  
 Você deve salvar o parâmetro `pThreadProxy` e retorná-lo em uma chamada para o `GetProxy` método. O Gerenciador de recursos garante que o proxy de thread associado ao contexto de execução não será alterada enquanto o proxy de thread está em execução o `Dispatch` método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IScheduler](ischeduler-structure.md)   
 [Estrutura IThreadProxy](ithreadproxy-structure.md)
