---
title: Estrutura IUMSUnblockNotification | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IUMSUnblockNotification
- CONCRTRM/concurrency::IUMSUnblockNotification
- CONCRTRM/concurrency::IUMSUnblockNotification::IUMSUnblockNotification::GetContext
- CONCRTRM/concurrency::IUMSUnblockNotification::IUMSUnblockNotification::GetNextUnblockNotification
dev_langs: C++
helpviewer_keywords: IUMSUnblockNotification structure
ms.assetid: eaca9529-c1cc-472b-8ec6-722a1ff0fa2a
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3febe10f7c71e1c1d478dd6f6b6f565c4134e033
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[Iumsunblocknotification](#getcontext)|Retorna o `IExecutionContext` interface para o contexto de execução associado ao proxy de thread que foi desbloqueado. Quando este método retorna o contexto de execução subjacente foi reagendado por meio de uma chamada para o `IThreadProxy::SwitchTo` método, essa interface não é mais válida.|  
|[: Getnextunblocknotification](#getnextunblocknotification)|Retorna o próximo `IUMSUnblockNotification` interface na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IUMSUnblockNotification`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="getcontext"></a>Método Iumsunblocknotification:  
 Retorna o `IExecutionContext` interface para o contexto de execução associado ao proxy de thread que foi desbloqueado. Quando este método retorna o contexto de execução subjacente foi reagendado por meio de uma chamada para o `IThreadProxy::SwitchTo` método, essa interface não é mais válida.  
  
```
virtual IExecutionContext* GetContext() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `IExecutionContext` interface para o contexto de execução para um proxy de thread que foi desbloqueado.  
  
##  <a name="getnextunblocknotification"></a>Método: Getnextunblocknotification  
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
