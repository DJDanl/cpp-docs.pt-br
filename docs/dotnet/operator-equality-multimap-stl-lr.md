---
title: "operador== (multimap) (STL/CLR) | Microsoft Docs"
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
  - "cliext::multimap::operator=="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator== [STL/CLR]"
ms.assetid: 19f22238-7acf-47dc-b95e-310b39f554ad
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador== (multimap) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Comparação igual na lista.  
  
## Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    bool operator==(multimap<Key, Mapped>% left,  
        multimap<Key, Mapped>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo da ser comparada.  
  
 direita  
 Contêiner direito da ser comparada.  
  
## Comentários  
 A função do operador só retornará true se as sequências controladas por `left` e por `right` têm o mesmo tamanho e, para cada posição `i`, `left``[i] ==` `right``[i]`.  Use\-a para testar se `left` é ordenado da mesma forma que `right` quando os dois multimaps elemento são comparados pelo elemento.  
  
## Exemplo  
  
```  
// cliext_multimap_operator_eq.cpp   
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
  
// assign to a new container   
    Mymultimap c2;   
    c2.insert(Mymultimap::make_value(L'a', 1));   
    c2.insert(Mymultimap::make_value(L'b', 2));   
    c2.insert(Mymultimap::make_value(L'd', 4));   
  
// display contents " [a 1] [b 2] [d 4]"   
    for each (Mymultimap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] == [a b c] is {0}",   
        c1 == c1);   
    System::Console::WriteLine("[a b c] == [a b d] is {0}",   
        c1 == c2);   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
 **um \[1\] \[2\] \[bde 4\]**  
**\[um b c\] \=\= \[um b c\] é true**  
**\[um b c\] \=\= b de um \[\] é false**   
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multimapa](../dotnet/multimap-stl-clr.md)   
 [operador\!\= \(multimap\)](../Topic/operator!=%20\(multimap\)%20\(STL-CLR\).md)   
 [operador\< \(multimap\)](../dotnet/operator-less-than-multimap-stl-clr.md)   
 [operador\>\= \(multimap\)](../Topic/operator%3E=%20\(multimap\)%20\(STL-CLR\).md)   
 [operador\> \(multimap\)](../dotnet/operator-greater-than-multimap-stl-clr.md)   
 [operador\<\= \(multimap\)](../dotnet/operator-less-or-equal-multimap-stl-clr.md)