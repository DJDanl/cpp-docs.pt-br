---
title: "Classe is_base_of | Microsoft Docs"
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
  - "std.tr1.is_base_of"
  - "is_base_of"
  - "std::tr1::is_base_of"
  - "std.is_base_of"
  - "std::is_base_of"
  - "type_traits/std::is_base_of"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_base_of [TR1]"
  - "is_base_of"
ms.assetid: 436f6213-1d4c-4ffc-a588-fc7c4887dd86
caps.latest.revision: 19
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_base_of
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se um tipo é a base de outro.  
  
## Sintaxe  
  
```  
template<class Base, class Derived>  
    struct is_base_of;  
```  
  
#### Parâmetros  
 `Base`  
 A classe base para testar.  
  
 `Derived`  
 O tipo derivado para testar.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `Base` é uma classe base do tipo `Derived`, caso contrário, manterá false.  
  
## Exemplo  
  
```  
  
#include <type_traits>   
#include <iostream>   
  
struct base   
    {   
    int val;   
    };   
  
struct derived   
    : public base   
    {   
    };   
  
int main()   
    {   
    std::cout << "is_base_of<base, base> == " << std::boolalpha   
        << std::is_base_of<base, base>::value << std::endl;   
    std::cout << "is_base_of<base, derived> == " << std::boolalpha   
        << std::is_base_of<base, derived>::value << std::endl;   
    std::cout << "is_base_of<derived, base> == " << std::boolalpha   
        << std::is_base_of<derived, base>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **is\_base\_of \< base, base de dados de \> \= \= true**  
**is\_base\_of \< base, derivado \> \= \= true**  
**is\_base\_of \< derivada, base \> \= \= false**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe is\_convertible](../standard-library/is-convertible-class.md)