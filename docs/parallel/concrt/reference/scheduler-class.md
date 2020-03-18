---
title: Classe Scheduler
ms.date: 11/04/2016
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
helpviewer_keywords:
- Scheduler class
ms.assetid: 34cf7961-048d-4852-8a5c-a32f823e3506
ms.openlocfilehash: 77ad876b8352ab1ae86fde622b05712ec5f2cea9
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79422111"
---
# <a name="scheduler-class"></a>Classe Scheduler

Representa uma abstração para um Agendador de Tempo de Execução de Simultaneidade.

## <a name="syntax"></a>Sintaxe

```cpp
class Scheduler;
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Agendador](#ctor)|Um objeto da classe `Scheduler` só pode ser criado usando métodos de fábrica ou implicitamente.|
|[~ Destruidor do Agendador](#dtor)|Um objeto da classe `Scheduler` é destruído implicitamente quando todas as referências externas a ele deixa de existir.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Anexar](#attach)|Anexa o Agendador ao contexto de chamada. Depois que esse método retornar, o contexto de chamada será gerenciado pelo Agendador e o Agendador se tornará o Agendador atual.|
|[Criar](#create)|Cria um novo agendador cujo comportamento é descrito pelo parâmetro `_Policy`, coloca uma referência inicial no Agendador e retorna um ponteiro para ele.|
|[CreateSchedule](#createschedulegroup)|Sobrecarregado. Cria um novo grupo de agendamento dentro do Agendador. A versão que usa o parâmetro `_Placement` faz com que as tarefas dentro do grupo de agendamento recém-criado sejam ajustadas em direção à execução no local especificado por esse parâmetro.|
|[GetNumberOfVirtualProcessors](#getnumberofvirtualprocessors)|Retorna o número atual de processadores virtuais para o Agendador.|
|[GetPolicy](#getpolicy)|Retorna uma cópia da política com a qual o Agendador foi criado.|
|[Id](#id)|Retorna um identificador exclusivo para o Agendador.|
|[IsAvailableLocation](#isavailablelocation)|Determina se um determinado local está disponível no Agendador.|
|[Referência](#reference)|Incrementa a contagem de referência do Agendador.|
|[RegisterShutdownEvent](#registershutdownevent)|Faz com que o identificador de evento do Windows passado no parâmetro `_Event` seja sinalizado quando o Agendador é desligado e se destrói. No momento em que o evento é sinalizado, todo o trabalho que foi agendado para o Agendador é concluído. Vários eventos de desligamento podem ser registrados por meio desse método.|
|[Versão](#release)|Decrementa a contagem de referência do Agendador.|
|[ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy)|Redefine a política padrão do Agendador para o padrão de tempo de execução. Na próxima vez que um agendador padrão for criado, ele usará as configurações de política padrão de tempo de execução.|
|[ScheduleTask](#scheduletask)|Sobrecarregado. Agenda uma tarefa leve no Agendador. A tarefa de peso leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado.|
|[SetDefaultSchedulerPolicy](#setdefaultschedulerpolicy)|Permite que uma política definida pelo usuário seja usada para criar o agendador padrão. Esse método pode ser chamado somente quando não houver um agendador padrão dentro do processo. Depois que uma política padrão tiver sido definida, ela permanecerá em vigor até a próxima chamada válida para o método `SetDefaultSchedulerPolicy` ou [ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy) .|

## <a name="remarks"></a>Comentários

O Agendador de Tempo de Execução de Simultaneidade usa contextos de execução, que mapeiam para os contextos de execução do sistema operacional, como um thread, para executar o trabalho na fila por seu aplicativo. A qualquer momento, o nível de simultaneidade de um Agendador é igual ao número de processadores virtuais concedidos a ele pelo Gerenciador de recursos. Um processador virtual é uma abstração para um recurso de processamento e é mapeado para um thread de hardware no sistema subjacente. Apenas um único contexto de Agendador pode ser executado em um processador virtual em um determinado momento.

O Tempo de Execução de Simultaneidade criará um agendador padrão por processo para executar o trabalho paralelo. Além disso, você pode criar suas próprias instâncias do Agendador e manipulá-las usando essa classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Scheduler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="attach"></a>Anexa

Anexa o Agendador ao contexto de chamada. Depois que esse método retornar, o contexto de chamada será gerenciado pelo Agendador e o Agendador se tornará o Agendador atual.

```cpp
virtual void Attach() = 0;
```

### <a name="remarks"></a>Comentários

A anexação de um Agendador coloca implicitamente uma referência no Agendador.

Em algum momento no futuro, você deve chamar o método [CurrentScheduler::D Etach](currentscheduler-class.md#detach) para permitir que o Agendador seja desligado.

Se esse método for chamado de um contexto que já está anexado a um Agendador diferente, o Agendador existente será lembrado como o Agendador anterior e o Agendador recém-criado se tornará o Agendador atual. Quando você chama o método `CurrentScheduler::Detach` em um ponto posterior, o Agendador anterior é restaurado como o Agendador atual.

Esse método gerará uma exceção de [improper_scheduler_attach](improper-scheduler-attach-class.md) se este Agendador for o Agendador atual do contexto de chamada.

## <a name="create"></a> Criar

Cria um novo agendador cujo comportamento é descrito pelo parâmetro `_Policy`, coloca uma referência inicial no Agendador e retorna um ponteiro para ele.

```cpp
static Scheduler* __cdecl Create(const SchedulerPolicy& _Policy);
```

### <a name="parameters"></a>parâmetros

*_Policy*<br/>
A política do Agendador que descreve o comportamento do Agendador recém-criado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um Agendador recém-criado. Este objeto de `Scheduler` tem uma contagem de referência inicial colocada nele.

### <a name="remarks"></a>Comentários

Depois que um Agendador é criado com o método `Create`, você deve chamar o método `Release` em algum momento no futuro para remover a contagem de referência inicial e permitir que o Agendador seja desligado.

Um Agendador criado com este método não está anexado ao contexto de chamada. Ele pode ser anexado a um contexto usando o método [Attach](#attach) .

Esse método pode lançar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md) e [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md).

## <a name="createschedulegroup"></a>CreateSchedule

Cria um novo grupo de agendamento dentro do Agendador. A versão que usa o parâmetro `_Placement` faz com que as tarefas dentro do grupo de agendamento recém-criado sejam ajustadas em direção à execução no local especificado por esse parâmetro.

```cpp
virtual ScheduleGroup* CreateScheduleGroup() = 0;

virtual ScheduleGroup* CreateScheduleGroup(location& _Placement) = 0;
```

### <a name="parameters"></a>parâmetros

*_Placement*<br/>
Uma referência a um local em que as tarefas dentro do grupo de agendamento serão inclinadas em direção à execução em.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o grupo de agendamento recém-criado. Este objeto de `ScheduleGroup` tem uma contagem de referência inicial colocada nele.

### <a name="remarks"></a>Comentários

Você deve invocar o método de [liberação](schedulegroup-class.md#release) em um grupo de agendamento quando terminar de agendar trabalho para ele. O Agendador destruirá o grupo de agendamento quando todo o trabalho enfileirado para ele for concluído.

Observe que, se você tiver criado explicitamente esse Agendador, deverá liberar todas as referências para agendar grupos dentro dela, antes de liberar suas referências no Agendador.

## <a name="getnumberofvirtualprocessors"></a>GetNumberOfVirtualProcessors

Retorna o número atual de processadores virtuais para o Agendador.

```cpp
virtual unsigned int GetNumberOfVirtualProcessors() const = 0;
```

### <a name="return-value"></a>Valor retornado

O número atual de processadores virtuais para o Agendador.

## <a name="getpolicy"></a>GetPolicy

Retorna uma cópia da política com a qual o Agendador foi criado.

```cpp
virtual SchedulerPolicy GetPolicy() const = 0;
```

### <a name="return-value"></a>Valor retornado

Uma cópia da política com a qual o Agendador foi criado.

## <a name="id"></a>Sessão

Retorna um identificador exclusivo para o Agendador.

```cpp
virtual unsigned int Id() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador exclusivo para o Agendador.

## <a name="isavailablelocation"></a>IsAvailableLocation

Determina se um determinado local está disponível no Agendador.

```cpp
virtual bool IsAvailableLocation(const location& _Placement) const = 0;
```

### <a name="parameters"></a>parâmetros

*_Placement*<br/>
Uma referência ao local para o qual consultar o Agendador.

### <a name="return-value"></a>Valor retornado

Uma indicação de se o local especificado pelo argumento `_Placement` está disponível no Agendador.

### <a name="remarks"></a>Comentários

Observe que o valor de retorno é uma amostragem instantânea de se o local fornecido está disponível. Na presença de vários agendadores, o gerenciamento dinâmico de recursos pode adicionar ou retirar recursos de agendadores a qualquer momento. Se isso acontecer, o local especificado poderá alterar a disponibilidade.

## <a name="reference"></a>Referência

Incrementa a contagem de referência do Agendador.

```cpp
virtual unsigned int Reference() = 0 ;
```

### <a name="return-value"></a>Valor retornado

A contagem de referência incrementada recentemente.

### <a name="remarks"></a>Comentários

Normalmente, isso é usado para gerenciar o tempo de vida do Agendador para composição. Quando a contagem de referência de um Agendador cai para zero, o Agendador será desligado e se destrui depois que todo o trabalho no Agendador for concluído.

O método gerará uma exceção de [improper_scheduler_reference](improper-scheduler-reference-class.md) se a contagem de referência antes de chamar o método `Reference` fosse zero e a chamada for feita de um contexto que não pertence ao agendador.

## <a name="registershutdownevent"></a>RegisterShutdownEvent

Faz com que o identificador de evento do Windows passado no parâmetro `_Event` seja sinalizado quando o Agendador é desligado e se destrói. No momento em que o evento é sinalizado, todo o trabalho que foi agendado para o Agendador é concluído. Vários eventos de desligamento podem ser registrados por meio desse método.

```cpp
virtual void RegisterShutdownEvent(HANDLE _Event) = 0;
```

### <a name="parameters"></a>parâmetros

*_Event*<br/>
Um identificador para um objeto de evento do Windows que será sinalizado pelo tempo de execução quando o Agendador for desligado e se destruir.

## <a name="release"></a>Liberar

Decrementa a contagem de referência do Agendador.

```cpp
virtual unsigned int Release() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem de referência recentemente decrementada.

### <a name="remarks"></a>Comentários

Normalmente, isso é usado para gerenciar o tempo de vida do Agendador para composição. Quando a contagem de referência de um Agendador cai para zero, o Agendador será desligado e se destrui depois que todo o trabalho no Agendador for concluído.

## <a name="resetdefaultschedulerpolicy"></a>ResetDefaultSchedulerPolicy

Redefine a política padrão do Agendador para o padrão de tempo de execução. Na próxima vez que um agendador padrão for criado, ele usará as configurações de política padrão de tempo de execução.

```cpp
static void __cdecl ResetDefaultSchedulerPolicy();
```

### <a name="remarks"></a>Comentários

Esse método pode ser chamado enquanto existir um agendador padrão dentro do processo. Ele não afetará a política do agendador padrão existente. No entanto, se o agendador padrão tiver sido desligado e um novo padrão fosse criado posteriormente, o novo agendador usará as configurações de política padrão de tempo de execução.

## <a name="ctor"></a>Agendador

Um objeto da classe `Scheduler` só pode ser criado usando métodos de fábrica ou implicitamente.

```cpp
Scheduler();
```

### <a name="remarks"></a>Comentários

O agendador padrão do processo é criado implicitamente quando você utiliza muitas das funções de tempo de execução que exigem que um Agendador seja anexado ao contexto de chamada. Os métodos dentro da classe `CurrentScheduler` e os recursos das camadas PPL e Agents normalmente executam o anexo implícito.

Você também pode criar um Agendador explicitamente por meio do método `CurrentScheduler::Create` ou do método `Scheduler::Create`.

## <a name="dtor"></a>~ Agendador

Um objeto da classe `Scheduler` é destruído implicitamente quando todas as referências externas a ele deixa de existir.

```cpp
virtual ~Scheduler();
```

## <a name="scheduletask"></a>ScheduleTask

Agenda uma tarefa leve no Agendador. A tarefa de peso leve será colocada em um grupo de agendamento determinado pelo tempo de execução. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado.

```cpp
virtual void ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data) = 0;

virtual void ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data,
    location& _Placement) = 0;
```

### <a name="parameters"></a>parâmetros

*_Proc*<br/>
Um ponteiro para a função a ser executada para executar o corpo da tarefa de peso leve.

*_Data*<br/>
Um ponteiro void para os dados que serão passados como um parâmetro para o corpo da tarefa.

*_Placement*<br/>
Uma referência a um local onde a tarefa de peso leve será ajustada em direção à execução em.

## <a name="setdefaultschedulerpolicy"></a>SetDefaultSchedulerPolicy

Permite que uma política definida pelo usuário seja usada para criar o agendador padrão. Esse método pode ser chamado somente quando não houver um agendador padrão dentro do processo. Depois que uma política padrão tiver sido definida, ela permanecerá em vigor até a próxima chamada válida para o método `SetDefaultSchedulerPolicy` ou [ResetDefaultSchedulerPolicy](#resetdefaultschedulerpolicy) .

```cpp
static void __cdecl SetDefaultSchedulerPolicy(const SchedulerPolicy& _Policy);
```

### <a name="parameters"></a>parâmetros

*_Policy*<br/>
A política a ser definida como a política padrão do Agendador.

### <a name="remarks"></a>Comentários

Se o método `SetDefaultSchedulerPolicy` for chamado quando um agendador padrão já existir dentro do processo, o tempo de execução gerará uma exceção de [default_scheduler_exists](default-scheduler-exists-class.md) .

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)<br/>
[PolicyElementKey](concurrency-namespace-enums.md)<br/>
[Agendador de Tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)
