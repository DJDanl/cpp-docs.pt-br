---
title: Classe task_group
ms.date: 07/20/2018
f1_keywords:
- task_group
- PPL/concurrency::task_group
- PPL/concurrency::task_group::task_group
helpviewer_keywords:
- task_group class
ms.openlocfilehash: 1ba7251afca80c561bd8861968c35e3242c1507a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588845"
---
# <a name="taskgroup-class"></a>Classe task_group

O `task_group` classe representa uma coleção de trabalho paralelo que pode ser cancelada ou aguardada.

## <a name="syntax"></a>Sintaxe

```
class task_group;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[task_group](#ctor)|Sobrecarregado. Constrói um novo objeto `task_group`.|
|[~ task_group destruidor](#dtor)|Destrói um objeto `task_group`. Você deve chamar o tanto a `wait` ou `run_and_wait` método no objeto antes do destruidor em execução, a menos que o destruidor está sendo executado como resultado da pilha de desenrolamento devido a uma exceção.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cancel](#cancel)|Se esforça para tentativa de cancelar a subárvore enraizada nesse grupo de tarefas de trabalho. Cada tarefa agendada no grupo de tarefas será obter cancelada transitivamente se possível.|
|[is_canceling](#is_canceling)|Informa ao chamador se o grupo de tarefas está atualmente em meio a um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado em de `task_group` objeto (embora, certamente qualifica esse método para retornar `true`). Ele pode ser o caso que a `task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá por meio deste `task_group` objeto, `true` também será retornado.|
|[run](#run)|Sobrecarregado. Agenda uma tarefa no `task_group` objeto. Se um `task_handle` objeto é passado como um parâmetro para `run`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve alocação de heap de dentro do tempo de execução que pode ser um desempenho inferior que usar a versão que usa uma referência a um `task_handle` objeto. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado por esse parâmetro.|
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa para ser executado embutido no contexto de chamada com o auxílio do `task_group` objeto para suporte ao cancelamento completa. A função, em seguida, aguarda até que todo o trabalho no `task_group` objeto foi concluída ou cancelado. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto.|
|[wait](#wait)|Aguarda até que todo o trabalho no `task_group` objeto foi concluída ou cancelado.|

## <a name="remarks"></a>Comentários

Ao contrário de altamente restrita `structured_task_group` classe, o `task_group` classe é construção muito mais geral. Ele não tem qualquer uma das restrições descritas por [structured_task_group](structured-task-group-class.md). `task_group` objetos com segurança podem ser usados em threads e utilizados de formas de forma livre. A desvantagem do `task_group` construção é que ele não pode executar, bem como a `structured_task_group` construir para tarefas que realizam pequenas quantidades de trabalho.

Para obter mais informações, consulte [paralelismo de tarefas](../task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task_group`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="cancel"></a> Cancelar

Se esforça para tentativa de cancelar a subárvore enraizada nesse grupo de tarefas de trabalho. Cada tarefa agendada no grupo de tarefas será obter cancelada transitivamente se possível.

```
void cancel();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).

##  <a name="is_canceling"></a> is_canceling

Informa ao chamador se o grupo de tarefas está atualmente em meio a um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado em de `task_group` objeto (embora, certamente qualifica esse método para retornar `true`). Ele pode ser o caso que a `task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá por meio deste `task_group` objeto, `true` também será retornado.

```
bool is_canceling();
```

### <a name="return-value"></a>Valor de retorno

Indica se o `task_group` objeto está no meio de um cancelamento (ou é garantido que seja em breve).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).

##  <a name="run"></a> executar

Agenda uma tarefa no `task_group` objeto. Se um `task_handle` objeto é passado como um parâmetro para `run`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve alocação de heap de dentro do tempo de execução que pode ser um desempenho inferior que usar a versão que usa uma referência a um `task_handle` objeto. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado por esse parâmetro.

```
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
O tipo do objeto de função que será chamado para executar o corpo do identificador de tarefa.

*_Func*<br/>
Uma função que será chamada para invocar o corpo da tarefa. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.

*Posicionamento*<br/>
Uma referência para o local em que a tarefa representada pelo `_Func` parâmetro deve ser executada.

*_Task_handle*<br/>
Um identificador para o trabalho agendado. Observe que o chamador tem responsabilidade pelo tempo de vida deste objeto. O tempo de execução continuará esperá-lo útil até que o `wait` ou `run_and_wait` método foi chamado neste `task_group` objeto.

### <a name="remarks"></a>Comentários

O tempo de execução agenda a função de trabalho fornecida para ser executado em um momento posterior, o que pode ser após retorna da função de chamada. Esse método usa um [task_handle](task-handle-class.md) objeto para manter uma cópia da função de trabalho fornecida. Portanto, as alterações de estado que ocorrem em um objeto de função que você passa para esse método não aparecerá na sua cópia desse objeto de função. Além disso, certifique-se de que o tempo de vida de todos os objetos que passam por ponteiro ou referência para a função de trabalho permaneça válido até que a função de trabalho retorna.

Se o `task_group` destructs como resultado de desenrolamento de uma exceção de pilha, não é necessário garantir que uma chamada foi feita para o `wait` ou `run_and_wait` método. Nesse caso, o destruidor adequadamente cancelará e aguarde até que a tarefa representada pelo `_Task_handle` parâmetro para ser concluída.

O método lança um [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) exceção se a tarefa de lidar com determinado pelo `_Task_handle` parâmetro já foi agendado para um objeto de grupo de tarefas por meio do `run` método e houve nenhum chamada intermediária para o `wait` ou `run_and_wait` método nesse grupo de tarefas.

##  <a name="run_and_wait"></a> run_and_wait

Agenda uma tarefa para ser executado embutido no contexto de chamada com o auxílio do `task_group` objeto para suporte ao cancelamento completa. A função, em seguida, aguarda até que todo o trabalho no `task_group` objeto foi concluída ou cancelado. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto.

```
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
O tipo do objeto de função que será chamado para executar o corpo da tarefa.

*_Task_handle*<br/>
Um identificador para a tarefa que será executada embutida no contexto de chamada. Observe que o chamador tem responsabilidade pelo tempo de vida deste objeto. O tempo de execução continuará esperar que ele live até o `run_and_wait` método conclui a execução.

*_Func*<br/>
Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.

### <a name="return-value"></a>Valor de retorno

Uma indicação de se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícito ou uma exceção é lançada de uma das suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).

### <a name="remarks"></a>Comentários

Observe que uma ou mais das tarefas agendadas para isso `task_group` objeto pode ser executada embutida no contexto de chamada.

Se uma ou mais das tarefas agendadas para isso `task_group` objeto gerou uma exceção, o tempo de execução selecionará um tal exceção de sua escolha e propagá-los de fora a chamada para o `run_and_wait` método.

Após o retorno do `run_and_wait` método em um `task_group` do objeto, o tempo de execução redefine o objeto para um estado limpo, onde ele possa ser reutilizado. Isso inclui o caso em que o `task_group` objeto foi cancelado.

No caminho de execução não excepcional, você tem uma exigência para chamar esse método qualquer ou o `wait` método antes do destruidor do `task_group` executa.

##  <a name="ctor"></a> task_group

Constrói um novo objeto `task_group`.

```
task_group();

task_group(
   cancellation_token _CancellationToken
);
```

### <a name="parameters"></a>Parâmetros

*_CancellationToken*<br/>
Um token de cancelamento para associar a esse grupo de tarefas. O grupo de tarefas será cancelado quando o token é cancelado.

### <a name="remarks"></a>Comentários

O construtor que usa um token de cancelamento cria um `task_group` que serão canceladas quando o código-fonte associado ao token é cancelado. Fornecer um token de cancelamento explícito também isola a esse grupo de trabalho da participação em um cancelamento implícito de um grupo pai, com um token diferente ou nenhum.

##  <a name="dtor"></a> ~ task_group

Destrói um objeto `task_group`. Você deve chamar o tanto a `wait` ou `run_and_wait` método no objeto antes do destruidor em execução, a menos que o destruidor está sendo executado como resultado da pilha de desenrolamento devido a uma exceção.

```
~task_group();
```

### <a name="remarks"></a>Comentários

Se o destruidor for executado como o resultado da execução normal (por exemplo, não desenrolamento de pilha devido a uma exceção) e nem o `wait` nem `run_and_wait` métodos tiveram sido chamados, o destruidor pode lançar uma [missing_wait](missing-wait-class.md) exceção.

##  <a name="wait"></a> Aguarde

Aguarda até que todo o trabalho no `task_group` objeto foi concluída ou cancelado.

```
task_group_status wait();
```

### <a name="return-value"></a>Valor de retorno

Uma indicação de se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícito ou uma exceção é lançada de uma das suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).

### <a name="remarks"></a>Comentários

Observe que uma ou mais das tarefas agendadas para isso `task_group` objeto pode ser executada embutida no contexto de chamada.

Se uma ou mais das tarefas agendadas para isso `task_group` objeto gerou uma exceção, o tempo de execução selecionará um tal exceção de sua escolha e propagá-los de fora a chamada para o `wait` método.

Chamando `wait` em um `task_group` objeto, ele será redefinido para um estado limpo, onde ele possa ser reutilizado. Isso inclui o caso em que o `task_group` objeto foi cancelado.

No caminho de execução não excepcional, você tem uma exigência para chamar esse método qualquer ou o `run_and_wait` método antes do destruidor do `task_group` executa.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe structured_task_group](structured-task-group-class.md)<br/>
[Classe task_handle](task-handle-class.md)