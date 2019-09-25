---
title: 'Passo a passo: Depurando um C++ aplicativo amp'
ms.date: 04/23/2019
helpviewer_keywords:
- debugging, C++ Accelerated Massive Parallelism
- C++ AMP, debugging
- C++ Accelerated Massive Parallelism, debugging
- debugging, C++ AMP
ms.assetid: 40e92ecc-f6ba-411c-960c-b3047b854fb5
ms.openlocfilehash: 0c9fb5588cfd44c83d8fe72c7c4aede0fedab672
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "69631593"
---
# <a name="walkthrough-debugging-a-c-amp-application"></a>Passo a passo: Depurando um C++ aplicativo amp

Este tópico demonstra como depurar um aplicativo que usa C++ o grande paralelismo acelerado (C++ amp) para aproveitar a GPU (unidade de processamento gráfico). Ele usa um programa de redução paralela que soma uma grande matriz de inteiros. Esta explicação passo a passo ilustra as seguintes tarefas:

- Iniciando o depurador de GPU.

- Inspecionando threads de GPU na janela threads de GPU.

- Usando a janela de **pilhas paralelas** para observar simultaneamente as pilhas de chamadas de vários threads de GPU.

- Usando a janela de **inspeção paralela** para inspecionar valores de uma única expressão entre vários threads ao mesmo tempo.

- Sinalização, congelamento, descongelamento e agrupamento de threads de GPU.

- Executar todos os threads de um bloco em um local específico no código.

## <a name="prerequisites"></a>Pré-requisitos

Antes de iniciar este passo a passos:

- Leia [ C++ visão geral do amp](../../parallel/amp/cpp-amp-overview.md).

- Verifique se os números de linha são exibidos no editor de texto. Para obter mais informações, confira [Como: Exiba os números de linha no](/visualstudio/ide/reference/how-to-display-line-numbers-in-the-editor)editor.

- Verifique se você está executando pelo menos o Windows 8 ou o Windows Server 2012 para dar suporte à depuração no emulador de software. 

[!INCLUDE[note_settings_general](../../mfc/includes/note_settings_general_md.md)]

### <a name="to-create-the-sample-project"></a>Para criar o projeto de exemplo

As instruções para criar um projeto variam de acordo com a versão do Visual Studio que você está usando. Verifique se você tem a versão correta selecionada no canto superior esquerdo desta página.

::: moniker range="vs-2019"

### <a name="to-create-the-sample-project-in-visual-studio-2019"></a>Para criar o projeto de exemplo no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto**.

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Console**. 

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**. Na próxima página, insira `AMPMapReduce` na caixa **Nome** para especificar um nome para o projeto e, se quiser, especifique o local do projeto.

   ![Nomear o projeto](../../build/media/mathclient-project-name-2019.png "Nomear o projeto")

1. Escolha o botão **Criar** para criar o projeto do cliente.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-the-sample-project-in-visual-studio-2017-or-visual-studio-2015"></a>Para criar o projeto de exemplo no Visual Studio 2017 ou no Visual Studio 2015

1. Inicie o Visual Studio.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto**.

1. Em **instalado** no painel modelos, escolha **Visual C++** .

1. Escolha **aplicativo de console**do Win32 `AMPMapReduce` , digite na caixa **nome** e escolha o botão **OK** .

1. Escolha o botão **Avançar**.

1. Desmarque a caixa de seleção **cabeçalho pré-compilado** e, em seguida, escolha o botão **concluir** .

1. Em **Gerenciador de soluções**, exclua *stdafx. h*, *targetver. h*e *stdafx. cpp* do projeto.

::: moniker-end

Última

8. Abra AMPMapReduce. cpp e substitua seu conteúdo pelo código a seguir.

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

10. No **Gerenciador de soluções**, abra o menu de atalho para **AMPMapReduce**e escolha **Propriedades**.

11. Na caixa de diálogo **páginas de propriedades** , em **Propriedades de configuração**, escolha cabeçalhos **C/C++**  > pré-compilados.

12. Para a propriedade de **cabeçalho pré-compilado** , selecione **não usar cabeçalhos pré-compilados**e, em seguida, escolha o botão **OK** .

13. Na barra de menus, escolha **Compilar** > **Compilar Solução**.

## <a name="debugging-the-cpu-code"></a>Depurando o código de CPU

Neste procedimento, você usará o depurador local do Windows para certificar-se de que o código de CPU neste aplicativo está correto. O segmento do código de CPU neste aplicativo que é especialmente interessante é o `for` loop `reduction_sum_gpu_kernel` na função. Ele controla a redução paralela baseada em árvore que é executada na GPU.

### <a name="to-debug-the-cpu-code"></a>Para depurar o código de CPU

1. No **Gerenciador de soluções**, abra o menu de atalho para **AMPMapReduce**e escolha **Propriedades**.

2. Na caixa de diálogo **páginas de propriedades** , em **Propriedades de configuração**, escolha **depuração**. Verifique se o **depurador local do Windows** está selecionado na lista **depurador a ser iniciado** .

3. Retorne ao **Editor de código**.

4. Defina pontos de interrupção nas linhas de código mostradas na ilustração a seguir (aproximadamente linhas 67 linha 70).

   ![Pontos de interrupção de CPU](../../parallel/amp/media/campcpubreakpoints.png "Pontos de interrupção de CPU") <br/>
   Pontos de interrupção de CPU

5. Na barra de menus, escolha **Depurar** > **Iniciar Depuração**.

6. Na janela **locais** , observe o valor de `stride_size` até que o ponto de interrupção na linha 70 seja atingido.

7. Na barra de menus, escolha **Depurar** > **Parar Depuração**.

## <a name="debugging-the-gpu-code"></a>Depurando o código de GPU

Esta seção mostra como depurar o código da GPU, que é o código contido na `sum_kernel_tiled` função. O código de GPU computa a soma de inteiros para cada "bloco" em paralelo.

### <a name="to-debug-the-gpu-code"></a>Para depurar o código de GPU

1. No **Gerenciador de soluções**, abra o menu de atalho para **AMPMapReduce**e escolha **Propriedades**.

2. Na caixa de diálogo **páginas de propriedades** , em **Propriedades de configuração**, escolha **depuração**.

3. Na lista **Depurador a iniciar**, selecione **Depurador Local do Windows**.

4. Na lista **tipo de depurador** , verifique se a **seleção automática** está selecionada.

    **Auto** é o valor padrão. Antes do Windows 10, a **GPU só** é o valor necessário em vez de **auto**.

5. Escolha o botão **OK**.

6. Defina um ponto de interrupção na linha 30, conforme mostrado na ilustração a seguir.

   ![Pontos de interrupção de GPU](../../parallel/amp/media/campgpubreakpoints.png "Pontos de interrupção de GPU") <br/>
   Ponto de interrupção de GPU

7. Na barra de menus, escolha **Depurar** > **Iniciar Depuração**. Os pontos de interrupção no código de CPU nas linhas 67 e 70 não são executados durante a depuração de GPU porque essas linhas de código são executadas na CPU.

### <a name="to-use-the-gpu-threads-window"></a>Para usar a janela threads de GPU

1. Para abrir a janela **threads de GPU** , na barra de menus, escolha **depurar** > **threads de GPU**do**Windows** > .

   Você pode inspecionar o estado dos threads de GPU na janela **threads de GPU** que aparece.

2. Encaixe a janela **threads de GPU** na parte inferior do Visual Studio. Escolha o botão de **opção expandir thread** para exibir as caixas de texto bloco e thread. A janela **threads de GPU** mostra o número total de threads de GPU ativos e bloqueados, conforme mostrado na ilustração a seguir.

   ![Janela threads GPU com 4 threads ativos](../../parallel/amp/media/campc.png "Janela threads GPU com 4 threads ativos") <br/>
   Janela threads GPU

   Há 313 blocos alocados para esse cálculo. Cada bloco contém 32 threads. Como a depuração de GPU local ocorre em um emulador de software, há quatro threads de GPU ativos. Os quatro threads executam as instruções simultaneamente e, em seguida, passam para a próxima instrução.

   Na janela **threads de GPU** , há quatro threads de GPU ativos e 28 threads de GPU bloqueados na instrução [tile_barrier:: Wait](reference/tile-barrier-class.md#wait) definida na`t_idx.barrier.wait();`linha 21 (). Todos os threads de GPU 32 pertencem ao primeiro `tile[0]`bloco,. Uma seta aponta para a linha que inclui o thread atual. Para alternar para um thread diferente, use um dos seguintes métodos:

    - Na linha para o thread alternar para na janela **threads de GPU** , abra o menu de atalho e escolha **alternar para thread**. Se a linha representar mais de um thread, você mudará para o primeiro thread de acordo com as coordenadas de thread.

    - Insira os valores de bloco e thread do thread nas caixas de texto correspondentes e, em seguida, escolha o botão **alternar thread** .

   A janela **pilha de chamadas** exibe a pilha de chamadas do thread da GPU atual.

### <a name="to-use-the-parallel-stacks-window"></a>Para usar a janela pilhas paralelas

1. Para abrir a janela **pilhas paralelas** , na barra de menus, escolha **depurar** > **pilhas paralelas**do**Windows** > .

   Você pode usar a janela de **pilhas paralelas** para inspecionar simultaneamente os quadros de pilha de vários threads de GPU.

2. Encaixe a janela de **pilhas paralelas** na parte inferior do Visual Studio.

3. Verifique se **threads** está selecionado na lista no canto superior esquerdo. Na ilustração a seguir, a janela **pilhas paralelas** mostra uma exibição focalizada de pilha de chamadas dos threads de GPU que você viu na janela **threads de GPU** .

   ![Janela de pilhas paralelas com 4 threads ativos](../../parallel/amp/media/campd.png "Janela de pilhas paralelas com 4 threads ativos") <br/>
   Janela pilhas paralelas

   32 threads passaram `_kernel_stub` de para a instrução Lambda `parallel_for_each` na chamada de função e, em `sum_kernel_tiled` seguida, para a função, em que ocorre a redução paralela. 28 dos 32 threads progrediram para a instrução [tile_barrier:: Wait](reference/tile-barrier-class.md#wait) e permanecem bloqueados na linha 22, enquanto os outros 4 threads permanecem ativos na `sum_kernel_tiled` função na linha 30.

   Você pode inspecionar as propriedades de um thread de GPU que estão disponíveis na janela **threads de GPU** no DataTip avançado da janela **pilhas paralelas** . Para fazer isso, posicione o ponteiro do mouse no registro de ativação de **sum_kernel_tiled**. A ilustração a seguir mostra o DataTip.

   ![DataTip para janela de pilhas paralelas](../../parallel/amp/media/campe.png "DataTip para janela de pilhas paralelas") <br/>
   Thread de GPU DataTip

   Para obter mais informações sobre a janela de **pilhas paralelas** , consulte [usando a janela pilhas paralelas](/visualstudio/debugger/using-the-parallel-stacks-window).

### <a name="to-use-the-parallel-watch-window"></a>Para usar o janela Inspeção paralelo

1. Para abrir a janela de **inspeção paralela** , na barra de menus, escolha **depurar** > **Windows** > **Parallel Watch** > **paralela Watch 1**.

   Você pode usar a janela de **inspeção paralela** para inspecionar os valores de uma expressão em vários threads.

2. Encaixe a janela **paralela Watch 1** na parte inferior do Visual Studio. Há 32 linhas na tabela da janela de **inspeção paralela** . Cada uma corresponde a um thread de GPU que apareceu na janela threads de GPU e na janela de **pilhas paralelas** . Agora, você pode inserir expressões cujos valores você deseja inspecionar em todos os threads de GPU de 32.

3. Selecione o cabeçalho adicionar coluna de **inspeção** , `localIdx`digite e, em seguida, escolha a tecla **Enter** .

4. Selecione o cabeçalho adicionar coluna de **inspeção** novamente, `globalIdx`digite e, em seguida, escolha a tecla **Enter** .

5. Selecione o cabeçalho adicionar coluna de **inspeção** novamente, `localA[localIdx[0]]`digite e, em seguida, escolha a tecla **Enter** .

   Você pode classificar por uma expressão especificada selecionando seu cabeçalho de coluna correspondente.

   Selecione o cabeçalho de coluna **locala [localIdx [0]]** para classificar a coluna. A ilustração a seguir mostra os resultados da classificação por **locala [localIdx [0]]** .

   ![Janela inspeção paralelos com resultados classificados](../../parallel/amp/media/campf.png "Janela inspeção paralelos com resultados classificados") <br/>
   Resultados da classificação

   Você pode exportar o conteúdo na janela de **inspeção paralela** para o Excel escolhendo o botão **Excel** e, em seguida, escolhendo **abrir no Excel**. Se você tiver o Excel instalado em seu computador de desenvolvimento, isso abrirá uma planilha do Excel que contém o conteúdo.

6. No canto superior direito da janela de **inspeção paralela** , há um controle de filtro que você pode usar para filtrar o conteúdo usando expressões booleanas. Digite `localA[localIdx[0]] > 20000` na caixa de texto controle de filtro e escolha a tecla **Enter** .

   A janela agora contém apenas threads nos quais `localA[localIdx[0]]` o valor é maior que 20000. O conteúdo ainda é classificado pela `localA[localIdx[0]]` coluna, que é a ação de classificação executada anteriormente.

## <a name="flagging-gpu-threads"></a>Sinalizando threads de GPU

Você pode marcar threads de GPU específicos sinalizando-os na janela **threads de GPU** , na janela de **inspeção paralela** ou no DataTip na janela **pilhas paralelas** . Se uma linha na janela threads de GPU contiver mais de um thread, sinalizando que a linha sinalizará todos os threads contidos na linha.

### <a name="to-flag-gpu-threads"></a>Para sinalizar threads de GPU

1. Selecione o cabeçalho de coluna **[Thread]** na janela de **inspeção paralela 1** para classificar por índice de bloco e índice de thread.

2. Na barra de menus, escolha **depurar** > **continuar**, que faz com que os quatro threads que estavam ativos sejam progredidos para a próxima barreira (definida na linha 32 de AMPMapReduce. cpp).

3. Escolha o símbolo de sinalizador no lado esquerdo da linha que contém os quatro threads que agora estão ativos.

   A ilustração a seguir mostra os quatro threads sinalizados ativos na janela **threads de GPU** .

   ![Janela de threads de GPU com threads sinalizados](../../parallel/amp/media/campg.png "Janela de threads de GPU com threads sinalizados") <br/>
   Threads ativos na janela threads de GPU

   A janela de **inspeção paralela** e a DataTip da janela **pilhas paralelas** indicam os threads sinalizados.

4. Se você quiser se concentrar nos quatro threads sinalizados, poderá optar por mostrar, nas janelas **threads de GPU**, **inspeção paralela**e **pilhas paralelas** , somente os threads sinalizados.

   Escolha o botão **Mostrar somente sinalizado** em qualquer uma das janelas ou na barra de ferramentas **local de depuração** . A ilustração a seguir mostra o botão **Mostrar somente sinalizado** na barra de ferramentas do **local de depuração** .

   ![Barra de ferramentas do local de depuração com o ícone mostrar somente sinalizado](../../parallel/amp/media/camph.png "Barra de ferramentas do local de depuração com o ícone mostrar somente sinalizado") <br/>
   **Mostrar botão somente sinalizado**

   Agora, as janelas **threads de GPU**, **inspeção paralela**e **pilhas paralelas** exibem apenas os threads sinalizados.

## <a name="freezing-and-thawing-gpu-threads"></a>Congelando e descongelando threads de GPU

Você pode congelar (suspender) e descongelar (retomar) threads de GPU da janela **threads de GPU** ou da janela de **inspeção paralela** . Você pode congelar e descongelar Threads de CPU da mesma forma; para obter informações, [consulte Como: Use a janela](/visualstudio/debugger/how-to-use-the-threads-window)threads.

### <a name="to-freeze-and-thaw-gpu-threads"></a>Para congelar e descongelar Threads de GPU

1. Escolha o botão **Mostrar somente sinalizado** para exibir todos os threads.

2. Na barra de menus, escolha **depurar** > **continuar**.

3. Abra o menu de atalho da linha ativa e escolha **congelar**.

   A ilustração a seguir da janela **threads de GPU** mostra que todos os quatro threads estão congelados.

   ![Threads de GPU janelas mostrando threads congelados](../../parallel/amp/media/campk.png "Threads de GPU janelas mostrando threads congelados") <br/>
   Threads congelados na janela **threads de GPU**

   Da mesma forma, a janela de **inspeção paralela** mostra que todos os quatro threads estão congelados.

4. Na barra de menus, escolha **depurar** > **continuar** para permitir que os próximos quatro threads de GPU progredissem além da barreira na linha 22 e atinjam o ponto de interrupção na linha 30. A janela **threads de GPU** mostra que os quatro threads congelados anteriormente permanecem congelados e no estado ativo.

5. Na barra de menus, escolha **depurar**, **continuar**.

6. Na janela de **inspeção paralela** , você também pode descongelar Threads de GPU individuais ou múltiplos.

### <a name="to-group-gpu-threads"></a>Para agrupar threads de GPU

1. No menu de atalho para um dos threads na janela **threads de GPU** , escolha **Agrupar por**, **endereço**.

   Os threads na janela **threads de GPU** são agrupados por endereço. O endereço corresponde à instrução na desmontagem em que cada grupo de threads está localizado. 24 threads estão na linha 22, em que o [método tile_barrier:: Wait](reference/tile-barrier-class.md#wait) é executado. 12 threads estão na instrução para a barreira na linha 32. Quatro desses threads estão sinalizados. Oito threads estão no ponto de interrupção na linha 30. Quatro desses threads estão congelados. A ilustração a seguir mostra os threads agrupados na janela **threads de GPU** .

   ![Janela threads GPU com threads agrupados por endereço](../../parallel/amp/media/campl.png "Janela threads GPU com threads agrupados por endereço") <br/>
   Threads agrupados na janela **threads de GPU**

2. Você também pode executar a operação **Agrupar por** abrindo o menu de atalho para a grade de dados da janela de **inspeção paralela** , escolhendo **Agrupar por**e, em seguida, escolhendo o item de menu que corresponde ao modo como você deseja agrupar os threads.

## <a name="running-all-threads-to-a-specific-location-in-code"></a>Executando todos os threads em um local específico no código

Você executa todos os threads em um determinado bloco para a linha que contém o cursor usando **executar bloco atual para cursor**.

### <a name="to-run-all-threads-to-the-location-marked-by-the-cursor"></a>Para executar todos os threads para o local marcado pelo cursor

1. No menu de atalho para os threads congelados, escolha **descongelar**.

2. No **Editor de código**, coloque o cursor na linha 30.

3. No menu de atalho do **Editor de código**, escolha **executar bloco atual para cursor**.

   Os 24 threads que foram bloqueados anteriormente na barreira na linha 21 progrediram para a linha 32. Isso é mostrado na janela **threads de GPU** .

## <a name="see-also"></a>Consulte também

[Visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md)<br/>
[Depurando código de GPU](/visualstudio/debugger/debugging-gpu-code)<br/>
[Como: Usar a janela de Threads de GPU](/visualstudio/debugger/how-to-use-the-gpu-threads-window)<br/>
[Como: Usar a janela Inspeção Paralela](/visualstudio/debugger/how-to-use-the-parallel-watch-window)<br/>
[Analisando C++ o amp Code com o Visualizador de simultaneidade](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/03/09/analyzing-c-amp-code-with-the-concurrency-visualizer/)
