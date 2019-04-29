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
ms.openlocfilehash: 326a2dfc6837665adb4d46a6aaa8780052ad2b22
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62296092"
---
# <a name="defaultschedulerexists-class"></a>Classe default_scheduler_exists

Esta classe descreve uma exceção gerada quando o `Scheduler::SetDefaultSchedulerPolicy` método é chamado quando um agendador padrão já existe dentro do processo.

## <a name="syntax"></a>Sintaxe

```
class default_scheduler_exists : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[default_scheduler_exists](#ctor)|Sobrecarregado. Constrói um objeto `default_scheduler_exists`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`default_scheduler_exists`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> default_scheduler_exists

Constrói um objeto `default_scheduler_exists`.

```
explicit _CRTIMP default_scheduler_exists(_In_z_ const char* _Message) throw();

default_scheduler_exists() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
