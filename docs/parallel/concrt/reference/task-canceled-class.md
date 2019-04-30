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
ms.openlocfilehash: caef1c62ff09ffb76f74d4a1453e9d59dcb7d45b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385239"
---
# <a name="taskcanceled-class"></a>Classe task_canceled

Esta classe descreve uma exceção acionada pela camada de tarefas de PPL para forçar a cancelamento da tarefa atual. Ele também é gerado pela `get()` método no [tarefa](/visualstudio/extensibility/debugger/task-class-internal-members), para uma tarefa cancelada.

## <a name="syntax"></a>Sintaxe

```
class task_canceled : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[task_canceled](#ctor)|Sobrecarregado. Constrói um objeto `task_canceled`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`task_canceled`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> task_canceled

Constrói um objeto `task_canceled`.

```
explicit _CRTIMP task_canceled(_In_z_ const char* _Message) throw();

task_canceled() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
