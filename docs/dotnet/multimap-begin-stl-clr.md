---
title: "multimap::begin (STL/CLR) | Microsoft Docs"
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
  - "cliext::multimap::begin"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "iniciar membro [STL/CLR]"
ms.assetid: 2e1e48f5-31e5-4ead-abae-bb5220925226
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multimap::begin (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Designa o início da sequência controlada.  
  
## Sintaxe  
  
```  
iterator begin();  
```  
  
## Comentários  
 A função de membro retorna um iterador bidirecional que designa o primeiro elemento da sequência controlada, ou apenas além do de uma sequência vazia.  Use\-a para obter um iterador que designa o início de `current` de sequência controlada, mas seu status pode ser alterado se o comprimento da sequência controlada é alterado.  
  
## Exemplo  
  
```  
// cliext_multimap_begin.cpp   
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
  
// inspect first two items   
    Mymultimap::iterator it = c1.begin();   
    System::Console::WriteLine("*begin() = [{0} {1}]",   
        it->first, it->second);   
    ++it;   
    System::Console::WriteLine("*++begin() = [{0} {1}]",   
        it->first, it->second);   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
**\= \[\*begin\(\) um 1\]**  
**\= \[\*\+\+begin\(\) b 2\]**   
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multimapa](../dotnet/multimap-stl-clr.md)   
 [multimap::end](../dotnet/multimap-end-stl-clr.md)