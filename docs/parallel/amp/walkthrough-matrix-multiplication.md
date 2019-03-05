---
title: 'Passo a passo: Multiplicação de matriz'
ms.date: 11/19/2018
ms.assetid: 61172e8b-da71-4200-a462-ff3a908ab0cf
ms.openlocfilehash: 597ba0f47c7b081f62c82bf8e1ca01c286d35140
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300967"
---
# <a name="walkthrough-matrix-multiplication"></a>Passo a passo: Multiplicação de matriz

Este passo a passo demonstra como usar o C++ AMP para acelerar a execução de multiplicação de matriz. Dois algoritmos são apresentados, sem lado a lado e outra com lado a lado.

## <a name="prerequisites"></a>Pré-requisitos

Antes de começar:

- Leia [visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md).

- Leia [usando blocos](../../parallel/amp/using-tiles.md).

- Certifique-se de que Windows 7, Windows 8, Windows Server 2008 R2 ou Windows Server 2012 está instalado no seu computador.

### <a name="to-create-the-project"></a>Para criar o projeto

1. Na barra de menus no Visual Studio, escolha **arquivo** > **New** > **projeto**.

1. Sob **Installed** no painel de modelos, selecione **Visual C++**.

1. Selecione **projeto vazio**, insira *MatrixMultiply* no **nome** caixa e, em seguida, escolha o **Okey** botão.

1. Escolha o botão **Avançar**.

1. Na **Gerenciador de soluções**, abra o menu de atalho **arquivos de origem**e, em seguida, escolha **Add** > **Novo Item**.

1. No **Adicionar Novo Item** caixa de diálogo, selecione **arquivo do C++ (. cpp)**, insira *MatrixMultiply.cpp* no **nome** caixa e, em seguida, escolha o  **Adicionar** botão.

## <a name="multiplication-without-tiling"></a>Multiplicação sem lado a lado

Nesta seção, considere a multiplicação de duas matrizes, A e B, que são definidos da seguinte maneira:

![3&#45;por&#45;matriz de 2 A](../../parallel/amp/media/campmatrixanontiled.png "3&#45;,&#45;matriz 2 A")

![2&#45;por&#45;matriz 3 B](../../parallel/amp/media/campmatrixbnontiled.png "2&#45;,&#45;matriz 3 B")

Um é uma matriz de 3 por 2 e B é uma matriz 2 por 3. O produto da multiplicação A por B é a seguinte matriz de 3 por 3. O produto é calculado multiplicando-se as linhas de um pelas colunas de B, elemento por elemento.

![3&#45;por&#45;matriz 3 produtos](../../parallel/amp/media/campmatrixproductnontiled.png "3&#45;,&#45;matriz 3 produtos")

### <a name="to-multiply-without-using-c-amp"></a>Multiplicar sem usar o C++ AMP

1. Abra MatrixMultiply.cpp e use o código a seguir para substituir o código existente.

```cpp
#include <iostream>

void MultiplyWithOutAMP() {
    int aMatrix[3][2] = {{1, 4}, {2, 5}, {3, 6}};
    int bMatrix[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int product[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 2; inner++) {
                product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
            }
            std::cout << product[row][col] << "  ";
        }
        std::cout << "\n";
    }
}

void main() {
    MultiplyWithOutAMP();
    getchar();
}
```

   O algoritmo é uma implementação simples da definição de multiplicação de matriz. Ele não usa qualquer algoritmo paralelo ou multithread para reduzir o tempo de computação.

1. Na barra de menus, escolha **Arquivo** > **Salvar Todos**.

1. Escolha o **F5** atalho de teclado para iniciar a depuração e verificar se a saída está correta.

1. Escolher **Enter** para sair do aplicativo.

### <a name="to-multiply-by-using-c-amp"></a>Multiplicar usando C++ AMP

1. No MatrixMultiply.cpp, adicione o código a seguir antes do `main` método.

```cpp
void MultiplyWithAMP() {
    int aMatrix[] = { 1, 4, 2, 5, 3, 6 };
    int bMatrix[] = { 7, 8, 9, 10, 11, 12 };
    int productMatrix[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    array_view<int, 2> a(3, 2, aMatrix);

    array_view<int, 2> b(2, 3, bMatrix);

    array_view<int, 2> product(3, 3, productMatrix);

    parallel_for_each(product.extent,
        [=] (index<2> idx) restrict(amp) {
            int row = idx[0];
            int col = idx[1];
            for (int inner = 0; inner <2; inner++) {
                product[idx] += a(row, inner)* b(inner, col);
            }
        });

    product.synchronize();

    for (int row = 0; row <3; row++) {
        for (int col = 0; col <3; col++) {
            //std::cout << productMatrix[row*3 + col] << "  ";
            std::cout << product(row, col) << "  ";
        }
        std::cout << "\n";
    }
}
```

   O código de AMP lembra o código de AMP não. A chamada para `parallel_for_each` inicia um thread para cada elemento na `product.extent`e substitui o `for` loops de linha e coluna. O valor da célula na linha e coluna está disponível em `idx`. Você pode acessar os elementos de uma `array_view` objeto usando o `[]` operador e uma variável de índice, ou o `()` operador e as variáveis de linha e coluna. O exemplo demonstra ambos os métodos. O `array_view::synchronize` método copia os valores da `product` variável de volta para o `productMatrix` variável.

1. Adicione o seguinte `include` e `using` instruções na parte superior da MatrixMultiply.cpp.

```cpp
#include <amp.h>
using namespace concurrency;
```

1. Modificar a `main` método para chamar o `MultiplyWithAMP` método.

```cpp
void main() {
    MultiplyWithOutAMP();
    MultiplyWithAMP();
    getchar();
}
```

1. Escolha o **Ctrl**+**F5** atalho de teclado para iniciar a depuração e verificar se a saída está correta.

1. Escolha o **barra de espaços** para sair do aplicativo.

## <a name="multiplication-with-tiling"></a>Multiplicação com lado a lado

Lado a lado é uma técnica em que você particionar dados em subconjuntos de tamanhos iguais, que são conhecidos como blocos. Três coisas mudam quando você usa o lado a lado.

- Você pode criar `tile_static` variáveis. Acesso a dados no `tile_static` espaço pode ser muitas vezes mais rápido do que o acesso aos dados no espaço global. Uma instância de um `tile_static` variável é criada para cada bloco, e todos os threads no tile têm acesso à variável. O principal benefício do tiling é o ganho de desempenho devido a `tile_static` acesso.

- Você pode chamar o [tile_barrier:: wait](reference/tile-barrier-class.md#wait) método para interromper todos os threads em um bloco em uma linha de código especificada. Você não pode garantir a ordem em que os threads serão executados, só que todos os threads em um bloco deixará a chamada para `tile_barrier::wait` antes de continuar a execução.

- Você tem acesso ao índice do thread relativo a todo o `array_view` objeto e o índice relativo ao tile. Usando o índice local, você pode tornar seu código mais fácil de ler e depurar.

Para tirar proveito de lado a lado em uma multiplicação de matriz, o algoritmo deve dividir a matriz em blocos e, em seguida, copie os dados do bloco em `tile_static` variáveis para acesso mais rápido. Neste exemplo, a matriz é particionada em submatrices de tamanho igual. O produto é encontrado multiplicando os submatrices. As duas matrizes e seus produtos neste exemplo são:

![4&#45;por&#45;matriz de 4 A](../../parallel/amp/media/campmatrixatiled.png "4&#45;,&#45;matriz de 4 A")

![4&#45;por&#45;matriz 4 B](../../parallel/amp/media/campmatrixbtiled.png "4&#45;,&#45;matriz 4 B")

![4&#45;por&#45;matriz de produtos 4](../../parallel/amp/media/campmatrixproducttiled.png "4&#45;por&#45;matriz produto 4")

As matrizes são particionadas em matrizes de quatro de 2 x 2, que são definidas da seguinte maneira:

![4&#45;por&#45;matriz de 4 A particionados em 2&#45;por&#45;sub 2&#45;matrizes](../../parallel/amp/media/campmatrixapartitioned.png "4&#45;por&#45;matriz de 4 A particionados em 2&#45;por&#45;sub 2&#45;matrizes")

![4&#45;por&#45;matriz 4 B particionados em 2&#45;por&#45;sub 2&#45;matrizes](../../parallel/amp/media/campmatrixbpartitioned.png "4&#45;por&#45;matriz 4 B particionados em 2&#45;por&#45;sub 2&#45;matrizes")

O produto de A e B agora pode ser gravada e calculada da seguinte maneira:

![4&#45;por&#45;matriz de 4 A B particionados em 2&#45;por&#45;sub 2&#45;matrizes](../../parallel/amp/media/campmatrixproductpartitioned.png "4&#45;por&#45;a matriz de 4 A B particionados em 2&#45;por&#45;sub 2&#45;matrizes")

Porque as matrizes `a` por meio de `h` são matrizes de 2 x 2, todos os produtos e somas, eles também são matrizes de 2 x 2. Ele segue também que o produto de A e B é uma 4x4 matriz, conforme o esperado. Para verificar rapidamente o algoritmo, calcule o valor do elemento na primeira linha, primeira coluna no produto. No exemplo, isso seria o valor do elemento na primeira linha e primeira coluna da `ae + bg`. Você só precisará calcular a primeira coluna, a primeira linha da `ae` e `bg` para cada termo. Esse valor para `ae` é `(1 * 1) + (2 * 5) = 11`. O valor para `bg` é `(3 * 1) + (4 * 5) = 23`. O valor final é `11 + 23 = 34`, que está correto.

Para implementar esse algoritmo, o código:

- Usa um `tiled_extent` do objeto, em vez de um `extent` do objeto no `parallel_for_each` chamar.

- Usa um `tiled_index` do objeto, em vez de um `index` do objeto no `parallel_for_each` chamar.

- Cria `tile_static` variáveis para armazenar os submatrices.

- Usa o `tile_barrier::wait` método parar os threads para o cálculo dos produtos das submatrices.

### <a name="to-multiply-by-using-amp-and-tiling"></a>Multiplicar usando AMP e lado a lado

1. No MatrixMultiply.cpp, adicione o código a seguir antes do `main` método.

```cpp
void MultiplyWithTiling() {
    // The tile size is 2.
    static const int TS = 2;

    // The raw data.
    int aMatrix[] = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 };
    int bMatrix[] = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 };
    int productMatrix[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    // Create the array_view objects.
    array_view<int, 2> a(4, 4, aMatrix);
    array_view<int, 2> b(4, 4, bMatrix);
    array_view<int, 2> product(4, 4, productMatrix);

    // Call parallel_for_each by using 2x2 tiles.
    parallel_for_each(product.extent.tile<TS, TS>(),
        [=] (tiled_index<TS, TS> t_idx) restrict(amp)
        {
            // Get the location of the thread relative to the tile (row, col)
            // and the entire array_view (rowGlobal, colGlobal).
            int row = t_idx.local[0];
            int col = t_idx.local[1];
            int rowGlobal = t_idx.global[0];
            int colGlobal = t_idx.global[1];
            int sum = 0;

            // Given a 4x4 matrix and a 2x2 tile size, this loop executes twice for each thread.
            // For the first tile and the first loop, it copies a into locA and e into locB.
            // For the first tile and the second loop, it copies b into locA and g into locB.
            for (int i = 0; i < 4; i += TS) {
                tile_static int locA[TS][TS];
                tile_static int locB[TS][TS];
                locA[row][col] = a(rowGlobal, col + i);
                locB[row][col] = b(row + i, colGlobal);
                // The threads in the tile all wait here until locA and locB are filled.
                t_idx.barrier.wait();

                // Return the product for the thread. The sum is retained across
                // both iterations of the loop, in effect adding the two products
                // together, for example, a*e.
                for (int k = 0; k < TS; k++) {
                    sum += locA[row][k] * locB[k][col];
                }

                // All threads must wait until the sums are calculated. If any threads
                // moved ahead, the values in locA and locB would change.
                t_idx.barrier.wait();
                // Now go on to the next iteration of the loop.
            }

            // After both iterations of the loop, copy the sum to the product variable by using the global location.
            product[t_idx.global] = sum;
        });

    // Copy the contents of product back to the productMatrix variable.
    product.synchronize();

    for (int row = 0; row <4; row++) {
        for (int col = 0; col <4; col++) {
            // The results are available from both the product and productMatrix variables.
            //std::cout << productMatrix[row*3 + col] << "  ";
            std::cout << product(row, col) << "  ";
        }
        std::cout << "\n";
    }
}
```

    This example is significantly different than the example without tiling. The code uses these conceptual steps:

    1. Copiar os elementos de bloco [0,0] da `a` em `locA`. Copiar os elementos de bloco [0,0] da `b` em `locB`. Observe que `product` é colocada lado a lado não `a` e `b`. Portanto, você usa índices globais para acessar `a, b`, e `product`. A chamada para `tile_barrier::wait` é essencial. Ele interrompe todos os segmentos no bloco até que ambas `locA` e `locB` são preenchidos.

    2. Multiplicar `locA` e `locB` e colocar os resultados em `product`.

    3. Copiar os elementos de bloco [0,1] da `a` em `locA`. Copiar os elementos de bloco [1,0] da `b` em `locB`.

    4. Multiplicar `locA` e `locB` e adicione-os aos resultados que já estão em `product`.

    5. A multiplicação de lado a lado [0,0] foi concluída.

    6. Repita para os quatro blocos. Não há nenhuma indexação especificamente para os blocos e os threads podem ser executados em qualquer ordem. Como cada thread é executado, o `tile_static` variáveis são criadas para cada peça adequadamente e a chamada para `tile_barrier::wait` controla o fluxo de programa.

    7. Conforme você examina atentamente o algoritmo, observe que cada submatrix seja carregado em um `tile_static` memória duas vezes. Essa transferência de dados levar tempo. No entanto, quando os dados estiverem em `tile_static` memória, o acesso aos dados é muito mais rápido. Como calcular os produtos requer acesso repetido com os valores nos submatrices, há um ganho de desempenho geral. Para cada algoritmo, experimentação é necessária para localizar o algoritmo ideal e tamanho de bloco.

         Nos exemplos AMP não e não de bloco, cada elemento da e B é acessado quatro vezes da memória global para calcular o produto. O exemplo de bloco, cada elemento é acessado dobro de memória global em quatro vezes o `tile_static` memória. Isso não é um ganho de desempenho significativa. No entanto, se a e B foram 1024 x 1024 matrizes e o tamanho de bloco eram 16, haveria um ganho de desempenho significativa. Nesse caso, cada elemento deve ser copiado para `tile_static` memória somente 16 vezes e acessados de `tile_static` memória tempos de 1024.

2. Modifique o método principal para chamar o `MultiplyWithTiling` método, conforme mostrado.

```cpp
void main() {
    MultiplyWithOutAMP();
    MultiplyWithAMP();
    MultiplyWithTiling();
    getchar();
}
```

3. Escolha o **Ctrl**+**F5** atalho de teclado para iniciar a depuração e verificar se a saída está correta.

4. Escolha o **espaço** barra para sair do aplicativo.

## <a name="see-also"></a>Consulte também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Passo a passo: Depurando um aplicativo C++ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)
