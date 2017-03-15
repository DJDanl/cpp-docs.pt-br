---
title: "Estrutura CriticalSectionTraits | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CriticalSectionTraits"
ms.assetid: c515a1b5-4eb0-40bc-9035-c4d9352c9de7
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CriticalSectionTraits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especializa um objeto de CriticalSection para oferecer suporte a uma seção crítica inválida ou uma função para liberar uma seção crítica.  
  
## Sintaxe  
  
```  
struct CriticalSectionTraits;  
```  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`Type`|`typedef` que define um ponteiro para uma seção crítica.  `Type` é definido como `typedef CRITICAL_SECTION* Type;`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método CriticalSectionTraits::GetInvalidValue](../windows/criticalsectiontraits-getinvalidvalue-method.md)|Especializa um modelo de CriticalSection de forma que o modelo sempre é inválido.|  
|[Método CriticalSectionTraits::Unlock](../Topic/CriticalSectionTraits::Unlock%20Method.md)|Especializa um modelo de CriticalSection de modo que dê suporte ao liberar a propriedade do objeto especificado da seção crítica.|  
  
## Hierarquia de Herança  
 `CriticalSectionTraits`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)