---
title: "stack::stack (STL/CLR) | Microsoft Docs"
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
  - "cliext::stack::stack"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro de pilha [STL/CLR]"
ms.assetid: f1cfb3fe-4d22-41e5-906b-e8faa0bcde9b
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# stack::stack (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto do adaptador do contêiner.  
  
## Sintaxe  
  
```  
stack();  
stack(stack<Value, Container>% right);  
stack(stack<Value, Container>^ right);  
explicit stack(container_type% wrapped);  
```  
  
#### Parâmetros  
 direita  
 Objeto a ser copiado.  
  
 ajustado  
 Contêiner ajustado a ser usado.  
  
## Comentários  
 O construtor:  
  
 `stack();`  
  
 cria um contêiner de conjunto vazio.  Use\-a para especificar uma sequência vazia inicial controlada.  
  
 O construtor:  
  
 `stack(stack<Value, Container>% right);`  
  
 cria um contêiner ajustado que é uma cópia de `right.get_container()`.  São utilizados para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de pilha.  
  
 O construtor:  
  
 `stack(stack<Value, Container>^ right);`  
  
 cria um contêiner ajustado que é uma cópia de `right->get_container()`.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `*right`de pilha.  
  
 O construtor:  
  
 `explicit stack(container_type% wrapped);`  
  
 usa o contêiner existente `wrapped` como o contêiner ajustado.  Você usa para construir uma pilha de um contêiner existente.  
  
## Exemplo  
  
```  
// cliext_stack_construct.cpp   
// compile with: /clr   
#include <cliext/stack>   
#include <cliext/vector>   
  
typedef cliext::stack<wchar_t> Mystack;   
typedef cliext::vector<wchar_t> Myvector;   
typedef cliext::stack<wchar_t, Myvector> Mystack_vec;   
int main()   
    {   
// construct an empty container   
    Mystack c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct from an underlying container   
    Myvector v2(5, L'x');   
    Mystack_vec c2(v2);       
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Mystack_vec c3(c2);   
    for each (wchar_t elem in c3.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container through handle   
    Mystack_vec c4(%c2);   
    for each (wchar_t elem in c4.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **size\(\) \= 0**  
 **x x x x x**  
 **x x x x x**  
 **x x x x x**   
## Requisitos  
 cliext \<\/pilha de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [stack](../dotnet/stack-stl-clr.md)   
 [stack::assign](../Topic/stack::assign%20\(STL-CLR\).md)   
 [stack::generic\_container](../Topic/stack::generic_container%20\(STL-CLR\).md)   
 [stack::operator\=](../dotnet/stack-operator-assign-stl-clr.md)