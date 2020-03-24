---
title: Operador reinterpret_cast
ms.date: 11/04/2016
f1_keywords:
- reinterpret_cast_cpp
helpviewer_keywords:
- reinterpret_cast keyword [C++]
ms.assetid: eb3283c7-7f88-467e-affd-407d37b46d6c
ms.openlocfilehash: 34c2fcb0e1f7f4df4e207d1737afc9c42e011feb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188279"
---
# <a name="reinterpret_cast-operator"></a>Operador reinterpret_cast

Permite que qualquer ponteiro seja convertido em outro tipo de ponteiro. Também permite que qualquer tipo integral seja convertido em qualquer tipo de ponteiro e vice-versa.

## <a name="syntax"></a>Sintaxe

```
reinterpret_cast < type-id > ( expression )
```

## <a name="remarks"></a>Comentários

O uso indevido do operador **reinterpret_cast** pode ser facilmente inseguro. A menos que a conversão desejada seja inerentemente de nível baixo, você deve usar um dos outros operadores de conversão.

O operador de **reinterpret_cast** pode ser usado para conversões, como `char*` para `int*`ou `One_class*` para `Unrelated_class*`, que são inerentemente inseguras.

O resultado de uma **reinterpret_cast** não pode ser usado com segurança para nada além de ser convertido em seu tipo original. Outros usos são, na melhor das hipóteses, não portáteis.

O operador de **reinterpret_cast** não pode converter os atributos **const**, **volatile**ou **__unaligned** . Consulte [operador de const_cast](../cpp/const-cast-operator.md) para obter informações sobre como remover esses atributos.

O operador **reinterpret_cast** converte um valor de ponteiro nulo para o valor de ponteiro nulo do tipo de destino.

Um uso prático de **reinterpret_cast** está em uma função de hash, que mapeia um valor para um índice de forma que dois valores distintos raramente terminem com o mesmo índice.

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

O **reinterpret_cast** permite que o ponteiro seja tratado como um tipo integral. O resultado de bit é deslocado e recebe XOR para gerar um índice exclusivo (exclusivo para um alto nível de probabilidade). O índice é truncado em seguida por uma conversão padrão do estilo C para o tipo de retorno de função.

## <a name="see-also"></a>Confira também

[Operadores de conversão](../cpp/casting-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
