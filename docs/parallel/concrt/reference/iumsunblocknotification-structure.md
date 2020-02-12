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
ms.openlocfilehash: d4fd95b1f11ed6edac26cb03e41e8b650acfafa3
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139979"
---
# <a name="iumsunblocknotification-structure"></a>Estrutura IUMSUnblockNotification

Representa uma notificação do Gerenciador de recursos que um proxy de thread que bloqueou e disparou um retorno ao contexto de agendamento designado do Agendador foi desbloqueado e está pronto para ser agendado. Essa interface é inválida quando o contexto de execução associado do proxy de thread, retornado do método `GetContext`, é reagendado.

## <a name="syntax"></a>Sintaxe

```cpp
struct IUMSUnblockNotification;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IUMSUnblockNotification:: GetContext](#getcontext)|Retorna a interface `IExecutionContext` para o contexto de execução associado ao proxy de thread que foi desbloqueado. Quando esse método retornar e o contexto de execução subjacente tiver sido reagendado por meio de uma chamada para o método `IThreadProxy::SwitchTo`, essa interface não será mais válida.|
|[IUMSUnblockNotification::GetNextUnblockNotification](#getnextunblocknotification)|Retorna a próxima interface de `IUMSUnblockNotification` na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IUMSUnblockNotification`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="getcontext"></a>Método IUMSUnblockNotification:: GetContext

Retorna a interface `IExecutionContext` para o contexto de execução associado ao proxy de thread que foi desbloqueado. Quando esse método retornar e o contexto de execução subjacente tiver sido reagendado por meio de uma chamada para o método `IThreadProxy::SwitchTo`, essa interface não será mais válida.

```cpp
virtual IExecutionContext* GetContext() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface `IExecutionContext` para o contexto de execução para um proxy de thread que foi desbloqueado.

## <a name="getnextunblocknotification"></a>Método IUMSUnblockNotification:: GetNextUnblockNotification

Retorna a próxima interface de `IUMSUnblockNotification` na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.

```cpp
virtual IUMSUnblockNotification* GetNextUnblockNotification() = 0;
```

### <a name="return-value"></a>Valor retornado

A próxima interface de `IUMSUnblockNotification` na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)<br/>
[Estrutura IUMSCompletionList](iumscompletionlist-structure.md)
