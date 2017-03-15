---
title: "map::operator= (STL/CLR) | Microsoft Docs"
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
  - "cliext::map::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator= [STL/CLR]"
ms.assetid: d27d42c3-9910-407c-8b35-e09641345940
caps.latest.revision: 8
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# map::operator= (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Substitui a sequência controlada.  
  
## Sintaxe  
  
```  
map<Key, Mapped>% operator=(map<Key, Mapped>% right);  
```  
  
#### Parâmetros  
 direita  
 Contêiner a ser copiada.  
  
## Comentários  
 O membro que o operador copia `right` ao objeto, retornará `*this`.  Você usará para substituir a sequência controlada por uma cópia de sequência controlada em `right`.  
  
## Exemplo  
  
```  
// cliext_map_operator_as.cpp   
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
    c2 = c1;   
// display contents " [a 1] [b 2] [c 3]"   
    for each (Mymap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
 **um \[1\] \[2\] \[b3 c\]**   
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [map](../dotnet/map-stl-clr.md)