---
title: 'Instruções passo a passo: depurando um aplicativo C++ AMP'
ms.date: 11/19/2018
helpviewer_keywords:
- debugging, C++ Accelerated Massive Parallelism
- C++ AMP, debugging
- C++ Accelerated Massive Parallelism, debugging
- debugging, C++ AMP
ms.assetid: 40e92ecc-f6ba-411c-960c-b3047b854fb5
ms.openlocfilehash: 610cf317982204715d55d12ece510cb477543f4d
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52176686"
---
# <a name="walkthrough-debugging-a-c-amp-application"></a>Instruções passo a passo: depurando um aplicativo C++ AMP

Este tópico demonstra como depurar um aplicativo que usa C++ Accelerated Massive Parallelism (C++ AMP) para aproveitar a unidade de processamento gráfico (GPU). Ele usa um programa de redução em paralelo a soma de uma grande matriz de inteiros. Esta explicação passo a passo ilustra as seguintes tarefas:

- Iniciando o depurador GPU.

- Inspecionando os threads da GPU na janela Threads da GPU.

- Usando o **pilhas paralelas** janela para observar simultaneamente as pilhas de chamadas de vários threads GPU.

- Usando o **inspeção paralela** janela Inspecionar os valores de uma única expressão entre vários threads ao mesmo tempo.

- Sinalização, congelar, Descongelando e agrupamento de threads da GPU.

- Executar todos os threads de um bloco em um local específico no código.

## <a name="prerequisites"></a>Pré-requisitos

Antes de começar este passo a passo:

- Leia [visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md).

- Certifique-se de que a linha números são exibidos no editor de texto. Para obter mais informações, consulte [como: exibir números de linha no Editor de](/visualstudio/ide/reference/how-to-display-line-numbers-in-the-editor).

- Verifique se que você estiver executando o Windows 8 ou Windows Server 2012 para dar suporte à depuração no emulador de software.

[!INCLUDE[note_settings_general](../../mfc/includes/note_settings_general_md.md)]

### <a name="to-create-the-sample-project"></a>Para criar o projeto de exemplo

1. Inicie o Visual Studio.

2. Na barra de menus, selecione **Arquivo** > **Novo** > **Projeto**.

3. Sob **Installed** no painel modelos, escolha **Visual C++**.

4. Escolher **aplicativo do Console Win32**, tipo `AMPMapReduce` no **nome** caixa e, em seguida, escolha o **Okey** botão.

5. Escolha o botão **Avançar**.

6. Desmarque a **cabeçalho pré-compilado** caixa de seleção e, em seguida, escolha o **concluir** botão.

7. Na **Gerenciador de soluções**, excluí a Stdafx. h, targetver e Stdafx do projeto.

8. Abra AMPMapReduce.cpp e substitua seu conteúdo pelo código a seguir.

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

9. Na barra de menus, escolha **Arquivo** > **Salvar Todos**.

10. Na **Gerenciador de soluções**, abra o menu de atalho **AMPMapReduce**e, em seguida, escolha **propriedades**.

11. No **páginas de propriedades** caixa de diálogo **propriedades de configuração**, escolha **C/C++** > **cabeçalhos pré-compilados**.

12. Para o **cabeçalho pré-compilado** propriedade, selecione **não usando cabeçalhos pré-compilados**e, em seguida, escolha o **Okey** botão.

13. Na barra de menus, escolha **Compilar** > **Compilar Solução**.

## <a name="debugging-the-cpu-code"></a>Depurar o código de CPU

Neste procedimento, você usará o depurador Local do Windows para certificar-se de que o código de CPU neste aplicativo esteja correto. O segmento do código da CPU neste aplicativo que é especialmente interessante é o `for` em um loop de `reduction_sum_gpu_kernel` função. Ele controla a redução paralela baseada em árvore que é executada no GPU.

### <a name="to-debug-the-cpu-code"></a>Para depurar o código de CPU

1. Na **Gerenciador de soluções**, abra o menu de atalho **AMPMapReduce**e, em seguida, escolha **propriedades**.

2. No **páginas de propriedades** caixa de diálogo **propriedades de configuração**, escolha **depuração**. Verifique **depurador Local do Windows** está selecionado na **depurador a iniciar** lista.

3. Volte para o **Editor de códigos**.

4. Definir pontos de interrupção nas linhas do código mostrado na ilustração a seguir (aproximadamente linhas 67 linha 70).

   ![Pontos de interrupção de CPU](../../parallel/amp/media/campcpubreakpoints.png "pontos de interrupção de CPU") <br/>
   Pontos de interrupção de CPU

5. Na barra de menus, escolha **Depurar** > **Iniciar Depuração**.

6. No **Locals** janela, observe o valor de `stride_size` até que o ponto de interrupção na linha 70 seja atingido.

7. Na barra de menus, escolha **Depurar** > **Parar Depuração**.

## <a name="debugging-the-gpu-code"></a>Depurando o código de GPU

Esta seção mostra como depurar o código GPU, que é o código contido no `sum_kernel_tiled` função. O código GPU calcula a soma de números inteiros para cada "bloco" em paralelo.

### <a name="to-debug-the-gpu-code"></a>Para depurar o código GPU

1. Na **Gerenciador de soluções**, abra o menu de atalho **AMPMapReduce**e, em seguida, escolha **propriedades**.

2. No **páginas de propriedades** caixa de diálogo **propriedades de configuração**, escolha **depuração**.

3. No **depurador a iniciar** lista, selecione **depurador Local do Windows**.

4. No **tipo de depurador** lista, verifique **automático** está selecionado.

    **Auto** é o valor padrão. Antes do Windows 10 **somente GPU** é o valor necessário em vez de **automática**.

5. Escolha o botão **OK**.

6. Defina um ponto de interrupção na linha 30, conforme mostrado na ilustração a seguir.

   ![Pontos de interrupção GPU](../../parallel/amp/media/campgpubreakpoints.png "pontos de interrupção GPU") <br/>
   Ponto de interrupção GPU

7. Na barra de menus, escolha **Depurar** > **Iniciar Depuração**. Os pontos de interrupção no código da CPU em linhas 67 e 70 não são executados durante a depuração, pois as linhas de código são executadas na CPU de GPU.

### <a name="to-use-the-gpu-threads-window"></a>Usar a janela Threads da GPU

1. Para abrir o **Threads da GPU** janela, na barra de menus, escolha **Debug** > **Windows** > **Threads da GPU**.

   Você pode inspecionar o estado de threads de GPU na **Threads da GPU** janela que aparece.

2. Encaixe a **Threads da GPU** janela na parte inferior do Visual Studio. Escolha o **comutador de Thread expanda** botão para exibir caixas de texto lado a lado e thread. O **Threads da GPU** janela mostra o número total de threads de GPU do Active Directory e bloqueado, conforme mostrado na ilustração a seguir.

   ![Janela Threads da GPU com 4 threads ativos](../../parallel/amp/media/campc.png "janela Threads da GPU com 4 threads ativos") <br/>
   Janela Threads da GPU

   Há 313 blocos alocados para esse cálculo. Cada bloco contém 32 segmentos. Como a depuração de GPU local ocorre em um emulador de software, há quatro threads GPU ativos. Os quatro threads de executam as instruções simultaneamente e, em seguida, passar em conjunto para a próxima instrução.

   No **Threads da GPU** janela, há quatro threads GPU ativos e 28 threads da GPU bloqueada na [tile_barrier:: wait](reference/tile-barrier-class.md#wait) instrução definida na sobre linha 21 (`t_idx.barrier.wait();`). Todos os threads da GPU 32 pertencem ao primeiro bloco, `tile[0]`. Uma seta aponta para a linha que inclui o thread atual. Para alternar para um thread diferente, use um dos seguintes métodos:

    - Na linha para o thread alternar para na **Threads da GPU** janela, abra o menu de atalho e escolha **alternar para Thread**. Se a linha representa mais de um thread, você alternará para o primeiro thread de acordo com as coordenadas de thread.

    - Insira os valores de bloco e o thread do thread nas caixas de texto correspondente e, em seguida, escolha o **comutador Thread** botão.

   O **pilha de chamadas** janela exibe a pilha de chamadas do thread atual de GPU.

### <a name="to-use-the-parallel-stacks-window"></a>Para usar a janela pilhas paralelas

1. Para abrir o **pilhas paralelas** janela, na barra de menus, escolha **Debug** > **Windows** > **pilhas paralelas**.

   Você pode usar o **pilhas paralelas** janela Inspecionar simultaneamente os registros de ativação de vários threads GPU.

2. Encaixe a **pilhas paralelas** janela na parte inferior do Visual Studio.

3. Certifique-se de que **Threads** é selecionado na lista no canto superior esquerdo. Na ilustração a seguir, o **pilhas paralelas** janela mostra uma exibição de pilha de chamadas com foco os threads da GPU que você viu na **Threads da GPU** janela.

   ![Janela pilhas paralelas com 4 threads ativos](../../parallel/amp/media/campd.png "janela pilhas paralelas com 4 threads ativos") <br/>
   Janela pilhas paralelas

   32 segmentos passaram de `_kernel_stub` à instrução lambda na `parallel_for_each` chamada de função e, em seguida, para o `sum_kernel_tiled` função, onde ocorre a redução paralela. 28 sem os 32 threads progrediram para o [tile_barrier:: wait](reference/tile-barrier-class.md#wait) instrução e permanecem bloqueados na linha 22, enquanto outros 4 threads permanecem ativos no `sum_kernel_tiled` função na linha 30.

   Você pode inspecionar as propriedades de um thread GPU que estão disponíveis na **Threads da GPU** janela no DataTip Avançada da **pilhas paralelas** janela. Para fazer isso, o ponteiro do mouse no quadro da pilha **sum_kernel_tiled**. A ilustração a seguir mostra o DataTip.

   ![DataTip para a janela pilhas paralelas](../../parallel/amp/media/campe.png "DataTip para a janela pilhas paralelas") <br/>
   Thread de GPU DataTip

   Para obter mais informações sobre o **pilhas paralelas** janela, consulte [usando a janela Parallel Stacks](/visualstudio/debugger/using-the-parallel-stacks-window).

### <a name="to-use-the-parallel-watch-window"></a>Usar a janela Inspeção paralela

1. Para abrir o **inspeção paralela** janela, na barra de menus, escolha **Debug** > **Windows** > **inspeção paralela**  >  **Inspeção 1 paralela**.

   Você pode usar o **inspeção paralela** janela Inspecionar os valores de uma expressão entre vários threads.

2. Encaixe a **paralela inspeção 1** janela na parte inferior do Visual Studio. Há 32 linhas na tabela do **inspeção paralela** janela. Cada um corresponde a um thread GPU que apareceu na janela Threads da GPU e o **pilhas paralelas** janela. Agora, você pode inserir expressões cujos valores você deseja inspecionar entre todos os threads GPU 32.

3. Selecione o **Adicionar inspeção** cabeçalho de coluna, digite `localIdx`e, em seguida, escolha o **Enter** chave.

4. Selecione o **Adicionar inspeção** cabeçalho de coluna novamente, digite `globalIdx`e, em seguida, escolha o **Enter** chave.

5. Selecione o **Adicionar inspeção** cabeçalho de coluna novamente, digite `localA[localIdx[0]]`e, em seguida, escolha o **Enter** chave.

   Você pode classificar por uma expressão especificada, selecionando o título de coluna correspondente.

   Selecione o **localA [localIdx [0]]** cabeçalho de coluna para classificar a coluna. A ilustração a seguir mostra os resultados da classificação por **localA [localIdx [0]]**.

   ![Janela de inspeção paralela com os resultados classificados](../../parallel/amp/media/campf.png "janela Inspeção paralela com os resultados classificados") <br/>
   Resultados de classificação

   Você pode exportar o conteúdo a **inspeção paralela** janela para o Excel, escolhendo o **Excel** botão e, em seguida, escolhendo **abrir no Excel**. Se você tiver o Excel instalado em seu computador de desenvolvimento, isso abre uma planilha do Excel que contém o conteúdo.

6. No canto superior direito dos **inspeção paralela** janela, há um controle de filtro que você pode usar para filtrar o conteúdo por meio de expressões Boolianas. ENTER `localA[localIdx[0]] > 20000` no texto do controle de filtro caixa e, em seguida, escolha o **Enter** chave.

   A janela agora contém apenas os threads nos quais o `localA[localIdx[0]]` valor é maior que 20000. O conteúdo ainda é classificado pelo `localA[localIdx[0]]` coluna, que é a ação de classificação que você executou anteriormente.

## <a name="flagging-gpu-threads"></a>Sinalizar Threads da GPU

Você pode marcar os threads GPU específicos sinalizando-los de **Threads da GPU** janela, o **inspeção paralela** janela ou o DataTip no **pilhas paralelas** janela. Se uma linha na janela Threads da GPU contém mais de um thread, sinalizar que a linha sinaliza todos os threads que estão contidos na linha.

### <a name="to-flag-gpu-threads"></a>Para sinalizar threads da GPU

1. Selecione o **[Thread]** cabeçalho de coluna na **paralela inspeção 1** janela para classificar por índice lado a lado e o índice de thread.

2. Na barra de menus, escolha **Debug** > **continuar**, que faz com que os quatro threads que estavam ativas para o progresso para a próxima barreira (definido na linha 32 de AMPMapReduce.cpp).

3. Escolha o símbolo de sinalizador no lado esquerdo da linha que contém os quatro threads que agora estão ativos.

   A ilustração a seguir mostra os quatro threads sinalizados Active Directory na **Threads da GPU** janela.

   ![Janela Threads da GPU com threads sinalizados](../../parallel/amp/media/campg.png "janela Threads da GPU com threads sinalizados") <br/>
   Threads ativos na janela Threads da GPU

   O **inspeção paralela** janela e o DataTip da **pilhas paralelas** janela ambos os indicam os threads sinalizados.

4. Se você quiser se concentrar em quatro threads que é sinalizado, você pode optar por mostrar, além de **Threads da GPU**, **inspeção paralela**, e **pilhas paralelas** windows, apenas os sinalizados threads.

   Escolha o **Mostrar apenas sinalizados** botão em qualquer uma das janelas ou nos **local de depuração** barra de ferramentas. A ilustração a seguir mostra a **Mostrar apenas sinalizados** botão a **local de depuração** barra de ferramentas.

   ![Depurar barra de ferramentas do local com o ícone de mostrar somente sinalizados](../../parallel/amp/media/camph.png "barra de ferramentas de depuração local com o ícone de mostrar somente sinalizados") <br/>
   **Mostrar apenas sinalizados** botão

   Agora o **Threads da GPU**, **inspeção paralela**, e **pilhas paralelas** janelas exibem apenas os threads sinalizados.

## <a name="freezing-and-thawing-gpu-threads"></a>Congelando e Descongelando Threads da GPU

Você pode congelar (Suspender) e descongelar (retomar) GPU threads de qualquer um de **Threads da GPU** janela ou o **inspeção paralela** janela. Você pode congelar e descongelar threads de CPU da mesma forma; Para obter informações, consulte [como: usar a janela Threads](/visualstudio/debugger/how-to-use-the-threads-window).

### <a name="to-freeze-and-thaw-gpu-threads"></a>Para congelar e descongelar threads da GPU

1. Escolha o **Mostrar apenas sinalizados** botão para exibir todos os threads.

2. Na barra de menus, escolha **Debug** > **continuar**.

3. Abra o menu de atalho para a linha ativa e, em seguida, escolha **congelar**.

   A ilustração a seguir da **Threads da GPU** janela mostra que todos os quatro threads estão congelados.

   ![Janelas de Threads da GPU mostrando threads congelados](../../parallel/amp/media/campk.png "janelas de Threads da GPU mostrando threads congelados") <br/>
   Congeladas threads na **Threads da GPU** janela

   Da mesma forma, o **inspeção paralela** janela mostra que todos os quatro threads estão congelados.

4. Na barra de menus, escolha **Debug** > **continuar** para permitir que os próximos quatro threads da GPU Avançar após a barreira na linha 22 e alcançar o ponto de interrupção na linha 30. O **Threads da GPU** janela mostra que quatro threads congelados anteriormente permanecem congelados e no estado ativo.

5. Na barra de menus, escolha **Debug**, **continuar**.

6. Dos **inspeção paralela** janela, você também pode descongelar individuais ou vários threads da GPU.

### <a name="to-group-gpu-threads"></a>Para agrupar threads da GPU

1. No menu de atalho para um dos threads na **Threads da GPU** janela, escolha **Group By**, **endereço**.

   Os threads na **Threads da GPU** janela são agrupadas por endereço. O endereço corresponde à instrução no desmontagem onde cada grupo de threads está localizado. 24 threads estão na linha 22 em que o [tile_barrier:: wait método](reference/tile-barrier-class.md#wait) é executado. 12 threads são durante a instrução para a barreira na linha 32. Quatro desses threads sinalizados. Oito threads estão no ponto de interrupção na linha 30. Quatro desses threads estão congelados. A ilustração a seguir mostra os segmentos agrupados na **Threads da GPU** janela.

   ![Janela Threads da GPU com threads são agrupados pelo endereço](../../parallel/amp/media/campl.png "janela Threads da GPU com segmentos agrupados por endereço") <br/>
   Agrupados threads na **Threads da GPU** janela

2. Você também pode executar o **Group By** operação abrindo o menu de atalho para a grade de dados das **inspeção paralela** janela, escolhendo **Group By**e, em seguida, escolhendo o menu item que corresponde a como você deseja agrupar threads.

## <a name="running-all-threads-to-a-specific-location-in-code"></a>Executando todos os Threads em um local específico no código

Executar todos os threads em um determinado bloco para a linha que contém o cursor usando **executados lado a lado para Cursor atual**.

### <a name="to-run-all-threads-to-the-location-marked-by-the-cursor"></a>Para executar todos os threads com o local marcado pelo cursor

1. No menu de atalho para os threads congelados, escolha **descongelar**.

2. No **Editor de códigos**, coloque o cursor na linha 30.

3. No menu de atalho para o **Editor de códigos**, escolha **executar bloco atual para Cursor**.

   Os 24 threads que foram bloqueados anteriormente na barreira na linha 21 progrediram à linha 32. Isso é mostrado na **Threads da GPU** janela.

## <a name="see-also"></a>Consulte também

[Visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md)<br/>
[Depurando código de GPU](/visualstudio/debugger/debugging-gpu-code)<br/>
[Como usar a janela Threads da GPU](/visualstudio/debugger/how-to-use-the-gpu-threads-window)<br/>
[Como usar a janela Inspeção Paralela](/visualstudio/debugger/how-to-use-the-parallel-watch-window)<br/>
[Analisando código AMP de C++ com o Visualizador de simultaneidade](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/03/09/analyzing-c-amp-code-with-the-concurrency-visualizer/)
