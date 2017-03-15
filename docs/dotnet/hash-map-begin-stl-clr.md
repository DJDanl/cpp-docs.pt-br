---
title: "hash_map::begin (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_map::begin"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "iniciar membro [STL/CLR]"
ms.assetid: b2ff4605-ac37-4456-8299-b3bcccdbe45a
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_map::begin (STL/CLR)
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
// cliext_hash_map_begin.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_map<wchar_t, int> Myhash_map;   
int main()   
    {   
    Myhash_map c1;   
    c1.insert(Myhash_map::make_value(L'a', 1));   
    c1.insert(Myhash_map::make_value(L'b', 2));   
    c1.insert(Myhash_map::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_map::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect first two items   
    Myhash_map::iterator it = c1.begin();   
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
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_map::end](../dotnet/hash-map-end-stl-clr.md)