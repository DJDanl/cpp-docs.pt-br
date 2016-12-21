---
title: "Classe is_convertible | Microsoft Docs"
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
  - "is_convertible"
  - "std.tr1.is_convertible"
  - "std::tr1::is_convertible"
  - "std.is_convertible"
  - "std::is_convertible"
  - "type_traits/std::is_convertible"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_convertible [TR1]"
  - "is_convertible"
ms.assetid: 75614008-1894-42ea-bd57-974399628536
caps.latest.revision: 19
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_convertible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se um tipo é convertido em outro.  
  
## Sintaxe  
  
```  
template<class From, class To>  
    struct is_convertible;  
```  
  
#### Parâmetros  
 `From`  
 O tipo para converter.  
  
 `Ty`  
 O tipo no qual converter.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se a expressão `To to = from;`, onde `from` é um objeto do tipo `From`, está bem formado.  
  
## Exemplo  
  
```  
// std_tr1__type_traits__is_convertible.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct trivial   
    {   
    int val;   
    };   
  
int main()   
    {   
    std::cout << "is_convertible<trivial, int> == " << std::boolalpha   
        << std::is_convertible<trivial, int>::value << std::endl;   
    std::cout << "is_convertible<trivial, trivial> == " << std::boolalpha   
        << std::is_convertible<trivial, trivial>::value << std::endl;   
    std::cout << "is_convertible<char, int> == " << std::boolalpha   
        << std::is_convertible<char, int>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **is\_convertible \< trivial, int \> \= \= false**  
**is\_convertible \< trivial, trivial \> \= \= true**  
**is\_convertible \< char, int \> \= \= true**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe is\_base\_of](../standard-library/is-base-of-class.md)