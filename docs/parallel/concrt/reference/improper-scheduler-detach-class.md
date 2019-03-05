---
title: Classe improper_scheduler_detach
ms.date: 11/04/2016
f1_keywords:
- improper_scheduler_detach
- CONCRT/concurrency::improper_scheduler_detach
- CONCRT/concurrency::improper_scheduler_detach::improper_scheduler_detach
helpviewer_keywords:
- improper_scheduler_detach class
ms.assetid: 30132102-c900-4951-a470-b63b4e3aa2d2
ms.openlocfilehash: 7e85ff8ea7ffb817c141094649cd39b8becccf53
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57285029"
---
# <a name="improperschedulerdetach-class"></a>Classe improper_scheduler_detach

Esta classe descreve uma exceção gerada quando o `CurrentScheduler::Detach` método é chamado em um contexto que ainda não foi anexado a qualquer Agendador usando o `Attach` método de um `Scheduler` objeto.

## <a name="syntax"></a>Sintaxe

```
class improper_scheduler_detach : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[improper_scheduler_detach](#ctor)|Sobrecarregado. Constrói um `improper_scheduler_detach` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`improper_scheduler_detach`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> improper_scheduler_detach

Constrói um `improper_scheduler_detach` objeto.

```
explicit _CRTIMP improper_scheduler_detach(_In_z_ const char* _Message) throw();

improper_scheduler_detach() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)
