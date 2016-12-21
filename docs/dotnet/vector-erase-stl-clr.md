---
title: "vector::erase (STL/CLR) | Microsoft Docs"
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
  - "cliext::vector::erase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "apagar membro [STL/CLR]"
ms.assetid: 624905eb-83c0-499b-a07a-c10aebd7acc3
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vector::erase (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Remove os elementos nas posições especificadas.  
  
## Sintaxe  
  
```  
iterator erase(iterator where);  
iterator erase(iterator first, iterator last);  
```  
  
#### Parâmetros  
 primeiro  
 Início do intervalo para apagar.  
  
 last  
 O fim do intervalo para apagar.  
  
 onde  
 Elemento para apagar.  
  
## Comentários  
 A primeira função de membro remove o elemento de sequência controlada apontada por `where`.  Use\-a para remover um único elemento.  
  
 A segunda função de membro remove os elementos de sequência controlada no intervalo `[``first``,` `last``)`.  Use\-a para remover os elementos zero ou mais contíguas.  
  
 Ambas as funções de membro retornam um iterador que designa o primeiro elemento que permanece além de todos os elementos removidos, ou [vector::end](../dotnet/vector-end-stl-clr.md)`()` se tal elemento existe.  
  
 Para apagar os elementos, o número de cópias do elemento é linear no número de elementos entre o final da exclusão e término mais próximo da sequência. \(Para apagar um ou mais elementos em um ou outro fim de sequência, nenhuma cópia do elemento ocorre.\)  
  
## Exemplo  
  
```  
// cliext_vector_erase.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase an element and reinspect   
    System::Console::WriteLine("erase(begin()) = {0}",   
        *c1.erase(c1.begin()));   
  
// add elements and display " b c d e"   
    c1.push_back(L'd');   
    c1.push_back(L'e');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase all but end   
    cliext::vector<wchar_t>::iterator it = c1.end();   
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
 cliext \<\/vetor de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [vector](../dotnet/vector-stl-clr.md)   
 [vector::clear](../dotnet/vector-clear-stl-clr.md)