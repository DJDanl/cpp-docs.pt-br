---
title: Classe task_canceled
ms.date: 11/04/2016
f1_keywords:
- task_canceled
- CONCRT/concurrency::task_canceled
- CONCRT/concurrency::task_canceled::task_canceled
helpviewer_keywords:
- task_canceled class
ms.assetid: c3f0b234-2cc1-435f-a48e-995f45b190be
ms.openlocfilehash: b1436f921343843ee2b50888f00b6d470e513329
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142599"
---
# <a name="task_canceled-class"></a>Classe task_canceled

Essa classe descreve uma exceção gerada pela camada de tarefas PPL para forçar a cancelamento da tarefa atual. Ele também é gerado pelo método `get()` na [tarefa](/visualstudio/extensibility/debugger/task-class-internal-members), para uma tarefa cancelada.

## <a name="syntax"></a>Sintaxe

```cpp
class task_canceled : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[task_canceled](#ctor)|Sobrecarregado. Constrói um objeto `task_canceled`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`task_canceled`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>task_canceled

Constrói um objeto `task_canceled`.

```cpp
explicit _CRTIMP task_canceled(_In_z_ const char* _Message) throw();

task_canceled() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
