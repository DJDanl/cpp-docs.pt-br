---
title: "Membro de dados EventSource::targetsPointerLock_ | Microsoft Docs"
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
  - "event/Microsoft::WRL::EventSource::targetsPointerLock_"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro de dados targetsPointerLock_"
ms.assetid: 8f08409f-5262-4be7-9cf1-2ed15f19684a
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Membro de dados EventSource::targetsPointerLock_
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Sincroniza o acesso a membros de dados internos, mesmo enquanto manipuladores de eventos para este EventSource estão sendo adicionados, removidos ou invocado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
Wrappers::SRWLock targetsPointerLock_;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)