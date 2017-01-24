---
title: "Estrutura SRWLockSharedTraits | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura SRWLockSharedTraits"
ms.assetid: 709cb51e-d70c-40b6-bdb4-d8eacf3af495
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura SRWLockSharedTraits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve características comuns da classe de SRWLock no modo de bloqueio compartilhado.  
  
## Sintaxe  
  
```  
struct SRWLockSharedTraits;  
```  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`Type`|Sinônimo para um ponteiro para a classe de [SRWLOCK](../windows/srwlock-class.md) .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método SRWLockSharedTraits::GetInvalidValue](../Topic/SRWLockSharedTraits::GetInvalidValue%20Method.md)|Recupera um objeto de SRWLockSharedTraits que sempre é inválido.|  
|[Método SRWLockSharedTraits::Unlock](../Topic/SRWLockSharedTraits::Unlock%20Method.md)|Controle exclusivo das versões do objeto especificado de SRWLock.|  
  
## Hierarquia de Herança  
 `SRWLockSharedTraits`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)