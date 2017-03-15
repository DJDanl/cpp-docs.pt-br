---
title: "find_first_of (STL/CLR) | Microsoft Docs"
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
  - "cliext::find_first_of"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função find_first_of [STL/CLR]"
ms.assetid: d559bad4-fc12-4201-af49-db0e7eec48e8
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# find_first_of (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Procura a primeira ocorrência de qualquer um de vários valores em uma carreira de captura ou para a primeira ocorrência de qualquer um de vários elementos que são equivalentes de certo modo especificados por um predicado binário a um conjunto especificado de elementos.  
  
## Sintaxe  
  
```  
template<class _FwdIt1, class _FwdIt2> inline  
    _FwdIt1 find_first_of(_FwdIt1 _First1, _FwdIt1 _Last1,  
        _FwdIt2 _First2, _FwdIt2 _Last2);  
template<class _FwdIt1, class _FwdIt2, class _Pr> inline  
    _FwdIt1 find_first_of(_FwdIt1 _First1, _FwdIt1 _Last1,  
        _FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred);  
```  
  
## Comentários  
 Essa função se comportará da mesma forma como a função `find_first_of`STL.  Para obter mais informações, consulte [find\_first\_of](../Topic/find_first_of.md).  
  
## Requisitos  
 cliext \<\/algoritmo de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [algorithm](../Topic/algorithm%20\(STL-CLR\).md)