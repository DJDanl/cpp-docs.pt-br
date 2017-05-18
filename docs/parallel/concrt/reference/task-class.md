---
title: "tarefa de classe (tempo de execução de simultaneidade) | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- task
- PPLTASKS/concurrency::task
- PPLTASKS/concurrency::task::task
- PPLTASKS/concurrency::task::get
- PPLTASKS/concurrency::task::is_apartment_aware
- PPLTASKS/concurrency::task::is_done
- PPLTASKS/concurrency::task::scheduler
- PPLTASKS/concurrency::task::then
- PPLTASKS/concurrency::task::wait
dev_langs:
- C++
helpviewer_keywords:
- task class
ms.assetid: cdc3a8c0-5cbe-45a0-b5d5-e9f81d94df1a
caps.latest.revision: 12
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: e6c568b0b6a5f07df51980e1e440f31482f45846
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="task-class-concurrency-runtime"></a>Classe task (Tempo de Execução de Simultaneidade)
A classe `task` da Biblioteca de Padrões Paralelos (PPL). O objeto `task` representa o trabalho que pode ser executado de forma assíncrona e simultaneamente com outras tarefas e o trabalho paralelo produzido por algoritmos paralelos no Tempo de execução de simultaneidade. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Também podem ser composto com outras tarefas usando continuações ( `then`) e a associação ( `when_all`) e a opção ( `when_any`) padrões.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T>
class task;

template <>
class task<void>;

template<typename _ReturnType>
class task;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 `T`  
 `_ReturnType`  
 O tipo de resultado desta tarefa.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`result_type`|O tipo do resultado que um objeto desta classe produz.|  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[tarefa](#ctor)|Sobrecarregado. Constrói um objeto `task`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get](#get)|Sobrecarregado. Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.|  
|[is_apartment_aware](#is_apartment_aware)|Determina se a tarefa desvincula uma interface de Tempo de execução do Windows `IAsyncInfo` ou se é descendente de tal tarefa.|  
|[is_done](#is_done)|Determina se a tarefa foi concluída.|  
|[Agendador](#scheduler)|Retorna o agendador para essa tarefa|  
|[em seguida](#then)|Sobrecarregado. Adiciona uma tarefa de continuação para essa tarefa.|  
|[Aguarde](#wait)|Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.|  
  
### <a name="public-operators"></a>Operadores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator!=](#operator_neq)|Sobrecarregado. Determina se dois objetos `task` representam tarefas internas diferentes.|  
|[operator=](#operator_eq)|Sobrecarregado. Substitui o conteúdo de um objeto `task` por outro.|  
|[operator==](#operator_eq_eq)|Sobrecarregado. Determina se dois objetos `task` representam a mesma tarefa interna.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `task`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppltasks.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="get"></a>Obter 

 Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.  
  
```
_ReturnType get() const;

void get() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado da tarefa.  
  
### <a name="remarks"></a>Comentários  
 Se a tarefa for cancelada, uma chamada para `get` lançará um [task_canceled](task-canceled-class.md) exceção. Se a tarefa encontrou uma exceção diferente ou uma exceção é propagada a ele de um antecessor tarefa, uma chamada para `get` gerará essa exceção.  
  
> [!IMPORTANT]
>  Em um [!INCLUDE[win8_appname_long](../../../build/includes/win8_appname_long_md.md)] aplicativo, não chame [concurrency::task::wait](#wait) ou `get` ( `wait` chamadas `get`) no código que é executado sobre o STA. Caso contrário, o tempo de execução lança [concurrency::invalid_operation](invalid-operation-class.md) porque esses métodos bloquear o thread atual e pode fazer com que o aplicativo pare de responder. No entanto, você pode chamar o `get` método para receber o resultado da tarefa antecedente em uma continuação baseado em tarefa, porque o resultado fica imediatamente disponível.  
  
##  <a name="is_apartment_aware"></a>is_apartment_aware 

 Determina se a tarefa desvincula uma interface de Tempo de execução do Windows `IAsyncInfo` ou se é descendente de tal tarefa.  
  
```
bool is_apartment_aware() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a tarefa desvincula uma `IAsyncInfo` interface ou descendentes de tarefa, `false` caso contrário.  
  
##  <a name="is_done"></a>Task:: is_done (tempo de execução de simultaneidade) do método  
 Determina se a tarefa foi concluída.  
  
```
bool is_done() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 True se a tarefa for concluída, FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 A função retornará true se a tarefa é concluída ou cancelada (com ou sem exceção do usuário).  
  
##  <a name="operator_neq"></a>operador! = 

 Determina se dois objetos `task` representam tarefas internas diferentes.  
  
```
bool operator!= (const task<_ReturnType>& _Rhs) const;

bool operator!= (const task<void>& _Rhs) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se os objetos se referem a diferentes tarefas subjacentes, e `false` caso contrário.  
  
##  <a name="operator_eq"></a>operador = 

 Substitui o conteúdo de um objeto `task` por outro.  
  
```
task& operator= (const task& _Other);

task& operator= (task&& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 A fonte `task` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Como `task` comporta-se como um ponteiro inteligente, depois de uma atribuição de cópia, isso `task` objetos representa a mesma tarefa real como `_Other` does.  
  
##  <a name="operator_eq_eq"></a>operador = = 

 Determina se dois objetos `task` representam a mesma tarefa interna.  
  
```
bool operator== (const task<_ReturnType>& _Rhs) const;

bool operator== (const task<void>& _Rhs) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se os objetos se referir à mesma tarefa subjacente, e `false` caso contrário.  
  
##  <a name="scheduler"></a>Task:: Scheduler (tempo de execução de simultaneidade) do método  
 Retorna o agendador para essa tarefa  
  
```
scheduler_ptr scheduler() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o Agendador  
  
##  <a name="ctor"></a>tarefa 

 Constrói um objeto `task`.  
  
```
task();

template<typename T>
__declspec(
    noinline) explicit task(T _Param);

template<typename T>
__declspec(
    noinline) explicit task(T _Param, const task_options& _TaskOptions);

task(
    const task& _Other);

task(
    task&& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do parâmetro do qual a tarefa é a ser criada.  
  
 `_Param`  
 O parâmetro do qual a tarefa é a ser criada. Isso pode ser uma lambda, um objeto de função, um `task_completion_event<result_type>` objeto ou um Windows::Foundation::IAsyncInfo se você estiver usando tarefas em seu aplicativo da Windows Store. O objeto de lambda ou função deve ser um tipo equivalente a `std::function<X(void)>`, onde X pode ser uma variável do tipo `result_type`, `task<result_type>`, ou um Windows::Foundation::IAsyncInfo em aplicativos da Windows Store.  
  
 `_TaskOptions`  
 As opções de tarefa incluem Agendador de token de cancelamento etc  
  
 `_Other`  
 A fonte `task` objeto.  
  
### <a name="remarks"></a>Comentários  
 O construtor padrão para um `task` só está presente para permitir que tarefas a serem usadas dentro de contêineres. Uma tarefa padrão criada não pode ser usada até que você atribua uma tarefa válida a ele. Métodos como `get`, `wait` ou `then` lançará um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção quando chamado em uma tarefa padrão construído.  
  
 Uma tarefa criada a partir de um `task_completion_event` será concluída (e terá as continuações agendadas) quando o evento de conclusão de tarefas é definido.  
  
 A versão do construtor que usa um token de cancelamento cria uma tarefa que pode ser cancelada usando o `cancellation_token_source` o token foi obtido. Tarefas criadas sem um token de cancelamento não serão canceláveis.  
  
 Tarefas criadas a partir um `Windows::Foundation::IAsyncInfo` interface ou um lambda que retorna um `IAsyncInfo` interface alcançar seu estado terminal quando a operação assíncrona de tempo de execução do Windows incluído ou a ação é concluída. Da mesma forma, as tarefas criadas a partir uma lambda que retorna um `task<result_type>` atingir seu estado terminal quando a tarefa interna atinge seu estado terminal, e não quando a lambda retorna.  
  
 `task`se comporta como um ponteiro inteligente e é seguro passar por valor. Ele pode ser acessado por vários threads sem a necessidade de bloqueios.  
  
 As sobrecargas de construtor que obtêm uma interface Windows::Foundation::IAsyncInfo ou uma lambda retornando interface, só estão disponíveis para aplicativos da Windows Store.  
  
 Para obter mais informações, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
##  <a name="then"></a>em seguida 

 Adiciona uma tarefa de continuação para essa tarefa.  
  
```
template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func) const -> typename details::_ContinuationTypeTraits<_Function,
    _ReturnType>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    const task_options& _TaskOptions) const -> typename details::_ContinuationTypeTraits<_Function,
    _ReturnType>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    cancellation_token _CancellationToken,
    task_continuation_context _ContinuationContext) const -> typename details::_ContinuationTypeTraits<_Function,
    _ReturnType>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    const task_options& _TaskOptions = task_options()) const -> typename details::_ContinuationTypeTraits<_Function,
    void>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    cancellation_token _CancellationToken,
    task_continuation_context _ContinuationContext) const -> typename details::_ContinuationTypeTraits<_Function,
    void>::_TaskOfType;
```   
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo de objeto de função que será invocado pela tarefa.  
  
 `_Func`  
 A função de continuação para executar quando esta tarefa for concluída. Essa função de continuação deve levar como uma variável de entrada `result_type` ou `task<result_type>`, onde `result_type` é o tipo do resultado produz esta tarefa.  
  
 `_TaskOptions`  
 As opções de tarefa incluem o contexto de token, o Agendador e a continuação do cancelamento. Por padrão, as 3 opções anteriores são herdadas da tarefa antecedente  
  
 `_CancellationToken`  
 O token de cancelamento para associar a tarefa de continuação. Uma tarefa de continuação é criada sem um token de cancelamento herdarão o token de sua tarefa antecedente.  
  
 `_ContinuationContext`  
 Uma variável que especifica onde a continuação deve ser executada. Essa variável só é útil quando usado em um aplicativo de estilo da Windows Store. Para obter mais informações, consulte [task_continuation_context](task-continuation-context-class.md)  
  
### <a name="return-value"></a>Valor de retorno  
 A tarefa de continuação recém-criado. O tipo de resultado da tarefa retornada é determinado pelo que `_Func` retorna.  
  
### <a name="remarks"></a>Comentários  
 As sobrecargas de `then` que levam um lambda ou functor que retorna uma interface Windows::Foundation::IAsyncInfo, só estão disponíveis para aplicativos da Windows Store.  
  
 Para obter mais informações sobre como usar as continuações de tarefa para compor o trabalho assíncrono, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
##  <a name="wait"></a>Aguarde 

 Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.  
  
```
task_status wait() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A `task_status` valor que pode ser feito `completed` ou `canceled`. Se a tarefa encontrou uma exceção durante a execução, ou se uma exceção é propagada a ele de uma tarefa antecedente, `wait` gerará essa exceção.  
  
### <a name="remarks"></a>Comentários  
  
> [!IMPORTANT]
>  Em um [!INCLUDE[win8_appname_long](../../../build/includes/win8_appname_long_md.md)] aplicativo, não chame `wait` no código que é executado sobre o STA. Caso contrário, o tempo de execução lança [concurrency::invalid_operation](invalid-operation-class.md) porque esse método bloqueia o segmento atual e pode fazer com que o aplicativo pare de responder. No entanto, você pode chamar o [concurrency::task::get](#get) método para receber o resultado da tarefa antecedente em uma continuação baseado em tarefa.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

