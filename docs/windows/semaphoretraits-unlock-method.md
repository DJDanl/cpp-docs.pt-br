---
title: "M&#233;todo SemaphoreTraits::Unlock | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SemaphoreTraits::Unlock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Unlock"
ms.assetid: 4e0ea808-b70d-43f7-81ef-998c3b34e3a0
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SemaphoreTraits::Unlock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Controle de versões de um recurso compartilhado.  
  
## Sintaxe  
  
```  
inline static void Unlock(  
   _In_ Type h  
);  
```  
  
#### Parâmetros  
 `h`  
 Identificador para um objeto de semáforo.  
  
## Comentários  
 Se a operação desbloquear for malsucedido, Unlock\(\) emite um erro que indica a causa da falha.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Estrutura SemaphoreTraits](../Topic/SemaphoreTraits%20Structure.md)