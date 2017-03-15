---
title: "deque::resize (STL/CLR) | Microsoft Docs"
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
  - "cliext::deque::resize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "redimensionar membro [STL/CLR]"
ms.assetid: c83f3c57-38b3-4706-a124-59bafbf88484
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deque::resize (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Altera o número de elementos.  
  
## Sintaxe  
  
```  
void resize(size_type new_size);  
void resize(size_type new_size, value_type val);  
```  
  
#### Parâmetros  
 new\_size  
 Novo tamanho de sequência controlada.  
  
 val  
 Valor do elemento de preenchimento.  
  
## Comentários  
 As funções de membro ambas garantem que [deque::size](../Topic/deque::size%20\(STL-CLR\).md)`()` retorna `new_size`daqui em diante.  Se deve fazer a sequência controlada mais longa, a primeira função de membro adiciona os elementos com valor `value_type()`, enquanto a segunda função de membro acrescentar os elementos com valor `val`.  Para fazer a sequência controlada mais curto, ambas as funções de membro apagam efetivamente hora posterior de [deque::size](../Topic/deque::size%20\(STL-CLR\).md)`() -` `new_size` do elemento.  Você usará para garantir que a sequência controlada tem o tamanho `new_size`, por fragmentação ou o preenchimento a sequência controlada atual.  
  
## Exemplo  
  
```  
// cliext_deque_resize.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
// construct an empty container and pad with default values   
    cliext::deque<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
    c1.resize(4);   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// resize to empty   
    c1.resize(0);   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// resize and pad   
    c1.resize(5, L'x');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **size\(\) \= 0**  
 **0 0 0 0**  
**size\(\) \= 0**  
 **x x x x x**   
## Requisitos  
 **Cabeçalho:** \<cliext\/deque\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [deque::clear](../dotnet/deque-clear-stl-clr.md)   
 [deque::erase](../Topic/deque::erase%20\(STL-CLR\).md)   
 [deque::insert](../dotnet/deque-insert-stl-clr.md)