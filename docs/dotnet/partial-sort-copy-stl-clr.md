---
title: "partial_sort_copy (STL/CLR) | Microsoft Docs"
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
  - "cliext::partial_sort_copy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função partial_sort_copy [STL/CLR]"
ms.assetid: ed4af83e-7554-4f6d-bf54-c56fa6210fe8
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# partial_sort_copy (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os elementos de cópias de um intervalo de origem para um destino variam onde os elementos de origem são ordenados por menor que ou outro predicado binário especificado.  
  
## Sintaxe  
  
```  
template<class _InIt, class _RanIt> inline  
    _RanIt partial_sort_copy(_InIt _First1, _InIt _Last1,  
        _RanIt _First2, _RanIt _Last2);  
template<class _InIt, class _RanIt, class _Pr> inline  
    _RanIt partial_sort_copy(_InIt _First1, _InIt _Last1,  
        _RanIt _First2, _RanIt _Last2, _Pr _Pred);  
```  
  
## Comentários  
 Essa função se comportará da mesma forma como a função `partial_sort_copy`STL.  Para obter mais informações, consulte [partial\_sort\_copy](../Topic/partial_sort_copy.md).  
  
## Requisitos  
 cliext \<\/algoritmo de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [algorithm](../Topic/algorithm%20\(STL-CLR\).md)