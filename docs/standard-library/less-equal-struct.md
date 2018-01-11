---
title: Struct less_equal | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xfunctional/std::less_equal
dev_langs: C++
helpviewer_keywords:
- less_equal function
- less_equal struct
ms.assetid: 32085782-c7e0-4310-9b40-8aa3c1bff211
caps.latest.revision: "23"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 15a4d46b299ddaf99db8f39c39caaec233f8747e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="lessequal-struct"></a>Struct less_equal
Um predicado binário que executa a operação "menor ou igual a" (`operator<=`) em seus argumentos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Type = void>
struct less_equal : public binary_function <Type, Type, bool>  
{
    bool operator()(const Type& Left, const Type& Right) const;
};

// specialized transparent functor for operator<=
template <>
struct less_equal<void>  
{
  template <class T, class U>
  auto operator()(T&& Left, U&& Right) const`
    -> decltype(std::forward<T>(Left) <= std::forward<U>(Right));
};
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Type`, `T`, `U`  
 Qualquer tipo que dê suporte a um `operator<=` que usa operandos dos tipos especificados ou inferidos.  
  
 `Left`  
 O operando esquerdo da operação "menor ou igual a". O modelo não especializado usa um argumento de referência lvalue do tipo `Type`. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `T`.  
  
 `Right`  
 O operando direito da operação "menor ou igual a". O modelo não especializado usa um argumento de referência lvalue do tipo `Type`. O modelo especializado realiza o encaminhamento perfeito dos argumentos de referência lvalue e rvalue do tipo inferido `U`.  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado de `Left <= Right`. O modelo especializado realiza o encaminhamento perfeito do resultado, que tem o tipo retornado por `operator<=`.  
  
## <a name="remarks"></a>Comentários  
 O predicado binário `less_equal`< `Type`> fornece uma ordenação fraca estrita de um conjunto de valores de elemento do tipo `Type` em classes de equivalência, se e somente se esse tipo atender aos requisitos matemáticos padrão para ser ordenado dessa forma. As especializações de qualquer tipo de ponteiro produzem uma ordenação total dos elementos, pois todos os elementos de valores distintos são ordenados em relação uns aos outros.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// functional_less_equal.cpp  
// compile with: /EHsc  
#define _CRT_RAND_S  
#include <stdlib.h>  
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
   vector <int>::reverse_iterator rIter1;  
   unsigned int randomNumber;  
  
   int i;  
   for ( i = 0 ; i < 5 ; i++ )  
   {  
      if ( rand_s( &randomNumber ) == 0 )  
      {  
         // Convert the random number to be between 1 - 50000  
         // This is done for readability purposes  
         randomNumber = ( unsigned int) ((double)randomNumber /   
            (double) UINT_MAX * 50000) + 1;  
  
         v1.push_back( randomNumber );  
      }  
   }  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      v1.push_back( 2836 );  
   }  
  
   cout << "Original vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
  
   // To sort in ascending order,  
   // use the binary predicate less_equal<int>( )  
   sort( v1.begin( ), v1.end( ), less_equal<int>( ) );  
   cout << "Sorted vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
}  
```  
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```
Original vector v1 = (31247 37154 48755 15251 6205 2836 2836 2836)
Sorted vector v1 = (2836 2836 2836 6205 15251 31247 37154 48755)
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



