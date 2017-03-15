---
title: "map::const_reverse_iterator (STL/CLR) | Microsoft Docs"
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
  - "cliext::map::const_reverse_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro const_reverse_iterator [STL/CLR]"
ms.assetid: 056a765c-4f59-4bd8-99f4-c308a6f29c12
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# map::const_reverse_iterator (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de um iterador invertido constante para a sequência controlada.  
  
## Sintaxe  
  
```  
typedef T4 const_reverse_iterator;  
```  
  
## Comentários  
 O tipo descreve um objeto do tipo não for especificado `T4` que pode servir como um iterador invertido constante para a sequência controlada.  
  
## Exemplo  
  
```  
// cliext_map_const_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/map>   
  
typedef cliext::map<wchar_t, int> Mymap;   
int main()   
    {   
    Mymap c1;   
    c1.insert(Mymap::make_value(L'a', 1));   
    c1.insert(Mymap::make_value(L'b', 2));   
    c1.insert(Mymap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]" reversed   
    Mymap::const_reverse_iterator crit = c1.rbegin();   
    for (; crit != c1.rend(); ++crit)   
        System::Console::Write(" [{0} {1}]", crit->first, crit->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **c \[3\] \[2\] \[bum 1\]**   
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [map](../dotnet/map-stl-clr.md)   
 [map::reverse\_iterator](../dotnet/map-reverse-iterator-stl-clr.md)