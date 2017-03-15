---
title: "vector::const_reference (STL/CLR) | Microsoft Docs"
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
  - "cliext::vector::const_reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro const_reference [STL/CLR]"
ms.assetid: c68743cd-5367-46ca-88ae-b90b2f0ecc34
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vector::const_reference (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de uma referência constante para um elemento.  
  
## Sintaxe  
  
```  
typedef value_type% const_reference;  
```  
  
## Comentários  
 O tipo descreve uma constante referência a um elemento.  
  
## Exemplo  
  
```  
// cliext_vector_const_reference.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    cliext::vector<wchar_t>::const_iterator cit = c1.begin();   
    for (; cit != c1.end(); ++cit)   
        {   // get a const reference to an element   
        cliext::vector<wchar_t>::const_reference cref = *cit;   
        System::Console::Write(" {0}", cref);   
        }   
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
 [vector::reference](../dotnet/vector-reference-stl-clr.md)   
 [vector::value\_type](../Topic/vector::value_type%20\(STL-CLR\).md)