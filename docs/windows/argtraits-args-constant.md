---
title: "Constante ArgTraits::args | Microsoft Docs"
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
  - "event/Microsoft::WRL::Details::ArgTraits::args"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "constante args"
ms.assetid: a68100ab-254b-4571-a0bc-946f1633a46b
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Constante ArgTraits::args
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
static const int args = -1; ;  
```  
  
## Comentários  
 Mantém a contagem do número de parâmetros no método invocar de uma interface de delegação.  
  
## Comentários  
 Quando `args` é igual a \-1 indica que não pode haver nenhuma correspondência para invocar a assinatura do método.  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Estrutura ArgTraits](../windows/argtraits-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)