---
title: "multiset::size (STL/CLR) | Microsoft Docs"
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
  - "cliext::multiset::size"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro de tamanho [STL/CLR]"
ms.assetid: 29338f4f-c13e-4eb6-844d-1d94769553c8
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multiset::size (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conta o número de elementos.  
  
## Sintaxe  
  
```  
size_type size();  
```  
  
## Comentários  
 A função de membro retorna o comprimento da sequência controlada.  Use\-a para determinar atualmente o número de elementos na sequência controlada.  Se tudo o que você precisa se preocupar é aproximadamente se a sequência tiver o tamanho diferente de zero, consulte [multiset::empty](../dotnet/multiset-empty-stl-clr.md)`()`.  
  
## Exemplo  
  
```  
// cliext_multiset_size.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::multiset<wchar_t> Mymultiset;   
int main()   
    {   
    Mymultiset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("size() = {0} starting with 3", c1.size());   
  
// clear the container and reinspect   
    c1.clear();   
    System::Console::WriteLine("size() = {0} after clearing", c1.size());   
  
// add elements and clear again   
    c1.insert(L'a');   
    c1.insert(L'b');   
    System::Console::WriteLine("size() = {0} after adding 2", c1.size());   
    return (0);   
    }  
  
```  
  
  **um b c**  
**size\(\) \= 3 começando com 3**  
**size\(\) \= 0 depois de limpar**  
**size\(\) \= 2 depois da adição de 2**   
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multiset](../dotnet/multiset-stl-clr.md)   
 [multiset::empty](../dotnet/multiset-empty-stl-clr.md)