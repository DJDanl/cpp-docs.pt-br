---
title: Classe weak_ptr
ms.date: 11/04/2016
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
ms.openlocfilehash: e2efb5d534ad43e2492ac4fb0bf76db402dca272
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410844"
---
# <a name="weakptr-class"></a>Classe weak_ptr

Encapsula um ponteiro vinculado de modo fraco.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _Ty>
   class weak_ptr {
public:
   typedef Ty element_type;
   weak_ptr();
   weak_ptr(const weak_ptr&);
   template <class Other>
      weak_ptr(const weak_ptr<Other>&);
   template <class Other>
      weak_ptr(const shared_ptr<Other>&);
   weak_ptr& operator=(const weak_ptr&);
   template <class Other>
      weak_ptr& operator=(const weak_ptr<Other>&);
   template <class Other>
      weak_ptr& operator=(shared_ptr<Other>&);
   void swap(weak_ptr&);
   void reset();
   long use_count() const;
   bool expired() const;
   shared_ptr<Ty> lock() const;
   };
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo controlado pelo ponteiro fraco.

## <a name="remarks"></a>Comentários

A classe de modelo descreve um objeto que aponta para um recurso gerenciado por um ou mais objetos da [Classe shared_ptr](../standard-library/shared-ptr-class.md). Os objetos `weak_ptr` que apontam para um recurso não afetam a contagem de referência do recurso. Dessa forma, quando o último objeto `shared_ptr` que gerencia esse recurso for destruído, os recursos serão liberados, mesmo se houver objetos `weak_ptr` apontando para esse recurso. Isso é essencial para evitar ciclos em estruturas de dados.

O objeto `weak_ptr` aponta para um recurso se ele foi construído com base em um objeto `shared_ptr` que tem esse recurso, se ele foi construído com base em um objeto `weak_ptr` que aponta para esse recurso ou se esse recurso foi atribuído a ele com [operator=](#op_eq). Um objeto `weak_ptr` não fornece acesso direto ao recurso para o qual ele aponta. O código que precisa usar o recurso faz isso por meio de um objeto `shared_ptr` que tem esse recurso, criado chamando a função membro [lock](#lock). Um objeto `weak_ptr` expirou quando o recurso para o qual ele aponta foi liberado porque todos os objetos `shared_ptr` que têm o recurso foram destruídos. Chamar `lock` em um objeto `weak_ptr` que expirou cria um objeto shared_ptr vazio.

Um objeto weak_ptr vazio não aponta para nenhum recurso e não tem nenhum bloco de controle. Sua função membro `lock` retorna um objeto shared_ptr vazio.

Um ciclo ocorre quando dois ou mais recursos controlados por objetos `shared_ptr` contêm mutuamente objetos `shared_ptr` de referência. Por exemplo, uma lista vinculada circular com três elementos tem um nó principal `N0`; esse nó contém um objeto `shared_ptr` que tem o próximo nó, `N1`; esse nó contém um objeto `shared_ptr` que tem o próximo nó, `N2`; esse nó, por sua vez, contém um objeto `shared_ptr` que tem o nó principal, `N0`, fechando o ciclo. Nessa situação, nenhuma das contagens de referência se tornará zero e os nós no ciclo não serão liberados. Para eliminar o ciclo, o último nó `N2` deve conter um objeto `weak_ptr` apontando para `N0` em vez de um objeto `shared_ptr`. Uma vez que o objeto `weak_ptr` não tem `N0`, ele não afeta a contagem de referência de `N0` e quando a última referência do programa ao nó principal for destruída, os nós na lista também serão destruídos.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[weak_ptr](#weak_ptr)|Constrói um `weak_ptr`.|

### <a name="methods"></a>Métodos

|||
|-|-|
|[element_type](#element_type)|O tipo do elemento.|
|[expired](#expired)|Testa se a propriedade expirou.|
|[lock](#lock)|Obtém a propriedade exclusiva de um recurso.|
|[owner_before](#owner_before)|Retorna **verdadeira** se este `weak_ptr` é ordenado antes (ou menor que) ponteiro fornecido.|
|[reset](#reset)|Libera o recurso possuído.|
|[swap](#swap)|Troca dois objetos `weak_ptr`.|
|[use_count](#use_count)|Conta o número de objetos `shared_ptr` designados.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Substitui o recurso possuído.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<memory>

**Namespace:** std

## <a name="element_type"></a>  element_type

O tipo do elemento.

```cpp
typedef Ty element_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Ty`.

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

## <a name="expired"></a> expired

Testa se a propriedade expirou.

```cpp
bool expired() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna **verdadeira** se `*this` tiver expirado, caso contrário **false**.

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_expired.cpp
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

## <a name="lock"></a>  lock

Obtém a propriedade exclusiva de um recurso.

```cpp
shared_ptr<Ty> lock() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna um objeto shared_ptr vazio se `*this` tiver expirado; caso contrário, retornará um [classe shared_ptr](../standard-library/shared-ptr-class.md)\<Ty > objeto que possui o recurso que `*this` aponta.

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_lock.cpp
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

## <a name="op_eq"></a>  operator=

Substitui o recurso possuído.

```cpp
weak_ptr& operator=(const weak_ptr& wp);

template <class Other>
weak_ptr& operator=(const weak_ptr<Other>& wp);

template <class Other>
weak_ptr& operator=(const shared_ptr<Other>& sp);
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
O tipo controlado pelo ponteiro compartilhado/fraco do argumento.

*wp*<br/>
O ponteiro fraco a ser copiado.

*sp*<br/>
O ponteiro compartilhado a ser copiado.

### <a name="remarks"></a>Comentários

Todos os operadores liberam o recurso apontado no momento por `*this` e atribuem a propriedade do recurso nomeada pela sequência de operandos a `*this`. Se um operador falhar, `*this` permanecerá inalterado.

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

## <a name="owner_before"></a> owner_before

Retorna **verdadeira** se este `weak_ptr` é ordenado antes (ou menor que) ponteiro fornecido.

```cpp
template <class Other>
bool owner_before(const shared_ptr<Other>& ptr);

template <class Other>
bool owner_before(const weak_ptr<Other>& ptr);
```

### <a name="parameters"></a>Parâmetros

*ptr*<br/>
Uma referência de `lvalue` a um `shared_ptr` ou um `weak_ptr`.

### <a name="remarks"></a>Comentários

A função de membro de modelo retorna **verdadeira** se `*this` é `ordered before` `ptr`.

## <a name="reset"></a> reset

Libera o recurso possuído.

```cpp
void reset();
```

### <a name="remarks"></a>Comentários

A função membro libera o recurso apontado por `*this` e converte `*this` em um objeto weak_ptr vazio.

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

## <a name="swap"></a>  swap

Troca dois objetos `weak_ptr`.

```cpp
void swap(weak_ptr& wp);
```

### <a name="parameters"></a>Parâmetros

*wp*<br/>
O ponteiro fraco pelo qual deve ser trocado.

### <a name="remarks"></a>Comentários

A função membro deixa o recurso originalmente apontado por `*this` subsequentemente apontado por *wp*e o recurso originalmente apontado por *wp* subsequentemente apontado por `*this`. A função não altera as contagens de referências dos dois recursos e ela não gera nenhuma exceção.

### <a name="example"></a>Exemplo

```cpp
// std__memory__weak_ptr_swap.cpp
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

## <a name="use_count"></a> use_count

Conta o número de objetos `shared_ptr` designados.

```cpp
long use_count() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o número de objetos `shared_ptr` que tem do recurso apontado por `*this`.

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

## <a name="weak_ptr"></a> weak_ptr

Constrói um `weak_ptr`.

```cpp
weak_ptr();

weak_ptr(const weak_ptr& wp);

template <class Other>
weak_ptr(const weak_ptr<Other>& wp);

template <class Other>
weak_ptr(const shared_ptr<Other>& sp);
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
O tipo controlado pelo ponteiro compartilhado/fraco do argumento.

*wp*<br/>
O ponteiro fraco a ser copiado.

*sp*<br/>
O ponteiro compartilhado a ser copiado.

### <a name="remarks"></a>Comentários

Cada um dos construtores constroem um objeto que aponta para o recurso nomeado pela sequência de operandos.

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

## <a name="see-also"></a>Consulte também

[Classe shared_ptr](../standard-library/shared-ptr-class.md)<br/>
