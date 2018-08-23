---
title: Classe CurrentScheduler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- CurrentScheduler
- CONCRT/concurrency::CurrentScheduler
- CONCRT/concurrency::CurrentScheduler::Create
- CONCRT/concurrency::CurrentScheduler::CreateScheduleGroup
- CONCRT/concurrency::CurrentScheduler::Detach
- CONCRT/concurrency::CurrentScheduler::Get
- CONCRT/concurrency::CurrentScheduler::GetNumberOfVirtualProcessors
- CONCRT/concurrency::CurrentScheduler::GetPolicy
- CONCRT/concurrency::CurrentScheduler::Id
- CONCRT/concurrency::CurrentScheduler::IsAvailableLocation
- CONCRT/concurrency::CurrentScheduler::RegisterShutdownEvent
- CONCRT/concurrency::CurrentScheduler::ScheduleTask
dev_langs:
- C++
helpviewer_keywords:
- CurrentScheduler class
ms.assetid: 31c20e0e-4cdf-49b4-8220-d726130aad2b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2893644dc4dbec2d1ebc25be42ba4b30fbd19cb1
ms.sourcegitcommit: e9ce38decc9f986edab5543de3464b11ebccb123
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2018
ms.locfileid: "42538201"
---
# <a name="currentscheduler-class"></a>Classe CurrentScheduler
Representa uma abstração para o Agendador atual associado com o contexto de chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CurrentScheduler;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[criar](#create)|Cria um novo Agendador cujo comportamento é descrito o `_Policy` parâmetro e a anexa ao contexto da chamada. O Agendador recém-criado se tornará o Agendador atual para o contexto de chamada.|  
|[CreateScheduleGroup](#createschedulegroup)|Sobrecarregado. Cria um novo grupo de agendamento dentro do agendador associado com o contexto de chamada. A versão que usa o parâmetro `_Placement` faz com que as tarefas dentro do grupo de agenda recém-criada para ser mais adequado para a execução no local especificado por esse parâmetro.|  
|[Desanexar](#detach)|Desanexa o Agendador atual do contexto de chamada e restaura o Agendador anexado anteriormente como o Agendador atual, se houver. Depois que esse método retorna, o contexto de chamada é gerenciado pelo Agendador que já tenha sido anexado ao contexto usando o `CurrentScheduler::Create` ou `Scheduler::Attach` método.|  
|[Get](#get)|Retorna um ponteiro para o Agendador associado com o contexto de chamada, também conhecido como o Agendador atual.|  
|[GetNumberOfVirtualProcessors](#getnumberofvirtualprocessors)|Retorna o número atual de processadores virtuais para o Agendador associado no contexto de chamada.|  
|[GetPolicy](#getpolicy)|Retorna uma cópia da política que o Agendador atual foi criado com.|  
|[Id](#id)|Retorna um identificador exclusivo para o Agendador atual.|  
|[IsAvailableLocation](#isavailablelocation)|Determina se um determinado local está disponível no Agendador atual.|  
|[RegisterShutdownEvent](#registershutdownevent)|Faz com que o identificador de eventos do Windows passado a `_ShutdownEvent` parâmetro a ser sinalizado quando o Agendador associado ao contexto atual é desligado e destrói em si. No momento em que o evento é sinalizado, todo o trabalho foi agendado para o Agendador foi concluído. Vários eventos de desligamento podem ser registrados por meio desse método.|  
|[ScheduleTask](#scheduletask)|Sobrecarregado. Agenda uma tarefa leve dentro do agendador associado com o contexto de chamada. A tarefa leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado.|  
  
## <a name="remarks"></a>Comentários  
 Se não houver nenhum Agendador (consulte [Agendador](scheduler-class.md)) associado com o contexto de chamada, muitos métodos dentro de `CurrentScheduler` classe resultará em anexo do Agendador de padrão do processo. Isso também pode implicar em que o agendador padrão do processo é criado durante essa chamada.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CurrentScheduler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="create"></a> criar 

 Cria um novo Agendador cujo comportamento é descrito o `_Policy` parâmetro e a anexa ao contexto da chamada. O Agendador recém-criado se tornará o Agendador atual para o contexto de chamada.  
  
```
static void __cdecl Create(const SchedulerPolicy& _Policy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Policy`  
 A política de agendador que descreve o comportamento do Agendador recém-criado.  
  
### <a name="remarks"></a>Comentários  
 O anexo do Agendador para o contexto de chamada implicitamente coloca uma contagem de referência no Agendador.  
  
 Depois que um agendador é criado com o `Create` método, você deve chamar o [currentscheduler:: Detach](#detach) método em algum momento no futuro a fim de permitir que o Agendador desligar.  
  
 Se esse método é chamado de um contexto que já está anexado a um agendador diferente, o Agendador existente será lembrado como o Agendador anterior e o Agendador recém-criado se torna o Agendador atual. Quando você chama o `CurrentScheduler::Detach` método em um momento posterior, o Agendador anterior será restaurado como o Agendador atual.  
  
 Esse método poderá gerar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md) e [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md).  
  
##  <a name="createschedulegroup"></a> CreateScheduleGroup 

 Cria um novo grupo de agendamento dentro do agendador associado com o contexto de chamada. A versão que usa o parâmetro `_Placement` faz com que as tarefas dentro do grupo de agenda recém-criada para ser mais adequado para a execução no local especificado por esse parâmetro.  
  
```
static ScheduleGroup* __cdecl CreateScheduleGroup();

static ScheduleGroup* __cdecl CreateScheduleGroup(location& _Placement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Placement`  
 Uma referência a um local em que as tarefas dentro do grupo de agendamento serão ser mais adequadas para execução em.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o grupo de agenda recém-criada. Isso `ScheduleGroup` objeto tem uma contagem de referência inicial colocada sobre ele.  
  
### <a name="remarks"></a>Comentários  
 Esse método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada, se não houver nenhum agendador associado atualmente com o contexto de chamada.  
  
 Você deve chamar o [versão](schedulegroup-class.md#release) método em um grupo de agenda quando você terminar o trabalho de agendamento para ele. O Agendador destruirá a agenda de grupo quando todo o trabalho na fila a ele foi concluída.  
  
 Observe que, se você criou explicitamente este Agendador, você deve liberar todas as referências para agendar grupos dentro dele, antes de liberar sua referência no Agendador, desanexando o contexto atual dele.  
  
##  <a name="detach"></a> Detach 

 Desanexa o Agendador atual do contexto de chamada e restaura o Agendador anexado anteriormente como o Agendador atual, se houver. Depois que esse método retorna, o contexto de chamada é gerenciado pelo Agendador que já tenha sido anexado ao contexto usando o `CurrentScheduler::Create` ou `Scheduler::Attach` método.  
  
```
static void __cdecl Detach();
```  
  
### <a name="remarks"></a>Comentários  
 O `Detach` implicitamente o método Remove uma contagem de referência do Agendador.  
  
 Se não houver nenhum Agendador anexado ao contexto de chamada, a chamada desse método resultará em um [scheduler_not_attached](scheduler-not-attached-class.md) exceção sendo lançada.  
  
 Chamar esse método em um contexto que é interno para e gerenciado por um agendador ou um contexto que foi anexado usando um método diferente de [Scheduler:: Attach](scheduler-class.md#attach) ou [currentscheduler:: Create](#create) métodos, resultará em uma [improper_scheduler_detach](improper-scheduler-detach-class.md) exceção sendo lançada.  
  
##  <a name="get"></a> Obter 

 Retorna um ponteiro para o Agendador associado com o contexto de chamada, também conhecido como o Agendador atual.  
  
```
static Scheduler* __cdecl Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o Agendador associado no contexto de chamada (o Agendador atual).  
  
### <a name="remarks"></a>Comentários  
 Esse método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada, se não houver nenhum agendador associado atualmente com o contexto de chamada. Nenhuma referência adicional é colocada no `Scheduler` objeto retornado por esse método.  
  
##  <a name="getnumberofvirtualprocessors"></a> GetNumberOfVirtualProcessors 

 Retorna o número atual de processadores virtuais para o Agendador associado no contexto de chamada.  
  
```
static unsigned int __cdecl GetNumberOfVirtualProcessors();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se um agendador está associado com o contexto de chamada, o número atual de processadores virtuais para que o Agendador; Caso contrário, o valor `-1`.  
  
### <a name="remarks"></a>Comentários  
 Esse método não resultará em anexo do Agendador se o contexto de chamada já não estiver associado um agendador.  
  
 O valor de retorno desse método é uma amostragem instantânea do número de processadores virtuais para o Agendador associado no contexto de chamada. Esse valor pode ser obsoleto no momento em que ele é retornado.  
  
##  <a name="getpolicy"></a> GetPolicy 

 Retorna uma cópia da política que o Agendador atual foi criado com.  
  
```
static SchedulerPolicy __cdecl GetPolicy();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia da política que o Agendador atual foi criado com.  
  
### <a name="remarks"></a>Comentários  
 Esse método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada, se não houver nenhum agendador associado atualmente com o contexto de chamada.  
  
##  <a name="id"></a> Id 

 Retorna um identificador exclusivo para o Agendador atual.  
  
```
static unsigned int __cdecl Id();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se um agendador está associado com o contexto de chamada, um identificador exclusivo para que o Agendador; Caso contrário, o valor `-1`.  
  
### <a name="remarks"></a>Comentários  
 Esse método não resultará em anexo do Agendador se o contexto de chamada já não estiver associado um agendador.  
  
##  <a name="isavailablelocation"></a> IsAvailableLocation 

 Determina se um determinado local está disponível no Agendador atual.  
  
```
static bool __cdecl IsAvailableLocation(const location& _Placement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Placement`  
 Uma referência para o local para fazer consultas sobre o Agendador atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma indicação de se ou não o local especificado pelo `_Placement` argumento está disponível no Agendador atual.  
  
### <a name="remarks"></a>Comentários  
 Esse método não resultará em anexo do Agendador se o contexto de chamada já não estiver associado um agendador.  
  
 Observe que o valor de retorno é uma amostragem de instantânea se o local em questão está disponível. Na presença de vários agendadores, gerenciamento dinâmico de recursos pode adicionar ou tirar recursos de agendadores a qualquer momento. Isso acontecer, o local em questão pode alterar a disponibilidade.  
  
##  <a name="registershutdownevent"></a> RegisterShutdownEvent 

 Faz com que o identificador de eventos do Windows passado a `_ShutdownEvent` parâmetro a ser sinalizado quando o Agendador associado ao contexto atual é desligado e destrói em si. No momento em que o evento é sinalizado, todo o trabalho foi agendado para o Agendador foi concluído. Vários eventos de desligamento podem ser registrados por meio desse método.  
  
```
static void __cdecl RegisterShutdownEvent(HANDLE _ShutdownEvent);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_ShutdownEvent`  
 Um identificador para um objeto de evento do Windows que será sinalizado pelo tempo de execução quando o Agendador associado ao contexto atual é desligado e destrói em si.  
  
### <a name="remarks"></a>Comentários  
 Se não houver nenhum Agendador anexado ao contexto de chamada, a chamada desse método resultará em um [scheduler_not_attached](scheduler-not-attached-class.md) exceção sendo lançada.  
  
##  <a name="scheduletask"></a> ScheduleTask 

 Agenda uma tarefa leve dentro do agendador associado com o contexto de chamada. A tarefa leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado.  
  
```
static void __cdecl ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data);

static void __cdecl ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data,
    location& _Placement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Proc`  
 Um ponteiro para a função a ser executada para executar o corpo da tarefa leve.  
  
 `_Data`  
 Um ponteiro nulo para os dados que serão passados como um parâmetro ao corpo da tarefa.  
  
 `_Placement`  
 Uma referência a um local em que a tarefa leve será ser mais adequada para execução em.  
  
### <a name="remarks"></a>Comentários  
 Esse método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada, se não houver nenhum agendador associado atualmente com o contexto de chamada.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe de Agendador](scheduler-class.md)   
 [PolicyElementKey](concurrency-namespace-enums.md)   
 [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)



