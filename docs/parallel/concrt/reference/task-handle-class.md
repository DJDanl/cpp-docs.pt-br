---
title: Classe task_handle | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- task_handle
- PPL/concurrency::task_handle
- PPL/concurrency::task_handle::task_handle
dev_langs:
- C++
helpviewer_keywords:
- task_handle class
ms.assetid: 74a34b15-708b-4231-a509-947874292b13
caps.latest.revision: 23
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 0fef1ef7b1c02287a0113eb80be413e4a17dc1a4
ms.lasthandoff: 03/17/2017

---
# <a name="taskhandle-class"></a>Classe task_handle
O `task_handle` classe representa um item de trabalho paralelas individuais. Ele encapsula as instruções e os dados necessários para executar um trabalho.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<
    typename _Function  
>  
class task_handle : public ::Concurrency::details::_UnrealizedChore;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo do objeto de função que será chamado para executar o trabalho representado pelo `task_handle` objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[task_handle](#ctor)|Constrói um novo `task_handle` objeto. O trabalho da tarefa é executado, chamando a função especificada como um parâmetro para o construtor.|  
|[~ task_handle destruidor](#dtor)|Destrói o `task_handle` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operator)](#task_handle__operator_call)|O operador de chamada de função que o tempo de execução invoca para realizar o trabalho do identificador de tarefa.|  
  
## <a name="remarks"></a>Comentários  
 `task_handle`objetos podem ser usados em conjunto com um `structured_task_group` ou um mais geral `task_group` objeto, decompor o trabalho em tarefas paralelas. Para obter mais informações, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 Observe que o criador de um `task_handle` objeto é responsável por manter o tempo de vida de criaram `task_handle` objeto até que ele não é exigido pelo tempo de execução de simultaneidade. Normalmente, isso significa que o `task_handle` objeto não deve destruct até que o `wait` ou `run_and_wait` método o `task_group` ou `structured_task_group` para que ele é enfileirado foi chamado.  
  
 `task_handle`Normalmente, os objetos são usados em conjunto com lambdas de C++. Porque você não souber o tipo true do lambda, o [make_task](concurrency-namespace-functions.md#make_task) função geralmente é usada para criar um `task_handle` objeto.  
  
 O tempo de execução cria uma cópia da função de trabalho que você passa para um `task_handle` objeto. Portanto, qualquer alteração de estado que ocorrem em uma função de objeto que você passar para um `task_handle` objeto não aparecerá na sua cópia desse objeto de função.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `task_handle`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="task_handle__operator_call"></a>Operator) 

 O operador de chamada de função que o tempo de execução invoca para realizar o trabalho do identificador de tarefa.  
  
```  
void operator()() const;

 
```  
  
##  <a name="task_handle__ctor"></a>task_handle 

 Constrói um novo `task_handle` objeto. O trabalho da tarefa é executado, chamando a função especificada como um parâmetro para o construtor.  
  
```  
task_handle(const _Function& _Func);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Func`  
 A função que será chamada para executar o trabalho representado pelo `task_handle` objeto. Isso pode ser um functor lambda, um ponteiro para uma função, ou qualquer objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução cria uma cópia da função de trabalho que você passa ao construtor. Portanto, qualquer alteração de estado que ocorrem em uma função de objeto que você passar para um `task_handle` objeto não aparecerá na sua cópia desse objeto de função.  
  
##  <a name="dtor"></a>~ task_handle 

 Destrói o `task_handle` objeto.  
  
```  
~task_handle();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe task_group](task-group-class.md)   
 [Classe structured_task_group](structured-task-group-class.md)

