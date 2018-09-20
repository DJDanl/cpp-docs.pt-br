---
title: 'Passo a passo: Removendo trabalho de um Thread de Interface do usuário | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- user-interface threads, removing work from [Concurrency Runtime]
- removing work from user-interface threads [Concurrency Runtime]
ms.assetid: a4a65cc2-b3bc-4216-8fa8-90529491de02
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6d87fe1060756e46418411584fa6042533bbc1f2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46385502"
---
# <a name="walkthrough-removing-work-from-a-user-interface-thread"></a>Instruções passo a passo: removendo trabalho de um thread de interface de usuário

Este documento demonstra como usar o tempo de execução de simultaneidade para mover o trabalho que é executado pelo thread de interface do usuário (IU) em um aplicativo do Microsoft Foundation Classes (MFC) para um thread de trabalho. Este documento também demonstra como melhorar o desempenho de uma operação demorada de desenho.

Removendo o trabalho do thread de interface do usuário ao descarregar as operações de bloqueio, por exemplo, desenho para threads de trabalho pode melhorar a capacidade de resposta do seu aplicativo. Este passo a passo usa uma rotina de desenho que gera o fractal Mandelbrot para demonstrar uma longa operação de bloqueio. A geração do fractal Mandelbrot também é um bom candidato para paralelização porque a computação de cada pixel é independente de todos os outros cálculos.

## <a name="prerequisites"></a>Pré-requisitos

Leia os tópicos a seguir antes de começar este passo a passo:

- [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

- [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)

- [Cancelamento no PPL](cancellation-in-the-ppl.md)

Também recomendamos que você compreenda os fundamentos de desenvolvimento de aplicativos do MFC e GDI+ antes de começar este passo a passo. Para obter mais informações sobre o MFC, consulte [aplicativos de área de trabalho do MFC](../../mfc/mfc-desktop-applications.md). Para obter mais informações sobre a GDI+, consulte [GDI+](https://msdn.microsoft.com/library/windows/desktop/ms533798).

##  <a name="top"></a> Seções

Este passo a passo contém as seguintes seções:

- [Criando o aplicativo do MFC](#application)

- [Implementando a versão Serial do aplicativo Mandelbrot](#serial)

- [Removendo o trabalho do Thread de Interface do usuário](#removing-work)

- [Melhorando o desempenho de desenho](#performance)

- [Adicionando suporte a cancelamento](#cancellation)

##  <a name="application"></a> Criando o aplicativo do MFC

Esta seção descreve como criar o aplicativo básico do MFC.

### <a name="to-create-a-visual-c-mfc-application"></a>Para criar um aplicativo do MFC do Visual C++

1. No menu **Arquivo**, clique em **Novo** e clique em **Projeto**.

1. No **novo projeto** na caixa de **modelos instalados** painel, selecione **Visual C++** e, em seguida, no **modelos** painel, selecione **Aplicativo do MFC**. Digite um nome para o projeto, por exemplo, `Mandelbrot`e, em seguida, clique em **Okey** para exibir o **Assistente de aplicativo MFC**.

1. No **tipo de aplicativo** painel, selecione **único documento**. Certifique-se de que o **suporte de arquitetura de documento/exibição** caixa de seleção está desmarcada.

1. Clique em **terminar** para criar o projeto e feche o **Assistente de aplicativo MFC**.

     Verifique se que o aplicativo foi criado com êxito pela criação e executá-lo. Para compilar o aplicativo, na **construir** menu, clique em **compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo clicando **iniciar depuração** sobre o **depurar** menu.

##  <a name="serial"></a> Implementando a versão Serial do aplicativo Mandelbrot

Esta seção descreve como desenhar o fractal Mandelbrot. Esta versão desenha o fractal Mandelbrot para um GDI+ [Bitmap](/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) de objeto e, em seguida, copia o conteúdo desse bitmap para a janela do cliente.

#### <a name="to-implement-the-serial-version-of-the-mandelbrot-application"></a>Para implementar a versão serial do aplicativo Mandelbrot

1. Em Stdafx. h, adicione o seguinte `#include` diretiva:

     [!code-cpp[concrt-mandelbrot#1](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_1.h)]

1. No ChildView.h, depois que o `pragma` diretiva, defina o `BitmapPtr` tipo. O `BitmapPtr` tipo permite que um ponteiro para um `Bitmap` objeto a ser compartilhado por vários componentes. O `Bitmap` objeto é excluído quando ele não for mais referenciado por nenhum componente.

     [!code-cpp[concrt-mandelbrot#2](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_2.h)]

1. No ChildView.h, adicione o seguinte código para o `protected` seção o `CChildView` classe:

     [!code-cpp[concrt-mandelbrot#3](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_3.h)]

1. No ChildView.cpp, comente ou remova as linhas a seguir.

     [!code-cpp[concrt-mandelbrot#4](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_4.cpp)]

     Em compilações de depuração, essa etapa impede que o aplicativo que usa o `DEBUG_NEW` alocador, que é incompatível com o GDI+.

1. No ChildView.cpp, adicione uma `using` diretiva para o `Gdiplus` namespace.

     [!code-cpp[concrt-mandelbrot#5](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_5.cpp)]

1. Adicione o seguinte código para o construtor e destruidor do `CChildView` classe para inicializar e desligar GDI+.

     [!code-cpp[concrt-mandelbrot#6](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_6.cpp)]

1. Implementar o método de `CChildView::DrawMandelbrot` . Esse método desenha o fractal Mandelbrot especificado `Bitmap` objeto.

     [!code-cpp[concrt-mandelbrot#7](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_7.cpp)]

1. Implementar o método de `CChildView::OnPaint` . Este método chama `CChildView::DrawMandelbrot` e, em seguida, copia o conteúdo do `Bitmap` objeto para a janela.

     [!code-cpp[concrt-mandelbrot#8](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_8.cpp)]

9. Verifique se que o aplicativo foi atualizado com êxito pela criação e executá-lo.

A ilustração a seguir mostra os resultados do aplicativo Mandelbrot.

![O aplicativo de Mandelbrot](../../parallel/concrt/media/mandelbrot.png "mandelbrot")

Como a computação para cada pixel é computacionalmente cara, o thread de interface do usuário não pode processar mensagens adicionais até que a computação geral seja concluída. Isso pode reduzir a capacidade de resposta do aplicativo. No entanto, você pode aliviar esse problema removendo o trabalho do thread de interface do usuário.

[[Superior](#top)]

##  <a name="removing-work"></a> Removendo o trabalho do Thread de interface do usuário

Esta seção mostra como remover o trabalho de desenho do thread de interface do usuário no aplicativo Mandelbrot. Ao mover o trabalho de desenho do thread de interface do usuário para um thread de trabalho, o thread de interface do usuário pode processar mensagens, como o thread de trabalho gera a imagem em segundo plano.

O tempo de execução de simultaneidade fornece três maneiras de executar tarefas de: [grupos de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md), [agentes assíncronos](../../parallel/concrt/asynchronous-agents.md), e [tarefas leves](../../parallel/concrt/task-scheduler-concurrency-runtime.md). Embora você possa usar qualquer um desses mecanismos para remover o trabalho do thread de interface do usuário, este exemplo usa uma [Concurrency:: task_group](reference/task-group-class.md) porque grupos de tarefas dão suporte ao cancelamento de objeto. Posteriormente, este passo a passo usa cancelamento para reduzir a quantidade de trabalho que é executada quando a janela do cliente é redimensionada e para executar a limpeza quando a janela é destruída.

Este exemplo também usa um [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) objeto para permitir que o thread de interface do usuário e o thread de trabalho para se comunicar uns com os outros. Depois que o thread de trabalho produz a imagem, ele envia um ponteiro para o `Bitmap` do objeto para o `unbounded_buffer` do objeto e, em seguida, envia uma mensagem de pintura para o thread de interface do usuário. O thread de interface do usuário, em seguida, recebe do `unbounded_buffer` objeto o `Bitmap` de objeto e desenha-lo para a janela do cliente.

#### <a name="to-remove-the-drawing-work-from-the-ui-thread"></a>Para remover o trabalho de desenho do thread de interface do usuário

1. Em Stdafx. h, adicione o seguinte `#include` diretivas:

     [!code-cpp[concrt-mandelbrot#101](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_9.h)]

1. No ChildView.h, adicione `task_group` e `unbounded_buffer` variáveis de membro para o `protected` seção o `CChildView` classe. O `task_group` objeto contém as tarefas que executam o desenho; a `unbounded_buffer` objeto contém a imagem de Mandelbrot concluída.

     [!code-cpp[concrt-mandelbrot#102](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_10.h)]

1. No ChildView.cpp, adicione uma `using` diretiva para o `concurrency` namespace.

     [!code-cpp[concrt-mandelbrot#103](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_11.cpp)]

1. No `CChildView::DrawMandelbrot` método, após a chamada para `Bitmap::UnlockBits`, chame o [Concurrency:: Send](reference/concurrency-namespace-functions.md#send) função para passar o `Bitmap` objeto para o thread de interface do usuário. Em seguida, postar uma mensagem de pintura para o thread de interface do usuário e invalidar a área de cliente.

     [!code-cpp[concrt-mandelbrot#104](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_12.cpp)]

1. Atualizar o `CChildView::OnPaint` método para receber a atualização `Bitmap` do objeto e desenhar a imagem para a janela do cliente.

     [!code-cpp[concrt-mandelbrot#105](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_13.cpp)]

     O `CChildView::OnPaint` método cria uma tarefa para gerar a imagem de Mandelbrot se ela não existir no buffer de mensagem. O buffer de mensagem não conterá um `Bitmap` objeto em casos como a mensagem de pintura inicial e a outra janela é movida na frente da janela do cliente.

1. Verifique se que o aplicativo foi atualizado com êxito pela criação e executá-lo.

A interface do usuário agora está mais responsivo, porque o trabalho de desenho está sendo executado em segundo plano.

[[Superior](#top)]

##  <a name="performance"></a> Melhorando o desempenho de desenho

A geração do fractal Mandelbrot é um bom candidato para paralelização porque a computação de cada pixel é independente de todos os outros cálculos. Para paralelizar o procedimento de desenho, converter externo `for` loop na `CChildView::DrawMandelbrot` método a uma chamada para o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo, da seguinte maneira.

[!code-cpp[concrt-mandelbrot#301](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_14.cpp)]

Como a computação de cada elemento de bitmap é independente, não é necessário que sincronizar as operações de desenho que acessam a memória do bitmap. Isso permite que o desempenho de expandir conforme o número de processadores disponíveis aumenta.

[[Superior](#top)]

##  <a name="cancellation"></a> Adicionando suporte a cancelamento

Esta seção descreve como lidar com redimensionamento de janela e como cancelar quaisquer tarefas de desenho ativas quando a janela é destruída.

O documento [cancelamento no PPL](cancellation-in-the-ppl.md) explica como funciona o cancelamento no tempo de execução. O cancelamento é cooperativo; Portanto, ele não ocorre imediatamente. Para interromper uma tarefa cancelada, o tempo de execução gera uma exceção de interna durante uma chamada subsequente da tarefa no tempo de execução. A seção anterior mostra como usar o `parallel_for` algoritmo para melhorar o desempenho da tarefa de desenho. A chamada para `parallel_for` permite que o tempo de execução interromper a tarefa e, portanto, permite o cancelamento funcione.

### <a name="cancelling-active-tasks"></a>Cancelando tarefas ativas

Cria o aplicativo de Mandelbrot `Bitmap` objetos cujas dimensões correspondem o tamanho da janela do cliente. Toda vez que a janela do cliente for redimensionada, o aplicativo cria uma tarefa de plano de fundo adicional para gerar uma imagem para o novo tamanho da janela. O aplicativo não exigir essas imagens intermediárias; ela exige apenas a imagem para o tamanho da janela final. Para impedir que o aplicativo realizar esse trabalho adicional, você pode cancelar quaisquer tarefas ativas de desenho nos manipuladores de mensagem para o `WM_SIZE` e `WM_SIZING` mensagens e desenhando reagendar trabalham depois que a janela é redimensionada.

Para cancelar tarefas ativas de desenho quando a janela é redimensionada, o aplicativo chama o [concurrency::task_group::cancel](reference/task-group-class.md#cancel) método nos manipuladores para o `WM_SIZING` e `WM_SIZE` mensagens. O manipulador para o `WM_SIZE` da mensagem também chamadas a [concurrency::task_group::wait](reference/task-group-class.md#wait) método esperar por ativa todas as tarefas para concluir e, em seguida, reagendará a tarefa de desenho para o tamanho da janela atualizada.

Quando a janela do cliente é destruída, é uma boa prática Cancelar quaisquer tarefas ativas de desenho. Cancelamento de quaisquer tarefas ativas de desenho certifica-se de que os threads de trabalho não postar mensagens para o thread de interface do usuário depois que a janela do cliente é destruída. O aplicativo cancela quaisquer tarefas ativas de desenho no manipulador para o `WM_DESTROY` mensagem.

### <a name="responding-to-cancellation"></a>Responder ao cancelamento

O `CChildView::DrawMandelbrot` método, que executa a tarefa de desenho, deve responder ao cancelamento. Como o tempo de execução usa o tratamento de exceções para cancelar as tarefas, o `CChildView::DrawMandelbrot` método deve usar um mecanismo de exceção segura para garantir que todos os recursos são corretamente limpas. Este exemplo usa o *recurso de aquisição é inicialização* padrão (RAII) para garantir que os bits de bitmap sejam desbloqueados quando a tarefa é cancelada.

##### <a name="to-add-support-for-cancellation-in-the-mandelbrot-application"></a>Para adicionar suporte ao cancelamento no aplicativo Mandelbrot

1. No ChildView.h, no `protected` seção o `CChildView` , adicione as declarações para o `OnSize`, `OnSizing`, e `OnDestroy` funções de mapa de mensagem.

     [!code-cpp[concrt-mandelbrot#201](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_15.h)]

1. No ChildView.cpp, modifique o mapa da mensagem para conter os manipuladores para o `WM_SIZE`, `WM_SIZING`, e `WM_DESTROY` mensagens.

     [!code-cpp[concrt-mandelbrot#202](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_16.cpp)]

1. Implementar o método de `CChildView::OnSizing` . Esse método cancela quaisquer tarefas de desenho existentes.

     [!code-cpp[concrt-mandelbrot#203](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_17.cpp)]

1. Implementar o método de `CChildView::OnSize` . Esse método cancela quaisquer tarefas de desenho existentes e cria uma nova tarefa de desenho para o tamanho da janela cliente atualizado.

     [!code-cpp[concrt-mandelbrot#204](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_18.cpp)]

1. Implementar o método de `CChildView::OnDestroy` . Esse método cancela quaisquer tarefas de desenho existentes.

     [!code-cpp[concrt-mandelbrot#205](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_19.cpp)]

1. No ChildView.cpp, defina o `scope_guard` classe, que implementa o padrão RAII.

     [!code-cpp[concrt-mandelbrot#206](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_20.cpp)]

1. Adicione o seguinte código para o `CChildView::DrawMandelbrot` método após a chamada para `Bitmap::LockBits`:

     [!code-cpp[concrt-mandelbrot#207](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_21.cpp)]

     Esse código manipula o cancelamento, criando um `scope_guard` objeto. Quando o objeto sai do escopo, ele desbloqueia os bits de bitmap.

1. Modificar o final do `CChildView::DrawMandelbrot` método para ignorar o `scope_guard` depois que os bits de bitmap estiverem desbloqueados, mas antes de todas as mensagens são enviadas para o thread de interface do usuário do objeto. Isso garante que o thread de interface do usuário não é atualizado antes que os bits de bitmap são desbloqueados.

     [!code-cpp[concrt-mandelbrot#208](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_22.cpp)]

9. Verifique se que o aplicativo foi atualizado com êxito pela criação e executá-lo.

Quando você redimensiona a janela, desenhar o trabalho é executada somente para o tamanho da janela final. Todas as tarefas desenho Active Directory também são canceladas quando a janela é destruída.

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Aplicativos da área de trabalho MFC](../../mfc/mfc-desktop-applications.md)
