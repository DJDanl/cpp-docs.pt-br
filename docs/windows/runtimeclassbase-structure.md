---
title: "Estrutura RuntimeClassBase | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::RuntimeClassBase"
dev_langs: 
  - "C++"
ms.assetid: 6ada4f81-a857-488a-ad56-8d0b11ccbfcc
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura RuntimeClassBase
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
struct RuntimeClassBase;  
```  
  
## Comentários  
 Usado para detectar RuntimeClass na função de [Faça](../windows/make-function.md) .  
  
 RuntimeClassBase é uma estrutura vazia.  
  
## Hierarquia de Herança  
 `RuntimeClassBase`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)