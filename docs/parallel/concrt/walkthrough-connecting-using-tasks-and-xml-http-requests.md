---
title: 'Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML'
ms.date: 04/25/2019
helpviewer_keywords:
- connecting to web services, UWP apps [C++]
- IXMLHTTPRequest2 and tasks, example
- IXHR2 and tasks, example
ms.assetid: e8e12d46-604c-42a7-abfd-b1d1bb2ed6b3
ms.openlocfilehash: 2c627a543ec18702bf5358ff0170bec177fd7497
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032259"
---
# <a name="walkthrough-connecting-using-tasks-and-xml-http-requests"></a>Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML

Este exemplo mostra como usar as interfaces [IXMLHTTPRequest2](/windows/win32/api/msxml6/nn-msxml6-ixmlhttprequest2) e [IXMLHTTPRequest2Callback](/windows/win32/api/msxml6/nn-msxml6-ixmlhttprequest2callback) juntamente com tarefas para enviar solicitações HTTP GET e POST para um serviço web em um aplicativo Universal Windows Platform (UWP). Combinando `IXMLHTTPRequest2` com tarefas, você pode escrever código que compõe com outras tarefas. Por exemplo, você pode usar a tarefa de download como parte de uma cadeia de tarefas. A tarefa de download também pode responder quando o trabalho é cancelado.

> [!TIP]
> Você também pode usar o C++ REST SDK para realizar solicitações HTTP a partir de um aplicativo UWP usando o aplicativo C++ ou a partir de um aplicativo C++ desktop. Para obter mais informações, consulte [C++ REST SDK (Codinome "Casablanca").](https://github.com/Microsoft/cpprestsdk)

Para obter mais informações sobre tarefas, consulte [O Paralelismo da Tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre como usar tarefas em um aplicativo UWP, consulte [programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) e [Criando Operações Assíncronas em C++ para Aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).

Este documento mostra primeiro `HttpRequest` como criar e suas classes de suporte. Em seguida, ele mostra como usar esta classe a partir de um aplicativo UWP que usa C++ e XAML.

Para um exemplo `IXMLHTTPRequest2` que usa, mas não usa tarefas, consulte [Quickstart: Conectando usando a solicitação XML HTTP (IXMLHTTPRequest2)](/previous-versions/windows/apps/hh770550\(v=win.10\)).

> [!TIP]
> `IXMLHTTPRequest2`e `IXMLHTTPRequest2Callback` são as interfaces que recomendamos para uso em um aplicativo UWP. Você também pode adaptar este exemplo para uso em um aplicativo de desktop.

## <a name="prerequisites"></a>Pré-requisitos

O suporte ao UWP é opcional no Visual Studio 2017 e posterior. Para instalá-lo, abra o Visual Studio Installer no menu Windows Start e escolha a versão do Visual Studio que você está usando. Clique no botão **Modificar** e certifique-se de que o bloco **de desenvolvimento UWP** seja verificado. Em **Componentes Opcionais** certifique-se de que **as ferramentas C++ UWP** sejam verificadas. Use v141 para visual studio 2017 ou v142 para Visual Studio 2019.

## <a name="defining-the-httprequest-httprequestbufferscallback-and-httprequeststringcallback-classes"></a>Definindo as Classes HttpRequest, HttpRequestBuffersCallback e HttpRequestStringCallback

Quando você `IXMLHTTPRequest2` usa a interface para criar solicitações da Web em HTTP, você implementa a `IXMLHTTPRequest2Callback` interface para receber a resposta do servidor e reagir a outros eventos. Este exemplo define `HttpRequest` a classe para criar `HttpRequestBuffersCallback` `HttpRequestStringCallback` solicitações web e as classes para processar respostas. As `HttpRequestBuffersCallback` `HttpRequestStringCallback` aulas apoiam `HttpRequest` a classe; você trabalha apenas `HttpRequest` com a classe a partir do código do aplicativo.

Os `GetAsync` `PostAsync` métodos da `HttpRequest` classe permitem iniciar as operações HTTP GET e POST, respectivamente. Esses métodos `HttpRequestStringCallback` usam a classe para ler a resposta do servidor como uma string. Os `SendAsync` `ReadAsync` métodos permitem que você transmita grandes conteúdos em pedaços. Esses métodos [cada retorno conmoeda::tarefa](../../parallel/concrt/reference/task-class.md) para representar a operação. Os `GetAsync` `PostAsync` métodos `task<std::wstring>` produzem valor, `wstring` onde a peça representa a resposta do servidor. Os `SendAsync` `ReadAsync` métodos `task<void>` produzem valores; essas tarefas são concluídas quando as operações de envio e leitura são concluídas.

Como `IXMLHTTPRequest2` as interfaces agem assíncronamente, este exemplo usa [a simultâneo::task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) criar uma tarefa que seja concluída após o objeto de retorno de chamada concluir ou cancelar a operação de download. A `HttpRequest` classe cria uma continuação baseada em tarefas a partir desta tarefa para definir o resultado final. A `HttpRequest` classe usa uma continuação baseada em tarefas para garantir que a tarefa de continuação seja executada mesmo que a tarefa anterior produza um erro ou seja cancelada. Para obter mais informações sobre continuações baseadas em tarefas, consulte [O Paralelismo da Tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)

Para suportar o `HttpRequest` `HttpRequestBuffersCallback`cancelamento, `HttpRequestStringCallback` as classes e as classes usam tokens de cancelamento. As `HttpRequestBuffersCallback` `HttpRequestStringCallback` classes e as classes usam o método [simultâneo::cancellation_token::register_callback](reference/cancellation-token-class.md#register_callback) para permitir que o evento de conclusão de tarefas responda ao cancelamento. Este retorno de chamada de cancelamento aborta o download. Para obter mais informações sobre o cancelamento, consulte [Cancelamento](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

### <a name="to-define-the-httprequest-class"></a>Para Definir a Classe HttpRequest

1. No menu principal, escolha **Arquivo** > **Novo** > **Projeto**.

1. Use o modelo C++ **Blank App (Universal Windows)** para criar um projeto de aplicativo XAML em branco. Este exemplo nomeia o projeto `UsingIXMLHTTPRequest2`.

1. Adicione ao projeto um arquivo de cabeçalho chamado HttpRequest.h e um arquivo de origem chamado HttpRequest.cpp.

1. Em pch.h, adicione este código:

   [!code-cpp[concrt-using-ixhr2#1](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_1.h)]

1. Em HttpRequest.h, adicione este código:

   [!code-cpp[concrt-using-ixhr2#2](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_2.h)]

1. Em HttpRequest.cpp, adicione este código:

   [!code-cpp[concrt-using-ixhr2#3](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_3.cpp)]

## <a name="using-the-httprequest-class-in-a-uwp-app"></a>Usando a classe HttpRequest em um aplicativo UWP

Esta seção demonstra `HttpRequest` como usar a classe em um aplicativo UWP. O aplicativo fornece uma caixa de entrada que define um recurso de URL e comandos de botão que executam operações GET e POST, e um comando de botão que cancela a operação atual.

### <a name="to-use-the-httprequest-class"></a>Para Usar a Classe HttpRequest

1. No MainPage.xaml, defina o elemento [StackPanel](/uwp/api/windows.ui.xaml.controls.stackpanel) da seguinte forma.

   [!code-xml[concrt-using-ixhr2#A1](../../parallel/concrt/codesnippet/xaml/walkthrough-connecting-using-tasks-and-xml-http-requests_4.xaml)]

1. No MainPage.xaml.h, `#include` adicione esta diretiva:

   [!code-cpp[concrt-using-ixhr2#A2](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_5.h)]

1. No MainPage.xaml.h, `private` adicione essas variáveis `MainPage` de membro à classe:

   [!code-cpp[concrt-using-ixhr2#A3](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_6.h)]

1. Em MainPage.xaml.h, `private` declare `ProcessHttpRequest`o método :

   [!code-cpp[concrt-using-ixhr2#A4](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_7.h)]

1. No MainPage.xaml.cpp, `using` adicione essas instruções:

   [!code-cpp[concrt-using-ixhr2#A5](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_8.cpp)]

1. No MainPage.xaml.cpp, `GetButton_Click`implemente os `PostButton_Click`métodos e `CancelButton_Click` métodos da `MainPage` classe.

   [!code-cpp[concrt-using-ixhr2#A6](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_9.cpp)]

   > [!TIP]
   > Se o aplicativo não precisar de suporte para cancelamento, passe `HttpRequest::GetAsync` para `HttpRequest::PostAsync` [o saque::cancellation_token::nenhum](reference/cancellation-token-class.md#none) para os métodos e métodos.

1. No MainPage.xaml.cpp, `MainPage::ProcessHttpRequest` implemente o método.

   [!code-cpp[concrt-using-ixhr2#A7](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_10.cpp)]

1. Nas propriedades do projeto, em **Linker,** **Entrada,** especificação `shcore.lib` e `msxml6.lib`.

Aqui está o aplicativo em execução:

![O aplicativo de execução do Windows Runtime](../../parallel/concrt/media/concrt_usingixhr2.png "O aplicativo de execução do Windows Runtime")

## <a name="next-steps"></a>Próximas etapas

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)

## <a name="see-also"></a>Confira também

[Paralelismo de Tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps)<br/>
[Criando operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md)<br/>
[Início rápido: Conectando-se usando a classe de tarefa sinuosa (IXMLHTTPRequest2)](/previous-versions/windows/apps/hh770550\(v=win.10\))
[(Tempo de execução da concorrência)](../../parallel/concrt/reference/task-class.md)<br/>
[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)
