---
title: 'Passo a passo: Conectando usando tarefas e solicitações HTTP XML | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- connecting to web services, UWP apps [C++]
- IXMLHTTPRequest2 and tasks, example
- IXHR2 and tasks, example
ms.assetid: e8e12d46-604c-42a7-abfd-b1d1bb2ed6b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 94143580cc65d53a428000fc74b3fb4eafa42e13
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396568"
---
# <a name="walkthrough-connecting-using-tasks-and-xml-http-requests"></a>Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML

Este exemplo mostra como usar o [IXMLHTTPRequest2](/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) e [IXMLHTTPRequest2Callback](/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback) interfaces junto com tarefas enviar solicitações HTTP GET e POST para um serviço web em um Windows UWP (plataforma Universal ) aplicativo. Combinando `IXMLHTTPRequest2` junto com tarefas, você pode escrever código que compõe com outras tarefas. Por exemplo, você pode usar a tarefa de download como parte de uma cadeia de tarefas. A tarefa de download também pode responder quando o trabalho é cancelado.

> [!TIP]
>  Você também pode usar o C++ REST SDK para executar solicitações HTTP de um aplicativo UWP usando o aplicativo em C++ ou de uma aplicativo C++ da área de trabalho. Para obter mais informações, consulte [C++ REST SDK (codinome "Casablanca")](https://github.com/Microsoft/cpprestsdk).

Para obter mais informações sobre tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre como usar tarefas em um aplicativo UWP, consulte [programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) e [criando a operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).

Primeiro, este documento mostra como criar `HttpRequest` e suas classes de suporte. Ela mostra também como usar essa classe de um aplicativo UWP que usa C++ e XAML.

Para obter um exemplo que usa `IXMLHTTPRequest2` , mas não usa tarefas, consulte [guia de início rápido: conectando-se usando a solicitação de HTTP XML (IXMLHTTPRequest2)](/previous-versions/windows/apps/hh770550\(v=win.10\)).

> [!TIP]
>  `IXMLHTTPRequest2` e `IXMLHTTPRequest2Callback` são as interfaces que recomendamos para uso em um aplicativo UWP. Você também pode adaptar este exemplo para uso em um aplicativo da área de trabalho.

## <a name="prerequisites"></a>Pré-requisitos

## <a name="defining-the-httprequest-httprequestbufferscallback-and-httprequeststringcallback-classes"></a>Definindo as Classes HttpRequest, HttpRequestBuffersCallback e HttpRequestStringCallback

Quando você usa o `IXMLHTTPRequest2` da interface para criar solicitações da web via HTTP, você deverá implementar o `IXMLHTTPRequest2Callback` interface para receber a resposta do servidor e reagir a outros eventos. Este exemplo define o `HttpRequest` classe para criar solicitações da web e o `HttpRequestBuffersCallback` e `HttpRequestStringCallback` classes para processar as respostas. O `HttpRequestBuffersCallback` e `HttpRequestStringCallback` classes oferecem suporte a `HttpRequest` classe; você só funcionam com o `HttpRequest` classe do código do aplicativo.

O `GetAsync`, `PostAsync` métodos do `HttpRequest` classe permitem que você inicie operações HTTP GET e POST, respectivamente. Esses métodos usam o `HttpRequestStringCallback` classe para ler a resposta do servidor como uma cadeia de caracteres. O `SendAsync` e `ReadAsync` métodos permitem que você transmitir conteúdo grandes em partes. Esses métodos retornam [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) para representar a operação. O `GetAsync` e `PostAsync` métodos produzem `task<std::wstring>` valor, onde o `wstring` parte representa a resposta do servidor. O `SendAsync` e `ReadAsync` métodos produzem `task<void>` valores; essas tarefas são concluídas quando concluir as operações de envio e leitura.

Porque o `IXMLHTTPRequest2` interfaces agir de forma assíncrona, este exemplo usa [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) para criar uma tarefa que termine após o objeto de retorno de chamada seja concluído ou cancela a operação de download. O `HttpRequest` classe cria uma continuação baseada em tarefas dessa tarefa para definir o resultado final. O `HttpRequest` classe usa uma continuação baseada em tarefas para garantir que a tarefa de continuação seja executada mesmo que a tarefa anterior produz um erro ou é cancelada. Para obter mais informações sobre continuações baseado em tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)

Para dar suporte ao cancelamento, o `HttpRequest`, `HttpRequestBuffersCallback`, e `HttpRequestStringCallback` classes usam tokens de cancelamento. O `HttpRequestBuffersCallback` e `HttpRequestStringCallback` classes usam o [concurrency::cancellation_token::register_callback](reference/cancellation-token-class.md#register_callback) método para habilitar o evento de conclusão de tarefa responder ao cancelamento. Esse retorno de chamada de cancelamento anula o download. Para obter mais informações sobre cancelamento, consulte [cancelamento](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

#### <a name="to-define-the-httprequest-class"></a>Para Definir a Classe HttpRequest

1. Usar o Visual C++ **aplicativo em branco (XAML)** modelo para criar um projeto de aplicativo em branco do XAML. Este exemplo denomina o projeto `UsingIXMLHTTPRequest2`.

1. Adicione ao projeto um arquivo de cabeçalho chamado HttpRequest.h e um arquivo de origem chamado HttpRequest.

1. Em pch. h, adicione este código:

     [!code-cpp[concrt-using-ixhr2#1](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_1.h)]

1. No HttpRequest.h, adicione este código:

     [!code-cpp[concrt-using-ixhr2#2](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_2.h)]

1. Na HttpRequest, adicione este código:

     [!code-cpp[concrt-using-ixhr2#3](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_3.cpp)]

## <a name="using-the-httprequest-class-in-a-uwp-app"></a>Usando a classe HttpRequest em um aplicativo UWP

Esta seção demonstra como usar o `HttpRequest` classe em um aplicativo UWP. O aplicativo fornece uma caixa de entrada que define um recurso de URL, e os comandos de botão que executam operações GET e POST e um botão de comando que cancela a operação atual.

#### <a name="to-use-the-httprequest-class"></a>Para Usar a Classe HttpRequest

1. Em MainPage. XAML, defina as [StackPanel](https://msdn.microsoft.com/library/windows/apps/xaml/windows.ui.xaml.controls.stackpanel.aspx) elemento da seguinte maneira.

     [!code-xml[concrt-using-ixhr2#A1](../../parallel/concrt/codesnippet/xaml/walkthrough-connecting-using-tasks-and-xml-http-requests_4.xaml)]

1. Em MainPage, adicione isso `#include` diretiva:

     [!code-cpp[concrt-using-ixhr2#A2](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_5.h)]

1. Em MainPage, adicione estas `private` variáveis de membro a `MainPage` classe:

     [!code-cpp[concrt-using-ixhr2#A3](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_6.h)]

1. Em MainPage, declare a `private` método `ProcessHttpRequest`:

     [!code-cpp[concrt-using-ixhr2#A4](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_7.h)]

1. Em MainPage, adicione estas `using` instruções:

     [!code-cpp[concrt-using-ixhr2#A5](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_8.cpp)]

1. Em MainPage, implemente a `GetButton_Click`, `PostButton_Click`, e `CancelButton_Click` métodos do `MainPage` classe.

     [!code-cpp[concrt-using-ixhr2#A6](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_9.cpp)]

    > [!TIP]

    >  Se seu aplicativo não exija o suporte para cancelamento, passe [cancellation_token:: none](reference/cancellation-token-class.md#none) para o `HttpRequest::GetAsync` e `HttpRequest::PostAsync` métodos.

1. Em MainPage, implemente o `MainPage::ProcessHttpRequest` método.

     [!code-cpp[concrt-using-ixhr2#A7](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_10.cpp)]

1. Nas propriedades do projeto, sob **vinculador**, **entrada**, especifique `shcore.lib` e `msxml6.lib`.

Aqui está o aplicativo em execução:

![O aplicativo de tempo de execução do Windows em execução](../../parallel/concrt/media/concrt_usingixhr2.png "concrt_usingixhr2")

## <a name="next-steps"></a>Próximas etapas

[Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)

## <a name="see-also"></a>Consulte também

[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps)<br/>
[Criando operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md)<br/>
[Guia de início rápido: Conectando-se usando a solicitação de HTTP XML (IXMLHTTPRequest2)](/previous-versions/windows/apps/hh770550\(v=win.10\))
[(tempo de execução de simultaneidade) da classe task](../../parallel/concrt/reference/task-class.md)<br/>
[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)
