---
title: Classe function
ms.date: 11/04/2016
f1_keywords:
- functional/std::function
- functional/std::function::result_type
- functional/std::function::assign
- functional/std::function::swap
- functional/std::function::target
- functional/std::function::target_type
- functional/std::function::operator unspecified
- functional/std::function::operator()
helpviewer_keywords:
- std::function [C++]
- std::function [C++], result_type
- std::function [C++], assign
- std::function [C++], swap
- std::function [C++], target
- std::function [C++], target_type
ms.assetid: 7b5ca76b-9ca3-4d89-8fcf-cad70a4aeae6
ms.openlocfilehash: 052cbba69aa99d33de963a3e360e6951a6006bec
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831457"
---
# <a name="function-class"></a>Classe function

Wrapper para um objeto que pode ser chamado.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Fty>
class function  // Fty of type Ret(T1, T2, ..., TN)
    : public unary_function<T1, Ret>       // when Fty is Ret(T1)
    : public binary_function<T1, T2, Ret>  // when Fty is Ret(T1, T2)
{
public:
    typedef Ret result_type;

    function();
    function(nullptr_t);
    function(const function& right);
    template <class Fty2>
        function(Fty2 fn);
    template <class Fty2, class Alloc>
        function(reference_wrapper<Fty2>, const Alloc& Ax);

    template <class Fty2, class Alloc>
        void assign(Fty2, const Alloc& Ax);
    template <class Fty2, class Alloc>
        void assign(reference_wrapper<Fty2>, const Alloc& Ax);
    function& operator=(nullptr_t);
    function& operator=(const function&);
    template <class Fty2>
        function& operator=(Fty2);
    template <class Fty2>
        function& operator=(reference_wrapper<Fty2>);

    void swap(function&);
    explicit operator bool() const;

    result_type operator()(T1, T2, ....., TN) const;
    const std::type_info& target_type() const;
    template <class Fty2>
        Fty2 *target();

    template <class Fty2>
        const Fty2 *target() const;

    template <class Fty2>
        void operator==(const Fty2&) const = delete;
    template <class Fty2>
        void operator!=(const Fty2&) const = delete;
};
```

### <a name="parameters"></a>parâmetros

*Fty*\
O tipo de função a ser encapsulada.

*AX*\
A função do alocador.

## <a name="remarks"></a>Comentários

O modelo de classe é um wrapper de chamada cuja assinatura de chamada é `Ret(T1, T2, ..., TN)` . Você pode usá-lo para circunscrever uma variedade de objetos resgatáveis em um wrapper uniforme.

Algumas funções membro usam um operando que nomeia o objeto de destino desejado. É possível especificar esse operando de várias maneiras:

`fn` – o objeto que pode ser chamado `fn`; após a chamada, o objeto `function` mantém uma cópia de `fn`

`fnref` – o objeto que pode ser chamado nomeado por `fnref.get()`; após a chamada, o objeto `function` mantém uma referência a `fnref.get()`

`right` – o objeto que pode ser chamado, se houver, mantido pelo objeto `function``right`

`npc` – um ponteiro nulo; após a chamada, o objeto `function` fica vazio

Em todos os casos, `INVOKE(f, t1, t2, ..., tN)`, em que `f` é o objeto que pode ser chamado e `t1, t2, ..., tN` são lvalues dos tipos `T1, T2, ..., TN`, respectivamente, deve ser bem formado e, se `Ret` não for nulo, conversível em `Ret`.

Um objeto `function` vazio não tem um objeto que pode ser chamado ou uma referência a um objeto que pode ser chamado.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|-|-|
|[função](#function)|Constrói um wrapper que é vazio ou armazena um objeto que pode ser chamado, de tipo arbitrário com uma assinatura fixa.|

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|-|-|
|[result_type](#result_type)|O tipo retornado do objeto que pode ser chamado armazenado.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[assign](#assign)|Atribui um objeto que pode ser chamado a esse objeto de função.|
|[permuta](#swap)|Troca dois objetos resgatáveis.|
|[destino](#target)|Testa se o objeto pode ser chamado conforme especificado.|
|[target_type](#target_type)|Obtém informações de tipo sobre o objeto que pode ser chamado.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador não especificado](#op_unspecified)|Testa se o objeto que pode ser chamado armazenado existe.|
|[operador ()](#op_call)|Chama um objeto que pode ser chamado.|
|[operador =](#op_eq)|Substitui o objeto que pode ser chamado armazenado.|

## <a name="assign"></a><a name="assign"></a> Cancele

Atribui um objeto que pode ser chamado a esse objeto de função.

```cpp
template <class Fx, class Alloc>
    void assign(
        Fx _Func,
        const Alloc& Ax);

template <class Fx, class Alloc>
    void assign(
        reference_wrapper<Fx> _Fnref,
        const Alloc& Ax);
```

### <a name="parameters"></a>parâmetros

*_Func*\
Um objeto que pode ser chamado.

*_Fnref*\
Um wrapper de referência que contém um objeto que pode ser chamado.

*AX*\
Um objeto alocador.

### <a name="remarks"></a>Comentários

As funções de membro substituem a `callable object` mantida por pelo **`*this`** objeto que pôde ser chamado passado como o `operand` . Ambos alocam armazenamento com o objeto de alocador *AX*.

## <a name="function"></a>Função <a name="function"></a>

Constrói um wrapper que é vazio ou armazena um objeto que pode ser chamado, de tipo arbitrário com uma assinatura fixa.

```cpp
function();
function(nullptr_t npc);
function(const function& right);
template <class Fx>
    function(Fx _Func);
template <class Fx>
    function(reference_wrapper<Fx> _Fnref);
template <class Fx, class Alloc>
    function(
        Fx _Func,
        const Alloc& Ax);

template <class Fx, class Alloc>
    function(
        reference_wrapper<Fx> _Fnref,
        const Alloc& Ax);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O objeto de função a ser copiado.

*Efeito*\
O tipo do objeto que pode ser chamado.

*_Func*\
O objeto que pode ser chamado a ser encapsulado.

*Alocação*\
O tipo do alocador.

*AX*\
O alocador.

*_Fnref*\
A referência do objeto que pode ser chamado a ser encapsulado.

### <a name="remarks"></a>Comentários

Os dois primeiros construtores constroem um objeto `function` vazio. Os próximos três construtores constroem um objeto `function` que contém o objeto que pode ser chamado passado como o operando. Os últimos dois construtores alocam o armazenamento com o objeto de alocador Ax.

### <a name="example"></a>Exemplo

```cpp
// std__functional__function_function.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>
#include <vector>

int square(int val)
{
    return val * val;
}

class multiply_by
{
public:
    explicit multiply_by(const int n) : m_n(n) { }

    int operator()(const int x) const
    {
        return m_n * x;
    }

private:
    int m_n;
};

int main()
{

    typedef std::vector< std::function<int (int)> > vf_t;

    vf_t v;
    v.push_back(square);
    v.push_back(std::negate<int>());
    v.push_back(multiply_by(3));

    for (vf_t::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << (*i)(10) << std::endl;
    }

    std::function<int (int)> f = v[0];
    std::function<int (int)> g;

    if (f) {
        std::cout << "f is non-empty (correct)." << std::endl;
    } else {
        std::cout << "f is empty (can't happen)." << std::endl;
    }

    if (g) {
        std::cout << "g is non-empty (can't happen)." << std::endl;
    } else {
        std::cout << "g is empty (correct)." << std::endl;
    }

    return 0;
}
```

```Output
100
-10
30
f is non-empty (correct).
g is empty (correct).
```

## <a name="operator-unspecified"></a><a name="op_unspecified"></a> operador não especificado

Testa se o objeto que pode ser chamado armazenado existe.

```cpp
operator unspecified();
```

### <a name="remarks"></a>Comentários

O operador retornará um valor que será convertido para **`bool`** com um valor true somente se o objeto não estiver vazio. Você pode usá-lo para testar se o objeto está vazio.

### <a name="example"></a>Exemplo

```cpp
// std__functional__function_operator_bool.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val)
    {
    return (-val);
    }

int main()
    {
    std::function<int (int)> fn0;
    std::cout << std::boolalpha << "not empty == " << (bool)fn0 << std::endl;

    std::function<int (int)> fn1(neg);
    std::cout << std::boolalpha << "not empty == " << (bool)fn1 << std::endl;

    return (0);
    }
```

```Output
not empty == false
not empty == true
```

## <a name="operator"></a><a name="op_call"></a> operador ()

Chama um objeto que pode ser chamado.

```cpp
result_type operator()(
    T1 t1,
    T2 t2, ...,
    TN tN);
```

### <a name="parameters"></a>parâmetros

*TN*\
O tipo do enésimo argumento de chamada.

*tN*\
O enésimo argumento de chamada.

### <a name="remarks"></a>Comentários

A função membro retorna `INVOKE(fn, t1, t2, ..., tN, Ret)` , em que `fn` é o objeto de destino armazenado no **`*this`** . Você pode usá-lo para chamar o objeto que pode ser chamado encapsulado.

### <a name="example"></a>Exemplo

```cpp
// std__functional__function_operator_call.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val)
    {
    return (-val);
    }

int main()
    {
    std::function<int (int)> fn1(neg);
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;
    std::cout << "val == " << fn1(3) << std::endl;

    return (0);
    }
```

```Output
empty == false
val == -3
```

## <a name="operator"></a><a name="op_eq"></a> operador =

Substitui o objeto que pode ser chamado armazenado.

```cpp
function& operator=(null_ptr_type npc);
function& operator=(const function& right);
template <class Fty>
    function& operator=(Fty fn);
template <class Fty>
    function& operator=(reference_wrapper<Fty> fnref);
```

### <a name="parameters"></a>parâmetros

*npc*\
Uma constante de ponteiro nulo.

*Certo*\
O objeto de função a ser copiado.

*FN*\
O objeto que pode ser chamado a ser encapsulado.

*fnref*\
A referência do objeto que pode ser chamado a ser encapsulado.

### <a name="remarks"></a>Comentários

Os operadores substituem cada um dos objetos que podem ser chamados pelo **`*this`** objeto que pôde ser chamado como operando.

### <a name="example"></a>Exemplo

```cpp
// std__functional__function_operator_as.cpp
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
    fn1 = 0;
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;

    fn1 = neg;
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;
    std::cout << "val == " << fn1(3) << std::endl;

    fn1 = fn0;
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;
    std::cout << "val == " << fn1(3) << std::endl;

    fn1 = std::cref(fn1);
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;
    std::cout << "val == " << fn1(3) << std::endl;

    return (0);
    }
```

```Output
empty == false
val == -3
empty == true
empty == false
val == -3
empty == false
val == -3
empty == false
val == -3
```

## <a name="result_type"></a><a name="result_type"></a> result_type

O tipo retornado do objeto que pode ser chamado armazenado.

```cpp
typedef Ret result_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo do tipo de `Ret` na assinatura de chamada do modelo. Você pode usá-lo para determinar o tipo retornado do objeto que pode ser chamado encapsulado.

### <a name="example"></a>Exemplo

```cpp
// std__functional__function_result_type.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val)
    {
    return (-val);
    }

int main()
    {
    std::function<int (int)> fn1(neg);
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;

    std::function<int (int)>::result_type val = fn1(3);
    std::cout << "val == " << val << std::endl;

    return (0);
    }
```

```Output
empty == false
val == -3
```

## <a name="swap"></a><a name="swap"></a> permuta

Troca dois objetos resgatáveis.

```cpp
void swap(function& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O objeto de função com o qual será feita a troca.

### <a name="remarks"></a>Comentários

A função membro troca os objetos de destino entre **`*this`** e *à direita*. Ela faz isso em um horário constante e não gera exceções.

### <a name="example"></a>Exemplo

```cpp
// std__functional__function_swap.cpp
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

    fn0.swap(fn1);
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

## <a name="target"></a><a name="target"></a> alvo

Testa se o objeto pode ser chamado conforme especificado.

```cpp
template <class Fty2>
    Fty2 *target();
template <class Fty2>
    const Fty2 *target() const;
```

### <a name="parameters"></a>parâmetros

*Fty2*\
O tipo de objeto que pode ser chamado de destino a ser testado.

### <a name="remarks"></a>Comentários

O tipo *Fty2* deve ser chamável para os tipos de argumento `T1, T2, ..., TN` e o tipo de retorno `Ret` . Se `target_type() == typeid(Fty2)`, a função modelo membro retornará o endereço do objeto de destino; caso contrário, retornará 0.

Um tipo *Fty2* é chamável para os tipos de argumento `T1, T2, ..., TN` e o tipo de retorno `Ret` se, para lvalues `fn, t1, t2, ..., tN` de tipos `Fty2, T1, T2, ..., TN` , respectivamente, `INVOKE(fn, t1, t2, ..., tN)` é bem formado e, se `Ret` não for **`void`** , conversível para `Ret` .

### <a name="example"></a>Exemplo

```cpp
// std__functional__function_target.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val)
    {
    return (-val);
    }

int main()
    {
    typedef int (*Myfun)(int);
    std::function<int (int)> fn0(neg);
    std::cout << std::boolalpha << "empty == " << !fn0 << std::endl;
    std::cout << "no target == " << (fn0.target<Myfun>() == 0) << std::endl;

    Myfun *fptr = fn0.target<Myfun>();
    std::cout << "val == " << (*fptr)(3) << std::endl;

    std::function<int (int)> fn1;
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;
    std::cout << "no target == " << (fn1.target<Myfun>() == 0) << std::endl;

    return (0);
    }
```

```Output
empty == false
no target == false
val == -3
empty == true
no target == true
```

## <a name="target_type"></a><a name="target_type"></a> target_type

Obtém informações de tipo sobre o objeto que pode ser chamado.

```cpp
const std::type_info& target_type() const;
```

### <a name="remarks"></a>Comentários

A função de membro retorna `typeid(void)` se **`*this`** está vazia, caso contrário `typeid(T)` , retorna, em que `T` é o tipo do objeto de destino.

### <a name="example"></a>Exemplo

```cpp
// std__functional__function_target_type.cpp
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
    std::cout << "type == " << fn0.target_type().name() << std::endl;

    std::function<int (int)> fn1;
    std::cout << std::boolalpha << "empty == " << !fn1 << std::endl;
    std::cout << "type == " << fn1.target_type().name() << std::endl;

    return (0);
    }
```

```Output
empty == false
type == int (__cdecl*)(int)
empty == true
type == void
```
