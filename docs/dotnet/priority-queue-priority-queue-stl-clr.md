---
title: "priority_queue::priority_queue (STL/CLR) | Microsoft Docs"
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
  - "cliext::priority_queue::priority_queue"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro priority_queue [STL/CLR]"
ms.assetid: aab423d7-959e-48fd-9028-e9f45f43cb8a
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# priority_queue::priority_queue (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto do adaptador do contêiner.  
  
## Sintaxe  
  
```  
priority_queue();  
priority_queue(priority_queue<Value, Container> right);  
priority_queue(priority_queue<Value, Container> right);  
explicit priority_queue(value_compare^ pred);  
priority_queue(value_compare^ pred, container_type% cont);  
template<typename InIt>  
    priority_queue(InIt first, InIt last);  
template<typename InIt>  
    priority_queue(InIt first, InIt last,  
        value_compare^ pred);  
template<typename InIt>  
    priority_queue(InIt first, InIt last,  
        value_compare^ pred, container_type% cont);  
```  
  
#### Parâmetros  
 cont  
 Contêiner a ser copiada.  
  
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
  
 `priority_queue();`  
  
 cria um contêiner de conjunto vazio, com o padrão de ordenação predicado.  Você usa para especificar inicial uma sequência vazia, controlada com o predicado padrão de ordenação.  
  
 O construtor:  
  
 `priority_queue(priority_queue<Value, Container>% right);`  
  
 cria um contêiner ajustado que é uma cópia de `right.get_container()`, com o predicado de ordenação `right.value_comp()`.  Você usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto da fila `right`, com o mesmo predicado de solicitação.  
  
 O construtor:  
  
 `priority_queue(priority_queue<Value, Container>^ right);`  
  
 cria um contêiner ajustado que é uma cópia de `right->get_container()`, com o predicado de ordenação `right->value_comp()`.  Você usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto da fila `*right`, com o mesmo predicado de solicitação.  
  
 O construtor:  
  
 `explicit priority_queue(value_compare^ pred);`  
  
 cria um contêiner de conjunto vazio, com o predicado de ordenação `pred`.  Você usa para especificar inicial uma sequência vazia, controlada pelo predicado especificado. ordenando  
  
 O construtor:  
  
 `priority_queue(value_compare^ pred, container_type cont);`  
  
 cria um contêiner de conjunto vazio, com o predicado de ordenação `pred`, então empurra todos os elementos de `cont` que você usa para especificar uma sequência controlada inicial de um contêiner existente, com o predicado ordenando especificado.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `priority_queue(InIt first, InIt last);`  
  
 cria um contêiner de conjunto vazio, com o padrão de ordenação predicado, então empurra a sequência `[``first``,` `last``)`.  Use\-a para especificar uma sequência controlada inicial de um eqeuence especificado, com o predicado ordenando especificado.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `priority_queue(InIt first, InIt last,`  
  
 `value_compare^ pred);`  
  
 cria um contêiner de conjunto vazio, com o predicado de ordenação `pred`, então empurra a sequência `[``first``,` `last``)`.  Use\-a para especificar uma sequência controlada inicial de um seqeuence especificado, com o predicado ordenando especificado.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `priority_queue(InIt first, InIt last,`  
  
 `value_compare^ pred, container_type% cont);`  
  
 cria um contêiner de conjunto vazio, com o predicado de ordenação `pred`, então empurra todos os elementos de `cont` mais a sequência `[``first``,` `last``)`.  Use\-a para especificar uma sequência controlada inicial de um contêiner existente e um seqeuence especificado, com o predicado ordenando especificado.  
  
## Exemplo  
  
```  
// cliext_priority_queue_construct.cpp   
// compile with: /clr   
#include <cliext/queue>   
#include <cliext/deque>   
  
typedef cliext::priority_queue<wchar_t> Mypriority_queue;   
typedef cliext::deque<wchar_t> Mydeque;   
int main()   
    {   
// construct an empty container   
    Mypriority_queue c1;   
    Mypriority_queue::container_type^ wc1 = c1.get_container();   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
    for each (wchar_t elem in wc1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an ordering rule   
    Mypriority_queue c2 = cliext::greater<wchar_t>();   
    System::Console::WriteLine("size() = {0}", c2.size());   
  
    for each (wchar_t elem in wc1)   
        c2.push(elem);   
    for each (wchar_t elem in c2.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an ordering rule by copying an underlying container   
    Mypriority_queue c2x =   
        gcnew Mypriority_queue(cliext::greater<wchar_t>(), *wc1);   
   for each (wchar_t elem in c2x.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    Mypriority_queue c3(wc1->begin(), wc1->end());   
    for each (wchar_t elem in c3.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule   
    Mypriority_queue c4(wc1->begin(), wc1->end(),   
        cliext::greater<wchar_t>());   
    for each (wchar_t elem in c4.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range, another container, and an ordering rule   
    Mypriority_queue c5(wc1->begin(), wc1->end(),   
        cliext::greater<wchar_t>(), *wc1);   
    for each (wchar_t elem in c5.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct from a generic container   
    Mypriority_queue c6(c3);   
    for each (wchar_t elem in c6.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Mypriority_queue c7(%c3);   
    for each (wchar_t elem in c7.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an ordering rule, by copying an underlying container   
    Mypriority_queue c8 =   
        gcnew Mypriority_queue(cliext::greater<wchar_t>(), *wc1);   
    for each (wchar_t elem in c8.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    return (0);   
    }  
  
```  
  
  **size\(\) \= 0**  
 **c um b**  
**size\(\) \= 0**  
 **c b**  
 **c b**  
 **c um b**  
 **c b**  
 **um b c c b**  
 **c um b**  
 **c um b**  
 **c b**   
## Requisitos  
 cliext \<\/fila de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)   
 [priority\_queue::assign](../dotnet/priority-queue-assign-stl-clr.md)   
 [priority\_queue::generic\_container](../dotnet/priority-queue-generic-container-stl-clr.md)   
 [priority\_queue::operator\=](../dotnet/priority-queue-operator-assign-stl-clr.md)