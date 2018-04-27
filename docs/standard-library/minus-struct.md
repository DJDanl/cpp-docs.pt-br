---
title: Struct minus | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- xfunctional/std::minus
dev_langs:
- C++
helpviewer_keywords:
- minus struct
- minus class
ms.assetid: 7bce784e-2be6-413a-b516-004e9ecb2a39
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bc3c1a2f2f1695e92d8ff6d0583ea74b500422ef
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="minus-struct"></a>Struct minus

Um objeto de função predefinido que executa a operação de subtração (binário `operator-`) em seus argumentos.

## <a name="syntax"></a>Sintaxe

```
template <class Type = void>
struct minus : public binary_function <Type, Type, Type>
{
    Type operator()(const Type& Left, const Type& Right) const;
};

// specialized transparent functor for operator-
template <>
struct minus<void>
{
  template <class T, class U>
  auto operator()(T&& Left, U&& Right) const`
    -> decltype(std::forward<T>(Left) - std::forward<U>(Right));
 };
```

### <a name="parameters"></a>Parâmetros

`Type`, `T`, `U` Um tipo que oferece suporte a um binário `operator-` que usa operandos dos tipos especificados ou inferidos.

`Left` O operando da esquerda da operação. O modelo não especializado usa um argumento de referência lvalue do tipo `Type`. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `T`.

`Right` O operando direito da operação. O modelo não especializado usa um argumento de referência lvalue do tipo `Type`. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `U`.

## <a name="return-value"></a>Valor de retorno

O resultado de `Left - Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator-`.

## <a name="example"></a>Exemplo

```cpp
// functional_minus.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

int main( )
{
   vector <int> v1, v2, v3 ( 6 );
   vector <int>::iterator Iter1, Iter2, Iter3;

   int i;
   for ( i = 0 ; i <= 5 ; i++ )
   {
      v1.push_back( 4 * i + 1);
   }

   int j;
   for ( j = 0 ; j <= 5 ; j++ )
   {
      v2.push_back( 3 * j - 1);
   }

   cout << "The vector v1 = ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")" << endl;

   cout << "The vector v2 = ( " ;
   for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
      cout << *Iter2 << " ";
   cout << ")" << endl;

   // Finding the element-wise diference of the elements of v1 & v2
   transform ( v1.begin( ),  v1.end( ), v2.begin( ), v3.begin ( ),
      minus<int>( ) );

   cout << "The element-wise differences between v1 and v2 are: ( " ;
   for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )
      cout << *Iter3 << " ";
   cout << ")" << endl;
}
\* Output:
The vector v1 = ( 1 5 9 13 17 21 )
The vector v2 = ( -1 2 5 8 11 14 )
The element-wise differences between v1 and v2 are: ( 2 3 4 5 6 7 )
*\
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
