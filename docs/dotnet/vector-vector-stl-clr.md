---
title: "vector::vector (STL/CLR) | Microsoft Docs"
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
  - "cliext::vector::vector"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro vetor [STL/CLR]"
ms.assetid: a0b5e807-1ef2-422b-b772-1f96cd62fb51
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vector::vector (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto contêiner.  
  
## Sintaxe  
  
```  
vector();  
vector(vector<Value>% right);  
vector(vector<Value>^ right);  
explicit vector(size_type count);  
vector(size_type count, value_type val);  
template<typename InIt>  
    vector(InIt first, InIt last);  
vector(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### Parâmetros  
 count  
 Número de elementos a ser inserido.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 O fim do intervalo a ser inserido.  
  
 direita  
 Objeto ou intervalo a ser inserido.  
  
 val  
 Valor do elemento a ser inserido.  
  
## Comentários  
 O construtor:  
  
 `vector();`  
  
 inicializa a sequência controlada sem os elementos.  Use\-a para especificar uma sequência vazia inicial controlada.  
  
 O construtor:  
  
 `vector(vector<Value>% right);`  
  
 inicializa a sequência controlada pela sequência `[``right``.`[vector::begin](../dotnet/vector-begin-stl-clr.md)`(),` `right``.`[vector::end](../dotnet/vector-end-stl-clr.md)`())`.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de vetor.  
  
 O construtor:  
  
 `vector(vector<Value>^ right);`  
  
 inicializa a sequência controlada pela sequência `[``right``->`[vector::begin](../dotnet/vector-begin-stl-clr.md)`(),` `right``->`[vector::end](../dotnet/vector-end-stl-clr.md)`())`.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de vetor cujo identificador é `right`.  
  
 O construtor:  
  
 `explicit vector(size_type count);`  
  
 inicializa a sequência controlada com elementos de `count` cada um com valor `value_type()`.  Você usará para preencher qualquer contêiner com elementos que tem o valor padrão.  
  
 O construtor:  
  
 `vector(size_type count, value_type val);`  
  
 inicializa a sequência controlada com elementos de `count` cada um com valor `val`.  Use\-a para preencher qualquer contêiner com elementos que tem o mesmo valor.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `vector(InIt first, InIt last);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência.  
  
 O construtor:  
  
 `vector(System::Collections::Generic::IEnumerable<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador.  
  
## Exemplo  
  
```  
// cliext_vector_construct.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
// construct an empty container   
    cliext::vector<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct with a repetition of default values   
    cliext::vector<wchar_t> c2(3);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// construct with a repetition of values   
    cliext::vector<wchar_t> c3(6, L'x');   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    cliext::vector<wchar_t>::iterator it = c3.end();   
    cliext::vector<wchar_t> c4(c3.begin(), --it);   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    cliext::vector<wchar_t> c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    cliext::vector<wchar_t> c7(c3);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    cliext::vector<wchar_t> c8(%c3);   
    for each (wchar_t elem in c8)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    return (0);   
    }  
  
```  
  
  **size\(\) \= 0**  
 **0 0 0**  
 **x x x x x x**  
 **x x x x x**  
 **x x x x x x**  
 **x x x x x x**  
 **x x x x x x**   
## Requisitos  
 cliext \<\/vetor de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [vector](../dotnet/vector-stl-clr.md)   
 [vector::assign](../Topic/vector::assign%20\(STL-CLR\).md)   
 [vector::generic\_container](../dotnet/vector-generic-container-stl-clr.md)   
 [vector::operator\=](../dotnet/vector-operator-assign-stl-clr.md)