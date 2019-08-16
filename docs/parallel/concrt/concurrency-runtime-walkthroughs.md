---
title: Instruções passo a passo do Tempo de Execução de Simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- walkthroughs [Concurrency Runtime]
- Concurrency Runtime, walkthroughs
ms.assetid: 7374c5e9-54eb-44bf-9ed9-5e190cfd290b
ms.openlocfilehash: 7c5973f8010d7c428406a8a3f69574eab20edf82
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512832"
---
# <a name="concurrency-runtime-walkthroughs"></a>Instruções passo a passo do Tempo de Execução de Simultaneidade

Os tópicos baseados em cenários nesta seção mostram como usar muitos dos recursos do Tempo de Execução de Simultaneidade.

## <a name="in-this-section"></a>Nesta seção

[Passo a passo: Conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)<br/>
Mostra como usar as interfaces [IXMLHTTPRequest2](/windows/win32/api/msxml6/nn-msxml6-ixmlhttprequest2) e [IXMLHTTPRequest2Callback](/windows/win32/api/msxml6/nn-msxml6-ixmlhttprequest2callback) junto com as tarefas para enviar solicitações HTTP Get e post para um serviço Web em um aplicativo de plataforma universal do Windows (UWP).

[Passo a passo: Criando um aplicativo com base em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)<br/>
Descreve como criar um aplicativo básico baseado em agente.

[Passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)<br/>
Demonstra como criar aplicativos baseados em agente baseados em Dataflow, em vez de no fluxo de controle.

[Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)<br/>
Demonstra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagens.

[Passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)<br/>
Mostra como computar valores de forma assíncrona para uso posterior.

[Passo a passo: Usando join para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)<br/>
Usa o problema do jantar filósofos para ilustrar como usar a classe [Concurrency:: join](../../parallel/concrt/reference/join-class.md) para evitar o deadlock em seu aplicativo.

[Passo a passo: Removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)<br/>
Demonstra como melhorar o desempenho de um aplicativo MFC que desenha o fractal Mandelbrot.

[Passo a passo: Usando o Tempo de Execução de Simultaneidade em um aplicativo habilitado para COM](../../parallel/concrt/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application.md)<br/>
Demonstra como usar o Tempo de Execução de Simultaneidade em um aplicativo que usa a Component Object Model (COM).

[Passo a passo: Adaptando um código existente para usar tarefas leves](../../parallel/concrt/walkthrough-adapting-existing-code-to-use-lightweight-tasks.md)<br/>
Mostra como adaptar o código existente que usa a API do Windows para criar e executar um thread para usar uma tarefa leve.

[Passo a passo: Criar um bloco de mensagem personalizado](../../parallel/concrt/walkthrough-creating-a-custom-message-block.md)<br/>
Descreve como criar um tipo de bloco de mensagens personalizado que ordena mensagens de entrada por prioridade.

## <a name="related-sections"></a>Seções relacionadas

[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
Apresenta a estrutura de programação simultânea para Visual C++.
