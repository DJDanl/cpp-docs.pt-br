---
title: Classe mask_array
ms.date: 11/04/2016
f1_keywords:
- valarray/std::mask_array
helpviewer_keywords:
- mask_array class
ms.assetid: c49bed6a-3000-4f39-bff6-cb9a453acb0b
ms.openlocfilehash: 12398203d61f2c3ea155b5f6e6e7b118d4a13c75
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689398"
---
# <a name="mask_array-class"></a>Classe mask_array

Um modelo de classe auxiliar interno que dá suporte a objetos que são subconjuntos de valarrays pai, especificados com uma expressão booleana, fornecendo operações entre as matrizes de subconjuntos.

## <a name="syntax"></a>Sintaxe

## <a name="remarks"></a>Comentários

A classe descreve um objeto que armazena uma referência a um objeto `va` da classe [valarray](../standard-library/valarray-class.md)  **\<Type >** , juntamente com um objeto `ba` da classe [valarray \<bool](../standard-library/valarray-bool-class.md)>, que descreve a sequência de elementos a serem selecionados do objeto `valarray<Type>`.

Você constrói um objeto `mask_array<Type>` apenas escrevendo uma expressão no formato [VA&#91;BA&#93;](../standard-library/valarray-class.md#op_at). As funções de membro da classe mask_array se comportam como as assinaturas de função correspondentes definidas para `valarray<Type>`, exceto que apenas a sequência de elementos selecionados é afetada.

A sequência consiste em no máximo `ba.size` elementos. Um elemento *J* será incluído somente se **ba**[ *J*] for true. Portanto, há tantos elementos na sequência quanto os elementos verdadeiros em `ba`. Se `I` for o índice do elemento true mais baixo no `ba`, o **VA**[`I`] será o elemento zero na sequência selecionada.

## <a name="example"></a>Exemplo

```cpp
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

```Output
The initial operand valarray is:  (0 -1 2 -1 4 -1 6 -1 8 -1).
The modified operand valarray is:  (0 -1 2 -1 10 -1 10 -1 10 -1).
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<valarray>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
