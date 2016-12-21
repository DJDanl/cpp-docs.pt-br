---
title: "operador&gt; (multiset) (STL/CLR) | Microsoft Docs"
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
  - "cliext::multiset::operator>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator> [STL/CLR]"
ms.assetid: 88b4d56d-c7e9-4ac9-a460-0f26e1e5b837
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador&gt; (multiset) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Lista maior que a comparação.  
  
## Sintaxe  
  
```  
template<typename Key>  
    bool operator>(multiset<Key>% left,  
        multiset<Key>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo da ser comparada.  
  
 direita  
 Contêiner direito da ser comparada.  
  
## Comentários  
 A função do operador retorna `right` `<` `left`.  Use\-a para testar se `left` é ordenado depois de `right` quando os dois multisets elemento são comparados pelo elemento.  
  
## Exemplo  
  
```  
// cliext_multiset_operator_gt.cpp   
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
  
    System::Console::WriteLine("[a b c] > [a b c] is {0}",   
        c1 > c1);   
    System::Console::WriteLine("[a b d] > [a b c] is {0}",   
        c2 > c1);   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **um de b**  
**\[um b c\] \> \[um b c\] é false**  
**\[\] \> \[um b de um b c\] é true**   
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multiset](../dotnet/multiset-stl-clr.md)   
 [operador\=\= \(multiset\)](../Topic/operator==%20\(multiset\)%20\(STL-CLR\).md)   
 [operador\!\= \(multiset\)](../dotnet/operator-inequality-multiset-stl-clr.md)   
 [operador\< \(multiset\)](../dotnet/operator-less-than-multiset-stl-clr.md)   
 [operador\>\= \(multiset\)](../Topic/operator%3E=%20\(multiset\)%20\(STL-CLR\).md)   
 [operador\<\= \(multiset\)](../Topic/operator%3C=%20\(multiset\)%20\(STL-CLR\).md)