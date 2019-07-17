---
title: '&lt;opcional&gt; operadores'
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
ms.openlocfilehash: c5d0de435180054b186400384fc0583df5b03246
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268918"
---
# <a name="ltoptionalgt-operators"></a>&lt;opcional&gt; operadores

## <a name="op_eq_eq"></a> operador = =

Testa se o `optional` objeto no lado esquerdo do operador é igual ao `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator==(const optional<T>& left, const optional<U>& right);
template <class T> constexpr bool operator==(const optional<T>& left, nullopt_t right) noexcept;
template <class T> constexpr bool operator==(nullopt_t left, const optional<T>& right) noexcept;
template <class T, class U> constexpr bool operator==(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator==(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

*Certo*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

## <a name="op_neq"></a> operador! =

Testa se o `optional` objeto no lado esquerdo do operador não é igual ao `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator!=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator!=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator!=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator!=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator!=(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

*Certo*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(left == right)`.

## <a name="op_lt"></a> Operador&lt;

Testa se o `optional` objeto no lado esquerdo do operador é menor do que o `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator<(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator<(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator<(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator<(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator<(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

*Certo*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for menor que ou diferente da lista à direita do operador; caso contrário, **false**.

## <a name="op_lt_eq"></a>  operator&lt;=

Testa se o `optional` objeto no lado esquerdo do operador é menor ou igual ao `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator<=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator<=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator<=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator<=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator<=(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

*Certo*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for menor que ou igual à lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(right < left)`.

## <a name="op_gt"></a> Operador&gt;

Testa se o `optional` objeto no lado esquerdo do operador é maior que o `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator>(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator>(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator>(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator>(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator>(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

*Certo*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for maior que a lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `right < left`.

## <a name="op_gt_eq"></a> operador&gt;=

Testa se o `optional` objeto no lado esquerdo do operador é maior que ou igual ao `optional` objeto no lado direito.

```cpp
template <class T, class U> constexpr bool operator>=(const optional<T>&, const optional<U>&);
template <class T> constexpr bool operator>=(const optional<T>&, nullopt_t) noexcept;
template <class T> constexpr bool operator>=(nullopt_t, const optional<T>&) noexcept;
template <class T, class U> constexpr bool operator>=(const optional<T>&, const U&);
template <class T, class U> constexpr bool operator>=(const U&, const optional<T>&);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

*Certo*\
Um objeto do tipo `optional`, `nullopt_t`, ou `T`.

### <a name="return-value"></a>Valor de retorno

**true** se a `optional` no lado esquerdo do operador for maior que ou igual à `optional` à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A função do modelo retorna `!(left < right)`.
