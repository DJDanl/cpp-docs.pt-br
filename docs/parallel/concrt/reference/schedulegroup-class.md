---
title: Classe ScheduleGroup
ms.date: 11/04/2016
f1_keywords:
- ScheduleGroup
- CONCRT/concurrency::ScheduleGroup
- CONCRT/concurrency::ScheduleGroup::Id
- CONCRT/concurrency::ScheduleGroup::Reference
- CONCRT/concurrency::ScheduleGroup::Release
- CONCRT/concurrency::ScheduleGroup::ScheduleTask
helpviewer_keywords:
- ScheduleGroup class
ms.assetid: 86d380ff-f2e8-411c-b1a8-22bd3079824a
ms.openlocfilehash: 8686b5ef0906e3188a1e683d1190bbe6124cd19e
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143264"
---
# <a name="schedulegroup-class"></a>Classe ScheduleGroup

Representa uma abstração para um grupo de agendamento. Os grupos de agendamento organizam um conjunto de trabalho relacionado que se beneficia de ser agendado de forma temporal, executando outra tarefa no mesmo grupo antes de passar para outro grupo, ou espacial, executando vários itens dentro do mesmo grupo na mesma Nó NUMA ou soquete físico.

## <a name="syntax"></a>Sintaxe

```cpp
class ScheduleGroup;
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[~ Destruidor de programador](#dtor)||

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Id](#id)|Retorna um identificador para o grupo de agendamento que é exclusivo dentro do Agendador ao qual o grupo pertence.|
|[Referência](#reference)|Incrementa a contagem de referência do grupo de agendamento.|
|[Versão](#release)|Decrementa a contagem de referência de grupo do Agendador.|
|[ScheduleTask](#scheduletask)|Agenda uma tarefa leve dentro do grupo de agendamento.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ScheduleGroup`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="id"></a>Sessão

Retorna um identificador para o grupo de agendamento que é exclusivo dentro do Agendador ao qual o grupo pertence.

```cpp
virtual unsigned int Id() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o grupo de agendamento que é exclusivo dentro do Agendador ao qual o grupo pertence.

## <a name="operator_delete"></a>operador Delete

Um objeto `ScheduleGroup` é destruído internamente pelo tempo de execução quando todas as referências externas a ele são liberadas. Ele não pode ser excluído explicitamente.

```cpp
void operator delete(
    void* _PObject);

void operator delete(
    void* _PObject,
    int,
const char *,
    int);
```

### <a name="parameters"></a>Parâmetros

*_PObject*<br/>
Um ponteiro para o objeto a ser excluído.

## <a name="reference"></a>Referência

Incrementa a contagem de referência do grupo de agendamento.

```cpp
virtual unsigned int Reference() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem de referência incrementada recentemente.

### <a name="remarks"></a>Comentários

Normalmente, isso é usado para gerenciar o tempo de vida do grupo de agendamento para composição. Quando a contagem de referência de um grupo de agendamento cai para zero, o grupo de agendamento é excluído pelo tempo de execução. Um grupo de agendamento criado usando o método [CurrentScheduler:: CreateSchedule](currentscheduler-class.md#createschedulegroup) Group ou o método [Scheduler:: CreateSchedule](scheduler-class.md#createschedulegroup) Group começa com uma contagem de referência de um.

## <a name="release"></a>Liberar

Decrementa a contagem de referência de grupo do Agendador.

```cpp
virtual unsigned int Release() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem de referência recentemente decrementada.

### <a name="remarks"></a>Comentários

Normalmente, isso é usado para gerenciar o tempo de vida do grupo de agendamento para composição. Quando a contagem de referência de um grupo de agendamento cai para zero, o grupo de agendamento é excluído pelo tempo de execução. Depois de ter chamado o método `Release` o número específico de vezes para remover a contagem de referência de criação e quaisquer referências adicionais feitas usando o método `Reference`, você não poderá utilizar o grupo de agendamento ainda mais. Isso resultará em um comportamento indefinido.

Um grupo de agendamento é associado a uma instância específica do Agendador. Você deve garantir que todas as referências ao grupo de agendamento sejam liberadas antes que todas as referências ao agendador sejam liberadas, pois o último pode resultar na destruição do Agendador. Caso contrário, resulta em um comportamento indefinido.

## <a name="dtor"></a>~ Scheduler

```cpp
virtual ~ScheduleGroup();
```

## <a name="scheduletask"></a>ScheduleTask

Agenda uma tarefa leve dentro do grupo de agendamento.

```cpp
virtual void ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data) = 0;
```

### <a name="parameters"></a>Parâmetros

*_Proc*<br/>
Um ponteiro para a função a ser executada para executar o corpo da tarefa de peso leve.

*_Data*<br/>
Um ponteiro void para os dados que serão passados como um parâmetro para o corpo da tarefa.

### <a name="remarks"></a>Comentários

Chamar o método `ScheduleTask` coloca implicitamente uma contagem de referência no grupo de agendamento que é removido pelo tempo de execução em um momento apropriado após a execução da tarefa.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe CurrentScheduler](currentscheduler-class.md)<br/>
[Classe Scheduler](scheduler-class.md)<br/>
[Agendador de Tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)
