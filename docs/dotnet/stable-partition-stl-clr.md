---
title: "stable_partition (STL/CLR) | Microsoft Docs"
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
  - "cliext::stable_partition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função stable_partition [STL/CLR]"
ms.assetid: b82c194c-ae38-4afb-b255-a95a4c2b3101
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# stable_partition (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Classifica os elementos em um intervalo separam em dois conjuntos, com os elementos que satisfazem um predicado unário que precede os que não satisfazem o, preservando a ordem relativa de elementos equivalentes.  
  
## Sintaxe  
  
```  
template<class _BidIt, class _Pr> inline  
    _BidIt stable_partition(_BidIt _First, _BidIt _Last, _Pr _Pred);  
```  
  
## Comentários  
 Essa função se comportará da mesma forma como a função `stable_partition`STL.  Para obter mais informações, consulte [stable\_partition](../Topic/stable_partition.md).  
  
## Requisitos  
 cliext \<\/algoritmo de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [algorithm](../Topic/algorithm%20\(STL-CLR\).md)