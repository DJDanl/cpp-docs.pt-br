---
title: Operador const_cast
ms.date: 11/04/2016
f1_keywords:
- const_cast_cpp
helpviewer_keywords:
- const_cast keyword [C++]
ms.assetid: 4d8bb203-ef33-4a10-9f9f-c64d4fbc1687
ms.openlocfilehash: 36de296d1e871ca759108497922973ddea8e3382
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227550"
---
# <a name="const_cast-operator"></a>Operador const_cast

Remove os **`const`** **`volatile`** atributos, e **`__unaligned`** de uma classe.

## <a name="syntax"></a>Sintaxe

```
const_cast <type-id> (expression)
```

## <a name="remarks"></a>Comentários

Um ponteiro para qualquer tipo de objeto ou um ponteiro para um membro de dados pode ser explicitamente convertido em um tipo que seja idêntico, exceto para os **`const`** **`volatile`** **`__unaligned`** qualificadores, e. Para ponteiros e referências, o resultado fará referência ao objeto original. Para ponteiros para membros de dados, o resultado fará referência ao mesmo membro que o ponteiro original (não convertido) para o membro de dados. Dependendo do tipo do objeto referenciado, uma operação de gravação pelo ponteiro, referência ou ponteiro para o membro de dados resultante pode gerar comportamento indefinido.

Você não pode usar o **`const_cast`** operador para substituir diretamente o status constante de uma variável constante.

O **`const_cast`** operador converte um valor de ponteiro nulo para o valor de ponteiro nulo do tipo de destino.

## <a name="example"></a>Exemplo

```cpp
// expre_const_cast_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class CCTest {
public:
   void setNumber( int );
   void printNumber() const;
private:
   int number;
};

void CCTest::setNumber( int num ) { number = num; }

void CCTest::printNumber() const {
   cout << "\nBefore: " << number;
   const_cast< CCTest * >( this )->number--;
   cout << "\nAfter: " << number;
}

int main() {
   CCTest X;
   X.setNumber( 8 );
   X.printNumber();
}
```

Na linha que contém o **`const_cast`** , o tipo de dados do **`this`** ponteiro é `const CCTest *` . O **`const_cast`** operador altera o tipo de dados do **`this`** ponteiro para `CCTest *` , permitindo que o membro `number` seja modificado. A conversão só durará pelo restante da instrução em que aparece.

## <a name="see-also"></a>Confira também

[Operadores de conversão](../cpp/casting-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
