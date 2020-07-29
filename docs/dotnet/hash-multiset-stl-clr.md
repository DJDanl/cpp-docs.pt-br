---
title: hash_multiset (STL/CLR)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- cliext::hash_multiset
- cliext::hash_multiset::begin
- cliext::hash_multiset::bucket_count
- cliext::hash_multiset::clear
- cliext::hash_multiset::const_iterator
- cliext::hash_multiset::const_reference
- cliext::hash_multiset::const_reverse_iterator
- cliext::hash_multiset::count
- cliext::hash_multiset::difference_type
- cliext::hash_multiset::empty
- cliext::hash_multiset::end
- cliext::hash_multiset::equal_range
- cliext::hash_multiset::erase
- cliext::hash_multiset::find
- cliext::hash_multiset::generic_container
- cliext::hash_multiset::generic_iterator
- cliext::hash_multiset::generic_reverse_iterator
- cliext::hash_multiset::generic_value
- cliext::hash_multiset::hash_delegate
- cliext::hash_multiset::hash_multiset
- cliext::hash_multiset::hasher
- cliext::hash_multiset::insert
- cliext::hash_multiset::iterator
- cliext::hash_multiset::key_comp
- cliext::hash_multiset::key_compare
- cliext::hash_multiset::key_type
- cliext::hash_multiset::load_factor
- cliext::hash_multiset::lower_bound
- cliext::hash_multiset::make_value
- cliext::hash_multiset::max_load_factor
- cliext::hash_multiset::operator=
- cliext::hash_multiset::rbegin
- cliext::hash_multiset::reference
- cliext::hash_multiset::rehash
- cliext::hash_multiset::rend
- cliext::hash_multiset::reverse_iterator
- cliext::hash_multiset::size
- cliext::hash_multiset::size_type
- cliext::hash_multiset::swap
- cliext::hash_multiset::to_array
- cliext::hash_multiset::upper_bound
- cliext::hash_multiset::value_comp
- cliext::hash_multiset::value_compare
- cliext::hash_multiset::value_type
helpviewer_keywords:
- <cliext/hash_set> header [STL/CLR]
- hash_multiset class [STL/CLR]
- <hash_set> header [STL/CLR]
- begin member [STL/CLR]
- bucket_count member [STL/CLR]
- clear member [STL/CLR]
- const_iterator member [STL/CLR]
- const_reference member [STL/CLR]
- const_reverse_iterator member [STL/CLR]
- count member [STL/CLR]
- difference_type member [STL/CLR]
- empty member [STL/CLR]
- end member [STL/CLR]
- equal_range member [STL/CLR]
- erase member [STL/CLR]
- find member [STL/CLR]
- generic_container member [STL/CLR]
- generic_iterator member [STL/CLR]
- generic_reverse_iterator member [STL/CLR]
- generic_value member [STL/CLR]
- hash_delegate member [STL/CLR]
- hash_multiset member [STL/CLR]
- hasher member [STL/CLR]
- insert member [STL/CLR]
- iterator member [STL/CLR]
- key_comp member [STL/CLR]
- key_compare member [STL/CLR]
- key_type member [STL/CLR]
- load_factor member [STL/CLR]
- lower_bound member [STL/CLR]
- make_value member [STL/CLR]
- max_load_factor member [STL/CLR]
- operator= member [STL/CLR]
- rbegin member [STL/CLR]
- reference member [STL/CLR]
- rehash member [STL/CLR]
- rend member [STL/CLR]
- reverse_iterator member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- swap member [STL/CLR]
- to_array member [STL/CLR]
- upper_bound member [STL/CLR]
- value_comp member [STL/CLR]
- value_compare member [STL/CLR]
- value_type member [STL/CLR]
ms.assetid: 8462bd21-6829-4dd3-ac81-c42d6fdf92f0
ms.openlocfilehash: 8f7858628b16f6ed2364a78186685fabb6d578ea
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221387"
---
# <a name="hash_multiset-stlclr"></a>hash_multiset (STL/CLR)

A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tem acesso bidirecional. Você usa o contêiner `hash_multiset` para gerenciar uma sequência de elementos como uma tabela de hash, cada entrada de tabela que armazena uma lista vinculada bidirecional de nós e cada nó armazenando um elemento. O valor de cada elemento é usado como uma chave para ordenar a sequência.

Na descrição abaixo, `GValue` é o mesmo que `GKey` , por sua vez, é o mesmo que a *chave* , a menos que o último seja um tipo ref, nesse caso é `Key^` .

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Key>
    ref class hash_multiset
        :   public
        System::ICloneable,
        System::Collections::IEnumerable,
        System::Collections::ICollection,
        System::Collections::Generic::IEnumerable<GValue>,
        System::Collections::Generic::ICollection<GValue>,
        System::Collections::Generic::IList<GValue>,
        Microsoft::VisualC::StlClr::IHash<Gkey, GValue>
    { ..... };
```

### <a name="parameters"></a>parâmetros

*Chave*<br/>
O tipo do componente de chave de um elemento na sequência controlada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<cliext/hash_set>

**Namespace:** cliext

## <a name="declarations"></a>Declarações

|Definição de tipo|Descrição|
|---------------------|-----------------|
|[hash_multiset::const_iterator (STL/CLR)](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|
|[hash_multiset::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|
|[hash_multiset::const_reverse_iterator (STL/CLR)](#const_reverse_iterator)|O tipo de um iterador reverso de constante para a sequência controlada.|
|[hash_multiset::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância (possivelmente assinada) entre dois elementos.|
|[hash_multiset::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o contêiner.|
|[hash_multiset::generic_iterator (STL/CLR)](#generic_iterator)|O tipo de um iterador para a interface genérica para o contêiner.|
|[hash_multiset::generic_reverse_iterator (STL/CLR)](#generic_reverse_iterator)|O tipo de um iterador reverso para a interface genérica para o contêiner.|
|[hash_multiset::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o contêiner.|
|[hash_multiset::hasher (STL/CLR)](#hasher)|O delegado de hash para uma chave.|
|[hash_multiset::iterator (STL/CLR)](#iterator)|O tipo de um iterador para a sequência controlada.|
|[hash_multiset::key_compare (STL/CLR)](#key_compare)|O delegado de ordenação para duas chaves.|
|[hash_multiset::key_type (STL/CLR)](#key_type)|O tipo de uma chave de classificação.|
|[hash_multiset::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|
|[hash_multiset::reverse_iterator (STL/CLR)](#reverse_iterator)|O tipo de um iterador inverso para a sequência controlada.|
|[hash_multiset::size_type (STL/CLR)](#size_type)|O tipo de uma distância (não negativa) entre dois elementos.|
|[hash_multiset::value_compare (STL/CLR)](#value_compare)|O delegado de ordenação para dois valores de elemento.|
|[hash_multiset::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|

|Função membro|Descrição|
|---------------------|-----------------|
|[hash_multiset::begin (STL/CLR)](#begin)|Designa o início da sequência controlada.|
|[hash_multiset::bucket_count (STL/CLR)](#bucket_count)|Conta o número de buckets.|
|[hash_multiset::clear (STL/CLR)](#clear)|Remove todos os elementos.|
|[hash_multiset::count (STL/CLR)](#count)|Conta os elementos que correspondem a uma chave especificada.|
|[hash_multiset::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|
|[hash_multiset::end (STL/CLR)](#end)|Designa o fim da sequência controlada.|
|[hash_multiset::equal_range (STL/CLR)](#equal_range)|Localiza o intervalo que corresponde a uma chave especificada.|
|[hash_multiset::erase (STL/CLR)](#erase)|Remove os elementos em posições especificadas.|
|[hash_multiset::find (STL/CLR)](#find)|Localiza um elemento que corresponde a uma chave especificada.|
|[hash_multiset::hash_delegate (STL/CLR)](#hash_delegate)|Copia o delegado de hash para uma chave.|
|[hash_multiset::hash_multiset (STL/CLR)](#hash_multiset)|Constrói um objeto contêiner.|
|[hash_multiset::insert (STL/CLR)](#insert)|Adiciona elementos.|
|[hash_multiset::key_comp (STL/CLR)](#key_comp)|Copia o delegado de ordenação de duas chaves.|
|[hash_multiset::load_factor (STL/CLR)](#load_factor)|Conta a média de elementos por bucket.|
|[hash_multiset::lower_bound (STL/CLR)](#lower_bound)|Localiza o início do intervalo que corresponde a uma chave especificada.|
|[hash_multiset::make_value (STL/CLR)](#make_value)|Constrói um objeto de valor.|
|[hash_multiset::max_load_factor (STL/CLR)](#max_load_factor)|Obtém ou define o máximo de elementos por bucket.|
|[hash_multiset::rbegin (STL/CLR)](#rbegin)|Designa o início da sequência controlada invertida.|
|[hash_multiset::rehash (STL/CLR)](#rehash)|Recria a tabela de hash.|
|[hash_multiset::rend (STL/CLR)](#rend)|Designa o fim da sequência controlada invertida.|
|[hash_multiset::size (STL/CLR)](#size)|Conta o número de elementos.|
|[hash_multiset::swap (STL/CLR)](#swap)|Alterna o conteúdo de dois contêineres.|
|[hash_multiset::to_array (STL/CLR)](#to_array)|Copia a sequência controlada em uma nova matriz.|
|[hash_multiset::upper_bound (STL/CLR)](#upper_bound)|Localiza o fim do intervalo que corresponde a uma chave especificada.|
|[hash_multiset::value_comp (STL/CLR)](#value_comp)|Copia o delegado de ordenação para dois valores de elemento.|

|Operador|Descrição|
|--------------|-----------------|
|[hash_multiset::operator= (STL/CLR)](#op)|Substitui a sequência controlada.|

## <a name="interfaces"></a>Interfaces

|Interface|Descrição|
|---------------|-----------------|
|<xref:System.ICloneable>|Duplicar um objeto.|
|<xref:System.Collections.IEnumerable>|Sequência por meio de elementos.|
|<xref:System.Collections.ICollection>|Manter grupo de elementos.|
|<xref:System.Collections.Generic.IEnumerable%601>|Sequenciar por meio de elementos tipados.|
|<xref:System.Collections.Generic.ICollection%601>|Manter grupo de elementos tipados.|
|IHash\<Key, Value>|Manter contêiner genérico.|

## <a name="remarks"></a>Comentários

O objeto aloca e libera o armazenamento para a sequência que ele controla como nós individuais em uma lista vinculada bidirecional. Para agilizar o acesso, o objeto também mantém uma matriz de comprimento variável de ponteiros na lista (a tabela de hash), gerenciando efetivamente a lista inteira como uma sequência de sublistas ou buckets. Ele insere elementos em um Bucket que ele mantém ordenado alterando os links entre os nós, nunca copiando o conteúdo de um nó para outro. Isso significa que você pode inserir e remover elementos livremente sem perturbar os elementos restantes.

O objeto ordena cada bucket que ele controla chamando um objeto delegado armazenado do tipo [hash_set:: key_compare (STL/CLR)](../dotnet/hash-set-key-compare-stl-clr.md). Você pode especificar o objeto delegado armazenado ao construir o hash_set; Se você não especificar nenhum objeto delegado, o padrão será a comparação `operator<=(key_type, key_type)` .

Você acessa o objeto delegado armazenado chamando a função de membro [hash_set:: key_comp (STL/CLR)](../dotnet/hash-set-key-comp-stl-clr.md) `()` . Esse objeto delegado deve definir a ordenação equivalente entre as chaves do tipo [hash_set:: KEY_TYPE (STL/CLR)](../dotnet/hash-set-key-type-stl-clr.md). Isso significa que, para quaisquer duas chaves `X` e `Y` :

`key_comp()(X, Y)`Retorna o mesmo resultado booliano em cada chamada.

Se `key_comp()(X, Y) && key_comp()(Y, X)` for true, será `X` `Y` dito que deve haver uma ordenação equivalente.

Qualquer regra de ordenação que se comporta `operator<=(key_type, key_type)` como `operator>=(key_type, key_type)` ou `operator==(key_type, key_type)` define a ordenação eqivalent.

Observe que o contêiner garante que apenas os elementos cujas chaves tenham uma ordenação equivalente (e qual hash para o mesmo valor inteiro) sejam adjacentes em um Bucket. Ao contrário da classe de modelo [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md), um objeto de classe de modelo `hash_multiset` não exige que as chaves para todos os elementos sejam exclusivas. (Duas ou mais chaves podem ter uma ordenação equivalente.)

O objeto determina qual Bucket deve conter uma determinada chave de ordenação chamando um objeto delegado armazenado do tipo [hash_set:: Hasher (STL/CLR)](../dotnet/hash-set-hasher-stl-clr.md). Você acessa esse objeto armazenado chamando a função de membro [hash_set:: hash_delegate (STL/CLR)](../dotnet/hash-set-hash-delegate-stl-clr.md) `()` para obter um valor inteiro que depende do valor da chave. Você pode especificar o objeto delegado armazenado ao construir o hash_set; Se você não especificar nenhum objeto delegado, o padrão será a função `System::Object::hash_value(key_type)` . Isso significa, para quaisquer chaves `X` e `Y` :

`hash_delegate()(X)`Retorna o mesmo resultado inteiro em cada chamada.

Se `X` e `Y` tiver uma ordenação equivalente, `hash_delegate()(X)` deverá retornar o mesmo resultado inteiro que `hash_delegate()(Y)` .

Cada elemento serve como uma chave e um valor. A sequência é representada de uma maneira que permite pesquisa, inserção e remoção de um elemento arbitrário com várias operações que são independentes do número de elementos na sequência (tempo constante), pelo menos no melhor dos casos. Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.

No entanto, se os valores com hash não forem distribuídos uniformemente, uma tabela de hash poderá ser regenerada. No extremo, para uma função de hash que sempre retorna o mesmo valor--Lookup, a inserção e a remoção são proporcionais ao número de elementos na sequência (tempo linear). O contêiner tenta escolher uma função de hash razoável, o tamanho médio do Bucket e o tamanho da tabela de hash (número total de buckets), mas você pode substituir qualquer ou todas essas opções. Consulte, por exemplo, as funções [hash_set:: max_load_factor (STL/CLR)](../dotnet/hash-set-max-load-factor-stl-clr.md) e [hash_set:: rehash (STL/CLR)](../dotnet/hash-set-rehash-stl-clr.md).

Um hash_multiset dá suporte a iteradores bidirecionais, o que significa que você pode passar para elementos adjacentes, dado um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde ao iterador retornado por [hash_multiset:: End (STL/CLR)](../dotnet/hash-multiset-end-stl-clr.md) `()` . Você pode decrementar esse iterador para alcançar o último elemento na sequência controlada, se presente. Você pode incrementar um hash_multiset iterador para alcançar o nó principal e ele será comparado igual a `end()` . Mas não é possível desreferenciar o iterador retornado pelo `end()` .

Observe que você não pode fazer referência a um elemento hash_multiset diretamente dado sua posição numérica, que requer um iterador de acesso aleatório.

Um iterador hash_multiset armazena um identificador para seu nó hash_multiset associado, que, por sua vez, armazena um identificador em seu contêiner associado. Você pode usar iteradores somente com seus objetos de contêiner associados. Um iterador de hash_multiset permanece válido, desde que seu nó de hash_multiset associado esteja associado a alguns hash_multiset. Além disso, um iterador válido é dereferencable--você pode usá-lo para acessar ou alterar o valor do elemento que ele designa--desde que ele não seja igual a `end()` .

Apagar ou remover um elemento chama o destruidor para seu valor armazenado. A destruição do contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma ref class garante que nenhum elemento sobreviver além o contêiner. No entanto, observe que um contêiner de identificadores *não* destrói seus elementos.

## <a name="members"></a>Membros

## <a name="hash_multisetbegin-stlclr"></a><a name="begin"></a>hash_multiset:: Begin (STL/CLR)

Designa o início da sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator begin();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador bidirecional que designa o primeiro elemento da sequência controlada ou apenas além do final de uma sequência vazia. Use-o para obter um iterador que designa o início `current` da sequência controlada, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_begin.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first two items
    Myhash_multiset::iterator it = c1.begin();
    System::Console::WriteLine("*begin() = {0}", *it);
    System::Console::WriteLine("*++begin() = {0}", *++it);
    return (0);
    }
```

```Output
a b c
*begin() = a
*++begin() = b
```

## <a name="hash_multisetbucket_count-stlclr"></a><a name="bucket_count"></a>hash_multiset:: bucket_count (STL/CLR)

Conta o número de buckets.

### <a name="syntax"></a>Sintaxe

```cpp
int bucket_count();
```

### <a name="remarks"></a>Comentários

As funções de membro retornam o número atual de buckets. Você o usa para determinar o tamanho da tabela de hash.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_bucket_count.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect current parameters
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    System::Console::WriteLine();

    // change max_load_factor and redisplay
    c1.max_load_factor(0.25f);
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    System::Console::WriteLine();

    // rehash and redisplay
    c1.rehash(100);
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    return (0);
    }
```

```Output
a b c
bucket_count() = 16
load_factor() = 0.1875
max_load_factor() = 4

bucket_count() = 16
load_factor() = 0.1875
max_load_factor() = 0.25

bucket_count() = 128
load_factor() = 0.0234375
max_load_factor() = 0.25
```

## <a name="hash_multisetclear-stlclr"></a><a name="clear"></a>hash_multiset:: Clear (STL/CLR)

Remove todos os elementos.

### <a name="syntax"></a>Sintaxe

```cpp
void clear();
```

### <a name="remarks"></a>Comentários

A função de membro efetivamente chama [hash_multiset:: Erase (STL/CLR)](../dotnet/hash-multiset-erase-stl-clr.md) `(` [hash_multiset:: Begin (STL/CLR)](../dotnet/hash-multiset-begin-stl-clr.md) `(),` [hash_multiset:: End (STL/CLR)](../dotnet/hash-multiset-end-stl-clr.md) `())` . Você o usa para garantir que a sequência controlada esteja vazia.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_clear.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // clear the container and reinspect
    c1.clear();
    System::Console::WriteLine("size() = {0}", c1.size());

    // add elements and clear again
    c1.insert(L'a');
    c1.insert(L'b');

    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    c1.clear();
    System::Console::WriteLine("size() = {0}", c1.size());
    return (0);
    }
```

```Output
a b c
size() = 0
a b
size() = 0
```

## <a name="hash_multisetconst_iterator-stlclr"></a><a name="const_iterator"></a>hash_multiset:: const_iterator (STL/CLR)

O tipo de um iterador de constante para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T2 const_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T2` que pode servir como um iterador bidirecional constante para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_const_iterator.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c"
    Myhash_multiset::const_iterator cit = c1.begin();
    for (; cit != c1.end(); ++cit)
        System::Console::Write("{0} ", *cit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="hash_multisetconst_reference-stlclr"></a><a name="const_reference"></a>hash_multiset:: const_reference (STL/CLR)

O tipo de uma referência de constante para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% const_reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência constante para um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_const_reference.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    Myhash_multiset::const_iterator cit = c1.begin();
    for (; cit != c1.end(); ++cit)
        {   // get a const reference to an element
        Myhash_multiset::const_reference cref = *cit;
        System::Console::Write("{0} ", cref);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="hash_multisetconst_reverse_iterator-stlclr"></a><a name="const_reverse_iterator"></a>hash_multiset:: const_reverse_iterator (STL/CLR)

O tipo de um iterador reverso constante para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T4 const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T4` que pode servir como um iterador reverso constante para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_const_reverse_iterator.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c" reversed
    Myhash_multiset::const_reverse_iterator crit = c1.rbegin();
    for (; crit != c1.rend(); ++crit)
        System::Console::Write("{0} ", *crit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
```

## <a name="hash_multisetcount-stlclr"></a><a name="count"></a>hash_multiset:: Count (STL/CLR)

Localiza o número de elementos que correspondem a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
size_type count(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função member retorna o número de elementos na sequência controlada que têm uma ordenação equivalente com a *chave*. Usado para determinar o número de elementos que estão na sequência controlada no momento e que correspondem a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_count.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("count(L'A') = {0}", c1.count(L'A'));
    System::Console::WriteLine("count(L'b') = {0}", c1.count(L'b'));
    System::Console::WriteLine("count(L'C') = {0}", c1.count(L'C'));
    return (0);
    }
```

```Output
a b c
count(L'A') = 0
count(L'b') = 1
count(L'C') = 0
```

## <a name="hash_multisetdifference_type-stlclr"></a><a name="difference_type"></a>hash_multiset::d ifference_type (STL/CLR)

Os tipos de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int difference_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos possivelmente negativo.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_difference_type.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // compute positive difference
    Myhash_multiset::difference_type diff = 0;
    for (Myhash_multiset::iterator it = c1.begin(); it != c1.end(); ++it)
        ++diff;
    System::Console::WriteLine("end()-begin() = {0}", diff);

    // compute negative difference
    diff = 0;
    for (Myhash_multiset::iterator it = c1.end(); it != c1.begin(); --it)
        --diff;
    System::Console::WriteLine("begin()-end() = {0}", diff);
    return (0);
    }
```

```Output
a b c
end()-begin() = 3
begin()-end() = -3
```

## <a name="hash_multisetempty-stlclr"></a><a name="empty"></a>hash_multiset:: Empty (STL/CLR)

Testa se nenhum elemento está presente.

### <a name="syntax"></a>Sintaxe

```cpp
bool empty();
```

### <a name="remarks"></a>Comentários

A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [hash_multiset:: Size (STL/CLR)](../dotnet/hash-multiset-size-stl-clr.md) `() == 0` . Você o usa para testar se o hash_multiset está vazio.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_empty.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine("size() = {0}", c1.size());
    System::Console::WriteLine("empty() = {0}", c1.empty());

    // clear the container and reinspect
    c1.clear();
    System::Console::WriteLine("size() = {0}", c1.size());
    System::Console::WriteLine("empty() = {0}", c1.empty());
    return (0);
    }
```

```Output
a b c
size() = 3
empty() = False
size() = 0
empty() = True
```

## <a name="hash_multisetend-stlclr"></a><a name="end"></a>hash_multiset:: End (STL/CLR)

Designa o fim da sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator end();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador bidirecional que aponta apenas além do fim da sequência controlada. Você o usa para obter um iterador que designa o final da sequência controlada; seu status não será alterado se o comprimento da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_end.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect last two items
    Myhash_multiset::iterator it = c1.end();
    --it;
    System::Console::WriteLine("*-- --end() = {0}", *--it);
    System::Console::WriteLine("*--end() = {0}", *++it);
    return (0);
    }
```

```Output
a b c
*-- --end() = b
*--end() = c
```

## <a name="hash_multisetequal_range-stlclr"></a><a name="equal_range"></a>hash_multiset:: equal_range (STL/CLR)

Localiza o intervalo que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
cliext::pair<iterator, iterator> equal_range(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função membro retorna um par de iteradores `cliext::pair<iterator, iterator>(` [hash_multiset:: lower_bound (STL/CLR)](../dotnet/hash-multiset-lower-bound-stl-clr.md) `(key),` [hash_multiset:: upper_bound (STL/CLR)](../dotnet/hash-multiset-upper-bound-stl-clr.md) `(key))` . Você o usa para determinar o intervalo de elementos atualmente na sequência controlada que corresponde a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_equal_range.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
typedef Myhash_multiset::pair_iter_iter Pairii;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // display results of failed search
    Pairii pair1 = c1.equal_range(L'x');
    System::Console::WriteLine("equal_range(L'x') empty = {0}",
        pair1.first == pair1.second);

    // display results of successful search
    pair1 = c1.equal_range(L'b');
    for (; pair1.first != pair1.second; ++pair1.first)
        System::Console::Write("{0} ", *pair1.first);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
equal_range(L'x') empty = True
b
```

## <a name="hash_multiseterase-stlclr"></a><a name="erase"></a>hash_multiset:: Erase (STL/CLR)

Remove os elementos em posições especificadas.

### <a name="syntax"></a>Sintaxe

```cpp
iterator erase(iterator where);
iterator erase(iterator first, iterator last);
bool erase(key_type key)
```

#### <a name="parameters"></a>parâmetros

*first*<br/>
Início do intervalo a ser apagado.

*chave*<br/>
Valor de chave a ser apagado.

*last*<br/>
Fim do intervalo a ser apagado.

*where*<br/>
Elemento a ser apagado.

### <a name="remarks"></a>Comentários

A primeira função de membro remove o elemento da sequência controlada apontada por *Where*e retorna um iterador que designa o primeiro elemento restante além do elemento removido, ou [hash_multiset:: End (STL/CLR)](../dotnet/hash-multiset-end-stl-clr.md) `()` se nenhum elemento desse tipo existir. Você o usa para remover um único elemento.

A segunda função de membro remove os elementos da sequência controlada no intervalo [ `first` , `last` ), e retorna um iterador que designa o primeiro elemento restante além de todos os elementos removidos, ou `end()` se nenhum elemento desse tipo existir. Você o usa para remover zero ou mais elementos contíguos.

A terceira função de membro remove qualquer elemento da sequência controlada cuja chave tem ordenação equivalente para a *chave*e retorna uma contagem do número de elementos removidos. Você o usa para remover e contar todos os elementos que correspondem a uma chave especificada.

Cada eliminação de elemento leva tempo proporcional ao logaritmo do número de elementos na sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_erase.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // erase an element and reinspect
    System::Console::WriteLine("erase(begin()) = {0}",
        *c1.erase(c1.begin()));

    // add elements and display " b c d e"
    c1.insert(L'd');
    c1.insert(L'e');
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // erase all but end
    Myhash_multiset::iterator it = c1.end();
    System::Console::WriteLine("erase(begin(), end()-1) = {0}",
        *c1.erase(c1.begin(), --it));
    System::Console::WriteLine("size() = {0}", c1.size());
    return (0);
    }
```

```Output
a b c
erase(begin()) = b
b c d e
erase(begin(), end()-1) = e
size() = 1
```

## <a name="hash_multisetfind-stlclr"></a><a name="find"></a>hash_multiset:: find (STL/CLR)

Localiza um elemento que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator find(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

Se pelo menos um elemento na sequência controlada tiver uma ordenação equivalente com *chave*, a função de membro retornará um iterador que designa um desses elementos; caso contrário, ele retornará [hash_multiset:: End (STL/CLR)](../dotnet/hash-multiset-end-stl-clr.md) `()` . Você o usa para localizar um elemento atualmente na sequência controlada que corresponde a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_find.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("find {0} = {1}",
        L'A', c1.find(L'A') != c1.end());
    System::Console::WriteLine("find {0} = {1}",
        L'b', *c1.find(L'b'));
    System::Console::WriteLine("find {0} = {1}",
        L'C', c1.find(L'C') != c1.end());
    return (0);
    }
```

```Output
a b c
find A = False
find b = b
find C = False
```

## <a name="hash_multisetgeneric_container-stlclr"></a><a name="generic_container"></a>hash_multiset:: generic_container (STL/CLR)

O tipo da interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::
    IHash<GKey, GValue>
    generic_container;
```

### <a name="remarks"></a>Comentários

O tipo descreve a interface genérica para esta classe de contêiner de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_generic_container.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    Myhash_multiset::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify generic and display original
    gc1->insert(L'd');
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify original and display generic
    c1.insert(L'e');
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
a b c d
a b c d e
```

## <a name="hash_multisetgeneric_iterator-stlclr"></a><a name="generic_iterator"></a>hash_multiset:: generic_iterator (STL/CLR)

O tipo de um iterador para uso com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::Generic::
    ContainerBidirectionalIterator<generic_value>
    generic_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um iterador genérico que pode ser usado com a interface genérica para essa classe de contêiner de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_generic_iterator.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    Myhash_multiset::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // get an element and display it
    Myhash_multiset::generic_iterator gcit = gc1->begin();
    Myhash_multiset::generic_value gcval = *gcit;
    System::Console::WriteLine("{0} ", gcval);
    return (0);
    }
```

```Output
a b c
a b c
a
```

## <a name="hash_multisetgeneric_reverse_iterator-stlclr"></a><a name="generic_reverse_iterator"></a>hash_multiset:: generic_reverse_iterator (STL/CLR)

O tipo de um iterador reverso para uso com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::Generic::
    ReverseRandomAccessIterator<generic_value>
    generic_reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um iterador reverso genérico que pode ser usado com a interface genérica para essa classe de contêiner de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_generic_reverse_iterator.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    Myhash_multiset::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // get an element and display it
    Myhash_multiset::generic_reverse_iterator gcit = gc1->rbegin();
    Myhash_multiset::generic_value gcval = *gcit;
    System::Console::WriteLine("{0} ", gcval);
    return (0);
    }
```

```Output
a b c
a b c
c
```

## <a name="hash_multisetgeneric_value-stlclr"></a><a name="generic_value"></a>hash_multiset:: generic_value (STL/CLR)

O tipo de um elemento a ser usado com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef GValue generic_value;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo `GValue` que descreve o valor do elemento armazenado para uso com a interface genérica para essa classe de contêiner de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_generic_value.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    Myhash_multiset::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // get an element and display it
    Myhash_multiset::generic_iterator gcit = gc1->begin();
    Myhash_multiset::generic_value gcval = *gcit;
    System::Console::WriteLine("{0} ", gcval);
    return (0);
    }
```

```Output
a b c
a b c
a
```

## <a name="hash_multisethash_delegate-stlclr"></a><a name="hash_delegate"></a>hash_multiset:: hash_delegate (STL/CLR)

Localiza um elemento que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
hasher^ hash_delegate();
```

### <a name="remarks"></a>Comentários

A função member retorna o delegado usado para converter um valor de chave em um inteiro. Você o usa para fazer hash de uma chave.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_hash_delegate.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    Myhash_multiset::hasher^ myhash = c1.hash_delegate();

    System::Console::WriteLine("hash(L'a') = {0}", myhash(L'a'));
    System::Console::WriteLine("hash(L'b') = {0}", myhash(L'b'));
    return (0);
    }
```

```Output
hash(L'a') = 1616896120
hash(L'b') = 570892832
```

## <a name="hash_multisethash_multiset-stlclr"></a><a name="hash_multiset"></a>hash_multiset:: hash_multiset (STL/CLR)

Constrói um objeto contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
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

#### <a name="parameters"></a>parâmetros

*first*<br/>
Início do intervalo a ser inserido.

*hashfn*<br/>
Função de hash para mapear chaves para buckets.

*last*<br/>
Fim do intervalo a ser inserido.

*Pred*<br/>
Predicado de ordenação para a sequência controlada.

*Certo*<br/>
Objeto ou intervalo a inserir.

### <a name="remarks"></a>Comentários

O construtor:

`hash_multiset();`

Inicializa a sequência controlada sem elementos, com o predicado de ordenação padrão `key_compare()` e com a função de hash padrão. Você o usa para especificar uma sequência controlada inicial vazia, com o predicado de ordenação padrão e a função de hash.

O construtor:

`explicit hash_multiset(key_compare^ pred);`

Inicializa a sequência controlada sem elementos, com o predicado de ordenação *Pred*e com a função de hash padrão. Você o usa para especificar uma sequência controlada inicial vazia, com o predicado de ordenação especificado e a função de hash padrão.

O construtor:

`hash_multiset(key_compare^ pred, hasher^ hashfn);`

Inicializa a sequência controlada sem elementos, com o predicado de ordenação *Pred*e com a função de hash *hashfn*. Você o usa para especificar uma sequência controlada inicial vazia, com o predicado de ordenação e a função de hash especificados.

O construtor:

`hash_multiset(hash_multiset<Key>% right);`

Inicializa a sequência controlada com a sequência [ `right.begin()` , `right.end()` ), com o predicado de ordenação padrão e com a função de hash padrão. Você o usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto hash_multiset *direita*, com o predicado de ordenação padrão e a função de hash.

O construtor:

`hash_multiset(hash_multiset<Key>^ right);`

Inicializa a sequência controlada com a sequência [ `right->begin()` , `right->end()` ), com o predicado de ordenação padrão e com a função de hash padrão. Você o usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto hash_multiset *direita*, com o predicado de ordenação padrão e a função de hash.

O construtor:

`template<typename InIter> hash_multiset(InIter first, InIter last);`

Inicializa a sequência controlada com a sequência [ `first` , `last` ), com o predicado de ordenação padrão e com a função de hash padrão. Você o usa para tornar a sequência controlada uma cópia de outra sequência, com o predicado de ordenação padrão e a função de hash.

O construtor:

`template<typename InIter> hash_multiset(InIter first, InIter last, key_compare^ pred);`

Inicializa a sequência controlada com a sequência [ `first` , `last` ), com o predicado de ordenação *Pred*e com a função de hash padrão. Você o usa para tornar a sequência controlada uma cópia de outra sequência, com o predicado de ordenação especificado e a função de hash padrão.

O construtor:

`template<typename InIter> hash_multiset(InIter first, InIter last, key_compare^ pred, hasher^ hashfn);`

Inicializa a sequência controlada com a sequência [ `first` , `last` ), com o predicado de ordenação *Pred*e com a função de hash *hashfn*. Você o usa para tornar a sequência controlada uma cópia de outra sequência, com o predicado de ordenação e a função de hash especificados.

O construtor:

`hash_multiset(System::Collections::Generic::IEnumerable<Key>^ right);`

Inicializa a sequência controlada com a sequência designada pelo enumerador *à direita*, com o predicado de ordenação padrão e com a função de hash padrão. Você o usa para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado de ordenação padrão e a função de hash.

O construtor:

`hash_multiset(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred);`

Inicializa a sequência controlada com a sequência designada pelo enumerador *à direita*, com o predicado de ordenação *Pred*e com a função de hash padrão. Você o usa para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado de ordenação especificado e a função de hash padrão.

O construtor:

`hash_multiset(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred, hasher^ hashfn);`

Inicializa a sequência controlada com a sequência designada pelo enumerador *à direita*, com o predicado de ordenação *Pred*e com a função de hash *hashfn*. Você o usa para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado de ordenação e a função de hash especificados.

### <a name="example"></a>Exemplo

```cpp
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
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an ordering rule
    Myhash_multiset c2 = cliext::greater_equal<wchar_t>();
    System::Console::WriteLine("size() = {0}", c2.size());

    c2.insert(c1.begin(), c1.end());
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an ordering rule and hash function
    Myhash_multiset c2h(cliext::greater_equal<wchar_t>(),
        gcnew Myhash_multiset::hasher(&myfun));
    System::Console::WriteLine("size() = {0}", c2h.size());

    c2h.insert(c1.begin(), c1.end());
    for each (wchar_t elem in c2h)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine();

    // construct with an iterator range
    Myhash_multiset c3(c1.begin(), c1.end());
    for each (wchar_t elem in c3)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an iterator range and an ordering rule
    Myhash_multiset c4(c1.begin(), c1.end(),
        cliext::greater_equal<wchar_t>());
    for each (wchar_t elem in c4)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an iterator range and an ordering rule and hash function
    Myhash_multiset c4h(c1.begin(), c1.end(),
        cliext::greater_equal<wchar_t>(),
        gcnew Myhash_multiset::hasher(&myfun));
    for each (wchar_t elem in c4h)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine();

    // construct with an enumeration
    Myhash_multiset c5(   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);
    for each (wchar_t elem in c5)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an enumeration and an ordering rule
    Myhash_multiset c6(   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3,
            cliext::greater_equal<wchar_t>());
    for each (wchar_t elem in c6)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an enumeration and an ordering rule and hash function
    Myhash_multiset c6h(   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3,
            cliext::greater_equal<wchar_t>(),
                gcnew Myhash_multiset::hasher(&myfun));
    for each (wchar_t elem in c6h)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine();

    // construct from a generic container
    Myhash_multiset c7(c4);
    for each (wchar_t elem in c7)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct by copying another container
    Myhash_multiset c8(%c3);
    for each (wchar_t elem in c8)
        System::Console::Write("{0} ", elem);
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

## <a name="hash_multisethasher-stlclr"></a><a name="hasher"></a>hash_multiset:: Hasher (STL/CLR)

O delegado de hash para uma chave.

### <a name="syntax"></a>Sintaxe

```cpp
Microsoft::VisualC::StlClr::UnaryDelegate<GKey, int>
    hasher;
```

### <a name="remarks"></a>Comentários

O tipo descreve um delegado que converte um valor de chave em um inteiro.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_hasher.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    Myhash_multiset::hasher^ myhash = c1.hash_delegate();

    System::Console::WriteLine("hash(L'a') = {0}", myhash(L'a'));
    System::Console::WriteLine("hash(L'b') = {0}", myhash(L'b'));
    return (0);
    }
```

```Output
hash(L'a') = 1616896120
hash(L'b') = 570892832
```

## <a name="hash_multisetinsert-stlclr"></a><a name="insert"></a>hash_multiset:: Insert (STL/CLR)

Adiciona elementos.

### <a name="syntax"></a>Sintaxe

```cpp
iterator insert(value_type val);
iterator insert(iterator where, value_type val);
template<typename InIter>
    void insert(InIter first, InIter last);
void insert(System::Collections::Generic::IEnumerable<value_type>^ right);
```

#### <a name="parameters"></a>parâmetros

*first*<br/>
Início do intervalo a ser inserido.

*last*<br/>
Fim do intervalo a ser inserido.

*Certo*<br/>
Enumeração a ser inserida.

*Val*<br/>
Valor de chave a ser inserido.

*where*<br/>
Onde o contêiner deve ser inserido (somente dica).

### <a name="remarks"></a>Comentários

Cada uma das funções de membro insere uma sequência especificada pelos operandos restantes.

A primeira função de membro insere um elemento com valor *Val*e retorna um iterador que designa o elemento recém-inserido. Você o usa para inserir um único elemento.

A segunda função de membro insere um elemento com valor *Val*, usando *Where* como uma dica (para melhorar o desempenho) e retorna um iterador que designa o elemento recém-inserido. Você o usa para inserir um único elemento que pode ser adjacente a um elemento que você conhece.

A terceira função de membro insere a sequência [ `first` , `last` ). Você o usa para inserir zero ou mais elementos copiados de outra sequência.

A quarta função de membro insere a sequência designada à *direita*. Você o usa para inserir uma sequência descrita por um enumerador.

Cada inserção de elemento leva tempo proporcional ao logaritmo do número de elementos na sequência controlada. A inserção pode ocorrer em tempo constante amortizado, no entanto, dada uma dica que designa um elemento adjacente ao ponto de inserção.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_insert.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // insert a single value, unique and duplicate
    System::Console::WriteLine("insert(L'x') = {0}",
        *c1.insert(L'x'));

    System::Console::WriteLine("insert(L'b') = {0}",
        *c1.insert(L'b'));

    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // insert a single value with hint
    System::Console::WriteLine("insert(begin(), L'y') = {0}",
        *c1.insert(c1.begin(), L'y'));
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // insert an iterator range
    Myhash_multiset c2;
    Myhash_multiset::iterator it = c1.end();
    c2.insert(c1.begin(), --it);
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // insert an enumeration
    Myhash_multiset c3;
    c3.insert(   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);
    for each (wchar_t elem in c3)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
insert(L'x') = x
insert(L'b') = b
a b b c x
insert(begin(), L'y') = y
a b b c x y
a b b c x
a b b c x y
```

## <a name="hash_multisetiterator-stlclr"></a><a name="iterator"></a>hash_multiset:: iterador (STL/CLR)

O tipo de um iterador para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T1 iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T1` que pode servir como um iterador bidirecional para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_iterator.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c"
    Myhash_multiset::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        System::Console::Write("{0} ", *it);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="hash_multisetkey_comp-stlclr"></a><a name="key_comp"></a>hash_multiset:: key_comp (STL/CLR)

Copia o delegado de ordenação de duas chaves.

### <a name="syntax"></a>Sintaxe

```cpp
key_compare^key_comp();
```

### <a name="remarks"></a>Comentários

A função member retorna o delegado de ordenação usado para ordenar a sequência controlada. Use-o para comparar duas chaves.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_key_comp.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    Myhash_multiset::key_compare^ kcomp = c1.key_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        kcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        kcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        kcomp(L'b', L'a'));
    System::Console::WriteLine();

    // test a different ordering rule
    Myhash_multiset c2 = cliext::greater<wchar_t>();
    kcomp = c2.key_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        kcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        kcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        kcomp(L'b', L'a'));
    return (0);
    }
```

```Output
compare(L'a', L'a') = True
compare(L'a', L'b') = True
compare(L'b', L'a') = False

compare(L'a', L'a') = False
compare(L'a', L'b') = False
compare(L'b', L'a') = True
```

## <a name="hash_multisetkey_compare-stlclr"></a><a name="key_compare"></a>hash_multiset:: key_compare (STL/CLR)

O delegado de ordenação para duas chaves.

### <a name="syntax"></a>Sintaxe

```cpp
Microsoft::VisualC::StlClr::BinaryDelegate<GKey, GKey, bool>
    key_compare;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o delegado que determina a ordenação de seus argumentos de chave.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_key_compare.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    Myhash_multiset::key_compare^ kcomp = c1.key_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        kcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        kcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        kcomp(L'b', L'a'));
    System::Console::WriteLine();

    // test a different ordering rule
    Myhash_multiset c2 = cliext::greater<wchar_t>();
    kcomp = c2.key_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        kcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        kcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        kcomp(L'b', L'a'));
    return (0);
    }
```

```Output
compare(L'a', L'a') = True
compare(L'a', L'b') = True
compare(L'b', L'a') = False

compare(L'a', L'a') = False
compare(L'a', L'b') = False
compare(L'b', L'a') = True
```

## <a name="hash_multisetkey_type-stlclr"></a><a name="key_type"></a>hash_multiset:: key_type (STL/CLR)

O tipo de uma chave de classificação.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a *chave*de parâmetro do modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_key_type.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c" using key_type
    for (Myhash_multiset::iterator it = c1.begin(); it != c1.end(); ++it)
        {   // store element in key_type object
        Myhash_multiset::key_type val = *it;

        System::Console::Write("{0} ", val);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="hash_multisetload_factor-stlclr"></a><a name="load_factor"></a>hash_multiset:: load_factor (STL/CLR)

Conta a média de elementos por bucket.

### <a name="syntax"></a>Sintaxe

```cpp
float load_factor();
```

### <a name="remarks"></a>Comentários

A função membro retorna `(float)` [hash_multiset:: Size (STL/CLR)](../dotnet/hash-multiset-size-stl-clr.md) `() /` [hash_multiset:: bucket_count (STL/CLR)](../dotnet/hash-multiset-bucket-count-stl-clr.md) `()` . Você o usa para determinar o tamanho médio do Bucket.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_load_factor.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect current parameters
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    System::Console::WriteLine();

    // change max_load_factor and redisplay
    c1.max_load_factor(0.25f);
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    System::Console::WriteLine();

    // rehash and redisplay
    c1.rehash(100);
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    return (0);
    }
```

```Output
a b c
bucket_count() = 16
load_factor() = 0.1875
max_load_factor() = 4

bucket_count() = 16
load_factor() = 0.1875
max_load_factor() = 0.25

bucket_count() = 128
load_factor() = 0.0234375
max_load_factor() = 0.25
```

## <a name="hash_multisetlower_bound-stlclr"></a><a name="lower_bound"></a>hash_multiset:: lower_bound (STL/CLR)

Localiza o início do intervalo que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator lower_bound(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função de membro determina o primeiro elemento `X` na sequência controlada que faz hash para o mesmo Bucket como *chave* e tem ordenação equivalente para *chave*. Se nenhum elemento desse tipo existir, ele retornará [hash_multiset:: End (STL/CLR)](../dotnet/hash-multiset-end-stl-clr.md) `()` ; caso contrário, ele retornará um iterador que designa `X` . Você o usa para localizar o início de uma sequência de elementos atualmente na sequência controlada que corresponde a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_lower_bound.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("lower_bound(L'x')==end() = {0}",
        c1.lower_bound(L'x') == c1.end());

    System::Console::WriteLine("*lower_bound(L'a') = {0}",
        *c1.lower_bound(L'a'));
    System::Console::WriteLine("*lower_bound(L'b') = {0}",
        *c1.lower_bound(L'b'));
    return (0);
    }
```

```Output
a b c
lower_bound(L'x')==end() = True
*lower_bound(L'a') = a
*lower_bound(L'b') = b
```

## <a name="hash_multisetmake_value-stlclr"></a><a name="make_value"></a>hash_multiset:: make_value (STL/CLR)

Constrói um objeto de valor.

### <a name="syntax"></a>Sintaxe

```cpp
static value_type make_value(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
Valor de chave a ser usado.

### <a name="remarks"></a>Comentários

A função membro retorna um `value_type` objeto cuja chave é *chave*. Você o usa para compor um objeto adequado para uso com várias outras funções de membro.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_make_value.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(Myhash_multiset::make_value(L'a'));
    c1.insert(Myhash_multiset::make_value(L'b'));
    c1.insert(Myhash_multiset::make_value(L'c'));

    // display contents " a b c"
    for each (Myhash_multiset::value_type elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="hash_multisetmax_load_factor-stlclr"></a><a name="max_load_factor"></a>hash_multiset:: max_load_factor (STL/CLR)

Obtém ou define o máximo de elementos por bucket.

### <a name="syntax"></a>Sintaxe

```cpp
float max_load_factor();
void max_load_factor(float new_factor);
```

#### <a name="parameters"></a>parâmetros

*new_factor*<br/>
Novo fator de carga máximo a ser armazenado.

### <a name="remarks"></a>Comentários

A primeira função de membro retorna o fator de carga máximo armazenado atual. Você o usa para determinar o tamanho médio máximo de buckets.

A segunda função de membro substitui o fator de carga máximo da loja por *new_factor*. Nenhum rehash automático ocorrerá até uma inserção subsequente.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_max_load_factor.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect current parameters
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    System::Console::WriteLine();

    // change max_load_factor and redisplay
    c1.max_load_factor(0.25f);
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    System::Console::WriteLine();

    // rehash and redisplay
    c1.rehash(100);
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    return (0);
    }
```

```Output
a b c
bucket_count() = 16
load_factor() = 0.1875
max_load_factor() = 4

bucket_count() = 16
load_factor() = 0.1875
max_load_factor() = 0.25

bucket_count() = 128
load_factor() = 0.0234375
max_load_factor() = 0.25
```

## <a name="hash_multisetoperator-stlclr"></a><a name="op"></a>hash_multiset:: Operator = (STL/CLR)

Substitui a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
hash_multiset<Key>% operator=(hash_multiset<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*Certo*<br/>
O contêiner a ser copiado.

### <a name="remarks"></a>Comentários

O operador membro copia *diretamente* para o objeto e, em seguida, retorna **`*this`** . Você o usa para substituir a sequência controlada por uma cópia da sequência controlada *à direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_operator_as.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c"
    for each (Myhash_multiset::value_type elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    Myhash_multiset c2;
    c2 = c1;
// display contents " a b c"
    for each (Myhash_multiset::value_type elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
```

## <a name="hash_multisetrbegin-stlclr"></a><a name="rbegin"></a>hash_multiset:: rbegin (STL/CLR)

Designa o início da sequência controlada invertida.

### <a name="syntax"></a>Sintaxe

```cpp
reverse_iterator rbegin();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador reverso que designa o último elemento da sequência controlada ou apenas além do início de uma sequência vazia. Portanto, ele designa o `beginning` da sequência invertida. Use-o para obter um iterador que designa o início `current` da sequência controlada que é vista na ordem inversa, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_rbegin.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first two items in reversed sequence
    Myhash_multiset::reverse_iterator rit = c1.rbegin();
    System::Console::WriteLine("*rbegin() = {0}", *rit);
    System::Console::WriteLine("*++rbegin() = {0}", *++rit);
    return (0);
    }
```

```Output
a b c
*rbegin() = c
*++rbegin() = b
```

## <a name="hash_multisetreference-stlclr"></a><a name="reference"></a>hash_multiset:: Reference (STL/CLR)

O tipo de uma referência para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência a um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_reference.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    Myhash_multiset::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        {   // get a reference to an element
        Myhash_multiset::reference ref = *it;
        System::Console::Write("{0} ", ref);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="hash_multisetrehash-stlclr"></a><a name="rehash"></a>hash_multiset:: rehash (STL/CLR)

Recria a tabela de hash.

### <a name="syntax"></a>Sintaxe

```cpp
void rehash();
```

### <a name="remarks"></a>Comentários

A função de membro recria a tabela de hash, garantindo que [hash_multiset:: load_factor (STL/CLR)](../dotnet/hash-multiset-load-factor-stl-clr.md) `() <=` [hash_multiset:: max_load_factor (STL/CLR)](../dotnet/hash-multiset-max-load-factor-stl-clr.md). Caso contrário, a tabela de hash aumentará em tamanho apenas conforme necessário após uma inserção. (Ela nunca diminui automaticamente em tamanho.) Você o usa para ajustar o tamanho da tabela de hash.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_rehash.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect current parameters
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    System::Console::WriteLine();

    // change max_load_factor and redisplay
    c1.max_load_factor(0.25f);
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    System::Console::WriteLine();

    // rehash and redisplay
    c1.rehash(100);
    System::Console::WriteLine("bucket_count() = {0}", c1.bucket_count());
    System::Console::WriteLine("load_factor() = {0}", c1.load_factor());
    System::Console::WriteLine("max_load_factor() = {0}",
        c1.max_load_factor());
    return (0);
    }
```

```Output
a b c
bucket_count() = 16
load_factor() = 0.1875
max_load_factor() = 4

bucket_count() = 16
load_factor() = 0.1875
max_load_factor() = 0.25

bucket_count() = 128
load_factor() = 0.0234375
max_load_factor() = 0.25
```

## <a name="hash_multisetrend-stlclr"></a><a name="rend"></a>hash_multiset:: rend (STL/CLR)

Designa o fim da sequência controlada invertida.

### <a name="syntax"></a>Sintaxe

```cpp
reverse_iterator rend();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador reverso que aponta apenas além do início da sequência controlada. Portanto, ele designa o `end` da sequência invertida. Use-o para obter um iterador que designa o fim `current` da sequência controlada vista na ordem inversa, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_rend.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first two items
    Myhash_multiset::reverse_iterator rit = c1.rend();
    --rit;
    System::Console::WriteLine("*-- --rend() = {0}", *--rit);
    System::Console::WriteLine("*--rend() = {0}", *++rit);
    return (0);
    }
```

```Output
a b c
*-- --rend() = b
*--rend() = a
```

## <a name="hash_multisetreverse_iterator-stlclr"></a><a name="reverse_iterator"></a>hash_multiset:: reverse_iterator (STL/CLR)

O tipo de um iterador inverso para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T3 reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T3` que pode servir como um iterador reverso para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_reverse_iterator.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c" reversed
    Myhash_multiset::reverse_iterator rit = c1.rbegin();
    for (; rit != c1.rend(); ++rit)
        System::Console::Write("{0} ", *rit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
```

## <a name="hash_multisetsize-stlclr"></a><a name="size"></a>hash_multiset:: Size (STL/CLR)

Conta o número de elementos.

### <a name="syntax"></a>Sintaxe

```cpp
size_type size();
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência controlada. Você o usa para determinar o número de elementos atualmente na sequência controlada. Se tudo o que você se importa é se a sequência tem tamanho diferente de zero, consulte [hash_multiset:: Empty (STL/CLR)](../dotnet/hash-multiset-empty-stl-clr.md) `()` .

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_size.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine("size() = {0} starting with 3", c1.size());

    // clear the container and reinspect
    c1.clear();
    System::Console::WriteLine("size() = {0} after clearing", c1.size());

    // add elements and clear again
    c1.insert(L'a');
    c1.insert(L'b');
    System::Console::WriteLine("size() = {0} after adding 2", c1.size());
    return (0);
    }
```

```Output
a b c
size() = 3 starting with 3
size() = 0 after clearing
size() = 2 after adding 2
```

## <a name="hash_multisetsize_type-stlclr"></a><a name="size_type"></a>hash_multiset:: size_type (STL/CLR)

O tipo de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int size_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos não negativos.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_size_type.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // compute positive difference
    Myhash_multiset::size_type diff = 0;
    for (Myhash_multiset::iterator it = c1.begin(); it != c1.end(); ++it)
        ++diff;
    System::Console::WriteLine("end()-begin() = {0}", diff);
    return (0);
    }
```

```Output
a b c
end()-begin() = 3
```

## <a name="hash_multisetswap-stlclr"></a><a name="swap"></a>hash_multiset:: swap (STL/CLR)

Alterna o conteúdo de dois contêineres.

### <a name="syntax"></a>Sintaxe

```cpp
void swap(hash_multiset<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*Certo*<br/>
Contêiner com o qual trocar conteúdos.

### <a name="remarks"></a>Comentários

A função membro troca as sequências controladas entre **`this`** e *à direita*. Ele faz isso em constante tempo e não lança nenhuma exceção. Você o usa como uma maneira rápida de trocar o conteúdo de dois contêineres.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_swap.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct another container with repetition of values
    Myhash_multiset c2;
    c2.insert(L'd');
    c2.insert(L'e');
    c2.insert(L'f');
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // swap and redisplay
    c1.swap(c2);
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
d e f
d e f
a b c
```

## <a name="hash_multisetto_array-stlclr"></a><a name="to_array"></a>hash_multiset:: to_array (STL/CLR)

Copia a sequência controlada em uma nova matriz.

### <a name="syntax"></a>Sintaxe

```cpp
cli::array<value_type>^ to_array();
```

### <a name="remarks"></a>Comentários

A função membro retorna uma matriz que contém a sequência controlada. Você o usa para obter uma cópia da sequência controlada na forma de matriz.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_to_array.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // copy the container and modify it
    cli::array<wchar_t>^ a1 = c1.to_array();

    c1.insert(L'd');
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // display the earlier array copy
    for each (wchar_t elem in a1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c d
a b c
```

## <a name="hash_multisetupper_bound-stlclr"></a><a name="upper_bound"></a>hash_multiset:: upper_bound (STL/CLR)

Localiza o fim do intervalo que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator upper_bound(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função membro determina o último elemento `X` na sequência controlada que faz hash para o mesmo Bucket como *chave* e tem ordenação equivalente para *chave*. Se esse elemento não existir, ou se `X` for o último elemento na sequência controlada, ele retornará [hash_multiset:: End (STL/CLR)](../dotnet/hash-multiset-end-stl-clr.md) `()` ; caso contrário, ele retornará um iterador que designa o primeiro elemento além `X` . Você o usa para localizar o final de uma sequência de elementos atualmente na sequência controlada que corresponde a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_upper_bound.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("upper_bound(L'x')==end() = {0}",
        c1.upper_bound(L'x') == c1.end());

    System::Console::WriteLine("*upper_bound(L'a') = {0}",
        *c1.upper_bound(L'a'));
    System::Console::WriteLine("*upper_bound(L'b') = {0}",
        *c1.upper_bound(L'b'));
    return (0);
    }
```

```Output
a b c
upper_bound(L'x')==end() = True
*upper_bound(L'a') = b
*upper_bound(L'b') = c
```

## <a name="hash_multisetvalue_comp-stlclr"></a><a name="value_comp"></a>hash_multiset:: value_comp (STL/CLR)

Copia o delegado de ordenação para dois valores de elemento.

### <a name="syntax"></a>Sintaxe

```cpp
value_compare^ value_comp();
```

### <a name="remarks"></a>Comentários

A função member retorna o delegado de ordenação usado para ordenar a sequência controlada. Você o usa para comparar dois valores de elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_value_comp.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    Myhash_multiset::value_compare^ kcomp = c1.value_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        kcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        kcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        kcomp(L'b', L'a'));
    System::Console::WriteLine();
    return (0);
    }
```

```Output
compare(L'a', L'a') = True
compare(L'a', L'b') = True
compare(L'b', L'a') = False
```

## <a name="hash_multisetvalue_compare-stlclr"></a><a name="value_compare"></a>hash_multiset:: value_compare (STL/CLR)

O delegado de ordenação para dois valores de elemento.

### <a name="syntax"></a>Sintaxe

```cpp
Microsoft::VisualC::StlClr::BinaryDelegate<generic_value, generic_value, bool>
    value_compare;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o delegado que determina a ordenação de seus argumentos de valor.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_value_compare.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    Myhash_multiset::value_compare^ kcomp = c1.value_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        kcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        kcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        kcomp(L'b', L'a'));
    System::Console::WriteLine();
    return (0);
    }
```

```Output
compare(L'a', L'a') = True
compare(L'a', L'b') = True
compare(L'b', L'a') = False
```

## <a name="hash_multisetvalue_type-stlclr"></a><a name="value_type"></a>hash_multiset:: value_type (STL/CLR)

O tipo de um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef generic_value value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `generic_value`.

### <a name="example"></a>Exemplo

```cpp
// cliext_hash_multiset_value_type.cpp
// compile with: /clr
#include <cliext/hash_set>

typedef cliext::hash_multiset<wchar_t> Myhash_multiset;
int main()
    {
    Myhash_multiset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

    // display contents " a b c" using value_type
    for (Myhash_multiset::iterator it = c1.begin(); it != c1.end(); ++it)
        {   // store element in value_type object
        Myhash_multiset::value_type val = *it;

        System::Console::Write("{0} ", val);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```
