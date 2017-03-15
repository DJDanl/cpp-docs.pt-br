---
title: "set::difference_type (STL/CLR) | Microsoft Docs"
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
  - "cliext::set::difference_type"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro difference_type [STL/CLR]"
ms.assetid: db8121f0-ca2f-4024-996a-0b8513f03079
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# set::difference_type (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os tipos de uma distância assinado entre dois elementos.  
  
## Sintaxe  
  
```  
typedef int difference_type;  
```  
  
## Comentários  
 O tipo descreve uma contagem de elementos possivelmente negativo.  
  
## Exemplo  
  
```  
// cliext_set_difference_type.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::set<wchar_t> Myset;   
int main()   
    {   
    Myset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute positive difference   
    Myset::difference_type diff = 0;   
    for (Myset::iterator it = c1.begin(); it != c1.end(); ++it)   
        ++diff;   
    System::Console::WriteLine("end()-begin() = {0}", diff);   
  
// compute negative difference   
    diff = 0;   
    for (Myset::iterator it = c1.end(); it != c1.begin(); --it)   
        --diff;   
    System::Console::WriteLine("begin()-end() = {0}", diff);   
    return (0);   
    }  
  
```  
  
  **um b c**  
**end\(\)\- inicie \(\) \= 3**  
**begin\(\)\- extremidade \(\) \= \-3**   
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [set](../dotnet/set-stl-clr.md)   
 [set::size\_type](../Topic/set::size_type%20\(STL-CLR\).md)