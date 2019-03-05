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
ms.openlocfilehash: ce7734a1330f2d6e495565338879764482439d09
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283846"
---
# <a name="schedulegroup-class"></a>Classe ScheduleGroup

Representa uma abstração para um grupo de agendas. Grupos de agendas organizam um conjunto de trabalho relacionados que se beneficiam de ser agendados em datas próximas temporariamente, por executando outra tarefa no mesmo grupo antes de passar para outro grupo ou espaçadamente, executando vários itens dentro do mesmo grupo no mesmo Nó NUMA ou soquete físico.

## <a name="syntax"></a>Sintaxe

```
class ScheduleGroup;
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[~ Destruidor ScheduleGroup](#dtor)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ID](#id)|Retorna um identificador para o grupo de agendas que é exclusivo dentro do Agendador ao qual pertence o grupo.|
|[Referência](#reference)|Incrementa a contagem de referência do grupo de agendamento.|
|[Versão](#release)|Diminui a referência de grupo do Agendador contagem.|
|[ScheduleTask](#scheduletask)|Agenda uma tarefa leve no grupo.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ScheduleGroup`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="id"></a> Id

Retorna um identificador para o grupo de agendas que é exclusivo dentro do Agendador ao qual pertence o grupo.

```
virtual unsigned int Id() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o grupo de agendas que é exclusivo dentro do Agendador ao qual pertence o grupo.

##  <a name="operator_delete"></a> operador delete

Um `ScheduleGroup` objeto é destruído internamente pelo tempo de execução quando todas as referências externas a ele são liberadas. Ele não pode ser explicitamente excluído.

```
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

##  <a name="reference"></a> Referência

Incrementa a contagem de referência do grupo de agendamento.

```
virtual unsigned int Reference() = 0;
```

### <a name="return-value"></a>Valor de retorno

A contagem de referência recentemente incrementado.

### <a name="remarks"></a>Comentários

Isso normalmente é usado para gerenciar o tempo de vida do grupo de agendamento para a composição. Quando a contagem de referência de um grupo de agendas cai para zero, o grupo de agendas é excluído pelo tempo de execução. Um grupo de agendamento criado usando o [currentscheduler:: Createschedulegroup](currentscheduler-class.md#createschedulegroup) método, ou o [Scheduler:: createschedulegroup](scheduler-class.md#createschedulegroup) método começa com uma contagem de referência de um.

##  <a name="release"></a> versão

Diminui a referência de grupo do Agendador contagem.

```
virtual unsigned int Release() = 0;
```

### <a name="return-value"></a>Valor de retorno

A contagem de referência recentemente decrementado.

### <a name="remarks"></a>Comentários

Isso normalmente é usado para gerenciar o tempo de vida do grupo de agendamento para a composição. Quando a contagem de referência de um grupo de agendas cai para zero, o grupo de agendas é excluído pelo tempo de execução. Depois de ter chamado a `Release` o número específico de vezes para remover a criação de método referência contagem e todas as referências adicionais colocadas, usando o `Reference` método, não é possível utilizar o grupo de agendas. Isso resultará em um comportamento indefinido.

Um grupo de agendamento está associado uma instância de Agendador específico. Você deve garantir que todas as referências para o grupo de agendas são liberadas antes de todas as referências para o Agendador são lançadas, porque a última opção pode resultar no Agendador que está sendo destruído. Fazendo caso contrário, resulta em um comportamento indefinido.

##  <a name="dtor"></a> ~ScheduleGroup

```
virtual ~ScheduleGroup();
```

##  <a name="scheduletask"></a> ScheduleTask

Agenda uma tarefa leve no grupo.

```
virtual void ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data) = 0;
```

### <a name="parameters"></a>Parâmetros

*_Proc*<br/>
Um ponteiro para a função a ser executada para executar o corpo da tarefa leve.

*_Data*<br/>
Um ponteiro nulo para os dados que serão passados como um parâmetro ao corpo da tarefa.

### <a name="remarks"></a>Comentários

Chamar o `ScheduleTask` implicitamente o método coloca uma contagem de referência no grupo de agenda que é removido pelo tempo de execução em um momento apropriado depois que a tarefa será executada.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe CurrentScheduler](currentscheduler-class.md)<br/>
[Classe Scheduler](scheduler-class.md)<br/>
[Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)
