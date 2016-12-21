---
title: "collection_adapter::difference_type (STL/CLR) | Microsoft Docs"
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
  - "cliext::collection_adapter::difference_type"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro difference_type [STL/CLR]"
ms.assetid: ef263e3f-f932-4d64-9d27-429c7b8ba279
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# collection_adapter::difference_type (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os tipos de uma distância assinado entre dois elementos.  
  
## Sintaxe  
  
```  
typedef int difference_type;  
```  
  
## Comentários  
 O tipo descreve uma contagem assinado do elemento.  
  
## Exemplo  
  
```  
// cliext_collection_adapter_difference_type.cpp   
// compile with: /clr   
#include <cliext/adapter>   
#include <cliext/deque>   
  
typedef cliext::collection_adapter<   
    System::Collections::ICollection> Mycoll;   
int main()   
    {   
    cliext::deque<wchar_t> d1;   
    d1.push_back(L'a');   
    d1.push_back(L'b');   
    d1.push_back(L'c');   
    Mycoll c1(%d1);   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// compute positive difference   
    Mycoll::difference_type diff = 0;   
    Mycoll::iterator it = c1.begin();   
    for (; it != c1.end(); ++it)   
        ++diff;   
    System::Console::WriteLine("end()-begin() = {0}", diff);   
    return (0);   
    }  
  
```  
  
  **um b c**  
**end\(\)\- inicie \(\) \= 3**   
## Requisitos  
 cliext \<\/adaptador de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [collection\_adapter](../Topic/collection_adapter%20\(STL-CLR\).md)   
 [collection\_adapter::size\_type](../dotnet/collection-adapter-size-type-stl-clr.md)