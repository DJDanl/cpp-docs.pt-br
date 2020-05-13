---
title: Struct logical_and
ms.date: 11/04/2016
f1_keywords:
- functional/std::logical_and
helpviewer_keywords:
- logical_and class
- logical_and struct
ms.assetid: 1a375cc2-0592-4d57-a553-78009c7ad610
ms.openlocfilehash: 7036ebf9fed3877a395e44d8383776002b9afcae
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351685"
---
# <a name="logical_and-struct"></a>Struct logical_and

Um objeto de função predefinido que`operator&&`executa a operação de conjunção lógica ( ) em seus argumentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type = void>
struct logical_and : public binary_function<Type, Type, bool>
{
    bool operator()(const Type& Left, const Type& Right) const;
};

// specialized transparent functor for operator&&
template <>
struct logical_and<void>
{
  template <class T, class U>
  auto operator()(T&& Left, U&& Right) const`
    -> decltype(std::forward<T>(Left) && std::forward<U>(Right));
};
```

### <a name="parameters"></a>Parâmetros

*Tipo,* *T,* *U*\
Qualquer tipo que dê suporte a um `operator&&` que usa operandos dos tipos especificados ou inferidos.

*Deixou*\
O operando à esquerda da operação de conjunção lógica. O modelo não especializado leva um argumento de referência de valor do *tipo Tipo*. O modelo especializado faz um encaminhamento perfeito de argumentos de referência de valor e valor de valor do tipo *T*inferido .

*Certo*\
O operando à direita da operação de conjunção lógica. O modelo não especializado leva um argumento de referência de valor do *tipo Tipo*. O modelo especializado faz o encaminhamento perfeito de argumentos de referência de valor e valor de valor do tipo *U*inferido .

## <a name="return-value"></a>Valor retornado

O resultado de `Left && Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator&&`.

## <a name="remarks"></a>Comentários

Para tipos definidos pelo usuário, não há nenhum curto-circuito da avaliação do operando. Ambos os argumentos são avaliados por `operator&&`.

## <a name="example"></a>Exemplo

```cpp
// functional_logical_and.cpp
// compile with: /EHsc

#define _CRT_RAND_S
#include <stdlib.h>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>

int main( )
{
   using namespace std;
   deque<bool> d1, d2, d3( 7 );
   deque<bool>::iterator iter1, iter2, iter3;

   unsigned int randomValue;

   int i;
   for ( i = 0 ; i < 7 ; i++ )
   {
      if ( rand_s( &randomValue ) == 0 )
      {
         d1.push_back((bool)(( randomValue % 2 ) != 0));
      }

   }

   int j;
   for ( j = 0 ; j < 7 ; j++ )
   {
      if ( rand_s( &randomValue ) == 0 )
      {
         d2.push_back((bool)(( randomValue % 2 ) != 0));
      }
   }

   cout << boolalpha;    // boolalpha I/O flag on

   cout << "Original deque:\n d1 = ( " ;
   for ( iter1 = d1.begin( ) ; iter1 != d1.end( ) ; iter1++ )
      cout << *iter1 << " ";
   cout << ")" << endl;

   cout << "Original deque:\n d2 = ( " ;
   for ( iter2 = d2.begin( ) ; iter2 != d2.end( ) ; iter2++ )
      cout << *iter2 << " ";
   cout << ")" << endl;

   // To find element-wise conjunction of the truth values
   // of d1 & d2, use the logical_and function object
   transform( d1.begin( ), d1.end( ), d2.begin( ),
      d3.begin( ), logical_and<bool>( ) );
   cout << "The deque which is the conjunction of d1 & d2 is:\n d3 = ( " ;
   for ( iter3 = d3.begin( ) ; iter3 != d3.end( ) ; iter3++ )
      cout << *iter3 << " ";
   cout << ")" << endl;
}
```

```Output
Original deque:
d1 = ( true true true true true false false )
Original deque:
d2 = ( true false true true false true false )
The deque which is the conjunction of d1 & d2 is:
d3 = ( true false true true false false false )
```
