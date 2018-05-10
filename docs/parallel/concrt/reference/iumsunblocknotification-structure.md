---
title: Estrutura IUMSUnblockNotification | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- IUMSUnblockNotification
- CONCRTRM/concurrency::IUMSUnblockNotification
- CONCRTRM/concurrency::IUMSUnblockNotification::IUMSUnblockNotification::GetContext
- CONCRTRM/concurrency::IUMSUnblockNotification::IUMSUnblockNotification::GetNextUnblockNotification
dev_langs:
- C++
helpviewer_keywords:
- IUMSUnblockNotification structure
ms.assetid: eaca9529-c1cc-472b-8ec6-722a1ff0fa2a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bda4f6e2b0565d39fd604767f3a89bcdd9a6df2c
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="iumsunblocknotification-structure"></a>Estrutura IUMSUnblockNotification
Representa uma notificação do Gerenciador de recursos que um proxy de thread que bloqueada e disparou um retorno para o Agendador designado contexto de programação foi desbloqueado e está pronto para ser agendado. Essa interface é inválida quando o contexto de execução associadas do proxy de thread, retornado do `GetContext` método, será reagendada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IUMSUnblockNotification;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IUMSUnblockNotification::GetContext](#getcontext)|Retorna o `IExecutionContext` interface para o contexto de execução associado ao proxy de thread que foi desbloqueado. Quando este método retorna o contexto de execução subjacente foi reagendado por meio de uma chamada para o `IThreadProxy::SwitchTo` método, essa interface não é mais válida.|  
|[IUMSUnblockNotification::GetNextUnblockNotification](#getnextunblocknotification)|Retorna o próximo `IUMSUnblockNotification` interface na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IUMSUnblockNotification`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="getcontext"></a>  Método Iumsunblocknotification:  
 Retorna o `IExecutionContext` interface para o contexto de execução associado ao proxy de thread que foi desbloqueado. Quando este método retorna o contexto de execução subjacente foi reagendado por meio de uma chamada para o `IThreadProxy::SwitchTo` método, essa interface não é mais válida.  
  
```
virtual IExecutionContext* GetContext() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `IExecutionContext` interface para o contexto de execução para um proxy de thread que foi desbloqueado.  
  
##  <a name="getnextunblocknotification"></a>  Método: Getnextunblocknotification  
 Retorna o próximo `IUMSUnblockNotification` interface na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.  
  
```
virtual IUMSUnblockNotification* GetNextUnblockNotification() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O próximo `IUMSUnblockNotification` interface na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IUMSScheduler](iumsscheduler-structure.md)   
 [Estrutura IUMSCompletionList](iumscompletionlist-structure.md)
