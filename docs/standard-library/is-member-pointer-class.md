---
title: "Classe is_member_pointer | Microsoft Docs"
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
  - "std::tr1::is_member_pointer"
  - "is_member_pointer"
  - "std.tr1.is_member_pointer"
  - "std.is_member_pointer"
  - "std::is_member_pointer"
  - "type_traits/std::is_member_pointer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_member_pointer [TR1]"
  - "is_member_pointer"
ms.assetid: da07ff4e-9ee0-4baa-ad93-1741f10913d1
caps.latest.revision: 19
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_member_pointer
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo é um ponteiro para o membro.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_member_pointer;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo para consulte.  
  
## Comentários  
 Uma instância do predicado do tipo se aplica se o tipo `Ty` é um ponteiro para a função de membro ou um ponteiro para o objeto do membro, ou um formulário de `cv-qualified` de um deless, se não mantém false.  
  
## Exemplo  
  
```  
// std_tr1__type_traits__is_member_pointer.cpp   
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
    std::cout << "is_member_pointer<trivial *> == "   
        << std::boolalpha   
        << std::is_member_pointer<trivial *>::value   
        << std::endl;   
    std::cout << "is_member_pointer<int trivial::*> == "   
        << std::boolalpha   
        << std::is_member_pointer<int trivial::*>::value   
        << std::endl;   
    std::cout << "is_member_pointer<int (functional::*)()> == "   
        << std::boolalpha   
        << std::is_member_pointer<int (functional::*)()>::value   
        << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **is\_member\_pointertrivial\<\*\> \=\= false**  
**\=\=\<de trivial::\*\> de is\_member\_pointerint true**  
**\=\=\<de is\_member\_pointerint \(functional::\*\) \(true\)\>**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe is\_member\_function\_pointer](../Topic/is_member_function_pointer%20Class.md)   
 [Classe is\_member\_object\_pointer](../standard-library/is-member-object-pointer-class.md)   
 [Classe is\_pointer](../standard-library/is-pointer-class.md)