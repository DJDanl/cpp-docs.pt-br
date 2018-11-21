---
title: Usando blocos
ms.date: 11/19/2018
ms.assetid: acb86a86-2b7f-43f1-8fcf-bcc79b21d9a8
ms.openlocfilehash: ede62c80a83b5f5fc1d691bf52dde67140e68246
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52176088"
---
# <a name="using-tiles"></a>Usando blocos

Você pode usar tiling para maximizar a aceleração do seu aplicativo. Tiling divide threads em subconjuntos retangulares iguais ou *blocos*. Se você usar um tamanho de bloco apropriado e o algoritmo lado a lado, você pode obter aceleração ainda mais a partir do código C++ AMP. Os componentes básicos do tiling são:

- `tile_static` variáveis. O principal benefício do tiling é o ganho de desempenho `tile_static` acesso. Acesso a dados no `tile_static` memória pode ser significativamente mais rápida do que o acesso aos dados no espaço global (`array` ou `array_view` objetos). Uma instância de um `tile_static` variável é criada para cada bloco, e todos os threads no tile têm acesso à variável. Em um típico algoritmo lado a lado, os dados são copiados para `tile_static` memória uma vez da memória global e, em seguida, acessados muitas vezes a partir de `tile_static` memória.

- [tile_barrier:: wait método](reference/tile-barrier-class.md#wait). Uma chamada para `tile_barrier::wait` suspende a execução do thread atual até que todos os threads no mesmo tile atinjam a chamada para `tile_barrier::wait`. Você não pode garantir a ordem em que os threads serão executados, só que não há threads no tile serão executado após a chamada para `tile_barrier::wait` até que todos os threads tenham atingido a chamada. Isso significa que, ao usar o `tile_barrier::wait` método, você pode executar tarefas em uma base de tile-por-tile em vez de uma base de thread-por-thread. Um algoritmo típico de lado a lado tiver o código para inicializar o `tile_static` memória para o bloco inteiro seguido por uma chamada para `tile_barrer::wait`. Código que segue `tile_barrier::wait` contém cálculos que exigem acesso a todos os `tile_static` valores.

- Indexação local e global. Você tem acesso ao índice do thread relativo a todo `array_view` ou `array` objeto e o índice relativo ao tile. Usando o índice local pode tornar seu código mais fácil de ler e depurar. Normalmente, você usa a indexação local para acessar `tile_static` variáveis e indexação global para acessar `array` e `array_view` variáveis.

- [Classe tiled_extent](../../parallel/amp/reference/tiled-extent-class.md) e [classe tiled_index](../../parallel/amp/reference/tiled-index-class.md). Você usa um `tiled_extent` do objeto, em vez de um `extent` do objeto no `parallel_for_each` chamar. Você usa um `tiled_index` do objeto, em vez de um `index` do objeto no `parallel_for_each` chamar.

Para tirar proveito de lado a lado, seu algoritmo deve dividir o domínio de cálculo em blocos e, em seguida, copie os dados do bloco em `tile_static` variáveis para acesso mais rápido.

## <a name="example-of-global-tile-and-local-indices"></a>Exemplo de Global, lado a lado, locais e de Tile

O diagrama a seguir representa uma 8x9 matriz de dados organizados em 2x3 tiles.

![8&#45;por&#45;matriz 9 dividido em 2&#45;por&#45;3 blocos](../../parallel/amp/media/usingtilesmatrix.png "8&#45;por&#45;9 matriz dividida em 2&#45;por&#45;3 blocos")

O exemplo a seguir exibe o bloco global, e lado a lado local Tile dessa matriz. Uma `array_view` objeto é criado usando elementos do tipo `Description`. O `Description` mantém global, lado a lado, locais e Tile do elemento na matriz. O código na chamada para `parallel_for_each` define os valores do global, lado a lado e índices de locais de cada elemento. A saída exibe os valores de `Description` estruturas.

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

void main() {
    TilingDescription();
    char wait;
    std::cin >> wait;
}
```

O trabalho principal do exemplo é na definição do `array_view` objeto e a chamada para `parallel_for_each`.

1. O vetor dos `Description` estruturas é copiado para um 8x9 `array_view` objeto.

2. O `parallel_for_each` método é chamado com um `tiled_extent` objeto como o domínio de cálculo. O `tiled_extent` objeto é criado chamando o `extent::tile()` método o `descriptions` variável. Os parâmetros de tipo da chamada para `extent::tile()`, `<2,3>`, especifica que 2x3 tiles são criados. Portanto, a 8x9 matriz é lado a lado em 12 tiles, quatro linhas e três colunas.

3. O `parallel_for_each` método é chamado usando um `tiled_index<2,3>` objeto (`t_idx`) como o índice. Os parâmetros de tipo do índice (`t_idx`) deve corresponder aos parâmetros de tipo de domínio de cálculo (`descriptions.extent.tile< 2, 3>()`).

4. Quando cada thread é executado, o índice `t_idx` retorna informações sobre em qual tile o thread está em (`tiled_index::tile` propriedade) e o local do thread dentro do bloco (`tiled_index::local` propriedade).

## <a name="tile-synchronizationtilestatic-and-tilebarrierwait"></a>Sincronização de Tile — tile_static e tile_barrier:: wait

O exemplo anterior ilustra o layout de bloco e índices, mas não é por si só muito útil.  Lado a lado se torna útil quando os tiles são essenciais para o algoritmo e exploram `tile_static` variáveis. Como todos os threads em um tile têm acesso aos `tile_static` variáveis, chamadas para `tile_barrier::wait` são usados para sincronizar o acesso ao `tile_static` variáveis. Embora todos os threads em um tile tenham acesso ao `tile_static` variáveis, não há nenhuma garantia de ordem de execução de threads no tile. O exemplo a seguir mostra como usar `tile_static` variáveis e o `tile_barrier::wait` método para calcular o valor médio de cada bloco. Aqui estão as chaves para entender o exemplo:

1. Os rawData são armazenados em uma 8x8 matriz.

2. O tamanho do bloco é 2 x 2. Isso cria uma 4x4 grade de blocos e as médias podem ser armazenadas em uma 4x4 matriz, usando um `array` objeto. Há apenas um número limitado de tipos que você pode capturar por referência em uma função restrita por AMP. O `array` classe é um deles.

3. O tamanho da matriz e o tamanho da amostra são definidos por meio `#define` instruções, porque os parâmetros de tipo para `array`, `array_view`, `extent`, e `tiled_index` devem ser valores constantes. Você também pode usar `const int static` declarações. Como um benefício adicional, é trivial alterar o tamanho da amostra para calcular a média mais de 4 x 4 blocos.

4. Um `tile_static` matriz 2 x 2 valores float de é declarada para cada peça. Embora a declaração esteja no caminho de código para cada thread, apenas uma matriz é criada para cada tile na matriz.

5. Há uma linha de código para copiar os valores em cada lado a lado para o `tile_static` matriz. Para cada thread, depois que o valor é copiado para a matriz, a execução no thread para devido a chamada para `tile_barrier::wait`.

6. Quando todos os threads em um tile tiverem atingido a barreira, pode ser calculada a média. Como o código é executado para cada thread, há um `if` instrução apenas para calcular a média em um thread. A média é armazenada na variável médias. A barreira é, essencialmente, a construção que controla os cálculos pelos Tiles, tanto quanto você pode usar um `for` loop.

7. Os dados a `averages` variável, porque ele é um `array` de objeto, devem ser copiados para o host. Este exemplo usa o operador de conversão de vetor.

8. O exemplo completo, você pode alterar SAMPLESIZE para 4 e o código é executado corretamente sem outras alterações.

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
    // Output for SAMPLESSIZE = 2 is:
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

Pode ser tentador criar uma `tile_static` variável chamada `total` e incrementar essa variável para cada thread, como este:

```cpp
// Do not do this.
tile_static float total;
total += matrix[t_idx];
t_idx.barrier.wait();

averages(t_idx.tile[0],t_idx.tile[1]) /= (float) (SAMPLESIZE* SAMPLESIZE);
```

O primeiro problema com essa abordagem é que `tile_static` variáveis não podem ter inicializadores. O segundo problema é que há uma condição de corrida na atribuição a `total`, porque todos os threads no tile têm acesso à variável sem nenhuma ordem específica. Você poderia programar um algoritmo para permitir que somente um thread acesse o total em cada barreira, como mostrado a seguir. No entanto, essa solução não é extensível.

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

Há dois tipos de acessos à memória que devem ser sincronizados — acesso de memória global e `tile_static` acesso à memória. Um `concurrency::array` objeto aloca somente memória global. Um `concurrency::array_view` pode fazer referência a memória global, `tile_static` memória, ou ambos, dependendo de como ele foi construído.  Há dois tipos de memória que devem ser sincronizados:

- memória global

- `tile_static`

Um *limite de memória* garante que acessos à memória estejam disponíveis para outros threads no quadro de threads e que a memória acessos sejam executados de acordo com a ordem do programa. Para garantir isso, os compiladores e processadores não reordenam leituras e gravações entre o limite. No C++ AMP, um limite de memória é criado por uma chamada para um dos seguintes métodos:

- [tile_barrier:: wait método](reference/tile-barrier-class.md#wait): cria um limite em torno de ambos global e `tile_static` memória.

- [tile_barrier:: wait_with_all_memory_fence método](reference/tile-barrier-class.md#wait_with_all_memory_fence): cria um limite em torno de ambos global e `tile_static` memória.

- [tile_barrier:: wait_with_global_memory_fence método](reference/tile-barrier-class.md#wait_with_global_memory_fence): cria um limite em torno de memória global apenas.

- [tile_barrier:: wait_with_tile_static_memory_fence método](reference/tile-barrier-class.md#wait_with_tile_static_memory_fence): cria um limite em torno de apenas `tile_static` memória.

Chamar o limite específico que você precisa pode melhorar o desempenho do seu aplicativo. O tipo de barreira afeta como o compilador e o hardware reordenam as instruções. Por exemplo, se você usar um limite de memória global, ele se aplica a acessos de memória global apenas como e por isso, o compilador e o hardware podem reordenar lê e grava `tile_static` variáveis nos dois lados do limite.

No exemplo a seguir, a barreira sincroniza as gravações `tileValues`, um `tile_static` variável. Neste exemplo, `tile_barrier::wait_with_tile_static_memory_fence` é chamado em vez de `tile_barrier::wait`.

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
