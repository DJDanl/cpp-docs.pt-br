---
title: Estrutura pair
ms.date: 11/04/2016
f1_keywords:
- utility/std::pair
helpviewer_keywords:
- pair class
ms.assetid: 539d3d67-80a2-4170-b347-783495d42109
ms.openlocfilehash: e66ee5dd39628065e52eb95a89e1cd81272a6b86
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520921"
---
# <a name="pair-structure"></a>Estrutura pair

Uma estrutura que fornece a capacidade de tratar os dois objetos como um único objeto.

## <a name="syntax"></a>Sintaxe

```cpp
struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;
    constexpr pair();
    pair(const pair&) = default;
    pair(pair&&) = default;
    constexpr pair(
        const T1& Val1,
        const T2& Val2);

    template <class Other1, class Other2>
    constexpr pair(const pair<Other1, Other2>& Right);

    template <class Other1, class Other2>
    constexpr pair(const pair <Other1 Val1, Other2 Val2>&& Right);

    template <class Other1, class Other2>
    constexpr pair(Other1&& Val1, Other2&& Val2);

    template <class... Args1, class... Args2>
    pair(piecewise_construct_t, tuple<Args1...> first_args, tuple<Args2...> second_args);

    pair& operator=(const pair& p);
    template<class U1, class U2> pair& operator=(const pair<U1, U2>& p);
    pair& operator=(pair&& p) noexcept(see below );
    template<class U1, class U2> pair& operator=(pair<U1, U2>&& p);

    void swap(pair& p) noexcept(see below );
};

template<class T1, class T2>
    pair(T1, T2) -> pair<T1, T2>;
```

### <a name="parameters"></a>Parâmetros

*Val1*\
O valor que inicializa o primeiro elemento de `pair`.

*Val2*\
O valor que inicializa o segundo elemento de `pair`.

*Certo*\
Um par cujos valores devem ser usados para inicializar os elementos de outro par.

## <a name="return-value"></a>Valor retornado

O primeiro Construtor (padrão) inicializa o primeiro elemento do par para o padrão do tipo `T1` e o segundo elemento como padrão do tipo `T2` .

O segundo construtor inicializa o primeiro elemento do par para *val1* e segundo para *Val2.*

O terceiro construtor (modelo) inicializa o primeiro elemento do par para `Right`. **primeiro** e segundo para `Right`. **segundo**.

O quarto construtor inicializa o primeiro elemento do par para *val1* e segundo para *Val2* usando o [Declarador de referência rvalue:  &&](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="remarks"></a>Comentários

A estrutura de modelo armazena um par de objetos do tipo `T1` e `T2` , respectivamente. O tipo `first_type` é o mesmo que o parâmetro de modelo `T1` e o tipo `second_type` é o mesmo que o parâmetro de modelo `T2` . `T1`e `T2` cada uma delas precisa fornecer apenas um construtor padrão, um construtor de argumento único e um destruidor. Todos os membros do tipo `pair` são públicos, pois o tipo é declarado como um **`struct`** e não como um **`class`** . Os dois usos mais comuns para um par são como tipos de retorno para funções que retornam dois valores e como elementos para as classes de contêiner associativo [Classe map](../standard-library/map-class.md) e [Classe multimap](../standard-library/multimap-class.md) que têm uma chave e um tipo de valor associado a cada elemento. O último satisfaz os requisitos para um contêiner associativo de par e tem um tipo de valor do formulário `pair< const key_type, mapped_type >` .

## <a name="example"></a>Exemplo

```cpp
// utility_pair.cpp
// compile with: /EHsc
#include <utility>
#include <map>
#include <iomanip>
#include <iostream>

int main( )
{
   using namespace std;

   // Using the constructor to declare and initialize a pair
   pair <int, double> p1 ( 10, 1.1e-2 );

   // Compare using the helper function to declare and initialize a pair
   pair <int, double> p2;
   p2 = make_pair ( 10, 2.22e-1 );

   // Making a copy of a pair
   pair <int, double> p3 ( p1 );

   cout.precision ( 3 );
   cout << "The pair p1 is: ( " << p1.first << ", "
        << p1.second << " )." << endl;
   cout << "The pair p2 is: ( " << p2.first << ", "
        << p2.second << " )." << endl;
   cout << "The pair p3 is: ( " << p3.first << ", "
        << p3.second << " )." << endl;

   // Using a pair for a map element
   map <int, int> m1;
   map <int, int>::iterator m1_Iter;

   typedef pair <int, int> Map_Int_Pair;

   m1.insert ( Map_Int_Pair ( 1, 10 ) );
   m1.insert ( Map_Int_Pair ( 2, 20 ) );
   m1.insert ( Map_Int_Pair ( 3, 30 ) );

   cout << "The element pairs of the map m1 are:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " ( " << m1_Iter -> first << ", "
           << m1_Iter -> second << " )";
   cout   << "." << endl;

   // Using pair as a return type for a function
   pair< map<int,int>::iterator, bool > pr1, pr2;
   pr1 = m1.insert ( Map_Int_Pair ( 4, 40 ) );
   pr2 = m1.insert ( Map_Int_Pair (1, 10 ) );

   if( pr1.second == true )
   {
      cout << "The element (4,40) was inserted successfully in m1."
           << endl;
   }
   else
   {
      cout << "The element with a key value of\n"
           << " ( (pr1.first) -> first ) = " << ( pr1.first ) -> first
           << " is already in m1,\n so the insertion failed." << endl;
   }

   if( pr2.second == true )
   {
      cout << "The element (1,10) was inserted successfully in m1."
           << endl;
   }
   else
   {
      cout << "The element with a key value of\n"
           << " ( (pr2.first) -> first ) = " << ( pr2.first ) -> first
           << " is already in m1,\n so the insertion failed." << endl;
   }
}
```

```Output
The pair p1 is: ( 10, 0.011 ).
The pair p2 is: ( 10, 0.222 ).
The pair p3 is: ( 10, 0.011 ).
The element pairs of the map m1 are: ( 1, 10 ) ( 2, 20 ) ( 3, 30 ).
The element (4,40) was inserted successfully in m1.
The element with a key value of
( (pr2.first) -> first ) = 1 is already in m1,
so the insertion failed.
```
