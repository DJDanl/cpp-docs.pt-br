---
title: "set::count (STL/CLR) | Microsoft Docs"
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
  - "cliext::set::Count"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "contar membro [STL/CLR]"
ms.assetid: 78855f8c-3de5-4d3e-800b-0bbea5e829dd
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# set::count (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Localiza o número de elementos que correspondem a uma chave especificada.  
  
## Sintaxe  
  
```  
size_type count(key_type key);  
```  
  
#### Parâmetros  
 key  
 Valor de chave para pesquisar por.  
  
## Comentários  
 A função de membro retorna o número de elementos na sequência controlada que têm o equivalente que regras com `key`.  Use\-a para determinar atualmente o número de elementos na sequência controlada que correspondem a uma chave especificada.  
  
## Exemplo  
  
```  
// cliext_set_count.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::set<wchar_t> Myset;   
int main()   
    {   
    Myset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("count(L'A') = {0}", c1.count(L'A'));   
    System::Console::WriteLine("count(L'b') = {0}", c1.count(L'b'));   
    System::Console::WriteLine("count(L'C') = {0}", c1.count(L'C'));   
    return (0);   
    }  
  
```  
  
  **um b c**  
**count \(L'A\) \= 0**  
**count \(L'b\) \= 1**  
**count \(L'C\) \= 0**   
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [set](../dotnet/set-stl-clr.md)   
 [set::equal\_range](../dotnet/set-equal-range-stl-clr.md)