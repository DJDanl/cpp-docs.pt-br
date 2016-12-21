---
title: "M&#233;todo SRWLockExclusiveTraits::Unlock | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits::Unlock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Unlock"
ms.assetid: 7fd6b0fb-8b88-4a43-aa74-0d7fe47a0da6
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SRWLockExclusiveTraits::Unlock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Controle exclusivo das versões do objeto especificado de SRWLock.  
  
## Sintaxe  
  
```  
inline static void Unlock(  
   _In_ Type srwlock  
);  
```  
  
#### Parâmetros  
 `srwlock`  
 Identificador para um objeto de SRWLock.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Estrutura SRWLockExclusiveTraits](../windows/srwlockexclusivetraits-structure.md)