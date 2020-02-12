---
title: 'Instruções passo a passo: removendo trabalho de um thread de interface de usuário'
ms.date: 08/19/2019
helpviewer_keywords:
- user-interface threads, removing work from [Concurrency Runtime]
- removing work from user-interface threads [Concurrency Runtime]
ms.assetid: a4a65cc2-b3bc-4216-8fa8-90529491de02
ms.openlocfilehash: 518044d4e3adea44c3776793c8277939076066d6
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140704"
---
# <a name="walkthrough-removing-work-from-a-user-interface-thread"></a>Instruções passo a passo: removendo trabalho de um thread de interface de usuário

Este documento demonstra como usar o Tempo de Execução de Simultaneidade para mover o trabalho que é executado pelo thread da interface do usuário (IU) em um aplicativo MFC (MFC) para um thread de trabalho. Este documento também demonstra como melhorar o desempenho de uma operação de desenho demorada.

Remover o trabalho do thread da interface do usuário descarregando operações de bloqueio, por exemplo, o desenho, para threads de trabalho pode melhorar a capacidade de resposta do seu aplicativo. Esta instrução usa uma rotina de desenho que gera o fractal Mandelbrot para demonstrar uma operação de bloqueio demorada. A geração do fractal Mandelbrot também é um bom candidato para paralelização porque a computação de cada pixel é independente de todos os outros cálculos.

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

Leia os tópicos a seguir antes de iniciar este passo a passos:

- [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

- [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)

- [Cancelamento no PPL](cancellation-in-the-ppl.md)

Também recomendamos que você entenda os conceitos básicos do desenvolvimento de aplicativos do MFC e do GDI+ antes de iniciar este guia. Para obter mais informações sobre MFC, consulte [aplicativos de área de trabalho do MFC](../../mfc/mfc-desktop-applications.md). Para obter mais informações sobre o GDI+, consulte [GDI+](/windows/win32/gdiplus/-gdiplus-gdi-start).

## <a name="top"></a>As

Este passo a passo contém as seguintes seções:

- [Criando o aplicativo MFC](#application)

- [Implementando a versão serial do aplicativo Mandelbrot](#serial)

- [Removendo o trabalho do thread da interface do usuário](#removing-work)

- [Melhorando o desempenho do desenho](#performance)

- [Adicionando suporte para cancelamento](#cancellation)

## <a name="application"></a>Criando o aplicativo MFC

Esta seção descreve como criar o aplicativo básico do MFC.

### <a name="to-create-a-visual-c-mfc-application"></a>Para criar um aplicativo C++ do Visual MFC

1. Use o **Assistente de aplicativo MFC** para criar um aplicativo MFC com todas as configurações padrão. Consulte [Walkthrough: usando os novos controles do shell do MFC](../../mfc/walkthrough-using-the-new-mfc-shell-controls.md) para obter instruções sobre como abrir o assistente para sua versão do Visual Studio.

1. Digite um nome para o projeto, por exemplo, `Mandelbrot`e clique em **OK** para exibir o **Assistente de aplicativo do MFC**.

1. No painel **tipo de aplicativo** , selecione **documento único**. Verifique se a caixa de seleção **suporte à arquitetura de documento/exibição** está desmarcada.

1. Clique em **concluir** para criar o projeto e fechar o **Assistente de aplicativo do MFC**.

   Verifique se o aplicativo foi criado com êxito criando-o e executando-o. Para criar o aplicativo, no menu **Compilar** , clique em **Compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo clicando em **Iniciar Depuração** no menu **depurar** .

## <a name="serial"></a>Implementando a versão serial do aplicativo Mandelbrot

Esta seção descreve como desenhar o fractal Mandelbrot. Essa versão desenha o fractal Mandelbrot para um objeto de [bitmap](/windows/win32/api/gdiplusheaders/nl-gdiplusheaders-bitmap) do GDI+ e, em seguida, copia o conteúdo desse bitmap para a janela do cliente.

#### <a name="to-implement-the-serial-version-of-the-mandelbrot-application"></a>Para implementar a versão serial do aplicativo Mandelbrot

1. Em *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior), adicione a seguinte diretiva de `#include`:

   [!code-cpp[concrt-mandelbrot#1](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_1.h)]

1. Em ChildView. h, após a diretiva de `pragma`, defina o tipo de `BitmapPtr`. O tipo de `BitmapPtr` permite que um ponteiro para um objeto de `Bitmap` seja compartilhado por vários componentes. O objeto `Bitmap` é excluído quando não é mais referenciado por nenhum componente.

   [!code-cpp[concrt-mandelbrot#2](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_2.h)]

1. Em ChildView. h, adicione o seguinte código à seção `protected` da classe `CChildView`:

   [!code-cpp[concrt-mandelbrot#3](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_3.h)]

1. Em ChildView. cpp, comente ou remova as linhas a seguir.

   [!code-cpp[concrt-mandelbrot#4](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_4.cpp)]

   Em compilações de depuração, esta etapa impede que o aplicativo use o alocador de `DEBUG_NEW`, que é incompatível com o GDI+.

1. Em ChildView. cpp, adicione uma diretiva `using` ao namespace `Gdiplus`.

   [!code-cpp[concrt-mandelbrot#5](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_5.cpp)]

1. Adicione o código a seguir ao construtor e ao destruidor da classe `CChildView` para inicializar e desligar o GDI+.

   [!code-cpp[concrt-mandelbrot#6](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_6.cpp)]

1. Implementar o método de `CChildView::DrawMandelbrot` . Esse método desenha o fractal Mandelbrot para o objeto de `Bitmap` especificado.

   [!code-cpp[concrt-mandelbrot#7](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_7.cpp)]

1. Implementar o método de `CChildView::OnPaint` . Esse método chama `CChildView::DrawMandelbrot` e, em seguida, copia o conteúdo do objeto `Bitmap` para a janela.

   [!code-cpp[concrt-mandelbrot#8](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_8.cpp)]

1. Verifique se o aplicativo foi atualizado com êxito criando-o e executando-o.

A ilustração a seguir mostra os resultados do aplicativo Mandelbrot.

![O aplicativo Mandelbrot](../../parallel/concrt/media/mandelbrot.png "O aplicativo Mandelbrot")

Como o cálculo de cada pixel é computacionalmente caro, o thread da interface do usuário não pode processar mensagens adicionais até que a computação geral seja concluída. Isso pode diminuir a capacidade de resposta no aplicativo. No entanto, você pode aliviar esse problema removendo o trabalho do thread da interface do usuário.

[[Superior](#top)]

## <a name="removing-work"></a>Removendo o trabalho do thread da interface do usuário

Esta seção mostra como remover o trabalho de desenho do thread da interface do usuário no aplicativo Mandelbrot. Ao mover o trabalho de desenho do thread da interface do usuário para um thread de trabalho, o thread da interface do usuário pode processar mensagens à medida que o thread de trabalho gera a imagem em segundo plano.

O Tempo de Execução de Simultaneidade fornece três maneiras de executar tarefas: [grupos de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md), [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)e [tarefas leves](../../parallel/concrt/task-scheduler-concurrency-runtime.md). Embora você possa usar qualquer um desses mecanismos para remover o trabalho do thread da interface do usuário, este exemplo usa um objeto [Concurrency:: task_group](reference/task-group-class.md) porque os grupos de tarefas dão suporte ao cancelamento. Posteriormente, esse passo a passos usa o cancelamento para reduzir a quantidade de trabalho que é executada quando a janela do cliente é redimensionada e para executar a limpeza quando a janela é destruída.

Este exemplo também usa um objeto [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) para permitir que o thread da interface do usuário e o thread de trabalho se comuniquem entre si. Depois que o thread de trabalho produz a imagem, ele envia um ponteiro para o objeto `Bitmap` para o objeto `unbounded_buffer` e, em seguida, posta uma mensagem de pintura no thread da interface do usuário. Em seguida, o thread da interface do usuário recebe do objeto `unbounded_buffer` o objeto `Bitmap` e o desenha na janela do cliente.

#### <a name="to-remove-the-drawing-work-from-the-ui-thread"></a>Para remover o trabalho de desenho do thread da interface do usuário

1. Em *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior), adicione as seguintes diretivas de `#include`:

   [!code-cpp[concrt-mandelbrot#101](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_9.h)]

1. Em ChildView. h, adicione `task_group` e `unbounded_buffer` variáveis de membro à seção `protected` da classe `CChildView`. O objeto `task_group` contém as tarefas que executam o desenho; o objeto `unbounded_buffer` contém a imagem Mandelbrot concluída.

   [!code-cpp[concrt-mandelbrot#102](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_10.h)]

1. Em ChildView. cpp, adicione uma diretiva `using` ao namespace `concurrency`.

   [!code-cpp[concrt-mandelbrot#103](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_11.cpp)]

1. No método `CChildView::DrawMandelbrot`, após a chamada para `Bitmap::UnlockBits`, chame a função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) para passar o objeto `Bitmap` para o thread da interface do usuário. Em seguida, poste uma mensagem de pintura no thread da interface do usuário e invalida a área do cliente.

   [!code-cpp[concrt-mandelbrot#104](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_12.cpp)]

1. Atualize o método `CChildView::OnPaint` para receber o objeto de `Bitmap` atualizado e desenhar a imagem na janela do cliente.

   [!code-cpp[concrt-mandelbrot#105](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_13.cpp)]

   O método `CChildView::OnPaint` cria uma tarefa para gerar a imagem Mandelbrot se ela não existir no buffer de mensagens. O buffer de mensagens não conterá um objeto `Bitmap` em casos como a mensagem inicial de pintura e quando outra janela for movida na frente da janela do cliente.

1. Verifique se o aplicativo foi atualizado com êxito criando-o e executando-o.

Agora, a interface do usuário está mais responsiva, pois o trabalho de desenho é executado em segundo plano.

[[Superior](#top)]

## <a name="performance"></a>Melhorando o desempenho do desenho

A geração do fractal Mandelbrot é um bom candidato para paralelização porque a computação de cada pixel é independente de todos os outros cálculos. Para paralelizar o procedimento de desenho, converta o loop de `for` externo no método `CChildView::DrawMandelbrot` para uma chamada para o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) da seguinte maneira.

[!code-cpp[concrt-mandelbrot#301](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_14.cpp)]

Como a computação de cada elemento de bitmap é independente, você não precisa sincronizar as operações de desenho que acessam a memória de bitmap. Isso permite que o desempenho seja dimensionado conforme o número de processadores disponíveis aumenta.

[[Superior](#top)]

## <a name="cancellation"></a>Adicionando suporte para cancelamento

Esta seção descreve como manipular o redimensionamento de janela e como cancelar qualquer tarefa de desenho ativa quando a janela é destruída.

O [cancelamento do documento na ppl](cancellation-in-the-ppl.md) explica como o cancelamento funciona no tempo de execução. O cancelamento é cooperativo; Portanto, ele não ocorre imediatamente. Para interromper uma tarefa cancelada, o tempo de execução gera uma exceção interna durante uma chamada subsequente da tarefa para o tempo de execução. A seção anterior mostra como usar o algoritmo de `parallel_for` para melhorar o desempenho da tarefa de desenho. A chamada para `parallel_for` permite que o tempo de execução interrompa a tarefa e, portanto, permite que o cancelamento funcione.

### <a name="cancelling-active-tasks"></a>Cancelando tarefas ativas

O aplicativo Mandelbrot cria `Bitmap` objetos cujas dimensões correspondem ao tamanho da janela do cliente. Toda vez que a janela do cliente é redimensionada, o aplicativo cria uma tarefa de segundo plano adicional para gerar uma imagem para o novo tamanho da janela. O aplicativo não requer essas imagens intermediárias; Ele requer apenas a imagem para o tamanho final da janela. Para impedir que o aplicativo execute esse trabalho adicional, você pode cancelar todas as tarefas de desenho ativas nos manipuladores de mensagens para as mensagens `WM_SIZE` e `WM_SIZING` e, em seguida, reagendar o trabalho de desenho depois que a janela for redimensionada.

Para cancelar tarefas de desenho ativas quando a janela é redimensionada, o aplicativo chama o método [Concurrency:: task_group:: Cancel](reference/task-group-class.md#cancel) nos manipuladores para as mensagens `WM_SIZING` e `WM_SIZE`. O manipulador para a mensagem de `WM_SIZE` também chama o método [Concurrency:: task_group:: Wait](reference/task-group-class.md#wait) para aguardar a conclusão de todas as tarefas ativas e, em seguida, reagendar a tarefa de desenho para o tamanho de janela atualizado.

Quando a janela do cliente é destruída, é uma boa prática cancelar tarefas de desenho ativas. Cancelar tarefas de desenho ativas garante que os threads de trabalho não publiquem mensagens no thread da interface do usuário depois que a janela do cliente for destruída. O aplicativo cancela todas as tarefas de desenho ativas no manipulador para a mensagem de `WM_DESTROY`.

### <a name="responding-to-cancellation"></a>Respondendo ao cancelamento

O método `CChildView::DrawMandelbrot`, que executa a tarefa de desenho, deve responder ao cancelamento. Como o tempo de execução usa tratamento de exceções para cancelar tarefas, o método `CChildView::DrawMandelbrot` deve usar um mecanismo seguro de exceção para garantir que todos os recursos sejam limpos corretamente. Este exemplo usa o padrão de RAII ( *aquisição de recursos é inicialização* ) para garantir que os bits de bitmap sejam desbloqueados quando a tarefa for cancelada.

##### <a name="to-add-support-for-cancellation-in-the-mandelbrot-application"></a>Para adicionar suporte para cancelamento no aplicativo Mandelbrot

1. No ChildView. h, na seção `protected` da classe `CChildView`, adicione declarações para as funções de mapeamento de mensagem `OnSize`, `OnSizing`e `OnDestroy`.

   [!code-cpp[concrt-mandelbrot#201](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_15.h)]

1. Em ChildView. cpp, modifique o mapa da mensagem para conter manipuladores para as mensagens `WM_SIZE`, `WM_SIZING`e `WM_DESTROY`.

   [!code-cpp[concrt-mandelbrot#202](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_16.cpp)]

1. Implementar o método de `CChildView::OnSizing` . Esse método cancela todas as tarefas de desenho existentes.

   [!code-cpp[concrt-mandelbrot#203](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_17.cpp)]

1. Implementar o método de `CChildView::OnSize` . Esse método cancela todas as tarefas de desenho existentes e cria uma nova tarefa de desenho para o tamanho da janela do cliente atualizado.

   [!code-cpp[concrt-mandelbrot#204](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_18.cpp)]

1. Implementar o método de `CChildView::OnDestroy` . Esse método cancela todas as tarefas de desenho existentes.

   [!code-cpp[concrt-mandelbrot#205](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_19.cpp)]

1. Em ChildView. cpp, defina a classe `scope_guard`, que implementa o padrão RAII.

   [!code-cpp[concrt-mandelbrot#206](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_20.cpp)]

1. Adicione o seguinte código ao método `CChildView::DrawMandelbrot` após a chamada para `Bitmap::LockBits`:

   [!code-cpp[concrt-mandelbrot#207](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_21.cpp)]

   Esse código manipula o cancelamento criando um objeto `scope_guard`. Quando o objeto sai do escopo, ele desbloqueia os bits de bitmap.

1. Modifique o final do método `CChildView::DrawMandelbrot` para descartar o objeto `scope_guard` depois que os bits de bitmap forem desbloqueados, mas antes de qualquer mensagem ser enviada ao thread da interface do usuário. Isso garante que o thread de interface do usuário não seja atualizado antes que os bits de bitmap sejam desbloqueados.

   [!code-cpp[concrt-mandelbrot#208](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_22.cpp)]

9. Verifique se o aplicativo foi atualizado com êxito criando-o e executando-o.

Quando você redimensiona a janela, o trabalho de desenho é executado apenas para o tamanho final da janela. Todas as tarefas de desenho ativas também são canceladas quando a janela é destruída.

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Aplicativos da área de trabalho MFC](../../mfc/mfc-desktop-applications.md)
