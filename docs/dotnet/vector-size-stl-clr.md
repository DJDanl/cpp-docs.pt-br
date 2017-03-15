---
title: "vector::size (STL/CLR) | Microsoft Docs"
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
  - "cliext::vector::size"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro de tamanho [STL/CLR]"
ms.assetid: 3d2a156e-5871-4441-9307-21a20cd1430f
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vector::size (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conta o número de elementos.  
  
## Sintaxe  
  
```  
size_type size();  
```  
  
## Comentários  
 A função de membro retorna o comprimento da sequência controlada.  Use\-a para determinar atualmente o número de elementos na sequência controlada.  Se tudo o que você precisa se preocupar é aproximadamente se a sequência tiver o tamanho diferente de zero, consulte [vector::empty](../Topic/vector::empty%20\(STL-CLR\).md)`()`.  
  
## Exemplo  
  
```  
// cliext_vector_size.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0} starting with 3", c1.size());   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0} after clearing", c1.size());   
  
// add elements and clear again   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    System::Console::WriteLine("size() = {0} after adding 2", c1.size());   
    return (0);   
    }  
  
```  
  
  **um b c**  
**size\(\) \= 3 começando com 3**  
**size\(\) \= 0 depois de limpar**  
**size\(\) \= 2 depois da adição de 2**   
## Requisitos  
 cliext \<\/vetor de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [vector](../dotnet/vector-stl-clr.md)   
 [vector::empty](../Topic/vector::empty%20\(STL-CLR\).md)