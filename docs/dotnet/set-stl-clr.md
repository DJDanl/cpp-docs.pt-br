---
title: set (STL/CLR)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- cliext::set
- cliext::set::begin
- cliext::set::clear
- cliext::set::const_iterator
- cliext::set::const_reference
- cliext::set::const_reverse_iterator
- cliext::set::count
- cliext::set::difference_type
- cliext::set::empty
- cliext::set::end
- cliext::set::equal_range
- cliext::set::erase
- cliext::set::find
- cliext::set::generic_container
- cliext::set::generic_iterator
- cliext::set::generic_reverse_iterator
- cliext::set::generic_value
- cliext::set::insert
- cliext::set::iterator
- cliext::set::key_comp
- cliext::set::key_compare
- cliext::set::key_type
- cliext::set::lower_bound
- cliext::set::make_value
- cliext::set::operator=
- cliext::set::rbegin
- cliext::set::reference
- cliext::set::rend
- cliext::set::reverse_iterator
- cliext::set::set
- cliext::set::size
- cliext::set::size_type
- cliext::set::swap
- cliext::set::to_array
- cliext::set::upper_bound
- cliext::set::value_comp
- cliext::set::value_compare
- cliext::set::value_type
helpviewer_keywords:
- <cliext/set> header [STL/CLR]
- <set> header [STL/CLR]
- set class [STL/CLR]
- operator!= (set) member [STL/CLR]
- operator< (set) member [STL/CLR]
- operator<= (set) member [STL/CLR]
- operator== (set) member [STL/CLR]
- operator> (set) member [STL/CLR]
- operator>= (set) member [STL/CLR]
- begin member [STL/CLR]
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
- insert member [STL/CLR]
- iterator member [STL/CLR]
- key_comp member [STL/CLR]
- key_compare member [STL/CLR]
- key_type member [STL/CLR]
- lower_bound member [STL/CLR]
- make_value member [STL/CLR]
- operator= member [STL/CLR]
- rbegin member [STL/CLR]
- reference member [STL/CLR]
- rend member [STL/CLR]
- reverse_iterator member [STL/CLR]
- set member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- swap member [STL/CLR]
- to_array member [STL/CLR]
- upper_bound member [STL/CLR]
- value_comp member [STL/CLR]
- value_compare member [STL/CLR]
- value_type member [STL/CLR]
ms.assetid: 27d3628c-741a-43a7-bef1-5085536f679e
ms.openlocfilehash: 76f67ad900e975ff084f5760e6830c6a5d229e86
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214875"
---
# <a name="set-stlclr"></a>set (STL/CLR)

A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tem acesso bidirecional. Você usa o contêiner `set` para gerenciar uma sequência de elementos como uma árvore ordenada com balanceamento de nós (aproximadamente), cada um armazenando um elemento.

Na descrição abaixo, `GValue` é o mesmo que `GKey` , por sua vez, é o mesmo que a *chave* , a menos que o último seja um tipo ref, nesse caso é `Key^` .

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Key>
    ref class set
        :   public
        System::ICloneable,
        System::Collections::IEnumerable,
        System::Collections::ICollection,
        System::Collections::Generic::IEnumerable<GValue>,
        System::Collections::Generic::ICollection<GValue>,
        System::Collections::Generic::IList<GValue>,
        Microsoft::VisualC::StlClr::ITree<Gkey, GValue>
    { ..... };
```

### <a name="parameters"></a>parâmetros

*Chave*<br/>
O tipo do componente de chave de um elemento na sequência controlada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<cliext/set>

**Namespace:** cliext

## <a name="declarations"></a>Declarações

|Definição de tipo|Descrição|
|---------------------|-----------------|
|[set::const_iterator (STL/CLR)](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|
|[set::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|
|[set::const_reverse_iterator (STL/CLR)](#const_reverse_iterator)|O tipo de um iterador reverso de constante para a sequência controlada.|
|[set::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância (possivelmente assinada) entre dois elementos.|
|[set::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o contêiner.|
|[set::generic_iterator (STL/CLR)](#generic_iterator)|O tipo de um iterador para a interface genérica para o contêiner.|
|[set::generic_reverse_iterator (STL/CLR)](#generic_reverse_iterator)|O tipo de um iterador reverso para a interface genérica para o contêiner.|
|[set::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o contêiner.|
|[set::iterator (STL/CLR)](#iterator)|O tipo de um iterador para a sequência controlada.|
|[set::key_compare (STL/CLR)](#key_compare)|O delegado de ordenação para duas chaves.|
|[set::key_type (STL/CLR)](#key_type)|O tipo de uma chave de classificação.|
|[set::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|
|[set::reverse_iterator (STL/CLR)](#reverse_iterator)|O tipo de um iterador inverso para a sequência controlada.|
|[set::size_type (STL/CLR)](#size_type)|O tipo de uma distância (não negativa) entre dois elementos.|
|[set::value_compare (STL/CLR)](#value_compare)|O delegado de ordenação para dois valores de elemento.|
|[set::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|

|Função membro|Descrição|
|---------------------|-----------------|
|[set::begin (STL/CLR)](#begin)|Designa o início da sequência controlada.|
|[set::clear (STL/CLR)](#clear)|Remove todos os elementos.|
|[set::count (STL/CLR)](#count)|Conta os elementos que correspondem a uma chave especificada.|
|[set::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|
|[set::end (STL/CLR)](#end)|Designa o fim da sequência controlada.|
|[set::equal_range (STL/CLR)](#equal_range)|Localiza o intervalo que corresponde a uma chave especificada.|
|[set::erase (STL/CLR)](#erase)|Remove os elementos em posições especificadas.|
|[set::find (STL/CLR)](#find)|Localiza um elemento que corresponde a uma chave especificada.|
|[set::insert (STL/CLR)](#insert)|Adiciona elementos.|
|[set::key_comp (STL/CLR)](#key_comp)|Copia o delegado de ordenação de duas chaves.|
|[set::lower_bound (STL/CLR)](#lower_bound)|Localiza o início do intervalo que corresponde a uma chave especificada.|
|[set::make_value (STL/CLR)](#make_value)|Constrói um objeto de valor.|
|[set::rbegin (STL/CLR)](#rbegin)|Designa o início da sequência controlada invertida.|
|[set::rend (STL/CLR)](#rend)|Designa o fim da sequência controlada invertida.|
|[set::set (STL/CLR)](#set)|Constrói um objeto contêiner.|
|[set::size (STL/CLR)](#size)|Conta o número de elementos.|
|[set::swap (STL/CLR)](#swap)|Alterna o conteúdo de dois contêineres.|
|[set::to_array (STL/CLR)](#to_array)|Copia a sequência controlada em uma nova matriz.|
|[set::upper_bound (STL/CLR)](#upper_bound)|Localiza o fim do intervalo que corresponde a uma chave especificada.|
|[set::value_comp (STL/CLR)](#value_comp)|Copia o delegado de ordenação para dois valores de elemento.|

|Operador|Descrição|
|--------------|-----------------|
|[set::operator= (STL/CLR)](#op_as)|Substitui a sequência controlada.|
|[operador! = (conjunto) (STL/CLR)](#op_neq)|Determina se um `set` objeto não é igual a outro `set` objeto.|
|[operador< (conjunto) (STL/CLR)](#op_lt)|Determina se um `set` objeto é menor que outro `set` objeto.|
|[operador<= (conjunto) (STL/CLR)](#op_lteq)|Determina se um `set` objeto é menor ou igual a outro `set` objeto.|
|[operator== (set) (STL/CLR)](#op_eq)|Determina se um `set` objeto é igual a outro `set` objeto.|
|[operador> (conjunto) (STL/CLR)](#op_gt)|Determina se um `set` objeto é maior que outro `set` objeto.|
|[operador>= (conjunto) (STL/CLR)](#op_gteq)|Determina se um `set` objeto é maior ou igual a outro `set` objeto.|

## <a name="interfaces"></a>Interfaces

|Interface|Descrição|
|---------------|-----------------|
|<xref:System.ICloneable>|Duplicar um objeto.|
|<xref:System.Collections.IEnumerable>|Sequência por meio de elementos.|
|<xref:System.Collections.ICollection>|Manter grupo de elementos.|
|<xref:System.Collections.Generic.IEnumerable%601>|Sequenciar por meio de elementos tipados.|
|<xref:System.Collections.Generic.ICollection%601>|Manter grupo de elementos tipados.|
|ITree\<Key, Value>|Manter contêiner genérico.|

## <a name="remarks"></a>Comentários

O objeto aloca e libera o armazenamento para a sequência que ele controla como nós individuais. Ele insere elementos em uma árvore (quase) equilibrada que ele mantém ordenada alterando os links entre os nós, nunca copiando o conteúdo de um nó para outro. Isso significa que você pode inserir e remover elementos livremente sem perturbar os elementos restantes.

O objeto ordena a sequência que ele controla chamando um objeto delegado armazenado do tipo [set:: key_compare (STL/CLR)](../dotnet/set-key-compare-stl-clr.md). Você pode especificar o objeto delegado armazenado ao construir o conjunto; Se você não especificar nenhum objeto delegado, o padrão será a comparação `operator<(key_type, key_type)` . Você acessa esse objeto armazenado chamando o conjunto de funções de membro [:: key_comp (STL/CLR)](../dotnet/set-key-comp-stl-clr.md) `()` .

Esse objeto delegado deve impor uma ordenação fraca estrita em chaves do tipo [set:: KEY_TYPE (STL/CLR)](../dotnet/set-key-type-stl-clr.md). Isso significa que, para quaisquer duas chaves `X` e `Y` :

`key_comp()(X, Y)`Retorna o mesmo resultado booliano em cada chamada.

Se `key_comp()(X, Y)` for true, `key_comp()(Y, X)` deverá ser false.

Se `key_comp()(X, Y)` for true, `X` será considerado que deve ser ordenado antes `Y` .

Se `!key_comp()(X, Y) && !key_comp()(Y, X)` for true, será `X` `Y` dito que deve haver uma ordenação equivalente.

Para qualquer elemento `X` que precede `Y` na sequência controlada, `key_comp()(Y, X)` é false. (Para o objeto delegado padrão, as chaves nunca diminuem em valor.) Ao contrário do [conjunto](../dotnet/set-stl-clr.md)de classes de modelo, um objeto de classe de modelo `set` não exige que as chaves para todos os elementos sejam exclusivas. (Duas ou mais chaves podem ter uma ordenação equivalente.)

Cada elemento serve como um ey e um valor. A sequência é representada de uma maneira que permite a pesquisa, a inserção e a remoção de um elemento arbitrário com várias operações proporcionais ao logaritmo do número de elementos na sequência (tempo logarítmica). Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.

Um conjunto dá suporte a iteradores bidirecionais, o que significa que você pode percorrer elementos adjacentes, dado um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde ao iterador retornado por [set:: End (STL/CLR)](../dotnet/set-end-stl-clr.md) `()` . Você pode decrementar esse iterador para alcançar o último elemento na sequência controlada, se presente. Você pode incrementar um iterador de conjunto para alcançar o nó principal e ele será comparado igual a `end()` . Mas não é possível desreferenciar o iterador retornado pelo `end()` .

Observe que você não pode fazer referência a um elemento Set diretamente, dada sua posição numérica, que requer um iterador de acesso aleatório.

Um iterador Set armazena um identificador para seu nó de conjunto associado que, por sua vez, armazena um identificador para seu contêiner associado. Você pode usar iteradores somente com seus objetos de contêiner associados. Um iterador de conjunto permanece válido, desde que seu nó de conjunto associado esteja associado a algum conjunto. Além disso, um iterador válido é dereferencable--você pode usá-lo para acessar ou alterar o valor do elemento que ele designa--desde que ele não seja igual a `end()` .

Apagar ou remover um elemento chama o destruidor para seu valor armazenado. A destruição do contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma ref class garante que nenhum elemento sobreviver além o contêiner. No entanto, observe que um contêiner de identificadores *não* destrói seus elementos.

## <a name="members"></a>Membros

## <a name="setbegin-stlclr"></a><a name="begin"></a>Set:: Begin (STL/CLR)

Designa o início da sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator begin();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador bidirecional que designa o primeiro elemento da sequência controlada ou apenas além do final de uma sequência vazia. Use-o para obter um iterador que designa o início `current` da sequência controlada, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_begin.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// inspect first two items
    Myset::iterator it = c1.begin();
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

## <a name="setclear-stlclr"></a><a name="clear"></a>Set:: Clear (STL/CLR)

Remove todos os elementos.

### <a name="syntax"></a>Sintaxe

```cpp
void clear();
```

### <a name="remarks"></a>Comentários

A função de membro efetivamente chama [set:: Erase (STL/CLR)](../dotnet/set-erase-stl-clr.md) `(` [set:: Begin (STL/CLR)](../dotnet/set-begin-stl-clr.md) `(),` [set:: End (STL/CLR)](../dotnet/set-end-stl-clr.md) `())` . Você o usa para garantir que a sequência controlada esteja vazia.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_clear.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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

## <a name="setconst_iterator-stlclr"></a><a name="const_iterator"></a>definir:: const_iterator (STL/CLR)

O tipo de um iterador de constante para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T2 const_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T2` que pode servir como um iterador bidirecional constante para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_const_iterator.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    Myset::const_iterator cit = c1.begin();
    for (; cit != c1.end(); ++cit)
        System::Console::Write("{0} ", *cit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="setconst_reference-stlclr"></a><a name="const_reference"></a>definir:: const_reference (STL/CLR)

O tipo de uma referência de constante para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% const_reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência constante para um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_const_reference.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    Myset::const_iterator cit = c1.begin();
    for (; cit != c1.end(); ++cit)
        {   // get a const reference to an element
        Myset::const_reference cref = *cit;
        System::Console::Write("{0} ", cref);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="setconst_reverse_iterator-stlclr"></a><a name="const_reverse_iterator"></a>definir:: const_reverse_iterator (STL/CLR)

O tipo de um iterador reverso constante para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T4 const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T4` que pode servir como um iterador reverso constante para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_const_reverse_iterator.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c" reversed
    Myset::const_reverse_iterator crit = c1.rbegin();
    for (; crit != c1.rend(); ++crit)
        System::Console::Write("{0} ", *crit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
```

## <a name="setcount-stlclr"></a><a name="count"></a>Set:: Count (STL/CLR)

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
// cliext_set_count.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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

## <a name="setdifference_type-stlclr"></a><a name="difference_type"></a>conjunto::d ifference_type (STL/CLR)

Os tipos de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int difference_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos possivelmente negativo.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_difference_type.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// compute positive difference
    Myset::difference_type diff = 0;
    for (Myset::iterator it = c1.begin(); it != c1.end(); ++it)
        ++diff;
    System::Console::WriteLine("end()-begin() = {0}", diff);

// compute negative difference
    diff = 0;
    for (Myset::iterator it = c1.end(); it != c1.begin(); --it)
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

## <a name="setempty-stlclr"></a><a name="empty"></a>Set:: Empty (STL/CLR)

Testa se nenhum elemento está presente.

### <a name="syntax"></a>Sintaxe

```cpp
bool empty();
```

### <a name="remarks"></a>Comentários

A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [set:: Size (STL/CLR)](../dotnet/set-size-stl-clr.md) `() == 0` . Você o usa para testar se o conjunto está vazio.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_empty.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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

## <a name="setend-stlclr"></a><a name="end"></a>Set:: End (STL/CLR)

Designa o fim da sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator end();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador bidirecional que aponta apenas além do fim da sequência controlada. Você o usa para obter um iterador que designa o final da sequência controlada; seu status não será alterado se o comprimento da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_end.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// inspect last two items
    Myset::iterator it = c1.end();
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

## <a name="setequal_range-stlclr"></a><a name="equal_range"></a>definir:: equal_range (STL/CLR)

Localiza o intervalo que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
cliext::pair<iterator, iterator> equal_range(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função member retorna um par de iteradores `cliext::pair<iterator, iterator>(` [set:: lower_bound (STL/CLR)](../dotnet/set-lower-bound-stl-clr.md) `(key),` [set:: upper_bound (STL/CLR)](../dotnet/set-upper-bound-stl-clr.md) `(key))` . Você o usa para determinar o intervalo de elementos atualmente na sequência controlada que corresponde a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_equal_range.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
typedef Myset::pair_iter_iter Pairii;
int main()
    {
    Myset c1;
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

## <a name="seterase-stlclr"></a><a name="erase"></a>Set:: Erase (STL/CLR)

Remove os elementos em posições especificadas.

### <a name="syntax"></a>Sintaxe

```cpp
iterator erase(iterator where);
iterator erase(iterator first, iterator last);
size_type erase(key_type key)
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

A primeira função de membro remove o elemento da sequência controlada apontada por *Where*e retorna um iterador que designa o primeiro elemento restante além do elemento removido, ou [set:: End (STL/CLR)](../dotnet/set-end-stl-clr.md) `()` se nenhum elemento desse tipo existir. Você o usa para remover um único elemento.

A segunda função de membro remove os elementos da sequência controlada no intervalo [ `first` , `last` ), e retorna um iterador que designa o primeiro elemento restante além de todos os elementos removidos, ou `end()` se nenhum elemento desse tipo existir. Você o usa para remover zero ou mais elementos contíguos.

A terceira função de membro remove qualquer elemento da sequência controlada cuja chave tem ordenação equivalente para a *chave*e retorna uma contagem do número de elementos removidos. Você o usa para remover e contar todos os elementos que correspondem a uma chave especificada.

Cada eliminação de elemento leva tempo proporcional ao logaritmo do número de elementos na sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_erase.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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
    Myset::iterator it = c1.end();
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

## <a name="setfind-stlclr"></a><a name="find"></a>Set:: find (STL/CLR)

Localiza um elemento que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator find(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

Se pelo menos um elemento na sequência controlada tiver uma ordenação equivalente com *chave*, a função de membro retornará um iterador que designa um desses elementos; caso contrário, ele retornará [set:: End (STL/CLR)](../dotnet/set-end-stl-clr.md) `()` . Você o usa para localizar um elemento atualmente na sequência controlada que corresponde a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_find.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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

## <a name="setgeneric_container-stlclr"></a><a name="generic_container"></a>definir:: generic_container (STL/CLR)

O tipo da interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::
    ITree<GKey, GValue>
    generic_container;
```

### <a name="remarks"></a>Comentários

O tipo descreve a interface genérica para esta classe de contêiner de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_generic_container.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct a generic container
    Myset::generic_container^ gc1 = %c1;
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

## <a name="setgeneric_iterator-stlclr"></a><a name="generic_iterator"></a>definir:: generic_iterator (STL/CLR)

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
// cliext_set_generic_iterator.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct a generic container
    Myset::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// get an element and display it
    Myset::generic_iterator gcit = gc1->begin();
    Myset::generic_value gcval = *gcit;
    System::Console::WriteLine("{0} ", gcval);
    return (0);
    }
```

```Output
a b c
a b c
a
```

## <a name="setgeneric_reverse_iterator-stlclr"></a><a name="generic_reverse_iterator"></a>definir:: generic_reverse_iterator (STL/CLR)

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
// cliext_set_generic_reverse_iterator.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct a generic container
    Myset::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// get an element and display it
    Myset::generic_reverse_iterator gcit = gc1->rbegin();
    Myset::generic_value gcval = *gcit;
    System::Console::WriteLine("{0} ", gcval);
    return (0);
    }
```

```Output
a b c
a b c
c
```

## <a name="setgeneric_value-stlclr"></a><a name="generic_value"></a>definir:: generic_value (STL/CLR)

O tipo de um elemento a ser usado com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef GValue generic_value;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo `GValue` que descreve o valor do elemento armazenado para uso com a interface genérica para essa classe de contêiner de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_generic_value.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct a generic container
    Myset::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// get an element and display it
    Myset::generic_iterator gcit = gc1->begin();
    Myset::generic_value gcval = *gcit;
    System::Console::WriteLine("{0} ", gcval);
    return (0);
    }
```

```Output
a b c
a b c
a
```

## <a name="setinsert-stlclr"></a><a name="insert"></a>Set:: Insert (STL/CLR)

Adiciona elementos.

### <a name="syntax"></a>Sintaxe

```cpp
cliext::pair<iterator, bool> insert(value_type val);
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

A primeira função de membro tenta inserir um elemento com valor *Val*e retorna um par de valores `X` . Se `X.second` for true, `X.first` designa o elemento recém-inserido. caso contrário, `X.first` designa um elemento com ordenação equivalente que já existe e nenhum elemento novo é inserido. Você o usa para inserir um único elemento.

A segunda função de membro insere um elemento com valor *Val*, usando *Where* como uma dica (para melhorar o desempenho) e retorna um iterador que designa o elemento recém-inserido. Você o usa para inserir um único elemento que pode ser adjacente a um elemento que você conhece.

A terceira função de membro insere a sequência [ `first` , `last` ). Você o usa para inserir zero ou mais elementos copiados de outra sequência.

A quarta função de membro insere a sequência designada à *direita*. Você o usa para inserir uma sequência descrita por um enumerador.

Cada inserção de elemento leva tempo proporcional ao logaritmo do número de elementos na sequência controlada. A inserção pode ocorrer em tempo constante amortizado, no entanto, dada uma dica que designa um elemento adjacente ao ponto de inserção.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_insert.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
typedef Myset::pair_iter_bool Pairib;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// insert a single value, unique and duplicate
    Pairib pair1 = c1.insert(L'x');
    System::Console::WriteLine("insert(L'x') = [{0} {1}]",
        *pair1.first, pair1.second);

    pair1 = c1.insert(L'b');
    System::Console::WriteLine("insert(L'b') = [{0} {1}]",
        *pair1.first, pair1.second);

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
    Myset c2;
    Myset::iterator it = c1.end();
    c2.insert(c1.begin(), --it);
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// insert an enumeration
    Myset c3;
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
insert(L'x') = [x True]
insert(L'b') = [b False]
a b c x
insert(begin(), L'y') = y
a b c x y
a b c x
a b c x y
```

## <a name="setiterator-stlclr"></a><a name="iterator"></a>Set:: iterador (STL/CLR)

O tipo de um iterador para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T1 iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T1` que pode servir como um iterador bidirecional para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_iterator.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    Myset::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        System::Console::Write("{0} ", *it);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="setkey_comp-stlclr"></a><a name="key_comp"></a>definir:: key_comp (STL/CLR)

Copia o delegado de ordenação de duas chaves.

### <a name="syntax"></a>Sintaxe

```cpp
key_compare^key_comp();
```

### <a name="remarks"></a>Comentários

A função member retorna o delegado de ordenação usado para ordenar a sequência controlada. Use-o para comparar duas chaves.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_key_comp.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    Myset::key_compare^ kcomp = c1.key_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        kcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        kcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        kcomp(L'b', L'a'));
    System::Console::WriteLine();

// test a different ordering rule
    Myset c2 = cliext::greater<wchar_t>();
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
compare(L'a', L'a') = False
compare(L'a', L'b') = True
compare(L'b', L'a') = False

compare(L'a', L'a') = False
compare(L'a', L'b') = False
compare(L'b', L'a') = True
```

## <a name="setkey_compare-stlclr"></a><a name="key_compare"></a>definir:: key_compare (STL/CLR)

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
// cliext_set_key_compare.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    Myset::key_compare^ kcomp = c1.key_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        kcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        kcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        kcomp(L'b', L'a'));
    System::Console::WriteLine();

// test a different ordering rule
    Myset c2 = cliext::greater<wchar_t>();
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
compare(L'a', L'a') = False
compare(L'a', L'b') = True
compare(L'b', L'a') = False

compare(L'a', L'a') = False
compare(L'a', L'b') = False
compare(L'b', L'a') = True
```

## <a name="setkey_type-stlclr"></a><a name="key_type"></a>definir:: key_type (STL/CLR)

O tipo de uma chave de classificação.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a *chave*de parâmetro do modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_key_type.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c" using key_type
    for (Myset::iterator it = c1.begin(); it != c1.end(); ++it)
        {   // store element in key_type object
        Myset::key_type val = *it;

        System::Console::Write("{0} ", val);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="setlower_bound-stlclr"></a><a name="lower_bound"></a>definir:: lower_bound (STL/CLR)

Localiza o início do intervalo que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator lower_bound(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função membro determina o primeiro elemento `X` na sequência controlada que tem a ordenação equivalente para a *chave*. Se nenhum elemento desse tipo existir, ele retornará [set:: End (STL/CLR)](../dotnet/set-end-stl-clr.md) `()` ; caso contrário, ele retornará um iterador que designa `X` . Você o usa para localizar o início de uma sequência de elementos atualmente na sequência controlada que corresponde a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_lower_bound.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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

## <a name="setmake_value-stlclr"></a><a name="make_value"></a>definir:: make_value (STL/CLR)

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
// cliext_set_make_value.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(Myset::make_value(L'a'));
    c1.insert(Myset::make_value(L'b'));
    c1.insert(Myset::make_value(L'c'));

// display contents " a b c"
    for each (Myset::value_type elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="setoperator-stlclr"></a><a name="op_as"></a>Set:: Operator = (STL/CLR)

Substitui a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
set<Key>% operator=(set<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*Certo*<br/>
O contêiner a ser copiado.

### <a name="remarks"></a>Comentários

O operador membro copia *diretamente* para o objeto e, em seguida, retorna **`*this`** . Você o usa para substituir a sequência controlada por uma cópia da sequência controlada *à direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_operator_as.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (Myset::value_type elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myset c2;
    c2 = c1;
// display contents " a b c"
    for each (Myset::value_type elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
```

## <a name="setrbegin-stlclr"></a><a name="rbegin"></a>Set:: rbegin (STL/CLR)

Designa o início da sequência controlada invertida.

### <a name="syntax"></a>Sintaxe

```cpp
reverse_iterator rbegin();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador reverso que designa o último elemento da sequência controlada ou apenas além do início de uma sequência vazia. Portanto, ele designa o `beginning` da sequência invertida. Use-o para obter um iterador que designa o início `current` da sequência controlada que é vista na ordem inversa, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_rbegin.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// inspect first two items in reversed sequence
    Myset::reverse_iterator rit = c1.rbegin();
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

## <a name="setreference-stlclr"></a><a name="reference"></a>Set:: Reference (STL/CLR)

O tipo de uma referência para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência a um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_reference.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    Myset::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        {   // get a reference to an element
        Myset::reference ref = *it;
        System::Console::Write("{0} ", ref);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="setrend-stlclr"></a><a name="rend"></a>Set:: rend (STL/CLR)

Designa o fim da sequência controlada invertida.

### <a name="syntax"></a>Sintaxe

```cpp
reverse_iterator rend();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador reverso que aponta apenas além do início da sequência controlada. Portanto, ele designa o `end` da sequência invertida. Use-o para obter um iterador que designa o fim `current` da sequência controlada vista na ordem inversa, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_rend.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// inspect first two items
    Myset::reverse_iterator rit = c1.rend();
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

## <a name="setreverse_iterator-stlclr"></a><a name="reverse_iterator"></a>definir:: reverse_iterator (STL/CLR)

O tipo de um iterador inverso para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T3 reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T3` que pode servir como um iterador reverso para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_reverse_iterator.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c" reversed
    Myset::reverse_iterator rit = c1.rbegin();
    for (; rit != c1.rend(); ++rit)
        System::Console::Write("{0} ", *rit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
```

## <a name="setset-stlclr"></a><a name="set"></a>Set:: Set (STL/CLR)

Constrói um objeto contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
set();
explicit set(key_compare^ pred);
set(set<Key>% right);
set(set<Key>^ right);
template<typename InIter>
    setset(InIter first, InIter last);
template<typename InIter>
    set(InIter first, InIter last,
        key_compare^ pred);
set(System::Collections::Generic::IEnumerable<GValue>^ right);
set(System::Collections::Generic::IEnumerable<GValue>^ right,
    key_compare^ pred);
```

#### <a name="parameters"></a>parâmetros

*first*<br/>
Início do intervalo a ser inserido.

*last*<br/>
Fim do intervalo a ser inserido.

*Pred*<br/>
Predicado de ordenação para a sequência controlada.

*Certo*<br/>
Objeto ou intervalo a inserir.

### <a name="remarks"></a>Comentários

O construtor:

`set();`

Inicializa a sequência controlada sem elementos, com o predicado de ordenação padrão `key_compare()` . Você o usa para especificar uma sequência controlada inicial vazia, com o predicado de ordenação padrão.

O construtor:

`explicit set(key_compare^ pred);`

Inicializa a sequência controlada sem elementos, com o predicado de ordenação *Pred*. Você o usa para especificar uma sequência controlada inicial vazia, com o predicado de ordenação especificado.

O construtor:

`set(set<Key>% right);`

Inicializa a sequência controlada com a sequência [ `right.begin()` , `right.end()` ), com o predicado de ordenação padrão. Você o usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo *direito*Set Object, com o predicado de ordenação padrão.

O construtor:

`set(set<Key>^ right);`

Inicializa a sequência controlada com a sequência [ `right->begin()` , `right->end()` ), com o predicado de ordenação padrão. Você o usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo *direito*Set Object, com o predicado de ordenação padrão.

O construtor:

`template<typename InIter> set(InIter first, InIter last);`

Inicializa a sequência controlada com a sequência [ `first` , `last` ), com o predicado de ordenação padrão. Você o usa para tornar a sequência controlada uma cópia de outra sequência, com o predicado de ordenação padrão.

O construtor:

`template<typename InIter> set(InIter first, InIter last, key_compare^ pred);`

Inicializa a sequência controlada com a sequência [ `first` , `last` ), com o predicado de ordenação *Pred*. Você o usa para tornar a sequência controlada uma cópia de outra sequência, com o predicado de ordenação especificado.

O construtor:

`set(System::Collections::Generic::IEnumerable<Key>^ right);`

Inicializa a sequência controlada com a sequência designada pelo enumerador *à direita*, com o predicado de ordenação padrão. Você o usa para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado de ordenação padrão.

O construtor:

`set(System::Collections::Generic::IEnumerable<Key>^ right, key_compare^ pred);`

Inicializa a sequência controlada com a sequência designada pelo enumerador *à direita*, com o predicado de ordenação *Pred*. Você o usa para tornar a sequência controlada uma cópia de outra sequência descrita por um enumerador, com o predicado de ordenação especificado.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_construct.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
// construct an empty container
    Myset c1;
    System::Console::WriteLine("size() = {0}", c1.size());

    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct with an ordering rule
    Myset c2 = cliext::greater_equal<wchar_t>();
    System::Console::WriteLine("size() = {0}", c2.size());

    c2.insert(c1.begin(), c1.end());
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct with an iterator range
    Myset c3(c1.begin(), c1.end());
    for each (wchar_t elem in c3)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct with an iterator range and an ordering rule
    Myset c4(c1.begin(), c1.end(),
        cliext::greater_equal<wchar_t>());
    for each (wchar_t elem in c4)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct with an enumeration
    Myset c5(   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);
    for each (wchar_t elem in c5)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct with an enumeration and an ordering rule
    Myset c6(   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3,
            cliext::greater_equal<wchar_t>());
    for each (wchar_t elem in c6)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct from a generic container
    Myset c7(c4);
    for each (wchar_t elem in c7)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct by copying another container
    Myset c8(%c3);
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
c b a
a b c
c b a
a b c
c b a
c b a
a b c
```

## <a name="setsize-stlclr"></a><a name="size"></a>Set:: Size (STL/CLR)

Conta o número de elementos.

### <a name="syntax"></a>Sintaxe

```cpp
size_type size();
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência controlada. Você o usa para determinar o número de elementos atualmente na sequência controlada. Se tudo o que você se importa é se a sequência tem tamanho diferente de zero, consulte [set:: Empty (STL/CLR)](../dotnet/set-empty-stl-clr.md) `()` .

### <a name="example"></a>Exemplo

```cpp
// cliext_set_size.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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

## <a name="setsize_type-stlclr"></a><a name="size_type"></a>definir:: size_type (STL/CLR)

O tipo de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int size_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos não negativos.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_size_type.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// compute positive difference
    Myset::size_type diff = 0;
    for (Myset::iterator it = c1.begin(); it != c1.end(); ++it)
        ++diff;
    System::Console::WriteLine("end()-begin() = {0}", diff);
    return (0);
    }
```

```Output
a b c
end()-begin() = 3
```

## <a name="setswap-stlclr"></a><a name="swap"></a>Set:: swap (STL/CLR)

Alterna o conteúdo de dois contêineres.

### <a name="syntax"></a>Sintaxe

```cpp
void swap(set<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*Certo*<br/>
Contêiner com o qual trocar conteúdos.

### <a name="remarks"></a>Comentários

A função membro troca as sequências controladas entre **`this`** e *à direita*. Ele faz isso em constante tempo e não lança nenhuma exceção. Você o usa como uma maneira rápida de trocar o conteúdo de dois contêineres.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_swap.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct another container with repetition of values
    Myset c2;
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

## <a name="setto_array-stlclr"></a><a name="to_array"></a>definir:: to_array (STL/CLR)

Copia a sequência controlada em uma nova matriz.

### <a name="syntax"></a>Sintaxe

```cpp
cli::array<value_type>^ to_array();
```

### <a name="remarks"></a>Comentários

A função membro retorna uma matriz que contém a sequência controlada. Você o usa para obter uma cópia da sequência controlada na forma de matriz.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_to_array.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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

## <a name="setupper_bound-stlclr"></a><a name="upper_bound"></a>definir:: upper_bound (STL/CLR)

Localiza o fim do intervalo que corresponde a uma chave especificada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator upper_bound(key_type key);
```

#### <a name="parameters"></a>parâmetros

*chave*<br/>
O valor chave a ser pesquisado.

### <a name="remarks"></a>Comentários

A função membro determina o último elemento `X` na sequência controlada que tem a ordenação equivalente para a *chave*. Se esse elemento não existir, ou se `X` for o último elemento na sequência controlada, ele retornará [set:: End (STL/CLR)](../dotnet/set-end-stl-clr.md) `()` ; caso contrário, ele retornará um iterador que designa o primeiro elemento além `X` . Você o usa para localizar o final de uma sequência de elementos atualmente na sequência controlada que corresponde a uma chave especificada.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_upper_bound.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
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

## <a name="setvalue_comp-stlclr"></a><a name="value_comp"></a>definir:: value_comp (STL/CLR)

Copia o delegado de ordenação para dois valores de elemento.

### <a name="syntax"></a>Sintaxe

```cpp
value_compare^ value_comp();
```

### <a name="remarks"></a>Comentários

A função member retorna o delegado de ordenação usado para ordenar a sequência controlada. Você o usa para comparar dois valores de elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_value_comp.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    Myset::value_compare^ kcomp = c1.value_comp();

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
compare(L'a', L'a') = False
compare(L'a', L'b') = True
compare(L'b', L'a') = False
```

## <a name="setvalue_compare-stlclr"></a><a name="value_compare"></a>definir:: value_compare (STL/CLR)

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
// cliext_set_value_compare.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    Myset::value_compare^ kcomp = c1.value_comp();

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
compare(L'a', L'a') = False
compare(L'a', L'b') = True
compare(L'b', L'a') = False
```

## <a name="setvalue_type-stlclr"></a><a name="value_type"></a>definir:: value_type (STL/CLR)

O tipo de um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef generic_value value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `generic_value`.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_value_type.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c" using value_type
    for (Myset::iterator it = c1.begin(); it != c1.end(); ++it)
        {   // store element in value_type object
        Myset::value_type val = *it;

        System::Console::Write("{0} ", val);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="operator-set-stlclr"></a><a name="op_neq"></a>operador! = (conjunto) (STL/CLR)

Lista não é igual a comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Key>
    bool operator!=(set<Key>% left,
        set<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(left == right)` . Você o usa para testar se a *esquerda* não é ordenada da mesma forma que a *correta* quando os dois conjuntos são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_operator_ne.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myset c2;
    c2.insert(L'a');
    c2.insert(L'b');
    c2.insert(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("[a b c] != [a b c] is {0}",
        c1 != c1);
    System::Console::WriteLine("[a b c] != [a b d] is {0}",
        c1 != c2);
    return (0);
    }
```

```Output
a b c
a b d
[a b c] != [a b c] is False
[a b c] != [a b d] is True
```

## <a name="operatorlt-set-stlclr"></a><a name="op_lt"></a>Operator &lt; (Set) (STL/CLR)

Lista menor que comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Key>
    bool operator<(set<Key>% left,
        set<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retornará true se, para a posição mais baixa `i` para a qual `!(right[i] < left[i])` também é verdadeira `left[i] < right[i]` . Caso contrário, ele retornará o `left->size() < right->size()` uso para testar se a *esquerda* é ordenada antes da *direita* quando os dois conjuntos são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_operator_lt.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myset c2;
    c2.insert(L'a');
    c2.insert(L'b');
    c2.insert(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("[a b c] < [a b c] is {0}",
        c1 < c1);
    System::Console::WriteLine("[a b c] < [a b d] is {0}",
        c1 < c2);
    return (0);
    }
```

```Output
a b c
a b d
[a b c] < [a b c] is False
[a b c] < [a b d] is True
```

## <a name="operatorlt-set-stlclr"></a><a name="op_lteq"></a>Operator &lt; = (conjunto) (STL/CLR)

Lista de comparação menor ou igual.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Key>
    bool operator<=(set<Key>% left,
        set<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(right < left)` . Você o usa para testar se a *esquerda* não é ordenada após *direita* quando os dois conjuntos são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_operator_le.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myset c2;
    c2.insert(L'a');
    c2.insert(L'b');
    c2.insert(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("[a b c] <= [a b c] is {0}",
        c1 <= c1);
    System::Console::WriteLine("[a b d] <= [a b c] is {0}",
        c2 <= c1);
    return (0);
    }
```

```Output
a b c
a b d
[a b c] <= [a b c] is True
[a b d] <= [a b c] is False
```

## <a name="operator-set-stlclr"></a><a name="op_eq"></a>Operator = = (Set) (STL/CLR)

Listar comparação igual.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Key>
    bool operator==(set<Key>% left,
        set<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retornará true somente se as sequências controladas pela *esquerda* e *à direita* tiverem o mesmo comprimento e, para cada posição `i` , `left[i] ==` `right[i]` . Você o usa para testar se a *esquerda* é ordenada da mesma forma que a *direita* quando os dois conjuntos são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_operator_eq.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myset c2;
    c2.insert(L'a');
    c2.insert(L'b');
    c2.insert(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("[a b c] == [a b c] is {0}",
        c1 == c1);
    System::Console::WriteLine("[a b c] == [a b d] is {0}",
        c1 == c2);
    return (0);
    }
```

```Output
a b c
a b d
[a b c] == [a b c] is True
[a b c] == [a b d] is False
```

## <a name="operatorgt-set-stlclr"></a><a name="op_gt"></a>Operator &gt; (Set) (STL/CLR)

Lista maior que comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Key>
    bool operator>(set<Key>% left,
        set<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `right` `<` `left` . Você o usa para testar se a *esquerda* é ordenada após *direita* quando os dois conjuntos são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_operator_gt.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myset c2;
    c2.insert(L'a');
    c2.insert(L'b');
    c2.insert(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("[a b c] > [a b c] is {0}",
        c1 > c1);
    System::Console::WriteLine("[a b d] > [a b c] is {0}",
        c2 > c1);
    return (0);
    }
```

```Output
a b c
a b d
[a b c] > [a b c] is False
[a b d] > [a b c] is True
```

## <a name="operatorgt-set-stlclr"></a><a name="op_gteq"></a>Operator &gt; = (conjunto) (STL/CLR)

Lista maior ou igual a comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Key>
    bool operator>=(set<Key>% left,
        set<Key>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(left < right)` . Você o usa para testar se a *esquerda* não é ordenada antes da *direita* quando os dois conjuntos são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_set_operator_ge.cpp
// compile with: /clr
#include <cliext/set>

typedef cliext::set<wchar_t> Myset;
int main()
    {
    Myset c1;
    c1.insert(L'a');
    c1.insert(L'b');
    c1.insert(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myset c2;
    c2.insert(L'a');
    c2.insert(L'b');
    c2.insert(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("[a b c] >= [a b c] is {0}",
        c1 >= c1);
    System::Console::WriteLine("[a b c] >= [a b d] is {0}",
        c1 >= c2);
    return (0);
    }
```

```Output
a b c
a b d
[a b c] >= [a b c] is True
[a b c] >= [a b d] is False
```
