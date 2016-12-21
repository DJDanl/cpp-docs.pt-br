---
title: "operador!= (set) (STL/CLR) | Microsoft Docs"
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
  - "cliext::set::operator!="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator!= [STL/CLR]"
ms.assetid: cb82d6a4-0954-49a4-b979-a9ae39df9553
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador!= (set) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Listar a comparação diferente.  
  
## Sintaxe  
  
```  
template<typename Key>  
    bool operator!=(set<Key>% left,  
        set<Key>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo da ser comparada.  
  
 direita  
 Contêiner direito da ser comparada.  
  
## Comentários  
 A função do operador retorna `!(``left` `==` `right``)`.  Você usa para testar se `left` não está ordenado da mesma forma que `right` quando os dois conjuntos elemento são comparados pelo elemento.  
  
## Exemplo  
  
```  
// cliext_set_operator_ne.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::set<wchar_t> Myset;   
int main()   
    {   
    Myset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myset c2;   
    c2.insert(L'a');   
    c2.insert(L'b');   
    c2.insert(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] != [a b c] is {0}",   
        c1 != c1);   
    System::Console::WriteLine("[a b c] != [a b d] is {0}",   
        c1 != c2);   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **um de b**  
**\[um b c\!\]\= \[um b c\] é false**  
**\[um b c\!\]\= um\] \[de b é true**   
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [set](../dotnet/set-stl-clr.md)   
 [operador\=\= \(set\)](../dotnet/operator-equality-set-stl-clr.md)   
 [operador\< \(set\)](../dotnet/operator-less-than-set-stl-clr.md)   
 [operador\>\= \(set\)](../dotnet/operator-greater-or-equal-set-stl-clr.md)   
 [operador\> \(set\)](../Topic/operator%3E%20\(set\)%20\(STL-CLR\).md)   
 [operador\<\= \(set\)](../dotnet/operator-less-or-equal-set-stl-clr.md)