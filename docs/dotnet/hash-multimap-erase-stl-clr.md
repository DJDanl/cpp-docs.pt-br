---
title: "hash_multimap::erase (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_multimap::erase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "apagar membro [STL/CLR]"
ms.assetid: 663c67f6-8070-47db-abdc-58f7ace69736
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multimap::erase (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Remove os elementos nas posições especificadas.  
  
## Sintaxe  
  
```  
iterator erase(iterator where);  
iterator erase(iterator first, iterator last);  
bool erase(key_type key)  
```  
  
#### Parâmetros  
 primeiro  
 Início do intervalo para apagar.  
  
 key  
 Valor de chave para apagar.  
  
 last  
 O fim do intervalo para apagar.  
  
 onde  
 Elemento para apagar.  
  
## Comentários  
 A primeira função de membro remove o elemento de sequência controlada apontada por `where`, e retorna um iterador que designa o primeiro elemento que permanece além de elemento removido, ou [hash\_multimap::end](../dotnet/hash-multimap-end-stl-clr.md)`()` se tal elemento existe.  Use\-a para remover um único elemento.  
  
 A segunda função de membro remove os elementos de sequência controlada no intervalo `[``first``,` `last``)`, e retorna um iterador que designa o primeiro elemento que permanece além de todos os elementos removidos, ou `end()` se tal elemento existirão.  Use\-a para remover os elementos zero ou mais contíguas.  
  
 A terceira função de membro remove qualquer elemento da sequência controlada cuja chave tem o equivalente de ordenação da `key`, e retorna uma contagem do número de elementos removidos.  Use\-a para remover e contar todos os elementos que correspondem a uma chave especificada.  
  
 Cada exclusão do elemento usa o tempo proporcionais ao logaritmo o número de elementos na sequência controlada.  
  
## Exemplo  
  
```  
// cliext_hash_multimap_erase.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    cliext::hash_multimap<wchar_t, int> c1;   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'a', 1));   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'b', 2));   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (cliext::hash_multimap<wchar_t, int>::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// erase an element and reinspect   
    cliext::hash_multimap<wchar_t, int>::iterator it =   
        c1.erase(c1.begin());   
    System::Console::WriteLine("erase(begin()) = [{0} {1}]",   
        it->first, it->second);   
  
// add elements and display " b c d e"   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'd', 4));   
    c1.insert(cliext::hash_multimap<wchar_t, int>::make_value(L'e', 5));   
    for each (cliext::hash_multimap<wchar_t, int>::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// erase all but end   
    it = c1.end();   
    it = c1.erase(c1.begin(), --it);   
    System::Console::WriteLine("erase(begin(), end()-1) = [{0} {1}]",   
        it->first, it->second);   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// erase end   
    System::Console::WriteLine("erase(L'x') = {0}", c1.erase(L'x'));   
    System::Console::WriteLine("erase(L'e') = {0}", c1.erase(L'e'));   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
**\= \[erase\(begin\(\)\)b 2\]**  
 **b \[2\] \[3\] \[c de \[4\]e 5\]**  
**erase\(begin\(\), end\(\)\-1\) \= \[e 5\]**  
**size\(\) \= 1**  
**erase \(L'x\) \= 0**  
**erase \(L'e\) \= 1**   
## Requisitos  
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_multimap](../dotnet/hash-multimap-stl-clr.md)   
 [hash\_multimap::clear](../dotnet/hash-multimap-clear-stl-clr.md)