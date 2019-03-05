---
title: Instruções passo a passo do Tempo de Execução de Simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- walkthroughs [Concurrency Runtime]
- Concurrency Runtime, walkthroughs
ms.assetid: 7374c5e9-54eb-44bf-9ed9-5e190cfd290b
ms.openlocfilehash: d176049bb3b03ae0f55170e45e20e7c2c0e322ff
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57296404"
---
# <a name="concurrency-runtime-walkthroughs"></a>Instruções passo a passo do Tempo de Execução de Simultaneidade

Os tópicos com base no cenário nesta seção mostram como usar muitos dos recursos do tempo de execução de simultaneidade.

## <a name="in-this-section"></a>Nesta seção

[Passo a passo: Conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)<br/>
Mostra como usar o [IXMLHTTPRequest2](/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) e [IXMLHTTPRequest2Callback](/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback) interfaces junto com tarefas enviar solicitações HTTP GET e POST para um serviço web em um aplicativo da plataforma Universal do Windows (UWP).

[Passo a passo: Criando um aplicativo com base em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)<br/>
Descreve como criar um aplicativo básico com base em agente.

[Passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)<br/>
Demonstra como criar aplicativos baseados em agente que se baseiam no fluxo de dados, em vez de fluxo de controle.

[Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)<br/>
Demonstra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagem.

[Passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)<br/>
Mostra como calcular valores para uso posterior de forma assíncrona.

[Passo a passo: Usando join para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)<br/>
Usa o problema de filósofos jantar para ilustrar como usar o [concurrency::join](../../parallel/concrt/reference/join-class.md) classe para evitar deadlocks em seu aplicativo.

[Passo a passo: Removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)<br/>
Demonstra como melhorar o desempenho de um aplicativo do MFC que desenha o fractal Mandelbrot.

[Passo a passo: Usando o Tempo de Execução de Simultaneidade em um aplicativo habilitado para COM](../../parallel/concrt/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application.md)<br/>
Demonstra como usar o tempo de execução de simultaneidade em um aplicativo que usa o modelo de objeto de componente (COM).

[Passo a passo: Adaptando um código existente para usar tarefas leves](../../parallel/concrt/walkthrough-adapting-existing-code-to-use-lightweight-tasks.md)<br/>
Mostra como adaptar o código existente que usa a API do Windows para criar e executar um thread para usar uma tarefa leve.

[Passo a passo: Criar um bloco de mensagem personalizado](../../parallel/concrt/walkthrough-creating-a-custom-message-block.md)<br/>
Descreve como criar um tipo de bloco de mensagem personalizado que ordena as mensagens de entrada por prioridade.

## <a name="related-sections"></a>Seções relacionadas

[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
Apresenta a estrutura de programação simultânea para Visual C++.
