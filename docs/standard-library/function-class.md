---
title: Classe function | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- function
- functional/std::function
- functional/std::function::result_type
- functional/std::function::assign
- functional/std::function::swap
- functional/std::function::target
- functional/std::function::target_type
- functional/std::function::operator unspecified
- functional/std::function::operator()
dev_langs:
- C++
helpviewer_keywords:
- function class
ms.assetid: 7b5ca76b-9ca3-4d89-8fcf-cad70a4aeae6
caps.latest.revision: 26
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 0c79b2b4d1ac2e9df7f38708ff232d70392cce15
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

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
  
### <a name="parameters"></a>Parâmetros  
 `Fty`  
 O tipo de função a ser encapsulada.  
  
 `Ax`  
 A função do alocador.  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo é um wrapper de chamada cuja assinatura de chamada é `Ret(T1, T2, ..., TN)`. Você pode usá-lo para circunscrever uma variedade de objetos resgatáveis em um wrapper uniforme.  
  
 Algumas funções membro usam um operando que nomeia o objeto de destino desejado. É possível especificar esse operando de várias maneiras:  
  
 `fn` – o objeto que pode ser chamado `fn`; após a chamada, o objeto `function` mantém uma cópia de `fn`  
  
 `fnref` – o objeto que pode ser chamado nomeado por `fnref.get()`; após a chamada, o objeto `function` mantém uma referência a `fnref.get()`  
  
 `right` – o objeto que pode ser chamado, se houver, mantido pelo objeto `function` `right`  
  
 `npc` – um ponteiro nulo; após a chamada, o objeto `function` fica vazio  
  
 Em todos os casos, `INVOKE(f, t1, t2, ..., tN)`, em que `f` é o objeto que pode ser chamado e `t1, t2, ..., tN` são lvalues dos tipos `T1, T2, ..., TN`, respectivamente, deve ser bem formado e, se `Ret` não for nulo, conversível em `Ret`.  
  
 Um objeto `function` vazio não tem um objeto que pode ser chamado ou uma referência a um objeto que pode ser chamado.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[function](#function)|Constrói um wrapper que é vazio ou armazena um objeto que pode ser chamado, de tipo arbitrário com uma assinatura fixa.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[tipo_resultado](#result_type)|O tipo retornado do objeto que pode ser chamado armazenado.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[assign](#assign)|Atribui um objeto que pode ser chamado a esse objeto de função.|  
|[swap](#swap)|Troca dois objetos resgatáveis.|  
|[destino](#target)|Testa se o objeto pode ser chamado conforme especificado.|  
|[target_type](#target_type)|Obtém informações de tipo sobre o objeto que pode ser chamado.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[function::operator unspecified](#op_unspecified)|Testa se o objeto que pode ser chamado armazenado existe.|  
|[function::operator()](#op_call)|Chama um objeto que pode ser chamado.|  
|[function::operator=](#op_eq)|Substitui o objeto que pode ser chamado armazenado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
##  <a name="assign"></a>  function::assign  
 Atribui um objeto que pode ser chamado a esse objeto de função.  
  
```  
template <class Fx, class Alloc>  
    void assign(
        Fx _Func,   
        const Alloc& Ax);

template <class Fx, class Alloc>  
    void assign(
        reference_wrapper<Fx> _Fnref,   
        const Alloc& Ax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Func`  
 Um objeto que pode ser chamado.  
  
 `_Fnref`  
 Um wrapper de referência que contém um objeto que pode ser chamado.  
  
 `Ax`  
 Um objeto alocador.  
  
### <a name="remarks"></a>Comentários  
 As funções membro substituem o `callable object` mantido por `*this` pelo objeto que pode ser chamado passado como o `operand`. Ambas alocam o armazenamento com o objeto de alocador `Ax`.  
  
##  <a name="function"></a>  function::function  
 Constrói um wrapper que é vazio ou armazena um objeto que pode ser chamado, de tipo arbitrário com uma assinatura fixa.  
  
```  
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
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O objeto de função a ser copiado.  
  
 `Fx`  
 O tipo do objeto que pode ser chamado.  
  
 `_Func`  
 O objeto que pode ser chamado a ser encapsulado.  
  
 `Alloc`  
 O tipo do alocador.  
  
 `Ax`  
 O alocador.  
  
 `_Fnref`  
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
  
##  <a name="op_unspecified"></a>  function::operator unspecified  
 Testa se o objeto que pode ser chamado armazenado existe.  
  
```  
operator unspecified();
```   
  
### <a name="remarks"></a>Comentários  
 O operador retornará um valor conversível em `bool` com um valor true somente se o objeto não estiver vazio. Você pode usá-lo para testar se o objeto está vazio.  
  
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
  
##  <a name="op_call"></a>  function::operator()  
 Chama um objeto que pode ser chamado.  
  
```  
result_type operator()(
    T1 t1,
    T2 t2, ...,
    TN tN);
```  
  
### <a name="parameters"></a>Parâmetros  
 `TN`  
 O tipo do enésimo argumento de chamada.  
  
 `tN`  
 O enésimo argumento de chamada.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna `INVOKE(fn, t1, t2, ..., tN, Ret)`, em que `fn` é o objeto de destino armazenado em `*this`. Você pode usá-lo para chamar o objeto que pode ser chamado encapsulado.  
  
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
  
##  <a name="op_eq"></a>  function::operator=  
 Substitui o objeto que pode ser chamado armazenado.  
  
```  
function& operator=(null_ptr_type npc);
function& operator=(const function& right);
template <class Fty>  
    function& operator=(Fty fn);
template <class Fty>  
    function& operator=(reference_wrapper<Fty> fnref);
```  
  
### <a name="parameters"></a>Parâmetros  
 `npc`  
 Uma constante de ponteiro nulo.  
  
 `right`  
 O objeto de função a ser copiado.  
  
 `fn`  
 O objeto que pode ser chamado a ser encapsulado.  
  
 `fnref`  
 A referência do objeto que pode ser chamado a ser encapsulado.  
  
### <a name="remarks"></a>Comentários  
 Os operadores substituem o objeto que pode ser chamado mantido por `*this` pelo objeto que pode ser chamado passado como o operando.  
  
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
  
##  <a name="result_type"></a>  function::result_type  
 O tipo retornado do objeto que pode ser chamado armazenado.  
  
```  
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
  
##  <a name="swap"></a>  function::swap  
 Troca dois objetos resgatáveis.  
  
```  
void swap(function& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O objeto de função com o qual será feita a troca.  
  
### <a name="remarks"></a>Comentários  
 A função membro troca os objetos de destino entre `*this` e `right`. Ela faz isso em um horário constante e não gera exceções.  
  
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
  
##  <a name="target"></a>  function::target  
 Testa se o objeto pode ser chamado conforme especificado.  
  
```  
template <class Fty2>  
    Fty2 *target();
template <class Fty2>  
    const Fty2 *target() const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Fty2`  
 O tipo de objeto que pode ser chamado de destino a ser testado.  
  
### <a name="remarks"></a>Comentários  
 O tipo `Fty2` deve ser que pode ser chamado para os tipos de argumento `T1, T2, ..., TN` e o tipo retornado `Ret`. Se `target_type() == typeid(Fty2)`, a função modelo membro retornará o endereço do objeto de destino; caso contrário, retornará 0.  
  
 Um tipo `Fty2` pode ser chamado para os tipos de argumento `T1, T2, ..., TN` e o tipo retornado `Ret` se, para lvalues `fn, t1, t2, ..., tN` dos tipos `Fty2, T1, T2, ..., TN`, respectivamente, `INVOKE(fn, t1, t2, ..., tN)` for bem formado e, se `Ret` não for `void`, conversível em `Ret`.  
  
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
  
##  <a name="target_type"></a>  function::target_type  
 Obtém informações de tipo sobre o objeto que pode ser chamado.  
  
```  
const std::type_info& target_type() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna `typeid(void)` se `*this` estiver vazio, caso contrário, ela retorna `typeid(T)`, em que `T` é o tipo de objeto de destino.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [mem_fn](../standard-library/functional-functions.md#mem_fn)   
 [Classe reference_wrapper](../standard-library/reference-wrapper-class.md)

