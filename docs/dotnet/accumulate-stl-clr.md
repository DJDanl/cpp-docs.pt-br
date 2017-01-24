---
title: "accumulate (STL/CLR) | Microsoft Docs"
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
  - "cliext::accumulate"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função accumulate [STL/CLR]"
ms.assetid: b80e1ef1-1858-4c1d-817b-c42ad1f17a2f
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# accumulate (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Calcula a soma de todos os elementos em um intervalo especificado que inclui qualquer valor inicial calculando somas parciais sucessivas ou calcula o resultado de resultados parciais sucessivos obtidos da mesma forma de usar uma operação binária especificada diferente da soma.  
  
## Sintaxe  
  
```  
template<class _InIt, class _Ty> inline  
    _Ty accumulate(_InIt _First, _InIt _Last, _Ty _Val);  
template<class _InIt, class _Ty, class _Fn2> inline  
    _Ty accumulate(_InIt _First, _InIt _Last, _Ty _Val, _Fn2 _Func);  
```  
  
## Comentários  
 Essa função se comporta semelhante à função numérica `accumulate`STL.  Para obter mais informações, consulte [accumulate](../Topic/accumulate.md).  
  
## Requisitos  
 cliext \<de**Cabeçalho:** \/numérico\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [numérico](../dotnet/numeric-stl-clr.md)