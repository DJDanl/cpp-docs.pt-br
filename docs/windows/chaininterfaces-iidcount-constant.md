---
title: "Constante ChainInterfaces::IidCount | Microsoft Docs"
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
  - "implements/Microsoft::WRL::ChainInterfaces::IidCount"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante IidCount"
ms.assetid: d4a90aa0-513c-4e99-b978-e12149734936
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Constante ChainInterfaces::IidCount
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O número total de IDs de interface contidos nas interfaces especificadas por `I0` parâmetros do modelo com `I9`.  
  
## Sintaxe  
  
```  
static const unsigned long IidCount = Details::InterfaceTraits<I0>::IidCount + Details::InterfaceTraits<I1>::IidCount + Details::InterfaceTraits<I2>::IidCount + Details::InterfaceTraits<I3>::IidCount + Details::InterfaceTraits<I4>::IidCount + Details::InterfaceTraits<I5>::IidCount + Details::InterfaceTraits<I6>::IidCount + Details::InterfaceTraits<I7>::IidCount + Details::InterfaceTraits<I8>::IidCount + Details::InterfaceTraits<I9>::IidCount;  
```  
  
## Valor de retorno  
 O número total de IDs da interface.  
  
## Comentários  
 Os parâmetros `I0` e `I1` de modelo são necessários, e os parâmetros `I2` com `I9` são opcionais. A contagem de IID de cada interface normalmente é 1.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)