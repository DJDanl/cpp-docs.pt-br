---
title: 'Instruções passo a passo: multiplicação de matrizes'
ms.date: 04/23/2019
ms.assetid: 61172e8b-da71-4200-a462-ff3a908ab0cf
ms.openlocfilehash: d45e731cefe51a815424aa941362dce8ceaa4500
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924347"
---
# <a name="walkthrough-matrix-multiplication"></a>Instruções passo a passo: multiplicação de matrizes

Este guia passo a passo demonstra como usar C++ AMP para acelerar a execução da multiplicação de matriz. Dois algoritmos são apresentados, um sem divisão e outro com divisão.

## <a name="prerequisites"></a>Pré-requisitos

Antes de começar:

- Leia [C++ amp Visão geral](../../parallel/amp/cpp-amp-overview.md).

- Leia [usando blocos](../../parallel/amp/using-tiles.md).

- Verifique se você está executando pelo menos o Windows 7 ou o Windows Server 2008 R2.

### <a name="to-create-the-project"></a>Para criar o projeto

As instruções para criar um novo projeto variam de acordo com a versão do Visual Studio instalada. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.

::: moniker range="msvc-160"

### <a name="to-create-the-project-in-visual-studio-2019"></a>Para criar o projeto no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto** .

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Console** .

1. Na lista filtrada de tipos de projeto, escolha **projeto vazio** e, em seguida, escolha **Avançar** . Na página seguinte, digite *MatrixMultiply* na caixa **nome** para especificar um nome para o projeto e especifique o local do projeto, se desejado.

   ![Novo aplicativo de console](../../build/media/mathclient-project-name-2019.png "Novo aplicativo de console")

1. Escolha o botão **Criar** para criar o projeto do cliente.

1. No **Gerenciador de soluções** , abra o menu de atalho para **arquivos de origem** e escolha **Adicionar** > **novo item** .

1. Na caixa de diálogo **Adicionar novo item** , selecione **arquivo C++ (. cpp)** , insira *MatrixMultiply. cpp* na caixa **nome** e, em seguida, escolha o botão **Adicionar** .

::: moniker-end

::: moniker range="<=msvc-150"

### <a name="to-create-a-project-in-visual-studio-2017-or-2015"></a>Para criar um projeto no Visual Studio 2017 ou 2015

1. Na barra de menus no Visual Studio, escolha **arquivo** > **novo** > **projeto** .

1. Em **instalado** no painel modelos, selecione **Visual C++** .

1. Selecione **projeto vazio** , insira *MatrixMultiply* na caixa **nome** e escolha o botão **OK** .

1. Escolha o botão **Avançar** .

1. No **Gerenciador de soluções** , abra o menu de atalho para **arquivos de origem** e escolha **Adicionar** > **novo item** .

1. Na caixa de diálogo **Adicionar novo item** , selecione **arquivo C++ (. cpp)** , insira *MatrixMultiply. cpp* na caixa **nome** e, em seguida, escolha o botão **Adicionar** .

::: moniker-end

## <a name="multiplication-without-tiling"></a>Multiplicação sem divisão

Nesta seção, considere a multiplicação de duas matrizes, A e B, que são definidas da seguinte maneira:

![3&#45;por&#45;matriz A 2](../../parallel/amp/media/campmatrixanontiled.png "3&#45;por&#45;matriz A 2")

![2&#45;pela matriz de&#45;3 B](../../parallel/amp/media/campmatrixbnontiled.png "2&#45;pela matriz de&#45;3 B")

Um é uma matriz 3 por 2 e B é uma matriz 2-por-3. O produto da multiplicação de a por B é a seguinte matriz 3-por-3. O produto é calculado multiplicando as linhas de uma pelas colunas do elemento B por elemento.

![3&#45;pela matriz de produtos&#45;3](../../parallel/amp/media/campmatrixproductnontiled.png "3&#45;pela matriz de produtos&#45;3")

### <a name="to-multiply-without-using-c-amp"></a>Para multiplicar sem usar C++ AMP

1. Abra MatrixMultiply. cpp e use o código a seguir para substituir o código existente.

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

   O algoritmo é uma implementação simples da definição de multiplicação de matriz. Ele não usa nenhum algoritmo paralelo ou threaded para reduzir o tempo de computação.

1. Na barra de menus, escolha **arquivo**  >  **salvar tudo** .

1. Escolha o atalho de teclado **F5** para iniciar a depuração e verificar se a saída está correta.

1. Escolha **Enter** para sair do aplicativo.

### <a name="to-multiply-by-using-c-amp"></a>Para multiplicar usando C++ AMP

1. Em MatrixMultiply. cpp, adicione o código a seguir antes do `main` método.

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

   O código de AMP se assemelha ao código que não é AMP. A chamada para `parallel_for_each` inicia um thread para cada elemento no `product.extent` e substitui os **`for`** loops para linha e coluna. O valor da célula na linha e coluna está disponível em `idx` . Você pode acessar os elementos de um `array_view` objeto usando o `[]` operador e uma variável de índice, ou o `()` operador e as variáveis de linha e coluna. O exemplo demonstra os dois métodos. O `array_view::synchronize` método copia os valores da `product` variável de volta para a `productMatrix` variável.

1. Adicione as `include` instruções e a seguir **`using`** na parte superior de MatrixMultiply. cpp.

   ```cpp
   #include <amp.h>
   using namespace concurrency;
   ```

1. Modifique o `main` método para chamar o `MultiplyWithAMP` método.

   ```cpp
   int main() {
       MultiplyWithOutAMP();
       MultiplyWithAMP();
       getchar();
   }
   ```

1. Pressione o atalho de teclado **Ctrl** + **F5** para iniciar a depuração e verificar se a saída está correta.

1. Pressione a **barra de espaços** para sair do aplicativo.

## <a name="multiplication-with-tiling"></a>Multiplicação por divisão

O agrupamento é uma técnica na qual você particiona dados em subconjuntos de tamanho igual, que são conhecidos como blocos. Três coisas mudam quando você usa o disposição em blocos.

- Você pode criar `tile_static` variáveis. O acesso aos dados no `tile_static` espaço pode ser muitas vezes mais rápido do que o acesso aos dados no espaço global. Uma instância de uma `tile_static` variável é criada para cada bloco e todos os threads no bloco têm acesso à variável. O principal benefício de disposição em blocos é o lucro de desempenho devido ao `tile_static` acesso.

- Você pode chamar o método [tile_barrier:: Wait](reference/tile-barrier-class.md#wait) para interromper todos os threads em um bloco em uma linha de código especificada. Você não pode garantir a ordem em que os threads serão executados, apenas que todos os threads em um bloco serão interrompidos na chamada para `tile_barrier::wait` antes de continuarem a execução.

- Você tem acesso ao índice do thread em relação ao `array_view` objeto inteiro e ao índice relativo ao bloco. Usando o índice local, você pode tornar seu código mais fácil de ler e depurar.

Para aproveitar a divisão na multiplicação de matriz, o algoritmo deve particionar a matriz em blocos e, em seguida, copiar os dados do bloco em `tile_static` variáveis para acesso mais rápido. Neste exemplo, a matriz é particionada em submatrizes de tamanho igual. O produto é encontrado multiplicando-se as submatrizes. As duas matrizes e seus produtos neste exemplo são:

![4&#45;por&#45;matriz A 4](../../parallel/amp/media/campmatrixatiled.png "4&#45;por&#45;matriz A 4")

![4&#45;por&#45;matriz 4](../../parallel/amp/media/campmatrixbtiled.png "4&#45;por&#45;matriz 4")

![4&#45;pela matriz de produtos&#45;4](../../parallel/amp/media/campmatrixproducttiled.png "4&#45;pela matriz de produtos&#45;4")

As matrizes são particionadas em quatro matrizes 2x2, que são definidas da seguinte maneira:

![4&#45;pela matriz&#45;4, particionada em 2&#45;por&#45;duas matrizes de&#45;](../../parallel/amp/media/campmatrixapartitioned.png "4&#45;pela matriz&#45;4, particionada em 2&#45;por&#45;duas matrizes de&#45;")

![4&#45;por&#45;de 4 matriz B particionadas em 2&#45;por matrizes de&#45;&#45;2](../../parallel/amp/media/campmatrixbpartitioned.png "4&#45;por&#45;de 4 matriz B particionadas em 2&#45;por matrizes de&#45;&#45;2")

O produto de A e B agora pode ser escrito e calculado da seguinte maneira:

![4&#45;por&#45;matriz A B particionada em 2&#45;por&#45;duas matrizes de&#45;](../../parallel/amp/media/campmatrixproductpartitioned.png "4&#45;por&#45;matriz A B particionada em 2&#45;por&#45;duas matrizes de&#45;")

Como as matrizes `a` `h` são matrizes 2x2, todos os produtos e as somas delas também são matrizes 2x2. Também segue que o produto de A e B é uma matriz 4x4, conforme esperado. Para verificar rapidamente o algoritmo, calcule o valor do elemento na primeira linha, primeira coluna do produto. No exemplo, esse seria o valor do elemento na primeira linha e primeira coluna de `ae + bg` . Você só precisa calcular a primeira coluna, primeira linha de `ae` e `bg` para cada termo. Esse valor para `ae` é `(1 * 1) + (2 * 5) = 11` . O valor para `bg` é `(3 * 1) + (4 * 5) = 23`. O valor final é `11 + 23 = 34` , que está correto.

Para implementar esse algoritmo, o código:

- Usa um `tiled_extent` objeto em vez de um `extent` objeto na `parallel_for_each` chamada.

- Usa um `tiled_index` objeto em vez de um `index` objeto na `parallel_for_each` chamada.

- Cria `tile_static` variáveis para manter as submatrizes.

- Usa o `tile_barrier::wait` método para interromper os threads para o cálculo dos produtos das submatrizes.

### <a name="to-multiply-by-using-amp-and-tiling"></a>Para multiplicar usando AMP e disposição em blocos

1. Em MatrixMultiply. cpp, adicione o código a seguir antes do `main` método.

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

   Este exemplo é significativamente diferente do exemplo sem divisão. O código usa estas etapas conceituais:
   1. Copie os elementos do bloco [0, 0] de `a` em `locA` . Copie os elementos do bloco [0, 0] de `b` em `locB` . Observe que `product` há um lado do ladrilho, não `a` e `b` . Portanto, você usa índices globais para acessar `a, b` e `product` . A chamada para `tile_barrier::wait` é essencial. Ele interrompe todos os threads no bloco até que ambos `locA` e `locB` sejam preenchidos.

   1. Multiplique `locA` e `locB` Coloque os resultados em `product` .

   1. Copie os elementos do bloco [0, 1] de `a` em `locA` . Copie os elementos do bloco [1, 0] de `b` em `locB` .

   1. Multiplique `locA` e `locB` adicione-os aos resultados que já estão no `product` .

   1. A multiplicação do bloco [0, 0] está concluída.

   1. Repita para os outros quatro blocos. Não há indexação específica para os blocos e os threads podem ser executados em qualquer ordem. À medida que cada thread é executado, as `tile_static` variáveis são criadas para cada bloco adequadamente e a chamada para `tile_barrier::wait` controla o fluxo do programa.

   1. À medida que examina o algoritmo de forma minuciosa, observe que cada submatriz é carregada em uma `tile_static` memória duas vezes. Essa transferência de dados leva tempo. No entanto, uma vez que os dados estão na `tile_static` memória, o acesso aos dados é muito mais rápido. Como o cálculo dos produtos requer acesso repetido aos valores nas submatrizes, há um lucro geral de desempenho. Para cada algoritmo, a experimentação é necessária para localizar o algoritmo ideal e o tamanho do bloco.

   Nos exemplos de não-AMP e não-blocos, cada elemento de A e B é acessado quatro vezes da memória global para calcular o produto. No exemplo de bloco, cada elemento é acessado duas vezes a partir da memória global e quatro vezes da `tile_static` memória. Esse não é um benefício de desempenho significativo. No entanto, se a e B fossem matrizes 1024x1024 e o tamanho do bloco fosse 16, haveria um lucro significativo no desempenho. Nesse caso, cada elemento seria copiado para a `tile_static` memória somente 16 vezes e acessado da `tile_static` memória 1024 vezes.

1. Modifique o método Main para chamar o `MultiplyWithTiling` método, conforme mostrado.

   ```cpp
   int main() {
       MultiplyWithOutAMP();
       MultiplyWithAMP();
       MultiplyWithTiling();
       getchar();
   }
   ```

1. Pressione o atalho de teclado **Ctrl** + **F5** para iniciar a depuração e verificar se a saída está correta.

1. Pressione a barra de **espaço** para sair do aplicativo.

## <a name="see-also"></a>Veja também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Walkthrough: Depurando um aplicativo C++ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)
