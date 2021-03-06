---
title: Classe weak_ptr
ms.date: 07/29/2019
f1_keywords:
- memory/std::weak_ptr
- memory/std::weak_ptr::element_type
- memory/std::weak_ptr::expired
- memory/std::weak_ptr::lock
- memory/std::weak_ptr::owner_before
- memory/std::weak_ptr::reset
- memory/std::weak_ptr::swap
- memory/std::weak_ptr::use_count
- memory/std::weak_ptr::operator=
helpviewer_keywords:
- std::weak_ptr [C++]
- std::weak_ptr [C++], element_type
- std::weak_ptr [C++], expired
- std::weak_ptr [C++], lock
- std::weak_ptr [C++], owner_before
- std::weak_ptr [C++], reset
- std::weak_ptr [C++], swap
- std::weak_ptr [C++], use_count
- std::weak_ptr [C++], element_type
- std::weak_ptr [C++], expired
- std::weak_ptr [C++], lock
- std::weak_ptr [C++], owner_before
- std::weak_ptr [C++], reset
- std::weak_ptr [C++], swap
- std::weak_ptr [C++], use_count
ms.assetid: 2db4afb2-c7be-46fc-9c20-34ec2f8cc7c2
ms.openlocfilehash: 5a4989b9ac29e6a35e50479343d6bcf5a39ae1b0
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831730"
---
# <a name="weak_ptr-class"></a>Classe weak_ptr

Encapsula um ponteiro vinculado de modo fraco.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T> class weak_ptr;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo controlado pelo ponteiro fraco.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que aponta para um recurso que é gerenciado por um ou mais objetos [shared_ptr](shared-ptr-class.md) . Os `weak_ptr` objetos que apontam para um recurso não afetam a contagem de referência do recurso. Quando o último `shared_ptr` objeto que gerencia esse recurso for destruído, o recurso será liberado, mesmo se houver `weak_ptr` objetos que apontam para esse recurso. Esse comportamento é essencial para evitar ciclos em estruturas de dados.

O objeto `weak_ptr` aponta para um recurso se ele foi construído com base em um objeto `shared_ptr` que tem esse recurso, se ele foi construído com base em um objeto `weak_ptr` que aponta para esse recurso ou se esse recurso foi atribuído a ele com [operator=](#op_eq). Um `weak_ptr` objeto não fornece acesso direto ao recurso para o qual ele aponta. O código que precisa usar o recurso faz isso por meio de um objeto `shared_ptr` que tem esse recurso, criado chamando a função membro [lock](#lock). Um `weak_ptr` objeto expirou quando o recurso que ele aponta foi liberado porque todos os `shared_ptr` objetos que possuem o recurso foram destruídos. Chamar `lock` em um objeto `weak_ptr` que expirou cria um objeto shared_ptr vazio.

Um objeto weak_ptr vazio não aponta para nenhum recurso e não tem nenhum bloco de controle. Sua função membro `lock` retorna um objeto shared_ptr vazio.

Um ciclo ocorre quando dois ou mais recursos controlados por objetos `shared_ptr` contêm mutuamente objetos `shared_ptr` de referência. Por exemplo, uma lista vinculada circular com três elementos tem um nó principal `N0`; esse nó contém um objeto `shared_ptr` que tem o próximo nó, `N1`; esse nó contém um objeto `shared_ptr` que tem o próximo nó, `N2`; esse nó, por sua vez, contém um objeto `shared_ptr` que tem o nó principal, `N0`, fechando o ciclo. Nessa situação, as contagens de referência nunca se tornam zero e os nós no ciclo nunca são liberados. Para eliminar o ciclo, o último nó `N2` deve conter um objeto `weak_ptr` apontando para `N0` em vez de um objeto `shared_ptr`. Como o `weak_ptr` objeto não é o proprietário `N0` dele não afeta `N0` a contagem de referência e quando a última referência do programa para o nó principal é destruída, os nós na lista também serão destruídos.

## <a name="members"></a>Membros

|Nome|Descrição|
|-|-|
| **Construtores** | |
|[weak_ptr](#weak_ptr)|Constrói um `weak_ptr`.|
| **Destruidores** | |
|[~ weak_ptr](#tilde-weak_ptr)|Constrói um `weak_ptr`.|
| **TYPEDEFs** | |
|[element_type](#element_type)|O tipo do elemento.|
| **Funções de membro** | |
|[vencer](#expired)|Testa se a propriedade expirou.|
|[proprietário](#lock)|Obtém a propriedade exclusiva de um recurso.|
|[owner_before](#owner_before)|Retorna **`true`** se isso `weak_ptr` é ordenado antes (ou menor que) o ponteiro fornecido.|
|[reset](#reset)|Libera o recurso possuído.|
|[permuta](#swap)|Troca dois objetos `weak_ptr`.|
|[use_count](#use_count)|Conta o número de `shared_ptr` objetos.|
| **Operadores** | |
|[operador =](#op_eq)|Substitui o recurso possuído.|

## <a name="element_type"></a><a name="element_type"></a> element_type

O tipo do elemento.

```cpp
typedef T element_type; // through C++17
using element_type = remove_extent_t<T>; // C++20
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `T`.

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_element_type.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp0(new int(5));
    std::weak_ptr<int> wp0(sp0);
    std::weak_ptr<int>::element_type val = *wp0.lock();

    std::cout << "*wp0.lock() == " << val << std::endl;

    return (0);
}
```

```Output
*wp0.lock() == 5
```

## <a name="expired"></a><a name="expired"></a> vencer

Testa se a propriedade expirou, ou seja, se o objeto referenciado foi excluído.

```cpp
bool expired() const noexcept;
```

### <a name="remarks"></a>Comentários

A função de membro retornará **`true`** se **`*this`** tiver expirado, caso contrário **`false`** .

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_expired.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::weak_ptr<int> wp;

    {
        std::shared_ptr<int> sp(new int(10));
        wp = sp;
        std::cout << "wp.expired() == " << std::boolalpha
            << wp.expired() << std::endl;
        std::cout << "*wp.lock() == " << *wp.lock() << std::endl;
    }

    // check expired after sp is destroyed
    std::cout << "wp.expired() == " << std::boolalpha
        << wp.expired() << std::endl;
    std::cout << "(bool)wp.lock() == " << std::boolalpha
        << (bool)wp.lock() << std::endl;

    return (0);
}
```

```Output
wp.expired() == false
*wp.lock() == 10
wp.expired() == true
(bool)wp.lock() == false
```

## <a name="lock"></a><a name="lock"></a> proprietário

Obtém um `shared_ptr` que compartilha a propriedade de um recurso.

```cpp
shared_ptr<T> lock() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro retornará um objeto [shared_ptr](shared-ptr-class.md) vazio **`*this`** , se tiver expirado; caso contrário, ele retornará um `shared_ptr<T>` objeto que possui o recurso que **`*this`** aponta para. Retorna um valor equivalente à execução atômica de `expired() ? shared_ptr<T>() : shared_ptr<T>(*this)` .

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_lock.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::weak_ptr<int> wp;

    {
        std::shared_ptr<int> sp(new int(10));
        wp = sp;
        std::cout << "wp.expired() == " << std::boolalpha
            << wp.expired() << std::endl;
        std::cout << "*wp.lock() == " << *wp.lock() << std::endl;
    }

    // check expired after sp is destroyed
    std::cout << "wp.expired() == " << std::boolalpha
        << wp.expired() << std::endl;
    std::cout << "(bool)wp.lock() == " << std::boolalpha
        << (bool)wp.lock() << std::endl;

    return (0);
}
```

```Output
wp.expired() == false
*wp.lock() == 10
wp.expired() == true
(bool)wp.lock() == false
```

## <a name="operator"></a><a name="op_eq"></a> operador =

Substitui o recurso possuído.

```cpp
weak_ptr& operator=(const weak_ptr& ptr) noexcept;

template <class Other>
weak_ptr& operator=(const weak_ptr<Other>& ptr) noexcept;

template <class Other>
weak_ptr& operator=(const shared_ptr<Other>& ptr) noexcept;
```

### <a name="parameters"></a>parâmetros

*Outros*\
O tipo controlado pelo argumento compartilhado ou ponteiro fraco.

*PTR*\
O ponteiro fraco ou o ponteiro compartilhado a ser copiado.

### <a name="remarks"></a>Comentários

Todos os operadores liberam o recurso atualmente apontado para **`*this`** e atribuem a propriedade do recurso chamado por *PTR* a **`*this`** . Se um operador falhar, ele deixará **`*this`** inalterado. Cada operador tem um efeito equivalente a `weak_ptr(ptr).swap(*this)` .

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_operator_as.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp0(new int(5));
    std::weak_ptr<int> wp0(sp0);
    std::cout << "*wp0.lock() == " << *wp0.lock() << std::endl;

    std::shared_ptr<int> sp1(new int(10));
    wp0 = sp1;
    std::cout << "*wp0.lock() == " << *wp0.lock() << std::endl;

    std::weak_ptr<int> wp1;
    wp1 = wp0;
    std::cout << "*wp1.lock() == " << *wp1.lock() << std::endl;

    return (0);
}
```

```Output
*wp0.lock() == 5
*wp0.lock() == 10
*wp1.lock() == 10
```

## <a name="owner_before"></a><a name="owner_before"></a> owner_before

Retorna **`true`** se isso `weak_ptr` é ordenado antes (ou menor que) o ponteiro fornecido.

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

A função de membro de modelo retorna **`true`** se **`*this`** é ordenada antes de *PTR*.

## <a name="reset"></a><a name="reset"></a> definido

Libera o recurso de propriedade.

```cpp
void reset() noexcept;
```

### <a name="remarks"></a>Comentários

A função membro libera o recurso apontado por **`*this`** e converte **`*this`** em um `weak_ptr` objeto vazio.

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_reset.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp(new int(5));
    std::weak_ptr<int> wp(sp);
    std::cout << "*wp.lock() == " << *wp.lock() << std::endl;
    std::cout << "wp.expired() == " << std::boolalpha
        << wp.expired() << std::endl;

    wp.reset();
    std::cout << "wp.expired() == " << std::boolalpha
        << wp.expired() << std::endl;

    return (0);
}
```

```Output
*wp.lock() == 5
wp.expired() == false
wp.expired() == true
```

## <a name="swap"></a><a name="swap"></a> permuta

Troca dois objetos `weak_ptr`.

```cpp
void swap(weak_ptr& wp) noexcept;
```

Também inclui a especialização:

```cpp
template<class T>
void swap(weak_ptr<T>& a, weak_ptr<T>& b) noexcept;
```

### <a name="parameters"></a>parâmetros

*processador*\
O ponteiro fraco pelo qual deve ser trocado.

### <a name="remarks"></a>Comentários

Após um `swap` , o recurso originalmente apontado por **`*this`** é apontado pelo *WP*e o recurso originalmente apontado pelo *WP* é apontado por **`*this`** . A função não altera as contagens de referência para os dois recursos e não lança nenhuma exceção. O efeito da especialização do modelo é o equivalente de `a.swap(b)` .

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_swap.cpp
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

## <a name="use_count"></a><a name="use_count"></a> use_count

Conta o número de `shared_ptr` objetos que possuem o recurso compartilhado.

```cpp
long use_count() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro retorna o número de `shared_ptr` objetos que possuem o recurso apontado por **`*this`** .

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_use_count.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp1(new int(5));
    std::weak_ptr<int> wp(sp1);
    std::cout << "wp.use_count() == "
        << wp.use_count() << std::endl;

    std::shared_ptr<int> sp2(sp1);
    std::cout << "wp.use_count() == "
        << wp.use_count() << std::endl;

    return (0);
}
```

```Output
wp.use_count() == 1
wp.use_count() == 2
```

## <a name="weak_ptr"></a><a name="weak_ptr"></a> weak_ptr

Constrói um `weak_ptr`.

```cpp
constexpr weak_ptr() noexcept;

weak_ptr(const weak_ptr& wp) noexcept;

weak_ptr(weak_ptr&& wp) noexcept;

template <class Other>
weak_ptr(const weak_ptr<Other>& wp) noexcept;

template <class Other>
weak_ptr(weak_ptr<Other>&& sp) noexcept;

template <class Other>
weak_ptr(const shared_ptr<Other>& sp) noexcept;
```

### <a name="parameters"></a>parâmetros

*Outros*\
O tipo controlado pelo ponteiro compartilhado/fraco do argumento. Esses construtores não participam da resolução de sobrecarga, a menos que _outros \* _ sejam compatíveis com `element_type*` .

*processador*\
O ponteiro fraco a ser copiado.

*SP3*\
O ponteiro compartilhado a ser copiado.

### <a name="remarks"></a>Comentários

O construtor padrão constrói um objeto vazio `weak_ptr` . Os construtores que usam um argumento cada constroem um objeto vazio `weak_ptr` se o ponteiro do argumento estiver vazio. Caso contrário, eles constroem um `weak_ptr` objeto que aponta para o recurso nomeado pelo argumento. A contagem de referência do objeto compartilhado não é alterada.

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_construct.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::weak_ptr<int> wp0;
    std::cout << "wp0.expired() == " << std::boolalpha
        << wp0.expired() << std::endl;

    std::shared_ptr<int> sp1(new int(5));
    std::weak_ptr<int> wp1(sp1);
    std::cout << "*wp1.lock() == "
        << *wp1.lock() << std::endl;

    std::weak_ptr<int> wp2(wp1);
    std::cout << "*wp2.lock() == "
        << *wp2.lock() << std::endl;

    return (0);
}
```

```Output
wp0.expired() == true
*wp1.lock() == 5
*wp2.lock() == 5
```

## <a name="weak_ptr"></a><a name="tilde-weak_ptr"></a> ~ weak_ptr

Destrói um `weak_ptr`.

```cpp
~weak_ptr();
```

### <a name="remarks"></a>Comentários

O destruidor destrói isso `weak_ptr` , mas não tem efeito sobre a contagem de referência do objeto apontado pelo ponteiro armazenado.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](cpp-standard-library-header-files.md)\
[\<memory>](memory.md)\
[Classe shared_ptr](shared-ptr-class.md)
