---
title: is_invocable, is_invocable_r, is_nothrow_invocable, is_nothrow_invocable_r classes
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
ms.openlocfilehash: bb5e75a897029ded2e00e491d93d2df41a3e115b
ms.sourcegitcommit: 4299caac2dc9e806c74ac833d856a3838b0f52a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2019
ms.locfileid: "57006857"
---
# <a name="isinvocable-isinvocabler-isnothrowinvocable-isnothrowinvocabler-classes"></a>is_invocable, is_invocable_r, is_nothrow_invocable, is_nothrow_invocable_r classes

Esses modelos determinam se um tipo pode ser chamado com tipos de argumento especificados. `is_invocable_r` e `is_nothrow_invocable_r` também determinar se o resultado da invocação é convertido em um tipo específico. `is_nothrow_invocable` e `is_nothrow_invocable_r` também determinar se a invocação é conhecida para não gerar exceções. Adicionado no c++17.

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

### <a name="parameters"></a>Parâmetros

*pode ser chamado*<br/>
O tipo callable para consulta.

*Args*<br/>
Os tipos de argumento de consulta.

*Podem ser convertidas em*<br/>
O tipo de resultado de *Callable* deve ser convertido.

## <a name="remarks"></a>Comentários

O `is_invocable` predicado de tipo será verdadeira se o tipo callable *Callable* podem ser invocados usando os argumentos *Args* em um contexto não avaliado.

O `is_invocable_r` predicado de tipo será verdadeira se o tipo callable *Callable* podem ser invocados usando os argumentos *Args* em um contexto não avaliado para produzir um conversível do tipo de resultado para  *Podem ser convertidas em*.

O `is_nothrow_invocable` predicado de tipo será verdadeira se o tipo callable *Callable* podem ser invocados usando os argumentos *Args* em um contexto não avaliado e que essa chamada é conhecida para não lançar uma exceção.

O `is_nothrow_invocable_r` predicado de tipo será verdadeira se o tipo callable *Callable* podem ser invocados usando os argumentos *Args* em um contexto não avaliado para produzir um conversível do tipo de resultado para  *Podem ser convertidas em*, e que essa chamada é conhecida para não lançar uma exceção.

Cada um dos tipos *conversível*, *Callable*e os tipos de pacote de parâmetros *Args* deve ser um tipo completo, uma matriz de limite desconhecido ou uma possivelmentequalificadaporcv**void**. Caso contrário, o comportamento do predicado é indefinido.

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

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[invoke](functional-functions.md#invoke)<br/>
