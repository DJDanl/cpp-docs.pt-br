---
title: Estrutura IUMSUnblockNotification
ms.date: 11/04/2016
f1_keywords:
- IUMSUnblockNotification
- CONCRTRM/concurrency::IUMSUnblockNotification
- CONCRTRM/concurrency::IUMSUnblockNotification::IUMSUnblockNotification::GetContext
- CONCRTRM/concurrency::IUMSUnblockNotification::IUMSUnblockNotification::GetNextUnblockNotification
helpviewer_keywords:
- IUMSUnblockNotification structure
ms.assetid: eaca9529-c1cc-472b-8ec6-722a1ff0fa2a
ms.openlocfilehash: bdf083e2ad418269e49e53dc164f2a60f693d5d6
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57261382"
---
# <a name="iumsunblocknotification-structure"></a>Estrutura IUMSUnblockNotification

Representa uma notificação do Gerenciador de recursos que um proxy de thread que bloqueado e disparou um retorno para o Agendador designado o contexto de programação tem desbloqueado e está pronto para ser agendada. Essa interface é inválida quando o contexto de execução associadas do proxy de thread, retornado do `GetContext` método, será reagendada.

## <a name="syntax"></a>Sintaxe

```
struct IUMSUnblockNotification;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IUMSUnblockNotification::GetContext](#getcontext)|Retorna o `IExecutionContext` interface para o contexto de execução associado com o proxy de thread que foi desbloqueada. Depois que esse método retorna, e o contexto de execução subjacente foi reagendado por meio de uma chamada para o `IThreadProxy::SwitchTo` método, essa interface não é mais válida.|
|[IUMSUnblockNotification::GetNextUnblockNotification](#getnextunblocknotification)|Retorna o próximo `IUMSUnblockNotification` interface na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IUMSUnblockNotification`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="getcontext"></a>  Método iumsunblocknotification:: GetContext

Retorna o `IExecutionContext` interface para o contexto de execução associado com o proxy de thread que foi desbloqueada. Depois que esse método retorna, e o contexto de execução subjacente foi reagendado por meio de uma chamada para o `IThreadProxy::SwitchTo` método, essa interface não é mais válida.

```
virtual IExecutionContext* GetContext() = 0;
```

### <a name="return-value"></a>Valor de retorno

Um `IExecutionContext` interface para o contexto de execução para um proxy de thread que foi desbloqueada.

##  <a name="getnextunblocknotification"></a>  Método iumsunblocknotification:: Getnextunblocknotification

Retorna o próximo `IUMSUnblockNotification` interface na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.

```
virtual IUMSUnblockNotification* GetNextUnblockNotification() = 0;
```

### <a name="return-value"></a>Valor de retorno

A próxima `IUMSUnblockNotification` interface na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)<br/>
[Estrutura IUMSCompletionList](iumscompletionlist-structure.md)
