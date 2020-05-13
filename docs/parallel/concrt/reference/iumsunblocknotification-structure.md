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
ms.openlocfilehash: 0b88ddd4184e982a5e07c536efc301eaa16f4a41
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368065"
---
# <a name="iumsunblocknotification-structure"></a>Estrutura IUMSUnblockNotification

Representa uma notificação do Gerenciador de recursos de que um proxy de thread que bloqueou e desencadeou um retorno ao contexto de agendamento designado pelo agendador foi desbloqueado e está pronto para ser agendado. Esta interface é inválida uma vez que o contexto `GetContext` de execução associado do proxy de segmento, retornado do método, é reagendado.

## <a name="syntax"></a>Sintaxe

```cpp
struct IUMSUnblockNotification;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IUMSUnblockNotification::GetContext](#getcontext)|Retorna `IExecutionContext` a interface para o contexto de execução associado ao proxy thread que foi desbloqueado. Uma vez que este método retorna e o contexto de `IThreadProxy::SwitchTo` execução subjacente foi reagendado através de uma chamada para o método, esta interface não é mais válida.|
|[IUMSUnBlockNotification::GetNextUnblockNotification](#getnextunblocknotification)|Retorna a `IUMSUnblockNotification` próxima interface na cadeia `IUMSCompletionList::GetUnblockNotifications`retornada do método .|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IUMSUnblockNotification`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="iumsunblocknotificationgetcontext-method"></a><a name="getcontext"></a>IUMSUnblockNotification::GetContext Method

Retorna `IExecutionContext` a interface para o contexto de execução associado ao proxy thread que foi desbloqueado. Uma vez que este método retorna e o contexto de `IThreadProxy::SwitchTo` execução subjacente foi reagendado através de uma chamada para o método, esta interface não é mais válida.

```cpp
virtual IExecutionContext* GetContext() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma `IExecutionContext` interface para o contexto de execução para um proxy de segmento que foi desbloqueado.

## <a name="iumsunblocknotificationgetnextunblocknotification-method"></a><a name="getnextunblocknotification"></a>IUMSUnblockNotification::GetNextUnblockNotification Method

Retorna a `IUMSUnblockNotification` próxima interface na cadeia `IUMSCompletionList::GetUnblockNotifications`retornada do método .

```cpp
virtual IUMSUnblockNotification* GetNextUnblockNotification() = 0;
```

### <a name="return-value"></a>Valor retornado

A `IUMSUnblockNotification` próxima interface da cadeia retornou do método `IUMSCompletionList::GetUnblockNotifications`.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)<br/>
[Estrutura IUMSCompletionList](iumscompletionlist-structure.md)
