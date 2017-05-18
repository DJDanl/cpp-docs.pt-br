---
title: Classe de Agendador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: cc39a524e9a65aeab0c84fb43f5b38ddd892923e
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="scheduler-class"></a>Classe Scheduler
Representa uma abstração de um agendador de tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class Scheduler;
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Agendador](#ctor)|Um objeto de `Scheduler` classe pode ser apenas criados usando métodos de fábrica, ou implicitamente.|  
|[~ Destruidor scheduler](#dtor)|Um objeto de `Scheduler` classe implicitamente é destruída quando todas as referências externas a ele deixar de existir.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Anexar](#attach)|Anexa o Agendador para o contexto de chamada. Depois que este método retorna, o contexto de chamada é gerenciado pelo Agendador e o Agendador atual se torna o Agendador.|  
|[Criar](#create)|Cria um novo Agendador cujo comportamento é descrito pelo `_Policy` parâmetro, coloca uma referência inicial no Agendador e retorna um ponteiro para ele.|  
|[CreateScheduleGroup](#createschedulegroup)|Sobrecarregado. Cria um novo grupo de agenda no Agendador. A versão que aceita o parâmetro `_Placement` faz com que tarefas dentro do grupo de agenda recém-criada para ser mais adequado para a execução no local especificado pelo parâmetro.|  
|[GetNumberOfVirtualProcessors](#getnumberofvirtualprocessors)|Retorna o número atual de processadores virtuais para o Agendador.|  
|[GetPolicy](#getpolicy)|Retorna uma cópia da política criada com o Agendador.|  
|[ID](#id)|Retorna um identificador exclusivo para o Agendador.|  
|[IsAvailableLocation](#isavailablelocation)|Determina se um determinado local está disponível no Agendador.|  
|[Referência](#reference)|Incrementa a contagem de referência do Agendador.|  
|[RegisterShutdownEvent](#registershutdownevent)|Faz com que o manipulador de eventos do Windows passado a `_Event` parâmetro deve ser sinalizado quando o Agendador é desligado e destrói em si. Quando que o evento é sinalizado, todo o trabalho que teve foi agendado para o Agendador está concluído. Vários eventos de desligamento podem ser registrados por meio desse método.|  
|[Versão](#release)|Contagem de referência do programador diminui.|  
|[ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy)|Redefine a política de agendador padrão para o padrão de tempo de execução. Na próxima vez que um agendador padrão é criado, ele usará as configurações de política do tempo de execução padrão.|  
|[ScheduleTask](#scheduletask)|Sobrecarregado. Agenda uma tarefa leve no Agendador. A tarefa leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que aceita o parâmetro `_Placement` faz com que a tarefa a ser mais adequado para a execução no local especificado.|  
|[SetDefaultSchedulerPolicy](#setdefaultschedulerpolicy)|Permite que uma política definida pelo usuário a ser usado para criar o agendador padrão. Esse método pode ser chamado somente quando nenhum agendador padrão existe dentro do processo. Depois que uma política padrão tiver sido definida, ele permanecerá em vigor até a próxima chamada válida para o `SetDefaultSchedulerPolicy` ou [ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy) método.|  
  
## <a name="remarks"></a>Comentários  
 O Agendador de tempo de execução de simultaneidade usa contextos de execução, que mapeiam para os contextos de execução do sistema operacional, como um thread, para executar o trabalho em fila para ele pelo seu aplicativo. A qualquer momento, o nível de simultaneidade de um agendador é igual ao número de processadores virtuais concedidas a ele pelo Gerenciador de recursos. Um processador virtual é uma abstração para um recurso de processamento e é mapeado para um thread de hardware no sistema subjacente. Um contexto de Agendador único pode executar em um processador virtual em um determinado momento.  
  
 O tempo de execução de simultaneidade criará um agendador padrão por processo para executar o trabalho paralelo. Além disso, você pode criar seu próprio Agendador instâncias e manipulá-lo usando essa classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Scheduler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="attach"></a>Anexar 

 Anexa o Agendador para o contexto de chamada. Depois que este método retorna, o contexto de chamada é gerenciado pelo Agendador e o Agendador atual se torna o Agendador.  
  
```
virtual void Attach() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 Anexar um agendador implicitamente coloca uma referência no Agendador.  
  
 Em algum momento no futuro, você deve chamar o [Currentscheduler](currentscheduler-class.md#detach) método para permitir que o Agendador desligar.  
  
 Se esse método for chamado em um contexto já está anexado a um agendador diferente, o Agendador existente será lembrado como programador anterior e o Agendador recém-criado se torna o Agendador atual. Quando você chamar o `CurrentScheduler::Detach` método em um momento posterior, o Agendador anterior é restaurado como o Agendador atual.  
  
 Esse método gerará uma [improper_scheduler_attach](improper-scheduler-attach-class.md) exceção se o Agendador está o Agendador do contexto da chamada atual.  
  
##  <a name="create"></a>Criar 

 Cria um novo Agendador cujo comportamento é descrito pelo `_Policy` parâmetro, coloca uma referência inicial no Agendador e retorna um ponteiro para ele.  
  
```
static Scheduler* __cdecl Create(const SchedulerPolicy& _Policy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Policy`  
 A política de agendador que descreve o comportamento do Agendador recém-criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um agendador recém-criado. Isso `Scheduler` objeto tem uma contagem de referência inicial colocada nele.  
  
### <a name="remarks"></a>Comentários  
 Depois de um agendador é criado com o `Create` método, você deve chamar o `Release` método em algum momento no futuro para remover a contagem de referência inicial e permitir que o Agendador desligar.  
  
 Um agendador criado com esse método não está anexado ao contexto de chamada. Ele pode ser anexado a um contexto usando o [Attach](#attach) método.  
  
 Esse método pode acionar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md) e [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md).  
  
##  <a name="createschedulegroup"></a>CreateScheduleGroup 

 Cria um novo grupo de agenda no Agendador. A versão que aceita o parâmetro `_Placement` faz com que tarefas dentro do grupo de agenda recém-criada para ser mais adequado para a execução no local especificado pelo parâmetro.  
  
```
virtual ScheduleGroup* CreateScheduleGroup() = 0;

virtual ScheduleGroup* CreateScheduleGroup(location& _Placement) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Placement`  
 Uma referência a um local em que as tarefas dentro do grupo de agendamento serão tendência para execução em.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o grupo de agenda recém-criada. Isso `ScheduleGroup` objeto tem uma contagem de referência inicial colocada nele.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o [versão](schedulegroup-class.md#release) método em um grupo de agendamento quando terminar de agendamento de trabalho a ele. O Agendador destruirá a agenda de grupo quando todo o trabalho é colocado nela foi concluída.  
  
 Observe que, se você criou explicitamente este Agendador, você deve liberar todas as referências para agendar grupos dentro dele, antes de liberar as referências no Agendador.  
  
##  <a name="getnumberofvirtualprocessors"></a>GetNumberOfVirtualProcessors 

 Retorna o número atual de processadores virtuais para o Agendador.  
  
```
virtual unsigned int GetNumberOfVirtualProcessors() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número atual de processadores virtuais para o Agendador.  
  
##  <a name="getpolicy"></a>GetPolicy 

 Retorna uma cópia da política criada com o Agendador.  
  
```
virtual SchedulerPolicy GetPolicy() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia da política criada com o Agendador.  
  
##  <a name="id"></a>ID 

 Retorna um identificador exclusivo para o Agendador.  
  
```
virtual unsigned int Id() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador exclusivo para o Agendador.  
  
##  <a name="isavailablelocation"></a>IsAvailableLocation 

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
 Observe que o valor de retorno é uma amostragem de instantânea se o local especificado está disponível. Na presença de vários agendadores, gerenciamento dinâmico de recursos pode adicionar ou tirar recursos de agendadores a qualquer momento. Isso acontecer, o local determinado pode alterar a disponibilidade.  
  
##  <a name="reference"></a>Referência 

 Incrementa a contagem de referência do Agendador.  
  
```
virtual unsigned int Reference() = 0 ;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência recentemente incrementado.  
  
### <a name="remarks"></a>Comentários  
 Isso normalmente é usado para gerenciar o tempo de vida do Agendador de composição. Quando a contagem de referência de fica um agendador para zero, o Agendador será desligado e destruição próprio Afinal de contas de trabalho no Agendador foi concluída.  
  
 O método gerará uma [improper_scheduler_reference](improper-scheduler-reference-class.md) exceção se a contagem de referência antes de chamar o `Reference` método era zero e a chamada é feita em um contexto que não é propriedade pelo Agendador.  
  
##  <a name="registershutdownevent"></a>RegisterShutdownEvent 

 Faz com que o manipulador de eventos do Windows passado a `_Event` parâmetro deve ser sinalizado quando o Agendador é desligado e destrói em si. Quando que o evento é sinalizado, todo o trabalho que teve foi agendado para o Agendador está concluído. Vários eventos de desligamento podem ser registrados por meio desse método.  
  
```
virtual void RegisterShutdownEvent(HANDLE _Event) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Event`  
 Um identificador para um objeto de evento do Windows que será sinalizado pelo tempo de execução quando o Agendador é desligado e destrói em si.  
  
##  <a name="release"></a>Versão 

 Contagem de referência do programador diminui.  
  
```
virtual unsigned int Release() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência recentemente diminuído.  
  
### <a name="remarks"></a>Comentários  
 Isso normalmente é usado para gerenciar o tempo de vida do Agendador de composição. Quando a contagem de referência de fica um agendador para zero, o Agendador será desligado e destruição próprio Afinal de contas de trabalho no Agendador foi concluída.  
  
##  <a name="resetdefaultschedulerpolicy"></a>ResetDefaultSchedulerPolicy 

 Redefine a política de agendador padrão para o padrão de tempo de execução. Na próxima vez que um agendador padrão é criado, ele usará as configurações de política do tempo de execução padrão.  
  
```
static void __cdecl ResetDefaultSchedulerPolicy();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser chamado enquanto um agendador padrão existe dentro do processo. Isso não afetará a diretiva do agendador padrão existente. No entanto, se o agendador padrão para desligar, e um novo padrão foram a ser criado em um momento posterior, o novo Agendador usaria as configurações de política do tempo de execução padrão.  
  
##  <a name="ctor"></a>Agendador 

 Um objeto de `Scheduler` classe pode ser apenas criados usando métodos de fábrica, ou implicitamente.  
  
```
Scheduler();
```  
  
### <a name="remarks"></a>Comentários  
 O agendador padrão o processo é criado implicitamente quando você utilizar muitas das funções de tempo de execução que exigem um agendador a ser anexado ao contexto de chamada. Métodos dentro de `CurrentScheduler` classe e os recursos das camadas de agentes e PPL normalmente executam anexo implícito.  
  
 Você também pode criar um agendador explicitamente por meio de `CurrentScheduler::Create` método ou o `Scheduler::Create` método.  
  
##  <a name="dtor"></a>~ Scheduler 

 Um objeto de `Scheduler` classe implicitamente é destruída quando todas as referências externas a ele deixar de existir.  
  
```
virtual ~Scheduler();
```  
  
##  <a name="scheduletask"></a>ScheduleTask 

 Agenda uma tarefa leve no Agendador. A tarefa leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que aceita o parâmetro `_Placement` faz com que a tarefa a ser mais adequado para a execução no local especificado.  
  
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
 Um ponteiro nulo para os dados que serão passados como um parâmetro no corpo da tarefa.  
  
 `_Placement`  
 Uma referência a um local em que a tarefa leve será ser tendência para execução em.  
  
##  <a name="setdefaultschedulerpolicy"></a>SetDefaultSchedulerPolicy 

 Permite que uma política definida pelo usuário a ser usado para criar o agendador padrão. Esse método pode ser chamado somente quando nenhum agendador padrão existe dentro do processo. Depois que uma política padrão tiver sido definida, ele permanecerá em vigor até a próxima chamada válida para o `SetDefaultSchedulerPolicy` ou [ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy) método.  
  
```
static void __cdecl SetDefaultSchedulerPolicy(const SchedulerPolicy& _Policy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Policy`  
 A política a ser definida como a diretiva de agendador padrão.  
  
### <a name="remarks"></a>Comentários  
 Se o `SetDefaultSchedulerPolicy` método é chamado quando um agendador padrão já existe dentro do processo, o tempo de execução lançará um [default_scheduler_exists](default-scheduler-exists-class.md) exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe de Agendador](scheduler-class.md)   
 [PolicyElementKey](concurrency-namespace-enums.md)   
 [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)




