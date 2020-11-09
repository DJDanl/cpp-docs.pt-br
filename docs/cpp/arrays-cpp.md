---
title: Matrizes (C++)
description: Saiba como declarar e usar o tipo de matriz nativa na linguagem de programação C++ padrão.
ms.date: 11/08/2020
helpviewer_keywords:
- declaring arrays [C++], about declaring arrays
- multidimensional arrays [C++]
- arrays [C++]
ms.assetid: 3f5986aa-485c-4ba4-9502-67e2ef924238
ms.openlocfilehash: 2a84e5db04d0a37ebd65e0d979e9b075b7c23312
ms.sourcegitcommit: 3f0c1dcdcce25865d1a1022bcc5b9eec79f69025
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2020
ms.locfileid: "94381578"
---
# <a name="arrays-c"></a>Matrizes (C++)

Uma matriz é uma sequência de objetos do mesmo tipo que ocupam uma área contígua de memória. As matrizes tradicionais de estilo C são a fonte de muitos bugs, mas ainda são comuns, especialmente em bases de código mais antigas. No C++ moderno, é altamente recomendável usar [std:: vector](../standard-library/vector-class.md) ou [std:: array](../standard-library/array-class-stl.md) em vez de matrizes de estilo C descritos nesta seção. Ambos os tipos de biblioteca padrão armazenam seus elementos como um bloco contíguo de memória. No entanto, eles fornecem segurança de tipo muito maior e iteradores de suporte que têm garantia de apontar para um local válido dentro da sequência. Para obter mais informações, consulte [contêineres](../standard-library/stl-containers.md).

## <a name="stack-declarations"></a>Declarações de pilha

Em uma declaração de matriz do C++, o tamanho da matriz é especificado após o nome da variável, não após o nome do tipo, como em algumas outras linguagens. O exemplo a seguir declara uma matriz de 1000 duplos a serem alocados na pilha. O número de elementos deve ser fornecido como um literal inteiro ou, senão, como uma expressão constante. Isso ocorre porque o compilador precisa saber quanto espaço de pilha deve ser alocado; Ele não pode usar um valor calculado em tempo de execução. Cada elemento na matriz recebe um valor padrão de 0. Se você não atribuir um valor padrão, cada elemento inicialmente conterá quaisquer valores aleatórios que estejam nesse local de memória.

```cpp
    constexpr size_t size = 1000;

    // Declare an array of doubles to be allocated on the stack
    double numbers[size] {0};

    // Assign a new value to the first element
    numbers[0] = 1;

    // Assign a value to each subsequent element
    // (numbers[1] is the second element in the array.)
    for (size_t i = 1; i < size; i++)
    {
        numbers[i] = numbers[i-1] * 1.1;
    }

    // Access each element
    for (size_t i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }
```

O primeiro elemento na matriz é o elemento inicial. O último elemento é o elemento ( *n* -1), em que *n* é o número de elementos que a matriz pode conter. O número de elementos na declaração deve ser de um tipo integral e deve ser maior que 0. É sua responsabilidade garantir que seu programa nunca passe um valor para o operador subscrito maior que `(size - 1)` .

Uma matriz de tamanho zero é válida somente quando a matriz é o último campo em um **`struct`** ou **`union`** e quando as extensões da Microsoft são habilitadas ( **`/Za`** ou **`/permissive-`** não é definido).

As matrizes baseadas em pilha são mais rápidas de alocar e acessar do que as matrizes baseadas em heap. No entanto, o espaço de pilha é limitado. O número de elementos de matriz não pode ser tão grande que usa muita memória de pilha. A quantidade de excesso de dependências do seu programa. Você pode usar ferramentas de criação de perfil para determinar se uma matriz é muito grande.

## <a name="heap-declarations"></a>Declarações de heap

Você pode exigir uma matriz muito grande para alocar na pilha ou cujo tamanho não é conhecido no momento da compilação. É possível alocar essa matriz no heap usando uma [`new[]`](new-operator-cpp.md) expressão. O operador retorna um ponteiro para o primeiro elemento. O operador subscrito funciona na variável de ponteiro da mesma maneira que em uma matriz baseada em pilha. Você também pode usar a [aritmética de ponteiro](../c-language/pointer-arithmetic.md) para mover o ponteiro para qualquer elemento arbitrário na matriz. É sua responsabilidade garantir que:

- Você sempre mantém uma cópia do endereço do ponteiro original para poder excluir a memória quando não precisar mais da matriz.
- Você não incrementa ou Decrementa o endereço do ponteiro além dos limites da matriz.

O exemplo a seguir mostra como definir uma matriz no heap em tempo de execução. Ele mostra como acessar os elementos da matriz usando o operador subscrito e usando aritmética de ponteiro:

```cpp

void do_something(size_t size)
{
    // Declare an array of doubles to be allocated on the heap
    double* numbers = new double[size]{ 0 };

    // Assign a new value to the first element
    numbers[0] = 1;

    // Assign a value to each subsequent element
    // (numbers[1] is the second element in the array.)
    for (size_t i = 1; i < size; i++)
    {
        numbers[i] = numbers[i - 1] * 1.1;
    }

    // Access each element with subscript operator
    for (size_t i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }

    // Access each element with pointer arithmetic
    // Use a copy of the pointer for iterating
    double* p = numbers;

    for (size_t i = 0; i < size; i++)
    {
        // Dereference the pointer, then increment it
        std::cout << *p++ << " ";
    }

    // Alternate method:
    // Reset p to numbers[0]:
    p = numbers;

    // Use address of pointer to compute bounds.
    // The compiler computes size as the number
    // of elements * (bytes per element).
    while (p < (numbers + size))
    {
        // Dereference the pointer, then increment it
        std::cout << *p++ << " ";
    }

    delete[] numbers; // don't forget to do this!

}
int main()
{
    do_something(108);
}

```

## <a name="initializing-arrays"></a>Inicializando matrizes

Você pode inicializar uma matriz em um loop, um elemento por vez ou em uma única instrução. O conteúdo das duas matrizes a seguir é idêntico:

```cpp
    int a[10];
    for (int i = 0; i < 10; ++i)
    {
        a[i] = i + 1;
    }

    int b[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
```

## <a name="passing-arrays-to-functions"></a>Passando matrizes para funções

Quando uma matriz é passada para uma função, ela é passada como um ponteiro para o primeiro elemento, seja uma matriz baseada em pilha ou em heap. O ponteiro não contém informações adicionais de tamanho ou tipo. Esse comportamento é chamado de *ponteiro decaimento*. Ao passar uma matriz para uma função, você sempre deve especificar o número de elementos em um parâmetro separado. Esse comportamento também implica que os elementos da matriz não são copiados quando a matriz é passada para uma função. Para impedir que a função modifique os elementos, especifique o parâmetro como um ponteiro para **`const`** elementos.

O exemplo a seguir mostra uma função que aceita uma matriz e um comprimento. O ponteiro aponta para a matriz original, não para uma cópia. Como o parâmetro não é **`const`** , a função pode modificar os elementos da matriz.

```cpp
void process(double *p, const size_t len)
{
    std::cout << "process:\n";
    for (size_t i = 0; i < len; ++i)
    {
        // do something with p[i]
    }
}
```

Declare e defina o parâmetro de matriz `p` como **`const`** para torná-lo somente leitura dentro do bloco de função:

```cpp
void process(const double *p, const size_t len);
```

A mesma função também pode ser declarada de maneiras, sem alterações no comportamento. A matriz ainda é passada como um ponteiro para o primeiro elemento:

```cpp
// Unsized array
void process(const double p[], const size_t len);

// Fixed-size array. Length must still be specified explicitly.
void process(const double p[1000], const size_t len);
```

## <a name="multidimensional-arrays"></a>Matrizes multidimensionais

Matrizes construídas a partir de outras matrizes são matrizes multidimensionais. Essas matrizes multidimensionais são especificadas colocando várias expressões de constante entre colchetes em sequência. Por exemplo, considere esta declaração:

```cpp
int i2[5][7];
```

Ele especifica uma matriz do tipo **`int`** , conceitualmente organizada em uma matriz bidimensional de cinco linhas e sete colunas, conforme mostrado na figura a seguir:

![Layout conceitual de uma matriz dimensional de vários&#45;](../cpp/media/vc38rc1.gif "Layout conceitual de uma matriz dimensional de vários&#45;") <br/>
Layout conceitual de uma matriz multidimensional

Você pode declarar matrizes multidimensionais que têm uma lista de inicializadores (conforme descrito em [inicializadores](../cpp/initializers.md)). Nessas declarações, a expressão constante que especifica os limites para a primeira dimensão pode ser omitida. Por exemplo:

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

O uso do operador de indireção (*) em um tipo de matriz n-dimensional produz uma matriz dimensional n-1. Se n for 1, um escalar (ou elemento de matriz) será gerado.

As matrizes de C++ são armazenadas na ordem de linha principal. Ordem de linha principal significa que o último subscrito varia mais rápido.

## <a name="example"></a>Exemplo

Você também pode omitir a especificação de limites para a primeira dimensão de uma matriz multidimensional em declarações de função, como mostrado aqui:

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

   for( size_t i = 0; i < cFacts; ++i )
      MinCost = (MinCost < TransportCosts[i][Mkt]) ?
         MinCost : TransportCosts[i][Mkt];

   return MinCost;
}
```

```Output
The minimum cost to Market 3 is: 17.29
```

A função `FindMinToMkt` é escrita de modo que a adição de novas fábricas não exija nenhuma alteração de código, apenas uma recompilação.

## <a name="initializing-arrays"></a>Inicializando matrizes

Matrizes de objetos que têm um construtor de classe são inicializadas pelo construtor. Quando há menos itens na lista de inicializadores do que elementos na matriz, o construtor padrão é usado para os elementos restantes. Se nenhum construtor padrão for definido para a classe, a lista de inicializadores deverá ser *concluída* , ou seja, deve haver um inicializador para cada elemento na matriz.

Considere a classe `Point` que define dois construtores:

```cpp
// initializing_arrays1.cpp
class Point
{
public:
   Point()   // Default constructor.
   {
   }
   Point( int, int )   // Construct from two ints
   {
   }
};

// An array of Point objects can be declared as follows:
Point aPoint[3] = {
   Point( 3, 3 )     // Use int, int constructor.
};

int main()
{
}
```

O primeiro elemento de `aPoint` é construído usando o construtor `Point( int, int )`; os dois elementos restantes são construídos com o construtor padrão.

Matrizes de membros estáticos (se **`const`** ou não) podem ser inicializadas em suas definições (fora da declaração de classe). Por exemplo:

```cpp
// initializing_arrays2.cpp
class WindowColors
{
public:
    static const char *rgszWindowPartList[7];
};

const char *WindowColors::rgszWindowPartList[7] = {
    "Active Title Bar", "Inactive Title Bar", "Title Bar Text",
    "Menu Bar", "Menu Bar Text", "Window Background", "Frame"   };
int main()
{
}
```

## <a name="accessing-array-elements"></a>Acessando elementos de matriz

Você pode acessar elementos individuais de uma matriz usando o operador de subscrito de matriz (`[ ]`). Se você usar o nome de uma matriz unidimensional sem um subscrito, ela será avaliada como um ponteiro para o primeiro elemento da matriz.

```cpp
// using_arrays.cpp
int main() {
   char chArray[10];
   char *pch = chArray;   // Evaluates to a pointer to the first element.
   char   ch = chArray[0];   // Evaluates to the value of the first element.
   ch = chArray[3];   // Evaluates to the value of the fourth element.
}
```

Ao usar matrizes multidimensionais, você pode usar diversas combinações em expressões.

```cpp
// using_arrays_2.cpp
// compile with: /EHsc /W1
#include <iostream>
using namespace std;
int main() {
   double multi[4][4][3];   // Declare the array.
   double (*p2multi)[3];
   double (*p1multi);

   cout << multi[3][2][2] << "\n";   // C4700 Use three subscripts.
   p2multi = multi[3];               // Make p2multi point to
                                     // fourth "plane" of multi.
   p1multi = multi[3][2];            // Make p1multi point to
                                     // fourth plane, third row
                                     // of multi.
}
```

No código anterior, `multi` é uma matriz tridimensional do tipo **`double`** . O `p2multi` ponteiro aponta para uma matriz de tipo **`double`** de tamanho três. Nesse exemplo, a matriz é usada com um, dois e três subscritos. Embora seja mais comum especificar todos os subscritores, como na `cout` instrução, às vezes é útil selecionar um subconjunto específico de elementos de matriz, conforme mostrado nas instruções a seguir `cout` .

## <a name="overloading-subscript-operator"></a>Sobrecarregando operador subscrito

Assim como outros operadores, o operador subscrito ( `[]` ) pode ser redefinido pelo usuário. O comportamento padrão do operador subscrito, se não sobrecarregado, é combinar o nome da matriz e o subscrito usando o seguinte método:

`*((array_name) + (subscript))`

Como em todas as adição que envolvem tipos de ponteiro, o dimensionamento é feito automaticamente para ajustar o tamanho do tipo. O valor resultante não é *n* bytes da origem de `array_name` ; em vez disso, é o *n* -ésimo do elemento da matriz. Para obter mais informações sobre essa conversão, consulte [operadores aditivos](additive-operators-plus-and.md).

De maneira semelhante, para matrizes multidimensionais, o endereço é derivado usando o seguinte método:

`((array_name) + (subscript1 * max2 * max3 * ... * maxn) + (subscript2 * max3 * ... * maxn) + ... + subscriptn))`

## <a name="arrays-in-expressions"></a>Matrizes em expressões

Quando um identificador de um tipo de matriz é exibido em uma expressão diferente de **`sizeof`** , endereço-de ( `&` ) ou inicialização de uma referência, ele é convertido em um ponteiro para o primeiro elemento da matriz. Por exemplo:

```cpp
char szError1[] = "Error: Disk drive not ready.";
char *psz = szError1;
```

O ponteiro `psz` aponta para o primeiro elemento da matriz `szError1`. As matrizes, ao contrário de ponteiros, não são valores l modificáveis. É por isso que a atribuição a seguir é ilegal:

```cpp
szError1 = psz;
```

## <a name="see-also"></a>Confira também

[std:: array](../standard-library/array-class-stl.md)
