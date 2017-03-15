---
title: "bind2nd (STL/CLR) | Microsoft Docs"
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
  - "cliext::bind2nd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função bind2nd [STL/CLR]"
ms.assetid: 457cebea-38e4-4466-a468-fe9eb138e80c
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# bind2nd (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gerenciar `binder2nd` para um argumento e um funtor.  
  
## Sintaxe  
  
```  
template<typename Fun,  
    typename Arg>  
    binder2nd<Fun> bind2nd(Fun% functor,  
        Arg right);  
```  
  
## Parâmetros de modelo  
 Arg  
 O tipo de argumento.  
  
 Divertimento  
 O tipo de funtor.  
  
## Parâmetros de função  
 funtor  
 O funtor a quebra de texto.  
  
 direita  
 O segundo argumento para envolver.  
  
## Comentários  
 A função do modelo retorna [binder2nd](../Topic/binder2nd%20\(STL-CLR\).md)`<Fun>(functor, right)`.  Use\-a como uma maneira conveniente de envolver um funtor de dois argumentos e o segundo argumento em um funtor de um argumento que o chama com um primeiro argumento.  
  
## Exemplo  
  
```  
// cliext_bind2nd.cpp   
// compile with: /clr   
#include <cliext/algorithm>   
#include <cliext/functional>   
#include <cliext/vector>   
  
typedef cliext::vector<int> Myvector;   
int main()   
    {   
    Myvector c1;   
    c1.push_back(4);   
    c1.push_back(3);   
    Myvector c3(2, 0);   
  
// display initial contents " 4 3"   
    for each (int elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display   
    cliext::minus<int> sub_op;   
    cliext::binder2nd<cliext::minus<int> > sub4(sub_op, 4);   
  
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),   
        sub4);   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display with function   
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),   
        bind2nd(sub_op, 4));   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **4 3**  
 **0 \-1**  
 **0 \-1**   
## Requisitos  
 cliext \<de**Cabeçalho:** \/funcional\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [binder2nd](../Topic/binder2nd%20\(STL-CLR\).md)