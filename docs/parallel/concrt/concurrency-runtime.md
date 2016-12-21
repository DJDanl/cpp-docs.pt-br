---
title: "Tempo de Execu&#231;&#227;o de Simultaneidade | Microsoft Docs"
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
  - "Tempo de execução de simultaneidade, Introdução"
  - "ConcRT (consulte Tempo de Execução de Simultaneidade)"
  - "Tempo de Execução de Simultaneidade"
ms.assetid: 874bc58f-8dce-483e-a3a1-4dcc9e52ed2c
caps.latest.revision: 40
caps.handback.revision: 39
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tempo de Execu&#231;&#227;o de Simultaneidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O tempo de execução de simultaneidade para C\+\+ ajuda você a gravação robusta e escalonável e responsivos aplicativos paralelos. Ele aumenta o nível de abstração para que você não precisa gerenciar os detalhes de infra\-estrutura relacionados à simultaneidade. Você também pode usar\-especificar políticas de agendamento que atendem a qualidade das demandas de serviço de seus aplicativos. Use estes recursos para ajudá\-lo a começar a trabalhar com o tempo de execução de simultaneidade.  
  
 Para obter documentação de referência, consulte [Referência](../../parallel/concrt/reference/reference-concurrency-runtime.md).  
  
> [!TIP]
>  O tempo de execução de simultaneidade depende muito de recursos do C\+\+ 11 e adota o estilo C\+\+ mais moderno. Para saber mais, leia  [Bem\-vindo ao C\+\+](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md).  
  
## Escolhendo recursos de tempo de execução de simultaneidade  
  
|||  
|-|-|  
|[Visão Geral](../../parallel/concrt/overview-of-the-concurrency-runtime.md)|Ensina por que o tempo de execução de simultaneidade é importante e descreve seus principais recursos.|  
|[Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md)|Mostra como o tempo de execução de simultaneidade se compara aos outros modelos de simultaneidade, como as janelas de pool de threads e OpenMP, para que você possa usar o modelo de simultaneidade que melhor atenda às suas necessidades de aplicativo.|  
|[Migrando de OpenMP no Tempo de Execução de Simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)|Compara OpenMP no tempo de execução de simultaneidade e fornece exemplos sobre como migrar código OpenMP existente para usar o tempo de execução de simultaneidade.|  
|[Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Apresenta a PPL, que fornece loops paralelos, tarefas e contêineres em paralelo.|  
|[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)|Apresenta a você como usar agentes assíncronos e transmissão para incorporar facilmente o fluxo de dados e processamento de tarefas em seus aplicativos de mensagens.|  
|[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)|Apresenta o Agendador de tarefas, que permite que você ajuste o desempenho de seus aplicativos de área de trabalho que usa o tempo de execução de simultaneidade.|  
  
## Paralelismo de tarefa na PPL  
  
|||  
|-|-|  
|[Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br /><br /> [Como usar parallel\_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)<br /><br /> [Como usar parallel\_invoke para executar operações em paralelo](../Topic/How%20to:%20Use%20parallel_invoke%20to%20Execute%20Parallel%20Operations.md)<br /><br /> [Como criar uma tarefa que seja concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md)|Descreve as tarefas e grupos que podem ajudar você a escrever código assíncrono e decompor o trabalho paralelo em partes menores.|  
|[Instruções passo a passo: implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)|Demonstra como combinar os recursos de tempo de execução de simultaneidade para fazer algo mais.|  
|[Instruções passo a passo: removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)|Mostra como mover o trabalho executado pelo thread de interface do usuário em um aplicativo MFC para um thread de trabalho.|  
|[Práticas recomendadas na Biblioteca de Padrões Paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br /><br /> [Práticas recomendadas gerais no Tempo de Execução de Simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com a PPL.|  
  
## Paralelismo de dados na PPL  
  
|||  
|-|-|  
|[Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)<br /><br /> [Como gravar um loop parallel\_for](../Topic/How%20to:%20Write%20a%20parallel_for%20Loop.md)<br /><br /> [Como gravar um loop parallel\_for\_each](../Topic/How%20to:%20Write%20a%20parallel_for_each%20Loop.md)<br /><br /> [Como realizar operações de mapa e redução em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md)|Descreve `parallel_for`, `parallel_for_each`, `parallel_invoke`, e outros algoritmos paralelos. Usar algoritmos paralelos para resolver *dados paralelos* problemas que envolvem coleções de dados.|  
|[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br /><br /> [Como usar contêineres em paralelo para aumentar a eficiência](../Topic/How%20to:%20Use%20Parallel%20Containers%20to%20Increase%20Efficiency.md)<br /><br /> [Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)<br /><br /> [Como usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)|Descreve o `combinable` classe, bem como `concurrent_vector`, `concurrent_queue`, `concurrent_unordered_map`, e outro contêineres em paralelo. Use objetos e contêineres em paralelo quando precisar de contêineres que fornecem acesso thread\-safe para seus elementos.|  
|[Práticas recomendadas na Biblioteca de Padrões Paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br /><br /> [Práticas recomendadas gerais no Tempo de Execução de Simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com a PPL.|  
  
## Cancelando tarefas e algoritmos paralelos  
  
|||  
|-|-|  
|[Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)|Descreve a função de cancelamento no PPL, inclusive sobre como iniciar e responder às solicitações de cancelamento.|  
|[Como usar cancelamento para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)<br /><br /> [Como usar tratamento de exceções para parar um loop paralelo](../Topic/How%20to:%20Use%20Exception%20Handling%20to%20Break%20from%20a%20Parallel%20Loop.md)|Demonstra duas maneiras para cancelar o trabalho de paralelismo de dados.|  
  
## Aplicativos da Windows Store  
  
|||  
|-|-|  
|[Criando operações assíncronas n C\+\+ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md)|Descreve alguns dos principais pontos para ter em mente ao usar o tempo de execução de simultaneidade para produzir operações assíncronas em uma [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo.|  
|[Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)|Mostra como combinar tarefas PPL com o `IXMLHTTPRequest2` e `IXMLHTTPRequest2Callback` interfaces para enviar solicitações HTTP GET e POST para um serviço web em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo.|  
|[Exemplos de aplicativo da Windows Store](http://code.msdn.microsoft.com/windowsapps)|Contém exemplos de código para download e demonstração de aplicativos para [!INCLUDE[win8](../../build/includes/win8_md.md)]. Os exemplos de C\+\+ usam recursos de tempo de execução de simultaneidade, como tarefas PPL para processar dados em segundo plano para manter a experiência do usuário responsiva.|  
  
## Programação de fluxo de dados na biblioteca de agentes assíncronos  
  
|||  
|-|-|  
|[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br /><br /> [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br /><br /> [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br /><br /> [Como implementar vários padrões de produtor\-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)<br /><br /> [Como fornecer funções de trabalho para as classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)<br /><br /> [Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)<br /><br /> [Como selecionar tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)<br /><br /> [Como enviar uma mensagem em um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)<br /><br /> [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)|Descreve as funções de transmissão de mensagens, que são os blocos de construção para executar operações de fluxo de dados em tempo de execução de simultaneidade de agentes assíncronos e blocos de mensagens.|  
|[Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)<br /><br /> [Instruções passo a passo: criando um agente de fluxo de dados](../Topic/Walkthrough:%20Creating%20a%20Dataflow%20Agent.md)|Mostra como criar aplicativos baseados em agente básicos.|  
|[Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)|Mostra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagem.|  
|[Instruções passo a passo: usando join para Evitar Deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)|Usa o problema filósofos jantar para ilustrar como usar o tempo de execução de simultaneidade para evitar o deadlock em seu aplicativo.|  
|[Instruções passo a passo: criando um bloco de mensagens personalizado](../Topic/Walkthrough:%20Creating%20a%20Custom%20Message%20Block.md)|Mostra como criar um tipo de bloco de mensagem personalizada que ordena as mensagens recebidas por prioridade.|  
|[Práticas recomendadas na Biblioteca de Agentes Assíncrona](../Topic/Best%20Practices%20in%20the%20Asynchronous%20Agents%20Library.md)<br /><br /> [Práticas recomendadas gerais no Tempo de Execução de Simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com os agentes.|  
  
## Tratamento de exceções e depuração  
  
|||  
|-|-|  
|[Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md)|Descreve como trabalhar com exceções em tempo de execução de simultaneidade.|  
|[Ferramentas de diagnóstico em paralelo](../../parallel/concrt/parallel-diagnostic-tools-concurrency-runtime.md)|Ensina a ajustar seus aplicativos e fazer o uso mais eficiente do tempo de execução de simultaneidade.|  
  
## Ajuste de desempenho  
  
|||  
|-|-|  
|[Ferramentas de diagnóstico em paralelo](../../parallel/concrt/parallel-diagnostic-tools-concurrency-runtime.md)|Ensina a ajustar seus aplicativos e fazer o uso mais eficiente do tempo de execução de simultaneidade.|  
|[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)<br /><br /> [Como gerenciar uma instância de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)<br /><br /> [Políticas de agendador](../../parallel/concrt/scheduler-policies.md)<br /><br /> [Como especificar políticas de agendador específicas](../Topic/How%20to:%20Specify%20Specific%20Scheduler%20Policies.md)<br /><br /> [Como cria agentes que usam políticas de agendador específicas](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)|Mostra como trabalhar com o gerenciar instâncias de agendador e políticas de Agendador. Para aplicativos de desktop, políticas de Agendador permitem associar regras específicas de tipos específicos de cargas de trabalho. Por exemplo, você pode criar uma instância de Agendador para executar algumas tarefas com uma prioridade de thread com privilégios elevados e use o agendador padrão para executar outras tarefas com a prioridade normal de threads.|  
|[Grupos de agendas](../../parallel/concrt/schedule-groups.md)<br /><br /> [Como usar grupos de agendas para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)|Demonstra como usar grupos de agendamento para relacionar ou agrupar, tarefas relacionadas. Por exemplo, você pode exigir um alto grau de localidade entre tarefas relacionadas quando essas tarefas se beneficiar da execução no mesmo nó do processador.|  
|[Tarefas leves](../../parallel/concrt/lightweight-tasks.md)|Explica como simples tarefas são úteis para criar o trabalho que não exigem balanceamento de carga ou cancelamento e como eles também são úteis para adaptar o código existente para uso com o tempo de execução de simultaneidade.|  
|[Contextos](../../parallel/concrt/contexts.md)<br /><br /> [Como usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)<br /><br /> [Como usar excesso de assinatura para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)|Descreve como controlar o comportamento dos threads que são gerenciados pelo tempo de execução de simultaneidade.|  
|[Funções de gerenciamento da memória](../Topic/Memory%20Management%20Functions.md)<br /><br /> [Como usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)|Descreve as funções de gerenciamento de memória que o tempo de execução de simultaneidade fornece para ajudá\-lo a alocar e liberar memória, de forma simultânea.|  
  
## Recursos adicionais  
  
|||  
|-|-|  
|[Padrões de programação assíncrona e dicas no Hilo \(aplicativos da Windows Store usando C\+\+ e XAML\)](http://msdn.microsoft.com/library/windows/apps/jj160321.aspx)|Saiba como usamos o tempo de execução de simultaneidade para implementar operações assíncronas no Hilo, um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo usando o C\+\+ e XAML.|  
|[Exemplos de código para o tempo de execução de simultaneidade e a biblioteca de padrão paralelo no Visual Studio 2010](http://go.microsoft.com/fwlink/?LinkID=183875)|Fornece exemplos de aplicativos e utilitários que demonstram o tempo de execução de simultaneidade.|  
|[Programação paralela no blog de código nativo](http://go.microsoft.com/fwlink/?LinkID=183873)|Fornece artigos de blog detalhadas adicionais sobre programação paralela em tempo de execução de simultaneidade.|  
|[Computação paralela no Fórum do C\+\+ e código nativo](http://go.microsoft.com/fwlink/?LinkID=183874)|Permite que você participe de discussões da comunidade sobre o tempo de execução de simultaneidade.|  
|[Programação paralela](../Topic/Parallel%20Programming%20in%20the%20.NET%20Framework.md)|Ensina o modelo de programação paralelo que está disponível na [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)].|  
  
## Consulte também  
 [Referência](../../parallel/concrt/reference/reference-concurrency-runtime.md)