---
title: '&lt;operadores opcionais &gt;'
ms.date: 11/04/2016
f1_keywords:
- optional/std::operator!=
- optional/std::operator==
- optional/std::operatoroperator&gt;
- optional/std::operatoroperator&gt=;
- optional/std::operatoroperator&lt;
- optional/std::operatoroperator&lt;=
ms.assetid: 57492e09-3836-4dbc-9ae5-78ecf506c190
helpviewer_keywords:
- std::operator!= (optional)
- std::operator== (optional)
- std::operatoroperator&gt; (optional)
- std::operatoroperator&gt=; (optional)
- std::operatoroperator&lt; (optional)
- std::operatoroperator&lt;= (optional)
ms.openlocfilehash: c7eca76f71f12e7f7fe0e60c0a4cfe456d54c374
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224676"
---
# <a name="ltoptionalgt-operators"></a>&lt;operadores opcionais &gt;

## <a name="operator"></a><a name="op_eq_eq"></a>operador = =

Testa se o `optional` objeto no lado esquerdo do operador é igual ao `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator==(const optional<T>& left, const optional<U>& right);
template <class T> constexpr bool operator==(const optional<T>& left, nullopt_t right) noexcept;
template <class T> constexpr bool operator==(nullopt_t left, const optional<T>& right) noexcept;
template <class T, class U> constexpr bool operator==(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator==(const U&, const optional<T>&);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

*Certo*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

## <a name="operator"></a><a name="op_neq"></a>operador! =

Testa se o `optional` objeto no lado esquerdo do operador não é igual ao `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator!=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator!=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator!=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator!=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator!=(const U&, const optional<T>&);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

*Certo*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(left == right)`.

## <a name="operatorlt"></a><a name="op_lt"></a>operador&lt;

Testa se o `optional` objeto no lado esquerdo do operador é menor que o `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator<(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator<(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator<(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator<(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator<(const U&, const optional<T>&);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

*Certo*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

### <a name="return-value"></a>Valor retornado

**`true`** se a lista no lado esquerdo do operador for menor que, mas não igual à lista no lado direito do operador; caso contrário **`false`** .

## <a name="operatorlt"></a><a name="op_lt_eq"></a>operador&lt;=

Testa se o `optional` objeto no lado esquerdo do operador é menor ou igual ao `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator<=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator<=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator<=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator<=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator<=(const U&, const optional<T>&);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

*Certo*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

### <a name="return-value"></a>Valor retornado

**`true`** se a lista no lado esquerdo do operador for menor ou igual à lista no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(right < left)`.

## <a name="operatorgt"></a><a name="op_gt"></a>operador&gt;

Testa se o `optional` objeto no lado esquerdo do operador é maior que o `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator>(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator>(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator>(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator>(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator>(const U&, const optional<T>&);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

*Certo*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

### <a name="return-value"></a>Valor retornado

**`true`** se a lista no lado esquerdo do operador for maior que a lista no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `right < left`.

## <a name="operatorgt"></a><a name="op_gt_eq"></a>operador&gt;=

Testa se o `optional` objeto no lado esquerdo do operador é maior ou igual ao `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator>=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator>=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator>=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator>=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator>=(const U&, const optional<T>&);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

*Certo*\
Um objeto do tipo `optional` , `nullopt_t` ou `T` .

### <a name="return-value"></a>Valor retornado

**`true`** Se o `optional` no lado esquerdo do operador for maior ou igual ao `optional` no lado direito do operador; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

A função do modelo retorna `!(left < right)`.
