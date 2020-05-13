---
title: 'Operadores aditivos: + e -'
ms.date: 11/04/2016
f1_keywords:
- +
- '-'
helpviewer_keywords:
- operators [C++], addition
- subtraction operator [C++], additive operators
- + operator [C++], additive operators
- additive operators [C++]
- arithmetic operators [C++], additive operators
- '- operator [C++], additive operators in C++'
ms.assetid: d4afafe7-e201-4c69-a649-37f17756e784
ms.openlocfilehash: 2601debb0a21c4ab9cdcedb25b26085a1aff0a1b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370204"
---
# <a name="additive-operators--and--"></a>Operadores aditivos: + e -

## <a name="syntax"></a>Sintaxe

```
expression + expression
expression - expression
```

## <a name="remarks"></a>Comentários

Os operadores de adição são:

- Adição**+**( )

- Subtração**-**( )

Esses operadores binários possuem associatividade da esquerda para a direita.

Os operadores de adição usam operandos de tipos aritméticos ou ponteiro. O resultado do**+** operador de adição é a soma dos operands. O resultado do operador**-** de subtração é a diferença entre os operands. Se um ou ambos os operandos forem ponteiros, eles devem ser ponteiros para os objetos, não para funções. Se ambos os operandos forem ponteiros, os resultados não serão significativos a menos que ambos sejam ponteiros para os objetos na mesma matriz.

Os operadores aditivos tomam operands de *tipos aritméticos,* *integrais*e *escalares.* Eles são definidos na tabela a seguir.

### <a name="types-used-with-additive-operators"></a>Tipos usados com operadores de adição

|Type|Significado|
|----------|-------------|
|*Aritmética*|Os tipos integral e flutuante são coletivamente chamados de tipos “aritméticos”.|
|*integral*|Os tipos char e int de todos os tamanhos (curto, longo) e enumerações são os tipos “integrais”.|
|*escalar*|Os operandos escalares são operandos aritméticos ou de ponteiro.|

As combinações legais para usar esses operadores são:

*arithmetic**aritmética aritmética*  + 

*escalado* + *integral*

*escalaintegral* + *scalar*

*arithmetic**aritmética aritmética*  - 

*escalar* - *escalar*

Observe que a adição e subtração não são operações equivalentes.

Se ambos os operands forem do tipo aritmética, as conversões cobertas pelas [Conversões Padrão](standard-conversions.md) são aplicadas aos operands, e o resultado é do tipo convertido.

## <a name="example"></a>Exemplo

```cpp
// expre_Additive_Operators.cpp
// compile with: /EHsc
#include <iostream>
#define SIZE 5
using namespace std;
int main() {
   int i = 5, j = 10;
   int n[SIZE] = { 0, 1, 2, 3, 4 };
   cout  << "5 + 10 = " << i + j << endl
         << "5 - 10 = " << i - j << endl;

   // use pointer arithmetic on array

   cout << "n[3] = " << *( n + 3 ) << endl;
}
```

## <a name="pointer-addition"></a>Adição de ponteiro

Se um dos operandos em uma operação de adição é um ponteiro para uma matriz de objetos, o outro deve ser do tipo integral. O resultado é um ponteiro que tem o mesmo tipo do ponteiro original e que aponta para outro elemento da matriz. O fragmento de código a seguir ilustra esse conceito:

```cpp
short IntArray[10]; // Objects of type short occupy 2 bytes
short *pIntArray = IntArray;

for( int i = 0; i < 10; ++i )
{
    *pIntArray = i;
    cout << *pIntArray << "\n";
    pIntArray = pIntArray + 1;
}
```

Embora o valor de integral 1 seja adicionado a `pIntArray`, isso não significa "adicionar 1 ao endereço"; significa "ajustar o ponteiro de modo a apontar para o próximo objeto na matriz" que esteja afastado por 2 bytes (ou `sizeof( int )`).

> [!NOTE]
> O código do formato `pIntArray = pIntArray + 1` raramente é encontrado em programas C++; para executar um incremento, estes formatos são preferíveis: `pIntArray++` ou `pIntArray += 1`.

## <a name="pointer-subtraction"></a>Subtração de ponteiro

Se ambos os operandos forem ponteiros, o resultado da subtração será a diferença (em elementos de matriz) entre os operandos. A expressão de subtração produz `ptrdiff_t` um resultado integral assinado \<do tipo (definido no padrão incluir arquivo stddef.h>).

Um dos operandos pode ser do tipo integral, desde que seja o segundo operando. O resultado da subtração é do mesmo tipo do ponteiro original. O valor da subtração é um ponteiro para o elemento de matriz (*n* - *i*)th, onde *n* é o elemento apontado pelo ponteiro original e *eu* é o valor integral do segundo operand.

## <a name="see-also"></a>Confira também

[Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores aditivos C](../c-language/c-additive-operators.md)
