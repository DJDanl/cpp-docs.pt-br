---
title: Classe task_group
ms.date: 07/20/2018
f1_keywords:
- task_group
- PPL/concurrency::task_group
- PPL/concurrency::task_group::task_group
helpviewer_keywords:
- task_group class
ms.openlocfilehash: 4d11a7fc25d95884418a3062721df75cc11be520
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224949"
---
# <a name="task_group-class"></a>Classe task_group

A `task_group` classe representa uma coleção de trabalho paralelo que pode ser aguardado ou cancelado.

## <a name="syntax"></a>Sintaxe

```cpp
class task_group;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[task_group](#ctor)|Sobrecarregado. Constrói um novo objeto `task_group`.|
|[~ task_group destruidor](#dtor)|Destrói um objeto `task_group`. Você deve chamar o `wait` `run_and_wait` método ou no objeto antes do destruidor em execução, a menos que o destruidor esteja sendo executado como resultado do desenrolamento de pilha devido a uma exceção.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cancel](#cancel)|Faz com que seja possível tentar cancelar a subárvore de trabalho com raiz nesse grupo de tarefas. Cada tarefa agendada no grupo de tarefas será cancelada transitivamente, se possível.|
|[is_canceling](#is_canceling)|Informa ao chamador se o grupo de tarefas está ou não no meio de um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `task_group` objeto (embora, certamente, qualifique esse método para retornar **`true`** ). Pode ser o caso em que o `task_group` objeto está sendo executado em linha e um grupo de tarefas mais adiante na árvore de trabalho foi cancelado. Em casos como esses, onde o tempo de execução pode determinar antecipadamente que o cancelamento fluirá por esse `task_group` objeto, **`true`** também será retornado.|
|[funcionam](#run)|Sobrecarregado. Agenda uma tarefa no `task_group` objeto. Se um `task_handle` objeto for passado como um parâmetro para `run` , o chamador será responsável por gerenciar o tempo de vida do `task_handle` objeto. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve a alocação de heap dentro do tempo de execução que pode ser executada menos bem do que usar a versão que usa uma referência a um `task_handle` objeto. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado por esse parâmetro.|
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa a ser executada embutida no contexto de chamada com a assistência do `task_group` objeto para obter suporte completo ao cancelamento. A função aguarda até que todo o trabalho no `task_group` objeto seja concluído ou cancelado. Se um `task_handle` objeto for passado como um parâmetro para `run_and_wait` , o chamador será responsável por gerenciar o tempo de vida do `task_handle` objeto.|
|[esperado](#wait)|Aguarda até que todo o trabalho no `task_group` objeto seja concluído ou cancelado.|

## <a name="remarks"></a>Comentários

Diferentemente da classe muito restrita `structured_task_group` , a `task_group` classe é uma construção muito mais geral. Ele não tem nenhuma das restrições descritas por [structured_task_group](structured-task-group-class.md). `task_group`os objetos podem ser usados com segurança em threads e utilizados de formas de forma livre. A desvantagem da `task_group` construção é que ela pode não ser executada, bem como a `structured_task_group` construção de tarefas que executam pequenas quantidades de trabalho.

Para obter mais informações, consulte [paralelismo de tarefas](../task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task_group`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="cancel"></a><a name="cancel"></a>Cancelar

Faz com que seja possível tentar cancelar a subárvore de trabalho com raiz nesse grupo de tarefas. Cada tarefa agendada no grupo de tarefas será cancelada transitivamente, se possível.

```cpp
void cancel();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).

## <a name="is_canceling"></a><a name="is_canceling"></a>is_canceling

Informa ao chamador se o grupo de tarefas está ou não no meio de um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `task_group` objeto (embora, certamente, qualifique esse método para retornar **`true`** ). Pode ser o caso em que o `task_group` objeto está sendo executado em linha e um grupo de tarefas mais adiante na árvore de trabalho foi cancelado. Em casos como esses, onde o tempo de execução pode determinar antecipadamente que o cancelamento fluirá por esse `task_group` objeto, **`true`** também será retornado.

```cpp
bool is_canceling();
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se o `task_group` objeto está no meio de um cancelamento (ou se é garantido que esteja em breve).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).

## <a name="run"></a><a name="run"></a>funcionam

Agenda uma tarefa no `task_group` objeto. Se um `task_handle` objeto for passado como um parâmetro para `run` , o chamador será responsável por gerenciar o tempo de vida do `task_handle` objeto. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve a alocação de heap dentro do tempo de execução que pode ser executada menos bem do que usar a versão que usa uma referência a um `task_handle` objeto. A versão que usa o parâmetro `_Placement` faz com que a tarefa seja ajustada em direção à execução no local especificado por esse parâmetro.

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

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar o corpo do identificador de tarefa.

*_Func*<br/>
Uma função que será chamada para invocar o corpo da tarefa. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()` .

*_Placement*<br/>
Uma referência ao local onde a tarefa representada pelo `_Func` parâmetro deve ser executada.

*_Task_handle*<br/>
Um identificador para o trabalho que está sendo agendado. Observe que o chamador tem responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará esperando que ele fique ativo até que o `wait` método ou seja `run_and_wait` chamado neste `task_group` objeto.

### <a name="remarks"></a>Comentários

O tempo de execução agenda a função de trabalho fornecida para ser executada posteriormente, o que pode ser após o retorno da função de chamada. Esse método usa um objeto [task_handle](task-handle-class.md) para manter uma cópia da função de trabalho fornecida. Portanto, todas as alterações de estado que ocorrem em um objeto de função que você passa para esse método não aparecerão na sua cópia do objeto de função. Além disso, certifique-se de que o tempo de vida de todos os objetos passados por ponteiro ou por referência à função de trabalho permaneça válido até que a função de trabalho retorne.

Se o `task_group` destruições como resultado do desenrolamento da pilha de uma exceção, você não precisa garantir que uma chamada tenha sido feita para o `wait` `run_and_wait` método ou. Nesse caso, o destruidor irá cancelar adequadamente e aguardar que a tarefa representada pelo `_Task_handle` parâmetro seja concluída.

O método gera uma exceção [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) se o identificador de tarefa fornecido pelo `_Task_handle` parâmetro já tiver sido agendado para um objeto de grupo de tarefas por meio do `run` método e não houver uma chamada intermediária para `wait` o `run_and_wait` método ou nesse grupo de tarefas.

## <a name="run_and_wait"></a><a name="run_and_wait"></a>run_and_wait

Agenda uma tarefa a ser executada embutida no contexto de chamada com a assistência do `task_group` objeto para obter suporte completo ao cancelamento. A função aguarda até que todo o trabalho no `task_group` objeto seja concluído ou cancelado. Se um `task_handle` objeto for passado como um parâmetro para `run_and_wait` , o chamador será responsável por gerenciar o tempo de vida do `task_handle` objeto.

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

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar o corpo da tarefa.

*_Task_handle*<br/>
Um identificador para a tarefa que será executada embutida no contexto de chamada. Observe que o chamador tem responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará esperando que ele fique ativo até que o `run_and_wait` método conclua a execução.

*_Func*<br/>
Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()` .

### <a name="return-value"></a>Valor retornado

Uma indicação de se a espera foi satisfeita ou se o grupo de tarefas foi cancelado, devido a uma operação explícita de cancelamento ou à geração de uma exceção de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).

### <a name="remarks"></a>Comentários

Observe que uma ou mais tarefas agendadas para esse `task_group` objeto podem ser executadas em linha no contexto de chamada.

Se uma ou mais tarefas agendadas para esse `task_group` objeto gerarem uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para o `run_and_wait` método.

Após o retorno do `run_and_wait` método em um `task_group` objeto, o tempo de execução redefine o objeto para um estado limpo, no qual ele pode ser reutilizado. Isso inclui o caso em que o `task_group` objeto foi cancelado.

No caminho não excepcional da execução, você tem um mandato para chamar esse método ou o `wait` método antes de o destruidor de ser `task_group` executado.

## <a name="task_group"></a><a name="ctor"></a>task_group

Constrói um novo objeto `task_group`.

```cpp
task_group();

task_group(
   cancellation_token _CancellationToken
);
```

### <a name="parameters"></a>parâmetros

*_CancellationToken*<br/>
Um token de cancelamento a ser associado a esse grupo de tarefas. O grupo de tarefas será cancelado quando o token for cancelado.

### <a name="remarks"></a>Comentários

O construtor que usa um token de cancelamento cria um `task_group` que será cancelado quando a origem associada ao token for cancelada. Fornecer um token de cancelamento explícito também isola esse grupo de tarefas de participar de um cancelamento implícito de um grupo pai com um token diferente ou nenhum token.

## <a name="task_group"></a><a name="dtor"></a>~ task_group

Destrói um objeto `task_group`. Você deve chamar o `wait` `run_and_wait` método ou no objeto antes do destruidor em execução, a menos que o destruidor esteja sendo executado como resultado do desenrolamento de pilha devido a uma exceção.

```cpp
~task_group();
```

### <a name="remarks"></a>Comentários

Se o destruidor for executado como resultado da execução normal (por exemplo, sem desenrolamento de pilha devido a uma exceção) e nem `wait` os `run_and_wait` métodos nem forem chamados, o destruidor poderá lançar uma exceção de [missing_wait](missing-wait-class.md) .

## <a name="wait"></a><a name="wait"></a>esperado

Aguarda até que todo o trabalho no `task_group` objeto seja concluído ou cancelado.

```cpp
task_group_status wait();
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se a espera foi satisfeita ou se o grupo de tarefas foi cancelado, devido a uma operação explícita de cancelamento ou à geração de uma exceção de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).

### <a name="remarks"></a>Comentários

Observe que uma ou mais tarefas agendadas para esse `task_group` objeto podem ser executadas em linha no contexto de chamada.

Se uma ou mais tarefas agendadas para esse `task_group` objeto gerarem uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para o `wait` método.

Chamar `wait` em um `task_group` objeto o redefine para um estado limpo, onde ele pode ser reutilizado. Isso inclui o caso em que o `task_group` objeto foi cancelado.

No caminho não excepcional da execução, você tem um mandato para chamar esse método ou o `run_and_wait` método antes de o destruidor de ser `task_group` executado.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe structured_task_group](structured-task-group-class.md)<br/>
[Classe task_handle](task-handle-class.md)
