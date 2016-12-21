---
title: "Membro de dados EventSource::addRemoveLock_ | Microsoft Docs"
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
  - "event/Microsoft::WRL::EventSource::addRemoveLock_"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro de dados addRemoveLock_"
ms.assetid: e2d69256-4891-4aad-ad0b-76479c0bb076
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Membro de dados EventSource::addRemoveLock_
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Sincroniza o acesso para o [Targets _](../Topic/EventSource::targets_%20Data%20Member.md) matriz ao adicionar, remover ou invocar manipuladores de eventos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
Wrappers::SRWLock addRemoveLock_;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)