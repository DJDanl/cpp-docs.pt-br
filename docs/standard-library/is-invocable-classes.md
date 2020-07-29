---
title: is_invocable, is_invocable_r, is_nothrow_invocable is_nothrow_invocable_r classes
ms.date: 02/21/2019
f1_keywords:
- type_traits/std::is_invocable
- type_traits/std::is_invocable_r
- type_traits/std::is_nothrow_invocable
- type_traits/std::is_nothrow_invocable_r
helpviewer_keywords:
- is_invocable class
- is_invocable
- is_invocable_r class
- is_invocable_r
- is_nothrow_invocable class
- is_nothrow_invocable
- is_nothrow_invocable_r class
- is_nothrow_invocable_r
ms.openlocfilehash: 47801eff0ea0c41c7b69dfb7a1aa5190a43f1b75
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233100"
---
# <a name="is_invocable-is_invocable_r-is_nothrow_invocable-is_nothrow_invocable_r-classes"></a>is_invocable, is_invocable_r, is_nothrow_invocable is_nothrow_invocable_r classes

Esses modelos determinam se um tipo pode ser invocado com os tipos de argumento especificados. `is_invocable_r`Além `is_nothrow_invocable_r` disso, determine se o resultado da invocação é conversível para um tipo específico. `is_nothrow_invocable`Além `is_nothrow_invocable_r` disso, determine se a invocação é conhecida por não lançar exceções. Adicionado em C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Callable, class... Args>
struct is_invocable;

template <class Convertible, class Callable, class... Args>
struct is_invocable_r;

template <class Callable, class... Args>
struct is_nothrow_invocable;

template <class Convertible, class Callable, class... Args>
struct is_nothrow_invocable_r;

// Helper templates
template <class Callable, class... Args>
inline constexpr bool is_invocable_v =
    std::is_invocable<Callable, Args...>::value;

template <class Convertible, class Callable, class... Args>
inline constexpr bool is_invocable_r_v =
    std::is_invocable_r<Convertible, Callable, Args...>::value;

template <class Callable, class... Args>
inline constexpr bool is_nothrow_invocable_v =
    std::is_nothrow_invocable<Callable, Args...>::value;

template <class Convertible, class Callable, class... Args>
inline constexpr bool is_nothrow_invocable_r_v =
    std::is_nothrow_invocable_r<Convertible, Callable, Args...>::value;
```

### <a name="parameters"></a>parâmetros

*Acessível*\
O tipo callable para consulta.

*Argumento*\
Os tipos de argumentos a serem consultados.

*Vertida*\
O tipo de resultado de *callable* deve ser conversível.

## <a name="remarks"></a>Comentários

O `is_invocable` predicado de tipo será true se o tipo callable *callable* puder ser invocado usando os argumentos Arguments em um contexto não avaliado. *Args*

O `is_invocable_r` predicado de tipo se aplica true se o tipo callable *callable* puder ser *Args* invocado usando os argumentos Arguments em um contexto não avaliado para produzir um tipo de resultado conversível para *conversível*.

O `is_nothrow_invocable` predicado de tipo será true se o tipo callable *callable* puder ser invocado usando os argumentos Arguments em um contexto não avaliado e essa chamada não for conhecida como não lançar uma exceção. *Args*

O `is_nothrow_invocable_r` predicado de tipo se manterá verdadeiro se o tipo callable *callable* puder *Args* ser invocado usando os argumentos Arguments em um contexto não avaliado para produzir um tipo de resultado conversível para *conversível*e essa chamada não for conhecida como não lançar uma exceção.

Cada um dos tipos *conversíveis*, *chamáveis*e os tipos nos *args* do pacote de parâmetros deve ser um tipo completo, uma matriz de limite desconhecido ou um possivelmente qualificado por CV **`void`** . Caso contrário, o comportamento do predicado será indefinido.

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__is_invocable.cpp
// compile using: cl /EHsc /std:c++17 std__type_traits__is_invocable.cpp
#include <type_traits>

auto test1(int) noexcept -> int (*)()
{
    return nullptr;
}

auto test2(int) -> int (*)()
{
    return nullptr;
}

int main()
{
    static_assert( std::is_invocable<decltype(test1), short>::value );

    static_assert( std::is_invocable_r<int(*)(), decltype(test1), int>::value );
    static_assert( std::is_invocable_r<long(*)(), decltype(test1), int>::value ); // fails

    static_assert( std::is_nothrow_invocable<decltype(test1), int>::value );
    static_assert( std::is_nothrow_invocable<decltype(test2), int>::value ); // fails

    static_assert( std::is_nothrow_invocable_r<int(*)(), decltype(test1), int>::value );
    static_assert( std::is_nothrow_invocable_r<int(*)(), decltype(test2), int>::value ); // fails
}
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)\
[invoke](functional-functions.md#invoke)
