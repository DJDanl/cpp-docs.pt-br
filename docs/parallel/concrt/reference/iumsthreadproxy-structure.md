---
title: Estrutura IUMSThreadProxy | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- IUMSThreadProxy
- CONCRTRM/concurrency::IUMSThreadProxy
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::EnterCriticalRegion
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::EnterHyperCriticalRegion
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::ExitCriticalRegion
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::ExitHyperCriticalRegion
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::GetCriticalRegionType
dev_langs:
- C++
helpviewer_keywords:
- IUMSThreadProxy structure
ms.assetid: 61c69b7e-5c37-4048-bcb4-e75c536afd86
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bbba2955adc14ef73a0ba9932756ace57c4136e6
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33688603"
---
# <a name="iumsthreadproxy-structure"></a>Estrutura IUMSThreadProxy
Uma abstração para um thread de execução. Se você quiser que o Agendador para receber os threads do modo de usuário agendáveis (UMS), defina o valor para o elemento de diretiva do Agendador `SchedulerKind` para `UmsThreadDefault`e implementar o `IUMSScheduler` interface. Threads UMS são apenas com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IUMSThreadProxy : public IThreadProxy;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IUMSThreadProxy::EnterCriticalRegion](#entercriticalregion)|Chamado para inserir uma região crítica. Quando dentro de uma região crítica, o Agendador não observará bloqueio de operações assíncrona que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para falhas de página, suspensões de thread, chamadas de procedimento assíncrono do kernel (APCs) e assim por diante, para um thread UMS.|  
|[IUMSThreadProxy::EnterHyperCriticalRegion](#enterhypercriticalregion)|Chamado para inserir uma região hyper crítica. Quando dentro de uma região hyper crítica, o Agendador não observará bloqueio de operações que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para bloqueio de chamadas de função, tentativas de aquisição de bloqueio, o bloco, falhas de página, thread suspensões, chamadas de procedimento assíncrono do kernel (APCs) e assim por diante, para um UMS thread.|  
|[IUMSThreadProxy::ExitCriticalRegion](#exitcriticalregion)|Chamado para sair de uma região crítica.|  
|[IUMSThreadProxy::ExitHyperCriticalRegion](#exithypercriticalregion)|Chamado para sair de uma região hyper crítica.|  
|[IUMSThreadProxy::GetCriticalRegionType](#getcriticalregiontype)|Retorna o tipo de região crítica que o proxy de thread está dentro. Como regiões hyper críticas são um subconjunto de regiões críticas, se o código inserido uma região crítica e, em seguida, uma região hyper crítica, `InsideHyperCriticalRegion` será retornado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [IThreadProxy](ithreadproxy-structure.md)  
  
 `IUMSThreadProxy`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="entercriticalregion"></a>  Método: Entercriticalregion  
 Chamado para inserir uma região crítica. Quando dentro de uma região crítica, o Agendador não observará bloqueio de operações assíncrona que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para falhas de página, suspensões de thread, chamadas de procedimento assíncrono do kernel (APCs) e assim por diante, para um thread UMS.  
  
```
virtual int EnterCriticalRegion() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova profundidade da região crítica. Regiões críticas são reentrantes.  
  
##  <a name="enterhypercriticalregion"></a>  Método: Enterhypercriticalregion  
 Chamado para inserir uma região hyper crítica. Quando dentro de uma região hyper crítica, o Agendador não observará bloqueio de operações que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para bloqueio de chamadas de função, tentativas de aquisição de bloqueio, o bloco, falhas de página, thread suspensões, chamadas de procedimento assíncrono do kernel (APCs) e assim por diante, para um UMS thread.  
  
```
virtual int EnterHyperCriticalRegion() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova profundidade da região hyper crítica. Regiões Hyper críticas são reentrantes.  
  
### <a name="remarks"></a>Comentários  
 O Agendador deve ser extraordinariamente cuidado em relação a quais métodos chamados por ele e o que bloqueia adquire em regiões. Se o código em tal região bloqueia um bloqueio é mantido por algo que o Agendador é responsável por agendar, pode causar deadlock.  
  
##  <a name="exitcriticalregion"></a>  Método: Exitcriticalregion  
 Chamado para sair de uma região crítica.  
  
```
virtual int ExitCriticalRegion() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova profundidade da região crítica. Regiões críticas são reentrantes.  
  
##  <a name="exithypercriticalregion"></a>  Método: Exithypercriticalregion  
 Chamado para sair de uma região hyper crítica.  
  
```
virtual int ExitHyperCriticalRegion() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova profundidade da região hyper crítica. Regiões Hyper críticas são reentrantes.  
  
##  <a name="getcriticalregiontype"></a>  Método: Getcriticalregiontype  
 Retorna o tipo de região crítica que o proxy de thread está dentro. Como regiões hyper críticas são um subconjunto de regiões críticas, se o código inserido uma região crítica e, em seguida, uma região hyper crítica, `InsideHyperCriticalRegion` será retornado.  
  
```
virtual CriticalRegionType GetCriticalRegionType() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo de região crítica que o proxy de thread está dentro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IUMSScheduler](iumsscheduler-structure.md)
