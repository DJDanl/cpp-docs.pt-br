---
title: "set::generic_value (STL/CLR) | Microsoft Docs"
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
  - "cliext::set::generic_value"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro generic_value [STL/CLR]"
ms.assetid: bdb11400-c7b8-466f-abae-5c878e7721c2
caps.latest.revision: 8
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# set::generic_value (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de um elemento para uso com a interface genérica para o contêiner.  
  
## Sintaxe  
  
```  
typedef GValue generic_value;  
```  
  
## Comentários  
 O tipo descreve um objeto do tipo `GValue` que descreve o valor armazenado do elemento para uso com a interface genérica para esta classe do contêiner do modelo.  
  
## Exemplo  
  
```  
// cliext_set_generic_value.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::set<wchar_t> Myset;   
int main()   
    {   
    Myset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct a generic container   
    Myset::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// get an element and display it   
    Myset::generic_iterator gcit = gc1->begin();   
    Myset::generic_value gcval = *gcit;   
    System::Console::WriteLine(" {0}", gcval);   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **um b c**  
 **a**   
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [set](../dotnet/set-stl-clr.md)   
 [set::generic\_container](../dotnet/set-generic-container-stl-clr.md)   
 [set::generic\_iterator](../dotnet/set-generic-iterator-stl-clr.md)   
 [set::generic\_reverse\_iterator](../Topic/set::generic_reverse_iterator%20\(STL-CLR\).md)