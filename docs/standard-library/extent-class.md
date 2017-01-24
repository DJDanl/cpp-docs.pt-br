---
title: "Classe extent | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std.tr1.extent"
  - "extent"
  - "std::tr1::extent"
  - "std.extent"
  - "std::extent"
  - "type_traits/std::extent"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe extent [TR1]"
  - "extent"
ms.assetid: 6d16263d-90b2-4330-9ec7-b59ed898792d
caps.latest.revision: 20
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe extent
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém uma dimensão de matriz.  
  
## Sintaxe  
  
```  
template<class Ty, unsigned I = 0>  
    struct extent;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
 `I`  
 A matriz associado à consulta.  
  
## Comentários  
 Se `Ty` é um tipo de matriz que tenha pelo menos `I` dimensões, a consulta de tipo contém o número de elementos na dimensão especificada pelo `I`.  Se `Ty` não é um tipo de matriz ou sua classificação é menor que `I`, ou se `I` for zero e `Ty` é do tipo "array desconhecido associado do `U`", a consulta de tipo mantém o valor 0.  
  
## Exemplo  
  
```  
// std_tr1__type_traits__extent.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
int main()   
    {   
    std::cout << "extent 0 == "   
        << std::extent<int[5][10]>::value << std::endl;   
    std::cout << "extent 1 == "   
        << std::extent<int[5][10], 1>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **extensão 0 \= \= 5**  
**1 ponto \= \= 10**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe remove\_all\_extents](../standard-library/remove-all-extents-class.md)   
 [Classe remove\_extent](../standard-library/remove-extent-class.md)