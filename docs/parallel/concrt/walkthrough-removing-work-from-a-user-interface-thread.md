---
title: "Instru&#231;&#245;es passo a passo: removendo trabalho de um thread de interface de usu&#225;rio | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "removendo trabalho de threads de interface de usuário [Tempo de Execução de Simultaneidade]"
  - "threads de interface de usuário, removendo trabalho de [Tempo de Execução de Simultaneidade]"
ms.assetid: a4a65cc2-b3bc-4216-8fa8-90529491de02
caps.latest.revision: 14
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: removendo trabalho de um thread de interface de usu&#225;rio
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento demonstra como usar o tempo de execução de simultaneidade para mover o trabalho executado por thread de \(UI\) da interface do usuário em um aplicativo \(MFC\) de classes do Microsoft a um thread de trabalho.  Este documento também demonstra como melhorar o desempenho de uma operação demorada de desenho.  
  
 Removendo o trabalho do thread de interface do usuário descarregando operações de bloqueio, por exemplo, desenhar, a threads de trabalho pode melhorar a capacidade de resposta de seu aplicativo.  Este passo a passo usa uma rotina de desenho que gerencia o fractal de Mandelbrot para demonstrar uma operação demorada de bloqueio.  A geração de fractal de Mandelbrot também é uma boa candidata para o parallelization porque a computação de cada x é independente de todas computações restantes.  
  
## Pré-requisitos  
 Leia os tópicos a seguir antes de começar este passo a passo:  
  
-   [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)  
  
-   [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
-   [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)  
  
-   [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)  
  
-   [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)  
  
 Recomendamos também incluem os fundamentos de desenvolvimento de aplicativos e MFC [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)] antes de começar este passo a passo.  Para obter mais informações sobre MFC, consulte [Aplicativos para desktop do MFC](../../mfc/mfc-desktop-applications.md).  Para obter mais informações sobre como [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)], consulte [GDI\+](_gdiplus_GDI_start_cpp).  
  
##  <a name="top"></a> Seções  
 Essa explicação passo a passo contém as seguintes seções:  
  
-   [Criando o aplicativo MFC](#application)  
  
-   [Implementando a versão do aplicativo de Mandelbrot serial](#serial)  
  
-   [Removendo o trabalho do thread da interface do usuário](#removing-work)  
  
-   [Aprimorando o desempenho de desenho](#performance)  
  
-   [Adicionando suporte para o cancelamento](#cancellation)  
  
##  <a name="application"></a> Criando o aplicativo MFC  
 Esta seção descreve como criar o aplicativo básico de MFC.  
  
### Para criar um aplicativo de MFC do Visual C\+\+  
  
1.  No menu **Arquivo**, clique em **Novo** e em **Projeto**.  
  
2.  Na caixa de diálogo de **Novo Projeto** , no painel de **Modelos Instalados** , **Visual C\+\+**selecione e, em seguida, no painel de **Modelos** , **Aplicativo do MFC**selecione.  Digite um nome para o projeto, por exemplo, `Mandelbrot`, e clique em **OK** para exibir **Assistente para Aplicativo do MFC**.  
  
3.  No painel de **Tipo de Aplicativo** , **Único documento**selecione.  Verifique se a caixa de seleção de **Suporte à arquitetura do documento\/exibição** está desmarcada.  
  
4.  Clique **Concluir** para criar o projeto e fechar **Assistente para Aplicativo do MFC**.  
  
     Verifique se o aplicativo foi criado com êxito criando e executando o.  Para criar o aplicativo de **Compilar** , no menu, clique em **Compilar solução**.  Se o aplicativo compila com êxito, execute o aplicativo **Iniciar Depuração** clicando em no menu de **Depurar** .  
  
##  <a name="serial"></a> Implementando a versão do aplicativo de Mandelbrot serial  
 Esta seção descreve como desenhar o fractal de Mandelbrot.  Esta versão desenha o fractal de Mandelbrot a um objeto de [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)][Bitmap](https://msdn.microsoft.com/en-us/library/ms534420.aspx) e copia o conteúdo desse bitmap para a janela do cliente.  
  
#### Para implementar a versão do aplicativo de Mandelbrot serial  
  
1.  Em stdafx.h, adicione a seguinte política de `#include` :  
  
     [!code-cpp[concrt-mandelbrot#1](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_1.h)]  
  
2.  Em ChildView.h, depois da política de `pragma` , defina o tipo de `BitmapPtr` .  O tipo de `BitmapPtr` habilita um ponteiro para um objeto de `Bitmap` a ser compartilhado por vários componentes do.  O objeto de `Bitmap` será excluído quando não é referenciado por qualquer componente.  
  
     [!code-cpp[concrt-mandelbrot#2](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_2.h)]  
  
3.  Em ChildView.h, adicione o seguinte código na seção de `protected` da classe de `CChildView` :  
  
     [!code-cpp[concrt-mandelbrot#3](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_3.h)]  
  
4.  Em ChildView.cpp, faça comentários para fora ou remova as seguintes linhas.  
  
     [!code-cpp[concrt-mandelbrot#4](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_4.cpp)]  
  
     Em construções de depuração, essa etapa impedirá que o aplicativo use o alocador de `DEBUG_NEW` , que é incompatível com [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)].  
  
5.  Em ChildView.cpp, adicionar uma política de `using` ao namespace de `Gdiplus` .  
  
     [!code-cpp[concrt-mandelbrot#5](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_5.cpp)]  
  
6.  Adicione o seguinte código para o construtor e o destruidor da classe de `CChildView` para inicializar e fechar [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)].  
  
     [!code-cpp[concrt-mandelbrot#6](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_6.cpp)]  
  
7.  Implemente o método `CChildView::DrawMandelbrot`.  Esse método desenha o fractal de Mandelbrot ao objeto especificado de `Bitmap` .  
  
     [!code-cpp[concrt-mandelbrot#7](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_7.cpp)]  
  
8.  Implemente o método `CChildView::OnPaint`.  Esse método chama `CChildView::DrawMandelbrot` e copia o conteúdo do objeto de `Bitmap` à janela.  
  
     [!code-cpp[concrt-mandelbrot#8](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_8.cpp)]  
  
9. Verifique se o aplicativo seja atualizado com êxito criando e executando o.  
  
 A ilustração a seguir mostra os resultados do aplicativo de Mandelbrot.  
  
 ![O aplicativo de Mandelbrot](../Image/Mandelbrot.png "Mandelbrot")  
  
 Como a computação para cada x é computacionalmente dispendiosa, o thread de interface do usuário não pode processar mensagens adicionais até que a computação total seja concluída.  Isso pode diminuir a capacidade de resposta no aplicativo.  Porém, você pode reduzir esse problema removendo o trabalho do thread de interface do usuário.  
  
 \[[Superior](#top)\]  
  
##  <a name="removing-work"></a> Removendo o trabalho do thread de interface do usuário  
 Esta seção mostra como remover o trabalho de desenho do thread de interface de usuário no aplicativo de Mandelbrot.  Movendo o trabalho de desenho do thread de interface do usuário a um thread de trabalho, o thread de interface do usuário pode processar mensagens enquanto o thread de trabalho gerencia a imagem em segundo plano.  
  
 O tempo de execução de simultaneidade fornece três maneiras de executar tarefas: [grupos de trabalho](../../parallel/concrt/task-parallelism-concurrency-runtime.md), [agentes assíncronas](../../parallel/concrt/asynchronous-agents.md), e [tarefas de peso leve](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  Embora você possa usar qualquer um desses mecanismos para remover o trabalho do thread de interface do usuário, esse exemplo usa um objeto de [concurrency::task\_group](../Topic/task_group%20Class.md) porque os grupos de trabalho dão suporte ao cancelamento.  Este passo a passo usa posteriormente em cancelar para reduzir a quantidade de trabalho executado quando a janela do cliente é redimensionada, e para executar a limpeza quando a janela é destruída.  
  
 Este exemplo também usa um objeto de [concurrency::unbounded\_buffer](../Topic/unbounded_buffer%20Class.md) para habilitar o thread de interface do usuário e o thread de trabalho para comunicação entre si.  Depois que o thread de trabalho gerencia a imagem, envia um ponteiro para o objeto de `Bitmap` ao objeto de `unbounded_buffer` e então envia uma mensagem de pintura para o thread de interface do usuário.  O thread de interface do usuário pega do objeto de `unbounded_buffer` o objeto de `Bitmap` e desenhar\-lo à janela do cliente.  
  
#### Para remover o trabalho de desenho da interface do usuário executável  
  
1.  Em stdafx.h, adicione as políticas de `#include` :  
  
     [!code-cpp[concrt-mandelbrot#101](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_9.h)]  
  
2.  Em ChildView.h, adicione `task_group` e variáveis do membro de `unbounded_buffer` a seção de `protected` de `CChildView` classe.  O objeto de `task_group` contém as tarefas que executam o desenho; o objeto de `unbounded_buffer` contém a imagem concluída de Mandelbrot.  
  
     [!code-cpp[concrt-mandelbrot#102](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_10.h)]  
  
3.  Em ChildView.cpp, adicionar uma política de `using` ao namespace de `concurrency` .  
  
     [!code-cpp[concrt-mandelbrot#103](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_11.cpp)]  
  
4.  No método de `CChildView::DrawMandelbrot` , depois da chamada a `Bitmap::UnlockBits`, chame a função de [concurrency::send](../Topic/send%20Function.md) para passe o objeto de `Bitmap` ao thread de interface do usuário.  Em postar uma mensagem de pintura para o thread de interface do usuário e invalide a área do cliente.  
  
     [!code-cpp[concrt-mandelbrot#104](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_12.cpp)]  
  
5.  Atualizar o método de `CChildView::OnPaint` para receber o objeto atualizado de `Bitmap` e para desenhar a imagem à janela do cliente.  
  
     [!code-cpp[concrt-mandelbrot#105](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_13.cpp)]  
  
     O método de `CChildView::OnPaint` cria uma tarefa gerar a imagem de Mandelbrot se não existir uma no buffer de mensagem.  O buffer de mensagem não conterá um objeto de `Bitmap` em casos como a mensagem inicial de pintura e a outra janela é movida na frente da janela do cliente.  
  
6.  Verifique se o aplicativo seja atualizado com êxito criando e executando o.  
  
 Interface do usuário é agora mais respondente porque o trabalho de desenho é executado em segundo plano.  
  
 \[[Superior](#top)\]  
  
##  <a name="performance"></a> Aprimorando o desempenho de desenho  
 A geração de fractal de Mandelbrot é uma boa candidata para o parallelization porque a computação de cada x é independente de todas computações restantes.  Para parallelize o procedimento de desenho, converta o loop externo de `for` no método de `CChildView::DrawMandelbrot` a uma chamada para o algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) , como a seguir.  
  
 [!code-cpp[concrt-mandelbrot#301](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_14.cpp)]  
  
 Como a computação de cada elemento de bitmap é independente, não é necessário sincronizar as operações de desenho que acessam a memória de bitmap.  Isso permite que o desempenho para dimensionar à medida que o número de processadores disponíveis aumenta.  
  
 \[[Superior](#top)\]  
  
##  <a name="cancellation"></a> Adicionando suporte para o cancelamento  
 Esta seção descreve como controlar a janela que é redimensionado e como cancelar todas as tarefas ativas de desenho quando a janela é destruída.  
  
 O documento [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md) explica como cancelar o trabalha em tempo de execução.  O cancelamento é cooperativo; consequentemente, não acontecerá imediatamente.  Para parar uma tarefa cancelada, o tempo de execução gerará uma exceção interna durante uma chamada subsequente da tarefa no tempo de execução.  A seção anterior mostra como usar o algoritmo de `parallel_for` para melhorar o desempenho da tarefa de desenho.  A chamada para `parallel_for` permite que o tempo de execução para interromper a tarefa consequentemente, e permite o cancelamento para trabalhar.  
  
### Cancelando tarefas ativas  
 O aplicativo de Mandelbrot cria os objetos de `Bitmap` cujas dimensões correspondem ao tamanho da janela do cliente.  Cada vez que a janela do cliente é redimensionada, o aplicativo cria uma tarefa em segundo plano adicional gerar uma imagem para o tamanho da janela nova.  O aplicativo não exigir essas imagens intermediários; requer apenas a imagem para o tamanho final da janela.  Para impedir que o aplicativo execute esse trabalho adicional, poderá cancelar todas as tarefas ativas de desenho nos manipuladores de mensagem para mensagens de `WM_SIZE` e de `WM_SIZING` e depois reagendar o trabalho de desenho depois que a janela é redimensionada.  
  
 Para cancelar tarefas ativas de desenho quando a janela é redimensionada, o aplicativo chama o método de [concurrency::task\_group::cancel](../Topic/task_group::cancel%20Method.md) nos manipuladores para as mensagens de `WM_SIZING` e de `WM_SIZE` .  O manipulador para a mensagem de `WM_SIZE` também chamará o método de [concurrency::task\_group::wait](../Topic/task_group::wait%20Method.md) a esperar para concluir todas as tarefas ativas e reagendar na tarefa de desenho para o tamanho atualizado da janela.  
  
 Quando a janela do cliente é destruída, é uma prática recomendada para cancelar todas as tarefas ativas de desenho.  Cancelar todas as tarefas ativas de desenho assegura que os threads de trabalho não postam mensagens ao thread de interface do usuário depois que a janela do cliente é destruída.  O aplicativo cancela todas as tarefas ativas de desenho do manipulador da mensagem de `WM_DESTROY` .  
  
### Resposta ao cancelamento  
 O método de `CChildView::DrawMandelbrot` , que executa a tarefa de desenho, deve responder a ser cancelado.  Como o tempo de execução usa a manipulação de exceção para cancelar tarefas, o método de `CChildView::DrawMandelbrot` deve usar exceções gerais um mecanismo seguro para garantir que todos os recursos são limpos corretamente.  Este exemplo usa o padrão *Aquisição de recurso é inicialização* \(RAII\) para garantir que os bits de bitmap são desbloqueados quando a tarefa é cancelada.  
  
##### Para adicionar suporte para o cancelamento do aplicativo de Mandelbrot  
  
1.  Em ChildView.h, na seção de `protected` da classe de `CChildView` , adicione instruções para `OnSize`, `OnSizing`, e funções do mapa da mensagem de `OnDestroy` .  
  
     [!code-cpp[concrt-mandelbrot#201](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_15.h)]  
  
2.  Em ChildView.cpp, modifique o mapa de mensagem para manipuladores para conter `WM_SIZE`, `WM_SIZING`, e mensagens de `WM_DESTROY` .  
  
     [!code-cpp[concrt-mandelbrot#202](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_16.cpp)]  
  
3.  Implemente o método `CChildView::OnSizing`.  Esse método cancela todas as tarefas existentes de desenho.  
  
     [!code-cpp[concrt-mandelbrot#203](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_17.cpp)]  
  
4.  Implemente o método `CChildView::OnSize`.  Esse método cancela todas as tarefas existentes de desenho e crie uma nova tarefa de desenho para o tamanho atualizado da janela do cliente.  
  
     [!code-cpp[concrt-mandelbrot#204](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_18.cpp)]  
  
5.  Implemente o método `CChildView::OnDestroy`.  Esse método cancela todas as tarefas existentes de desenho.  
  
     [!code-cpp[concrt-mandelbrot#205](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_19.cpp)]  
  
6.  Em ChildView.cpp, defina a classe de `scope_guard` , que implementa o padrão de RAII.  
  
     [!code-cpp[concrt-mandelbrot#206](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_20.cpp)]  
  
7.  Adicione o seguinte código para o método de `CChildView::DrawMandelbrot` depois da chamada a `Bitmap::LockBits`:  
  
     [!code-cpp[concrt-mandelbrot#207](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_21.cpp)]  
  
     Esse código trata o cancelamento criando um objeto de `scope_guard` .  Quando as folhas objeto do escopo, desbloqueia os bits de bitmap.  
  
8.  Modifique o final do método de `CChildView::DrawMandelbrot` para ignorar o objeto de `scope_guard` depois que os bits de bitmap são desbloqueados, mas antes de todas as mensagens sejam enviadas ao thread de interface do usuário.  Isso assegura que o thread de interface do usuário não seja atualizado antes que os bits de bitmap sejam desbloqueados.  
  
     [!code-cpp[concrt-mandelbrot#208](../../parallel/concrt/codesnippet/CPP/walkthrough-removing-work-from-a-user-interface-thread_22.cpp)]  
  
9. Verifique se o aplicativo seja atualizado com êxito criando e executando o.  
  
 Quando você redimensionar a janela, para desenhar o trabalho será executado apenas para o tamanho final da janela.  Todas as tarefas ativas de desenho são canceladas também quando a janela é destruída.  
  
 \[[Superior](#top)\]  
  
## Consulte também  
 [Instruções passo a passo do Tempo de Execução de Simultaneidade](../Topic/Concurrency%20Runtime%20Walkthroughs.md)   
 [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)   
 [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)   
 [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)   
 [Aplicativos para desktop do MFC](../../mfc/mfc-desktop-applications.md)