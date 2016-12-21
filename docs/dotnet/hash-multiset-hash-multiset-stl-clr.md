---
title: "hash_multiset::hash_multiset (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_multiset::hash_multiset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro hash_multiset [STL/CLR]"
ms.assetid: 1b224c60-b714-4ed5-9234-79b61b92a953
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multiset::hash_multiset (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto contêiner.  
  
## Sintaxe  
  
```  
hash_multiset();  
explicit hash_multiset(key_compare^ pred);  
hash_multiset(key_compare^ pred, hasher^ hashfn);  
hash_multiset(hash_multiset<Key>% right);  
hash_multiset(hash_multiset<Key>^ right);  
template<typename InIter>  
    hash_multiset(InIter first, InIter last);  
template<typename InIter>  
    hash_multiset(InIter first, InIter last,  
        key_compare^ pred);  
template<typename InIter>  
    hash_multiset(InIter first, InIter last,  
        key_compare^ pred, hasher^ hashfn);  
hash_multiset(System::Collections::Generic::IEnumerable<GValue>^ right);  
hash_multiset(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred);  
hash_multiset(System::Collections::Generic::IEnumerable<GValue>^ right,  
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
  
 `hash_multiset();`  
  
 inicializa a sequência controlada sem os elementos, com o predicado padrão de ordenação `key_compare()`, e com a função de hash padrão.  Use\-a para especificar inicial uma sequência vazia, controlada com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `explicit hash_multiset(key_compare^ pred);`  
  
 inicializa a sequência controlada sem os elementos, com o predicado de ordenação `pred`, e com a função de hash padrão.  Use\-a para especificar inicial uma sequência vazia, controlada pelo predicado especificado e ordenando a função de hash padrão.  
  
 O construtor:  
  
 `hash_multiset(key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada sem os elementos, com o predicado de ordenação `pred`, e com a função de hash `hashfn`.  Use\-a para especificar inicial uma sequência vazia, controlada com o predicado e a função de hash ordenando especificados.  
  
 O construtor:  
  
 `hash_multiset(hash_multiset<Key>% right);`  
  
 inicializa a sequência controlada pela sequência `[``right``.`[hash\_multiset::begin](../dotnet/hash-multiset-begin-stl-clr.md)`(),` `right``.`[hash\_multiset::end](../dotnet/hash-multiset-end-stl-clr.md)`())`, com o padrão de ordenação predicado, e com a função de hash padrão.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de hash\_multiset, com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `hash_multiset(hash_multiset<Key>^ right);`  
  
 inicializa a sequência controlada pela sequência `[``right``->`[hash\_multiset::begin](../dotnet/hash-multiset-begin-stl-clr.md)`(),` `right``->`[hash\_multiset::end](../dotnet/hash-multiset-end-stl-clr.md)`())`, com o padrão de ordenação predicado, e com a função de hash padrão.  Use\-a para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto `right`de hash\_multiset, com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `template<typename InIter>`  
  
 `hash_multiset(InIter first, InIter last);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`, com o padrão de ordenação predicado, e com a função de hash padrão.  Use\-a para tornar a sequência controlada uma cópia de outra sequência, com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `template<typename InIter>`  
  
 `hash_multiset(InIter first, InIter last,`  
  
 `key_compare^ pred);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`, com o predicado de ordenação `pred`, e com a função de hash padrão.  Use\-a para tornar a sequência controlada uma cópia de outra sequência, com o predicado ordenando especificado e a função de hash padrão.  
  
 O construtor:  
  
 `template<typename InIter>`  
  
 `hash_multiset(InIter first, InIter last,`  
  
 `key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada pela sequência `[``first``,` `last``)`, com o predicado de ordenação `pred`, e com a função de hash `hashfn`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência, com o predicado e a função de hash ordenando especificados.  
  
 O construtor:  
  
 `hash_multiset(System::Collections::Generic::IEnumerable<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o padrão de ordenação predicado, e com a função de hash padrão.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado e a função de hash ordenando padrão.  
  
 O construtor:  
  
 `hash_multiset(System::Collections::Generic::IEnumerable<Key>^ right,`  
  
 `key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado de ordenação `pred`, e com a função de hash padrão.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado e a função de hash para classificar a opção especificada.  
  
 O construtor:  
  
 `hash_multiset(System::Collections::Generic::IEnumerable<Key>^ right,`  
  
 `key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado de ordenação `pred`, e com a função de hash `hashfn`.  Use\-a para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado e a função de hash ordenando especificados.  
  
## Exemplo  
  
```  
// cliext_hash_multiset_construct.cpp   
// compile with: /clr   
#include <cliext/hash_set>   
  
int myfun(wchar_t key)   
    { // hash a key   
    return (key ^ 0xdeadbeef);   
    }   
  
typedef cliext::hash_multiset<wchar_t> Myhash_multiset;   
int main()   
    {   
// construct an empty container   
    Myhash_multiset c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an ordering rule   
    Myhash_multiset c2 = cliext::greater_equal<wchar_t>();   
    System::Console::WriteLine("size() = {0}", c2.size());   
  
    c2.insert(c1.begin(), c1.end());   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an ordering rule and hash function   
    Myhash_multiset c2h(cliext::greater_equal<wchar_t>(),   
        gcnew Myhash_multiset::hasher(&myfun));   
    System::Console::WriteLine("size() = {0}", c2h.size());   
  
    c2h.insert(c1.begin(), c1.end());   
    for each (wchar_t elem in c2h)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    Myhash_multiset c3(c1.begin(), c1.end());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule   
    Myhash_multiset c4(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>());   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule and hash function   
    Myhash_multiset c4h(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>(),   
        gcnew Myhash_multiset::hasher(&myfun));   
    for each (wchar_t elem in c4h)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    Myhash_multiset c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule   
    Myhash_multiset c6(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3,   
            cliext::greater_equal<wchar_t>());   
    for each (wchar_t elem in c6)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule and hash function   
    Myhash_multiset c6h(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3,   
            cliext::greater_equal<wchar_t>(),   
                gcnew Myhash_multiset::hasher(&myfun));   
    for each (wchar_t elem in c6h)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct from a generic container   
    Myhash_multiset c7(c4);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Myhash_multiset c8(%c3);   
    for each (wchar_t elem in c8)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **size\(\) \= 0**  
 **um b c**  
**size\(\) \= 0**  
 **um b c**  
**size\(\) \= 0**  
 **b para c**  
 **um b c**  
 **um b c**  
 **b para c**  
 **um b c**  
 **um b c**  
 **b para c**  
 **um b c**  
 **um b c**   
## Requisitos  
 cliext \<\/hash\_set de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_multiset::generic\_container](../dotnet/hash-multiset-generic-container-stl-clr.md)   
 [hash\_multiset::operator\=](../dotnet/hash-multiset-operator-assign-stl-clr.md)