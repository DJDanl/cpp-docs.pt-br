---
title: Usando blocos
ms.date: 11/19/2018
ms.assetid: acb86a86-2b7f-43f1-8fcf-bcc79b21d9a8
ms.openlocfilehash: e5cedde255846f61ed0aaadacbd9966c00a03c9d
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126247"
---
# <a name="using-tiles"></a>Usando blocos

Você pode usar a divisão para maximizar a aceleração do seu aplicativo. A divisão divide threads em subconjuntos ou *blocos*iguais retangulares. Se você usar um tamanho de bloco apropriado e um algoritmo de lado, poderá obter ainda mais aceleração do seu C++ código de amp. Os componentes básicos de colocação em blocos são:

- variáveis de `tile_static`. O principal benefício de disposição em blocos é o lucro de desempenho do acesso `tile_static`. O acesso a dados na memória `tile_static` pode ser significativamente mais rápido do que o acesso aos dados no espaço global (`array` ou `array_view` objetos). Uma instância de uma variável de `tile_static` é criada para cada bloco e todos os threads no bloco têm acesso à variável. Em um algoritmo em ladrilho típico, os dados são copiados para `tile_static` memória uma vez da memória global e, em seguida, acessados muitas vezes da memória `tile_static`.

- [método tile_barrier:: Wait](reference/tile-barrier-class.md#wait). Uma chamada para `tile_barrier::wait` suspende a execução do thread atual até que todos os threads no mesmo bloco alcancem a chamada para `tile_barrier::wait`. Você não pode garantir a ordem em que os threads serão executados, apenas que nenhum thread no bloco será executado após a chamada para `tile_barrier::wait` até que todos os threads tenham atingido a chamada. Isso significa que, usando o método `tile_barrier::wait`, você pode executar tarefas em uma base bloco por bloco, em vez de thread a thread. Um algoritmo de colocação em cascata típico tem código para inicializar a `tile_static` memória para o bloco inteiro seguido por uma chamada para `tile_barrier::wait`. O código a seguir `tile_barrier::wait` contém cálculos que exigem acesso a todos os valores de `tile_static`.

- Indexação local e global. Você tem acesso ao índice do thread em relação a todo o `array_view` ou `array` objeto e o índice em relação ao bloco. Usar o índice local pode tornar seu código mais fácil de ler e depurar. Normalmente, você usa a indexação local para acessar variáveis de `tile_static` e a indexação global para acessar `array` e `array_view` variáveis.

- classe de [tiled_extent](../../parallel/amp/reference/tiled-extent-class.md) e classe de [tiled_index](../../parallel/amp/reference/tiled-index-class.md). Você usa um objeto `tiled_extent` em vez de um objeto `extent` na chamada `parallel_for_each`. Você usa um objeto `tiled_index` em vez de um objeto `index` na chamada `parallel_for_each`.

Para aproveitar a divisão, o algoritmo deve particionar o domínio de computação em blocos e, em seguida, copiar os dados do bloco em variáveis `tile_static` para acesso mais rápido.

## <a name="example-of-global-tile-and-local-indices"></a>Exemplo de índices globais, de bloco e locais

O diagrama a seguir representa uma matriz 8x9 de dados que é organizada em blocos do 2x3.

![8&#45;por&#45;9 matriz divididas em&#45;2&#45;por 3 blocos](../../parallel/amp/media/usingtilesmatrix.png "8&#45;por&#45;9 matriz divididas em&#45;2&#45;por 3 blocos")

O exemplo a seguir exibe os índices global, de bloco e locais desta matriz lado-a-quadro. Um objeto `array_view` é criado usando elementos do tipo `Description`. A `Description` contém os índices global, bloco e local do elemento na matriz. O código na chamada para `parallel_for_each` define os valores dos índices global, bloco e local de cada elemento. A saída exibe os valores nas estruturas de `Description`.

```cpp
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <amp.h>
using namespace concurrency;

const int ROWS = 8;
const int COLS = 9;

// tileRow and tileColumn specify the tile that each thread is in.
// globalRow and globalColumn specify the location of the thread in the array_view.
// localRow and localColumn specify the location of the thread relative to the tile.
struct Description {
    int value;
    int tileRow;
    int tileColumn;
    int globalRow;
    int globalColumn;
    int localRow;
    int localColumn;
};

// A helper function for formatting the output.
void SetConsoleColor(int color) {
    int colorValue = (color == 0)  4 : 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorValue);
}

// A helper function for formatting the output.
void SetConsoleSize(int height, int width) {
    COORD coord;

    coord.X = width;
    coord.Y = height;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    SMALL_RECT* rect = new SMALL_RECT();
    rect->Left = 0;
    rect->Top = 0;
    rect->Right = width;
    rect->Bottom = height;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, rect);
}

// This method creates an 8x9 matrix of Description structures.
// In the call to parallel_for_each, the structure is updated
// with tile, global, and local indices.
void TilingDescription() {
    // Create 72 (8x9) Description structures.
    std::vector<Description> descs;
    for (int i = 0; i < ROWS * COLS; i++) {
        Description d = {i, 0, 0, 0, 0, 0, 0};
        descs.push_back(d);
    }

    // Create an array_view from the Description structures.
    extent<2> matrix(ROWS, COLS);
    array_view<Description, 2> descriptions(matrix, descs);

    // Update each Description with the tile, global, and local indices.
    parallel_for_each(descriptions.extent.tile< 2, 3>(),
        [=] (tiled_index< 2, 3> t_idx) restrict(amp)
    {
        descriptions[t_idx].globalRow = t_idx.global[0];
        descriptions[t_idx].globalColumn = t_idx.global[1];
        descriptions[t_idx].tileRow = t_idx.tile[0];
        descriptions[t_idx].tileColumn = t_idx.tile[1];
        descriptions[t_idx].localRow = t_idx.local[0];
        descriptions[t_idx].localColumn= t_idx.local[1];
    });

    // Print out the Description structure for each element in the matrix.
    // Tiles are displayed in red and green to distinguish them from each other.
    SetConsoleSize(100, 150);
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLS; column++) {
            SetConsoleColor((descriptions(row, column).tileRow + descriptions(row, column).tileColumn) % 2);
            std::cout << "Value: " << std::setw(2) << descriptions(row, column).value << "      ";
        }
        std::cout << "\n";

        for (int column = 0; column < COLS; column++) {
            SetConsoleColor((descriptions(row, column).tileRow + descriptions(row, column).tileColumn) % 2);
            std::cout << "Tile:   " << "(" << descriptions(row, column).tileRow << "," << descriptions(row, column).tileColumn << ")  ";
        }
        std::cout << "\n";

        for (int column = 0; column < COLS; column++) {
            SetConsoleColor((descriptions(row, column).tileRow + descriptions(row, column).tileColumn) % 2);
            std::cout << "Global: " << "(" << descriptions(row, column).globalRow << "," << descriptions(row, column).globalColumn << ")  ";
        }
        std::cout << "\n";

        for (int column = 0; column < COLS; column++) {
            SetConsoleColor((descriptions(row, column).tileRow + descriptions(row, column).tileColumn) % 2);
            std::cout << "Local:  " << "(" << descriptions(row, column).localRow << "," << descriptions(row, column).localColumn << ")  ";
        }
        std::cout << "\n";
        std::cout << "\n";
    }
}

int main() {
    TilingDescription();
    char wait;
    std::cin >> wait;
}
```

O trabalho principal do exemplo é a definição do objeto `array_view` e a chamada para `parallel_for_each`.

1. O vetor de estruturas de `Description` é copiado em um objeto de `array_view` 8x9.

2. O método `parallel_for_each` é chamado com um objeto `tiled_extent` como o domínio de computação. O objeto `tiled_extent` é criado chamando o método `extent::tile()` da variável `descriptions`. Os parâmetros de tipo da chamada para `extent::tile()`, `<2,3>`, especificam que os blocos 2x3 são criados. Assim, a matriz 8x9 é disposta lado a 12 blocos, quatro linhas e três colunas.

3. O método `parallel_for_each` é chamado usando um objeto `tiled_index<2,3>` (`t_idx`) como o índice. Os parâmetros de tipo do índice (`t_idx`) devem corresponder aos parâmetros de tipo do domínio de computação (`descriptions.extent.tile< 2, 3>()`).

4. Quando cada thread é executado, o índice `t_idx` retorna informações sobre o bloco em que o thread está (`tiled_index::tile` Propriedade) e o local do thread dentro do bloco (Propriedade`tiled_index::local`).

## <a name="tile-synchronizationtile_static-and-tile_barrierwait"></a>Sincronização de bloco — tile_static e tile_barrier:: Wait

O exemplo anterior ilustra o layout do bloco e os índices, mas não é muito útil.  O agrupamento se torna útil quando os blocos são integrais ao algoritmo e exploram `tile_static` variáveis. Como todos os threads em um bloco têm acesso a `tile_static` variáveis, chamadas para `tile_barrier::wait` são usadas para sincronizar o acesso às variáveis de `tile_static`. Embora todos os threads em um bloco tenham acesso às variáveis de `tile_static`, não há nenhuma ordem garantida de execução de threads no bloco. O exemplo a seguir mostra como usar variáveis de `tile_static` e o método `tile_barrier::wait` para calcular o valor médio de cada bloco. Aqui estão as chaves para entender o exemplo:

1. O rawData é armazenado em uma matriz 8x8.

2. O tamanho do bloco é 2x2. Isso cria uma grade 4x4 de blocos e as médias podem ser armazenadas em uma matriz 4x4 usando um objeto `array`. Há apenas um número limitado de tipos que você pode capturar por referência em uma função restrita por AMP. A classe `array` é uma delas.

3. O tamanho da matriz e o tamanho da amostra são definidos usando instruções `#define`, porque os parâmetros de tipo a serem `array`, `array_view`, `extent`e `tiled_index` devem ser valores constantes. Você também pode usar declarações de `const int static`. Como um benefício adicional, é trivial alterar o tamanho da amostra para calcular a média de blocos de 4x4.

4. Uma `tile_static` matriz 2x2 de valores float é declarada para cada bloco. Embora a declaração esteja no caminho do código para cada thread, apenas uma matriz é criada para cada bloco na matriz.

5. Há uma linha de código para copiar os valores em cada bloco para a matriz de `tile_static`. Para cada thread, depois que o valor é copiado para a matriz, a execução no thread é interrompida devido à chamada para `tile_barrier::wait`.

6. Quando todos os threads em um bloco atingirem a barreira, a média poderá ser calculada. Como o código é executado para cada thread, há uma instrução `if` para calcular apenas a média em um thread. A média é armazenada na variável de médias. A barreira é essencialmente a construção que controla os cálculos por bloco, assim como você pode usar um loop de `for`.

7. Os dados na variável `averages`, porque é um objeto `array`, devem ser copiados de volta para o host. Este exemplo usa o operador de conversão de vetor.

8. No exemplo completo, você pode alterar SAMPLEs para 4 e o código é executado corretamente sem nenhuma outra alteração.

```cpp
#include <iostream>
#include <amp.h>
using namespace concurrency;

#define SAMPLESIZE 2
#define MATRIXSIZE 8
void SamplingExample() {

    // Create data and array_view for the matrix.
    std::vector<float> rawData;
    for (int i = 0; i < MATRIXSIZE * MATRIXSIZE; i++) {
        rawData.push_back((float)i);
    }
    extent<2> dataExtent(MATRIXSIZE, MATRIXSIZE);
    array_view<float, 2> matrix(dataExtent, rawData);

    // Create the array for the averages.
    // There is one element in the output for each tile in the data.
    std::vector<float> outputData;
    int outputSize = MATRIXSIZE / SAMPLESIZE;
    for (int j = 0; j < outputSize * outputSize; j++) {
        outputData.push_back((float)0);
    }
    extent<2> outputExtent(MATRIXSIZE / SAMPLESIZE, MATRIXSIZE / SAMPLESIZE);
    array<float, 2> averages(outputExtent, outputData.begin(), outputData.end());

    // Use tiles that are SAMPLESIZE x SAMPLESIZE.
    // Find the average of the values in each tile.
    // The only reference-type variable you can pass into the parallel_for_each call
    // is a concurrency::array.
    parallel_for_each(matrix.extent.tile<SAMPLESIZE, SAMPLESIZE>(),
        [=, &averages] (tiled_index<SAMPLESIZE, SAMPLESIZE> t_idx) restrict(amp)
    {
        // Copy the values of the tile into a tile-sized array.
        tile_static float tileValues[SAMPLESIZE][SAMPLESIZE];
        tileValues[t_idx.local[0]][t_idx.local[1]] = matrix[t_idx];

        // Wait for the tile-sized array to load before you calculate the average.
        t_idx.barrier.wait();

        // If you remove the if statement, then the calculation executes for every
        // thread in the tile, and makes the same assignment to averages each time.
        if (t_idx.local[0] == 0 && t_idx.local[1] == 0) {
            for (int trow = 0; trow < SAMPLESIZE; trow++) {
                for (int tcol = 0; tcol < SAMPLESIZE; tcol++) {
                    averages(t_idx.tile[0],t_idx.tile[1]) += tileValues[trow][tcol];
                }
            }
            averages(t_idx.tile[0],t_idx.tile[1]) /= (float) (SAMPLESIZE * SAMPLESIZE);
        }
    });

    // Print out the results.
    // You cannot access the values in averages directly. You must copy them
    // back to a CPU variable.
    outputData = averages;
    for (int row = 0; row < outputSize; row++) {
        for (int col = 0; col < outputSize; col++) {
            std::cout << outputData[row*outputSize + col] << " ";
        }
        std::cout << "\n";
    }
    // Output for SAMPLESIZE = 2 is:
    //  4.5  6.5  8.5 10.5
    // 20.5 22.5 24.5 26.5
    // 36.5 38.5 40.5 42.5
    // 52.5 54.5 56.5 58.5

    // Output for SAMPLESIZE = 4 is:
    // 13.5 17.5
    // 45.5 49.5
}

int main() {
    SamplingExample();
}
```

## <a name="race-conditions"></a>Condições de corrida

Pode ser tentador criar uma variável `tile_static` chamada `total` e incrementar essa variável para cada thread, da seguinte maneira:

```cpp
// Do not do this.
tile_static float total;
total += matrix[t_idx];
t_idx.barrier.wait();

averages(t_idx.tile[0],t_idx.tile[1]) /= (float) (SAMPLESIZE* SAMPLESIZE);
```

O primeiro problema dessa abordagem é que `tile_static` variáveis não podem ter inicializadores. O segundo problema é que há uma condição de corrida na atribuição para `total`, porque todos os threads no bloco têm acesso à variável em nenhuma ordem específica. Você pode programar um algoritmo para permitir que apenas um thread acesse o total em cada barreira, conforme mostrado a seguir. No entanto, essa solução não é extensível.

```cpp
// Do not do this.
tile_static float total;
if (t_idx.local[0] == 0&& t_idx.local[1] == 0) {
    total = matrix[t_idx];
}
t_idx.barrier.wait();

if (t_idx.local[0] == 0&& t_idx.local[1] == 1) {
    total += matrix[t_idx];
}
t_idx.barrier.wait();

// etc.
```

## <a name="memory-fences"></a>Limites de memória

Há dois tipos de acessos à memória que devem ser sincronizados — acesso de memória global e `tile_static` acesso à memória. Um objeto `concurrency::array` aloca apenas memória global. Um `concurrency::array_view` pode referenciar memória global, `tile_static` memória ou ambos, dependendo de como ele foi construído.  Há dois tipos de memória que devem ser sincronizados:

- memória global

- `tile_static`

Um *limite de memória* garante que os acessos de memória estejam disponíveis para outros threads no bloco de threads e que os acessos de memória sejam executados de acordo com a ordem do programa. Para garantir isso, os compiladores e os processadores não reordenam as leituras e gravações na cerca. No C++ amp, um limite de memória é criado por uma chamada para um destes métodos:

- [método tile_barrier:: Wait](reference/tile-barrier-class.md#wait): cria uma cerca em uma memória global e `tile_static`.

- [método tile_barrier:: wait_with_all_memory_fence](reference/tile-barrier-class.md#wait_with_all_memory_fence): cria uma cerca em uma memória global e `tile_static`.

- [método tile_barrier:: wait_with_global_memory_fence](reference/tile-barrier-class.md#wait_with_global_memory_fence): cria uma cerca em apenas memória global.

- [método tile_barrier:: wait_with_tile_static_memory_fence](reference/tile-barrier-class.md#wait_with_tile_static_memory_fence): cria uma cerca em apenas `tile_static` memória.

Chamar o limite específico que você precisa pode melhorar o desempenho do seu aplicativo. O tipo de barreira afeta como o compilador e as instruções de reordenação de hardware. Por exemplo, se você usar um limite de memória global, ele se aplicará somente a acessos de memória global e, portanto, o compilador e o hardware poderão reordenar leituras e gravações `tile_static` variáveis nos dois lados da cerca.

No próximo exemplo, a barreira sincroniza as gravações para `tileValues`, uma variável `tile_static`. Neste exemplo, `tile_barrier::wait_with_tile_static_memory_fence` é chamado em vez de `tile_barrier::wait`.

```cpp
// Using a tile_static memory fence.
parallel_for_each(matrix.extent.tile<SAMPLESIZE, SAMPLESIZE>(),
    [=, &averages] (tiled_index<SAMPLESIZE, SAMPLESIZE> t_idx) restrict(amp)
{
    // Copy the values of the tile into a tile-sized array.
    tile_static float tileValues[SAMPLESIZE][SAMPLESIZE];
    tileValues[t_idx.local[0]][t_idx.local[1]] = matrix[t_idx];

    // Wait for the tile-sized array to load before calculating the average.
    t_idx.barrier.wait_with_tile_static_memory_fence();

    // If you remove the if statement, then the calculation executes
    // for every thread in the tile, and makes the same assignment to
    // averages each time.
    if (t_idx.local[0] == 0&& t_idx.local[1] == 0) {
        for (int trow = 0; trow <SAMPLESIZE; trow++) {
            for (int tcol = 0; tcol <SAMPLESIZE; tcol++) {
                averages(t_idx.tile[0],t_idx.tile[1]) += tileValues[trow][tcol];
            }
        }
    averages(t_idx.tile[0],t_idx.tile[1]) /= (float) (SAMPLESIZE* SAMPLESIZE);
    }
});
```

## <a name="see-also"></a>Consulte também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Palavra-chave tile_static](../../cpp/tile-static-keyword.md)
