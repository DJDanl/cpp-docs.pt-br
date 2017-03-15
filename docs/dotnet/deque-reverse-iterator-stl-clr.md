---
title: "deque::reverse_iterator (STL/CLR) | Microsoft Docs"
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
  - "cliext::deque::reverse_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro reverse_iterator [STL/CLR]"
ms.assetid: 82bdfda7-496d-4f8a-8eb8-96bee83b5708
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deque::reverse_iterator (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de um iterador de cima para baixo para a sequência controlada.  
  
## Sintaxe  
  
```  
typedef T3 reverse_iterator;  
```  
  
## Comentários  
 O tipo descreve um objeto do tipo não for especificado `T3` que pode servir como um iterador de cima para baixo para a sequência controlada.  
  
## Exemplo  
  
```  
// cliext_deque_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
    cliext::deque<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" reversed   
    cliext::deque<wchar_t>::reverse_iterator rit = c1.rbegin();   
    for (; rit != c1.rend(); ++rit)   
        System::Console::Write(" {0}", *rit);   
    System::Console::WriteLine();   
  
// alter first element and redisplay   
    rit = c1.rbegin();   
    *rit = L'x';   
    for (; rit != c1.rend(); ++rit)   
        System::Console::Write(" {0}", *rit);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **b para c**  
 **x b a**   
## Requisitos  
 **Cabeçalho:** \<cliext\/deque\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [deque::const\_iterator](../Topic/deque::const_iterator%20\(STL-CLR\).md)   
 [deque::const\_reverse\_iterator](../dotnet/deque-const-reverse-iterator-stl-clr.md)   
 [deque::iterator](../dotnet/deque-iterator-stl-clr.md)