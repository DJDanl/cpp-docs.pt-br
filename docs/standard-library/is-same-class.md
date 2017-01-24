---
title: "Classe is_same | Microsoft Docs"
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
  - "std::tr1::is_same"
  - "std.tr1.is_same"
  - "is_same"
  - "std.is_same"
  - "std::is_same"
  - "type_traits/std::is_same"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_same [TR1]"
  - "is_same"
ms.assetid: d9df6c1d-c270-4ec2-802a-af275648dd1d
caps.latest.revision: 19
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_same
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se dois tipos são os mesmos.  
  
## Sintaxe  
  
```  
template<class Ty1, class Ty2>  
    struct is_same;  
```  
  
#### Parâmetros  
 `Ty1`  
 O primeiro tipo de consulta.  
  
 `Ty2`  
 O segundo tipo de consulta.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se os tipos de `Ty1` e `Ty2` são do mesmo tipo, caso contrário, manterá false.  
  
## Exemplo  
  
```  
// std_tr1__type_traits__is_same.cpp   
// compile with: /EHsc   
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
    std::cout << "is_same<base, base> == " << std::boolalpha   
        << std::is_same<base, base>::value << std::endl;   
    std::cout << "is_same<base, derived> == " << std::boolalpha   
        << std::is_same<base, derived>::value << std::endl;   
    std::cout << "is_same<derived, base> == " << std::boolalpha   
        << std::is_same<derived, base>::value << std::endl;   
    std::cout << "is_same<int, int> == " << std::boolalpha   
        << std::is_same<int, int>::value << std::endl;   
    std::cout << "is_same<int, const int> == " << std::boolalpha   
        << std::is_same<int, const int>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **is\_same \< base, base de dados de \> \= \= true**  
**is\_same \< base, derivado \> \= \= false**  
**is\_same \< derivada, base \> \= \= false**  
**is\_same \< int, int \> \= \= true**  
**is\_same \< int, int const \> \= \= false**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe is\_convertible](../standard-library/is-convertible-class.md)   
 [Classe is\_base\_of](../standard-library/is-base-of-class.md)