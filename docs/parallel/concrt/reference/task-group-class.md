O `task_group` classe representa uma coleção de trabalho paralelo que pode ser cancelada ou aguardada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class task_group;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[task_group](#ctor)|Sobrecarregado. Constrói um novo `task_group` objeto.|  
|[~ task_group destruidor](#dtor)|Destrói um objeto `task_group`. Você deve chamar o o `wait` ou `run_and_wait` método no objeto antes do destruidor está sendo executado, a menos que o destruidor está sendo executado como resultado de desenrolamento devido a uma exceção da pilha.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Cancelar](#cancel)|Se esforça tentar cancelar a subárvore enraizada nesse grupo de tarefas de trabalho. Cada tarefa agendada no grupo de tarefas serão obter cancelada transitivamente se possível.|  
|[is_canceling](#is_canceling)|Informa o chamador se o grupo de tarefas está no meio de um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `task_group` objeto (embora, certamente qualifica este método para retornar `true`). Ele pode ser o caso que a `task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá através de `task_group` objeto, `true` também será retornado.|  
|[run](#run)|Sobrecarregado. Agenda uma tarefa no `task_group` objeto. Se um `task_handle` objeto é passado como um parâmetro para `run`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve a alocação de heap dentro do runtime que pode ser executar menos bem que usar a versão que pega uma referência para um `task_handle` objeto. A versão que aceita o parâmetro `_Placement` faz com que a tarefa a ser mais adequado para a execução no local especificado pelo parâmetro.|  
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa para ser executada embutido no contexto de chamada com o auxílio do `task_group` objeto para suporte ao cancelamento completa. A função, em seguida, aguarda até que todo o trabalho no `task_group` objeto foi concluída ou cancelado. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto.|  
|[Aguarde](#wait)|Aguarda até que todo o trabalho no `task_group` objeto foi concluída ou cancelado.|  
  
## <a name="remarks"></a>Comentários  
 Ao contrário de altamente restrita `structured_task_group` classe, a `task_group` classe é construir muito mais geral. Ele não tem qualquer as restrições descritas por [structured_task_group](structured-task-group-class.md). `task_group`objetos com segurança podem ser usados em threads e utilizados de formas de forma livre. A desvantagem de `task_group` construção é que ele pode não executar, bem como a `structured_task_group` construir para tarefas que executam pequenas quantidades de trabalho.  
  
 Para obter mais informações, consulte [paralelismo de tarefa](../task-parallelism-concurrency-runtime.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `task_group`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="cancel"></a>Cancelar 

 Se esforça tentar cancelar a subárvore enraizada nesse grupo de tarefas de trabalho. Cada tarefa agendada no grupo de tarefas serão obter cancelada transitivamente se possível.  
  
```  
void cancel();  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).  
  
##  <a name="is_canceling"></a>is_canceling 

 Informa o chamador se o grupo de tarefas está no meio de um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `task_group` objeto (embora, certamente qualifica este método para retornar `true`). Ele pode ser o caso que a `task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá através de `task_group` objeto, `true` também será retornado.  
  
```  
bool is_canceling();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se o `task_group` objeto está no meio de um cancelamento (ou garantia em breve).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).  
  
##  <a name="run"></a>executar 

 Agenda uma tarefa no `task_group` objeto. Se um `task_handle` objeto é passado como um parâmetro para `run`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve a alocação de heap dentro do runtime que pode ser executar menos bem que usar a versão que pega uma referência para um `task_handle` objeto. A versão que aceita o parâmetro `_Placement` faz com que a tarefa a ser mais adequado para a execução no local especificado pelo parâmetro.  
  
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
 `_Function`  
 O tipo de objeto de função que será chamado para executar o corpo do identificador de tarefa.  
  
 `_Func`  
 Uma função que será chamada para invocar o corpo da tarefa. Isso pode ser uma expressão lambda ou outro objeto que oferece suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
 `_Placement`  
 Uma referência para o local em que a tarefa é representada pelo `_Func` parâmetro deve ser executado.  
  
 `_Task_handle`  
 Um identificador para o trabalho agendado. Observe que o chamador tem a responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará a esperada live até que o `wait` ou `run_and_wait` método foi chamado neste `task_group` objeto.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução para programar a função de trabalho fornecida para ser executado em um momento posterior, que pode ser depois que a função de chamada retorna. Esse método usa um [task_handle](task-handle-class.md) objeto para manter uma cópia da função de trabalho fornecida. Portanto, qualquer alteração de estado que ocorrem em um objeto de função que você passa para esse método não aparecerá na sua cópia desse objeto de função. Além disso, certifique-se de que o tempo de vida de todos os objetos que você passa o ponteiro ou referência à função de trabalho permanecem válido até que a função de trabalho retorna.  
  
 Se o `task_group` destructs como resultado de desenrolamento da exceção da pilha, não é necessário garantir que uma chamada foi feita para o `wait` ou `run_and_wait` método. Nesse caso, o destruidor será adequadamente Cancelar e aguardar a tarefa representada pelo `_Task_handle` parâmetro para ser concluída.  
  
 O método lança um [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) exceção se a tarefa manipular determinado pelo `_Task_handle` parâmetro já foi agendado para um objeto de grupo de tarefa por meio o `run` método e não houve nenhuma chamada intermediária para o `wait` ou `run_and_wait` método nesse grupo de tarefas.  
  
##  <a name="run_and_wait"></a>run_and_wait 

 Agenda uma tarefa para ser executada embutido no contexto de chamada com o auxílio do `task_group` objeto para suporte ao cancelamento completa. A função, em seguida, aguarda até que todo o trabalho no `task_group` objeto foi concluída ou cancelado. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar a vida útil do `task_handle` objeto.  
  
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
 `_Function`  
 O tipo de objeto de função que será chamado para executar o corpo da tarefa.  
  
 `_Task_handle`  
 Um identificador para a tarefa que será executado embutido no contexto de chamada. Observe que o chamador tem a responsabilidade pelo tempo de vida desse objeto. O tempo de execução continuará a esperada live até o `run_and_wait` método finaliza a execução.  
  
 `_Func`  
 Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser uma expressão lambda ou outro objeto que oferece suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícita ou uma exceção sendo lançada de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).  

  
### <a name="remarks"></a>Comentários  
 Observe que uma ou mais das tarefas agendadas para isso `task_group` objeto pode executar embutido no contexto de chamada.  
  
 Se uma ou mais das tarefas agendadas para isso `task_group` objeto lançará uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-la fora da chamada para o `run_and_wait` método.  
  
 Após retornar no `run_and_wait` método em um `task_group` do objeto, o tempo de execução redefine o objeto para um estado limpo, onde ele pode ser reutilizado. Isso inclui o caso em que o `task_group` objeto foi cancelado.  
  
 O caminho não excepcional de execução, você tem uma exigência para chamar esse método qualquer ou o `wait` método antes do destruidor do `task_group` executa.  
  
##  <a name="ctor"></a>task_group 

 Constrói um novo `task_group` objeto.  
  
```  
task_group();  
  
task_group(  
   cancellation_token _CancellationToken  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_CancellationToken`  
 Um token de cancelamento para associar a esse grupo de tarefas. O grupo de tarefas será cancelado quando o token é cancelado.  
  
### <a name="remarks"></a>Comentários  
 O construtor que usa um token de cancelamento cria um `task_group` que serão canceladas quando o código-fonte associado ao token é cancelada. Também fornecer um token de cancelamento explícita isola a esse grupo de tarefa da participação em um cancelamento implícito de um grupo pai com um token diferente ou não.  
  
##  <a name="dtor"></a>~ task_group 

 Destrói um objeto `task_group`. Você deve chamar o o `wait` ou `run_and_wait` método no objeto antes do destruidor está sendo executado, a menos que o destruidor está sendo executado como resultado de desenrolamento devido a uma exceção da pilha.  
  
```  
~task_group();  
```  
  
### <a name="remarks"></a>Comentários  
 Se o destruidor é executado como resultado da execução normal (por exemplo, não desenrolamento da pilha devido a uma exceção) e não o `wait` nem `run_and_wait` métodos têm sido chamados, o destruidor pode lançar uma [missing_wait](missing-wait-class.md) exceção.  
  
##  <a name="wait"></a>Aguarde 

 Aguarda até que todo o trabalho no `task_group` objeto foi concluída ou cancelado.  
  
```  
task_group_status wait();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícita ou uma exceção sendo lançada de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).  

  
### <a name="remarks"></a>Comentários  
 Observe que uma ou mais das tarefas agendadas para isso `task_group` objeto pode executar embutido no contexto de chamada.  
  
 Se uma ou mais das tarefas agendadas para isso `task_group` objeto lançará uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-la fora da chamada para o `wait` método.  
  
 Chamando `wait` em uma `task_group` objeto, ele será redefinido para um estado limpo, onde ele pode ser reutilizado. Isso inclui o caso em que o `task_group` objeto foi cancelado.  
  
 O caminho não excepcional de execução, você tem uma exigência para chamar esse método qualquer ou o `run_and_wait` método antes do destruidor do `task_group` executa.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe structured_task_group](structured-task-group-class.md)   
 [Classe task_handle](task-handle-class.md)