---
title: "Usando blocos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: acb86a86-2b7f-43f1-8fcf-bcc79b21d9a8
caps.latest.revision: 18
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando blocos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode usar tiling para maximizar a aceleração do seu aplicativo.  O tiling divide threads em subconjuntos retangulares iguais ou *tiles*.  Se você usar um algoritmo de agrupamento lado a lado e um tamanho de tile apropriados, você pode até obter mais aceleração de seu código de C\+\+ AMP.  Os componentes básicos do tiling são:  
  
-   `tile_static` variáveis.  O principal benefício do tiling é o ganho de desempenho de acesso de `tile_static`.  Acesso a dados na memória `tile_static` pode ser significativamente mais rápido do que o acesso a dados no espaço global \(objetos `array` ou `array_view`\).  Uma instância de uma variável `tile_static` é criada para cada tile, e todos os threads no tile tem acesso à variável.  Em um típico algoritmo de agrupamento lado a lado, os dados são copiados para a memória `tile_static` uma vez a partir da memória global e, em seguida, acessados várias vezes a partir da memória `tile_static`.  
  
-   [Método tile\_barrier::wait](../Topic/tile_barrier::wait%20Method.md).  Uma chamada a `tile_barrier::wait` suspende a execução do thread atual até que todos os threads no mesmo tile atinjam a chamada para `tile_barrier::wait`.  Você não pode garantir a ordem em que os threads serão executados. Garante\-se apenas que nenhum thread no tile será executado após a chamada a `tile_barrier::wait` até que todos os threads tenham atingido a chamada.  Isso significa que usando o método `tile_barrier::wait`, você pode executar tarefas em uma base de tile\-por\-tile em vez de uma base de thread\-por\-thread.  Um algoritmo típico de disposição possui código para inicializar a memória `tile_static` para toda a disposição, seguido por uma chamada para `tile_barrer::wait`.  O código que segue `tile_barrier::wait` contém cálculos que exigem acesso a todos os valores `tile_static`.  
  
-   Indexação local e global.  Você tem acesso ao índice do thread relativo a todo o `array_view` ou ao objeto `array` e o índice relativo ao tile.  Usar o índice local pode tornar seu código mais fácil de ler e depurar.  Normalmente, você usa a indexação local para acessar as variáveis `tile_static` e a indexação global para acessar as variáveis `array` e `array_view`.  
  
-   [Classe tiled\_extent](../../parallel/amp/reference/tiled-extent-class.md) e [Classe tiled\_index](../../parallel/amp/reference/tiled-index-class.md).  Você usa um objeto `tiled_extent` em vez de um objeto `extent` na chamada `parallel_for_each`.  Você usa um objeto `tiled_index` em vez de um objeto `index` na chamada `parallel_for_each`.  
  
 Para se beneficiar com o tiling, o seu algoritmo deve dividir o domínio de cálculo em tiles e copiar os dados de tile em variáveis `tile_static` para acesso mais rápido.  
  
## Exemplo de índices globais, locais e de tile  
 O diagrama a seguir representa uma matriz 8x9 de dados organizados em tiles 2x3.  
  
 ![Uma matriz de 8 x 9 dividida em 2 x 3 peças](../../parallel/amp/media/usingtilesmatrix.png "UsingTilesMatrix")  
  
 O exemplo seguinte exibe os índices globais, locais e de tile dessa matriz de agrupamento lado a lado.  Um objeto `array_view` é criado usando elementos do tipo `Description`.  O `Description` mantém os índices globais, locais e de tile do elemento na matriz.  O código na chamada a `parallel_for_each` define os valores dos índices globais, locais e de tile de cada elemento.  A saída exibe os valores nas estruturas `Description`.  
  
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
    int colorValue = (color == 0) ? 4 : 2;  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorValue);  
}  
  
// A helper function for formatting the output.  
void SetConsoleSize(int height, int width) {  
    COORD coord; coord.X = width; coord.Y = height;  
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
    SMALL_RECT* rect = new SMALL_RECT();  
    rect->Left = 0; rect->Top = 0; rect->Right = width; rect->Bottom = height;  
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, rect);  
}  
  
// This method creates an 8x9 matrix of Description structures. In the call to parallel_for_each, the structure is updated   
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
  
 O trabalho principal do exemplo é na definição do objeto `array_view` e a chamada a `parallel_for_each`.  
  
1.  O vetor de estruturas `Description` é copiado em um objeto `array_view` 8x9.  
  
2.  O método `parallel_for_each` é chamado com um objeto `tiled_extent` assim como o domínio do cálculo.  O objeto `tiled_extent` é criado chamando o método `extent::tile()` da variável `descriptions`.  Os parâmetros do tipo de chamada para `extent::tile()`, `<2,3>`, especifica que tiles 2x3 são criados.  Assim, a matriz 8x9 é distribuída em 12 tiles, quatro linhas e três colunas.  
  
3.  O método `parallel_for_each` é chamado usando um objeto `tiled_index<2,3>` \(`t_idx`\) como o índice.  Os parâmetros de tipo do índice \(`t_idx`\) devem corresponder aos parâmetros de tipo do domínio do cálculo \(`descriptions.extent.tile< 2, 3>()`\).  
  
4.  Quando cada thread é executado, o índice `t_idx` retorna informações sobre em qual tile o thread está \(propriedade `tiled_index::tile`\) e a localização do thread dentro do tile \(propriedade `tiled_index::local`\).  
  
## Sincronização de Tile—tile\_static e tile\_barrier::wait  
 O exemplo anterior ilustra os índices e layout do tile, mas não é, por si só, muito útil.  O tiling se torna útil quando os tiles são essenciais para o algoritmo e exploram variáveis `tile_static`.  Como todos os threads em um tile têm acesso a variáveis `tile_static`, chamadas para `tile_barrier::wait` são usadas para sincronizar o acesso a variáveis `tile_static`.  Embora todos os threads em um tile tenham acesso a variáveis `tile_static`, não há ordem garantida de execução dos threads no tile.  O exemplo a seguir mostra como usar variáveis `tile_static` e o método `tile_barrier::wait` para calcular o valor médio de cada tile.  Aqui estão as chaves para entender o exemplo:  
  
1.  Os rawData são armazenados em uma matriz 8x8.  
  
2.  O tamanho do tile é 2x2.  Isso cria uma grade 4x4 de tiles e as médias podem ser armazenadas em uma matriz 4x4, usando um objeto `array`.  Há somente um número limitado de tipos que você pode capturar por referência em uma função restrita de AMP.  A classe `array` é um deles.  
  
3.  O tamanho da matriz e o tamanho da amostra são definidos usando instruções `#define`, porque os parâmetros de tipo para `array`, `array_view`, `extent`, e `tiled_index` devem ser valores constantes.  Você também pode usar declarações `const int static`.  Como um benefício adicional, é trivial alterar o tamanho da amostra para calcular a média sobre tiles 4x4.  
  
4.  Uma matriz `tile_static` 2x2 de valores de flutuação é declarada para cada tile.  Embora a declaração esteja no caminho do código para cada thread, apenas uma matriz é criada para cada tile na matriz.  
  
5.  Há uma linha de código para copiar os valores em cada tile para a matriz `tile_static`.  Para cada thread, após o valor ser copiado para a matriz, a execução no thread para devido a chamada para `tile_barrier::wait`.  
  
6.  Quando todos os threads em um tile tiverem atingido a barreira, a média pode ser calculada.  Como o código é executado para cada thread, há uma instrução `if` apenas para calcular a média em um thread.  A média é armazenada na variável médias.  A barreira é, essencialmente, a construção que controla os cálculos pelos tiles, tanto quanto você pode usar um loop `for`.  
  
7.  Os dados na variável `averages`, pois ela é um objeto `array`, devem ser copiados de volta no host.  Este exemplo usa o operador de conversão de vetor.  
  
8.  No exemplo completo, você pode alterar SAMPLESIZE para 4 e o código é executado corretamente sem outras alterações.  
  
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
  
## Condições de Corrida  
 Pode ser tentador criar uma variável `tile_static` chamada `total` e incrementar essa variável para cada thread, assim:  
  
```cpp  
  
// Do not do this.  
tile_static float total;  
total += matrix[t_idx];  
t_idx.barrier.wait();  
averages(t_idx.tile[0],t_idx.tile[1]) /= (float) (SAMPLESIZE * SAMPLESIZE);  
  
```  
  
 A primeira questão com essa abordagem é que as variáveis `tile_static` não podem ter inicializadores.  O segundo problema é que há uma condição de corrida na atribuição a `total`, porque todos os threads no tile têm acesso à variável sem uma ordem específica.  Você poderia programar um algoritmo para permitir que somente um thread acesse o total em cada barreira, como mostrado em seguida.  No entanto, esta solução não é extensível.  
  
```cpp  
  
// Do not do this.  
tile_static float total;  
if (t_idx.local[0] == 0 && t_idx.local[1] == 0) {  
    total = matrix[t_idx];  
}  
t_idx.barrier.wait();  
  
if (t_idx.local[0] == 0 && t_idx.local[1] == 1) {  
    total += matrix[t_idx];  
}  
t_idx.barrier.wait();  
  
// etc.  
  
```  
  
## Limites de Memória  
 Há dois tipos de acessos de memória que devem ser sincronizados—acesso de memória global e acesso de memória `tile_static`.  O objeto `concurrency::array` aloca somente memória global.  Um `concurrency::array_view` pode fazer referência à memória global, à memória `tile_static` ou ambas, dependendo de como foi construído.  Há dois tipos de memória que devem ser sincronizadas:  
  
-   memória global  
  
-   `tile_static`  
  
 Um *limite de memória* garante que os acessos à memória estejam disponíveis para outros threads no tile de thread, e que os acessos à memória sejam executados de acordo com a ordem do programa.  Para garantir isso, os compiladores e os processadores não reordenam leituras e escritas através dos limites.  No C\+\+ AMP, um limite de memória é criado por uma chamada a um dos seguintes métodos:  
  
-   [Método tile\_barrier::wait](../Topic/tile_barrier::wait%20Method.md): Cria um limite ao redor das memórias global e `tile_static`.  
  
-   [Método tile\_barrier::wait\_with\_all\_memory\_fence](../Topic/tile_barrier::wait_with_all_memory_fence%20Method.md): Cria um limite ao redor das memórias global e `tile_static`.  
  
-   [Método tile\_barrier::wait\_with\_global\_memory\_fence](../Topic/tile_barrier::wait_with_global_memory_fence%20Method.md): Cria um limite em torno da memória global apenas.  
  
-   [Método tile\_barrier::wait\_with\_tile\_static\_memory\_fence](../Topic/tile_barrier::wait_with_tile_static_memory_fence%20Method.md): Cria um limite somente em torno de memória `tile_static`.  
  
 Chamar o limite específico que você precisa pode melhorar o desempenho do seu aplicativo.  O tipo de barreira afeta como o compilador e o hardware reordenam as instruções.  Por exemplo, se você usar um limite global de memória, ele se aplica somente a acessos de memória global e portanto, o compilador e o hardware podem reordenar leituras e escritas a variáveis `tile_static` nos dois lados do limite.  
  
 No exemplo a seguir, a barreira sincroniza as escritas a `tileValues`, uma variável `tile_static`.  Nesse exemplo, `tile_barrier::wait_with_tile_static_memory_fence` é chamado em vez de `tile_barrier::wait`.  
  
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
  
```  
  
## Consulte também  
 [C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)   
 [Palavra\-chave tile\_static](../Topic/tile_static%20Keyword.md)