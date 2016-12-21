---
title: "List:: Size (STL CLR) | Microsoft Docs"
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
  - "cliext::list::size"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro de tamanho [STL/CLR]"
ms.assetid: 409e39fb-4468-44bb-b179-52c90e2fa293
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::size (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conta o número de elementos.  
  
## Sintaxe  
  
```  
size_type size();  
```  
  
## Comentários  
 A função de membro retorna o comprimento da sequência controlada. Você pode usá\-lo para determinar o número de elementos no momento na sequência controlada. Se você se preocupa se a seqüência tem tamanho diferente de zero, consulte [list::empty](../dotnet/list-empty-stl-clr.md)`()`.  
  
## Exemplo  
  
```  
// cliext_list_size.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
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
  
```Output  
um Size de c (b) = 3 começando com 3 Size () = 0 após a limpeza Size () = 2 após a adição de 2  
```  
  
## Requisitos  
 **Cabeçalho:** \< cliext\/lista \>  
  
 **Namespace:** cliext  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::empty](../dotnet/list-empty-stl-clr.md)