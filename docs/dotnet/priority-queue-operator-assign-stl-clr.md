---
title: "priority_queue::operator= (STL/CLR) | Microsoft Docs"
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
  - "cliext::priority_queue::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator= [STL/CLR]"
ms.assetid: 796b4ad2-3e40-49e8-8462-87460d086fe4
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# priority_queue::operator= (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Substitui a sequência controlada.  
  
## Sintaxe  
  
```  
priority_queue <Value, Container>% operator=(priority_queue <Value, Container>% right);  
```  
  
#### Parâmetros  
 direita  
 Adaptador do contêiner a ser copiada.  
  
## Comentários  
 O membro que o operador copia `right` ao objeto, retornará `*this`.  Você usará para substituir a sequência controlada por uma cópia de sequência controlada em `right`.  
  
## Exemplo  
  
```  
// cliext_priority_queue_operator_as.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::priority_queue<wchar_t> Mypriority_queue;   
int main()   
    {   
    Mypriority_queue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mypriority_queue c2;   
    c2 = c1;   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **c um b**  
 **c um b**   
## Requisitos  
 cliext \<\/fila de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)   
 [priority\_queue::assign](../dotnet/priority-queue-assign-stl-clr.md)