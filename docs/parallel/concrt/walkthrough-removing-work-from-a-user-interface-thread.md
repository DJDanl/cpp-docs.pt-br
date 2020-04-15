---
title: 'Instruções passo a passo: removendo trabalho de um thread de interface de usuário'
ms.date: 08/19/2019
helpviewer_keywords:
- user-interface threads, removing work from [Concurrency Runtime]
- removing work from user-interface threads [Concurrency Runtime]
ms.assetid: a4a65cc2-b3bc-4216-8fa8-90529491de02
ms.openlocfilehash: 52bc98ef339a19c6ec2a53697f532a9a94b6c9a6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377438"
---
# <a name="walkthrough-removing-work-from-a-user-interface-thread"></a>Instruções passo a passo: removendo trabalho de um thread de interface de usuário

Este documento demonstra como usar o Tempo de Execução de Moedas para mover o trabalho que é realizado pelo segmento de interface do usuário (UI) em um aplicativo Microsoft Foundation Classes (MFC) para um segmento de trabalhador. Este documento também demonstra como melhorar o desempenho de uma operação de desenho demorada.

A remoção do trabalho do segmento de interface do ui descarregando operações de bloqueio, por exemplo, desenhando, para os segmentos do trabalhador pode melhorar a capacidade de resposta do seu aplicativo. Este passo a passo usa uma rotina de desenho que gera o fractal Mandelbrot para demonstrar uma longa operação de bloqueio. A geração do fractal Mandelbrot também é um bom candidato para a paralelização porque a computação de cada pixel é independente de todos os outros cálculos.

## <a name="prerequisites"></a>Pré-requisitos

Leia os seguintes tópicos antes de iniciar este passo a passo:

- [Paralelismo de Tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

- [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)

- [Cancelamento no PPL](cancellation-in-the-ppl.md)

Também recomendamos que você entenda o básico do desenvolvimento de aplicativos MFC e GDI+ antes de iniciar este passo a passo. Para obter mais informações sobre o MFC, consulte [MFC Desktop Applications](../../mfc/mfc-desktop-applications.md). Para obter mais informações sobre o GDI+, consulte [GDI+](/windows/win32/gdiplus/-gdiplus-gdi-start).

## <a name="sections"></a><a name="top"></a>Seções

Este passo a passo contém as seguintes seções:

- [Criando o aplicativo MFC](#application)

- [Implementando a versão serial do aplicativo Mandelbrot](#serial)

- [Removendo o trabalho da linha interface do usuário](#removing-work)

- [Melhorando o desempenho do desenho](#performance)

- [Adicionando suporte para cancelamento](#cancellation)

## <a name="creating-the-mfc-application"></a><a name="application"></a>Criando o aplicativo MFC

Esta seção descreve como criar o aplicativo Básico do MFC.

### <a name="to-create-a-visual-c-mfc-application"></a>Para criar um aplicativo Visual C++ MFC

1. Use o **Assistente de Aplicativo MFC** para criar um aplicativo MFC com todas as configurações padrão. Veja [o passo a passo: Usando os novos controles do Shell Do MFC](../../mfc/walkthrough-using-the-new-mfc-shell-controls.md) para obter instruções sobre como abrir o assistente para a sua versão do Visual Studio.

1. Digite um nome para o `Mandelbrot`projeto, por exemplo, e clique em **OK** para exibir o **Assistente de Aplicativo Do MFC**.

1. No painel **Tipo de aplicativo,** selecione **Documento Único**. Certifique-se de que a caixa de **seleção de suporte à arquitetura Document/View** esteja limpa.

1. Clique **em Concluir** para criar o projeto e fechar o Assistente de Aplicativo do **MFC**.

   Verifique se o aplicativo foi criado com sucesso, construindo e executando-o. Para construir o aplicativo, no menu **Construir,** clique em **Criar solução**. Se o aplicativo for criado com sucesso, execute o aplicativo clicando em **Iniciar depuração** no menu **Depuração.**

## <a name="implementing-the-serial-version-of-the-mandelbrot-application"></a><a name="serial"></a>Implementando a versão serial do aplicativo Mandelbrot

Esta seção descreve como desenhar o fractal Mandelbrot. Esta versão desenha o fractal Mandelbrot para um objeto GDI+ [Bitmap](/windows/win32/api/gdiplusheaders/nl-gdiplusheaders-bitmap) e, em seguida, copia o conteúdo desse bitmap para a janela do cliente.

#### <a name="to-implement-the-serial-version-of-the-mandelbrot-application"></a>Para implementar a versão serial do aplicativo Mandelbrot

1. Em *pch.h* *(stdafx.h* no Visual Studio 2017 `#include` e anterior), adicione a seguinte diretiva:

   [!code-cpp[concrt-mandelbrot#1](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_1.h)]

1. No ChildView.h, `pragma` após a `BitmapPtr` diretiva, defina o tipo. O `BitmapPtr` tipo permite que `Bitmap` um ponteiro para um objeto seja compartilhado por vários componentes. O `Bitmap` objeto é excluído quando não é mais referenciado por nenhum componente.

   [!code-cpp[concrt-mandelbrot#2](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_2.h)]

1. No ChildView.h, adicione o `protected` seguinte código `CChildView` à seção da classe:

   [!code-cpp[concrt-mandelbrot#3](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_3.h)]

1. Em ChildView.cpp, comente ou remova as seguintes linhas.

   [!code-cpp[concrt-mandelbrot#4](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_4.cpp)]

   Nas compilações de Debug, essa etapa `DEBUG_NEW` impede que a aplicação use o alocador, que é incompatível com o GDI+.

1. No ChildView.cpp, `using` adicione uma `Gdiplus` diretiva ao namespace.

   [!code-cpp[concrt-mandelbrot#5](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_5.cpp)]

1. Adicione o seguinte código ao construtor e destrutor da `CChildView` classe para inicializar e desligar o GDI+.

   [!code-cpp[concrt-mandelbrot#6](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_6.cpp)]

1. Implementar o método de `CChildView::DrawMandelbrot` . Este método atrai o fractal mandelbrot para o objeto especificado. `Bitmap`

   [!code-cpp[concrt-mandelbrot#7](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_7.cpp)]

1. Implementar o método de `CChildView::OnPaint` . Este método `CChildView::DrawMandelbrot` chama e copia `Bitmap` o conteúdo do objeto para a janela.

   [!code-cpp[concrt-mandelbrot#8](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_8.cpp)]

1. Verifique se o aplicativo foi atualizado com sucesso, construindo e executando-o.

A ilustração a seguir mostra os resultados da aplicação de Mandelbrot.

![A Aplicação mandelbrot](../../parallel/concrt/media/mandelbrot.png "A Aplicação mandelbrot")

Como a computação de cada pixel é computacionalmente cara, o segmento de ia não pode processar mensagens adicionais até que a computação geral termine. Isso poderia diminuir a capacidade de resposta na aplicação. No entanto, você pode aliviar esse problema removendo o trabalho do segmento de IA.

[[Top](#top)]

## <a name="removing-work-from-the-ui-thread"></a><a name="removing-work"></a>Removendo o trabalho do segmento de ui

Esta seção mostra como remover o trabalho de desenho do segmento de interface do ida na aplicação mandelbrot. Ao mover o trabalho de desenho do segmento de ui para um segmento de trabalhador, o segmento de ia pode processar mensagens à medida que o segmento do trabalhador gera a imagem em segundo plano.

O Tempo de Execução de Concurrency fornece três maneiras de executar tarefas: grupos de [tarefas, agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)e [tarefas leves.](../../parallel/concrt/task-scheduler-concurrency-runtime.md) [task groups](../../parallel/concrt/task-parallelism-concurrency-runtime.md) Embora você possa usar qualquer um desses mecanismos para remover o trabalho do segmento de IA, este exemplo usa uma [concorrência::task_group](reference/task-group-class.md) objeto porque grupos de tarefas suportam cancelamento. Este passo a passo posteriormente usa o cancelamento para reduzir a quantidade de trabalho que é realizada quando a janela do cliente é redimensionada e para realizar a limpeza quando a janela é destruída.

Este exemplo também usa uma [concorrência::unbounded_buffer](reference/unbounded-buffer-class.md) objeto para habilitar o segmento de ui e o segmento de trabalhador para se comunicarem entre si. Depois que o segmento do trabalhador produz a `Bitmap` imagem, `unbounded_buffer` ele envia um ponteiro para o objeto para o objeto e, em seguida, posta uma mensagem de tinta para o segmento de ui. O segmento de ia `unbounded_buffer` de `Bitmap` ui recebe do objeto o objeto e o desenha para a janela do cliente.

#### <a name="to-remove-the-drawing-work-from-the-ui-thread"></a>Para remover o trabalho de desenho do segmento de IA

1. Em *pch.h* *(stdafx.h* no Visual Studio 2017 `#include` e anterior), adicione as seguintes diretivas:

   [!code-cpp[concrt-mandelbrot#101](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_9.h)]

1. No ChildView.h, `task_group` `unbounded_buffer` adicione e agregando variáveis de membro à `protected` seção da `CChildView` classe. O `task_group` objeto contém as tarefas que executam o desenho; o `unbounded_buffer` objeto mantém a imagem completa de Mandelbrot.

   [!code-cpp[concrt-mandelbrot#102](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_10.h)]

1. No ChildView.cpp, `using` adicione uma `concurrency` diretiva ao namespace.

   [!code-cpp[concrt-mandelbrot#103](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_11.cpp)]

1. No `CChildView::DrawMandelbrot` método, após a `Bitmap::UnlockBits`chamada para , chame a função `Bitmap` de [concorrência::enviar](reference/concurrency-namespace-functions.md#send) para passar o objeto para o segmento de IA. Em seguida, publique uma mensagem de tinta no segmento de ida e invalide a área do cliente.

   [!code-cpp[concrt-mandelbrot#104](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_12.cpp)]

1. Atualize `CChildView::OnPaint` o método `Bitmap` para receber o objeto atualizado e desenhe a imagem para a janela do cliente.

   [!code-cpp[concrt-mandelbrot#105](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_13.cpp)]

   O `CChildView::OnPaint` método cria uma tarefa para gerar a imagem de Mandelbrot se não existir no buffer de mensagens. O buffer de mensagem não conterá um `Bitmap` objeto em casos como a mensagem de pintura inicial e quando outra janela é movida em frente à janela do cliente.

1. Verifique se o aplicativo foi atualizado com sucesso, construindo e executando-o.

A ui agora está mais responsiva porque o trabalho de desenho é realizado em segundo plano.

[[Top](#top)]

## <a name="improving-drawing-performance"></a><a name="performance"></a>Melhorando o desempenho do desenho

A geração do fractal Mandelbrot é um bom candidato para a paralelização porque a computação de cada pixel é independente de todos os outros cálculos. Para paraleletrizar o `for` procedimento de `CChildView::DrawMandelbrot` desenho, converta o loop externo no método para uma chamada para o [algoritmo de :parallel_para](reference/concurrency-namespace-functions.md#parallel_for) algoritmo, da seguinte forma.

[!code-cpp[concrt-mandelbrot#301](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_14.cpp)]

Como a computação de cada elemento bitmap é independente, você não precisa sincronizar as operações de desenho que acessam a memória bitmap. Isso permite que o desempenho seja dimensionado à medida que o número de processadores disponíveis aumenta.

[[Top](#top)]

## <a name="adding-support-for-cancellation"></a><a name="cancellation"></a>Adicionando suporte para cancelamento

Esta seção descreve como lidar com o redimensionamento da janela e como cancelar quaisquer tarefas ativas de desenho quando a janela é destruída.

O [cancelamento do documento no PPL](cancellation-in-the-ppl.md) explica como funciona o cancelamento em tempo de execução. O cancelamento é cooperativo; portanto, não ocorre imediatamente. Para interromper uma tarefa cancelada, o tempo de execução lança uma exceção interna durante uma chamada subseqüente da tarefa para o tempo de execução. A seção anterior mostra `parallel_for` como usar o algoritmo para melhorar o desempenho da tarefa de desenho. A chamada `parallel_for` para permitir que o tempo de execução interrompa a tarefa e, portanto, permite que o cancelamento funcione.

### <a name="cancelling-active-tasks"></a>Cancelando tarefas ativas

O aplicativo Mandelbrot cria `Bitmap` objetos cujas dimensões correspondem ao tamanho da janela do cliente. Toda vez que a janela do cliente é redimensionada, o aplicativo cria uma tarefa de fundo adicional para gerar uma imagem para o novo tamanho da janela. O aplicativo não requer essas imagens intermediárias; requer apenas a imagem para o tamanho final da janela. Para evitar que o aplicativo execute esse trabalho adicional, você pode cancelar `WM_SIZE` quaisquer `WM_SIZING` tarefas ativas de desenho nos manipuladores de mensagens para as mensagens e, em seguida, reagendar o trabalho de desenho depois que a janela for redimensionada.

Para cancelar tarefas de desenho ativa quando a janela é redimensionada, o aplicativo `WM_SIZING` chama `WM_SIZE` o método [de saque::task_group::cancele](reference/task-group-class.md#cancel) nos manipuladores para as mensagens. O manipulador `WM_SIZE` da mensagem também chama a [concorrência::task_group::aguarde](reference/task-group-class.md#wait) o método para esperar que todas as tarefas ativas sejam concluídas e, em seguida, reagende a tarefa de desenho para o tamanho da janela atualizada.

Quando a janela do cliente é destruída, é uma boa prática cancelar quaisquer tarefas ativas de desenho. O cancelamento de quaisquer tarefas de desenho ativos garante que os segmentos do trabalhador não publiquem mensagens no segmento de ui depois que a janela do cliente for destruída. O aplicativo cancela todas as tarefas `WM_DESTROY` ativas de desenho no manipulador para a mensagem.

### <a name="responding-to-cancellation"></a>Respondendo ao cancelamento

O `CChildView::DrawMandelbrot` método, que executa a tarefa de desenho, deve responder ao cancelamento. Como o tempo de execução usa `CChildView::DrawMandelbrot` o manuseio de exceções para cancelar tarefas, o método deve usar um mecanismo seguro contra exceções para garantir que todos os recursos sejam limpos corretamente. Este exemplo usa o padrão *DE Aquisição de Recursos é initialização* (RAII) para garantir que os bits do bitmap sejam desbloqueados quando a tarefa é cancelada.

##### <a name="to-add-support-for-cancellation-in-the-mandelbrot-application"></a>Para adicionar suporte ao cancelamento no aplicativo Mandelbrot

1. No ChildView.h, `protected` na `CChildView` seção da classe, `OnSize`adicione `OnSizing`declarações para as funções do mapa de mensagens e `OnDestroy` das funções do mapa de mensagens.

   [!code-cpp[concrt-mandelbrot#201](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_15.h)]

1. No ChildView.cpp, modifique o mapa de `WM_SIZE` `WM_SIZING`mensagens `WM_DESTROY` para conter manipuladores para as mensagens e mensagens.

   [!code-cpp[concrt-mandelbrot#202](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_16.cpp)]

1. Implementar o método de `CChildView::OnSizing` . Este método cancela quaisquer tarefas de desenho existentes.

   [!code-cpp[concrt-mandelbrot#203](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_17.cpp)]

1. Implementar o método de `CChildView::OnSize` . Este método cancela quaisquer tarefas de desenho existentes e cria uma nova tarefa de desenho para o tamanho atualizado da janela do cliente.

   [!code-cpp[concrt-mandelbrot#204](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_18.cpp)]

1. Implementar o método de `CChildView::OnDestroy` . Este método cancela quaisquer tarefas de desenho existentes.

   [!code-cpp[concrt-mandelbrot#205](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_19.cpp)]

1. No ChildView.cpp, `scope_guard` defina a classe, que implementa o padrão RAII.

   [!code-cpp[concrt-mandelbrot#206](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_20.cpp)]

1. Adicione o seguinte `CChildView::DrawMandelbrot` código ao método `Bitmap::LockBits`após a chamada para:

   [!code-cpp[concrt-mandelbrot#207](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_21.cpp)]

   Este código lida com `scope_guard` o cancelamento criando um objeto. Quando o objeto deixa o escopo, ele desbloqueia os bits do bitmap.

1. Modifique o `CChildView::DrawMandelbrot` fim do `scope_guard` método para descartar o objeto depois que os bits do bitmap forem desbloqueados, mas antes que quaisquer mensagens sejam enviadas para o segmento de IA. Isso garante que o segmento de IA não seja atualizado antes que os bits do bitmap sejam desbloqueados.

   [!code-cpp[concrt-mandelbrot#208](../../parallel/concrt/codesnippet/cpp/walkthrough-removing-work-from-a-user-interface-thread_22.cpp)]

1. Verifique se o aplicativo foi atualizado com sucesso, construindo e executando-o.

Quando você redimensiona a janela, o trabalho de desenho é realizado apenas para o tamanho final da janela. Quaisquer tarefas ativas de desenho também são canceladas quando a janela é destruída.

[[Top](#top)]

## <a name="see-also"></a>Confira também

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Paralelismo de Tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Aplicativos da área de trabalho MFC](../../mfc/mfc-desktop-applications.md)
