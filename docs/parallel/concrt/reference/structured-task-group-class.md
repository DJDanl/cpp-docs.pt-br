---
title: Classe structured_task_group | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- structured_task_group
- PPL/concurrency::structured_task_group
- PPL/concurrency::structured_task_group::structured_task_group
- PPL/concurrency::structured_task_group::cancel
- PPL/concurrency::structured_task_group::is_canceling
- PPL/concurrency::structured_task_group::run
- PPL/concurrency::structured_task_group::run_and_wait
- PPL/concurrency::structured_task_group::wait
dev_langs:
- C++
helpviewer_keywords:
- structured_task_group class
ms.assetid: 742afa8c-c7b6-482c-b0ba-04c809927b22
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5cca5d20b89df97e27529d656e9a6553fd8a1820
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33694138"
---
# <a name="structuredtaskgroup-class"></a>Classe structured_task_group
O `structured_task_group` classe representa uma coleção altamente estruturada de trabalho paralelos. É possível enfileirar tarefas individuais em paralelo para uma `structured_task_group` usando `task_handle` objetos e aguarde até que elas sejam concluídas ou cancele o grupo de tarefas antes de eles terminarem de executar, que anulará as tarefas que não começaram a execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class structured_task_group;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[structured_task_group](#ctor)|Sobrecarregado. Constrói um novo objeto `structured_task_group`.|  
|[~ structured_task_group destruidor](#dtor)|Destrói um objeto `structured_task_group`. Você deve chamar o `wait` ou `run_and_wait` método no objeto antes de executar o destruidor, a menos que o destruidor está em execução como resultado de pilha desenrolamento devido a uma exceção.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[cancel](#cancel)|Se esforça tentativa de cancelar a subárvore de trabalho vinculado a este grupo de tarefas. Todas as tarefas agendadas no grupo de tarefas serão obter cancelada transitivamente se possível.|  
|[is_canceling](#is_canceling)|Informa o chamador se o grupo de tarefas está em meio a um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `structured_task_group` objeto (embora, certamente qualifica este método para retornar `true`). Ele pode ser o caso que a `structured_task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá por isso `structured_task_group` objeto, `true` também será retornado.|  
|[run](#run)|Sobrecarregado. Agenda uma tarefa no `structured_task_group` objeto. O chamador gerencia o tempo de vida do `task_handle` objeto passado a `_Task_handle` parâmetro. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado por esse parâmetro.|  
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa para ser executado embutido no contexto de chamada com a assistência de `structured_task_group` objeto para suporte ao cancelamento completo. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar o tempo de vida de `task_handle` objeto. A função, em seguida, aguarda até que todos eles funcionam no `structured_task_group` objeto concluída ou cancelado.|  
|[wait](#wait)|Aguarda até que todos eles funcionam no `structured_task_group` foi concluído ou foi cancelada.|  
  
## <a name="remarks"></a>Comentários  
 Há várias restrições severas colocado no uso de um `structured_task_group` objeto para obter um melhor desempenho:  
  
-   Um único `structured_task_group` objeto não pode ser usado por vários threads. Todas as operações em um `structured_task_group` objeto deve ser executado pelo thread que criou o objeto. As duas exceções a essa regra são as funções de membro `cancel` e `is_canceling`. O objeto não pode estar na lista de captura de uma expressão lambda e ser usado em uma tarefa, a menos que a tarefa estiver usando uma das operações de cancelamento.  
  
-   Todas as tarefas agendadas para uma `structured_task_group` objeto são agendados por meio do uso de `task_handle` objetos que você deve gerenciar explicitamente a vida útil do.  
  
-   Vários grupos só podem ser usados na ordem absolutamente aninhada. Se dois `structured_task_group` objetos são declarados, o outro está sendo declarado (aquele interna) deve destruct antes de qualquer método exceto `cancel` ou `is_canceling` é chamado no primeiro (aquele externa). Esta condição for verdadeira no caso de simplesmente declarar vários `structured_task_group` objetos dentro de escopos mesmo ou funcionalmente aninhados, bem como no caso de uma tarefa que foi enfileirada para o `structured_task_group` por meio de `run` ou `run_and_wait` métodos.  
  
-   Ao contrário de gerais `task_group` classe, todos os estados no `structured_task_group` classe são finais. Depois que foram colocadas em fila o grupo de tarefas e aguardaram para que elas sejam concluídas, você não poderá usar o mesmo grupo novamente.  
  
 Para obter mais informações, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `structured_task_group`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="cancel"></a> Cancelar 

 Se esforça tentativa de cancelar a subárvore de trabalho vinculado a este grupo de tarefas. Todas as tarefas agendadas no grupo de tarefas serão obter cancelada transitivamente se possível.  
  
```
void cancel();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).  
  
##  <a name="is_canceling"></a> is_canceling 

 Informa o chamador se o grupo de tarefas está em meio a um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `structured_task_group` objeto (embora, certamente qualifica este método para retornar `true`). Ele pode ser o caso que a `structured_task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá por isso `structured_task_group` objeto, `true` também será retornado.  
  
```
bool is_canceling();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma indicação se o `structured_task_group` objeto está em meio a um cancelamento (ou é a garantia de estar em breve).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).  
  
##  <a name="run"></a> Executar 

 Agenda uma tarefa no `structured_task_group` objeto. O chamador gerencia o tempo de vida do `task_handle` objeto passado a `_Task_handle` parâmetro. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado por esse parâmetro.  
  
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
 `_Function`  
 O tipo do objeto de função que será chamado para executar o corpo do identificador de tarefa.  
  
 `_Task_handle`  
 Um identificador para o trabalho agendado. Observe que o chamador tem a responsabilidade pelo tempo de vida do objeto. O tempo de execução continuarão a esperar que ele live até que o `wait` ou `run_and_wait` método foi chamado neste `structured_task_group` objeto.  
  
 `_Placement`  
 Uma referência para o local em que a tarefa é representada pelo `_Task_handle` parâmetro deve ser executado.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução cria uma cópia da função de trabalho que você passar para este método. Qualquer alteração de estado que ocorrem em um objeto de função que você passa para este método não aparecerá na sua cópia do objeto de função.  
  
 Se o `structured_task_group` destructs como resultado da pilha de desenrolamento da exceção, não é necessário garantir que uma chamada foi feita para o `wait` ou `run_and_wait` método. Nesse caso, o destruidor adequadamente cancelará e aguarde até que a tarefa representada pelo `_Task_handle` parâmetro para ser concluída.  
  
 Gera um [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) exceção se a tarefa de manipular fornecida pelo `_Task_handle` parâmetro já foi agendado para um objeto de grupo de tarefas por meio de `run` método e não houve nenhuma chamada intermediária para tanto o `wait` ou `run_and_wait` método nesse grupo de tarefas.  
  
##  <a name="run_and_wait"></a> run_and_wait 

 Agenda uma tarefa para ser executado embutido no contexto de chamada com a assistência de `structured_task_group` objeto para suporte ao cancelamento completo. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar o tempo de vida de `task_handle` objeto. A função, em seguida, aguarda até que todos eles funcionam no `structured_task_group` objeto concluída ou cancelado.  
  
```
template<class _Function>
task_group_status run_and_wait(task_handle<_Function>& _Task_handle);

template<class _Function>
task_group_status run_and_wait(const _Function& _Func);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo do objeto de função que será chamado para executar a tarefa.  
  
 `_Task_handle`  
 Um identificador para a tarefa que executará embutido no contexto do chamador. Observe que o chamador tem a responsabilidade pelo tempo de vida do objeto. O tempo de execução continuarão a esperar que ele live até o `run_and_wait` método conclui a execução.  
  
 `_Func`  
 Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícita ou uma exceção sendo lançada de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)  
  
### <a name="remarks"></a>Comentários  
 Observe que um ou mais das tarefas agendadas para isso `structured_task_group` objeto pode ser executada embutido no contexto do chamador.  
  
 Se uma ou mais das tarefas agendadas para isso `structured_task_group` objeto gerou uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-lo sem a chamada para o `run_and_wait` método.  
  
 Depois que essa função retorna, o `structured_task_group` é considerado em um estado final de objeto e não deve ser usado. Observe que utilização após a `run_and_wait` método retorna resultará em um comportamento indefinido.  
  
 No caminho de execução do não excepcional, você tem uma exigência para chamar esse método ou ou o `wait` método antes do destruidor do `structured_task_group` executa.  
  
##  <a name="ctor"></a> structured_task_group 

 Constrói um novo objeto `structured_task_group`.  
  
```
structured_task_group();

structured_task_group(cancellation_token _CancellationToken);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_CancellationToken`  
 Um token de cancelamento para associar a este grupo de tarefas estruturadas. O grupo de tarefas estruturadas será cancelado quando o token é cancelado.  
  
### <a name="remarks"></a>Comentários  
 O construtor que usa um token de cancelamento cria um `structured_task_group` que será cancelada quando a fonte associada ao token é cancelada. Também fornecer um token de cancelamento explícita isola a esse grupo de tarefas estruturadas da participação em um cancelamento implícita de um grupo pai com um token diferente ou não.  
  
##  <a name="dtor"></a> ~ structured_task_group 

 Destrói um objeto `structured_task_group`. Você deve chamar o `wait` ou `run_and_wait` método no objeto antes de executar o destruidor, a menos que o destruidor está em execução como resultado de pilha desenrolamento devido a uma exceção.  
  
```
~structured_task_group();
```  
  
### <a name="remarks"></a>Comentários  
 Se o destruidor é executado como o resultado de execução normal (por exemplo, não desenrolamento da pilha devido a uma exceção) e não o `wait` nem `run_and_wait` métodos tem sido chamados, o destruidor pode gerar um [missing_wait](missing-wait-class.md) exceção.  
  
##  <a name="wait"></a> Aguarde 

 Aguarda até que todos eles funcionam no `structured_task_group` foi concluído ou foi cancelada.  
  
```
task_group_status wait();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícita ou uma exceção sendo lançada de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)  
  
### <a name="remarks"></a>Comentários  
 Observe que um ou mais das tarefas agendadas para isso `structured_task_group` objeto pode ser executada embutido no contexto do chamador.  
  
 Se uma ou mais das tarefas agendadas para isso `structured_task_group` objeto gerou uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-lo sem a chamada para o `wait` método.  
  
 Depois que essa função retorna, o `structured_task_group` é considerado em um estado final de objeto e não deve ser usado. Observe que utilização após a `wait` método retorna resultará em um comportamento indefinido.  
  
 No caminho de execução do não excepcional, você tem uma exigência para chamar esse método ou ou o `run_and_wait` método antes do destruidor do `structured_task_group` executa.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe task_group](task-group-class.md)   
 [Classe task_handle](task-handle-class.md)
