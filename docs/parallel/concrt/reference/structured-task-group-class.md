---
title: Classe structured_task_group | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ppl/concurrency::structured_task_group
dev_langs:
- C++
helpviewer_keywords:
- structured_task_group class
ms.assetid: 742afa8c-c7b6-482c-b0ba-04c809927b22
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: ef20ff7fef8683cec4a3856c80c09846aa69a89a
ms.lasthandoff: 02/25/2017

---
# <a name="structuredtaskgroup-class"></a>Classe structured_task_group
O `structured_task_group` classe representa uma coleção altamente estruturada de trabalho paralelos. É possível enfileirar tarefas individuais em paralelo para uma `structured_task_group` usando `task_handle` objetos e aguarde a conclusão ou cancelar o grupo de tarefas antes de eles tem terminado a execução, que anulará as tarefas que não começaram a execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class structured_task_group;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor structured_task_group](#ctor)|Sobrecarregado. Constrói um novo `structured_task_group` objeto.|  
|[~ structured_task_group destruidor](#dtor)|Destrói um objeto `structured_task_group`. Você deve chamar o `wait` ou `run_and_wait` método no objeto antes de executar o destruidor, a menos que o destruidor está sendo executado como resultado de desenrolamento de pilha devido a uma exceção.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Cancel](#cancel)|Se esforça tentar cancelar a subárvore enraizada nesse grupo de tarefas de trabalho. Cada tarefa agendada no grupo de tarefas serão obter cancelada transitivamente se possível.|  
|[Método is_canceling](#is_canceling)|Informa o chamador se o grupo de tarefas está no meio de um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `structured_task_group` objeto (embora, certamente qualifica este método para retornar `true`). Ele pode ser o caso que a `structured_task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá através de `structured_task_group` objeto, `true` também será retornado.|  
|[o método Run](#run)|Sobrecarregado. Agenda uma tarefa no `structured_task_group` objeto. O chamador gerencia a vida útil do `task_handle` objeto passado a `_Task_handle` parâmetro. A versão que aceita o parâmetro `_Placement` faz com que a tarefa a ser mais adequado para a execução no local especificado pelo parâmetro.|  
|[Método run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa para ser executada embutido no contexto de chamada com o auxílio do `structured_task_group` objeto para suporte ao cancelamento completa. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto. A função, em seguida, aguarda até que todo o trabalho no `structured_task_group` objeto foi concluída ou cancelado.|  
|[Método Wait](#wait)|Aguarda até que todo o trabalho na `structured_task_group` foi concluída ou é cancelado.|  
  
## <a name="remarks"></a>Comentários  
 Há várias restrições severas colocado no uso de um `structured_task_group` objeto para obter um melhor desempenho:  
  
-   Um único `structured_task_group` objeto não pode ser usado por vários threads. Todas as operações em um `structured_task_group` objeto deve ser executado pelo thread que criou o objeto. As duas exceções a essa regra são as funções de membro `cancel` e `is_canceling`. O objeto pode não estar na lista de uma expressão lambda captura e ser usado em uma tarefa, a menos que a tarefa estiver usando uma das operações de cancelamento.  
  
-   Todas as tarefas agendadas para uma `structured_task_group` agendados por meio do uso do objeto `task_handle` objetos que você deve gerenciar explicitamente a vida útil do.  
  
-   Vários grupos só podem ser usados na ordem absolutamente aninhado. Se dois `structured_task_group` objetos são declarados, o outro está sendo declarado (aquele interna) deve destruct antes de qualquer método exceto `cancel` ou `is_canceling` é chamado no primeiro (aquele externa). Essa condição se aplica no caso de simplesmente declarar vários `structured_task_group` objetos dentro de escopos mesmo ou funcionalmente aninhados, bem como no caso de uma tarefa está na fila a `structured_task_group` por meio de `run` ou `run_and_wait` métodos.  
  
-   Diferentemente geral `task_group` classe, todos os estados de `structured_task_group` classe são finais. Depois de na fila de tarefas ao grupo e aguardou para que elas sejam concluídas, você não poderá usar o mesmo grupo novamente.  
  
 Para obter mais informações, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `structured_task_group`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namecancela-cancel"></a><a name="cancel"></a>Cancelar 

 Se esforça tentar cancelar a subárvore enraizada nesse grupo de tarefas de trabalho. Cada tarefa agendada no grupo de tarefas serão obter cancelada transitivamente se possível.  
  
```
void cancel();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).  
  
##  <a name="a-nameiscancelinga-iscanceling"></a><a name="is_canceling"></a>is_canceling 

 Informa o chamador se o grupo de tarefas está no meio de um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `structured_task_group` objeto (embora, certamente qualifica este método para retornar `true`). Ele pode ser o caso que a `structured_task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá através de `structured_task_group` objeto, `true` também será retornado.  
  
```
bool is_canceling();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se o `structured_task_group` objeto está no meio de um cancelamento (ou garantia em breve).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).  
  
##  <a name="a-nameruna-run"></a><a name="run"></a>executar 

 Agenda uma tarefa no `structured_task_group` objeto. O chamador gerencia a vida útil do `task_handle` objeto passado a `_Task_handle` parâmetro. A versão que aceita o parâmetro `_Placement` faz com que a tarefa a ser mais adequado para a execução no local especificado pelo parâmetro.  
  
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
 O tipo de objeto de função que será chamado para executar o corpo do identificador de tarefa.  
  
 `_Task_handle`  
 Um identificador para o trabalho agendado. Observe que o chamador tem a responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará a esperada live até que o `wait` ou `run_and_wait` método foi chamado neste `structured_task_group` objeto.  
  
 `_Placement`  
 Uma referência para o local em que a tarefa é representada pelo `_Task_handle` parâmetro deve ser executado.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução cria uma cópia da função de trabalho que você passa para esse método. As alterações de estado que ocorrem em um objeto de função que você passa para esse método não aparecerá na sua cópia desse objeto de função.  
  
 Se o `structured_task_group` destructs como resultado de desenrolamento da exceção da pilha, não é necessário garantir que uma chamada foi feita para o `wait` ou `run_and_wait` método. Nesse caso, o destruidor será adequadamente Cancelar e aguardar a tarefa representada pelo `_Task_handle` parâmetro para ser concluída.  
  
 Lança um [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) exceção se a tarefa manipular determinado pelo `_Task_handle` parâmetro já foi agendado para um objeto de grupo de tarefa por meio o `run` método e não houve nenhuma chamada intermediária para o `wait` ou `run_and_wait` método nesse grupo de tarefas.  
  
##  <a name="a-namerunandwaita-runandwait"></a><a name="run_and_wait"></a>run_and_wait 

 Agenda uma tarefa para ser executada embutido no contexto de chamada com o auxílio do `structured_task_group` objeto para suporte ao cancelamento completa. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto. A função, em seguida, aguarda até que todo o trabalho no `structured_task_group` objeto foi concluída ou cancelado.  
  
```
template<class _Function>
task_group_status run_and_wait(task_handle<_Function>& _Task_handle);

template<class _Function>
task_group_status run_and_wait(const _Function& _Func);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo de objeto de função que será chamado para executar a tarefa.  
  
 `_Task_handle`  
 Um identificador para a tarefa que será executado embutido no contexto de chamada. Observe que o chamador tem a responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará a esperada live até o `run_and_wait` método finaliza a execução.  
  
 `_Func`  
 Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser um lambda ou outro objeto que oferece suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícita ou uma exceção sendo lançada de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)  
  
### <a name="remarks"></a>Comentários  
 Observe que uma ou mais das tarefas agendadas para isso `structured_task_group` objeto pode executar embutido no contexto de chamada.  
  
 Se uma ou mais das tarefas agendadas para isso `structured_task_group` objeto lançará uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-la fora da chamada para o `run_and_wait` método.  
  
 Depois que essa função retorna, o `structured_task_group` objeto é considerado em um estado final e não deve ser usado. Observe que uso após o `run_and_wait` método retorna resultará em um comportamento indefinido.  
  
 O caminho não excepcional de execução, você tem uma exigência para chamar esse método qualquer ou o `wait` método antes do destruidor do `structured_task_group` executa.  
  
##  <a name="a-namectora-structuredtaskgroup"></a><a name="ctor"></a>structured_task_group 

 Constrói um novo `structured_task_group` objeto.  
  
```
structured_task_group();

structured_task_group(cancellation_token _CancellationToken);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_CancellationToken`  
 Um token de cancelamento para associar a esse grupo de tarefas estruturadas. O grupo de tarefas estruturadas será cancelado quando o token é cancelado.  
  
### <a name="remarks"></a>Comentários  
 O construtor que usa um token de cancelamento cria um `structured_task_group` que serão canceladas quando o código-fonte associado ao token é cancelada. Também fornecer um token de cancelamento explícita isola a esse grupo de tarefas estruturadas da participação em um cancelamento implícito de um grupo pai com um token diferente ou não.  
  
##  <a name="a-namedtora-structuredtaskgroup"></a><a name="dtor"></a>~ structured_task_group 

 Destrói um objeto `structured_task_group`. Você deve chamar o `wait` ou `run_and_wait` método no objeto antes de executar o destruidor, a menos que o destruidor está sendo executado como resultado de desenrolamento de pilha devido a uma exceção.  
  
```
~structured_task_group();
```  
  
### <a name="remarks"></a>Comentários  
 Se o destruidor é executado como resultado da execução normal (por exemplo, não desenrolamento da pilha devido a uma exceção) e não o `wait` nem `run_and_wait` métodos têm sido chamados, o destruidor pode lançar uma [missing_wait](missing-wait-class.md) exceção.  
  
##  <a name="a-namewaita-wait"></a><a name="wait"></a>Aguarde 

 Aguarda até que todo o trabalho na `structured_task_group` foi concluída ou é cancelado.  
  
```
task_group_status wait();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícita ou uma exceção sendo lançada de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md)  
  
### <a name="remarks"></a>Comentários  
 Observe que uma ou mais das tarefas agendadas para isso `structured_task_group` objeto pode executar embutido no contexto de chamada.  
  
 Se uma ou mais das tarefas agendadas para isso `structured_task_group` objeto lançará uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-la fora da chamada para o `wait` método.  
  
 Depois que essa função retorna, o `structured_task_group` objeto é considerado em um estado final e não deve ser usado. Observe que uso após o `wait` método retorna resultará em um comportamento indefinido.  
  
 O caminho não excepcional de execução, você tem uma exigência para chamar esse método qualquer ou o `run_and_wait` método antes do destruidor do `structured_task_group` executa.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe task_group](task-group-class.md)   
 [Classe task_handle](task-handle-class.md)

