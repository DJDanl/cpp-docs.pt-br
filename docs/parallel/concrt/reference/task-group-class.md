O `task_group` classe representa uma coleção de trabalho paralela que pode ser aguardado ou cancelada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class task_group;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[task_group](#ctor)|Sobrecarregado. Constrói um novo objeto `task_group`.|  
|[~ task_group destruidor](#dtor)|Destrói um objeto `task_group`. Você deve chamar o tanto o `wait` ou `run_and_wait` método no objeto antes do destruidor executar, a menos que o destruidor está em execução como resultado de desenrolamento devido a uma exceção da pilha.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[cancel](#cancel)|Se esforça tentativa de cancelar a subárvore de trabalho vinculado a este grupo de tarefas. Todas as tarefas agendadas no grupo de tarefas serão obter cancelada transitivamente se possível.|  
|[is_canceling](#is_canceling)|Informa o chamador se o grupo de tarefas está em meio a um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `task_group` objeto (embora, certamente qualifica este método para retornar `true`). Ele pode ser o caso que a `task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá por isso `task_group` objeto, `true` também será retornado.|  
|[run](#run)|Sobrecarregado. Agenda uma tarefa no `task_group` objeto. Se um `task_handle` objeto é passado como um parâmetro para `run`, o chamador é responsável por gerenciar o tempo de vida de `task_handle` objeto. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve a alocação de heap em tempo de execução que pode ser um desempenho inferior que usar a versão que usa uma referência a um `task_handle` objeto. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado por esse parâmetro.|  
|[run_and_wait](#run_and_wait)|Sobrecarregado. Agenda uma tarefa para ser executado embutido no contexto de chamada com a assistência de `task_group` objeto para suporte ao cancelamento completo. A função, em seguida, aguarda até que todos eles funcionam no `task_group` objeto concluída ou cancelado. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar o tempo de vida de `task_handle` objeto.|  
|[wait](#wait)|Aguarda até que todos eles funcionam no `task_group` objeto concluída ou cancelado.|  
  
## <a name="remarks"></a>Comentários  
 Ao contrário de altamente restrita `structured_task_group` classe, o `task_group` classe é muito mais geral construção. Ele não tem qualquer as restrições descritas por [structured_task_group](structured-task-group-class.md). `task_group` objetos com segurança podem ser usados entre threads e utilizados de formas de forma livre. A desvantagem do `task_group` construção é que ele não pode executar, bem como a `structured_task_group` construir para tarefas que executam pequenas quantidades de trabalho.  
  
 Para obter mais informações, consulte [paralelismo de tarefa](../task-parallelism-concurrency-runtime.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `task_group`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="cancel"></a> Cancelar 

 Se esforça tentativa de cancelar a subárvore de trabalho vinculado a este grupo de tarefas. Todas as tarefas agendadas no grupo de tarefas serão obter cancelada transitivamente se possível.  
  
```  
void cancel();  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).  
  
##  <a name="is_canceling"></a> is_canceling 

 Informa o chamador se o grupo de tarefas está em meio a um cancelamento. Isso não indica necessariamente que o `cancel` método foi chamado no `task_group` objeto (embora, certamente qualifica este método para retornar `true`). Ele pode ser o caso que a `task_group` objeto está em execução em linha e um grupo de tarefas para cima na árvore de trabalho foi cancelado. Em casos como esses onde o tempo de execução pode determinar antecipadamente que cancelamento fluirá por isso `task_group` objeto, `true` também será retornado.  
  
```  
bool is_canceling();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma indicação se o `task_group` objeto está em meio a um cancelamento (ou é a garantia de estar em breve).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../cancellation-in-the-ppl.md).  
  
##  <a name="run"></a> Executar 

 Agenda uma tarefa no `task_group` objeto. Se um `task_handle` objeto é passado como um parâmetro para `run`, o chamador é responsável por gerenciar o tempo de vida de `task_handle` objeto. A versão do método que usa uma referência a um objeto de função como um parâmetro envolve a alocação de heap em tempo de execução que pode ser um desempenho inferior que usar a versão que usa uma referência a um `task_handle` objeto. A versão que usa o parâmetro `_Placement` faz com que a tarefa ser mais adequado para a execução no local especificado por esse parâmetro.  
  
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
 O tipo do objeto de função que será chamado para executar o corpo do identificador de tarefa.  
  
 `_Func`  
 Uma função que será chamada para invocar o corpo da tarefa. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
 `_Placement`  
 Uma referência para o local em que a tarefa é representada pelo `_Func` parâmetro deve ser executado.  
  
 `_Task_handle`  
 Um identificador para o trabalho agendado. Observe que o chamador tem a responsabilidade pelo tempo de vida do objeto. O tempo de execução continuarão a esperar que ele live até que o `wait` ou `run_and_wait` método foi chamado neste `task_group` objeto.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução agenda a função de trabalho fornecida para ser executado em um momento posterior, o que pode ser depois retorna a função de chamada. Esse método usa um [task_handle](task-handle-class.md) objeto para manter uma cópia da função de trabalho fornecida. Portanto, qualquer alteração de estado que ocorrem em um objeto de função que você passa para este método não aparecerá na sua cópia do objeto de função. Além disso, certifique-se de que o tempo de vida de todos os objetos que você passe por ponteiro ou referência para a função de trabalho permanecem válido até que a função de trabalho retorna.  
  
 Se o `task_group` destructs como resultado da pilha de desenrolamento da exceção, não é necessário garantir que uma chamada foi feita para o `wait` ou `run_and_wait` método. Nesse caso, o destruidor adequadamente cancelará e aguarde até que a tarefa representada pelo `_Task_handle` parâmetro para ser concluída.  
  
 O método gera uma [invalid_multiple_scheduling](invalid-multiple-scheduling-class.md) exceção se a tarefa de manipular fornecida pelo `_Task_handle` parâmetro já foi agendado para um objeto de grupo de tarefas por meio do `run` método e houve nenhum interrupção de chamada como o `wait` ou `run_and_wait` método nesse grupo de tarefas.  
  
##  <a name="run_and_wait"></a> run_and_wait 

 Agenda uma tarefa para ser executado embutido no contexto de chamada com a assistência de `task_group` objeto para suporte ao cancelamento completo. A função, em seguida, aguarda até que todos eles funcionam no `task_group` objeto concluída ou cancelado. Se um `task_handle` objeto é passado como um parâmetro para `run_and_wait`, o chamador é responsável por gerenciar o tempo de vida de `task_handle` objeto.  
  
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
 O tipo do objeto de função que será chamado para executar o corpo da tarefa.  
  
 `_Task_handle`  
 Um identificador para a tarefa que executará embutido no contexto do chamador. Observe que o chamador tem a responsabilidade pelo tempo de vida do objeto. O tempo de execução continuarão a esperar que ele live até o `run_and_wait` método conclui a execução.  
  
 `_Func`  
 Uma função que será chamada para invocar o corpo do trabalho. Isso pode ser uma expressão lambda ou outro objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícita ou uma exceção sendo lançada de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).  

  
### <a name="remarks"></a>Comentários  
 Observe que um ou mais das tarefas agendadas para isso `task_group` objeto pode ser executada embutido no contexto do chamador.  
  
 Se uma ou mais das tarefas agendadas para isso `task_group` objeto gerou uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-lo sem a chamada para o `run_and_wait` método.  
  
 Após o retorno do `run_and_wait` método em um `task_group` do objeto, o tempo de execução redefine o objeto para um estado limpo, onde ele pode ser reutilizado. Isso inclui o caso em que o `task_group` objeto foi cancelado.  
  
 No caminho de execução do não excepcional, você tem uma exigência para chamar esse método ou ou o `wait` método antes do destruidor do `task_group` executa.  
  
##  <a name="ctor"></a> task_group 

 Constrói um novo objeto `task_group`.  
  
```  
task_group();  
  
task_group(  
   cancellation_token _CancellationToken  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_CancellationToken`  
 Um token de cancelamento para associar a este grupo de tarefas. O grupo de tarefas será cancelado quando o token é cancelado.  
  
### <a name="remarks"></a>Comentários  
 O construtor que usa um token de cancelamento cria um `task_group` que será cancelada quando a fonte associada ao token é cancelada. Também fornecer um token de cancelamento explícita isola a esse grupo de tarefas da participação em um cancelamento implícita de um grupo pai com um token diferente ou nenhuma.  
  
##  <a name="dtor"></a> ~ task_group 

 Destrói um objeto `task_group`. Você deve chamar o tanto o `wait` ou `run_and_wait` método no objeto antes do destruidor executar, a menos que o destruidor está em execução como resultado de desenrolamento devido a uma exceção da pilha.  
  
```  
~task_group();  
```  
  
### <a name="remarks"></a>Comentários  
 Se o destruidor é executado como o resultado de execução normal (por exemplo, não desenrolamento da pilha devido a uma exceção) e não o `wait` nem `run_and_wait` métodos tem sido chamados, o destruidor pode gerar um [missing_wait](missing-wait-class.md) exceção.  
  
##  <a name="wait"></a> Aguarde 

 Aguarda até que todos eles funcionam no `task_group` objeto concluída ou cancelado.  
  
```  
task_group_status wait();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Indica se a espera foi atendida ou o grupo de tarefas foi cancelado, devido a uma operação de cancelamento explícita ou uma exceção sendo lançada de uma de suas tarefas. Para obter mais informações, consulte [task_group_status](concurrency-namespace-enums.md#task_group_status).  

  
### <a name="remarks"></a>Comentários  
 Observe que um ou mais das tarefas agendadas para isso `task_group` objeto pode ser executada embutido no contexto do chamador.  
  
 Se uma ou mais das tarefas agendadas para isso `task_group` objeto gerou uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-lo sem a chamada para o `wait` método.  
  
 Chamando `wait` em uma `task_group` objeto, ele será redefinido para um estado limpo, onde ele pode ser reutilizado. Isso inclui o caso em que o `task_group` objeto foi cancelado.  
  
 No caminho de execução do não excepcional, você tem uma exigência para chamar esse método ou ou o `run_and_wait` método antes do destruidor do `task_group` executa.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe structured_task_group](structured-task-group-class.md)   
 [Classe task_handle](task-handle-class.md)