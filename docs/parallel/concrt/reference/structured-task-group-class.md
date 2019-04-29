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
ms.openlocfilehash: 27610539ab500a113ea41021744c55425fe9cd9b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62337187"
---
# <a name="structuredtaskgroup-class"></a>Classe structured_task_group

O `structured_task_group` classe representa uma coleção altamente estruturada de trabalho em paralelo. Você pode colocar na fila de tarefas individuais em paralelo para uma `structured_task_group` usando `task_handle` objetos e aguarde até que elas sejam concluídas ou cancele o grupo de tarefas antes que eles concluírem a execução, qual anulará todas as tarefas que não começaram a execução.

## <a name="syntax"></a>Sintaxe

```
class structured_task_group;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[structured_task_group](#ctor)|Sobrecarregado. Constrói um novo objeto `structured_task_group`.|
|[~ structured_task_group destruidor](#dtor)|Destrói um objeto `structured_task_group`. Você deve chamar o `wait` ou `run_and_wait` método no objeto antes de executar o destruidor, a menos que o destruidor está sendo executado como resultado de desenrolamento de pilha devido a uma exceção.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cancel](#cancel)|Se esforça para tentativa de cancelar a subárvore enraizada nesse grupo de tarefas de trabalho. Cada tarefa agendada no grupo de tarefas será obter cancelada transitivamente se possível.|
|[is_canceling](#is_canceling)|Informa ao chamador se o grupo de tarefas está atualmente em meio a um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado em de `structured_task_group` objeto (embora, certamente qualifica esse método para retornar **verdadeiro**). Ele pode ser o caso que a `structured_task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá por meio deste `structured_task_group` objeto, **verdadeiro** também será retornado.|
|[run](#run)|Sobrecarregado. Agenda uma tarefa no `structured_task_group` objeto. O chamador gerencia a vida útil do `task_handle` objeto passado a `_Task_handle` parâmetro. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado por esse parâmetro.|
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa para ser executado embutido no contexto de chamada com o auxílio do `structured_task_group` objeto para suporte ao cancelamento completa. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto. A função, em seguida, aguarda até que todo o trabalho no `structured_task_group` objeto foi concluída ou cancelado.|
|[wait](#wait)|Aguarda até que todo o trabalho no `structured_task_group` foi concluída ou é cancelado.|

## <a name="remarks"></a>Comentários

Há um número de restrições severas colocado sobre o uso de um `structured_task_group` objeto para obter um melhor desempenho:

- Um único `structured_task_group` objeto não pode ser usado por vários threads. Todas as operações em um `structured_task_group` objeto deve ser executado pelo thread que criou o objeto. As duas exceções a essa regra são as funções de membro `cancel` e `is_canceling`. O objeto não pode estar na lista de captura de uma expressão lambda e ser usado dentro de uma tarefa, a menos que a tarefa estiver usando uma das operações de cancelamento.

- Todas as tarefas agendadas para um `structured_task_group` objeto são agendados por meio do uso de `task_handle` objetos que é necessário gerenciar explicitamente a vida útil do.

- Vários grupos só podem ser usados na ordem absolutamente aninhado. Se duas `structured_task_group` objetos são declarados, o segundo é que está sendo declarado (aquele interna) deve destruir antes de qualquer método, exceto `cancel` ou `is_canceling` é chamado no primeiro (aquele externa). Essa condição se aplica no caso de simplesmente declarar vários `structured_task_group` objetos dentro os escopos aninhados funcionalmente ou mesmos, bem como no caso de uma tarefa que foi colocado na fila para o `structured_task_group` por meio de `run` ou `run_and_wait` métodos.

- Ao contrário de gerais `task_group` classe, todos os estados no `structured_task_group` classe são finais. Depois de você ter tarefas em fila para o grupo e espera por eles devem concluir, você não poderá usar o mesmo grupo novamente.

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`structured_task_group`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="cancel"></a> Cancelar

Se esforça para tentativa de cancelar a subárvore enraizada nesse grupo de tarefas de trabalho. Cada tarefa agendada no grupo de tarefas será obter cancelada transitivamente se possível.

```
void cancel();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

##  <a name="is_canceling"></a> is_canceling

Informa ao chamador se o grupo de tarefas está atualmente em meio a um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado em de `structured_task_group` objeto (embora, certamente qualifica esse método para retornar **verdadeiro**). Ele pode ser o caso que a `structured_task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá por meio deste `structured_task_group` objeto, **verdadeiro** também será retornado.

```
bool is_canceling();
```

### <a name="return-value"></a>Valor de retorno

Indica se o `structured_task_group` objeto está no meio de um cancelamento (ou é garantido que seja em breve).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

##  <a name="run"></a> run

Agenda uma tarefa no `structured_task_group` objeto. O chamador gerencia a vida útil do `task_handle` objeto passado a `_Task_handle` parâmetro. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado por esse parâmetro.

```
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
O tipo do objeto de função que será chamado para executar o corpo do identificador de tarefa.

*_Task_handle*<br/>
Um identificador para o trabalho agendado. Observe que o chamador tem responsabilidade pelo tempo de vida deste objeto. O tempo de execução continuará esperá-lo útil até que o `wait` ou `run_and_wait` método foi chamado neste `structured_task_group` objeto.

*_Placement*<br/>
Uma referência para o local em que a tarefa representada pelo `_Task_handle` parâmetro deve ser executada.

### <a name="remarks"></a>Comentários

O tempo de execução cria uma cópia da função de trabalho que você passa para esse método. As alterações de estado que ocorrem em um objeto de função que você passa para esse método não aparecerão na sua cópia desse objeto de função.

Se o `structured_task_group` destructs como resultado de desenrolamento de uma exceção de pilha, não é necessário garantir que uma chamada foi feita para o `wait` ou `run_and_wait` método. Nesse caso, o destruidor adequadamente cancelará e aguarde até que a tarefa representada pelo `_Task_handle` parâmetro para ser concluída.

Gera uma [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) exceção se a tarefa manipular determinado pelo `_Task_handle` parâmetro já foi agendado para um objeto de grupo de tarefas por meio do `run` método e não houve nenhuma chamada intermediária para tanto a `wait` ou `run_and_wait` método nesse grupo de tarefas.

##  <a name="run_and_wait"></a> run_and_wait

Agenda uma tarefa para ser executado embutido no contexto de chamada com o auxílio do `structured_task_group` objeto para suporte ao cancelamento completa. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto. A função, em seguida, aguarda até que todo o trabalho no `structured_task_group` objeto foi concluída ou cancelado.

```
template<class _Function>
task_group_status run_and_wait(task_handle<_Function>& _Task_handle);

template<class _Function>
task_group_status run_and_wait(const _Function& _Func);
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será chamado para executar a tarefa.

*_Task_handle*<br/>
Um identificador para a tarefa que será executada embutida no contexto de chamada. Observe que o chamador tem responsabilidade pelo tempo de vida deste objeto. O tempo de execução continuará esperar que ele live até o `run_and_wait` método conclui a execução.

*_Func*<br/>
Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser um lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.

### <a name="return-value"></a>Valor de retorno

Uma indicação de se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícito ou uma exceção é lançada de uma das suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)

### <a name="remarks"></a>Comentários

Observe que uma ou mais das tarefas agendadas para isso `structured_task_group` objeto pode ser executada embutida no contexto de chamada.

Se uma ou mais das tarefas agendadas para isso `structured_task_group` objeto gerou uma exceção, o tempo de execução selecionará um tal exceção de sua escolha e propagá-los de fora a chamada para o `run_and_wait` método.

Depois que essa função retornar, o `structured_task_group` objeto é considerado em um estado final e não deve ser usado. Observe que utilização após o `run_and_wait` método retorna resultará em um comportamento indefinido.

No caminho de execução não excepcional, você tem uma exigência para chamar esse método qualquer ou o `wait` método antes do destruidor do `structured_task_group` executa.

##  <a name="ctor"></a> structured_task_group

Constrói um novo objeto `structured_task_group`.

```
structured_task_group();

structured_task_group(cancellation_token _CancellationToken);
```

### <a name="parameters"></a>Parâmetros

*_CancellationToken*<br/>
Um token de cancelamento para associar a esse grupo de tarefas estruturados. O grupo de tarefas estruturados será cancelado quando o token é cancelado.

### <a name="remarks"></a>Comentários

O construtor que usa um token de cancelamento cria um `structured_task_group` que serão canceladas quando o código-fonte associado ao token é cancelado. Fornecer um token de cancelamento explícito também isola a esse grupo de tarefas estruturados de participar de um cancelamento implícito de um grupo pai, com um token diferente ou nenhum.

##  <a name="dtor"></a> ~structured_task_group

Destrói um objeto `structured_task_group`. Você deve chamar o `wait` ou `run_and_wait` método no objeto antes de executar o destruidor, a menos que o destruidor está sendo executado como resultado de desenrolamento de pilha devido a uma exceção.

```
~structured_task_group();
```

### <a name="remarks"></a>Comentários

Se o destruidor for executado como o resultado da execução normal (por exemplo, não desenrolamento de pilha devido a uma exceção) e nem o `wait` nem `run_and_wait` métodos tiveram sido chamados, o destruidor pode lançar uma [missing_wait](missing-wait-class.md) exceção.

##  <a name="wait"></a> Aguarde

Aguarda até que todo o trabalho no `structured_task_group` foi concluída ou é cancelado.

```
task_group_status wait();
```

### <a name="return-value"></a>Valor de retorno

Uma indicação de se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícito ou uma exceção é lançada de uma das suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)

### <a name="remarks"></a>Comentários

Observe que uma ou mais das tarefas agendadas para isso `structured_task_group` objeto pode ser executada embutida no contexto de chamada.

Se uma ou mais das tarefas agendadas para isso `structured_task_group` objeto gerou uma exceção, o tempo de execução selecionará um tal exceção de sua escolha e propagá-los de fora a chamada para o `wait` método.

Depois que essa função retornar, o `structured_task_group` objeto é considerado em um estado final e não deve ser usado. Observe que utilização após o `wait` método retorna resultará em um comportamento indefinido.

No caminho de execução não excepcional, você tem uma exigência para chamar esse método qualquer ou o `run_and_wait` método antes do destruidor do `structured_task_group` executa.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe task_group](task-group-class.md)<br/>
[Classe task_handle](task-handle-class.md)
