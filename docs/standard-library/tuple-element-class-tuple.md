---
title: Classe tuple_element
ms.date: 11/04/2016
f1_keywords:
- utility/std::tuple_element
helpviewer_keywords:
- std::tuple_element
ms.assetid: 4c51a6c1-ce81-462f-8c6c-291d69f2b77c
ms.openlocfilehash: be9d9fe56d35e96e4179eb511edccd475a369f32
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008288"
---
# <a name="tuple_element-class"></a>Classe tuple_element

Encapsula um elemento `tuple`. Elementos `array` e `pair` de encapsulamento de especializações.

## <a name="syntax"></a>Sintaxe

```cpp
// CLASS tuple_element (find element by index)
template <size_t Index, class Tuple>
   struct tuple_element;

// tuple_element for const
template <size_t Index, class Tuple>
   struct tuple_element<Index, const Tuple>;

// tuple_element for volatile
template <size_t Index, class Tuple>
   struct tuple_element<Index, volatile Tuple>;

// tuple_element for const volatile
template <size_t Index, class Tuple>
   struct tuple_element<Index, const volatile Tuple>;

// Helper typedef
template <size_t Index, class Tuple>
   using tuple_element_t = typename tuple_element<Index, Tuple>::type;

// Specialization for arrays
template <size_t Index, class Elem, size_t Size>
   struct tuple_element<Index, array<Elem, Size>>;

// Specializations for pairs
// struct to determine type of element 0 in pair
template <class T1, class T2>
   struct tuple_element<0, pair<T1, T2>>;

// struct to determine type of element 1 in pair
template <class T1, class T2>
   struct tuple_element<1, pair<T1, T2>>;
```

### <a name="parameters"></a>Parâmetros

*Index*\
O índice do elemento designado.

*Serem*\
O tipo da tupla.

*Elem*\
O tipo de um elemento de matriz.

*Tamanho*\
O tamanho da matriz.

*T1*\
O tipo do primeiro elemento em um par.

*T2*\
O tipo do segundo elemento em um par.

## <a name="remarks"></a>Comentários

O modelo de classe `tuple_element` tem um typedef aninhado `type` que é um sinônimo para o tipo no *índice* de índice da *tupla*do tipo de tupla.

O typedef `tuple_element_t` é um alias conveniente para `tuple_element<Index, Tuple>::type`.

A especialização de modelo de classe para matrizes fornece uma interface para um `array` como uma tupla de `Size` elementos, cada um dos quais tem o mesmo tipo. Cada especialização tem um typedef aninhado `type` que é um sinônimo para o tipo do elemento *index* do `array` , com quaisquer qualificações const-volatile preservadas.

As especializações de modelo para os tipos `pair` fornecem um único membro typedef, `type`, que é um sinônimo para o tipo de elemento na posição especificada no par, com qualquer qualificações constantes e/ou voláteis preservadas. O typedef `tuple_element_t` é um alias conveniente para `tuple_element<N, pair<T1, T2>>::type`.

Use o [ &lt; utilitário &gt; obter função](../standard-library/utility-functions.md#get) para retornar o elemento em uma posição especificada ou de um tipo especificado.

## <a name="example-get-an-element-from-a-tuple"></a>Exemplo: obter um elemento de uma tupla

```cpp
#include <tuple>
#include <string>
#include <iostream>

using namespace std;
typedef tuple<int, double, string> MyTuple;

int main() {
    MyTuple c0{ 0, 1.5, "Tail" };

    tuple_element_t<0, MyTuple> val = get<0>(c0); //get by index
    tuple_element_t<1, MyTuple> val2 = get<1>(c0);
    tuple_element_t<2, MyTuple> val3 = get<string>(c0); // get by type

    cout << val << " " << val2 << " " << val3 << endl;
}
```

```Output
0 1.5 Tail
```

## <a name="example-get-an-element-from-an-array"></a>Exemplo: obter um elemento de uma matriz

```cpp
#include <array>
#include <iostream>

using namespace std;
typedef array<int, 4> MyArray;

int main()
{
    MyArray c0 { 0, 1, 2, 3 };

    for (const auto& e : c0)
    {
        cout << e << " ";
    }
    cout << endl;

    // display first element "0"
    tuple_element<0, MyArray>::type val = c0.front();
    cout << val << endl;
}
```

```Output
0 1 2 3
0
```

## <a name="example-get-an-element-from-a-pair"></a>Exemplo: obter um elemento de um par

```cpp
#include <utility>
#include <iostream>

using namespace std;

typedef pair<int, double> MyPair;
int main() {
    MyPair c0(0, 1.333);

    // display contents "0 1"
    cout << get<0>(c0) << " ";
    cout << get<1>(c0) << endl;

    // display first element "0 " by index
    tuple_element<0, MyPair>::type val = get<0>(c0);
    cout << val << " ";

    // display second element by type
    tuple_element<1, MyPair>::type val2 = get<double>(c0);
    cout << val2 << endl;
}
```

```Output
0 1.333
0 1.333
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<tuple>

**Cabeçalho:** \<array> (para especialização de matriz)

**Cabeçalho:** \<utility> (para especializações de par)

**Namespace:** std
