---
title: "deque::push_back (STL/CLR) | Microsoft Docs"
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
  - "cliext::deque::push_back"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro push_back [STL/CLR]"
ms.assetid: dafd5a4d-1fc7-434c-b129-a523099f8701
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deque::push_back (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona um novo elemento a última vez.  
  
## Sintaxe  
  
```  
void push_back(value_type val);  
```  
  
## Comentários  
 A função de membro insere um elemento com valor `val` ao término da sequência controlada.  Você usará para anexar outro elemento ao deque.  
  
## Exemplo  
  
```  
// cliext_deque_push_back.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
    cliext::deque<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**   
## Requisitos  
 **Cabeçalho:** \<cliext\/deque\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [deque::pop\_back](../dotnet/deque-pop-back-stl-clr.md)   
 [deque::pop\_front](../dotnet/deque-pop-front-stl-clr.md)   
 [deque::push\_front](../dotnet/deque-push-front-stl-clr.md)