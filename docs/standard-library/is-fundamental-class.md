---
title: "Classe is_fundamental | Microsoft Docs"
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
  - "is_fundamental"
  - "std.tr1.is_fundamental"
  - "std::tr1::is_fundamental"
  - "std.is_fundamental"
  - "std::is_fundamental"
  - "type_traits/std::is_fundamental"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_fundamental [TR1]"
  - "is_fundamental"
ms.assetid: b84eee84-2fb2-4611-beaf-b384074d8b6a
caps.latest.revision: 19
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_fundamental
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo é nulo ou aritmética.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_fundamental;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `Ty` é um tipo fundamental, ou seja, `void`, um tipo integral, um flutuante, tipo de ponto ou uma `cv-qualified` formulário de um deles, caso contrário, manterá false.  
  
## Exemplo  
  
```  
// std_tr1__type_traits__is_fundamental.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct trivial   
    {   
    int val;   
    };   
  
int main()   
    {   
    std::cout << "is_fundamental<trivial> == " << std::boolalpha   
        << std::is_fundamental<trivial>::value << std::endl;   
    std::cout << "is_fundamental<int> == " << std::boolalpha   
        << std::is_fundamental<int>::value << std::endl;   
    std::cout << "is_fundamental<const float> == " << std::boolalpha   
        << std::is_fundamental<const float>::value << std::endl;   
    std::cout << "is_fundamental<void> == " << std::boolalpha   
        << std::is_fundamental<void>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **is\_fundamental \< trivial \> \= \= false**  
**is\_fundamental \< int \> \= \= true**  
**is\_fundamental \< const float \> \= \= true**  
**is\_fundamental \< void \> \= \= true**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe is\_compound](../standard-library/is-compound-class.md)