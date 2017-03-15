---
title: "multiset::erase (STL/CLR) | Microsoft Docs"
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
  - "cliext::multiset::erase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "apagar membro [STL/CLR]"
ms.assetid: 3ff9fe2d-bf43-446a-bd3f-74550313a1d2
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multiset::erase (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Remove os elementos nas posições especificadas.  
  
## Sintaxe  
  
```  
iterator erase(iterator where);  
iterator erase(iterator first, iterator last);  
size_type erase(key_type key)  
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
 A primeira função de membro remove o elemento de sequência controlada apontada por `where`, e retorna um iterador que designa o primeiro elemento que permanece além de elemento removido, ou [multiset::end](../dotnet/multiset-end-stl-clr.md)`()` se tal elemento existe.  Use\-a para remover um único elemento.  
  
 A segunda função de membro remove os elementos de sequência controlada no intervalo `[``first``,` `last``)`, e retorna um iterador que designa o primeiro elemento que permanece além de todos os elementos removidos, ou `end()` se tal elemento existirão.  Use\-a para remover os elementos zero ou mais contíguas.  
  
 A terceira função de membro remove qualquer elemento da sequência controlada cuja chave tem o equivalente de ordenação da `key`, e retorna uma contagem do número de elementos removidos.  Use\-a para remover e contar todos os elementos que correspondem a uma chave especificada.  
  
 Cada exclusão do elemento usa o tempo proporcionais ao logaritmo o número de elementos na sequência controlada.  
  
## Exemplo  
  
```  
// cliext_multiset_erase.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::multiset<wchar_t> Mymultiset;   
int main()   
    {   
    Mymultiset c1;   
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
    Mymultiset::iterator it = c1.end();   
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
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multiset](../dotnet/multiset-stl-clr.md)   
 [multiset::clear](../dotnet/multiset-clear-stl-clr.md)