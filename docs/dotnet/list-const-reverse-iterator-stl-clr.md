---
title: "list::const_reverse_iterator (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "11/17/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::list::const_reverse_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro const_reverse_iterator [STL/CLR]"
ms.assetid: d9a9a1ec-df5f-411f-9918-beb5838ffa63
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::const_reverse_iterator (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de um iterador inverso constante para a sequência controlada.  
  
## Sintaxe  
  
```  
typedef T4 const_reverse_iterator;  
```  
  
## Comentários  
 O tipo descreve um objeto do tipo especificado `T4` que pode servir como um iterador inverso constante para a sequência controlada.  
  
## Exemplo  
  
```  
// cliext_list_const_reverse_iterator.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c" reversed   
    cliext::list<wchar_t>::const_reverse_iterator crit = c1.rbegin();   
    cliext::list<wchar_t>::const_reverse_iterator crend = c1.rend();   
    for (; crit != crend; ++crit)   
        System::Console::Write(" {0}", *crit);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
b c um  
```  
  
## Requisitos  
 **Cabeçalho:** \< cliext\/lista \>  
  
 **Namespace:** cliext  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::reverse\_iterator](../dotnet/list-reverse-iterator-stl-clr.md)