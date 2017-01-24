---
title: "operador!= (list) (STL/CLR) | Microsoft Docs"
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
  - "cliext::list::operator!="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator!= [STL/CLR]"
ms.assetid: aa4e1461-8137-43df-a99c-fbec8dd3269f
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador!= (list) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Listar a comparação diferente.  
  
## Sintaxe  
  
```  
template<typename Value>  
    bool operator!=(list<Value>% left,  
        list<Value>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo da ser comparada.  
  
 direita  
 Contêiner direito da ser comparada.  
  
## Comentários  
 A função do operador retorna `!(``left` `==` `right``)`.  Você usa para testar se `left` não está ordenado da mesma forma que `right` quando as duas listas são elemento comparado pelo elemento.  
  
## Exemplo  
  
```  
// cliext_list_operator_ne.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    cliext::list<wchar_t> c2;   
    c2.push_back(L'a');   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
  
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
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [operador\=\= \(list\)](../dotnet/operator-equality-list-stl-clr.md)   
 [operador\< \(list\)](../dotnet/operator-less-than-list-stl-clr.md)   
 [operador\>\= \(list\)](../dotnet/operator-greater-or-equal-list-stl-clr.md)   
 [operador\> \(list\)](../Topic/operator%3E%20\(list\)%20\(STL-CLR\).md)   
 [operador\<\= \(list\)](../dotnet/operator-less-or-equal-list-stl-clr.md)