---
title: "Classe add_rvalue_reference | Microsoft Docs"
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
  - "type_traits/std::add_rvalue_reference"
  - "std::add_rvalue_reference"
  - "add_rvalue_reference"
  - "std.add_rvalue_reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe add_rvalue_reference"
ms.assetid: 76b0cb7c-1031-45d0-b409-f03ab0297580
caps.latest.revision: 11
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe add_rvalue_reference
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um tipo de referência rvalue de parâmetro do modelo, se for um tipo de objeto ou função. Caso contrário, devido a semântica de recolhimento de referência, o tipo é o mesmo que o parâmetro do modelo.  
  
## Sintaxe  
  
```cpp  
template<class T>  
    struct add_rvalue_reference;  
  
template<class T>  
    using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;  
```  
  
#### Parâmetros  
 T  
 O tipo para modificar.  
  
## Comentários  
 O `add_rvalue_reference` classe tem um membro chamado `type`, que é um alias para o tipo de uma referência rvalue para o parâmetro de modelo `T`. A semântica de recolhimento de referência implica que, para tipos diferentes de objeto e não\-função `T`, `T&&` é um `T`. Por exemplo, quando `T` é um tipo de referência de lvalue,  `add_rvalue_reference<T>::type` é o tipo de referência de lvalue, não uma referência de rvalue.  
  
 Para sua conveniência, \< type\_traits \> define um modelo de auxiliar, `add_rvalue_reference_t`, que aliases a `type` membro do `add_rvalue_reference`.  
  
## Exemplo  
 Este exemplo de código usa static\_assert para mostrar como os tipos de referência rvalue são criados usando `add_rvalue_reference` e `add_rvalue_reference_t`, e como o resultado de `add_rvalue_reference` em uma referência de lvalue tipo não é uma referência de rvalue, mas recolhe ao tipo de referência l\-value.  
  
```cpp  
// ex_add_rvalue_reference.cpp  
// Build by using: cl /EHsc /W4 ex_add_rvalue_reference.cpp  
#include <type_traits>   
#include <iostream>   
#include <string>  
  
using namespace std;  
int main()  
{  
    static_assert(is_same<add_rvalue_reference<string>::type, string&&>::value,   
        "Expected add_rvalue_reference_t<string> to be string&&");  
    static_assert(is_same<add_rvalue_reference_t<string*>, string*&&>::value,   
        "Expected add_rvalue_reference_t<string*> to be string*&&");  
    static_assert(is_same<add_rvalue_reference<string&>::type, string&>::value,   
        "Expected add_rvalue_reference_t<string&> to be string&");  
    static_assert(is_same<add_rvalue_reference_t<string&&>, string&&>::value,   
        "Expected add_rvalue_reference_t<string&&> to be string&&");  
    cout << "All static_assert tests of add_rvalue_reference passed." << endl;  
    return 0;  
}  
  
/*Output:  
All static_assert tests of add_rvalue_reference passed.  
*/  
```  
  
## Requisitos  
 Cabeçalho: \< type\_traits \> Namespace: std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe add\_lvalue\_reference](../standard-library/add-lvalue-reference-class.md)   
 [Classe is\_rvalue\_reference](../Topic/is_rvalue_reference%20Class.md)