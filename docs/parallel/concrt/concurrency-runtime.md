---
title: Tempo de execução de simultaneidade | Microsoft Docs
ms.custom: ''
ms.date: 07/20/2018
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Concurrency Runtime, getting started
- ConcRT (see Concurrency Runtime)
- Concurrency Runtime
ms.assetid: 874bc58f-8dce-483e-a3a1-4dcc9e52ed2c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b39fb35b21721cb9b93741a74f62d749b6fb1051
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42608261"
---
# <a name="concurrency-runtime"></a>Tempo de Execução de Simultaneidade
O tempo de execução de simultaneidade para C++ ajuda você a gravação robusta, escalonável e responsivos aplicativos paralelos. Ele aumenta o nível de abstração para que você não precise gerenciar os detalhes da infraestrutura que estão relacionados à simultaneidade. Também pode usá-lo para especificar o agendamento de políticas que atendem a qualidade das demandas de serviço de seus aplicativos. Use estes recursos para ajudá-lo a começar a trabalhar com o tempo de execução de simultaneidade.  
  
 Para obter a documentação de referência, consulte [referência](../../parallel/concrt/reference/reference-concurrency-runtime.md).  
  
> [!TIP]
>  O tempo de execução de simultaneidade depende muito de recursos do C++11 e adota o estilo mais moderno do C++. Para saber mais, leia [bem-vindo de volta ao C++](../../cpp/welcome-back-to-cpp-modern-cpp.md).  
  
## <a name="choosing-concurrency-runtime-features"></a>Escolhendo Recursos do Tempo de Execução de Simultaneidade  
  
|||  
|-|-|  
|[Visão geral](../../parallel/concrt/overview-of-the-concurrency-runtime.md)|Ensina por que o tempo de execução de simultaneidade é importante e descreve seus principais recursos.|  
|[Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md)|Mostra como o tempo de execução de simultaneidade se compara a outros modelos de simultaneidade, como os Windows pool de threads e OpenMP, para que você possa usar o modelo de simultaneidade que melhor atende aos requisitos do aplicativo.|  
|[Migrando do OpenMP para o tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)|Compara o OpenMP no tempo de execução de simultaneidade e fornece exemplos sobre como migrar o código de OpenMP existente para usar o tempo de execução de simultaneidade.|  
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Apresenta o PPL, que fornece os loops paralelos, tarefas e contêineres em paralelo.|  
|[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)|Apresenta a você como usar agentes assíncronos e transmissão para incorporar facilmente o fluxo de dados e pipelining de tarefas em seus aplicativos de mensagens.|  
|[Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)|Apresenta o Agendador de tarefas, que permite que você ajustar o desempenho de seus aplicativos da área de trabalho que usa o tempo de execução de simultaneidade.|  
  
## <a name="task-parallelism-in-the-ppl"></a>Paralelismo da Tarefa na PPL  
  
|||  
|-|-|  
|[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br /><br /> [Como usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)<br /><br /> [Como usar Parallel.Invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)<br /><br /> [Como criar uma tarefa que seja concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md)|Descreve as tarefas e grupos que podem ajudar você a escrever código assíncrono e decompo trabalho paralelo em partes menores.|  
|[Instruções passo a passo: implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)|Demonstra como combinar os recursos de tempo de execução de simultaneidade para fazer algo mais.|  
|[Instruções passo a passo: removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)|Mostra como mover o trabalho que é executado pelo thread de interface do usuário em um aplicativo do MFC para um thread de trabalho.|  
|[Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br /><br /> [Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com o PPL.|  
  
## <a name="data-parallelism-in-the-ppl"></a>Paralelismo de Dados na PPL  
  
|||  
|-|-|  
|[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br /><br /> [Como escrever um loop parallel_for](../../parallel/concrt/how-to-write-a-parallel-for-loop.md)<br /><br /> [Como gravar um loop parallel_for_each](../../parallel/concrt/how-to-write-a-parallel-for-each-loop.md)<br /><br /> [Como realizar operações de mapa e redução em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md)|Descreve `parallel_for`, `parallel_for_each`, `parallel_invoke`e outros algoritmos paralelos. Use algoritmos paralelos para resolver *paralela de dados* problemas que envolvem a coleções de dados.|  
|[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br /><br /> [Como usar contêineres em paralelo para aumentar a eficiência](../../parallel/concrt/how-to-use-parallel-containers-to-increase-efficiency.md)<br /><br /> [Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)<br /><br /> [Como usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)|Descreve o `combinable` classe, bem como `concurrent_vector`, `concurrent_queue`, `concurrent_unordered_map`e outro contêineres em paralelo. Use objetos e contêineres em paralelo quando precisar de contêineres, que fornecem acesso thread-safe aos seus elementos.|  
|[Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br /><br /> [Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com o PPL.|  
  
## <a name="canceling-tasks-and-parallel-algorithms"></a>Cancelando Tarefas e Algoritmos Paralelos  
  
|||  
|-|-|  
|[Cancelamento no PPL](cancellation-in-the-ppl.md)|Descreve a função de cancelamento no PPL, incluindo como iniciar e responder a solicitações de cancelamento.|  
|[Como usar cancelamento para interromper um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)<br /><br /> [Como usar tratamento de exceções para interromper um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md)|Demonstra duas maneiras de cancelar o trabalho de dados paralelos.|  
  
## <a name="universal-windows-platform-apps"></a>Windows universal aplicativos de plataforma  
  
|||  
|-|-|  
|[Criando operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md)|Descreve alguns dos principais pontos para ter em mente quando você usa o tempo de execução de simultaneidade para gerar operações assíncronas em um aplicativo UWP.|  
|[Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)|Mostra como combinar tarefas PPL com o `IXMLHTTPRequest2` e `IXMLHTTPRequest2Callback` interfaces para enviar solicitações HTTP GET e POST para um serviço web em um aplicativo UWP.|  
|[Exemplos de aplicativos de tempo de execução do Windows](http://code.msdn.microsoft.com/windowsapps)|Contém exemplos de código para download e demonstração de aplicativos para Windows 8. x. Os exemplos de C++ usam recursos de tempo de execução de simultaneidade, como tarefas de PPL para processar dados em segundo plano para manter a experiência do usuário responsiva.|  
  
## <a name="dataflow-programming-in-the-asynchronous-agents-library"></a>Programação do Fluxo de Dados na Biblioteca de Agentes Assíncrona  
  
|||  
|-|-|  
|[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br /><br /> [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br /><br /> [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br /><br /> [Como implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)<br /><br /> [Como fornecer funções de trabalho para as classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)<br /><br /> [Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)<br /><br /> [Como selecionar entre tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)<br /><br /> [Como enviar uma mensagem a um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)<br /><br /> [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)|Descreve as funções de transmissão de mensagens, que são os blocos de construção para executar operações de fluxo de dados no tempo de execução de simultaneidade de agentes assíncronos e blocos de mensagem.|  
|[Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)<br /><br /> [Instruções passo a passo: criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)|Mostra como criar aplicativos baseados em agente básicos.|  
|[Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)|Mostra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagem.|  
|[Instruções passo a passo: usando unir para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)|Usa o problema de filósofos jantar para ilustrar como usar o tempo de execução de simultaneidade para evitar deadlocks em seu aplicativo.|  
|[Instruções passo a passo: criando um bloco de mensagens personalizado](../../parallel/concrt/walkthrough-creating-a-custom-message-block.md)|Mostra como criar um tipo de bloco de mensagem personalizado que ordena as mensagens de entrada por prioridade.|  
|[Práticas recomendadas na biblioteca de agentes assíncronos](../../parallel/concrt/best-practices-in-the-asynchronous-agents-library.md)<br /><br /> [Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com os agentes.|  
  
## <a name="exception-handling-and-debugging"></a>Tratamento de Exceção e Depuração  
  
|||  
|-|-|  
|[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)|Descreve como trabalhar com exceções em tempo de execução de simultaneidade.|  
|[Ferramentas de diagnóstico paralelo](../../parallel/concrt/parallel-diagnostic-tools-concurrency-runtime.md)|Ensina você a ajustar seus aplicativos e fazer o uso mais eficiente do tempo de execução de simultaneidade.|  
  
## <a name="tuning-performance"></a>Ajustando Desempenho  
  
|||  
|-|-|  
|[Ferramentas de diagnóstico paralelo](../../parallel/concrt/parallel-diagnostic-tools-concurrency-runtime.md)|Ensina você a ajustar seus aplicativos e fazer o uso mais eficiente do tempo de execução de simultaneidade.|  
|[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)<br /><br /> [Como gerenciar instâncias de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)<br /><br /> [Políticas de agendador](../../parallel/concrt/scheduler-policies.md)<br /><br /> [Como especificar políticas de agendador específicas](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md)<br /><br /> [Como criar agentes que usam políticas de agendador específicas](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)|Mostra como trabalhar com o gerenciar instâncias de agendador e políticas de Agendador. Para aplicativos da área de trabalho, políticas de Agendador permitem associar regras específicas de tipos específicos de cargas de trabalho. Por exemplo, você pode criar uma instância de Agendador para executar algumas tarefas com uma prioridade de thread com privilégios elevados e use o agendador padrão para executar outras tarefas com a prioridade normal de threads.|  
|[Grupos Agendados](../../parallel/concrt/schedule-groups.md)<br /><br /> [Como usar grupos agendados para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)|Demonstra como usar grupos de agendamento para relacionar ou agrupar, tarefas relacionadas. Por exemplo, você pode exigir um alto grau de localidade entre tarefas relacionadas ao aproveitar a essas tarefas de execução no mesmo nó de processador.|  
|[Tarefas leves](../../parallel/concrt/lightweight-tasks.md)|Explica as tarefas leves como são úteis para a criação de trabalho que não exigem balanceamento de carga ou cancelamento e como eles também são úteis para adaptar o código existente para uso com o tempo de execução de simultaneidade.|  
|[Contextos](../../parallel/concrt/contexts.md)<br /><br /> [Como usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)<br /><br /> [Como usar excesso de assinatura para compensar a latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)|Descreve como controlar o comportamento dos threads que são gerenciados pelo tempo de execução de simultaneidade.|  
|[Funções de gerenciamento da memória](../../parallel/concrt/memory-management-functions.md)<br /><br /> [Como usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)|Descreve as funções de gerenciamento de memória que o tempo de execução de simultaneidade oferece para ajudá-lo a alocar e liberar memória, de forma simultânea.|  
  
## <a name="additional-resources"></a>Recursos adicionais  
  
|||  
|-|-|  
|[Padrões de programação assíncrona e dicas no Hilo (aplicativos da Windows Store usando C++ e XAML)](http://msdn.microsoft.com/library/windows/apps/jj160321.aspx)|Saiba como usamos o tempo de execução de simultaneidade para implementar operações assíncronas no Hilo, um aplicativo de tempo de execução do Windows usando C++ e XAML.|  
|[Exemplos de código para o tempo de execução de simultaneidade e a biblioteca de padrões paralela no Visual Studio 2010](http://go.microsoft.com/fwlink/p/?linkid=183875)|Fornece exemplos de aplicativos e utilitários que demonstram o tempo de execução de simultaneidade.|  
|[Programação paralela no blog de código nativo](http://go.microsoft.com/fwlink/p/?linkid=183873)|Fornece artigos de blog detalhadas adicionais sobre programação paralela em tempo de execução de simultaneidade.|  
|[Computação paralela no Fórum do C++ e o código nativo](http://go.microsoft.com/fwlink/p/?linkid=183874)|Permite que você participe de discussões da comunidade sobre o tempo de execução de simultaneidade.|  
|[Programação paralela](/dotnet/standard/parallel-programming/index)|Ensina sobre o modelo de programação paralelo que está disponível no .NET Framework.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência](../../parallel/concrt/reference/reference-concurrency-runtime.md)


