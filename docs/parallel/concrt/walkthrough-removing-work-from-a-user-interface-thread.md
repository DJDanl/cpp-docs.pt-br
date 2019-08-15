---
title: 'Passo a passo: Removendo o trabalho de um thread de interface do usuário'
ms.date: 04/25/2019
helpviewer_keywords:
- user-interface threads, removing work from [Concurrency Runtime]
- removing work from user-interface threads [Concurrency Runtime]
ms.assetid: a4a65cc2-b3bc-4216-8fa8-90529491de02
ms.openlocfilehash: 214796777968c8aec7116a848e791aeef0d3af7b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512257"
---
# <a name="walkthrough-removing-work-from-a-user-interface-thread"></a>Passo a passo: Removendo o trabalho de um thread de interface do usuário

Este documento demonstra como usar o Tempo de Execução de Simultaneidade para mover o trabalho que é executado pelo thread da interface do usuário (IU) em um aplicativo MFC (MFC) para um thread de trabalho. Este documento também demonstra como melhorar o desempenho de uma operação de desenho demorada.

Remover o trabalho do thread da interface do usuário descarregando operações de bloqueio, por exemplo, o desenho, para threads de trabalho pode melhorar a capacidade de resposta do seu aplicativo. Esta instrução usa uma rotina de desenho que gera o fractal Mandelbrot para demonstrar uma operação de bloqueio demorada. A geração do fractal Mandelbrot também é um bom candidato para paralelização porque a computação de cada pixel é independente de todos os outros cálculos.

## <a name="prerequisites"></a>Pré-requisitos

Leia os tópicos a seguir antes de iniciar este passo a passos:

- [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

- [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)

- [Cancelamento no PPL](cancellation-in-the-ppl.md)

Também recomendamos que você entenda os conceitos básicos do desenvolvimento de aplicativos do MFC e do GDI+ antes de iniciar este guia. Para obter mais informações sobre MFC, consulte [aplicativos de área de trabalho do MFC](../../mfc/mfc-desktop-applications.md). Para obter mais informações sobre o GDI+, consulte [GDI+](/windows/win32/gdiplus/-gdiplus-gdi-start).

##  <a name="top"></a>As

Este passo a passo contém as seguintes seções:

- [Criando o aplicativo MFC](#application)

- [Implementando a versão serial do aplicativo Mandelbrot](#serial)

- [Removendo o trabalho do thread da interface do usuário](#removing-work)

- [Melhorando o desempenho do desenho](#performance)

- [Adicionando suporte para cancelamento](#cancellation)

##  <a name="application"></a>Criando o aplicativo MFC

Esta seção descreve como criar o aplicativo básico do MFC.

### <a name="to-create-a-visual-c-mfc-application"></a>Para criar um aplicativo C++ do Visual MFC

1. Use o **Assistente de aplicativo MFC** para criar um aplicativo MFC com todas as configurações padrão. Confira [Passo a passo: Usando os novos controles](../../mfc/walkthrough-using-the-new-mfc-shell-controls.md) do shell do MFC para obter instruções sobre como abrir o assistente para sua versão do Visual Studio.

1. Digite um nome para o projeto, por exemplo `Mandelbrot`, e clique em **OK** para exibir o assistente de aplicativo do **MFC**.

1. No painel **tipo de aplicativo** , selecione **documento único**. Verifique se a caixa de seleção **suporte à arquitetura de documento/exibição** está desmarcada.

1. Clique em **concluir** para criar o projeto e fechar o **Assistente de aplicativo do MFC**.

   Verifique se o aplicativo foi criado com êxito criando-o e executando-o. Para criar o aplicativo, no menu **Compilar** , clique em **Compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo clicando em **Iniciar Depuração** no menu **depurar** .

##  <a name="serial"></a>Implementando a versão serial do aplicativo Mandelbrot

Esta seção descreve como desenhar o fractal Mandelbrot. Essa versão desenha o fractal Mandelbrot para um objeto de [bitmap](/windows/win32/api/gdiplusheaders/nl-gdiplusheaders-bitmap) do GDI+ e, em seguida, copia o conteúdo desse bitmap para a janela do cliente.

#### <a name="to-implement-the-serial-version-of-the-mandelbrot-application"></a>Para implementar a versão serial do aplicativo Mandelbrot

1. Em stdafx. h, adicione a seguinte `#include` diretiva:

   [!code-cpp[concrt-mandelbrot#1](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_1.h)]

1. Em ChildView. h, após a `pragma` diretiva, defina o `BitmapPtr` tipo. O `BitmapPtr` tipo permite que um ponteiro para `Bitmap` um objeto seja compartilhado por vários componentes. O `Bitmap` objeto é excluído quando não é mais referenciado por nenhum componente.

   [!code-cpp[concrt-mandelbrot#2](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_2.h)]

1. Em ChildView. h, adicione o seguinte código à `protected` seção `CChildView` da classe:

   [!code-cpp[concrt-mandelbrot#3](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_3.h)]

1. Em ChildView. cpp, comente ou remova as linhas a seguir.

   [!code-cpp[concrt-mandelbrot#4](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_4.cpp)]

   Em compilações de depuração, esta etapa impede que o aplicativo `DEBUG_NEW` use o alocador, que é incompatível com o GDI+.

1. Em ChildView. cpp, adicione uma `using` diretiva `Gdiplus` ao namespace.

   [!code-cpp[concrt-mandelbrot#5](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_5.cpp)]

1. Adicione o código a seguir ao construtor e ao destruidor da `CChildView` classe para inicializar e desligar o GDI+.

   [!code-cpp[concrt-mandelbrot#6](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_6.cpp)]

1. Implementar o método de `CChildView::DrawMandelbrot` . Esse método desenha o fractal Mandelbrot para o objeto `Bitmap` especificado.

   [!code-cpp[concrt-mandelbrot#7](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_7.cpp)]

1. Implementar o método de `CChildView::OnPaint` . Esse método chama `CChildView::DrawMandelbrot` e, em seguida, copia o `Bitmap` conteúdo do objeto para a janela.

   [!code-cpp[concrt-mandelbrot#8](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_8.cpp)]

1. Verifique se o aplicativo foi atualizado com êxito criando-o e executando-o.

A ilustração a seguir mostra os resultados do aplicativo Mandelbrot.

![O aplicativo Mandelbrot](../../parallel/concrt/media/mandelbrot.png "O aplicativo Mandelbrot")

Como o cálculo de cada pixel é computacionalmente caro, o thread da interface do usuário não pode processar mensagens adicionais até que a computação geral seja concluída. Isso pode diminuir a capacidade de resposta no aplicativo. No entanto, você pode aliviar esse problema removendo o trabalho do thread da interface do usuário.

[[Superior](#top)]

##  <a name="removing-work"></a>Removendo o trabalho do thread da interface do usuário

Esta seção mostra como remover o trabalho de desenho do thread da interface do usuário no aplicativo Mandelbrot. Ao mover o trabalho de desenho do thread da interface do usuário para um thread de trabalho, o thread da interface do usuário pode processar mensagens à medida que o thread de trabalho gera a imagem em segundo plano.

O Tempo de Execução de Simultaneidade fornece três maneiras de executar tarefas: [grupos de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md), [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)e [tarefas leves](../../parallel/concrt/task-scheduler-concurrency-runtime.md). Embora você possa usar qualquer um desses mecanismos para remover o trabalho do thread da interface do usuário, este exemplo usa um objeto [Concurrency:: task_group](reference/task-group-class.md) porque os grupos de tarefas dão suporte ao cancelamento. Posteriormente, esse passo a passos usa o cancelamento para reduzir a quantidade de trabalho que é executada quando a janela do cliente é redimensionada e para executar a limpeza quando a janela é destruída.

Este exemplo também usa um objeto [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) para permitir que o thread da interface do usuário e o thread de trabalho se comuniquem entre si. Depois que o thread de trabalho produz a imagem, ele envia um ponteiro `Bitmap` para o objeto `unbounded_buffer` para o objeto e, em seguida, posta uma mensagem de pintura no thread da interface do usuário. O thread da interface do usuário recebe `unbounded_buffer` do objeto `Bitmap` o objeto e o desenha na janela do cliente.

#### <a name="to-remove-the-drawing-work-from-the-ui-thread"></a>Para remover o trabalho de desenho do thread da interface do usuário

1. Em stdafx. h, adicione as seguintes `#include` diretivas:

   [!code-cpp[concrt-mandelbrot#101](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_9.h)]

1. Em ChildView. h, adicione `task_group` e `unbounded_buffer` variáveis de membro `CChildView` à `protected` seção da classe. O `task_group` objeto contém as tarefas que executam o desenho `unbounded_buffer` ; o objeto contém a imagem Mandelbrot concluída.

   [!code-cpp[concrt-mandelbrot#102](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_10.h)]

1. Em ChildView. cpp, adicione uma `using` diretiva `concurrency` ao namespace.

   [!code-cpp[concrt-mandelbrot#103](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_11.cpp)]

1. No método, após a chamada para `Bitmap::UnlockBits`, chame a função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) para passar o `Bitmap` objeto para o thread da interface do usuário. `CChildView::DrawMandelbrot` Em seguida, poste uma mensagem de pintura no thread da interface do usuário e invalida a área do cliente.

   [!code-cpp[concrt-mandelbrot#104](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_12.cpp)]

1. Atualize o `CChildView::OnPaint` método para receber o objeto `Bitmap` atualizado e desenhe a imagem na janela do cliente.

   [!code-cpp[concrt-mandelbrot#105](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_13.cpp)]

   O `CChildView::OnPaint` método cria uma tarefa para gerar a imagem Mandelbrot se ela não existir no buffer de mensagens. O buffer de mensagens não conterá `Bitmap` um objeto em casos como a mensagem inicial de pintura e quando outra janela for movida na frente da janela do cliente.

1. Verifique se o aplicativo foi atualizado com êxito criando-o e executando-o.

Agora, a interface do usuário está mais responsiva, pois o trabalho de desenho é executado em segundo plano.

[[Superior](#top)]

##  <a name="performance"></a>Melhorando o desempenho do desenho

A geração do fractal Mandelbrot é um bom candidato para paralelização porque a computação de cada pixel é independente de todos os outros cálculos. Para paralelizar o procedimento de desenho, converta `for` o loop externo `CChildView::DrawMandelbrot` no método para uma chamada para o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) , da seguinte maneira.

[!code-cpp[concrt-mandelbrot#301](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_14.cpp)]

Como a computação de cada elemento de bitmap é independente, você não precisa sincronizar as operações de desenho que acessam a memória de bitmap. Isso permite que o desempenho seja dimensionado conforme o número de processadores disponíveis aumenta.

[[Superior](#top)]

##  <a name="cancellation"></a>Adicionando suporte para cancelamento

Esta seção descreve como manipular o redimensionamento de janela e como cancelar qualquer tarefa de desenho ativa quando a janela é destruída.

O cancelamento do documento [na ppl](cancellation-in-the-ppl.md) explica como o cancelamento funciona no tempo de execução. O cancelamento é cooperativo; Portanto, ele não ocorre imediatamente. Para interromper uma tarefa cancelada, o tempo de execução gera uma exceção interna durante uma chamada subsequente da tarefa para o tempo de execução. A seção anterior mostra como usar o `parallel_for` algoritmo para melhorar o desempenho da tarefa de desenho. A chamada para `parallel_for` permite que o tempo de execução interrompa a tarefa e, portanto, permite que o cancelamento funcione.

### <a name="cancelling-active-tasks"></a>Cancelando tarefas ativas

O aplicativo Mandelbrot cria `Bitmap` objetos cujas dimensões correspondem ao tamanho da janela do cliente. Toda vez que a janela do cliente é redimensionada, o aplicativo cria uma tarefa de segundo plano adicional para gerar uma imagem para o novo tamanho da janela. O aplicativo não requer essas imagens intermediárias; Ele requer apenas a imagem para o tamanho final da janela. Para impedir que o aplicativo execute esse trabalho adicional, você pode cancelar todas as tarefas de desenho ativas nos manipuladores de `WM_SIZE` mensagem `WM_SIZING` para as mensagens e, em seguida, reagendar o trabalho de desenho depois que a janela for redimensionada.

Para cancelar tarefas de desenho ativas quando a janela é redimensionada, o aplicativo chama o método [Concurrency:: task_group:: Cancel](reference/task-group-class.md#cancel) nos manipuladores para `WM_SIZING` as `WM_SIZE` mensagens e. O manipulador `WM_SIZE` da mensagem também chama o método [Concurrency:: task_group:: Wait](reference/task-group-class.md#wait) para aguardar a conclusão de todas as tarefas ativas e, em seguida, reagendar a tarefa de desenho para o tamanho da janela atualizado.

Quando a janela do cliente é destruída, é uma boa prática cancelar tarefas de desenho ativas. Cancelar tarefas de desenho ativas garante que os threads de trabalho não publiquem mensagens no thread da interface do usuário depois que a janela do cliente for destruída. O aplicativo cancela todas as tarefas de desenho ativas no manipulador para `WM_DESTROY` a mensagem.

### <a name="responding-to-cancellation"></a>Respondendo ao cancelamento

O `CChildView::DrawMandelbrot` método, que executa a tarefa de desenho, deve responder ao cancelamento. Como o tempo de execução usa tratamento de exceções para cancelar `CChildView::DrawMandelbrot` tarefas, o método deve usar um mecanismo seguro de exceção para garantir que todos os recursos sejam limpos corretamente. Este exemplo usa o padrão de RAII ( *aquisição de recursos é inicialização* ) para garantir que os bits de bitmap sejam desbloqueados quando a tarefa for cancelada.

##### <a name="to-add-support-for-cancellation-in-the-mandelbrot-application"></a>Para adicionar suporte para cancelamento no aplicativo Mandelbrot

1. Em ChildView. h, na `protected` seção `CChildView` da classe, adicione declarações para as `OnSize`funções de mapa `OnSizing`de mensagens `OnDestroy` , e.

   [!code-cpp[concrt-mandelbrot#201](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_15.h)]

1. Em ChildView. cpp, modifique o mapa da mensagem para conter manipuladores para `WM_SIZE`as `WM_SIZING`mensagens, `WM_DESTROY` e.

   [!code-cpp[concrt-mandelbrot#202](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_16.cpp)]

1. Implementar o método de `CChildView::OnSizing` . Esse método cancela todas as tarefas de desenho existentes.

   [!code-cpp[concrt-mandelbrot#203](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_17.cpp)]

1. Implementar o método de `CChildView::OnSize` . Esse método cancela todas as tarefas de desenho existentes e cria uma nova tarefa de desenho para o tamanho da janela do cliente atualizado.

   [!code-cpp[concrt-mandelbrot#204](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_18.cpp)]

1. Implementar o método de `CChildView::OnDestroy` . Esse método cancela todas as tarefas de desenho existentes.

   [!code-cpp[concrt-mandelbrot#205](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_19.cpp)]

1. Em ChildView. cpp, defina a `scope_guard` classe, que implementa o padrão RAII.

   [!code-cpp[concrt-mandelbrot#206](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_20.cpp)]

1. Adicione o seguinte código ao `CChildView::DrawMandelbrot` método após a chamada para: `Bitmap::LockBits`

   [!code-cpp[concrt-mandelbrot#207](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_21.cpp)]

   Esse código manipula o cancelamento criando um `scope_guard` objeto. Quando o objeto sai do escopo, ele desbloqueia os bits de bitmap.

1. Modifique o final do `CChildView::DrawMandelbrot` método para ignorar o `scope_guard` objeto depois que os bits de bitmap forem desbloqueados, mas antes de qualquer mensagem ser enviada ao thread da interface do usuário. Isso garante que o thread de interface do usuário não seja atualizado antes que os bits de bitmap sejam desbloqueados.

   [!code-cpp[concrt-mandelbrot#208](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_22.cpp)]

9. Verifique se o aplicativo foi atualizado com êxito criando-o e executando-o.

Quando você redimensiona a janela, o trabalho de desenho é executado apenas para o tamanho final da janela. Todas as tarefas de desenho ativas também são canceladas quando a janela é destruída.

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Aplicativos da área de trabalho MFC](../../mfc/mfc-desktop-applications.md)
