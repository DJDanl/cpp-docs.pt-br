---
title: "Classe add_volatile | Microsoft Docs"
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
  - "std::tr1::add_volatile"
  - "add_volatile"
  - "std.tr1.add_volatile"
  - "std.add_volatile"
  - "std::add_volatile"
  - "type_traits/std::add_volatile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe add_volatile [TR1]"
  - "add_volatile"
ms.assetid: cde57277-d764-402d-841e-97611ebaab14
caps.latest.revision: 21
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe add_volatile
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria tipo volátil do tipo especificado.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct add_volatile;  
  
template<class T>  
using add_volatile_t = typename add_volatile<T>::type;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser modificado.  
  
## Comentários  
 Uma instância do modificador de tipo mantém um tipo modificado que será `Ty` se `Ty` for uma referência, uma função ou um tipo qualificado volátil; caso contrário, será `volatile Ty`.  
  
## Exemplo  
  
```  
#include <type_traits>   
#include <iostream>   
  
int main()   
    {   
    std::add_volatile_t<int> *p = (volatile int *)0;   
  
    p = p;  // to quiet "unused" warning   
    std::cout << "add_volatile<int> == "   
        << typeid(*p).name() << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **add\_volatile\<int\> \=\= int**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe remove\_volatile](../Topic/remove_volatile%20Class.md)