---
title: Operador const_cast
ms.date: 11/04/2016
f1_keywords:
- const_cast_cpp
helpviewer_keywords:
- const_cast keyword [C++]
ms.assetid: 4d8bb203-ef33-4a10-9f9f-c64d4fbc1687
ms.openlocfilehash: 389ef84149031fd602ff9ded15d34869258ffd52
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399103"
---
# <a name="constcast-operator"></a>Operador const_cast

Remove o **const**, **volátil**, e **unaligned** atributos de uma classe.

## <a name="syntax"></a>Sintaxe

```
const_cast <type-id> (expression)
```

## <a name="remarks"></a>Comentários

Um ponteiro para qualquer tipo de objeto ou um ponteiro para um membro de dados pode ser explicitamente convertido para um tipo que é idêntico, exceto para o **const**, **volátil**, e **unaligned** qualificadores. Para ponteiros e referências, o resultado fará referência ao objeto original. Para ponteiros para membros de dados, o resultado fará referência ao mesmo membro que o ponteiro original (não convertido) para o membro de dados. Dependendo do tipo do objeto referenciado, uma operação de gravação pelo ponteiro, referência ou ponteiro para o membro de dados resultante pode gerar comportamento indefinido.

Não é possível usar o **const_cast** operador para substituir diretamente o status de uma variáveis constante.

O **const_cast** operador converte um valor de ponteiro nulo para o valor de ponteiro nulo do tipo de destino.

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

Na linha que contém o **const_cast**, o tipo de dados de **isso** ponteiro é `const CCTest *`. O **const_cast** operador altera o tipo de dados das **isso** ponteiro para `CCTest *`, permitindo que o membro `number` a ser modificado. A conversão só durará pelo restante da instrução em que aparece.

## <a name="see-also"></a>Consulte também

[Operadores de conversão](../cpp/casting-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)