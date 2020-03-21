---
title: Classe integer_sequence
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::index_sequence
- type_traits/std::make_index_sequence
- type_traits/std::integer_sequence
- type_traits/std::make_integer_sequence
- type_traits/std::index_sequence_for
helpviewer_keywords:
- std::index_sequence
- std::make_index_sequence
- std::integer_sequence
- std::make_integer_sequence
- std::index_sequence_for
ms.assetid: 2cfdddee-819d-478e-bb78-c8a9c2696803
ms.openlocfilehash: d0de2e56e1f6b8e68e5989f21ecd89b9646caa1b
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076469"
---
# <a name="integer_sequence-class"></a>Classe integer_sequence

Representa uma sequência de inteiros. Pode ser usada para deduzir e expandir pacotes de parâmetros em tipos variadic, como std::tuple\<T...>, que são passados como argumentos para uma função.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, T... Vals>
struct integer_sequence
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo dos valores; deve ser um tipo integral: bool, char, char16_t, char32_t, wchar_t, ou tipos inteiros com sinal ou sem sinal.

\ *Vals*
Um pacote de parâmetro que não são de tipo e que representa uma sequência de valores do tipo integral T.

## <a name="members"></a>Membros

|||
|-|-|
|`static size_t size() noexcept`|O número de elementos na sequência.|
|`typedef T value_type`|O tipo de cada elemento na sequência. Deve ser um tipo integral.|

## <a name="remarks"></a>Comentários

Um pacote de parâmetros passado diretamente a uma função pode ser desempacotado sem nenhum auxiliar de biblioteca especial. Quando um pacote de parâmetros faz parte de um tipo passado para uma função, e você precisa de índices para acessar os elementos, a maneira mais fácil de desempacotá-o é usar `integer_sequence` e os aliases de tipo relacionados `make_integer_sequence`, `index_sequence`, `make_index_sequence` e `index_sequence_for`.

## <a name="example"></a>Exemplo

O exemplo a seguir é baseado na proposta [N3658](https://wg21.link/n3658) original. Ele mostra como usar um `integer_sequence` para criar um `std::tuple` de um `std::array<T,N>`, bem como usar um `integer_sequence` para chegar aos membros da tupla.

Na função `a2t`, um `index_sequence` é um alias de `integer_sequence` com base no tipo integral `size_t`. `make_index_sequence` é um alias que, em tempo de compilação, cria `index_sequence` baseado em zero com o mesmo número de elementos da matriz que é passado pelo chamador. `a2t` passa o `index_sequence`, por valor, para `a2t_`, em que a expressão `a[I]...` desempacota `I` e, então, os elementos são alimentados para `make_tuple`, que os consome como argumentos individuais. Por exemplo, se a sequência contiver três elementos, `make_tuple` será chamado como make_tuple(a[0], a[1], a[2]). Os próprios elementos da matriz podem, claro, ser de qualquer tipo.

A função Apply aceita um [std:: tupla](../standard-library/tuple-class.md)e produz um `integer_sequence` usando a classe auxiliar `tuple_size`. Observe que o [std::d ecay_t](../standard-library/decay-class.md) é necessário porque [tuple_size](../standard-library/tuple-size-class-tuple.md) não funciona com tipos de referência. A função `apply_` desempacota os membros da tupla e os encaminha como argumentos separados para uma chamada de função. Neste exemplo, a função é uma expressão lambda simples que imprime os valores.

```cpp
#include <stddef.h>
#include <iostream>
#include <tuple>
#include <utility>
#include <array>
#include <string>

using namespace std;

// Create a tuple from the array and the index_sequence
template<typename Array, size_t... I>
auto a2t_(const Array& a, index_sequence<I...>)
{
    return make_tuple(a[I]...);
}

// Create an index sequence for the array, and pass it to the
// implementation function a2t_
template<typename T, size_t N>
auto a2t(const array<T, N>& a)
{
    return a2t_(a, make_index_sequence<N>());
}

// Call function F with the tuple members as separate arguments.
template<typename F, typename Tuple = tuple<T...>, size_t... I>
decltype(auto) apply_(F&& f, Tuple&& args, index_sequence<I...>)
{
    return forward<F>(f)(get<I>(forward<Tuple>(args))...);
}

// Create an index_sequence for the tuple, and pass it with the
// function object and the tuple to the implementation function apply_
template<typename F, typename Tuple = tuple<T...>>
decltype(auto) apply(F&& f, Tuple&& args)
{
    using Indices = make_index_sequence<tuple_size<decay_t<Tuple>>::value >;
    return apply_(forward<F>(f), forward<Tuple>(args), Indices());
}

int main()
{
    const array<string, 3> arr { "Hello", "from", "C++14" };

    //Create a tuple given a array
    auto tup = a2t(arr);

    // Extract the tuple elements
    apply([](const string& a, const string& b, const string& c) {cout << a << " " << b << " " << c << endl; }, tup);

    char c;
    cin >> c;
}
```

Para fazer um `index_sequence` para um pacote de parâmetro, use `index_sequence_for`\<T...>, que é um alias para `make_index_sequence`\<sizeof...(T)>

## <a name="requirements"></a>Requisitos

Cabeçalho: \<type_traits\>

Namepace: std

## <a name="see-also"></a>Confira também

[Reticências e modelos variadic](../cpp/ellipses-and-variadic-templates.md)
