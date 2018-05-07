---
title: 'hash_set:: hash_set (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_set::hash_set
dev_langs:
- C++
helpviewer_keywords:
- hash_set member [STL/CLR]
ms.assetid: 006414ed-db5a-4c08-ac81-4a8ae57d0aad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1e0f8ce11d66b02c63d2eee6cf2022c16c214fe2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="hashsethashset-stlclr"></a>hash_set::hash_set (STL/CLR)
Constrói um objeto contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
hash_set();  
explicit hash_set(key_compare^ pred);  
hash_set(key_compare^ pred, hasher^ hashfn);  
hash_set(hash_set<Key>% right);  
hash_set(hash_set<Key>^ right);  
template<typename InIter>  
    hash_sethash_set(InIter first, InIter last);  
template<typename InIter>  
    hash_set(InIter first, InIter last,  
        key_compare^ pred);  
template<typename InIter>  
    hash_set(InIter first, InIter last,  
        key_compare^ pred, hasher^ hashfn);  
hash_set(System::Collections::Generic::IEnumerable<GValue>^ right);  
hash_set(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred);  
hash_set(System::Collections::Generic::IEnumerable<GValue>^ right,  
    key_compare^ pred, hasher^ hashfn);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 primeiro  
 Início do intervalo a ser inserido.  
  
 hashfn  
 Função para chaves de mapeamento para buckets de hash.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 Pred  
 Ordenação de predicado para sequência controlada.  
  
 direita  
 Objeto ou intervalo a inserir.  
  
## <a name="remarks"></a>Comentários  
 O construtor:  
  
 `hash_set();`  
  
 inicializa a sequência controlada com nenhum elemento com o padrão de ordenação predicado `key_compare()`e com a função de hash padrão. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o padrão de ordenação de função de predicado e hash.  
  
 O construtor:  
  
 `explicit hash_set(key_compare^ pred);`  
  
 inicializa a sequência controlada com nenhum elemento, com o predicado ordenação `pred`e com a função de hash padrão. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com o predicado de ordenação especificado e a função de hash padrão.  
  
 O construtor:  
  
 `hash_set(key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada com nenhum elemento, com o predicado ordenação `pred`e com a função de hash `hashfn`. Você pode usá-lo para especificar uma inicial controlada sequência vazia, com a função de predicado e hash ordenação especificada.  
  
 O construtor:  
  
 `hash_set(hash_set<Key>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`), com o padrão de ordenação de predicado e com a função de hash padrão. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto hash_set `right`com o predicado de classificação padrão e a função de hash.  
  
 O construtor:  
  
 `hash_set(hash_set<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`), com o padrão de ordenação de predicado e com a função de hash padrão. Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto hash_set `right`com o predicado de classificação padrão e a função de hash.  
  
 O construtor:  
  
 `template<typename InIter> hash_set(InIter first, InIter last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o padrão de ordenação de predicado e com a função de hash padrão. Você pode usá-lo para fazer uma cópia de outra sequência, de sequência controlada com o padrão de ordenação de função de predicado e hash.  
  
 O construtor:  
  
 `template<typename InIter> hash_set(InIter first, InIter last, key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o predicado ordenação `pred`e com a função de hash padrão. Você pode usá-lo para fazer uma cópia de outra sequência, com o predicado de ordenação especificado e a função de hash padrão de sequência controlada.  
  
 O construtor:  
  
 `template<typename InIter> hash_set(InIter first, InIter last, key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`), com o predicado ordenação `pred`e com a função de hash `hashfn`. Você pode usá-lo para fazer uma cópia de outra sequência, com a função especificada e ordenação de predicado e hash de sequência controlada.  
  
 O construtor:  
  
 `hash_set(System::Collections::Generic::IEnumerable<Key>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o padrão de ordenação de predicado e com a função de hash padrão. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com o padrão de ordenação de função de predicado e hash de sequência controlada.  
  
 O construtor:  
  
 `hash_set(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado ordenação `pred`e com a função de hash padrão. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com a função de hash padrão e o predicado de ordenação especificado de sequência controlada.  
  
 O construtor:  
  
 `hash_set(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred, hasher^ hashfn);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`, com o predicado ordenação `pred`e com a função de hash `hashfn`. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador, com a função de predicado e hash ordenação especificada de sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_set_construct.cpp   
// compile with: /clr   
#include <cliext/hash_set>   
  
int myfun(wchar_t key)   
    { // hash a key   
    return (key ^ 0xdeadbeef);   
    }   
  
typedef cliext::hash_set<wchar_t> Myhash_set;   
int main()   
    {   
// construct an empty container   
    Myhash_set c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an ordering rule   
    Myhash_set c2 = cliext::greater_equal<wchar_t>();   
    System::Console::WriteLine("size() = {0}", c2.size());   
  
    c2.insert(c1.begin(), c1.end());   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an ordering rule and hash function   
    Myhash_set c2h(cliext::greater_equal<wchar_t>(),   
        gcnew Myhash_set::hasher(&myfun));   
    System::Console::WriteLine("size() = {0}", c2h.size());   
  
    c2h.insert(c1.begin(), c1.end());   
    for each (wchar_t elem in c2h)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    Myhash_set c3(c1.begin(), c1.end());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule   
    Myhash_set c4(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>());   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range and an ordering rule and hash function   
    Myhash_set c4h(c1.begin(), c1.end(),   
        cliext::greater_equal<wchar_t>(),   
        gcnew Myhash_set::hasher(&myfun));   
    for each (wchar_t elem in c4h)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    Myhash_set c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule   
    Myhash_set c6(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3,   
            cliext::greater_equal<wchar_t>());   
    for each (wchar_t elem in c6)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration and an ordering rule and hash function   
    Myhash_set c6h(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3,   
            cliext::greater_equal<wchar_t>(),   
                gcnew Myhash_set::hasher(&myfun));   
    for each (wchar_t elem in c6h)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine();   
  
// construct from a generic container   
    Myhash_set c7(c4);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    Myhash_set c8(%c3);   
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
 a b c  
size() = 0  
 c b a  
  
 a b c  
 a b c  
 c b a  
  
 a b c  
 a b c  
 c b a  
  
 a b c  
 a b c  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [hash_set::generic_container (STL/CLR)](../dotnet/hash-set-generic-container-stl-clr.md)   
 [hash_set::operator= (STL/CLR)](../dotnet/hash-set-operator-assign-stl-clr.md)