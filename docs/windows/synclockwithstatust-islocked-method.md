---
title: "M&#233;todo SyncLockWithStatusT::IsLocked | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::IsLocked"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método IsLocked"
ms.assetid: e1b75b7b-c145-471a-aa5d-71abf31f5990
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SyncLockWithStatusT::IsLocked
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
bool IsLocked() const;  
```  
  
## Comentários  
 Indica se o objeto atual de SyncLockWithStatusT possui um recurso; isto é, o objeto de SyncLockWithStatusT *é bloqueada*.  
  
## Valor de retorno  
 **true** se o objeto de SyncLockWithStatusT é bloqueada; caso contrário, **false**.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## Consulte também  
 [Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)