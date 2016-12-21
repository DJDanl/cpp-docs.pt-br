---
title: "list::list (STL/CLR) | Microsoft Docs"
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
  - "cliext::list::list"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro de lista [STL/CLR]"
ms.assetid: 51b58f63-c65a-4d54-b746-0c10635b123b
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::list (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto contêiner.  
  
## Sintaxe  
  
```  
list();  
list(list<Value>% right);  
list(list<Value>^ right);  
explicit list(size_type count);  
list(size_type count, value_type val);  
template<typename InIt>  
    list(InIt first, InIt last);  
list(System::Collections::Generic::IEnumerable<Value>^ right);  
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
  
 `list();`  
  
 inicializa a sequência controlada sem os elementos.  Use\-a para especificar uma sequência vazia inicial controlada.  
  
 O construtor:  
  
 `list(list<Value>% right);`  
  
 inicializa a sequência controlada pela sequência `[``right``.`[list::begin](../Topic/list::begin%20\(STL-CLR\).md)`(),` `right``.`[list::end](../Topic/list::end%20\(STL-CLR\).md)`())`.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`na lista.  
  
 O construtor:  
  
 `list(list<Value>^ right);`  
  
 inicializa a sequência controlada pela sequência `[``right``->`[list::begin](../Topic/list::begin%20\(STL-CLR\).md)`(),` `right``->`[list::end](../Topic/list::end%20\(STL-CLR\).md)`())`.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto da lista cujo identificador é `right`.  
  
 O construtor:  
  
 `explicit list(size_type count);`  
  
 inicializa a sequência controlada com elementos de `count` cada um com valor `value_type()`.  Você usará para preencher qualquer contêiner com elementos que tem o valor padrão.  
  
 O construtor:  
  
 `list(size_type count, value_type val);`  
  
 inicializa a sequência controlada com elementos de `count` cada um com valor `val`.  Use\-a para preencher qualquer contêiner com elementos que tem o mesmo valor.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `list(InIt first, InIt last);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência.  
  
 O construtor:  
  
 `list(System::Collections::Generic::IEnumerable<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador.  
  
## Exemplo  
  
```  
// cliext_list_construct.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
// construct an empty container   
    cliext::list<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct with a repetition of default values   
    cliext::list<wchar_t> c2(3);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// construct with a repetition of values   
    cliext::list<wchar_t> c3(6, L'x');   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    cliext::list<wchar_t>::iterator it = c3.end();   
    cliext::list<wchar_t> c4(c3.begin(), --it);   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    cliext::list<wchar_t> c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    cliext::list<wchar_t> c7(c3);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    cliext::list<wchar_t> c8(%c3);   
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
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::assign](../dotnet/list-assign-stl-clr.md)   
 [list::generic\_container](../dotnet/list-generic-container-stl-clr.md)   
 [list::operator\= \(STL\/CLR\)](../dotnet/list-operator-assign-stl-clr.md)