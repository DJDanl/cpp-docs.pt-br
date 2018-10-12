---
title: Classe task_completion_event | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- task_completion_event
- PPLTASKS/concurrency::task_completion_event
- PPLTASKS/concurrency::task_completion_event::task_completion_event
- PPLTASKS/concurrency::task_completion_event::set
- PPLTASKS/concurrency::task_completion_event::set_exception
dev_langs:
- C++
helpviewer_keywords:
- task_completion_event class
ms.assetid: fb19ed98-f245-48dc-9ba5-487ba879b28a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 867f94cd290e6b8ee5f9e50b266b0e4c9df63adf
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49163251"
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

*_ResultType*<br/>
O tipo de resultado desta classe `task_completion_event`.

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

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

##  <a name="set"></a> Definir

Define o evento de conclusão de tarefas.

```
bool set(_ResultType _Result) const ;

bool set() const ;
```

### <a name="parameters"></a>Parâmetros

*_Result*<br/>
O resultado para definir este evento.

### <a name="return-value"></a>Valor de retorno

O método retornará **verdadeira** se tiver sido bem-sucedido na configuração do evento. Ele retorna **falsos** se o evento já está definido.

### <a name="remarks"></a>Comentários

Na presença de vários ou chamadas simultâneas para `set`, somente a primeira chamada terá êxito e seu resultado (se houver) será armazenado no evento de conclusão de tarefa. Os conjuntos restantes são ignorados e o método retornará false. Quando você definir um evento de conclusão de tarefas, todas as tarefas criadas do que o evento serão concluídas imediatamente, e suas continuações, se houver, serão agendadas. Tarefa de objetos de conclusão que têm uma `_ResultType` diferente de **void** passará o valor para suas continuações.

##  <a name="set_exception"></a> set_exception

Propaga uma exceção para todas as tarefas associadas a esse evento.

```
template<typename _E>
__declspec(noinline) bool set_exception(_E _Except) const;

__declspec(noinline) bool set_exception(std::exception_ptr _ExceptionPtr) const ;
```

### <a name="parameters"></a>Parâmetros

*_E*<br/>
O tipo de exceção.

*Except*<br/>
A exceção a ser definido.

*_ExceptionPtr*<br/>
O ponteiro de exceção definido.

### <a name="return-value"></a>Valor de retorno

##  <a name="ctor"></a> task_completion_event

Constrói um objeto `task_completion_event`.

```
task_completion_event();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
