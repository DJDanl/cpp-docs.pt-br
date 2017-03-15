---
title: "vector::push_back (STL/CLR) | Microsoft Docs"
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
  - "cliext::vector::push_back"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro push_back [STL/CLR]"
ms.assetid: 4a4c302b-e29f-4b68-b759-2f831814d896
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vector::push_back (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona um novo elemento a última vez.  
  
## Sintaxe  
  
```  
void push_back(value_type val);  
```  
  
## Comentários  
 A função de membro insere um elemento com valor `val` ao término da sequência controlada.  Use\-a para anexar outro elemento ao vetor.  
  
## Exemplo  
  
```  
// cliext_vector_push_back.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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
 cliext \<\/vetor de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [vector](../dotnet/vector-stl-clr.md)   
 [vector::pop\_back](../Topic/vector::pop_back%20\(STL-CLR\).md)