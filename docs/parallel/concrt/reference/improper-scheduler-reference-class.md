---
title: Classe improper_scheduler_reference | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- improper_scheduler_reference
- CONCRT/concurrency::improper_scheduler_reference
- CONCRT/concurrency::improper_scheduler_reference::improper_scheduler_reference
dev_langs:
- C++
helpviewer_keywords:
- improper_scheduler_reference class
ms.assetid: 434a7512-7796-4255-92a7-f3bf71c6a7a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c5a061ca3c7bb39d90608685e04b62da9b2e83fb
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46410410"
---
# <a name="improperschedulerreference-class"></a>Classe improper_scheduler_reference

Esta classe descreve uma exceção gerada quando o `Reference` método é chamado em um `Scheduler` objeto que está sendo desligado, de um contexto que não faz parte do que o Agendador.

## <a name="syntax"></a>Sintaxe

```
class improper_scheduler_reference : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[improper_scheduler_reference](#ctor)|Sobrecarregado. Constrói um `improper_scheduler_reference` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`improper_scheduler_reference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> improper_scheduler_reference

Constrói um `improper_scheduler_reference` objeto.

```
explicit _CRTIMP improper_scheduler_reference(_In_z_ const char* _Message) throw();

improper_scheduler_reference() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)
