---
title: "multimap::find (STL/CLR) | Microsoft Docs"
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
  - "cliext::multimap::find"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "localizar membro [STL/CLR]"
ms.assetid: 94b42497-3be4-448c-8de9-0a072ae14fbf
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multimap::find (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Localiza um elemento que corresponde a uma chave especificada.  
  
## Sintaxe  
  
```  
iterator find(key_type key);  
```  
  
#### Parâmetros  
 key  
 Valor de chave para pesquisar por.  
  
## Comentários  
 Se pelo menos um elemento na sequência controlada tem o equivalente que regras com `key`, a função de membro retorna um iterador que designa um desses elementos; se não retorna [multimap::end](../dotnet/multimap-end-stl-clr.md)`()`.  Use\-a para posicionar atualmente um elemento na sequência controlada que corresponde a uma chave especificada.  
  
## Exemplo  
  
```  
// cliext_multimap_find.cpp   
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
  
    System::Console::WriteLine("find {0} = {1}",   
        L'A', c1.find(L'A') != c1.end());   
  
    Mymultimap::iterator it = c1.find(L'b');   
    System::Console::WriteLine("find {0} = [{1} {2}]",   
        L'b', it->first, it->second);   
  
    System::Console::WriteLine("find {0} = {1}",   
        L'C', c1.find(L'C') != c1.end());   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
**find A \= False**  
**localizar b \= \[b 2\]**  
**find C \= False**   
## Descrição  
 Observe que `find` não garante que os vários ele localiza o elemento.  
  
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multimapa](../dotnet/multimap-stl-clr.md)   
 [multimap::equal\_range](../dotnet/multimap-equal-range-stl-clr.md)   
 [multimap::lower\_bound](../dotnet/multimap-lower-bound-stl-clr.md)   
 [multimap::upper\_bound](../dotnet/multimap-upper-bound-stl-clr.md)