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
ms.openlocfilehash: 3b8baca48b7b7a32b88079a1668aecdd1c9aca88
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224689"
---
# <a name="optional-class"></a>Classe opcional

O modelo de classe `optional<T>` descreve um objeto que pode ou não conter um valor do tipo `T` , conhecido como o *valor contido*.

Quando uma instância do `optional<T>` contém um valor, o valor contido é alocado dentro do armazenamento do `optional` objeto, em uma região adequadamente alinhada para o tipo `T` . Quando um `optional<T>` for convertido em **`bool`** , o resultado será **`true`** se o objeto contiver um valor; caso contrário, será **`false`** .

O tipo de objeto contido `T` não deve ser [in_place_t](in-place-t-struct.md) ou [nullopt_t](nullopt-t-structure.md). `T`deve ser *destrutíveis*, ou seja, seu destruidor deve recuperar todos os recursos de propriedade e não pode gerar exceções.

A `optional` classe é nova no c++ 17.

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
| **Construtores e destruidor** | |
|[adicional](#optional) | Constrói um objeto do tipo `optional`. |
|[~ opcional](#optional-destructor) | Destrói um objeto do tipo `optional` . |
| **Atribuição** | |
| [operador =](#op_eq) | Substitui o `optional` por uma cópia de outro `optional` . |
| [emplace](#op_eq) | Inicializa o valor contido com os argumentos especificados. |
| **Permuta** | |
| [permuta](#swap) | Permuta o valor contido ou o estado vazio por outro `optional` . |
| **Observadores** | |
| [has_value](#has_value) | Retorna se um `optional` objeto contém um valor. |
| [value](#value) | Retorna o valor contido. |
| [value_or](#value_or) | Retorna o valor contido ou uma alternativa se nenhum valor estiver presente. |
| [operador->](#op_as) | Faz referência ao valor contido de um `optional` objeto. |
| [operador](#op_mem) | Faz referência ao valor contido de um `optional` objeto. |
| [booliano de operador](#op_bool) | Retorna se um `optional` objeto contém um valor. |
| **Modificadores** | |
| [reset](#reset) | Redefine o `optional` destruindo qualquer valor contido. |

## <a name="has_value"></a><a name="has_value"></a>has_value

```cpp
constexpr bool has_value() const noexcept;
```

## <a name="optional-constructor"></a><a name="optional"></a>Construtor opcional

Constrói um objeto do tipo `optional`.

```cpp
constexpr optional() noexcept;
constexpr optional(nullopt_t nullopt) noexcept;
constexpr optional(const optional& rhs);
constexpr optional(optional&& rhs) noexcept;

template <class... Args>
constexpr explicit optional(in_place_t, Args&&... args);

template <class U, class... Args>
constexpr explicit optional(in_place_t, initializer_list<U> i_list, Args&&... args);

template <class U = T>
explicit constexpr optional(U&& rhs);

template <class U>
explicit optional(const optional<U>& rhs);

template <class U>
explicit optional(optional<U>&& rhs);
```

### <a name="parameters"></a>parâmetros

*RHS*\
O `optional` a ser copiado ou movido da construção do valor contido.

*i_list*\
A lista de inicializadores da qual construir o valor contido.

*argumento*\
A lista de argumentos da qual construir o valor contido.

### <a name="remarks"></a>Comentários

`constexpr optional() noexcept;`
`constexpr optional(nullopt_t nullopt) noexcept;`Esses construtores constroem um `optional` que não contém um valor.

`constexpr optional(const optional& rhs);`O construtor de cópia Inicializa o valor contido a partir do valor contido do argumento. Ele é definido como **excluído** , a menos que `is_copy_constructible_v<T>` seja verdadeiro, e é trivial se `is_trivially_copy_constructible_v<T>` for verdadeiro.

`constexpr optional(optional&& rhs) noexcept;`O Construtor move Inicializa o valor contido movendo-se do valor contido do argumento. Ele não participa da resolução de sobrecarga, a menos que `is_move_constructible_v<T>` seja verdadeiro, e é trivial se `is_trivially_move_constructible_v<T>` for verdadeiro.

`template <class... Args> constexpr explicit optional(in_place_t, Args&&... args);`Direciona Inicializa o valor contido como se estiver usando os argumentos `std::forward<Args>(args)` . Esse construtor é **`constexpr`** se o `T` Construtor usado for **`constexpr`** . Ele não participa da resolução de sobrecarga, a menos que `is_constructible_v<T, Args...>` seja verdadeiro.

`template <class U, class... Args> constexpr explicit optional(in_place_t, initializer_list<U> i_list, Args&&... args);`Direciona Inicializa o valor contido como se estiver usando os argumentos `i_list, std::forward<Args>(args)` . Esse construtor é **`constexpr`** se o `T` Construtor usado for **`constexpr`** . Ele não participa da resolução de sobrecarga, a menos que `is_constructible_v<T, initializer_list<U>&, Args&&...>` seja verdadeiro.

`template <class U = T> explicit constexpr optional(U&& rhs);`Direciona Inicializa o valor contido como se estiver usando `std::forward<U>(v)` . Esse construtor é **`constexpr`** se o `T` Construtor usado for **`constexpr`** . Ele não participa da resolução de sobrecarga, a menos que `is_constructible_v<T, U&&>` seja verdadeiro, e `is_same_v<remove_cvref_t<U>, in_place_t>` e `is_same_v<remove_cvref_t<U>, optional>` seja falso.

`template <class U> explicit optional(const optional<U>& rhs);`Se o *RHS* contiver um valor, o direcionará o valor contido a partir do valor contido do argumento. Ele não participa da resolução de sobrecarga, a menos que seja verdadeiro, e,,,,,, `is_constructible_v<T, const U&>` `is_constructible_v<T, optional<U>&>` `is_constructible_v<T, optional<U>&&>` `is_constructible_v<T, const optional<U>&>` `is_constructible_v<T, const optional<U>&&>` `is_convertible_v<optional<U>&, T>` `is_convertible_v<optional<U>&&, T>` `is_convertible_v<const optional<U>&, T>` e `is_convertible_v<const optional<U>&&, T>` sejam todos falsos.

`template <class U> explicit optional(optional<U>&& rhs);`Se o *RHS* contiver um valor, direto inicializará o valor contido como se estiver usando `std::move(*rhs)` . Ele não participa da resolução de sobrecarga, a menos que seja verdadeiro, e,,,,,, `is_constructible_v<T, U&&>` `is_constructible_v<T, optional<U>&>` `is_constructible_v<T, optional<U>&&>` `is_constructible_v<T, const optional<U>&>` `is_constructible_v<T, const optional<U>&&>` `is_convertible_v<optional<U>&, T>` `is_convertible_v<optional<U>&&, T>` `is_convertible_v<const optional<U>&, T>` e `is_convertible_v<const optional<U>&&, T>` sejam todos falsos.

## <a name="optional-destructor"></a><a name="optional-destructor"></a>~ destruidor opcional

Destrói qualquer valor de destrutíveis não trivial, se houver um presente, invocando seu destruidor.

```cpp
~optional();
```

### <a name="remarks"></a>Comentários

Se o `T` for trivialmente destrutíveis, ele `optional<T>` também será destrutíveis trivialmente.

## <a name="operator"></a><a name="op_eq"></a>operador =

Substitui o valor contido de um `optional` por uma cópia ou movimentação de outro `optional` valor contido.

```cpp
optional& operator=(nullopt_t) noexcept;
optional& operator=(const optional& rhs);
optional& operator=(optional&&) noexcept( /* see below */ );

template <class U = T>
    optional& operator=(U&&);

template <class U>
optional& operator=(const optional<U>&);

template <class U>
    optional& operator=(optional<U>&&);

template <class... Args>
T& emplace(Args&&...);

template <class U, class... Args>
T& emplace(initializer_list<U>, Args&&...);
```

## <a name="operator-"></a><a name="op_as"></a>operador->

Faz referência ao valor contido de um `optional` objeto.

```cpp
constexpr const T* operator->() const;
constexpr T* operator->();
```

## <a name="operator"></a><a name="op_mem"></a>operador

Faz referência ao valor contido de um `optional` objeto.

```cpp
constexpr const T& operator*() const&;
constexpr T& operator*() &;
constexpr T&& operator*() &&;
constexpr const T&& operator*() const&&;
```

## <a name="operator-bool"></a><a name="op_bool"></a>booliano de operador

Relata se o `optional` objeto tem um valor contido.

```cpp
constexpr explicit operator bool() const noexcept;
```

## <a name="reset"></a><a name="reset"></a>definido

Efetivamente, chama o destruidor do objeto contido, se houver, e o define como um estado não inicializado.

```cpp
void reset() noexcept;
```

## <a name="swap"></a><a name="swap"></a>permuta

```cpp
template<class T>
void swap(optional<T>&, optional<T>&) noexcept;
```

## <a name="value"></a><a name="value"></a> valor

```cpp
constexpr const T& value() const&;
constexpr T& value() &;
constexpr T&& value() &&;
constexpr const T&& value() const&&;
```

## <a name="value_or"></a><a name="value_or"></a>value_or

```cpp
template <class U>
    constexpr T value_or(U&&) const&;
template <class U>
    constexpr T value_or(U&&) &&;
```

## <a name="see-also"></a>Confira também

[\<optional>](optional.md)
