---
title: "Passo a passo: Multiplicação de matrizes | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 61172e8b-da71-4200-a462-ff3a908ab0cf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f91bed0b33ae29d7928ec7df3420eb4878b51eef
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-matrix-multiplication"></a>Instruções passo a passo: multiplicação de matrizes
Este passo a passo demonstra como usar C++ AMP para acelerar a execução de multiplicação de matriz. Dois algoritmos são apresentadas sem lado a lado e uma com lado a lado.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Antes de começar:  
  
-   Leitura [visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md).  
  
-   Leitura [usando blocos](../../parallel/amp/using-tiles.md).  
  
-   Verifique se [!INCLUDE[win7](../../build/includes/win7_md.md)], [!INCLUDE[win8](../../build/reference/includes/win8_md.md)], [!INCLUDE[winsvr08_r2](../../parallel/amp/includes/winsvr08_r2_md.md)], ou [!INCLUDE[winserver8](../../build/reference/includes/winserver8_md.md)] está instalado no seu computador.  
  
### <a name="to-create-the-project"></a>Para criar o projeto  
  
1.  Na barra de menus do Visual Studio, escolha **arquivo**, **novo**, **projeto**.  
  
2.  Em **instalado** no painel de modelos, selecione **Visual C++**.  
  
3.  Selecione **projeto vazio**, digite `MatrixMultiply` no **nome** caixa e, em seguida, escolha o **Okey** botão.  
  
4.  Escolha o botão **Avançar**.  
  
5.  Em **Solution Explorer**, abra o menu de atalho para **arquivos de origem**e, em seguida, escolha **adicionar**, **Novo Item**.  
  
6.  No **Adicionar Novo Item** caixa de diálogo, selecione **C++ arquivo (. cpp)**, digite `MatrixMultiply.cpp` no **nome** caixa e, em seguida, escolha o **adicionar** botão.  
  
## <a name="multiplication-without-tiling"></a>Multiplicação sem lado a lado  
 Nesta seção, considere a multiplicação de duas matrizes, A e B, que são definidas da seguinte maneira:  
  
 ![3 &#45; por &#45; 2 matriz](../../parallel/amp/media/campmatrixanontiled.png "campmatrixanontiled")  
  
 ![2 &#45; por &#45; 3 matriz](../../parallel/amp/media/campmatrixbnontiled.png "campmatrixbnontiled")  
  
 Um é uma matriz 3 por 2 e B é uma matriz de 2 por 3. O produto da multiplicação A, B é a matriz de 3 por 3 a seguir. O produto é calculado multiplicando-se as linhas de um pelas colunas de B pelo elemento.  
  
 ![3 &#45; por &#45; 3 matriz](../../parallel/amp/media/campmatrixproductnontiled.png "campmatrixproductnontiled")  
  
### <a name="to-multiply-without-using-c-amp"></a>Multiplicar sem o uso de C++ AMP  
  
1.  Abra MatrixMultiply.cpp e use o código a seguir para substituir o código existente.  
  
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
  
    The algorithm is a straightforward implementation of the definition of matrix multiplication. It does not use any parallel or threaded algorithms to reduce the computation time.  
  
2.  Na barra de menus, escolha **Arquivo**, **Salvar Todos**.  
  
3.  Escolha o atalho de teclado F5 para iniciar a depuração e verificar se a saída está correta.  
  
4.  Escolha Enter para sair do aplicativo.  
  
### <a name="to-multiply-by-using-c-amp"></a>Multiplicar usando C++ AMP  
  
1.  Em MatrixMultiply.cpp, adicione o código a seguir antes do `main` método.  
  
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
  
    The AMP code resembles the non-AMP code. The call to `parallel_for_each` starts one thread for each element in `product.extent`, and replaces the `for` loops for row and column. The value of the cell at the row and column is available in `idx`. You can access the elements of an `array_view` object by using either the `[]` operator and an index variable, or the `()` operator and the row and column variables. The example demonstrates both methods. The `array_view::synchronize` method copies the values of the `product` variable back to the `productMatrix` variable.  
  
2.  Adicione o seguinte `include` e `using` instruções no topo da MatrixMultiply.cpp.  
  
```cpp  
#include <amp.h>  
using namespace concurrency;  
```  
  
3.  Modificar o `main` método para chamar o `MultiplyWithAMP` método.  
  
```cpp  
void main() {  
    MultiplyWithOutAMP();  
    MultiplyWithAMP();  
    getchar();  
}  
```  
  
4.  Escolha o atalho de teclado Ctrl + F5 para iniciar a depuração e verificar se a saída está correta.  
  
5.  Escolha a spacebar para sair do aplicativo.  
  
## <a name="multiplication-with-tiling"></a>Multiplicação com lado a lado  
 Lado a lado é uma técnica em que você dividir os dados em subconjuntos de tamanhos iguais, que são conhecidos como blocos. Três coisas alterar quando você usar lado a lado.  
  
-   Você pode criar `tile_static` variáveis. Acesso a dados em `tile_static` espaço pode ser muitas vezes mais rápido do que o acesso a dados no espaço global. Uma instância de um `tile_static` variável é criada para cada bloco e todos os threads no bloco tem acesso à variável. O principal benefício de lado a lado é o ganho de desempenho devido a `tile_static` acesso.  
  
-   Você pode chamar o [tile_barrier:: wait](reference/tile-barrier-class.md#wait) método para interromper todos os threads em um bloco em uma linha de código especificada. Você não pode garantir a ordem em que os threads serão executados, só que todos os threads em um bloco irá parar na chamada de `tile_barrier::wait` antes de continuar a execução.  

  
-   Você tem acesso ao índice de thread em relação a todo o `array_view` objeto e o índice em relação ao bloco. Usando o índice do local, você pode fazer seu código mais fácil de ler e depurar.  
  
 Para tirar proveito das lado a lado de multiplicação de matriz, o algoritmo deve dividir a matriz em peças e, em seguida, copie os dados de bloco em `tile_static` variáveis para acesso mais rápido. Neste exemplo, a matriz é particionada em submatrices de tamanhos iguais. O produto é encontrado, multiplicando os submatrices. As duas matrizes e seus produtos neste exemplo são:  
  
 ![4 &#45; por &#45; 4 matriz](../../parallel/amp/media/campmatrixatiled.png "campmatrixatiled")  
  
 ![4 &#45; por &#45; 4 matriz](../../parallel/amp/media/campmatrixbtiled.png "campmatrixbtiled")  
  
 ![4 &#45; por &#45; 4 matriz](../../parallel/amp/media/campmatrixproducttiled.png "campmatrixproducttiled")  
  
 As matrizes são particionadas em matrizes de quatro 2 x 2, que são definidas da seguinte maneira:  
  
 ![4 &#45; por &#45; 4 matriz particionados em 2 &#45; &#45; sub 2 &#45; matrizes](../../parallel/amp/media/campmatrixapartitioned.png "campmatrixapartitioned")  
  
 ![4 &#45; por &#45; 4 matriz particionados em 2 &#45; &#45; sub 2 &#45; matrizes](../../parallel/amp/media/campmatrixbpartitioned.png "campmatrixbpartitioned")  
  
 O produto de A e B agora pode ser gravado e calculada da seguinte maneira:  
  
 ![4 &#45; por &#45; 4 matriz particionados em 2 &#45; &#45; sub 2 &#45; matrizes](../../parallel/amp/media/campmatrixproductpartitioned.png "campmatrixproductpartitioned")  
  
 Como matrizes `a` por meio de `h` são matrizes de 2 x 2, todos os produtos e somas, eles também são matrizes de 2 x 2. Ele também segue A * B é uma matriz 4 x 4, conforme o esperado. Para verificar rapidamente o algoritmo, calcule o valor do elemento na primeira linha, primeira coluna no produto. No exemplo, que poderia ser o valor do elemento na primeira linha e primeira coluna da `ae + bg`. Você só precisa calcular a primeira coluna, a primeira linha de `ae` e `bg` para cada termo. Esse valor para `ae` é `1*1 + 2*5 = 11`. O valor de `bg` é `3*1 + 4*5 = 23`. O valor final é `11 + 23 = 34`, que está correto.  
  
 Para implementar esse algoritmo, o código:  
  
-   Usa um `tiled_extent` do objeto, em vez de um `extent` objeto o `parallel_for_each` chamar.  
  
-   Usa um `tiled_index` do objeto, em vez de um `index` objeto o `parallel_for_each` chamar.  
  
-   Cria `tile_static` variáveis para manter os submatrices.  
  
-   Usa o `tile_barrier::wait` método para interromper os segmentos para o cálculo dos produtos das submatrices.  
  
### <a name="to-multiply-by-using-amp-and-tiling"></a>Multiplicar usando AMP e lado a lado  
  
1.  Em MatrixMultiply.cpp, adicione o código a seguir antes do `main` método.  
  
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
  
    1.  Copiar os elementos de bloco [0,0] de `a` em `locA`. Copiar os elementos de bloco [0,0] de `b` em `locB`. Observe que `product` é colocada lado a lado não `a` e `b`. Portanto, você usa índices global para acessar `a, b`, e `product`. A chamada para `tile_barrier::wait` é essencial. Ele interrompe todos os segmentos no bloco até que as `locA` e `locB` são preenchidas.  
  
    2.  Multiplique `locA` e `locB` e colocar os resultados em `product`.  
  
    3.  Copiar os elementos de bloco [0,1] de `a` em `locA`. Copiar os elementos de bloco [1.0] de `b` em `locB`.  
  
    4.  Multiplique `locA` e `locB` e adicioná-los para os resultados que já estão no `product`.  
  
    5.  A multiplicação de bloco [0,0] foi concluída.  
  
    6.  Repita para os quatro blocos. Não há nenhuma indexação especificamente para os blocos e os threads podem executar em qualquer ordem. Como cada thread é executado, o `tile_static` variáveis são criadas para cada peça adequadamente e a chamada para `tile_barrier::wait` controla o fluxo de programa.  
  
    7.  Conforme você examina atentamente o algoritmo, observe que cada submatrix é carregado em um `tile_static` memória duas vezes. Essa transferência de dados leva tempo. No entanto, quando os dados estão em `tile_static` memória, o acesso aos dados é muito mais rápido. Como calcular os produtos requer acesso repetido para os valores de submatrices, há um ganho de desempenho geral. Para cada algoritmo experimentação é necessária para localizar o algoritmo ideal e o tamanho de bloco.  
  
         Nos exemplos a AMP não e não do bloco, cada elemento da e B é acessado quatro vezes da memória global para calcular o produto. O exemplo de bloco, cada elemento é acessado dobro de memória global em quatro vezes o `tile_static` memória. Não é um ganho de desempenho significativa. No entanto, se a e B foram 1024 x 1024 matrizes e o tamanho de bloco foram 16, haveria um ganho de desempenho significativa. Nesse caso, cada elemento deve ser copiado para `tile_static` memória somente 16 vezes e acessadas de `tile_static` memória 1024 vezes.  
  
2.  Modifique o método principal para chamar o `MultiplyWithTiling` método, conforme mostrado.  
  
```cpp  
void main() {  
    MultiplyWithOutAMP();  
    MultiplyWithAMP();  
    MultiplyWithTiling();  
    getchar();  
}  
```  
  
3.  Escolha o atalho de teclado Ctrl + F5 para iniciar a depuração e verificar se a saída está correta.  
  
4.  Escolha a barra de espaços para sair do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)   
 [Passo a passo: depurando um aplicativo C++ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)

