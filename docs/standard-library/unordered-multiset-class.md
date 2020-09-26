---
title: Classe unordered_multiset
description: Referência de API para a classe de contêiner da biblioteca padrão C++ `unordered_multiset` , que descreve um objeto usado para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos não precisam ser exclusivos e nos quais eles servem como valores de chave. Os dados não são ordenados automaticamente.
ms.date: 9/10/2020
f1_keywords:
- unordered_set/std::unordered_multiset
- unordered_set/std::unordered_multiset::allocator_type
- unordered_set/std::unordered_multiset::const_iterator
- unordered_set/std::unordered_multiset::const_local_iterator
- unordered_set/std::unordered_multiset::const_pointer
- unordered_set/std::unordered_multiset::const_reference
- unordered_set/std::unordered_multiset::difference_type
- unordered_set/std::unordered_multiset::hasher
- unordered_set/std::unordered_multiset::iterator
- unordered_set/std::unordered_multiset::key_equal
- unordered_set/std::unordered_multiset::key_type
- unordered_set/std::unordered_multiset::local_iterator
- unordered_set/std::unordered_multiset::pointer
- unordered_set/std::unordered_multiset::reference
- unordered_set/std::unordered_multiset::size_type
- unordered_set/std::unordered_multiset::value_type
- unordered_set/std::unordered_multiset::begin
- unordered_set/std::unordered_multiset::bucket
- unordered_set/std::unordered_multiset::bucket_count
- unordered_set/std::unordered_multiset::bucket_size
- unordered_set/std::unordered_multiset::cbegin
- unordered_set/std::unordered_multiset::cend
- unordered_set/std::unordered_multiset::clear
- unordered_set/std::unordered_multiset::contains
- unordered_set/std::unordered_multiset::count
- unordered_set/std::unordered_multiset::emplace
- unordered_set/std::unordered_multiset::emplace_hint
- unordered_set/std::unordered_multiset::empty
- unordered_set/std::unordered_multiset::end
- unordered_set/std::unordered_multiset::equal_range
- unordered_set/std::unordered_multiset::erase
- unordered_set/std::unordered_multiset::find
- unordered_set/std::unordered_multiset::get_allocator
- unordered_set/std::unordered_multiset::hash
- unordered_set/std::unordered_multiset::insert
- unordered_set/std::unordered_multiset::key_eq
- unordered_set/std::unordered_multiset::load_factor
- unordered_set/std::unordered_multiset::max_bucket_count
- unordered_set/std::unordered_multiset::max_load_factor
- unordered_set/std::unordered_multiset::max_size
- unordered_set/std::unordered_multiset::rehash
- unordered_set/std::unordered_multiset::size
- unordered_set/std::unordered_multiset::swap
- unordered_set/std::unordered_multiset::unordered_multiset
- unordered_set/std::unordered_multiset::operator=
- unordered_set/std::unordered_multiset::hash_function
helpviewer_keywords:
- std::unordered_multiset
- std::unordered_multiset::allocator_type
- std::unordered_multiset::const_iterator
- std::unordered_multiset::const_local_iterator
- std::unordered_multiset::const_pointer
- std::unordered_multiset::const_reference
- std::unordered_multiset::difference_type
- std::unordered_multiset::hasher
- std::unordered_multiset::iterator
- std::unordered_multiset::key_equal
- std::unordered_multiset::key_type
- std::unordered_multiset::local_iterator
- std::unordered_multiset::pointer
- std::unordered_multiset::reference
- std::unordered_multiset::size_type
- std::unordered_multiset::value_type
- std::unordered_multiset::begin
- std::unordered_multiset::bucket
- std::unordered_multiset::bucket_count
- std::unordered_multiset::bucket_size
- std::unordered_multiset::cbegin
- std::unordered_multiset::cend
- std::unordered_multiset::clear
- std::unordered_multiset::contains
- std::unordered_multiset::count
- std::unordered_multiset::emplace
- std::unordered_multiset::emplace_hint
- std::unordered_multiset::empty
- std::unordered_multiset::end
- std::unordered_multiset::equal_range
- std::unordered_multiset::erase
- std::unordered_multiset::find
- std::unordered_multiset::get_allocator
- std::unordered_multiset::hash
- std::unordered_multiset::insert
- std::unordered_multiset::key_eq
- std::unordered_multiset::load_factor
- std::unordered_multiset::max_bucket_count
- std::unordered_multiset::max_load_factor
- std::unordered_multiset::max_size
- std::unordered_multiset::rehash
- std::unordered_multiset::size
- std::unordered_multiset::swap
- std::unordered_multiset::unordered_multiset
- std::unordered_multiset::operator=
- std::unordered_multiset::allocator_type
- std::unordered_multiset::const_iterator
- std::unordered_multiset::const_local_iterator
- std::unordered_multiset::const_pointer
- std::unordered_multiset::const_reference
- std::unordered_multiset::difference_type
- std::unordered_multiset::hasher
- std::unordered_multiset::iterator
- std::unordered_multiset::key_equal
- std::unordered_multiset::key_type
- std::unordered_multiset::local_iterator
- std::unordered_multiset::pointer
- std::unordered_multiset::reference
- std::unordered_multiset::size_type
- std::unordered_multiset::value_type
- std::unordered_multiset::begin
- std::unordered_multiset::bucket
- std::unordered_multiset::bucket_count
- std::unordered_multiset::bucket_size
- std::unordered_multiset::cbegin
- std::unordered_multiset::cend
- std::unordered_multiset::clear
- std::unordered_multiset::count
- std::unordered_multiset::emplace
- std::unordered_multiset::emplace_hint
- std::unordered_multiset::empty
- std::unordered_multiset::end
- std::unordered_multiset::equal_range
- std::unordered_multiset::erase
- std::unordered_multiset::find
- std::unordered_multiset::get_allocator
- std::unordered_multiset::hash_function
- std::unordered_multiset::insert
- std::unordered_multiset::key_eq
- std::unordered_multiset::load_factor
- std::unordered_multiset::max_bucket_count
- std::unordered_multiset::max_load_factor
- std::unordered_multiset::max_size
- std::unordered_multiset::rehash
- std::unordered_multiset::size
- std::unordered_multiset::swap
ms.assetid: 70c8dfc5-492a-4af2-84f5-1aa9cb04b71c
ms.openlocfilehash: 0730f4eb6ba8e625c2c40cecddc4f689ec775d17
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91352772"
---
# <a name="unordered_multiset-class"></a>Classe unordered_multiset

O modelo de classe descreve um objeto que controla uma sequência de comprimento variável de elementos do tipo `const Key` . A sequência é ordenada sem muita rigidez por uma função de hash, que particiona a sequência em um conjunto ordenado de subsequências chamado bucket. Dentro de cada bucket uma função de comparação determina se um par de elementos tem ordenação equivalente. Cada elemento serve como uma chave de classificação e um valor. A sequência é representada de forma a permitir pesquisa, inserção e remoção de um elemento com um número arbitrário de operações que podem ser independentes do número de elementos na sequência (tempo constante), pelo menos quando todos os buckets forem de comprimento aproximadamente igual. No pior caso, quando todos os elementos estiverem em um bucket, o número de operações será proporcional ao número de elementos na sequência (tempo linear). Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Key,
    class Hash = std::hash<Key>,
    class Pred = std::equal_to<Key>,
    class Alloc = std::allocator<Key>>
class unordered_multiset;
```

### <a name="parameters"></a>Parâmetros

*Chaves*\
O tipo principal.

*Tralha*\
O tipo de objeto da função de hash.

*Pred*\
O tipo de objeto da função de comparação de igualdade.

*Alocação*\
A classe do alocador.

## <a name="members"></a>Membros

|Definição de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|O tipo de um distribuidor para gerenciar o armazenamento.|
|[const_iterator](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|
|[const_local_iterator](#const_local_iterator)|O tipo de um iterador de bucket de constante para a sequência controlada.|
|[const_pointer](#const_pointer)|O tipo de um ponteiro de constante para um elemento.|
|[const_reference](#const_reference)|O tipo de uma referência de constante para um elemento.|
|[difference_type](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|
|[Hasher sem](#hasher)|O tipo de função de hash.|
|[repeti](#iterator)|O tipo de um iterador para a sequência controlada.|
|[key_equal](#key_equal)|O tipo da função de comparação.|
|[key_type](#key_type)|O tipo de uma chave de classificação.|
|[local_iterator](#local_iterator)|O tipo de um iterador de bucket para a sequência controlada.|
|[refere](#pointer)|O tipo de um ponteiro para um elemento.|
|[reference](#reference)|O tipo de uma referência para um elemento.|
|[size_type](#size_type)|O tipo de uma distância sem sinal entre dois elementos.|
|[value_type](#value_type)|O tipo de um elemento.|

|Função membro|Descrição|
|-|-|
|[Comece](#begin)|Designa o início da sequência controlada.|
|[sequencia](#bucket)|Obtém o número de buckets de um valor de chave.|
|[bucket_count](#bucket_count)|Obtém o número de buckets.|
|[bucket_size](#bucket_size)|Obtém o tamanho de um bucket.|
|[cbegin](#cbegin)|Designa o início da sequência controlada.|
|[cend](#cend)|Designa o fim da sequência controlada.|
|[clear](#clear)|Remove todos os elementos.|
|[contém](#contains)<sup>c++ 20</sup>|Verifica se há um elemento com a chave especificada.|
|[contagem](#count)|Localiza o número de elementos que correspondem a uma chave especificada.|
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
|[prolongar](#rehash)|Recria a tabela de hash.|
|[size](#size)|Conta o número de elementos.|
|[permuta](#swap)|Alterna o conteúdo de dois contêineres.|
|[unordered_multiset](#unordered_multiset)|Constrói um objeto contêiner.|

|Operador|Descrição|
|-|-|
|[unordered_multiset::operator=](#op_eq)|Copia uma tabela de hash.|

## <a name="remarks"></a>Comentários

O objeto ordena a sequência que ele controla chamando dois objetos armazenados, um objeto de função de comparação do tipo [unordered_multiset::key_equal](#key_equal) e um objeto de função de hash do tipo [unordered_multiset::hasher](#hasher). Você acessa o primeiro objeto armazenado chamando a função de membro [unordered_multiset:: key_eq](#key_eq) `()` ; e acessa o segundo objeto armazenado chamando a função de membro [unordered_multiset:: hash_function](#hash) `()` . Especificamente, para todos os valores `X` e `Y` do tipo `Key`, a chamada `key_eq()(X, Y)` retornará true somente se os dois valores de argumento tiverem ordem equivalente; a chamada `hash_function()(keyval)` resulta em uma distribuição de valores do tipo `size_t`. Diferentemente do modelo de classe [Unordered_set classe](../standard-library/unordered-set-class.md), um objeto do tipo `unordered_multiset` não garante que `key_eq()(X, Y)` seja sempre false para quaisquer dois elementos da sequência controlada. (As chaves não precisam ser exclusivas.)

O objeto também armazena um fator de carga máximo, que especifica o número máximo médio desejado de elementos por bucket. Se a inserção de um elemento fizer com que [unordered_multiset:: load_factor](#load_factor) `()` exceda o fator de carga máximo, o contêiner aumentará o número de buckets e recompilará a tabela de hash conforme necessário.

A ordem real de elementos na sequência controlada depende da função de hash, da função de comparação, da ordem de inserção, do fator máximo de carga e do número atual de buckets. Você não pode fazer uma previsão geral da ordem dos elementos na sequência controlada. No entanto, você sempre terá certeza de que qualquer subconjunto de elementos que tenha ordem equivalente será adjacente na sequência de controle.

O objeto aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado de alocador do tipo [unordered_multiset::allocator_type](#allocator_type). Esse objeto de alocador deve ter a mesma interface externa que um objeto do tipo `allocator` . Observe que o objeto de alocador armazenado não é copiado quando o objeto de contêiner é atribuído.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<unordered_set>

**Namespace:** std

## <a name="unordered_multisetallocator_type"></a><a name="allocator_type"></a> unordered_multiset:: allocator_type

O tipo de um distribuidor para gerenciar o armazenamento.

```cpp
typedef Alloc allocator_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Alloc`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_allocator_type.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
typedef std::allocator<std::pair<const char, int> > Myalloc;
int main()
{
    Myset c1;

    Myset::allocator_type al = c1.get_allocator();
    std::cout << "al == std::allocator() is "
        << std::boolalpha << (al == Myalloc()) << std::endl;

    return (0);
}
```

```Output
al == std::allocator() is true
```

## <a name="unordered_multisetbegin"></a><a name="begin"></a> unordered_multiset:: Begin

Designa o início da sequência controlada ou um bucket.

```cpp
iterator begin();

const_iterator begin() const;

local_iterator begin(size_type nbucket);

const_local_iterator begin(size_type nbucket) const;
```

### <a name="parameters"></a>Parâmetros

*nbucket*\
O número de bucket.

### <a name="remarks"></a>Comentários

As duas primeiras funções membro retornam um iterador de encaminhamento que aponta para o primeiro elemento da sequência (ou imediatamente após o fim de uma sequência vazia). As duas últimas funções de membro retornam um iterador de encaminhamento que aponta para o primeiro elemento do Bucket *nbucket* (ou apenas além do final de um bucket vazio).

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_begin.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // inspect first two items "[c] [b]"
    Myset::iterator it2 = c1.begin();
    std::cout << "[" << *it2 << "] ";
    ++it2;
    std::cout << "[" << *it2 << "] ";
    std::cout << std::endl;

    // inspect bucket containing 'a'
    Myset::const_local_iterator lit = c1.begin(c1.bucket('a'));
    std::cout << "[" << *lit << "] ";

    return (0);
}
```

```Output
[c] [b] [a]
[c] [b]
[a]
```

## <a name="unordered_multisetbucket"></a><a name="bucket"></a> unordered_multiset:: Bucket

Obtém o número de buckets de um valor de chave.

```cpp
size_type bucket(const Key& keyval) const;
```

### <a name="parameters"></a>Parâmetros

*keyval*\
O valor de chave a ser mapeado.

### <a name="remarks"></a>Comentários

A função membro retorna o número de bucket atualmente correspondente ao valor da chave `keyval`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_bucket.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a] "
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // display buckets for keys
    Myset::size_type bs = c1.bucket('a');
    std::cout << "bucket('a') == " << bs << std::endl;
    std::cout << "bucket_size(" << bs << ") == " << c1.bucket_size(bs)
        << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
bucket('a') == 7
bucket_size(7) == 1
```

## <a name="unordered_multisetbucket_count"></a><a name="bucket_count"></a> unordered_multiset:: bucket_count

Obtém o número de buckets.

```cpp
size_type bucket_count() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o número atual de buckets.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_bucket_count.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a] "
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
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

    return (0);
}
```

```Output
[c] [b] [a]
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

## <a name="unordered_multisetbucket_size"></a><a name="bucket_size"></a> unordered_multiset:: bucket_size

Obtém o tamanho de um bucket

```cpp
size_type bucket_size(size_type nbucket) const;
```

### <a name="parameters"></a>Parâmetros

*nbucket*\
O número de bucket.

### <a name="remarks"></a>Comentários

As funções de membro retornam o tamanho do número de buckets *nbucket*.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_bucket_size.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a] "
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // display buckets for keys
    Myset::size_type bs = c1.bucket('a');
    std::cout << "bucket('a') == " << bs << std::endl;
    std::cout << "bucket_size(" << bs << ") == " << c1.bucket_size(bs)
        << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
bucket('a') == 7
bucket_size(7) == 1
```

## <a name="unordered_multisetcbegin"></a><a name="cbegin"></a> unordered_multiset:: cbegin

Retorna um **`const`** iterador que aborda o primeiro elemento no intervalo.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um **`const`** iterador de acesso de encaminhamento que aponta para o primeiro elemento do intervalo ou o local logo após o final de um intervalo vazio (para um intervalo vazio `cbegin() == cend()` ).

### <a name="remarks"></a>Comentários

Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.

Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` ser um contêiner modificável (não **`const`** ) de qualquer tipo que dê suporte a `begin()` e `cbegin()` .

```cpp
auto i1 = Container.begin();
// i1 is Container<T>::iterator

auto i2 = Container.cbegin();
// i2 is Container<T>::const_iterator
```

## <a name="unordered_multisetcend"></a><a name="cend"></a> unordered_multiset:: cend

Retorna um **`const`** iterador que aborda o local logo após o último elemento em um intervalo.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor retornado

Um **`const`** iterador de acesso de encaminhamento que aponta muito além do fim do intervalo.

### <a name="remarks"></a>Comentários

`cend` é usado para testar se um iterador passou do fim de seu intervalo.

Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` ser um contêiner modificável (não **`const`** ) de qualquer tipo que dê suporte a `end()` e `cend()` .

```cpp
auto i1 = Container.end();
// i1 is Container<T>::iterator

auto i2 = Container.cend();
// i2 is Container<T>::const_iterator
```

O valor retornado por `cend` não deve ser desreferenciado.

## <a name="unordered_multisetclear"></a><a name="clear"></a> unordered_multiset:: Clear

Remove todos os elementos.

```cpp
void clear();
```

### <a name="remarks"></a>Comentários

As chamadas de função membro [unordered_multiset::erase](#erase)`(` [unordered_multiset::begin](#begin)`(),` [unordered_multiset::end](#end)`())`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_clear.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a] "
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // clear the container and reinspect
    c1.clear();
    std::cout << "size == " << c1.size() << std::endl;
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;
    std::cout << std::endl;

    c1.insert('d');
    c1.insert('e');

    // display contents "[e] [d] "
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    std::cout << "size == " << c1.size() << std::endl;
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
size == 0
empty() == true

[e] [d]
size == 2
empty() == false
```

## <a name="unordered_multisetconst_iterator"></a><a name="const_iterator"></a> unordered_multiset:: const_iterator

O tipo de um iterador de constante para a sequência controlada.

```cpp
typedef T1 const_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um iterador de encaminhamento constante para a sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T1`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_const_iterator.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
```

## <a name="unordered_multisetconst_local_iterator"></a><a name="const_local_iterator"></a> unordered_multiset:: const_local_iterator

O tipo de um iterador de bucket de constante para a sequência controlada.

```cpp
typedef T5 const_local_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um iterador de encaminhamento constante para um bucket. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T5`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_const_local_iterator.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // inspect bucket containing 'a'
    Myset::const_local_iterator lit = c1.begin(c1.bucket('a'));
    std::cout << "[" << *lit << "] ";

    return (0);
}
```

```Output
[c] [b] [a]
[a]
```

## <a name="unordered_multisetconst_pointer"></a><a name="const_pointer"></a> unordered_multiset:: const_pointer

O tipo de um ponteiro de constante para um elemento.

```cpp
typedef Alloc::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um ponteiro constante para um elemento da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_const_pointer.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::iterator it = c1.begin();
        it != c1.end(); ++it)
        {
        Myset::const_pointer p = &*it;
        std::cout << "[" << *p << "] ";
        }
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
```

## <a name="unordered_multisetconst_reference"></a><a name="const_reference"></a> unordered_multiset:: const_reference

O tipo de uma referência de constante para um elemento.

```cpp
typedef Alloc::const_reference const_reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como uma referência constante para um elemento da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_const_reference.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::iterator it = c1.begin();
        it != c1.end(); ++it)
        {
        Myset::const_reference ref = *it;
        std::cout << "[" << ref << "] ";
        }
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
```

## <a name="unordered_multisetcontains"></a><a name="contains"></a> unordered_multiset:: contém

Verifica se há um elemento com a chave especificada no `unordered_multiset` .

```cpp
bool contains(const Key& key) const;
template<class K> bool contains(const K& key) const;
```

### <a name="parameters"></a>Parâmetros

*C*\
Tipo da chave.

*chaves*\
O valor de chave do elemento a ser pesquisado.

### <a name="return-value"></a>Valor retornado

`true` Se o elemento for encontrado no contêiner; `false` caso contrário.

### <a name="remarks"></a>Comentários

`contains()` é novo no C++ 20. Para usá-lo, especifique a opção de compilador [/std: c + + mais recente](../build/reference/std-specify-language-standard-version.md) .

`template<class K> bool contains(const K& key) const` só participará da resolução de sobrecarga se `key_compare` for transparente.

### <a name="example"></a>Exemplo

```cpp
// Requires /std:c++latest
#include <unordered_set>
#include <iostream>

int main()
{
    std::unordered_multiset<int> theUnorderedMultiset = { 1, 2, 3 };

    std::cout << std::boolalpha; // so booleans show as 'true' or 'false'
    std::cout << theUnorderedMultiset.contains(1) << '\n';
    std::cout << theUnorderedMultiset.contains(4) << '\n';

    return 0;
}
```

```Output
true
false
```

## <a name="unordered_multisetcount"></a><a name="count"></a> unordered_multiset:: Count

Localiza o número de elementos que correspondem a uma chave especificada.

```cpp
size_type count(const Key& keyval) const;
```

### <a name="parameters"></a>Parâmetros

*keyval*\
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função membro retorna o número de elementos no intervalo delimitado por [unordered_multiset:: equal_range](#equal_range) `(keyval)` .

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_count.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    std::cout << "count('A') == " << c1.count('A') << std::endl;
    std::cout << "count('b') == " << c1.count('b') << std::endl;
    std::cout << "count('C') == " << c1.count('C') << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
count('A') == 0
count('b') == 1
count('C') == 0
```

## <a name="unordered_multisetdifference_type"></a><a name="difference_type"></a> unordered_multiset::d ifference_type

O tipo de uma distância com sinal entre dois elementos.

```cpp
typedef T3 difference_type;
```

### <a name="remarks"></a>Comentários

O tipo inteiro com sinal descreve um objeto que pode representar a diferença entre os endereços de dois elementos quaisquer na sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T3`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_difference_type.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // compute positive difference
    Myset::difference_type diff = 0;
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        ++diff;
    std::cout << "end()-begin() == " << diff << std::endl;

    // compute negative difference
    diff = 0;
    for (Myset::const_iterator it = c1.end();
        it != c1.begin(); --it)
        --diff;
    std::cout << "begin()-end() == " << diff << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
end()-begin() == 3
begin()-end() == -3
```

## <a name="unordered_multisetemplace"></a><a name="emplace"></a> unordered_multiset:: emplace

Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada).

```cpp
template <class... Args>
iterator emplace(Args&&... args);
```

### <a name="parameters"></a>Parâmetros

*argumento*\
Os argumentos encaminhados para criar um elemento a ser inserido no unordered_multiset.

### <a name="return-value"></a>Valor retornado

Um iterador para o elemento recém-inserido.

### <a name="remarks"></a>Comentários

Nenhuma referência a elementos de contêiner é invalidada por essa função, mas ela pode invalidar todos os iteradores no contêiner.

Durante a inserção, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o contêiner não será modificado. Se a exceção for lançada na função hash, o resultado é indefinido.

Para obter um exemplo de código, consulte [multiset::emplace](../standard-library/multiset-class.md#emplace).

## <a name="unordered_multisetemplace_hint"></a><a name="emplace_hint"></a> unordered_multiset:: emplace_hint

Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada), com uma dica de posicionamento.

```cpp
template <class... Args>
iterator emplace_hint(
    const_iterator where,
    Args&&... args);
```

### <a name="parameters"></a>Parâmetros

*argumento*\
Os argumentos encaminhados para criar um elemento a ser inserido no unordered_multiset.

*posição*\
Uma dica relacionada ao local do qual se começa a procurar pelo ponto de inserção correto.

### <a name="return-value"></a>Valor retornado

Um iterador para o elemento recém-inserido.

### <a name="remarks"></a>Comentários

Nenhuma referência a elementos de contêiner é invalidada por essa função, mas ela pode invalidar todos os iteradores no contêiner.

Durante a inserção, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o contêiner não será modificado. Se a exceção for lançada na função hash, o resultado é indefinido.

Para obter um exemplo de código, consulte [set::emplace_hint](../standard-library/set-class.md#emplace_hint).

## <a name="unordered_multisetempty"></a><a name="empty"></a> unordered_multiset:: Empty

Testa se nenhum elemento está presente.

```cpp
bool empty() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna verdadeiro para uma sequência controlada vazia.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_empty.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // clear the container and reinspect
    c1.clear();
    std::cout << "size == " << c1.size() << std::endl;
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;
    std::cout << std::endl;

    c1.insert('d');
    c1.insert('e');

    // display contents "[e] [d]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    std::cout << "size == " << c1.size() << std::endl;
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
size == 0
empty() == true

[e] [d]
size == 2
empty() == false
```

## <a name="unordered_multisetend"></a><a name="end"></a> unordered_multiset:: End

Designa o fim da sequência controlada.

```cpp
iterator end();
const_iterator end() const;
local_iterator end(size_type nbucket);
const_local_iterator end(size_type nbucket) const;
```

### <a name="parameters"></a>Parâmetros

*nbucket*\
O número de bucket.

### <a name="remarks"></a>Comentários

As duas primeiras funções membro retornam um iterador de encaminhamento que aponta para logo além do fim da sequência. As duas últimas funções de membro retornam um iterador de encaminhamento que aponta muito além do fim do Bucket *nbucket*.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_end.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // inspect last two items "[a] [b]"
    Myset::iterator it2 = c1.end();
    --it2;
    std::cout << "[" << *it2 << "] ";
    --it2;
    std::cout << "[" << *it2 << "] ";
    std::cout << std::endl;

    // inspect bucket containing 'a'
    Myset::const_local_iterator lit = c1.end(c1.bucket('a'));
    --lit;
    std::cout << "[" << *lit << "] ";

    return (0);
}
```

```Output
[c] [b] [a]
[a] [b]
[a]
```

## <a name="unordered_multisetequal_range"></a><a name="equal_range"></a> unordered_multiset:: equal_range

Localiza o intervalo que corresponde a uma chave especificada.

```cpp
std::pair<iterator, iterator>
    equal_range(const Key& keyval);

std::pair<const_iterator, const_iterator>
    equal_range(const Key& keyval) const;
```

### <a name="parameters"></a>Parâmetros

*keyval*\
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função membro retorna um par de iteradores `X` , de modo que `[X.first, X.second)` delimite apenas os elementos da sequência controlada que têm uma ordenação equivalente com *keyval*. Se esses elementos não existirem, ambos os iteradores serão `end()`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_equal_range.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // display results of failed search
    std::pair<Myset::iterator, Myset::iterator> pair1 =
        c1.equal_range('x');
    std::cout << "equal_range('x'):";
    for (; pair1.first != pair1.second; ++pair1.first)
        std::cout << "[" << *pair1.first << "] ";
    std::cout << std::endl;

    // display results of successful search
    pair1 = c1.equal_range('b');
    std::cout << "equal_range('b'):";
    for (; pair1.first != pair1.second; ++pair1.first)
        std::cout << "[" << *pair1.first << "] ";
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
equal_range('x'):
equal_range('b'): [b]
```

## <a name="unordered_multiseterase"></a><a name="erase"></a> unordered_multiset:: Erase

Remove um elemento ou um intervalo de elementos em um unordered_multiset das posições especificadas ou remove elementos que correspondem a uma chave especificada.

```cpp
iterator erase(
    const_iterator Where);

iterator erase(
    const_iterator First,
    const_iterator Last);

size_type erase(
    const key_type& Key);
```

### <a name="parameters"></a>Parâmetros

*Posição*\
A posição do elemento a ser removido.

*Primeiro*\
A posição do primeiro elemento a ser removido.

*Última*\
A posição logo após o último elemento a ser removido.

*Chaves*\
O valor de chave dos elementos a serem removidos.

### <a name="return-value"></a>Valor retornado

Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de quaisquer elementos removidos ou um elemento que será o final do unordered_multiset, se esse elemento não existir.

Para a terceira função membro, ele retorna o número de elementos que foram removidos do unordered_multiset.

### <a name="remarks"></a>Comentários

Para obter um exemplo de código, consulte [set::erase](../standard-library/set-class.md#erase).

## <a name="unordered_multisetfind"></a><a name="find"></a> unordered_multiset:: localizar

Localiza um elemento que corresponde a uma chave especificada.

```cpp
const_iterator find(const Key& keyval) const;
```

### <a name="parameters"></a>Parâmetros

*keyval*\
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função membro retorna [unordered_multiset:: equal_range](#equal_range) `(keyval).first` .

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_find.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // try to find and fail
    std::cout << "find('A') == "
        << std::boolalpha << (c1.find('A') != c1.end()) << std::endl;

    // try to find and succeed
    Myset::iterator it = c1.find('b');
    std::cout << "find('b') == "
        << std::boolalpha << (it != c1.end())
        << ": [" << *it << "] " << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
find('A') == false
find('b') == true: [b]
```

## <a name="unordered_multisetget_allocator"></a><a name="get_allocator"></a> unordered_multiset:: get_allocator

Obtém o objeto de alocador armazenado.

```cpp
Alloc get_allocator() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o objeto alocador armazenado.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_get_allocator.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
typedef std::allocator<std::pair<const char, int> > Myalloc;
int main()
{
    Myset c1;

    Myset::allocator_type al = c1.get_allocator();
    std::cout << "al == std::allocator() is "
        << std::boolalpha << (al == Myalloc()) << std::endl;

    return (0);
}
```

```Output
al == std::allocator() is true
```

## <a name="unordered_multisethash_function"></a><a name="hash"></a> unordered_multiset:: hash_function

Obtém o objeto armazenado da função de hash.

```cpp
Hash hash_function() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o objeto da função hash armazenado.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_hash_function.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    Myset::hasher hfn = c1.hash_function();
    std::cout << "hfn('a') == " << hfn('a') << std::endl;
    std::cout << "hfn('b') == " << hfn('b') << std::endl;

    return (0);
}
```

```Output
hfn('a') == 1630279
hfn('b') == 1647086
```

## <a name="unordered_multisethasher"></a><a name="hasher"></a> unordered_multiset:: Hasher

O tipo de função de hash.

```cpp
typedef Hash hasher;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Hash`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_hasher.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    Myset::hasher hfn = c1.hash_function();
    std::cout << "hfn('a') == " << hfn('a') << std::endl;
    std::cout << "hfn('b') == " << hfn('b') << std::endl;

    return (0);
}
```

```Output
hfn('a') == 1630279
hfn('b') == 1647086
```

## <a name="unordered_multisetinsert"></a><a name="insert"></a> unordered_multiset:: Insert

Insere um elemento ou um intervalo de elementos em um unordered_multiset.

```cpp
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

*Val*\
O valor de um elemento a ser inserido no unordered_multiset.

*Posição*\
O local a partir do qual se começa a procurar pelo ponto de inserção correto.

*ValTy*\
Parâmetro de modelo que especifica o tipo de argumento que o unordered_multiset pode usar para construir um elemento de [value_type](../standard-library/map-class.md#value_type)e o *valor* de encaminhamentos perfeitos como um argumento.

*Primeiro*\
A posição do primeiro elemento a ser copiado.

*Última*\
A posição imediatamente após o último elemento a ser copiado.

*InputIterator*\
Argumento da função de modelo que atende aos requisitos de um [iterador de entrada](../standard-library/input-iterator-tag-struct.md) que aponta para elementos de um tipo que pode ser usado para construir objetos [value_type](../standard-library/map-class.md#value_type).

*IList*\
O [initializer_list](../standard-library/initializer-list.md) do qual copiar os elementos.

### <a name="return-value"></a>Valor retornado

As funções do membro de inserir elemento único, (1) e (2), retornam um iterador para a posição em que o novo elemento foi inserido no unordered_multiset.

As funções do membro de inserir elemento único, (3) e (4), retornam um iterador para a posição em que o novo elemento foi inserido no unordered_multiset.

### <a name="remarks"></a>Comentários

Nenhum ponteiro ou referência é invalidado por esta função, mas ela pode invalidar todos os iteradores para o contêiner.

Durante a inserção de apenas um elemento, se uma exceção for lançada, mas não ocorrer na função hash do contêiner, o estado do contêiner não é modificado. Se a exceção for lançada na função hash, o resultado é indefinido. Durante a inserção de vários elementos, se uma exceção for lançada, o contêiner será deixado em um estado não especificado, mas válido.

O [value_type](../standard-library/map-class.md#value_type) de um contêiner é um typedef que pertence ao contêiner e, para o conjunto, `unordered_multiset<V>::value_type` é do tipo `const V`.

A função de membro Range (5) insere a sequência de valores de elemento em um unordered_multiset que corresponde a cada elemento endereçado por um iterador no intervalo `[First, Last)` ; portanto, *Last* não é inserido. A função de membro do contêiner `end()` refere-se à posição logo após o último elemento no contêiner, por exemplo, a instrução `m.insert(v.begin(), v.end());` insere todos os elementos de `v` em `m`.

A função membro da lista do inicializador (6) usa uma [initializer_list](../standard-library/initializer-list.md) para copiar elementos no unordered_multiset.

Para inserir um elemento criado no local, ou seja, sem a realização de operações de cópia ou movimentação, consulte [unordered_multiset::emplace](#emplace) e [unordered_multiset::emplace_hint](#emplace_hint).

Para obter um exemplo de código, consulte [multiset::insert](../standard-library/multiset-class.md#insert).

## <a name="unordered_multisetiterator"></a><a name="iterator"></a> unordered_multiset:: iterador

Um tipo que fornece uma constante [iterador de avanço](../standard-library/forward-iterator-tag-struct.md) que pode ler os elementos em um unordered_multiset.

```cpp
typedef implementation-defined iterator;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [begin](../standard-library/multiset-class.md#begin) para obter um exemplo de como declarar e usar um **iterator**.

## <a name="unordered_multisetkey_eq"></a><a name="key_eq"></a> unordered_multiset:: key_eq

Obtém o objeto armazenado da função de comparação.

```cpp
Pred key_eq() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o objeto da função de comparação armazenado.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_key_eq.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    Myset::key_equal cmpfn = c1.key_eq();
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

## <a name="unordered_multisetkey_equal"></a><a name="key_equal"></a> unordered_multiset:: key_equal

O tipo da função de comparação.

```cpp
typedef Pred key_equal;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Pred`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_key_equal.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    Myset::key_equal cmpfn = c1.key_eq();
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

## <a name="unordered_multisetkey_type"></a><a name="key_type"></a> unordered_multiset:: key_type

O tipo de uma chave de classificação.

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Key`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_key_type.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // add a value and reinspect
    Myset::key_type key = 'd';
    Myset::value_type val = key;
    c1.insert(val);

    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
[d] [c] [b] [a]
```

## <a name="unordered_multisetload_factor"></a><a name="load_factor"></a> unordered_multiset:: load_factor

Conta a média de elementos por bucket.

```cpp
float load_factor() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna `(float)` [unordered_multiset:: Size](#size) `() / (float)` [unordered_multiset:: bucket_count](#bucket_count) `()` , o número médio de elementos por Bucket.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_load_factor.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
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

## <a name="unordered_multisetlocal_iterator"></a><a name="local_iterator"></a> unordered_multiset:: local_iterator

O tipo de um iterador de bucket.

```cpp
typedef T4 local_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um iterador de encaminhamento para um bucket. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T4`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_local_iterator.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // inspect bucket containing 'a'
    Myset::local_iterator lit = c1.begin(c1.bucket('a'));
    std::cout << "[" << *lit << "] ";

    return (0);
}
```

```Output
[c] [b] [a]
[a]
```

## <a name="unordered_multisetmax_bucket_count"></a><a name="max_bucket_count"></a> unordered_multiset:: max_bucket_count

Obtém o número máximo de buckets.

```cpp
size_type max_bucket_count() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o número máximo de buckets permitidos no momento.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_max_bucket_count.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
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
[c] [b] [a]
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

## <a name="unordered_multisetmax_load_factor"></a><a name="max_load_factor"></a> unordered_multiset:: max_load_factor

Obtém ou define o máximo de elementos por bucket.

```cpp
float max_load_factor() const;

void max_load_factor(float factor);
```

### <a name="parameters"></a>Parâmetros

*multi-fator*\
O novo fator de carga máxima.

### <a name="remarks"></a>Comentários

A primeira função membro retorna o fator de carga máxima armazenado. A segunda função de membro substitui o fator de carga máximo armazenado pelo *fator*.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_max_load_factor.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
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
[c] [b] [a]
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

## <a name="unordered_multisetmax_size"></a><a name="max_size"></a> unordered_multiset:: max_size

Obtém o tamanho máximo da sequência controlada.

```cpp
size_type max_size() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência mais longa que o objeto pode controlar.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_max_size.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    std::cout << "max_size() == " << c1.max_size() << std::endl;

    return (0);
}
```

```Output
max_size() == 4294967295
```

## <a name="unordered_multisetoperator"></a><a name="op_eq"></a> unordered_multiset:: Operator =

Copia uma tabela de hash.

```cpp
unordered_multiset& operator=(const unordered_multiset& right);

unordered_multiset& operator=(unordered_multiset&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [unordered_multiset](../standard-library/unordered-multiset-class.md) que está sendo copiado para o `unordered_multiset`.

### <a name="remarks"></a>Comentários

Depois de apagar todos os elementos existentes em um `unordered_multiset` , `operator=` o copia ou move o conteúdo do *lado* para o `unordered_multiset` .

### <a name="example"></a>Exemplo

```cpp
// unordered_multiset_operator_as.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

int main( )
{
    using namespace std;
    unordered_multiset<int> v1, v2, v3;
    unordered_multiset<int>::iterator iter;

    v1.insert(10);

    cout << "v1 = " ;
    for (iter = v1.begin(); iter != v1.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    v2 = v1;
    cout << "v2 = ";
    for (iter = v2.begin(); iter != v2.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    // move v1 into v2
    v2.clear();
    v2 = move(v1);
    cout << "v2 = ";
    for (iter = v2.begin(); iter != v2.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}
```

## <a name="unordered_multisetpointer"></a><a name="pointer"></a> unordered_multiset::p ointer

O tipo de um ponteiro para um elemento.

```cpp
typedef Alloc::pointer pointer;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um ponteiro para um elemento da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_pointer.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::iterator it = c1.begin();
        it != c1.end(); ++it)
        {
        Myset::key_type key = *it;
        Myset::pointer p = &key;
        std::cout << "[" << *p << "] ";
        }
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
```

## <a name="unordered_multisetreference"></a><a name="reference"></a> unordered_multiset:: referência

O tipo de uma referência para um elemento.

```cpp
typedef Alloc::reference reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como uma referência para um elemento da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_reference.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::iterator it = c1.begin();
        it != c1.end(); ++it)
        {
        Myset::key_type key = *it;
        Myset::reference ref = key;
        std::cout << "[" << ref << "] ";
        }
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
```

## <a name="unordered_multisetrehash"></a><a name="rehash"></a> unordered_multiset:: rehash

Recria a tabela de hash.

```cpp
void rehash(size_type nbuckets);
```

### <a name="parameters"></a>Parâmetros

*nbuckets*\
O número solicitado de buckets.

### <a name="remarks"></a>Comentários

A função membro altera o número de buckets para ser pelo menos *nbuckets* e recria a tabela de hash conforme necessário.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_rehash.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
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
[c] [b] [a]
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

## <a name="unordered_multisetsize"></a><a name="size"></a> unordered_multiset:: tamanho

Conta o número de elementos.

```cpp
size_type size() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_size.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // clear the container and reinspect
    c1.clear();
    std::cout << "size == " << c1.size() << std::endl;
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;
    std::cout << std::endl;

    c1.insert('d');
    c1.insert('e');

    // display contents "[e] [d]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    std::cout << "size == " << c1.size() << std::endl;
    std::cout << "empty() == " << std::boolalpha << c1.empty() << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
size == 0
empty() == true

[e] [d]
size == 2
empty() == false
```

## <a name="unordered_multisetsize_type"></a><a name="size_type"></a> unordered_multiset:: size_type

O tipo de uma distância sem sinal entre dois elementos.

```cpp
typedef T2 size_type;
```

### <a name="remarks"></a>Comentários

O tipo inteiro sem sinal descreve um objeto que pode representar o tamanho de qualquer sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação `T2`.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_size_type.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;
    Myset::size_type sz = c1.size();

    std::cout << "size == " << sz << std::endl;

    return (0);
}
```

```Output
size == 0
```

## <a name="unordered_multisetswap"></a><a name="swap"></a> unordered_multiset:: swap

Alterna o conteúdo de dois contêineres.

```cpp
void swap(unordered_multiset& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O contêiner para alternância.

### <a name="remarks"></a>Comentários

A função membro troca as sequências controladas entre **`*this`** e *à direita*. Se [unordered_multiset:: get_allocator](#get_allocator) `() == right.get_allocator()` , ele faz isso em constante tempo, ele lança uma exceção somente como resultado da cópia do objeto de características armazenado do tipo `Tr` e invalida nenhuma referência, ponteiros ou iteradores que designam elementos nas duas sequências controladas. Caso contrário, executará uma série de atribuições de elemento e de chamadas do construtor proporcional ao número de elementos nas duas sequências controladas.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_swap.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    Myset c2;

    c2.insert('d');
    c2.insert('e');
    c2.insert('f');

    c1.swap(c2);

    // display contents "[f] [e] [d]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    swap(c1, c2);

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
[f] [e] [d]
[c] [b] [a]
```

## <a name="unordered_multisetunordered_multiset"></a><a name="unordered_multiset"></a> unordered_multiset:: unordered_multiset

Constrói um objeto contêiner.

```cpp
unordered_multiset(
    const unordered_multiset& Right);

explicit unordered_multiset(
    size_type Bucket_count = N0,
    const Hash& Hash = Hash(),
    const Comp& Comp = Comp(),
    const Allocator& Al = Alloc());

unordered_multiset(
    unordered_multiset&& Right);

unordered_set(
    initializer_list<Type> IList);

unordered_set(
    initializer_list<Typ> IList,
    size_type Bucket_count);

unordered_set(
    initializer_list<Type> IList,
    size_type Bucket_count,
    const Hash& Hash);

unordered_set(
    initializer_list<Type> IList,
    size_type Bucket_count,
    const Hash& Hash,
    const Key& Key);

unordered_set(
    initializer_list<Type> IList,
    size_type Bucket_count,
    const Hash& Hash,
    const Key& Key,
    const Allocator& Al);

template <class InputIterator>
unordered_multiset(
    InputIterator First,
    InputIterator Last,
    size_type Bucket_count = N0,
    const Hash& Hash = Hash(),
    const Comp& Comp = Comp(),
    const Allocator& Al = Alloc());
```

### <a name="parameters"></a>Parâmetros

*InputIterator*\
O tipo de iterador.

*&*\
O objeto de alocador a ser armazenado.

*Às*\
O objeto de função de comparação a ser armazenado.

*Tralha*\
O objeto de função de hash a ser armazenado.

*Bucket_count*\
O número mínimo de buckets.

*Certo*\
O contêiner a ser copiado.

*IList*\
A initializer_list da qual copiar.

### <a name="remarks"></a>Comentários

O primeiro construtor Especifica uma cópia da sequência controlada pela *direita*. O segundo construtor especifica uma sequência controlada vazia. O terceiro construtor insere a sequência de valores do elemento `[First, Last)`. O quarto construtor Especifica uma cópia da sequência movendo-se para a *direita*.

Todos os construtores também inicializam vários valores armazenados. Para o construtor de cópia, os valores são obtidos da *direita*. Caso contrário:

O número mínimo de buckets é o argumento *Bucket_count*, se presente; caso contrário, é um valor padrão descrito aqui como o valor definido pela implementação `N0` .

O objeto de função de hash é o *hash*de argumento, se presente; caso contrário, é `Hash()` .

O objeto de função de comparação é o argumento *comp*, se presente; caso contrário, é `Comp()` .

O objeto de alocador é o argumento *Al*, se presente; caso contrário, é `Alloc()` .

## <a name="unordered_multisetvalue_type"></a><a name="value_type"></a> unordered_multiset:: value_type

O tipo de um elemento.

```cpp
typedef Key value_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve um elemento da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// std__unordered_set__unordered_multiset_value_type.cpp
// compile with: /EHsc
#include <unordered_set>
#include <iostream>

typedef std::unordered_multiset<char> Myset;
int main()
{
    Myset c1;

    c1.insert('a');
    c1.insert('b');
    c1.insert('c');

    // display contents "[c] [b] [a]"
    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    // add a value and reinspect
    Myset::key_type key = 'd';
    Myset::value_type val = key;
    c1.insert(val);

    for (Myset::const_iterator it = c1.begin();
        it != c1.end(); ++it)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;

    return (0);
}
```

```Output
[c] [b] [a]
[d] [c] [b] [a]
```

## <a name="see-also"></a>Confira também

[<unordered_set>](../standard-library/unordered-set.md)\
[Recipientes](./stl-containers.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
