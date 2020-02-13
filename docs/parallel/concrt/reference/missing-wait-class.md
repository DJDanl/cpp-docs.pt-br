---
title: Classe missing_wait
ms.date: 11/04/2016
f1_keywords:
- missing_wait
- CONCRT/concurrency::missing_wait
- CONCRT/concurrency::missing_wait::missing_wait
helpviewer_keywords:
- missing_wait class
ms.assetid: ff981875-bd43-47e3-806f-b03c9f418b18
ms.openlocfilehash: cf81d1ee6c144da210da5b1f37aca7910ae37bc8
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142383"
---
# <a name="missing_wait-class"></a>Classe missing_wait

Essa classe descreve uma exceção lançada quando há tarefas ainda agendadas para um objeto `task_group` ou `structured_task_group` no momento em que o destruidor do objeto é executado. Essa exceção nunca será gerada se o destruidor for atingido por causa de um desenrolamento de pilha como o resultado de uma exceção.

## <a name="syntax"></a>Sintaxe

```cpp
class missing_wait : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[missing_wait](#ctor)|Sobrecarregado. Constrói um objeto `missing_wait`.|

## <a name="remarks"></a>Comentários

Fluxo de exceção ausente, você é responsável por chamar o `wait` ou `run_and_wait` método de um `task_group` ou `structured_task_group` objeto antes de permitir que esse objeto seja destruído. O tempo de execução gera essa exceção como uma indicação de que você esqueceu de chamar o `wait` ou o método `run_and_wait`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`missing_wait`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>missing_wait

Constrói um objeto `missing_wait`.

```cpp
explicit _CRTIMP missing_wait(_In_z_ const char* _Message) throw();

missing_wait() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe task_group](task-group-class.md)<br/>
[esperado](task-group-class.md)<br/>
[run_and_wait](task-group-class.md)<br/>
[Classe structured_task_group](structured-task-group-class.md)
