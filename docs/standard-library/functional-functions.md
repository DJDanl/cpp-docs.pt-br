---
title: Funções &lt;funcionais&gt;
ms.date: 02/21/2019
f1_keywords:
- functional/std::bind
- functional/std::bind1st
- functional/std::bind2nd
- functional/std::bit_and
- functional/std::bit_not
- functional/std::bit_or
- functional/std::bit_xor
- functional/std::cref
- type_traits/std::cref
- functional/std::mem_fn
- functional/std::mem_fun_ref
- functional/std::not1
- functional/std::not2
- functional/std::not_fn
- functional/std::ptr_fun
- functional/std::ref
- functional/std::swap
helpviewer_keywords:
- std::bind [C++]
- std::bind1st
- std::bind2nd
- std::bit_and [C++]
- std::bit_not [C++]
- std::bit_or [C++]
- std::bit_xor [C++]
- std::cref [C++]
ms.assetid: c34d0b45-50a7-447a-9368-2210d06339a4
ms.openlocfilehash: 559110361b9d3d8c66ff261860f8885ff56d44d5
ms.sourcegitcommit: 4299caac2dc9e806c74ac833d856a3838b0f52a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2019
ms.locfileid: "57006716"
---
# <a name="ltfunctionalgt-functions"></a>Funções &lt;funcionais&gt;

||||
|-|-|-|
| [bind](#bind) | [bit_and](#bit_and) | [bit_not](#bit_not) |
| [bit_or](#bit_or) | [bit_xor](#bit_xor) | [cref](#cref) |
| [invoke](#invoke) | [mem_fn](#mem_fn) | [not_fn](#not_fn) |
| [ref](#ref) | [swap](#swap) | |

Essas funções são preteridas no c++11 e removidas em c++17:

||||
|-|-|-|
| [bind1st](#bind1st) | [bind2nd](#bind2nd) | [mem_fun](#mem_fun) |
| [mem_fun_ref](#mem_fun_ref) | [ptr_fun](#ptr_fun) | |

Essas funções foram preteridas no C++ 17:

|||
|-|-|
| [not1](#not1) | [not2](#not2) |

## <a name="bind"></a> bind

Associa argumentos a um objeto que pode ser chamado.

```cpp
template <class Fty, class T1, class T2, ..., class TN>
unspecified bind(Fty fn, T1 t1, T2 t2, ..., TN tN);

template <class Ret, class Fty, class T1, class T2, ..., class TN>
unspecified bind(Fty fn, T1 t1, T2 t2, ..., TN tN);
```

### <a name="parameters"></a>Parâmetros

*Fty*<br/>
O tipo do objeto a ser chamado.

*TN*<br/>
O tipo do enésimo argumento de chamada.

*fn*<br/>
O objeto a ser chamado.

*tN*<br/>
O enésimo argumento de chamada.

### <a name="remarks"></a>Comentários

Os tipos `Fty, T1, T2, ..., TN` devem ser construíveis de cópias e `INVOKE(fn, t1, ..., tN)` deve ser uma expressão válida para alguns valores de `w1, w2, ..., wN`.

A primeira função de modelo retorna um wrapper de chamada de encaminhamento `g` com um tipo de resultado fraco. O efeito `g(u1, u2, ..., uM)` está `INVOKE(f, v1, v2, ..., vN, ` [invoke_result](../standard-library/invoke-result-class.md)`<Fty cv (V1, V2, ..., VN)>::type)`, onde `cv` são os qualificadores cv de `g` e os valores e tipos dos argumentos associados `v1, v2, ..., vN` são determinadas conforme especificado abaixo. É possível usá-lo para associar argumentos a um objeto que pode ser chamado e criar um objeto que pode ser chamado com uma lista de argumentos personalizada.

A segunda função de modelo retorna um wrapper de chamada de encaminhamento `g` com um tipo aninhado `result_type`, que é sinônimo de `Ret`. O efeito de `g(u1, u2, ..., uM)` é `INVOKE(f, v1, v2, ..., vN, Ret)`, em que `cv` são os qualificadores cv de `g` e os valores e tipos dos argumentos associados `v1, v2, ..., vN` são determinados conforme especificado abaixo. É possível usá-lo para associar argumentos a um objeto que pode ser chamado e criar um objeto que pode ser chamado com uma lista de argumentos personalizada e um tipo de retorno especificado.

Os valores dos argumentos associados `v1, v2, ..., vN` e seus tipos correspondentes `V1, V2, ..., VN` dependem do tipo do argumento correspondente `ti` de tipo `Ti` na chamada para `bind` e os qualificadores cv `cv` do wrapper de chamada `g`, da seguinte maneira:

se `ti` for do tipo `reference_wrapper<T>`, o argumento `vi` será `ti.get()` e seu tipo `Vi` será `T&`;

Se o valor de `std::is_bind_expression<Ti>::value` está **verdadeira** o argumento `vi` é `ti(u1, u2, ..., uM)` e seu tipo `Vi` é `result_of<Ti` `cv` `(U1&, U2&, ..., UN&>::type`;

se o valor `j` de `std::is_placeholder<Ti>::value` não for zero, o argumento `vi` será `uj` e seu tipo `Vi` será `Uj&`;

caso contrário, o argumento `vi` será `ti` e seu tipo `Vi` será `Ti` `cv` `&`.

Por exemplo, dada uma função `f(int, int)`, a expressão `bind(f, _1, 0)` retorna um wrapper de chamada de encaminhamento `cw`, de forma que `cw(x)` chama `f(x, 0)`. A expressão `bind(f, 0, _1)` retorna um wrapper de chamada encaminhamento `cw`, de forma que `cw(x)` chama `f(0, x)`.

O número de argumentos em uma chamada para `bind`, além do argumento `fn`, deve ser igual ao número de argumentos que podem ser passados para o objeto que pode ser chamado `fn`. Portanto, `bind(cos, 1.0)` está correto e `bind(cos)` e `bind(cos, _1, 0.0)` estão incorretos.

O número de argumentos na chamada de função para o wrapper de chamada retornado por `bind` deve ser, pelo menos, tão grande quanto o maior valor numerado de `is_placeholder<PH>::value` para todos os argumentos de espaço reservado na chamada para `bind`. Portanto, `bind(cos, _2)(0.0, 1.0)` está correto (e retorna `cos(1.0)`) e `bind(cos, _2)(0.0)` está incorreto.

### <a name="example"></a>Exemplo

```cpp
// std__functional__bind.cpp
// compile with: /EHsc
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std::placeholders;

void square(double x)
{
    std::cout << x << "^2 == " << x * x << std::endl;
}

void product(double x, double y)
{
    std::cout << x << "*" << y << " == " << x * y << std::endl;
}

int main()
{
    double arg[] = { 1, 2, 3 };

    std::for_each(&arg[0], arg + 3, square);
    std::cout << std::endl;

    std::for_each(&arg[0], arg + 3, std::bind(product, _1, 2));
    std::cout << std::endl;

    std::for_each(&arg[0], arg + 3, std::bind(square, _1));

    return (0);
}
```

```Output
1^2 == 1
2^2 == 4
3^2 == 9

1*2 == 2
2*2 == 4
3*2 == 6

1^2 == 1
2^2 == 4
3^2 == 9
```

## <a name="bind1st"></a> bind1st

Uma função de modelo auxiliar que cria um adaptador para converter um objeto de função binária em um objeto de função unária, associando o primeiro argumento da função binária a um valor especificado. Preterido no c++11, removido do c++17.

```cpp
template <class Operation, class Type>
binder1st <Operation> bind1st (const Operation& func, const Type& left);
```

### <a name="parameters"></a>Parâmetros

*func*<br/>
O objeto de função binária a ser convertido em um objeto de função unária.

*left*<br/>
O valor ao qual o primeiro argumento do objeto de função binária deve ser associado.

### <a name="return-value"></a>Valor de retorno

O objeto de função unária que resulta da associação o primeiro argumento do objeto de função binária ao valor *esquerdo*.

### <a name="remarks"></a>Comentários

Associadores de função são um tipo de adaptador de função e, como retornam objetos de função, eles podem ser usados em determinados tipos de composição de função para construir expressões mais complicadas e avançadas.

Se *func* é um objeto do tipo `Operation` e `c` é uma constante, então `bind1st` ( `func`, `c`) é equivalente ao [binder1st](../standard-library/binder1st-class.md) construtor de classe `binder1st` <  `Operation`> ( `func`, `c`) e é mais conveniente.

### <a name="example"></a>Exemplo

```cpp
// functional_bind1st.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

// Creation of a user-defined function object
// that inherits from the unary_function base class
class greaterthan5: unary_function<int, bool>
{
public:
    result_type operator()(argument_type i)
    {
        return (result_type)(i > 5);
    }
};

int main()
{
    vector<int> v1;
    vector<int>::iterator Iter;

    int i;
    for (i = 0; i <= 5; i++)
    {
        v1.push_back(5 * i);
    }

    cout << "The vector v1 = ( " ;
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << *Iter << " ";
    cout << ")" << endl;

    // Count the number of integers > 10 in the vector
    vector<int>::iterator::difference_type result1a;
    result1a = count_if(v1.begin(), v1.end(), bind1st(less<int>(), 10));
    cout << "The number of elements in v1 greater than 10 is: "
         << result1a << "." << endl;

    // Compare: counting the number of integers > 5 in the vector
    // with a user defined function object
    vector<int>::iterator::difference_type result1b;
    result1b = count_if(v1.begin(), v1.end(), greaterthan5());
    cout << "The number of elements in v1 greater than 5 is: "
         << result1b << "." << endl;

    // Count the number of integers < 10 in the vector
    vector<int>::iterator::difference_type result2;
    result2 = count_if(v1.begin(), v1.end(), bind2nd(less<int>(), 10));
    cout << "The number of elements in v1 less than 10 is: "
         << result2 << "." << endl;
}
```

```Output
The vector v1 = ( 0 5 10 15 20 25 )
The number of elements in v1 greater than 10 is: 3.
The number of elements in v1 greater than 5 is: 4.
The number of elements in v1 less than 10 is: 2.
```

## <a name="bind2nd"></a> bind2nd

Uma função de modelo auxiliar que cria um adaptador para converter um objeto de função binária em um objeto de função unária, associando o segundo argumento da função binária a um valor especificado. Preterido no c++11, removido do c++17.

```cpp
template <class Operation, class Type>
binder2nd <Operation> bind2nd(const Operation& func, const Type& right);
```

### <a name="parameters"></a>Parâmetros

*func*<br/>
O objeto de função binária a ser convertido em um objeto de função unária.

*right*<br/>
O valor ao qual o segundo argumento do objeto de função binária deve ser associado.

### <a name="return-value"></a>Valor de retorno

O objeto de função unária que resulta da associação do segundo argumento do objeto de função binária ao valor *certa*.

### <a name="remarks"></a>Comentários

Associadores de função são um tipo de adaptador de função e, como retornam objetos de função, eles podem ser usados em determinados tipos de composição de função para construir expressões mais complicadas e avançadas.

Se *func* é um objeto do tipo `Operation` e `c` é uma constante, então `bind2nd` ( `func`, `c` ) é equivalente ao [binder2nd](../standard-library/binder2nd-class.md) construtor de classe **binder2nd\<operação >** ( `func`, `c` ) e mais conveniente.

### <a name="example"></a>Exemplo

```cpp
// functional_bind2nd.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

// Creation of a user-defined function object
// that inherits from the unary_function base class
class greaterthan15: unary_function<int, bool>
{
public:
    result_type operator()(argument_type i)
    {
        return (result_type)(i > 15);
    }
};

int main()
{
    vector<int> v1;
    vector<int>::iterator Iter;

    int i;
    for (i = 0; i <= 5; i++)
    {
        v1.push_back(5 * i);
    }

    cout << "The vector v1 = ( ";
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << *Iter << " ";
    cout << ")" << endl;

    // Count the number of integers > 10 in the vector
    vector<int>::iterator::difference_type result1a;
    result1a = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 10));
    cout << "The number of elements in v1 greater than 10 is: "
         << result1a << "." << endl;

    // Compare counting the number of integers > 15 in the vector
    // with a user-defined function object
    vector<int>::iterator::difference_type result1b;
    result1b = count_if(v1.begin(), v1.end(), greaterthan15());
    cout << "The number of elements in v1 greater than 15 is: "
         << result1b << "." << endl;

    // Count the number of integers < 10 in the vector
    vector<int>::iterator::difference_type result2;
    result2 = count_if(v1.begin(), v1.end(), bind1st(greater<int>(), 10));
    cout << "The number of elements in v1 less than 10 is: "
         << result2 << "." << endl;
}
```

```Output
The vector v1 = ( 0 5 10 15 20 25 )
The number of elements in v1 greater than 10 is: 3.
The number of elements in v1 greater than 15 is: 2.
The number of elements in v1 less than 10 is: 2.
```

## <a name="bit_and"></a> bit_and

Um objeto de função predefinido que executa a operação bit a bit AND (`operator&` binário) em seus argumentos.

```cpp
template <class Type = void>
struct bit_and : public binary_function<Type, Type, Type> {
    Type operator()(
    const Type& Left,
    const Type& Right) const;
};

// specialized transparent functor for operator&
template <>
struct bit_and<void>
{
    template <class T, class U>
    auto operator()(T&& Left, U&& Right) const  ->
        decltype(std::forward<T>(Left) & std::forward<U>(Right));
};
```

### <a name="parameters"></a>Parâmetros

*Tipo de*, *T*, *U* qualquer tipo que dá suporte a um `operator&` que usa operandos dos tipos especificados ou inferidos.

*Esquerda*<br/>
O operando esquerdo da operação bit a bit AND. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *T*.

*Direita*<br/>
O operando direito da operação bit a bit AND. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *U*.

### <a name="return-value"></a>Valor de retorno

O resultado de `Left & Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator&`.

### <a name="remarks"></a>Comentários

O functor `bit_and` é restrito a tipos integrais para os tipos de dados básicos ou a tipos definidos pelo usuário que implementam o `operator&` binário.

## <a name="bit_not"></a> bit_not

Um objeto de função predefinido que executa a operação complementar bit a bit (NOT) (`operator~` unário) em seu argumento. Adicionado no C + + 14.

```cpp
template <class Type = void>
struct bit_not : public unary_function<Type, Type>
{
    Type operator()(const Type& Right) const;
};

// specialized transparent functor for operator~
template <>
struct bit_not<void>
{
    template <class Type>
    auto operator()(Type&& Right) const -> decltype(~std::forward<Type>(Right));
};
```

### <a name="parameters"></a>Parâmetros

*Tipo*<br/>
Um tipo que dá suporte a um `operator~` unário.

*Direita*<br/>
O operando da operação complementar bit a bit. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de um argumento de referência lvalue e rvalue do tipo inferido perfeito *tipo*.

### <a name="return-value"></a>Valor de retorno

O resultado de `~ Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator~`.

### <a name="remarks"></a>Comentários

O functor `bit_not` é restrito a tipos integrais para os tipos de dados básicos ou a tipos definidos pelo usuário que implementam o `operator~` binário.

## <a name="bit_or"></a> bit_or

Um objeto de função predefinido que executa a operação OR bit a bit (`operator|`) em seus argumentos.

```cpp
template <class Type = void>
struct bit_or : public binary_function<Type, Type, Type> {
    Type operator()(
    const Type& Left,
    const Type& Right) const;
};

// specialized transparent functor for operator|
template <>
struct bit_or<void>
{
    template <class T, class U>
    auto operator()(T&& Left, U&& Right) const
        -> decltype(std::forward<T>(Left) | std::forward<U>(Right));
};
```

### <a name="parameters"></a>Parâmetros

*Tipo de*, *T*, *U* qualquer tipo que dá suporte a um `operator|` que usa operandos dos tipos especificados ou inferidos.

*Esquerda*<br/>
O operando esquerdo da operação bit a bit OR. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *T*.

*Direita*<br/>
O operando direito da operação bit a bit OR. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *U*.

### <a name="return-value"></a>Valor de retorno

O resultado de `Left | Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator|`.

### <a name="remarks"></a>Comentários

O functor `bit_or` é restrito a tipos integrais para os tipos de dados básicos ou a tipos definidos pelo usuário que implementam `operator|`.

## <a name="bit_xor"></a> bit_xor

Um objeto de função predefinido que executa a operação bit a bit XOR (`operator^` binário) em seus argumentos.

```cpp
template <class Type = void>
struct bit_xor : public binary_function<Type, Type, Type> {
    Type operator()(
    const Type& Left,
    const Type& Right) const;
};

// specialized transparent functor for operator^
template <>
struct bit_xor<void>
{
    template <class T, class U>
    auto operator()(T&& Left, U&& Right) const
        -> decltype(std::forward<T>(Left) ^ std::forward<U>(Right));
};
```

### <a name="parameters"></a>Parâmetros

*Tipo de*, *T*, *U* qualquer tipo que dá suporte a um `operator^` que usa operandos dos tipos especificados ou inferidos.

*Esquerda*<br/>
O operando esquerdo da operação bit a bit XOR. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *T*.

*Direita*<br/>
O operando direito da operação bit a bit XOR. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *U*.

### <a name="return-value"></a>Valor de retorno

O resultado de `Left ^ Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator^`.

### <a name="remarks"></a>Comentários

O functor `bit_xor` é restrito a tipos integrais para os tipos de dados básicos ou a tipos definidos pelo usuário que implementam o `operator^` binário.

## <a name="cref"></a> cref

Constrói uma constante `reference_wrapper` de um argumento.

```cpp
template <class Ty>
reference_wrapper<const Ty> cref(const Ty& arg);

template <class Ty>
reference_wrapper<const Ty> cref(const reference_wrapper<Ty>& arg);
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo do argumento a ser encapsulado.

*arg*<br/>
O argumento a ser encapsulado.

### <a name="remarks"></a>Comentários

A primeira função retorna `reference_wrapper<const Ty>(arg.get())`. Ela é usada para encapsular uma referência constante. A segunda função retorna `reference_wrapper<const Ty>(arg)`. Ela é usada para encapsular novamente uma referência encapsulada como uma referência constante.

### <a name="example"></a>Exemplo

```cpp
// std__functional__cref.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val)
    {
    return (-val);
    }

int main()
    {
    int i = 1;

    std::cout << "i = " << i << std::endl;
    std::cout << "cref(i) = " << std::cref(i) << std::endl;
    std::cout << "cref(neg)(i) = "
        << std::cref(&neg)(i) << std::endl;

    return (0);
    }
```

```Output
i = 1
cref(i) = 1
cref(neg)(i) = -1
```

## <a name="invoke"></a> invoke

Invoca qualquer objeto que pode ser chamado com os argumentos fornecidos. Adicionado no c++17.

```cpp
template <class Callable, class... Args>
invoke_result_t<Callable, Args...>
    invoke(Callable&& fn, Args&&... args) noexcept(/* specification */);
```

### <a name="parameters"></a>Parâmetros

*pode ser chamado*<br/>
O tipo do objeto a ser chamado.

*Args*<br/>
Os tipos dos argumentos de chamada.

*fn*<br/>
O objeto a ser chamado.

*args*<br/>
Os argumentos da chamada.

*specification*<br/>
O **noexcept** especificação `std::is_nothrow_invocable_v<Callable, Args>)`.

### <a name="remarks"></a>Comentários

Invoca o objeto callable *fn* usando os parâmetros *args*. Na verdade, `INVOKE(std::forward<Callable>(fn), std::forward<Args>(args)...)`, onde a pseudo função `INVOKE(f, t1, t2, ..., tN)` significa um dos seguintes itens:

- `(t1.*f)(t2, ..., tN)` quando `f` é um ponteiro para uma função membro da classe `T` e `t1` é um objeto do tipo `T` ou uma referência a um objeto do tipo `T` ou uma referência a um objeto de um tipo derivado de `T`. Ou seja, quando `std::is_base_of<T, std::decay_t<decltype(t1)>>::value` é verdadeiro.

- `(t1.get().*f)(t2, ..., tN)` Quando `f` é um ponteiro para função de membro da classe `T` e `std::decay_t<decltype(t1)>` é uma especialização de `std::reference_wrapper`.

- `((*t1).*f)(t2, ..., tN)` Quando `f` é um ponteiro para função de membro da classe `T` e `t1` não é um dos tipos anteriores.

- `t1.*f` quando N == 1 e `f` é um ponteiro para dados de membro de uma classe `T` e `t1` é um objeto do tipo `T` ou uma referência a um objeto do tipo `T` ou uma referência a um objeto de um tipo derivado de `T`.  Ou seja, quando `std::is_base_of<T, std::decay_t<decltype(t1)>>::value` é verdadeiro.

- `t1.get().*f` Quando N = = 1 e `f` é um ponteiro para dados de membro de uma classe `T` e `std::decay_t<decltype(t1)>` é uma especialização de `std::reference_wrapper`.

- `(*t1).*f` Quando N = = 1 e `f` é um ponteiro para dados de membro de uma classe `T` e `t1` não é um dos tipos anteriores.

- `f(t1, t2, ..., tN)` em todos os outros casos.

Para obter informações sobre o tipo de resultado de um objeto que pode ser chamado, consulte [invoke_result](invoke-result-class.md). Para predicados em tipos que pode ser chamados, consulte [is_invocable, is_invocable_r, is_nothrow_invocable, classes is_nothrow_invocable_r](is-invocable-classes.md).

### <a name="example"></a>Exemplo

```cpp
// functional_invoke.cpp
// compile using: cl /EHsc /std:c++17 functional_invoke.cpp
#include <functional>
#include <iostream>

struct Demo
{
    int n_;

    Demo(int const n) : n_{n} {}

    void operator()(int const i, int const j) const
    {
        std::cout << "Demo operator( " << i << ", "
            << j << " ) is " << i * j << std::endl;
    }

    void difference(int const i) const 
    {
        std::cout << "Demo.difference( " << i << " ) is "
            << n_ - i << std::endl;
    }
};

void divisible_by_3(int const i)
{
    std::cout << i;
    (i % 3) ? std::cout << " isn't divisible by 3."
        : std::cout << " is divisible by 3.";
    std::cout << std::endl;
}

int main()
{
    // Invoke a function object (call operator).
    Demo d{ 42 };
    std::invoke( d, 3, -7 );

    // Invoke a member function.
    std::invoke(&Demo::difference, d, 29);

    // Invoke a data member.
    std::cout << "n_: " << std::invoke(&Demo::n_, d) << '\n';

    // Invoke a stand-alone (free) function.
    std::invoke( divisible_by_3, 42 );

    // Invoke a lambda.
    std::invoke( [](int const i){
        std::cout << i; 
        (i % 7) ? std::cout << " isn't divisible by 7."
            : std::cout << " is divisible by 7.";
        std::cout << std::endl;
    }, 42 );
}
```

## <a name="mem_fn"></a> mem_fn

Gera um wrapper de chamada simples.

```cpp
template <class Ret, class Ty>
unspecified mem_fn(Ret Ty::*pm);
```

### <a name="parameters"></a>Parâmetros

*Ret*<br/>
O tipo de retorno da função encapsulada.

*Ty*<br/>
O tipo de ponteiro da função membro.

### <a name="remarks"></a>Comentários

A função de modelo retorna um wrapper de chamada simples `cw`, com um tipo de resultado fraco, de forma que a expressão `cw(t, a2, ..., aN)` é equivalente a `INVOKE(pm, t, a2, ..., aN)`. Ela não gera nenhuma exceção.

O wrapper de chamada retornado é derivado de `std::unary_function<cv Ty*, Ret>` (assim, definindo o tipo aninhado `result_type` como sinônimo de um *Ret* e o tipo aninhado `argument_type` como um sinônimo para `cv Ty*`) somente se o tipo  *Ty* é um ponteiro para função de membro com o qualificador cv `cv` que não usa argumentos.

O wrapper de chamada retornado é derivado de `std::binary_function<cv Ty*, T2, Ret>` (assim, definindo o tipo aninhado `result_type` como sinônimo de um *Ret*, o tipo aninhado `first argument_type` como um sinônimo para `cv Ty*`e o tipo aninhado `second argument_type`como um sinônimo de `T2`) somente se o tipo *Ty* é um ponteiro para função de membro com o qualificador cv `cv` que usa um argumento do tipo `T2`.

### <a name="example"></a>Exemplo

```cpp
// std__functional__mem_fn.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

class Funs
    {
public:
    void square(double x)
        {
        std::cout << x << "^2 == " << x * x << std::endl;
        }

    void product(double x, double y)
        {
        std::cout << x << "*" << y << " == " << x * y << std::endl;
        }
    };

int main()
    {
    Funs funs;

    std::mem_fn(&Funs::square)(funs, 3.0);
    std::mem_fn(&Funs::product)(funs, 3.0, 2.0);

    return (0);
    }
```

```Output
3^2 == 9
3*2 == 6
```

## <a name="mem_fun"></a> mem_fun

Funções de modelo auxiliares usadas para construir adaptadores de objeto de função para funções membro, quando inicializadas com argumentos de ponteiro. Preterido no c++11 em favor da [mem_fn](#mem_fn) e [associar](#bind)e removidos em c++17.

```cpp
template <class Result, class Type>
mem_fun_t<Result, Type> mem_fun (Result(Type::* pmem)());

template <class Result, class Type, class Arg>
mem_fun1_t<Result, Type, Arg> mem_fun(Result (Type::* pmem)(Arg));

template <class Result, class Type>
const_mem_fun_t<Result, Type> mem_fun(Result (Type::* pmem)() const);

template <class Result, class Type, class Arg>
const_mem_fun1_t<Result, Type, Arg> mem_fun(Result (Type::* pmem)(Arg) const);
```

### <a name="parameters"></a>Parâmetros

*pmem*<br/>
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

### <a name="return-value"></a>Valor de retorno

Um objeto de função **const** ou **non_const** do tipo `mem_fun_t` ou `mem_fun1_t`.

### <a name="example"></a>Exemplo

```cpp
// functional_mem_fun.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

class StoreVals
{
    int val;
public:
    StoreVals() { val = 0; }
    StoreVals(int j) { val = j; }

    bool display() { cout << val << " "; return true; }
    int squareval() { val *= val; return val; }
    int lessconst(int k) {val -= k; return val; }
};

int main( )
{
    vector<StoreVals *> v1;

    StoreVals sv1(5);
    v1.push_back(&sv1);
    StoreVals sv2(10);
    v1.push_back(&sv2);
    StoreVals sv3(15);
    v1.push_back(&sv3);
    StoreVals sv4(20);
    v1.push_back(&sv4);
    StoreVals sv5(25);
    v1.push_back(&sv5);

    cout << "The original values stored are: " ;
    for_each(v1.begin(), v1.end(), mem_fun<bool, StoreVals>(&StoreVals::display));
    cout << endl;

    // Use of mem_fun calling member function through a pointer
    // square each value in the vector using squareval ()
    for_each(v1.begin(), v1.end(), mem_fun<int, StoreVals>(&StoreVals::squareval));
    cout << "The squared values are: " ;
    for_each(v1.begin(), v1.end(), mem_fun<bool, StoreVals>(&StoreVals::display));
    cout << endl;

    // Use of mem_fun1 calling member function through a pointer
    // subtract 5 from each value in the vector using lessconst ()
    for_each(v1.begin(), v1.end(),
        bind2nd (mem_fun1<int, StoreVals,int>(&StoreVals::lessconst), 5));
    cout << "The squared values less 5 are: " ;
    for_each(v1.begin(), v1.end(), mem_fun<bool, StoreVals>(&StoreVals::display));
    cout << endl;
}
```

## <a name="mem_fun_ref"></a> mem_fun_ref

Funções de modelo auxiliares usadas para construir adaptadores de objeto de função para funções membro, quando inicializadas usando argumentos de referência. Preterido no c++11, removido do c++17.

```cpp
template <class Result, class Type>
mem_fun_ref_t<Result, Type> mem_fun_ref(Result (Type::* pmem)());

template <class Result, class Type, class Arg>
mem_fun1_ref_t<Result, Type, Arg> mem_fun_ref(Result (Type::* pmem)(Arg));

template <class Result, class Type>
const_mem_fun_ref_t<Result, Type> mem_fun_ref(Result Type::* pmem)() const);

template <class Result, class Type, class Arg>
const_mem_fun1_ref_t<Result, Type, Arg> mem_fun_ref(Result (T::* pmem)(Arg) const);
```

### <a name="parameters"></a>Parâmetros

*pmem*<br/>
Um ponteiro para a função membro da classe `Type` a ser convertida em um objeto de função.

### <a name="return-value"></a>Valor de retorno

Um **const** ou `non_const` objeto de função do tipo `mem_fun_ref_t` ou `mem_fun1_ref_t`.

### <a name="example"></a>Exemplo

```cpp
// functional_mem_fun_ref.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

class NumVals
   {
   int val;
   public:
   NumVals ( ) { val = 0; }
   NumVals ( int j ) { val = j; }

   bool display ( ) { cout << val << " "; return true; }
   bool isEven ( ) { return ( bool )  !( val %2 ); }
   bool isPrime( )
   {
      if (val < 2) { return true; }
      for (int i = 2; i <= val / i; ++i)
      {
         if (val % i == 0) { return false; }
      }
      return true;
   }
};

int main( )
{
   vector <NumVals> v1 ( 13 ), v2 ( 13 );
   vector <NumVals>::iterator v1_Iter, v2_Iter;
   int i, k;

   for ( i = 0; i < 13; i++ ) v1 [ i ] = NumVals ( i+1 );
   for ( k = 0; k < 13; k++ ) v2 [ k ] = NumVals ( k+1 );

   cout << "The original values stored in v1 are: " ;
   for_each( v1.begin( ), v1.end( ),
   mem_fun_ref ( &NumVals::display ) );
   cout << endl;

   // Use of mem_fun_ref calling member function through a reference
   // remove the primes in the vector using isPrime ( )
   v1_Iter = remove_if ( v1.begin( ),  v1.end( ),
      mem_fun_ref ( &NumVals::isPrime ) );
   cout << "With the primes removed, the remaining values in v1 are: " ;
   for_each( v1.begin( ), v1_Iter,
   mem_fun_ref ( &NumVals::display ) );
   cout << endl;

   cout << "The original values stored in v2 are: " ;
   for_each( v2.begin( ), v2.end( ),
   mem_fun_ref ( &NumVals::display ) );
   cout << endl;

   // Use of mem_fun_ref calling member function through a reference
   // remove the even numbers in the vector v2 using isEven ( )
   v2_Iter = remove_if ( v2.begin( ),  v2.end( ),
      mem_fun_ref ( &NumVals::isEven ) );
   cout << "With the even numbers removed, the remaining values are: " ;
   for_each( v2.begin( ),  v2_Iter,
   mem_fun_ref ( &NumVals::display ) );
   cout << endl;
}
```

```Output
The original values stored in v1 are: 1 2 3 4 5 6 7 8 9 10 11 12 13
With the primes removed, the remaining values in v1 are: 4 6 8 9 10 12
The original values stored in v2 are: 1 2 3 4 5 6 7 8 9 10 11 12 13
With the even numbers removed, the remaining values are: 1 3 5 7 9 11 13
```

## <a name="not1"></a> not1

Retorna o complemento de um predicado unário. Preterido em favor da [not_fn](#not_fn) no c++17.

```cpp
template <class UnaryPredicate>
unary_negate<UnaryPredicate> not1(const UnaryPredicate& pred);
```

### <a name="parameters"></a>Parâmetros

*pred*<br/>
O predicado unário a ser negado.

### <a name="return-value"></a>Valor de retorno

Um predicado unário que é a negação do predicado unário modificado.

### <a name="remarks"></a>Comentários

Se um `unary_negate` for construído de um predicado unário **Pred**( *x*), ele retornará **!Pred**( *x*).

### <a name="example"></a>Exemplo

```cpp
// functional_not1.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int>::iterator Iter;

    int i;
    for (i = 0; i <= 7; i++)
    {
        v1.push_back(5 * i);
    }

    cout << "The vector v1 = ( ";
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << *Iter << " ";
    cout << ")" << endl;

    vector<int>::iterator::difference_type result1;
    // Count the elements greater than 10
    result1 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 10));
    cout << "The number of elements in v1 greater than 10 is: "
         << result1 << "." << endl;

    vector<int>::iterator::difference_type result2;
    // Use the negator to count the elements less than or equal to 10
    result2 = count_if(v1.begin(), v1.end(),
        not1(bind2nd(greater<int>(), 10)));

    cout << "The number of elements in v1 not greater than 10 is: "
         << result2 << "." << endl;
}
```

```Output
The vector v1 = ( 0 5 10 15 20 25 30 35 )
The number of elements in v1 greater than 10 is: 5.
The number of elements in v1 not greater than 10 is: 3.
```

## <a name="not2"></a> not2

Retorna o complemento de um predicado binário. Preterido em favor da [not_fn](#not_fn) no c++17.

```cpp
template <class BinaryPredicate>
binary_negate<BinaryPredicate> not2(const BinaryPredicate& func);
```

### <a name="parameters"></a>Parâmetros

*func*<br/>
O predicado binário a ser negado.

### <a name="return-value"></a>Valor de retorno

Um predicado binário que é a negação do predicado binário modificado.

### <a name="remarks"></a>Comentários

Se um `binary_negate` for construído de um predicado binário **BinPred**( *x*, *y*), ele retornará ! **BinPred**( *x*, *y*).

### <a name="example"></a>Exemplo

```cpp
// functional_not2.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator Iter1;

   int i;
   v1.push_back( 6262 );
   v1.push_back( 6262 );
   for ( i = 0 ; i < 5 ; i++ )
   {
      v1.push_back( rand( ) );
   }

   cout << "Original vector v1 = ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")" << endl;

   // To sort in ascending order,
   // use default binary predicate less<int>( )
   sort( v1.begin( ), v1.end( ) );
   cout << "Sorted vector v1 = ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")" << endl;

   // To sort in descending order,
   // use the binary_negate helper function not2
   sort( v1.begin( ), v1.end( ), not2(less<int>( ) ) );
   cout << "Resorted vector v1 = ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")" << endl;
}
```

```Output
Original vector v1 = ( 6262 6262 41 18467 6334 26500 19169 )
Sorted vector v1 = ( 41 6262 6262 6334 18467 19169 26500 )
Resorted vector v1 = ( 26500 19169 18467 6334 6262 6262 41 )
```

## <a name="not_fn"></a> not_fn

O `not_fn` utiliza um objeto que pode ser chamado de modelo de função e retorna um objeto que pode ser chamado. Quando o objeto que pode ser chamado retornado é invocado posteriormente com alguns argumentos, ele passa para o objeto callable original e logicamente nega o resultado. Preserva o comportamento de categoria de qualificação e o valor const do objeto que pode ser chamado encapsulado. `not_fn` há de novo no C++ 17 e o substitui preteridas `std::not1`, `std::not2`, `std::unary_negate` e `std::binary_negate`.

```cpp
template <class Callable>
/* unspecified */ not_fn(Callable&& func);
```

### <a name="parameters"></a>Parâmetros

*func*<br/>
Um objeto que pode ser chamado usado para construir a chamada de encaminhamento de wrapper.

### <a name="remarks"></a>Comentários

A função de modelo retorna um wrapper de chamada equivalente a `return call_wrapper(std::forward<Callable>(func))` baseado nessa classe somente exposition:

```cpp
class call_wrapper
{
   using FD = decay_t<Callable>;
   explicit call_wrapper(Callable&& func);

public:
   call_wrapper(call_wrapper&&) = default;
   call_wrapper(call_wrapper const&) = default;

   template<class... Args>
     auto operator()(Args&&...) & -> decltype(!declval<invoke_result_t<FD&(Args...)>>());

   template<class... Args>
     auto operator()(Args&&...) const& -> decltype(!declval<invoke_result_t<FD const&(Args...)>>());

   template<class... Args>
     auto operator()(Args&&...) && -> decltype(!declval<invoke_result_t<FD(Args...)>>());

   template<class... Args>
     auto operator()(Args&&...) const&& -> decltype(!declval<invoke_result_t<FD const(Args...)>>());

private:
  FD fd;
};
```

O construtor explícito sobre o objeto callable *func* requer o tipo `std::decay_t<Callable>` satisfazer os requisitos de `MoveConstructible`, e `is_constructible_v<FD, Callable>` deve ser verdadeira. Ele inicializa o objeto que pode ser chamado encapsulado `fd` partir `std::forward<Callable>(func)`e lança uma exceção gerada pela construção de `fd`.

O wrapper expõe os operadores de chamada diferenciados por lvalue ou categoria de referência de rvalue e qualificação const, conforme mostrado aqui,

```cpp
template<class... Args> auto operator()(Args&&... args) & -> decltype(!declval<invoke_result_t<FD&(Args...)>>());
template<class... Args> auto operator()(Args&&... args) const& -> decltype(!declval<invoke_result_t<FD const&(Args...)>>());
template<class... Args> auto operator()(Args&&... args) && -> decltype(!declval<invoke_result_t<FD(Args...)>>());
template<class... Args> auto operator()(Args&&... args) const&& -> decltype(!declval<invoke_result_t<FD const(Args...)>>());
```

As duas primeiras são equivalentes a `return !INVOKE(fd, std::forward<Args>(args)...)`, e os dois são equivalentes a `return !INVOKE(std::move(fd), std::forward<Args>(args)...)`.

### <a name="example"></a>Exemplo

```cpp
// functional_not_fn_.cpp
// compile with: /EHsc /std:c++17
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

int main()
{
    std::vector<int> v1 = { 99, 6264, 41, 18467, 6334, 26500, 19169 };
    auto divisible_by_3 = [](int i){ return i % 3 == 0; };

    std::cout << "Vector v1 = ( " ;
    for (const auto& item : v1)
    {
        std::cout << item << " ";
    }
    std::cout << ")" << std::endl;

    // Count the number of vector elements divisible by 3.
    int divisible =
        std::count_if(v1.begin(), v1.end(), divisible_by_3);
    std::cout << "Elements divisible by three: "
        << divisible << std::endl;

    // Count the number of vector elements not divisible by 3.
    int not_divisible =
        std::count_if(v1.begin(), v1.end(), std::not_fn(divisible_by_3));
    std::cout << "Elements not divisible by three: "
        << not_divisible << std::endl;
}
```

```Output
Vector v1 = ( 99 6264 41 18467 6334 26500 19169 )
Elements divisible by three: 2
Elements not divisible by three: 5
```

## <a name="ptr_fun"></a> ptr_fun

Funções de modelo auxiliares usadas para converter ponteiros de funções unárias e binárias, respectivamente, em funções adaptáveis unárias e binárias. Preterido no c++11, removido do c++17.

```cpp
template <class Arg, class Result>
pointer_to_unary_function<Arg, Result, Result (*)(Arg)> ptr_fun(Result (*pfunc)(Arg));

template <class Arg1, class Arg2, class Result>
pointer_to_binary_function<Arg1, Arg2, Result, Result (*)(Arg1, Arg2)> ptr_fun(Result (*pfunc)(Arg1, Arg2));
```

### <a name="parameters"></a>Parâmetros

*pfunc*<br/>
O ponteiro de função unária ou binária a ser convertido em uma função adaptável.

### <a name="return-value"></a>Valor de retorno

A primeira função de modelo retorna a função unária [pointer_to_unary_function](../standard-library/pointer-to-unary-function-class.md) < `Arg`, **resultados**> (\* `pfunc`).

A segunda função de modelo retorna a função binária [pointer_to_binary_function](../standard-library/pointer-to-binary-function-class.md) \< **Arg1**, **Arg2**, **resultado**> (\* `pfunc`).

### <a name="remarks"></a>Comentários

Um ponteiro de função é um objeto de função e pode ser passado para qualquer algoritmo da Biblioteca Padrão C++ que esperar uma função como parâmetro, mas não é adaptável. Para usá-lo com um adaptador, como ao associar um valor a ele ou usá-lo com um negador, ele deve ser fornecido com os tipos aninhados que possibilitam essa adaptação. A conversão de ponteiros de funções unárias ou binárias pela função auxiliar `ptr_fun` permite que os adaptadores de função funcionem com ponteiros de funções unárias ou binárias.

### <a name="example"></a>Exemplo

[!code-cpp[functional_ptr_fun#1](../standard-library/codesnippet/CPP/functional-functions_1.cpp)]

## <a name="ref"></a> ref

Constrói um `reference_wrapper` de um argumento.

```cpp
template <class Ty>
reference_wrapper<Ty> ref(Ty& arg);

template <class Ty>
reference_wrapper<Ty> ref(reference_wrapper<Ty>& arg);
```

### <a name="return-value"></a>Valor de retorno

Uma referência para `arg`; especificamente, `reference_wrapper<Ty>(arg)`.

### <a name="example"></a>Exemplo

O exemplo a seguir define duas funções: uma associada a uma variável de cadeia de caracteres e a outra associada a uma referência da variável de cadeia de caracteres calculada por uma chamada para `ref`. Quando o valor da variável muda, a primeira função continua usando o valor antigo e a segunda função usa o novo valor.

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
using namespace std;
using namespace std;
using namespace std::placeholders;

bool shorter_than(const string& l, const string& r) {
    return l.size() < r.size();
}

int main() {
    vector<string> v_original;
    v_original.push_back("tiger");
    v_original.push_back("cat");
    v_original.push_back("lion");
    v_original.push_back("cougar");

    copy(v_original.begin(), v_original.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    string s("meow");

    function<bool (const string&)> f = bind(shorter_than, _1, s);
    function<bool (const string&)> f_ref = bind(shorter_than, _1, ref(s));

    vector<string> v;

    // Remove elements that are shorter than s ("meow")

    v = v_original;
    v.erase(remove_if(v.begin(), v.end(), f), v.end());

    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    // Now change the value of s.
    // f_ref, which is bound to ref(s), will use the
    // new value, while f is still bound to the old value.

    s = "kitty";

    // Remove elements that are shorter than "meow" (f is bound to old value of s)

    v = v_original;
    v.erase(remove_if(v.begin(), v.end(), f), v.end());

    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    // Remove elements that are shorter than "kitty" (f_ref is bound to ref(s))

    v = v_original;
    v.erase(remove_if(v.begin(), v.end(), f_ref), v.end());

    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}
```

```Output
tiger cat lion cougar
tiger lion cougar
tiger lion cougar
tiger cougar
```

## <a name="swap"></a> swap

Troca dois objetos `function`.

```cpp
template <class Fty>
void swap(function<Fty>& f1, function<Fty>& f2);
```

### <a name="parameters"></a>Parâmetros

*Fty*<br/>
O tipo controlado pelos objetos de função.

*f1*<br/>
O primeiro objeto de função.

*f2*<br/>
O segundo objeto de função.

### <a name="remarks"></a>Comentários

A função retorna `f1.swap(f2)`.

### <a name="example"></a>Exemplo

```cpp
// std__functional__swap.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val)
    {
    return (-val);
    }

int main()
    {
    std::function<int (int)> fn0(neg);
    std::cout << std::boolalpha << "empty == " << !fn0 << std::endl;
    std::cout << "val == " << fn0(3) << std::endl;

    std::function<int (int)> fn1;
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;
    std::cout << std::endl;

    swap(fn0, fn1);
    std::cout << std::boolalpha << "empty == " << !fn0 << std::endl;
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;
    std::cout << "val == " << fn1(3) << std::endl;

    return (0);
    }
```

```Output
empty == false
val == -3
empty == true

empty == true
empty == false
val == -3
```

## <a name="see-also"></a>Consulte também

[\<functional>](../standard-library/functional.md)<br/>
