---
title: "Classe, bool_constant classe integral_constant | Microsoft Docs"
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
  - "std.tr1.integral_constant"
  - "integral_constant"
  - "std::tr1::integral_constant"
  - "std.integral_constant"
  - "std::integral_constant"
  - "type_traits/std::integral_constant"
  - "std.bool_constant"
  - "std::bool_constant"
  - "type_traits/std::bool_constant"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe integral_constant [TR1]"
  - "integral_constant"
  - "bool_constant"
ms.assetid: 11c002c6-4d31-4042-9341-f2543f43e108
caps.latest.revision: 23
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe, bool_constant classe integral_constant
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Torna constante integral de um tipo e valor.  
  
## Sintaxe  
  
```  
template <class T, T v>  
    struct integral_constant {  
        static constexpr T value = v;  
        typedef T value_type;  
        typedef integral_constant<T, v> type;  
        constexpr operator value_type() const noexcept { return (value); }  
        constexpr value_type operator()() const noexcept { return (value); }  
    };  
  
template <bool v>  
    using bool_constant = integral_constant<bool, v>;  
  
```  
  
#### Parâmetros  
 `T`  
 O tipo da constante.  
  
 `v`  
 O valor da constante.  
  
## Comentários  
 O `integral_constant` classe de modelo, quando especializadas com um tipo integral `T` e um valor `v` desse tipo, representa um objeto que contém uma constante desse tipo integral com o valor especificado. O membro denominado `type` é um alias para o tipo de especialização de modelo gerado e o `value` membro contém o valor `v` usado para criar a especialização.  
  
 O `bool_constant` classe de modelo é uma especialização parcial explícita de `integral_constant` que usa `bool` como o `T` argumento.  
  
## Exemplo  
  
```cpp  
// std__type_traits__integral_constant.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
int main()   
    {   
    std::cout << "integral_constant<int, 5> == "   
        << std::integral_constant<int, 5>::value << std::endl;   
    std::cout << "integral_constant<bool, false> == " << std::boolalpha   
        << std::integral_constant<bool, false>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
5 < int > integral_constant = = 5 integral_constant < bool, false > = = false  
```  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Typedef false\_type](../Topic/false_type%20Typedef.md)   
 [Typedef true\_type](../Topic/true_type%20Typedef.md)