---
title: "operador&lt;= (queue) (STL/CLR) | Microsoft Docs"
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
  - "cliext::queue::operator<="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro operator<= [STL/CLR]"
ms.assetid: 63b7f908-4f6b-40d6-bcc6-22970760789d
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# operador&lt;= (queue) (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fila menor que ou igual comparação.  
  
## Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    bool operator<=(queue<Value, Container>% left,  
        queue<Value, Container>% right);  
```  
  
#### Parâmetros  
 esquerda  
 Contêiner esquerdo da ser comparada.  
  
 direita  
 Contêiner direito da ser comparada.  
  
## Comentários  
 A função do operador retorna `!(``right` `<` `left``)`.  Use\-a para testar se `left` não está ordenado depois de `right` quando as duas filas são elemento comparado pelo elemento.  
  
## Exemplo  
  
```  
// cliext_queue_operator_le.cpp   
// compile with: /clr   
#include <cliext/queue>   
  
typedef cliext::queue<wchar_t> Myqueue;   
int main()   
    {   
    Myqueue c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign to a new container   
    Myqueue c2;   
    c2.push(L'a');   
    c2.push(L'b');   
    c2.push(L'd');   
  
// display contents " a b d"   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("[a b c] <= [a b c] is {0}",   
        c1 <= c1);   
    System::Console::WriteLine("[a b d] <= [a b c] is {0}",   
        c2 <= c1);   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **um de b**  
**\[um b c \= um\] \<\[\] b c é true**  
**b de um \[\] \<\= \[um b c\] é false**   
## Requisitos  
 cliext \<\/fila de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [queue](../Topic/queue%20\(STL-CLR\).md)   
 [operador\=\= \(queue\)](../dotnet/operator-equality-queue-stl-clr.md)   
 [operador\!\= \(queue\)](../dotnet/operator-inequality-queue-stl-clr.md)   
 [operador\< \(queue\)](../dotnet/operator-less-than-queue-stl-clr.md)   
 [operador\>\= \(queue\)](../Topic/operator%3E=%20\(queue\)%20\(STL-CLR\).md)   
 [operador\> \(queue\)](../dotnet/operator-greater-than-queue-stl-clr.md)