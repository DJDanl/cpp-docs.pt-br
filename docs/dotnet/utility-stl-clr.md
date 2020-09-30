---
title: utility (STL/CLR)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- <cliext/utility>
- cliext::pair
- cliext::pair::pair
- cliext::pair::first
- cliext::pair::first_type
- cliext::pair::second
- cliext::pair::second_type
- cliext::pair::swap
- cliext::make_pair
- cliext::pair::operator=
- cliext::pair::operator==
- cliext::pair::operator>=
- cliext::pair::operator>
- cliext::pair::operator!=
- cliext::pair::operator<=
- cliext::pair::operator<
helpviewer_keywords:
- <utility> header [STL/CLR]
- utility header [STL/CLR]
- <cliext/utility> header [STL/CLR]
- first member [STL/CLR]
- first_type member [STL/CLR]
- second member [STL/CLR]
- second_type member [STL/CLR]
- swap member [STL/CLR]
- make_pair function [STL/CLR]
- pair class [STL/CLR]
- pair member [STL/CLR]
- operator== member [STL/CLR]
- operator= member [STL/CLR]
- operator>= member [STL/CLR]
- operator> member [STL/CLR]
- operator!= member [STL/CLR]
- operator<= member [STL/CLR]
- operator< member [STL/CLR]
ms.assetid: fb48cb75-d5ef-47ce-b526-bf60dc86c552
ms.openlocfilehash: 271bc01f5c8fd9dd07bfa03035ae3d0204ebd8e7
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500593"
---
# <a name="utility-stlclr"></a>utility (STL/CLR)

Inclua o cabeçalho STL/CLR `<cliext/utility>` para definir a classe de modelo `pair` e várias funções de modelo de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <utility>
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<cliext/utility>

**Namespace:** cliext

## <a name="declarations"></a>Declarações

|Classe|Descrição|
|-----------|-----------------|
|[pair (STL/CLR)](#pair)|Encapsular um par de elementos.|

|Operador|Descrição|
|--------------|-----------------|
|[operator== (pair) (STL/CLR)](#op_eq)|Comparar comparação igual.|
|[operador! = (par) (STL/CLR)](#op_neq)|Comparação de pares não igual.|
|[operador< (par) (STL/CLR)](#op_lt)|Par menor que comparação.|
|[Operator \< = (par) (STL/CLR)](#op_lteq)|Par comparação menor ou igual a.|
|[operador> (par) (STL/CLR)](#op_gt)|Par maior que comparação.|
|[operador>= (par) (STL/CLR)](#op_gteq)|Par maior ou igual a comparação.|

|Função|Descrição|
|--------------|-----------------|
|[make_pair (STL/CLR)](#make_pair)|Crie um par de um par de valores.|

## <a name="members"></a>Membros

## <a name="pair-stlclr"></a><a name="pair"></a> par (STL/CLR)

A classe de modelo descreve um objeto que encapsula um par de valores.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    ref class pair;
```

#### <a name="parameters"></a>Parâmetros

*Value1*<br/>
O tipo do primeiro valor encapsulado.

*Value2*<br/>
O tipo do segundo valor encapsulado.

## <a name="members"></a>Membros

|Definição de tipo|Descrição|
|---------------------|-----------------|
|[pair::first_type (STL/CLR)](#first_type)|O tipo do primeiro valor encapsulado.|
|[pair::second_type (STL/CLR)](#second_type)|O tipo do segundo valor encapsulado.|

|Objeto de membro|Descrição|
|-------------------|-----------------|
|[pair::first (STL/CLR)](#first)|O primeiro valor armazenado.|
|[pair::second (STL/CLR)](#second)|O segundo valor armazenado.|

|Função membro|Descrição|
|---------------------|-----------------|
|[pair::pair (STL/CLR)](#pair_pair)|Constrói um objeto de par.|
|[pair::swap (STL/CLR)](#swap)|Permuta o conteúdo de dois pares.|

|Operador|Descrição|
|--------------|-----------------|
|[pair::operator= (STL/CLR)](#op_as)|Substitui o par de valores armazenado.|

## <a name="remarks"></a>Comentários

O objeto armazena um par de valores. Você usa essa classe de modelo para combinar dois valores em um único objeto. Além disso, o objeto `cliext::pair` (descrito aqui) armazena apenas os tipos gerenciados; para armazenar um par de tipos não gerenciados `std::pair` , declarados em `<utility>` .

## <a name="pairfirst-stlclr"></a><a name="first"></a> par:: primeiro (STL/CLR)

O primeiro valor encapsulado.

### <a name="syntax"></a>Sintaxe

```cpp
Value1 first;
```

### <a name="remarks"></a>Comentários

O objeto armazena o primeiro valor encapsulado.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_first.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);

    cliext::pair<wchar_t, int>::first_type first_val = c1.first;
    cliext::pair<wchar_t, int>::second_type second_val = c1.second;
    System::Console::WriteLine("[{0}, {1}]", first_val, second_val);
    return (0);
    }
```

```Output
[x, 3]
```

## <a name="pairfirst_type-stlclr"></a><a name="first_type"></a> par:: first_type (STL/CLR)

O tipo do primeiro valor encapsulado.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value1 first_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo *value1*.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_first_type.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);

    cliext::pair<wchar_t, int>::first_type first_val = c1.first;
    cliext::pair<wchar_t, int>::second_type second_val = c1.second;
    System::Console::WriteLine("[{0}, {1}]", first_val, second_val);
    return (0);
    }
```

```Output
[x, 3]
```

## <a name="pairoperator-stlclr"></a><a name="op_as"></a> par:: Operator = (STL/CLR)

Substitui o par de valores armazenado.

### <a name="syntax"></a>Sintaxe

```cpp
pair<Value1, Value2>% operator=(pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*direita*<br/>
Emparelhar para copiar.

### <a name="remarks"></a>Comentários

O operador membro copia *diretamente* para o objeto e, em seguida, retorna **`*this`** . Você o usa para substituir o par de valores armazenado por uma cópia do par de valores armazenado *à direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_operator_as.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);

// assign to a new pair
    cliext::pair<wchar_t, int> c2;
    c2 = c1;
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);
    return (0);
    }
```

```Output
[x, 3]
[x, 3]
```

## <a name="pairpair-stlclr"></a><a name="pair_pair"></a> par::p ar (STL/CLR)

Constrói um objeto de par.

### <a name="syntax"></a>Sintaxe

```cpp
pair();
pair(pair<Coll>% right);
pair(pair<Coll>^ right);
pair(Value1 val1, Value2 val2);
```

#### <a name="parameters"></a>Parâmetros

*direita*<br/>
Emparelhar para armazenar.

*val1*<br/>
Primeiro valor a ser armazenado.

*val2*<br/>
Segundo valor a ser armazenado.

### <a name="remarks"></a>Comentários

O construtor:

`pair();`

Inicializa o par armazenado com valores construídos padrão.

O construtor:

`pair(pair<Value1, Value2>% right);`

Inicializa o par armazenado com o `right.` [par:: First (STL/CLR)](#first) e `right.` [par:: Second (STL/CLR)](#second).

`pair(pair<Value1, Value2>^ right);`

Inicializa o par armazenado com o `right->` [par:: First (STL/CLR)](#first) e `right>` [par:: Second (STL/CLR)](#second).

O construtor:

`pair(Value1 val1, Value2 val2);`

Inicializa o par armazenado com *val1* e *val2*.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_construct.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
// construct an empty container
    cliext::pair<wchar_t, int> c1;
    System::Console::WriteLine("[{0}, {1}]",
        c1.first == L'\0' ? "\\0" : "??", c1.second);

// construct with a pair of values
    cliext::pair<wchar_t, int> c2(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);

// construct by copying another pair
    cliext::pair<wchar_t, int> c3(c2);
    System::Console::WriteLine("[{0}, {1}]", c3.first, c3.second);

// construct by copying a pair handle
    cliext::pair<wchar_t, int> c4(%c3);
    System::Console::WriteLine("[{0}, {1}]", c4.first, c4.second);

    return (0);
    }
```

```Output
[\0, 0]
[x, 3]
[x, 3]
[x, 3]
```

## <a name="pairsecond-stlclr"></a><a name="second"></a> par:: segundo (STL/CLR)

O segundo valor encapsulado.

### <a name="syntax"></a>Sintaxe

```cpp
Value2 second;
```

### <a name="remarks"></a>Comentários

O objeto armazena o segundo valor encapsulado.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_second.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);

    cliext::pair<wchar_t, int>::first_type first_val = c1.first;
    cliext::pair<wchar_t, int>::second_type second_val = c1.second;
    System::Console::WriteLine("[{0}, {1}]", first_val, second_val);
    return (0);
    }
```

```Output
[x, 3]
```

## <a name="pairsecond_type-stlclr"></a><a name="second_type"></a> par:: second_type (STL/CLR)

O tipo do segundo valor encapsulado.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value2 second_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo *value2*.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_second_type.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);

    cliext::pair<wchar_t, int>::first_type first_val = c1.first;
    cliext::pair<wchar_t, int>::second_type second_val = c1.second;
    System::Console::WriteLine("[{0}, {1}]", first_val, second_val);
    return (0);
    }
```

```Output
[x, 3]
```

## <a name="pairswap-stlclr"></a><a name="swap"></a> Pair:: swap (STL/CLR)

Permuta o conteúdo de dois pares.

### <a name="syntax"></a>Sintaxe

```cpp
void swap(pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*direita*<br/>
Par com o qual trocar conteúdo.

### <a name="remarks"></a>Comentários

A função membro troca o par de valores armazenados entre **`*this`** e *à direita*.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_swap.cpp
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

## <a name="make_pair-stlclr"></a><a name="make_pair"></a> make_pair (STL/CLR)

Crie um `pair` de um par de valores.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    pair<Value1, Value2> make_pair(Value1 first, Value2 second);
```

#### <a name="parameters"></a>Parâmetros

*Value1*<br/>
O tipo do primeiro valor encapsulado.

*Value2*<br/>
O tipo do segundo valor encapsulado.

*first*<br/>
Primeiro valor a ser quebrado.

*second*<br/>
Segundo valor a ser encapsulado.

### <a name="remarks"></a>Comentários

A função do modelo retorna `pair<Value1, Value2>(first, second)`. Você o usa para construir um `pair<Value1, Value2>` objeto de um par de valores.

### <a name="example"></a>Exemplo

```cpp
// cliext_make_pair.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);

    c1 = cliext::make_pair(L'y', 4);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);
    return (0);
    }
```

```Output
[x, 3]
[y, 4]
```

## <a name="operator-pair-stlclr"></a><a name="op_neq"></a> operador! = (par) (STL/CLR)

Comparação de pares não igual.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator!=(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*esquerda*<br/>
Par esquerdo para comparar.

*direita*<br/>
Par correto para comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(left == right)` . Você o usa para testar se a *esquerda* não é ordenada da mesma forma que a *correta* quando os dois pares são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_operator_ne.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);
    cliext::pair<wchar_t, int> c2(L'x', 4);
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);

    System::Console::WriteLine("[x 3] != [x 3] is {0}",
        c1 != c1);
    System::Console::WriteLine("[x 3] != [x 4] is {0}",
        c1 != c2);
    return (0);
    }
```

```Output
[x, 3]
[x, 4]
[x 3] != [x 3] is False
[x 3] != [x 4] is True
```

## <a name="operatorlt-pair-stlclr"></a><a name="op_lt"></a> operador &lt; (par) (STL/CLR)

Par menor que comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator<(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*esquerda*<br/>
Par esquerdo para comparar.

*direita*<br/>
Par correto para comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `left.first <` `right.first || !(right.first <` `left.first &&` `left.second <` `right.second` . Você o usa para testar se a *esquerda* é ordenada da anterior para a *direita* quando os dois pares são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_operator_lt.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);
    cliext::pair<wchar_t, int> c2(L'x', 4);
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);

    System::Console::WriteLine("[x 3] < [x 3] is {0}",
        c1 < c1);
    System::Console::WriteLine("[x 3] < [x 4] is {0}",
        c1 < c2);
    return (0);
    }
```

```Output
[x, 3]
[x, 4]
[x 3] < [x 3] is False
[x 3] < [x 4] is True
```

## <a name="operatorlt-pair-stlclr"></a><a name="op_lteq"></a> Operator &lt; = (par) (STL/CLR)

Par comparação menor ou igual a.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator<=(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*esquerda*<br/>
Par esquerdo para comparar.

*direita*<br/>
Par correto para comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(right < left)` . Você o usa para testar se a *esquerda* não é ordenada após *direita* quando os dois pares são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_operator_le.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);
    cliext::pair<wchar_t, int> c2(L'x', 4);
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);

    System::Console::WriteLine("[x 3] <= [x 3] is {0}",
        c1 <= c1);
    System::Console::WriteLine("[x 4] <= [x 3] is {0}",
        c2 <= c1);
    return (0);
    }
```

```Output
[x, 3]
[x, 4]
[x 3] <= [x 3] is True
[x 4] <= [x 3] is False
```

## <a name="operator-pair-stlclr"></a><a name="op_eq"></a> Operator = = (par) (STL/CLR)

Comparar comparação igual.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator==(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*esquerda*<br/>
Par esquerdo para comparar.

*direita*<br/>
Par correto para comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `left.first ==` `right.first &&` `left.second ==` `right.second` . Você o usa para testar se a *esquerda* é ordenada da mesma forma que a *direita* quando os dois pares são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_operator_eq.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);
    cliext::pair<wchar_t, int> c2(L'x', 4);
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);

    System::Console::WriteLine("[x 3] == [x 3] is {0}",
        c1 == c1);
    System::Console::WriteLine("[x 3] == [x 4] is {0}",
        c1 == c2);
    return (0);
    }
```

```Output
[x, 3]
[x, 4]
[x 3] == [x 3] is True
[x 3] == [x 4] is False
```

## <a name="operatorgt-pair-stlclr"></a><a name="op_gt"></a> operador &gt; (par) (STL/CLR)

Par maior que comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator>(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*esquerda*<br/>
Par esquerdo para comparar.

*direita*<br/>
Par correto para comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `right` `<` `left` . Você o usa para testar se a *esquerda* é ordenada após *direita* quando os dois pares são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_operator_gt.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);
    cliext::pair<wchar_t, int> c2(L'x', 4);
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);

    System::Console::WriteLine("[x 3] > [x 3] is {0}",
        c1 > c1);
    System::Console::WriteLine("[x 4] > [x 3] is {0}",
        c2 > c1);
    return (0);
    }
```

```Output
[x, 3]
[x, 4]
[x 3] > [x 3] is False
[x 4] > [x 3] is True
```

## <a name="operatorgt-pair-stlclr"></a><a name="op_gteq"></a> Operator &gt; = (par) (STL/CLR)

Par maior ou igual a comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator>=(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*esquerda*<br/>
Par esquerdo para comparar.

*direita*<br/>
Par correto para comparar.

### <a name="remarks"></a>Comentários

A função Operator retorna `!(left < right)` . Você o usa para testar se a *esquerda* não é ordenada antes da *direita* quando os dois pares são elementos comparados por elemento.

### <a name="example"></a>Exemplo

```cpp
// cliext_pair_operator_ge.cpp
// compile with: /clr
#include <cliext/utility>

int main()
    {
    cliext::pair<wchar_t, int> c1(L'x', 3);
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);
    cliext::pair<wchar_t, int> c2(L'x', 4);
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);

    System::Console::WriteLine("[x 3] >= [x 3] is {0}",
        c1 >= c1);
    System::Console::WriteLine("[x 3] >= [x 4] is {0}",
        c1 >= c2);
    return (0);
    }
```

```Output
[x, 3]
[x, 4]
[x 3] >= [x 3] is True
[x 3] >= [x 4] is False
```
