---
title: deque (STL/CLR)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- cliext::deque
- cliext::deque::assign
- cliext::deque::at
- cliext::deque::back
- cliext::deque::back_item
- cliext::deque::begin
- cliext::deque::clear
- cliext::deque::const_iterator
- cliext::deque::const_reference
- cliext::deque::const_reverse_iterator
- cliext::deque::deque
- cliext::deque::difference_type
- cliext::deque::empty
- cliext::deque::end
- cliext::deque::erase
- cliext::deque::front
- cliext::deque::front_item
- cliext::deque::generic_container
- cliext::deque::generic_iterator
- cliext::deque::generic_reverse_iterator
- cliext::deque::generic_value
- cliext::deque::insert
- cliext::deque::iterator
- cliext::deque::operator!=
- cliext::deque::operator[]
- cliext::deque::pop_back
- cliext::deque::pop_front
- cliext::deque::push_back
- cliext::deque::push_front
- cliext::deque::rbegin
- cliext::deque::reference
- cliext::deque::rend
- cliext::deque::resize
- cliext::deque::reverse_iterator
- cliext::deque::size
- cliext::deque::size_type
- cliext::deque::swap
- cliext::deque::to_array
- cliext::deque::value_type
- cliext::deque::operator<
- cliext::deque::operator<=
- cliext::deque::operator=
- cliext::deque::operator==
- cliext::deque::operator>
- cliext::deque::operator>=
helpviewer_keywords:
- deque class [STL/CLR]
- <deque> header [STL/CLR]
- <cliext/deque> header [STL/CLR]
- assign member [STL/CLR]
- assign member [STL/CLR]
- at member [STL/CLR]
- back member [STL/CLR]
- back_item member [STL/CLR]
- begin member [STL/CLR]
- clear member [STL/CLR]
- const_iterator member [STL/CLR]
- const_reference member [STL/CLR]
- const_reverse_iterator member [STL/CLR]
- deque member [STL/CLR]
- difference_type member [STL/CLR]
- empty member [STL/CLR]
- end member [STL/CLR]
- erase member [STL/CLR]
- front member [STL/CLR]
- front_item member [STL/CLR]
- generic_container member [STL/CLR]
- generic_iterator member [STL/CLR]
- generic_reverse_iterator member [STL/CLR]
- generic_value member [STL/CLR]
- insert member [STL/CLR]
- iterator member [STL/CLR]
- operator!= member [STL/CLR]
- operator member [] [STL/CLR]
- pop_back member [STL/CLR]
- pop_front member [STL/CLR]
- push_back member [STL/CLR]
- push_front member [STL/CLR]
- rbegin member [STL/CLR]
- reference member [STL/CLR]
- rend member [STL/CLR]
- resize member [STL/CLR]
- reverse_iterator member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- swap member [STL/CLR]
- to_array member [STL/CLR]
- value_type member [STL/CLR]
- operator< member [STL/CLR]
- operator<= member [STL/CLR]
- operator= member [STL/CLR]
- operator== member [STL/CLR]
- operator> member [STL/CLR]
- operator>= member [STL/CLR]
ms.assetid: dd669da3-3c0e-45e9-8596-f6b483720941
ms.openlocfilehash: ff5ddcfa101baf4c85145d1c6d64a6a3b9e7df58
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393760"
---
# <a name="deque-stlclr"></a>deque (STL/CLR)

A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos que tem acesso aleatório. Você pode usar o contêiner `deque` para gerenciar uma sequência de elementos que se parece com um bloco contíguo de armazenamento, mas que pode aumentar ou reduzir em ambas as extremidades sem a necessidade de copiar todos os elementos restantes. Portanto, ela pode implementar com eficiência um `double-ended queue`. (Portanto, o nome.)

Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo ref, nesse caso, ele é `Value^`.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Value>
    ref class deque
        :   public
        System::ICloneable,
        System::Collections::IEnumerable,
        System::Collections::ICollection,
        System::Collections::Generic::IEnumerable<GValue>,
        System::Collections::Generic::ICollection<GValue>,
        System::Collections::Generic::IList<GValue>,
        Microsoft::VisualC::StlClr::IDeque<GValue>
    { ..... };
```

### <a name="parameters"></a>Parâmetros

*GValue*<br/>
O tipo genérico de um elemento na sequência controlada.

*Valor*<br/>
O tipo de um elemento na sequência controlada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<cliext/deque >

**Namespace:** cliext

## <a name="declarations"></a>Declarações

|Definição do tipo|Descrição|
|---------------------|-----------------|
|[deque::const_iterator (STL/CLR)](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|
|[deque::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|
|[deque::const_reverse_iterator (STL/CLR)](#const_reverse_iterator)|O tipo de um iterador reverso de constante para a sequência controlada.|
|[deque::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|
|[deque::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o contêiner.|
|[deque::generic_iterator (STL/CLR)](#generic_iterator)|O tipo de um iterador para a interface genérica para o contêiner.|
|[deque::generic_reverse_iterator (STL/CLR)](#generic_reverse_iterator)|O tipo de um iterador inverso para a interface genérica para o contêiner.|
|[deque::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o contêiner.|
|[deque::iterator (STL/CLR)](#iterator)|O tipo de um iterador para a sequência controlada.|
|[deque::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|
|[deque::reverse_iterator (STL/CLR)](#reverse_iterator)|O tipo de um iterador inverso para a sequência controlada.|
|[deque::size_type (STL/CLR)](#size_type)|O tipo de uma distância com sinal entre dois elementos.|
|[deque::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|

|Função membro|Descrição|
|---------------------|-----------------|
|[deque::assign (STL/CLR)](#assign)|Substitui todos os elementos.|
|[deque::at (STL/CLR)](#at)|Acessa um elemento em uma posição especificada.|
|[deque::back (STL/CLR)](#back)|Acessa o último elemento.|
|[deque::begin (STL/CLR)](#begin)|Designa o início da sequência controlada.|
|[deque::clear (STL/CLR)](#clear)|Remove todos os elementos.|
|[deque::deque (STL/CLR)](#deque)|Constrói um objeto contêiner.|
|[deque::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|
|[deque::end (STL/CLR)](#end)|Designa o fim da sequência controlada.|
|[deque::erase (STL/CLR)](#erase)|Remove os elementos em posições especificadas.|
|[deque::front (STL/CLR)](#front)|Acessa o primeiro elemento.|
|[deque::insert (STL/CLR)](#insert)|Adiciona os elementos em uma posição especificada.|
|[deque::pop_back (STL/CLR)](#pop_back)|Remove o último elemento.|
|[deque::pop_front (STL/CLR)](#pop_front)|Remove o primeiro elemento.|
|[deque::push_back (STL/CLR)](#push_back)|Adiciona um novo último elemento.|
|[deque::push_front (STL/CLR)](#push_front)|Adiciona um novo elemento primeiro.|
|[deque::rbegin (STL/CLR)](#rbegin)|Designa o início da sequência controlada invertida.|
|[deque::rend (STL/CLR)](#rend)|Designa o fim da sequência controlada invertida.|
|[deque::resize (STL/CLR)](#resize)|Altera o número de elementos.|
|[deque::size (STL/CLR)](#size)|Conta o número de elementos.|
|[deque::swap (STL/CLR)](#swap)|Alterna o conteúdo de dois contêineres.|
|[deque::to_array (STL/CLR)](#to_array)|Copia a sequência controlada para uma nova matriz.|

|Propriedade|Descrição|
|--------------|-----------------|
|[deque::back_item (STL/CLR)](#back_item)|Acessa o último elemento.|
|[deque::front_item (STL/CLR)](#front_item)|Acessa o primeiro elemento.|

|Operador|Descrição|
|--------------|-----------------|
|[deque::operator!= (STL/CLR)](#op_neq)|Determina se dois `deque` objetos não forem iguais.|
|[deque::operator(STL/CLR)](#operator)|Acessa um elemento em uma posição especificada.|
|[operator< (deque) (STL/CLR)](#op_lt)|Determina se um `deque` objeto é menor que outro `deque` objeto.|
|[operator<= (deque) (STL/CLR)](#op_lteq)|Determina se um `deque` objeto é menor ou igual a outro `deque` objeto.|
|[operator= (deque) (STL/CLR)](#op_as)|Substitui a sequência controlada.|
|[operator== (deque) (STL/CLR)](#op_eq)|Determina se um `deque` objeto é igual a outro `deque` objeto.|
|[operator> (deque) (STL/CLR)](#op_gt)|Determina se um `deque` objeto é maior que outro `deque` objeto.|
|[operator>= (deque) (STL/CLR)](#op_gteq)|Determina se um `deque` objeto é maior que ou igual a outro `deque` objeto.|

## <a name="interfaces"></a>Interfaces

|Interface|Descrição|
|---------------|-----------------|
|<xref:System.ICloneable>|Duplicar um objeto.|
|<xref:System.Collections.IEnumerable>|Por meio de elementos de sequência.|
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|
|<xref:System.Collections.Generic.IEnumerable%601>|Por meio de elementos com tipo de sequência.|
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|
|<xref:System.Collections.Generic.IList%601>|Manter o grupo ordenado de elementos com tipo.|
|IDeque<Value\>|Manter o contêiner genérico.|

## <a name="remarks"></a>Comentários

O objeto aloca e libera armazenamento para a sequência que controla por meio de uma matriz armazenada das alças que designam os blocos de `Value` elementos. A matriz aumenta conforme a demanda. O crescimento ocorre de forma que o custo de prefixação das ou acrescentando um novo elemento é um tempo constante e não há elementos restantes são afetados. Você também pode remover um elemento em ambas as extremidades em tempo constante e sem prejudicar os elementos restantes. Portanto, um deque é um bom candidato para o contêiner subjacente para a classe de modelo [queue (STL/CLR)](../dotnet/queue-stl-clr.md) ou a classe de modelo [stack (STL/CLR)](../dotnet/stack-stl-clr.md).

Um `deque` objeto dá suporte a iteradores de acesso aleatório, que significa que você pode se referir a um elemento diretamente, dado sua posição numérica, contando a partir de zero para o primeiro elemento (frontal), para [deque (STL/CLR)](#size) `() - 1` para o último elemento (Voltar). Isso também significa que um deque é um bom candidato para o contêiner subjacente para a classe de modelo [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md).

Um iterador de deque armazena um identificador para o seu objeto do deque associado, juntamente com a tendência do elemento que ele designa. Você pode usar iteradores somente com seus objetos de contêiner associado. É a tendência de um elemento de deque *não* necessariamente o mesmo que sua posição. O primeiro elemento inserido tem diferença zero, o próximo elemento acrescentado tem diferença 1, mas o próximo elemento antecedendo tem diferença -1.

Inserir ou apagar elementos em ambas as extremidades faz *não* alterar o valor de um elemento armazenado em qualquer tendência válida. Inserir ou apagar um elemento interior, no entanto, *pode* alterar o valor do elemento armazenado em um desvio determinado, portanto, também pode alterar o valor designado por um iterador. (O contêiner pode ter que copiar elementos para cima ou para baixo para criar um buraco antes de uma inserção ou para preencher um buraco após um apagamento). No entanto, um iterador de deque permanece válido desde que o bias designa um elemento válido. Além disso, um iterador válido permanece dereferencable – você pode usá-lo para acessar ou alterar o valor do elemento que ele designa – desde que seu desvio não é igual ao desvio para o iterador retornado por `end()`.

Apagando ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Portanto, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento sobreviver além do contêiner. No entanto, observe que um contêiner de identificadores não *não* destruir seus elementos.

## <a name="members"></a>Membros

## <a name="assign"></a> deque::assign (STL/CLR)

Substitui todos os elementos.

### <a name="syntax"></a>Sintaxe

```cpp
void assign(size_type count, value_type val);
template<typename InIt>
    void assign(InIt first, InIt last);
void assign(System::Collections::Generic::IEnumerable<Value>^ right);
```

#### <a name="parameters"></a>Parâmetros

*count*<br/>
Número de elementos a inserir.

*first*<br/>
Início do intervalo a ser inserido.

*last*<br/>
Fim do intervalo a inserir.

*right*<br/>
Enumeração a ser inserido.

*val*<br/>
Valor do elemento a ser inserido.

### <a name="remarks"></a>Comentários

A primeira função membro substitui a sequência controlada por uma repetição de *contagem* elementos de valor *val*. Você usá-lo para preencher o contêiner com elementos tudo que tem o mesmo valor.

Se `InIt` é um tipo inteiro, a segunda função membro se comporta da mesma como `assign((size_type)first, (value_type)last)`. Caso contrário, ele substitui a sequência controlada pela sequência [`first`, `last`). Você usá-lo para tornar o controlado uma cópia de sequência outra sequência.

A terceira função membro substitui a sequência controlada pela sequência designada pelo enumerador *certa*. Você pode usá-lo para fazer uma cópia de uma sequência descrita por um enumerador a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_assign.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // assign a repetition of values
    cliext::deque<wchar_t> c2;
    c2.assign(6, L'x');
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign an iterator range
    c2.assign(c1.begin(), c1.end() - 1);
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign an enumeration
    c2.assign(   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
x x x x x x
a b
a b c
```

## <a name="at"></a> deque::at (STL/CLR)

Acessa um elemento em uma posição especificada.

### <a name="syntax"></a>Sintaxe

```cpp
reference at(size_type pos);
```

#### <a name="parameters"></a>Parâmetros

*pos*<br/>
Posição do elemento a acessar.

### <a name="remarks"></a>Comentários

A função membro retorna uma referência ao elemento da sequência controlada na posição *pos*. Você pode usá-lo para ler ou gravar um elemento cuja posição você sabe.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_at.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c" using at
    for (int i = 0; i < c1.size(); ++i)
        System::Console::Write("{0} ", c1.at(i));
    System::Console::WriteLine();

    // change an entry and redisplay
    c1.at(1) = L'x';
    for (int i = 0; i < c1.size(); ++i)
        System::Console::Write("{0} ", c1[i]);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a x c
```

## <a name="back"></a> deque::back (STL/CLR)

Acessa o último elemento.

### <a name="syntax"></a>Sintaxe

```cpp
reference back();
```

### <a name="remarks"></a>Comentários

A função membro retorna uma referência ao último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para acessar o último elemento, quando você souber que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_back.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect last item
    System::Console::WriteLine("back() = {0}", c1.back());

    // alter last item and reinspect
    c1.back() = L'x';
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
back() = c
a b x
```

## <a name="back_item"></a> deque::back_item (STL/CLR)

Acessa o último elemento.

### <a name="syntax"></a>Sintaxe

```cpp
property value_type back_item;
```

### <a name="remarks"></a>Comentários

A propriedade acessa o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o último elemento, quando você souber que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_back_item.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect last item
    System::Console::WriteLine("back_item = {0}", c1.back_item);

    // alter last item and reinspect
    c1.back_item = L'x';
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
back_item = c
a b x
```

## <a name="begin"></a> deque::begin (STL/CLR)

Designa o início da sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator begin();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador de acesso aleatório que designa o primeiro elemento da sequência controlada ou logo após o fim de uma sequência vazia. Use-o para obter um iterador que designa o início `current` da sequência controlada, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_begin.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first two items
    cliext::deque<wchar_t>::iterator it = c1.begin();
    System::Console::WriteLine("*begin() = {0}", *it);
    System::Console::WriteLine("*++begin() = {0}", *++it);

    // alter first two items and reinspect
    *--it = L'x';
    *++it = L'y';
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
*begin() = a
*++begin() = b
x y c
```

## <a name="clear"></a> deque::clear (STL/CLR)

Remove todos os elementos.

### <a name="syntax"></a>Sintaxe

```cpp
void clear();
```

### <a name="remarks"></a>Comentários

A função membro chama efetivamente [Erase (STL/CLR)](#erase) `(` [deque (STL/CLR)](#begin) `(),` [deque:: end (STL/CLR)](#end) `())`. Você pode usá-lo para garantir que a sequência controlada vazia.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_clear.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // clear the container and reinspect
    c1.clear();
    System::Console::WriteLine("size() = {0}", c1.size());

    // add elements and clear again
    c1.push_back(L'a');
    c1.push_back(L'b');

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

## <a name="const_iterator"></a> deque::const_iterator (STL/CLR)

O tipo de um iterador de constante para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T2 const_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo não especificado `T2` que pode servir como um iterador de acesso aleatório constante para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_const_iterator.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    cliext::deque<wchar_t>::const_iterator cit = c1.begin();
    for (; cit != c1.end(); ++cit)
        System::Console::Write("{0} ", *cit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="const_reference"></a> deque::const_reference (STL/CLR)

O tipo de uma referência de constante para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% const_reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência constante para um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_const_reference.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    cliext::deque<wchar_t>::const_iterator cit = c1.begin();
    for (; cit != c1.end(); ++cit)
        {   // get a const reference to an element
        cliext::deque<wchar_t>::const_reference cref = *cit;
        System::Console::Write("{0} ", cref);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="const_reverse_iterator"></a> deque::const_reverse_iterator (STL/CLR)

O tipo de um iterador inverso constante para a sequência controlada...

### <a name="syntax"></a>Sintaxe

```cpp
typedef T4 const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo não especificado `T4` que pode servir como um iterador inverso constante para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_const_reverse_iterator.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c" reversed
    cliext::deque<wchar_t>::const_reverse_iterator crit = c1.rbegin();
    cliext::deque<wchar_t>::const_reverse_iterator crend = c1.rend();
    for (; crit != crend; ++crit)
        System::Console::Write("{0} ", *crit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
```

## <a name="deque"></a> deque::deque (STL/CLR)

Constrói um objeto contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
deque();
deque(deque<Value>% right);
deque(deque<Value>^ right);
explicit deque(size_type count);
deque(size_type count, value_type val);
template<typename InIt>
    deque(InIt first, InIt last);
deque(System::Collections::Generic::IEnumerable<Value>^ right);
```

#### <a name="parameters"></a>Parâmetros

*count*<br/>
Número de elementos a inserir.

*first*<br/>
Início do intervalo a ser inserido.

*last*<br/>
Fim do intervalo a inserir.

*right*<br/>
Objeto ou intervalo a inserir.

*val*<br/>
Valor do elemento a ser inserido.

### <a name="remarks"></a>Comentários

O construtor:

`deque();`

inicializa a sequência controlada com nenhum elemento. Você pode usá-lo para especificar uma sequência controlada inicial vazia.

O construtor:

`deque(deque<Value>% right);`

inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto do deque *certa*. Para obter mais informações sobre iteradores, consulte [deque (STL/CLR)](#begin) e [deque:: end (STL/CLR)](#end).

O construtor:

`deque(deque<Value>^ right);`

inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto do deque cujo identificador é *certa*.

O construtor:

`explicit deque(size_type count);`

inicializa a sequência controlada com *contagem* elementos com valor `value_type()`. Você usá-lo para preencher o contêiner com elementos tudo que tem o valor padrão.

O construtor:

`deque(size_type count, value_type val);`

inicializa a sequência controlada com *contagem* elementos com valor de *val*. Você usá-lo para preencher o contêiner com elementos tudo que tem o mesmo valor.

O construtor:

`template<typename InIt>`

`deque(InIt first, InIt last);`

inicializa a sequência controlada com a sequência [`first`, `last`). Você pode usá-lo para fazer uma cópia de outra sequência a sequência controlada.

O construtor:

`deque(System::Collections::Generic::IEnumerable<Value>^ right);`

inicializa a sequência controlada com a sequência designada pelo enumerador *certa*. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_construct.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
// construct an empty container
    cliext::deque<wchar_t> c1;
    System::Console::WriteLine("size() = {0}", c1.size());

    // construct with a repetition of default values
    cliext::deque<wchar_t> c2(3);
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", (int)elem);
    System::Console::WriteLine();

    // construct with a repetition of values
    cliext::deque<wchar_t> c3(6, L'x');
    for each (wchar_t elem in c3)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an iterator range
    cliext::deque<wchar_t>::iterator it = c3.end();
    cliext::deque<wchar_t> c4(c3.begin(), --it);
    for each (wchar_t elem in c4)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an enumeration
    cliext::deque<wchar_t> c5(   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);
    for each (wchar_t elem in c5)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct by copying another container
    cliext::deque<wchar_t> c7(c3);
    for each (wchar_t elem in c7)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct by copying a container handle
    cliext::deque<wchar_t> c8(%c3);
    for each (wchar_t elem in c8)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    return (0);
    }
```

```Output
size() = 0
0 0 0
x x x x x x
x x x x x
x x x x x x
x x x x x x
x x x x x x
```

## <a name="difference_type"></a> deque::difference_type (STL/CLR)

Os tipos de uma distância com sinal entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int difference_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem com sinal de elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_difference_type.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // compute positive difference
    cliext::deque<wchar_t>::difference_type diff = 0;
    for (cliext::deque<wchar_t>::iterator it = c1.begin();
        it != c1.end(); ++it) ++diff;
    System::Console::WriteLine("end()-begin() = {0}", diff);

    // compute negative difference
    diff = 0;
    for (cliext::deque<wchar_t>::iterator it = c1.end();
        it != c1.begin(); --it) --diff;
    System::Console::WriteLine("begin()-end() = {0}", diff);
    return (0);
    }
```

```Output
a b c
end()-begin() = 3
begin()-end() = -3
```

## <a name="empty"></a> deque::empty (STL/CLR)

Testa se nenhum elemento está presente.

### <a name="syntax"></a>Sintaxe

```cpp
bool empty();
```

### <a name="remarks"></a>Comentários

A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [deque (STL/CLR)](#size)`() == 0`. Você pode usá-lo para testar se o deque estiver vazio.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_empty.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

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

## <a name="end"></a> deque::end (STL/CLR)

Designa o fim da sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator end();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador de acesso aleatório que aponta para logo após o fim da sequência controlada. Use-o para obter um iterador que designa o fim `current` da sequência controlada, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_end.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect last two items
    cliext::deque<wchar_t>::iterator it = c1.end();
    --it;
    System::Console::WriteLine("*-- --end() = {0}", *--it);
    System::Console::WriteLine("*--end() = {0}", *++it);

    // alter first two items and reinspect
    *--it = L'x';
    *++it = L'y';
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
*-- --end() = b
*--end() = c
a x y
```

## <a name="erase"></a> deque::erase (STL/CLR)

Remove os elementos em posições especificadas.

### <a name="syntax"></a>Sintaxe

```cpp
iterator erase(iterator where);
iterator erase(iterator first, iterator last);
```

#### <a name="parameters"></a>Parâmetros

*first*<br/>
Início do intervalo a ser apagado.

*last*<br/>
Fim do intervalo a ser apagado.

*where*<br/>
Elemento a ser apagado.

### <a name="remarks"></a>Comentários

A primeira função membro remove o elemento da sequência controlada apontada por *onde*. Você pode usá-lo para remover um único elemento.

A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`). Você pode usá-lo para remover a zero ou mais elementos contíguos.

Ambas as funções membro retornam um iterador que designa o primeiro elemento restante além de todos os elementos removidos ou [deque:: end (STL/CLR)](#end) `()` se não houver tal elemento.

Ao apagar elementos, o número de cópias de elemento é linear no número de elementos entre o fim de apagamento e final da sequência mais próximo. (Ao apagar uma ou mais elementos em ambas as extremidades da sequência, nenhuma cópia do elemento ocorre.)

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_erase.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // erase an element and reinspect
    System::Console::WriteLine("erase(begin()) = {0}",
        *c1.erase(c1.begin()));

    // add elements and display " b c d e"
    c1.push_back(L'd');
    c1.push_back(L'e');
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // erase all but end
    cliext::deque<wchar_t>::iterator it = c1.end();
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

## <a name="front"></a> deque::front (STL/CLR)

Acessa o primeiro elemento.

### <a name="syntax"></a>Sintaxe

```cpp
reference front();
```

### <a name="remarks"></a>Comentários

A função membro retorna uma referência para o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o primeiro elemento, quando você souber que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_front.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first item
    System::Console::WriteLine("front() = {0}", c1.front());

    // alter first item and reinspect
    c1.front() = L'x';
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
front() = a
x b c
```

## <a name="front_item"></a> deque::front_item (STL/CLR)

Acessa o primeiro elemento.

### <a name="syntax"></a>Sintaxe

```cpp
property value_type front_item;
```

### <a name="remarks"></a>Comentários

A propriedade acessa o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para ler ou gravar o primeiro elemento, quando você souber que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_front_item.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first item
    System::Console::WriteLine("front_item = {0}", c1.front_item);

    // alter first item and reinspect
    c1.front_item = L'x';
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
front_item = a
x b c
```

## <a name="generic_container"></a> deque::generic_container (STL/CLR)

O tipo da interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::
    IDeque<generic_value>
    generic_container;
```

### <a name="remarks"></a>Comentários

O tipo descreve a interface genérica para essa classe de contêiner do modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_generic_container.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    cliext::deque<wchar_t>::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify generic and display original
    gc1->insert(gc1->end(), L'd');
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify original and display generic
    c1.push_back(L'e');

    System::Collections::IEnumerator^ enum1 =
        gc1->GetEnumerator();
    while (enum1->MoveNext())
        System::Console::Write("{0} ", enum1->Current);
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

## <a name="generic_iterator"></a> deque::generic_iterator (STL/CLR)

O tipo de um iterador para uso com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::Generic::
    ContainerRandomAccessIterator<generic_value> generic_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um iterador genérico que pode ser usado com a interface genérica para essa classe de contêiner do modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_generic_iterator.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    cliext::deque<wchar_t>::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify generic and display original
    cliext::deque<wchar_t>::generic_iterator gcit = gc1->begin();
    cliext::deque<wchar_t>::generic_value gcval = *gcit;
    *++gcit = gcval;
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
a a c
```

## <a name="generic_reverse_iterator"></a> deque::generic_reverse_iterator (STL/CLR)

O tipo de um iterador inverso para uso com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::Generic::
    ReverseRandomAccessIterator<generic_value> generic_reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um iterador inverso genérico que pode ser usado com a interface genérica para essa classe de contêiner do modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_generic_reverse_iterator.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    cliext::deque<wchar_t>::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify generic and display original
    cliext::deque<wchar_t>::generic_reverse_iterator gcit = gc1->rbegin();
    cliext::deque<wchar_t>::generic_value gcval = *gcit;
    *++gcit = gcval;
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
a c c
```

## <a name="generic_value"></a> deque::generic_value (STL/CLR)

O tipo de um elemento para uso com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef GValue generic_value;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo `GValue` que descreve o valor de elemento armazenado para uso com a interface genérica para essa classe de contêiner do modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_generic_value.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    cliext::deque<wchar_t>::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify generic and display original
    cliext::deque<wchar_t>::generic_iterator gcit = gc1->begin();
    cliext::deque<wchar_t>::generic_value gcval = *gcit;
    *++gcit = gcval;
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
a a c
```

## <a name="insert"></a> deque::insert (STL/CLR)

Adiciona os elementos em uma posição especificada.

### <a name="syntax"></a>Sintaxe

```cpp
iterator insert(iterator where, value_type val);
void insert(iterator where, size_type count, value_type val);
template<typename InIt>
    void insert(iterator where, InIt first, InIt last);
void insert(iterator where,
    System::Collections::Generic::IEnumerable<Value>^ right);
```

#### <a name="parameters"></a>Parâmetros

*count*<br/>
Número de elementos a inserir.

*first*<br/>
Início do intervalo a ser inserido.

*last*<br/>
Fim do intervalo a inserir.

*right*<br/>
Enumeração a ser inserido.

*val*<br/>
Valor do elemento a ser inserido.

*where*<br/>
Onde no contêiner antes da qual inserir.

### <a name="remarks"></a>Comentários

Cada um dos membro funções inserções, antes do elemento apontado por *onde* na sequência controlada, uma sequência especificada pelos operandos restantes.

A primeira função membro insere um elemento com o valor *val* e retorna um iterador que designa o elemento recém-inserido. Você pode usá-lo para inserir um único elemento antes de um local designado por um iterador.

A segunda função membro insere uma repetição de *contagem* elementos de valor *val*. Você pode usá-lo para inserir zero ou mais elementos adjacentes que são todas as cópias do mesmo valor.

Se `InIt` for um tipo inteiro, a terceira função membro se comportará da mesma forma que `insert(where, (size_type)first, (value_type)last)`. Caso contrário, ele insere a sequência [`first`, `last`). Você pode usá-lo para inserir a zero ou mais elementos contíguos copiados de outra sequência.

A quarta função membro insere a sequência designada pela *certa*. Você pode usá-lo para inserir uma sequência descrita por um enumerador.

Ao inserir um único elemento, o número de cópias de elemento é linear no número de elementos entre o ponto de inserção e a extremidade mais próximo da sequência. (Ao inserir um ou mais elementos em ambas as extremidades da sequência, não há cópias de elemento ocorrem). Se `InIt` é um iterador de entrada, a terceira função membro efetivamente executa uma inserção única para cada elemento na sequência. Caso contrário, quando inserindo `N` elementos, o número de cópias de elemento é linear no `N` mais o número de elementos entre o ponto de inserção e a extremidade mais próximo da sequência.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_insert.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // insert a single value using iterator
    cliext::deque<wchar_t>::iterator it = c1.begin();
    System::Console::WriteLine("insert(begin()+1, L'x') = {0}",
        *c1.insert(++it, L'x'));
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // insert a repetition of values
    cliext::deque<wchar_t> c2;
    c2.insert(c2.begin(), 2, L'y');
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // insert an iterator range
    it = c1.end();
    c2.insert(c2.end(), c1.begin(), --it);
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // insert an enumeration
    c2.insert(c2.begin(),   // NOTE: cast is not needed
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);
    for each (wchar_t elem in c2)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
insert(begin()+1, L'x') = x
a x b c
y y
y y a x b
a x b c y y a x b
```

## <a name="iterator"></a> deque::iterator (STL/CLR)

O tipo de um iterador para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T1 iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo não especificado `T1` que pode servir como um iterador de acesso aleatório para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_iterator.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    cliext::deque<wchar_t>::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        System::Console::Write("{0} ", *it);
    System::Console::WriteLine();

    // alter first element and redisplay
    it = c1.begin();
    *it = L'x';
    for (; it != c1.end(); ++it)
        System::Console::Write("{0} ", *it);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
x b c
```

## <a name="op_neq"></a> deque::operator!= (STL/CLR)

Deque não igual a comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value>
    bool operator!=(deque<Value>% left,
        deque<Value>% right);
```

#### <a name="parameters"></a>Parâmetros

*left*<br/>
Contêiner esquerdo a comparar.

*right*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

Retorna a função de operador `!(left == right)`. Usá-lo para testar se *esquerdo* não for ordenado igual *direita* quando os dois deques serão comparado elemento por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_operator_ne.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    cliext::deque<wchar_t> c2;
    c2.push_back(L'a');
    c2.push_back(L'b');
    c2.push_back(L'd');

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

## <a name="operator"></a> deque::operator(STL/CLR)

Acessa um elemento em uma posição especificada.

### <a name="syntax"></a>Sintaxe

```cpp
reference operator[](size_type pos);
```

#### <a name="parameters"></a>Parâmetros

*pos*<br/>
Posição do elemento a acessar.

### <a name="remarks"></a>Comentários

O operador de membro retorna um referene para o elemento na posição *pos*. Você pode usá-lo para acessar um elemento cuja posição em que você sabe.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_operator_sub.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c" using subscripting
    for (int i = 0; i < c1.size(); ++i)
        System::Console::Write("{0} ", c1[i]);
    System::Console::WriteLine();

    // change an entry and redisplay
    c1[1] = L'x';
    for (int i = 0; i < c1.size(); ++i)
        System::Console::Write("{0} ", c1[i]);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a x c
```

## <a name="pop_back"></a> deque::pop_back (STL/CLR)

Remove o último elemento.

### <a name="syntax"></a>Sintaxe

```cpp
void pop_back();
```

### <a name="remarks"></a>Comentários

A função membro remove o último elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para encurtar o deque por um elemento na parte traseira.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_pop_back.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // pop an element and redisplay
    c1.pop_back();
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b
```

## <a name="pop_front"></a> deque::pop_front (STL/CLR)

Remove o primeiro elemento.

### <a name="syntax"></a>Sintaxe

```cpp
void pop_front();
```

### <a name="remarks"></a>Comentários

A função de membro remove o primeiro elemento da sequência controlada, que deve ser não vazio. Você pode usá-lo para encurtar o deque por um elemento na frente.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_pop_front.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // pop an element and redisplay
    c1.pop_front();
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
b c
```

## <a name="push_back"></a> deque::push_back (STL/CLR)

Adiciona um novo último elemento.

### <a name="syntax"></a>Sintaxe

```cpp
void push_back(value_type val);
```

### <a name="remarks"></a>Comentários

A função membro insere um elemento com valor `val` no final da sequência controlada. Você pode usá-lo para acrescentar a outro elemento ao deque.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_push_back.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="push_front"></a> deque::push_front (STL/CLR)

Adiciona um novo elemento primeiro.

### <a name="syntax"></a>Sintaxe

```cpp
void push_front(value_type val);
```

### <a name="remarks"></a>Comentários

A função membro insere um elemento com valor `val` no início da sequência controlada. Você pode usá-lo para preceder a outro elemento ao deque.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_push_front.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_front(L'a');
    c1.push_front(L'b');
    c1.push_front(L'c');

    // display contents " c b a"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
```

## <a name="rbegin"></a> deque::rbegin (STL/CLR)

Designa o início da sequência controlada invertida.

### <a name="syntax"></a>Sintaxe

```cpp
reverse_iterator rbegin();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador inverso que designa o último elemento da sequência controlada ou logo após o início de uma sequência vazia. Portanto, ele designa o `beginning` da sequência invertida. Use-o para obter um iterador que designa o início `current` da sequência controlada que é vista na ordem inversa, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_rbegin.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first two items in reversed sequence
    cliext::deque<wchar_t>::reverse_iterator rit = c1.rbegin();
    System::Console::WriteLine("*rbegin() = {0}", *rit);
    System::Console::WriteLine("*++rbegin() = {0}", *++rit);

    // alter first two items and reinspect
    *--rit = L'x';
    *++rit = L'y';
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
*rbegin() = c
*++rbegin() = b
a y x
```

## <a name="reference"></a> deque::reference (STL/CLR)

O tipo de uma referência para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência a um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_reference.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    cliext::deque<wchar_t>::iterator it = c1.begin();
    for (; it != c1.end(); ++it)
        {   // get a reference to an element
        cliext::deque<wchar_t>::reference ref = *it;
        System::Console::Write("{0} ", ref);
        }
    System::Console::WriteLine();

    // modify contents " a b c"
    for (it = c1.begin(); it != c1.end(); ++it)
        {   // get a reference to an element
        cliext::deque<wchar_t>::reference ref = *it;

        ref += (wchar_t)(L'A' - L'a');
        System::Console::Write("{0} ", ref);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
A B C
```

## <a name="rend"></a> deque::rend (STL/CLR)

Designa o fim da sequência controlada invertida.

### <a name="syntax"></a>Sintaxe

```cpp
reverse_iterator rend();
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador inverso que aponta logo após o início da sequência controlada. Portanto, ele designa o `end` da sequência invertida. Use-o para obter um iterador que designa o fim `current` da sequência controlada vista na ordem inversa, mas seu status poderá mudar se o tamanho da sequência controlada for alterado.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_rend.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect first two items
    cliext::deque<wchar_t>::reverse_iterator rit = c1.rend();
    --rit;
    System::Console::WriteLine("*-- --rend() = {0}", *--rit);
    System::Console::WriteLine("*--rend() = {0}", *++rit);

    // alter first two items and reinspect
    *--rit = L'x';
    *++rit = L'y';
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
*-- --rend() = b
*--rend() = a
y x c
```

## <a name="resize"></a> deque::resize (STL/CLR)

Altera o número de elementos.

### <a name="syntax"></a>Sintaxe

```cpp
void resize(size_type new_size);
void resize(size_type new_size, value_type val);
```

#### <a name="parameters"></a>Parâmetros

*new_size*<br/>
Novo tamanho da sequência controlada.

*val*<br/>
Valor do elemento de preenchimento.

### <a name="remarks"></a>Comentários

As funções membro de ambos os Verifique [deque (STL/CLR)](#size) `()` daqui em diante retorna *new_size*. Se for necessário tornar a sequência controlada mais longa, a primeira função membro acrescentará elementos com valor `value_type()`, enquanto a segunda função membro acrescentará elementos com valor *val*. Para tornar a sequência controlada mais curta, ambas as funções membro efetivamente apagar o último elemento [deque (STL/CLR)](#size) `() -` `new_size` vezes. Você pode usá-lo para garantir que a sequência controlada tem tamanho *new_size*, filtragem ou preenchimento atual sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_resize.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
// construct an empty container and pad with default values
    cliext::deque<wchar_t> c1;
    System::Console::WriteLine("size() = {0}", c1.size());
    c1.resize(4);
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", (int)elem);
    System::Console::WriteLine();

    // resize to empty
    c1.resize(0);
    System::Console::WriteLine("size() = {0}", c1.size());

    // resize and pad
    c1.resize(5, L'x');
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
size() = 0
0 0 0 0
size() = 0
x x x x x
```

## <a name="reverse_iterator"></a> deque::reverse_iterator (STL/CLR)

O tipo de um iterador inverso para a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
typedef T3 reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo não especificado `T3` que pode servir como um iterador inverso para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_reverse_iterator.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c" reversed
    cliext::deque<wchar_t>::reverse_iterator rit = c1.rbegin();
    for (; rit != c1.rend(); ++rit)
        System::Console::Write("{0} ", *rit);
    System::Console::WriteLine();

    // alter first element and redisplay
    rit = c1.rbegin();
    *rit = L'x';
    for (; rit != c1.rend(); ++rit)
        System::Console::Write("{0} ", *rit);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
x b a
```

## <a name="size"></a> deque::size (STL/CLR)

Conta o número de elementos.

### <a name="syntax"></a>Sintaxe

```cpp
size_type size();
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência controlada. Você pode usá-lo para determinar o número de elementos que estão na sequência controlada. Se você se preocupa se a sequência tem tamanho diferente de zero, consulte [deque:: Empty (STL/CLR)](#empty)`()`.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_size.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine("size() = {0} starting with 3", c1.size());

    // clear the container and reinspect
    c1.clear();
    System::Console::WriteLine("size() = {0} after clearing", c1.size());

    // add elements and clear again
    c1.push_back(L'a');
    c1.push_back(L'b');
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

## <a name="size_type"></a> deque::size_type (STL/CLR)

O tipo de uma distância com sinal entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int size_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elemento não negativo.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_size_type.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // compute positive difference
    cliext::deque<wchar_t>::size_type diff = c1.end() - c1.begin();
    System::Console::WriteLine("end()-begin() = {0}", diff);
    return (0);
    }
```

```Output
a b c
end()-begin() = 3
```

## <a name="swap"></a> deque::swap (STL/CLR)

Alterna o conteúdo de dois contêineres.

### <a name="syntax"></a>Sintaxe

```cpp
void swap(deque<Value>% right);
```

#### <a name="parameters"></a>Parâmetros

*right*<br/>
Contêiner com o qual trocar conteúdos.

### <a name="remarks"></a>Comentários

A função membro troca as sequências controladas entre `*this` e *direito*. Ele faz isso em tempo constante e não gera exceções. Você pode usá-lo como uma maneira rápida para trocar o conteúdo de dois contêineres.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_swap.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct another container with repetition of values
    cliext::deque<wchar_t> c2(5, L'x');
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

## <a name="to_array"></a> deque::to_array (STL/CLR)

Copia a sequência controlada para uma nova matriz.

### <a name="syntax"></a>Sintaxe

```cpp
cli::array<Value>^ to_array();
```

### <a name="remarks"></a>Comentários

A função membro retorna uma matriz que contém a sequência controlada. Você pode usá-lo para obter uma cópia da sequência controlada em forma de matriz.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_to_array.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // copy the container and modify it
    cli::array<wchar_t>^ a1 = c1.to_array();

    c1.push_back(L'd');
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

## <a name="value_type"></a> deque::value_type (STL/CLR)

O tipo de um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo *valor*.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_value_type.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c" using value_type
    for (cliext::deque<wchar_t>::iterator it = c1.begin();
        it != c1.end(); ++it)
        {   // store element in value_type object
        cliext::deque<wchar_t>::value_type val = *it;

        System::Console::Write("{0} ", val);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="op_lt"></a> operator&lt; (deque) (STL/CLR)

Deque menor do que a comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value>
    bool operator<(deque<Value>% left,
        deque<Value>% right);
```

#### <a name="parameters"></a>Parâmetros

*left*<br/>
Contêiner esquerdo a comparar.

*right*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

O operador função retornará true se, para a posição mais baixa `i` para o qual `!(right[i] < left[i])` é verdade também que `left[i] < right[i]`. Caso contrário, retornará `left->size() < right->size()` usá-lo para testar se *esquerdo* é ordenado antes *direita* quando os dois deques serão comparado elemento por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_operator_lt.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    cliext::deque<wchar_t> c2;
    c2.push_back(L'a');
    c2.push_back(L'b');
    c2.push_back(L'd');

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

## <a name="op_lteq"></a> operator&lt;= (deque) (STL/CLR)

Deque menor ou igual comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value>
    bool operator<=(deque<Value>% left,
        deque<Value>% right);
```

#### <a name="parameters"></a>Parâmetros

*left*<br/>
Contêiner esquerdo a comparar.

*right*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

Retorna a função de operador `!(right < left)`. Usá-lo para testar se *esquerdo* não for ordenado após *direita* quando os dois deques serão comparado elemento por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_operator_le.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    cliext::deque<wchar_t> c2;
    c2.push_back(L'a');
    c2.push_back(L'b');
    c2.push_back(L'd');

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

## <a name="op_as"></a> operator= (deque) (STL/CLR)

Substitui a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
deque<Value>% operator=(deque<Value>% right);
```

#### <a name="parameters"></a>Parâmetros

*right*<br/>
O contêiner a ser copiado.

### <a name="remarks"></a>Comentários

As cópias de operador de membro *certa* ao objeto, em seguida, retorna `*this`. Você pode usá-lo para substituir a sequência controlada por uma cópia da sequência controlada no *certa*.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_operator_as.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    cliext::deque<wchar_t> c2;
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

## <a name="op_eq"></a> operator== (deque) (STL/CLR)

Comparação de igualdade do deque.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value>
    bool operator==(deque<Value>% left,
        deque<Value>% right);
```

#### <a name="parameters"></a>Parâmetros

*left*<br/>
Contêiner esquerdo a comparar.

*right*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função de operador retornará true somente se as sequências controladas por *esquerdo* e *à direita* têm o mesmo tamanho e, para cada posição `i`, `left[i] ==` `right[i]`. Usá-lo para testar se *esquerdo* é ordenada igual *direita* quando os dois deques serão comparado elemento por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_operator_eq.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    cliext::deque<wchar_t> c2;
    c2.push_back(L'a');
    c2.push_back(L'b');
    c2.push_back(L'd');

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

## <a name="op_gt"></a> operator&gt; (deque) (STL/CLR)

Maior que a comparação do deque.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value>
    bool operator>(deque<Value>% left,
        deque<Value>% right);
```

#### <a name="parameters"></a>Parâmetros

*left*<br/>
Contêiner esquerdo a comparar.

*right*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

Retorna a função de operador `right` `<` `left`. Usá-lo para testar se *esquerdo* é ordenada após *direita* quando os dois deques serão comparado elemento por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_operator_gt.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    cliext::deque<wchar_t> c2;
    c2.push_back(L'a');
    c2.push_back(L'b');
    c2.push_back(L'd');

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

## <a name="op_gteq"></a> operator&gt;= (deque) (STL/CLR)

Comparação de maior que ou igual do deque.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value>
    bool operator>=(deque<Value>% left,
        deque<Value>% right);
```

#### <a name="parameters"></a>Parâmetros

*left*<br/>
Contêiner esquerdo a comparar.

*right*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

Retorna a função de operador `!(left` `<` `right)`. Você pode usá-lo para testar se *à esquerda* não for ordenado antes *à direita* quando os dois deques serão comparado elemento por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_deque_operator_ge.cpp
// compile with: /clr
#include <cliext/deque>

int main()
    {
    cliext::deque<wchar_t> c1;
    c1.push_back(L'a');
    c1.push_back(L'b');
    c1.push_back(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    cliext::deque<wchar_t> c2;
    c2.push_back(L'a');
    c2.push_back(L'b');
    c2.push_back(L'd');

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