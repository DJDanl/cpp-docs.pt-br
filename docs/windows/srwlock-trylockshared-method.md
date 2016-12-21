---
title: "M&#233;todo SRWLock::TryLockShared | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockShared"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método TryLockShared"
ms.assetid: 10cc198d-39a0-4d18-aa78-706744948668
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SRWLock::TryLockShared
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Tentativas de adquirir um objeto de SRWLock no modo compartilhado para o atual ou o objeto especificado de SRWLock.  
  
## Sintaxe  
  
```  
WRL_NOTHROW SyncLockShared TryLockShared();  
WRL_NOTHROW static SyncLockShared TryLockShared(  
   _In_ SRWLOCK* lock  
);  
```  
  
#### Parâmetros  
 `lock`  
 Ponteiro para um objeto de SRWLock.  
  
## Valor de retorno  
 Se tiver êxito, um objeto de SRWLock no modo compartilhado e o thread de chamada têm a propriedade de bloqueio.  Caso contrário, um objeto de SRWLock cujo estado não é válido.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe SRWLock](../windows/srwlock-class.md)