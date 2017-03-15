---
title: "operador&lt; (multiset) (STL/CLR) | Microsoft Docs"
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
  - "cliext::multiset::operator<"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator< [STL/CLR]"
ms.assetid: 48150cda-4f3e-4535-860c-89f622a7f0a8
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador&lt; (multiset) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Lista menor que a comparação.  
  
## Sintaxe  
  
```  
template<typename Key>  
    bool operator<(multiset<Key>% left,  
        multiset<Key>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo da ser comparada.  
  
 direita  
 Contêiner direito da ser comparada.  
  
## Comentários  
 A função do operador retornará true se, da mais baixa posição `i` para que `!(``right``[i] <` `left``[i])` ele também será true `left`que`[i] <` `right``[i]`.  Caso contrário, retorna `left``->size() <` `right``->size()` que você usa para testar se `left` é ordenado antes de `right` quando os dois multisets elemento são comparados pelo elemento.  
  
## Exemplo  
  
```  
// cliext_multiset_operator_lt.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::multiset<wchar_t> Mymultiset;   
int main()   
    {   
    Mymultiset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mymultiset c2;   
    c2.insert(L'a');   
    c2.insert(L'b');   
    c2.insert(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] < [a b c] is {0}",   
        c1 < c1);   
    System::Console::WriteLine("[a b c] < [a b d] is {0}",   
        c1 < c2);   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **um de b**  
**\[um b c\] \< \[um b c\] é false**  
**\[um b c\] \< \[\] de um b é true**   
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multiset](../dotnet/multiset-stl-clr.md)   
 [operador\=\= \(multiset\)](../Topic/operator==%20\(multiset\)%20\(STL-CLR\).md)   
 [operador\!\= \(multiset\)](../dotnet/operator-inequality-multiset-stl-clr.md)   
 [operador\>\= \(multiset\)](../Topic/operator%3E=%20\(multiset\)%20\(STL-CLR\).md)   
 [operador\> \(multiset\)](../dotnet/operator-greater-than-multiset-stl-clr.md)   
 [operador\<\= \(multiset\)](../Topic/operator%3C=%20\(multiset\)%20\(STL-CLR\).md)