---
title: Operador subscrito]
ms.date: 11/04/2016
f1_keywords:
- '[]'
helpviewer_keywords:
- operators [C++], subscript
- postfix operators [C++]
- '[] operator'
- subscript operator [C++], syntax
ms.assetid: 69c31494-52da-4dd0-8bbe-6ccbfd50f197
ms.openlocfilehash: 2d55c18d2c9faa1a704bea129f2551937e76133c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62266888"
---
# <a name="subscript-operator-"></a>Operador subscrito]

## <a name="syntax"></a>Sintaxe

```
postfix-expression [ expression ]
```

## <a name="remarks"></a>Comentários

Uma expressão de pós-fixação (que também pode ser uma expressão primária) seguida pelo operador de subscrito **[]**, especifica a indexação de matriz.

Para obter informações sobre matrizes gerenciadas no C++/CLI, consulte [matrizes](../extensions/arrays-cpp-component-extensions.md).

Geralmente, o valor representado pelo *postfix-expression* é um valor de ponteiro, como um identificador de matriz, e *expressão* é um valor integral (incluindo tipos enumerados). No entanto, tudo o que é necessário sintaticamente é que uma das expressões seja do tipo ponteiro e a outra seja do tipo integral. Assim que o valor integral pode estar na *postfix-expression* posição e o valor do ponteiro pode estar entre colchetes na *expressão* ou posição de subscrito. Considere o fragmento de código a seguir:

```cpp
int nArray[5] = { 0, 1, 2, 3, 4 };
cout << nArray[2] << endl;            // prints "2"
cout << 2[nArray] << endl;            // prints "2"
```

No exemplo acima, a expressão `nArray[2]` é idêntica a `2[nArray]`. O motivo é que o resultado de uma expressão de subscrito `e1[e2]` é dado por:

`*((e2) + (e1))`

O endereço gerado pela expressão não é *e2* bytes do endereço *e1*. Em vez disso, o endereço é dimensionado para gerar o próximo objeto na matriz *e2*. Por exemplo:

```cpp
double aDbl[2];
```

Os endereços dos `aDb[0]` e `aDb[1]` são 8 bytes distância — o tamanho de um objeto do tipo **duplo**. Esse dimensionamento de acordo com o tipo de objeto é feito automaticamente pela linguagem C++ e é definido em [operadores aditivos](../cpp/additive-operators-plus-and.md) em que a adição e subtração de operandos do tipo de ponteiro é discutido.

Uma expressão subscrita também pode ter vários subscritos, como segue:

*Expression1* **[** *expression2* **] [** *expression3* **]** ...

As expressões subscritas são associadas da esquerda para a direita. A expressão subscrita mais à esquerda, *expression1* **[** *expression2* **]**, é avaliada primeiro. O endereço resultante da adição de *expression1* e *expression2* forma uma expressão do ponteiro; *expression3* é adicionada a essa expressão de ponteiro para formar uma nova expressão de ponteiro e assim por diante até que a última expressão subscrita seja adicionada. O operador de indireção (<strong>\*</strong>) é aplicado depois que a última expressão Subscrita é avaliada, a menos que o valor do ponteiro final resolve um tipo de matriz.

As expressões com vários subscritos referem-se aos elementos de matrizes multidimensionais. Uma matriz multidimensional é uma matriz cujos elementos são matrizes. Por exemplo, o primeiro elemento de uma matriz tridimensional é uma matriz com duas dimensões. O exemplo a seguir declara e inicializa uma matriz bidimensional simples de caracteres:

```cpp
// expre_Subscript_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
#define MAX_ROWS 2
#define MAX_COLS 2

int main() {
  char c[ MAX_ROWS ][ MAX_COLS ] = { { 'a', 'b' }, { 'c', 'd' } };
  for ( int i = 0; i < MAX_ROWS; i++ )
     for ( int j = 0; j < MAX_COLS; j++ )
        cout << c[ i ][ j ] << endl;
}
```

## <a name="positive-and-negative-subscripts"></a>Subscritos positivos e negativos

O primeiro elemento de uma matriz é o elemento 0. O intervalo de um C++ matriz está entre *array*[0] para *matriz*[*tamanho* - 1]. No entanto, o C++ oferece suporte a subscritos positivos e negativos. Os subscritos negativos devem estar dentro dos limites da matriz, se não estiverem, os resultados serão imprevisíveis. O código a seguir mostra os subscritos positivo e negativo da matriz:

```cpp
#include <iostream>
using namespace std;

int main() {
    int intArray[1024];
    for (int i = 0, j = 0; i < 1024; i++)
    {
        intArray[i] = j++;
    }

    cout << intArray[512] << endl;   // 512

    cout << 257[intArray] << endl;   // 257

    int *midArray = &intArray[512];  // pointer to the middle of the array

    cout << midArray[-256] << endl;  // 256

    cout << intArray[-256] << endl;  // unpredictable, may crash
}
```

O subscrito negativo na última linha pode gerar um erro de tempo de execução porque aponta para um endereço 256 **int** posições inferiores na memória que a origem da matriz. O ponteiro `midArray` é inicializado na metade da `intArray`; portanto, é possível (mas perigoso) usar ambos os índices positivo e negativo da matriz nele. Os erros de subscrito de matriz não geram erros de tempo de compilação, mas geram resultados imprevisíveis.

O operador subscrito é comutativo. Portanto, as expressões *array*[*índice*] e *índice*[*matriz*] têm garantia de serem equivalentes, enquanto o subscrito operador não está sobrecarregado (consulte [operadores sobrecarregados](../cpp/operator-overloading.md)). O primeiro formulário é a prática de codificação mais comum, mas ambas funcionam.

## <a name="see-also"></a>Consulte também

[Expressões pós-fixadas](../cpp/postfix-expressions.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Matrizes](../cpp/arrays-cpp.md)<br/>
[Matrizes unidimensionais](../c-language/one-dimensional-arrays.md)<br/>
[Matrizes multidimensionais](../c-language/multidimensional-arrays-c.md)<br/>
