---
title: "vector::swap (STL/CLR) | Microsoft Docs"
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
  - "cliext::vector::swap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro swap [STL/CLR]"
ms.assetid: 9ad083fe-f79b-4b97-8013-581fd00c059a
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vector::swap (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Alterna o conteúdo de dois contêineres.  
  
## Sintaxe  
  
```  
void swap(vector<Value>% right);  
```  
  
#### Parâmetros  
 direita  
 Contêiner para alternar conteúdo com.  
  
## Comentários  
 A função de membro alterna entre as sequências controladas `*this` e `right`.  Fazer isso no momento e constantes não gerencie nenhuma exceção.  Use\-a como um modo rápido de troca o conteúdo de dois contêineres.  
  
## Exemplo  
  
```  
// cliext_vector_swap.cpp   
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
  
// construct another container with repetition of values   
    cliext::vector<wchar_t> c2(5, L'x');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// swap and redisplay   
    c1.swap(c2);   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **x x x x x**  
 **x x x x x**  
 **um b c**   
## Requisitos  
 cliext \<\/vetor de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [vector](../dotnet/vector-stl-clr.md)   
 [vector::assign](../Topic/vector::assign%20\(STL-CLR\).md)   
 [vector::operator\=](../dotnet/vector-operator-assign-stl-clr.md)