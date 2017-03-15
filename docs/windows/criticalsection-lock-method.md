---
title: "M&#233;todo CriticalSection::Lock | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::CriticalSection::Lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Lock"
ms.assetid: 37cb184c-e13c-49ef-b6a0-13908a956414
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo CriticalSection::Lock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As esperas para a propriedade da seção crítica especificada objeto.  A função retorna quando o thread de chamada é concedido a propriedade.  
  
## Sintaxe  
  
```  
SyncLock Lock();  
  
   static SyncLock Lock(  
   _In_ CRITICAL_SECTION* cs  
);  
```  
  
#### Parâmetros  
 `cs`  
 Um objeto especificado pelo usuário da seção crítica.  
  
## Valor de retorno  
 Um objeto de bloqueio que pode ser usado para desbloquear a seção crítica atual.  
  
## Comentários  
 A primeira função de **Lock** afeta o objeto atual da seção crítica.  A segunda função de **Lock** afeta uma seção crítica especificada pelo usuário.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe CriticalSection](../Topic/CriticalSection%20Class.md)