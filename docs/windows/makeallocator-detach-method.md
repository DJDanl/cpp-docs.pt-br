---
title: "M&#233;todo MakeAllocator::Detach | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::MakeAllocator::Detach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Detach"
ms.assetid: 78012634-2dda-4ea2-9ffe-40f105d2fe47
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo MakeAllocator::Detach
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
__forceinline void Detach();  
```  
  
## Comentários  
 Desassocia a memória alocada pelo método de [Aloque](../Topic/MakeAllocator::Allocate%20Method.md) do objeto atual de MakeAllocator.  
  
 Se você chamar Detach\(\), você é responsável para excluir a memória fornecida pelo método de alocação.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Classe MakeAllocator](../windows/makeallocator-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)