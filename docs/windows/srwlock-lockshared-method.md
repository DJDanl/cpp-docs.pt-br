---
title: "M&#233;todo SRWLock::LockShared | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::SRWLock::LockShared"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método LockShared"
ms.assetid: 9d826a5c-b6a2-4430-ac85-d5753cbca889
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SRWLock::LockShared
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adquire um objeto de SRWLock no modo compartilhado.  
  
## Sintaxe  
  
```  
SyncLockShared LockShared();  
  
static SyncLockShared LockShared(  
   _In_ SRWLOCK* lock  
);  
```  
  
#### Parâmetros  
 `lock`  
 Ponteiro para um objeto de SRWLock.  
  
## Valor de retorno  
 Um objeto de SRWLock no modo compartilhado.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe SRWLock](../windows/srwlock-class.md)