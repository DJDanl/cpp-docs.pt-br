---
title: "map::rbegin (STL/CLR) | Microsoft Docs"
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
  - "cliext::map::rbegin"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro rbegin [STL/CLR]"
ms.assetid: bd7165a3-561f-48d4-9791-7aaafc2cf3a5
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# map::rbegin (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Designa o início da sequência controlada invertida.  
  
## Sintaxe  
  
```  
reverse_iterator rbegin();  
```  
  
## Comentários  
 A função de membro retorna um iterador invertido que designa o elemento o último de sequência controlada, ou apenas além do início de uma sequência vazia.  Consequentemente, designa `beginning` de sequência inversa.  Use\-a para obter um iterador que designa o início de `current` de sequência controlada consultada em ordem inversa, mas seu status pode ser alterado se o comprimento da sequência controlada é alterado.  
  
## Exemplo  
  
```  
// cliext_map_rbegin.cpp   
// compile with: /clr   
#include <cliext/map>   
  
typedef cliext::map<wchar_t, int> Mymap;   
int main()   
    {   
    Mymap c1;   
    c1.insert(Mymap::make_value(L'a', 1));   
    c1.insert(Mymap::make_value(L'b', 2));   
    c1.insert(Mymap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Mymap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect first two items in reversed sequence   
    Mymap::reverse_iterator rit = c1.rbegin();   
    System::Console::WriteLine("*rbegin() = [{0} {1}]",   
        rit->first, rit->second);   
    ++rit;   
    System::Console::WriteLine("*++rbegin() = [{0} {1}]",   
        rit->first, rit->second);   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
**\= \[\*rbegin\(\) 3 c\]**  
**\= \[\*\+\+rbegin\(\) b 2\]**   
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [map](../dotnet/map-stl-clr.md)   
 [map::begin](../dotnet/map-begin-stl-clr.md)   
 [map::end](../dotnet/map-end-stl-clr.md)   
 [map::rend](../dotnet/map-rend-stl-clr.md)