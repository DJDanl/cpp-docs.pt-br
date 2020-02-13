---
title: Classe task_group
ms.date: 07/20/2018
f1_keywords:
- task_group
- PPL/concurrency::task_group
- PPL/concurrency::task_group::task_group
helpviewer_keywords:
- task_group class
ms.openlocfilehash: 60c147f38ddc3936f47aea0cfd1ab1548b382441
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142562"
---
# <a name="task_group-class"></a>Classe task_group

A classe `task_group` representa uma coleção de trabalho paralelo que pode ser aguardado ou cancelado.

## <a name="syntax"></a>Sintaxe

```cpp
class task_group;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[task_group](#ctor)|Sobrecarregado. Constrói um novo objeto `task_group`.|
|[~ task_group destruidor](#dtor)|Destrói um objeto `task_group`. Você deve chamar o método `wait` ou `run_and_wait` no objeto antes da execução do destruidor, a menos que o destruidor esteja sendo executado como resultado do desenrolamento da pilha devido a uma exceção.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[cancel](#cancel)|Faz com que seja possível tentar cancelar a subárvore de trabalho com raiz nesse grupo de tarefas. Cada tarefa agendada no grupo de tarefas será cancelada transitivamente, se possível.|
|[is_canceling](#is_canceling)|Informa ao chamador se o grupo de tarefas está ou não no meio de um cancelamento. Isso não indica necessariamente que o método `cancel` foi chamado no objeto `task_group` (embora, certamente, qualifique esse método para retornar `true`). Pode ser o caso em que o objeto `task_group` está sendo executado em linha e um grupo de tarefas mais adiante na árvore de trabalho foi cancelado. Em casos como esses, onde o tempo de execução pode determinar antecipadamente que o cancelamento fluirá por esse `task_group` objeto, `true` também será retornada.|
|[run](#run)|Sobrecarregado. Agenda uma tarefa no objeto `task_group`. Se um objeto `task_handle` for passado como um parâmetro para `run`, o chamador será responsável por gerenciar o tempo de vida do objeto `task_handle`. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve a alocação de heap dentro do tempo de execução que pode ser executada menos bem do que usar a versão que usa uma referência a um objeto `task_handle`. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado por esse parâmetro.|
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa a ser executada embutida no contexto de chamada com a assistência do objeto `task_group` para obter suporte completo ao cancelamento. A função aguarda até que todo o trabalho no objeto de `task_group` tenha sido concluído ou cancelado. Se um objeto `task_handle` for passado como um parâmetro para `run_and_wait`, o chamador será responsável por gerenciar o tempo de vida do objeto `task_handle`.|
|[esperado](#wait)|Aguarda até que todo o trabalho no objeto de `task_group` seja concluído ou cancelado.|

## <a name="remarks"></a>Comentários

Diferentemente da classe `structured_task_group` altamente restrita, a classe `task_group` é muito mais constructo geral. Ele não tem nenhuma das restrições descritas por [structured_task_group](structured-task-group-class.md). `task_group` objetos podem ser usados com segurança em threads e utilizados de formas de forma livre. A desvantagem da construção de `task_group` é que ela pode não ser executada, bem como a construção de `structured_task_group` para tarefas que executam pequenas quantidades de trabalho.

Para obter mais informações, consulte [paralelismo de tarefas](../task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task_group`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="cancel"></a>Cancelar

Faz com que seja possível tentar cancelar a subárvore de trabalho com raiz nesse grupo de tarefas. Cada tarefa agendada no grupo de tarefas será cancelada transitivamente, se possível.

```cpp
void cancel();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).

## <a name="is_canceling"></a>is_canceling

Informa ao chamador se o grupo de tarefas está ou não no meio de um cancelamento. Isso não indica necessariamente que o método `cancel` foi chamado no objeto `task_group` (embora, certamente, qualifique esse método para retornar `true`). Pode ser o caso em que o objeto `task_group` está sendo executado em linha e um grupo de tarefas mais adiante na árvore de trabalho foi cancelado. Em casos como esses, onde o tempo de execução pode determinar antecipadamente que o cancelamento fluirá por esse `task_group` objeto, `true` também será retornada.

```cpp
bool is_canceling();
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se o objeto de `task_group` está no meio de um cancelamento (ou se é garantido que esteja em breve).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).

## <a name="run"></a>funcionam

Agenda uma tarefa no objeto `task_group`. Se um objeto `task_handle` for passado como um parâmetro para `run`, o chamador será responsável por gerenciar o tempo de vida do objeto `task_handle`. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve a alocação de heap dentro do tempo de execução que pode ser executada menos bem do que usar a versão que usa uma referência a um objeto `task_handle`. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado por esse parâmetro.

```cpp
template<
   typename _Function
>
void run(
   const _Function& _Func
);

template<
   typename _Function
>
void run(
   const _Function& _Func,
   location& _Placement
);

template<
   typename _Function
>
void run(
   task_handle<_Function>& _Task_handle
);

template<
   typename _Function
>
void run(
   task_handle<_Function>& _Task_handle,
   location& _Placement
);
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar o corpo do identificador de tarefa.

*_Func*<br/>
Uma função que será chamada para invocar o corpo da tarefa. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.

*_Placement*<br/>
Uma referência ao local onde a tarefa representada pelo parâmetro `_Func` deve ser executada.

*_Task_handle*<br/>
Um identificador para o trabalho que está sendo agendado. Observe que o chamador tem responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará esperando que ele fique ativo até que o método `wait` ou `run_and_wait` tenha sido chamado nesse objeto `task_group`.

### <a name="remarks"></a>Comentários

O tempo de execução agenda a função de trabalho fornecida para ser executada posteriormente, o que pode ser após o retorno da função de chamada. Esse método usa um objeto [task_handle](task-handle-class.md) para manter uma cópia da função de trabalho fornecida. Portanto, todas as alterações de estado que ocorrem em um objeto de função que você passa para esse método não aparecerão na sua cópia do objeto de função. Além disso, certifique-se de que o tempo de vida de todos os objetos passados por ponteiro ou por referência à função de trabalho permaneça válido até que a função de trabalho retorne.

Se o `task_group` for destruido como resultado do desenrolamento da pilha de uma exceção, você não precisará garantir que uma chamada tenha sido feita para o método `wait` ou `run_and_wait`. Nesse caso, o destruidor irá cancelar adequadamente e aguardar a tarefa representada pelo parâmetro `_Task_handle` a ser concluída.

O método gera uma exceção [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) se o identificador de tarefa fornecido pelo parâmetro `_Task_handle` já tiver sido agendado em um objeto de grupo de tarefas por meio do método `run` e não houver nenhuma chamada intermediária para o método `wait` ou `run_and_wait` nesse grupo de tarefas.

## <a name="run_and_wait"></a>run_and_wait

Agenda uma tarefa a ser executada embutida no contexto de chamada com a assistência do objeto `task_group` para obter suporte completo ao cancelamento. A função aguarda até que todo o trabalho no objeto de `task_group` tenha sido concluído ou cancelado. Se um objeto `task_handle` for passado como um parâmetro para `run_and_wait`, o chamador será responsável por gerenciar o tempo de vida do objeto `task_handle`.

```cpp
template<
   class _Function
>
task_group_status run_and_wait(
   task_handle<_Function>& _Task_handle
);

template<
   class _Function
>
task_group_status run_and_wait(
   const _Function& _Func
);
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar o corpo da tarefa.

*_Task_handle*<br/>
Um identificador para a tarefa que será executada embutida no contexto de chamada. Observe que o chamador tem responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará esperando que ele fique ativo até que o método `run_and_wait` conclua a execução.

*_Func*<br/>
Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.

### <a name="return-value"></a>Valor retornado

Uma indicação de se a espera foi satisfeita ou se o grupo de tarefas foi cancelado, devido a uma operação explícita de cancelamento ou à geração de uma exceção de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).

### <a name="remarks"></a>Comentários

Observe que uma ou mais tarefas agendadas para esse objeto de `task_group` podem ser executadas em linha no contexto de chamada.

Se uma ou mais tarefas agendadas para este `task_group` objeto gerar uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para o método `run_and_wait`.

Após o retorno do método `run_and_wait` em um objeto `task_group`, o tempo de execução redefine o objeto para um estado limpo, no qual ele pode ser reutilizado. Isso inclui o caso em que o objeto `task_group` foi cancelado.

No caminho não excepcional da execução, você tem um mandato para chamar esse método ou o método `wait` antes de o destruidor do `task_group` ser executado.

## <a name="ctor"></a>task_group

Constrói um novo objeto `task_group`.

```cpp
task_group();

task_group(
   cancellation_token _CancellationToken
);
```

### <a name="parameters"></a>Parâmetros

*_CancellationToken*<br/>
Um token de cancelamento a ser associado a esse grupo de tarefas. O grupo de tarefas será cancelado quando o token for cancelado.

### <a name="remarks"></a>Comentários

O construtor que usa um token de cancelamento cria um `task_group` que será cancelado quando a origem associada ao token for cancelada. Fornecer um token de cancelamento explícito também isola esse grupo de tarefas de participar de um cancelamento implícito de um grupo pai com um token diferente ou nenhum token.

## <a name="dtor"></a>~ task_group

Destrói um objeto `task_group`. Você deve chamar o método `wait` ou `run_and_wait` no objeto antes da execução do destruidor, a menos que o destruidor esteja sendo executado como resultado do desenrolamento da pilha devido a uma exceção.

```cpp
~task_group();
```

### <a name="remarks"></a>Comentários

Se o destruidor for executado como resultado da execução normal (por exemplo, sem desenrolamento de pilha devido a uma exceção) e nem os métodos `wait` nem `run_and_wait` tiverem sido chamados, o destruidor poderá lançar uma exceção [missing_wait](missing-wait-class.md) .

## <a name="wait"></a>esperado

Aguarda até que todo o trabalho no objeto de `task_group` seja concluído ou cancelado.

```cpp
task_group_status wait();
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se a espera foi satisfeita ou se o grupo de tarefas foi cancelado, devido a uma operação explícita de cancelamento ou à geração de uma exceção de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).

### <a name="remarks"></a>Comentários

Observe que uma ou mais tarefas agendadas para esse objeto de `task_group` podem ser executadas em linha no contexto de chamada.

Se uma ou mais tarefas agendadas para este `task_group` objeto gerar uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para o método `wait`.

Chamar `wait` em um objeto `task_group` o redefine para um estado limpo, onde ele pode ser reutilizado. Isso inclui o caso em que o objeto `task_group` foi cancelado.

No caminho não excepcional da execução, você tem um mandato para chamar esse método ou o método `run_and_wait` antes de o destruidor do `task_group` ser executado.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe structured_task_group](structured-task-group-class.md)<br/>
[Classe task_handle](task-handle-class.md)
