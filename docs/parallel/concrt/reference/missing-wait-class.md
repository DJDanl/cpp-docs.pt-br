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
ms.openlocfilehash: 7e515a33bfa827bba5329182cd3b79764495d728
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50531112"
---
# <a name="missingwait-class"></a>Classe missing_wait

Esta classe descreve uma exceção gerada quando há tarefas que ainda está agendadas para um `task_group` ou `structured_task_group` do objeto do objeto ao tempo destruidor é executado. Essa exceção nunca será gerada se o destruidor for atingido devido a uma pilha de desenrolamento como resultado de uma exceção.

## <a name="syntax"></a>Sintaxe

```
class missing_wait : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[missing_wait](#ctor)|Sobrecarregado. Constrói um objeto `missing_wait`.|

## <a name="remarks"></a>Comentários

Ausência de fluxo de exceção, você é responsável por chamar o `wait` ou `run_and_wait` método de um `task_group` ou `structured_task_group` objeto antes de permitir que esse objeto destruir. O tempo de execução gera esta exceção como uma indicação de que você se esqueceu de chamar o `wait` ou `run_and_wait` método.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`missing_wait`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> missing_wait

Constrói um objeto `missing_wait`.

```
explicit _CRTIMP missing_wait(_In_z_ const char* _Message) throw();

missing_wait() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe task_group](task-group-class.md)<br/>
[wait](task-group-class.md)<br/>
[run_and_wait](task-group-class.md)<br/>
[Classe structured_task_group](structured-task-group-class.md)
