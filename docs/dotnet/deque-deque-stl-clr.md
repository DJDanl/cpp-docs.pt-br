---
title: "deque::deque (STL/CLR) | Microsoft Docs"
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
  - "cliext::deque::deque"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro deque [STL/CLR]"
ms.assetid: e5bc9511-619e-469c-b50a-e06858e7fce7
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deque::deque (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto contêiner.  
  
## Sintaxe  
  
```  
deque();  
deque(deque<Value>% right);  
deque(deque<Value>^ right);  
explicit deque(size_type count);  
deque(size_type count, value_type val);  
template<typename InIt>  
    deque(InIt first, InIt last);  
deque(System::Collections::Generic::IEnumerable<Value>^ right);  
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
  
 `deque();`  
  
 inicializa a sequência controlada sem os elementos.  Use\-a para especificar uma sequência vazia inicial controlada.  
  
 O construtor:  
  
 `deque(deque<Value>% right);`  
  
 inicializa a sequência controlada pela sequência `[``right``.`[deque::begin](../dotnet/deque-begin-stl-clr.md)`(),` `right``.`[deque::end](../Topic/deque::end%20\(STL-CLR\).md)`())`.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de deque.  
  
 O construtor:  
  
 `deque(deque<Value>^ right);`  
  
 inicializa a sequência controlada pela sequência `[``right``->`[deque::begin](../dotnet/deque-begin-stl-clr.md)`(),` `right``->`[deque::end](../Topic/deque::end%20\(STL-CLR\).md)`())`.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de deque cujo identificador é `right`.  
  
 O construtor:  
  
 `explicit deque(size_type count);`  
  
 inicializa a sequência controlada com elementos de `count` cada um com valor `value_type()`.  Você usará para preencher qualquer contêiner com elementos que tem o valor padrão.  
  
 O construtor:  
  
 `deque(size_type count, value_type val);`  
  
 inicializa a sequência controlada com elementos de `count` cada um com valor `val`.  Use\-a para preencher qualquer contêiner com elementos que tem o mesmo valor.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `deque(InIt first, InIt last);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência.  
  
 O construtor:  
  
 `deque(System::Collections::Generic::IEnumerable<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador.  
  
## Exemplo  
  
```  
// cliext_deque_construct.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
// construct an empty container   
    cliext::deque<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct with a repetition of default values   
    cliext::deque<wchar_t> c2(3);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// construct with a repetition of values   
    cliext::deque<wchar_t> c3(6, L'x');   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    cliext::deque<wchar_t>::iterator it = c3.end();   
    cliext::deque<wchar_t> c4(c3.begin(), --it);   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    cliext::deque<wchar_t> c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    cliext::deque<wchar_t> c7(c3);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    cliext::deque<wchar_t> c8(%c3);   
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
 **Cabeçalho:** \<cliext\/deque\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [deque::assign](../dotnet/deque-assign-stl-clr.md)   
 [deque::generic\_container](../Topic/deque::generic_container%20\(STL-CLR\).md)   
 [operador\= \(deque\)](../dotnet/operator-assign-deque-stl-clr.md)