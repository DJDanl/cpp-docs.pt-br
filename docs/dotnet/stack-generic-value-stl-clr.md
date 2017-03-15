---
title: "stack::generic_value (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::stack::generic_value"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro generic_value [STL/CLR]"
ms.assetid: f918f5e6-5cb6-480e-8548-13e15026ffde
caps.latest.revision: 8
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# stack::generic_value (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de um elemento para uso com a interface genérica para o contêiner.  
  
## Sintaxe  
  
```  
typedef GValue generic_value;  
```  
  
## Comentários  
 O tipo descreve um objeto do tipo `GValue` que descreve o valor armazenado do elemento para uso com a interface genérica para esta classe do contêiner do modelo. \(`GValue` é `value_type` ou `value_type^` se `value_type` é um tipo de referência.\)  
  
## Exemplo  
  
```  
// cliext_stack_generic_value.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// get interface to container   
    Mystack::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1->get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display in reverse using generic_value   
    for (; !gc1->empty(); gc1->pop())   
        {   
        Mystack::generic_value elem = gc1->top();   
  
        System::Console::Write(" {0}", elem);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **um b c**  
 **b para c**   
## Requisitos  
 cliext \<\/pilha de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [stack](../dotnet/stack-stl-clr.md)   
 [stack::generic\_container](../Topic/stack::generic_container%20\(STL-CLR\).md)   
 [stack::value\_type](../dotnet/stack-value-type-stl-clr.md)