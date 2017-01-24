---
title: "Instru&#231;&#245;es passo a passo: depurando um aplicativo C++ AMP | Microsoft Docs"
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
helpviewer_keywords: 
  - "depuração de C++ Accelerated Massive Parallelism"
  - "C++ AMP, depuração"
  - "C++ Accelerated Massive Parallelism, depuração"
  - "depuração, C++ AMP"
ms.assetid: 40e92ecc-f6ba-411c-960c-b3047b854fb5
caps.latest.revision: 35
caps.handback.revision: 34
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: depurando um aplicativo C++ AMP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico demonstra como depurar um aplicativo que usa o C\+\+ Accelerated Massive Parallelism \(C\+\+ AMP\) para aproveitar a unidade de processamentos gráficos \(GPU\).  Ele usa um programa de redução paralela que resume uma grande matriz de inteiros.  Essa explicação passo a passo mostra as seguintes tarefas:  
  
-   Iniciando o depurador do GPU.  
  
-   Inspecionando threads do GPU na janela de Threads do GPU.  
  
-   Usando a janela de Pilhas Paralelas para observar simultaneamente as pilhas de chamada de vários threads do GPU.  
  
-   Usando a janela Relógio Paralela para verificar valores de uma única expressão por vários threads ao mesmo tempo.  
  
-   Sinalizando, congelando, descongelando e agrupando threads do GPU.  
  
-   Executando todos os segmentos de um quadro para um local específico no código.  
  
## Pré-requisitos  
 Antes de iniciar esta explicação passo a passo:  
  
-   Leia [Visão geral do C\+\+ AMP](../../parallel/amp/cpp-amp-overview.md).  
  
-   Certifique\-se de que o número de linhas é exibido no editor de texto.  Para obter mais informações, consulte [Como exibir números de linha no Editor](../Topic/How%20to:%20Display%20Line%20Numbers%20in%20the%20Editor.md).  
  
-   Certifique\-se de que você está executando o [!INCLUDE[win8](../../build/includes/win8_md.md)] ou [!INCLUDE[winserver8](../../build/includes/winserver8_md.md)] para oferecer suporte a depuração no emulador de software.  
  
 [!INCLUDE[note_settings_general](../../mfc/includes/note_settings_general_md.md)]  
  
### Para criar o projeto modelo  
  
1.  Inicie o Visual Studio.  
  
2.  Na barra de menu, escolha **Arquivo**, **Novo**, **Projeto**.  
  
3.  Em baixo de **Instalado** no painel de modelos, escolha **Visual C\+\+**.  
  
4.  Escolha **Aplicativo de Console do Win32**, digite `AMPMapReduce` na caixa de **Nome** , e então escolha o botão **OK**.  
  
5.  Escolha o botão **Próximo**.  
  
6.  Desmarque a caixa de seleção **Cabeçalho pré\-compilado** e então escolha o botão **Concluir**.  
  
7.  Em **Gerenciador de Soluções**, delete stdafx.h, targetver.h, e stdafx.cpp do projeto.  
  
8.  Abra AMPMapReduce.cpp e substitua seu conteúdo com o código a seguir.  
  
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
        printf("sum: %s\n", passed ? "Passed!" : "Failed!");   
  
        getchar();  
  
        return 0;  
    }  
  
    ```  
  
9. Na barra de menus, escolha **Arquivo**, **Salvar Tudo**.  
  
10. No **Gerenciador de Soluções**, abra o menu de atalho para **AMPMapReduce**, e então escolha **Propriedades**.  
  
11. Na caixa de diálogo **Páginas de Propriedade** , em baixo de **Propriedades de Configuração**, escolha **C\/C\+\+**, **Cabeçalhos Pré\-Compilados**.  
  
12. Para a propriedade **Cabeçalho Pré\-compilado**, selecione **Não Usar Cabeçalhos Pré\-Compilados**e então clique no botão **OK**.  
  
13. Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
## Depurando o Código da CPU  
 Nesse procedimento, você usará o Depurador Local do Windows para certificar\-se que o código da CPU neste aplicativo está correto.  O segmento do código da CPU neste aplicativo que é especialmente interessante é o laço `for` na função `reduction_sum_gpu_kernel`.  Ele controla a redução paralela baseada em árvore que é realizada no GPU.  
  
### Para depurar o Código da CPU  
  
1.  No **Gerenciador de Soluções**, abra o menu de atalho para **AMPMapReduce**, e então escolha **Propriedades**.  
  
2.  Na caixa de diálogo **Páginas de Propriedade**, em baixo de **Propriedades de Configuração**, escolha **Depurando**.  Verifique que **Depurador Local do Windows** está selecionado na lista **Depurador a iniciar**.  
  
3.  Retorne ao editor de códigos.  
  
4.  Defina pontos de interrupção nas linhas de código mostradas na ilustração a seguir \(aproximadamente linhas 67 a 70\).  
  
     ![Pontos de interrupção da CPU](../../parallel/amp/media/campcpubreakpoints.png "CampCpuBreakpoints")  
pontos de interrupção da CPU  
  
5.  Na barra de menus, escolha **Depurar**, **Iniciar Depuração**.  
  
6.  Na janela de **Locais** , observe o valor para `stride_size` até que o ponto de interrupção na linha 70 é alcançado.  
  
7.  Na barra de menu, escolha **Depurar**, **Parar Depuração**.  
  
## Depurando o Código da GPU  
 Esta seção mostra como depurar o código da GPU, que é o código contido na função `sum_kernel_tiled`.  O código da GPU calcula a soma de inteiros para cada "bloco" em paralelo.  
  
### Para depurar o Código da GPU  
  
1.  No **Gerenciador de Soluções**, abra o menu de atalho para **AMPMapReduce**, e então escolha **Propriedades**.  
  
2.  Na caixa de diálogo **Páginas de Propriedade**, em baixo de **Propriedades de Configuração**, escolha **Depurando**.  
  
3.  Na lista **Depurador a iniciar**, selecione **Depurador Local do Windows**.  
  
4.  Na lista **Tipo de Depurador**, selecione **Somente GPU**.  
  
5.  Escolha o botão **OK**.  
  
6.  Defina um ponto de interrupção na linha 30, conforme mostrado na ilustração a seguir:  
  
     ![Pontos de interrupção GPU](../../parallel/amp/media/campgpubreakpoints.png "CampGpuBreakpoints")  
Ponto de Interrupção da GPU  
  
7.  Na barra de menus, escolha **Depurar**, **Iniciar Depuração**.  Os pontos de interrupção no código da CPU nas linhas 67 e 70 não são executados durante a depuração da GPU porque essas linhas de código são executadas na CPU.  
  
### Para usar a janela de Threads da GPU  
  
1.  Para abrir a janela de Threads da GPU, na barra de menu, escolha **Depurar**, **Janelas**, **Threads da GPU**.  
  
     Você pode inspecionar o estado dos threads da GPU na janela de Threads da GPU que aparece.  
  
2.  Encaixe a janela de Threads da GPU na parte inferior do Visual Studio.  Escolha o botão **Expandir Alternância de Thread** para exibir as caixas de texto do bloco e do thread.  A janela de Threads da GPU mostra o número total de threads ativos e bloqueados da GPU, como mostrado na ilustração a seguir:  
  
     ![Janela de Threads da GPU com 4 segmentos ativos](../../parallel/amp/media/campc.png "CampC")  
Janela de Threads da GPU  
  
     Existem 313 blocos alocados para esse cálculo.  Cada bloco contém 32 threads.  Porque a depuração local da GPU ocorre em um emulador de software, há quatro threads ativos da GPU.  Os quatro threads executam as instruções simultaneamente e então seguem juntos para a próxima instrução.  
  
     Na janela threads de GPU, há quatro threads de GPU ativas e 28 threads de GPU bloqueados instrução definida na linha de [tile\_barrier::wait](../Topic/tile_barrier::wait%20Method.md) aproximadamente 21 \(`t_idx.barrier.wait();`\).  Todos os 32 threads da GPU pertencem ao primeiro bloco, `tile[0]`.  Uma seta aponta para a linha que inclui o thread atual.  Para alternar para um thread diferente, use um dos seguintes métodos:  
  
    -   Na linha para o thread que será alternado na janela de Threads da GPU, abra o menu de atalho e escolha **Alternar Para Thread**.  Se a linha representa mais de um thread, você alternará para o primeiro thread de acordo com as coordenadas do thread.  
  
    -   Insira valores do bloco e do thread do thread nas caixas de texto correspondente e então escolha o botão **Alternar Thread**.  
  
     A janela da pilha de chamadas exibe a pilha de chamadas do thread atual da GPU.  
  
### Para usar a janela de pilhas paralelas  
  
1.  Para abrir a janela de pilhas paralelas, na barra de menu, escolha **Depurar**, **Janelas**, **Pilhas paralelas**.  
  
     Você pode usar a janela de pilhas paralelas para inspecionar simultaneamente os quadros de pilha de vários threads da GPU.  
  
2.  Encaixe a janela de Pilhas Paralelas na parte inferior do Visual Studio.  
  
3.  Certifique\-se de que **Threads** está selecionado na lista no canto superior esquerdo.  Na ilustração a seguir, a janela de Pilhas paralelas mostra uma exibição focada da pilha de chamadas dos threads da GPU que você viu na janela de Threads da GPU.  
  
     ![Janela pilhas paralelas com 4 segmentos ativos](../../parallel/amp/media/campd.png "CampD")  
Janela de Pilhas Paralelas  
  
     32 threads foram do `_kernel_stub` para a instrução lambda na chamada de função `parallel_for_each` e então para a função `sum_kernel_tiled`, onde a redução paralela ocorre. 28 de 32 threads progrediram para a declaração [tile\_barrier::wait](../Topic/tile_barrier::wait%20Method.md) e permanecem bloqueados na linha 22, enquanto os outros 4 threads permanecem ativos na função `sum_kernel_tiled` na linha 30.  
  
     Você pode inspecionar as propriedades de um thread da GPU que estão disponíveis na janela de threads da GPU no DataTip rico da janela de pilhas paralelas.  Para fazer isso, posicione o ponteiro do mouse no quadro de pilha do **sum\_kernel\_tiled**.  A ilustração a seguir mostra o DataTip.  
  
     ![DataTip janela pilhas paralelas](../../parallel/amp/media/campe.png "CampE")  
DataTip do thread da GPU  
  
     Para obter mais informações sobre a janela de pilhas paralelas, consulte [Usando a janela Pilhas Paralelas](../Topic/Using%20the%20Parallel%20Stacks%20Window.md).  
  
### Para usar a janela de inspeção paralela  
  
1.  Para abrir a janela de inspeção paralela, na barra de menu, escolha **Depurar**, **Janelas**, **Inspeção Paralela**, **inspeção paralela 1**.  
  
     Você pode usar a janela de inspeção paralela para inspecionar os valores de uma expressão através de vários threads.  
  
2.  Encaixe a janela de inspeção paralela 1 na parte inferior do Visual Studio.  Existem 32 linhas na tabela da janela de inspeção paralela.  Cada um corresponde a um thread da GPU que aparece na janela de Threads da GPU e na janela de pilhas de paralela.  Agora, você pode inserir expressões cujos valores você deseja inspecionar por todos os 32 threads da GPU.  
  
3.  Selecione o cabeçalho da coluna **Adicionar Inspeção**, digite `localIdx`, e pressione ENTER.  
  
4.  Selecione, novamente, o cabeçalho da coluna **Adicionar Inspeção**, digite `globalIdx`, e pressione ENTER.  
  
5.  Selecione, novamente, o cabeçalho da coluna **Adicionar Inspeção**, digite `localA[localIdx[0]]`, e pressione ENTER.  
  
     Você pode classificar por uma expressão específica selecionando o cabeçalho da coluna correspondente.  
  
     Selecione o cabeçalho da coluna **localA\[localIdx\[0\]\]** para classificar a coluna.  A ilustração a seguir mostra os resultados da classificação por **localA\[localIdx\[0\]\]**.  
  
     ![Janela de inspeção com resultados classificados paralelas](../../parallel/amp/media/campf.png "CampF")  
 Resultados do tipo  
  
     Você pode exportar o conteúdo na janela de Inspeção Paralela para o Excel escolhendo o botão do Excel e então **Abra no Excel**.  Se você tiver o Excel instalado no seu computador de desenvolvimento, isso abre uma planilha do excel com o conteúdo.  
  
6.  Em o canto superior direito da janela de Inspeção Paralela, há um controle de filtro que você pode usar para filtrar o conteúdo usando expressões booleanas.  Entre em `localA [localIdx [0]] > 20000` na caixa de texto do controle de filtro e escolha a tecla ENTER.  
  
     A janela contém agora somente os threads em que o valor de `localA[localIdx[0]]` é maior que 20000.  O conteúdo ainda é classificado pela coluna de `localA[localIdx[0]]` , que é a ação de classificação que você executou anteriormente.  
  
## Sinalizando Threads da GPU  
 Você pode marcar threads específicos da GPU sinalizando\-os na janela de Threads da GPU, na janela de Inspeção Paralela, ou no DataTip na janela de Pilhas Paralelas.  Se uma linha na janela de Threads da GPU contém mais de um thread, sinalizar essa linha sinaliza todos os threads que estão contidos na linha.  
  
### Para sinalizar threads da GPU  
  
1.  Selecione o cabeçalho da coluna do **\[Thread\]** na janela de Inspeção Paralela 1 para classificar por índice de bloco e índice de thread.  
  
2.  Na barra de menu, escolha **Depurar**, **Continuar**, o que faz com que os quatro threads que estão ativos progridam para a barreira seguinte \(definida na linha 32 do AMPMapReduce.cpp\).  
  
3.  Escolha o símbolo do sinalizador no lado esquerdo da linha que contém os quatro threads que agora estão ativos.  
  
     A ilustração a seguir mostra os quatro threads assinalados ativos na janela de threads da GPU.  
  
     ![Janela de Threads da GPU com threads sinalizados](../../parallel/amp/media/campg.png "CampG")  
Threads ativos na janela de Threads da GPU  
  
     A janela de Inspeção paralela e o DataTip da janela de pilhas de Paralelas indicam, ambos, os threads assinalados.  
  
4.  Se você deseja se concentra nos quatro threads que você sinalizou, você pode escolher para mostrar, nos threads da GPU, na Inspeção paralela, e na janela de pilhas paralelas, somente os threads assinalados.  
  
     Pressione o botão mostrar apenas sinalizado em qualquer uma das janelas ou na barra de ferramentas **Depurar Localização**.  A ilustração a seguir mostra o botão mostrar apenas sinalizado na barra de ferramentas **Depurar Localização**.  
  
     ![Barra de ferramentas do local com o ícone Mostrar apenas sinalizadas de depuração](../Image/CampH.png "CampH")  
Botão Mostrar Apenas Sinalizado  
  
     Agora as janelas de Threads da GPU, Inspeção Paralela, e de Pilhas Paralelas exibem somente os threads assinalados.  
  
## Congelando e Descongelando threads da GPU  
 Você pode congelar \(Suspender\) e descongelar \(Retomar\) threads da GPU a partir da janela Threads da GPU ou da janela de Inspeção Paralela.  Você pode congelar e descongelar threads da CPU da mesma forma; para mais informações, consulte [Como usar a janela Threads](../Topic/How%20to:%20Use%20the%20Threads%20Window.md).  
  
### Para congelar e descongelar threads da GPU  
  
1.  Escolha o botão **Mostrar Apenas Sinalizado** para exibir todos os threads.  
  
2.  Na barra de menu, escolha **Depurar**, **Continuar**.  
  
3.  Abra o menu de atalho para a linha ativa e então escolha **Congelar**.  
  
     A ilustração a seguir da janela de threads da GPU mostra que todos os quatro threads estão congelados.  
  
     ![Windows GPU Threads mostrando segmentos congelados](../../parallel/amp/media/campk.png "CampK")  
Threads congelados na janela de Threads da GPU  
  
     Da mesma forma, a janela de Inspeção Paralela mostra que todos os quatro threads estão congelados.  
  
4.  Na barra de menu, escolha **Depurar**, **Continuar** para permitir aos próximos quatro threads da GPU progredir após a barreira na linha 22 e atingir o ponto de interrupção na linha 30.  A janela de Threads da GPU mostra que os quatro threads congelados anteriormente permanecem congelados e em estado ativo.  
  
5.  Na barra de menu, escolha **Depurar**, **Continuar**.  
  
6.  Da janela de Inspeção Paralela, você também pode descongelar threads individuais ou múltiplos da GPU.  
  
### Para agrupar threads da GPU  
  
1.  No menu de atalho para um dos threads na janela **Threads da GPU** , escolha **Agrupar Por**, **Endereço**.  
  
     Os threads na janela de Threads da GPU são agrupados por endereço.  O endereço corresponde à instrução em desmontagem onde cada grupo de threads é localizado. 24 threads estão na linha 22, onde o [Método tile\_barrier::wait](../Topic/tile_barrier::wait%20Method.md) é executado. 12 threads estão na instrução para a barreira na linha 32.  Quatro desses threads são sinalizados.  Oito threads estão no ponto de interrupção na linha 30.  Quatro desses threads estão congelados.  A ilustração a seguir mostra os threads agrupados na janela de Threads da GPU.  
  
     ![Janela de Threads da GPU com segmentos agrupados por endereço](../../parallel/amp/media/campl.png "CampL")  
Threads agrupados na janela de Threads da GPU  
  
2.  Você também pode executar a operação **Agrupar por** abrindo o menu de atalho para a grade de dados da janela de Inspeção Paralela, escolhendo **Agrupar por** e escolhendo o item de menu que corresponde a como você deseja agrupar os threads.  
  
## Executando Todos os Threads para uma Localização Específica no Código  
 Você executa todos os threads em um determinado quadro para a linha que contém o cursor usando **Executar Bloco Atual para o Cursor**.  
  
### Para executar todos os threads para o local marcado pelo cursor  
  
1.  No menu de atalho para os threads congelados, escolha **Descongelar**.  
  
2.  No editor de códigos, coloque o cursor na linha 30.  
  
3.  No menu de atalho para o Editor de Códigos, escolha **Executar Bloco Atual para o Cursor**.  
  
     Os 24 threads que foram previamente bloqueados na barreira na linha 21 progrediram para a linha 32.  Isso é mostrado na janela **Threads da GPU**.  
  
## Consulte também  
 [Visão geral do C\+\+ AMP](../../parallel/amp/cpp-amp-overview.md)   
 [Depurando código de GPU](../Topic/Debugging%20GPU%20Code.md)   
 [Como usar a janela Threads de GPU](../Topic/How%20to:%20Use%20the%20GPU%20Threads%20Window.md)   
 [Como usar a janela Inspeção Paralela](../Topic/How%20to:%20Use%20the%20Parallel%20Watch%20Window.md)   
 [Analisando o código de AMP C\+\+ com o visualizador de simultaneidade](http://go.microsoft.com/fwlink/?LinkID=253987&clcid=0x409)