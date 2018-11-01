---
title: Funções &lt;type_traits&gt;
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_assignable
- type_traits/std::is_copy_assignable
- type_traits/std::is_copy_constructible
- type_traits/std::is_default_constructible
- type_traits/std::is_move_assignable
- type_traits/std::is_move_constructible
- type_traits/std::is_nothrow_move_assignable
- type_traits/std::is_trivially_copy_assignable
- type_traits/std::is_trivially_move_assignable
- type_traits/std::is_trivially_move_constructible
ms.assetid: dce4492f-f3e4-4d5e-bdb4-5875321254ec
helpviewer_keywords:
- std::is_assignable
- std::is_copy_assignable
- std::is_copy_constructible
- std::is_default_constructible
- std::is_move_assignable
- std::is_move_constructible
- std::is_nothrow_move_assignable
- std::is_trivially_copy_assignable
- std::is_trivially_move_assignable
- std::is_trivially_move_constructible
ms.openlocfilehash: 05e72f07117cd5317dd0b8ea3590be9e87ae7b6d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50653616"
---
# <a name="lttypetraitsgt-functions"></a>Funções &lt;type_traits&gt;

||||
|-|-|-|
|[is_assignable](#is_assignable)|[is_copy_assignable](#is_copy_assignable)|[is_copy_constructible](#is_copy_constructible)|
|[is_default_constructible](#is_default_constructible)|[is_move_assignable](#is_move_assignable)|[is_move_constructible](#is_move_constructible)|
|[is_nothrow_move_assignable](#is_nothrow_move_assignable)|[is_trivially_copy_assignable](#is_trivially_copy_assignable)|[is_trivially_move_assignable](#is_trivially_move_assignable)|
|[is_trivially_move_constructible](#is_trivially_move_constructible)|

## <a name="is_assignable"></a> is_assignable

Testa se um valor de *partir* tipo pode ser atribuído a um *para* tipo.

```cpp
template <class To, class From>
struct is_assignable;
```

### <a name="parameters"></a>Parâmetros

*To*<br/>
O tipo do objeto que recebe a atribuição.

*From*<br/>
O tipo do objeto que fornece o valor.

### <a name="remarks"></a>Comentários

A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formada. Ambos *partir* e *à* devem ser tipos completos, **void**, ou matrizes de limite desconhecido.

## <a name="is_copy_assignable"></a> is_copy_assignable

Teste se o tipo pode ser copiado na atribuição.

```cpp
template <class Ty>
struct is_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* é uma classe que tem um operador de atribuição, caso contrário, será falsa. Equivalente a is_assignable\<Ty&, const Ty&>.

## <a name="is_copy_constructible"></a> is_copy_constructible

Testa se o tipo tem um construtor de cópia.

```cpp
template <class Ty>
struct is_copy_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* é uma classe que tem um construtor de cópia, caso contrário, será falsa.

### <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

struct Copyable
{
    int val;
};

struct NotCopyable
{
   NotCopyable(const NotCopyable&) = delete;
   int val;

};

int main()
{
    std::cout << "is_copy_constructible<Copyable> == " << std::boolalpha
        << std::is_copy_constructible<Copyable>::value << std::endl;
    std::cout << "is_copy_constructible<NotCopyable> == " << std::boolalpha
        << std::is_copy_constructible<NotCopyable>::value << std::endl;

    return (0);
}

```

```Output
is_copy_constructible<Copyable> == true
is_copy_constructible<NotCopyable > == false
```

## <a name="is_default_constructible"></a> is_default_constructible

Testa se o tipo tem um construtor padrão.

```cpp
template <class Ty>
struct is_default_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é um tipo de classe que tem um construtor padrão, caso contrário, será falsa. Isso é equivalente ao predicado `is_constructible<T>`. Tipo de *T* deve ser um tipo completo, **void**, ou uma matriz de limite desconhecido.

### <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

struct Simple
{
    Simple() : val(0) {}
    int val;
};

struct Simple2
{
    Simple2(int v) : val(v) {}
    int val;
};

int main()
{
    std::cout << "is_default_constructible<Simple> == " << std::boolalpha
        << std::is_default_constructible<Simple>::value << std::endl;
    std::cout << "is_default_constructible<Simple2> == " << std::boolalpha
        << std::is_default_constructible<Simple2>::value << std::endl;

    return (0);
}

```

```Output
is_default_constructible<Simple> == true
is_default_constructible<Simple2> == false
```

## <a name="is_move_assignable"></a> is_move_assignable

Testa se o tipo pode ser atribuído a uma movimentação.

```cpp
template <class T>
struct is_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Um tipo poderá ser atribuído a uma movimentação se uma referência rvalue ao tipo puder ser atribuída a uma referência ao tipo. O predicado de tipo é equivalente a `is_assignable<T&, T&&>`. Tipos atribuíveis a movimentação incluem tipos escalares referenciáveis e tipos de classe que tenham operadores de atribuição de movimentação definidos pelo usuário ou gerados pelo compilador.

## <a name="is_move_constructible"></a> is_move_constructible

Testa se o tipo tem um construtor de movimentação.

```cpp
template <class T>
struct is_move_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser avaliado

### <a name="remarks"></a>Comentários

Um predicado de tipo que é avaliada como true se o tipo *T* podem ser construídos por meio de uma operação de movimentação. Esse predicado é equivalente a `is_constructible<T, T&&>`.

## <a name="is_nothrow_move_assignable"></a> is_nothrow_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação **nothrow**.

```cpp
template <class Ty>
struct is_nothrow_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* tem um nothrow mover operador de atribuição, caso contrário, será falsa.

## <a name="is_trivially_copy_assignable"></a> is_trivially_copy_assignable

Testa se o tipo tem uma cópia trivial do operador de atribuição.

```cpp
template <class Ty>
struct is_trivially_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é uma classe que tem um cópia trivial operador de atribuição, caso contrário, será falsa.

Um construtor de atribuição para uma classe *T* será trivial se for implicitamente fornecido, a classe *T* não tiver funções virtuais, a classe *T* não tiver bases virtuais, as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição triviais e as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem operadores de atribuição trivial.

## <a name="is_trivially_move_assignable"></a> is_trivially_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação trivial.

```cpp
template <class Ty>
struct is_trivially_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* é uma classe que tem um movimentação trivial operador de atribuição, caso contrário, será falsa.

Um operador de atribuição de movimentação para uma classe *Ty* é trivial se:

for fornecido implicitamente

a classe *Ty* não tiver funções virtuais

a classe *Ty* não tiver bases virtuais

as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo da classe tiverem operadores de atribuição de movimentação trivial

## <a name="is_trivially_move_constructible"></a> is_trivially_move_constructible

Testa se o tipo tem construtor de movimentação trivial.

```cpp
template <class Ty>
struct is_trivially_move_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* é uma classe que tem um construtor de movimentação trivial caso contrário, será falsa.

Um construtor de movimentação de uma classe *Ty* é trivial se:

for implicitamente declarado

seus tipos de parâmetro forem equivalentes aos de uma declaração implícita

a classe *Ty* não tiver funções virtuais

a classe *Ty* não tiver bases virtuais

a classe não tiver membros de dados não estáticos voláteis

todas as bases diretas da classe *Ty* tiverem construtores de movimentação trivial

as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores de movimentação trivial

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
