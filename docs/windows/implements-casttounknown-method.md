---
title: "M&#233;todo Implements::CastToUnknown | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Implements::CastToUnknown"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CastToUnknown"
ms.assetid: ca3324f7-4136-406b-8698-7389f4f3d3c7
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Implements::CastToUnknown
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém um ponteiro para a interface IUnknown subjacente.  
  
## Sintaxe  
  
```  
__forceinline IUnknown* CastToUnknown();  
```  
  
## Valor de retorno  
 Essa operação sempre terá êxito e retorna o ponteiro IUnknown.  
  
## Comentários  
 Função interna de auxiliar.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Implementa estrutura](../Topic/Implements%20Structure.md)