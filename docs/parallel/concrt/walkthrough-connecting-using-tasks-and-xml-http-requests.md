---
title: "Instru&#231;&#245;es passo a passo: conex&#227;o usando tarefas e solicita&#231;&#245;es HTTP XML | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
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
  - "conectar-se aos serviços da web, Windows Store aplicativos [C++]"
  - "IXMLHTTPRequest2 e tarefas, por exemplo:"
  - "IXHR2 e tarefas, por exemplo:"
ms.assetid: e8e12d46-604c-42a7-abfd-b1d1bb2ed6b3
caps.latest.revision: 16
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: conex&#227;o usando tarefas e solicita&#231;&#245;es HTTP XML
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como usar o [IXMLHTTPRequest2](http://msdn.microsoft.com/pt-br/bbc11c4a-aecf-4d6d-8275-3e852e309908) e [IXMLHTTPRequest2Callback](http://msdn.microsoft.com/pt-br/aa4b3f4c-6e28-458b-be25-6cce8865fc71) interfaces junto com tarefas para enviar solicitações HTTP GET e POST para um serviço web em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo. Combinando `IXMLHTTPRequest2` junto com tarefas, você pode escrever código que compõe com outras tarefas. Por exemplo, você pode usar a tarefa de download como parte de uma cadeia de tarefas. A tarefa de download também pode responder quando o trabalho é cancelado.  
  
> [!TIP]
>  Você também pode usar o C\+\+ REST SDK para executar solicitações HTTP de um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo usando o aplicativo C\+\+ ou de um aplicativo da área de trabalho do C\+\+. Para saber mais, veja [C\+\+ REST SDK \(codinome "Casablanca"\)](../../top/cpp-rest-sdk-codename-casablanca.md).  
  
 Para obter mais informações sobre tarefas, consulte [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre como usar tarefas em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo, consulte [Asynchronous programming in C\+\+](http://msdn.microsoft.com/pt-br/512700b7-7863-44cc-93a2-366938052f31) e [Criando operações assíncronas n C\+\+ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).  
  
 Primeiro, este documento mostra como criar `HttpRequest` e suas classes de suporte. Mostra como usar essa classe em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo que usa C\+\+ e XAML.  
  
 Para obter um exemplo mais completo que usa o `HttpReader` classe descritos neste documento, consulte [Desenvolvendo o Bing Maps Trip Optimizer, um aplicativo da Windows Store em JavaScript e C\+\+](../Topic/Developing%20Bing%20Maps%20Trip%20Optimizer,%20a%20Windows%20Store%20app%20in%20JavaScript%20and%20C++.md). Outro exemplo que usa `IXMLHTTPRequest2` mas não usar tarefas, consulte [Quickstart: Connecting using XML HTTP Request \(IXMLHTTPRequest2\)](http://msdn.microsoft.com/pt-br/cc7aed53-b2c5-4d83-b85d-cff2f5ba7b35).  
  
> [!TIP]
>  `IXMLHTTPRequest2` e `IXMLHTTPRequest2Callback` são as interfaces que recomendamos para uso em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo. Você também pode adaptar este exemplo para uso em um aplicativo de área de trabalho.  
  
## Pré-requisitos  
  
## Definindo o HttpRequest, HttpRequestBuffersCallback e HttpRequestStringCallback Classes  
 Quando você usa o `IXMLHTTPRequest2` interface para criar solicitações da web via HTTP, você implementa o `IXMLHTTPRequest2Callback` interface para receber a resposta do servidor e reagir a outros eventos. Este exemplo define o `HttpRequest` classe para criar solicitações da web e o `HttpRequestBuffersCallback` e `HttpRequestStringCallback` classes para processar as respostas. O `HttpRequestBuffersCallback` e `HttpRequestStringCallback` classes oferecem suporte a `HttpRequest` classe; você só funcionam com o `HttpRequest` classe do código do aplicativo.  
  
 O `GetAsync`, `PostAsync` métodos de `HttpRequest` classe permitem iniciar operações HTTP GET e POST, respectivamente. Esses métodos usam o `HttpRequestStringCallback` classe para ler a resposta do servidor como uma cadeia de caracteres. O `SendAsync` e `ReadAsync` métodos permitem que você transmitir conteúdo grandes em partes. Esses métodos retornam [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md) para representar a operação. O `GetAsync` e `PostAsync` métodos produzem `task<std::wstring>` valor, onde o `wstring` parte representa a resposta do servidor. O `SendAsync` e `ReadAsync` métodos produzem `task<void>` valores; essas tarefas concluídas quando concluir as operações de envio e leitura.  
  
 Porque o `IXMLHTTPRequest2` interfaces agir de forma assíncrona, este exemplo usa [concurrency::task\_completion\_event](../../parallel/concrt/reference/task-completion-event-class.md) para criar uma tarefa é concluída depois que o objeto de retorno de chamada é concluída ou cancela a operação de download. O `HttpRequest` classe cria uma continuação baseado em tarefas para definir o resultado final desta tarefa. O `HttpRequest` classe usa uma continuação baseado em tarefas para garantir que a tarefa de continuação seja executada mesmo que a tarefa anterior produz um erro ou é cancelada. Para obter mais informações sobre continuações baseado em tarefas, consulte [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)  
  
 Para dar suporte ao cancelamento, o `HttpRequest`, `HttpRequestBuffersCallback`, e `HttpRequestStringCallback` classes usam tokens de cancelamento. O `HttpRequestBuffersCallback` e `HttpRequestStringCallback` classes usam o [concurrency::cancellation\_token::register\_callback](../Topic/cancellation_token::register_callback%20Method.md) método para permitir que o evento de conclusão de tarefas responder ao cancelamento. Esse retorno de chamada de cancelamento anula o download. Para obter mais informações sobre cancelamento, consulte [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md).  
  
#### Para definir a classe HttpRequest  
  
1.  Usar o Visual C\+\+ **aplicativo em branco \(XAML\)** modelo para criar um projeto de aplicativo em branco XAML. Este exemplo denomina o projeto `UsingIXMLHTTPRequest2`.  
  
2.  Adicione ao projeto um arquivo de cabeçalho chamado HttpRequest.h e um arquivo de origem chamado HttpRequest.cpp.  
  
3.  No pch, adicione este código:  
  
     [!code-cpp[concrt-using-ixhr2#1](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_1.h)]  
  
4.  No HttpRequest.h, adicione este código:  
  
     [!code-cpp[concrt-using-ixhr2#2](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_2.h)]  
  
5.  No HttpRequest.cpp, adicione este código:  
  
     [!code-cpp[concrt-using-ixhr2#3](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_3.cpp)]  
  
## Usando a classe HttpRequest em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo  
 Esta seção demonstra como usar o `HttpRequest` de classe em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo. O aplicativo fornece uma caixa de entrada que define um recurso de URL, e os comandos de botão que executam operações GET e POST e um botão de comando que cancela a operação atual.  
  
#### Para usar a classe HttpRequest  
  
1.  Em MainPage. XAML, definir o [StackPanel](http://msdn.microsoft.com/library/windows/apps/xaml/windows.ui.xaml.controls.stackpanel.aspx) elemento da seguinte maneira.  
  
     [!code-xml[concrt-using-ixhr2#A1](../../parallel/concrt/codesnippet/Xaml/walkthrough-connecting-using-tasks-and-xml-http-requests_4.xaml)]  
  
2.  No MainPage.xaml.h, adicione isso `#include` diretiva:  
  
     [!code-cpp[concrt-using-ixhr2#A2](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_5.h)]  
  
3.  Em MainPage.xaml.h, adicioná\-las `private` variáveis de membro para o `MainPage` classe:  
  
     [!code-cpp[concrt-using-ixhr2#A3](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_6.h)]  
  
4.  No MainPage.xaml.h, declare o `private` método `ProcessHttpRequest`:  
  
     [!code-cpp[concrt-using-ixhr2#A4](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_7.h)]  
  
5.  Em MainPage.xaml.cpp, adicioná\-las `using` instruções:  
  
     [!code-cpp[concrt-using-ixhr2#A5](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_8.cpp)]  
  
6.  No MainPage.xaml.cpp, implemente o `GetButton_Click`, `PostButton_Click`, e `CancelButton_Click` métodos o `MainPage` classe.  
  
     [!code-cpp[concrt-using-ixhr2#A6](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_9.cpp)]  
  
    > [!TIP]
    >  Se seu aplicativo não precisar de suporte para cancelamento, passe [concurrency::cancellation\_token:: nenhum](../Topic/cancellation_token::none%20Method.md) para o `HttpRequest::GetAsync` e `HttpRequest::PostAsync` métodos.  
  
7.  No MainPage.xaml.cpp, implemente o `MainPage::ProcessHttpRequest` método.  
  
     [!code-cpp[concrt-using-ixhr2#A7](../../parallel/concrt/codesnippet/CPP/walkthrough-connecting-using-tasks-and-xml-http-requests_10.cpp)]  
  
8.  Nas propriedades do projeto, em **vinculador**, **entrada**, especificar `shcore.lib` e `msxml6.lib`.  
  
 Aqui está o aplicativo em execução:  
  
 ![O aplicativo de armazenamento do Windows em execução](../../parallel/concrt/media/concrt_usingixhr2.png "ConcRT\_UsingIXHR2")  
  
## Próximas etapas  
 [Instruções passo a passo do Tempo de Execução de Simultaneidade](../Topic/Concurrency%20Runtime%20Walkthroughs.md)  
  
## Consulte também  
 [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)   
 [Asynchronous programming in C\+\+](http://msdn.microsoft.com/pt-br/512700b7-7863-44cc-93a2-366938052f31)   
 [Criando operações assíncronas n C\+\+ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md)   
 [Quickstart: Connecting using XML HTTP Request \(IXMLHTTPRequest2\)](http://msdn.microsoft.com/pt-br/cc7aed53-b2c5-4d83-b85d-cff2f5ba7b35)   
 [Classe task \(Tempo de Execução de Simultaneidade\)](../../parallel/concrt/reference/task-class-concurrency-runtime.md)   
 [Classe task\_completion\_event](../../parallel/concrt/reference/task-completion-event-class.md)   
 [IXMLHTTPRequest2](http://msdn.microsoft.com/pt-br/bbc11c4a-aecf-4d6d-8275-3e852e309908)   
 [IXMLHTTPRequest2Callback](http://msdn.microsoft.com/pt-br/aa4b3f4c-6e28-458b-be25-6cce8865fc71)