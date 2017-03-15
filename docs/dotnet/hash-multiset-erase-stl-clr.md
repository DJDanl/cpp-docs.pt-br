---
title: "hash_multiset::erase (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_multiset::erase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "apagar membro [STL/CLR]"
ms.assetid: bddd329d-aece-4b93-8355-005351c3aa45
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multiset::erase (STL/CLR)
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
 A primeira função de membro remove o elemento de sequência controlada apontada por `where`, e retorna um iterador que designa o primeiro elemento que permanece além de elemento removido, ou [hash\_multiset::end](../dotnet/hash-multiset-end-stl-clr.md)`()` se tal elemento existe.  Use\-a para remover um único elemento.  
  
 A segunda função de membro remove os elementos de sequência controlada no intervalo `[``first``,` `last``)`, e retorna um iterador que designa o primeiro elemento que permanece além de todos os elementos removidos, ou `end()` se tal elemento existirão.  Use\-a para remover os elementos zero ou mais contíguas.  
  
 A terceira função de membro remove qualquer elemento da sequência controlada cuja chave tem o equivalente de ordenação da `key`, e retorna uma contagem do número de elementos removidos.  Use\-a para remover e contar todos os elementos que correspondem a uma chave especificada.  
  
 Cada exclusão do elemento usa o tempo proporcionais ao logaritmo o número de elementos na sequência controlada.  
  
## Exemplo  
  
```  
// cliext_hash_multiset_erase.cpp   
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
  
// erase an element and reinspect   
    System::Console::WriteLine("erase(begin()) = {0}",   
        *c1.erase(c1.begin()));   
  
// add elements and display " b c d e"   
    c1.insert(L'd');   
    c1.insert(L'e');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase all but end   
    Myhash_multiset::iterator it = c1.end();   
    System::Console::WriteLine("erase(begin(), end()-1) = {0}",   
        *c1.erase(c1.begin(), --it));   
    System::Console::WriteLine("size() = {0}", c1.size());   
    return (0);   
    }  
  
```  
  
  **um b c**  
**erase\(begin\(\)\) \= b**  
 **b c e d**  
**erase\(begin\(\), end\(\)\-1\) \= e**  
**size\(\) \= 1**   
## Requisitos  
 cliext \<\/hash\_set de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_multiset::clear](../dotnet/hash-multiset-clear-stl-clr.md)