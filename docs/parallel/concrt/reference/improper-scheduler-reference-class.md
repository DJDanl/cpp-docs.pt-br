---
title: Classe improper_scheduler_reference
ms.date: 11/04/2016
f1_keywords:
- improper_scheduler_reference
- CONCRT/concurrency::improper_scheduler_reference
- CONCRT/concurrency::improper_scheduler_reference::improper_scheduler_reference
helpviewer_keywords:
- improper_scheduler_reference class
ms.assetid: 434a7512-7796-4255-92a7-f3bf71c6a7a7
ms.openlocfilehash: 121e61447775cdcb5d7f5f1187c5d4cc6b7d68b7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62262899"
---
# <a name="improperschedulerreference-class"></a>Classe improper_scheduler_reference

Esta classe descreve uma exceção gerada quando o `Reference` método é chamado em um `Scheduler` objeto que está sendo desligado, de um contexto que não faz parte do que o Agendador.

## <a name="syntax"></a>Sintaxe

```
class improper_scheduler_reference : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

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

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)
