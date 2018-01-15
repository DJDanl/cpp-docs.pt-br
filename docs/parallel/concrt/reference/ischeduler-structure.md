---
title: Estrutura IScheduler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IScheduler
- CONCRTRM/concurrency::IScheduler
- CONCRTRM/concurrency::IScheduler::IScheduler::AddVirtualProcessors
- CONCRTRM/concurrency::IScheduler::IScheduler::GetId
- CONCRTRM/concurrency::IScheduler::IScheduler::GetPolicy
- CONCRTRM/concurrency::IScheduler::IScheduler::NotifyResourcesExternallyBusy
- CONCRTRM/concurrency::IScheduler::IScheduler::NotifyResourcesExternallyIdle
- CONCRTRM/concurrency::IScheduler::IScheduler::RemoveVirtualProcessors
- CONCRTRM/concurrency::IScheduler::IScheduler::Statistics
dev_langs: C++
helpviewer_keywords: IScheduler structure
ms.assetid: 471de85a-2b1a-4b6d-ab81-2eff2737161e
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c639bd760b837923f3011e9209d923fef31f8aee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ischeduler-structure"></a>Estrutura IScheduler
Uma interface para uma abstração de um agendador de trabalho. Gerenciador de recursos do tempo de execução de simultaneidade usa essa interface para se comunicar com os agendadores de trabalho.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IScheduler;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[: Addvirtualprocessors](#addvirtualprocessors)|Fornece um agendador com um conjunto de raízes de processador virtual para seu uso. Cada `IVirtualProcessorRoot` interface representa o direito de executar um thread único que pode executar o trabalho em nome do Agendador.|  
|[Ischeduler](#getid)|Retorna um identificador exclusivo para o Agendador.|  
|[: Getpolicy](#getpolicy)|Retorna uma cópia da política do Agendador. Para obter mais informações sobre políticas de Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).|  
|[: Notifyresourcesexternallybusy](#notifyresourcesexternallybusy)|Notifica a este agendador que os threads de hardware representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` agora estão sendo usadas por outros agendadores.|  
|[: Notifyresourcesexternallyidle](#notifyresourcesexternallyidle)|Notifica a este agendador que os threads de hardware representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` não estão sendo usados por outros agendadores.|  
|[: Removevirtualprocessors](#removevirtualprocessors)|Inicia a remoção de raízes de processador virtual que anteriormente foram alocados a este agendador.|  
|[Ischeduler](#statistics)|Fornece informações relacionadas às taxas de chegada e a conclusão da tarefa e a alteração no tamanho da fila para um agendador.|  
  
## <a name="remarks"></a>Comentários  
 Se você estiver implementando um agendador personalizado que se comunica com o Gerenciador de recursos, você deve fornecer uma implementação de `IScheduler` interface. Esta interface é uma extremidade de um canal bidirecional de comunicação entre um agendador e o Gerenciador de recursos. A outra extremidade é representada pelo `IResourceManager` e `ISchedulerProxy` interfaces que são implementados pelo Gerenciador de recursos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IScheduler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="addvirtualprocessors"></a>Método: Addvirtualprocessors  
 Fornece um agendador com um conjunto de raízes de processador virtual para seu uso. Cada `IVirtualProcessorRoot` interface representa o direito de executar um thread único que pode executar o trabalho em nome do Agendador.  
  
```
virtual void AddVirtualProcessors(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppVirtualProcessorRoots`  
 Uma matriz de `IVirtualProcessorRoot` raízes de interfaces que representa o processador virtual que está sendo adicionado ao Agendador.  
  
 `count`  
 O número de `IVirtualProcessorRoot` interfaces na matriz.  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de recursos invoca o `AddVirtualProcessor` método conceder um conjunto inicial de raízes de processador virtual para um agendador. Ele também pode invocar o método para adicionar raízes de processador virtual para o Agendador quando ele redistribui recursos entre os agendadores.  
  
##  <a name="getid"></a>Método Ischeduler:  
 Retorna um identificador exclusivo para o Agendador.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador inteiro exclusivo.  
  
### <a name="remarks"></a>Comentários  
 Você deve usar o [GetSchedulerId](concurrency-namespace-functions.md) função para obter um identificador exclusivo para o objeto que implementa o `IScheduler` interface, antes de você usar a interface como um parâmetro para métodos fornecidos pelo Gerenciador de recursos. Você deve retornar o mesmo identificador quando a `GetId` função é invocada.  
  
 Um identificador obtido de uma fonte diferente pode resultar em um comportamento indefinido.  
  
##  <a name="getpolicy"></a>Método: Getpolicy  
 Retorna uma cópia da política do Agendador. Para obter mais informações sobre políticas de Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).  
  
```
virtual SchedulerPolicy GetPolicy() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia da política do Agendador.  
  
##  <a name="notifyresourcesexternallybusy"></a>Método: Notifyresourcesexternallybusy  
 Notifica a este agendador que os threads de hardware representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` agora estão sendo usadas por outros agendadores.  
  
```
virtual void NotifyResourcesExternallyBusy(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppVirtualProcessorRoots`  
 Uma matriz de `IVirtualProcessorRoot` interfaces associadas com os threads de hardware no qual outros agendadores têm se tornado ocupados.  
  
 `count`  
 O número de `IVirtualProcessorRoot` interfaces na matriz.  
  
### <a name="remarks"></a>Comentários  
 É possível que um thread de hardware específica a ser atribuído a vários agendadores ao mesmo tempo. Um motivo para isso poderia ser que não há threads de hardware suficientes no sistema para satisfazer a simultaneidade mínimo para todos os agendadores, sem compartilhamento de recursos. Outra possibilidade é que recursos são atribuídos temporariamente a outros agendadores quando o Agendador do proprietário não está usando, por meio de todas as suas raízes de processador virtual nesse thread de hardware que está sendo desativado.  
  
 O nível de assinatura de um thread de hardware é indicado pelo número de threads assinados e ativados raízes de processador virtual associados a esse thread de hardware. Do ponto de vista de um agendador específico, o nível de assinatura externa de um thread de hardware é a parte da assinatura para que outros agendadores contribuem. Que recursos estão ocupados externamente de notificações são enviadas para um agendador quando o nível de assinatura externa para um thread de hardware se move de zero em território positivo.  
  
 Notificações por esse método só são enviadas para os agendadores que têm uma política de onde o valor para o `MinConcurrency` chave de política é igual ao valor para o `MaxConcurrency` chave de política. Para obter mais informações sobre políticas de Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).  
  
 Um agendador que se qualificam para notificações obtém um conjunto de notificações inicias quando ela é criada, informando-o se os recursos que ele recebeu são externamente ocupado ou ocioso.  
  
##  <a name="notifyresourcesexternallyidle"></a>Método: Notifyresourcesexternallyidle  
 Notifica a este agendador que os threads de hardware representados pelo conjunto de raízes de processador virtual na matriz `ppVirtualProcessorRoots` não estão sendo usados por outros agendadores.  
  
```
virtual void NotifyResourcesExternallyIdle(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppVirtualProcessorRoots`  
 Uma matriz de `IVirtualProcessorRoot` interfaces associadas threads de hardware no qual outros agendadores têm se tornado ociosas.  
  
 `count`  
 O número de `IVirtualProcessorRoot` interfaces na matriz.  
  
### <a name="remarks"></a>Comentários  
 É possível que um thread de hardware específica a ser atribuído a vários agendadores ao mesmo tempo. Um motivo para isso poderia ser que não há threads de hardware suficientes no sistema para satisfazer a simultaneidade mínimo para todos os agendadores, sem compartilhamento de recursos. Outra possibilidade é que recursos são atribuídos temporariamente a outros agendadores quando o Agendador do proprietário não está usando, por meio de todas as suas raízes de processador virtual nesse thread de hardware que está sendo desativado.  
  
 O nível de assinatura de um thread de hardware é indicado pelo número de threads assinados e ativados raízes de processador virtual associados a esse thread de hardware. Do ponto de vista de um agendador específico, o nível de assinatura externa de um thread de hardware é a parte da assinatura para que outros agendadores contribuem. Que recursos estão ocupados externamente de notificações são enviadas para um agendador quando o nível de assinatura externa para um thread de hardware cair para zero de um valor positivo anterior.  
  
 Notificações por esse método só são enviadas para os agendadores que têm uma política de onde o valor para o `MinConcurrency` chave de política é igual ao valor para o `MaxConcurrency` chave de política. Para obter mais informações sobre políticas de Agendador, consulte [SchedulerPolicy](schedulerpolicy-class.md).  
  
 Um agendador que se qualificam para notificações obtém um conjunto de notificações inicias quando ela é criada, informando-o se os recursos que ele recebeu são externamente ocupado ou ocioso.  
  
##  <a name="removevirtualprocessors"></a>Método: Removevirtualprocessors  
 Inicia a remoção de raízes de processador virtual que anteriormente foram alocados a este agendador.  
  
```
virtual void RemoveVirtualProcessors(
    _In_reads_(count) IVirtualProcessorRoot** ppVirtualProcessorRoots,
    unsigned int count) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppVirtualProcessorRoots`  
 Uma matriz de `IVirtualProcessorRoot` interfaces que representa as raízes de processador virtual a ser removido.  
  
 `count`  
 O número de `IVirtualProcessorRoot` interfaces na matriz.  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de recursos invoca o `RemoveVirtualProcessors` método para usar um conjunto de raízes de processador virtual de volta de um agendador. O Agendador é esperado para invocar o [remover](iexecutionresource-structure.md#remove) método em cada interface quando isso é feito com as raízes de processador virtual. Não use um `IVirtualProcessorRoot` interface quando invocado o `Remove` método nele.  
  
 O parâmetro `ppVirtualProcessorRoots` aponta para uma matriz de interfaces. Entre o conjunto de raízes de processador virtual a ser removido, as raízes nunca foram ativadas podem ser retornadas imediatamente usando o `Remove` método. As raízes de ativação e a execução do trabalho, ou foi desativadas e estão aguardando trabalho chegar, devem ser retornadas assincronamente. O Agendador deve verificar cada tentativa de remover a raiz virtual processador mais rápido possível. Atrasar a remoção das raízes de processador virtual pode resultar em excesso de assinatura não intencional no Agendador.  
  
##  <a name="statistics"></a>Método Ischeduler:  
 Fornece informações relacionadas às taxas de chegada e a conclusão da tarefa e a alteração no tamanho da fila para um agendador.  
  
```
virtual void Statistics(
    _Out_ unsigned int* pTaskCompletionRate,
    _Out_ unsigned int* pTaskArrivalRate,
    _Out_ unsigned int* pNumberOfTasksEnqueued) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTaskCompletionRate`  
 O número de tarefas que foram concluídas pelo Agendador desde a última chamada a este método.  
  
 `pTaskArrivalRate`  
 O número de tarefas que chegaram no Agendador do desde a última chamada a este método.  
  
 `pNumberOfTasksEnqueued`  
 O número total de tarefas em todas as filas do Agendador.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo Gerenciador de recursos para coletar estatísticas para um agendador. As estatísticas coletadas aqui usará para algoritmos de comentário dinâmico para determinar quando é apropriado atribuir mais recursos para o Agendador e quando a tirar recursos da unidade. Os valores fornecidos pelo Agendador podem ser otimistas e não precisam necessariamente refletem a contagem atual com precisão.  
  
 Você deve implementar esse método se você quiser que o Gerenciador de recursos para usar comentários sobre coisas como entrada de tarefa para determinar como equilibrar os recursos entre o Agendador e outros agendadores registrados com o Gerenciador de recursos. Se você optar por não coletar estatísticas, você pode definir a chave de política `DynamicProgressFeedback` para o valor `DynamicProgressFeedbackDisabled` na política do Agendador e o recurso Manager não invocar esse método em seu Agendador.  
  
 Na ausência de informações estatísticas, o Gerenciador de recursos usará níveis de assinatura de thread de hardware para tomar decisões de migração e alocação de recursos. Para obter mais informações sobre níveis de assinatura, consulte [: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [PolicyElementKey](concurrency-namespace-enums.md)   
 [Classe SchedulerPolicy](schedulerpolicy-class.md)   
 [Estrutura IExecutionContext](iexecutioncontext-structure.md)   
 [Estrutura IThreadProxy](ithreadproxy-structure.md)   
 [Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)   
 [Estrutura IResourceManager](iresourcemanager-structure.md)
