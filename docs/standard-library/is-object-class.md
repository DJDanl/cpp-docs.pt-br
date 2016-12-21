---
title: "Classe is_object | Microsoft Docs"
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
  - "is_object"
  - "std.tr1.is_object"
  - "std::tr1::is_object"
  - "std.is_object"
  - "std::is_object"
  - "type_traits/std::is_object"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_object [TR1]"
  - "is_object"
ms.assetid: b452ceea-5676-488f-925b-ab881126c387
caps.latest.revision: 19
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_object
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo é um tipo de objeto.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_object;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 Uma instância do predicado do tipo mantém falso se o tipo `Ty` é um tipo de referência, um tipo de função ou nulo, ou um `cv-qualified` formulário de um deles, se aplica.  
  
## Exemplo  
  
```  
// std_tr1__type_traits__is_object.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct trivial   
    {   
    int val;   
    };   
  
struct functional   
    {   
    int f();   
    };   
  
int main()   
    {   
    std::cout << "is_object<trivial> == " << std::boolalpha   
        << std::is_object<trivial>::value << std::endl;   
    std::cout << "is_object<functional> == " << std::boolalpha   
        << std::is_object<functional>::value << std::endl;   
    std::cout << "is_object<trivial&> == " << std::boolalpha   
        << std::is_object<trivial&>::value << std::endl;   
    std::cout << "is_object<float()> == " << std::boolalpha   
        << std::is_object<float()>::value << std::endl;   
    std::cout << "is_object<void> == " << std::boolalpha   
        << std::is_object<void>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **is\_object \< trivial \> \= \= true**  
**is\_object \< funcional \> \= \= true**  
**is\_object \< trivial & \> \= \= false**  
**is\_object \< float\(\) \> \= \= false**  
**is\_object \< void \> \= \= false**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe is\_function](../standard-library/is-function-class.md)