---
title: Classe invalid_multiple_scheduling
ms.date: 11/04/2016
f1_keywords:
- invalid_multiple_scheduling
- CONCRT/concurrency::invalid_multiple_scheduling
- CONCRT/concurrency::invalid_multiple_scheduling::invalid_multiple_scheduling
helpviewer_keywords:
- invalid_multiple_scheduling class
ms.assetid: e9a47cb7-a778-4df7-92b0-3752119fd4c7
ms.openlocfilehash: a8b2a045ce94562dcba0019bc03aaa90c4d384a9
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140901"
---
# <a name="invalid_multiple_scheduling-class"></a>Classe invalid_multiple_scheduling

Essa classe descreve uma exceção gerada quando um objeto de `task_handle` é agendado várias vezes usando o método `run` de um objeto `task_group` ou `structured_task_group` sem uma chamada intermediária para os métodos `wait` ou `run_and_wait`.

## <a name="syntax"></a>Sintaxe

```cpp
class invalid_multiple_scheduling : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[invalid_multiple_scheduling](#ctor)|Sobrecarregado. Constrói um objeto `invalid_multiple_scheduling`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_multiple_scheduling`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>invalid_multiple_scheduling

Constrói um objeto `invalid_multiple_scheduling`.

```cpp
explicit _CRTIMP invalid_multiple_scheduling(_In_z_ const char* _Message) throw();

invalid_multiple_scheduling() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe task_handle](task-handle-class.md)<br/>
[Classe task_group](task-group-class.md)<br/>
[run](task-group-class.md)<br/>
[esperado](task-group-class.md)<br/>
[run_and_wait](task-group-class.md)<br/>
[Classe structured_task_group](structured-task-group-class.md)
