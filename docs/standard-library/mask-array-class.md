---
title: Classe mask_array | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- valarray/std::mask_array
dev_langs:
- C++
helpviewer_keywords:
- mask_array class
ms.assetid: c49bed6a-3000-4f39-bff6-cb9a453acb0b
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 882091956f9d9c5985e3bfacfe015ff81e84ac6c
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="maskarray-class"></a>Classe mask_array
Uma classe de modelo interno e auxiliar, que dá suporte para objetos que são subconjuntos dos valarrays pai, especificados com uma expressão booliana, ao fornecer operações entre as matrizes de subconjunto.  
  
## <a name="syntax"></a>Sintaxe  
  
  
  
## <a name="remarks"></a>Comentários  
 A classe descreve um objeto que armazena uma referência a um objeto **va** da classe [valarray](../standard-library/valarray-class.md)**\<Type>**, bem como um objeto **ba** da classe [valarray\<bool>](../standard-library/valarray-bool-class.md), que descreve a sequência de elementos a serem selecionados do objeto **valarray\<Type>**.  
  
 Você cria um objeto **mask_array\<Type>** apenas escrevendo uma expressão no formato [va&#91;ba&#93;](../standard-library/valarray-class.md#op_at). As funções de membro da classe mask_array, então, se comportam como as assinaturas de função correspondentes definidas para **valarray\<Type>**, exceto pelo fato de somente a sequência de elementos selecionados ser afetada.  
  
 A sequência consiste, em sua maioria, de elementos **ba.size**. Um elemento *J* será incluído somente se **ba**[ *J*] for true. Portanto, há tantos elementos na sequência quanto há elementos true em **ba**. Se `I` for o índice do menor elemento true em **ba**, então **va**[ `I`] será o elemento zero na sequência selecionada.  
  
## <a name="example"></a>Exemplo:  
  
```  
// mask_array.cpp  
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
  
   // Use masked subsets to assign a value of 10  
   // to all elements grrater than 3 in value  
   va [va > 3 ] = 10;  
   cout << "The modified operand valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va [ i ] << " ";  
   cout << ")." << endl;  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
The initial operand valarray is:  (0 -1 2 -1 4 -1 6 -1 8 -1).  
The modified operand valarray is:  (0 -1 2 -1 10 -1 10 -1 10 -1).  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<valarray>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


