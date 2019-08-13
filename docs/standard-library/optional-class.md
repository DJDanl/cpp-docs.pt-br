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
ms.openlocfilehash: f664df6493a7ee20361d49531a930aeb810d3d2a
ms.sourcegitcommit: 16c0392fc8d96e814c3a40b0c5346d7389aeb525
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/12/2019
ms.locfileid: "68957157"
---
# <a name="optional-class"></a>Classe opcional

A classe `optional<T>` de modelo descreve um objeto que pode ou não conter um valor do tipo `T`, conhecido como o *valor contido*.

Quando uma instância do `optional<T>` contém um valor, o valor contido é alocado dentro do armazenamento `optional` do objeto, em uma região adequadamente alinhada para o `T`tipo. Quando um `optional<T>` for convertido em `bool`, o resultado será `true` se o objeto `false`contiver um valor; caso contrário, será.

O tipo `T` de objeto contido não deve ser [in_place_t](in-place-t-struct.md) ou [nullopt_t](nullopt-t-structure.md). `T`deve ser *destrutíveis*, ou seja, seu destruidor deve recuperar todos os recursos de propriedade e não pode gerar exceções.

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
|[optional](#optional) | Constrói um objeto do tipo `optional`. |
|[~ opcional](#optional-destructor) | Destrói um objeto do tipo `optional`. |
| **Atribuição** | |
| [operator=](#op_eq) | Substitui o `optional` por uma cópia de outro `optional`. |
| [emplace](#op_eq) | Inicializa o valor contido com os argumentos especificados. |
| **Swap** | |
| [swap](#swap) | Permuta o valor contido ou o estado vazio por outro `optional`. |
| **Observadores** | |
| [has_value](#has_value) | Retorna se um `optional` objeto contém um valor. |
| [value](#value) | Retorna o valor contido. |
| [value_or](#value_or) | Retorna o valor contido ou uma alternativa se nenhum valor estiver presente. |
| [operator->](#op_as) | Faz referência ao valor contido de `optional` um objeto. |
| [operator*](#op_mem) | Faz referência ao valor contido de `optional` um objeto. |
| [operator bool](#op_bool) | Retorna se um `optional` objeto contém um valor. |
| **Modificadores** | |
| [reset](#reset) | Redefine o `optional` destruindo qualquer valor contido. |

## <a name="has_value"></a>has_value

```cpp
constexpr bool has_value() const noexcept;
```

## <a name="optional"></a>Construtor opcional

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

### <a name="parameters"></a>Parâmetros

*RHS*\
O `optional` a ser copiado ou movido da construção do valor contido.

*i_list*\
A lista de inicializadores da qual construir o valor contido.

*argumento*\
A lista de argumentos da qual construir o valor contido.

### <a name="remarks"></a>Comentários

`constexpr optional() noexcept;`
`constexpr optional(nullopt_t nullopt) noexcept;`Esses construtores constroem um `optional` que não contém um valor.

`constexpr optional(const optional& rhs);`O construtor de cópia Inicializa o valor contido a partir do valor contido do argumento. Ele é definido como **excluído** , `is_copy_constructible_v<T>` a menos que seja verdadeiro, e é `is_trivially_copy_constructible_v<T>` trivial se for verdadeiro.

`constexpr optional(optional&& rhs) noexcept;`O Construtor move Inicializa o valor contido movendo-se do valor contido do argumento. Ele não participa da resolução de sobrecarga `is_move_constructible_v<T>` , a menos que seja verdadeiro, e `is_trivially_move_constructible_v<T>` é trivial se for verdadeiro.

`template <class... Args> constexpr explicit optional(in_place_t, Args&&... args);`Direciona Inicializa o valor contido como se estiver usando os `std::forward<Args>(args)`argumentos. Esse construtor é `constexpr` se o `T` Construtor usado for `constexpr`. Ele não participa da resolução de sobrecarga `is_constructible_v<T, Args...>` , a menos que seja verdadeiro.

`template <class U, class... Args> constexpr explicit optional(in_place_t, initializer_list<U> i_list, Args&&... args);`Direciona Inicializa o valor contido como se estiver usando os `i_list, std::forward<Args>(args)`argumentos. Esse construtor é `constexpr` se o `T` Construtor usado for `constexpr`. Ele não participa da resolução de sobrecarga `is_constructible_v<T, initializer_list<U>&, Args&&...>` , a menos que seja verdadeiro.

`template <class U = T> explicit constexpr optional(U&& rhs);`Direciona Inicializa o valor contido como se estiver `std::forward<U>(v)`usando. Esse construtor é `constexpr` se o `T` Construtor usado for `constexpr`. Ele não participa da resolução de sobrecarga `is_constructible_v<T, U&&>` , a menos que `is_same_v<remove_cvref_t<U>, in_place_t>` seja `is_same_v<remove_cvref_t<U>, optional>` verdadeiro, e e seja falso.

`template <class U> explicit optional(const optional<U>& rhs);`Se o *RHS* contiver um valor, o direcionará o valor contido a partir do valor contido do argumento. Ele não participa da resolução de sobrecarga `is_constructible_v<T, const U&>` , a menos que `is_constructible_v<T, optional<U>&>`seja verdadeiro `is_constructible_v<T, const optional<U>&>`, `is_constructible_v<T, const optional<U>&&>` `is_convertible_v<optional<U>&, T>` `is_constructible_v<T, optional<U>&&>`e `is_convertible_v<optional<U>&&, T>` `is_convertible_v<const optional<U>&, T>`,,,, `is_convertible_v<const optional<U>&&, T>` ,, e sejam todos falsos.

`template <class U> explicit optional(optional<U>&& rhs);`Se o *RHS* contiver um valor, direto inicializará o valor contido `std::move(*rhs)`como se estiver usando. Ele não participa da resolução de sobrecarga `is_constructible_v<T, U&&>` , a menos que `is_constructible_v<T, optional<U>&>`seja verdadeiro `is_constructible_v<T, const optional<U>&>`, `is_constructible_v<T, const optional<U>&&>` `is_convertible_v<optional<U>&, T>` `is_constructible_v<T, optional<U>&&>`e `is_convertible_v<optional<U>&&, T>` `is_convertible_v<const optional<U>&, T>`,,,, `is_convertible_v<const optional<U>&&, T>` ,, e sejam todos falsos.

## <a name="optional-destructor"></a>~ destruidor opcional

Destrói qualquer valor de destrutíveis não trivial, se houver um presente, invocando seu destruidor.

```cpp
~optional();
```

### <a name="remarks"></a>Comentários

Se `T` o for trivialmente destrutíveis `optional<T>` , ele também será destrutíveis trivialmente.

## <a name="op_eq"></a>operador =

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

## <a name="op_as"></a>operador->

Faz referência ao valor contido de um `optional` objeto.

```cpp
constexpr const T* operator->() const;
constexpr T* operator->();
```

## <a name="op_mem"></a>operador

Faz referência ao valor contido de um `optional` objeto.

```cpp
constexpr const T& operator*() const&;
constexpr T& operator*() &;
constexpr T&& operator*() &&;
constexpr const T&& operator*() const&&;
```

## <a name="op_bool"></a>booliano de operador

Relata se o `optional` objeto tem um valor contido.

```cpp
constexpr explicit operator bool() const noexcept;
```

## <a name="reset"></a>definido

Efetivamente, chama o destruidor do objeto contido, se houver, e o define como um estado não inicializado.

```cpp
void reset() noexcept;
```

## <a name="swap"></a>permuta

```cpp
template<class T>
void swap(optional<T>&, optional<T>&) noexcept;
```

## <a name="value"></a>valor

```cpp
constexpr const T& value() const&;
constexpr T& value() &;
constexpr T&& value() &&;
constexpr const T&& value() const&&;
```

## <a name="value_or"></a>value_or

```cpp
template <class U>
    constexpr T value_or(U&&) const&;
template <class U>
    constexpr T value_or(U&&) &&;
```

## <a name="see-also"></a>Consulte também

[\<> opcional](optional.md)
