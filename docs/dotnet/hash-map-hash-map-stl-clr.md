---
title: "hash_map::hash_map (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_map::hash_map"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro hash_map [STL/CLR]"
ms.assetid: d65eb3fa-4bf9-4186-95f8-5517c90ef1fa
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_map::hash_map (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto contêiner.  
  
## Sintaxe  
  
```  
hash_map();  
explicit hash_map(key_compare^ pred);  
hash_map(key_compare^ pred, hasher^ hashfn);  
hash_map(hash_map<Key, Mapped>% right);  
hash_map(hash_map<Key, Mapped>^ right);  
template<typename InIter>  
    hash_maphash_map(InIter first, InIter last);  
template<typename InIter>  
    hash_map(InIter first, InIter last,  
        key_compare^ pred);  
template<typename InIter>  
    hash_map(InIter first, InIter last,  
        key_compare^ pred, hasher^ hashfn);  
hash_map(System::Collections::Generic::IEnumerable<GValue>^ right);  
hash_map(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred);  
hash_map(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred, hasher^ hashfn);  
```  
  
#### Parâmetros  
 primeiro  
 Início do intervalo a ser inserido.  
  
 hashfn  
 Função de hash para mapear chaves para os segmentos.  
  
 last  
 O fim do intervalo a ser inserido.  
  
 pred  
 Ordenando o predicado da sequência controlada.  
  
 direita  
 Objeto ou intervalo a ser inserido.  
  
## Comentários  
 O construtor:  
  
 `hash_map();`  
  
 inicializa a sequência controlada sem os elementos, com o predicado padrão de ordenação `key_compare()`, e com a função de hash padrão.  Use\-a para especificar inicial uma sequência vazia, controlada com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `explicit hash_map(key_compare^ pred);`  
  
 inicializa a sequência controlada sem os elementos, com o predicado de ordenação `pred`, e com a função de hash padrão.  Use\-a para especificar inicial uma sequência vazia, controlada pelo predicado especificado e ordenando a função de hash padrão.  
  
 O construtor:  
  
 `hash_map(key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada sem os elementos, com o predicado de ordenação `pred`, e com a função de hash `hashfn`.  Use\-a para especificar inicial uma sequência vazia, controlada com o predicado e a função de hash ordenando especificados.  
  
 O construtor:  
  
 `hash_map(hash_map<Key, Mapped>% right);`  
  
 inicializa a sequência controlada pela sequência `[``right``.`[hash\_map::begin](../dotnet/hash-map-begin-stl-clr.md)`(),` `right``.`[hash\_map::end](../dotnet/hash-map-end-stl-clr.md)`())`, com o padrão de ordenação predicado, e com a função de hash padrão.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de hash\_map, com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `hash_map(hash_map<Key, Mapped>^ right);`  
  
 inicializa a sequência controlada pela sequência `[``right``->`[hash\_map::begin](../dotnet/hash-map-begin-stl-clr.md)`(),` `right``->`[hash\_map::end](../dotnet/hash-map-end-stl-clr.md)`())`, com o padrão de ordenação predicado, e com a função de hash padrão.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de hash\_map, com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `template<typename InIter>`  
  
 `hash_map(InIter first, InIter last);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`, com o padrão de ordenação predicado, e com a função de hash padrão.  Use\-a para tornar a sequência controlada uma cópia de outra sequência, com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `template<typename InIter>`  
  
 `hash_map(InIter first, InIter last,`  
  
 `key_compare^ pred);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`, com o predicado de ordenação `pred`, e com a função de hash padrão.  Use\-a para tornar a sequência controlada uma cópia de outra sequência, com o predicado ordenando especificado e a função de hash padrão.  
  
 O construtor:  
  
 `template<typename InIter>`  
  
 `hash_map(InIter first, InIter last,`  
  
 `key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`, com o predicado de ordenação `pred`, e com a função de hash `hashfn`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência, com o predicado e a função de hash ordenando especificados.  
  
 O construtor:  
  
 `hash_map(System::Collections::Generic::IEnumerable<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o padrão de ordenação predicado, e com a função de hash padrão.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `hash_map(System::Collections::Generic::IEnumerable<Key>^ right,`  
  
 `key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado de ordenação `pred`, e com a função de hash padrão.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado e a função de hash para classificar a opção especificada.  
  
 O construtor:  
  
 `hash_map(System::Collections::Generic::IEnumerable<Key>^ right,`  
  
 `key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado de ordenação `pred`, e com a função de hash `hashfn`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado e a função de hash ordenando especificados.  
  
## Exemplo  
  
```  
// cliext_hash_map_construct.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
int myfun(wchar_t key)   
    { // hash a key   
    return (key ^ 0xdeadbeef);   
    }   
  
typedef cliext::hash_map<wchar_t, int> Myhash_map;   
int main()   
    {   
// construct an empty container   
    Myhash_map c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.insert(Myhash_map::make_value(L'a', 1));   
    c1.insert(Myhash_map::make_value(L'b', 2));   
    c1.insert(Myhash_map::make_value(L'c', 3));   
    for each (Myhash_map::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an ordering rule   
    Myhash_map c2 = cliext::greater_equal<wchar_t>();   
    System::Console::WriteLine("size() = {0}", c2.size());   
  
    c2.insert(c1.begin(), c1.end());   
    for each (Myhash_map::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an ordering rule and hash function   
    Myhash_map c2h(cliext::greater_equal<wchar_t>(),   
        gcnew Myhash_map::hasher(&myfun));   
    System::Console::WriteLine("size() = {0}", c2h.size());   
  
    c2h.insert(c1.begin(), c1.end());   
    for each (Myhash_map::value_type elem in c2h)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    Myhash_map c3(c1.begin(), c1.end());   
    for each (Myhash_map::value_type elem in c3)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule   
    Myhash_map c4(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>());   
    for each (Myhash_map::value_type elem in c4)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule and hash function   
    Myhash_map c4h(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>(),   
        gcnew Myhash_map::hasher(&myfun));   
    for each (Myhash_map::value_type elem in c4h)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    Myhash_map c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Myhash_map::value_type>^)%c3);   
    for each (Myhash_map::value_type elem in c5)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule   
    Myhash_map c6(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Myhash_map::value_type>^)%c3,   
                cliext::greater_equal<wchar_t>());   
    for each (Myhash_map::value_type elem in c6)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule and hash function   
    Myhash_map c6h(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<   
            Myhash_map::value_type>^)%c3,   
                cliext::greater_equal<wchar_t>(),   
                gcnew Myhash_map::hasher(&myfun));   
    for each (Myhash_map::value_type elem in c6h)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Myhash_map c7(c4);   
    for each (Myhash_map::value_type elem in c7)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    Myhash_map c8(%c3);   
    for each (Myhash_map::value_type elem in c8)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **size\(\) \= 0**  
 **um \[1\] \[2\] \[b3 c\]**  
**size\(\) \= 0**  
 **um \[1\] \[2\] \[b3 c\]**  
**size\(\) \= 0**  
 **c \[3\] \[2\] \[bum 1\]**  
 **um \[1\] \[2\] \[b3 c\]**  
 **um \[1\] \[2\] \[b3 c\]**  
 **c \[3\] \[2\] \[bum 1\]**  
 **um \[1\] \[2\] \[b3 c\]**  
 **um \[1\] \[2\] \[b3 c\]**  
 **c \[3\] \[2\] \[bum 1\]**  
 **um \[1\] \[2\] \[b3 c\]**  
 **um \[1\] \[2\] \[b3 c\]**   
## Requisitos  
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_map::generic\_container](../dotnet/hash-map-generic-container-stl-clr.md)   
 [hash\_map::operator\=](../dotnet/hash-map-operator-assign-stl-clr.md)