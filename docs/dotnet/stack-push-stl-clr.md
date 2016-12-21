---
title: "Stack:: push (STL CLR) | Microsoft Docs"
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
  - "cliext::stack::push"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro push [STL/CLR]"
ms.assetid: 60e5b076-c80f-4af0-a018-62cda7e081db
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# stack::push (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona um novo elemento último.  
  
## Sintaxe  
  
```  
void push(value_type val);  
```  
  
## Comentários  
 A função de membro insere um elemento com o valor `val` ao final da sequência controlada. Você pode usá\-lo para anexar outro elemento na pilha.  
  
## Exemplo  
  
```  
// cliext_stack_push.cpp   
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
    return (0);   
    }  
  
```  
  
```Output  
c b  
```  
  
## Requisitos  
 **Cabeçalho:** \< cliext\/pilha \>  
  
 **Namespace:** cliext  
  
## Consulte também  
 [stack](../dotnet/stack-stl-clr.md)   
 [stack::pop](../Topic/stack::pop%20\(STL-CLR\).md)