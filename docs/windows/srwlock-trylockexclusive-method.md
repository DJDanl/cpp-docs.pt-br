---
title: "M&#233;todo SRWLock::TryLockExclusive | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockExclusive"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método TryLockExclusive"
ms.assetid: 661e8b19-3058-4511-8742-c9fbb90412c7
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SRWLock::TryLockExclusive
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Tentativas de adquirir um objeto de SRWLock no modo exclusivo para o atual ou o objeto especificado de SRWLock.  Se a chamada for bem\-sucedida, o thread de chamada assume a propriedade de bloqueio.  
  
## Sintaxe  
  
```  
SyncLockExclusive TryLockExclusive();  
  
static SyncLockExclusive TryLockExclusive(  
   _In_ SRWLOCK* lock  
);  
```  
  
#### Parâmetros  
 `lock`  
 Ponteiro para um objeto de SRWLock.  
  
## Valor de retorno  
 Se tiver êxito, um objeto de SRWLock no modo exclusivo e o thread de chamada têm a propriedade de bloqueio.  Caso contrário, um objeto de SRWLock cujo estado não é válido.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe SRWLock](../windows/srwlock-class.md)