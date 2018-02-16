---
title: "Explicações passo a passo de tempo de execução de simultaneidade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- walkthroughs [Concurrency Runtime]
- Concurrency Runtime, walkthroughs
ms.assetid: 7374c5e9-54eb-44bf-9ed9-5e190cfd290b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3c5716bcfa997a45ab44fcb1026d7e082026a7a8
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="concurrency-runtime-walkthroughs"></a>Instruções passo a passo do Tempo de Execução de Simultaneidade
Os tópicos baseada em cenário nesta seção mostram como usar muitos dos recursos de tempo de execução de simultaneidade.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)  
 Mostra como usar o [IXMLHTTPRequest2](http://msdn.microsoft.com/en-us/bbc11c4a-aecf-4d6d-8275-3e852e309908) e [IXMLHTTPRequest2Callback](http://msdn.microsoft.com/en-us/aa4b3f4c-6e28-458b-be25-6cce8865fc71) interfaces junto com as tarefas para enviar solicitações HTTP GET e POST para um serviço da web em um aplicativo do Windows UWP (plataforma Universal).  
  
 [Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)  
 Descreve como criar um aplicativo básico com base em agente.  
  
 [Instruções passo a passo: criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)  
 Demonstra como criar aplicativos baseados em agente que se baseiam no fluxo de dados, em vez de fluxo de controle.  
  
 [Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)  
 Demonstra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagem.  
  
 [Instruções passo a passo: implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)  
 Mostra como computar valores para uso posterior de forma assíncrona.  
  
 [Instruções passo a passo: usando unir para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)  
 Usa o problema filósofos restaurantes para ilustrar como usar o [concurrency::join](../../parallel/concrt/reference/join-class.md) classe para evitar deadlock em seu aplicativo.  
  
 [Instruções passo a passo: removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)  
 Demonstra como melhorar o desempenho de um aplicativo MFC que desenha o fractal Mandelbrot.  
  
 [Instruções passo a passo: usando o tempo de execução de simultaneidade em um aplicativo habilitado para COM](../../parallel/concrt/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application.md)  
 Demonstra como usar o tempo de execução de simultaneidade em um aplicativo que usa o modelo de objeto de componente (COM).  
  
 [Instruções passo a passo: adaptando um código existente para usar tarefas leves](../../parallel/concrt/walkthrough-adapting-existing-code-to-use-lightweight-tasks.md)  
 Mostra como adaptar o código existente que usa a API do Windows para criar e executar um thread para usar uma tarefa simples.  
  
 [Instruções passo a passo: criando um bloco de mensagens personalizado](../../parallel/concrt/walkthrough-creating-a-custom-message-block.md)  
 Descreve como criar um tipo de bloco de mensagem personalizada que ordena as mensagens de entrada por prioridade.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)  
 Apresenta a estrutura de programação simultânea do Visual C++.

