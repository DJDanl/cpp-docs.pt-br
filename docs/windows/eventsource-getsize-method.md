---
title: "M&#233;todo EventSource::GetSize | Microsoft Docs"
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
  - "event/Microsoft::WRL::EventSource::GetSize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetSize"
ms.assetid: 7825aab5-1a6b-465f-9159-3a6684142d1f
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo EventSource::GetSize
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recupera o número de manipuladores de eventos associados ao objeto EventSource atual  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t GetSize() const;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O número de manipuladores de eventos [Targets _](../Topic/EventSource::targets_%20Data%20Member.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe EventSource](../windows/eventsource-class.md)