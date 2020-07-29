---
title: Classe Variant
ms.date: 04/04/2019
f1_keywords:
- variant/std::variant
- variant/std::variant::emplace
- variant/std::variant::index
- variant/std::variant::valueless_by_exception
helpviewer_keywords:
- variant/std::variant
- variant/std::variant::emplace
- variant/std::variant::index
- variant/std::variant::valueless_by_exception
ms.openlocfilehash: e34704b0ad8cf8fbaf8ee9514583f9597be40122
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215394"
---
# <a name="variant-class"></a>Classe Variant

Qualquer instância de Variant em um determinado momento mantém um valor de um de seus tipos alternativos ou não contém nenhum valor.

## <a name="syntax"></a>Sintaxe

```cpp
template <class... Types>
    class variant
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[variant](#variant)|Constrói um objeto do tipo `variant`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[emplace](#emplace)|Cria um novo valor contido.|
|[index](#index)|Retorna o índice de um valor contido.|
|[permuta](#swap)||
|[valueless_by_exception](#emplace)|Retorna **`false`** se a variante contém um valor.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#op_eq)|Substitui a variante por uma cópia de outra variante.|

## <a name="emplace"></a><a name="emplace"></a>emplace

Cria um novo valor contido.

```cpp
template <class T, class... Args>
    T& emplace(Args&&...);
template <class T, class U, class... Args>
    T& emplace(initializer_list<U>, Args&&...);
template <size_t I, class... Args>
    variant_alternative_t<I, variant<Types...>>& emplace(Args&&...);
template <size_t I, class U, class... Args>
    variant_alternative_t<I, variant<Types...>>& emplace(initializer_list<U>, Args&&...);
```

## <a name="index"></a><a name="index"></a>index

Retorna o índice de um valor contido.

```cpp
constexpr size_t index() const noexcept;
```

## <a name="variant"></a><a name="variant"></a>variante

Constrói um objeto do tipo `variant`. Também inclui um destruidor.

```cpp
constexpr variant() noexcept(see below);
variant(const variant&);
variant(variant&&) noexcept(see below);
template <class T>
    constexpr variant(T&&) noexcept(see below);
template <class T, class... Args>
    constexpr explicit variant(in_place_type_t<T>, Args&&...);
template <class T, class U, class... Args>
    constexpr explicit variant(in_place_type_t<T>, initializer_list<U>, Args&&...);
template <size_t I, class... Args>
    constexpr explicit variant(in_place_index_t<I>, Args&&...);
template <size_t I, class U, class... Args>
    constexpr explicit variant(in_place_index_t<I>, initializer_list<U>, Args&&...);

template <class Alloc>
    variant(allocator_arg_t, const Al&);
template <class Alloc>
    variant(allocator_arg_t, const Al&, const variant&);
template <class Alloc>
    variant(allocator_arg_t, const Al&, variant&&);
template <class Alloc, class T>
    variant(allocator_arg_t, const Al&, T&&);
template <class Alloc, class T, class... Args>
    variant(allocator_arg_t, const Al&, in_place_type_t<T>, Args&&...);
template <class Alloc, class T, class U, class... Args>
    variant(allocator_arg_t, const Al&, in_place_type_t<T>, initializer_list<U>, Args&&...);
template <class Alloc, size_t I, class... Args>
    variant(allocator_arg_t, const Al&, in_place_index_t<I>, Args&&...);
template <class Alloc, size_t I, class U, class... Args>
    variant(allocator_arg_t, const Al&, in_place_index_t<I>, initializer_list<U>, Args&&...);

~variant();
```

### <a name="parameters"></a>parâmetros

*&*\
A classe de alocador a ser usada com esse objeto.

## <a name="operator"></a><a name="op_eq"></a>operador =

Substitui a variante por uma cópia de outra variante.

```cpp
variant& operator=(const variant&);
variant& operator=(variant&&) noexcept(see below);
template <class T>
    variant& operator=(T&&) noexcept(see below);
```

## <a name="swap"></a><a name="swap"></a>permuta

```cpp
void swap(variant&) noexcept(see below);
```

## <a name="valueless_by_exception"></a><a name="valueless"></a>valueless_by_exception

Retorna **`false`** se a variante contém um valor.

```cpp
constexpr bool valueless_by_exception() const noexcept;
```
