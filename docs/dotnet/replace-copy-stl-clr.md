---
title: "replace_copy (STL/CLR) | Microsoft Docs"
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
  - "cliext::replace_copy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função replace_copy [STL/CLR]"
ms.assetid: b531b49b-b16d-4b04-8f80-74f43dd496a4
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# replace_copy (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Examinará cada elemento em um intervalo de origem e substitua\-o se corresponde a um valor especificado ao copiar o resultado em um novo intervalo de destino.  
  
## Sintaxe  
  
```  
template<class _InIt, class _OutIt, class _Ty> inline  
    _OutIt replace_copy(_InIt _First, _InIt _Last, _OutIt _Dest,  
        const _Ty% _Oldval, const _Ty% _Newval);  
```  
  
## Comentários  
 Essa função se comportará da mesma forma como a função `replace_copy`STL.  Para obter mais informações, consulte [replace\_copy](../Topic/replace_copy.md).  
  
## Requisitos  
 cliext \<\/algoritmo de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [algorithm](../Topic/algorithm%20\(STL-CLR\).md)