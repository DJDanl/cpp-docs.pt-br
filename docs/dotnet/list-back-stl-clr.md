---
title: "list::back (STL/CLR) | Microsoft Docs"
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
  - "cliext::list::back"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro posterior [STL/CLR]"
ms.assetid: 3241e497-42ab-4108-8598-3f90eac76f07
caps.latest.revision: 18
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::back (STL/CLR)
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
// cliext_list_back.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
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
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::back\_item](../Topic/list::back_item%20\(STL-CLR\).md)   
 [list::front](../dotnet/list-front-stl-clr.md)   
 [list::front\_item \(STL\/CLR\)](../dotnet/list-front-item-stl-clr.md)