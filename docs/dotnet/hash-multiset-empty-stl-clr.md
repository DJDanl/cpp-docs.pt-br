---
title: "hash_multiset::empty (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_multiset::empty"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro vazio [STL/CLR]"
ms.assetid: e1c738eb-9ac9-426b-88b0-2997c9476001
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multiset::empty (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se nenhum elemento estiver presente.  
  
## Sintaxe  
  
```  
bool empty();  
```  
  
## Comentários  
 A função de membro retorna true para uma sequência vazia controlada.  É equivalente a [hash\_multiset::size](../Topic/hash_multiset::size%20\(STL-CLR\).md)`() == 0`.  Use\-a para testar se o hash\_multiset está vazia.  
  
## Exemplo  
  
```  
// cliext_hash_multiset_empty.cpp   
// compile with: /clr   
#include <cliext/hash_set>   
  
typedef cliext::hash_multiset<wchar_t> Myhash_multiset;   
int main()   
    {   
    Myhash_multiset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
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
  
  **um b c**  
**size\(\) \= 3**  
**empty\(\) \= false**  
**size\(\) \= 0**  
**empty\(\) \= retifica**   
## Requisitos  
 cliext \<\/hash\_set de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_multiset::size](../Topic/hash_multiset::size%20\(STL-CLR\).md)