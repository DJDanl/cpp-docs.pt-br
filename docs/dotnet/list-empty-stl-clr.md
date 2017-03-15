---
title: "list::empty (STL/CLR) | Microsoft Docs"
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
  - "cliext::list::empty"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro vazio [STL/CLR]"
ms.assetid: f45edf8a-927d-41ff-9c09-cb0fba4f08b8
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::empty (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se nenhum elemento estiver presente.  
  
## Sintaxe  
  
```  
bool empty();  
```  
  
## Comentários  
 A função de membro retorna true para uma sequência vazia controlada.  É equivalente a [list::size \(STL\/CLR\)](../dotnet/list-size-stl-clr.md)`() == 0`.  Você usa para testar se a lista estiver vazia.  
  
## Exemplo  
  
```  
// cliext_list_empty.cpp   
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
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0}", c1.size());   
    System::Console::WriteLine("empty() = {0}", c1.empty());   
    return (0);   
    }  
  
```  
  
  **um b c**  
**size\(\) \= 3**  
**empty\(\) \= false**  
**size\(\) \= 0**  
**empty\(\) \= retifica**   
## Requisitos  
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::size \(STL\/CLR\)](../dotnet/list-size-stl-clr.md)