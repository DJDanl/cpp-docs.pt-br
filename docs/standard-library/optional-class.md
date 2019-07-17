---
title: Classe opcional
ms.date: 11/04/2016
f1_keywords:
- optional/std::optional
- optional/std::optional::has_value
- optional/std::optional::reset
- optional/std::optional::value
- optional/std::optional::value_or
helpviewer_keywords:
- optional/std::optional
- optional/std::optional::has_value
- optional/std::optional::reset
- optional/std::optional::value
- optional/std::optional::value_or
ms.assetid: 89a3b805-ab60-4858-b772-5855130c11b1
ms.openlocfilehash: 414b3e608e915ec06dbdf90726151a1c33ea4c60
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68269198"
---
# <a name="optional-class"></a>Classe opcional

Descreve um objeto que pode ou não conter um valor.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class optional
{
    using value_type = T;
};

template<class T> optional(T) -> optional<T>;
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[optional](#optional)|Constrói um objeto do tipo `optional`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[has_value](#has_value)|Retorna **verdadeira** se `optional` contém o valor.|
|[reset](#reset)|Redefine o `optional`.|
|[value](#value)|Avalia a `optional` valor.|
|[value_or](#value_or)|Avalia a `optional` valor.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator=](#op_eq)|Substitui o `optional` com uma cópia de outro `optional`.|
|[operator->](#op_as)|Atribua o valor a ser `optional`.|
|[operator*](#op_mem)|Fazer referência a memória de `optional`.|
|[operator bool](#op_bool)|Retornar o valor booliano de `optional` valor.|

### <a name="has_value"></a> has_value

```cpp
constexpr bool has_value() const noexcept;
```

### <a name="optional"></a> Opcional

Constrói um objeto do tipo `optional`. Também inclui um destruidor.

```cpp
constexpr optional() noexcept;
constexpr optional(nullopt_t) noexcept;
constexpr optional(const optional&);
constexpr optional(optional&&) noexcept(see below);

template <class... Args>
    constexpr explicit optional(in_place_t, Args&&...);
template <class U, class... Args>
    constexpr explicit optional(in_place_t, initializer_list<U>, Args&&...);
template <class U = T>
    explicit constexpr optional(U&&);
template <class U>
    explicit optional(const optional<U>&);
template <class U>
    explicit optional(optional<U>&&);

~optional();
```

### <a name="op_eq"></a> operador =

Substitui o `optional` com uma cópia de outro `optional`.

```cpp
optional& operator=(nullopt_t) noexcept;
optional& operator=(const optional&);
optional& operator=(optional&&) noexcept(see below);

template <class U = T>
    optional& operator=(U&&); template <class U> optional& operator=(const optional<U>&);
template <class U>
    optional& operator=(optional<U>&&); template <class... Args> T& emplace(Args&&...);
template <class U, class... Args>
    T& emplace(initializer_list<U>, Args&&...);
```

### <a name="op_as"></a> operador ->

```cpp
constexpr const T* operator->() const;
constexpr T* operator->();
```

### <a name="op_mem"></a> operador *

```cpp
constexpr const T& operator*() const&;
constexpr T& operator*() &;
constexpr T&& operator*() &&;
constexpr const T&& operator*() const&&;
```

### <a name="op_bool"></a> operador bool

```cpp
constexpr explicit operator bool() const noexcept;
```

### <a name="reset"></a> Redefinir

```cpp
void reset() noexcept;
```

### <a name="value"></a> Valor

```cpp
constexpr const T& value() const&;
constexpr T& value() &;
constexpr T&& value() &&;
constexpr const T&& value() const&&;
```

### <a name="value_or"></a> value_or

```cpp
template <class U>
    constexpr T value_or(U&&) const&;
template <class U>
    constexpr T value_or(U&&) &&;
```
