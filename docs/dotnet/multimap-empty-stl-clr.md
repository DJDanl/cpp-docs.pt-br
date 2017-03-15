---
title: "multimap::empty (STL/CLR) | Microsoft Docs"
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
  - "cliext::multimap::empty"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro vazio [STL/CLR]"
ms.assetid: 6214279b-289a-4843-a52a-2034667a2ba3
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multimap::empty (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se nenhum elemento estiver presente.  
  
## Sintaxe  
  
```  
bool empty();  
```  
  
## Comentários  
 A função de membro retorna true para uma sequência vazia controlada.  É equivalente a [multimap::size](../Topic/multimap::size%20\(STL-CLR\).md)`() == 0`.  Você usa para testar se o multimap está vazia.  
  
## Exemplo  
  
```  
// cliext_multimap_empty.cpp   
// compile with: /clr   
#include <cliext/map>   
  
typedef cliext::multimap<wchar_t, int> Mymultimap;   
int main()   
    {   
    Mymultimap c1;   
    c1.insert(Mymultimap::make_value(L'a', 1));   
    c1.insert(Mymultimap::make_value(L'b', 2));   
    c1.insert(Mymultimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Mymultimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
**size\(\) \= 3**  
**empty\(\) \= false**  
**size\(\) \= 0**  
**empty\(\) \= retifica**   
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multimapa](../dotnet/multimap-stl-clr.md)   
 [multimap::size](../Topic/multimap::size%20\(STL-CLR\).md)