---
title: Classe task_handle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- task_handle
- PPL/concurrency::task_handle
- PPL/concurrency::task_handle::task_handle
dev_langs: C++
helpviewer_keywords: task_handle class
ms.assetid: 74a34b15-708b-4231-a509-947874292b13
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 358d217a131ec3e282775604619f1ff265baf490
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="taskhandle-class"></a>Classe task_handle
O `task_handle` classe representa um item de trabalho paralelas individual. Ele encapsula as instruções e os dados necessários para executar um trabalho.  
  
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
|[task_handle](#ctor)|Constrói um novo `task_handle` objeto. O trabalho da tarefa é executado invocando a função especificada como um parâmetro para o construtor.|  
|[~ task_handle destruidor](#dtor)|Destrói a `task_handle` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operator)](#task_handle__operator_call)|O operador de chamada de função que invoca o tempo de execução para executar o trabalho do identificador de tarefa.|  
  
## <a name="remarks"></a>Comentários  
 `task_handle`objetos podem ser usados em conjunto com um `structured_task_group` ou um mais geral `task_group` objeto decompor o trabalho em tarefas paralelas. Para obter mais informações, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 Observe que o criador de uma `task_handle` objeto é responsável por manter o tempo de vida de criaram `task_handle` objeto até que ele não é exigido pelo tempo de execução de simultaneidade. Normalmente, isso significa que o `task_handle` objeto não deve destruct até que o `wait` ou `run_and_wait` método do `task_group` ou `structured_task_group` para que ele é enfileirado foi chamado.  
  
 `task_handle`Normalmente, os objetos são usados em conjunto com lambdas de C++. Porque você não souber o tipo true de lambda, o [make_task](concurrency-namespace-functions.md#make_task) função geralmente é usada para criar um `task_handle` objeto.  
  
 O tempo de execução cria uma cópia da função de trabalho que você passa para um `task_handle` objeto. Portanto, qualquer alteração de estado que ocorrem em uma função do objeto que você passar para um `task_handle` objeto não aparecerá na sua cópia do objeto de função.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `task_handle`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="task_handle__operator_call"></a>Operator) 

 O operador de chamada de função que invoca o tempo de execução para executar o trabalho do identificador de tarefa.  
  
```  
void operator()() const;

 
```  
  
##  <a name="task_handle__ctor"></a>task_handle 

 Constrói um novo `task_handle` objeto. O trabalho da tarefa é executado invocando a função especificada como um parâmetro para o construtor.  
  
```  
task_handle(const _Function& _Func);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Func`  
 A função que será chamada para executar o trabalho representado pelo `task_handle` objeto. Isso pode ser um functor lambda, um ponteiro para uma função, ou qualquer objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução cria uma cópia da função de trabalho que você passa para o construtor. Portanto, qualquer alteração de estado que ocorrem em uma função do objeto que você passar para um `task_handle` objeto não aparecerá na sua cópia do objeto de função.  
  
##  <a name="dtor"></a>~ task_handle 

 Destrói a `task_handle` objeto.  
  
```  
~task_handle();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe task_group](task-group-class.md)   
 [Classe structured_task_group](structured-task-group-class.md)
