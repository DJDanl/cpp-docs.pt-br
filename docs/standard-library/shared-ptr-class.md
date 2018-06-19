---
title: Classe shared_ptr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eff0c41993a450e74b468b747776368bae6ad848
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33862868"
---
# <a name="sharedptr-class"></a>Classe shared_ptr

Encapsula um ponteiro inteligente de contagem de referência em torno de um objeto alocado dinamicamente.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class shared_ptr;
```

## <a name="remarks"></a>Comentários

A classe shared_ptr descreve um objeto que usa contagem de referências para gerenciar recursos. Um objeto `shared_ptr` contém efetivamente um ponteiro para o recurso que esse objeto possui ou então retém um ponteiro nulo. Um recurso pode ser possuído por mais um objeto `shared_ptr`; quando o último objeto `shared_ptr` que possui um recurso específico é destruído, o recurso é liberado.

Um `shared_ptr` deixa de possuir um recurso quando ele é reatribuído ou redefinido.

O argumento de modelo `T` pode ser um tipo incompleto, exceto como observado para determinadas funções membro.

Quando um objeto `shared_ptr<T>` é criado com base em de um ponteiro de recurso do tipo `G*` ou com base em um `shared_ptr<G>`, o tipo de ponteiro `G*` deve poder ser convertido para `T*`. Se não for, o código não será compilado. Por exemplo:

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

- se ele foi criado com um objeto [weak_ptr Class](../standard-library/weak-ptr-class.md) que aponta para esse recurso ou

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

`ptr` – um ponteiro de tipo `Other*` para o recurso a ser gerenciado. `T` deve ser um tipo completo. Se a função falhar (por não ser possível alocar o bloco de controle) ele avaliará a expressão `delete ptr`.

`ptr, dtor` – um ponteiro de tipo `Other*` para o recurso a ser gerenciado e um agente de exclusão para esse recurso. Se a função falhar (por não ser possível alocar o bloco de controle) ela chamará `dtor(ptr)`, que precisará ser bem definido.

`ptr, dtor, alloc` – um ponteiro de tipo `Other*` para o recurso a ser gerenciado, um agente de exclusão para esse recurso e um alocador para gerenciar qualquer armazenamento que deva ser alocado e liberado. Se a função falhar (por não ser possível alocar o bloco de controle) ela chamará `dtor(ptr)`, que precisará ser bem definido.

`sp` – um objeto `shared_ptr<Other>` que possui o recurso a ser gerenciado.

`wp` – um objeto `weak_ptr<Other>` que aponta para o recurso a ser gerenciado.

`ap` – um objeto `auto_ptr<Other>` que contém um ponteiro para o recurso a ser gerenciado. Se a função obtiver êxito ela chamará `ap.release()`; caso contrário, ela deixará `ap` inalterado.

Em todos os casos, o tipo de ponteiro `Other*` deve poder ser convertido para `T*`.

## <a name="thread-safety"></a>Segurança de threads

Vários threads podem ler e gravar simultaneamente objetos `shared_ptr` diferentes, mesmo quando os objetos são cópias que compartilham a propriedade.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[shared_ptr](#shared_ptr)|Constrói um `shared_ptr`.|
|[shared_ptr::~shared_ptr](#dtorshared_ptr)|Destrói um `shared_ptr`.|

### <a name="types"></a>Tipos

|Nome de tipo|Descrição|
|-|-|
|[element_type](#element_type)|O tipo de um elemento.|

### <a name="functions"></a>Funções

|Função|Descrição|
|-|-|
|[get](#get)|Obtém o endereço do recurso possuído.|
|[owner_before](#owner_before)|Retornará true se este `shared_ptr` estiver ordenado antes do (ou for inferior ao) ponteiro fornecido.|
|[reset](#reset)|Substitua o recurso possuído.|
|[swap](#swap)|Troca dois objetos `shared_ptr`.|
|[unique](#unique)|Testa se o recurso possuído é exclusivo.|
|[use_count](#use_count)|Conta números de proprietários de recurso.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[bool shared_ptr](#op_bool)|Testa se um recurso possuído existe.|
|[shared_ptr::operator*](#op_star)|Obtém o valor designado.|
|[shared_ptr::operator=](#op_eq)|Substitui o recurso possuído.|
|[shared_ptr::operator-&gt;](#op_arrow)|Obtém um ponteiro para o valor designado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<memory>

**Namespace:** std

## <a name="element_type"></a>  shared_ptr::element_type

O tipo de um elemento.

```cpp
typedef T element_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `T`.

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

## <a name="get"></a>  shared_ptr::get

Obtém o endereço do recurso possuído.

```cpp
T *get() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do recurso possuído. Se o objeto não possui um recurso, ele retorna 0.

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

## <a name="op_bool"></a>  bool shared_ptr

Testa se um recurso possuído existe.

```cpp
explicit operator bool() const noexcept;
```

### <a name="remarks"></a>Comentários

O operador retornará um valor de `true` quando `get() != nullptr`, caso contrário, `false`.

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

## <a name="op_star"></a>  shared_ptr::operator*

Obtém o valor designado.

```cpp
T& operator*() const;
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

## <a name="op_eq"></a>  shared_ptr::operator=

Substitui o recurso possuído.

```cpp
shared_ptr& operator=(const shared_ptr& sp);

template <class Other>
shared_ptr& operator=(const shared_ptr<Other>& sp);

template <class Other>
shared_ptr& operator=(auto_ptr<Other>& ap);

template <class Other>
shared_ptr& operator=(auto_ptr<Other>& ap);

template <class Other>
shared_ptr& operator=(auto_ptr<Other>&& ap);

template <class Other, class Deletor>
shared_ptr& operator=(unique_ptr<Other, Deletor>&& ap);
```

### <a name="parameters"></a>Parâmetros

`sp` O ponteiro compartilhado para copiar.

`ap` O ponteiro de automática para copiar.

### <a name="remarks"></a>Comentários

Todos os operadores decrementam a contagem de referência para o recurso pertencente a `*this` e atribuem a propriedade do recurso nomeado pela sequência de operandos para `*this`. Se a contagem de referência cai para zero, o recurso é liberado. Se um operador falhar, `*this` permanecerá inalterado.

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
    std::auto_ptr<int> ap(new int(10));

    sp0 = sp1;
    std::cout << "*sp0 == " << *sp0 << std::endl;

    sp0 = ap;
    std::cout << "*sp0 == " << *sp0 << std::endl;

    return (0);
}

```

```Output
*sp0 == 5
*sp0 == 10
```

## <a name="op_arrow"></a>  shared_ptr::operator-&gt;

Obtém um ponteiro para o valor designado.

```cpp
T * operator->() const;
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

## <a name="owner_before"></a>  shared_ptr::owner_before

Retornará true se este `shared_ptr` estiver ordenado antes do (ou for inferior ao) ponteiro fornecido.

```cpp
template <class Other>
bool owner_before(const shared_ptr<Other>& ptr);

template <class Other>
bool owner_before(const weak_ptr<Other>& ptr);
```

### <a name="parameters"></a>Parâmetros

`ptr` Um `lvalue` referência como um `shared_ptr` ou `weak_ptr`.

### <a name="remarks"></a>Comentários

A função de membro de modelo retorna true se `*this` é `ordered before` `ptr`.

## <a name="reset"></a>  shared_ptr::reset

Substitua o recurso possuído.

```cpp
void reset();

template <class Other>
void reset(Other *ptr;);

template <class Other, class D>
void reset(Other *ptr, D dtor);

template <class Other, class D, class A>
void reset(Other *ptr, D dtor, A alloc);
```

### <a name="parameters"></a>Parâmetros

`Other` O tipo controlado pelo ponteiro de argumento.

`D` O tipo de deleter.

`ptr` O ponteiro para copiar.

`dtor` Deleter para copiar.

`A` O tipo do alocador.

`alloc` O alocador para copiar.

### <a name="remarks"></a>Comentários

Todos os operadores decrementam a contagem de referência para o recurso pertencente a `*this` e atribuem a propriedade do recurso nomeado pela sequência de operandos para `*this`. Se a contagem de referência cai para zero, o recurso é liberado. Se um operador falhar, `*this` permanecerá inalterado.

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

## <a name="shared_ptr"></a>  shared_ptr::shared_ptr

Constrói um `shared_ptr`.

```cpp
shared_ptr();

shared_ptr(nullptr_t);

shared_ptr(const shared_ptr& sp);

shared_ptr(shared_ptr&& sp);

template <class Other>
explicit shared_ptr(Other* ptr);

template <class Other, class D>
shared_ptr(Other* ptr, D dtor);

template <class D>
shared_ptr(nullptr_t ptr, D dtor);

template <class Other, class D, class A>
shared_ptr(Other* ptr, D dtor, A  alloc);

template <class D, class A>
shared_ptr(nullptr_t ptr, D dtor, A alloc);

template <class Other>
shared_ptr(const shared_ptr<Other>& sp);

template <class Other>
shared_ptr(const weak_ptr<Other>& wp);

template <class &>
shared_ptr(std::auto_ptr<Other>& ap);

template <class &>
shared_ptr(std::auto_ptr<Other>&& ap);

template <class Other, class D>
shared_ptr(unique_ptr<Other, D>&& up);

template <class Other>
shared_ptr(const shared_ptr<Other>& sp, T* ptr);

template <class Other, class D>
shared_ptr(const unique_ptr<Other, D>& up) = delete;
```

### <a name="parameters"></a>Parâmetros

`Other` O tipo controlado pelo ponteiro de argumento.

`ptr` O ponteiro para copiar.

`D` O tipo de deleter.

`A` O tipo do alocador.

`dtor` Deleter.

`ator` O alocador.

`sp` O ponteiro inteligente para copiar.

`wp` O ponteiro fraco.

`ap` O ponteiro de automática para copiar.

### <a name="remarks"></a>Comentários

Cada um dos construtores cria um objeto que possui o recurso nomeado pela sequência de operandos. O construtor `shared_ptr(const weak_ptr<Other>& wp)` gerará um objeto de exceção do tipo [Classe bad_weak_ptr](../standard-library/bad-weak-ptr-class.md) se `wp.expired()`.

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

## <a name="dtorshared_ptr"></a>  shared_ptr::~shared_ptr

Destrói um `shared_ptr`.

```cpp
~shared_ptr();
```

### <a name="remarks"></a>Comentários

O destruidor decrementa a contagem de referência para o recurso atualmente pertencente a `*this`. Se a contagem de referência cai para zero, o recurso é liberado.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_destroy.cpp
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

## <a name="swap"></a>  shared_ptr::swap

Troca dois objetos `shared_ptr`.

```cpp
void swap(shared_ptr& sp);
```

### <a name="parameters"></a>Parâmetros

`sp` O ponteiro compartilhado para troca.

### <a name="remarks"></a>Comentários

A função membro deixa o recurso originalmente possuído por `*this` e subsequentemente possuído por `sp` e o recurso originalmente possuído por `sp` subsequentemente possuído por `*this`. A função não altera as contagens de referências dos dois recursos e ela não gera nenhuma exceção.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_swap.cpp
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

## <a name="unique"></a>  shared_ptr::unique

Testa se o recurso possuído é exclusivo.

```cpp
bool unique() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna `true` se nenhum outro objeto `shared_ptr` possui o recurso que pertence a `*this`, caso contrário, `false`.

### <a name="example"></a>Exemplo

```cpp
// std__memory__shared_ptr_unique.cpp
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

## <a name="use_count"></a>  shared_ptr::use_count

Conta números de proprietários de recurso.

```cpp
long use_count() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o número de objetos `shared_ptr` que tem do recurso que pertence a `*this`.

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

## <a name="see-also"></a>Consulte também

[Classe weak_ptr](../standard-library/weak-ptr-class.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
