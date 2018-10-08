---
title: Matrizes (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- declaring arrays [C++], about declaring arrays
- multidimensional arrays [C++]
- arrays [C++]
ms.assetid: 3f5986aa-485c-4ba4-9502-67e2ef924238
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b2423355aa53abe52fffcd81ec847b41337efcbf
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861025"
---
# <a name="arrays-c"></a>Matrizes (C++)

Uma matriz é uma coleção de objetos afins. O caso mais simples de uma matriz é um vetor, que pode ser declarado pela seguinte sequência:

> *especificador de Decl* *identificador* **\[** *expressão constante* **]**<br/>
> *especificador de Decl* *identificador*  **\[]**<br/>
> *especificador de Decl* *identificador* **\[]\[** *expressão constante* **]** . . .<br/>
> *especificador de Decl* *identificador* **\[** *expressão constante* **]** **\[** *expressão constante* **]** . . .

1. O especificador de declaração:

   - Um especificador de classe de armazenamento opcional.

   - Opcional **const** e/ou **volátil** especificadores.

   - O nome do tipo dos elementos da matriz.

1. O declarador:

   - O identificador.

   - Uma expressão constante do tipo integral entre colchetes,  **\[]**. Se várias dimensões são declaradas usando os colchetes adicionais, a expressão de constante pode ser omitida no primeiro conjunto de colchetes.

   - Colchetes adicionais opcionais que incluem expressões constantes.

1. Um inicializador opcional. Para obter mais informações, consulte [inicializadores](../cpp/initializers.md).

O número de elementos na matriz é determinado pela *expressão-constante*. O primeiro elemento na matriz é o elemento 0 e o último elemento é o (*n*-1) elemento, onde *n* é o número de elementos de matriz pode conter. O *expressão-constante* deve ser do tipo integral e deve ser maior que 0. Uma matriz de tamanho zero é válida somente quando a matriz é o último campo em uma **struct** ou **união** e quando as extensões da Microsoft (/Ze) estão habilitadas.

O exemplo a seguir mostra como definir uma matriz no tempo de execução:

```cpp
// arrays.cpp
// compile with: /EHsc
#include <iostream>

int main() {
   using namespace std;
   int size = 3, i = 0;

   int* myarr = new int[size];

   for (i = 0 ; i < size ; i++)
      myarr[i] = 10;

   for (i = 0 ; i < size ; i++)
      printf_s("myarr[%d] = %d\n", i, myarr[i]);

   delete [] myarr;
}
```

Matrizes são tipos derivados e, portanto, podem ser construídos a partir de qualquer outro tipo, derivado ou fundamental, exceto as funções, referências, e **void**.

Matrizes construídas a partir de outras matrizes são matrizes multidimensionais. Essas matrizes multidimensionais são especificadas colocando várias expressões de constante entre colchetes em sequência. Por exemplo, considere esta declaração:

```cpp
int i2[5][7];
```

Especifica uma matriz do tipo **int**, organizada conceitualmente em uma matriz bidimensional de cinco linhas e sete colunas, conforme mostrado na figura a seguir:

![Layout conceitual de uma de várias&#45;matriz dimensional](../cpp/media/vc38rc1.gif "vc38RC1") Layout conceitual de matriz Multidimensional

Em declarações de matrizes multidimensionadas que têm uma lista de inicializadores (conforme descrito em [inicializadores](../cpp/initializers.md)), a expressão de constante que especifica os limites para a primeira dimensão pode ser omitida. Por exemplo:

```cpp
// arrays2.cpp
// compile with: /c
const int cMarkets = 4;
// Declare a float that represents the transportation costs.
double TransportCosts[][cMarkets] = {
   { 32.19, 47.29, 31.99, 19.11 },
   { 11.29, 22.49, 33.47, 17.29 },
   { 41.97, 22.09,  9.76, 22.55 }
};
```

A declaração anterior define uma matriz com três linhas por quatro colunas. As linhas representam fábricas e colunas representam os mercados para os quais as fábricas enviam. Os valores são os custos de transporte das fábricas para os mercados. A primeira dimensão da matriz é deixada de fora, mas o compilador a preenche examinando o inicializador.

Tópicos desta seção:

- [Usando matrizes](../cpp/using-arrays-cpp.md)

- [Matrizes em expressões](../cpp/arrays-in-expressions.md)

- [Interpretação do operador subscrito](../cpp/interpretation-of-subscript-operator.md)

- [Indireção em tipos de matriz](../cpp/indirection-on-array-types.md)

- [Ordenação de matrizes C++](../cpp/ordering-of-cpp-arrays.md)

## <a name="example"></a>Exemplo

A técnica de omitir a especificação dos limites para a primeira dimensão de uma matriz multidimensional também pode ser usada em declarações de função como a seguir:

```cpp
// multidimensional_arrays.cpp
// compile with: /EHsc
// arguments: 3
#include <limits>   // Includes DBL_MAX
#include <iostream>

const int cMkts = 4, cFacts = 2;

// Declare a float that represents the transportation costs
double TransportCosts[][cMkts] = {
   { 32.19, 47.29, 31.99, 19.11 },
   { 11.29, 22.49, 33.47, 17.29 },
   { 41.97, 22.09,  9.76, 22.55 }
};

// Calculate size of unspecified dimension
const int cFactories = sizeof TransportCosts /
                  sizeof( double[cMkts] );

double FindMinToMkt( int Mkt, double myTransportCosts[][cMkts], int mycFacts);

using namespace std;

int main( int argc, char *argv[] ) {
   double MinCost;

   if (argv[1] == 0) {
      cout << "You must specify the number of markets." << endl;
      exit(0);
   }
   MinCost = FindMinToMkt( *argv[1] - '0', TransportCosts, cFacts);
   cout << "The minimum cost to Market " << argv[1] << " is: "
       << MinCost << "\n";
}

double FindMinToMkt(int Mkt, double myTransportCosts[][cMkts], int mycFacts) {
   double MinCost = DBL_MAX;

   for( int i = 0; i < cFacts; ++i )
      MinCost = (MinCost < TransportCosts[i][Mkt]) ?
         MinCost : TransportCosts[i][Mkt];

   return MinCost;
}
```

```Output
The minimum cost to Market 3 is: 17.29
```

## <a name="comments"></a>Comentários

A função `FindMinToMkt` é escrita de forma que a adição de novas fábricas não exija qualquer alteração de código, somente uma recompilação.
