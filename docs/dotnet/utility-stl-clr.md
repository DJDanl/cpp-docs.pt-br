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
ms.openlocfilehash: 6d025230abcff42e367a231e616a13f0f8c684f0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320280"
---
# <a name="utility-stlclr"></a>utility (STL/CLR)

Inclua o cabeçalho `<cliext/utility>` STL/CLR `pair` para definir a classe de modelo e várias funções de modelo de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <utility>
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<cliext/utility>

**Namespace:** cliext

## <a name="declarations"></a>Declarations

|Classe|Descrição|
|-----------|-----------------|
|[pair (STL/CLR)](#pair)|Enrole um par de elementos.|

|Operador|Descrição|
|--------------|-----------------|
|[operator== (pair) (STL/CLR)](#op_eq)|Par igual comparação.|
|[operador!= (par) (STL/CLR)](#op_neq)|Par não igual a comparação.|
|[operador< (par) (STL/CLR)](#op_lt)|Par menos do que comparação.|
|[operador\<= (par) (STL/CLR)](#op_lteq)|Parear com menos ou igual comparação.|
|[operador> (par) (STL/CLR)](#op_gt)|Par maior do que comparação.|
|[operador>= (par) (STL/CLR)](#op_gteq)|Par maior ou igual comparativo.|

|Função|Descrição|
|--------------|-----------------|
|[make_pair (STL/CLR)](#make_pair)|Faça um par de valores.|

## <a name="members"></a>Membros

## <a name="pair-stlclr"></a><a name="pair"></a>par (STL/CLR)

A classe modelo descreve um objeto que envolve um par de valores.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    ref class pair;
```

#### <a name="parameters"></a>Parâmetros

*Value1*<br/>
O tipo de primeiro valor embrulhado.

*Value2*<br/>
O tipo de segundo valor embrulhado.

## <a name="members"></a>Membros

|Definição do tipo|Descrição|
|---------------------|-----------------|
|[pair::first_type (STL/CLR)](#first_type)|O tipo do primeiro valor embrulhado.|
|[pair::second_type (STL/CLR)](#second_type)|O tipo do segundo valor embrulhado.|

|Objeto de membro|Descrição|
|-------------------|-----------------|
|[pair::first (STL/CLR)](#first)|O primeiro valor armazenado.|
|[pair::second (STL/CLR)](#second)|O segundo valor armazenado.|

|Função membro|Descrição|
|---------------------|-----------------|
|[pair::pair (STL/CLR)](#pair_pair)|Constrói um objeto de par.|
|[pair::swap (STL/CLR)](#swap)|Troca o conteúdo de dois pares.|

|Operador|Descrição|
|--------------|-----------------|
|[pair::operator= (STL/CLR)](#op_as)|Substitui o par de valores armazenados.|

## <a name="remarks"></a>Comentários

O objeto armazena um par de valores. Você usa esta classe de modelo para combinar dois valores em um único objeto. Além disso, `cliext::pair` o objeto (descrito aqui) armazena apenas tipos gerenciados; para armazenar um par de `std::pair`tipos não `<utility>`gerenciados de uso, declarado em .

## <a name="pairfirst-stlclr"></a><a name="first"></a>pareamento::primeiro (STL/CLR)

O primeiro valor embrulhado.

### <a name="syntax"></a>Sintaxe

```cpp
Value1 first;
```

### <a name="remarks"></a>Comentários

O objeto armazena o primeiro valor embrulhado.

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

## <a name="pairfirst_type-stlclr"></a><a name="first_type"></a>par::first_type (STL/CLR)

O tipo do primeiro valor embrulhado.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value1 first_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo *Value1*.

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

## <a name="pairoperator-stlclr"></a><a name="op_as"></a>pareamento::operador= (STL/CLR)

Substitui o par de valores armazenados.

### <a name="syntax"></a>Sintaxe

```cpp
pair<Value1, Value2>% operator=(pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*Certo*<br/>
Par para copiar.

### <a name="remarks"></a>Comentários

O operador membro copia *o* direito `*this`ao objeto e retorna . Você o usa para substituir o par de valores armazenados por uma cópia do par de valores armazenados no *direito*.

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

## <a name="pairpair-stlclr"></a><a name="pair_pair"></a>:par (STL/CLR)

Constrói um objeto de par.

### <a name="syntax"></a>Sintaxe

```cpp
pair();
pair(pair<Coll>% right);
pair(pair<Coll>^ right);
pair(Value1 val1, Value2 val2);
```

#### <a name="parameters"></a>Parâmetros

*Certo*<br/>
Par para armazenar.

*val1*<br/>
Primeiro valor para armazenar.

*val2*<br/>
Segundo valor para armazenar.

### <a name="remarks"></a>Comentários

O construtor:

`pair();`

inicializa o par armazenado com valores construídos padrão.

O construtor:

`pair(pair<Value1, Value2>% right);`

inicializa o par `right.`armazenado com [par::primeiro (STL/CLR)](../dotnet/pair-first-stl-clr.md) e `right.` [par::segundo (STL/CLR)](../dotnet/pair-second-stl-clr.md).

`pair(pair<Value1, Value2>^ right);`

inicializa o par `right->`armazenado com [par::primeiro (STL/CLR)](../dotnet/pair-first-stl-clr.md) e `right>` [par::segundo (STL/CLR)](../dotnet/pair-second-stl-clr.md).

O construtor:

`pair(Value1 val1, Value2 val2);`

inicializa o par armazenado com *val1* e *val2*.

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

## <a name="pairsecond-stlclr"></a><a name="second"></a>pareamento::segundo (STL/CLR)

O segundo valor embrulhado.

### <a name="syntax"></a>Sintaxe

```cpp
Value2 second;
```

### <a name="remarks"></a>Comentários

O objeto armazena o segundo valor embrulhado.

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

## <a name="pairsecond_type-stlclr"></a><a name="second_type"></a>par::second_type (STL/CLR)

O tipo do segundo valor embrulhado.

### <a name="syntax"></a>Sintaxe

```cpp
typedef Value2 second_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo *Valor2*.

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

## <a name="pairswap-stlclr"></a><a name="swap"></a>par::swap (STL/CLR)

Troca o conteúdo de dois pares.

### <a name="syntax"></a>Sintaxe

```cpp
void swap(pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*Certo*<br/>
Parear para trocar o conteúdo.

### <a name="remarks"></a>Comentários

A função do membro troca o `*this` par armazenado de valores entre e *à direita*.

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

## <a name="make_pair-stlclr"></a><a name="make_pair"></a>make_pair (STL/CLR)

Faça `pair` um a partir de um par de valores.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    pair<Value1, Value2> make_pair(Value1 first, Value2 second);
```

#### <a name="parameters"></a>Parâmetros

*Value1*<br/>
O tipo do primeiro valor embrulhado.

*Value2*<br/>
O tipo do segundo valor embrulhado.

*Primeiro*<br/>
Primeiro valor para embrulhar.

*second*<br/>
Segundo valor para embrulhar.

### <a name="remarks"></a>Comentários

A função do modelo retorna `pair<Value1, Value2>(first, second)`. Você o usa `pair<Value1, Value2>` para construir um objeto a partir de um par de valores.

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

## <a name="operator-pair-stlclr"></a><a name="op_neq"></a>operador!= (par) (STL/CLR)

Par não igual a comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator!=(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*Deixou*<br/>
Par esquerdo para comparar.

*Certo*<br/>
Par certo para comparar.

### <a name="remarks"></a>Comentários

A função `!(left == right)`do operador retorna . Você o usa para testar se *a esquerda* não é ordenada da mesma forma que a *direita* quando os dois pares são comparados elemento por elemento.

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

## <a name="operatorlt-pair-stlclr"></a><a name="op_lt"></a>operador&lt; (par) (STL/CLR)

Par menos do que comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator<(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*Deixou*<br/>
Par esquerdo para comparar.

*Certo*<br/>
Par certo para comparar.

### <a name="remarks"></a>Comentários

A função `left.first <` `right.first || !(right.first <` `left.first &&` `left.second <` `right.second`do operador retorna . Você o usa para testar se *a esquerda* é ordenada antes da *direita* quando os dois pares são comparados elemento por elemento.

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

## <a name="operatorlt-pair-stlclr"></a><a name="op_lteq"></a>operador&lt;= (par) (STL/CLR)

Parear com menos ou igual comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator<=(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*Deixou*<br/>
Par esquerdo para comparar.

*Certo*<br/>
Par certo para comparar.

### <a name="remarks"></a>Comentários

A função `!(right < left)`do operador retorna . Você o usa para testar se *a esquerda* não é ordenada após a *direita* quando os dois pares são comparados elemento por elemento.

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

## <a name="operator-pair-stlclr"></a><a name="op_eq"></a>operador== (par) (STL/CLR)

Par igual comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator==(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*Deixou*<br/>
Par esquerdo para comparar.

*Certo*<br/>
Par certo para comparar.

### <a name="remarks"></a>Comentários

A função `left.first ==` `right.first &&` `left.second ==` `right.second`do operador retorna . Você o usa para testar se *a esquerda* é ordenada da mesma forma que a *direita* quando os dois pares são comparados elemento por elemento.

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

## <a name="operatorgt-pair-stlclr"></a><a name="op_gt"></a>operador&gt; (par) (STL/CLR)

Par maior do que comparação.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator>(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*Deixou*<br/>
Par esquerdo para comparar.

*Certo*<br/>
Par certo para comparar.

### <a name="remarks"></a>Comentários

A função `right` `<` `left`do operador retorna . Você o usa para testar se *a esquerda* é encomendada após a *direita* quando os dois pares são comparados elemento por elemento.

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

## <a name="operatorgt-pair-stlclr"></a><a name="op_gteq"></a>operador&gt;= (par) (STL/CLR)

Par maior ou igual comparativo.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Value1,
    typename Value2>
    bool operator>=(pair<Value1, Value2>% left,
        pair<Value1, Value2>% right);
```

#### <a name="parameters"></a>Parâmetros

*Deixou*<br/>
Par esquerdo para comparar.

*Certo*<br/>
Par certo para comparar.

### <a name="remarks"></a>Comentários

A função `!(left < right)`do operador retorna . Você o usa para testar se *a esquerda* não é ordenada antes *da direita* quando os dois pares são comparados elemento por elemento.

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
