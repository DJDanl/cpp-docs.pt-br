---
title: "deque::assign (STL/CLR) | Microsoft Docs"
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
  - "cliext::deque::assign"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "atribuir membro [STL/CLR]"
ms.assetid: 03fafdbb-6b10-4464-b3dc-0cc5cb8ac980
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deque::assign (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Substitui todos os elementos.  
  
## Sintaxe  
  
```  
void assign(size_type count, value_type val);  
template<typename InIt>  
    void assign(InIt first, InIt last);  
void assign(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### Parâmetros  
 count  
 Número de elementos a ser inserido.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 O fim do intervalo a ser inserido.  
  
 direita  
 Enumeração o a ser inserido.  
  
 val  
 Valor do elemento a ser inserido.  
  
## Comentários  
 A primeira função de membro substitui a sequência controlada com uma reprodução dos elementos de `count` de valor `val`.  Use\-a para preencher qualquer contêiner com elementos que tem o mesmo valor.  
  
 Se `InIt` é do tipo inteiro, a segunda função de membro se comportará da mesma maneira que `assign((size_type)``first``, (value_type)``last``)`.  Caso contrário, o substitui a sequência controlada pela sequência `[``first``,` `last``)`.  Use\-a para tornar a sequência controlada uma cópia outra sequência.  
  
 A terceira função de membro substitui a sequência controlada com a sequência designada pelo enumerador `right`.  Use\-a para tornar a sequência controlada uma cópia de uma sequência descrita por um enumerador.  
  
## Exemplo  
  
```  
// cliext_deque_assign.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
    cliext::deque<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// assign a repetition of values   
    cliext::deque<wchar_t> c2;   
    c2.assign(6, L'x');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign an iterator range   
    c2.assign(c1.begin(), c1.end() - 1);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign an enumeration   
    c2.assign(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **x x x x x x**  
 **um b**  
 **um b c**   
## Requisitos  
 **Cabeçalho:** \<cliext\/deque\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [operador\= \(deque\)](../dotnet/operator-assign-deque-stl-clr.md)