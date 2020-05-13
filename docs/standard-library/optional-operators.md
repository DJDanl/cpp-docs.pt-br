---
title: '&lt;operadores opcionais&gt;'
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
ms.openlocfilehash: 9bdef0669f90da7865f7652ff4528e51e584e1a2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373628"
---
# <a name="ltoptionalgt-operators"></a>&lt;operadores opcionais&gt;

## <a name="operator"></a><a name="op_eq_eq"></a>operador==

Teste se `optional` o objeto no lado esquerdo do `optional` operador é igual ao objeto do lado direito.

```cpp
template <class T, class U> constexpr bool operator==(const optional<T>& left, const optional<U>& right);
template <class T> constexpr bool operator==(const optional<T>& left, nullopt_t right) noexcept;
template <class T> constexpr bool operator==(nullopt_t left, const optional<T>& right) noexcept;
template <class T, class U> constexpr bool operator==(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator==(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

*Certo*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

## <a name="operator"></a><a name="op_neq"></a>operador!=

Teste se `optional` o objeto do lado esquerdo do `optional` operador não é igual ao objeto do lado direito.

```cpp
template <class T, class U> constexpr bool operator!=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator!=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator!=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator!=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator!=(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

*Certo*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(left == right)`.

## <a name="operatorlt"></a><a name="op_lt"></a>Operador&lt;

Teste se `optional` o objeto do lado esquerdo do `optional` operador é menor que o objeto do lado direito.

```cpp
template <class T, class U> constexpr bool operator<(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator<(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator<(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator<(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator<(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

*Certo*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

### <a name="return-value"></a>Valor retornado

**true** se a lista no lado esquerdo do operador for menor que ou diferente da lista à direita do operador; caso contrário, **false**.

## <a name="operatorlt"></a><a name="op_lt_eq"></a>Operador&lt;=

Teste se `optional` o objeto do lado esquerdo do operador `optional` é menor ou igual ao objeto do lado direito.

```cpp
template <class T, class U> constexpr bool operator<=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator<=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator<=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator<=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator<=(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

*Certo*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

### <a name="return-value"></a>Valor retornado

**true** se a lista no lado esquerdo do operador for menor que ou igual à lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(right < left)`.

## <a name="operatorgt"></a><a name="op_gt"></a>Operador&gt;

Teste se `optional` o objeto do lado esquerdo do `optional` operador é maior que o objeto do lado direito.

```cpp
template <class T, class U> constexpr bool operator>(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator>(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator>(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator>(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator>(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

*Certo*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

### <a name="return-value"></a>Valor retornado

**true** se a lista no lado esquerdo do operador for maior que a lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `right < left`.

## <a name="operatorgt"></a><a name="op_gt_eq"></a>Operador&gt;=

Teste se `optional` o objeto do lado esquerdo do operador `optional` é maior ou igual ao objeto do lado direito.

```cpp
template <class T, class U> constexpr bool operator>=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator>=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator>=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator>=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator>=(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

*Certo*\
Um objeto `optional`de `nullopt_t`tipo, ou `T`.

### <a name="return-value"></a>Valor retornado

**true** se a `optional` no lado esquerdo do operador for maior que ou igual à `optional` à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A função do modelo retorna `!(left < right)`.
