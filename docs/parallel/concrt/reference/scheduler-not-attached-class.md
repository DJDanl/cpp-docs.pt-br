---
title: Classe scheduler_not_attached
ms.date: 11/04/2016
f1_keywords:
- scheduler_not_attached
- CONCRT/concurrency::scheduler_not_attached
- CONCRT/concurrency::scheduler_not_attached::scheduler_not_attached
helpviewer_keywords:
- scheduler_not_attached class
ms.assetid: 26001970-b400-463b-be3d-8623359c399a
ms.openlocfilehash: be8a04c7cf6ef5aa4d6070e92df14e643395ef00
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160114"
---
# <a name="schedulernotattached-class"></a>Classe scheduler_not_attached

Esta classe descreve uma exceção gerada quando é executada uma operação que exige um agendador a ser anexado ao contexto atual e um não é.

## <a name="syntax"></a>Sintaxe

```
class scheduler_not_attached : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_not_attached](#ctor)|Sobrecarregado. Constrói um objeto `scheduler_not_attached`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`scheduler_not_attached`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> scheduler_not_attached

Constrói um objeto `scheduler_not_attached`.

```
explicit _CRTIMP scheduler_not_attached(_In_z_ const char* _Message) throw();

scheduler_not_attached() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)
