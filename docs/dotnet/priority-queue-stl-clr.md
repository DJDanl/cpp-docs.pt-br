---
title: priority_queue (STL/CLR)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- cliext::priority_queue
- cliext::priority_queue::assign
- cliext::priority_queue::const_reference
- cliext::priority_queue::container_type
- cliext::priority_queue::difference_type
- cliext::priority_queue::empty
- cliext::priority_queue::generic_container
- cliext::priority_queue::generic_value
- cliext::priority_queue::get_container
- cliext::priority_queue::operator=
- cliext::priority_queue::pop
- cliext::priority_queue::priority_queue
- cliext::priority_queue::push
- cliext::priority_queue::reference
- cliext::priority_queue::size
- cliext::priority_queue::size_type
- cliext::priority_queue::to_array
- cliext::priority_queue::top
- cliext::priority_queue::top_item
- cliext::priority_queue::value_comp
- cliext::priority_queue::value_compare
- cliext::priority_queue::value_type
helpviewer_keywords:
- priority_queue class [STL/CLR]
- <queue> header [STL/CLR]
- <cliext/queue> header [STL/CLR]
- assign member [STL/CLR]
- const_reference member [STL/CLR]
- container_type member [STL/CLR]
- difference_type member [STL/CLR]
- empty member [STL/CLR]
- generic_container member [STL/CLR]
- generic_value member [STL/CLR]
- get_container member [STL/CLR]
- operator= member [STL/CLR]
- pop member [STL/CLR]
- priority_queue member [STL/CLR]
- push member [STL/CLR]
- reference member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- to_array member [STL/CLR]
- top member [STL/CLR]
- top_item member [STL/CLR]
- value_comp member [STL/CLR]
- value_compare member [STL/CLR]
- value_type member [STL/CLR]
ms.assetid: 4d0000d3-68ff-4c4b-8157-7060540136f5
ms.openlocfilehash: e21e7ba4dc3a4ed270548506ac1a9e37a2c1a23a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208462"
---
# <a name="priority_queue-stlclr"></a>priority_queue (STL/CLR)

A classe de modelo descreve um objeto que controla uma sequência ordenada de comprimento variável de elementos que tem acesso limitado. Você usa o adaptador de contêiner `priority_queue` para gerenciar um contêiner subjacente como uma fila de prioridade.

Na descrição abaixo, `GValue` é igual ao *valor* , a menos que o último seja um tipo ref; nesse caso, ele é `Value^`. Da mesma forma, `GContainer` é o mesmo que o *contêiner* , a menos que o último seja um tipo ref; nesse caso, ele é `Container^`.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Value,
    typename Container>
    ref class priority_queue
        System::ICloneable,
        Microsoft::VisualC::StlClr::IPriorityQueue<GValue, GContainer>
    { ..... };
```

### <a name="parameters"></a>parâmetros

*Valor*<br/>
O tipo de um elemento na sequência controlada.

*Contêiner*<br/>
O tipo do contêiner subjacente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<cliext/fila >

**Namespace:** cliext

## <a name="declarations"></a>{1&gt;{2&gt;Declarações&lt;2}&lt;1}

|Definição do tipo|DESCRIÇÃO|
|---------------------|-----------------|
|[priority_queue::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|
|[priority_queue::container_type (STL/CLR)](#container_type)|O tipo do contêiner subjacente.|
|[priority_queue::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|
|[priority_queue::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o adaptador do contêiner.|
|[priority_queue::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o adaptador de contêiner.|
|[priority_queue::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|
|[priority_queue::size_type (STL/CLR)](#size_type)|O tipo de uma distância com sinal entre dois elementos.|
|[priority_queue::value_compare (STL/CLR)](#value_compare)|O delegado de ordenação para dois elementos.|
|[priority_queue::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|

|Função membro|DESCRIÇÃO|
|---------------------|-----------------|
|[priority_queue::assign (STL/CLR)](#assign)|Substitui todos os elementos.|
|[priority_queue::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|
|[priority_queue::get_container (STL/CLR)](#get_container)|Acessa o contêiner subjacente.|
|[priority_queue::pop (STL/CLR)](#pop)|Remove o elemento hghest-Priority.|
|[priority_queue::priority_queue (STL/CLR)](#priority_queue)|Constrói um objeto contêiner.|
|[priority_queue::push (STL/CLR)](#push)|Adiciona um novo elemento.|
|[priority_queue::size (STL/CLR)](#size)|Conta o número de elementos.|
|[priority_queue::top (STL/CLR)](#top)|Acessa o elemento de prioridade mais alta.|
|[priority_queue::to_array (STL/CLR)](#to_array)|Copia a sequência controlada em uma nova matriz.|
|[priority_queue::value_comp (STL/CLR)](#value_comp)|Copia o delegado de ordenação para dois elementos.|

|Propriedade|DESCRIÇÃO|
|--------------|-----------------|
|[priority_queue::top_item (STL/CLR)](#top_item)|Acessa o elemento de prioridade mais alta.|

|Operador|DESCRIÇÃO|
|--------------|-----------------|
|[priority_queue::operator= (STL/CLR)](#op_as)|Substitui a sequência controlada.|

## <a name="interfaces"></a>Interfaces

|Interface|DESCRIÇÃO|
|---------------|-----------------|
|<xref:System.ICloneable>|Duplicar um objeto.|
|IPriorityQueue\<valor, contêiner >|Mantenha o adaptador de contêiner genérico.|

## <a name="remarks"></a>Comentários

O objeto aloca e libera o armazenamento para a sequência que ele controla por meio de um contêiner subjacente, do tipo `Container`, que armazena `Value` elementos e cresce sob demanda. Ele mantém a sequência ordenada como um heap, com o elemento de prioridade mais alta (o elemento superior) prontamente acessível e removível. O objeto restringe o acesso para enviar novos elementos por push e retirar apenas o elemento de prioridade mais alta, implementando uma fila de prioridade.

O objeto ordena a sequência que ele controla chamando um objeto delegado armazenado do tipo [priority_queue:: value_compare (STL/CLR)](../dotnet/priority-queue-value-compare-stl-clr.md). Você pode especificar o objeto delegado armazenado ao construir o priority_queue; Se você não especificar nenhum objeto delegado, o padrão será a `operator<(value_type, value_type)`de comparação. Você acessa esse objeto armazenado chamando a função membro [priority_queue:: value_comp (STL/CLR)](../dotnet/priority-queue-value-comp-stl-clr.md)`()`.

Esse objeto delegado deve impor uma ordenação fraca estrita em valores do tipo [priority_queue:: value_type (STL/CLR)](../dotnet/priority-queue-value-type-stl-clr.md). Isso significa que, para quaisquer duas chaves `X` e `Y`:

`value_comp()(X, Y)` retorna o mesmo resultado booliano em cada chamada.

Se `value_comp()(X, Y)` for true, `value_comp()(Y, X)` deverá ser false.

Se `value_comp()(X, Y)` for true, `X` será considerado como ordenado antes de `Y`.

Se `!value_comp()(X, Y) && !value_comp()(Y, X)` for true, `X` e `Y` serão considerados como uma ordenação equivalente.

Para qualquer elemento `X` que preceda `Y` na sequência controlada, `key_comp()(Y, X)` é false. (Para o objeto delegado padrão, as chaves nunca diminuem em valor.)

O elemento de prioridade mais alta é, portanto, um dos elementos que não são ordenados antes de qualquer outro elemento.

Como o contêiner subjacente mantém os elementos ordenados como um heap:

O contêiner deve oferecer suporte a iteradores de acesso aleatório.

Elementos com ordenação equivalente podem ser retirados em uma ordem diferente da que foram enviados por push. (A ordem não é estável.)

Assim, os candidatos ao contêiner subjacente incluem [deque (STL/CLR)](../dotnet/deque-stl-clr.md) e [vector (STL/CLR)](../dotnet/vector-stl-clr.md).

## <a name="members"></a>Membros

## <a name="priority_queueassign-stlclr"></a><a name="assign"></a>priority_queue:: assign (STL/CLR)

Substitui todos os elementos.

### <a name="syntax"></a>Sintaxe

```cpp
void assign(priority_queue<Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*right*<br/>
Adaptador de contêiner a ser inserido.

### <a name="remarks"></a>Comentários

A função de membro atribui `right.get_container()` ao contêiner subjacente. Você o usa para alterar todo o conteúdo da fila.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_assign.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign a repetition of values
    Mypriority_queue c2;
    c2.assign(c1);
    for each (wchar_t elem in c2.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
c a b
```

## <a name="priority_queueconst_reference-stlclr"></a><a name="const_reference"></a>priority_queue:: const_reference (STL/CLR)

O tipo de uma referência de constante para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% const_reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência constante para um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_const_reference.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display reversed contents " c b a"
    for (; !c1.empty(); c1.pop())
        {   // get a const reference to an element
        Mypriority_queue::const_reference cref = c1.top();
        System::Console::Write("{0} ", cref);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
```

## <a name="priority_queuecontainer_type-stlclr"></a><a name="container_type"></a>priority_queue:: container_type (STL/CLR)

O tipo do contêiner subjacente.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Container value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Container`.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_container_type.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display contents " a b c" using container_type
    Mypriority_queue::container_type wc1 = c1.get_container();
    for each (wchar_t elem in wc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
```

## <a name="priority_queuedifference_type-stlclr"></a><a name="difference_type"></a>priority_queue::d ifference_type (STL/CLR)

Os tipos de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int difference_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos possivelmente negativo.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_difference_type.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // compute negative difference
    Mypriority_queue::difference_type diff = c1.size();
    c1.push(L'd');
    c1.push(L'e');
    diff -= c1.size();
    System::Console::WriteLine("pushing 2 = {0}", diff);

    // compute positive difference
    diff = c1.size();
    c1.pop();
    c1.pop();
    c1.pop();
    diff -= c1.size();
    System::Console::WriteLine("popping 3 = {0}", diff);
    return (0);
    }
```

```Output
c a b
pushing 2 = -2
popping 3 = 3
```

## <a name="priority_queueempty-stlclr"></a><a name="empty"></a>priority_queue:: Empty (STL/CLR)

Testa se nenhum elemento está presente.

### <a name="syntax"></a>Sintaxe

```cpp
bool empty();
```

### <a name="remarks"></a>Comentários

A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [priority_queue:: Size (STL/CLR)](../dotnet/priority-queue-size-stl-clr.md)`() == 0`. Você o usa para testar se o priority_queue está vazio.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_empty.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine("size() = {0}", c1.size());
    System::Console::WriteLine("empty() = {0}", c1.empty());

    // clear the container and reinspect
    c1.pop();
    c1.pop();
    c1.pop();
    System::Console::WriteLine("size() = {0}", c1.size());
    System::Console::WriteLine("empty() = {0}", c1.empty());
    return (0);
    }
```

```Output
c a b
size() = 3
empty() = False
size() = 0
empty() = True
```

## <a name="priority_queuegeneric_container-stlclr"></a><a name="generic_container"></a>priority_queue:: generic_container (STL/CLR)

O tipo da interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::IPriorityQueue<Value>
    generic_container;
```

### <a name="remarks"></a>Comentários

O tipo descreve a interface genérica para essa classe de adaptador de contêiner de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_generic_container.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct a generic container
    Mypriority_queue::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1->get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify generic and display original
    gc1->push(L'd');
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify original and display generic
    c1.push(L'e');
    for each (wchar_t elem in gc1->get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
c a b
d c b a
e d b a c
```

## <a name="priority_queuegeneric_value-stlclr"></a><a name="generic_value"></a>priority_queue:: generic_value (STL/CLR)

O tipo de um elemento a ser usado com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef GValue generic_value;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo `GValue` que descreve o valor do elemento armazenado para uso com a interface genérica para essa classe de contêiner de modelo. (`GValue` será `value_type` ou `value_type^` se `value_type` for um tipo de referência.)

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_generic_value.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // get interface to container
    Mypriority_queue::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1->get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // display in priority order using generic_value
    for (; !gc1->empty(); gc1->pop())
        {
        Mypriority_queue::generic_value elem = gc1->top();

        System::Console::Write("{0} ", elem);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
c a b
c b a
```

## <a name="priority_queueget_container-stlclr"></a><a name="get_container"></a>priority_queue:: get_container (STL/CLR)

Acessa o contêiner subjacente.

### <a name="syntax"></a>Sintaxe

```cpp
container_type get_container();
```

### <a name="remarks"></a>Comentários

A função membro retorna o contêiner subjacente. Você o usa para ignorar as restrições impostas pelo wrapper do contêiner.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_get_container.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
```

## <a name="priority_queueoperator-stlclr"></a><a name="op_as"></a>priority_queue:: Operator = (STL/CLR)

Substitui a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
priority_queue <Value, Container>% operator=(priority_queue <Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*right*<br/>
Adaptador de contêiner a ser copiado.

### <a name="remarks"></a>Comentários

O operador membro copia *diretamente* para o objeto e, em seguida, retorna `*this`. Você o usa para substituir a sequência controlada por uma cópia da sequência controlada *à direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_operator_as.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // assign to a new container
    Mypriority_queue c2;
    c2 = c1;
    for each (wchar_t elem in c2.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
c a b
```

## <a name="priority_queuepop-stlclr"></a><a name="pop"></a>priority_queue::p op (STL/CLR)

Remove o elemento proirity mais alto.

### <a name="syntax"></a>Sintaxe

```cpp
void pop();
```

### <a name="remarks"></a>Comentários

A função membro remove o elemento de prioridade mais alta da sequência controlada, que deve ser não vazia. Você o usa para encurtar a fila por um elemento na parte de trás.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_pop.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // pop an element and redisplay
    c1.pop();
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
b a
```

## <a name="priority_queuepriority_queue-stlclr"></a><a name="priority_queue"></a>priority_queue::p riority_queue (STL/CLR)

Constrói um objeto de adaptador de contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
priority_queue();
priority_queue(priority_queue<Value, Container> right);
priority_queue(priority_queue<Value, Container> right);
explicit priority_queue(value_compare^ pred);
priority_queue(value_compare^ pred, container_type% cont);
template<typename InIt>
    priority_queue(InIt first, InIt last);
template<typename InIt>
    priority_queue(InIt first, InIt last,
        value_compare^ pred);
template<typename InIt>
    priority_queue(InIt first, InIt last,
        value_compare^ pred, container_type% cont);
```

#### <a name="parameters"></a>parâmetros

*contínua*<br/>
O contêiner a ser copiado.

*first*<br/>
Início do intervalo a ser inserido.

*last*<br/>
Fim do intervalo a ser inserido.

*Pred*<br/>
Predicado de ordenação para a sequência controlada.

*right*<br/>
Objeto ou intervalo a inserir.

### <a name="remarks"></a>Comentários

O construtor:

`priority_queue();`

Cria um contêiner encapsulado vazio, com o predicado de ordenação padrão. Você o usa para especificar uma sequência controlada inicial vazia, com o predicado de ordenação padrão.

O construtor:

`priority_queue(priority_queue<Value, Container>% right);`

Cria um contêiner encapsulado que é uma cópia de `right.get_container()`, com o predicado de ordenação `right.value_comp()`. Você o usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de fila *direito*, com o mesmo predicado de ordenação.

O construtor:

`priority_queue(priority_queue<Value, Container>^ right);`

Cria um contêiner encapsulado que é uma cópia de `right->get_container()`, com o predicado de ordenação `right->value_comp()`. Você o usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de fila `*right`, com o mesmo predicado de ordenação.

O construtor:

`explicit priority_queue(value_compare^ pred);`

Cria um contêiner encapsulado vazio, com o predicado de ordenação *Pred*. Você o usa para especificar uma sequência controlada inicial vazia, com o predicado de ordenação especificado.

O construtor:

`priority_queue(value_compare^ pred, container_type cont);`

Cria um contêiner encapsulado vazio, com o predicado de ordenação *Pred*, em seguida, envia todos os elementos de *cont* . Use-os para especificar uma sequência controlada inicial de um contêiner existente, com o predicado de ordenação especificado.

O construtor:

`template<typename InIt> priority_queue(InIt first, InIt last);`

Cria um contêiner encapsulado vazio, com o predicado de ordenação padrão e, em seguida, envia por push a sequência [`first`, `last`). Você o usa para especificar uma sequência controlada inicial de um eqeuence especificado, com o predicado de ordenação especificado.

O construtor:

`template<typename InIt> priority_queue(InIt first, InIt last, value_compare^ pred);`

Cria um contêiner encapsulado vazio, com o predicado de ordenação *Pred*e, em seguida, envia a sequência [`first`, `last`). Você o usa para especificar uma sequência controlada inicial de um seqeuence especificado, com o predicado de ordenação especificado.

O construtor:

`template<typename InIt> priority_queue(InIt first, InIt last, value_compare^ pred, container_type% cont);`

Cria um contêiner encapsulado vazio, com o predicado de ordenação *Pred*, em seguida, envia todos os elementos de *cont* plus a sequence [`first`, `last`). Você o usa para especificar uma sequência controlada inicial de um contêiner existente e um seqeuence especificado, com o predicado de ordenação especificado.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_construct.cpp
// compile with: /clr
#include <cliext/queue>
#include <cliext/deque>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
typedef cliext::deque<wchar_t> Mydeque;
int main()
    {
// construct an empty container
    Mypriority_queue c1;
    Mypriority_queue::container_type^ wc1 = c1.get_container();
    System::Console::WriteLine("size() = {0}", c1.size());

    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');
    for each (wchar_t elem in wc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an ordering rule
    Mypriority_queue c2 = cliext::greater<wchar_t>();
    System::Console::WriteLine("size() = {0}", c2.size());

    for each (wchar_t elem in wc1)
        c2.push(elem);
    for each (wchar_t elem in c2.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an ordering rule by copying an underlying container
    Mypriority_queue c2x =
        gcnew Mypriority_queue(cliext::greater<wchar_t>(), *wc1);
   for each (wchar_t elem in c2x.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an iterator range
    Mypriority_queue c3(wc1->begin(), wc1->end());
    for each (wchar_t elem in c3.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an iterator range and an ordering rule
    Mypriority_queue c4(wc1->begin(), wc1->end(),
        cliext::greater<wchar_t>());
    for each (wchar_t elem in c4.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an iterator range, another container, and an ordering rule
    Mypriority_queue c5(wc1->begin(), wc1->end(),
        cliext::greater<wchar_t>(), *wc1);
    for each (wchar_t elem in c5.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct from a generic container
    Mypriority_queue c6(c3);
    for each (wchar_t elem in c6.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct by copying another container
    Mypriority_queue c7(%c3);
    for each (wchar_t elem in c7.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // construct with an ordering rule, by copying an underlying container
    Mypriority_queue c8 =
        gcnew Mypriority_queue(cliext::greater<wchar_t>(), *wc1);
    for each (wchar_t elem in c8.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    return (0);
    }
```

```Output
size() = 0
c a b
size() = 0
a c b
a c b
c a b
a c b
a a b c c b
c a b
c a b
a c b
```

## <a name="priority_queuepush-stlclr"></a><a name="push"></a>priority_queue::p USH (STL/CLR)

Adiciona um novo elemento.

### <a name="syntax"></a>Sintaxe

```cpp
void push(value_type val);
```

### <a name="remarks"></a>Comentários

A função membro insere um elemento com valor `val` na sequência controlada e reordena a sequência controlada para manter a disciplina de heap. Você o usa para adicionar outro elemento à fila.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_push.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
```

## <a name="priority_queuereference-stlclr"></a><a name="reference"></a>priority_queue:: Reference (STL/CLR)

O tipo de uma referência para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência a um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_reference.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // modify top of priority_queue and redisplay
    Mypriority_queue::reference ref = c1.top();
    ref = L'x';
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
x a b
```

## <a name="priority_queuesize-stlclr"></a><a name="size"></a>priority_queue:: Size (STL/CLR)

Conta o número de elementos.

### <a name="syntax"></a>Sintaxe

```cpp
size_type size();
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência controlada. Você o usa para determinar o número de elementos atualmente na sequência controlada. Se tudo o que você se importa é se a sequência tem tamanho diferente de zero, consulte [priority_queue:: Empty (STL/CLR)](../dotnet/priority-queue-empty-stl-clr.md)`()`.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_size.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    System::Console::WriteLine("size() = {0} starting with 3", c1.size());

    // pop an item and reinspect
    c1.pop();
    System::Console::WriteLine("size() = {0} after popping", c1.size());

    // add two elements and reinspect
    c1.push(L'a');
    c1.push(L'b');
    System::Console::WriteLine("size() = {0} after adding 2", c1.size());
    return (0);
    }
```

```Output
c a b
size() = 3 starting with 3
size() = 2 after popping
size() = 4 after adding 2
```

## <a name="priority_queuesize_type-stlclr"></a><a name="size_type"></a>priority_queue:: size_type (STL/CLR)

O tipo de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int size_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos não negativos.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_size_type.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // compute positive difference
    Mypriority_queue::size_type diff = c1.size();
    c1.pop();
    c1.pop();
    diff -= c1.size();
    System::Console::WriteLine("size difference = {0}", diff);
    return (0);
    }
```

```Output
c a b
size difference = 2
```

## <a name="priority_queueto_array-stlclr"></a><a name="to_array"></a>priority_queue:: to_array (STL/CLR)

Copia a sequência controlada em uma nova matriz.

### <a name="syntax"></a>Sintaxe

```cpp
cli::array<Value>^ to_array();
```

### <a name="remarks"></a>Comentários

A função membro retorna uma matriz que contém a sequência controlada. Você o usa para obter uma cópia da sequência controlada na forma de matriz.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_to_array.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // copy the container and modify it
    cli::array<wchar_t>^ a1 = c1.to_array();

    c1.push(L'd');
    for each (wchar_t elem in c1.get_container())
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
d c b a
c a b
```

## <a name="priority_queuetop-stlclr"></a><a name="top"></a>priority_queue:: Top (STL/CLR)

Acessa o elemento de prioridade mais alta.

### <a name="syntax"></a>Sintaxe

```cpp
reference top();
```

### <a name="remarks"></a>Comentários

A função membro retorna uma referência ao elemento superior (prioridade mais alta) da sequência controlada, que deve ser não vazia. Você o usa para acessar o elemento de prioridade mais alta, quando você sabe que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_top.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect last item
    System::Console::WriteLine("top() = {0}", c1.top());

    // alter last item and reinspect
    c1.top() = L'x';
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

## <a name="priority_queuetop_item-stlclr"></a><a name="top_item"></a>priority_queue:: top_item (STL/CLR)

Acessa o elemento de prioridade mais alta.

### <a name="syntax"></a>Sintaxe

```cpp
property value_type back_item;
```

### <a name="remarks"></a>Comentários

A propriedade acessa o elemento superior (prioridade mais alta) da sequência controlada, que deve ser não vazio. Você o usa para ler ou gravar o elemento de prioridade mais alta, quando você sabe que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_top_item.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

    // inspect last item
    System::Console::WriteLine("top_item = {0}", c1.top_item);

    // alter last item and reinspect
    c1.top_item = L'x';
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c a b
top_item = c
x a b
```

## <a name="priority_queuevalue_comp-stlclr"></a><a name="value_comp"></a>priority_queue:: value_comp (STL/CLR)

Copia o delegado de ordenação para dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
value_compare^ value_comp();
```

### <a name="remarks"></a>Comentários

A função member retorna o delegado de ordenação usado para ordenar a sequência controlada. Use-o para comparar dois valores.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_value_comp.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    Mypriority_queue::value_compare^ vcomp = c1.value_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        vcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        vcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        vcomp(L'b', L'a'));
    System::Console::WriteLine();

    // test a different ordering rule
    Mypriority_queue c2 = cliext::greater<wchar_t>();
    vcomp = c2.value_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        vcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        vcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        vcomp(L'b', L'a'));
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

## <a name="priority_queuevalue_compare-stlclr"></a><a name="value_compare"></a>priority_queue:: value_compare (STL/CLR)

O delegado de ordenação para dois valores.

### <a name="syntax"></a>Sintaxe

```cpp
binary_delegate<value_type, value_type, int> value_compare;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o delegado que determina se o primeiro argumento é ordenado antes do segundo.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_value_compare.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    Mypriority_queue::value_compare^ vcomp = c1.value_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        vcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        vcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        vcomp(L'b', L'a'));
    System::Console::WriteLine();

    // test a different ordering rule
    Mypriority_queue c2 = cliext::greater<wchar_t>();
    vcomp = c2.value_comp();

    System::Console::WriteLine("compare(L'a', L'a') = {0}",
        vcomp(L'a', L'a'));
    System::Console::WriteLine("compare(L'a', L'b') = {0}",
        vcomp(L'a', L'b'));
    System::Console::WriteLine("compare(L'b', L'a') = {0}",
        vcomp(L'b', L'a'));
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

## <a name="priority_queuevalue_type-stlclr"></a><a name="value_type"></a>priority_queue:: value_type (STL/CLR)

O tipo de um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o *valor*do parâmetro de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_priority_queue_value_type.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::priority_queue<wchar_t> Mypriority_queue;
int main()
    {
    Mypriority_queue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

    // display reversed contents " a b c" using value_type
    for (; !c1.empty(); c1.pop())
        {   // store element in value_type object
        Mypriority_queue::value_type val = c1.top();

        System::Console::Write("{0} ", val);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
c b a
```
