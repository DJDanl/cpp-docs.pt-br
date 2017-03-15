---
title: "operador&gt;= (list) (STL/CLR) | Microsoft Docs"
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
  - "cliext::list::operator>="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator>= [STL/CLR]"
ms.assetid: c6142241-8e85-4759-98fd-4f2b7d37b255
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador&gt;= (list) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Listar maior que ou igual a comparação.  
  
## Sintaxe  
  
```  
template<typename Value>  
    bool operator>=(list<Value>% left,  
        list<Value>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo a ser comparado.  
  
 direita  
 Contêiner de direita para comparar.  
  
## Comentários  
 Retorna a função de operador `!(``left` `<` `right``)`. Você pode usá\-lo para testar se `left` não for ordenado antes `right` quando as duas listas são comparado elemento por elemento.  
  
## Exemplo  
  
```  
// cliext_list_operator_ge.cpp   
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
  
    System::Console::WriteLine("[a b c] >= [a b c] is {0}",   
        c1 >= c1);   
    System::Console::WriteLine("[a b c] >= [a b d] is {0}",   
        c1 >= c2);   
    return (0);   
    }  
  
```  
  
```Output  
b c d b [c b] > = [c b] é True [c b] > = [um b d] é falso  
```  
  
## Requisitos  
 **Cabeçalho:** \< cliext\/lista \>  
  
 **Namespace:** cliext  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [operador\=\= \(list\)](../dotnet/operator-equality-list-stl-clr.md)   
 [operador\!\= \(list\)](../dotnet/operator-inequality-list-stl-clr.md)   
 [operador\< \(list\)](../dotnet/operator-less-than-list-stl-clr.md)   
 [operador\> \(list\)](../Topic/operator%3E%20\(list\)%20\(STL-CLR\).md)   
 [operador\<\= \(list\)](../dotnet/operator-less-or-equal-list-stl-clr.md)