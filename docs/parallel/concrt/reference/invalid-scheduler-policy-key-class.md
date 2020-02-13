---
title: Classe invalid_scheduler_policy_key
ms.date: 11/04/2016
f1_keywords:
- invalid_scheduler_policy_key
- CONCRT/concurrency::invalid_scheduler_policy_key
- CONCRT/concurrency::invalid_scheduler_policy_key::invalid_scheduler_policy_key
helpviewer_keywords:
- invalid_scheduler_policy_key class
ms.assetid: 6a7c42fe-9bc4-4a02-bebb-99fe9ef9817d
ms.openlocfilehash: 60d5a57ff9cb33a3d522c14514f5107844216852
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143019"
---
# <a name="invalid_scheduler_policy_key-class"></a>Classe invalid_scheduler_policy_key

Essa classe descreve uma exceção lançada quando uma chave inválida ou desconhecida é passada para um construtor de objeto `SchedulerPolicy` ou o método `SetPolicyValue` de um objeto `SchedulerPolicy` é passado para uma chave que deve ser alterada usando outros meios, como o método `SetConcurrencyLimits`.

## <a name="syntax"></a>Sintaxe

```cpp
class invalid_scheduler_policy_key : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[invalid_scheduler_policy_key](#ctor)|Sobrecarregado. Constrói um objeto `invalid_scheduler_policy_key`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_scheduler_policy_key`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>invalid_scheduler_policy_key

Constrói um objeto `invalid_scheduler_policy_key`.

```cpp
explicit _CRTIMP invalid_scheduler_policy_key(_In_z_ const char* _Message) throw();

invalid_scheduler_policy_key() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe SchedulerPolicy](schedulerpolicy-class.md)
