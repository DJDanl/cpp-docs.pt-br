---
title: "operador== (map) (STL/CLR) | Microsoft Docs"
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
  - "cliext::map::operator=="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator== [STL/CLR]"
ms.assetid: 6f7672af-71f8-4086-ac42-173203e52951
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador== (map) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Comparação igual na lista.  
  
## Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    bool operator==(map<Key, Mapped>% left,  
        map<Key, Mapped>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo da ser comparada.  
  
 direita  
 Contêiner direito da ser comparada.  
  
## Comentários  
 A função do operador só retornará true se as sequências controladas por `left` e por `right` têm o mesmo tamanho e, para cada posição `i`, `left``[i] ==` `right``[i]`.  Use\-a para testar se `left` é ordenado da mesma forma que `right` quando os dois mapas são elemento comparado pelo elemento.  
  
## Exemplo  
  
```  
// cliext_map_operator_eq.cpp   
// compile with: /clr   
#include <cliext/map>   
  
typedef cliext::map<wchar_t, int> Mymap;   
int main()   
    {   
    Mymap c1;   
    c1.insert(Mymap::make_value(L'a', 1));   
    c1.insert(Mymap::make_value(L'b', 2));   
    c1.insert(Mymap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Mymap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Mymap c2;   
    c2.insert(Mymap::make_value(L'a', 1));   
    c2.insert(Mymap::make_value(L'b', 2));   
    c2.insert(Mymap::make_value(L'd', 4));   
  
// display contents " [a 1] [b 2] [d 4]"   
    for each (Mymap::value_type elem in c2)   
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
 [map](../dotnet/map-stl-clr.md)   
 [operador\!\= \(map\)](../dotnet/operator-inequality-map-stl-clr.md)   
 [operador\< \(map\)](../Topic/operator%3C%20\(map\)%20\(STL-CLR\).md)   
 [operador\>\= \(map\)](../dotnet/operator-greater-or-equal-map-stl-clr.md)   
 [operador\> \(map\)](../dotnet/operator-greater-than-map-stl-clr.md)   
 [operador\<\= \(map\)](../dotnet/operator-less-or-equal-map-stl-clr.md)