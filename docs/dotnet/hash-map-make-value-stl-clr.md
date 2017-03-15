---
title: "hash_map::make_value (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_map::make_value"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro make_value [STL/CLR]"
ms.assetid: 1fcdcacc-5edf-46b7-9481-9a4aef32b025
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_map::make_value (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto de valor.  
  
## Sintaxe  
  
```  
static value_type make_value(key_type key, mapped_type mapped);  
```  
  
#### Parâmetros  
 key  
 Valor de chave a ser usado.  
  
 mapeado  
 Valor mapeado para pesquisar por.  
  
## Comentários  
 A função de membro retorna um objeto de `value_type` cuja chave é `key` e cujo valor é mapeado `mapped`.  Use\-a para compor um objeto apropriado para uso com várias outras funções de membro.  
  
## Exemplo  
  
```  
// cliext_hash_map_make_value.cpp   
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
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**   
## Requisitos  
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_map::key\_type](../Topic/hash_map::key_type%20\(STL-CLR\).md)   
 [hash\_map::mapped\_type](../Topic/hash_map::mapped_type%20\(STL-CLR\).md)   
 [hash\_map::value\_type](../dotnet/hash-map-value-type-stl-clr.md)