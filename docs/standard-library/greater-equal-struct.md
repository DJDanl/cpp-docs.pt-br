---
title: Struct greater_equal
ms.date: 11/04/2016
f1_keywords:
- functional/std::greater_equal
helpviewer_keywords:
- greater_equal struct
- greater_equal function
ms.assetid: a8ba911b-7af8-4653-b972-d8618f4df7d5
ms.openlocfilehash: f09364203c905407d8ce4607f527d58108eec778
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68243742"
---
# <a name="greaterequal-struct"></a>Struct greater_equal

Um predicado binário que executa a operação maior que-ou-igual a (`operator>=`) em seus argumentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type = void>
struct greater_equal : public binary_function <Type, Type, bool>
{
    bool operator()(const Type& Left, const Type& Right) const;
};

// specialized transparent functor for operator>=
template <>
struct greater_equal<void>
{
  template <class T, class U>
  auto operator()(T&& Left, U&& Right) const`
    -> decltype(std::forward<T>(Left)>= std::forward<U>(Right));
};
```

### <a name="parameters"></a>Parâmetros

*Tipo de*, *T*, *U*\
Qualquer tipo que dê suporte a um `operator>=` que usa operandos dos tipos especificados ou inferidos.

*À esquerda*\
O operando esquerdo da operação "maior ou igual a". O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *T*.

*Certo*\
O operando direito da operação "maior ou igual a". O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *U*.

## <a name="return-value"></a>Valor de retorno

O resultado de `Left >= Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator>=`.

## <a name="remarks"></a>Comentários

O predicado binário `greater_equal` < `Type`> fornece uma ordenação fraca estrita de um conjunto de valores de elemento do tipo *tipo* em classes de equivalência, se e somente se esse tipo satisfizer o padrão de matemático requisitos para ser ordenado dessa forma. As especializações de qualquer tipo de ponteiro produzem uma ordenação total dos elementos, pois todos os elementos de valores distintos são ordenados em relação uns aos outros.

## <a name="example"></a>Exemplo

```cpp
// functional_greater_equal.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator Iter1;

   int i;
   v1.push_back( 6262 );
   v1.push_back( 6262 );
   for ( i = 0 ; i < 5 ; i++ )
   {
      v1.push_back( rand( ) );
   }

   cout << "Original vector v1 = ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")" << endl;

   // To sort in ascending order,
   // use default binary predicate less<int>( )
   sort( v1.begin( ), v1.end( ) );
   cout << "Sorted vector v1 = ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")" << endl;

   // To sort in descending order,
   // specify binary predicate greater_equal<int>( )
   sort( v1.begin( ), v1.end( ), greater_equal<int>( ) );
   cout << "Resorted vector v1 = ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")" << endl;
}
```

```Output
Original vector v1 = (6262 6262 41 18467 6334 26500 19169)
Sorted vector v1 = (41 6262 6262 6334 18467 19169 26500)
Resorted vector v1 = (26500 19169 18467 6334 6262 6262 41)
```
