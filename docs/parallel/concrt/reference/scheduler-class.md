---
title: Classe de Agendador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- Scheduler
- CONCRT/concurrency::Scheduler
- CONCRT/concurrency::Scheduler::Scheduler
- CONCRT/concurrency::Scheduler::Attach
- CONCRT/concurrency::Scheduler::Create
- CONCRT/concurrency::Scheduler::CreateScheduleGroup
- CONCRT/concurrency::Scheduler::GetNumberOfVirtualProcessors
- CONCRT/concurrency::Scheduler::GetPolicy
- CONCRT/concurrency::Scheduler::Id
- CONCRT/concurrency::Scheduler::IsAvailableLocation
- CONCRT/concurrency::Scheduler::Reference
- CONCRT/concurrency::Scheduler::RegisterShutdownEvent
- CONCRT/concurrency::Scheduler::Release
- CONCRT/concurrency::Scheduler::ResetDefaultSchedulerPolicy
- CONCRT/concurrency::Scheduler::ScheduleTask
- CONCRT/concurrency::Scheduler::SetDefaultSchedulerPolicy
dev_langs:
- C++
helpviewer_keywords:
- Scheduler class
ms.assetid: 34cf7961-048d-4852-8a5c-a32f823e3506
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f7431776a27668fc1f1c465377f1e947eb36ab99
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="scheduler-class"></a>Classe Scheduler
Representa uma abstração para um agendador de tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class Scheduler;
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Agendador](#ctor)|Um objeto de `Scheduler` classe pode apenas criadas usando métodos de fábrica, ou implicitamente.|  
|[~ Destruidor scheduler](#dtor)|Um objeto de `Scheduler` classe implicitamente é destruída quando todas as referências externas a ele deixar de existir.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Anexar](#attach)|Anexa o Agendador para o contexto de chamada. Depois que este método retorna, o contexto de chamada é gerenciado pelo Agendador e o Agendador se torna o Agendador atual.|  
|[Criar](#create)|Cria um novo Agendador cujo comportamento é descrito pelo `_Policy` parâmetro, coloca uma referência inicial no Agendador e retorna um ponteiro para ele.|  
|[CreateScheduleGroup](#createschedulegroup)|Sobrecarregado. Cria um novo grupo de agenda no Agendador. A versão que usa o parâmetro `_Placement` faz com que tarefas dentro do grupo de agenda recém-criada para ser mais adequado para a execução no local especificado por esse parâmetro.|  
|[GetNumberOfVirtualProcessors](#getnumberofvirtualprocessors)|Retorna o número atual de processadores virtuais para o Agendador.|  
|[GetPolicy](#getpolicy)|Retorna uma cópia da política com o Agendador foi criado.|  
|[Id](#id)|Retorna um identificador exclusivo para o Agendador.|  
|[IsAvailableLocation](#isavailablelocation)|Determina se um determinado local está disponível no Agendador.|  
|[Referência](#reference)|Incrementa a contagem de referência do Agendador.|  
|[RegisterShutdownEvent](#registershutdownevent)|Faz com que o identificador de eventos do Windows passado a `_Event` parâmetro para ser avisado quando o Agendador fecha e destrói a mesmo. No momento em que o evento é sinalizado, todo o trabalho que teve foi agendado para o Agendador está concluído. Vários eventos de desligamento podem ser registrados por esse método.|  
|[Versão](#release)|Diminui a Agendador contagem de referência.|  
|[ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy)|Redefine a política de agendador padrão para o padrão de tempo de execução. Na próxima vez que um agendador padrão é criado, ele usará as configurações de política do tempo de execução padrão.|  
|[ScheduleTask](#scheduletask)|Sobrecarregado. Agenda uma tarefa leve no Agendador. A tarefa leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado.|  
|[SetDefaultSchedulerPolicy](#setdefaultschedulerpolicy)|Permite que uma política definida pelo usuário a ser usado para criar o agendador padrão. Esse método pode ser chamado somente quando nenhum agendador padrão existe dentro do processo. Depois que uma política padrão tiver sido definida, ele permanecerá em vigor até a próxima chamada válida para o `SetDefaultSchedulerPolicy` ou [ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy) método.|  
  
## <a name="remarks"></a>Comentários  
 O Agendador de tempo de execução de simultaneidade usa contextos de execução, que mapeiam para os contextos de execução do sistema operacional, como um thread executar o trabalho enfileirado para ele pelo seu aplicativo. A qualquer momento, o nível de simultaneidade de um agendador é igual ao número de processador virtual concedido a ele pelo Gerenciador de recursos. Um processador virtual é uma abstração para um recurso de processamento e é mapeado para um thread de hardware do sistema subjacente. Somente um contexto de Agendador único pode executar em um processador virtual em um determinado momento.  
  
 O tempo de execução de simultaneidade criará um agendador padrão por um processo para executar o trabalho paralelos. Além disso, você pode criar seu próprios Agendador instâncias e manipulá-lo usando esta classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Scheduler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="attach"></a> Attach 

 Anexa o Agendador para o contexto de chamada. Depois que este método retorna, o contexto de chamada é gerenciado pelo Agendador e o Agendador se torna o Agendador atual.  
  
```
virtual void Attach() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 A anexação de um agendador implicitamente coloca uma referência no Agendador.  
  
 Em algum momento no futuro, você deve chamar o [Currentscheduler](currentscheduler-class.md#detach) método para permitir que o Agendador desligar.  
  
 Se esse método é chamado de um contexto que já está anexado a um agendador diferente, o Agendador existente será lembrado como o Agendador anterior, e o Agendador recém-criado se torna o Agendador atual. Quando você chama o `CurrentScheduler::Detach` método em um momento posterior, o Agendador anterior será restaurado como o Agendador atual.  
  
 Esse método lançará um [improper_scheduler_attach](improper-scheduler-attach-class.md) exceção se o Agendador está o Agendador atual do contexto da chamada.  
  
##  <a name="create">Criar</a> 

 Cria um novo Agendador cujo comportamento é descrito pelo `_Policy` parâmetro, coloca uma referência inicial no Agendador e retorna um ponteiro para ele.  
  
```
static Scheduler* __cdecl Create(const SchedulerPolicy& _Policy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Policy`  
 A política de agendador que descreve o comportamento do Agendador recém-criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um agendador recém-criado. Isso `Scheduler` objeto tem uma contagem de referência inicial colocada nela.  
  
### <a name="remarks"></a>Comentários  
 Depois de um agendador é criado com o `Create` método, você deve chamar o `Release` método em algum momento no futuro para remover a contagem de referência inicial e permitir que o Agendador desligar.  
  
 Um agendador criado com esse método não está anexado ao contexto de chamada. Ele pode ser anexado a um contexto usando o [Attach](#attach) método.  
  
 Esse método pode acionar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md) e [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md).  
  
##  <a name="createschedulegroup"></a> CreateScheduleGroup 

 Cria um novo grupo de agenda no Agendador. A versão que usa o parâmetro `_Placement` faz com que tarefas dentro do grupo de agenda recém-criada para ser mais adequado para a execução no local especificado por esse parâmetro.  
  
```
virtual ScheduleGroup* CreateScheduleGroup() = 0;

virtual ScheduleGroup* CreateScheduleGroup(location& _Placement) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Placement`  
 Uma referência a um local em que as tarefas dentro do grupo de agendamento será restrito em execução no.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o grupo de agenda recém-criada. Isso `ScheduleGroup` objeto tem uma contagem de referência inicial colocada nela.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o [versão](schedulegroup-class.md#release) método em um grupo de agenda quando você terminar de agendamento de trabalho a ele. O Agendador destruirá o agendamento de grupo quando todo o trabalho em fila para que ele foi concluído.  
  
 Observe que, se você criou explicitamente neste Agendador, você deve liberar todas as referências para agendar grupos dentro dele, antes de liberar as referências no Agendador.  
  
##  <a name="getnumberofvirtualprocessors"></a> GetNumberOfVirtualProcessors 

 Retorna o número atual de processadores virtuais para o Agendador.  
  
```
virtual unsigned int GetNumberOfVirtualProcessors() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número atual de processadores virtuais para o Agendador.  
  
##  <a name="getpolicy"></a> GetPolicy 

 Retorna uma cópia da política com o Agendador foi criado.  
  
```
virtual SchedulerPolicy GetPolicy() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia da política com o Agendador foi criado.  
  
##  <a name="id"></a> Id 

 Retorna um identificador exclusivo para o Agendador.  
  
```
virtual unsigned int Id() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador exclusivo para o Agendador.  
  
##  <a name="isavailablelocation"></a> IsAvailableLocation 

 Determina se um determinado local está disponível no Agendador.  
  
```
virtual bool IsAvailableLocation(const location& _Placement) const = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Placement`  
 Uma referência para o local para consultar o Agendador sobre.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se o local especificado pelo `_Placement` argumento está disponível no Agendador.  
  
### <a name="remarks"></a>Comentários  
 Observe que o valor de retorno é uma amostragem imediatos de se o local em questão está disponível. Na presença de agendadores várias, gerenciamento dinâmico de recursos para adicionar ou tirar recursos de agendadores a qualquer momento. Isso acontecer, o local em questão pode alterar a disponibilidade.  
  
##  <a name="reference"></a> Referência 

 Incrementa a contagem de referência do Agendador.  
  
```
virtual unsigned int Reference() = 0 ;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência recentemente incrementado.  
  
### <a name="remarks"></a>Comentários  
 Isso normalmente é usado para gerenciar o tempo de vida do Agendador de composição. Quando a contagem de referência de um agendador está como zero, o Agendador será desligado e destruct próprio depois que todos os trabalhar no Agendador foi concluída.  
  
 O método lançará um [improper_scheduler_reference](improper-scheduler-reference-class.md) exceção se a contagem de referência antes de chamar o `Reference` método era zero e a chamada é feita em um contexto que não é propriedade pelo Agendador.  
  
##  <a name="registershutdownevent"></a> RegisterShutdownEvent 

 Faz com que o identificador de eventos do Windows passado a `_Event` parâmetro para ser avisado quando o Agendador fecha e destrói a mesmo. No momento em que o evento é sinalizado, todo o trabalho que teve foi agendado para o Agendador está concluído. Vários eventos de desligamento podem ser registrados por esse método.  
  
```
virtual void RegisterShutdownEvent(HANDLE _Event) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Event`  
 Um identificador para um objeto de evento do Windows que será sinalizado pelo tempo de execução quando o Agendador fecha e destrói a mesmo.  
  
##  <a name="release"></a> versão 

 Diminui a Agendador contagem de referência.  
  
```
virtual unsigned int Release() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência recentemente diminuído.  
  
### <a name="remarks"></a>Comentários  
 Isso normalmente é usado para gerenciar o tempo de vida do Agendador de composição. Quando a contagem de referência de um agendador está como zero, o Agendador será desligado e destruct próprio depois que todos os trabalhar no Agendador foi concluída.  
  
##  <a name="resetdefaultschedulerpolicy"></a> ResetDefaultSchedulerPolicy 

 Redefine a política de agendador padrão para o padrão de tempo de execução. Na próxima vez que um agendador padrão é criado, ele usará as configurações de política do tempo de execução padrão.  
  
```
static void __cdecl ResetDefaultSchedulerPolicy();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser chamado enquanto um agendador padrão existe dentro do processo. Isso não afetará a política do agendador padrão existente. No entanto, se o agendador padrão foram desligamento, e um novo padrão a ser criado em um momento posterior, o novo Agendador usaria as configurações de política do tempo de execução padrão.  
  
##  <a name="ctor"></a> Agendador 

 Um objeto de `Scheduler` classe pode apenas criadas usando métodos de fábrica, ou implicitamente.  
  
```
Scheduler();
```  
  
### <a name="remarks"></a>Comentários  
 Agendador de padrão do processo é criado implicitamente quando você usar muitas das funções de tempo de execução que exigem um agendador a ser anexado ao contexto de chamada. Métodos dentro de `CurrentScheduler` classe e os recursos das camadas de agentes e PPL normalmente executam anexo implícita.  
  
 Você também pode criar um agendador explicitamente por meio de `CurrentScheduler::Create` método ou o `Scheduler::Create` método.  
  
##  <a name="dtor"></a> ~ Scheduler 

 Um objeto de `Scheduler` classe implicitamente é destruída quando todas as referências externas a ele deixar de existir.  
  
```
virtual ~Scheduler();
```  
  
##  <a name="scheduletask"></a> ScheduleTask 

 Agenda uma tarefa leve no Agendador. A tarefa leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado.  
  
```
virtual void ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data) = 0;

virtual void ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data,
    location& _Placement) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Proc`  
 Um ponteiro para a função a ser executada para executar o corpo da tarefa leve.  
  
 `_Data`  
 Um ponteiro nulo para os dados que serão passados como um parâmetro para o corpo da tarefa.  
  
 `_Placement`  
 Uma referência a um local em que a tarefa leve será ser restrito em execução no.  
  
##  <a name="setdefaultschedulerpolicy"></a> SetDefaultSchedulerPolicy 

 Permite que uma política definida pelo usuário a ser usado para criar o agendador padrão. Esse método pode ser chamado somente quando nenhum agendador padrão existe dentro do processo. Depois que uma política padrão tiver sido definida, ele permanecerá em vigor até a próxima chamada válida para o `SetDefaultSchedulerPolicy` ou [ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy) método.  
  
```
static void __cdecl SetDefaultSchedulerPolicy(const SchedulerPolicy& _Policy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Policy`  
 A política a ser definido como a política de agendador padrão.  
  
### <a name="remarks"></a>Comentários  
 Se o `SetDefaultSchedulerPolicy` método é chamado quando um agendador padrão já existe dentro do processo, o tempo de execução lançará um [default_scheduler_exists](default-scheduler-exists-class.md) exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe de Agendador](scheduler-class.md)   
 [PolicyElementKey](concurrency-namespace-enums.md)   
 [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)



