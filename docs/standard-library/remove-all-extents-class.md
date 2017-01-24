---
title: "Classe remove_all_extents | Microsoft Docs"
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
  - "std.tr1.remove_all_extents"
  - "std::tr1::remove_all_extents"
  - "remove_all_extents"
  - "std.remove_all_extents"
  - "std::remove_all_extents"
  - "type_traits/std::remove_all_extents"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe remove_all_extents [TR1]"
  - "remove_all_extents"
ms.assetid: 548dc536-82e7-423a-b8c1-443d66d9632e
caps.latest.revision: 16
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe remove_all_extents
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria tipo de não matriz do tipo de matriz.  
  
## Sintaxe  
  
```  
template<class T>  
    struct remove_all_extents;  
  
template<class T>  
  using remove_all_extents_t = typename remove_all_extents<T>::type;  
```  
  
#### Parâmetros  
 `T`  
 O tipo a ser modificado.  
  
## Comentários  
 Uma instância de `remove_all_extents<T>` mantém um tipo modificado que é o tipo de elemento do tipo de matriz `T` com todas as dimensões da matriz removidas ou `T` se `T` não for um tipo de matriz.  
  
## Exemplo  
  
```  
#include <type_traits>   
#include <iostream>   
  
int main()   
    {   
    std::cout << "remove_all_extents<int> == "   
        << typeid(std::remove_all_extents_t<int>).name()   
        << std::endl;   
    std::cout << "remove_all_extents_t<int[5]> == "   
        << typeid(std::remove_all_extents_t<int[5]>).name()   
        << std::endl;   
    std::cout << "remove_all_extents_t<int[5][10]> == "   
        << typeid(std::remove_all_extents_t<int[5][10]>).name()   
        << std::endl;   
  
    return (0);   
    }  
  
```  
  
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe remove\_extent](../standard-library/remove-extent-class.md)