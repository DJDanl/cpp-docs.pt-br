---
title: Struct equal_to | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- equal_to
- xfunctional/std::equal_to
dev_langs:
- C++
helpviewer_keywords:
- equal_to function
- equal_to struct
ms.assetid: 8e4f2b50-b2db-48e3-b4cc-6cc03362c2a6
caps.latest.revision: 17
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4ecf60434799708acab4726a95380a2d3b9dbb3a
ms.openlocfilehash: bac0d0114b10fc4ac7a83a60f21db5218cb3f1c8
ms.contentlocale: pt-br
ms.lasthandoff: 04/19/2017

---
# <a name="equalto-struct"></a>Struct equal_to
Um predicado binário que executa a operação de igualdade ( `operator==`) em seus argumentos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type = void>  
struct equal_to : public binary_function<Type, Type, bool>   
 {  
    bool operator()(const Type& Left, const Type& Right) const; 
 };  
 
// specialized transparent functor for operator== 
template <>  
struct equal_to<void>  
 {  
    template <class T, class U>  
    auto operator()(T&& Left, U&& Right) const 
      ->  decltype(std::forward<T>(Left) == std::forward<U>(Right));
 };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Type`, `T`, `U`  
 Qualquer tipo que dê suporte a um `operator==` que usa operandos dos tipos especificados ou inferidos.  
  
 `Left`  
 O operando esquerdo da operação de igualdade. O modelo não especializado usa um argumento de referência lvalue do tipo `Type`. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `T`.  
  
 `Right`  
 O operando direito da operação de igualdade. O modelo não especializado usa um argumento de referência lvalue do tipo `Type`. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `U`.  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado de `Left``==``Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator==`.  
  
## <a name="remarks"></a>Comentários  
 Os objetos do tipo `Type` devem ser comparáveis por igualdade. Isso requer que o `operator==` definido no conjunto de objetos atenda às propriedades matemáticas de uma relação de equivalência. Todos os tipos numéricos internos e de ponteiro atendem a esse requisito.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// functional_equal_to.cpp  
// compile with: /EHsc  
#include <vector>  
#include <functional>  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
  
int main( )  
{  
   vector <double> v1, v2, v3 ( 6 );  
   vector <double>::iterator Iter1, Iter2, Iter3;  
  
   int i;  
   for ( i = 0 ; i <= 5 ; i+=2 )  
   {  
      v1.push_back( 2.0 *i );  
      v1.push_back( 2.0 * i + 1.0 );  
   }  
  
   int j;  
   for ( j = 0 ; j <= 5 ; j+=2 )  
   {  
      v2.push_back( - 2.0 * j );  
      v2.push_back( 2.0 * j + 1.0 );  
   }  
  
   cout << "The vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
  
   cout << "The vector v2 = ( " ;  
   for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )  
      cout << *Iter2 << " ";  
   cout << ")" << endl;  
  
   // Testing for the element-wise equality between v1 & v2  
   transform ( v1.begin( ),  v1.end( ), v2.begin( ), v3.begin ( ),   
      equal_to<double>( ) );  
  
   cout << "The result of the element-wise equal_to comparison\n"  
      << "between v1 & v2 is: ( " ;  
   for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )  
      cout << *Iter3 << " ";  
   cout << ")" << endl;  
}  
```  
  
```Output  
The vector v1 = ( 0 1 4 5 8 9 )  
The vector v2 = ( -0 1 -4 5 -8 9 )  
The result of the element-wise equal_to comparison  
between v1 & v2 is: ( 1 1 0 1 0 1 )  
```


