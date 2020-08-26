---
title: Classe shared_ptr
ms.date: 07/29/2019
f1_keywords:
- memory/std::shared_ptr
- memory/std::shared_ptr::element_type
- memory/std::shared_ptr::get
- memory/std::shared_ptr::owner_before
- memory/std::shared_ptr::reset
- memory/std::shared_ptr::swap
- memory/std::shared_ptr::unique
- memory/std::shared_ptr::use_count
- memory/std::shared_ptr::operator boolean-type
- memory/std::shared_ptr::operator*
- memory/std::shared_ptr::operator=
- memory/std::shared_ptr::operator->
helpviewer_keywords:
- std::shared_ptr [C++]
- std::shared_ptr [C++], element_type
- std::shared_ptr [C++], get
- std::shared_ptr [C++], owner_before
- std::shared_ptr [C++], reset
- std::shared_ptr [C++], swap
- std::shared_ptr [C++], unique
- std::shared_ptr [C++], use_count
- std::shared_ptr [C++], element_type
- std::shared_ptr [C++], get
- std::shared_ptr [C++], owner_before
- std::shared_ptr [C++], reset
- std::shared_ptr [C++], swap
- std::shared_ptr [C++], unique
- std::shared_ptr [C++], use_count
ms.assetid: 1469fc51-c658-43f1-886c-f4530dd84860
ms.openlocfilehash: e41c76e7bd3e77b34ad38d3998ee1d38cdc2fee4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846206"
---
# <a name="shared_ptr-class"></a>Classe shared_ptr

Encapsula um ponteiro inteligente de contagem de referência em torno de um objeto alocado dinamicamente.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class shared_ptr;
```

## <a name="remarks"></a>Comentários

A `shared_ptr` classe descreve um objeto que usa a contagem de referência para gerenciar recursos. Um objeto `shared_ptr` contém efetivamente um ponteiro para o recurso que esse objeto possui ou então retém um ponteiro nulo. Um recurso pode ser possuído por mais um objeto `shared_ptr`; quando o último objeto `shared_ptr` que possui um recurso específico é destruído, o recurso é liberado.

Um `shared_ptr` para o proprietário de um recurso quando ele é reatribuído ou redefinido.

O argumento de modelo `T` pode ser um tipo incompleto, exceto como observado para determinadas funções membro.

Quando um objeto `shared_ptr<T>` é criado com base em de um ponteiro de recurso do tipo `G*` ou com base em um `shared_ptr<G>`, o tipo de ponteiro `G*` deve poder ser convertido para `T*`. Se não for conversível, o código não será compilado. Por exemplo:

```cpp
#include <memory>
using namespace std;

class F {};
class G : public F {};

shared_ptr<G> sp0(new G);   // okay, template parameter G and argument G*
shared_ptr<G> sp1(sp0);     // okay, template parameter G and argument shared_ptr<G>
shared_ptr<F> sp2(new G);   // okay, G* convertible to F*
shared_ptr<F> sp3(sp0);     // okay, template parameter F and argument shared_ptr<G>
shared_ptr<F> sp4(sp2);     // okay, template parameter F and argument shared_ptr<F>
shared_ptr<int> sp5(new G); // error, G* not convertible to int*
shared_ptr<int> sp6(sp2);   // error, template parameter int and argument shared_ptr<F>
```

Um objeto `shared_ptr` possui um recurso:

- se ele foi criado com um ponteiro para esse recurso,

- se ele foi criado com um objeto `shared_ptr` que possui esse recurso,

- Se ele foi construído a partir de um objeto [weak_ptr](weak-ptr-class.md) que aponta para esse recurso, ou

- se a propriedade desse recurso foi atribuída a ele, seja com [shared_ptr::operator=](#op_eq) ou chamando a função membro [shared_ptr::reset](#reset).

Os objetos `shared_ptr` que possuem um recurso compartilham um bloco de controle. O bloco de controle contém:

- o número de objetos `shared_ptr` que são proprietários do recurso,

- o número de objetos `weak_ptr` que apontam para o recurso,

- o agente de exclusão para esse recurso, se houver,

- o alocador personalizado para o bloco de controle, se houver.

Um objeto `shared_ptr` que é inicializado pelo uso de um ponteiro nulo tem um bloco de controle de objeto e não está vazio. Após um objeto `shared_ptr` liberar um recurso, ele não possui mais esse recurso. Após um objeto `weak_ptr` liberar um recurso, ele não aponta mais para esse recurso.

Quando o número de objetos `shared_ptr` que possuem um recurso se torna zero, o recurso é liberado, excluindo-o ou passando o seu endereço para um agente de exclusão, dependendo de como a propriedade do recurso foi originalmente criada. Quando o número de objetos `shared_ptr` que possuem um recurso é zero e o número de objetos `weak_ptr` que apontam para esse recurso é zero, o bloco de controle é liberado, usando o alocador personalizado para o bloco de controle se ele tiver um.

Um objeto `shared_ptr` vazio não possui nenhum recurso e não tem nenhum bloco de controle.

Um agente de exclusão é um objeto de função que tem uma função membro `operator()`. Seu tipo deve ser construível por cópia e seu construtor e destruidor de cópia não devem gerar exceções. Ele aceita um parâmetro, o objeto a ser excluído.

Algumas funções usam uma lista de argumentos que define propriedades do objeto `shared_ptr<T>` ou `weak_ptr<T>` resultante. É possível especificar essa lista de argumentos de várias maneiras:

sem argumentos – o objeto resultante é um ou objeto `shared_ptr` vazio ou um objeto `weak_ptr` vazio.

`ptr` – um ponteiro de tipo `Other*` para o recurso a ser gerenciado. `T` deve ser um tipo completo. Se a função falhar (porque o bloco de controle não pode ser alocado), ele avaliará a expressão `delete ptr` .

`ptr, deleter` – um ponteiro de tipo `Other*` para o recurso a ser gerenciado e um agente de exclusão para esse recurso. Se a função falhar (porque o bloco de controle não pode ser alocado), ele chamará `deleter(ptr)` , que deve ser bem definido.

`ptr, deleter, alloc` – um ponteiro de tipo `Other*` para o recurso a ser gerenciado, um agente de exclusão para esse recurso e um alocador para gerenciar qualquer armazenamento que deva ser alocado e liberado. Se a função falhar (porque o bloco de controle não pode ser alocado), ele chamará `deleter(ptr)` , que deve ser bem definido.

`sp` – um objeto `shared_ptr<Other>` que possui o recurso a ser gerenciado.

`wp` – um objeto `weak_ptr<Other>` que aponta para o recurso a ser gerenciado.

`ap` – um objeto `auto_ptr<Other>` que contém um ponteiro para o recurso a ser gerenciado. Se a função tiver sucesso, ela será chamada `ap.release()` ; caso contrário, ela deixará `ap` inalterada.

Em todos os casos, o tipo de ponteiro `Other*` deve poder ser convertido para `T*`.

## <a name="thread-safety"></a>Acesso thread-safe

Vários threads podem ler e gravar simultaneamente objetos `shared_ptr` diferentes, mesmo quando os objetos são cópias que compartilham a propriedade.

## <a name="members"></a>Membros

|Nome|Descrição|
|-|-|
| **Construtores** | |
|[shared_ptr](#shared_ptr)|Constrói um `shared_ptr`.|
|[~ shared_ptr](#dtorshared_ptr)|Destrói um `shared_ptr`.|
| **TYPEDEFs** | |
|[element_type](#element_type)|O tipo de um elemento.|
|[weak_type](#weak_type)|O tipo de um ponteiro fraco para um elemento.|
| **Funções de membro** | |
|[get](#get)|Obtém o endereço do recurso possuído.|
|[owner_before](#owner_before)|Retornará true se este `shared_ptr` estiver ordenado antes do (ou for inferior ao) ponteiro fornecido.|
|[reset](#reset)|Substitua o recurso possuído.|
|[permuta](#swap)|Troca dois objetos `shared_ptr`.|
|[unique](#unique)|Testa se o recurso possuído é exclusivo.|
|[use_count](#use_count)|Conta números de proprietários de recurso.|
| **Operadores** | |
|[booliano de operador](#op_bool)|Testa se um recurso possuído existe.|
|[operador](#op_star)|Obtém o valor designado.|
|[operador =](#op_eq)|Substitui o recurso possuído.|
|[operador&gt;](#op_arrow)|Obtém um ponteiro para o valor designado.|

## <a name="element_type"></a><a name="element_type"></a> element_type

O tipo de um elemento.

```cpp
typedef T element_type;                  // before C++17
using element_type = remove_extent_t<T>; // C++17
```

### <a name="remarks"></a>Comentários

O `element_type` tipo é um sinônimo para o parâmetro de modelo `T` .

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_element_type.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp0(new int(5));
    std::shared_ptr<int>::element_type val = *sp0;

    std::cout << "*sp0 == " << val << std::endl;

    return (0);
}
```

```Output
*sp0 == 5
```

## <a name="get"></a><a name="get"></a> Obter

Obtém o endereço do recurso possuído.

```cpp
element_type* get() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do recurso possuído. Se o objeto não possuir um recurso, ele retornará 0.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_get.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp0;
    std::shared_ptr<int> sp1(new int(5));

    std::cout << "sp0.get() == 0 == " << std::boolalpha
        << (sp0.get() == 0) << std::endl;
    std::cout << "*sp1.get() == " << *sp1.get() << std::endl;

    return (0);
}
```

```Output
sp0.get() == 0 == true
*sp1.get() == 5
```

## <a name="operator-bool"></a><a name="op_bool"></a> booliano de operador

Testa se um recurso possuído existe.

```cpp
explicit operator bool() const noexcept;
```

### <a name="remarks"></a>Comentários

O operador retorna um valor de **`true`** quando `get() != nullptr` , caso contrário, **`false`** .

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_operator_bool.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp0;
    std::shared_ptr<int> sp1(new int(5));

    std::cout << "(bool)sp0 == " << std::boolalpha
        << (bool)sp0 << std::endl;
    std::cout << "(bool)sp1 == " << std::boolalpha
        << (bool)sp1 << std::endl;

    return (0);
}
```

```Output
(bool)sp0 == false
(bool)sp1 == true
```

## <a name="operator"></a><a name="op_star"></a> operador

Obtém o valor designado.

```cpp
T& operator*() const noexcept;
```

### <a name="remarks"></a>Comentários

O operador de indireção retorna `*get()`. Portanto, o ponteiro armazenado não deve ser nulo.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_operator_st.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp0(new int(5));

    std::cout << "*sp0 == " << *sp0 << std::endl;

    return (0);
}
```

```Output
*sp0 == 5
```

## <a name="operator"></a><a name="op_eq"></a> operador =

Substitui o recurso possuído.

```cpp
shared_ptr& operator=(const shared_ptr& sp) noexcept;

shared_ptr& operator=(shared_ptr&& sp) noexcept;

template <class Other>
shared_ptr& operator=(const shared_ptr<Other>& sp) noexcept;

template <class Other>
shared_ptr& operator=(shared_ptr<Other>&& sp) noexcept;

template <class Other>
shared_ptr& operator=(auto_ptr<Other>&& ap);    // deprecated in C++11, removed in C++17

template <class Other, class Deleter>
shared_ptr& operator=(unique_ptr<Other, Deleter>&& up);
```

### <a name="parameters"></a>parâmetros

*SP3*\
O ponteiro compartilhado para copiar ou mover.

*pontos*\
O ponteiro automático a ser movido. A `auto_ptr` sobrecarga é preterida no c++ 11 e é removida no c++ 17.

*limpeza*\
O ponteiro exclusivo para o objeto com o qual adotar a propriedade. *up* não possui nenhum objeto após a chamada.

*Outros*\
O tipo do objeto apontado por *SP*, *AP*ou *up*.

*Excluidor*\
O tipo de excluidor do objeto de propriedade, armazenado para exclusão posterior do objeto.

### <a name="remarks"></a>Comentários

Todos os operadores decrementam a contagem de referência para o recurso atualmente de propriedade **`*this`** e atribuem a propriedade do recurso nomeado pela sequência de operando para **`*this`** . Se a contagem de referência cai para zero, o recurso é liberado. Se um operador falhar, ele deixará **`*this`** inalterado.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_operator_as.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp0;
    std::shared_ptr<int> sp1(new int(5));
    std::unique_ptr<int> up(new int(10));

    sp0 = sp1;
    std::cout << "*sp0 == " << *sp0 << std::endl;

    sp0 = up;
    std::cout << "*sp0 == " << *sp0 << std::endl;

    return (0);
}
```

```Output
*sp0 == 5
*sp0 == 10
```

## <a name="operator-"></a><a name="op_arrow"></a> operador->

Obtém um ponteiro para o valor designado.

```cpp
T* operator->() const noexcept;
```

### <a name="remarks"></a>Comentários

O operador de seleção retorna `get()`, de modo que a expressão `sp->member` comporta-se da mesma forma que `(sp.get())->member`, em que `sp` é um objeto da classe `shared_ptr<T>`. Portanto, o ponteiro armazenado não deve ser nulo e o `T` deve ser uma classe, estrutura ou tipo de união com um membro `member`.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_operator_ar.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

typedef std::pair<int, int> Mypair;
int main()
{
    std::shared_ptr<Mypair> sp0(new Mypair(1, 2));

    std::cout << "sp0->first == " << sp0->first << std::endl;
    std::cout << "sp0->second == " << sp0->second << std::endl;

    return (0);
}
```

```Output
sp0->first == 1
sp0->second == 2
```

## <a name="owner_before"></a><a name="owner_before"></a> owner_before

Retornará true se este `shared_ptr` estiver ordenado antes do (ou for inferior ao) ponteiro fornecido.

```cpp
template <class Other>
bool owner_before(const shared_ptr<Other>& ptr) const noexcept;

template <class Other>
bool owner_before(const weak_ptr<Other>& ptr) const noexcept;
```

### <a name="parameters"></a>parâmetros

*PTR*\
Uma referência lvalue para um `shared_ptr` ou um `weak_ptr` .

### <a name="remarks"></a>Comentários

A função de membro de modelo retornará true se **`*this`** for ordenada antes `ptr` .

## <a name="reset"></a><a name="reset"></a> definido

Substitua o recurso possuído.

```cpp
void reset() noexcept;

template <class Other>
void reset(Other *ptr);

template <class Other, class Deleter>
void reset(
    Other *ptr,
    Deleter deleter);

template <class Other, class Deleter, class Allocator>
void reset(
    Other *ptr,
    Deleter deleter,
    Allocator alloc);
```

### <a name="parameters"></a>parâmetros

*Outros*\
O tipo controlado pelo ponteiro de argumento.

*Excluidor*\
O tipo do agente de exclusão.

*PTR*\
O ponteiro para copiar.

*excluidor*\
O agente de exclusão a copiar.

*Alocador*\
O tipo do alocador.

*alocação*\
O alocador a copiar.

### <a name="remarks"></a>Comentários

Todos os operadores decrementam a contagem de referência para o recurso atualmente de propriedade **`*this`** e atribuem a propriedade do recurso nomeado pela sequência de operando para **`*this`** . Se a contagem de referência cai para zero, o recurso é liberado. Se um operador falhar, ele deixará **`*this`** inalterado.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_reset.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

struct deleter
{
    void operator()(int *p)
    {
        delete p;
    }
};

int main()
{
    std::shared_ptr<int> sp(new int(5));

    std::cout << "*sp == " << std::boolalpha
        << *sp << std::endl;

    sp.reset();
    std::cout << "(bool)sp == " << std::boolalpha
        << (bool)sp << std::endl;

    sp.reset(new int(10));
    std::cout << "*sp == " << std::boolalpha
        << *sp << std::endl;

    sp.reset(new int(15), deleter());
    std::cout << "*sp == " << std::boolalpha
        << *sp << std::endl;

    return (0);
}
```

```Output
*sp == 5
(bool)sp == false
*sp == 10
*sp == 15
```

## <a name="shared_ptr"></a><a name="shared_ptr"></a> shared_ptr

Constrói um `shared_ptr`.

```cpp
constexpr shared_ptr() noexcept;

constexpr shared_ptr(nullptr_t) noexcept : shared_ptr() {}

shared_ptr(const shared_ptr& sp) noexcept;

shared_ptr(shared_ptr&& sp) noexcept;

template <class Other>
explicit shared_ptr(Other* ptr);

template <class Other, class Deleter>
shared_ptr(
    Other* ptr,
    Deleter deleter);

template <class Deleter>
shared_ptr(
    nullptr_t ptr,
    Deleter deleter);

template <class Other, class Deleter, class Allocator>
shared_ptr(
    Other* ptr,
    Deleter deleter,
    Allocator alloc);

template <class Deleter, class Allocator>
shared_ptr(
    nullptr_t ptr,
    Deleter deleter,
    Allocator alloc);

template <class Other>
shared_ptr(
    const shared_ptr<Other>& sp) noexcept;

template <class Other>
explicit shared_ptr(
    const weak_ptr<Other>& wp);

template <class &>
shared_ptr(
    std::auto_ptr<Other>& ap);

template <class &>
shared_ptr(
    std::auto_ptr<Other>&& ap);

template <class Other, class Deleter>
shared_ptr(
    unique_ptr<Other, Deleter>&& up);

template <class Other>
shared_ptr(
    const shared_ptr<Other>& sp,
    element_type* ptr) noexcept;

template <class Other>
shared_ptr(
    shared_ptr<Other>&& sp,
    element_type* ptr) noexcept;

template <class Other, class Deleter>
shared_ptr(
    const unique_ptr<Other, Deleter>& up) = delete;
```

### <a name="parameters"></a>parâmetros

*Outros*\
O tipo controlado pelo ponteiro de argumento.

*PTR*\
O ponteiro para copiar.

*Excluidor*\
O tipo do agente de exclusão.

*Alocador*\
O tipo do alocador.

*excluidor*\
O agente de exclusão.

*alocação*\
O alocador.

*SP3*\
O ponteiro inteligente a copiar.

*processador*\
O ponteiro fraco.

*pontos*\
O ponteiro automático para copiar.

### <a name="remarks"></a>Comentários

Cada um dos construtores cria um objeto que possui o recurso nomeado pela sequência de operandos. O construtor `shared_ptr(const weak_ptr<Other>& wp)` gera um objeto de exceção do tipo [bad_weak_ptr](bad-weak-ptr-class.md) se `wp.expired()` .

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_construct.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

struct deleter
{
    void operator()(int *p)
    {
        delete p;
    }
};

int main()
{
    std::shared_ptr<int> sp0;
    std::cout << "(bool)sp0 == " << std::boolalpha
        << (bool)sp0 << std::endl;

    std::shared_ptr<int> sp1(new int(5));
    std::cout << "*sp1 == " << *sp1 << std::endl;

    std::shared_ptr<int> sp2(new int(10), deleter());
    std::cout << "*sp2 == " << *sp2 << std::endl;

    std::shared_ptr<int> sp3(sp2);
    std::cout << "*sp3 == " << *sp3 << std::endl;

    std::weak_ptr<int> wp(sp3);
    std::shared_ptr<int> sp4(wp);
    std::cout << "*sp4 == " << *sp4 << std::endl;

    std::auto_ptr<int> ap(new int(15));
    std::shared_ptr<int> sp5(ap);
    std::cout << "*sp5 == " << *sp5 << std::endl;

    return (0);
}
```

```Output
(bool)sp0 == false
*sp1 == 5
*sp2 == 10
*sp3 == 10
*sp4 == 10
*sp5 == 15
```

## <a name="shared_ptr"></a><a name="dtorshared_ptr"></a> ~ shared_ptr

Destrói um `shared_ptr`.

```cpp
~shared_ptr();
```

### <a name="remarks"></a>Comentários

O destruidor decrementa a contagem de referência para o recurso atualmente pertencente ao **`*this`** . Se a contagem de referência cai para zero, o recurso é liberado.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_destroy.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp1(new int(5));
    std::cout << "*sp1 == " << *sp1 << std::endl;
    std::cout << "use count == " << sp1.use_count() << std::endl;

    {
        std::shared_ptr<int> sp2(sp1);
        std::cout << "*sp2 == " << *sp2 << std::endl;
        std::cout << "use count == " << sp1.use_count() << std::endl;
    }

    // check use count after sp2 is destroyed
    std::cout << "use count == " << sp1.use_count() << std::endl;

    return (0);
}
```

```Output
*sp1 == 5
use count == 1
*sp2 == 5
use count == 2
use count == 1
```

## <a name="swap"></a><a name="swap"></a> permuta

Troca dois objetos `shared_ptr`.

```cpp
void swap(shared_ptr& sp) noexcept;
```

### <a name="parameters"></a>parâmetros

*SP3*\
O ponteiro compartilhado com o qual realizar a troca.

### <a name="remarks"></a>Comentários

A função de membro deixa o recurso originalmente de Propriedade do **`*this`** *SP*, e o recurso originalmente pertencente ao *SP* , subsequentemente pertencente a **`*this`** . A função não altera as contagens de referências dos dois recursos e ela não gera nenhuma exceção.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_swap.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp1(new int(5));
    std::shared_ptr<int> sp2(new int(10));
    std::cout << "*sp1 == " << *sp1 << std::endl;

    sp1.swap(sp2);
    std::cout << "*sp1 == " << *sp1 << std::endl;

    swap(sp1, sp2);
    std::cout << "*sp1 == " << *sp1 << std::endl;
    std::cout << std::endl;

    std::weak_ptr<int> wp1(sp1);
    std::weak_ptr<int> wp2(sp2);
    std::cout << "*wp1 == " << *wp1.lock() << std::endl;

    wp1.swap(wp2);
    std::cout << "*wp1 == " << *wp1.lock() << std::endl;

    swap(wp1, wp2);
    std::cout << "*wp1 == " << *wp1.lock() << std::endl;

    return (0);
}
```

```Output
*sp1 == 5
*sp1 == 10
*sp1 == 5
*wp1 == 5
*wp1 == 10
*wp1 == 5
```

## <a name="unique"></a><a name="unique"></a> diferente

Testa se o recurso possuído é exclusivo. Essa função foi preterida em C++ 17 e foi removida em C++ 20.

```cpp
bool unique() const noexcept;
```

### <a name="remarks"></a>Comentários

A função de membro retornará **`true`** se nenhum outro `shared_ptr` objeto possuir o recurso que pertence **`*this`** , caso contrário **`false`** .

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_unique.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp1(new int(5));
    std::cout << "sp1.unique() == " << std::boolalpha
        << sp1.unique() << std::endl;

    std::shared_ptr<int> sp2(sp1);
    std::cout << "sp1.unique() == " << std::boolalpha
        << sp1.unique() << std::endl;

    return (0);
}
```

```Output
sp1.unique() == true
sp1.unique() == false
```

## <a name="use_count"></a><a name="use_count"></a> use_count

Conta números de proprietários de recurso.

```cpp
long use_count() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro retorna o número de `shared_ptr` objetos que possuem o recurso de Propriedade do **`*this`** .

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_use_count.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp1(new int(5));
    std::cout << "sp1.use_count() == "
        << sp1.use_count() << std::endl;

    std::shared_ptr<int> sp2(sp1);
    std::cout << "sp1.use_count() == "
        << sp1.use_count() << std::endl;

    return (0);
}
```

```Output
sp1.use_count() == 1
sp1.use_count() == 2
```

## <a name="weak_type"></a><a name="weak_type"></a> weak_type

O tipo de um ponteiro fraco para um elemento.

```cpp
using weak_type = weak_ptr<T>; // C++17
```

### <a name="remarks"></a>Comentários

A `weak_type` definição foi adicionada em c++ 17.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](cpp-standard-library-header-files.md)\
[\<memory>](memory.md)\
[unique_ptr](unique-ptr-class.md)\
[Classe weak_ptr](weak-ptr-class.md)
