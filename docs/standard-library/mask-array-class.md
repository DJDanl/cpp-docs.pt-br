---
title: Classe mask_array
ms.date: 11/04/2016
f1_keywords:
- valarray/std::mask_array
helpviewer_keywords:
- mask_array class
ms.assetid: c49bed6a-3000-4f39-bff6-cb9a453acb0b
ms.openlocfilehash: 9da5e3593288be02819330e11b60e306784054dc
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68460148"
---
# <a name="maskarray-class"></a>Classe mask_array

Uma classe de modelo interno e auxiliar, que dá suporte para objetos que são subconjuntos dos valarrays pai, especificados com uma expressão booliana, ao fornecer operações entre as matrizes de subconjunto.

## <a name="syntax"></a>Sintaxe

## <a name="remarks"></a>Comentários

A classe descreve um objeto que armazena uma referência a um objeto `va` da classe [valarray](../standard-library/valarray-class.md) **\<do tipo >** , juntamente com um `ba` objeto da [classe\<valarray bool >](../standard-library/valarray-bool-class.md), que descreve o sequência de elementos a serem selecionados do `valarray<Type>` objeto.

Você constrói um `mask_array<Type>` objeto apenas escrevendo uma expressão no formato [VA&#91;BA&#93;](../standard-library/valarray-class.md#op_at). As funções de membro da classe mask_array se comportam como as assinaturas de `valarray<Type>`função correspondentes definidas para, exceto que apenas a sequência de elementos selecionados é afetada.

A sequência consiste em no máximo `ba.size` elementos. Um elemento *J* será incluído somente se **ba**[ *J*] for true. Portanto, há tantos elementos na sequência quanto os elementos verdadeiros em `ba`. Se `I` for o índice do elemento true mais baixo em `ba`, o **VA**[ `I`] será o elemento zero na sequência selecionada.

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
