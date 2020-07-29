---
title: queue (STL/CLR)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- cliext::queue
- cliext::queue::assign
- cliext::queue::back
- cliext::queue::back_item
- cliext::queue::const_reference
- cliext::queue::container_type
- cliext::queue::difference_type
- cliext::queue::empty
- cliext::queue::front
- cliext::queue::front_item
- cliext::queue::generic_container
- cliext::queue::generic_value
- cliext::queue::get_container
- cliext::queue::operator=
- cliext::queue::pop
- cliext::queue::push
- cliext::queue::queue
- cliext::queue::reference
- cliext::queue::size
- cliext::queue::size_type
- cliext::queue::to_array
- cliext::queue::value_type
helpviewer_keywords:
- <queue> header [STL/CLR]
- queue class [STL/CLR]
- <cliext/queue> header [STL/CLR]
- operator!= member [STL/CLR]
- operator< member [STL/CLR]
- operator<= member [STL/CLR]
- operator== member [STL/CLR]
- operator> member [STL/CLR]
- operator>= member [STL/CLR]
- assign member [STL/CLR]
- back member [STL/CLR]
- back_item member [STL/CLR]
- const_reference member [STL/CLR]
- container_type member [STL/CLR]
- difference_type member [STL/CLR]
- empty member [STL/CLR]
- front member [STL/CLR]
- front_item member [STL/CLR]
- generic_container member [STL/CLR]
- generic_value member [STL/CLR]
- get_container member [STL/CLR]
- operator= member [STL/CLR]
- pop member [STL/CLR]
- push member [STL/CLR]
- queue member [STL/CLR]
- reference member [STL/CLR]
- size member [STL/CLR]
- size_type member [STL/CLR]
- to_array member [STL/CLR]
- value_type member [STL/CLR]
ms.assetid: 9ea7dec3-ea98-48ff-87d0-a5afc924aaf2
ms.openlocfilehash: ce4b3ca37fc5e13ace3058cb9ec9e9daad073b47
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87210924"
---
# <a name="queue-stlclr"></a>queue (STL/CLR)

A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tem o acesso de primeiro a entrar em primeiro lugar. Você usa o adaptador de contêiner `queue` para gerenciar um contêiner subjacente como uma fila.

Na descrição abaixo, `GValue` é igual ao *valor* , a menos que o último seja um tipo de referência, nesse caso é `Value^` . Da mesma forma, `GContainer` é o mesmo que o *contêiner* , a menos que o último seja um tipo de referência, nesse caso é `Container^` .

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Value,
    typename Container>
    ref class queue
        :   public
        System::ICloneable,
        Microsoft::VisualC::StlClr::IQueue<GValue, GContainer>
    { ..... };
```

### <a name="parameters"></a>parâmetros

*Valor*<br/>
O tipo de um elemento na sequência controlada.

*Contêiner*<br/>
O tipo do contêiner subjacente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<cliext/queue>

**Namespace:** cliext

## <a name="declarations"></a>Declarações

|Definição de tipo|Descrição|
|---------------------|-----------------|
|[queue::const_reference (STL/CLR)](#const_reference)|O tipo de uma referência de constante para um elemento.|
|[queue::container_type (STL/CLR)](#container_type)|O tipo do contêiner subjacente.|
|[queue::difference_type (STL/CLR)](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|
|[queue::generic_container (STL/CLR)](#generic_container)|O tipo da interface genérica para o adaptador do contêiner.|
|[queue::generic_value (STL/CLR)](#generic_value)|O tipo de um elemento para a interface genérica para o adaptador de contêiner.|
|[queue::reference (STL/CLR)](#reference)|O tipo de uma referência para um elemento.|
|[queue::size_type (STL/CLR)](#size_type)|O tipo de uma distância com sinal entre dois elementos.|
|[queue::value_type (STL/CLR)](#value_type)|O tipo de um elemento.|

|Função membro|Descrição|
|---------------------|-----------------|
|[queue::assign (STL/CLR)](#assign)|Substitui todos os elementos.|
|[queue::back (STL/CLR)](#back)|Acessa o último elemento.|
|[queue::empty (STL/CLR)](#empty)|Testa se nenhum elemento está presente.|
|[queue::front (STL/CLR)](#front)|Acessa o primeiro elemento.|
|[queue::get_container (STL/CLR)](#get_container)|Acessa o contêiner subjacente.|
|[queue::pop (STL/CLR)](#pop)|Remove o primeiro elemento.|
|[queue::push (STL/CLR)](#push)|Adiciona um novo último elemento.|
|[queue::queue (STL/CLR)](#queue)|Constrói um objeto contêiner.|
|[queue::size (STL/CLR)](#size)|Conta o número de elementos.|
|[queue::to_array (STL/CLR)](#to_array)|Copia a sequência controlada em uma nova matriz.|

|Propriedade|DESCRIÇÃO|
|--------------|-----------------|
|[queue::back_item (STL/CLR)](#back_item)|Acessa o último elemento.|
|[queue::front_item (STL/CLR)](#front_item)|Acessa o primeiro elemento.|

|Operador|Descrição|
|--------------|-----------------|
|[queue::operator= (STL/CLR)](#op_as)|Substitui a sequência controlada.|
|[operador! = (fila) (STL/CLR)](#op_neq)|Determina se um `queue` objeto não é igual a outro `queue` objeto.|
|[< do operador (fila) (STL/CLR)](#op_lt)|Determina se um `queue` objeto é menor que outro `queue` objeto.|
|[operador<= (fila) (STL/CLR)](#op_lteq)|Determina se um `queue` objeto é menor ou igual a outro `queue` objeto.|
|[Operator = = (fila) (STL/CLR)](#op_eq)|Determina se um `queue` objeto é igual a outro `queue` objeto.|
|[> do operador (fila) (STL/CLR)](#op_gt)|Determina se um `queue` objeto é maior que outro `queue` objeto.|
|[operator>= (queue) (STL/CLR)](#op_gteq)|Determina se um `queue` objeto é maior ou igual a outro `queue` objeto.|

## <a name="interfaces"></a>Interfaces

|Interface|Descrição|
|---------------|-----------------|
|<xref:System.ICloneable>|Duplicar um objeto.|
|IQueue\<Value, Container>|Mantenha o adaptador de contêiner genérico.|

## <a name="remarks"></a>Comentários

O objeto aloca e libera o armazenamento para a sequência que ele controla por meio de um contêiner subjacente, do tipo `Container` , que armazena `Value` elementos e cresce sob demanda. O objeto restringe o acesso para apenas enviar o primeiro elemento e retirar o último elemento, implementando uma primeira fila de primeiro a entrar (também conhecida como fila FIFO ou simplesmente uma fila).

## <a name="members"></a>Membros

## <a name="queueassign-stlclr"></a><a name="assign"></a>fila:: atribuir (STL/CLR)

Substitui todos os elementos.

### <a name="syntax"></a>Sintaxe

```cpp
void assign(queue<Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*Certo*<br/>
Adaptador de contêiner a ser inserido.

### <a name="remarks"></a>Comentários

A função de membro é atribuída `right.get_container()` ao contêiner subjacente. Você o usa para alterar todo o conteúdo da fila.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_assign.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign a repetition of values
    Myqueue c2;
    c2.assign(c1);
    for each (wchar_t elem in c2.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
```

## <a name="queueback-stlclr"></a><a name="back"></a>fila:: voltar (STL/CLR)

Acessa o último elemento.

### <a name="syntax"></a>Sintaxe

```cpp
reference back();
```

### <a name="remarks"></a>Comentários

A função member retorna uma referência ao último elemento da sequência controlada, que deve ser não vazia. Você o usa para acessar o último elemento, quando você sabe que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_back.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// inspect last item
    System::Console::WriteLine("back() = {0}", c1.back());

// alter last item and reinspect
    c1.back() = L'x';
    for each (wchar_t elem in c1.get_container())
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

## <a name="queueback_item-stlclr"></a><a name="back_item"></a>fila:: back_item (STL/CLR)

Acessa o último elemento.

### <a name="syntax"></a>Sintaxe

```cpp
property value_type back_item;
```

### <a name="remarks"></a>Comentários

A propriedade acessa o último elemento da sequência controlada, que deve ser não vazio. Você o usa para ler ou gravar o último elemento, quando souber que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_back_item.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// inspect last item
    System::Console::WriteLine("back_item = {0}", c1.back_item);

// alter last item and reinspect
    c1.back_item = L'x';
    for each (wchar_t elem in c1.get_container())
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

## <a name="queueconst_reference-stlclr"></a><a name="const_reference"></a>fila:: const_reference (STL/CLR)

O tipo de uma referência de constante para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% const_reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência constante para um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_const_reference.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for (; !c1.empty(); c1.pop())
        {   // get a const reference to an element
        Myqueue::const_reference cref = c1.front();
        System::Console::Write("{0} ", cref);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="queuecontainer_type-stlclr"></a><a name="container_type"></a>fila:: container_type (STL/CLR)

O tipo do contêiner subjacente.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Container value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Container`.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_container_type.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c" using container_type
    Myqueue::container_type wc1 = c1.get_container();
    for each (wchar_t elem in wc1)
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="queuedifference_type-stlclr"></a><a name="difference_type"></a>fila: ifference_type de:d (STL/CLR)

Os tipos de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int difference_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos possivelmente negativo.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_difference_type.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// compute negative difference
    Myqueue::difference_type diff = c1.size();
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
a b c
pushing 2 = -2
popping 3 = 3
```

## <a name="queueempty-stlclr"></a><a name="empty"></a>fila:: Empty (STL/CLR)

Testa se nenhum elemento está presente.

### <a name="syntax"></a>Sintaxe

```cpp
bool empty();
```

### <a name="remarks"></a>Comentários

A função membro retorna verdadeiro para uma sequência controlada vazia. É equivalente a [Queue:: Size (STL/CLR)](../dotnet/queue-size-stl-clr.md) `() == 0` . Você o usa para testar se a fila está vazia.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_empty.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
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
a b c
size() = 3
empty() = False
size() = 0
empty() = True
```

## <a name="queuefront-stlclr"></a><a name="front"></a>Queue:: Front (STL/CLR)

Acessa o primeiro elemento.

### <a name="syntax"></a>Sintaxe

```cpp
reference front();
```

### <a name="remarks"></a>Comentários

A função member retorna uma referência ao primeiro elemento da sequência controlada, que deve ser não vazia. Você o usa para acessar o primeiro elemento, quando você sabe que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_front.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// inspect first item
    System::Console::WriteLine("front() = {0}", c1.front());

// alter first item and reinspect
    c1.front() = L'x';
    for each (wchar_t elem in c1.get_container())
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

## <a name="queuefront_item-stlclr"></a><a name="front_item"></a>fila:: front_item (STL/CLR)

Acessa o primeiro elemento.

### <a name="syntax"></a>Sintaxe

```cpp
property value_type front_item;
```

### <a name="remarks"></a>Comentários

A propriedade acessa o primeiro elemento da sequência controlada, que deve ser não vazio. Você o usa para ler ou gravar o primeiro elemento, quando souber que ele existe.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_front_item.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// inspect last item
    System::Console::WriteLine("front_item = {0}", c1.front_item);

// alter last item and reinspect
    c1.front_item = L'x';
    for each (wchar_t elem in c1.get_container())
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

## <a name="queuegeneric_container-stlclr"></a><a name="generic_container"></a>fila:: generic_container (STL/CLR)

O tipo da interface genérica para o adaptador do contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Microsoft::VisualC::StlClr::IQueue<Value>
    generic_container;
```

### <a name="remarks"></a>Comentários

O tipo descreve a interface genérica para essa classe de adaptador de contêiner de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_generic_container.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct a generic container
    Myqueue::generic_container^ gc1 = %c1;
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
a b c
a b c
a b c d
a b c d e
```

## <a name="queuegeneric_value-stlclr"></a><a name="generic_value"></a>fila:: generic_value (STL/CLR)

O tipo de um elemento a ser usado com a interface genérica para o contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
typedef GValue generic_value;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto do tipo `GValue` que descreve o valor do elemento armazenado para uso com a interface genérica para essa classe de contêiner de modelo. ( `GValue` é `value_type` ou `value_type^` se `value_type` for um tipo ref.)

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_generic_value.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// get interface to container
    Myqueue::generic_container^ gc1 = %c1;
    for each (wchar_t elem in gc1->get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// display in order using generic_value
    for (; !gc1->empty(); gc1->pop())
        {
        Myqueue::generic_value elem = gc1->front();

        System::Console::Write("{0} ", elem);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
a b c
```

## <a name="queueget_container-stlclr"></a><a name="get_container"></a>fila:: get_container (STL/CLR)

Acessa o contêiner subjacente.

### <a name="syntax"></a>Sintaxe

```cpp
container_type^ get_container();
```

### <a name="remarks"></a>Comentários

A função membro retorna o contêiner subjacente. Você o usa para ignorar as restrições impostas pelo wrapper do contêiner.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_get_container.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
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
a b c
```

## <a name="queueoperator-stlclr"></a><a name="op_as"></a>Queue:: Operator = (STL/CLR)

Substitui a sequência controlada.

### <a name="syntax"></a>Sintaxe

```cpp
queue <Value, Container>% operator=(queue <Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*Certo*<br/>
Adaptador de contêiner a ser copiado.

### <a name="remarks"></a>Comentários

O operador membro copia *diretamente* para o objeto e, em seguida, retorna **`*this`** . Você o usa para substituir a sequência controlada por uma cópia da sequência controlada *à direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_operator_as.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myqueue c2;
    c2 = c1;
    for each (wchar_t elem in c2.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b c
```

## <a name="queuepop-stlclr"></a><a name="pop"></a>fila::p op (STL/CLR)

Remove o último elemento.

### <a name="syntax"></a>Sintaxe

```cpp
void pop();
```

### <a name="remarks"></a>Comentários

A função membro remove o último elemento da sequência controlada, que deve ser não vazio. Você o usa para encurtar a fila por um elemento na parte de trás.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_pop.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
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
a b c
b c
```

## <a name="queuepush-stlclr"></a><a name="push"></a>fila::p USH (STL/CLR)

Adiciona um novo último elemento.

### <a name="syntax"></a>Sintaxe

```cpp
void push(value_type val);
```

### <a name="remarks"></a>Comentários

A função membro adiciona um elemento com valor `val` no final da fila. Você o usa para acrescentar um elemento à fila.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_push.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
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
a b c
```

## <a name="queuequeue-stlclr"></a><a name="queue"></a>fila:: Queue (STL/CLR)

Constrói um objeto de adaptador de contêiner.

### <a name="syntax"></a>Sintaxe

```cpp
queue();
queue(queue<Value, Container>% right);
queue(queue<Value, Container>^ right);
explicit queue(container_type% wrapped);
```

#### <a name="parameters"></a>parâmetros

*Certo*<br/>
Objeto a ser copiado.

*encapsulado*<br/>
Contêiner encapsulado a ser usado.

### <a name="remarks"></a>Comentários

O construtor:

`queue();`

Cria um contêiner encapsulado vazio. Você o usa para especificar uma sequência controlada inicial vazia.

O construtor:

`queue(queue<Value, Container>% right);`

Cria um contêiner encapsulado que é uma cópia do `right.get_container()` . Você o usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de fila *diretamente*.

O construtor:

`queue(queue<Value, Container>^ right);`

Cria um contêiner encapsulado que é uma cópia do `right->get_container()` . Você o usa para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de fila `*right` .

O construtor:

`explicit queue(container_type wrapped);`

usa o contêiner existente *encapsulado* como o contêiner encapsulado. Você o usa para construir uma fila de um contêiner existente.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_construct.cpp
// compile with: /clr
#include <cliext/queue>
#include <cliext/list>

typedef cliext::queue<wchar_t> Myqueue;
typedef cliext::list<wchar_t> Mylist;
typedef cliext::queue<wchar_t, Mylist> Myqueue_list;
int main()
    {
// construct an empty container
    Myqueue c1;
    System::Console::WriteLine("size() = {0}", c1.size());

// construct from an underlying container
    Mylist v2(5, L'x');
    Myqueue_list c2(v2);
    for each (wchar_t elem in c2.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct by copying another container
    Myqueue_list c3(c2);
    for each (wchar_t elem in c3.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// construct by copying another container through handle
    Myqueue_list c4(%c2);
    for each (wchar_t elem in c4.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
size() = 0
x x x x x
x x x x x
x x x x x
```

## <a name="queuereference-stlclr"></a><a name="reference"></a>Queue:: Reference (STL/CLR)

O tipo de uma referência para um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef value_type% reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência a um elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_reference.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// modify back of queue and redisplay
    Myqueue::reference ref = c1.back();
    ref = L'x';
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
a b x
```

## <a name="queuesize-stlclr"></a><a name="size"></a>fila:: tamanho (STL/CLR)

Conta o número de elementos.

### <a name="syntax"></a>Sintaxe

```cpp
size_type size();
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência controlada. Você o usa para determinar o número de elementos atualmente na sequência controlada. Se tudo o que você se importa é se a sequência tem tamanho diferente de zero, confira [fila:: Empty (STL/CLR)](../dotnet/queue-empty-stl-clr.md) `()` .

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_size.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
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
a b c
size() = 3 starting with 3
size() = 2 after popping
size() = 4 after adding 2
```

## <a name="queuesize_type-stlclr"></a><a name="size_type"></a>fila:: size_type (STL/CLR)

O tipo de uma distância assinada entre dois elementos.

### <a name="syntax"></a>Sintaxe

```cpp
typedef int size_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma contagem de elementos não negativos.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_size_type.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display initial contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// compute positive difference
    Myqueue::size_type diff = c1.size();
    c1.pop();
    c1.pop();
    diff -= c1.size();
    System::Console::WriteLine("size difference = {0}", diff);
    return (0);
    }
```

```Output
a b c
size difference = 2
```

## <a name="queueto_array-stlclr"></a><a name="to_array"></a>fila:: to_array (STL/CLR)

Copia a sequência controlada em uma nova matriz.

### <a name="syntax"></a>Sintaxe

```cpp
cli::array<Value>^ to_array();
```

### <a name="remarks"></a>Comentários

A função membro retorna uma matriz que contém a sequência controlada. Você o usa para obter uma cópia da sequência controlada na forma de matriz.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_to_array.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
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
a b c d
a b c
```

## <a name="queuevalue_type-stlclr"></a><a name="value_type"></a>fila:: value_type (STL/CLR)

O tipo de um elemento.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o *valor*do parâmetro de modelo.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_value_type.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display reversed contents " a b c" using value_type
    for (; !c1.empty(); c1.pop())
        {   // store element in value_type object
        Myqueue::value_type val = c1.front();

        System::Console::Write("{0} ", val);
        }
    System::Console::WriteLine();
    return (0);
    }
```

```Output
a b c
```

## <a name="operator-queue-stlclr"></a><a name="op_neq"></a>operador! = (fila) (STL/CLR)

Comparação de não Equals de fila.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value,
    typename Container>
    bool operator!=(queue<Value, Container>% left,
        queue<Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(left == right)` . Você o usa para testar se a *esquerda* não é ordenada da mesma forma que a *correta* quando as duas filas são comparadas Element por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_operator_ne.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myqueue c2;
    c2.push(L'a');
    c2.push(L'b');
    c2.push(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2.get_container())
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

## <a name="operatorlt-queue-stlclr"></a><a name="op_lt"></a>operador &lt; (fila) (STL/CLR)

Fila menor que comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value,
    typename Container>
    bool operator<(queue<Value, Container>% left,
        queue<Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retornará true se, para a posição mais baixa `i` para a qual `!(right[i] < left[i])` também é verdadeira `left[i] < right[i]` . Caso contrário, retorna `left->` [Queue:: Size (STL/CLR)](../dotnet/queue-size-stl-clr.md) `() <` `right->size()` que você o usa para testar se a *esquerda* é ordenada antes da *direita* quando as duas filas são comparadas Element por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_operator_lt.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myqueue c2;
    c2.push(L'a');
    c2.push(L'b');
    c2.push(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2.get_container())
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

## <a name="operatorlt-queue-stlclr"></a><a name="op_lteq"></a>Operator &lt; = (fila) (STL/CLR)

Fila menor ou igual a comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value,
    typename Container>
    bool operator<=(queue<Value, Container>% left,
        queue<Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(right < left)` . Você o usa para testar se a *esquerda* não é ordenada após *direita* quando as duas filas são comparadas Element por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_operator_le.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myqueue c2;
    c2.push(L'a');
    c2.push(L'b');
    c2.push(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2.get_container())
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

## <a name="operator-queue-stlclr"></a><a name="op_eq"></a>Operator = = (fila) (STL/CLR)

Comparação de igual da fila.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value,
    typename Container>
    bool operator==(queue<Value, Container>% left,
        queue<Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retornará true somente se as sequências controladas pela *esquerda* e *à direita* tiverem o mesmo comprimento e, para cada posição `i` , `left[i] ==` `right[i]` . Você o usa para testar se a *esquerda* é ordenada da mesma forma que a *direita* quando as duas filas são comparadas Element por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_operator_eq.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myqueue c2;
    c2.push(L'a');
    c2.push(L'b');
    c2.push(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2.get_container())
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

## <a name="operatorgt-queue-stlclr"></a><a name="op_gt"></a>operador &gt; (fila) (STL/CLR)

Fila maior que comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value,
    typename Container>
    bool operator>(queue<Value, Container>% left,
        queue<Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `right` `<` `left` . Você o usa para testar se a *esquerda* é ordenada após *direita* quando as duas filas são comparadas Element por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_operator_gt.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myqueue c2;
    c2.push(L'a');
    c2.push(L'b');
    c2.push(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2.get_container())
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

## <a name="operatorgt-queue-stlclr"></a><a name="op_gteq"></a>Operator &gt; = (fila) (STL/CLR)

Fila maior ou igual a comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value,
    typename Container>
    bool operator>=(queue<Value, Container>% left,
        queue<Value, Container>% right);
```

#### <a name="parameters"></a>parâmetros

*mantida*<br/>
Contêiner esquerdo a comparar.

*Certo*<br/>
Contêiner direito a comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(left < right)` . Você o usa para testar se a *esquerda* não é ordenada antes da *direita* quando as duas filas são comparadas Element por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_queue_operator_ge.cpp
// compile with: /clr
#include <cliext/queue>

typedef cliext::queue<wchar_t> Myqueue;
int main()
    {
    Myqueue c1;
    c1.push(L'a');
    c1.push(L'b');
    c1.push(L'c');

// display contents " a b c"
    for each (wchar_t elem in c1.get_container())
        System::Console::Write("{0} ", elem);
    System::Console::WriteLine();

// assign to a new container
    Myqueue c2;
    c2.push(L'a');
    c2.push(L'b');
    c2.push(L'd');

// display contents " a b d"
    for each (wchar_t elem in c2.get_container())
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
