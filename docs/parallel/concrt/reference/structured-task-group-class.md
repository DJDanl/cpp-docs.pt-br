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
ms.openlocfilehash: 93dd79b755f79dcb4857c1b1c4856362b0bd45dd
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78884112"
---
# <a name="structured_task_group-class"></a>Classe structured_task_group

A classe `structured_task_group` representa uma coleção altamente estruturada de trabalho paralelo. Você pode colocar tarefas paralelas individuais em uma `structured_task_group` usando `task_handle` objetos e esperar que elas sejam concluídas ou cancelar o grupo de tarefas antes de concluir a execução, o que anulará todas as tarefas que não começaram a execução.

## <a name="syntax"></a>Sintaxe

```cpp
class structured_task_group;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[structured_task_group](#ctor)|Sobrecarregado. Constrói um novo objeto `structured_task_group`.|
|[~ structured_task_group destruidor](#dtor)|Destrói um objeto `structured_task_group`. Você deve chamar o método `wait` ou `run_and_wait` no objeto antes da execução do destruidor, a menos que o destruidor esteja sendo executado como resultado do desenrolamento da pilha devido a uma exceção.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[cancel](#cancel)|Faz com que seja possível tentar cancelar a subárvore de trabalho com raiz nesse grupo de tarefas. Cada tarefa agendada no grupo de tarefas será cancelada transitivamente, se possível.|
|[is_canceling](#is_canceling)|Informa ao chamador se o grupo de tarefas está ou não no meio de um cancelamento. Isso não indica necessariamente que o método `cancel` foi chamado no objeto `structured_task_group` (embora, certamente, qualifique esse método para retornar **true**). Pode ser o caso em que o objeto `structured_task_group` está sendo executado em linha e um grupo de tarefas mais adiante na árvore de trabalho foi cancelado. Em casos como esses, onde o tempo de execução pode determinar antecipadamente que o cancelamento fluirá por esse `structured_task_group` objeto, **verdadeiro** também será retornado.|
|[run](#run)|Sobrecarregado. Agenda uma tarefa no objeto `structured_task_group`. O chamador gerencia o tempo de vida do objeto de `task_handle` passado no parâmetro `_Task_handle`. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado por esse parâmetro.|
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa a ser executada embutida no contexto de chamada com a assistência do objeto `structured_task_group` para obter suporte completo ao cancelamento. Se um objeto `task_handle` for passado como um parâmetro para `run_and_wait`, o chamador será responsável por gerenciar o tempo de vida do objeto `task_handle`. A função aguarda até que todo o trabalho no objeto de `structured_task_group` tenha sido concluído ou cancelado.|
|[esperado](#wait)|Aguarda até que todo o trabalho na `structured_task_group` tenha sido concluído ou cancelado.|

## <a name="remarks"></a>Comentários

Há várias restrições severas colocadas no uso de um objeto `structured_task_group` para obter o desempenho:

- Um único objeto `structured_task_group` não pode ser usado por vários threads. Todas as operações em um objeto `structured_task_group` devem ser executadas pelo thread que criou o objeto. As duas exceções a essa regra são as funções de membro `cancel` e `is_canceling`. O objeto pode não estar na lista de captura de uma expressão lambda e ser usado dentro de uma tarefa, a menos que a tarefa esteja usando uma das operações de cancelamento.

- Todas as tarefas agendadas para um objeto de `structured_task_group` são agendadas por meio do uso de `task_handle` objetos que você deve gerenciar explicitamente o tempo de vida de.

- Vários grupos só podem ser usados em ordem absolutamente aninhada. Se dois objetos `structured_task_group` forem declarados, o segundo que está sendo declarado (o interno) deverá ser destruído antes de qualquer método, exceto `cancel` ou `is_canceling` for chamado na primeira (a externa). Essa condição se aplica em ambos os casos de simplesmente declarar vários objetos de `structured_task_group` dentro dos mesmos ou de escopos aninhados com funcionalidade, bem como o caso de uma tarefa que foi enfileirada para o `structured_task_group` por meio dos métodos `run` ou `run_and_wait`.

- Ao contrário da classe de `task_group` geral, todos os Estados na classe `structured_task_group` são finais. Depois de colocar as tarefas em fila no grupo e aguardar sua conclusão, você não poderá usar o mesmo grupo novamente.

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`structured_task_group`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="cancel"></a>Cancelar

Faz com que seja possível tentar cancelar a subárvore de trabalho com raiz nesse grupo de tarefas. Cada tarefa agendada no grupo de tarefas será cancelada transitivamente, se possível.

```cpp
void cancel();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

## <a name="is_canceling"></a>is_canceling

Informa ao chamador se o grupo de tarefas está ou não no meio de um cancelamento. Isso não indica necessariamente que o método `cancel` foi chamado no objeto `structured_task_group` (embora, certamente, qualifique esse método para retornar **true**). Pode ser o caso em que o objeto `structured_task_group` está sendo executado em linha e um grupo de tarefas mais adiante na árvore de trabalho foi cancelado. Em casos como esses, onde o tempo de execução pode determinar antecipadamente que o cancelamento fluirá por esse `structured_task_group` objeto, **verdadeiro** também será retornado.

```cpp
bool is_canceling();
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se o objeto de `structured_task_group` está no meio de um cancelamento (ou se é garantido que esteja em breve).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

## <a name="run"></a>funcionam

Agenda uma tarefa no objeto `structured_task_group`. O chamador gerencia o tempo de vida do objeto de `task_handle` passado no parâmetro `_Task_handle`. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado por esse parâmetro.

```cpp
template<class _Function>
void run(
    task_handle<_Function>& _Task_handle);

template<class _Function>
void run(
    task_handle<_Function>& _Task_handle,
    location& _Placement);
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar o corpo do identificador de tarefa.

*_Task_handle*<br/>
Um identificador para o trabalho que está sendo agendado. Observe que o chamador tem responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará esperando que ele fique ativo até que o método `wait` ou `run_and_wait` tenha sido chamado nesse objeto `structured_task_group`.

*_Placement*<br/>
Uma referência ao local onde a tarefa representada pelo parâmetro `_Task_handle` deve ser executada.

### <a name="remarks"></a>Comentários

O tempo de execução cria uma cópia da função de trabalho que você passa para esse método. As alterações de estado que ocorrem em um objeto de função que você passa para esse método não aparecerão na sua cópia do objeto de função.

Se o `structured_task_group` for destruido como resultado do desenrolamento da pilha de uma exceção, você não precisará garantir que uma chamada tenha sido feita para o método `wait` ou `run_and_wait`. Nesse caso, o destruidor irá cancelar adequadamente e aguardar a tarefa representada pelo parâmetro `_Task_handle` a ser concluída.

Gera uma exceção [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) se o identificador de tarefa fornecido pelo parâmetro `_Task_handle` já tiver sido agendado em um objeto de grupo de tarefas por meio do método `run` e não houver nenhuma chamada intermediária para o método `wait` ou `run_and_wait` nesse grupo de tarefas.

## <a name="run_and_wait"></a>run_and_wait

Agenda uma tarefa a ser executada embutida no contexto de chamada com a assistência do objeto `structured_task_group` para obter suporte completo ao cancelamento. Se um objeto `task_handle` for passado como um parâmetro para `run_and_wait`, o chamador será responsável por gerenciar o tempo de vida do objeto `task_handle`. A função aguarda até que todo o trabalho no objeto de `structured_task_group` tenha sido concluído ou cancelado.

```cpp
template<class _Function>
task_group_status run_and_wait(task_handle<_Function>& _Task_handle);

template<class _Function>
task_group_status run_and_wait(const _Function& _Func);
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar a tarefa.

*_Task_handle*<br/>
Um identificador para a tarefa que será executada embutida no contexto de chamada. Observe que o chamador tem responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará esperando que ele fique ativo até que o método `run_and_wait` conclua a execução.

*_Func*<br/>
Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser um lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.

### <a name="return-value"></a>Valor retornado

Uma indicação de se a espera foi satisfeita ou se o grupo de tarefas foi cancelado, devido a uma operação explícita de cancelamento ou à geração de uma exceção de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)

### <a name="remarks"></a>Comentários

Observe que uma ou mais tarefas agendadas para esse objeto de `structured_task_group` podem ser executadas em linha no contexto de chamada.

Se uma ou mais tarefas agendadas para este `structured_task_group` objeto gerar uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para o método `run_and_wait`.

Depois que essa função retorna, o objeto `structured_task_group` é considerado em um estado final e não deve ser usado. Observe que a utilização após o `run_and_wait` método retorna resultará em um comportamento indefinido.

No caminho não excepcional da execução, você tem um mandato para chamar esse método ou o método `wait` antes de o destruidor do `structured_task_group` ser executado.

## <a name="ctor"></a>structured_task_group

Constrói um novo objeto `structured_task_group`.

```cpp
structured_task_group();

structured_task_group(cancellation_token _CancellationToken);
```

### <a name="parameters"></a>Parâmetros

*_CancellationToken*<br/>
Um token de cancelamento a ser associado a esse grupo de tarefas estruturado. O grupo de tarefas estruturado será cancelado quando o token for cancelado.

### <a name="remarks"></a>Comentários

O construtor que usa um token de cancelamento cria um `structured_task_group` que será cancelado quando a origem associada ao token for cancelada. Fornecer um token de cancelamento explícito também isola esse grupo de tarefas estruturado de participar de um cancelamento implícito de um grupo pai com um token diferente ou nenhum token.

## <a name="dtor"></a>~ structured_task_group

Destrói um objeto `structured_task_group`. Você deve chamar o método `wait` ou `run_and_wait` no objeto antes da execução do destruidor, a menos que o destruidor esteja sendo executado como resultado do desenrolamento da pilha devido a uma exceção.

```cpp
~structured_task_group();
```

### <a name="remarks"></a>Comentários

Se o destruidor for executado como resultado da execução normal (por exemplo, sem desenrolamento de pilha devido a uma exceção) e nem os métodos `wait` nem `run_and_wait` tiverem sido chamados, o destruidor poderá lançar uma exceção [missing_wait](missing-wait-class.md) .

## <a name="wait"></a>esperado

Aguarda até que todo o trabalho na `structured_task_group` tenha sido concluído ou cancelado.

```cpp
task_group_status wait();
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se a espera foi satisfeita ou se o grupo de tarefas foi cancelado, devido a uma operação explícita de cancelamento ou à geração de uma exceção de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)

### <a name="remarks"></a>Comentários

Observe que uma ou mais tarefas agendadas para esse objeto de `structured_task_group` podem ser executadas em linha no contexto de chamada.

Se uma ou mais tarefas agendadas para este `structured_task_group` objeto gerar uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para o método `wait`.

Depois que essa função retorna, o objeto `structured_task_group` é considerado em um estado final e não deve ser usado. Observe que a utilização após o `wait` método retorna resultará em um comportamento indefinido.

No caminho não excepcional da execução, você tem um mandato para chamar esse método ou o método `run_and_wait` antes de o destruidor do `structured_task_group` ser executado.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe task_group](task-group-class.md)<br/>
[Classe task_handle](task-handle-class.md)
