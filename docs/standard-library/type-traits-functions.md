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
ms.openlocfilehash: 11defadff0b1785f6e4c5aba6356f7b68a78b9fc
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841773"
---
# <a name="lttype_traitsgt-functions"></a>Funções &lt;type_traits&gt;

[is_assignable](#is_assignable)\
[is_copy_assignable](#is_copy_assignable)\
[is_copy_constructible](#is_copy_constructible)\
[is_default_constructible](#is_default_constructible)\
[is_move_assignable](#is_move_assignable)\
[is_move_constructible](#is_move_constructible)\
[is_nothrow_move_assignable](#is_nothrow_move_assignable)\
[is_nothrow_swappable](#is_nothrow_swappable)\
[is_nothrow_swappable_with](#is_nothrow_swappable_with)\
[is_swappable](#is_swappable)\
[is_swappable_with](#is_swappable_with)\
[is_trivially_copy_assignable](#is_trivially_copy_assignable)\
[is_trivially_move_assignable](#is_trivially_move_assignable)\
[is_trivially_move_constructible](#is_trivially_move_constructible)

## <a name="is_assignable"></a><a name="is_assignable"></a> is_assignable

Testa se um valor do tipo *from* pode ser atribuído a um tipo *to* .

```cpp
template <class To, class From>
struct is_assignable;
```

### <a name="parameters"></a>parâmetros

*Para*\
O tipo do objeto que recebe a atribuição.

*De*\
O tipo do objeto que fornece o valor.

### <a name="remarks"></a>Comentários

A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formada. Tanto *de* e *para* devem ser tipos completos, **`void`** , ou matrizes de associação desconhecida.

## <a name="is_copy_assignable"></a><a name="is_copy_assignable"></a> is_copy_assignable

Teste se o tipo pode ser copiado na atribuição.

```cpp
template <class Ty>
struct is_copy_assignable;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um operador de atribuição de cópia, caso contrário, ela mantém false. Equivalente a is_assignable \<Ty&, const Ty&> .

## <a name="is_copy_constructible"></a><a name="is_copy_constructible"></a> is_copy_constructible

Testa se o tipo tem um construtor de cópia.

```cpp
template <class Ty>
struct is_copy_constructible;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um construtor de cópia, caso contrário, ela mantém false.

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

## <a name="is_default_constructible"></a><a name="is_default_constructible"></a> is_default_constructible

Testa se o tipo tem um construtor padrão.

```cpp
template <class Ty>
struct is_default_constructible;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo fica true se o tipo *T* é um tipo de classe que tem um construtor padrão, caso contrário, ele mantém false. Isso é equivalente ao predicado `is_constructible<T>`. O tipo *T* deve ser um tipo completo, **`void`** ou uma matriz de limite desconhecido.

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

## <a name="is_move_assignable"></a><a name="is_move_assignable"></a> is_move_assignable

Testa se o tipo pode ser atribuído a uma movimentação.

```cpp
template <class T>
struct is_move_assignable;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Um tipo poderá ser atribuído a uma movimentação se uma referência rvalue ao tipo puder ser atribuída a uma referência ao tipo. O predicado de tipo é equivalente a `is_assignable<T&, T&&>`. Tipos atribuíveis a movimentação incluem tipos escalares referenciáveis e tipos de classe que tenham operadores de atribuição de movimentação definidos pelo usuário ou gerados pelo compilador.

## <a name="is_move_constructible"></a><a name="is_move_constructible"></a> is_move_constructible

Testa se o tipo tem um construtor de movimentação.

```cpp
template <class T>
struct is_move_constructible;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser avaliado

### <a name="remarks"></a>Comentários

Um predicado de tipo que será avaliado como true se o tipo *T* puder ser construído usando uma operação de movimentação. Esse predicado é equivalente a `is_constructible<T, T&&>`.

## <a name="is_nothrow_move_assignable"></a><a name="is_nothrow_move_assignable"></a> is_nothrow_move_assignable

Testa se o tipo tem um **`nothrow`** operador de atribuição de movimentação.

```cpp
template <class Ty>
struct is_nothrow_move_assignable;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* tiver um operador de atribuição de movimentação nothrow; caso contrário, ele será false.

## <a name="is_nothrow_swappable"></a><a name="is_nothrow_swappable"></a> is_nothrow_swappable

```cpp
template <class T> struct is_nothrow_swappable;
```

## <a name="is_nothrow_swappable_with"></a><a name="is_nothrow_swappable_with"></a> is_nothrow_swappable_with

```cpp
template <class T, class U> struct is_nothrow_swappable_with;
```

## <a name="is_swappable"></a><a name="is_swappable"></a> is_swappable

```cpp
template <class T> struct is_swappable;
```

## <a name="is_swappable_with"></a><a name="is_swappable_with"></a> is_swappable_with

```cpp
template <class T, class U> struct is_swappable_with;
```

## <a name="is_trivially_copy_assignable"></a><a name="is_trivially_copy_assignable"></a> is_trivially_copy_assignable

Testa se o tipo tem uma cópia trivial do operador de atribuição.

```cpp
template <class Ty>
struct is_trivially_copy_assignable;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo fica true se o tipo *T* é uma classe que tem um operador de atribuição de cópia trivial, caso contrário, ela mantém false.

Um construtor de atribuição para uma classe *t* é trivial se for fornecido implicitamente, a classe *t* não tem nenhuma função virtual, a classe *t* não tem bases virtuais, as classes de todos os membros de dados não estáticos do tipo de classe têm operadores de atribuição triviais, e as classes de todos os membros de dados não estáticos do tipo matriz de classe têm operadores de atribuição trivial.

## <a name="is_trivially_move_assignable"></a><a name="is_trivially_move_assignable"></a> is_trivially_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação trivial.

```cpp
template <class Ty>
struct is_trivially_move_assignable;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um operador de atribuição de movimento trivial, caso contrário, ela mantém false.

Um operador de atribuição de movimentação para uma classe *Ty* é trivial se:

for fornecido implicitamente

a classe *Ty* não tem nenhuma função virtual

a classe *Ty* não tem bases virtuais

as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo da classe tiverem operadores de atribuição de movimentação trivial

## <a name="is_trivially_move_constructible"></a><a name="is_trivially_move_constructible"></a> is_trivially_move_constructible

Testa se o tipo tem construtor de movimentação trivial.

```cpp
template <class Ty>
struct is_trivially_move_constructible;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser consultado.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um construtor de movimentação trivial, caso contrário, ela mantém false.

Um construtor de movimentação para uma classe *Ty* é trivial se:

for implicitamente declarado

seus tipos de parâmetro forem equivalentes aos de uma declaração implícita

a classe *Ty* não tem nenhuma função virtual

a classe *Ty* não tem bases virtuais

a classe não tiver membros de dados não estáticos voláteis

todas as bases diretas da classe *Ty* têm construtores de movimentação trivial

as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores de movimentação trivial

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
