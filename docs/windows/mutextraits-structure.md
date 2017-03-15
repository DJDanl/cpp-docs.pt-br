---
title: "Estrutura MutexTraits | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::MutexTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura MutexTraits"
ms.assetid: 6582df80-b9ba-4892-948f-d572a3b23d54
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura MutexTraits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define características comuns da classe de [Mutex](../Topic/Mutex%20Class1.md) .  
  
## Sintaxe  
  
```  
struct MutexTraits : HANDLENullTraits;  
  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método MutexTraits::Unlock](../windows/mutextraits-unlock-method.md)|Libera o controle exclusivo de um recurso compartilhado.|  
  
## Hierarquia de Herança  
 `HANDLENullTraits`  
  
 `MutexTraits`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)