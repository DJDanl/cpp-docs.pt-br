---
title: 'Instruções passo a passo: multiplicação de matrizes'
ms.date: 04/23/2019
ms.assetid: 61172e8b-da71-4200-a462-ff3a908ab0cf
ms.openlocfilehash: f30f8dc235bf0e76c342bea26a35bcbb36cfa237
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366808"
---
# <a name="walkthrough-matrix-multiplication"></a>Instruções passo a passo: multiplicação de matrizes

Este passo-a-passo demonstra como usar o C++ AMP para acelerar a execução da multiplicação matricial. Dois algoritmos são apresentados, um sem revestimento e outro com revestimento.

## <a name="prerequisites"></a>Pré-requisitos

Antes de iniciar:

- Leia [a visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md).

- Leia [usando telhas](../../parallel/amp/using-tiles.md).

- Certifique-se de que você está executando pelo menos o Windows 7 ou o Windows Server 2008 R2.

### <a name="to-create-the-project"></a>Para criar o projeto

As instruções para criar um novo projeto variam dependendo da versão do Visual Studio que você instalou. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

### <a name="to-create-the-project-in-visual-studio-2019"></a>Para criar o projeto no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto**.

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++**, **Plataforma** como **Windows** e **Tipo de projeto** como **Console**.

1. Na lista filtrada dos tipos de projeto, escolha **Projeto Vazio** e escolha **Next**. Na página seguinte, digite *MatrixMultiply* na caixa **Nome** para especificar um nome para o projeto e especifique o local do projeto se desejar.

   ![Novo aplicativo de console](../../build/media/mathclient-project-name-2019.png "Novo aplicativo de console")

1. Escolha o botão **Criar** para criar o projeto do cliente.

1. No **Solution Explorer,** abra o menu de atalho para **Arquivos de Origem**e escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** selecione **Arquivo C++ (.cpp)**, digite *MatrixMultiply.cpp* na caixa **Nome** e escolha o botão **Adicionar.**

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-a-project-in-visual-studio-2017-or-2015"></a>Para criar um projeto no Visual Studio 2017 ou 2015

1. Na barra de menus do Visual Studio, escolha **Arquivo** > **Novo** > **Projeto**.

1. Em **Instalado** no painel de modelos, selecione **Visual C++**.

1. Selecione **Projeto vazio,** *digite MatrixMultiply* na caixa **Nome** e escolha o botão **OK.**

1. Escolha o botão **Avançar**.

1. No **Solution Explorer,** abra o menu de atalho para **Arquivos de Origem**e escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** selecione **Arquivo C++ (.cpp)**, digite *MatrixMultiply.cpp* na caixa **Nome** e escolha o botão **Adicionar.**

::: moniker-end

## <a name="multiplication-without-tiling"></a>Multiplicação sem revestimento

Nesta seção, considere a multiplicação de duas matrizes, A e B, que são definidas da seguinte forma:

![3&#45;por&#45;matriz 2 A](../../parallel/amp/media/campmatrixanontiled.png "3&#45;por&#45;matriz 2 A")

![2&#45;por&#45;matriz 3 B](../../parallel/amp/media/campmatrixbnontiled.png "2&#45;por&#45;matriz 3 B")

A é uma matriz 3 por 2 e B é uma matriz 2 por 3. O produto da multiplicação A por B é a seguinte matriz de 3 por 3. O produto é calculado multiplicando as linhas de A pelas colunas de elemento B por elemento.

![3&#45;por&#45;matriz de produtos 3](../../parallel/amp/media/campmatrixproductnontiled.png "3&#45;por&#45;matriz de produtos 3")

### <a name="to-multiply-without-using-c-amp"></a>Para multiplicar sem usar C++ AMP

1. Abra MatrixMultiply.cpp e use o seguinte código para substituir o código existente.

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

   int main() {
       MultiplyWithOutAMP();
       getchar();
   }
   ```

   O algoritmo é uma implementação direta da definição de multiplicação matricial. Ele não usa algoritmos paralelos ou roscados para reduzir o tempo de computação.

1. Na barra de menu, escolha **'Salvar todos'** **do arquivo** > .

1. Escolha o atalho do teclado **F5** para iniciar a depuração e verifique se a saída está correta.

1. Escolha **Enter** para sair do aplicativo.

### <a name="to-multiply-by-using-c-amp"></a>Para multiplicar usando C++ AMP

1. Em MatrixMultiply.cpp, adicione o `main` seguinte código antes do método.

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

   O código AMP se assemelha ao código não-AMP. A chamada `parallel_for_each` para iniciar um `product.extent`segmento para cada `for` elemento em , e substitui os loops para linha e coluna. O valor da célula na linha e `idx`na coluna está disponível em . Você pode acessar os `array_view` elementos de `[]` um objeto usando o `()` operador e uma variável de índice, ou o operador e as variáveis de linha e coluna. O exemplo demonstra ambos os métodos. O `array_view::synchronize` método copia os `product` valores `productMatrix` da variável de volta para a variável.

1. Adicione as `include` `using` seguintes e instruções na parte superior de MatrixMultiply.cpp.

   ```cpp
   #include <amp.h>
   using namespace concurrency;
   ```

1. Modifique `main` o método `MultiplyWithAMP` para chamar o método.

   ```cpp
   int main() {
       MultiplyWithOutAMP();
       MultiplyWithAMP();
       getchar();
   }
   ```

1. Pressione o atalho do teclado **Ctrl**+**F5** para iniciar a depuração e verifique se a saída está correta.

1. Pressione a **barra de espaço** para sair do aplicativo.

## <a name="multiplication-with-tiling"></a>Multiplicação com revestimento

Tiling é uma técnica na qual você particiona dados em subconjuntos de tamanho igual, que são conhecidos como telhas. Três coisas mudam quando você usa azulejo.

- Você pode `tile_static` criar variáveis. O acesso `tile_static` aos dados no espaço pode ser muitas vezes mais rápido do que o acesso aos dados no espaço global. Uma instância `tile_static` de uma variável é criada para cada ladrilho, e todos os segmentos no azulejo têm acesso à variável. O principal benefício da telhas é `tile_static` o ganho de desempenho devido ao acesso.

- Você pode chamar o [método tile_barrier::wait](reference/tile-barrier-class.md#wait) para parar todos os segmentos em um azulejo em uma linha de código especificada. Não é possível garantir a ordem em que os segmentos serão executados, apenas `tile_barrier::wait` que todos os segmentos em um único ladrilho param na chamada antes de continuarem a execução.

- Você tem acesso ao índice do segmento `array_view` relativo a todo o objeto e ao índice relativo ao azulejo. Usando o índice local, você pode tornar seu código mais fácil de ler e depurar.

Para aproveitar o revestimento na multiplicação da matriz, o algoritmo deve dividir `tile_static` a matriz em telhas e, em seguida, copiar os dados do ladrilho em variáveis para acesso mais rápido. Neste exemplo, a matriz é dividida em submatrizes de tamanho igual. O produto é encontrado multiplicando as submatrizs. As duas matrizes e seu produto neste exemplo são:

![4&#45;por&#45;matriz 4 A](../../parallel/amp/media/campmatrixatiled.png "4&#45;por&#45;matriz 4 A")

![4&#45;por&#45;matriz 4 B](../../parallel/amp/media/campmatrixbtiled.png "4&#45;por&#45;matriz 4 B")

![4&#45;por&#45;matriz de produtos 4](../../parallel/amp/media/campmatrixproducttiled.png "4&#45;por&#45;matriz de produtos 4")

As matrizes são divididas em quatro matrizes 2x2, que são definidas da seguinte forma:

![4&#45;por&#45;matriz 4 A dividida em 2&#45;por&#45;2 matrizes sub&#45;](../../parallel/amp/media/campmatrixapartitioned.png "4&#45;por&#45;matriz 4 A dividida em 2&#45;por&#45;2 matrizes sub&#45;")

![4&#45;por&#45;matriz B particionada em 2&#45;por&#45;2 matrizes sub&#45;](../../parallel/amp/media/campmatrixbpartitioned.png "4&#45;por&#45;matriz B particionada em 2&#45;por&#45;2 matrizes sub&#45;")

O produto de A e B pode agora ser escrito e calculado da seguinte forma:

![4&#45;por&#45;matriz 4 A B dividida em 2&#45;por&#45;2 matrizes sub&#45;](../../parallel/amp/media/campmatrixproductpartitioned.png "4&#45;por&#45;matriz 4 A B dividida em 2&#45;por&#45;2 matrizes sub&#45;")

Como as `a` matrizes `h` são matrizes 2x2, todos os produtos e somas deles também são matrizes 2x2. Segue-se também que o produto de A e B é uma matriz 4x4, como esperado. Para verificar rapidamente o algoritmo, calcule o valor do elemento na primeira linha, primeira coluna do produto. No exemplo, esse seria o valor do elemento na primeira `ae + bg`linha e primeira coluna de . Você só tem que calcular a `ae` primeira `bg` coluna, primeira linha de e para cada termo. Esse valor `ae` `(1 * 1) + (2 * 5) = 11`é. O valor para `bg` é `(3 * 1) + (4 * 5) = 23`. O valor `11 + 23 = 34`final é, o que é correto.

Para implementar este algoritmo, o código:

- Usa `tiled_extent` um objeto `extent` em vez `parallel_for_each` de um objeto na chamada.

- Usa `tiled_index` um objeto `index` em vez `parallel_for_each` de um objeto na chamada.

- Cria `tile_static` variáveis para segurar as submatrizs.

- Utiliza `tile_barrier::wait` o método para parar os fios para o cálculo dos produtos das submatrizs.

### <a name="to-multiply-by-using-amp-and-tiling"></a>Para multiplicar usando AMP e ladrilho

1. Em MatrixMultiply.cpp, adicione o `main` seguinte código antes do método.

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

   Este exemplo é significativamente diferente do exemplo sem revestimento. O código usa essas etapas conceituais:
   1. Copie os elementos do ladrilho[0,0] de `a` em `locA`. Copie os elementos do ladrilho[0,0] de `b` em `locB`. Note `product` que é ladrilho, não `a` e `b`. Portanto, você usa índices `a, b`globais `product`para acessar, e . A chamada `tile_barrier::wait` é essencial. Ele pára todos os fios na `locA` telha até que ambos estejam cheios. `locB`

   1. `locA` Multiplique `locB` e coloque `product`os resultados em .

   1. Copie os elementos do ladrilho[0,1] de `a` em `locA`. Copie os elementos do azulejo [1,0] de `b` em `locB`.

   1. `locA` Multiplique `locB` e adicione-os aos resultados `product`que já estão dentro .

   1. A multiplicação de telhas[0,0] está completa.

   1. Repita para as outras quatro telhas. Não há indexação especificamente para as telhas e os segmentos podem ser executados em qualquer ordem. À medida que cada `tile_static` segmento é executado, as variáveis são `tile_barrier::wait` criadas para cada ladrilho adequadamente e a chamada para controlar o fluxo do programa.

   1. Ao examinar o algoritmo de perto, observe que cada `tile_static` submatriz é carregada em uma memória duas vezes. Essa transferência de dados leva tempo. No entanto, uma `tile_static` vez que os dados estão na memória, o acesso aos dados é muito mais rápido. Como o cálculo dos produtos requer acesso repetido aos valores nas submatrizes, há um ganho de desempenho geral. Para cada algoritmo, a experimentação é necessária para encontrar o algoritmo ideal e o tamanho da telha.

   Nos exemplos não-AMP e não-tile, cada elemento de A e B é acessado quatro vezes da memória global para calcular o produto. No exemplo do azulejo, cada elemento é acessado duas `tile_static` vezes da memória global e quatro vezes da memória. Isso não é um ganho significativo de desempenho. No entanto, se as matrizes A e B fossem 1024x1024 e o tamanho da telha fosse de 16, haveria um ganho significativo de desempenho. Nesse caso, cada elemento seria `tile_static` copiado na memória apenas `tile_static` 16 vezes e acessado da memória 1024 vezes.

1. Modifique o método `MultiplyWithTiling` principal para chamar o método, como mostrado.

   ```cpp
   int main() {
       MultiplyWithOutAMP();
       MultiplyWithAMP();
       MultiplyWithTiling();
       getchar();
   }
   ```

1. Pressione o atalho do teclado **Ctrl**+**F5** para iniciar a depuração e verifique se a saída está correta.

1. Pressione a barra **de espaço** para sair do aplicativo.

## <a name="see-also"></a>Confira também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Passo a passo: depurando um aplicativo C++ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)
