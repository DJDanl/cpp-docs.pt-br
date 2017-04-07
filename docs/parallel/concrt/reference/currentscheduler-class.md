---
title: Classe CurrentScheduler | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 20
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
ms.openlocfilehash: 9536dd28eeb375f3b9e018539cefb338812e340b
ms.lasthandoff: 03/17/2017

---
# <a name="currentscheduler-class"></a>Classe CurrentScheduler
Representa uma abstração para o Agendador atual associado ao contexto de chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CurrentScheduler;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Criar](#create)|Cria um novo Agendador cujo comportamento é descrito pelo `_Policy` parâmetro e anexa-o ao contexto de chamada. O Agendador recém-criado se tornará o Agendador atual para o contexto de chamada.|  
|[CreateScheduleGroup](#createschedulegroup)|Sobrecarregado. Cria um novo grupo de agenda no agendador associado ao contexto de chamada. A versão que aceita o parâmetro `_Placement` faz com que tarefas dentro do grupo de agenda recém-criada para ser mais adequado para a execução no local especificado pelo parâmetro.|  
|[Desanexar](#detach)|Desanexa o Agendador do contexto de chamada atual e restaura o Agendador anexado anteriormente como o Agendador atual, se houver. Depois que este método retorna, o contexto de chamada é gerenciado pelo Agendador que anteriormente foi anexado ao contexto usando o `CurrentScheduler::Create` ou `Scheduler::Attach` método.|  
|[Obter](#get)|Retorna um ponteiro para o Agendador associado ao contexto de chamada, também conhecido como o Agendador atual.|  
|[GetNumberOfVirtualProcessors](#getnumberofvirtualprocessors)|Retorna o número atual de processadores virtuais para o Agendador associado ao contexto de chamada.|  
|[GetPolicy](#getpolicy)|Retorna uma cópia da política criada com o Agendador atual.|  
|[ID](#id)|Retorna um identificador exclusivo para o Agendador atual.|  
|[IsAvailableLocation](#isavailablelocation)|Determina se um determinado local está disponível no Agendador atual.|  
|[RegisterShutdownEvent](#registershutdownevent)|Faz com que o manipulador de eventos do Windows passado a `_ShutdownEvent` parâmetro deve ser sinalizado quando o Agendador associado ao contexto atual é desligado e destrói em si. Quando que o evento é sinalizado, todo o trabalho que teve foi agendado para o Agendador está concluído. Vários eventos de desligamento podem ser registrados por meio desse método.|  
|[ScheduleTask](#scheduletask)|Sobrecarregado. Agenda uma tarefa leve dentro do agendador associado com o contexto de chamada. A tarefa leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que aceita o parâmetro `_Placement` faz com que a tarefa a ser mais adequado para a execução no local especificado.|  
  
## <a name="remarks"></a>Comentários  
 Se não houver nenhum Agendador (consulte [Agendador](scheduler-class.md)) associado ao contexto de chamada, muitos métodos dentro de `CurrentScheduler` classe resultará em anexo do Agendador de padrão do processo. Isso também pode indicar que o agendador padrão o processo é criado durante essa chamada.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CurrentScheduler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="create"></a>Criar 

 Cria um novo Agendador cujo comportamento é descrito pelo `_Policy` parâmetro e anexa-o ao contexto de chamada. O Agendador recém-criado se tornará o Agendador atual para o contexto de chamada.  
  
```
static void __cdecl Create(const SchedulerPolicy& _Policy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Policy`  
 A política de agendador que descreve o comportamento do Agendador recém-criado.  
  
### <a name="remarks"></a>Comentários  
 O anexo do Agendador para o contexto de chamada implicitamente coloca uma contagem de referência no Agendador.  
  
 Depois de um agendador é criado com o `Create` método, você deve chamar o [Currentscheduler](#detach) método em algum momento no futuro para permitir que o Agendador desligar.  
  
 Se esse método for chamado em um contexto já está anexado a um agendador diferente, o Agendador existente será lembrado como programador anterior e o Agendador recém-criado se torna o Agendador atual. Quando você chamar o `CurrentScheduler::Detach` método em um momento posterior, o Agendador anterior é restaurado como o Agendador atual.  
  
 Esse método pode acionar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md) e [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md).  
  
##  <a name="createschedulegroup"></a>CreateScheduleGroup 

 Cria um novo grupo de agenda no agendador associado ao contexto de chamada. A versão que aceita o parâmetro `_Placement` faz com que tarefas dentro do grupo de agenda recém-criada para ser mais adequado para a execução no local especificado pelo parâmetro.  
  
```
static ScheduleGroup* __cdecl CreateScheduleGroup();

static ScheduleGroup* __cdecl CreateScheduleGroup(location& _Placement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Placement`  
 Uma referência a um local em que as tarefas dentro do grupo de agendamento serão ser tendência para execução em.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o grupo de agenda recém-criada. Isso `ScheduleGroup` objeto tem uma contagem de referência inicial colocada nele.  
  
### <a name="remarks"></a>Comentários  
 Este método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada se não houver nenhum Agendador atualmente associado ao contexto de chamada.  
  
 Você deve chamar o [versão](schedulegroup-class.md#release) método em um grupo de agendamento quando terminar de agendamento de trabalho a ele. O Agendador destruirá a agenda de grupo quando todo o trabalho é colocado nela foi concluída.  
  
 Observe que, se você criou explicitamente este Agendador, você deve liberar todas as referências para agendar grupos dentro dele, antes de liberar sua referência no Agendador, desanexando o contexto atual dele.  
  
##  <a name="detach"></a>Desanexar 

 Desanexa o Agendador do contexto de chamada atual e restaura o Agendador anexado anteriormente como o Agendador atual, se houver. Depois que este método retorna, o contexto de chamada é gerenciado pelo Agendador que anteriormente foi anexado ao contexto usando o `CurrentScheduler::Create` ou `Scheduler::Attach` método.  
  
```
static void __cdecl Detach();
```  
  
### <a name="remarks"></a>Comentários  
 O `Detach` método implicitamente remove uma contagem de referência do Agendador.  
  
 Se não houver nenhum Agendador anexada ao contexto de chamada, chamar este método resulta em uma [scheduler_not_attached](scheduler-not-attached-class.md) exceção sendo lançada.  
  
 Chamar esse método em um contexto que é interno e gerenciados por um agendador ou um contexto que foi anexado com um método diferente do [Scheduler](scheduler-class.md#attach) ou [Currentscheduler](#create) métodos, resultará em uma [improper_scheduler_detach](improper-scheduler-detach-class.md) exceção sendo lançada.  
  
##  <a name="get"></a>Obter 

 Retorna um ponteiro para o Agendador associado ao contexto de chamada, também conhecido como o Agendador atual.  
  
```
static Scheduler* __cdecl Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o Agendador associado ao contexto de chamada (o Agendador atual).  
  
### <a name="remarks"></a>Comentários  
 Este método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada se não houver nenhum Agendador atualmente associado ao contexto de chamada. Nenhuma referência adicional é colocada sobre o `Scheduler` objeto retornado por esse método.  
  
##  <a name="getnumberofvirtualprocessors"></a>GetNumberOfVirtualProcessors 

 Retorna o número atual de processadores virtuais para o Agendador associado ao contexto de chamada.  
  
```
static unsigned int __cdecl GetNumberOfVirtualProcessors();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se um agendador está associado com o contexto de chamada, o número atual de processadores virtuais para que o Agendador; Caso contrário, o valor `-1`.  
  
### <a name="remarks"></a>Comentários  
 Esse método não resultará em anexo do Agendador se o contexto de chamada já não estiver associado um agendador.  
  
 O valor de retorno desse método é uma amostragem instantânea do número de processadores virtuais para o Agendador associado ao contexto de chamada. Esse valor pode ser atualizado no momento em que ele é retornado.  
  
##  <a name="getpolicy"></a>GetPolicy 

 Retorna uma cópia da política criada com o Agendador atual.  
  
```
static SchedulerPolicy __cdecl GetPolicy();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia da política que o Agendador atual foi criado.  
  
### <a name="remarks"></a>Comentários  
 Este método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada se não houver nenhum Agendador atualmente associado ao contexto de chamada.  
  
##  <a name="id"></a>ID 

 Retorna um identificador exclusivo para o Agendador atual.  
  
```
static unsigned int __cdecl Id();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se um agendador está associado com o contexto de chamada, um identificador exclusivo para que o Agendador; Caso contrário, o valor `-1`.  
  
### <a name="remarks"></a>Comentários  
 Esse método não resultará em anexo do Agendador se o contexto de chamada já não estiver associado um agendador.  
  
##  <a name="isavailablelocation"></a>IsAvailableLocation 

 Determina se um determinado local está disponível no Agendador atual.  
  
```
static bool __cdecl IsAvailableLocation(const location& _Placement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Placement`  
 Uma referência para o local para consultar o Agendador atual sobre.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se o local especificado pelo `_Placement` argumento está disponível no Agendador atual.  
  
### <a name="remarks"></a>Comentários  
 Esse método não resultará em anexo do Agendador se o contexto de chamada já não estiver associado um agendador.  
  
 Observe que o valor de retorno é uma amostragem de instantânea se o local especificado está disponível. Na presença de vários agendadores, gerenciamento dinâmico de recursos pode adicionar ou tirar recursos de agendadores a qualquer momento. Isso acontecer, o local determinado pode alterar a disponibilidade.  
  
##  <a name="registershutdownevent"></a>RegisterShutdownEvent 

 Faz com que o manipulador de eventos do Windows passado a `_ShutdownEvent` parâmetro deve ser sinalizado quando o Agendador associado ao contexto atual é desligado e destrói em si. Quando que o evento é sinalizado, todo o trabalho que teve foi agendado para o Agendador está concluído. Vários eventos de desligamento podem ser registrados por meio desse método.  
  
```
static void __cdecl RegisterShutdownEvent(HANDLE _ShutdownEvent);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_ShutdownEvent`  
 Um identificador para um objeto de evento do Windows que será sinalizado pelo tempo de execução quando o Agendador associado ao contexto atual é desligado e destrói em si.  
  
### <a name="remarks"></a>Comentários  
 Se não houver nenhum Agendador anexada ao contexto de chamada, chamar este método resulta em uma [scheduler_not_attached](scheduler-not-attached-class.md) exceção sendo lançada.  
  
##  <a name="scheduletask"></a>ScheduleTask 

 Agenda uma tarefa leve dentro do agendador associado com o contexto de chamada. A tarefa leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que aceita o parâmetro `_Placement` faz com que a tarefa a ser mais adequado para a execução no local especificado.  
  
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
 Um ponteiro nulo para os dados que serão passados como um parâmetro no corpo da tarefa.  
  
 `_Placement`  
 Uma referência a um local em que a tarefa leve será ser tendência para execução em.  
  
### <a name="remarks"></a>Comentários  
 Este método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada se não houver nenhum Agendador atualmente associado ao contexto de chamada.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe de Agendador](scheduler-class.md)   
 [PolicyElementKey](concurrency-namespace-enums.md)   
 [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)




