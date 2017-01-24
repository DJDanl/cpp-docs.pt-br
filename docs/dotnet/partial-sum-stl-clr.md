---
title: "partial_sum (STL/CLR) | Microsoft Docs"
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
  - "cliext::partial_sum"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função partial_sum [STL/CLR]"
ms.assetid: 845badae-8519-4ac8-9ea7-2b921bac7c51
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# partial_sum (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Computa uma série de somas em um intervalo de entrada do primeiro elemento no elemento do º de `i`e armazena o resultado de cada uma dessas soma no elemento do º de `i`de um intervalo de destino ou calcula o resultado de um procedimento generalizado em que a operação de soma seja substituída por outra operação binária especificada.  
  
## Sintaxe  
  
```  
template<class _InIt, class _OutIt> inline  
    _OutIt partial_sum(_InIt _First, _InIt _Last, _OutIt _Dest);  
template<class _InIt, class _OutIt, class _Fn2> inline  
    _OutIt partial_sum(_InIt _First, _InIt _Last,  
        _OutIt _Dest, _Fn2 _Func);  
```  
  
## Comentários  
 Essa função se comporta semelhante à função numérica `partial_sum`STL.  Para obter mais informações, consulte [partial\_sum](../Topic/partial_sum.md).  
  
## Requisitos  
 cliext \<de**Cabeçalho:** \/numérico\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [numérico](../dotnet/numeric-stl-clr.md)