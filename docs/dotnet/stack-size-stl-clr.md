---
title: "stack::size (STL/CLR) | Microsoft Docs"
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
  - "cliext::stack::size"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro de tamanho [STL/CLR]"
ms.assetid: 6113e649-a4f9-4021-8131-34cee4bc8ca0
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# stack::size (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conta o número de elementos.  
  
## Sintaxe  
  
```  
size_type size();  
```  
  
## Comentários  
 A função de membro retorna o comprimento da sequência controlada.  Use\-a para determinar atualmente o número de elementos na sequência controlada.  Se tudo o que você precisa se preocupar é aproximadamente se a sequência tiver o tamanho diferente de zero, consulte [stack::empty](../dotnet/stack-empty-stl-clr.md)`()`.  
  
## Exemplo  
  
```  
// cliext_stack_size.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0} starting with 3", c1.size());   
  
// pop an item and reinspect   
    c1.pop();   
    System::Console::WriteLine("size() = {0} after popping", c1.size());   
  
// add two elements and reinspect   
    c1.push(L'a');   
    c1.push(L'b');   
    System::Console::WriteLine("size() = {0} after adding 2", c1.size());   
    return (0);   
    }  
  
```  
  
  **um b c**  
**size\(\) \= 3 começando com 3**  
**2 \= aparecer apóssize\(\)**   
**size\(\) \= 4 depois da adição de 2**   
## Requisitos  
 cliext \<\/pilha de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [stack](../dotnet/stack-stl-clr.md)   
 [stack::empty](../dotnet/stack-empty-stl-clr.md)