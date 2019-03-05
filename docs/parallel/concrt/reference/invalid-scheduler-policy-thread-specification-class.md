---
title: Classe invalid_scheduler_policy_thread_specification
ms.date: 11/04/2016
f1_keywords:
- concrt/concurrency::invalid_scheduler_policy_thread_specification
helpviewer_keywords:
- invalid_scheduler_policy_thread_specification class
ms.assetid: 2d0fafb2-18f8-4284-8040-3db640d33303
ms.openlocfilehash: 26d09610c6bb9e0c87852c9804e094617b021273
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278867"
---
# <a name="invalidschedulerpolicythreadspecification-class"></a>Classe invalid_scheduler_policy_thread_specification

Esta classe descreve uma exceção gerada quando é feita uma tentativa de definir os limites de simultaneidade de um `SchedulerPolicy` objeto, de modo que o valor da `MinConcurrency` chave é menor que o valor da `MaxConcurrency` chave.

## <a name="syntax"></a>Sintaxe

```
class invalid_scheduler_policy_thread_specification : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-value-class.md#ctor|Sobrecarregado. Constrói um `invalid_scheduler_policy_value` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_scheduler_policy_thread_specification`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade
##  <a name="ctor"></a> invalid_scheduler_policy_thread_specification

Constrói um `invalid_scheduler_policy_value` objeto.

```
explicit _CRTIMP invalid_scheduler_policy_thread_specification(_In_z_ const char* _Message) throw();

invalid_scheduler_policy_thread_specification() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe SchedulerPolicy](schedulerpolicy-class.md)
