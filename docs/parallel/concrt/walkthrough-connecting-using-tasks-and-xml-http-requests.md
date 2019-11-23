---
title: 'Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML'
ms.date: 04/25/2019
helpviewer_keywords:
- connecting to web services, UWP apps [C++]
- IXMLHTTPRequest2 and tasks, example
- IXHR2 and tasks, example
ms.assetid: e8e12d46-604c-42a7-abfd-b1d1bb2ed6b3
ms.openlocfilehash: b11b56578cadc4b3bd037acf84014a718f9fad84
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "69512139"
---
# <a name="walkthrough-connecting-using-tasks-and-xml-http-requests"></a>Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML

Este exemplo mostra como usar as interfaces [IXMLHTTPRequest2](/windows/win32/api/msxml6/nn-msxml6-ixmlhttprequest2) e [IXMLHTTPRequest2Callback](/windows/win32/api/msxml6/nn-msxml6-ixmlhttprequest2callback) junto com as tarefas para enviar solicitações HTTP Get e post para um serviço Web em um aplicativo de plataforma universal do Windows (UWP). Ao combinar `IXMLHTTPRequest2` junto com as tarefas, você pode escrever código que compõe outras tarefas. Por exemplo, você pode usar a tarefa de download como parte de uma cadeia de tarefas. A tarefa de download também pode responder quando o trabalho é cancelado.

> [!TIP]
>  Você também pode usar o C++ SDK REST para executar solicitações HTTP de um aplicativo UWP usando C++ o aplicativo ou de um C++ aplicativo de desktop. Para obter mais informações, consulte [ C++ REST SDK (codinome "Casablanca")](https://github.com/Microsoft/cpprestsdk).

Para obter mais informações sobre tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre como usar tarefas em um aplicativo UWP, consulte [programação assíncrona C++ no](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) e [criando operações assíncronas no C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).

Este documento mostra primeiro como criar `HttpRequest` e suas classes de suporte. Em seguida, ele mostra como usar essa classe de um aplicativo UWP que C++ usa o e o XAML.

Para obter um exemplo que usa `IXMLHTTPRequest2` mas não usa tarefas, consulte [início rápido: conectando usando a solicitação XML http (IXMLHTTPRequest2)](/previous-versions/windows/apps/hh770550\(v=win.10\)).

> [!TIP]
>  `IXMLHTTPRequest2` e `IXMLHTTPRequest2Callback` são as interfaces que recomendamos para uso em um aplicativo UWP. Você também pode adaptar este exemplo para uso em um aplicativo de área de trabalho.

## <a name="prerequisites"></a>{1&gt;Pré-requisitos&lt;1}

O suporte a UWP é opcional no Visual Studio 2017 e posterior. Para instalá-lo, abra o Instalador do Visual Studio no menu Iniciar do Windows e escolha a versão do Visual Studio que você está usando. Clique no botão **Modificar** e verifique se o bloco de **desenvolvimento UWP** está marcado. Em **componentes opcionais** , verifique se  **C++ as ferramentas UWP** estão marcadas. Use o v141 para Visual Studio 2017 ou v142 para Visual Studio 2019.

## <a name="defining-the-httprequest-httprequestbufferscallback-and-httprequeststringcallback-classes"></a>Definindo as Classes HttpRequest, HttpRequestBuffersCallback e HttpRequestStringCallback

Quando você usa a interface `IXMLHTTPRequest2` para criar solicitações da Web por HTTP, você implementa a interface `IXMLHTTPRequest2Callback` para receber a resposta do servidor e reagir a outros eventos. Este exemplo define a classe `HttpRequest` para criar solicitações da Web e as classes `HttpRequestBuffersCallback` e `HttpRequestStringCallback` para processar respostas. As classes `HttpRequestBuffersCallback` e `HttpRequestStringCallback` dão suporte à classe `HttpRequest`; Você só trabalha com a classe `HttpRequest` do código do aplicativo.

A `GetAsync`, `PostAsync` métodos da classe `HttpRequest` permitem que você inicie operações HTTP GET e POST, respectivamente. Esses métodos usam a classe `HttpRequestStringCallback` para ler a resposta do servidor como uma cadeia de caracteres. Os métodos `SendAsync` e `ReadAsync` permitem que você transmita conteúdo grande em partes. Cada um dos métodos retorna [simultaneidade:: Task](../../parallel/concrt/reference/task-class.md) para representar a operação. Os métodos `GetAsync` e `PostAsync` produzem `task<std::wstring>` valor, em que a parte `wstring` representa a resposta do servidor. Os métodos `SendAsync` e `ReadAsync` produzem `task<void>` valores; essas tarefas são concluídas quando as operações de envio e leitura são concluídas.

Como as interfaces de `IXMLHTTPRequest2` atuam de forma assíncrona, este exemplo usa [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) para criar uma tarefa que é concluída depois que o objeto de retorno de chamada é concluído ou cancela a operação de download. A classe `HttpRequest` cria uma continuação baseada em tarefa a partir dessa tarefa para definir o resultado final. A classe `HttpRequest` usa uma continuação baseada em tarefa para garantir que a tarefa de continuação seja executada mesmo que a tarefa anterior produza um erro ou seja cancelada. Para obter mais informações sobre as continuações baseadas em tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)

Para dar suporte ao cancelamento, as classes `HttpRequest`, `HttpRequestBuffersCallback`e `HttpRequestStringCallback` usam tokens de cancelamento. As classes `HttpRequestBuffersCallback` e `HttpRequestStringCallback` usam o método [Concurrency:: cancellation_token:: register_callback](reference/cancellation-token-class.md#register_callback) para permitir que o evento de conclusão da tarefa responda ao cancelamento. Esse retorno de chamada de cancelamento anula o download. Para obter mais informações sobre o cancelamento, consulte [cancelamento](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

#### <a name="to-define-the-httprequest-class"></a>Para Definir a Classe HttpRequest

1. No menu principal, escolha **arquivo** > **novo** **projeto**de > . 

1. Use o C++ modelo de **aplicativo em branco (universal do Windows)** para criar um projeto de aplicativo XAML em branco. Este exemplo nomeia o projeto `UsingIXMLHTTPRequest2`.

1. Adicione ao projeto um arquivo de cabeçalho chamado HttpRequest. h e um arquivo de origem chamado HttpRequest. cpp.

1. Em PCH. h, adicione este código:

   [!code-cpp[concrt-using-ixhr2#1](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_1.h)]

1. Em HttpRequest. h, adicione este código:

   [!code-cpp[concrt-using-ixhr2#2](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_2.h)]

1. Em HttpRequest. cpp, adicione este código:

   [!code-cpp[concrt-using-ixhr2#3](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_3.cpp)]

## <a name="using-the-httprequest-class-in-a-uwp-app"></a>Usando a classe HttpRequest em um aplicativo UWP

Esta seção demonstra como usar a classe `HttpRequest` em um aplicativo UWP. O aplicativo fornece uma caixa de entrada que define um recurso de URL e comandos de botão que executam operações GET e POST e um comando de botão que cancela a operação atual.

#### <a name="to-use-the-httprequest-class"></a>Para Usar a Classe HttpRequest

1. Em MainPage. XAML, defina o elemento [StackPanel](/uwp/api/Windows.UI.Xaml.Controls.StackPanel) da seguinte maneira.

   [!code-xml[concrt-using-ixhr2#A1](../../parallel/concrt/codesnippet/xaml/walkthrough-connecting-using-tasks-and-xml-http-requests_4.xaml)]

2. Em MainPage. XAML. h, adicione esta diretiva de `#include`:

   [!code-cpp[concrt-using-ixhr2#A2](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_5.h)]

3. Em MainPage. XAML. h, adicione essas `private` variáveis de membro à classe `MainPage`:

   [!code-cpp[concrt-using-ixhr2#A3](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_6.h)]

4. Em MainPage. XAML. h, declare o método de `private` `ProcessHttpRequest`:

   [!code-cpp[concrt-using-ixhr2#A4](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_7.h)]

5. Em MainPage. XAML. cpp, adicione estas `using` instruções:

   [!code-cpp[concrt-using-ixhr2#A5](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_8.cpp)]

6. Em MainPage. XAML. cpp, implemente os métodos `GetButton_Click`, `PostButton_Click`e `CancelButton_Click` da classe `MainPage`.

   [!code-cpp[concrt-using-ixhr2#A6](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_9.cpp)]

   > [!TIP]
   > Se seu aplicativo não precisar de suporte para cancelamento, passe [Concurrency:: cancellation_token:: None](reference/cancellation-token-class.md#none) para os métodos `HttpRequest::GetAsync` e `HttpRequest::PostAsync`.

1. Em MainPage. XAML. cpp, implemente o método `MainPage::ProcessHttpRequest`.

   [!code-cpp[concrt-using-ixhr2#A7](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_10.cpp)]

8. Nas propriedades do projeto, em **linker**, **insira**, especifique `shcore.lib` e `msxml6.lib`.

Este é o aplicativo em execução:

![O aplicativo de Windows Runtime em execução](../../parallel/concrt/media/concrt_usingixhr2.png "no aplicativo em execução Windows Runtime")

## <a name="next-steps"></a>Próximas etapas

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)

## <a name="see-also"></a>Consulte também

[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Programação assíncrona emC++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps)<br/>
[Criando operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md)<br/>
[Início rápido: conectando usando a IXMLHTTPRequest2 (solicitação de http XML)](/previous-versions/windows/apps/hh770550\(v=win.10\))
[classe de tarefa (tempo de execução de simultaneidade)](../../parallel/concrt/reference/task-class.md)<br/>
[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)
