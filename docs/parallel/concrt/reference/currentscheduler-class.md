---
title: Classe CurrentScheduler
ms.date: 11/04/2016
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
helpviewer_keywords:
- CurrentScheduler class
ms.assetid: 31c20e0e-4cdf-49b4-8220-d726130aad2b
ms.openlocfilehash: 6bf61af9ff55722553353a045c87501dbd27fad9
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79422181"
---
# <a name="currentscheduler-class"></a>Classe CurrentScheduler

Representa uma abstração para o Agendador atual associado ao contexto de chamada.

## <a name="syntax"></a>Sintaxe

```cpp
class CurrentScheduler;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Criar](#create)|Cria um novo agendador cujo comportamento é descrito pelo parâmetro `_Policy` e o anexa ao contexto de chamada. O Agendador recém-criado se tornará o Agendador atual para o contexto de chamada.|
|[CreateSchedule](#createschedulegroup)|Sobrecarregado. Cria um novo grupo de agendamento dentro do Agendador associado ao contexto de chamada. A versão que usa o parâmetro `_Placement` faz com que as tarefas dentro do grupo de agendamento recém-criado sejam ajustadas em direção à execução no local especificado por esse parâmetro.|
|[Desanexar](#detach)|Desanexa o Agendador atual do contexto de chamada e restaura o Agendador anexado anteriormente como o Agendador atual, se houver. Após esse método retornar, o contexto de chamada é então gerenciado pelo Agendador que foi anexado anteriormente ao contexto usando o método `CurrentScheduler::Create` ou `Scheduler::Attach`.|
|[Get](#get)|Retorna um ponteiro para o Agendador associado ao contexto de chamada, também conhecido como o Agendador atual.|
|[GetNumberOfVirtualProcessors](#getnumberofvirtualprocessors)|Retorna o número atual de processadores virtuais para o Agendador associado ao contexto de chamada.|
|[GetPolicy](#getpolicy)|Retorna uma cópia da política com a qual o Agendador atual foi criado.|
|[Id](#id)|Retorna um identificador exclusivo para o Agendador atual.|
|[IsAvailableLocation](#isavailablelocation)|Determina se um determinado local está disponível no Agendador atual.|
|[RegisterShutdownEvent](#registershutdownevent)|Faz com que o identificador de evento do Windows passado no parâmetro `_ShutdownEvent` seja sinalizado quando o Agendador associado ao contexto atual é desligado e se destrói. No momento em que o evento é sinalizado, todo o trabalho que foi agendado para o Agendador é concluído. Vários eventos de desligamento podem ser registrados por meio desse método.|
|[ScheduleTask](#scheduletask)|Sobrecarregado. Agenda uma tarefa leve dentro do Agendador associado ao contexto de chamada. A tarefa de peso leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado.|

## <a name="remarks"></a>Comentários

Se não houver um Agendador (consulte o [Agendador](scheduler-class.md)) associado ao contexto de chamada, muitos métodos dentro da classe `CurrentScheduler` resultarão no anexo do agendador padrão do processo. Isso também pode indicar que o agendador padrão do processo é criado durante essa chamada.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CurrentScheduler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="create"></a> Criar

Cria um novo agendador cujo comportamento é descrito pelo parâmetro `_Policy` e o anexa ao contexto de chamada. O Agendador recém-criado se tornará o Agendador atual para o contexto de chamada.

```cpp
static void __cdecl Create(const SchedulerPolicy& _Policy);
```

### <a name="parameters"></a>parâmetros

*_Policy*<br/>
A política do Agendador que descreve o comportamento do Agendador recém-criado.

### <a name="remarks"></a>Comentários

O anexo do Agendador para o contexto de chamada coloca implicitamente uma contagem de referência no Agendador.

Depois que um Agendador é criado com o método `Create`, você deve chamar o método [CurrentScheduler::D Etach](#detach) em algum momento no futuro para permitir que o Agendador seja desligado.

Se esse método for chamado de um contexto que já está anexado a um Agendador diferente, o Agendador existente será lembrado como o Agendador anterior e o Agendador recém-criado se tornará o Agendador atual. Quando você chama o método `CurrentScheduler::Detach` em um ponto posterior, o Agendador anterior é restaurado como o Agendador atual.

Esse método pode lançar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md) e [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md).

## <a name="createschedulegroup"></a>CreateSchedule

Cria um novo grupo de agendamento dentro do Agendador associado ao contexto de chamada. A versão que usa o parâmetro `_Placement` faz com que as tarefas dentro do grupo de agendamento recém-criado sejam ajustadas em direção à execução no local especificado por esse parâmetro.

```cpp
static ScheduleGroup* __cdecl CreateScheduleGroup();

static ScheduleGroup* __cdecl CreateScheduleGroup(location& _Placement);
```

### <a name="parameters"></a>parâmetros

*_Placement*<br/>
Uma referência a um local em que as tarefas dentro do grupo de agendamento serão inclinadas em direção à execução em.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o grupo de agendamento recém-criado. Este objeto de `ScheduleGroup` tem uma contagem de referência inicial colocada nele.

### <a name="remarks"></a>Comentários

Esse método fará com que o agendador padrão do processo seja criado e/ou anexado ao contexto de chamada se não houver um Agendador associado ao contexto de chamada no momento.

Você deve invocar o método de [liberação](schedulegroup-class.md#release) em um grupo de agendamento quando terminar de agendar trabalho para ele. O Agendador destruirá o grupo de agendamento quando todo o trabalho enfileirado para ele for concluído.

Observe que, se você criou explicitamente esse Agendador, deverá liberar todas as referências para agendar grupos dentro dela, antes de liberar a referência no Agendador, desanexando o contexto atual dele.

## <a name="detach"></a>Remover

Desanexa o Agendador atual do contexto de chamada e restaura o Agendador anexado anteriormente como o Agendador atual, se houver. Após esse método retornar, o contexto de chamada é então gerenciado pelo Agendador que foi anexado anteriormente ao contexto usando o método `CurrentScheduler::Create` ou `Scheduler::Attach`.

```cpp
static void __cdecl Detach();
```

### <a name="remarks"></a>Comentários

O método `Detach` remove implicitamente uma contagem de referência do Agendador.

Se não houver um Agendador anexado ao contexto de chamada, chamar esse método resultará na geração de uma exceção [scheduler_not_attached](scheduler-not-attached-class.md) .

Chamar esse método de um contexto que é interno e gerenciado por um Agendador, ou um contexto que foi anexado usando um método diferente dos métodos [Scheduler:: Attach](scheduler-class.md#attach) ou [CurrentScheduler:: Create](#create) , resultará em uma exceção [improper_scheduler_detach](improper-scheduler-detach-class.md) sendo gerada.

## <a name="get"></a>Obter

Retorna um ponteiro para o Agendador associado ao contexto de chamada, também conhecido como o Agendador atual.

```cpp
static Scheduler* __cdecl Get();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o Agendador associado ao contexto de chamada (o Agendador atual).

### <a name="remarks"></a>Comentários

Esse método fará com que o agendador padrão do processo seja criado e/ou anexado ao contexto de chamada se não houver um Agendador associado ao contexto de chamada no momento. Nenhuma referência adicional é colocada no objeto `Scheduler` retornado por esse método.

## <a name="getnumberofvirtualprocessors"></a>GetNumberOfVirtualProcessors

Retorna o número atual de processadores virtuais para o Agendador associado ao contexto de chamada.

```cpp
static unsigned int __cdecl GetNumberOfVirtualProcessors();
```

### <a name="return-value"></a>Valor retornado

Se um Agendador estiver associado ao contexto de chamada, o número atual de processadores virtuais para esse Agendador; caso contrário, o valor `-1`.

### <a name="remarks"></a>Comentários

Esse método não resultará no anexo do Agendador se o contexto de chamada ainda não estiver associado a um Agendador.

O valor de retorno desse método é uma amostragem instantânea do número de processadores virtuais para o Agendador associado ao contexto de chamada. Esse valor pode ser obsoleto no momento em que é retornado.

## <a name="getpolicy"></a>GetPolicy

Retorna uma cópia da política com a qual o Agendador atual foi criado.

```cpp
static SchedulerPolicy __cdecl GetPolicy();
```

### <a name="return-value"></a>Valor retornado

Uma cópia da política com a qual o Agendador atual foi criado.

### <a name="remarks"></a>Comentários

Esse método fará com que o agendador padrão do processo seja criado e/ou anexado ao contexto de chamada se não houver um Agendador associado ao contexto de chamada no momento.

## <a name="id"></a>Sessão

Retorna um identificador exclusivo para o Agendador atual.

```cpp
static unsigned int __cdecl Id();
```

### <a name="return-value"></a>Valor retornado

Se um Agendador estiver associado ao contexto de chamada, um identificador exclusivo para esse Agendador; caso contrário, o valor `-1`.

### <a name="remarks"></a>Comentários

Esse método não resultará no anexo do Agendador se o contexto de chamada ainda não estiver associado a um Agendador.

## <a name="isavailablelocation"></a>IsAvailableLocation

Determina se um determinado local está disponível no Agendador atual.

```cpp
static bool __cdecl IsAvailableLocation(const location& _Placement);
```

### <a name="parameters"></a>parâmetros

*_Placement*<br/>
Uma referência ao local para o qual consultar o Agendador atual.

### <a name="return-value"></a>Valor retornado

Uma indicação de se o local especificado pelo argumento `_Placement` está disponível no Agendador atual.

### <a name="remarks"></a>Comentários

Esse método não resultará no anexo do Agendador se o contexto de chamada ainda não estiver associado a um Agendador.

Observe que o valor de retorno é uma amostragem instantânea de se o local fornecido está disponível. Na presença de vários agendadores, o gerenciamento dinâmico de recursos pode adicionar ou retirar recursos de agendadores a qualquer momento. Se isso acontecer, o local especificado poderá alterar a disponibilidade.

## <a name="registershutdownevent"></a>RegisterShutdownEvent

Faz com que o identificador de evento do Windows passado no parâmetro `_ShutdownEvent` seja sinalizado quando o Agendador associado ao contexto atual é desligado e se destrói. No momento em que o evento é sinalizado, todo o trabalho que foi agendado para o Agendador é concluído. Vários eventos de desligamento podem ser registrados por meio desse método.

```cpp
static void __cdecl RegisterShutdownEvent(HANDLE _ShutdownEvent);
```

### <a name="parameters"></a>parâmetros

*_ShutdownEvent*<br/>
Um identificador para um objeto de evento do Windows que será sinalizado pelo tempo de execução quando o Agendador associado ao contexto atual for desligado e se destruirá.

### <a name="remarks"></a>Comentários

Se não houver um Agendador anexado ao contexto de chamada, chamar esse método resultará na geração de uma exceção [scheduler_not_attached](scheduler-not-attached-class.md) .

## <a name="scheduletask"></a>ScheduleTask

Agenda uma tarefa leve dentro do Agendador associado ao contexto de chamada. A tarefa de peso leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado.

```cpp
static void __cdecl ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data);

static void __cdecl ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data,
    location& _Placement);
```

### <a name="parameters"></a>parâmetros

*_Proc*<br/>
Um ponteiro para a função a ser executada para executar o corpo da tarefa de peso leve.

*_Data*<br/>
Um ponteiro void para os dados que serão passados como um parâmetro para o corpo da tarefa.

*_Placement*<br/>
Uma referência a um local onde a tarefa de peso leve será ajustada em direção à execução em.

### <a name="remarks"></a>Comentários

Esse método fará com que o agendador padrão do processo seja criado e/ou anexado ao contexto de chamada se não houver um Agendador associado ao contexto de chamada no momento.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)<br/>
[PolicyElementKey](concurrency-namespace-enums.md)<br/>
[Agendador de Tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)
