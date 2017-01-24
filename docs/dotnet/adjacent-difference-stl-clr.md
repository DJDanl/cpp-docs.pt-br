---
title: "adjacent_difference (STL/CLR) | Microsoft Docs"
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
  - "cliext::adjacent_difference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função adjacent_difference"
ms.assetid: 2b462e2e-b8f2-4b2e-9b87-5f688d8da9f4
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# adjacent_difference (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Computa as diferenças entre sucessivas cada elemento e seus serviços em um intervalo de entrada e saída dos resultados em um intervalo de destino ou calcula o resultado de um procedimento generalizado em que a operação de diferença é substituída por outra operação binária, especificada.  
  
## Sintaxe  
  
```  
template<class _InIt, class _OutIt> inline  
    _OutIt adjacent_difference(_InIt _First, _InIt _Last,  
        _OutIt _Dest);  
template<class _InIt, class _OutIt, class _Fn2> inline  
    _OutIt adjacent_difference(_InIt _First, _InIt _Last,  
        _OutIt _Dest, _Fn2 _Func);  
```  
  
## Comentários  
 Essa função se comporta semelhante à função numérica `adjacent_difference`STL.  Para obter mais informações, consulte [adjacent\_difference](../Topic/adjacent_difference.md).  
  
## Requisitos  
 cliext \<de**Cabeçalho:** \/numérico\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [numérico](../dotnet/numeric-stl-clr.md)