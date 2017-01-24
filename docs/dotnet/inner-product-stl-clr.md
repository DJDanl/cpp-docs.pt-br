---
title: "inner_product (STL/CLR) | Microsoft Docs"
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
  - "cliext::inner_product"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função inner_product [STL/CLR]"
ms.assetid: 97d7a507-7494-4216-aedf-0546ed0edb3f
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# inner_product (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Calcula a soma de produto de elemento em dois intervalos e adicioná\-la a um valor inicial especificado ou computar\-lo o resultado de um procedimento generalizado que a soma e operações binários do produto são substituídas por outras operações binários especificadas.  
  
## Sintaxe  
  
```  
template<class _InIt1, class _InIt2, class _Ty> inline  
    _Ty inner_product(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2,  
        _Ty _Val);  
template<class _InIt1, class _InIt2, class _Ty, class _Fn21,  
       class _Fn22> inline  
    _Ty inner_product(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2,  
        _Ty _Val, _Fn21 _Func1, _Fn22 _Func2);  
```  
  
## Comentários  
 Essa função se comporta semelhante à função numérica `inner_product`STL.  Para obter mais informações, consulte [inner\_product](../Topic/inner_product.md).  
  
## Requisitos  
 cliext \<de**Cabeçalho:** \/numérico\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [numérico](../dotnet/numeric-stl-clr.md)