---
title: Tempo de Execução de Simultaneidade
ms.date: 07/20/2018
helpviewer_keywords:
- Concurrency Runtime, getting started
- ConcRT (see Concurrency Runtime)
- Concurrency Runtime
ms.assetid: 874bc58f-8dce-483e-a3a1-4dcc9e52ed2c
ms.openlocfilehash: a96c54a01788f03158b9fcdcd0bf72eb2b1ce84d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510557"
---
# <a name="concurrency-runtime"></a>Tempo de Execução de Simultaneidade

O Tempo de Execução de Simultaneidade para C++ o ajuda a escrever aplicativos paralelos robustos, escalonáveis e responsivos. Ele gera o nível de abstração para que você não precise gerenciar os detalhes da infraestrutura relacionados à simultaneidade. Você também pode usá-lo para especificar políticas de agendamento que atendam às demandas de qualidade de serviço de seus aplicativos. Use estes recursos para ajudá-lo a começar a trabalhar com o Tempo de Execução de Simultaneidade.

Para obter a documentação de referência, consulte [referência](../../parallel/concrt/reference/reference-concurrency-runtime.md).

> [!TIP]
>  A Tempo de Execução de Simultaneidade depende muito dos recursos do C++ 11 e adota o estilo mais moderno C++ . Para saber mais, leia [Bem-vindo C++de volta para ](../../cpp/welcome-back-to-cpp-modern-cpp.md).

## <a name="choosing-concurrency-runtime-features"></a>Escolhendo Recursos do Tempo de Execução de Simultaneidade

|||
|-|-|
|[Visão geral](../../parallel/concrt/overview-of-the-concurrency-runtime.md)|Ensina por que a Tempo de Execução de Simultaneidade é importante e descreve seus principais recursos.|
|[Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md)|Mostra como o Tempo de Execução de Simultaneidade se compara a outros modelos de simultaneidade, como o pool de threads do Windows e o OpenMP, para que você possa usar o modelo de simultaneidade que melhor atenda aos requisitos do aplicativo.|
|[Migrando do OpenMP para o tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)|Compara o OpenMP com o Tempo de Execução de Simultaneidade e fornece exemplos de como migrar o código de OpenMP existente para usar o Tempo de Execução de Simultaneidade.|
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Apresenta a PPL, que fornece loops paralelos, tarefas e contêineres paralelos.|
|[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)|Apresenta a você como usar agentes assíncronos e a transmissão de mensagem para incorporar facilmente as tarefas de fluxo de mensagens e de pipeline em seus aplicativos.|
|[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)|Apresenta o Agendador de Tarefas, que permite ajustar o desempenho de seus aplicativos de desktop que usam o Tempo de Execução de Simultaneidade.|

## <a name="task-parallelism-in-the-ppl"></a>Paralelismo da Tarefa na PPL

|||
|-|-|
|[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br /><br /> [Como: Usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)<br /><br /> [Como: Usar parallel_invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)<br /><br /> [Como: Criar uma tarefa que seja concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md)|Descreve tarefas e grupos de tarefas, que podem ajudá-lo a escrever código assíncrono e decompor o trabalho paralelo em partes menores.|
|[Passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)|Demonstra como combinar Tempo de Execução de Simultaneidade recursos para fazer algo mais.|
|[Passo a passo: Removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)|Mostra como mover o trabalho que é executado pelo thread de interface do usuário em um aplicativo MFC para um thread de trabalho.|
|[Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br /><br /> [Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com a PPL.|

## <a name="data-parallelism-in-the-ppl"></a>Paralelismo de Dados na PPL

|||
|-|-|
|[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br /><br /> [Como: Escrever um loop parallel_for](../../parallel/concrt/how-to-write-a-parallel-for-loop.md)<br /><br /> [Como: Escrever um loop parallel_for_each](../../parallel/concrt/how-to-write-a-parallel-for-each-loop.md)<br /><br /> [Como: Realizar operações de mapa e redução em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md)|Descreve `parallel_for`, `parallel_for_each` ,`parallel_invoke`e outros algoritmos paralelos. Use algoritmos paralelos para resolver problemas paralelos de *dados* que envolvem coleções de dados.|
|[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br /><br /> [Como: Usar contêineres em paralelo para aumentar a eficiência](../../parallel/concrt/how-to-use-parallel-containers-to-increase-efficiency.md)<br /><br /> [Como: Usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)<br /><br /> [Como: Usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)|Descreve a `combinable` classe, bem como `concurrent_vector`, `concurrent_queue` `concurrent_unordered_map`, e outros contêineres paralelos. Use contêineres paralelos e objetos quando você precisar de contêineres que fornecem acesso seguro ao thread aos seus elementos.|
|[Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br /><br /> [Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com a PPL.|

## <a name="canceling-tasks-and-parallel-algorithms"></a>Cancelando Tarefas e Algoritmos Paralelos

|||
|-|-|
|[Cancelamento no PPL](cancellation-in-the-ppl.md)|Descreve a função de cancelamento na PPL, incluindo como iniciar e responder a solicitações de cancelamento.|
|[Como: Usar cancelamento para interromper um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)<br /><br /> [Como: Usar tratamento de exceções para interromper um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md)|Demonstra duas maneiras de cancelar o trabalho de Parallel Data.|

## <a name="universal-windows-platform-apps"></a>Aplicativos da Plataforma Universal do Windows

|||
|-|-|
|[Criando operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md)|Descreve alguns dos principais pontos a serem considerados quando você usa o Tempo de Execução de Simultaneidade para produzir operações assíncronas em um aplicativo UWP.|
|[Passo a passo: Conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)|Mostra como combinar tarefas da PPL com as `IXMLHTTPRequest2` interfaces `IXMLHTTPRequest2Callback` e para enviar solicitações HTTP Get e post para um serviço Web em um aplicativo UWP.|
|[Exemplos de aplicativo Windows Runtime](https://code.msdn.microsoft.com/windowsapps)|Contém exemplos de código para download e aplicativos de demonstração para o Windows 8. x. Os C++ exemplos usam tempo de execução de simultaneidade recursos como tarefas ppl para processar dados em segundo plano para manter a UX responsiva.|

## <a name="dataflow-programming-in-the-asynchronous-agents-library"></a>Programação do Fluxo de Dados na Biblioteca de Agentes Assíncrona

|||
|-|-|
|[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br /><br /> [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br /><br /> [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br /><br /> [Como: Implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)<br /><br /> [Como: Fornecer funções de trabalho para as classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)<br /><br /> [Como: Usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)<br /><br /> [Como: Selecionar entre tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)<br /><br /> [Como: Enviar uma mensagem a um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)<br /><br /> [Como: Usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)|Descreve os agentes assíncronos, os blocos de mensagens e as funções de passagem de mensagens, que são os blocos de construção para executar operações de Dataflow no Tempo de Execução de Simultaneidade.|
|[Passo a passo: Criando um aplicativo com base em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)<br /><br /> [Passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)|Mostra como criar aplicativos básicos baseados em agente.|
|[Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)|Mostra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagens.|
|[Passo a passo: Usando join para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)|Usa o problema do jantar filósofos para ilustrar como usar o Tempo de Execução de Simultaneidade para impedir o deadlock em seu aplicativo.|
|[Passo a passo: Criar um bloco de mensagem personalizado](../../parallel/concrt/walkthrough-creating-a-custom-message-block.md)|Mostra como criar um tipo de bloco de mensagens personalizado que ordena mensagens de entrada por prioridade.|
|[Práticas recomendadas na biblioteca de agentes assíncronos](../../parallel/concrt/best-practices-in-the-asynchronous-agents-library.md)<br /><br /> [Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)|Fornece dicas e práticas recomendadas para trabalhar com agentes.|

## <a name="exception-handling-and-debugging"></a>Tratamento de Exceção e Depuração

|||
|-|-|
|[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)|Descreve como trabalhar com exceções no Tempo de Execução de Simultaneidade.|
|[Ferramentas de diagnóstico paralelo](../../parallel/concrt/parallel-diagnostic-tools-concurrency-runtime.md)|Ensina como ajustar seus aplicativos e fazer o uso mais eficiente do Tempo de Execução de Simultaneidade.|

## <a name="tuning-performance"></a>Ajustando Desempenho

|||
|-|-|
|[Ferramentas de diagnóstico paralelo](../../parallel/concrt/parallel-diagnostic-tools-concurrency-runtime.md)|Ensina como ajustar seus aplicativos e fazer o uso mais eficiente do Tempo de Execução de Simultaneidade.|
|[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)<br /><br /> [Como: Gerenciar uma instância de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)<br /><br /> [Políticas de agendador](../../parallel/concrt/scheduler-policies.md)<br /><br /> [Como: Especificar políticas específicas do agendador](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md)<br /><br /> [Como: Criar agentes que usam políticas específicas do agendador](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)|Mostra como trabalhar com o gerenciamento de instâncias do Agendador e as políticas do Agendador. Para aplicativos da área de trabalho, as políticas do Agendador permitem que você associe regras específicas a tipos específicos de cargas de trabalho. Por exemplo, você pode criar uma instância de Agendador para executar algumas tarefas em uma prioridade de thread elevada e usar o agendador padrão para executar outras tarefas na prioridade de thread normal.|
|[Grupos Agendados](../../parallel/concrt/schedule-groups.md)<br /><br /> [Como: Usar grupos agendados para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)|Demonstra como usar grupos de agendamento para relacionar ou agrupar tarefas relacionadas em conjunto. Por exemplo, você pode exigir um alto grau de localidade entre as tarefas relacionadas quando essas tarefas se beneficiarem da execução no mesmo nó do processador.|
|[Tarefas leves](../../parallel/concrt/lightweight-tasks.md)|Explica como as tarefas leves são úteis para a criação de trabalho que não requer balanceamento de carga ou cancelamento e como elas também são úteis para adaptar o código existente para uso com o Tempo de Execução de Simultaneidade.|
|[Contextos](../../parallel/concrt/contexts.md)<br /><br /> [Como: Usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)<br /><br /> [Como: Usar excesso de assinatura para compensar a latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)|Descreve como controlar o comportamento dos threads que são gerenciados pelo Tempo de Execução de Simultaneidade.|
|[Funções de gerenciamento da memória](../../parallel/concrt/memory-management-functions.md)<br /><br /> [Como: Usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)|Descreve as funções de gerenciamento de memória que o Tempo de Execução de Simultaneidade fornece para ajudá-lo a alocar e liberar memória de maneira simultânea.|

## <a name="additional-resources"></a>Recursos adicionais

|||
|-|-|
|[Padrões de programação assíncrona e dicas em Hilo (aplicativos da C++ Windows Store usando e XAML)](/previous-versions/windows/apps/jj160321(v=win.10))|Saiba como usamos o Tempo de Execução de Simultaneidade para implementar operações assíncronas no hilo, um aplicativo Windows Runtime C++ usando o e o XAML.|
|[Programação paralela no blog de código nativo](https://go.microsoft.com/fwlink/p/?linkid=183873)|Fornece artigos de blog mais detalhados sobre a programação paralela no Tempo de Execução de Simultaneidade.|
|[Computação paralela no C++ e no fórum de código nativo](https://go.microsoft.com/fwlink/p/?linkid=183874)|Permite que você participe de discussões da Comunidade sobre o Tempo de Execução de Simultaneidade.|
|[Programação paralela](/dotnet/standard/parallel-programming/index)|Ensina sobre o modelo de programação paralela que está disponível no .NET Framework.|

## <a name="see-also"></a>Consulte também

[Referência](../../parallel/concrt/reference/reference-concurrency-runtime.md)
