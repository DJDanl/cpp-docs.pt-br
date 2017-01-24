---
title: "deque::back (STL/CLR) | Microsoft Docs"
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
  - "cliext::deque::back"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro posterior [STL/CLR]"
ms.assetid: 5608cdda-212d-42f6-866b-b04aec04ef8e
caps.latest.revision: 18
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deque::back (STL/CLR)
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
// cliext_deque_back.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
    cliext::deque<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last item   
    System::Console::WriteLine("back() = {0}", c1.back());   
  
// alter last item and reinspect   
    c1.back() = L'x';   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
**back\(\) \= c**  
 **um x b**   
## Requisitos  
 **Cabeçalho:** \<cliext\/deque\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [deque::back\_item](../Topic/deque::back_item%20\(STL-CLR\).md)   
 [deque::front](../Topic/deque::front%20\(STL-CLR\).md)   
 [deque::front\_item](../dotnet/deque-front-item-stl-clr.md)