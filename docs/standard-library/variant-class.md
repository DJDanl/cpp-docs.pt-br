---
title: variante de classe
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
ms.openlocfilehash: 9bfdf644374a0b825fd0ca02bf4164a766cb42a3
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68269298"
---
# <a name="variant-class"></a>variante de classe

Qualquer instância de variant em um determinado momento ou contém um valor de um de seus tipos alternativos ou ela mantém nenhum valor.

## <a name="syntax"></a>Sintaxe

```cpp
template <class... Types>
    class variant
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[Variant](#variant)|Constrói um objeto do tipo `variant`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[emplace](#emplace)|Cria um novo valor contido.|
|[index](#index)|Retorna o índice de um valor contido.|
|[swap](#swap)||
|[valueless_by_exception](#emplace)|Retorna **falsos** se a variante contém um valor.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator=](#op_eq)|Substitui a variante com uma cópia de outra variante.|

## <a name="emplace"></a> emplace

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

## <a name="index"></a> Índice

Retorna o índice de um valor contido.

```cpp
constexpr size_t index() const noexcept;
```

## <a name="variant"></a> Variant

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

### <a name="parameters"></a>Parâmetros

*Al*\
A classe de alocador a ser usada com esse objeto.

## <a name="op_eq"></a> operador =

Substitui a variante com uma cópia de outra variante.

```cpp
variant& operator=(const variant&);
variant& operator=(variant&&) noexcept(see below);
template <class T>
    variant& operator=(T&&) noexcept(see below);
```

## <a name="swap"></a> troca

```cpp
void swap(variant&) noexcept(see below);
```

## <a name="valueless"></a> valueless_by_exception

Retorna **falsos** se a variante contém um valor.

```cpp
constexpr bool valueless_by_exception() const noexcept;
```
