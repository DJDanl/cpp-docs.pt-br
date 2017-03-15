---
title: "remove_copy (STL/CLR) | Microsoft Docs"
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
  - "cliext::remove_copy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função remove_copy [STL/CLR]"
ms.assetid: 602fd8e3-26f7-491f-bf2c-cddf269f9807
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# remove_copy (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os elementos de cópias de um intervalo de origem para um intervalo de destino, exceto que os elementos de um valor especificado não são copiados, sem afetar a ordem dos elementos restantes e retornar ao final de um novo intervalo de destino.  
  
## Sintaxe  
  
```  
template<class _InIt, class _OutIt, class _Ty> inline  
    _OutIt remove_copy(_InIt _First, _InIt _Last,  
        _OutIt _Dest, const _Ty% _Val);  
```  
  
## Comentários  
 Essa função se comportará da mesma forma como a função `remove_copy`STL.  Para obter mais informações, consulte [remove\_copy](../Topic/remove_copy.md).  
  
## Requisitos  
 cliext \<\/algoritmo de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [algorithm](../Topic/algorithm%20\(STL-CLR\).md)