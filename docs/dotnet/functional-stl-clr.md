---
title: functional (STL/CLR)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- <cliext/functional>
- cliext::binary_delegate
- cliext::binary_delegate_noreturn
- cliext::binary_negate
- cliext::bind1st
- cliext::bind2nd
- cliext::binder1st
- cliext::binder2nd
- cliext::divides
- cliext::equal_to
- cliext::greater
- cliext::greater_equal
- cliext::less
- cliext::less_equal
- cliext::logical_and
- cliext::logical_not
- cliext::logical_or
- cliext::minus
- cliext::modulus
- cliext::multiplies
- cliext::negate
- cliext::not_equal_to
- cliext::not1
- cliext::not2
- cliext::plus
- cliext::unary_delegate
- cliext::unary_delegate_noreturn
- cliext::unary_negate
helpviewer_keywords:
- <functional> header [STL/CLR]
- <cliext/functional> header [STL/CLR]
- functional functions [STL/CLR]
- binary_delegate function [STL/CLR]
- binary_delegate_noreturn function [STL/CLR]
- binary_negate function [STL/CLR]
- bind1st function [STL/CLR]
- bind2nd function [STL/CLR]
- binder1st function [STL/CLR]
- binder2nd function [STL/CLR]
- divides function [STL/CLR]
- equal_to function [STL/CLR]
- greater function [STL/CLR]
- greater_equal function [STL/CLR]
- less function [STL/CLR]
- less_equal function [STL/CLR]
- logical_and function [STL/CLR]
- logical_not function [STL/CLR]
- logical_or function [STL/CLR]
- minus function [STL/CLR]
- modulus function [STL/CLR]
- multiplies function [STL/CLR]
- negate function [STL/CLR]
- not_equal_to function [STL/CLR]
- not1 function [STL/CLR]
- not2 function [STL/CLR]
- plus function [STL/CLR]
- unary_delegate function [STL/CLR]
- unary_delegate_noreturn function [STL/CLR]
- unary_negate function [STL/CLR]
ms.assetid: 88738b8c-5d37-4375-970e-a4442bf5efde
ms.openlocfilehash: 5cfec19ad8a25d3b44647e490b2c328a5639e675
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743302"
---
# <a name="functional-stlclr"></a>functional (STL/CLR)

Inclua o cabeçalho STL/CLR `<cliext/functional>` para definir um número de classes de modelo e delegados e funções de modelo relacionados.

## <a name="syntax"></a>Sintaxe

```
#include <functional>
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<cliext/functional>

**Namespace:** cliext

## <a name="declarations"></a>Declarações

|Delegar|Descrição|
|--------------|-----------------|
|[binary_delegate (STL/CLR)](#binary_delegate)|Delegado de dois argumentos.|
|[binary_delegate_noreturn (STL/CLR)](#binary_delegate_noreturn)|Delegado de dois argumentos retornando **`void`** .|
|[unary_delegate (STL/CLR)](#unary_delegate)|Delegado de um argumento.|
|[unary_delegate_noreturn (STL/CLR)](#unary_delegate_noreturn)|Delegado de um argumento retornando **`void`** .|

|Classe|Descrição|
|-----------|-----------------|
|[binary_negate (STL/CLR)](#binary_negate)|Functor para negar um functor de dois argumentos.|
|[binder1st (STL/CLR)](#binder1st)|Functor para associar o primeiro argumento a um functor de dois argumentos.|
|[binder2nd (STL/CLR)](#binder2nd)|Functor para associar o segundo argumento a um functor de dois argumentos.|
|[divides (STL/CLR)](#divides)|Dividir functor.|
|[equal_to (STL/CLR)](#equal_to)|Functor de comparação igual.|
|[greater (STL/CLR)](#greater)|Maior functor de comparação.|
|[greater_equal (STL/CLR)](#greater_equal)|Functor de comparação maior ou igual.|
|[less (STL/CLR)](#less)|Menos functor de comparação.|
|[less_equal (STL/CLR)](#less_equal)|Functor de comparação menor ou igual a.|
|[logical_and (STL/CLR)](#logical_and)|AND lógico functor.|
|[logical_not (STL/CLR)](#logical_not)|Não functor lógico.|
|[logical_or (STL/CLR)](#logical_or)|OR lógico ou functor.|
|[minus (STL/CLR)](#minus)|Subtraia functor.|
|[modulus (STL/CLR)](#modulus)|Módulo functor.|
|[multiplies (STL/CLR)](#multiplies)|Multiplique functor.|
|[negate (STL/CLR)](#negate)|Functor para retornar seu argumento negado.|
|[not_equal_to (STL/CLR)](#not_equal_to)|Não é igual a functor de comparação.|
|[plus (STL/CLR)](#plus)|Adicione functor.|
|[unary_negate (STL/CLR)](#unary_negate)|Functor para negar um functor de um argumento.|

|Função|Descrição|
|--------------|-----------------|
|[bind1st (STL/CLR)](#bind1st)|Gera um binder1st para um argumento e functor.|
|[bind2nd (STL/CLR)](#bind2nd)|Gera um binder2nd para um argumento e functor.|
|[not1 (STL/CLR)](#not1)|Gera um unary_negate para um functor.|
|[not2 (STL/CLR)](#not2)|Gera um binary_negate para um functor.|

## <a name="members"></a>Membros

## <a name="binary_delegate-stlclr"></a><a name="binary_delegate"></a> binary_delegate (STL/CLR)

A classe genereic descreve um delegado de dois argumentos. Use-o para especificar um delegado em termos de seus tipos de retorno e argumento.

### <a name="syntax"></a>Sintaxe

```cpp
generic<typename Arg1,
    typename Arg2,
    typename Result>
    delegate Result binary_delegate(Arg1, Arg2);
```

#### <a name="parameters"></a>Parâmetros

*Arg1*<br/>
O tipo do primeiro argumento.

*Arg2*<br/>
O tipo do segundo argumento.

*Resultado*<br/>
O tipo de retorno.

### <a name="remarks"></a>Comentários

O delegado genereic descreve uma função de dois argumentos.

Observe que para:

`binary_delegate<int, int, int> Fun1;`

`binary_delegate<int, int, int> Fun2;`

os tipos `Fun1` e `Fun2` são sinônimos, enquanto para:

`delegate int Fun1(int, int);`

`delegate int Fun2(int, int);`

Eles não são do mesmo tipo.

### <a name="example"></a>Exemplo

```cpp
// cliext_binary_delegate.cpp
// compile with: /clr
#include <cliext/functional>

bool key_compare(wchar_t left, wchar_t right)
    {
    return (left < right);
    }

typedef cliext::binary_delegate<wchar_t, wchar_t, bool> Mydelegate;
int main()
    {
    Mydelegate^ kcomp = gcnew Mydelegate(&key_compare);

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

## <a name="binary_delegate_noreturn-stlclr"></a><a name="binary_delegate_noreturn"></a> binary_delegate_noreturn (STL/CLR)

A classe genereic descreve um delegado de dois argumentos que retorna **`void`** . Use-o para especificar um delegado em termos de seu argumento.

### <a name="syntax"></a>Sintaxe

```cpp
generic<typename Arg1,
    typename Arg2>
    delegate void binary_delegate(Arg1, Arg2);
```

#### <a name="parameters"></a>Parâmetros

*Arg1*<br/>
O tipo do primeiro argumento.

*Arg2*<br/>
O tipo do segundo argumento.

### <a name="remarks"></a>Comentários

O delegado genereic descreve uma função de dois argumentos que retorna **`void`** .

Observe que para:

`binary_delegate_noreturn<int, int> Fun1;`

`binary_delegate_noreturn<int, int> Fun2;`

os tipos `Fun1` e `Fun2` são sinônimos, enquanto para:

`delegate void Fun1(int, int);`

`delegate void Fun2(int, int);`

Eles não são do mesmo tipo.

### <a name="example"></a>Exemplo

```cpp
// cliext_binary_delegate_noreturn.cpp
// compile with: /clr
#include <cliext/functional>

void key_compare(wchar_t left, wchar_t right)
    {
    System::Console::WriteLine("compare({0}, {1}) = {2}",
        left, right, left < right);
    }

typedef cliext::binary_delegate_noreturn<wchar_t, wchar_t> Mydelegate;
int main()
    {
    Mydelegate^ kcomp = gcnew Mydelegate(&key_compare);

    kcomp(L'a', L'a');
    kcomp(L'a', L'b');
    kcomp(L'b', L'a');
    System::Console::WriteLine();
    return (0);
    }
```

```Output
compare(a, a) = False
compare(a, b) = True
compare(b, a) = False
```

## <a name="binary_negate-stlclr"></a><a name="binary_negate"></a> binary_negate (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna a lógica não de seu functor de dois argumentos armazenado. Use-o para especificar um objeto de função em termos de seu functor armazenado.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun>
    ref class binary_negate
    { // wrap operator()
public:
    typedef Fun stored_function_type;
    typedef typename Fun::first_argument_type first_argument_type;
    typedef typename Fun::second_argument_type second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    explicit binary_negate(Fun% functor);
    binary_negate(binary_negate<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*Diversão*<br/>
O tipo do functor armazenado.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|
|stored_function_type|O tipo de functor.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|binary_negate|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^ ()|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos que armazena outro functor de dois argumentos. Ele define o operador membro `operator()` para que, quando o objeto for chamado como uma função, ele retorne a lógica não do functor armazenado chamado com os dois argumentos.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_binary_negate.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(4);
    c2.push_back(4);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 4 4"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::less<int> less_op;

    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(),
        cliext::binary_negate<cliext::less<int> >(less_op));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display with function
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::not2(less_op));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
4 4
1 0
1 0
```

## <a name="bind1st-stlclr"></a><a name="bind1st"></a> bind1st (STL/CLR)

Gera um `binder1st` para um argumento e functor.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun,
    typename Arg>
    binder1st<Fun> bind1st(Fun% functor,
        Arg left);
```

#### <a name="template-parameters"></a>Parâmetros de modelo

*ARG*<br/>
O tipo do argumento.

*Diversão*<br/>
O tipo de functor.

#### <a name="function-parameters"></a>Parâmetros de Função

*functor*<br/>
O functor a ser quebrado.

*esquerda*<br/>
O primeiro argumento a ser encapsulado.

### <a name="remarks"></a>Comentários

A função de modelo retorna [binder1st (STL/CLR)](../dotnet/binder1st-stl-clr.md) `<Fun>(functor, left)` . Você o usa como uma maneira conveniente de encapsular um functor de dois argumentos e seu primeiro argumento em um functor de um argumento que o chama com um segundo argumento.

### <a name="example"></a>Exemplo

```cpp
// cliext_bind1st.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c3(2, 0);

// display initial contents " 4 3"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::minus<int> sub_op;
    cliext::binder1st<cliext::minus<int> > subfrom3(sub_op, 3);

    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        subfrom3);
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display with function
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        bind1st(sub_op, 3));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
-1 0
-1 0
```

## <a name="bind2nd-stlclr"></a><a name="bind2nd"></a> bind2nd (STL/CLR)

Gera um `binder2nd` para um argumento e functor.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun,
    typename Arg>
    binder2nd<Fun> bind2nd(Fun% functor,
        Arg right);
```

#### <a name="template-parameters"></a>Parâmetros de modelo

*ARG*<br/>
O tipo do argumento.

*Diversão*<br/>
O tipo de functor.

#### <a name="function-parameters"></a>Parâmetros de Função

*functor*<br/>
O functor a ser quebrado.

*direita*<br/>
O segundo argumento a ser encapsulado.

### <a name="remarks"></a>Comentários

A função de modelo retorna [binder2nd (STL/CLR)](../dotnet/binder2nd-stl-clr.md) `<Fun>(functor, right)` . Você o usa como uma maneira conveniente de encapsular um functor de dois argumentos e seu segundo argumento em um functor de um argumento que o chama com um primeiro argumento.

### <a name="example"></a>Exemplo

```cpp
// cliext_bind2nd.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c3(2, 0);

// display initial contents " 4 3"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::minus<int> sub_op;
    cliext::binder2nd<cliext::minus<int> > sub4(sub_op, 4);

    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        sub4);
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display with function
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        bind2nd(sub_op, 4));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
0 -1
0 -1
```

## <a name="binder1st-stlclr"></a><a name="binder1st"></a> binder1st (STL/CLR)

A classe de modelo descreve um functor de um argumento que, quando chamado, retorna seu functor de dois argumentos armazenado chamado com seu primeiro argumento armazenado e o segundo argumento fornecido. Use-o para especificar um objeto de função em termos de seu functor armazenado.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun>
    ref class binder1st
    { // wrap operator()
public:
    typedef Fun stored_function_type;
    typedef typename Fun::first_argument_type first_argument_type;
    typedef typename Fun::second_argument_type second_argument_type;
    typedef typename Fun:result_type result_type;
    typedef Microsoft::VisualC::StlClr::UnaryDelegate<
        second_argument_type, result_type>
        delegate_type;

    binder1st(Fun% functor, first_argument_type left);
    binder1st(binder1st<Arg>% right);

    result_type operator()(second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*Diversão*<br/>
O tipo do functor armazenado.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|
|stored_function_type|O tipo de functor.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|binder1st|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^ ()|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe template descreve um functor de um argumento que armazena um functor de dois argumentos e um primeiro argumento. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retorne o resultado da chamada do functor armazenado com o primeiro argumento armazenado e o segundo argumento fornecido.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_binder1st.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c3(2, 0);

// display initial contents " 4 3"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::minus<int> sub_op;
    cliext::binder1st<cliext::minus<int> > subfrom3(sub_op, 3);

    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        subfrom3);
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display with function
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        bind1st(sub_op, 3));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
-1 0
-1 0
```

## <a name="binder2nd-stlclr"></a><a name="binder2nd"></a> binder2nd (STL/CLR)

A classe de modelo descreve um functor de um argumento que, quando chamado, retorna seu functor de dois argumentos armazenado chamado com o primeiro argumento fornecido e seu segundo argumento armazenado. Use-o para especificar um objeto de função em termos de seu functor armazenado.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun>
    ref class binder2nd
    { // wrap operator()
public:
    typedef Fun stored_function_type;
    typedef typename Fun::first_argument_type first_argument_type;
    typedef typename Fun::second_argument_type second_argument_type;
    typedef typename Fun:result_type result_type;
    typedef Microsoft::VisualC::StlClr::UnaryDelegate<
        first_argument_type, result_type>
        delegate_type;

    binder2nd(Fun% functor, second_argument_type left);
    binder2nd(binder2nd<Arg>% right);

    result_type operator()(first_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*Diversão*<br/>
O tipo do functor armazenado.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|
|stored_function_type|O tipo de functor.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|binder2nd|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^ ()|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe template descreve um functor de um argumento que armazena um functor de dois argumentos e um segundo argumento. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retorne o resultado da chamada do functor armazenado com o primeiro argumento fornecido e o segundo argumento armazenado.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_binder2nd.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c3(2, 0);

// display initial contents " 4 3"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::minus<int> sub_op;
    cliext::binder2nd<cliext::minus<int> > sub4(sub_op, 4);

    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        sub4);
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display with function
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        bind2nd(sub_op, 4));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
0 -1
0 -1
```

## <a name="divides-stlclr"></a><a name="divides"></a> divisões (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna o primeiro argumento dividido pelo segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class divides
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef Arg result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    divides();
    divides(divides<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos e o valor de retorno.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|divides|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^ ()|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retorne o primeiro argumento dividido pelo segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_divides.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(2);
    c2.push_back(1);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 2 1"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::divides<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
2 1
2 3
```

## <a name="equal_to-stlclr"></a><a name="equal_to"></a> equal_to (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retornará true somente se o primeiro argumento for igual ao segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class equal_to
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    equal_to();
    equal_to(equal_to<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|equal_to|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^ ()|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retornará true somente se o primeiro argumento for igual ao segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_equal_to.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(4);
    c2.push_back(4);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 4 4"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::equal_to<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
4 4
1 0
```

## <a name="greater-stlclr"></a><a name="greater"></a> maior (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retornará true somente se o primeiro argumento for maior que o segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class greater
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    greater();
    greater(greater<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|greater|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retornará true somente se o primeiro argumento for maior que o segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_greater.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(3);
    c2.push_back(3);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 3 3"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::greater<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
3 3
1 0
```

## <a name="greater_equal-stlclr"></a><a name="greater_equal"></a> greater_equal (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retornará true somente se o primeiro argumento for maior ou igual ao segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class greater_equal
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    greater_equal();
    greater_equal(greater_equal<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|greater_equal|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retornará true somente se o primeiro argumento for maior ou igual ao segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_greater_equal.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(4);
    c2.push_back(4);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 4 4"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::greater_equal<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
4 4
1 0
```

## <a name="less-stlclr"></a><a name="less"></a> Less (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retornará true somente se o primeiro argumento for menor que o segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class less
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    less();
    less(less<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|less|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retornará true somente se o primeiro argumento for menor que o segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_less.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(4);
    c2.push_back(4);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 4 4"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::less<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
4 4
0 1
```

## <a name="less_equal-stlclr"></a><a name="less_equal"></a> less_equal (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retornará true somente se o primeiro argumento for menor ou igual ao segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class less_equal
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    less_equal();
    less_equal(less_equal<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|less_equal|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retornará true somente se o primeiro argumento for menor ou igual ao segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_less_equal.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(3);
    c2.push_back(3);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 3 3"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::less_equal<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
3 3
0 1
```

## <a name="logical_and-stlclr"></a><a name="logical_and"></a> logical_and (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna true somente se o primeiro argumento e o segundo teste forem verdadeiros. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class logical_and
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    logical_and();
    logical_and(logical_and<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|logical_and|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador membro de `operator()` modo que, quando o objeto for chamado como uma função, ele retornará true somente se o primeiro argumento e o segundo teste forem verdadeiros.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_logical_and.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(2);
    c1.push_back(0);
    Myvector c2;
    c2.push_back(3);
    c2.push_back(0);
    Myvector c3(2, 0);

// display initial contents " 1 0" and " 1 0"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::logical_and<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
2 0
3 0
1 0
```

## <a name="logical_not-stlclr"></a><a name="logical_not"></a> logical_not (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna true somente se o argumento for testado como falso. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class logical_not
    { // wrap operator()
public:
    typedef Arg argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::UnaryDelegate<
        argument_type, result_type>
        delegate_type;

    logical_not();
    logical_not(logical_not<Arg> %right);

    result_type operator()(argument_type left);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|argument_type|O tipo do argumento functor.|
|delegate_type|O tipo do delegado genérico.|
|result_type|O tipo do resultado de functor.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|logical_not|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de um argumento. Ele define o operador membro de `operator()` modo que, quando o objeto for chamado como uma função, ele retornará true somente se seu argumento testar como false.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_logical_not.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(0);
    Myvector c3(2, 0);

// display initial contents " 4 0"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c3.begin(), cliext::logical_not<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 0
0 1
```

## <a name="logical_or-stlclr"></a><a name="logical_or"></a> logical_or (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna true somente se o primeiro argumento ou o segundo é testado como verdadeiro. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class logical_or
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    logical_or();
    logical_or(logical_or<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|logical_or|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retornará true somente se o primeiro argumento ou o segundo for definido como true.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_logical_or.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(2);
    c1.push_back(0);
    Myvector c2;
    c2.push_back(0);
    c2.push_back(0);
    Myvector c3(2, 0);

// display initial contents " 2 0" and " 0 0"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::logical_or<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
2 0
0 0
1 0
```

## <a name="minus-stlclr"></a><a name="minus"></a> menos (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna o primeiro argumento menos o segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class minus
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef Arg result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    minus();
    minus(minus<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos e o valor de retorno.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|minus|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retorne o primeiro argumento menos o segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_minus.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(2);
    c2.push_back(1);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 2 1"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::minus<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
2 1
2 2
```

## <a name="modulus-stlclr"></a><a name="modulus"></a> módulo (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna o primeiro módulo de argumento para o segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class modulus
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef Arg result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    modulus();
    modulus(modulus<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos e o valor de retorno.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|módulo|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retorne o primeiro módulo de argumento o segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_modulus.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(2);
    Myvector c2;
    c2.push_back(3);
    c2.push_back(1);
    Myvector c3(2, 0);

// display initial contents " 4 2" and " 3 1"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::modulus<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 2
3 1
1 0
```

## <a name="multiplies-stlclr"></a><a name="multiplies"></a> multiplicações (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna o primeiro argumento vezes o segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class multiplies
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef Arg result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    multiplies();
    multiplies(multiplies<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos e o valor de retorno.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|multiplies|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retorne o primeiro argumento vezes o segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_multiplies.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(2);
    c2.push_back(1);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 2 1"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::multiplies<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
2 1
8 3
```

## <a name="negate-stlclr"></a><a name="negate"></a> negação (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna seu argumento negado. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class negate
    { // wrap operator()
public:
    typedef Arg argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::UnaryDelegate<
        argument_type, result_type>
        delegate_type;

    negate();
    negate(negate<Arg>% right);

    result_type operator()(argument_type left);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|argument_type|O tipo do argumento functor.|
|delegate_type|O tipo do delegado genérico.|
|result_type|O tipo do resultado de functor.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|negate|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de um argumento. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retorne seu argumento negado.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_negate.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(-3);
    Myvector c3(2, 0);

// display initial contents " 4 -3"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c3.begin(), cliext::negate<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 -3
-4 3
```

## <a name="not_equal_to-stlclr"></a><a name="not_equal_to"></a> not_equal_to (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retornará true somente se o primeiro argumento não for igual ao segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class not_equal_to
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    not_equal_to();
    not_equal_to(not_equal_to<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|not_equal_to|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retornará true somente se o primeiro argumento não for igual ao segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_not_equal_to.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(4);
    c2.push_back(4);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 4 4"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::not_equal_to<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
4 4
0 1
```

## <a name="not1-stlclr"></a><a name="not1"></a> not1 (STL/CLR)

Gera um `unary_negate` para um functor.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun>
    unary_negate<Fun> not1(Fun% functor);
```

#### <a name="template-parameters"></a>Parâmetros de modelo

*Diversão*<br/>
O tipo de functor.

#### <a name="function-parameters"></a>Parâmetros de Função

*functor*<br/>
O functor a ser quebrado.

### <a name="remarks"></a>Comentários

A função de modelo retorna [unary_negate (STL/CLR)](../dotnet/unary-negate-stl-clr.md) `<Fun>(functor)` . Você o usa como uma maneira conveniente de encapsular um functor de um argumento em um functor que entrega seu não lógico.

### <a name="example"></a>Exemplo

```cpp
// cliext_not1.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(0);
    Myvector c3(2, 0);

// display initial contents " 4 0"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::logical_not<int> not_op;

    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        cliext::unary_negate<cliext::logical_not<int> >(not_op));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display with function
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        cliext::not1(not_op));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 0
1 0
1 0
```

## <a name="not2-stlclr"></a><a name="not2"></a> not2 (STL/CLR)

Gera um `binary_negate` para um functor.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun>
    binary_negate<Fun> not2(Fun% functor);
```

#### <a name="template-parameters"></a>Parâmetros de modelo

*Diversão*<br/>
O tipo de functor.

#### <a name="function-parameters"></a>Parâmetros de Função

*functor*<br/>
O functor a ser quebrado.

### <a name="remarks"></a>Comentários

A função de modelo retorna [binary_negate (STL/CLR)](../dotnet/binary-negate-stl-clr.md) `<Fun>(functor)` . Você o usa como uma maneira conveniente de encapsular um functor de dois argumentos em um functor que entrega seu não lógico.

### <a name="example"></a>Exemplo

```cpp
// cliext_not2.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(4);
    c2.push_back(4);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 4 4"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::less<int> less_op;

    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(),
        cliext::binary_negate<cliext::less<int> >(less_op));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display with function
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::not2(less_op));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
4 4
1 0
1 0
```

## <a name="plus-stlclr"></a><a name="plus"></a> mais (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna o primeiro argumento mais o segundo. Use-o para especificar um objeto de função em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Arg>
    ref class plus
    { // wrap operator()
public:
    typedef Arg first_argument_type;
    typedef Arg second_argument_type;
    typedef Arg result_type;
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<
        first_argument_type, second_argument_type, result_type>
        delegate_type;

    plus();
    plus(plus<Arg>% right);

    result_type operator()(first_argument_type left,
        second_argument_type right);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo dos argumentos e o valor de retorno.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado de functor.|
|second_argument_type|O tipo do functor segundo argumento.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|plus|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|operador delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um functor de dois argumentos. Ele define o operador member `operator()` para que, quando o objeto for chamado como uma função, ele retorne o primeiro argumento mais o segundo.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_plus.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(3);
    Myvector c2;
    c2.push_back(2);
    c2.push_back(1);
    Myvector c3(2, 0);

// display initial contents " 4 3" and " 2 1"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

    for each (int elem in c2)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::transform(c1.begin(), c1.begin() + 2,
        c2.begin(), c3.begin(), cliext::plus<int>());
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 3
2 1
6 4
```

## <a name="unary_delegate-stlclr"></a><a name="unary_delegate"></a> unary_delegate (STL/CLR)

A classe genereic descreve um delegado de um argumento. Use-o para especificar um delegado em termos de seus tipos de retorno e argumento.

### <a name="syntax"></a>Sintaxe

```cpp
generic<typename Arg,
    typename Result>
    delegate Result unary_delegate(Arg);
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo do argumento.

*Resultado*<br/>
O tipo de retorno.

### <a name="remarks"></a>Comentários

O delegado genereic descreve uma função de um argumento.

Observe que para:

`unary_delegare<int, int> Fun1;`

`unary_delegare<int, int> Fun2;`

os tipos `Fun1` e `Fun2` são sinônimos, enquanto para:

`delegate int Fun1(int);`

`delegate int Fun2(int);`

Eles não são do mesmo tipo.

### <a name="example"></a>Exemplo

```cpp
// cliext_unary_delegate.cpp
// compile with: /clr
#include <cliext/functional>

int hash_val(wchar_t val)
    {
    return ((val * 17 + 31) % 67);
    }

typedef cliext::unary_delegate<wchar_t, int> Mydelegate;
int main()
    {
    Mydelegate^ myhash = gcnew Mydelegate(&hash_val);

    System::Console::WriteLine("hash(L'a') = {0}", myhash(L'a'));
    System::Console::WriteLine("hash(L'b') = {0}", myhash(L'b'));
    return (0);
    }
```

```Output
hash(L'a') = 5
hash(L'b') = 22
```

## <a name="unary_delegate_noreturn-stlclr"></a><a name="unary_delegate_noreturn"></a> unary_delegate_noreturn (STL/CLR)

A classe genereic descreve um delegado de um argumento que retorna **`void`** . Use-o para especificar um delegado em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
generic<typename Arg>
    delegate void unary_delegate_noreturn(Arg);
```

#### <a name="parameters"></a>Parâmetros

*ARG*<br/>
O tipo do argumento.

### <a name="remarks"></a>Comentários

O delegado genereic descreve uma função de um argumento que retorna **`void`** .

Observe que para:

`unary_delegare_noreturn<int> Fun1;`

`unary_delegare_noreturn<int> Fun2;`

os tipos `Fun1` e `Fun2` são sinônimos, enquanto para:

`delegate void Fun1(int);`

`delegate void Fun2(int);`

Eles não são do mesmo tipo.

### <a name="example"></a>Exemplo

```cpp
// cliext_unary_delegate_noreturn.cpp
// compile with: /clr
#include <cliext/functional>

void hash_val(wchar_t val)
    {
    System::Console::WriteLine("hash({0}) = {1}",
       val, (val * 17 + 31) % 67);
    }

typedef cliext::unary_delegate_noreturn<wchar_t> Mydelegate;
int main()
    {
    Mydelegate^ myhash = gcnew Mydelegate(&hash_val);

    myhash(L'a');
    myhash(L'b');
    return (0);
    }
```

```Output
hash(a) = 5
hash(b) = 22
```

## <a name="unary_negate-stlclr"></a><a name="unary_negate"></a> unary_negate (STL/CLR)

A classe de modelo descreve um functor que, quando chamado, retorna a lógica não de seu functor de um argumento armazenado. Use-o para especificar um objeto de função em termos de seu functor armazenado.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun>
    ref class unary_negate
    { // wrap operator()
public:
    typedef Fun stored_function_type;
    typedef typename Fun::argument_type argument_type;
    typedef bool result_type;
    typedef Microsoft::VisualC::StlClr::UnaryDelegate<
        argument_type, result_type>
        delegate_type;

    unary_negate(Fun% functor);
    unary_negate(unary_negate<Fun>% right);

    result_type operator()(argument_type left);
    operator delegate_type^();
    };
```

#### <a name="parameters"></a>Parâmetros

*Diversão*<br/>
O tipo do functor armazenado.

### <a name="member-functions"></a>Funções de membro

|Definição de tipo|Descrição|
|---------------------|-----------------|
|argument_type|O tipo do argumento functor.|
|delegate_type|O tipo do delegado genérico.|
|result_type|O tipo do resultado de functor.|

|Membro|DESCRIÇÃO|
|------------|-----------------|
|unary_negate|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Computa a função desejada.|
|delegate_type ^|Converte o functor em um delegado.|

### <a name="remarks"></a>Comentários

A classe template descreve um functor de um argumento que armazena outro functor de um argumento. Ele define o operador membro `operator()` para que, quando o objeto for chamado como uma função, ele retorne a lógica não do functor armazenado chamado com o argumento.

Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido adequadamente.

### <a name="example"></a>Exemplo

```cpp
// cliext_unary_negate.cpp
// compile with: /clr
#include <cliext/algorithm>
#include <cliext/functional>
#include <cliext/vector>

typedef cliext::vector<int> Myvector;
int main()
    {
    Myvector c1;
    c1.push_back(4);
    c1.push_back(0);
    Myvector c3(2, 0);

// display initial contents " 4 0"
    for each (int elem in c1)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display
    cliext::logical_not<int> not_op;

    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        cliext::unary_negate<cliext::logical_not<int> >(not_op));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();

// transform and display with function
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),
        cliext::not1(not_op));
    for each (int elem in c3)
        System::Console::Write(" {0}", elem);
    System::Console::WriteLine();
    return (0);
    }
```

```Output
4 0
1 0
1 0
```
