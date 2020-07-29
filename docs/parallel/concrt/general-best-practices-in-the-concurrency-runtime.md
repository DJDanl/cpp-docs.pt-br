---
title: Práticas recomendadas gerais no Runtime de Simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- Concurrency Runtime, general best practices
ms.assetid: ce5c784c-051e-44a6-be84-8b3e1139c18b
ms.openlocfilehash: 77ca8acbd3dedc28aaa6c330c3e91ed09046d162
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228447"
---
# <a name="general-best-practices-in-the-concurrency-runtime"></a>Práticas recomendadas gerais no Runtime de Simultaneidade

Este documento descreve as práticas recomendadas que se aplicam a várias áreas do Tempo de Execução de Simultaneidade.

## <a name="sections"></a><a name="top"></a>As

Este documento contém as seguintes seções:

- [Usar Constructos de Sincronização Cooperativos Quando Possível](#synchronization)

- [Evitar Tarefas Longas que não Produzam](#yield)

- [Usar Excesso de Assinatura para Deslocar Operações que Bloqueiam ou Têm Alta Latência](#oversubscription)

- [Usar Funções de Gerenciamento de Memória Simultâneas Quando Possível](#memory)

- [Usar RAII para Gerenciar o Tempo de Vida de Objetos de Simultaneidade](#raii)

- [Não Criar Objetos de Simultaneidade em Escopo Global](#global-scope)

- [Não Usar Objetos de Simultaneidade em Segmentos de Dados Compartilhados](#shared-data)

## <a name="use-cooperative-synchronization-constructs-when-possible"></a><a name="synchronization"></a>Usar constructos de sincronização cooperativa quando possível

O Tempo de Execução de Simultaneidade fornece muitas construções com simultaneidade segura que não exigem um objeto de sincronização externo. Por exemplo, a classe [Concurrency:: concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) fornece operações de acesso de elemento e acréscimo com segurança de simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. No entanto, para casos em que você precisa de acesso exclusivo a um recurso, o tempo de execução fornece as classes de evento [Concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md), [concurrency:: reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md)e [Concurrency:: Event](../../parallel/concrt/reference/event-class.md) . Esses tipos se comportam de maneira cooperativa; Portanto, o Agendador de tarefas pode realocar recursos de processamento para outro contexto, uma vez que a primeira tarefa aguarda dados. Quando possível, use esses tipos de sincronização em vez de outros mecanismos de sincronização, como os fornecidos pela API do Windows, que não se comportam de maneira cooperativa. Para obter mais informações sobre esses tipos de sincronização e um exemplo de código, consulte [sincronização de estruturas de dados](../../parallel/concrt/synchronization-data-structures.md) e comparação de [estruturas de dados de sincronização com a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md).

[[Superior](#top)]

## <a name="avoid-lengthy-tasks-that-do-not-yield"></a><a name="yield"></a>Evite tarefas demoradas que não produzam

Como o Agendador de tarefas se comporta de cooperativa, ele não fornece nenhuma imparcialidade entre as tarefas. Portanto, uma tarefa pode impedir que outras tarefas sejam iniciadas. Embora isso seja aceitável em alguns casos, em outros casos isso pode causar deadlock ou privação.

O exemplo a seguir executa mais tarefas do que o número de recursos de processamento alocados. A primeira tarefa não produz o Agendador de tarefas e, portanto, a segunda tarefa não é iniciada até que a primeira tarefa seja concluída.

[!code-cpp[concrt-cooperative-tasks#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_1.cpp)]

Esse exemplo gera a saída a seguir:

1: 250000000 1: 500000000 1: 750000000 1: 1000000000 2: 250000000 2: 500000000 2: 750000000 2: 1000000000

Há várias maneiras de habilitar a cooperação entre as duas tarefas. Uma delas é, ocasionalmente, gerar ao agendador de tarefas em uma tarefa de execução longa. O exemplo a seguir modifica a `task` função para chamar o método [Concurrency:: Context:: yield](reference/context-class.md#yield) para gerar a execução ao agendador de tarefas para que outra tarefa possa ser executada.

[!code-cpp[concrt-cooperative-tasks#2](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_2.cpp)]

Esse exemplo gera a saída a seguir:

```Output
1: 250000000
2: 250000000
1: 500000000
2: 500000000
1: 750000000
2: 750000000
1: 1000000000
2: 1000000000
```

O `Context::Yield` método gera apenas outro thread ativo no Agendador ao qual o thread atual pertence, uma tarefa leve ou outro thread do sistema operacional. Este método não produz o trabalho agendado para ser executado em um objeto [Concurrency:: task_group](reference/task-group-class.md) ou [concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) , mas ainda não foi iniciado.

Há outras maneiras de habilitar a cooperação entre tarefas de longa execução. Você pode dividir uma tarefa grande em subtarefas menores. Você também pode habilitar a assinatura em excesso durante uma tarefa demorada. O excesso de assinaturas lhe permite criar mais threads do que o número de threads de hardware disponíveis. A assinatura em excesso é especialmente útil quando uma tarefa demorada contém uma grande quantidade de latência, por exemplo, leitura de dados do disco ou de uma conexão de rede. Para obter mais informações sobre tarefas leves e assinatura em excesso, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

[[Superior](#top)]

## <a name="use-oversubscription-to-offset-operations-that-block-or-have-high-latency"></a><a name="oversubscription"></a>Usar a assinatura excedente para operações de deslocamento que bloqueiam ou têm alta latência

O Tempo de Execução de Simultaneidade fornece primitivos de sincronização, como [Concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md), que permitem que as tarefas sejam bloqueadas e geradas de forma cooperativa entre si. Quando uma tarefa bloqueia ou produz cooperativamente, o Agendador de tarefas pode realocar recursos de processamento para outro contexto, uma vez que a primeira tarefa aguarda dados.

Há casos em que você não pode usar o mecanismo de bloqueio cooperativo fornecido pelo Tempo de Execução de Simultaneidade. Por exemplo, uma biblioteca externa que você usa pode usar um mecanismo de sincronização diferente. Outro exemplo é quando você executa uma operação que pode ter uma grande quantidade de latência, por exemplo, ao usar a função da API do Windows `ReadFile` para ler dados de uma conexão de rede. Nesses casos, a assinatura em excesso pode permitir que outras tarefas sejam executadas quando outra tarefa estiver ociosa. O excesso de assinaturas lhe permite criar mais threads do que o número de threads de hardware disponíveis.

Considere a seguinte função, `download` , que baixa o arquivo na URL fornecida. Este exemplo usa o método [Concurrency:: Context:: Oversubscribe](reference/context-class.md#oversubscribe) para aumentar temporariamente o número de threads ativos.

[!code-cpp[concrt-download-oversubscription#4](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_3.cpp)]

Como a `GetHttpFile` função executa uma operação potencialmente latente, a assinatura em excesso pode permitir que outras tarefas sejam executadas conforme a tarefa atual aguarda dados. Para obter a versão completa deste exemplo, consulte [como: usar a superassinatura para a latência de deslocamento](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).

[[Superior](#top)]

## <a name="use-concurrent-memory-management-functions-when-possible"></a><a name="memory"></a>Usar funções de gerenciamento de memória simultâneas quando possível

Use as funções de gerenciamento de memória, [Concurrency:: Alloc](reference/concurrency-namespace-functions.md#alloc) e [Concurrency:: Free](reference/concurrency-namespace-functions.md#free), quando você tiver tarefas refinadas que freqüentemente alocam pequenos objetos que têm um tempo de vida relativamente curto. O Tempo de Execução de Simultaneidade mantém um cache de memória separado para cada thread em execução. As `Alloc` `Free` funções e alocam e liberam memória desses caches sem o uso de bloqueios ou barreiras de memória.

Para obter mais informações sobre essas funções de gerenciamento de memória, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md). Para obter um exemplo que usa essas funções, consulte [como: usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md).

[[Superior](#top)]

## <a name="use-raii-to-manage-the-lifetime-of-concurrency-objects"></a><a name="raii"></a>Use RAII para gerenciar o tempo de vida de objetos de simultaneidade

O Tempo de Execução de Simultaneidade usa a manipulação de exceções para implementar recursos como cancelamento. Portanto, grave código de exceção segura ao chamar o tempo de execução ou chamar outra biblioteca que chama o tempo de execução.

O padrão de *aquisição de recursos é inicialização* (RAII) é uma maneira de gerenciar com segurança o tempo de vida de um objeto de simultaneidade em um determinado escopo. No padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor seja chamado antes da saída do escopo delimitador. Esse padrão é útil quando uma função contém várias **`return`** instruções. Esse padrão também ajuda você a escrever código de exceção segura. Quando uma **`throw`** instrução faz com que a pilha fique desenrolada, o destruidor para o objeto RAII é chamado; portanto, o recurso é sempre excluído ou liberado corretamente.

O tempo de execução define várias classes que usam o padrão RAII, por exemplo, [Concurrency:: critical_section:: scoped_lock](../../parallel/concrt/reference/critical-section-class.md#critical_section__scoped_lock_class) e [concurrency:: reader_writer_lock:: scoped_lock](reference/reader-writer-lock-class.md#scoped_lock_class). Essas classes auxiliares são conhecidas como *bloqueios com escopo*. Essas classes fornecem vários benefícios quando você trabalha com objetos [Concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md) ou [concurrency:: reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) . O Construtor dessas classes adquire o acesso ao `critical_section` objeto fornecido ou `reader_writer_lock` ; o destruidor libera o acesso a esse objeto. Como um bloqueio com escopo libera o acesso ao seu objeto de exclusão mútua automaticamente quando é destruído, você não desbloqueia manualmente o objeto subjacente.

Considere a seguinte classe, `account` , que é definida por uma biblioteca externa e, portanto, não pode ser modificada.

[!code-cpp[concrt-account-transactions#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_4.h)]

O exemplo a seguir executa várias transações em um `account` objeto em paralelo. O exemplo usa um `critical_section` objeto para sincronizar o acesso ao `account` objeto porque a `account` classe não é segura para simultaneidade. Cada operação em paralelo usa um `critical_section::scoped_lock` objeto para garantir que o `critical_section` objeto seja desbloqueado quando a operação for bem-sucedida ou falhar. Quando o saldo da conta é negativo, a `withdraw` operação falha ao gerar uma exceção.

[!code-cpp[concrt-account-transactions#2](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_5.cpp)]

Este exemplo produz a seguinte saída de exemplo:

```Output
Balance before deposit: 1924
Balance after deposit: 2924
Balance before withdrawal: 2924
Balance after withdrawal: -76
Balance before withdrawal: -76
Error details:
    negative balance: -76
```

Para obter exemplos adicionais que usam o padrão RAII para gerenciar o tempo de vida de objetos de simultaneidade, consulte [passo a passos: removendo o trabalho de um thread de interface do usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md), [como usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)e [como: usar a superassinatura para a latência de deslocamento](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).

[[Superior](#top)]

## <a name="do-not-create-concurrency-objects-at-global-scope"></a><a name="global-scope"></a>Não criar objetos de simultaneidade em escopo global

Quando você cria um objeto de simultaneidade no escopo global, pode causar problemas como violações de acesso de memória ou deadlock para ocorrer em seu aplicativo.

Por exemplo, quando você cria um objeto Tempo de Execução de Simultaneidade, o tempo de execução cria um agendador padrão para você, caso ainda não tenha sido criado. Um objeto de tempo de execução criado durante a construção de objeto global fará com que o tempo de execução crie esse agendador padrão. No entanto, esse processo usa um bloqueio interno, que pode interferir na inicialização de outros objetos que dão suporte à infraestrutura de Tempo de Execução de Simultaneidade. Esse bloqueio interno pode ser exigido por outro objeto de infraestrutura que ainda não foi inicializado e, portanto, pode fazer com que o deadlock ocorra em seu aplicativo.

O exemplo a seguir demonstra a criação de um objeto global [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) . Esse padrão se aplica não apenas à `Scheduler` classe, mas todos os outros tipos fornecidos pelo tempo de execução de simultaneidade. É recomendável que você não siga esse padrão porque ele pode causar um comportamento inesperado em seu aplicativo.

[!code-cpp[concrt-global-scheduler#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_6.cpp)]

Para obter exemplos da maneira correta de criar `Scheduler` objetos, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

[[Superior](#top)]

## <a name="do-not-use-concurrency-objects-in-shared-data-segments"></a><a name="shared-data"></a>Não use objetos de simultaneidade em segmentos de dados compartilhados

O Tempo de Execução de Simultaneidade não dá suporte ao uso de objetos de simultaneidade em uma seção de dados compartilhados, por exemplo, uma seção de dados criada pela diretiva [data_seg](../../preprocessor/data-seg.md) `#pragma` . Um objeto de simultaneidade compartilhado entre limites de processo pode colocar o tempo de execução em um estado inconsistente ou inválido.

[[Superior](#top)]

## <a name="see-also"></a>Confira também

[Práticas recomendadas de Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime-best-practices.md)<br/>
[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)<br/>
[Comparando estruturas de dados de sincronização com a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md)<br/>
[Como: usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)<br/>
[Como: usar a assinatura em excesso para a latência de deslocamento](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)<br/>
[Como: usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)<br/>
[Walkthrough: removendo o trabalho de um thread de interface do usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)<br/>
[Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br/>
[Práticas recomendadas na biblioteca de agentes assíncronos](../../parallel/concrt/best-practices-in-the-asynchronous-agents-library.md)
