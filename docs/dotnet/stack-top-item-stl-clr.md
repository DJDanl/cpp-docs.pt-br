---
title: "stack::top_item (STL/CLR) | Microsoft Docs"
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
  - "cliext::stack::top_item"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro top_item [STL/CLR]"
ms.assetid: 01571acf-4880-44c4-80c4-bd91408a032d
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# stack::top_item (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Acessa o elemento pela última vez.  
  
## Sintaxe  
  
```  
property value_type top_item;  
```  
  
## Comentários  
 A propriedade acessa o elemento o último de sequência controlada, que deve estar vazio.  Use\-a para ler ou gravar o elemento o último, quando você conhece o existe.  
  
## Exemplo  
  
```  
// cliext_stack_top_item.cpp   
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
  
// inspect last item   
    System::Console::WriteLine("top_item = {0}", c1.top_item);   
  
// alter last item and reinspect   
    c1.top_item = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
**top\_item \= c**  
 **um x b**   
## Requisitos  
 cliext \<\/pilha de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [stack](../dotnet/stack-stl-clr.md)   
 [stack::top](../dotnet/stack-top-stl-clr.md)