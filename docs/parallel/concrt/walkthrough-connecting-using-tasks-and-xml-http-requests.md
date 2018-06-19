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
ms.openlocfilehash: 411d52201aad69a94267615cd0a2acbe6376f64d
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33692581"
---
# <a name="walkthrough-connecting-using-tasks-and-xml-http-requests"></a>Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML
Este exemplo mostra como usar o [IXMLHTTPRequest2](http://msdn.microsoft.com/en-us/bbc11c4a-aecf-4d6d-8275-3e852e309908) e [IXMLHTTPRequest2Callback](http://msdn.microsoft.com/en-us/aa4b3f4c-6e28-458b-be25-6cce8865fc71) interfaces junto com as tarefas para enviar solicitações HTTP GET e POST para um serviço da web em um Windows UWP (plataforma Universal ) aplicativo. Combinando `IXMLHTTPRequest2` junto com as tarefas, você pode escrever código que compõe com outras tarefas. Por exemplo, você pode usar a tarefa de download como parte de uma cadeia de tarefas. A tarefa de download também pode responder quando o trabalho foi cancelado.  
  
> [!TIP]
>  Você também pode usar o C++ REST SDK para executar solicitações HTTP de um aplicativo UWP usando o aplicativo em C++ ou de uma aplicativo em C++ da área de trabalho. Para obter mais informações, consulte [C++ REST SDK (codinome "Casablanca")](https://github.com/Microsoft/cpprestsdk).  
  
 Para obter mais informações sobre tarefas, consulte [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre como usar tarefas em um aplicativo UWP, consulte [programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) e [criando a operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).  
  
 Este documento mostra como criar inicialmente `HttpRequest` e suas classes de suporte. Em seguida, mostra como usar essa classe de um aplicativo UWP que usa C++ e XAML.  
  
 Para obter um exemplo mais completo que usa o `HttpReader` classe descritas neste documento, consulte [desenvolvendo Bing Maps Trip Optimizer, um aplicativo da Windows Store em JavaScript e C++](http://msdn.microsoft.com/library/974cf025-de1a-4299-b7dd-c6c7bf0e5d30). Para obter outro exemplo que usa `IXMLHTTPRequest2` , mas não usa tarefas, consulte [início rápido: conectando-se com a solicitação de HTTP XML (IXMLHTTPRequest2)](http://msdn.microsoft.com/en-us/cc7aed53-b2c5-4d83-b85d-cff2f5ba7b35).  
  
> [!TIP]
>  `IXMLHTTPRequest2` e `IXMLHTTPRequest2Callback` são as interfaces que recomendamos para uso em um aplicativo UWP. Você também pode adaptar este exemplo para uso em um aplicativo de área de trabalho.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
## <a name="defining-the-httprequest-httprequestbufferscallback-and-httprequeststringcallback-classes"></a>Definindo as Classes HttpRequest, HttpRequestBuffersCallback e HttpRequestStringCallback  
 Quando você usa o `IXMLHTTPRequest2` a interface para criar solicitações da web via HTTP, você implementa o `IXMLHTTPRequest2Callback` interface para receber a resposta do servidor e reagir a outros eventos. Este exemplo define o `HttpRequest` classe para criar solicitações da web e o `HttpRequestBuffersCallback` e `HttpRequestStringCallback` classes para processar respostas. O `HttpRequestBuffersCallback` e `HttpRequestStringCallback` classes oferecem suporte a `HttpRequest` classe; você só funcionam com o `HttpRequest` classe do código do aplicativo.  
  
 O `GetAsync`, `PostAsync` métodos de `HttpRequest` classe permitem que você inicie operações HTTP GET e POST, respectivamente. Esses métodos usam o `HttpRequestStringCallback` classe para ler a resposta do servidor como uma cadeia de caracteres. O `SendAsync` e `ReadAsync` métodos permitem que você para transmitir o conteúdo grande em partes. Esses métodos retornam [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) para representar a operação. O `GetAsync` e `PostAsync` métodos produzem `task<std::wstring>` valor, onde o `wstring` parte representa a resposta do servidor. O `SendAsync` e `ReadAsync` métodos produzem `task<void>` valores; essas tarefas concluídas quando concluir as operações de envio e leitura.  
  
 Porque o `IXMLHTTPRequest2` interfaces agir de forma assíncrona, este exemplo usa [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) para criar uma tarefa que é concluída depois que o objeto de retorno de chamada é concluída ou cancela a operação de download. O `HttpRequest` classe cria uma continuação de tarefas para definir o resultado final desta tarefa. O `HttpRequest` classe usa uma continuação de tarefas para garantir que a tarefa de continuação é executada mesmo que a tarefa anterior produz um erro ou for cancelada. Para obter mais informações sobre as continuações baseado em tarefa, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)  
  
 Para oferecer suporte ao cancelamento, o `HttpRequest`, `HttpRequestBuffersCallback`, e `HttpRequestStringCallback` classes usam tokens de cancelamento. O `HttpRequestBuffersCallback` e `HttpRequestStringCallback` uso de classes de [concurrency::cancellation_token::register_callback](reference/cancellation-token-class.md#register_callback) método para permitir que o evento de conclusão de tarefas responder ao cancelamento. Esse retorno de chamada de cancelamento anula o download. Para obter mais informações sobre cancelamento, consulte [cancelamento](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).  
  
#### <a name="to-define-the-httprequest-class"></a>Para Definir a Classe HttpRequest  
  
1.  Use o Visual C++ **aplicativo em branco (XAML)** modelo para criar um projeto de aplicativo XAML em branco. Este exemplo denomina o projeto `UsingIXMLHTTPRequest2`.  
  
2.  Adicione ao projeto um arquivo de cabeçalho chamado HttpRequest.h e um arquivo de origem que é chamado HttpRequest.cpp.  
  
3.  Em pch. h, adicione este código:  
  
     [!code-cpp[concrt-using-ixhr2#1](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_1.h)]  
  
4.  No HttpRequest.h, adicione este código:  
  
     [!code-cpp[concrt-using-ixhr2#2](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_2.h)]  
  
5.  No HttpRequest.cpp, adicione este código:  
  
     [!code-cpp[concrt-using-ixhr2#3](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_3.cpp)]  
  
## <a name="using-the-httprequest-class-in-a-uwp-app"></a>Usando a classe de HttpRequest em um aplicativo UWP  
 Esta seção demonstra como usar o `HttpRequest` classe em um aplicativo UWP. O aplicativo fornece uma caixa de entrada que define um recurso de URL, e comandos do botão que executam operações GET e POST e um botão de comando que cancela a operação atual.  
  
#### <a name="to-use-the-httprequest-class"></a>Para Usar a Classe HttpRequest  
  
1.  Em MainPage. XAML, definir o [StackPanel](http://msdn.microsoft.com/library/windows/apps/xaml/windows.ui.xaml.controls.stackpanel.aspx) elemento da seguinte maneira.  
  
     [!code-xml[concrt-using-ixhr2#A1](../../parallel/concrt/codesnippet/xaml/walkthrough-connecting-using-tasks-and-xml-http-requests_4.xaml)]  
  
2.  Em MainPage.xaml.h, adicionar `#include` diretiva:  
  
     [!code-cpp[concrt-using-ixhr2#A2](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_5.h)]  
  
3.  Em MainPage.xaml.h, adicione estas `private` variáveis de membro para o `MainPage` classe:  
  
     [!code-cpp[concrt-using-ixhr2#A3](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_6.h)]  
  
4.  No MainPage.xaml.h, declare o `private` método `ProcessHttpRequest`:  
  
     [!code-cpp[concrt-using-ixhr2#A4](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_7.h)]  
  
5.  Em MainPage.xaml.cpp, adicione estas `using` instruções:  
  
     [!code-cpp[concrt-using-ixhr2#A5](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_8.cpp)]  
  
6.  MainPage.xaml.cpp, implementar a `GetButton_Click`, `PostButton_Click`, e `CancelButton_Click` métodos de `MainPage` classe.  
  
     [!code-cpp[concrt-using-ixhr2#A6](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_9.cpp)]  
  
    > [!TIP]


    >  Se seu aplicativo não exigir suporte para cancelamento, passar [Concurrency:: none](reference/cancellation-token-class.md#none) para o `HttpRequest::GetAsync` e `HttpRequest::PostAsync` métodos.  


  
7.  No MainPage.xaml.cpp, implemente o `MainPage::ProcessHttpRequest` método.  
  
     [!code-cpp[concrt-using-ixhr2#A7](../../parallel/concrt/codesnippet/cpp/walkthrough-connecting-using-tasks-and-xml-http-requests_10.cpp)]  
  
8.  Nas propriedades do projeto, em **vinculador**, **entrada**, especifique `shcore.lib` e `msxml6.lib`.  
  
 Aqui está o aplicativo em execução:  
  
 ![O aplicativo de tempo de execução do Windows em execução](../../parallel/concrt/media/concrt_usingixhr2.png "concrt_usingixhr2")  
  
## <a name="next-steps"></a>Próximas etapas  
 [Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)  
  
## <a name="see-also"></a>Consulte também  
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Cancelamento no PPL](cancellation-in-the-ppl.md)   
 [Programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps)   
 [Criando operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md)   
 [Início rápido: Conectando-se com a solicitação de HTTP XML (IXMLHTTPRequest2)](http://msdn.microsoft.com/en-us/cc7aed53-b2c5-4d83-b85d-cff2f5ba7b35)   
 [tarefa de classe (tempo de execução de simultaneidade)](../../parallel/concrt/reference/task-class.md)   
 [Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)
