---
title: Funções &lt;type_traits&gt;
ms.date: 11/04/2016
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
ms.openlocfilehash: bc25c82629139c5bc2f6fa53d3555068374dca35
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367994"
---
# <a name="lttype_traitsgt-functions"></a>Funções &lt;type_traits&gt;

||||
|-|-|-|
|[is_assignable](#is_assignable)|[is_copy_assignable](#is_copy_assignable)|[is_copy_constructible](#is_copy_constructible)|
|[is_default_constructible](#is_default_constructible)|[is_move_assignable](#is_move_assignable)|[is_move_constructible](#is_move_constructible)|
|[is_nothrow_move_assignable](#is_nothrow_move_assignable)|[is_nothrow_swappable](#is_nothrow_swappable)|[is_nothrow_swappable_with](#is_nothrow_swappable_with)|
|[is_swappable](#is_swappable)|[is_swappable_with](#is_swappable_with)|[is_trivially_copy_assignable](#is_trivially_copy_assignable)|
|[is_trivially_move_assignable](#is_trivially_move_assignable)|[is_trivially_move_constructible](#is_trivially_move_constructible)|

## <a name="is_assignable"></a><a name="is_assignable"></a>is_assignable

Testa se um valor de *De* tipo pode ser atribuído a um *tipo Para.*

```cpp
template <class To, class From>
struct is_assignable;
```

### <a name="parameters"></a>Parâmetros

*Para*\
O tipo do objeto que recebe a atribuição.

*De*\
O tipo do objeto que fornece o valor.

### <a name="remarks"></a>Comentários

A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formada. *Tanto de e* para *dono* devem ser tipos completos, **vazios**ou matrizes de limite desconhecido.

## <a name="is_copy_assignable"></a><a name="is_copy_assignable"></a>is_copy_assignable

Teste se o tipo pode ser copiado na atribuição.

```cpp
template <class Ty>
struct is_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado do tipo é verdadeira se o tipo *Ty* é uma classe que tem um operador de atribuição de cópia, caso contrário ele contém falso. Equivalente a is_assignable\<Ty&, const Ty&>.

## <a name="is_copy_constructible"></a><a name="is_copy_constructible"></a>is_copy_constructible

Testa se o tipo tem um construtor de cópia.

```cpp
template <class Ty>
struct is_copy_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado do tipo é verdadeira se o tipo *Ty* é uma classe que tem um construtor de cópias, caso contrário ele contém falso.

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

## <a name="is_default_constructible"></a><a name="is_default_constructible"></a>is_default_constructible

Testa se o tipo tem um construtor padrão.

```cpp
template <class Ty>
struct is_default_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado do tipo é verdadeira se o tipo *T* é um tipo de classe que tem um construtor padrão, caso contrário ele contém falso. Isso é equivalente ao predicado `is_constructible<T>`. O tipo *T* deve ser um tipo completo, **vazio**ou uma matriz de limite desconhecido.

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

## <a name="is_move_assignable"></a><a name="is_move_assignable"></a>is_move_assignable

Testa se o tipo pode ser atribuído a uma movimentação.

```cpp
template <class T>
struct is_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Um tipo poderá ser atribuído a uma movimentação se uma referência rvalue ao tipo puder ser atribuída a uma referência ao tipo. O predicado de tipo é equivalente a `is_assignable<T&, T&&>`. Tipos atribuíveis a movimentação incluem tipos escalares referenciáveis e tipos de classe que tenham operadores de atribuição de movimentação definidos pelo usuário ou gerados pelo compilador.

## <a name="is_move_constructible"></a><a name="is_move_constructible"></a>is_move_constructible

Testa se o tipo tem um construtor de movimentação.

```cpp
template <class T>
struct is_move_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser avaliado

### <a name="remarks"></a>Comentários

Um predicado de tipo que avalia a verdade se o tipo *T* pode ser construído usando uma operação de movimento. Esse predicado é equivalente a `is_constructible<T, T&&>`.

## <a name="is_nothrow_move_assignable"></a><a name="is_nothrow_move_assignable"></a>is_nothrow_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação **nothrow**.

```cpp
template <class Ty>
struct is_nothrow_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado do tipo é verdadeira se o tipo *Ty* tiver um operador de atribuição de movimento nothrow, caso contrário, ele contém falso.

## <a name="is_nothrow_swappable"></a><a name="is_nothrow_swappable"></a>is_nothrow_swappable

```cpp
template <class T> struct is_nothrow_swappable;
```

## <a name="is_nothrow_swappable_with"></a><a name="is_nothrow_swappable_with"></a>is_nothrow_swappable_with

```cpp
template <class T, class U> struct is_nothrow_swappable_with;
```

## <a name="is_swappable"></a><a name="is_swappable"></a>is_swappable

```cpp
template <class T> struct is_swappable;
```

## <a name="is_swappable_with"></a><a name="is_swappable_with"></a>is_swappable_with

```cpp
template <class T, class U> struct is_swappable_with;
```

## <a name="is_trivially_copy_assignable"></a><a name="is_trivially_copy_assignable"></a>is_trivially_copy_assignable

Testa se o tipo tem uma cópia trivial do operador de atribuição.

```cpp
template <class Ty>
struct is_trivially_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado do tipo é verdadeira se o tipo *T* é uma classe que tem um operador de atribuição de cópia trivial, caso contrário, ele contém falso.

Um construtor de atribuição para uma classe *T* é trivial se for fornecido implicitamente, a classe *T* não tem funções virtuais, a classe *T* não tem bases virtuais, as classes de todos os membros de dados não estáticos do tipo de classe têm operadores de atribuição triviais, e as classes de todos os membros de dados não estáticos da classe tipo matriz de classe têm operadores de atribuição triviais.

## <a name="is_trivially_move_assignable"></a><a name="is_trivially_move_assignable"></a>is_trivially_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação trivial.

```cpp
template <class Ty>
struct is_trivially_move_assignable;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado do tipo é verdadeira se o tipo *Ty* é uma classe que tem um operador de atribuição de movimento trivial, caso contrário ele mantém falso.

Um operador de atribuição de movimento para uma classe *Ty* é trivial se:

for fornecido implicitamente

a classe *Ty* não tem funções virtuais

a classe *Ty* não tem bases virtuais

as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo da classe tiverem operadores de atribuição de movimentação trivial

## <a name="is_trivially_move_constructible"></a><a name="is_trivially_move_constructible"></a>is_trivially_move_constructible

Testa se o tipo tem construtor de movimentação trivial.

```cpp
template <class Ty>
struct is_trivially_move_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado do tipo é verdadeira se o tipo *Ty* é uma classe que tem um construtor de movimento trivial, caso contrário ele mantém falso.

Um construtor de movimentos para uma classe *Ty* é trivial se:

for implicitamente declarado

seus tipos de parâmetro forem equivalentes aos de uma declaração implícita

a classe *Ty* não tem funções virtuais

a classe *Ty* não tem bases virtuais

a classe não tiver membros de dados não estáticos voláteis

todas as bases diretas da classe *Ty* têm construtores movimento trivial

as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores de movimentação trivial

## <a name="see-also"></a>Confira também

[>type_traits<](../standard-library/type-traits.md)
