---
title: Classe indirect_array
ms.date: 11/04/2016
f1_keywords:
- valarray/std::indirect_array
helpviewer_keywords:
- indirect_array class
ms.assetid: 10e1eaea-ba5a-405c-a25e-7bdd3eee7fc7
ms.openlocfilehash: 5db5f2ce60038267b70ae8e77d9dd929d972af6a
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456336"
---
# <a name="indirectarray-class"></a>Classe indirect_array

Uma classe de modelo auxiliar interna, que dá suporte a objetos que são subconjuntos de valarrays fornecendo operações entre matrizes de subconjunto definidas pela especificação de um subconjunto de índices de uma valarray pai.

## <a name="syntax"></a>Sintaxe

## <a name="remarks"></a>Comentários

A classe descreve um objeto que armazena uma referência a um objeto `va` da classe [valarray](../standard-library/valarray-class.md) **\<do tipo >** , juntamente com um `xa` objeto da `valarray<size_t>`classe, que descreve a sequência de elementos a serem selecionados o `valarray<Type>` objeto.

Você constrói um `indirect_array<Type>` objeto apenas escrevendo uma expressão do formulário. `va[xa]` As funções de membro da classe indirect_array se comportam como as assinaturas de `valarray<Type>`função correspondentes definidas para, exceto que apenas a sequência de elementos selecionados é afetada.

A sequência consiste em **XA.** elementos de [tamanho](../standard-library/valarray-class.md#size) , em `I` que o elemento se torna `I`o índice `va` **XA**[] em.

## <a name="example"></a>Exemplo:

```cpp
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

```cpp
The initial operand valarray is:  (0 -1 2 -1 4 -1 6 -1 8 -1).
The modified operand valarray is:  (0 -1 10 -1 10 -1 10 -1 8 -1).
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<valarray>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
