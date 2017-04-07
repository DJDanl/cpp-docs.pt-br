---
title: Estrutura IUMSThreadProxy | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 46d486ddccce6f3c54627f3ea96f001e8e3bfcf7
ms.lasthandoff: 03/17/2017

---
# <a name="iumsthreadproxy-structure"></a>Estrutura IUMSThreadProxy
Uma abstração de um thread de execução. Se você quiser que o Agendador para receber threads (UMS) agendáveis de modo de usuário, defina o valor para o elemento de diretiva Agendador `SchedulerKind` para `UmsThreadDefault`e implementar o `IUMSScheduler` interface. Threads UMS são somente com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IUMSThreadProxy : public IThreadProxy;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Entercriticalregion](#entercriticalregion)|Chamado para inserir uma região crítica. Quando dentro de uma região crítica, o Agendador não observará bloqueio de operações assíncrona que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para falhas de página, suspensões do thread, chamadas de procedimento assíncrono (APCs) do kernel e assim por diante, para um thread UMS.|  
|[Enterhypercriticalregion](#enterhypercriticalregion)|Chamado para inserir uma região hyper-crítica. Quando dentro de uma região hyper-crítica, o Agendador não observará bloqueio de operações que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para bloquear chamadas de função, tentativas de aquisição de bloqueio, o bloco, falhas de página, suspensões, chamadas de procedimento assíncrono (APCs) do kernel do thread e assim por diante, para um UMS thread.|  
|[Exitcriticalregion](#exitcriticalregion)|Chamado para sair de uma região crítica.|  
|[Exithypercriticalregion](#exithypercriticalregion)|Chamado para sair de uma região hyper-crítica.|  
|[Getcriticalregiontype](#getcriticalregiontype)|Retorna o tipo de região crítica, o proxy thread está dentro. Como regiões hyper críticas são um superconjunto de regiões críticas, se o código inserido uma região crítica e, em seguida, uma região hyper-crítica, `InsideHyperCriticalRegion` será retornado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [IThreadProxy](ithreadproxy-structure.md)  
  
 `IUMSThreadProxy`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="entercriticalregion"></a>Método Entercriticalregion  
 Chamado para inserir uma região crítica. Quando dentro de uma região crítica, o Agendador não observará bloqueio de operações assíncrona que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para falhas de página, suspensões do thread, chamadas de procedimento assíncrono (APCs) do kernel e assim por diante, para um thread UMS.  
  
```
virtual int EnterCriticalRegion() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova profundidade da região crítica. As regiões críticas são reentrantes.  
  
##  <a name="enterhypercriticalregion"></a>Método Enterhypercriticalregion  
 Chamado para inserir uma região hyper-crítica. Quando dentro de uma região hyper-crítica, o Agendador não observará bloqueio de operações que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para bloquear chamadas de função, tentativas de aquisição de bloqueio, o bloco, falhas de página, suspensões, chamadas de procedimento assíncrono (APCs) do kernel do thread e assim por diante, para um UMS thread.  
  
```
virtual int EnterHyperCriticalRegion() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova profundidade da região hyper-crítica. Regiões críticas de Hyper são reentrantes.  
  
### <a name="remarks"></a>Comentários  
 O Agendador deve ser extremamente cuidadoso com o que ele chama de métodos e o que ele bloqueia adquire em regiões. Se o código em tal região bloqueia um bloqueio é mantido por algo que o Agendador é responsável por agendar, pode causar deadlock.  
  
##  <a name="exitcriticalregion"></a>Método Exitcriticalregion  
 Chamado para sair de uma região crítica.  
  
```
virtual int ExitCriticalRegion() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova profundidade da região crítica. As regiões críticas são reentrantes.  
  
##  <a name="exithypercriticalregion"></a>Método Exithypercriticalregion  
 Chamado para sair de uma região hyper-crítica.  
  
```
virtual int ExitHyperCriticalRegion() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova profundidade da região hyper-crítica. Regiões críticas de Hyper são reentrantes.  
  
##  <a name="getcriticalregiontype"></a>Método Getcriticalregiontype  
 Retorna o tipo de região crítica, o proxy thread está dentro. Como regiões hyper críticas são um superconjunto de regiões críticas, se o código inserido uma região crítica e, em seguida, uma região hyper-crítica, `InsideHyperCriticalRegion` será retornado.  
  
```
virtual CriticalRegionType GetCriticalRegionType() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo de região crítica, que o proxy thread está dentro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IUMSScheduler](iumsscheduler-structure.md)

