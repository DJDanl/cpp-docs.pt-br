---
title: "Passo a passo: Removendo trabalho de um Thread de Interface do usuário | Microsoft Docs"
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
helpviewer_keywords:
- user-interface threads, removing work from [Concurrency Runtime]
- removing work from user-interface threads [Concurrency Runtime]
ms.assetid: a4a65cc2-b3bc-4216-8fa8-90529491de02
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7c32613aa6938b873a820fbb491fa2c507605a6d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-removing-work-from-a-user-interface-thread"></a>Instruções passo a passo: removendo trabalho de um thread de interface de usuário
Este documento demonstra como usar o tempo de execução de simultaneidade para mover o trabalho realizado pelo thread de interface do usuário (IU) em um aplicativo do Microsoft Foundation Classes (MFC) para um thread de trabalho. Este documento também demonstra como melhorar o desempenho de uma operação demorada de desenho.  
  
 Removendo o trabalho do thread da interface do usuário ao descarregar as operações de bloqueio, por exemplo, desenho, para threads de trabalho pode melhorar a capacidade de resposta do seu aplicativo. Este passo a passo usa uma rotina de desenho que gera o fractal Mandelbrot para demonstrar uma longa operação de bloqueio. A geração do fractal Mandelbrot também é uma boa candidata para paralelização porque o cálculo de cada pixel é independente de todos os outros cálculos.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Leia os tópicos a seguir antes de iniciar esta explicação passo a passo:  
  
-   [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)  
  
-   [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
-   [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)  
  
-   [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)  
  
-   [Cancelamento no PPL](cancellation-in-the-ppl.md)  
  
 Também é recomendável que você entender os conceitos básicos do desenvolvimento de aplicativos MFC e [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)] antes de começar este passo a passo. Para obter mais informações sobre MFC, consulte [aplicativos de Desktop do MFC](../../mfc/mfc-desktop-applications.md). Para obter mais informações sobre [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)], consulte [GDI+](https://msdn.microsoft.com/en-us/library/windows/desktop/ms533798).  
  
##  <a name="top"></a>Seções  
 Este passo a passo contém as seguintes seções:  
  
-   [Criando o aplicativo do MFC](#application)  
  
-   [Implementando a versão Serial do aplicativo Mandelbrot](#serial)  
  
-   [Removendo o trabalho do Thread de Interface do usuário](#removing-work)  
  
-   [Melhorando o desempenho de desenho](#performance)  
  
-   [Adicionando suporte para cancelamento](#cancellation)  
  
##  <a name="application"></a>Criando o aplicativo do MFC  
 Esta seção descreve como criar o aplicativo básico do MFC.  
  
### <a name="to-create-a-visual-c-mfc-application"></a>Para criar um aplicativo MFC do Visual C++  
  
1.  No menu **Arquivo**, clique em **Novo** e clique em **Projeto**.  
  
2.  No **novo projeto** na caixa de **modelos instalados** painel, selecione **Visual C++**e, em seguida, no **modelos** painel, selecione **Aplicativo MFC**. Digite um nome para o projeto, por exemplo, `Mandelbrot`e, em seguida, clique em **Okey** para exibir o **Assistente de aplicativo MFC**.  
  
3.  No **tipo de aplicativo** painel, selecione **único documento**. Certifique-se de que o **suporte para a arquitetura de documento/exibição** caixa de seleção é desmarcada.  
  
4.  Clique em **concluir** para criar o projeto e fechar o **Assistente de aplicativo MFC**.  
  
     Verifique se que o aplicativo foi criado com êxito ao criar e executá-lo. Para criar o aplicativo, no **criar** menu, clique em **compilar solução**. Se o aplicativo foi criado com êxito, execute o aplicativo clicando **iniciar depuração** no **depurar** menu.  
  
##  <a name="serial"></a>Implementando a versão Serial do aplicativo Mandelbrot  
 Esta seção descreve como desenhar o fractal Mandelbrot. Esta versão desenha o fractal Mandelbrot para um [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)] [Bitmap](https://msdn.microsoft.com/library/ms534420.aspx) de objeto e, em seguida, copia o conteúdo desse bitmap para a janela do cliente.  
  
#### <a name="to-implement-the-serial-version-of-the-mandelbrot-application"></a>Para implementar a versão serial do aplicativo Mandelbrot  
  
1.  Em Stdafx. h, adicione o seguinte `#include` diretiva:  
  
     [!code-cpp[concrt-mandelbrot#1](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_1.h)]  
  
2.  Em ChildView.h, depois que o `pragma` diretiva, definir o `BitmapPtr` tipo. O `BitmapPtr` tipo permite que um ponteiro para um `Bitmap` objeto deve ser compartilhado por vários componentes. O `Bitmap` objeto é excluído quando ele não é referenciado por nenhum componente.  
  
     [!code-cpp[concrt-mandelbrot#2](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_2.h)]  
  
3.  Em ChildView.h, adicione o seguinte código para o `protected` seção o `CChildView` classe:  
  
     [!code-cpp[concrt-mandelbrot#3](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_3.h)]  
  
4.  Em ChildView.cpp, comente ou remova as linhas a seguir.  
  
     [!code-cpp[concrt-mandelbrot#4](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_4.cpp)]  
  
     Em compilações de depuração, esta etapa impede que o aplicativo que usa o `DEBUG_NEW` alocador, que é incompatível com [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)].  
  
5.  Em ChildView.cpp, adicione um `using` diretiva para o `Gdiplus` namespace.  
  
     [!code-cpp[concrt-mandelbrot#5](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_5.cpp)]  
  
6.  Adicione o seguinte código para o construtor e destruidor do `CChildView` classe para inicializar e desligar [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)].  
  
     [!code-cpp[concrt-mandelbrot#6](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_6.cpp)]  
  
7.  Implementar o método de `CChildView::DrawMandelbrot` . Esse método desenha o fractal Mandelbrot especificado `Bitmap` objeto.  
  
     [!code-cpp[concrt-mandelbrot#7](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_7.cpp)]  
  
8.  Implementar o método de `CChildView::OnPaint` . Este método chama `CChildView::DrawMandelbrot` e, em seguida, copia o conteúdo do `Bitmap` objeto para a janela.  
  
     [!code-cpp[concrt-mandelbrot#8](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_8.cpp)]  
  
9. Verifique se que o aplicativo foi atualizado com êxito ao criar e executá-lo.  
  
 A ilustração a seguir mostra os resultados do aplicativo Mandelbrot.  
  
 ![O aplicativo Mandelbrot](../../parallel/concrt/media/mandelbrot.png "mandelbrot")  
  
 Como a computação para cada pixel é dispendiosa, o thread de interface do usuário não pode processar mensagens adicionais até que a computação geral seja concluído. Isso pode reduzir a capacidade de resposta do aplicativo. No entanto, você pode aliviar esse problema removendo o trabalho do thread da interface do usuário.  
  
 [[Superior](#top)]  
  
##  <a name="removing-work"></a>Removendo o trabalho do Thread da interface do usuário  
 Esta seção mostra como remover o trabalho de desenho do thread da interface do usuário no aplicativo Mandelbrot. Ao mover o trabalho de desenho do thread da interface do usuário para um thread de trabalho, o thread de interface do usuário pode processar mensagens, como o thread de trabalho gera a imagem em segundo plano.  
  
 O tempo de execução de simultaneidade fornece três maneiras de executar tarefas: [grupos de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md), [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md), e [tarefas leves](../../parallel/concrt/task-scheduler-concurrency-runtime.md). Embora você possa usar qualquer um desses mecanismos para remover o trabalho do thread da interface do usuário, este exemplo usa um [concurrency::task_group](reference/task-group-class.md) porque a grupos de tarefas oferece suporte ao cancelamento. Posteriormente, este passo a passo usa cancelamento para reduzir a quantidade de trabalho que é executada quando a janela do cliente é redimensionada e para executar a limpeza quando a janela é destruída.  
  
 Este exemplo também usa um [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) objeto para permitir que o thread de interface do usuário e o thread de trabalho para se comunicar uns com os outros. Depois que o thread de trabalho produz a imagem, ele envia um ponteiro para o `Bitmap` o objeto para o `unbounded_buffer` do objeto e, em seguida, envia uma mensagem de pintura para o thread de interface do usuário. Em seguida, recebe o thread de interface do usuário da `unbounded_buffer` objeto o `Bitmap` de objeto e desenha a janela do cliente.  
  
#### <a name="to-remove-the-drawing-work-from-the-ui-thread"></a>Para remover o trabalho de desenho do thread da interface do usuário  
  
1.  Em Stdafx. h, adicione o seguinte `#include` diretivas:  
  
     [!code-cpp[concrt-mandelbrot#101](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_9.h)]  
  
2.  Em ChildView.h, adicione `task_group` e `unbounded_buffer` variáveis de membro para o `protected` seção o `CChildView` classe. O `task_group` objeto contém as tarefas que executam desenho; o `unbounded_buffer` objeto contém a imagem Mandelbrot concluída.  
  
     [!code-cpp[concrt-mandelbrot#102](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_10.h)]  
  
3.  Em ChildView.cpp, adicione um `using` diretiva para o `concurrency` namespace.  
  
     [!code-cpp[concrt-mandelbrot#103](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_11.cpp)]  
  

4.  No `CChildView::DrawMandelbrot` método, após a chamada a `Bitmap::UnlockBits`, chame o [concurrency::send](reference/concurrency-namespace-functions.md#send) função para passar o `Bitmap` objeto para o thread de interface do usuário. Em seguida, enviar uma mensagem de pintura para o thread de interface do usuário e invalidar a área cliente.  

  
     [!code-cpp[concrt-mandelbrot#104](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_12.cpp)]  
  
5.  Atualização de `CChildView::OnPaint` método para receber a atualização `Bitmap` do objeto e desenhar a imagem para a janela do cliente.  
  
     [!code-cpp[concrt-mandelbrot#105](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_13.cpp)]  
  
     O `CChildView::OnPaint` método cria uma tarefa para gerar a imagem Mandelbrot se não existir no buffer de mensagem. O buffer de mensagem não conterá uma `Bitmap` objeto em casos como a mensagem de pintura inicial e a outra janela é movida na frente da janela do cliente.  
  
6.  Verifique se que o aplicativo foi atualizado com êxito ao criar e executá-lo.  
  
 A interface do usuário agora está mais respondendo porque o trabalho de desenho é executado em segundo plano.  
  
 [[Superior](#top)]  
  
##  <a name="performance"></a>Melhorando o desempenho de desenho  

 A geração do fractal Mandelbrot é uma boa candidata para paralelização porque o cálculo de cada pixel é independente de todos os outros cálculos. Para colocar em paralelo, o procedimento de desenho, converter externa `for` loop no `CChildView::DrawMandelbrot` método para uma chamada para o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo, da seguinte maneira.  

  
 [!code-cpp[concrt-mandelbrot#301](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_14.cpp)]  
  
 Como a computação de cada elemento de bitmap é independente, você não precisa sincronizar as operações de desenho que acessam a memória de bitmap. Isso permite que o desempenho ao expandir conforme o número de processadores disponíveis.  
  
 [[Superior](#top)]  
  
##  <a name="cancellation"></a>Adicionando suporte para cancelamento  
 Esta seção descreve como tratar o redimensionamento de janela e como cancelar quaisquer tarefas de desenho ativas quando a janela é destruída.  
  
 O documento [cancelamento no PPL](cancellation-in-the-ppl.md) explica como funciona o cancelamento no tempo de execução. Cancelamento for cooperativo; Portanto, ele não ocorre imediatamente. Para interromper uma tarefa cancelada, o tempo de execução lança uma exceção interna durante uma chamada subsequente da tarefa no tempo de execução. A seção anterior mostra como usar o `parallel_for` algoritmo para melhorar o desempenho da tarefa desenho. A chamada para `parallel_for` permite que o tempo de execução interromper a tarefa e, portanto, permite o cancelamento de trabalho.  
  
### <a name="cancelling-active-tasks"></a>Cancelar tarefas ativas  
 Cria o aplicativo Mandelbrot `Bitmap` objetos cujas dimensões correspondem ao tamanho da janela do cliente. Toda vez que a janela do cliente é redimensionada, o aplicativo cria uma tarefa de plano de fundo adicional para gerar uma imagem para o novo tamanho da janela. O aplicativo não exigir essas imagens intermediárias; ela exige apenas a imagem para o tamanho da janela final. Para impedir que o aplicativo executar este trabalho adicional, você pode cancelar quaisquer tarefas de desenho ativas nos manipuladores de mensagem para o `WM_SIZE` e `WM_SIZING` mensagens e, em seguida, desenho de reagendar trabalham depois que a janela é redimensionada.  
  
 Para cancelar tarefas ativas de desenho quando a janela é redimensionada, o aplicativo chama o [concurrency::task_group::cancel](reference/task-group-class.md#cancel) método em manipuladores para o `WM_SIZING` e `WM_SIZE` mensagens. O manipulador para o `WM_SIZE` mensagem também chama o [concurrency::task_group::wait](reference/task-group-class.md#wait) método aguardar ativa todas as tarefas para concluir e reagenda, em seguida, a tarefa de desenho para o tamanho da janela atualizado.  
  
 Quando a janela do cliente é destruída, é uma boa prática para cancelar as tarefas de desenho ativas. Cancelar quaisquer tarefas ativas de desenho certifica-se de que os threads de trabalho não lançar mensagens para o thread de interface do usuário depois que a janela do cliente é destruída. O aplicativo cancela quaisquer tarefas ativas de desenho no manipulador para o `WM_DESTROY` mensagem.  
  
### <a name="responding-to-cancellation"></a>Responder ao cancelamento  
 O `CChildView::DrawMandelbrot` método, que executa a tarefa de desenho, deve responder ao cancelamento. Como o tempo de execução usa o tratamento de exceções para cancelar as tarefas, o `CChildView::DrawMandelbrot` método deve usar um mecanismo de exceção de segurança para garantir que todos os recursos estão corretamente limpas. Este exemplo usa o *recurso aquisição é inicialização* padrão (RAII) para garantir que os bits de bitmap sejam desbloqueados quando a tarefa foi cancelada.  
  
##### <a name="to-add-support-for-cancellation-in-the-mandelbrot-application"></a>Para adicionar suporte para cancelamento do aplicativo Mandelbrot  
  
1.  Em ChildView.h, no `protected` seção o `CChildView` da classe, adicione declarações para o `OnSize`, `OnSizing`, e `OnDestroy` funções de mapa de mensagem.  
  
     [!code-cpp[concrt-mandelbrot#201](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_15.h)]  
  
2.  Em ChildView.cpp, modifique o mapa de mensagem para conter os manipuladores para o `WM_SIZE`, `WM_SIZING`, e `WM_DESTROY` mensagens.  
  
     [!code-cpp[concrt-mandelbrot#202](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_16.cpp)]  
  
3.  Implementar o método de `CChildView::OnSizing` . Esse método cancela quaisquer tarefas de desenho existentes.  
  
     [!code-cpp[concrt-mandelbrot#203](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_17.cpp)]  
  
4.  Implementar o método de `CChildView::OnSize` . Esse método cancela quaisquer tarefas de desenho existentes e cria uma nova tarefa de desenho para o tamanho da janela de cliente atualizado.  
  
     [!code-cpp[concrt-mandelbrot#204](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_18.cpp)]  
  
5.  Implementar o método de `CChildView::OnDestroy` . Esse método cancela quaisquer tarefas de desenho existentes.  
  
     [!code-cpp[concrt-mandelbrot#205](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_19.cpp)]  
  
6.  No ChildView.cpp, defina o `scope_guard` classe que implementa o padrão RAII.  
  
     [!code-cpp[concrt-mandelbrot#206](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_20.cpp)]  
  
7.  Adicione o seguinte código para o `CChildView::DrawMandelbrot` método após a chamada a `Bitmap::LockBits`:  
  
     [!code-cpp[concrt-mandelbrot#207](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_21.cpp)]  
  
     Esse código manipula cancelamento criando um `scope_guard` objeto. Quando o objeto sai do escopo, ele desbloqueia os bits de bitmap.  
  
8.  Modificar o fim do `CChildView::DrawMandelbrot` método para ignorar o `scope_guard` após os bits de bitmap são desbloqueados, mas antes que as mensagens são enviadas para o thread de interface do usuário do objeto. Isso garante que o thread de interface do usuário não é atualizado antes dos bits de bitmap sejam desbloqueados.  
  
     [!code-cpp[concrt-mandelbrot#208](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_22.cpp)]  
  
9. Verifique se que o aplicativo foi atualizado com êxito ao criar e executá-lo.  
  
 Quando você redimensiona a janela, desenho de trabalho é executada somente para o tamanho da janela final. Quaisquer tarefas ativas de desenho também são canceladas quando a janela é destruída.  
  
 [[Superior](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Explicações passo a passo de tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)   
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md)   
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Cancelamento no PPL](cancellation-in-the-ppl.md)   
 [Aplicativos da área de trabalho MFC](../../mfc/mfc-desktop-applications.md)
