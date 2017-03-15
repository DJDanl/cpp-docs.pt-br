---
title: "priority_queue::value_type (STL/CLR) | Microsoft Docs"
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
  - "cliext::priority_queue::value_type"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro value_type [STL/CLR]"
ms.assetid: 0d81ef75-8bd1-44f5-8753-4b42a505d8c3
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# priority_queue::value_type (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de um elemento.  
  
## Sintaxe  
  
```  
typedef Value value_type;  
```  
  
## Comentários  
 O tipo é um sinônimo para o parâmetro `Value`do modelo.  
  
## Exemplo  
  
```  
// cliext_priority_queue_value_type.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::priority_queue<wchar_t> Mypriority_queue;   
int main()   
    {   
    Mypriority_queue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display reversed contents " a b c" using value_type   
    for (; !c1.empty(); c1.pop())   
        {   // store element in value_type object   
        Mypriority_queue::value_type val = c1.top();   
  
        System::Console::Write(" {0}", val);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **b para c**   
## Requisitos  
 cliext \<\/fila de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)   
 [priority\_queue::const\_reference](../dotnet/priority-queue-const-reference-stl-clr.md)   
 [priority\_queue::reference](../dotnet/priority-queue-reference-stl-clr.md)