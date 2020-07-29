---
title: Classe structured_task_group
ms.date: 11/04/2016
f1_keywords:
- structured_task_group
- PPL/concurrency::structured_task_group
- PPL/concurrency::structured_task_group::structured_task_group
- PPL/concurrency::structured_task_group::cancel
- PPL/concurrency::structured_task_group::is_canceling
- PPL/concurrency::structured_task_group::run
- PPL/concurrency::structured_task_group::run_and_wait
- PPL/concurrency::structured_task_group::wait
helpviewer_keywords:
- structured_task_group class
ms.assetid: 742afa8c-c7b6-482c-b0ba-04c809927b22
ms.openlocfilehash: 44fd2a42f4c98a569e985449f0c55102a9cbc3a6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231670"
---
# <a name="structured_task_group-class"></a>Classe structured_task_group

A `structured_task_group` classe representa uma coleção altamente estruturada de trabalho paralelo. Você pode enfileirar tarefas paralelas individuais para um `structured_task_group` usando `task_handle` objetos e esperar que elas sejam concluídas ou cancelar o grupo de tarefas antes de concluir a execução, o que anulará todas as tarefas que não começaram a execução.

## <a name="syntax"></a>Sintaxe

```cpp
class structured_task_group;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[structured_task_group](#ctor)|Sobrecarregado. Constrói um novo objeto `structured_task_group`.|
|[~ structured_task_group destruidor](#dtor)|Destrói um objeto `structured_task_group`. Você deve chamar o `wait` `run_and_wait` método ou no objeto antes da execução do destruidor, a menos que o destruidor esteja sendo executado como resultado do desenrolamento da pilha devido a uma exceção.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cancel](#cancel)|Faz com que seja possível tentar cancelar a subárvore de trabalho com raiz nesse grupo de tarefas. Cada tarefa agendada no grupo de tarefas será cancelada transitivamente, se possível.|
|[is_canceling](#is_canceling)|Informa ao chamador se o grupo de tarefas está ou não no meio de um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `structured_task_group` objeto (embora, certamente, qualifique esse método para retornar **`true`** ). Pode ser o caso em que o `structured_task_group` objeto está sendo executado em linha e um grupo de tarefas mais adiante na árvore de trabalho foi cancelado. Em casos como esses, onde o tempo de execução pode determinar antecipadamente que o cancelamento fluirá por esse `structured_task_group` objeto, **`true`** também será retornado.|
|[funcionam](#run)|Sobrecarregado. Agenda uma tarefa no `structured_task_group` objeto. O chamador gerencia o tempo de vida do `task_handle` objeto passado no `_Task_handle` parâmetro. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado por esse parâmetro.|
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa a ser executada embutida no contexto de chamada com a assistência do `structured_task_group` objeto para obter suporte completo ao cancelamento. Se um `task_handle` objeto for passado como um parâmetro para `run_and_wait` , o chamador será responsável por gerenciar o tempo de vida do `task_handle` objeto. A função aguarda até que todo o trabalho no `structured_task_group` objeto seja concluído ou cancelado.|
|[esperado](#wait)|Aguarda até que todo o trabalho no seja `structured_task_group` concluído ou cancelado.|

## <a name="remarks"></a>Comentários

Há várias restrições severas colocadas no uso de um `structured_task_group` objeto para obter desempenho:

- Um único `structured_task_group` objeto não pode ser usado por vários threads. Todas as operações em um `structured_task_group` objeto devem ser executadas pelo thread que criou o objeto. As duas exceções a essa regra são as funções de membro `cancel` e `is_canceling` . O objeto pode não estar na lista de captura de uma expressão lambda e ser usado dentro de uma tarefa, a menos que a tarefa esteja usando uma das operações de cancelamento.

- Todas as tarefas agendadas para um `structured_task_group` objeto são agendadas por meio do uso de `task_handle` objetos que você deve gerenciar explicitamente o tempo de vida de.

- Vários grupos só podem ser usados em ordem absolutamente aninhada. Se dois `structured_task_group` objetos forem declarados, o segundo que está sendo declarado (o interno) deve ser destruído antes de qualquer método, exceto `cancel` ou `is_canceling` ser chamado no primeiro (o externo). Essa condição se aplica em ambos os casos de simplesmente declarar vários `structured_task_group` objetos dentro dos mesmos escopos ou aninhados de forma funcional, bem como o caso de uma tarefa que foi enfileirada para o `structured_task_group` por meio dos `run` `run_and_wait` métodos ou.

- Ao contrário da `task_group` classe General, todos os Estados na `structured_task_group` classe são finais. Depois de colocar as tarefas em fila no grupo e aguardar sua conclusão, você não poderá usar o mesmo grupo novamente.

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`structured_task_group`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="cancel"></a><a name="cancel"></a>Cancelar

Faz com que seja possível tentar cancelar a subárvore de trabalho com raiz nesse grupo de tarefas. Cada tarefa agendada no grupo de tarefas será cancelada transitivamente, se possível.

```cpp
void cancel();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

## <a name="is_canceling"></a><a name="is_canceling"></a>is_canceling

Informa ao chamador se o grupo de tarefas está ou não no meio de um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `structured_task_group` objeto (embora, certamente, qualifique esse método para retornar **`true`** ). Pode ser o caso em que o `structured_task_group` objeto está sendo executado em linha e um grupo de tarefas mais adiante na árvore de trabalho foi cancelado. Em casos como esses, onde o tempo de execução pode determinar antecipadamente que o cancelamento fluirá por esse `structured_task_group` objeto, **`true`** também será retornado.

```cpp
bool is_canceling();
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se o `structured_task_group` objeto está no meio de um cancelamento (ou se é garantido que esteja em breve).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

## <a name="run"></a><a name="run"></a>funcionam

Agenda uma tarefa no `structured_task_group` objeto. O chamador gerencia o tempo de vida do `task_handle` objeto passado no `_Task_handle` parâmetro. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado por esse parâmetro.

```cpp
template<class _Function>
void run(
    task_handle<_Function>& _Task_handle);

template<class _Function>
void run(
    task_handle<_Function>& _Task_handle,
    location& _Placement);
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar o corpo do identificador de tarefa.

*_Task_handle*<br/>
Um identificador para o trabalho que está sendo agendado. Observe que o chamador tem responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará esperando que ele fique ativo até que o `wait` método ou seja `run_and_wait` chamado neste `structured_task_group` objeto.

*_Placement*<br/>
Uma referência ao local onde a tarefa representada pelo `_Task_handle` parâmetro deve ser executada.

### <a name="remarks"></a>Comentários

O tempo de execução cria uma cópia da função de trabalho que você passa para esse método. As alterações de estado que ocorrem em um objeto de função que você passa para esse método não aparecerão na sua cópia do objeto de função.

Se o `structured_task_group` destruições como resultado do desenrolamento da pilha de uma exceção, você não precisa garantir que uma chamada tenha sido feita para o `wait` `run_and_wait` método ou. Nesse caso, o destruidor irá cancelar adequadamente e aguardar que a tarefa representada pelo `_Task_handle` parâmetro seja concluída.

Gera uma exceção [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) se o identificador de tarefa fornecido pelo `_Task_handle` parâmetro já tiver sido agendado em um objeto de grupo de tarefas por meio do `run` método e não houver uma chamada intermediária para `wait` o `run_and_wait` método ou nesse grupo de tarefas.

## <a name="run_and_wait"></a><a name="run_and_wait"></a>run_and_wait

Agenda uma tarefa a ser executada embutida no contexto de chamada com a assistência do `structured_task_group` objeto para obter suporte completo ao cancelamento. Se um `task_handle` objeto for passado como um parâmetro para `run_and_wait` , o chamador será responsável por gerenciar o tempo de vida do `task_handle` objeto. A função aguarda até que todo o trabalho no `structured_task_group` objeto seja concluído ou cancelado.

```cpp
template<class _Function>
task_group_status run_and_wait(task_handle<_Function>& _Task_handle);

template<class _Function>
task_group_status run_and_wait(const _Function& _Func);
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar a tarefa.

*_Task_handle*<br/>
Um identificador para a tarefa que será executada embutida no contexto de chamada. Observe que o chamador tem responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará esperando que ele fique ativo até que o `run_and_wait` método conclua a execução.

*_Func*<br/>
Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser um lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()` .

### <a name="return-value"></a>Valor retornado

Uma indicação de se a espera foi satisfeita ou se o grupo de tarefas foi cancelado, devido a uma operação explícita de cancelamento ou à geração de uma exceção de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)

### <a name="remarks"></a>Comentários

Observe que uma ou mais tarefas agendadas para esse `structured_task_group` objeto podem ser executadas em linha no contexto de chamada.

Se uma ou mais tarefas agendadas para esse `structured_task_group` objeto gerarem uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para o `run_and_wait` método.

Depois que essa função retorna, o `structured_task_group` objeto é considerado em um estado final e não deve ser usado. Observe que a utilização após o `run_and_wait` método retornado resultará em um comportamento indefinido.

No caminho não excepcional da execução, você tem um mandato para chamar esse método ou o `wait` método antes de o destruidor de ser `structured_task_group` executado.

## <a name="structured_task_group"></a><a name="ctor"></a>structured_task_group

Constrói um novo objeto `structured_task_group`.

```cpp
structured_task_group();

structured_task_group(cancellation_token _CancellationToken);
```

### <a name="parameters"></a>parâmetros

*_CancellationToken*<br/>
Um token de cancelamento a ser associado a esse grupo de tarefas estruturado. O grupo de tarefas estruturado será cancelado quando o token for cancelado.

### <a name="remarks"></a>Comentários

O construtor que usa um token de cancelamento cria um `structured_task_group` que será cancelado quando a origem associada ao token for cancelada. Fornecer um token de cancelamento explícito também isola esse grupo de tarefas estruturado de participar de um cancelamento implícito de um grupo pai com um token diferente ou nenhum token.

## <a name="structured_task_group"></a><a name="dtor"></a>~ structured_task_group

Destrói um objeto `structured_task_group`. Você deve chamar o `wait` `run_and_wait` método ou no objeto antes da execução do destruidor, a menos que o destruidor esteja sendo executado como resultado do desenrolamento da pilha devido a uma exceção.

```cpp
~structured_task_group();
```

### <a name="remarks"></a>Comentários

Se o destruidor for executado como resultado da execução normal (por exemplo, sem desenrolamento de pilha devido a uma exceção) e nem `wait` os `run_and_wait` métodos nem forem chamados, o destruidor poderá lançar uma exceção de [missing_wait](missing-wait-class.md) .

## <a name="wait"></a><a name="wait"></a>esperado

Aguarda até que todo o trabalho no seja `structured_task_group` concluído ou cancelado.

```cpp
task_group_status wait();
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se a espera foi satisfeita ou se o grupo de tarefas foi cancelado, devido a uma operação explícita de cancelamento ou à geração de uma exceção de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)

### <a name="remarks"></a>Comentários

Observe que uma ou mais tarefas agendadas para esse `structured_task_group` objeto podem ser executadas em linha no contexto de chamada.

Se uma ou mais tarefas agendadas para esse `structured_task_group` objeto gerarem uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para o `wait` método.

Depois que essa função retorna, o `structured_task_group` objeto é considerado em um estado final e não deve ser usado. Observe que a utilização após o `wait` método retornado resultará em um comportamento indefinido.

No caminho não excepcional da execução, você tem um mandato para chamar esse método ou o `run_and_wait` método antes de o destruidor de ser `structured_task_group` executado.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe task_group](task-group-class.md)<br/>
[Classe task_handle](task-handle-class.md)
