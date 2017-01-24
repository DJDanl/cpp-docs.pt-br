---
title: "Classe de CNoWorkerThread | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL::CNoWorkerThread"
  - "ATL.CNoWorkerThread"
  - "CNoWorkerThread"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CNoWorkerThread"
ms.assetid: 29f06bae-b658-4aac-9c14-331e996d25d1
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CNoWorkerThread
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta classe como o argumento para o parâmetro do modelo de `MonitorClass` armazene em cache classes se você desejar desativar a manutenção dinâmico do cache.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CNoWorkerThread  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CNoWorkerThread::AddHandle](../Topic/CNoWorkerThread::AddHandle.md)|Não funcional equivalente de [CWorkerThread::AddHandle](../Topic/CWorkerThread::AddHandle.md).|  
|[CNoWorkerThread::AddTimer](../Topic/CNoWorkerThread::AddTimer.md)|Não funcional equivalente de [CWorkerThread::AddTimer](../Topic/CWorkerThread::AddTimer.md).|  
|[CNoWorkerThread::GetThreadHandle](../Topic/CNoWorkerThread::GetThreadHandle.md)|Não funcional equivalente de [CWorkerThread::GetThreadHandle](../Topic/CWorkerThread::GetThreadHandle.md).|  
|[CNoWorkerThread::GetThreadId](../Topic/CNoWorkerThread::GetThreadId.md)|Não funcional equivalente de [CWorkerThread::GetThreadId](../Topic/CWorkerThread::GetThreadId.md).|  
|[CNoWorkerThread::Initialize](../Topic/CNoWorkerThread::Initialize.md)|Não funcional equivalente de [CWorkerThread::Initialize](../Topic/CWorkerThread::Initialize.md).|  
|[CNoWorkerThread::RemoveHandle](../Topic/CNoWorkerThread::RemoveHandle.md)|Não funcional equivalente de [CWorkerThread::RemoveHandle](../Topic/CWorkerThread::RemoveHandle.md).|  
|[CNoWorkerThread::Shutdown](../Topic/CNoWorkerThread::Shutdown.md)|Não funcional equivalente de [CWorkerThread::Shutdown](../Topic/CWorkerThread::Shutdown.md).|  
  
## Comentários  
 Essa classe fornece a mesma interface pública que [CWorkerThread](../Topic/CWorkerThread%20Class.md).  Essa interface é esperada ser fornecida pelo parâmetro do modelo de `MonitorClass` a classes do cache.  
  
 Os métodos de essa classe são implementados para não fazer nada.  Os métodos que retornam um retornado S\_OK HRESULT sempre, e os métodos que retornam um retorno 0 de identificação de ALÇA ou de segmento sempre.  
  
## Requisitos  
 **Cabeçalho:** atlutil.h