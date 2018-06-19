---
title: 'priority_queue:: priority_queue (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::priority_queue::priority_queue
dev_langs:
- C++
helpviewer_keywords:
- priority_queue member [STL/CLR]
ms.assetid: aab423d7-959e-48fd-9028-e9f45f43cb8a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8cb50eed9dbfcbe9480a6588ff10f966f1888205
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33163387"
---
# <a name="priorityqueuepriorityqueue-stlclr"></a>priority_queue::priority_queue (STL/CLR)
Constrói um objeto de adaptador do contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 continuação  
 O contêiner a ser copiado.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 Pred  
 Ordenação de predicado para sequência controlada.  
  
 direita  
 Objeto ou intervalo a inserir.  
  
## <a name="remarks"></a>Comentários  
 O construtor:  
  
 `priority_queue();`  
  
 cria um contêiner encapsulado vazio, com o padrão de ordenação de predicado. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `priority_queue(priority_queue<Value, Container>% right);`  
  
 cria um contêiner encapsulado que é uma cópia do `right.get_container()`, com o predicado ordenação `right.value_comp()`. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de fila `right`, com o mesmo predicado ordenação.  
  
 O construtor:  
  
 `priority_queue(priority_queue<Value, Container>^ right);`  
  
 cria um contêiner encapsulado que é uma cópia do `right->get_container()`, com o predicado ordenação `right->value_comp()`. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de fila `*right`, com o mesmo predicado ordenação.  
  
 O construtor:  
  
 `explicit priority_queue(value_compare^ pred);`  
  
 cria um contêiner de encapsulado vazio, com o predicado ordenação `pred`. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o predicado de ordenação especificado.  
  
 O construtor:  
  
 `priority_queue(value_compare^ pred, container_type cont);`  
  
 cria um contêiner de encapsulado vazio, com o predicado de ordenação `pred`, em seguida, envia todos os elementos de `cont` usá-lo para especificar uma sequência controlada inicial de um contêiner existente, com o predicado de ordenação especificado.  
  
 O construtor:  
  
 `template<typename InIt> priority_queue(InIt first, InIt last);`  
  
 cria um contêiner encapsulado vazio, com o predicado de classificação padrão e, depois, a sequência [`first`, `last`). Você pode usá-lo para especificar uma sequência controlada inicial de um eqeuence especificado, com o predicado de ordenação especificado.  
  
 O construtor:  
  
 `template<typename InIt> priority_queue(InIt first, InIt last, value_compare^ pred);`  
  
 cria um contêiner de encapsulado vazio, com o predicado ordenação `pred`, em seguida, envia a sequência [`first`, `last`). Você pode usá-lo para especificar uma sequência controlada inicial de um seqeuence especificado, com o predicado de ordenação especificado.  
  
 O construtor:  
  
 `template<typename InIt> priority_queue(InIt first, InIt last, value_compare^ pred, container_type% cont);`  
  
 cria um contêiner de encapsulado vazio, com o predicado de ordenação `pred`, em seguida, envia todos os elementos de `cont` mais a sequência de [`first`, `last`). Você pode usá-lo para especificar uma sequência controlada inicial de um contêiner existente e um seqeuence especificado, com o predicado de ordenação especificado.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
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
  
```Output  
size() = 0  
 c a b  
size() = 0  
 a c b  
 a c b  
 c a b  
 a c b  
 a a b c c b  
 c a b  
 c a b  
 a c b  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/fila >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md)   
 [priority_queue::Assign (STL/CLR)](../dotnet/priority-queue-assign-stl-clr.md)   
 [priority_queue::generic_container (STL/CLR)](../dotnet/priority-queue-generic-container-stl-clr.md)   
 [priority_queue::operator= (STL/CLR)](../dotnet/priority-queue-operator-assign-stl-clr.md)