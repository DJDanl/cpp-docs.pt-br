---
title: Estrutura IUMSCompletionList | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IUMSCompletionList
- CONCRTRM/concurrency::IUMSCompletionList
- CONCRTRM/concurrency::IUMSCompletionList::IUMSCompletionList::GetUnblockNotifications
dev_langs:
- C++
helpviewer_keywords:
- IUMSCompletionList structure
ms.assetid: 81b5250e-3065-492c-b20d-2cdabf12271a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 378eccbc0e29a9356ffd89699039b9877c76c751
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="iumscompletionlist-structure"></a>Estrutura IUMSCompletionList
Representa uma lista de conclusão UMS. Quando um blocos de thread UMS, o Agendador designado de agendamento de contexto é enviado para tomar uma decisão do que agendar na raiz do processador virtual subjacente enquanto o thread original está bloqueado. Quando o thread original desbloqueia, o sistema operacional enfileira à lista de conclusão que pode ser acessada por meio dessa interface. O Agendador pode consultar a lista de conclusão no contexto de programação designado ou qualquer outro lugar, que ele procura por trabalho.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IUMSCompletionList;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IUMSCompletionList::GetUnblockNotifications](#getunblocknotifications)|Recupera uma cadeia de `IUMSUnblockNotification` interfaces que representa os contextos de execução cujo segmento associado proxies têm desbloqueado desde a última vez que esse método foi chamado.|  
  
## <a name="remarks"></a>Comentários  
 Um agendador deve ter muito cuidado sobre quais ações são executadas depois de utilizar esta interface para itens da lista de conclusão de remoção da fila. Os itens devem ser colocados na lista do Agendador de contextos de execução e geralmente acessíveis assim que possível. É totalmente possível que um dos itens removidas da fila tem a propriedade de um bloqueio arbitrário. O Agendador não pode fazer nenhuma chamadas de função arbitrária que podem bloquear entre a chamada para itens de remoção da fila e o posicionamento desses itens em uma lista que pode ser acessado em geral no Agendador.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IUMSCompletionList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="getunblocknotifications"></a>  IUMSCompletionList::GetUnblockNotifications Method  
 Recupera uma cadeia de `IUMSUnblockNotification` interfaces que representa os contextos de execução cujo segmento associado proxies têm desbloqueado desde a última vez que esse método foi chamado.  
  
```
virtual IUMSUnblockNotification *GetUnblockNotifications() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de `IUMSUnblockNotification` interfaces.  
  
### <a name="remarks"></a>Comentários  
 As notificações retornadas são inválidas depois que os contextos de execução sejam reagendados.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IUMSScheduler](iumsscheduler-structure.md)   
 [Estrutura IUMSUnblockNotification](iumsunblocknotification-structure.md)
