---
title: adapter (STL/CLR)
ms.date: 06/15/2018
ms.topic: reference
f1_keywords:
- <cliext/adapter>
- cliext::collection_adapter
- cliext::collection_adapter::base
- cliext::collection_adapter::begin
- cliext::collection_adapter::collection_adapter
- cliext::collection_adapter::difference_type
- cliext::collection_adapter::end
- cliext::collection_adapter::iterator
- cliext::collection_adapter::key_type
- cliext::collection_adapter::mapped_type
- cliext::collection_adapter::operator=
- cliext::collection_adapter::reference
- cliext::collection_adapter::size
- cliext::collection_adapter::size_type
- cliext::collection_adapter::swap
- cliext::collection_adapter::value_type
- cliext::make_collection
- cliext::range_adapter
- cliext::operator=
- cliext::range_adapter::operator=
- cliext::range_adapter::range_adapter
helpviewer_keywords:
- <adapter> header [STL/CLR]
- adapter [STL/CLR]
- <cliext/adapter> header [STL/CLR]
- collection_adapter class [STL/CLR]
- base member [STL/CLR]
- begin member [STL/CLR]
- collection_adapter member [STL/CLR]
- difference_type member [STL/CLR]
- end member [STL/CLR]
- iterator member [STL/CLR]
- key_type member [STL/CLR]
- mapped_type member [STL/CLR]
- operator= member [STL/CLR]
- reference member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- swap member [STL/CLR]
- value_type member [STL/CLR]
- make_collection function [STL/CLR]
- range_adapter class [STL/CLR]
- operator= member [STL/CLR]
- range_adapter member [STL/CLR]
ms.assetid: 71ce7e51-42b6-4f70-9595-303791a97677
ms.openlocfilehash: 3278371cc7afb08f0d461c77cde9578e1f2840c6
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502426"
---
# <a name="adapter-stlclr"></a>adapter (STL/CLR)

O cabeçalho STL/CLR `<cliext/adapter>` especifica duas classes de modelo ( `collection_adapter` e `range_adapter` ) e a função de modelo `make_collection` .

## <a name="syntax"></a>Sintaxe

```cpp
#include <cliext/adapter>
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<cliext/adapter>

**Namespace:** cliext

## <a name="declarations"></a>Declarações

|Classe|Descrição|
|-----------|-----------------|
|[collection_adapter (STL/CLR)](#collection_adapter)|Encapsula a coleção da BCL (biblioteca de classes base) como um intervalo.|
|[range_adapter (STL/CLR)](#range_adapter)|Encapsula o intervalo como uma coleção de BCL.|

|Função|Descrição|
|--------------|-----------------|
|[make_collection (STL/CLR)](#make_collection)|Cria um adaptador de intervalo usando um par de iteradores.|

## <a name="members"></a>Membros

## <a name="collection_adapter-stlclr"></a><a name="collection_adapter"></a> collection_adapter (STL/CLR)

Encapsula uma coleção .NET para uso como um contêiner STL/CLR. Um `collection_adapter` é uma classe de modelo que descreve um objeto de contêiner STL/CLR simples. Ele encapsula uma interface BCL (base Class Library) e retorna um par iterador que você usa para manipular a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Coll>
    ref class collection_adapter;

template<>
    ref class collection_adapter<
        System::Collections::ICollection>;
template<>
    ref class collection_adapter<
        System::Collections::IEnumerable>;
template<>
    ref class collection_adapter<
        System::Collections::IList>;
template<>
    ref class collection_adapter<
        System::Collections::IDictionary>;
template<typename Value>
    ref class collection_adapter<
        System::Collections::Generic::ICollection<Value>>;
template<typename Value>
    ref class collection_adapter<
        System::Collections::Generic::IEnumerable<Value>>;
template<typename Value>
    ref class collection_adapter<
        System::Collections::Generic::IList<Value>>;
template<typename Key,
    typename Value>
    ref class collection_adapter<
        System::Collections::Generic::IDictionary<Key, Value>>;
```

#### <a name="parameters"></a>Parâmetros

*Coll*<br/>
O tipo da coleção encapsulada.

### <a name="specializations"></a>Especializações

|Especialização|Descrição|
|--------------------|-----------------|
|IEnumerable|Sequências por meio de elementos.|
|ICollection|Mantém um grupo de elementos.|
|IList|Mantém um grupo ordenado de elementos.|
|IDictionary|Mantenha um conjunto de pares {Key, value}.|
|IEnumerable\<Value>|Sequências por meio de elementos tipados.|
|ICollection\<Value>|Mantém um grupo de elementos tipados.|
|IList\<Value>|Mantém um grupo ordenado de elementos tipados.|
|IDictionary\<Value> |Mantém um conjunto de pares {Key, Value} tipados.|

### <a name="members"></a>Membros

|Definição de tipo|Descrição|
|---------------------|-----------------|
|[collection_adapter::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|
|[collection_adapter::iterator (STL/CLR)](#iterator)|O tipo de um iterador para a sequência controlada.|
|[collection_adapter::key_type (STL/CLR)](#key_type)|O tipo de uma chave de dicionário.|
|[collection_adapter::mapped_type (STL/CLR)](#mapped_type)|O tipo de um valor de dicionário.|
|[collection_adapter::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|
|[collection_adapter::size_type (STL/CLR)](#size_type)|O tipo de uma distância com sinal entre dois elementos.|
|[collection_adapter::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|

|Função membro|Descrição|
|---------------------|-----------------|
|[collection_adapter::base (STL/CLR)](#base)|Designa a interface da BCL encapsulada.|
|[collection_adapter::begin (STL/CLR)](#begin)|Designa o início da sequência controlada.|
|[collection_adapter::collection_adapter (STL/CLR)](#collection_adapter_collection_adapter)|Constrói um objeto de adaptador.|
|[collection_adapter::end (STL/CLR)](#end)|Designa o fim da sequência controlada.|
|[collection_adapter::size (STL/CLR)](#size)|Conta o número de elementos.|
|[collection_adapter::swap (STL/CLR)](#swap)|Alterna o conteúdo de dois contêineres.|

|Operador|Descrição|
|--------------|-----------------|
|[collection_adapter::operator= (STL/CLR)](#op_eq)|Substitui o identificador de BCL armazenado.|

### <a name="remarks"></a>Comentários

Você usa essa classe de modelo para manipular um contêiner de BCL como um contêiner STL/CLR. O `collection_adapter` armazena um identificador para uma interface BCL que, por sua vez, controla uma sequência de elementos. Um `collection_adapter` objeto `X` retorna um par de iteradores de entrada `X.begin()` e `X.end()` que você usa para visitar os elementos, em ordem. Algumas das especializações também permitem que você escreva `X.size()` para determinar o comprimento da sequência controlada.

## <a name="collection_adapterbase-stlclr"></a><a name="base"></a> collection_adapter:: base (STL/CLR)

Designa a interface da BCL encapsulada.

### <a name="syntax"></a>Sintaxe

```cpp
Coll^ base();
```

### <a name="remarks"></a>Comentários

A função membro retorna o identificador da interface BCL armazenada.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_base.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
    {
    cliext::deque<wchar_t> d6x(6, L'x');
    Mycoll c1(%d6x);

    // display initial contents "x x x x x x "
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Console::WriteLine("base() same = {0}", c1.base() == %c1);
    return (0);
    }
```

```Output
x x x x x x
base() same = True
```

## <a name="collection_adapterbegin-stlclr"></a><a name="begin"></a> collection_adapter:: Begin (STL/CLR)

Designa o início da sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator begin();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador de entrada que designa o primeiro elemento da sequência controlada ou apenas após o final de uma sequência vazia.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_begin.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Mycoll c1(%d1);

    // display initial contents "a b c "
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first two items
    Mycoll::iterator it = c1.begin();
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

## <a name="collection_adaptercollection_adapter-stlclr"></a><a name="collection_adapter_collection_adapter"></a> collection_adapter:: collection_adapter (STL/CLR)

Constrói um objeto de adaptador.

### <a name="syntax"></a>Sintaxe

```cpp
collection_adapter();
collection_adapter(collection_adapter<Coll>% right);
collection_adapter(collection_adapter<Coll>^ right);
collection_adapter(Coll^ collection);
```

#### <a name="parameters"></a>Parâmetros

*Cole*<br/>
Identificador de BCL a ser encapsulado.

*direita*<br/>
Objeto a ser copiado.

### <a name="remarks"></a>Comentários

O construtor:

`collection_adapter();`

Inicializa o identificador armazenado com **`nullptr`** .

O construtor:

`collection_adapter(collection_adapter<Coll>% right);`

Inicializa o identificador armazenado com `right.` [collection_adapter:: base (STL/CLR)](#base) `()` .

O construtor:

`collection_adapter(collection_adapter<Coll>^ right);`

Inicializa o identificador armazenado com `right->` [collection_adapter:: base (STL/CLR)](#base) `()` .

O construtor:

`collection_adapter(Coll^ collection);`

Inicializa o identificador armazenado com `collection` .

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_construct.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d6x(6, L'x');

    // construct an empty container
    Mycoll c1;
    System::Console::WriteLine("base() null = {0}", c1.base() == nullptr);

    // construct with a handle
    Mycoll c2(%d6x);
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct by copying another container
    Mycoll c3(c2);
    for each (wchar_t elem in c3)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct by copying a container handle
    Mycoll c4(%c3);
    for each (wchar_t elem in c4)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    return (0);
}
```

```Output
base() null = True
x x x x x x
x x x x x x
x x x x x x
```

## <a name="collection_adapterdifference_type-stlclr"></a><a name="difference_type"></a> collection_adapter::d ifference_type (STL/CLR)

Os tipos de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int difference_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos assinados.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_difference_type.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Mycoll c1(%d1);

    // display initial contents "a b c "
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // compute positive difference
    Mycoll::difference_type diff = 0;
    Mycoll::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        ++diff;
    System::Console::WriteLine("end()-begin() = {0}", diff);
    return (0);
}
```

```Output
a b c
end()-begin() = 3
```

## <a name="collection_adapterend-stlclr"></a><a name="end"></a> collection_adapter:: End (STL/CLR)

Designa o fim da sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator end();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador de entrada que aponta apenas além do fim da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_end.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Mycoll c1(%d1);

    // display initial contents "a b c "
    Mycoll::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        System::Console::Write("{0} ", *it);
    System::Console::WriteLine();
    return (0);
}
```

```Output
a b c
```

## <a name="collection_adapteriterator-stlclr"></a><a name="iterator"></a> collection_adapter:: iterador (STL/CLR)

O tipo de um iterador para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T1 iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto de tipo não especificado `T1` que pode servir como um iterador de entrada para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_iterator.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Mycoll c1(%d1);

    // display initial contents "a b c "
    Mycoll::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        System::Console::Write("{0} ", *it);
    System::Console::WriteLine();
    return (0);
}
```

```Output
a b c
```

## <a name="collection_adapterkey_type-stlclr"></a><a name="key_type"></a> collection_adapter:: key_type (STL/CLR)

O tipo de uma chave de dicionário.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo `Key` , em uma especialização para `IDictionary` ou `IDictionary<Value>` ; caso contrário, ele não será definido.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_key_type.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/map>

typedef cliext::map<wchar_t, int> Mymap;
typedef cliext::collection_adapter<
    System::Collections::Generic::IDictionary<wchar_t, int>> Mycoll;
typedef System::Collections::Generic::KeyValuePair<wchar_t,int> Mypair;
int main()
{
    Mymap d1;
    d1.insert(Mymap::make_value(L'a', 1));
    d1.insert(Mymap::make_value(L'b', 2));
    d1.insert(Mymap::make_value(L'c', 3));
    Mycoll c1(%d1);

    // display contents "[a 1] [b 2] [c 3] "
    for each (Mypair elem in c1)
    {
        Mycoll::key_type key = elem.Key;
        Mycoll::mapped_type value = elem.Value;
        System::Console::Write("[{0} {1}] ", key, value);
    }
    System::Console::WriteLine();
    return (0);
}
```

```Output
[a 1] [b 2] [c 3]
```

## <a name="collection_adaptermapped_type-stlclr"></a><a name="mapped_type"></a> collection_adapter:: mapped_type (STL/CLR)

O tipo de um valor de dicionário.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value mapped_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo `Value` , em uma especialização para `IDictionary` ou `IDictionary<Value>` ; caso contrário, ele não será definido.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_mapped_type.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/map>

typedef cliext::map<wchar_t, int> Mymap;
typedef cliext::collection_adapter<
    System::Collections::Generic::IDictionary<wchar_t, int>> Mycoll;
typedef System::Collections::Generic::KeyValuePair<wchar_t,int> Mypair;
int main()
{
    Mymap d1;
    d1.insert(Mymap::make_value(L'a', 1));
    d1.insert(Mymap::make_value(L'b', 2));
    d1.insert(Mymap::make_value(L'c', 3));
    Mycoll c1(%d1);

    // display contents "[a 1] [b 2] [c 3] "
    for each (Mypair elem in c1)
    {
        Mycoll::key_type key = elem.Key;
        Mycoll::mapped_type value = elem.Value;
        System::Console::Write("[{0} {1}] ", key, value);
    }
    System::Console::WriteLine();
    return (0);
}
```

```Output
[a 1] [b 2] [c 3]
```

## <a name="collection_adapteroperator-stlclr"></a><a name="op_eq"></a> collection_adapter:: Operator = (STL/CLR)

Substitui o identificador de BCL armazenado.

### <a name="syntax"></a>Sintaxe

```cpp
collection_adapter<Coll>% operator=(collection_adapter<Coll>% right);
```

#### <a name="parameters"></a>Parâmetros

*direita*<br/>
Adaptador a ser copiado.

### <a name="remarks"></a>Comentários

O operador membro copia *diretamente* para o objeto e, em seguida, retorna **`*this`** . Você o usa para substituir o identificador de BCL armazenado por uma cópia do identificador de BCL armazenado à *direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_operator_as.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Mycoll c1(%d1);

    // display initial contents "a b c "
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    Mycoll c2;
    c2 = c1;
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
}
```

```Output
a b c
a b c
```

## <a name="collection_adapterreference-stlclr"></a><a name="reference"></a> collection_adapter:: Reference (STL/CLR)

O tipo de uma referência para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência a um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_reference.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
    {
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Mycoll c1(%d1);

    // display initial contents "a b c "
    Mycoll::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
    {   // get a reference to an element
        Mycoll::reference ref = *it;
        System::Console::Write("{0} ", ref);
    }
    System::Console::WriteLine();
    return (0);
}
```

```Output
a b c
```

## <a name="collection_adaptersize-stlclr"></a><a name="size"></a> collection_adapter:: Size (STL/CLR)

Conta o número de elementos.

### <a name="syntax"></a>Sintaxe

```cpp
size_type size();
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência controlada. Ele não é definido em uma especialização para `IEnumerable` ou `IEnumerable<Value>` .

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_size.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d6x(6, L'x');
    Mycoll c1(%d6x);

    // display initial contents "x x x x x x "
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine("size() = {0}", c1.size());
    return (0);
}
```

```Output
x x x x x x
size() = 6
```

## <a name="collection_adaptersize_type-stlclr"></a><a name="size_type"></a> collection_adapter:: size_type (STL/CLR)

O tipo de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int size_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos não negativos.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_size_type.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d6x(6, L'x');
    Mycoll c1(%d6x);

    // display initial contents "x x x x x x"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    Mycoll::size_type size = c1.size();
    System::Console::WriteLine("size() = {0}", size);
    return (0);
}
```

```Output
x x x x x x
size() = 6
```

## <a name="collection_adapterswap-stlclr"></a><a name="swap"></a> collection_adapter:: swap (STL/CLR)

Alterna o conteúdo de dois contêineres.

### <a name="syntax"></a>Sintaxe

```cpp
void swap(collection_adapter<Coll>% right);
```

#### <a name="parameters"></a>Parâmetros

*direita*<br/>
Contêiner com o qual trocar conteúdos.

### <a name="remarks"></a>Comentários

A função membro troca os identificadores de BCL armazenados entre **`*this`** e *à direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_swap.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Mycoll c1(%d1);

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct another container with repetition of values
    cliext::deque<wchar_t> d2(5, L'x');
    Mycoll c2(%d2);
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
x x x x x
x x x x x
a b c
```

## <a name="collection_adaptervalue_type-stlclr"></a><a name="value_type"></a> collection_adapter:: value_type (STL/CLR)

O tipo de um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o *valor*do parâmetro de modelo, se presente na especialização; caso contrário, é sinônimo de `System::Object^` .

### <a name="example"></a>Exemplo

```cpp
// cliext_collection_adapter_value_type.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::collection_adapter<
    System::Collections::ICollection> Mycoll;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Mycoll c1(%d1);

    // display contents "a b c" using value_type
    for (Mycoll::iterator it = c1.begin();
        it != c1.end(); ++it)
    {   // store element in value_type object
        Mycoll::value_type val = *it;

        System::Console::Write("{0} ", val);
    }
    System::Console::WriteLine();
    return (0);
}
```

```Output
a b c
```

## <a name="make_collection-stlclr"></a><a name="make_collection"></a> make_collection (STL/CLR)

Faça um `range_adapter` de um par de iteradores.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Iter>
    range_adapter<Iter> make_collection(Iter first, Iter last);
```

#### <a name="parameters"></a>Parâmetros

*Iter*<br/>
O tipo dos iteradores encapsulados.

*first*<br/>
Primeiro iterador a ser encapsulado.

*last*<br/>
Segundo iterador a ser encapsulado.

### <a name="remarks"></a>Comentários

A função do modelo retorna `gcnew range_adapter<Iter>(first, last)`. Você o usa para construir um `range_adapter<Iter>` objeto de um par de iteradores.

### <a name="example"></a>Exemplo

```cpp
// cliext_make_collection.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::deque<wchar_t> Mycont;
typedef cliext::range_adapter<Mycont::iterator> Myrange;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in d1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    System::Collections::ICollection^ p1 =
        cliext::make_collection(d1.begin(), d1.end());
    System::Console::WriteLine("Count = {0}", p1->Count);
    System::Console::WriteLine("IsSynchronized = {0}",
        p1->IsSynchronized);
    System::Console::WriteLine("SyncRoot not nullptr = {0}",
        p1->SyncRoot != nullptr);

    // copy the sequence
    cli::array<System::Object^>^ a1 = gcnew cli::array<System::Object^>(5);

    a1[0] = L'|';
    p1->CopyTo(a1, 1);
    a1[4] = L'|';
    for each (wchar_t elem in a1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    return (0);
}
```

```Output
a b c
Count = 3
IsSynchronized = False
SyncRoot not nullptr = True
| a b c |
```

## <a name="range_adapter-stlclr"></a><a name="range_adapter"></a> range_adapter (STL/CLR)

Uma classe de modelo que encapsula um par de iteradores que são usados para implementar várias interfaces de BCL (base Class Library). Você usa o range_adapter para manipular um intervalo STL/CLR como se fosse uma coleção de BCL.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Iter>
    ref class range_adapter
        :   public
        System::Collections::IEnumerable,
        System::Collections::ICollection,
        System::Collections::Generic::IEnumerable<Value>,
        System::Collections::Generic::ICollection<Value>
    { ..... };
```

#### <a name="parameters"></a>Parâmetros

*Iter*<br/>
O tipo associado aos iteradores encapsulados.

### <a name="members"></a>Membros

|Função membro|Descrição|
|---------------------|-----------------|
|[range_adapter::range_adapter (STL/CLR)](#range_adapter_range_adapter)|Constrói um objeto de adaptador.|

|Operador|Descrição|
|--------------|-----------------|
|[range_adapter::operator= (STL/CLR)](#range_adapter_op_eq)|Substitui o par do iterador armazenado.|

### <a name="interfaces"></a>Interfaces

|Interface|Descrição|
|---------------|-----------------|
|<xref:System.Collections.IEnumerable>|Itera através de elementos na coleção.|
|<xref:System.Collections.ICollection>|Mantém um grupo de elementos.|
|<xref:System.Collections.Generic.IEnumerable%601>|Itera por meio de elementos tipados na coleção.|
|<xref:System.Collections.Generic.ICollection%601>|Mantém um grupo de elementos tipados.|

### <a name="remarks"></a>Comentários

O range_adapter armazena um par de iteradores que, por sua vez, delimitam uma sequência de elementos. O objeto implementa quatro interfaces BCL que permitem iterar nos elementos, em ordem. Você usa essa classe de modelo para manipular intervalos STL/CLR de forma semelhante a contêineres de BCL.

## <a name="range_adapteroperator-stlclr"></a><a name="range_adapter_op_eq"></a> range_adapter:: Operator = (STL/CLR)

Substitui o par do iterador armazenado.

### <a name="syntax"></a>Sintaxe

```cpp
range_adapter<Iter>% operator=(range_adapter<Iter>% right);
```

#### <a name="parameters"></a>Parâmetros

*direita*<br/>
Adaptador a ser copiado.

### <a name="remarks"></a>Comentários

O operador membro copia *diretamente* para o objeto e, em seguida, retorna **`*this`** . Você o usa para substituir o par do iterador armazenado por uma cópia do par do iterador armazenado à *direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_range_adapter_operator_as.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::deque<wchar_t> Mycont;
typedef cliext::range_adapter<Mycont::iterator> Myrange;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');
    Myrange c1(d1.begin(), d1.end());

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    Myrange c2;
    c2 = c1;
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
}
```

```Output
a b c
a b c
```

## <a name="range_adapterrange_adapter-stlclr"></a><a name="range_adapter_range_adapter"></a> range_adapter:: range_adapter (STL/CLR)

Constrói um objeto de adaptador.

### <a name="syntax"></a>Sintaxe

```cpp
range_adapter();
range_adapter(range_adapter<Iter>% right);
range_adapter(range_adapter<Iter>^ right);
range_adapter(Iter first, Iter last);
```

#### <a name="parameters"></a>Parâmetros

*first*<br/>
Primeiro iterador a ser encapsulado.

*last*<br/>
Segundo iterador a ser encapsulado.

*direita*<br/>
Objeto a ser copiado.

### <a name="remarks"></a>Comentários

O construtor:

`range_adapter();`

Inicializa o par de iteradores armazenados com iteradores construídos padrão.

O construtor:

`range_adapter(range_adapter<Iter>% right);`

Inicializa o par do iterador armazenado copiando o par armazenado à *direita*.

O construtor:

`range_adapter(range_adapter<Iter>^ right);`

Inicializa o par do iterador armazenado copiando o par armazenado em `*right` .

O construtor:

`range_adapter(Iter^ first, last);`

Inicializa o par de iteradores armazenados com o *primeiro* e o *último*.

### <a name="example"></a>Exemplo

```cpp
// cliext_range_adapter_construct.cpp
// compile with: /clr
#include <cliext/adapter>
#include <cliext/deque>

typedef cliext::deque<wchar_t> Mycont;
typedef cliext::range_adapter<Mycont::iterator> Myrange;
int main()
{
    cliext::deque<wchar_t> d1;
    d1.push_back(L'a');
    d1.push_back(L'b');
    d1.push_back(L'c');

    // construct an empty adapter
    Myrange c1;

    // construct with an iterator pair
    Myrange c2(d1.begin(), d1.end());
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct by copying another adapter
    Myrange c3(c2);
    for each (wchar_t elem in c3)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct by copying an adapter handle
    Myrange c4(%c3);
    for each (wchar_t elem in c4)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    return (0);
}
```

```Output
a b c
a b c
a b c
```
