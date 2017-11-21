---
title: Classe unordered_multimap | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- unordered_map/std::unordered_multimap
- unordered_map/std::unordered_multimap::allocator_type
- unordered_map/std::unordered_multimap::const_iterator
- unordered_map/std::unordered_multimap::const_local_iterator
- unordered_map/std::unordered_multimap::const_pointer
- unordered_map/std::unordered_multimap::const_reference
- unordered_map/std::unordered_multimap::difference_type
- unordered_map/std::unordered_multimap::hasher
- unordered_map/std::unordered_multimap::iterator
- unordered_map/std::unordered_multimap::key_equal
- unordered_map/std::unordered_multimap::key_type
- unordered_map/std::unordered_multimap::local_iterator
- unordered_map/std::unordered_multimap::mapped_type
- unordered_map/std::unordered_multimap::pointer
- unordered_map/std::unordered_multimap::reference
- unordered_map/std::unordered_multimap::size_type
- unordered_map/std::unordered_multimap::value_type
- unordered_map/std::unordered_multimap::begin
- unordered_map/std::unordered_multimap::bucket
- unordered_map/std::unordered_multimap::bucket_count
- unordered_map/std::unordered_multimap::bucket_size
- unordered_map/std::unordered_multimap::cbegin
- unordered_map/std::unordered_multimap::cend
- unordered_map/std::unordered_multimap::clear
- unordered_map/std::unordered_multimap::count
- unordered_map/std::unordered_multimap::emplace
- unordered_map/std::unordered_multimap::emplace_hint
- unordered_map/std::unordered_multimap::empty
- unordered_map/std::unordered_multimap::end
- unordered_map/std::unordered_multimap::equal_range
- unordered_map/std::unordered_multimap::erase
- unordered_map/std::unordered_multimap::find
- unordered_map/std::unordered_multimap::get_allocator
- unordered_map/std::unordered_multimap::hash
- unordered_map/std::unordered_multimap::insert
- unordered_map/std::unordered_multimap::key_eq
- unordered_map/std::unordered_multimap::load_factor
- unordered_map/std::unordered_multimap::max_bucket_count
- unordered_map/std::unordered_multimap::max_load_factor
- unordered_map/std::unordered_multimap::max_size
- unordered_map/std::unordered_multimap::rehash
- unordered_map/std::unordered_multimap::size
- unordered_map/std::unordered_multimap::swap
- unordered_map/std::unordered_multimap::unordered_multimap
- unordered_map/std::unordered_multimap::operator=
- unordered_map/std::unordered_multimap::hash_function
dev_langs: C++
helpviewer_keywords:
- std::unordered_multimap
- std::unordered_multimap::allocator_type
- std::unordered_multimap::const_iterator
- std::unordered_multimap::const_local_iterator
- std::unordered_multimap::const_pointer
- std::unordered_multimap::const_reference
- std::unordered_multimap::difference_type
- std::unordered_multimap::hasher
- std::unordered_multimap::iterator
- std::unordered_multimap::key_equal
- std::unordered_multimap::key_type
- std::unordered_multimap::local_iterator
- std::unordered_multimap::mapped_type
- std::unordered_multimap::pointer
- std::unordered_multimap::reference
- std::unordered_multimap::size_type
- std::unordered_multimap::value_type
- std::unordered_multimap::begin
- std::unordered_multimap::bucket
- std::unordered_multimap::bucket_count
- std::unordered_multimap::bucket_size
- std::unordered_multimap::cbegin
- std::unordered_multimap::cend
- std::unordered_multimap::clear
- std::unordered_multimap::count
- std::unordered_multimap::emplace
- std::unordered_multimap::emplace_hint
- std::unordered_multimap::empty
- std::unordered_multimap::end
- std::unordered_multimap::equal_range
- std::unordered_multimap::erase
- std::unordered_multimap::find
- std::unordered_multimap::get_allocator
- std::unordered_multimap::hash
- std::unordered_multimap::insert
- std::unordered_multimap::key_eq
- std::unordered_multimap::load_factor
- std::unordered_multimap::max_bucket_count
- std::unordered_multimap::max_load_factor
- std::unordered_multimap::max_size
- std::unordered_multimap::rehash
- std::unordered_multimap::size
- std::unordered_multimap::swap
- std::unordered_multimap::unordered_multimap
- std::unordered_multimap::operator=
- std::unordered_multimap::allocator_type
- std::unordered_multimap::const_iterator
- std::unordered_multimap::const_local_iterator
- std::unordered_multimap::const_pointer
- std::unordered_multimap::const_reference
- std::unordered_multimap::difference_type
- std::unordered_multimap::hasher
- std::unordered_multimap::iterator
- std::unordered_multimap::key_equal
- std::unordered_multimap::key_type
- std::unordered_multimap::local_iterator
- std::unordered_multimap::mapped_type
- std::unordered_multimap::pointer
- std::unordered_multimap::reference
- std::unordered_multimap::size_type
- std::unordered_multimap::value_type
- std::unordered_multimap::begin
- std::unordered_multimap::bucket
- std::unordered_multimap::bucket_count
- std::unordered_multimap::bucket_size
- std::unordered_multimap::cbegin
- std::unordered_multimap::cend
- std::unordered_multimap::clear
- std::unordered_multimap::count
- std::unordered_multimap::emplace
- std::unordered_multimap::emplace_hint
- std::unordered_multimap::empty
- std::unordered_multimap::end
- std::unordered_multimap::equal_range
- std::unordered_multimap::erase
- std::unordered_multimap::find
- std::unordered_multimap::get_allocator
- std::unordered_multimap::hash_function
- std::unordered_multimap::insert
- std::unordered_multimap::key_eq
- std::unordered_multimap::load_factor
- std::unordered_multimap::max_bucket_count
- std::unordered_multimap::max_load_factor
- std::unordered_multimap::max_size
- std::unordered_multimap::rehash
- std::unordered_multimap::size
- std::unordered_multimap::swap
ms.assetid: 4baead6c-5870-4b85-940f-a47d6b891c27
caps.latest.revision: "28"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 25a555048252039a2d888fe69d50b1a6ef422e4c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="unorderedmultimap-class"></a>Classe unordered_multimap
A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos do tipo `std::pair<const Key, Ty>`. A sequência é ordenada sem muita rigidez por uma função de hash, que particiona a sequência em um conjunto ordenado de subsequências chamado bucket. Dentro de cada bucket uma função de comparação determina se um par de elementos tem ordenação equivalente. Cada elemento armazena dois objetos, uma chave de classificação e um valor. A sequência é representada de forma a permitir pesquisa, inserção e remoção de um elemento com um número arbitrário de operações que podem ser independentes do número de elementos na sequência (tempo constante), pelo menos quando todos os buckets forem de comprimento aproximadamente igual. No pior caso, quando todos os elementos estiverem em um bucket, o número de operações será proporcional ao número de elementos na sequência (tempo linear). Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Key,  
    class Ty,  
    class Hash = std::hash<Key>,  
    class Pred = std::equal_to<Key>,  
    class Alloc = std::allocator<Key>>  
class unordered_multimap;  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Key`|O tipo principal.|  
|`Ty`|O tipo mapeado.|  
|`Hash`|O tipo de objeto da função de hash.|  
|`Pred`|O tipo de objeto da função de comparação de igualdade.|  
|`Alloc`|A classe do alocador.|  
  
## <a name="members"></a>Membros  
  
|||  
|-|-|  
|Definição do tipo|Descrição|  
|[allocator_type](#allocator_type)|O tipo de um distribuidor para gerenciar o armazenamento.|  
|[const_iterator](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|  
|[const_local_iterator](#const_local_iterator)|O tipo de um iterador de bucket de constante para a sequência controlada.|  
|[const_pointer](#const_pointer)|O tipo de um ponteiro de constante para um elemento.|  
|[const_reference](#const_reference)|O tipo de uma referência de constante para um elemento.|  
|[difference_type](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[hasher](#hasher)|O tipo de função de hash.|  
|[iterator](#iterator)|O tipo de um iterador para a sequência controlada.|  
|[key_equal](#key_equal)|O tipo da função de comparação.|  
|[key_type](#key_type)|O tipo de uma chave de classificação.|  
|[local_iterator](#local_iterator)|O tipo de um iterador de bucket para a sequência controlada.|  
|[mapped_type](#mapped_type)|O tipo de um valor mapeado associado a cada chave.|  
|[pointer](#pointer)|O tipo de um ponteiro para um elemento.|  
|[reference](#reference)|O tipo de uma referência para um elemento.|  
|[size_type](#size_type)|O tipo de uma distância sem sinal entre dois elementos.|  
|[value_type](#value_type)|O tipo de um elemento.|  
  
|||  
|-|-|  
|Função membro|Descrição|  
|[begin](#begin)|Designa o início da sequência controlada.|  
|[bucket](#bucket)|Obtém o número de buckets de um valor de chave.|  
|[bucket_count](#bucket_count)|Obtém o número de buckets.|  
|[bucket_size](#bucket_size)|Obtém o tamanho de um bucket.|  
|[cbegin](#cbegin)|Designa o início da sequência controlada.|  
|[cend](#cend)|Designa o fim da sequência controlada.|  
|[clear](#clear)|Remove todos os elementos.|  
|[count](#count)|Localiza o número de elementos que correspondem a uma chave especificada.|  
|[emplace](#emplace)|Adiciona um elemento construído no lugar.|  
|[emplace_hint](#emplace_hint)|Adiciona um elemento construído no lugar, com dica.|  
|[empty](#empty)|Testa se nenhum elemento está presente.|  
|[end](#end)|Designa o fim da sequência controlada.|  
|[equal_range](#equal_range)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[erase](#erase)|Remove os elementos em posições especificadas.|  
|[find](#find)|Localiza um elemento que corresponde a uma chave especificada.|  
|[get_allocator](#get_allocator)|Obtém o objeto de alocador armazenado.|  
|[hash_function](#hash)|Obtém o objeto armazenado da função de hash.|  
|[insert](#insert)|Adiciona elementos.|  
|[key_eq](#key_eq)|Obtém o objeto armazenado da função de comparação.|  
|[load_factor](#load_factor)|Conta a média de elementos por bucket.|  
|[max_bucket_count](#max_bucket_count)|Obtém o número máximo de buckets.|  
|[max_load_factor](#max_load_factor)|Obtém ou define o máximo de elementos por bucket.|  
|[max_size](#max_size)|Obtém o tamanho máximo da sequência controlada.|  
|[rehash](#rehash)|Recria a tabela de hash.|  
|[size](#size)|Conta o número de elementos.|  
|[swap](#swap)|Alterna o conteúdo de dois contêineres.|  
|[unordered_multimap](#unordered_multimap)|Constrói um objeto contêiner.|  
  
|||  
|-|-|  
|Operador|Descrição|  
|[unordered_multimap::operator=](#op_eq)|Copia uma tabela de hash.|  
  
## <a name="remarks"></a>Comentários  
 O objeto ordena a sequência que ele controla chamando dois objetos armazenados, um objeto de função de comparação do tipo [unordered_multimap::key_equal](#key_equal) e um objeto de função de hash do tipo [unordered_multimap::hasher](#hasher). Você acessa o primeiro objeto armazenado chamando a função membro [unordered_multimap::key_eq](#key_eq)`()`; e acessa o segundo objeto armazenado chamando a função membro [unordered_multimap::hash_function](#hash)`()`. Especificamente, para todos os valores `X` e `Y` do tipo `Key`, a chamada `key_eq()(X, Y)` retornará true somente se os dois valores de argumento tiverem ordem equivalente; a chamada `hash_function()(keyval)` resulta em uma distribuição de valores do tipo `size_t`. Diferentemente da classe de modelo [unordered_multimap Class](../standard-library/unordered-map-class.md), um objeto da classe de modelo `unordered_multimap` não garante que seja `key_eq()(X, Y)` sempre falsa para um dos dois elementos da sequência controlada. (As chaves não precisam ser exclusivas.)  
  
 O objeto também armazena um fator de carga máximo, que especifica o número máximo médio desejado de elementos por bucket. Se a inserção de um elemento fizer com que [unordered_multimap::load_factor](#load_factor)`()` exceda o fator de carga máximo, o contêiner aumentará o número de buckets e recriará a tabela de hash conforme a necessidade.  
  
 A ordem real de elementos na sequência controlada depende da função de hash, da função de comparação, da ordem de inserção, do fator máximo de carga e do número atual de buckets. Você não pode fazer uma previsão geral da ordem dos elementos na sequência controlada. No entanto, você sempre terá certeza de que qualquer subconjunto de elementos que tenha ordem equivalente será adjacente na sequência de controle.  
  
 O objeto aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado de alocador do tipo [unordered_multimap::allocator_type](#allocator_type). Esse objeto de alocador deve ter a mesma interface externa que um objeto da classe de modelo `allocator`. Observe que o objeto de alocador armazenado não é copiado quando o objeto de contêiner é atribuído.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<unordered_map >  
  
 **Namespace:** std  
  
##  <a name="allocator_type"></a>  unordered_multimap::allocator_type  
 O tipo de um distribuidor para gerenciar o armazenamento.  
  
```  
typedef Alloc allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Alloc`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_allocator_type.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
typedef std::allocator<std::pair<const char, int> > Myalloc;   
int main()   
    {   
    Mymap c1;   
  
    Mymap::allocator_type al = c1.get_allocator();   
    std::cout << "al == std::allocator() is "   
        << std::boolalpha << (al == Myalloc()) << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
al == std::allocator() is true  
```  
  
##  <a name="begin"></a>  unordered_multimap::begin  
 Designa o início da sequência controlada ou um bucket.  
  
```  
iterator begin();

const_iterator begin() const;

 
local_iterator begin(size_type nbucket);

const_local_iterator begin(size_type nbucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`nbucket`|O número de bucket.|  
  
### <a name="remarks"></a>Comentários  
 As duas primeiras funções membro retornam um iterador de encaminhamento que aponta para o primeiro elemento da sequência (ou imediatamente após o fim de uma sequência vazia). As duas últimas funções membro retornam um iterador de encaminhamento que aponta para o primeiro elemento do bucket `nbucket` (ou imediatamente após o fim de um bucket vazio).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_begin.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect first two items " [c 3] [b 2]"   
    Mymap::iterator it2 = c1.begin();   
    std::cout << " [" << it2->first << ", " << it2->second << "]";   
    ++it2;   
    std::cout << " [" << it2->first << ", " << it2->second << "]";   
    std::cout << std::endl;   
  
// inspect bucket containing 'a'   
    Mymap::const_local_iterator lit = c1.begin(c1.bucket('a'));   
    std::cout << " [" << lit->first << ", " << lit->second << "]";   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
[c, 3] [b, 2]  
[a, 1]  
```  
  
##  <a name="bucket"></a>  unordered_multimap::bucket  
 Obtém o número de buckets de um valor de chave.  
  
```  
size_type bucket(const Key& keyval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `keyval`  
 O valor de chave a ser mapeado.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número de bucket atualmente correspondente ao valor da chave `keyval`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_bucket.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// display buckets for keys   
    Mymap::size_type bs = c1.bucket('a');   
    std::cout << "bucket('a') == " << bs << std::endl;   
    std::cout << "bucket_size(" << bs << ") == " << c1.bucket_size(bs)   
        << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
bucket('a') == 7  
bucket_size(7) == 1  
```  
  
##  <a name="bucket_count"></a>  unordered_multimap::bucket_count  
 Obtém o número de buckets.  
  
```  
size_type bucket_count() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número atual de buckets.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_bucket_count.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect current parameters   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.10f);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// rehash and redisplay   
    c1.rehash(100);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_bucket_count() == 128  
max_load_factor() == 0.1  
  
```  
  
##  <a name="bucket_size"></a>  unordered_multimap::bucket_size  
 Obtém o tamanho de um bucket  
  
```  
size_type bucket_size(size_type nbucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `nbucket`  
 O número de bucket.  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam o tamanho do número de bucket `nbucket`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_bucket_size.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// display buckets for keys   
    Mymap::size_type bs = c1.bucket('a');   
    std::cout << "bucket('a') == " << bs << std::endl;   
    std::cout << "bucket_size(" << bs << ") == " << c1.bucket_size(bs)   
        << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
bucket('a') == 7  
bucket_size(7) == 1  
```  
  
##  <a name="cbegin"></a>  unordered_multimap::cbegin  
 Retorna um iterador `const` que trata o primeiro elemento no intervalo.  
  
```  
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso por avanço `const` que aponta o primeiro elemento do intervalo ou o local logo após o fim de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.  
  
 Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` como um contêiner modificável (não `const`) de qualquer tipo, que dá suporte para `begin()` e `cbegin()`.  
  
```cpp  
auto i1 = Container.begin();
// i1 is Container<T>::iterator   
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator  
```  
  
##  <a name="cend"></a>  unordered_multimap::cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso por avanço `const` que aponta para além do fim do intervalo.  
  
### <a name="remarks"></a>Comentários  
 `cend` é usado para testar se um iterador passou do fim de seu intervalo.  
  
 Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` como um contêiner modificável (não `const`) de qualquer tipo, que dá suporte para `end()` e `cend()`.  
  
```cpp  
auto i1 = Container.end();
// i1 is Container<T>::iterator   
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator  
```  
  
 O valor retornado por `cend` não deve ser desreferenciado.  
  
##  <a name="clear"></a>  unordered_multimap::clear  
 Remove todos os elementos.  
  
```  
void clear();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de função membro [unordered_multimap::erase](#erase)`(` [unordered_multimap::begin](#begin)`(),` [unordered_multimap::end](#end)`())`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_clear.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// clear the container and reinspect   
    c1.clear();   
    std::cout << "size == " << c1.size() << std::endl;   
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;   
    std::cout << std::endl;   
  
    c1.insert(Mymap::value_type('d', 4));   
    c1.insert(Mymap::value_type('e', 5));   
  
// display contents " [e 5] [d 4]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    std::cout << "size == " << c1.size() << std::endl;   
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
size == 0  
empty() == true  
  
 [e, 5] [d, 4]  
size == 2  
empty() == false  
```  
  
##  <a name="const_iterator"></a>  unordered_multimap::const_iterator  
 O tipo de um iterador de constante para a sequência controlada.  
  
```  
typedef T1 const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de encaminhamento constante para a sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T1`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_const_iterator.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="const_local_iterator"></a>  unordered_multimap::const_local_iterator  
 O tipo de um iterador de bucket de constante para a sequência controlada.  
  
```  
typedef T5 const_local_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de encaminhamento constante para um bucket. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T5`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_const_local_iterator.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect bucket containing 'a'   
    Mymap::const_local_iterator lit = c1.begin(c1.bucket('a'));   
    std::cout << " [" << lit->first << ", " << lit->second << "]";   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
[a, 1]  
```  
  
##  <a name="const_pointer"></a>  unordered_multimap::const_pointer  
 O tipo de um ponteiro de constante para um elemento.  
  
```  
typedef Alloc::const_pointer const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um ponteiro constante para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_const_pointer.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::iterator it = c1.begin();   
        it != c1.end(); ++it)   
        {   
        Mymap::const_pointer p = &*it;   
        std::cout << " [" << p->first << ", " << p->second << "]";   
        }   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="const_reference"></a>  unordered_multimap::const_reference  
 O tipo de uma referência de constante para um elemento.  
  
```  
typedef Alloc::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como uma referência constante para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_const_reference.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::iterator it = c1.begin();   
        it != c1.end(); ++it)   
        {   
        Mymap::const_reference ref = *it;   
        std::cout << " [" << ref.first << ", " << ref.second << "]";   
        }   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="count"></a>  unordered_multimap::count  
 Localiza o número de elementos que correspondem a uma chave especificada.  
  
```  
size_type count(const Key& keyval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `keyval`  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número de elementos no intervalo delimitado por [unordered_multimap::equal_range](#equal_range)`(keyval)`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_count.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    std::cout << "count('A') == " << c1.count('A') << std::endl;   
    std::cout << "count('b') == " << c1.count('b') << std::endl;   
    std::cout << "count('C') == " << c1.count('C') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
count('A') == 0  
count('b') == 1  
count('C') == 0  
```  
  
##  <a name="difference_type"></a>  unordered_multimap::difference_type  
 O tipo de uma distância com sinal entre dois elementos.  
  
```  
typedef T3 difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo inteiro com sinal descreve um objeto que pode representar a diferença entre os endereços de dois elementos quaisquer na sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T3`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_difference_type.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// compute positive difference   
    Mymap::difference_type diff = 0;   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        ++diff;   
    std::cout << "end()-begin() == " << diff << std::endl;   
  
// compute negative difference   
    diff = 0;   
    for (Mymap::const_iterator it = c1.end();   
        it != c1.begin(); --it)   
        --diff;   
    std::cout << "begin()-end() == " << diff << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
end()-begin() == 3  
begin()-end() == -3  
```  
  
##  <a name="emplace"></a>  unordered_multimap::emplace  
 Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada), com uma dica de posicionamento.  
  
```  
template <class... Args>  
iterator emplace(Args&&... args);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`args`|Os argumentos encaminhados para criar um elemento a ser inserido no unordered_multimap.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o elemento recém-inserido.  
  
### <a name="remarks"></a>Comentários  
 Nenhuma referência a elementos de contêiner é invalidada por essa função, mas ela pode invalidar todos os iteradores no contêiner.  
  
 O [value_type](../standard-library/map-class.md#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.  
  
 Durante a inserção, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o contêiner não será modificado. Se a exceção for lançada na função hash, o resultado é indefinido.  
  
 Para obter um exemplo de código, consulte [multimap::emplace](../standard-library/multimap-class.md#emplace).  
  
##  <a name="emplace_hint"></a>  unordered_multimap::emplace_hint  
 Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada), com uma dica de posicionamento.  
  
```  
template <class... Args>  
iterator emplace_hint(
    const_iterator where,  
    Args&&... args);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`args`|Os argumentos encaminhados para criar um elemento a ser inserido no unordered.|  
|`where`|Uma dica relacionada ao local do qual se começa a procurar pelo ponto de inserção correto.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o elemento recém-inserido.  
  
### <a name="remarks"></a>Comentários  
 Nenhuma referência a elementos de contêiner é invalidada por essa função, mas ela pode invalidar todos os iteradores no contêiner.  
  
 Durante a inserção, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o contêiner não será modificado. Se a exceção for lançada na função hash, o resultado é indefinido.  
  
 O [value_type](../standard-library/map-class.md#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.  
  
 Para obter um exemplo de código, consulte [map::emplace_hint](../standard-library/map-class.md#emplace_hint).  
  
##  <a name="empty"></a>  unordered_multimap::empty  
 Testa se nenhum elemento está presente.  
  
```  
bool empty() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna verdadeiro para uma sequência controlada vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_empty.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// clear the container and reinspect   
    c1.clear();   
    std::cout << "size == " << c1.size() << std::endl;   
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;   
    std::cout << std::endl;   
  
    c1.insert(Mymap::value_type('d', 4));   
    c1.insert(Mymap::value_type('e', 5));   
  
// display contents " [e 5] [d 4]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    std::cout << "size == " << c1.size() << std::endl;   
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
size == 0  
empty() == true  
  
 [e, 5] [d, 4]  
size == 2  
empty() == false  
```  
  
##  <a name="end"></a>  unordered_multimap::end  
 Designa o fim da sequência controlada.  
  
```  
iterator end();

const_iterator end() const;

 
local_iterator end(size_type nbucket);

const_local_iterator end(size_type nbucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`nbucket`|O número de bucket.|  
  
### <a name="remarks"></a>Comentários  
 As duas primeiras funções membro retornam um iterador de encaminhamento que aponta para logo além do fim da sequência. As duas últimas funções membro retornam um iterador de encaminhamento que aponta para logo além do fim do bucket `nbucket`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_end.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect last two items " [a 1] [b 2]"   
    Mymap::iterator it2 = c1.end();   
    --it2;   
    std::cout << " [" << it2->first << ", " << it2->second << "]";   
    --it2;   
    std::cout << " [" << it2->first << ", " << it2->second << "]";   
    std::cout << std::endl;   
  
// inspect bucket containing 'a'   
    Mymap::const_local_iterator lit = c1.end(c1.bucket('a'));   
    --lit;   
    std::cout << " [" << lit->first << ", " << lit->second << "]";   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
[a, 1] [b, 2]  
[a, 1]  
```  
  
##  <a name="equal_range"></a>  unordered_multimap::equal_range  
 Localiza o intervalo que corresponde a uma chave especificada.  
  
```  
std::pair<iterator, iterator>  
    equal_range(const Key& keyval);

std::pair<const_iterator, const_iterator>  
    equal_range(const Key& keyval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `keyval`  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um par de iteradores `X` que `[X.first, X.second)` delimitam apenas os elementos da sequência controlada que tenha ordem equivalente com `keyval`. Se esses elementos não existirem, ambos os iteradores serão `end()`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_equal_range.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// display results of failed search   
    std::pair<Mymap::iterator, Mymap::iterator> pair1 =   
        c1.equal_range('x');   
    std::cout << "equal_range('x'):";   
    for (; pair1.first != pair1.second; ++pair1.first)   
        std::cout << " [" << pair1.first->first   
            << ", " << pair1.first->second << "]";   
    std::cout << std::endl;   
  
// display results of successful search   
    pair1 = c1.equal_range('b');   
    std::cout << "equal_range('b'):";   
    for (; pair1.first != pair1.second; ++pair1.first)   
        std::cout << " [" << pair1.first->first   
            << ", " << pair1.first->second << "]";   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
equal_range('x'):  
equal_range('b'): [b, 2]  
```  
  
##  <a name="erase"></a>  unordered_multimap::erase  
 Remove um elemento ou um intervalo de elementos em um unordered_multimap das posições especificadas ou remove elementos que correspondem a uma chave especificada.  
  
```  
iterator erase(
    const_iterator Where);

iterator erase(
    const_iterator First,  
    const_iterator Last);

size_type erase(
    const key_type& Key);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Where`  
 A posição do elemento a ser removido.  
  
 `First`  
 A posição do primeiro elemento a ser removido.  
  
 `Last`  
 A posição logo após o último elemento a ser removido.  
  
 `Key`  
 O valor de chave dos elementos a serem removidos.  
  
### <a name="return-value"></a>Valor de retorno  
 Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de quaisquer elementos removidos ou um elemento que será o final do mapa, se esse elemento não existir.  
  
 Para a terceira função membro, ele retorna o número de elementos que foram removidos do unordered_multimap.  
  
### <a name="remarks"></a>Comentários  
 Para obter um exemplo de código, consulte [map::erase](../standard-library/map-class.md#erase).  
  
##  <a name="find"></a>  unordered_multimap::find  
 Localiza um elemento que corresponde a uma chave especificada.  
  
```  
const_iterator find(const Key& keyval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `keyval`  
 O valor chave a ser pesquisado.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [unordered_multimap::equal_range](#equal_range)`(keyval).first`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_find.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// try to find and fail   
    std::cout << "find('A') == "   
        << std::boolalpha << (c1.find('A') != c1.end()) << std::endl;   
  
// try to find and succeed   
    Mymap::iterator it = c1.find('b');   
    std::cout << "find('b') == "   
        << std::boolalpha << (it != c1.end())   
        << ": [" << it->first << ", " << it->second << "]" << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
find('A') == false  
find('b') == true: [b, 2]  
```  
  
##  <a name="get_allocator"></a>  unordered_multimap::get_allocator  
 Obtém o objeto de alocador armazenado.  
  
```  
Alloc get_allocator() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o objeto alocador armazenado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_get_allocator.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
typedef std::allocator<std::pair<const char, int> > Myalloc;   
int main()   
    {   
    Mymap c1;   
  
    Mymap::allocator_type al = c1.get_allocator();   
    std::cout << "al == std::allocator() is "   
        << std::boolalpha << (al == Myalloc()) << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
al == std::allocator() is true  
```  
  
##  <a name="hash"></a>  unordered_multimap::hash_function  
 Obtém o objeto armazenado da função de hash.  
  
```  
Hash hash_function() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o objeto da função hash armazenado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_hash_function.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    Mymap::hasher hfn = c1.hash_function();   
    std::cout << "hfn('a') == " << hfn('a') << std::endl;   
    std::cout << "hfn('b') == " << hfn('b') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
hfn('a') == 1630279  
hfn('b') == 1647086  
```  
  
##  <a name="hasher"></a>  unordered_multimap::hasher  
 O tipo de função de hash.  
  
```  
typedef Hash hasher;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Hash`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_hasher.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    Mymap::hasher hfn = c1.hash_function();   
    std::cout << "hfn('a') == " << hfn('a') << std::endl;   
    std::cout << "hfn('b') == " << hfn('b') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
hfn('a') == 1630279  
hfn('b') == 1647086  
```  
  
##  <a name="insert"></a>  unordered_multimap::insert  
 Insere um elemento ou um intervalo de elementos em um unordered_multimap.  
  
```  
// (1) single element  
pair<iterator, bool> insert(
    const value_type& Val);

 
// (2) single element, perfect forwarded  
template <class ValTy>  
pair<iterator, bool>  
insert(
    ValTy&& Val);

 
// (3) single element with hint  
iterator insert(
    const_iterator Where,  
    const value_type& Val);

 
// (4) single element, perfect forwarded, with hint  
template <class ValTy>  
iterator insert(
    const_iterator Where,  
    ValTy&& Val);

 
// (5) range   
template <class InputIterator>   
void insert(
    InputIterator First,  
    InputIterator Last);

 
// (6) initializer list  
void insert(
    initializer_list<value_type>  
IList);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Val`|O valor de um elemento a ser inserido em unordered_multimap.|  
|`Where`|O local a partir do qual se começa a procurar pelo ponto de inserção correto.|  
|`ValTy`|O parâmetro de modelo que especifica o tipo de argumento que unordered_multimap pode usar para construir um elemento de [value_type](../standard-library/map-class.md#value_type) e aperfeiçoar/encaminhar `Val` como argumento.|  
|`First`|A posição do primeiro elemento a ser copiado.|  
|`Last`|A posição imediatamente após o último elemento a ser copiado.|  
|`InputIterator`|Argumento da função de modelo que atende aos requisitos de um [iterador de entrada](../standard-library/input-iterator-tag-struct.md) que aponta para elementos de um tipo que pode ser usado para construir objetos [value_type](../standard-library/map-class.md#value_type).|  
|`IList`|O [initializer_list](../standard-library/initializer-list.md) do qual os elementos serão copiados.|  
  
### <a name="return-value"></a>Valor de retorno  
 As funções do membro de inserir elemento único, (1) e (2), retornam um iterador para a posição em que o novo elemento foi inserido no unordered_multimap.  
  
 As funções do membro de inserir elemento único, (3) e (4), retornam um iterador para a posição em que o novo elemento foi inserido no unordered_multimap.  
  
### <a name="remarks"></a>Comentários  
 Nenhum ponteiro ou referência é invalidado por esta função, mas ela pode invalidar todos os iteradores para o contêiner.  
  
 Durante a inserção de apenas um elemento, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o estado do contêiner não é modificado. Se a exceção for lançada na função hash, o resultado é indefinido. Durante a inserção de vários elementos, se uma exceção for lançada, o contêiner será deixado em um estado não especificado, mas válido.  
  
 O [value_type](../standard-library/map-class.md#value_type) de um contêiner é um typedef que pertence ao contêiner e para o mapa, `map<K, V>::value_type` é `pair<const K, V>`. O valor de um elemento é um par ordenado no qual o primeiro componente é igual ao valor chave e o segundo componente é igual ao valor dos dados do elemento.  
  
 A função do membro de intervalo (5) insere a sequência de valores de elemento em um unordered_multimap que corresponde a cada elemento tratado por um iterador no intervalo`[First, Last)`; portanto, `Last` não é inserido. A função de membro do contêiner `end()` refere-se à posição logo após o último elemento no contêiner, por exemplo, a instrução `m.insert(v.begin(), v.end());` insere todos os elementos de `v` em `m`.  
  
 A função membro da lista do inicializador (6) usa um [initializer_list](../standard-library/initializer-list.md) para copiar elementos no unordered_multimap.  
  
 Para inserir um elemento criado no local, ou seja, sem a realização de operações de cópia ou movimentação, consulte [unordered_multimap::emplace](#emplace) and [unordered_multimap::emplace_hint](#emplace_hint).  
  
 Para obter um exemplo de código, consulte [multimap::insert](../standard-library/multiset-class.md#insert).  
  
##  <a name="iterator"></a>  unordered_multimap::iterator  
 O tipo de um iterador para a sequência controlada.  
  
```  
typedef T0 iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de encaminhamento para a sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T0`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_iterator.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="key_eq"></a>  unordered_multimap::key_eq  
 Obtém o objeto armazenado da função de comparação.  
  
```  
Pred key_eq() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o objeto da função de comparação armazenado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_key_eq.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    Mymap::key_equal cmpfn = c1.key_eq();   
    std::cout << "cmpfn('a', 'a') == "   
        << std::boolalpha << cmpfn('a', 'a') << std::endl;   
    std::cout << "cmpfn('a', 'b') == "   
        << std::boolalpha << cmpfn('a', 'b') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
cmpfn('a', 'a') == true  
cmpfn('a', 'b') == false  
```  
  
##  <a name="key_equal"></a>  unordered_multimap::key_equal  
 O tipo da função de comparação.  
  
```  
typedef Pred key_equal;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Pred`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_key_equal.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    Mymap::key_equal cmpfn = c1.key_eq();   
    std::cout << "cmpfn('a', 'a') == "   
        << std::boolalpha << cmpfn('a', 'a') << std::endl;   
    std::cout << "cmpfn('a', 'b') == "   
        << std::boolalpha << cmpfn('a', 'b') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
cmpfn('a', 'a') == true  
cmpfn('a', 'b') == false  
```  
  
##  <a name="key_type"></a>  unordered_multimap::key_type  
 O tipo de uma chave de classificação.  
  
```  
typedef Key key_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Key`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_key_type.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// add a value and reinspect   
    Mymap::key_type key = 'd';   
    Mymap::mapped_type mapped = 4;   
    Mymap::value_type val = Mymap::value_type(key, mapped);   
    c1.insert(val);   
  
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
[d, 4] [c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="load_factor"></a>  unordered_multimap::load_factor  
 Conta a média de elementos por bucket.  
  
```  
float load_factor() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna `(float)`[unordered_multimap::size](#size)`() / (float)`[unordered_multimap::bucket_count](#bucket_count)`()`, o número médio de elementos por bucket.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_load_factor.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect current parameters   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.10f);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// rehash and redisplay   
    c1.rehash(100);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
##  <a name="local_iterator"></a>  unordered_multimap::local_iterator  
 O tipo de um iterador de bucket.  
  
```  
typedef T4 local_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de encaminhamento para um bucket. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T4`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_local_iterator.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect bucket containing 'a'   
    Mymap::local_iterator lit = c1.begin(c1.bucket('a'));   
    std::cout << " [" << lit->first << ", " << lit->second << "]";   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
[a, 1]  
```  
  
##  <a name="mapped_type"></a>  unordered_multimap::mapped_type  
 O tipo de um valor mapeado associado a cada chave.  
  
```  
typedef Ty mapped_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Ty`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_mapped_type.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// add a value and reinspect   
    Mymap::key_type key = 'd';   
    Mymap::mapped_type mapped = 4;   
    Mymap::value_type val = Mymap::value_type(key, mapped);   
    c1.insert(val);   
  
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
[d, 4] [c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="max_bucket_count"></a>  unordered_multimap::max_bucket_count  
 Obtém o número máximo de buckets.  
  
```  
size_type max_bucket_count() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o número máximo de buckets permitidos no momento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_max_bucket_count.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect current parameters   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.10f);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// rehash and redisplay   
    c1.rehash(100);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_bucket_count() == 128  
max_load_factor() == 0.1  
  
```  
  
##  <a name="max_load_factor"></a>  unordered_multimap::max_load_factor  
 Obtém ou define o máximo de elementos por bucket.  
  
```  
float max_load_factor() const;

 
void max_load_factor(float factor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `factor`  
 O novo fator de carga máxima.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro retorna o fator de carga máxima armazenado. A segunda função membro substitui o fator de carga máxima armazenado com `factor`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_max_load_factor.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect current parameters   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.10f);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// rehash and redisplay   
    c1.rehash(100);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_bucket_count() == "   
        << c1.max_bucket_count() << std::endl;   
    std::cout << "max_load_factor() == "   
        << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_bucket_count() == 8  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_bucket_count() == 128  
max_load_factor() == 0.1  
  
```  
  
##  <a name="max_size"></a>  unordered_multimap::max_size  
 Obtém o tamanho máximo da sequência controlada.  
  
```  
size_type max_size() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência mais longa que o objeto pode controlar.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_max_size.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    std::cout << "max_size() == " << c1.max_size() << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
max_size() == 536870911  
```  
  
##  <a name="op_eq"></a>  unordered_multimap::operator=  
 Copia uma tabela de hash.  
  
```  
unordered_multimap& operator=(const unordered_multimap& right);

unordered_multimap& operator=(unordered_multimap&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`right`|Unordered_multimap que está sendo copiado no unordered_multimap.|  
  
### <a name="remarks"></a>Comentários  
 Depois de apagar os elementos existentes em um unordered_multimap `operator=` copiar ou mover o conteúdo de `right` no unordered_multimap.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// unordered_multimap_operator_as.cpp  
// compile with: /EHsc  
#include <unordered_multimap>  
#include <iostream>  
  
int main( )  
   {  
   using namespace std;  
   unordered_multimap<int, int> v1, v2, v3;  
   unordered_multimap<int, int>::iterator iter;  
  
   v1.insert(pair<int, int>(1, 10));  
  
   cout << "v1 = " ;  
   for (iter = v1.begin(); iter != v1.end(); iter++)  
      cout << iter->second << " ";  
   cout << endl;  
  
   v2 = v1;  
   cout << "v2 = ";  
   for (iter = v2.begin(); iter != v2.end(); iter++)  
      cout << iter->second << " ";  
   cout << endl;  
  
// move v1 into v2  
   v2.clear();  
   v2 = move(v1);  
   cout << "v2 = ";  
   for (iter = v2.begin(); iter != v2.end(); iter++)  
      cout << iter->second << " ";  
   cout << endl;  
   }  
```  
  
##  <a name="pointer"></a>  unordered_multimap::pointer  
 O tipo de um ponteiro para um elemento.  
  
```  
typedef Alloc::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um ponteiro para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_pointer.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::iterator it = c1.begin();   
        it != c1.end(); ++it)   
        {   
        Mymap::pointer p = &*it;   
        std::cout << " [" << p->first << ", " << p->second << "]";   
        }   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="reference"></a>  unordered_multimap::reference  
 O tipo de uma referência para um elemento.  
  
```  
typedef Alloc::reference reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como uma referência para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_reference.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::iterator it = c1.begin();   
        it != c1.end(); ++it)   
        {   
        Mymap::reference ref = *it;   
        std::cout << " [" << ref.first << ", " << ref.second << "]";   
        }   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="rehash"></a>  unordered_multimap::rehash  
 Recria a tabela de hash.  
  
```  
void rehash(size_type nbuckets);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nbuckets`  
 O número solicitado de buckets.  
  
### <a name="remarks"></a>Comentários  
 A função membro altera o número de buckets para que seja pelo menos `nbuckets` e recria a tabela de hash, conforme necessário.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_rehash.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// inspect current parameters   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_load_factor() == " << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// change max_load_factor and redisplay   
    c1.max_load_factor(0.10f);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_load_factor() == " << c1.max_load_factor() << std::endl;   
    std::cout << std::endl;   
  
// rehash and redisplay   
    c1.rehash(100);   
    std::cout << "bucket_count() == " << c1.bucket_count() << std::endl;   
    std::cout << "load_factor() == " << c1.load_factor() << std::endl;   
    std::cout << "max_load_factor() == " << c1.max_load_factor() << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
bucket_count() == 8  
load_factor() == 0.375  
max_load_factor() == 4  
  
bucket_count() == 8  
load_factor() == 0.375  
max_load_factor() == 0.1  
  
bucket_count() == 128  
load_factor() == 0.0234375  
max_load_factor() == 0.1  
```  
  
##  <a name="size"></a>  unordered_multimap::size  
 Conta o número de elementos.  
  
```  
size_type size() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o comprimento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_size.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// clear the container and reinspect   
    c1.clear();   
    std::cout << "size == " << c1.size() << std::endl;   
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;   
    std::cout << std::endl;   
  
    c1.insert(Mymap::value_type('d', 4));   
    c1.insert(Mymap::value_type('e', 5));   
  
// display contents " [e 5] [d 4]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    std::cout << "size == " << c1.size() << std::endl;   
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
 [c, 3] [b, 2] [a, 1]  
size == 0  
empty() == true  
  
 [e, 5] [d, 4]  
size == 2  
empty() == false  
```  
  
##  <a name="size_type"></a>  unordered_multimap::size_type  
 O tipo de uma distância sem sinal entre dois elementos.  
  
```  
typedef T2 size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo inteiro sem sinal descreve um objeto que pode representar o tamanho de qualquer sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T2`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_size_type.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
    Mymap::size_type sz = c1.size();   
  
    std::cout << "size == " << sz << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
size == 0  
```  
  
##  <a name="swap"></a>  unordered_multimap::swap  
 Alterna o conteúdo de dois contêineres.  
  
```  
void swap(unordered_multimap& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O contêiner para alternância.  
  
### <a name="remarks"></a>Comentários  
 A função membro troca as sequências controladas entre `*this` e `right`. Se [unordered_multimap::get_allocator](#get_allocator)`() == right.get_allocator()`, ele faz isso em tempo constante, ele gerará uma exceção apenas como resultado de copiar o objeto armazenado do tipo `Tr` e invalida sem referências, ponteiros ou iteradores que designam elementos em duas sequências de controlado. Caso contrário, executará uma série de atribuições de elemento e de chamadas do construtor proporcional ao número de elementos nas duas sequências controladas.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_swap.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    Mymap c2;   
  
    c2.insert(Mymap::value_type('d', 4));   
    c2.insert(Mymap::value_type('e', 5));   
    c2.insert(Mymap::value_type('f', 6));   
  
    c1.swap(c2);   
  
// display contents " [f 6] [e 5] [d 4]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    swap(c1, c2);   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
[f, 6] [e, 5] [d, 4]  
[c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="unordered_multimap"></a>  unordered_multimap::unordered_multimap  
 Constrói um objeto contêiner.  
  
```  
unordered_multimap(
    const unordered_multimap& Right);

explicit unordered_multimap(
    size_type Bucket_count = N0,  
    const Hash& Hash = Hash(),  
    const Comp& Comp = Pred(),  
    const Allocator& Al = Alloc());

unordered_multimap(
    unordered_multimap&& Right);

unordered_multimap(
    initializer_list<Type> IList);

unordered_multimap(
    initializer_list<Type> IList,  
    size_type Bucket_count);

unordered_multimap(
    initializer_list<Type> IList,  
    size_type Bucket_count,   
    const Hash& Hash);

unordered_multimap(
    initializer_list<Type> IList,  
    size_type Bucket_count,   
    const Hash& Hash,  
    const Key& Key);

unordered_multimap(
    initializer_list<Type> IList,  
    size_type Bucket_count,   
    const Hash& Hash,  
    const Key& Key,   
    const Allocator& Al);

template <class InputIterator>  
unordered_multimap(
 InputIterator first, InputIterator last,  
    size_type Bucket_count = N0,  
    const Hash& Hash = Hash(),  
    const Comp& Comp = Pred(),  
    const Allocator& Al = Alloc());
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`InputIterator`|O tipo de iterador.|  
|`Al`|O objeto de alocador a ser armazenado.|  
|`Comp`|O objeto de função de comparação a ser armazenado.|  
|`Hash`|O objeto de função de hash a ser armazenado.|  
|`Bucket_count`|O número mínimo de buckets.|  
|`Right`|O contêiner a ser copiado.|  
|`IList`|O initializer_list do qual copiar os elementos.|  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor especifica uma cópia da sequência controlada por `Right`. O segundo construtor especifica uma sequência controlada vazia. O terceiro construtor. especifica uma cópia da sequência movendo `Right`. O quarto, quinto, sexto, sétimo e oitavo construtores usam um initializer_list para os membros. O nono construtor insere a sequência dos valores `[First, Last)` do elemento.  
  
 Todos os construtores também inicializam vários valores armazenados. Para o construtor de cópia, os valores são obtidos de `Right`. Caso contrário:  
  
 O número mínimo de buckets é o argumento `Bucket_count`, se estiver presente; caso contrário, será um valor padrão descrito aqui como o valor `N0` definido pela implementação.  
  
 O objeto de função de hash é o argumento `Hash`, se estiver presente; caso contrário, será `Hash()`.  
  
 O objeto de função de comparação é o argumento `Comp`, se estiver presente; caso contrário, será `Pred()`.  
  
 O objeto de alocador é o argumento `Al`, se estiver presente; caso contrário, será `Alloc()`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_construct.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
using namespace std;  
  
using  Mymap = unordered_multimap<char, int> ;  
int main()  
{  
    Mymap c1;  
  
    c1.insert(Mymap::value_type('a', 1));  
    c1.insert(Mymap::value_type('b', 2));  
    c1.insert(Mymap::value_type('c', 3));  
  
    // display contents " [c 3] [b 2] [a 1]"   
    for (const auto& c : c1) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
  
    Mymap c2(8,  
        hash<char>(),  
        equal_to<char>(),  
        allocator<pair<const char, int> >());  
  
    c2.insert(Mymap::value_type('d', 4));  
    c2.insert(Mymap::value_type('e', 5));  
    c2.insert(Mymap::value_type('f', 6));  
  
    // display contents " [f 6] [e 5] [d 4]"   
    for (const auto& c : c2) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
  
    Mymap c3(c1.begin(),  
        c1.end(),  
        8,  
        hash<char>(),  
        equal_to<char>(),  
        allocator<pair<const char, int> >());  
  
    // display contents " [c 3] [b 2] [a 1]"   
    for (const auto& c : c3) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
  
    Mymap c4(move(c3));  
  
    // display contents " [c 3] [b 2] [a 1]"   
    for (const auto& c : c4) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
  
    // Construct with an initializer_list  
    unordered_multimap<int, char> c5({ { 5, 'g' }, { 6, 'h' }, { 7, 'i' }, { 8, 'j' } });  
    for (const auto& c : c5) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
  
    // Initializer_list plus size  
    unordered_multimap<int, char> c6({ { 5, 'g' }, { 6, 'h' }, { 7, 'i' }, { 8, 'j' } }, 4);  
    for (const auto& c : c1) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
  
    // Initializer_list plus size and hash  
    unordered_multimap<int, char, hash<char>> c7(  
        { { 5, 'g' }, { 6, 'h' }, { 7, 'i' }, { 8, 'j' } },  
        4,  
        hash<char>()  
    );  
  
    for (const auto& c : c1) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
  
    // Initializer_list plus size, hash, and key_equal  
    unordered_multimap<int, char, hash<char>, equal_to<char>> c8(  
        { { 5, 'g' }, { 6, 'h' }, { 7, 'i' }, { 8, 'j' } },  
        4,  
        hash<char>(),  
        equal_to<char>()  
    );  
  
    for (const auto& c : c1) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
  
    // Initializer_list plus size, hash, key_equal, and allocator  
    unordered_multimap<int, char, hash<char>, equal_to<char>> c9(  
        { { 5, 'g' }, { 6, 'h' }, { 7, 'i' }, { 8, 'j' } },  
        4,  
        hash<char>(),  
        equal_to<char>(),  
        allocator<pair<const char, int> >()  
    );  
  
    for (const auto& c : c1) {  
        cout << " [" << c.first << ", " << c.second << "]";  
    }  
    cout << endl;  
}  
  
```  
  
```Output  
[a, 1] [b, 2] [c, 3] [d, 4] [e, 5] [f, 6] [a, 1] [b, 2] [c, 3] [a, 1] [b, 2] [c, 3] [5, g] [6, h] [7, i] [8, j] [a, 1] [b, 2] [c, 3] [a, 1] [b, 2] [c, 3] [a, 1] [b, 2] [c, 3] [a, 1] [b, 2] [c, 3] [c, 3] [b, 2] [a, 1]  
 [f, 6] [e, 5] [d, 4]  
 [c, 3] [b, 2] [a, 1]  
 [c, 3] [b, 2] [a, 1]  
```  
  
##  <a name="value_type"></a>  unordered_multimap::value_type  
 O tipo de um elemento.  
  
```  
typedef std::pair<const Key, Ty> value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__unordered_map__unordered_multimap_value_type.cpp   
// compile with: /EHsc   
#include <unordered_map>   
#include <iostream>   
  
typedef std::unordered_multimap<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// display contents " [c 3] [b 2] [a 1]"   
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
// add a value and reinspect   
    Mymap::key_type key = 'd';   
    Mymap::mapped_type mapped = 4;   
    Mymap::value_type val = Mymap::value_type(key, mapped);   
    c1.insert(val);   
  
    for (Mymap::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " [" << it->first << ", " << it->second << "]";   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
[c, 3] [b, 2] [a, 1]  
[d, 4] [c, 3] [b, 2] [a, 1]  
```  
  
## <a name="see-also"></a>Consulte também  
 [<unordered_map>](../standard-library/unordered-map.md)   
 [Contêineres](../cpp/containers-modern-cpp.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)

