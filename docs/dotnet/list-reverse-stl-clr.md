---
title: "List:: reverse (STL CLR) | Microsoft Docs"
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
  - "cliext::list::reverse"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro reverse [STL/CLR]"
ms.assetid: de3bce1e-01fe-461d-a785-5cf4fcea988f
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::reverse (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inverte a sequência controlada.  
  
## Sintaxe  
  
```  
void reverse();  
```  
  
## Comentários  
 A função de membro inverte a ordem de todos os elementos na sequência controlada. Você pode usá\-lo para refletir uma lista de elementos.  
  
## Exemplo  
  
```  
// cliext_list_reverse.cpp   
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
  
// reverse and redisplay   
    c1.reverse();   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
b b c c um  
```  
  
## Requisitos  
 **Cabeçalho:** \< cliext\/lista \>  
  
 **Namespace:** cliext  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::sort](../dotnet/list-sort-stl-clr.md)