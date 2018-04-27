---
title: Funções &lt;type_traits&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
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
caps.latest.revision: 13
manager: ghogen
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
ms.openlocfilehash: 1d2db7b749bfc4266a613b872e32965ff16a4c4c
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="lttypetraitsgt-functions"></a>Funções &lt;type_traits&gt;

||||
|-|-|-|
|[is_assignable](#is_assignable)|[is_copy_assignable](#is_copy_assignable)|[is_copy_constructible](#is_copy_constructible)|
|[is_default_constructible](#is_default_constructible)|[is_move_assignable](#is_move_assignable)|[is_move_constructible](#is_move_constructible)|
|[is_nothrow_move_assignable](#is_nothrow_move_assignable)|[is_trivially_copy_assignable](#is_trivially_copy_assignable)|[is_trivially_move_assignable](#is_trivially_move_assignable)|
|[is_trivially_move_constructible](#is_trivially_move_constructible)|

## <a name="is_assignable"></a> is_assignable

Testa se um valor do tipo `From` pode ser atribuído a um tipo `To`.

```cpp
template <class To, class From>
struct is_assignable;
```

### <a name="parameters"></a>Parâmetros

Para o tipo do objeto que recebe a atribuição.

O tipo de objeto que fornece o valor.

### <a name="remarks"></a>Comentários

A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formada. `From` e `To` devem ser tipos completos, `void` ou matrizes de limite desconhecido.

## <a name="is_copy_assignable"></a> is_copy_assignable

Teste se o tipo pode ser copiado na atribuição.

```cpp
template <class Ty>
struct is_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe com um operador de atribuição de cópia; caso contrário, será falsa. Equivalente a is_assignable\<Ty&, const Ty&>.

## <a name="is_copy_constructible"></a> is_copy_constructible

Testa se o tipo tem um construtor de cópia.

```cpp
template <class Ty>
struct is_copy_constructible;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe que tem um construtor de cópia, caso contrário, será falsa.

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

`T` O tipo de consulta.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `T` for um tipo de classe que tem um construtor padrão; caso contrário, será falsa. Isso é equivalente ao predicado `is_constructible<T>`. O tipo de `T` deve ser um tipo completo, `void` ou uma matriz de limite desconhecido.

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

`T` O tipo de consulta.

### <a name="remarks"></a>Comentários

Um tipo poderá ser atribuído a uma movimentação se uma referência rvalue ao tipo puder ser atribuída a uma referência ao tipo. O predicado de tipo é equivalente a `is_assignable<T&, T&&>`. Tipos atribuíveis a movimentação incluem tipos escalares referenciáveis e tipos de classe que tenham operadores de atribuição de movimentação definidos pelo usuário ou gerados pelo compilador.

## <a name="is_move_constructible"></a> is_move_constructible

Testa se o tipo tem um construtor de movimentação.

```cpp
template <class T>
struct is_move_constructible;
```

### <a name="parameters"></a>Parâmetros

O tipo de T a ser avaliada

### <a name="remarks"></a>Comentários

Um predicado de tipo será avaliado como verdadeiro se o tipo `T` puder ser construído usando uma operação de movimentação. Esse predicado é equivalente a `is_constructible<T, T&&>`.

## <a name="is_nothrow_move_assignable"></a> is_nothrow_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação **nothrow**.

```cpp
template <class Ty>
struct is_nothrow_move_assignable;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `Ty` tiver um operador atribuição de movimento nothrow; caso contrário, será falsa.

## <a name="is_trivially_copy_assignable"></a> is_trivially_copy_assignable

Testa se o tipo tem uma cópia trivial do operador de atribuição.

```cpp
template <class Ty>
struct is_trivially_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

`T` O tipo de consulta.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `T` for uma classe que tem um operador de atribuição de cópia trivial; caso contrário, será falsa.

Um construtor de atribuição para uma classe `T` será trivial se for implicitamente fornecido, a classe `T` não tiver funções virtuais, a classe `T` não tiver bases virtuais, as classes de todos os membros de dados não estáticos de tipo de classe tiverem operadores de atribuição triviais e as classes de todos os membros de dados não estáticos de matriz de tipo de classe tiverem operadores de atribuição trivial.

## <a name="is_trivially_move_assignable"></a> is_trivially_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação trivial.

```cpp
template <class Ty>
struct is_trivially_move_assignable;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe com um operador de atribuição de movimentação trivial; caso contrário, será falsa.

Um operador de atribuição de movimentação para uma classe `Ty` será trivial se:

for fornecido implicitamente

a classe `Ty` não tiver funções virtuais

a classe `Ty` não tiver bases virtuais

as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo da classe tiverem operadores de atribuição de movimentação trivial

## <a name="is_trivially_move_constructible"></a> is_trivially_move_constructible

Testa se o tipo tem construtor de movimentação trivial.

```cpp
template <class Ty>
struct is_trivially_move_constructible;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

### <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe que tem um construtor de movimentação trivial; caso contrário, será falsa.

Um construtor de movimentação de uma classe `Ty` será trivial se:

for implicitamente declarado

seus tipos de parâmetro forem equivalentes aos de uma declaração implícita

a classe `Ty` não tiver funções virtuais

a classe `Ty` não tiver bases virtuais

a classe não tiver membros de dados não estáticos voláteis

todas as bases diretas da classe `Ty` tiverem construtores de movimentação trivial

as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores de movimentação trivial

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
