---
title: "multimap::multimap (STL/CLR) | Microsoft Docs"
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
  - "cliext::multimap::multimap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro multimapa [STL/CLR]"
ms.assetid: cdf9c5dc-774c-424e-aeea-7554643e401c
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multimap::multimap (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto contêiner.  
  
## Sintaxe  
  
```  
multimap();  
explicit multimap(key_compare^ pred);  
multimap(multimap<Key, Mapped>% right);  
multimap(multimap<Key, Mapped>^ right);  
template<typename InIter>  
    multimapmultimap(InIter first, InIter last);  
template<typename InIter>  
    multimap(InIter first, InIter last,  
        key_compare^ pred);  
multimap(System::Collections::Generic::IEnumerable<GValue>^ right);  
multimap(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred);  
```  
  
#### Parâmetros  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 O fim do intervalo a ser inserido.  
  
 pred  
 Ordenando o predicado da sequência controlada.  
  
 direita  
 Objeto ou intervalo a ser inserido.  
  
## Comentários  
 O construtor:  
  
 `multimap();`  
  
 inicializa a sequência controlada sem os elementos, com o padrão de ordenação `key_compare()`predicado.  Você usa para especificar inicial uma sequência vazia, controlada com o predicado padrão de ordenação.  
  
 O construtor:  
  
 `explicit multimap(key_compare^ pred);`  
  
 inicializa a sequência controlada sem os elementos, com o predicado de ordenação `pred`.  Você usa para especificar inicial uma sequência vazia, controlada pelo predicado especificado. ordenando  
  
 O construtor:  
  
 `multimap(multimap<Key, Mapped>% right);`  
  
 inicializa a sequência controlada pela sequência `[``right``.`[multimap::begin](../dotnet/multimap-begin-stl-clr.md)`(),` `right``.`[multimap::end](../dotnet/multimap-end-stl-clr.md)`())`, com o padrão de ordenação predicado.  Você usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de multimap, com o padrão de ordenação predicado.  
  
 O construtor:  
  
 `multimap(multimap<Key, Mapped>^ right);`  
  
 inicializa a sequência controlada pela sequência `[``right``->`[multimap::begin](../dotnet/multimap-begin-stl-clr.md)`(),` `right``->`[multimap::end](../dotnet/multimap-end-stl-clr.md)`())`, com o padrão de ordenação predicado.  Você usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de multimap, com o padrão de ordenação predicado.  
  
 O construtor:  
  
 `template<typename InIter>`  
  
 `multimap(InIter first, InIter last);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`, com o padrão de ordenação predicado.  Você usará para tornar a sequência controlada uma cópia de outra sequência, com o padrão de ordenação predicado.  
  
 O construtor:  
  
 `template<typename InIter>`  
  
 `multimap(InIter first, InIter last,`  
  
 `key_compare^ pred);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`, com o predicado de ordenação `pred`.  Você usará para tornar a sequência controlada uma cópia de outra sequência, com o predicado ordenando especificado.  
  
 O construtor:  
  
 `multimap(System::Collections::Generic::IEnumerable<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o padrão de ordenação predicado.  Você usará para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o padrão de ordenação predicado.  
  
 O construtor:  
  
 `multimap(System::Collections::Generic::IEnumerable<Key>^ right,`  
  
 `key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado de ordenação `pred`.  Você usará para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado ordenando especificado.  
  
## Exemplo  
  
```  
// cliext_multimap_construct.cpp   
// compile with: /clr   
#include <cliext/map>   
  
typedef cliext::multimap<wchar_t, int> Mymultimap;   
int main()   
    {   
// construct an empty container   
    Mymultimap c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.insert(Mymultimap::make_value(L'a', 1));   
    c1.insert(Mymultimap::make_value(L'b', 2));   
    c1.insert(Mymultimap::make_value(L'c', 3));   
    for each (Mymultimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an ordering rule   
    Mymultimap c2 = cliext::greater_equal<wchar_t>();   
    System::Console::WriteLine("size() = {0}", c2.size());   
  
    c2.insert(c1.begin(), c1.end());   
    for each (Mymultimap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    Mymultimap c3(c1.begin(), c1.end());   
    for each (Mymultimap::value_type elem in c3)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule   
    Mymultimap c4(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>());   
    for each (Mymultimap::value_type elem in c4)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    Mymultimap c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Mymultimap::value_type>^)%c3);   
    for each (Mymultimap::value_type elem in c5)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule   
    Mymultimap c6(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Mymultimap::value_type>^)%c3,   
                cliext::greater_equal<wchar_t>());   
    for each (Mymultimap::value_type elem in c6)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Mymultimap c7(c4);   
    for each (Mymultimap::value_type elem in c7)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    Mymultimap c8(%c3);   
    for each (Mymultimap::value_type elem in c8)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **size\(\) \= 0**  
 **um \[1\] \[2\] \[b3 c\]**  
**size\(\) \= 0**  
 **c \[3\] \[2\] \[bum 1\]**  
 **um \[1\] \[2\] \[b3 c\]**  
 **c \[3\] \[2\] \[bum 1\]**  
 **um \[1\] \[2\] \[b3 c\]**  
 **c \[3\] \[2\] \[bum 1\]**  
 **c \[3\] \[2\] \[bum 1\]**  
 **um \[1\] \[2\] \[b3 c\]**   
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multimapa](../dotnet/multimap-stl-clr.md)   
 [multimap::generic\_container](../dotnet/multimap-generic-container-stl-clr.md)   
 [multimap::operator\=](../dotnet/multimap-operator-assign-stl-clr.md)