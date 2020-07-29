---
title: Operador reinterpret_cast
ms.date: 11/04/2016
f1_keywords:
- reinterpret_cast_cpp
helpviewer_keywords:
- reinterpret_cast keyword [C++]
ms.assetid: eb3283c7-7f88-467e-affd-407d37b46d6c
ms.openlocfilehash: 33da7427adeb0a0cade2a369664d7fbd34790681
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233594"
---
# <a name="reinterpret_cast-operator"></a>Operador reinterpret_cast

Permite que qualquer ponteiro seja convertido em outro tipo de ponteiro. Também permite que qualquer tipo integral seja convertido em qualquer tipo de ponteiro e vice-versa.

## <a name="syntax"></a>Sintaxe

```
reinterpret_cast < type-id > ( expression )
```

## <a name="remarks"></a>Comentários

O uso indevido do **`reinterpret_cast`** operador pode ser facilmente inseguro. A menos que a conversão desejada seja inerentemente de nível baixo, você deve usar um dos outros operadores de conversão.

O **`reinterpret_cast`** operador pode ser usado para conversões, como **`char*`** para **`int*`** , ou `One_class*` para `Unrelated_class*` , que são inerentemente inseguras.

O resultado de um **`reinterpret_cast`** não pode ser usado com segurança para qualquer coisa que não seja a conversão de volta para seu tipo original. Outros usos são, na melhor das hipóteses, não portáteis.

O **`reinterpret_cast`** operador não pode converter os **`const`** **`volatile`** atributos, ou **`__unaligned`** . Consulte [operador de const_cast](../cpp/const-cast-operator.md) para obter informações sobre como remover esses atributos.

O **`reinterpret_cast`** operador converte um valor de ponteiro nulo para o valor de ponteiro nulo do tipo de destino.

Um uso prático do **`reinterpret_cast`** é em uma função de hash, que mapeia um valor para um índice de forma que dois valores distintos raramente terminem com o mesmo índice.

```cpp
#include <iostream>
using namespace std;

// Returns a hash code based on an address
unsigned short Hash( void *p ) {
   unsigned int val = reinterpret_cast<unsigned int>( p );
   return ( unsigned short )( val ^ (val >> 16));
}

using namespace std;
int main() {
   int a[20];
   for ( int i = 0; i < 20; i++ )
      cout << Hash( a + i ) << endl;
}

Output:
64641
64645
64889
64893
64881
64885
64873
64877
64865
64869
64857
64861
64849
64853
64841
64845
64833
64837
64825
64829
```

O **`reinterpret_cast`** permite que o ponteiro seja tratado como um tipo integral. O resultado de bit é deslocado e recebe XOR para gerar um índice exclusivo (exclusivo para um alto nível de probabilidade). O índice é truncado em seguida por uma conversão padrão do estilo C para o tipo de retorno de função.

## <a name="see-also"></a>Confira também

[Operadores de conversão](../cpp/casting-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
