---
title: "hash_multimap::generic_container (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_multimap::generic_container"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro generic_container [STL/CLR]"
ms.assetid: 2e616958-c5dc-4079-a34a-993a3ff3b13e
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multimap::generic_container (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de interface genérica para o contêiner.  
  
## Sintaxe  
  
```  
typedef Microsoft::VisualC::StlClr::  
    IHash<GKey, GValue>  
    generic_container;  
```  
  
## Comentários  
 O tipo descreve a interface genérica para esta classe do contêiner do modelo.  
  
## Exemplo  
  
```  
// cliext_hash_multimap_generic_container.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct a generic container   
    Myhash_multimap::generic_container^ gc1 = %c1;   
    for each (Myhash_multimap::value_type elem in gc1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// modify generic and display original   
    gc1->insert(Myhash_multimap::make_value(L'd', 4));   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// modify original and display generic   
    c1.insert(Myhash_multimap::make_value(L'e', 5));   
    for each (Myhash_multimap::value_type elem in gc1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
 **um \[1\] \[2\] \[b3 c\]**  
 **um \[1\] b \[2\] \[3\] \[cde 4\]**  
 **um \[1\] \[2\] b c \[3\] \[4\] \[de 5\]**   
## Requisitos  
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_multimap](../dotnet/hash-multimap-stl-clr.md)   
 [hash\_multimap::generic\_iterator](../dotnet/hash-multimap-generic-iterator-stl-clr.md)