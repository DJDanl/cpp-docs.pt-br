---
title: 'multiset:: multiset (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::multiset::multiset
dev_langs:
- C++
helpviewer_keywords:
- multiset member [STL/CLR]
ms.assetid: a6ddb2df-d7cd-4b12-aee7-81da1f67f57f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f890a7051d6764f2168c5d90859219fb3513031e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="multisetmultiset-stlclr"></a>multiset::multiset (STL/CLR)
Constrói um objeto contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
multiset();  
explicit multiset(key_compare^ pred);  
multiset(multiset<Key>% right);  
multiset(multiset<Key>^ right);  
template<typename InIter>  
    multisetmultiset(InIter first, InIter last);  
template<typename InIter>  
    multiset(InIter first, InIter last,  
        key_compare^ pred);  
multiset(System::Collections::Generic::IEnumerable<GValue>^ right);  
multiset(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred);  
```  
  
#### <a name="parameters"></a>Parâmetros  
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
  
 `multiset();`  
  
 inicializa a sequência controlada com nenhum elemento com o padrão de ordenação predicado `key_compare()`. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `explicit multiset(key_compare^ pred);`  
  
 inicializa a sequência controlada com nenhum elemento, com o predicado ordenação `pred`. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o predicado de ordenação especificado.  
  
 O construtor:  
  
 `multiset(multiset<Key>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`), com o padrão de ordenação de predicado. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto multiset `right`, com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `multiset(multiset<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`), com o padrão de ordenação de predicado. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto multiset `right`, com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `template<typename InIter> multiset(InIter first, InIter last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o padrão de ordenação de predicado. Você pode usá-lo para fazer uma cópia de outra sequência, de sequência controlada com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `template<typename InIter> multiset(InIter first, InIter last, key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o predicado ordenação `pred`. Você pode usá-lo para fazer uma cópia de outra sequência, com o predicado especificado de ordenação de sequência controlada.  
  
 O construtor:  
  
 `multiset(System::Collections::Generic::IEnumerable<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o padrão de ordenação de predicado. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com o padrão de ordenação de predicado de sequência controlada.  
  
 O construtor:  
  
 `multiset(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado ordenação `pred`. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com o predicado especificado de ordenação de sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// cliext_multiset_construct.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::multiset<wchar_t> Mymultiset;   
int main()   
    {   
// construct an empty container   
    Mymultiset c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an ordering rule   
    Mymultiset c2 = cliext::greater_equal<wchar_t>();   
    System::Console::WriteLine("size() = {0}", c2.size());   
  
    c2.insert(c1.begin(), c1.end());   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    Mymultiset c3(c1.begin(), c1.end());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule   
    Mymultiset c4(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>());   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    Mymultiset c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule   
    Mymultiset c6(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3,   
            cliext::greater_equal<wchar_t>());   
    for each (wchar_t elem in c6)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct from a generic container   
    Mymultiset c7(c4);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Mymultiset c8(%c3);   
    for each (wchar_t elem in c8)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
size() = 0  
 a b c  
size() = 0  
 c b a  
 a b c  
 c b a  
 a b c  
 c b a  
 c b a  
 a b c  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [multiconjunto (STL/CLR)](../dotnet/multiset-stl-clr.md)   
 [multiset::generic_container (STL/CLR)](../dotnet/multiset-generic-container-stl-clr.md)   
 [multiset::operator= (STL/CLR)](../dotnet/multiset-operator-assign-stl-clr.md)