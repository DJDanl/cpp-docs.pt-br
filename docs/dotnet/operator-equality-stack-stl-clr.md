---
title: "operador== (stack) (STL/CLR) | Microsoft Docs"
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
  - "cliext::stack::operator=="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator== [STL/CLR]"
ms.assetid: 862e7130-150a-44ea-9ec4-9f091ab7653d
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador== (stack) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Comparação igual de pilha.  
  
## Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    bool operator==(stack<Value, Container>% left,  
        stack<Value, Container>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo da ser comparada.  
  
 direita  
 Contêiner direito da ser comparada.  
  
## Comentários  
 A função do operador só retornará true se as sequências controladas por `left` e por `right` têm o mesmo tamanho e, para cada posição `i`, `left``[i] ==` `right``[i]`.  Use\-a para testar se `left` é ordenado da mesma forma que `right` quando as duas pilhas elemento são comparados pelo elemento.  
  
## Exemplo  
  
```  
// cliext_stack_operator_eq.cpp   
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
  
// assign to a new container   
    Mystack c2;   
    c2.push(L'a');   
    c2.push(L'b');   
    c2.push(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] == [a b c] is {0}",   
        c1 == c1);   
    System::Console::WriteLine("[a b c] == [a b d] is {0}",   
        c1 == c2);   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **um de b**  
**\[um b c\] \=\= \[um b c\] é true**  
**\[um b c\] \=\= b de um \[\] é false**   
## Requisitos  
 cliext \<\/pilha de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [stack](../dotnet/stack-stl-clr.md)   
 [operador\!\= \(stack\)](../dotnet/operator-inequality-stack-stl-clr.md)   
 [operador\< \(stack\)](../dotnet/operator-less-than-stack-stl-clr.md)   
 [operador\>\= \(stack\)](../Topic/operator%3E=%20\(stack\)%20\(STL-CLR\).md)   
 [operador\> \(stack\)](../dotnet/operator-greater-than-stack-stl-clr.md)   
 [operador\<\= \(stack\)](../dotnet/operator-less-or-equal-stack-stl-clr.md)