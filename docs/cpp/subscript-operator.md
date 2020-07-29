---
title: Operador subscrito []
ms.date: 11/04/2016
f1_keywords:
- '[]'
helpviewer_keywords:
- operators [C++], subscript
- postfix operators [C++]
- '[] operator'
- subscript operator [C++], syntax
ms.assetid: 69c31494-52da-4dd0-8bbe-6ccbfd50f197
ms.openlocfilehash: a4eb878a18aa38b7047104903d10d96d66cc6720
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231085"
---
# <a name="subscript-operator-"></a>Operador subscrito []

## <a name="syntax"></a>Sintaxe

```
postfix-expression [ expression ]
```

## <a name="remarks"></a>Comentários

Uma expressão de sufixo (que também pode ser uma expressão primária) seguida pelo operador subscrito, **[]**, especifica a indexação de matriz.

Para obter informações sobre matrizes gerenciadas em C++/CLI, consulte [matrizes](../extensions/arrays-cpp-component-extensions.md).

Normalmente, o valor representado pelo *sufixo-Expression* é um valor de ponteiro, como um identificador de matriz, e *expression* é um valor integral (incluindo tipos enumerados). No entanto, tudo o que é necessário sintaticamente é que uma das expressões seja do tipo ponteiro e a outra seja do tipo integral. Portanto, o valor integral pode estar na posição da *expressão de sufixo* e o valor do ponteiro pode estar entre colchetes na posição da *expressão* ou do subscrito. Considere o fragmento de código a seguir:

```cpp
int nArray[5] = { 0, 1, 2, 3, 4 };
cout << nArray[2] << endl;            // prints "2"
cout << 2[nArray] << endl;            // prints "2"
```

No exemplo acima, a expressão `nArray[2]` é idêntica a `2[nArray]`. O motivo é que o resultado de uma expressão de subscrito `e1[e2]` é fornecido por:

`*((e2) + (e1))`

O endereço produzido pela expressão não é *E2* bytes do endereço *E1*. Em vez disso, o endereço é dimensionado para produzir o próximo objeto na matriz *E2*. Por exemplo:

```cpp
double aDbl[2];
```

Os endereços de `aDb[0]` e `aDb[1]` têm 8 bytes de distância — o tamanho de um objeto do tipo **`double`** . Esse dimensionamento de acordo com o tipo de objeto é feito automaticamente pela linguagem C++ e é definido em [operadores aditivos](../cpp/additive-operators-plus-and.md) onde a adição e a subtração de operandos do tipo de ponteiro são discutidas.

Uma expressão subscrita também pode ter vários subscritos, como segue:

*expression1* **[** *expression2* **] [** *expression3* **]** ...

As expressões subscritas são associadas da esquerda para a direita. A expressão de subscrito mais à esquerda, *expressão1* **[** *expression2* **]**, é avaliada primeiro. O endereço resultante da adição de *expression1* e *expression2* forma uma expressão do ponteiro; *expression3* é adicionada a essa expressão de ponteiro para formar uma nova expressão de ponteiro e assim por diante até que a última expressão subscrita seja adicionada. O operador de indireção ( <strong>\*</strong> ) é aplicado depois que a última expressão de subscrito é avaliada, a menos que o valor final do ponteiro atenda a um tipo de matriz.

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

O primeiro elemento de uma matriz é o elemento 0. O intervalo de uma matriz de C++ é da *matriz*[0] para a *matriz*[*size* -1]. No entanto, o C++ oferece suporte a subscritos positivos e negativos. Os subscritos negativos devem estar dentro dos limites da matriz, se não estiverem, os resultados serão imprevisíveis. O código a seguir mostra os subscritos positivo e negativo da matriz:

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

O subscrito negativo na última linha pode produzir um erro em tempo de execução porque aponta para um endereço 256 **`int`** posições inferiores na memória do que a origem da matriz. O ponteiro `midArray` é inicializado com o meio de `intArray` ; portanto, é possível (mas perigoso) usar índices de matriz positivos e negativos nele. Os erros de subscrito de matriz não geram erros de tempo de compilação, mas geram resultados imprevisíveis.

O operador subscrito é comutativo. Portanto, é garantido que a *matriz*de expressões [*index*] e o *índice*[*array*] sejam equivalentes, desde que o operador subscrito não esteja sobrecarregado (consulte [operadores sobrecarregados](../cpp/operator-overloading.md)). O primeiro formulário é a prática de codificação mais comum, mas ambas funcionam.

## <a name="see-also"></a>Confira também

[Expressões de sufixo](../cpp/postfix-expressions.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[matrizes](../cpp/arrays-cpp.md)<br/>
[Matrizes unidimensionais](../c-language/one-dimensional-arrays.md)<br/>
[Matrizes multidimensionais](../c-language/multidimensional-arrays-c.md)<br/>
