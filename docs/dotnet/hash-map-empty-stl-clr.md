---
title: "hash_map::empty (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_map::empty"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro vazio [STL/CLR]"
ms.assetid: 2a145e16-a48a-4304-8fa6-5b2361693083
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_map::empty (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se nenhum elemento estiver presente.  
  
## Sintaxe  
  
```  
bool empty();  
```  
  
## Comentários  
 A função de membro retorna true para uma sequência vazia controlada.  É equivalente a [hash\_map::size](../dotnet/hash-map-size-stl-clr.md)`() == 0`.  Use\-a para testar se o hash\_map está vazia.  
  
## Exemplo  
  
```  
// cliext_hash_map_empty.cpp   
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
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_map::size](../dotnet/hash-map-size-stl-clr.md)