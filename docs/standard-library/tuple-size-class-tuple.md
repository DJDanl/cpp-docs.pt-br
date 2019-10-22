---
title: Classe tuple_size;
ms.date: 11/04/2016
f1_keywords:
- tuple_size
- std::tuple_size
- utility/std::tuple_size
helpviewer_keywords:
- std::tuple_size
ms.assetid: 73852fc5-eb68-41f1-8379-465cedc2314a
ms.openlocfilehash: 361545bee020d6c3624d1d45743abcb9c2b4ac85
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688849"
---
# <a name="tuple_size-class"></a>Classe tuple_size;

Informa o número de elementos que um `tuple` contém.

## <a name="syntax"></a>Sintaxe

```cpp
// TEMPLATE STRUCT tuple_size
template <class Tuple>
   struct tuple_size;

// number of elements in array
template <class Elem, size_t Size>
   struct tuple_size<array<Elem, Size>>
      : integral_constant<size_t, Size>;

// size of pair
template <class T1, class T2>
   struct tuple_size<pair<T1, T2>>
      : integral_constant<size_t, 2>

// size of tuple
template <class... Types>
   struct tuple_size<tuple<Types...>>
      : integral_constant<size_t, sizeof...(Types)>;

// size of const tuple
template <class Tuple>
   struct tuple_size<const Tuple>;

// size of volatile tuple
template <class Tuple>
   struct tuple_size<volatile Tuple>;

// size of const volatile tuple
template <class Tuple>
   struct tuple_size<const volatile Tuple>;
```

```cpp
template <class T> inline constexpr size_t tuple_size_v = tuple_size<T>::value;
```

### <a name="parameters"></a>Parâmetros

@No__t_1 de *tupla*
O tipo da tupla.

@No__t_1 *elem*
O tipo dos elementos da matriz.

@No__t_1 de *tamanho*
O tamanho da matriz.

@No__t_1 *T1*
O tipo do primeiro membro do par.

*T2* \
O tipo do segundo membro do par.

*Tipos*\
Os tipos dos elementos da tupla.

## <a name="remarks"></a>Comentários

O modelo de classe tem um membro `value` que é uma expressão constante integral cujo valor é a extensão da *tupla*do tipo de tupla.

A especialização de modelo para matrizes tem um membro `value` que é uma expressão constante integral cujo valor é *tamanho*, que é o tamanho da matriz.

A especialização de modelo para par tem um membro `value` que é uma expressão constante integral cujo valor é 2.

## <a name="example"></a>Exemplo

```cpp
#include <tuple>
#include <iostream>

using namespace std;

typedef tuple<int, double, int, double> MyTuple;
int main()
{
    MyTuple c0(0, 1.5, 2, 3.7);

    // display contents "0 1 2 3"
    cout << get<0>(c0);
    cout << " " << get<1>(c0);
    cout << " " << get<2>(c0);
    cout << " " << get<3>(c0) << endl;

    // display size "4"
    cout << " " << tuple_size<MyTuple>::value << endl;
}
```

```Output
0 1.5 2 3.7
4
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<tuple>

**Cabeçalho:** \<array> (para a especialização de matriz)

**Cabeçalho:** \<utility> (para a especialização de par)

**Namespace:** std
