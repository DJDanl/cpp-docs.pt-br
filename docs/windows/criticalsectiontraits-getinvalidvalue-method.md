---
title: "M&#233;todo CriticalSectionTraits::GetInvalidValue | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::GetInvalidValue"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetInvalidValue"
ms.assetid: 665f30a6-ca9c-4968-8c03-8f84e6b2329b
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo CriticalSectionTraits::GetInvalidValue
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especializa um modelo de CriticalSection de forma que o modelo sempre é inválido.  
  
## Sintaxe  
  
```  
inline static Type GetInvalidValue();  
```  
  
## Valor de retorno  
 Sempre retorna um ponteiro para uma seção crítica inválido.  
  
## Comentários  
 O modificador de *Type* é definido como `typedef CRITICAL_SECTION* Type;`.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Estrutura CriticalSectionTraits](../windows/criticalsectiontraits-structure.md)