---
title: "hash_multimap::make_value (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_multimap::make_value"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro make_value [STL/CLR]"
ms.assetid: 300fb6ec-98c8-48d5-8626-0646878a8462
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multimap::make_value (STL/CLR)
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
// cliext_hash_multimap_make_value.cpp   
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
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**   
## Requisitos  
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_multimap](../dotnet/hash-multimap-stl-clr.md)   
 [hash\_multimap::key\_type](../dotnet/hash-multimap-key-type-stl-clr.md)   
 [hash\_multimap::mapped\_type](../Topic/hash_multimap::mapped_type%20\(STL-CLR\).md)   
 [hash\_multimap::value\_type](../dotnet/hash-multimap-value-type-stl-clr.md)