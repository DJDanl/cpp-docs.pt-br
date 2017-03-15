---
title: "queue::back (STL/CLR) | Microsoft Docs"
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
  - "cliext::queue::back"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro posterior [STL/CLR]"
ms.assetid: 983a5c0f-0a2f-475f-932b-e7dec9eaffbb
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# queue::back (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Acessa o elemento pela última vez.  
  
## Sintaxe  
  
```  
reference back();  
```  
  
## Comentários  
 A função de membro retorna uma referência ao elemento o último de sequência controlada, que deve estar vazio.  Use\-a para acessar o elemento o último, quando você souber que existe.  
  
## Exemplo  
  
```  
// cliext_queue_back.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("back() = {0}", c1.back());   
  
// alter last item and reinspect   
    c1.back() = L'x';   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
**back\(\) \= c**  
 **um x b**   
## Requisitos  
 cliext \<\/fila de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [queue](../Topic/queue%20\(STL-CLR\).md)   
 [queue::back\_item](../dotnet/queue-back-item-stl-clr.md)   
 [queue::front](../Topic/queue::front%20\(STL-CLR\).md)   
 [queue::front\_item](../dotnet/queue-front-item-stl-clr.md)