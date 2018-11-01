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
ms.openlocfilehash: f4a99ea972c6d2ea9b9721664cc75dec257fd7b3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472898"
---
# <a name="functional-stlclr"></a>functional (STL/CLR)

Inclua o cabeçalho STL/CLR `<cliext/functional>` para definir a um número de classes de modelo e delegados de modelo relacionados e funções.

## <a name="syntax"></a>Sintaxe

```
#include <functional>
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<cliext/functional >

**Namespace:** cliext

## <a name="declarations"></a>Declarações

|delegado|Descrição|
|--------------|-----------------|
|[binary_delegate (STL/CLR)](#binary_delegate)|Delegado com dois argumentos.|
|[binary_delegate_noreturn (STL/CLR)](#binary_delegate_noreturn)|Delegado de dois argumentos retornando **void**.|
|[unary_delegate (STL/CLR)](#unary_delegate)|Um argumento delegado.|
|[unary_delegate_noreturn (STL/CLR)](#unary_delegate_noreturn)|Um argumento delegado retornando **void**.|

|Classe|Descrição|
|-----------|-----------------|
|[binary_negate (STL/CLR)](#binary_negate)|Functor para negar um funtor dois argumentos.|
|[binder1st (STL/CLR)](#binder1st)|Functor para associar o primeiro argumento para um funtor de dois argumentos.|
|[binder2nd (STL/CLR)](#binder2nd)|Functor para associar o segundo argumento para um funtor de dois argumentos.|
|[divides (STL/CLR)](#divides)|Divida o functor.|
|[equal_to (STL/CLR)](#equal_to)|Comparação de igualdade functor.|
|[greater (STL/CLR)](#greater)|Maior functor de comparação.|
|[greater_equal (STL/CLR)](#greater_equal)|Functor de comparação maior ou igual.|
|[less (STL/CLR)](#less)|Menos functor de comparação.|
|[less_equal (STL/CLR)](#less_equal)|Functor de comparação de menor ou igual.|
|[logical_and (STL/CLR)](#logical_and)|Functor do AND lógico.|
|[logical_not (STL/CLR)](#logical_not)|Lógica não functor.|
|[logical_or (STL/CLR)](#logical_or)|Functor do OR lógico.|
|[minus (STL/CLR)](#minus)|Subtrai functor.|
|[modulus (STL/CLR)](#modulus)|Functor de módulo.|
|[multiplies (STL/CLR)](#multiplies)|Multiplique o functor.|
|[negate (STL/CLR)](#negate)|Functor para retornar a seu argumento negado.|
|[not_equal_to (STL/CLR)](#not_equal_to)|Functor de comparação não é igual.|
|[plus (STL/CLR)](#plus)|Adicione o functor.|
|[unary_negate (STL/CLR)](#unary_negate)|Functor para negar um funtor um argumento.|

|Função|Descrição|
|--------------|-----------------|
|[bind1st (STL/CLR)](#bind1st)|Gera um binder1st para um argumento e o functor.|
|[bind2nd (STL/CLR)](#bind2nd)|Gera um binder2nd para um argumento e o functor.|
|[not1 (STL/CLR)](#not1)|Gera um unary_negate para um functor.|
|[not2 (STL/CLR)](#not2)|Gera um binary_negate para um functor.|

## <a name="members"></a>Membros

## <a name="binary_delegate"></a> binary_delegate (STL/CLR)

A classe genereic descreve um delegado de dois argumentos. Você usá-lo especificar um representante em termos de seus argumento e tipos de retorno.

### <a name="syntax"></a>Sintaxe

```cpp
generic<typename Arg1,
    typename Arg2,
    typename Result>
    delegate Result binary_delegate(Arg1, Arg2);
```

#### <a name="parameters"></a>Parâmetros

*arg1*<br/>
O tipo do primeiro argumento.

*Arg2*<br/>
O tipo do segundo argumento.

*Result*<br/>
O tipo de retorno.

### <a name="remarks"></a>Comentários

O delegado genereic descreve uma função de dois argumentos.

Observe que para:

`binary_delegate<int, int, int> Fun1;`

`binary_delegate<int, int, int> Fun2;`

os tipos `Fun1` e `Fun2` são sinônimos, enquanto para:

`delegate int Fun1(int, int);`

`delegate int Fun2(int, int);`

eles não são do mesmo tipo.

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

## <a name="binary_delegate_noreturn"></a> binary_delegate_noreturn (STL/CLR)

A classe genereic descreve um delegado de dois argumentos que retorna **void**. Você usá-lo especificar um representante em termos de seu argumento.

### <a name="syntax"></a>Sintaxe

```cpp
generic<typename Arg1,
    typename Arg2>
    delegate void binary_delegate(Arg1, Arg2);
```

#### <a name="parameters"></a>Parâmetros

*arg1*<br/>
O tipo do primeiro argumento.

*Arg2*<br/>
O tipo do segundo argumento.

### <a name="remarks"></a>Comentários

O delegado genereic descreve uma função de dois argumentos que retorna **void**.

Observe que para:

`binary_delegate_noreturn<int, int> Fun1;`

`binary_delegate_noreturn<int, int> Fun2;`

os tipos `Fun1` e `Fun2` são sinônimos, enquanto para:

`delegate void Fun1(int, int);`

`delegate void Fun2(int, int);`

eles não são do mesmo tipo.

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

## <a name="binary_negate"></a> binary_negate (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna a lógica não é do seu armazenado functor de dois argumentos. Você usá-lo especificar um objeto de função em termos de seu functor armazenado.

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

## <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|
|stored_function_type|O tipo do functor.|

|Membro|Descrição|
|------------|-----------------|
|binary_negate|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type^()|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor de dois argumentos que armazena a outro functor de dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna a lógica não do functor armazenado chamado com dois argumentos.

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

## <a name="bind1st"></a> bind1st (STL/CLR)

Gera um `binder1st` para um argumento e o functor.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun,
    typename Arg>
    binder1st<Fun> bind1st(Fun% functor,
        Arg left);
```

#### <a name="template-parameters"></a>Parâmetros de modelo

*arg*<br/>
O tipo do argumento.

*Diversão*<br/>
O tipo do functor.

#### <a name="function-parameters"></a>Parâmetros de função

*functor*<br/>
O functor para encapsular.

*left*<br/>
O primeiro argumento para encapsular.

### <a name="remarks"></a>Comentários

Retorna a função de modelo [binder1st (STL/CLR)](../dotnet/binder1st-stl-clr.md)`<Fun>(functor, left)`. Você pode usá-lo como uma maneira conveniente de encapsular um funtor dois argumentos e o seu primeiro argumento em um funtor um argumento que faz a chamada com um segundo argumento.

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

## <a name="bind2nd"></a> bind2nd (STL/CLR)

Gera um `binder2nd` para um argumento e o functor.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun,
    typename Arg>
    binder2nd<Fun> bind2nd(Fun% functor,
        Arg right);
```

#### <a name="template-parameters"></a>Parâmetros de modelo

*arg*<br/>
O tipo do argumento.

*Diversão*<br/>
O tipo do functor.

#### <a name="function-parameters"></a>Parâmetros de função

*functor*<br/>
O functor para encapsular.

*right*<br/>
O segundo argumento para encapsular.

### <a name="remarks"></a>Comentários

Retorna a função de modelo [binder2nd (STL/CLR)](../dotnet/binder2nd-stl-clr.md)`<Fun>(functor, right)`. Você pode usá-lo como uma maneira conveniente de encapsular um funtor dois argumentos e o segundo argumento em um funtor um argumento que faz a chamada com um primeiro argumento.

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

## <a name="binder1st"></a> binder1st (STL/CLR)

A classe de modelo descreve um funtor um argumento que, quando chamado, retorna seu functor dois argumentos armazenado chamado com seu primeiro argumento armazenado e o segundo argumento fornecido. Você usá-lo especificar um objeto de função em termos de seu functor armazenado.

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

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|
|stored_function_type|O tipo do functor.|

|Membro|Descrição|
|------------|-----------------|
|binder1st|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type^()|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor um argumento que armazena um funtor dois argumentos e um primeiro argumento. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna o resultado de chamar o functor armazenado com o primeiro argumento armazenado e o segundo argumento fornecido.

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

## <a name="binder2nd"></a> binder2nd (STL/CLR)

A classe de modelo descreve um funtor um argumento que, quando chamado, retorna seu functor dois argumentos armazenado chamado com o primeiro argumento fornecido e o segundo argumento armazenado. Você usá-lo especificar um objeto de função em termos de seu functor armazenado.

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

## <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|
|stored_function_type|O tipo do functor.|

|Membro|Descrição|
|------------|-----------------|
|binder2nd|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type^()|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor um argumento que armazena um funtor dois argumentos e um segundo argumento. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna o resultado de chamar o functor armazenado com o primeiro argumento fornecido e o segundo argumento armazenado.

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

## <a name="divides"></a> Divide (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna o primeiro argumento dividido pelo segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo do valor de retorno e argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|divides|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type^()|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna o primeiro argumento dividido pelo segundo.

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

## <a name="equal_to"></a> equal_to (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retornará true somente se o primeiro argumento for igual ao segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|equal_to|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type^()|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento é igual ao segundo.

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

## <a name="greater"></a> maior (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retornará true somente se o primeiro argumento for maior que o segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|greater|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento é maior que o segundo.

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

## <a name="greater_equal"></a> greater_equal (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna true somente se o primeiro argumento é maior que ou igual à segunda. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|greater_equal|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento é maior que ou igual à segunda.

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

## <a name="less"></a> menor (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retornará true somente se o primeiro argumento for menor que o segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|less|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento for menor que o segundo.

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

## <a name="less_equal"></a> less_equal (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna true somente se o primeiro argumento é menor ou igual ao segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|less_equal|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento é menor ou igual ao segundo.

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

## <a name="logical_and"></a> logical_and (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retornará true somente se o primeiro argumento e o segundo teste como true. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|logical_and|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento e o segundo teste como true.

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

## <a name="logical_not"></a> logical_not (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retornará true somente se qualquer um dos testes de seu argumento como false. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|argument_type|O tipo do argumento functor.|
|delegate_type|O tipo do delegado genérico.|
|result_type|O tipo do resultado functor.|

|Membro|Descrição|
|------------|-----------------|
|logical_not|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor um argumento. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se seu argumento testes como false.

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

## <a name="logical_or"></a> logical_or (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retornará true somente se o primeiro argumento ou os segundo testes como true. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|logical_or|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento ou os segundo testes como true.

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

## <a name="minus"></a> subtração (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna o primeiro argumento, menos o segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo do valor de retorno e argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|minus|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna o primeiro argumento menos a segunda.

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

## <a name="modulus"></a> módulo (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna o primeiro argumento de módulo a segunda. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo do valor de retorno e argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|módulo|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna o primeiro argumento de módulo a segunda.

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

## <a name="multiplies"></a> Multiplica (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna o primeiro argumento vezes o segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo do valor de retorno e argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|multiplies|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna o primeiro argumento vezes o segundo.

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

## <a name="negate"></a> Negar (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna o argumento negado. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|argument_type|O tipo do argumento functor.|
|delegate_type|O tipo do delegado genérico.|
|result_type|O tipo do resultado functor.|

|Membro|Descrição|
|------------|-----------------|
|negate|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor um argumento. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna seu argumento negado.

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

## <a name="not_equal_to"></a> not_equal_to (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retornará true somente se o primeiro argumento não for igual ao segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo dos argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|not_equal_to|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento não é igual à segunda.

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

## <a name="not1"></a> not1 (STL/CLR)

Gera um `unary_negate` para um functor.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun>
    unary_negate<Fun> not1(Fun% functor);
```

#### <a name="template-parameters"></a>Parâmetros de modelo

*Diversão*<br/>
O tipo do functor.

#### <a name="function-parameters"></a>Parâmetros de função

*functor*<br/>
O functor para encapsular.

### <a name="remarks"></a>Comentários

Retorna a função de modelo [unary_negate (STL/CLR)](../dotnet/unary-negate-stl-clr.md)`<Fun>(functor)`. Você pode usá-lo como uma maneira conveniente de encapsular um funtor um argumento em um funtor que oferece o NOT lógico.

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

## <a name="not2"></a> not2 (STL/CLR)

Gera um `binary_negate` para um functor.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename Fun>
    binary_negate<Fun> not2(Fun% functor);
```

#### <a name="template-parameters"></a>Parâmetros de modelo

*Diversão*<br/>
O tipo do functor.

#### <a name="function-parameters"></a>Parâmetros de função

*functor*<br/>
O functor para encapsular.

### <a name="remarks"></a>Comentários

Retorna a função de modelo [binary_negate (STL/CLR)](../dotnet/binary-negate-stl-clr.md)`<Fun>(functor)`. Você pode usá-lo como uma maneira conveniente de encapsular um funtor dois argumentos em um funtor que oferece o NOT lógico.

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

## <a name="plus"></a> Além de (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna o primeiro argumento e o segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.

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

*arg*<br/>
O tipo do valor de retorno e argumentos.

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|delegate_type|O tipo do delegado genérico.|
|first_argument_type|O tipo do primeiro argumento functor.|
|result_type|O tipo do resultado functor.|
|second_argument_type|O tipo do segundo argumento functor.|

|Membro|Descrição|
|------------|-----------------|
|plus|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|operador delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor dois argumentos. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna o primeiro argumento mais o segundo.

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

## <a name="unary_delegate"></a> unary_delegate (STL/CLR)

A classe genereic descreve um delegado de um argumento. Você usá-lo especificar um representante em termos de seus argumento e tipos de retorno.

### <a name="syntax"></a>Sintaxe

```cpp
generic<typename Arg,
    typename Result>
    delegate Result unary_delegate(Arg);
```

#### <a name="parameters"></a>Parâmetros

*arg*<br/>
O tipo do argumento.

*Result*<br/>
O tipo de retorno.

### <a name="remarks"></a>Comentários

O delegado genereic descreve uma função de um argumento.

Observe que para:

`unary_delegare<int, int> Fun1;`

`unary_delegare<int, int> Fun2;`

os tipos `Fun1` e `Fun2` são sinônimos, enquanto para:

`delegate int Fun1(int);`

`delegate int Fun2(int);`

eles não são do mesmo tipo.

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

## <a name="unary_delegate_noreturn"></a> unary_delegate_noreturn (STL/CLR)

A classe genereic descreve um delegado de um argumento que retorna **void**. Você usá-lo especificar um representante em termos de seu tipo de argumento.

### <a name="syntax"></a>Sintaxe

```cpp
generic<typename Arg>
    delegate void unary_delegate_noreturn(Arg);
```

#### <a name="parameters"></a>Parâmetros

*arg*<br/>
O tipo do argumento.

### <a name="remarks"></a>Comentários

O delegado genereic descreve uma função de um argumento que retorna **void**.

Observe que para:

`unary_delegare_noreturn<int> Fun1;`

`unary_delegare_noreturn<int> Fun2;`

os tipos `Fun1` e `Fun2` são sinônimos, enquanto para:

`delegate void Fun1(int);`

`delegate void Fun2(int);`

eles não são do mesmo tipo.

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

## <a name="unary_negate"></a> unary_negate (STL/CLR)

A classe de modelo descreve um funtor que, quando chamado, retorna a lógica não é do seu functor armazenado de um argumento. Você usá-lo especificar um objeto de função em termos de seu functor armazenado.

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

### <a name="member-functions"></a>Funções membro

|Definição do tipo|Descrição|
|---------------------|-----------------|
|argument_type|O tipo do argumento functor.|
|delegate_type|O tipo do delegado genérico.|
|result_type|O tipo do resultado functor.|

|Membro|Descrição|
|------------|-----------------|
|unary_negate|Constrói o functor.|

|Operador|Descrição|
|--------------|-----------------|
|operator()|Calcula a função desejada.|
|delegate_type ^|Converte o functor a um delegado.|

### <a name="remarks"></a>Comentários

A classe de modelo descreve um funtor um argumento que armazena o functor de um argumento de outra. Ele define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna a lógica não é do functor armazenado chamado com o argumento.

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