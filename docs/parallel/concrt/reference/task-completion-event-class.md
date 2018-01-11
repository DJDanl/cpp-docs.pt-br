---
title: Classe task_completion_event | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- task_completion_event
- PPLTASKS/concurrency::task_completion_event
- PPLTASKS/concurrency::task_completion_event::task_completion_event
- PPLTASKS/concurrency::task_completion_event::set
- PPLTASKS/concurrency::task_completion_event::set_exception
dev_langs: C++
helpviewer_keywords: task_completion_event class
ms.assetid: fb19ed98-f245-48dc-9ba5-487ba879b28a
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 48bf640d75a02b9033102b1c8fc7b824dc4a5be0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="taskcompletionevent-class"></a>Classe task_completion_event
A classe `task_completion_event` permite atrasar a execução de uma tarefa até que uma condição seja atendida, ou iniciar uma tarefa em resposta a um evento externo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename _ResultType>
class task_completion_event;

template<>
class task_completion_event<void>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_ResultType`  
 O tipo de resultado desta classe `task_completion_event`.  
  
 `T`  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[task_completion_event](#ctor)|Constrói um objeto `task_completion_event`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[set](#set)|Sobrecarregado. Define o evento de conclusão de tarefas.|  
|[set_exception](#set_exception)|Sobrecarregado. Propaga uma exceção para todas as tarefas associadas a esse evento.|  
  
## <a name="remarks"></a>Comentários  
 Use uma tarefa criada por meio de um evento de conclusão de tarefas quando seu cenário solicitar que você crie uma tarefa que será concluída e, assim, terá as continuações agendadas para execução, em algum momento no futuro. O `task_completion_event` deve ter o mesmo tipo da tarefa que você cria e a chamada do método de definição no evento de conclusão de tarefas com um valor desse tipo fará com que a tarefa associada seja concluída e fornecerá esse valor como resultado das continuações.  
  
 Se o evento de conclusão de tarefas nunca foi sinalizado, todas as tarefas criadas por meio dele serão canceladas quando ele for destruído.  
  
 `task_completion_event` se comporta como um ponteiro inteligente e deve ser passado por valor.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `task_completion_event`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppltasks  
  
 **Namespace:** simultaneidade  
  
##  <a name="set"></a>definir 

 Define o evento de conclusão de tarefas.  
  
```
bool set(_ResultType _Result) const ;

bool set() const ;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Result`  
 O resultado para definir esse evento com.  
  
### <a name="return-value"></a>Valor de retorno  
 O método retorna `true` se ela foi bem-sucedida na configuração de evento. Ele retorna `false` se o evento já está definido.  
  
### <a name="remarks"></a>Comentários  
 Na presença de várias chamadas simultâneas para ou `set`, somente a primeira chamada será bem-sucedida e seu resultado (se houver) será armazenado no evento de conclusão de tarefas. Os conjuntos restantes são ignorados e o método retornará false. Quando você define um evento de conclusão de tarefas, todas as tarefas criada do que evento será concluída imediatamente, e seus continuações, se houver, serão agendadas. Tarefa de objetos de conclusão que têm um `_ResultType` diferente de `void` irá passar o valor para seus continuações.  
  
##  <a name="set_exception"></a>set_exception 

 Propaga uma exceção para todas as tarefas associadas a esse evento.  
  
```
template<typename _E>
__declspec(noinline) bool set_exception(_E _Except) const;

__declspec(noinline) bool set_exception(std::exception_ptr _ExceptionPtr) const ;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_E`  
 `_Except`  
 `_ExceptionPtr`  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="ctor"></a>task_completion_event 

 Constrói um objeto `task_completion_event`.  
  
```
task_completion_event();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
