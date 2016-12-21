---
title: "Classe is_compound | Microsoft Docs"
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
  - "std::tr1::is_compound"
  - "is_compound"
  - "std.tr1.is_compound"
  - "std.is_compound"
  - "std::is_compound"
  - "type_traits/std::is_compound"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_compound [TR1]"
  - "is_compound"
ms.assetid: bdad1167-cf3f-4f37-8321-62a5df159ead
caps.latest.revision: 21
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_compound
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo especificado não é fundamental.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_compound;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 Contém uma instância do predicado do tipo `false` se o tipo de `Ty` é um tipo fundamental \(isto é, se [is\_fundamental](../standard-library/is-fundamental-class.md)`<``Ty``>` contém `true`\); caso contrário, ele contém `true`.  Portanto, o predicado contém `true` se `Ty` é um tipo de matriz, um tipo de função, um ponteiro para `void` ou um objeto ou uma função, uma referência, uma classe, uma união, uma enumeração, ou um ponteiro para membro não estático de classe ou um *qualificado VC* formulário de um deles.  
  
## Exemplo  
  
```  
// std_tr1__type_traits__is_compound.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct trivial   
    {   
    int val;   
    };   
  
int main()   
    {   
    std::cout << "is_compound<trivial> == " << std::boolalpha   
        << std::is_compound<trivial>::value << std::endl;   
    std::cout << "is_compound<int[]> == " << std::boolalpha   
        << std::is_compound<int[]>::value << std::endl;   
    std::cout << "is_compound<int()> == " << std::boolalpha   
        << std::is_compound<int()>::value << std::endl;   
    std::cout << "is_compound<int&> == " << std::boolalpha   
        << std::is_compound<int&>::value << std::endl;   
    std::cout << "is_compound<void *> == " << std::boolalpha   
        << std::is_compound<void *>::value << std::endl;   
    std::cout << "is_compound<int> == " << std::boolalpha   
        << std::is_compound<int>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **is\_compound \< trivial \> \= \= true**  
**is\_compound \< int \[\] \> \= \= true**  
**is\_compound \< int \(\) \> \= \= true**  
**is\_compound \< int & \> \= \= true**  
**is\_compound \< void \* \> \= \= true**  
**is\_compound \< int \> \= \= false**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe is\_class](../standard-library/is-class-class.md)