---
title: 'List:: List (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::list::list
dev_langs: C++
helpviewer_keywords: list member [STL/CLR]
ms.assetid: 51b58f63-c65a-4d54-b746-0c10635b123b
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 2ae85dbdab7bb1d72862aa315949821ba5cdb830
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="listlist-stlclr"></a>list::list (STL/CLR)
Constrói um objeto contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `count`  
 Número de elementos a inserir.  
  
 `first`  
 Início do intervalo a ser inserido.  
  
 `last`  
 Fim do intervalo a ser inserido.  
  
 `right`  
 Objeto ou intervalo a inserir.  
  
 `val`  
 Valor do elemento a ser inserido.  
  
## <a name="remarks"></a>Comentários  
  
 O construtor:  
  
 `list();`  
  
 inicializa a sequência controlada com nenhum elemento. Você pode usá-lo para especificar uma sequência vazia de controlado inicial.  
  
 O construtor:  
  
 `list(list<Value>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto lista `right`.  
  
 O construtor:  
  
 `list(list<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto lista cujo identificador é `right`.  
  
 O construtor:  
  
 `explicit list(size_type count);`  
  
 inicializa a sequência controlada com `count` elementos com o valor `value_type()`. Você usá-lo para preencher o contêiner com elementos todos com o valor padrão.  
  
 O construtor:  
  
 `list(size_type count, value_type val);`  
  
 inicializa a sequência controlada com `count` elementos com o valor `val`. Você usá-lo para preencher o contêiner com elementos todos com o mesmo valor.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `list(InIt first, InIt last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`). Você pode usá-lo para fazer uma cópia de outra sequência de sequência controlada.  
  
 O construtor:  
  
 `list(System::Collections::Generic::IEnumerable<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador de sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
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
  
```Output  
size() = 0  
 0 0 0  
 x x x x x x  
 x x x x x  
 x x x x x x  
 x x x x x x  
 x x x x x x  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/lista >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [List:: Assign (STL/CLR)](../dotnet/list-assign-stl-clr.md)   
 [List::generic_container (STL/CLR)](../dotnet/list-generic-container-stl-clr.md)   
 [list::operator= (STL/CLR)](../dotnet/list-operator-assign-stl-clr.md)