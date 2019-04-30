---
title: Struct logical_not
ms.date: 11/04/2016
f1_keywords:
- functional/std::logical_not
helpviewer_keywords:
- logical_not class
- logical_not struct
ms.assetid: 892db678-31da-4540-974b-17b05efc0849
ms.openlocfilehash: 7fd554a28775a6b625332ac250a46171dd369f50
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413093"
---
# <a name="logicalnot-struct"></a>Struct logical_not

Um objeto de função predefinido que executa a lógica não operação (`operator!`) em seu argumento.

## <a name="syntax"></a>Sintaxe

```
template <class Type = void>
struct logical_not : public unary_function<Type, bool>
{
    bool operator()(const Type& Left) const;
};

// specialized transparent functor for operator!
template <>
struct logical_not<void>
{
  template <class Type>
  auto operator()(Type&& Left) const`
     -> decltype(!std::forward<Type>(Left));
};
```

### <a name="parameters"></a>Parâmetros

*Tipo*<br/>
Qualquer tipo que dê suporte a um `operator!` que usa um operando do tipo especificado ou inferido.

*Esquerda*<br/>
O operando da operação de expressão not lógica. O modelo não especializado usa um argumento de referência de lvalue do tipo *tipo*. O modelo especializado realiza o encaminhamento de lvalue perfeito e inferidos de argumentos de referência de rvalue do tipo *tipo*.

## <a name="return-value"></a>Valor de retorno

O resultado de `!Left`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator!`.

## <a name="example"></a>Exemplo

```cpp
// functional_logical_not.cpp
// compile with: /EHsc
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>

int main( )
{
   using namespace std;
   deque<bool> d1, d2 ( 7 );
   deque<bool>::iterator iter1, iter2;

   int i;
   for ( i = 0 ; i < 7 ; i++ )
   {
      d1.push_back((bool)((i % 2) != 0));
   }

   cout << boolalpha;    // boolalpha I/O flag on

   cout << "Original deque:\n d1 = ( " ;
   for ( iter1 = d1.begin( ) ; iter1 != d1.end( ) ; iter1++ )
      cout << *iter1 << " ";
   cout << ")" << endl;

   // To flip all the truth values of the elements,
   // use the logical_not function object
   transform( d1.begin( ), d1.end( ), d2.begin( ),logical_not<bool>( ) );
   cout << "The deque with its values negated is:\n d2 = ( " ;
   for ( iter2 = d2.begin( ) ; iter2 != d2.end( ) ; iter2++ )
      cout << *iter2 << " ";
   cout << ")" << endl;
}
/* Output:
Original deque:
d1 = ( false true false true false true false )
The deque with its values negated is:
d2 = ( true false true false true false true )
*/
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
