---
title: Classe default_scheduler_exists
ms.date: 11/04/2016
f1_keywords:
- default_scheduler_exists
- CONCRT/concurrency::default_scheduler_exists
- CONCRT/concurrency::default_scheduler_exists::default_scheduler_exists
helpviewer_keywords:
- default_scheduler_exists class
ms.assetid: f6e575e2-4e0f-455a-9e06-54f462ce0c1c
ms.openlocfilehash: eed5dd242beb4c4cd481f22635e0d5f71c28d7e6
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139185"
---
# <a name="default_scheduler_exists-class"></a>Classe default_scheduler_exists

Essa classe descreve uma exceção gerada quando o método `Scheduler::SetDefaultSchedulerPolicy` é chamado quando um agendador padrão já existe dentro do processo.

## <a name="syntax"></a>Sintaxe

```cpp
class default_scheduler_exists : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[default_scheduler_exists](#ctor)|Sobrecarregado. Constrói um objeto `default_scheduler_exists`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`default_scheduler_exists`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>default_scheduler_exists

Constrói um objeto `default_scheduler_exists`.

```cpp
explicit _CRTIMP default_scheduler_exists(_In_z_ const char* _Message) throw();

default_scheduler_exists() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
