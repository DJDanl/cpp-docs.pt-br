---
title: 'Map:: Map (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::map::map
dev_langs:
- C++
helpviewer_keywords:
- map member [STL/CLR]
ms.assetid: c91f699a-4742-4859-b2b3-c2a01a750bea
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: cd39f72c776065eadac713012440b9fe4701329a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mapmap-stlclr"></a>map::map (STL/CLR)
Constrói um objeto contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
map();  
explicit map(key_compare^ pred);  
map(map<Key, Mapped>% right);  
map(map<Key, Mapped>^ right);  
template<typename InIter>  
    mapmap(InIter first, InIter last);  
template<typename InIter>  
    map(InIter first, InIter last,  
        key_compare^ pred);  
map(System::Collections::Generic::IEnumerable<GValue>^ right);  
map(System::Collections::Generic::IEnumerable<GValue>^ right,  
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
  
 `map();`  
  
 inicializa a sequência controlada com nenhum elemento com o padrão de ordenação predicado `key_compare()`. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `explicit map(key_compare^ pred);`  
  
 inicializa a sequência controlada com nenhum elemento, com o predicado ordenação `pred`. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o predicado de ordenação especificado.  
  
 O construtor:  
  
 `map(map<Key, Mapped>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`), com o padrão de ordenação de predicado. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de mapa `right`, com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `map(map<Key, Mapped>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`), com o padrão de ordenação de predicado. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de mapa `right`, com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `template<typename InIter> map(InIter first, InIter last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o padrão de ordenação de predicado. Você pode usá-lo para fazer uma cópia de outra sequência, de sequência controlada com o padrão de ordenação de predicado.  
  
 O construtor:  
  
 `template<typename InIter> map(InIter first, InIter last, key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o predicado ordenação `pred`. Você pode usá-lo para fazer uma cópia de outra sequência, com o predicado especificado de ordenação de sequência controlada.  
  
 O construtor:  
  
 `map(System::Collections::Generic::IEnumerable<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o padrão de ordenação de predicado. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com o padrão de ordenação de predicado de sequência controlada.  
  
 O construtor:  
  
 `map(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado ordenação `pred`. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com o predicado especificado de ordenação de sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// cliext_map_construct.cpp   
// compile with: /clr   
#include <cliext/map>   
  
typedef cliext::map<wchar_t, int> Mymap;   
int main()   
    {   
// construct an empty container   
    Mymap c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.insert(Mymap::make_value(L'a', 1));   
    c1.insert(Mymap::make_value(L'b', 2));   
    c1.insert(Mymap::make_value(L'c', 3));   
    for each (Mymap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an ordering rule   
    Mymap c2 = cliext::greater_equal<wchar_t>();   
    System::Console::WriteLine("size() = {0}", c2.size());   
  
    c2.insert(c1.begin(), c1.end());   
    for each (Mymap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    Mymap c3(c1.begin(), c1.end());   
    for each (Mymap::value_type elem in c3)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule   
    Mymap c4(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>());   
    for each (Mymap::value_type elem in c4)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    Mymap c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Mymap::value_type>^)%c3);   
    for each (Mymap::value_type elem in c5)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule   
    Mymap c6(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Mymap::value_type>^)%c3,   
                cliext::greater_equal<wchar_t>());   
    for each (Mymap::value_type elem in c6)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Mymap c7(c4);   
    for each (Mymap::value_type elem in c7)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    Mymap c8(%c3);   
    for each (Mymap::value_type elem in c8)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
size() = 0  
 [a 1] [b 2] [c 3]  
size() = 0  
 [c 3] [b 2] [a 1]  
 [a 1] [b 2] [c 3]  
 [c 3] [b 2] [a 1]  
 [a 1] [b 2] [c 3]  
 [c 3] [b 2] [a 1]  
 [c 3] [b 2] [a 1]  
 [a 1] [b 2] [c 3]  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/mapa >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [Map (STL/CLR)](../dotnet/map-stl-clr.md)   
 [Map::generic_container (STL/CLR)](../dotnet/map-generic-container-stl-clr.md)   
 [map::operator= (STL/CLR)](../dotnet/map-operator-assign-stl-clr.md)