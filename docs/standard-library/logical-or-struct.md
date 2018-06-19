---
title: Struct logical_or | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- xfunctional/std::logical_or
dev_langs:
- C++
helpviewer_keywords:
- logical_or class
- logical_or struct
ms.assetid: ec8143f8-5755-4e7b-8025-507fb6bf6911
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9591e11774550f198de601f36fce0350f76cf6bd
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33852091"
---
# <a name="logicalor-struct"></a>Struct logical_or

Um objeto de função predefinido que executa a operação de disjunção lógica (`operator||`) em seus argumentos.

## <a name="syntax"></a>Sintaxe

```
template <class Type = void>
struct logical_or : public binary_function<Type, Type, bool>
{
    bool operator()(const Type& Left, const Type& Right) const;
 };

// specialized transparent functor for operator||
template <>
struct logical_or<void>
{
  template <class T, class U>
  auto operator()(T&& Left, U&& Right) const`
    -> decltype(std::forward<T>(Left) || std::forward<U>(Right));
 };
```

### <a name="parameters"></a>Parâmetros

`Type`, `T`, `U` Qualquer tipo que oferece suporte a um `operator||` que usa operandos dos tipos especificados ou inferidos.

`Left` O operando da esquerda da operação de disjunção lógica. O modelo não especializado usa um argumento de referência lvalue do tipo `Type`. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `T`.

`Right` O operando direito da operação de disjunção lógica. O modelo não especializado usa um argumento de referência lvalue do tipo `Type`. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `U`.

## <a name="return-value"></a>Valor de retorno

O resultado de `Left || Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator||`.

## <a name="remarks"></a>Comentários

Para tipos definidos pelo usuário, não há nenhum curto-circuito da avaliação do operando. Ambos os argumentos são avaliados por `operator||`.

## <a name="example"></a>Exemplo

```cpp
// functional_logical_or.cpp
// compile with: /EHsc
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>

int main( )
{
   using namespace std;
   deque <bool> d1, d2, d3( 7 );
   deque <bool>::iterator iter1, iter2, iter3;

   int i;
   for ( i = 0 ; i < 7 ; i++ )
   {
      d1.push_back((bool)((rand() % 2) != 0));
   }

   int j;
   for ( j = 0 ; j < 7 ; j++ )
   {
      d2.push_back((bool)((rand() % 2) != 0));
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

   // To find element-wise disjunction of the truth values
   // of d1 & d2, use the logical_or function object
   transform( d1.begin( ), d1.end( ), d2.begin( ),
      d3.begin( ), logical_or<bool>( ) );
   cout << "The deque which is the disjuction of d1 & d2 is:\n d3 = ( " ;
   for ( iter3 = d3.begin( ) ; iter3 != d3.end( ) ; iter3++ )
      cout << *iter3 << " ";
   cout << ")" << endl;
}
\* Output:
Original deque:
 d1 = ( true true false false true false false )
Original deque:
 d2 = ( false false false true true true true )
The deque which is the disjuction of d1 & d2 is:
 d3 = ( true true false true true true true )
*\

```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
