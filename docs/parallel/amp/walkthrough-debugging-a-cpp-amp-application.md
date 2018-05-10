---
title: 'Passo a passo: Depurando um aplicativo C++ AMP | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- debugging, C++ Accelerated Massive Parallelism
- C++ AMP, debugging
- C++ Accelerated Massive Parallelism, debugging
- debugging, C++ AMP
ms.assetid: 40e92ecc-f6ba-411c-960c-b3047b854fb5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2f1308462133c11c8f945416a13fb5542c1d2da8
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="walkthrough-debugging-a-c-amp-application"></a>Instruções passo a passo: depurando um aplicativo C++ AMP
Este tópico demonstra como depurar um aplicativo que usa C++ Accelerated Massive Parallelism (C++ AMP) para tirar proveito da unidade de processamento de gráficos (GPU). Ele usa um programa de redução de paralelo resume uma grande variedade de números inteiros. Esta explicação passo a passo ilustra as seguintes tarefas:  
  
-   Iniciando o depurador GPU.  
  
-   Inspecionar threads GPU na janela de Threads de GPU.  
  
-   Usando a janela pilhas paralelas para observar simultaneamente as pilhas de chamadas de vários threads GPU.  
  
-   Usando a janela Inspeção paralela para inspecionar os valores de uma única expressão por vários threads ao mesmo tempo.  
  
-   Sinalizar, congelar, descongelar e agrupamento de threads de GPU.  
  
-   Executar todos os threads de um bloco em um local específico no código.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Antes de começar este passo a passo:  
  
-   Leitura [visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md).  
  
-   Verifique se essa linha números são exibidos no editor de texto. Para obter mais informações, consulte [como: exibir números de linha no Editor de](/visualstudio/ide/reference/how-to-display-line-numbers-in-the-editor).  
  
-   Verifique se você estiver executando [!INCLUDE[win8](../../build/reference/includes/win8_md.md)] ou [!INCLUDE[winserver8](../../build/reference/includes/winserver8_md.md)] para oferecer suporte à depuração no emulador do software.  
  
 [!INCLUDE[note_settings_general](../../mfc/includes/note_settings_general_md.md)]  
  
### <a name="to-create-the-sample-project"></a>Para criar o projeto de exemplo  
  
1.  Inicie o Visual Studio.  
  
2.  Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.  
  
3.  Em **instalado** no painel modelos, escolha **Visual C++**.  
  
4.  Escolha **aplicativo do Console Win32**, tipo `AMPMapReduce` no **nome** caixa e, em seguida, escolha o **Okey** botão.  
  
5.  Escolha o botão **Avançar**.  
  
6.  Limpar o **cabeçalho pré-compilado** caixa de seleção e, em seguida, escolha o **concluir** botão.  
  
7.  Em **Solution Explorer**, excluir Stdafx. h, targetver.h e stdafx.cpp do projeto.  
  
8.  Abra AMPMapReduce.cpp e substitua o seu conteúdo com o código a seguir.  
  
 ```cpp  
    // AMPMapReduce.cpp defines the entry point for the program.  
    // The program performs a parallel-sum reduction that computes the sum of an array of integers.   
  
    #include <stdio.h>  
    #include <tchar.h>  
    #include <amp.h>  
  
    const int BLOCK_DIM = 32;  
  
    using namespace concurrency;  
  
    void sum_kernel_tiled(tiled_index<BLOCK_DIM> t_idx, array<int, 1> &A, int stride_size) restrict(amp)  
    {  
        tile_static int localA[BLOCK_DIM];  
  
        index<1> globalIdx = t_idx.global * stride_size;  
        index<1> localIdx = t_idx.local;  
  
        localA[localIdx[0]] =  A[globalIdx];  
  
        t_idx.barrier.wait();  
  
        // Aggregate all elements in one tile into the first element.  
        for (int i = BLOCK_DIM / 2; i > 0; i /= 2)   
        {  
            if (localIdx[0] < i)   
            {  
  
                localA[localIdx[0]] += localA[localIdx[0] + i];  
            }  
  
            t_idx.barrier.wait();  
        }  
  
        if (localIdx[0] == 0)  
        {  
            A[globalIdx] = localA[0];  
        }  
    }  
  
    int size_after_padding(int n)  
    {  
        // The extent might have to be slightly bigger than num_stride to   
        // be evenly divisible by BLOCK_DIM. You can do this by padding with zeros.  
        // The calculation to do this is BLOCK_DIM * ceil(n / BLOCK_DIM)  
        return ((n - 1) / BLOCK_DIM + 1) * BLOCK_DIM;  
    }  
  
    int reduction_sum_gpu_kernel(array<int, 1> input)   
    {  
        int len = input.extent[0];  
  
        //Tree-based reduction control that uses the CPU.  
        for (int stride_size = 1; stride_size < len; stride_size *= BLOCK_DIM)   
        {  
            // Number of useful values in the array, given the current  
            // stride size.  
            int num_strides = len / stride_size;    
  
            extent<1> e(size_after_padding(num_strides));  
  
            // The sum kernel that uses the GPU.  
            parallel_for_each(extent<1>(e).tile<BLOCK_DIM>(), [&input, stride_size] (tiled_index<BLOCK_DIM> idx) restrict(amp)  
            {  
                sum_kernel_tiled(idx, input, stride_size);  
            });  
        }  
  
        array_view<int, 1> output = input.section(extent<1>(1));  
        return output[0];  
    }  
  
    int cpu_sum(const std::vector<int> &arr) {  
        int sum = 0;  
        for (size_t i = 0; i < arr.size(); i++) {  
            sum += arr[i];  
        }  
        return sum;  
    }  
  
    std::vector<int> rand_vector(unsigned int size) {  
        srand(2011);  
  
        std::vector<int> vec(size);  
        for (size_t i = 0; i < size; i++) {  
            vec[i] = rand();  
        }  
        return vec;  
    }  
  
    array<int, 1> vector_to_array(const std::vector<int> &vec) {  
        array<int, 1> arr(vec.size());  
        copy(vec.begin(), vec.end(), arr);  
        return arr;  
    }  
  
    int _tmain(int argc, _TCHAR* argv[])  
    {  
        std::vector<int> vec = rand_vector(10000);  
        array<int, 1> arr = vector_to_array(vec);  
  
        int expected = cpu_sum(vec);  
        int actual = reduction_sum_gpu_kernel(arr);  
  
        bool passed = (expected == actual);  
        if (!passed) {  
            printf("Actual (GPU): %d, Expected (CPU): %d", actual, expected);  
        }  
        printf("sum: %s\n", passed  "Passed!" : "Failed!");   
  
        getchar();  
  
        return 0;  
    }  
  
 ```  
  
9. Na barra de menus, escolha **Arquivo**, **Salvar Todos**.  
  
10. Em **Solution Explorer**, abra o menu de atalho para **AMPMapReduce**e, em seguida, escolha **propriedades**.  
  
11. No **páginas de propriedade** caixa de diálogo **propriedades de configuração**, escolha **C/C++**, **cabeçalhos pré-compilados**.  
  
12. Para o **cabeçalho pré-compilado** propriedade, selecione **não usar cabeçalhos pré-compilados**e, em seguida, escolha o **Okey** botão.  
  
13. Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
## <a name="debugging-the-cpu-code"></a>Depurar o código de CPU  
 Neste procedimento, você usará o depurador do Windows Local para certificar-se de que o código de CPU deste aplicativo está correto. O segmento do código da CPU neste aplicativo que é especialmente interessante é a `for` loop no `reduction_sum_gpu_kernel` função. Ele controla a redução de paralela baseada em árvore que é executada na GPU.  
  
### <a name="to-debug-the-cpu-code"></a>Para depurar o código de CPU  
  
1.  Em **Solution Explorer**, abra o menu de atalho para **AMPMapReduce**e, em seguida, escolha **propriedades**.  
  
2.  No **páginas de propriedade** caixa de diálogo **propriedades de configuração**, escolha **depuração**. Verifique **depurador Local do Windows** está selecionado no **depurador a iniciar** lista.  
  
3.  Retornar ao Editor de código.  
  
4.  Definir pontos de interrupção nas linhas de código mostrado na ilustração a seguir (aproximadamente linhas 67 linha 70).  
  
     ![Pontos de interrupção de CPU](../../parallel/amp/media/campcpubreakpoints.png "campcpubreakpoints")  
Pontos de interrupção de CPU  
  
5.  Na barra de menus, escolha **Depurar**, **Iniciar Depuração**.  
  
6.  No **locais** janela, observe o valor para `stride_size` até atingir o ponto de interrupção na linha 70.  
  
7.  Na barra de menus, escolha **Depurar**, **Parar Depuração**.  
  
## <a name="debugging-the-gpu-code"></a>Depurar o código GPU  
 Esta seção mostra como depurar o código GPU, que é o código contido no `sum_kernel_tiled` função. O código GPU calcula a soma de números inteiros para cada bloco de"" em paralelo.  
  
### <a name="to-debug-the-gpu-code"></a>Para depurar o código GPU  
  
1.  Em **Solution Explorer**, abra o menu de atalho para **AMPMapReduce**e, em seguida, escolha **propriedades**.  
  
2.  No **páginas de propriedade** caixa de diálogo **propriedades de configuração**, escolha **depuração**.  
  
3.  No **depurador a iniciar** lista, selecione **depurador Local do Windows**.  
  
4.  No **tipo de depurador** lista, selecione **somente GPU**.  
  
5.  Escolha o botão **OK**.  
  
6.  Defina um ponto de interrupção na linha 30, conforme mostrado na ilustração a seguir.  
  
     ![Pontos de interrupção GPU](../../parallel/amp/media/campgpubreakpoints.png "campgpubreakpoints")  
Ponto de interrupção GPU  
  
7.  Na barra de menus, escolha **Depurar**, **Iniciar Depuração**. Os pontos de interrupção no código da CPU em linhas 67 e 70 não são executados durante a depuração porque as linhas de código são executadas na CPU GPU.  
  
### <a name="to-use-the-gpu-threads-window"></a>Para usar a janela Threads de GPU  
  
1.  Para abrir a janela de Threads de GPU, na barra de menus, escolha **depurar**, **Windows**, **Threads de GPU**.  
  
     Você pode inspecionar o estado de threads GPU na janela de Threads de GPU que aparece.  
  
2.  Encaixe a janela de Threads de GPU na parte inferior do Visual Studio. Escolha o **expanda Thread comutador** botão para exibir as caixas de texto de bloco e segmento. A janela Threads de GPU mostra o número total de threads GPU ativo e bloqueado, conforme mostrado na ilustração a seguir.  
  
     ![Janela Threads de GPU com 4 threads ativos](../../parallel/amp/media/campc.png "campc")  
Janela Threads de GPU  
  
     Não há 313 blocos alocados para essa computação. Cada bloco contém 32 segmentos. Como a depuração da GPU local ocorre em um emulador de software, há quatro threads GPU ativos. Quatro threads executam as instruções simultaneamente e, em seguida, passar juntos para a próxima instrução.  
  
     Na janela de threads de GPU, há quatro threads GPU ativos e 28 threads GPU bloqueada no [tile_barrier:: wait](reference/tile-barrier-class.md#wait) instrução definida no sobre linha 21 (`t_idx.barrier.wait();`). Todos os threads GPU 32 pertencem ao primeiro bloco, `tile[0]`. Uma seta aponta para a linha que inclui o thread atual. Para alternar para um thread diferente, use um dos seguintes métodos:  

  
    -   Na linha para o thread alternar para na janela de Threads de GPU, abra o menu de atalho e escolha **alternar para Thread**. Se a linha representa mais de um segmento, você alternará para o primeiro thread de acordo com as coordenadas de thread.  
  
    -   Insira os valores de bloco e segmento do thread nas caixas de texto correspondente e, em seguida, escolha o **Switch Thread** botão.  
  
     Janela pilha de chamadas exibe a pilha de chamadas do thread atual da GPU.  
  
### <a name="to-use-the-parallel-stacks-window"></a>Para usar a janela pilhas paralelas  
  
1.  Para abrir a janela pilhas paralelas, na barra de menus, escolha **depurar**, **Windows**, **pilhas paralelas**.  
  
     Você pode usar a janela pilhas paralelas para inspecionar simultaneamente os quadros de pilha de vários threads GPU.  
  
2.  Encaixe a janela pilhas paralelas na parte inferior do Visual Studio.  
  
3.  Verifique se **Threads** está selecionado na lista no canto superior esquerdo. Na ilustração a seguir, a janela pilhas paralelas mostra uma exibição de foco na pilha de chamadas de threads de GPU que você viu na janela de Threads de GPU.  
  
     ![Janela pilhas paralelas com 4 threads ativos](../../parallel/amp/media/campd.png "campd")  
Janela pilhas paralelas  
  
     32 encadeamentos passaram do `_kernel_stub` para a instrução lambda a `parallel_for_each` chamada de função e, em seguida, para o `sum_kernel_tiled` função, onde ocorre a redução em paralela. 28 de 32 encadeamentos ter progrediu para o [tile_barrier:: wait](reference/tile-barrier-class.md#wait) instrução e permanecer bloqueados na linha 22, enquanto outros 4 threads permanecem ativos no `sum_kernel_tiled` função na linha 30.  

  
     Você pode inspecionar as propriedades de um thread GPU que estão disponíveis na janela de Threads de GPU no DataTip Avançado da janela pilhas paralelas. Para fazer isso, o ponteiro do mouse no quadro de pilha **sum_kernel_tiled**. A ilustração a seguir mostra o DataTip.  
  
     ![DataTip para janela pilhas paralelas](../../parallel/amp/media/campe.png "campe")  
Thread GPU DataTip  
  
     Para obter mais informações sobre a janela pilhas paralelas, consulte [usando a janela pilhas paralelas](/visualstudio/debugger/using-the-parallel-stacks-window).  
  
### <a name="to-use-the-parallel-watch-window"></a>Para usar a janela Inspeção paralela  
  
1.  Para abrir a janela Inspeção paralela, na barra de menus, escolha **depurar**, **Windows**, **inspeção paralela**, **paralela inspecionar 1**.  
  
     Você pode usar a janela Inspeção paralela para inspecionar os valores de uma expressão entre vários threads.  
  
2.  Encaixe a janela de paralelo inspecionar 1 até a parte inferior do Visual Studio. Há 32 linhas na tabela da janela Inspeção paralela. Cada corresponde a um thread GPU foi exibido na janela de Threads da GPU e a janela pilhas paralelas. Agora, você pode inserir expressões cujos valores você deseja inspecionar entre todos os threads GPU 32.  
  
3.  Selecione o **Adicionar inspeção** cabeçalho de coluna, digite `localIdx`e, em seguida, escolha a tecla Enter.  
  
4.  Selecione o **Adicionar inspeção** cabeçalho da coluna novamente, digite `globalIdx`e, em seguida, escolha a tecla Enter.  
  
5.  Selecione o **Adicionar inspeção** cabeçalho da coluna novamente, digite `localA[localIdx[0]]`e, em seguida, escolha a tecla Enter.  
  
     Você pode classificar por uma expressão especificada, selecionando o título de coluna correspondente.  
  
     Selecione o **localA [localIdx [0]]** cabeçalho de coluna para classificar a coluna. A ilustração a seguir mostra os resultados da classificação por **localA [localIdx [0]]**.  
  
     ![Janela de inspeção paralela com resultados classificados](../../parallel/amp/media/campf.png "campf")  
 Resultados da classificação  
  
     Você pode exportar o conteúdo na janela Inspeção paralela para o Excel escolhendo o botão do Excel e, em seguida, **abrir no Excel**. Se você tiver o Excel instalado em seu computador de desenvolvimento, isso abre uma planilha do Excel que contém o conteúdo.  
  
6.  No canto superior direito da janela Inspeção paralela, há um controle de filtro que você pode usar para filtrar o conteúdo por meio de expressões Boolianas. Insira `localA[localIdx[0]] > 20000` no texto do controle de filtro caixa e, em seguida, escolha a tecla Enter.  
  
     A janela agora contém apenas os threads nos quais o `localA[localIdx[0]]` valor é maior que 20000. O conteúdo ainda é classificado pelo `localA[localIdx[0]]` coluna, que é a ação de classificação executado anteriormente.  
  
## <a name="flagging-gpu-threads"></a>Sinalizar Threads de GPU  
 Você pode marcar os threads GPU específicos sinalizando-los na janela Threads de GPU, a janela Inspeção paralela ou DataTip na janela pilhas paralelas. Se uma linha na janela de Threads de GPU contém mais de um thread, sinalizar que a linha sinaliza todos os threads que estão contidos na linha.  
  
### <a name="to-flag-gpu-threads"></a>Para sinalizar threads de GPU  
  
1.  Selecione o **[Thread]** cabeçalho de coluna na janela Inspecionar 1 paralelo para classificar por índice de bloco e o índice de thread.  
  
2.  Na barra de menus, escolha **depurar**, **continuar**, que faz com que os quatro threads que estavam ativas em andamento para a próxima barreira (definido na linha 32 AMPMapReduce.cpp).  
  
3.  Escolha o símbolo de sinalizador no lado esquerdo da linha que contém quatro threads que agora estão ativo.  
  
     A ilustração a seguir mostra os quatro threads sinalizados ativos na janela de Threads de GPU.  
  
     ![Janela Threads de GPU com threads sinalizados](../../parallel/amp/media/campg.png "campg")  
Threads ativos na janela de Threads de GPU  
  
     A janela Inspeção paralela e DataTip da janela pilhas paralelas ambos indicam os threads sinalizados.  
  
4.  Se você quiser se concentrar em quatro segmentos que é sinalizado, você pode optar por mostrar, de Threads de GPU, inspeção paralela e windows de pilhas paralelas, apenas os threads sinalizados.  
  
     Escolha Mostrar apenas sinalizados botão em qualquer uma das janelas ou no **local do depurador** barra de ferramentas. A ilustração a seguir mostra o botão Mostrar apenas sinalizados no **local do depurador** barra de ferramentas.  
  
     ![Depuração da barra de ferramentas do local com o ícone de mostrar somente sinalizados](../../parallel/amp/media/camph.png "camph")  
Mostrar somente sinalizados botão  
  
     Agora as janelas de Threads de GPU, inspeção paralela e pilhas paralelas exibem apenas os threads sinalizados.  
  
## <a name="freezing-and-thawing-gpu-threads"></a>Congelar e descongelar Threads de GPU  
 Você pode congelar (Suspender) e descongelar threads GPU (Continuar) da janela de Threads de GPU ou a janela Inspeção paralela. Você pode congelar e descongelar threads de CPU do mesmo modo; Para obter informações, consulte [como: usar a janela Threads](/visualstudio/debugger/how-to-use-the-threads-window).  
  
### <a name="to-freeze-and-thaw-gpu-threads"></a>Para congelar e descongelar threads GPU  
  
1.  Escolha o **Mostrar apenas sinalizados** botão para exibir todos os threads.  
  
2.  Na barra de menus, escolha **depurar**, **continuar**.  
  
3.  Abra o menu de atalho para a linha ativa e, em seguida, escolha **congelar**.  
  
     A ilustração a seguir da janela de Threads de GPU mostra que todas as quatro threads estão congelados.  
  
     ![Janelas de Threads de GPU mostrando threads congeladas](../../parallel/amp/media/campk.png "campk")  
Threads congeladas na janela de Threads de GPU  
  
     Da mesma forma, a janela Inspeção paralela mostra que todas as quatro threads estão congelados.  
  
4.  Na barra de menus, escolha **depurar**, **continuar** para permitir que os threads GPU quatro progredir após a barreira na linha 22 e para alcançar o ponto de interrupção na linha 30. A janela Threads de GPU mostra que quatro threads congelados anteriormente permanecem congelada e no estado ativo.  
  
5.  Na barra de menus, escolha **depurar**, **continuar**.  
  
6.  Na janela Inspeção paralela, você também pode descongelar individuais ou vários threads GPU.  
  
### <a name="to-group-gpu-threads"></a>Para threads de GPU do grupo  
  
1.  No menu de atalho para um dos segmentos no **Threads de GPU** janela, escolha **Group By**, **endereço**.  
  
     Os threads na janela Threads de GPU são agrupados por endereço. O endereço corresponde à instrução no desmontagem onde cada grupo de threads está localizado. 24 threads estão na linha 22 onde o [tile_barrier:: wait método](reference/tile-barrier-class.md#wait) é executado. 12 threads estão na instrução para a barreira na linha 32. Quatro desses threads sinalizados. Oito threads estão no ponto de interrupção na linha 30. Quatro desses threads estão congelados. A ilustração a seguir mostra os threads agrupados na janela de Threads de GPU.  

  
     ![Janela Threads de GPU com threads agrupadas por endereço](../../parallel/amp/media/campl.png "campl")  
Threads agrupados na janela de Threads de GPU  
  
2.  Você também pode executar o **Group By** operação abrindo o menu de atalho para a grade de dados da janela Inspeção paralela, escolhendo **Group By**e, em seguida, escolhendo o item de menu que corresponde a como você deseja para agrupar os threads.  
  
## <a name="running-all-threads-to-a-specific-location-in-code"></a>Executar todos os Threads em um local específico no código  
 Executar todos os threads em um determinado bloco para a linha que contém o cursor usando **executados lado a lado para Cursor atual**.  
  
### <a name="to-run-all-threads-to-the-location-marked-by-the-cursor"></a>Para executar todos os threads com o local marcado pelo cursor  
  
1.  No menu de atalho para os threads congelados, escolha **descongelar**.  
  
2.  No Editor de códigos, coloque o cursor na linha 30.  
  
3.  No menu de atalho para o Editor de código, escolha **executar bloco atual para Cursor**.  
  
     Os 24 threads que foram bloqueados anteriormente à barreira na linha 21 tem progrediu à linha de 32. Isso é mostrado no **Threads de GPU** janela.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md)   
 [Depurando código de GPU](/visualstudio/debugger/debugging-gpu-code)   
 [Como: usar a janela de Threads GPU](/visualstudio/debugger/how-to-use-the-gpu-threads-window)   
 [Como: usar a janela Inspeção paralela](/visualstudio/debugger/how-to-use-the-parallel-watch-window)   
 [Análise de código do C++ AMP com o Visualizador de simultaneidade](http://go.microsoft.com/fwlink/p/?linkid=253987&clcid=0x409)

