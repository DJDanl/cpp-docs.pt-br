---
title: Classe indirect_array | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- valarray/std::indirect_array
- indirect_array
dev_langs:
- C++
helpviewer_keywords:
- indirect_array class
ms.assetid: 10e1eaea-ba5a-405c-a25e-7bdd3eee7fc7
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e14830a700a6b543fa0baa65a4e628d9e10bddab
ms.lasthandoff: 02/25/2017

---
# <a name="indirectarray-class"></a>Classe indirect_array
Uma classe de modelo auxiliar interna, que dá suporte a objetos que são subconjuntos de valarrays fornecendo operações entre matrizes de subconjunto definidas pela especificação de um subconjunto de índices de uma valarray pai.  
  
## <a name="syntax"></a>Sintaxe  
  
  
  
## <a name="remarks"></a>Comentários  
 A classe descreve um objeto que armazena uma referência a um objeto **va** da classe [valarray](../standard-library/valarray-class.md)**\<Type>**, bem como um objeto **xa** da classe **valarray<size_t>**, que descreve a sequência de elementos a serem selecionados do objeto **valarray\<Type>**.  
  
 Você constrói um objeto **indirect_array\<Type>** apenas escrevendo uma expressão no formato **va[xa]**. As funções membro da classe indirect_array, então, se comportam como as assinaturas de função correspondentes definidas para **valarray\<Type>**, exceto pelo fato de somente a sequência de elementos selecionados ser afetada.  
  
 A sequência consiste em elementos **xa.**[size](../standard-library/valarray-class.md#valarray__size), em que o elemento `I` torna-se o índice **xa**[ `I`] dentro de **va**.  
  
## <a name="example"></a>Exemplo:  
  
```  
// indirect_array.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> va ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      va [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      va [ i ] =  -1;  
  
   cout << "The initial operand valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va [ i ] << " ";  
   cout << ")." << endl;  
  
   // Select 2nd, 4th & 6th elements  
   // and assign a value of 10 to them  
   valarray<size_t> indx ( 3 );  
   indx [0] = 2;  
   indx [1] = 4;  
   indx [2] = 6;  
   va[indx] = 10;  
  
   cout << "The modified operand valarray is:  ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << va [ i ] << " ";  
   cout << ")." << endl;  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
The initial operand valarray is:  (0 -1 2 -1 4 -1 6 -1 8 -1).  
The modified operand valarray is:  (0 -1 10 -1 10 -1 10 -1 8 -1).  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<valarray>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


