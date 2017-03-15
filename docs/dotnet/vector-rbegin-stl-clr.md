---
title: "vector::rbegin (STL/CLR) | Microsoft Docs"
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
  - "cliext::vector::rbegin"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro rbegin [STL/CLR]"
ms.assetid: fad410b9-fe79-4820-9be5-6b7e0219a1af
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vector::rbegin (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Designa o início da sequência controlada invertida.  
  
## Sintaxe  
  
```  
reverse_iterator rbegin();  
```  
  
## Comentários  
 A função de membro retorna um iterador invertido que designa o elemento o último de sequência controlada, ou apenas além do início de uma sequência vazia.  Consequentemente, designa `beginning` de sequência inversa.  Use\-a para obter um iterador que designa o início de `current` de sequência controlada consultada em ordem inversa, mas seu status pode ser alterado se o comprimento da sequência controlada é alterado.  
  
## Exemplo  
  
```  
// cliext_vector_rbegin.cpp   
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
  
// inspect first two items in reversed sequence   
    cliext::vector<wchar_t>::reverse_iterator rit = c1.rbegin();   
    System::Console::WriteLine("*rbegin() = {0}", *rit);   
    System::Console::WriteLine("*++rbegin() = {0}", *++rit);   
  
// alter first two items and reinspect   
    *--rit = L'x';   
    *++rit = L'y';   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
**\*rbegin\(\) \= c**  
**\*\+\+rbegin\(\) \= b**  
 **um x y**   
## Requisitos  
 cliext \<\/vetor de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [vector](../dotnet/vector-stl-clr.md)   
 [vector::begin](../dotnet/vector-begin-stl-clr.md)   
 [vector::end](../dotnet/vector-end-stl-clr.md)   
 [vector::rend](../dotnet/vector-rend-stl-clr.md)