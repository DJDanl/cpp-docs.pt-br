---
title: "M&#233;todo ChainInterfaces::CastToUnknown | Microsoft Docs"
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
  - "implements/Microsoft::WRL::ChainInterfaces::CastToUnknown"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CastToUnknown"
ms.assetid: a6a58555-e5b0-4773-aba0-959d9d362c6b
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ChainInterfaces::CastToUnknown
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Converte o ponteiro de interface do tipo definido pelo parâmetro do modelo de `I0` a um ponteiro para IUnknown.  
  
## Sintaxe  
  
```  
__forceinline IUnknown* CastToUnknown();  
```  
  
## Valor de retorno  
 Um ponteiro para IUnknown.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)