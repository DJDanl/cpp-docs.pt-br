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
ms.openlocfilehash: 775b98d2394dce04b362e92927db1a408b8e1656
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50677403"
---
# <a name="invalidschedulerpolicykey-class"></a>Classe invalid_scheduler_policy_key

Esta classe descreve uma exceção gerada quando um inválido ou desconhecido de chave é passado para um `SchedulerPolicy` construtor de objeto, ou o `SetPolicyValue` método de um `SchedulerPolicy` objeto é passado a uma chave que deve ser alterada usando outros meios, como o `SetConcurrencyLimits` método.

## <a name="syntax"></a>Sintaxe

```
class invalid_scheduler_policy_key : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[invalid_scheduler_policy_key](#ctor)|Sobrecarregado. Constrói um `invalid_scheduler_policy_key` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_scheduler_policy_key`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> invalid_scheduler_policy_key

Constrói um `invalid_scheduler_policy_key` objeto.

```
explicit _CRTIMP invalid_scheduler_policy_key(_In_z_ const char* _Message) throw();

invalid_scheduler_policy_key() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe SchedulerPolicy](schedulerpolicy-class.md)
