---
title: Classe agente
ms.date: 11/04/2016
f1_keywords:
- agent
- AGENTS/concurrency::agent
- AGENTS/concurrency::agent::agent
- AGENTS/concurrency::agent::cancel
- AGENTS/concurrency::agent::start
- AGENTS/concurrency::agent::status
- AGENTS/concurrency::agent::status_port
- AGENTS/concurrency::agent::wait
- AGENTS/concurrency::agent::wait_for_all
- AGENTS/concurrency::agent::wait_for_one
- AGENTS/concurrency::agent::done
- AGENTS/concurrency::agent::run
helpviewer_keywords:
- agent class
ms.assetid: 1b09e3d2-5e37-4966-b016-907ef1512456
ms.openlocfilehash: f0092f5f90bbdf253c09dbdc80849c3db472212f
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79422258"
---
# <a name="agent-class"></a>Classe agente

Uma classe destinada a ser usada como classe base para todos os agentes independentes. Ele é usado para ocultar o estado de outros agentes e interagir com a passagem de mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
class agent;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Agente](#ctor)|Sobrecarregado. Constrói um agente.|
|[~ Destruidor de agente](#dtor)|Destrói o agente.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[cancel](#cancel)|Move um agente do `agent_created` ou `agent_runnable` Estados para o estado de `agent_canceled`.|
|[start](#start)|Move um agente do estado de `agent_created` para o estado de `agent_runnable` e o agenda para execução.|
|[status](#status)|Uma fonte síncrona de informações de status do agente.|
|[status_port](#status_port)|Uma fonte assíncrona de informações de status do agente.|
|[esperado](#wait)|Aguarda um agente concluir sua tarefa.|
|[wait_for_all](#wait_for_all)|Aguarda que todos os agentes especificados concluam suas tarefas.|
|[wait_for_one](#wait_for_one)|Aguarda que qualquer um dos agentes especificados conclua sua tarefa.|

### <a name="protected-methods"></a>Métodos protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[done](#done)|Move um agente para o estado de `agent_done`, indicando que o agente foi concluído.|
|[run](#run)|Representa a tarefa principal de um agente. `run` deve ser substituído em uma classe derivada e especifica o que o agente deve fazer depois de ser iniciado.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [agentes assíncronos](../../../parallel/concrt/asynchronous-agents.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`agent`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="ctor"></a>Agente

Constrói um agente.

```cpp
agent();

agent(Scheduler& _PScheduler);

agent(ScheduleGroup& _PGroup);
```

### <a name="parameters"></a>parâmetros

*_PScheduler*<br/>
O objeto `Scheduler` no qual a tarefa de execução do agente está agendada.

*_PGroup*<br/>
O objeto `ScheduleGroup` no qual a tarefa de execução do agente está agendada. O objeto de `Scheduler` usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os parâmetros `_PScheduler` ou `_PGroup`.

## <a name="dtor"></a>~ Agente

Destrói o agente.

```cpp
virtual ~agent();
```

### <a name="remarks"></a>Comentários

É um erro destruir um agente que não está em um estado de terminal (`agent_done` ou `agent_canceled`). Isso pode ser evitado aguardando que o agente alcance um estado terminal no destruidor de uma classe que herda da classe `agent`.

## <a name="cancel"></a>Cancelar

Move um agente do `agent_created` ou `agent_runnable` Estados para o estado de `agent_canceled`.

```cpp
bool cancel();
```

### <a name="return-value"></a>Valor retornado

**true** se o agente foi cancelado; caso contrário, **false** . Um agente não poderá ser cancelado se já tiver iniciado a execução ou já tiver sido concluído.

## <a name="done"></a>trabalhado

Move um agente para o estado de `agent_done`, indicando que o agente foi concluído.

```cpp
bool done();
```

### <a name="return-value"></a>Valor retornado

**true** se o agente for movido para o estado de `agent_done`; caso contrário, **false** . Um agente que foi cancelado não pode ser movido para o estado de `agent_done`.

### <a name="remarks"></a>Comentários

Esse método deve ser chamado no final do método `run`, quando você souber que a execução do seu agente foi concluída.

## <a name="run"></a>funcionam

Representa a tarefa principal de um agente. `run` deve ser substituído em uma classe derivada e especifica o que o agente deve fazer depois de ser iniciado.

```cpp
virtual void run() = 0;
```

### <a name="remarks"></a>Comentários

O status do agente é alterado para `agent_started` logo antes que este método seja invocado. O método deve invocar `done` no agente com um status apropriado antes de retornar e não pode lançar nenhuma exceção.

## <a name="start"></a>Comece

Move um agente do estado de `agent_created` para o estado de `agent_runnable` e o agenda para execução.

```cpp
bool start();
```

### <a name="return-value"></a>Valor retornado

**true** se o agente for iniciado corretamente; caso contrário, **false** . Um agente que foi cancelado não pode ser iniciado.

## <a name="status"></a>Estado

Uma fonte síncrona de informações de status do agente.

```cpp
agent_status status();
```

### <a name="return-value"></a>Valor retornado

Retorna o estado atual do agente. Observe que esse estado retornado pode ser alterado imediatamente após ser retornado.

## <a name="status_port"></a>status_port

Uma fonte assíncrona de informações de status do agente.

```cpp
ISource<agent_status>* status_port();
```

### <a name="return-value"></a>Valor retornado

Retorna uma fonte de mensagem que pode enviar mensagens sobre o estado atual do agente.

## <a name="wait"></a>esperado

Aguarda um agente concluir sua tarefa.

```cpp
static agent_status __cdecl wait(
    _Inout_ agent* _PAgent,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```

### <a name="parameters"></a>parâmetros

*_PAgent*<br/>
Um ponteiro para o agente aguardar.

*_Timeout*<br/>
O tempo máximo para aguardar, em milissegundos.

### <a name="return-value"></a>Valor retornado

A `agent_status` do agente quando a espera é concluída. Isso pode ser `agent_canceled` ou `agent_done`.

### <a name="remarks"></a>Comentários

Uma tarefa de agente é concluída quando o agente entra no `agent_canceled` ou `agent_done` Estados.

Se o parâmetro `_Timeout` tiver um valor diferente da constante `COOPERATIVE_TIMEOUT_INFINITE`, a exceção [operation_timed_out](operation-timed-out-class.md) será gerada se a quantidade de tempo especificada expirar antes que o agente tenha concluído sua tarefa.

## <a name="wait_for_all"></a>wait_for_all

Aguarda que todos os agentes especificados concluam suas tarefas.

```cpp
static void __cdecl wait_for_all(
    size_t count,
    _In_reads_(count) agent** _PAgents,
    _Out_writes_opt_(count) agent_status* _PStatus = NULL,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```

### <a name="parameters"></a>parâmetros

*contagem*<br/>
O número de ponteiros de agente presentes na matriz `_PAgents`.

*_PAgents*<br/>
Uma matriz de ponteiros para os agentes a serem esperados.

*_PStatus*<br/>
Um ponteiro para uma matriz de status do agente. Cada valor de status representará o status do agente correspondente quando o método for retornado.

*_Timeout*<br/>
O tempo máximo para aguardar, em milissegundos.

### <a name="remarks"></a>Comentários

Uma tarefa de agente é concluída quando o agente entra no `agent_canceled` ou `agent_done` Estados.

Se o parâmetro `_Timeout` tiver um valor diferente da constante `COOPERATIVE_TIMEOUT_INFINITE`, a exceção [operation_timed_out](operation-timed-out-class.md) será gerada se a quantidade de tempo especificada expirar antes que o agente tenha concluído sua tarefa.

## <a name="wait_for_one"></a>wait_for_one

Aguarda que qualquer um dos agentes especificados conclua sua tarefa.

```cpp
static void __cdecl wait_for_one(
    size_t count,
    _In_reads_(count) agent** _PAgents,
    agent_status& _Status,
    size_t& _Index,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```

### <a name="parameters"></a>parâmetros

*contagem*<br/>
O número de ponteiros de agente presentes na matriz `_PAgents`.

*_PAgents*<br/>
Uma matriz de ponteiros para os agentes a serem esperados.

*_Status*<br/>
Uma referência a uma variável em que o status do agente será colocado.

*_Index*<br/>
Uma referência a uma variável em que o índice do agente será colocado.

*_Timeout*<br/>
O tempo máximo para aguardar, em milissegundos.

### <a name="remarks"></a>Comentários

Uma tarefa de agente é concluída quando o agente entra no `agent_canceled` ou `agent_done` Estados.

Se o parâmetro `_Timeout` tiver um valor diferente da constante `COOPERATIVE_TIMEOUT_INFINITE`, a exceção [operation_timed_out](operation-timed-out-class.md) será gerada se a quantidade de tempo especificada expirar antes que o agente tenha concluído sua tarefa.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
