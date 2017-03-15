---
title: "pop_heap (STL/CLR) | Microsoft Docs"
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
  - "cliext::pop_heap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função pop_heap [STL/CLR]"
ms.assetid: d9bde0ed-2122-4d83-b4b3-f47f6fb3729a
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# pop_heap (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Remove o elemento o maior da frente de um heap a seguir \- posição do para último no intervalo e forma em um novo heap de elementos restantes.  
  
## Sintaxe  
  
```  
template<class _RanIt> inline  
    void pop_heap(_RanIt _First, _RanIt _Last);  
template<class _RanIt, class _Pr> inline  
    void pop_heap(_RanIt _First, _RanIt _Last, _Pr _Pred);  
```  
  
## Comentários  
 Essa função se comportará da mesma forma como a função `pop_heap`STL.  Para obter mais informações, consulte [pop\_heap](../Topic/pop_heap.md).  
  
## Requisitos  
 cliext \<\/algoritmo de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [algorithm](../Topic/algorithm%20\(STL-CLR\).md)