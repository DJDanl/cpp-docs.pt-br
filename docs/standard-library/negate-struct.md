---
title: Struct negate | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- negate
- xfunctional/std::negate
dev_langs:
- C++
helpviewer_keywords:
- negate struct
- negate class
ms.assetid: 8a372686-786e-4262-b37c-ca13dc11e62f
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 2d05749ba2837a3879c91886b9266de47dd2ece6
ms.openlocfilehash: 810861f1f1343d13b5e539a1a21206a72bcb3ec1
ms.lasthandoff: 02/25/2017

---
# <a name="negate-struct"></a>Struct negate
Um objeto de função predefinido que executa a operação de negação aritmética (`operator-` unário) em seu argumento.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Type = void>
struct negate : public unary_function<Type, Type>  
{
    Type operator()(const Type& Left) const;
};

// specialized transparent functor for unary operator-
template <>
struct negate<void>  
{
  template <class Type>
  auto operator()(Type&& Left) const`
    -> decltype(-std::forward<Type>(Left));
 };
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Type`  
 Qualquer tipo que dê suporte a um `operator-` que usa um operando do tipo especificado ou inferido.  
  
 `Left`  
 O operando que deve ser negado. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `Type`.  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado de `-``Left.`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado pelo unário `operator-`.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// functional_negate.cpp  
// compile with: /EHsc  
#include <vector>  
#include <functional>  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
  
int main( )  
{  
   vector <int> v1, v2 ( 8 );  
   vector <int>::iterator Iter1, Iter2;  
  
   int i;  
   for ( i = -2 ; i <= 5 ; i++ )  
   {  
      v1.push_back( 5 * i );  
   }  
  
   cout << "The vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
  
   // Finding the element-wise negatives of the vector v1  
   transform ( v1.begin( ),  v1.end( ), v2.begin( ), negate<int>( ) );  
  
   cout << "The negated elements of the vector = ( " ;  
   for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )  
      cout << *Iter2 << " ";  
   cout << ")" << endl;  
}  
\* Output:   
The vector v1 = ( -10 -5 0 5 10 15 20 25 )  
The negated elements of the vector = ( 10 5 0 -5 -10 -15 -20 -25 )  
*\  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




