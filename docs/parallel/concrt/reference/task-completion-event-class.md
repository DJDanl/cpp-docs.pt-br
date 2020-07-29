---
title: Classe task_completion_event
ms.date: 11/04/2016
f1_keywords:
- task_completion_event
- PPLTASKS/concurrency::task_completion_event
- PPLTASKS/concurrency::task_completion_event::task_completion_event
- PPLTASKS/concurrency::task_completion_event::set
- PPLTASKS/concurrency::task_completion_event::set_exception
helpviewer_keywords:
- task_completion_event class
ms.assetid: fb19ed98-f245-48dc-9ba5-487ba879b28a
ms.openlocfilehash: b63e8c6986508806cedc8c094a4e8844491dd2fa
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219502"
---
# <a name="task_completion_event-class"></a>Classe task_completion_event

A classe `task_completion_event` permite atrasar a execução de uma tarefa até que uma condição seja atendida, ou iniciar uma tarefa em resposta a um evento externo.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename _ResultType>
class task_completion_event;

template<>
class task_completion_event<void>;
```

### <a name="parameters"></a>parâmetros

*_ResultType*<br/>
O tipo de resultado desta classe `task_completion_event`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[task_completion_event](#ctor)|Constrói um objeto `task_completion_event`.|

### <a name="public-methods"></a>Métodos públicos

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

## <a name="set"></a><a name="set"></a>Definição

Define o evento de conclusão de tarefas.

```cpp
bool set(_ResultType _Result) const ;

bool set() const ;
```

### <a name="parameters"></a>parâmetros

*_Result*<br/>
O resultado para o qual definir esse evento.

### <a name="return-value"></a>Valor retornado

O método retorna **`true`** se foi bem-sucedido ao definir o evento. Ele retornará **`false`** se o evento já estiver definido.

### <a name="remarks"></a>Comentários

Na presença de chamadas múltiplas ou simultâneas para `set` , somente a primeira chamada terá sucesso e seu resultado (se houver) será armazenado no evento de conclusão de tarefa. Os conjuntos restantes são ignorados e o método retornará false. Quando você define um evento de conclusão de tarefa, todas as tarefas criadas a partir desse evento serão concluídas imediatamente e suas continuaçãos, se houver, serão agendadas. Objetos de conclusão de tarefa que têm um `_ResultType` diferente de **`void`** passarão o valor para suas continuações.

## <a name="set_exception"></a><a name="set_exception"></a>set_exception

Propaga uma exceção para todas as tarefas associadas a esse evento.

```cpp
template<typename _E>
__declspec(noinline) bool set_exception(_E _Except) const;

__declspec(noinline) bool set_exception(std::exception_ptr _ExceptionPtr) const ;
```

### <a name="parameters"></a>parâmetros

*_E*<br/>
O tipo de exceção.

*_Except*<br/>
A exceção a ser definida.

*_ExceptionPtr*<br/>
O ponteiro de exceção a ser definido.

### <a name="return-value"></a>Valor retornado

## <a name="task_completion_event"></a><a name="ctor"></a>task_completion_event

Constrói um objeto `task_completion_event`.

```cpp
task_completion_event();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
