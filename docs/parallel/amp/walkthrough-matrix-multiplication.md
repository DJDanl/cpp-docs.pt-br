---
title: "Instru&#231;&#245;es passo a passo: multiplica&#231;&#227;o de matrizes | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 61172e8b-da71-4200-a462-ff3a908ab0cf
caps.latest.revision: 16
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: multiplica&#231;&#227;o de matrizes
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta explicação passo a passo demonstra como usar o C\+\+ AMP para acelerar a execução de uma multiplicação de matriz.  Dois algoritmos são apresentados, um sem disposição lado a lado, e um com disposição lado a lado.  
  
## Pré-requisitos  
 Antes de iniciar:  
  
-   Leia [Visão geral do C\+\+ AMP](../../parallel/amp/cpp-amp-overview.md).  
  
-   Leia [Usando blocos](../../parallel/amp/using-tiles.md).  
  
-   Certifique\-se de que [!INCLUDE[win7](../../build/includes/win7_md.md)], [!INCLUDE[win8](../../build/includes/win8_md.md)], [!INCLUDE[winsvr08_r2](../Token/winsvr08_r2_md.md)], ou [!INCLUDE[winserver8](../../build/includes/winserver8_md.md)] está instalado no seu computador.  
  
### Para criar o projeto  
  
1.  Na barra de menus do Visual Studio, escolha **Arquivo**, **Novo**, **Projeto**.  
  
2.  Em baixo de **Instalados** no painel de modelos, selecione **Visual C\+\+**.  
  
3.  Selecione **Projeto Vazio**, digite `MatrixMultiply` na caixa de **Nome**, e escolha o botão **OK**.  
  
4.  Escolha o botão **Próximo**.  
  
5.  No **Explorador de Soluções**, abra o menu de atalho para **Arquivos Fontes**, e escolha **Adicionar**, **Novo Item**.  
  
6.  Na caixa de diálogo **Adicionar Novo Item** selecione **Arquivo C\+\+ \(. cpp\)**, digite `MatrixMultiply.cpp` na caixa **Nome** e escolha o botão **Adicionar**.  
  
## Multiplicação sem disposição lado a lado  
 Nesta seção, considere a multiplicação de duas matrizes, A e B, que estão definidas como segue:  
  
 ![Uma matriz 3 x 2](../../parallel/amp/media/campmatrixanontiled.png "CampMatrixANonTiled")  
  
 ![Uma 3 x 2 matriz](../Image/CampMatrixBNonTiled.PNG "CampMatrixBNonTiled")  
  
 A é uma matriz 3 por 2 e B é uma matriz 2 por 3.  O produto da multiplicação de A por B é a seguinte matriz 3 por 3.  O produto é calculado multiplicando\-se as linhas de A pelas colunas de B elemento por elemento.  
  
 ![Uma matriz 3 x 3](../../parallel/amp/media/campmatrixproductnontiled.png "CampMatrixProductNonTiled")  
  
### Para multiplicar sem usar C\+\+ AMP  
  
1.  Abra MatrixMultiply.cpp e use o seguinte código para substituir o código existente.  
  
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
  
     O algoritmo é uma implementação simples da definição de multiplicação de matriz.  Ele não usa nenhum algoritmo paralelo ou encadeado para reduzir o tempo de computação.  
  
2.  Na barra de menus, escolha **Arquivo**, **Salvar Tudo**.  
  
3.  Pressione o atalho de teclado F5 para iniciar depuração e verifique que a saída está correta.  
  
4.  Pressione Enter para sair do aplicativo.  
  
### Para multiplicar usando C\+\+ AMP  
  
1.  No MatrixMultiply.cpp, adicione o seguinte código antes do método `main`.  
  
    ```cpp  
  
    void MultiplyWithAMP() {  
        int aMatrix[] = { 1, 4, 2, 5, 3, 6 };  
        int bMatrix[] = { 7, 8, 9, 10, 11, 12 };  
        int productMatrix[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };  
  
        array_view<int, 2> a(3, 2, aMatrix);  
        array_view<int, 2> b(2, 3, bMatrix);  
        array_view<int, 2> product(3, 3, productMatrix);  
  
        parallel_for_each(  
            product.extent,   
             [=](index<2> idx) restrict(amp) {  
                int row = idx[0];  
                int col = idx[1];  
                for (int inner = 0; inner < 2; inner++) {  
                    product[idx] += a(row, inner) * b(inner, col);  
                }  
            }  
        );  
  
        product.synchronize();  
  
        for (int row = 0; row < 3; row++) {  
            for (int col = 0; col < 3; col++) {  
                //std::cout << productMatrix[row*3 + col] << "  ";  
                std::cout << product(row, col) << "  ";  
            }  
            std::cout << "\n";  
        }  
    }  
  
    ```  
  
     O código AMP assemelha\-se ao código não\-AMP.  A chamada para o `parallel_for_each` inicia um thread para cada elemento no `product.extent`e substitui o laço `for` por linha e coluna.  O valor da célula na linha e coluna está disponível em `idx`.  Você pode acessar os elementos de um objeto `array_view` usando o operador `[]` e uma variável de índice, ou o operador `()` e as variáveis de linha e coluna.  O exemplo demonstra ambos os métodos.  O método `array_view::synchronize` copia os valores da variável `product` de volta para a variável `productMatrix`.  
  
2.  Adicione as instruções seguintes na parte superior do MatrixMultiply.cpp: `include` e `using`.  
  
    ```cpp  
  
    #include <amp.h>  
    using namespace concurrency;  
  
    ```  
  
3.  Modifique o método `main` para chamar o método `MultiplyWithAMP`.  
  
    ```cpp  
  
    void main() {  
        MultiplyWithOutAMP();  
        MultiplyWithAMP();  
        getchar();  
    }  
  
    ```  
  
4.  Pressione o atalho de teclado Ctrl \+ F5 para iniciar a depuração e verifique que a saída está correta.  
  
5.  Pressione a barra de espaços para sair do aplicativo.  
  
## Multiplicação com disposição lado a lado  
 Disposição Lado a lado \(tiling\) é uma técnica na qual você particiona dados em subconjuntos de tamanho igual, que são conhecidos como tiles.  Três coisas mudam quando você usa a disposição lado a lado.  
  
-   Você pode criar variáveis `tile_static`.  Acesso a dados no espaço `tile_static` pode ser muitas vezes mais rápido do que o acesso a dados no espaço global.  Uma instância de uma variável `tile_static` é criada para cada tile, e todos os threads no tile tem acesso à variável.  O principal benefício da disposição lado a lado é o ganho de desempenho devido ao acesso `tile_static`.  
  
-   Você pode chamar o método [tile\_barrier::wait](../Topic/tile_barrier::wait%20Method.md) para interromper todos os threads em um tile em uma linha específica do código.  Você não pode garantir a ordem em que os threads serão executados, só que todos os threads em um tile irão parar na chamada para o `tile_barrier::wait` antes de continuar a execução.  
  
-   Você tem acesso ao índice do thread relativo a todo o objeto `array_view` e o índice relativo ao tile.  Usando o índice local, você pode tornar seu código mais fácil de ler e depurar.  
  
 Para tirar vantagem da disposição lado a lado na multiplicação de matriz, o algoritmo deve particionar a matriz em tiles e copiar os dados tile nas variáveis `tile_static` para acesso mais rápido.  Neste exemplo, a matriz é particionada em submatrizes de tamanho igual.  O produto é encontrado multiplicando as submatrizes.  As duas matrizes e seus produtos neste exemplo são:  
  
 ![Uma matriz de 4 x 4](../../parallel/amp/media/campmatrixatiled.png "CampMatrixATiled")  
  
 ![Uma matriz de 4 x 4](../../parallel/amp/media/campmatrixbtiled.png "CampMatrixBTiled")  
  
 ![Uma matriz de 4 x 4](../../parallel/amp/media/campmatrixproducttiled.png "CampMatrixProductTiled")  
  
 As matrizes são particionadas em quatro matrizes 2x2, que são definidas da seguinte maneira:  
  
 ![Uma matriz de 4 x 4 particionada em 2 x 2 submatrices](../../parallel/amp/media/campmatrixapartitioned.png "CampMatrixAPartitioned")  
  
 ![Uma matriz de 4 x 4 particionada em 2 x 2 submatrices](../../parallel/amp/media/campmatrixbpartitioned.png "CampMatrixBPartitioned")  
  
 O produto de A e B agora pode ser escrito e calculado da seguinte forma:  
  
 ![Uma matriz de 4 x 4 particionada em 2 x 2 submatrices](../../parallel/amp/media/campmatrixproductpartitioned.png "CampMatrixProductPartitioned")  
  
 Porque as matrizes `a` a `h` são matrizes 2x2, todos os produtos e somas delas também são matrizes 2x2.  Também segue que A\*B é uma matriz 4 x 4, conforme o esperado.  Para verificar rapidamente o algoritmo, calcule o valor do elemento da primeira linha e primeira coluna no produto.  No exemplo, aquele seria o valor do elemento da primeira linha e primeira coluna de `ae + bg`.  Você só precisa calcular a primeira coluna, a primeira linha de `ae` e `bg` para cada termo.  O valor para `ae` é `1*1 + 2*5 = 11`.  O valor para `bg` é `3*1 + 4*5 = 23`.  O valor final é `11 + 23 = 34`, que está correto.  
  
 Para implementar esse algoritmo, o código:  
  
-   Usa um objeto `tiled_extent` em vez de um objeto `extent` na chamada `parallel_for_each`.  
  
-   Usa um objeto `tiled_index` em vez de um objeto `index` na chamada `parallel_for_each`.  
  
-   Cria variáveis `tile_static` para armazenar as submatrizes.  
  
-   Usa o método `tile_barrier::wait` para parar os threads para o cálculo dos produtos das submatrizes.  
  
### Para multiplicar usando AMP e disposição lado a lado  
  
1.  No MatrixMultiply.cpp, adicione o seguinte código antes do método `main`.  
  
    ```cpp  
  
    void MultiplyWithTiling()  
    {  
        // The tile size is 2.  
        static const int TS = 2;  
  
        // The raw data.  
        int aMatrix[] =       { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 };  
        int bMatrix[] =       { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 };  
        int productMatrix[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };  
  
        // Create the array_view objects.  
        array_view<int, 2> a(4, 4, aMatrix);  
        array_view<int, 2> b(4, 4, bMatrix);  
        array_view<int, 2> product(4, 4, productMatrix);  
  
        // Call parallel_for_each by using  2x2 tiles.  
        parallel_for_each(product.extent.tile< TS, TS >(),  
            [=] (tiled_index< TS, TS> t_idx) restrict(amp)   
            {  
                // Get the location of the thread relative to the tile (row, col) and the entire array_view (rowGlobal, colGlobal).  
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
  
            for (int row = 0; row < 4; row++) {  
            for (int col = 0; col < 4; col++) {  
                // The results are available from both the product and productMatrix variables.  
                //std::cout << productMatrix[row*3 + col] << "  ";  
                std::cout << product(row, col) << "  ";  
            }  
            std::cout << "\n";  
        }  
  
    }  
  
    ```  
  
     Este exemplo é significativamente diferente do exemplo sem a disposição lado a lado.  O código usa estas etapas conceituais:  
  
    1.  Copiar os elementos do tile \[0,0\] do `a` em `locA`.  Copiar os elementos do tile \[0,0\] do `b` em `locB`.  Observe que `product` está disposto lado a lado, e não `a` e `b`.  Portanto, você usa índices globais para acessar `a, b`, e `product`.  A chamada para `tile_barrier::wait` é essencial.  Ele bloqueia todos os threads no tile até ambos `locA` e `locB` estarem preenchidos.  
  
    2.  Multiplicar `locA` e `locB` e colocar os resultados em `product`.  
  
    3.  Copiar os elementos do tile \[0,1\] do `a` em `locA`.  Copiar os elementos do tile \[1,0\] do `b` em `locB`.  
  
    4.  Multiplicar `locA` e `locB` e adicioná\-los para os resultados que já estão em `product`.  
  
    5.  A multiplicação de tile \[0,0\] está completa.  
  
    6.  Repita para os outros quatro tiles.  Não há nenhuma indexação específica para os tiles e os threads podem executar em qualquer ordem.  A medida que cada thread executa, as variáveis `tile_static` são criadas para cada tile apropriadamente e a chamada para `tile_barrier::wait` controla o fluxo do programa.  
  
    7.  A medida que você examina atentamente o algoritmo, observe que cada submatriz é carregada em uma memória `tile_static` duas vezes.  Esta transferência de dados leva tempo.  No entanto, uma vez que o dado está na memória `tile_static`, o acesso ao dado é muito mais rápido.  Como calcular os produtos requer acesso repetido para valores nas submatrizes, há um ganho de desempenho geral.  Para cada algoritmo, é necessário experimentação para localizar o algoritmo e tamanho do tile mais adequados.  
  
         Nos exemplos de não\-AMP e não\-tile, cada elemento de A e B é acessado quatro vezes da memória global para calcular o produto.  No exemplo do tile, cada elemento é acessado duas vezes da memória global e quatro vezes da memória `tile_static`.  Isso não é um ganho de desempenho significativo.  No entanto, se A e B fossem matrizes 1024x1024 e o tamanho do tile fosse 16, o ganho de desempenho seria significativo.  Nesse caso, cada elemento seria copiado para a memória `tile_static` somente 16 vezes e acessados a partir da memória `tile_static` 1024 vezes.  
  
2.  Modifique o método principal para chamar o método `MultiplyWithTiling` , como mostrado.  
  
    ```cpp  
  
    void main() {  
        MultiplyWithOutAMP();  
        MultiplyWithAMP();  
        MultiplyWithTiling();  
        getchar();  
    }  
  
    ```  
  
3.  Pressione o atalho de teclado Ctrl \+ F5 para iniciar a depuração e verifique que a saída está correta.  
  
4.  Pressione a barra de espaço para sair do aplicativo.  
  
## Consulte também  
 [C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)   
 [Instruções passo a passo: depurando um aplicativo C\+\+ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)