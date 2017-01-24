---
title: "Estrutura IUMSCompletionList | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "concrtrm/concurrency::IUMSCompletionList"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IUMSCompletionList"
ms.assetid: 81b5250e-3065-492c-b20d-2cdabf12271a
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IUMSCompletionList
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Representa uma lista de conclusão UMS.  Quando os blocos UMS thread, o agendador designado contexto está agendando despachados para tomar uma decisão de agendamento na raiz virtual subjacente do processador quando o thread original estiver bloqueado.  Quando o thread original desbloqueia, o sistema operacional enfileira\-o à lista de conclusão que é acessível através dessa interface.  O agendador poderá ver a lista de conclusão no contexto de agendamento designado ou em qualquer outro local que pesquisa por trabalho.  
  
## Sintaxe  
  
```  
struct IUMSCompletionList;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IUMSCompletionList::GetUnblockNotifications](../Topic/IUMSCompletionList::GetUnblockNotifications%20Method.md)|Recupera uma cadeia das interfaces de `IUMSUnblockNotification` que representam os contextos de execução cujos proxies associados de thread desbloquearam desde a última vez em que esse método foi chamado.|  
  
## Comentários  
 Um agendador deve ser extraordinària cuidado que ações forem executadas após superutilizado essa interface para remover da fila itens da lista de conclusão.  Os itens devem ser colocados na lista de agendador de contextos executáveis e geralmente acessíveis ser o mais rápido possível.  O é totalmente possível que um dos itens removidas da fila esteve determinado a propriedade de um bloqueio arbitrário.  O agendador não pode fazer nenhuma chamada de função arbitrária que pode bloquear entre a chamada para remover itens da fila e o posicionamento desses itens em uma lista que pode ser acessada em geral do agendador.  
  
## Hierarquia de Herança  
 `IUMSCompletionList`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Estrutura IUMSScheduler](../../../parallel/concrt/reference/iumsscheduler-structure.md)   
 [Estrutura IUMSUnblockNotification](../../../parallel/concrt/reference/iumsunblocknotification-structure.md)