---
title: Práticas recomendadas gerais no Tempo de Execução de Simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- Concurrency Runtime, general best practices
ms.assetid: ce5c784c-051e-44a6-be84-8b3e1139c18b
ms.openlocfilehash: e25011e2466d76c946cc55421ed228c8ea174161
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413912"
---
# <a name="general-best-practices-in-the-concurrency-runtime"></a>Práticas recomendadas gerais no Tempo de Execução de Simultaneidade

Este documento descreve as práticas recomendadas que se aplicam a várias áreas do tempo de execução de simultaneidade.

##  <a name="top"></a> Seções

Este documento contém as seguintes seções:

- [Usar construções de sincronização cooperativos quando possível](#synchronization)

- [Evitar tarefas longas que não produzam](#yield)

- [Usar excesso de assinatura para deslocar operações que bloqueiam ou têm alta latência](#oversubscription)

- [Usar funções de gerenciamento de memória simultâneas quando possível](#memory)

- [Usar RAII para gerenciar o tempo de vida de objetos de simultaneidade](#raii)

- [Não crie objetos de simultaneidade em escopo Global](#global-scope)

- [Não Use objetos de simultaneidade em segmentos de dados compartilhados](#shared-data)

##  <a name="synchronization"></a> Usar construções de sincronização cooperativos quando possível

O tempo de execução de simultaneidade fornece muitas construções de prova de simultaneidade que não exigem um objeto de sincronização externo. Por exemplo, o [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) classe fornece acréscimo protegido contra simultaneidade e operações de acesso de elemento. No entanto, para casos onde você requer acesso exclusivo a um recurso, o tempo de execução fornece o [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md), [concurrency::reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md), e [simultaneidade :: evento](../../parallel/concrt/reference/event-class.md) classes. Esses tipos se comportam de forma cooperativa; Portanto, o Agendador de tarefas pode realocar recursos de processamento para outro contexto, como a primeira tarefa espera por dados. Quando possível, use esses tipos de sincronização em vez de outros mecanismos de sincronização, como as fornecidas pela API do Windows, que não se comportam de forma cooperativa. Para obter mais informações sobre esses tipos de sincronização e um exemplo de código, consulte [estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md) e [comparando estruturas de dados de sincronização para a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md).

[[Top](#top)]

##  <a name="yield"></a> Evitar tarefas longas que não produzam

Como o Agendador de tarefas se comporta de forma cooperativa, ele não fornece honestidade entre tarefas. Portanto, uma tarefa pode impedir que outras tarefas de iniciar. Embora isso seja aceitável em alguns casos, em outros casos isso pode causar deadlock ou privação.

O exemplo a seguir executa as tarefas mais que o número de recursos de processamento alocado. A primeira tarefa não gera para o Agendador de tarefas e, portanto, a segunda tarefa não iniciará até que a primeira tarefa seja concluída.

[!code-cpp[concrt-cooperative-tasks#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_1.cpp)]

Este exemplo gera a seguinte saída:

1: 250000000 1: 500000000 1: 750000000 1: 1000000000 2: 250000000 2: 500000000 2: 750000000 2: 1000000000

Há várias maneiras para habilitar a cooperação entre as duas tarefas. É uma maneira de recebimento, ocasionalmente, o Agendador de tarefas em uma tarefa de longa execução. O exemplo a seguir modifica o `task` função a ser chamada a [concurrency::Context::Yield](reference/context-class.md#yield) método conceda a execução para o Agendador de tarefas para que outra tarefa pode ser executada.

[!code-cpp[concrt-cooperative-tasks#2](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_2.cpp)]

Este exemplo gera a seguinte saída:

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

O `Context::Yield` método produz apenas outro thread ativo no Agendador ao qual o thread atual pertence, uma tarefa leve ou outro thread do sistema operacional. Esse método não produz de trabalho que está agendado para ser executado um [Concurrency:: task_group](reference/task-group-class.md) ou [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objeto, mas ainda não foi iniciado.

Há outras maneiras de habilitar a cooperação entre tarefas de longa execução. É possível dividir uma grande tarefa em subtarefas menores. Você também pode habilitar assinaturas em excesso durante uma tarefa demorada. O excesso de assinaturas lhe permite criar mais threads do que o número de threads de hardware disponíveis. Excesso de assinatura é especialmente útil quando uma tarefa demorada contém uma grande quantidade de latência, por exemplo, ler dados do disco ou de uma conexão de rede. Para obter mais informações sobre tarefas leves e excesso de assinatura, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

[[Top](#top)]

##  <a name="oversubscription"></a> Usar excesso de assinatura para deslocar operações que bloqueiam ou têm alta latência

O tempo de execução de simultaneidade oferece primitivos de sincronização, como [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md), que permitem que tarefas de forma cooperativa bloquear e produzir uns aos outros. Quando uma tarefa de forma cooperativa bloqueia ou produz, o Agendador de tarefas pode realocar recursos de processamento para outro contexto como a primeira tarefa espera por dados.

Há casos em que você não pode usar o mecanismo de bloqueio cooperativo que é fornecido pelo tempo de execução de simultaneidade. Por exemplo, uma biblioteca externa que você usa pode usar um mecanismo de sincronização diferente. Outro exemplo é quando você executa uma operação que poderia ter uma grande quantidade de latência, por exemplo, quando você usa a API do Windows `ReadFile` função para ler dados de uma conexão de rede. Nesses casos, o excesso de assinatura pode habilitar outras tarefas para serem executadas quando outra tarefa estiver ociosa. O excesso de assinaturas lhe permite criar mais threads do que o número de threads de hardware disponíveis.

Considere a seguinte função, `download`, que baixa o arquivo na URL fornecida. Este exemplo usa o [concurrency::Context::Oversubscribe](reference/context-class.md#oversubscribe) método aumentar temporariamente o número de threads ativos.

[!code-cpp[concrt-download-oversubscription#4](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_3.cpp)]

Porque o `GetHttpFile` função executa uma operação potencialmente latente, excesso de assinatura pode habilitar outras tarefas sejam executadas conforme a tarefa atual espera por dados. Para obter a versão completa deste exemplo, consulte [como: Usar excesso de assinatura para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).

[[Top](#top)]

##  <a name="memory"></a> Usar funções de gerenciamento de memória simultâneas quando possível

Use as funções de gerenciamento de memória [concurrency::Alloc](reference/concurrency-namespace-functions.md#alloc) e [concurrency::Free](reference/concurrency-namespace-functions.md#free), quando você tiver tarefas refinadas que frequentemente alocam pequenos objetos que têm um tempo de vida relativamente curto. O tempo de execução de simultaneidade mantém um cache de memória separados para cada thread em execução. O `Alloc` e `Free` funções alocam e liberam memória a partir desses caches sem o uso de bloqueios ou as barreiras de memória.

Para obter mais informações sobre essas funções de gerenciamento de memória, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md). Para obter um exemplo que usa essas funções, consulte [como: Usar Alloc e Free para melhorar o desempenho de memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md).

[[Top](#top)]

##  <a name="raii"></a> Usar RAII para gerenciar o tempo de vida de objetos de simultaneidade

O tempo de execução de simultaneidade usa o tratamento de exceções para implementar recursos como o cancelamento. Portanto, escreva o código de exceção seguros quando você chama o tempo de execução ou chame outra biblioteca que chama o tempo de execução.

O *recurso de aquisição é inicialização* padrão (RAII) é uma maneira de gerenciar com segurança o tempo de vida de um objeto de simultaneidade em um determinado escopo. Sob o padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor é chamado antes de sair do escopo delimitador. Esse padrão é útil quando uma função contém várias `return` instruções. Esse padrão também ajuda você a escrever código de exceção segura. Quando um `throw` instrução faz com que a pilha de desenrolamento, o destruidor para o objeto RAII é chamado; portanto, o recurso sempre corretamente é excluído ou liberado.

O tempo de execução define várias classes que usam o padrão RAII, por exemplo, [concurrency::critical_section::scoped_lock](../../parallel/concrt/reference/critical-section-class.md#critical_section__scoped_lock_class) e [concurrency::reader_writer_lock::scoped_lock](reference/reader-writer-lock-class.md#scoped_lock_class). Essas classes auxiliares são conhecidas como *com escopo de bloqueios*. Essas classes fornecem vários benefícios ao trabalhar com [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md) ou [concurrency::reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) objetos. O construtor dessas classes adquire acesso ao fornecido `critical_section` ou `reader_writer_lock` objeto; o acesso de versões do destruidor àquele objeto. Porque um bloqueio no escopo libera automaticamente acesso ao seu objeto de exclusão mútua quando ele for destruído, você não desbloquear manualmente o objeto subjacente.

Considere a seguinte classe, `account`, que é definido por uma biblioteca externa e, portanto, não pode ser modificado.

[!code-cpp[concrt-account-transactions#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_4.h)]

O exemplo a seguir executa várias transações em um `account` objeto em paralelo. O exemplo usa uma `critical_section` objeto para sincronizar o acesso para o `account` porque o `account` classe não é seguro em simultaneidade. Cada operação paralela usa um `critical_section::scoped_lock` objeto para garantir que o `critical_section` objeto é desbloqueado quando a operação for bem-sucedida ou falha. Quando o saldo da conta é negativo, o `withdraw` operação falhar, lançando uma exceção.

[!code-cpp[concrt-account-transactions#2](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_5.cpp)]

Este exemplo produz a saída de exemplo a seguir:

```Output
Balance before deposit: 1924
Balance after deposit: 2924
Balance before withdrawal: 2924
Balance after withdrawal: -76
Balance before withdrawal: -76
Error details:
    negative balance: -76
```

Para obter exemplos adicionais que usam o padrão RAII para gerenciar o tempo de vida de objetos de simultaneidade, consulte [passo a passo: Removendo trabalho de um Thread de Interface do usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md), [como: Use a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md), e [como: Usar excesso de assinatura para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).

[[Top](#top)]

##  <a name="global-scope"></a> Não crie objetos de simultaneidade em escopo Global

Quando você cria um objeto de simultaneidade em escopo global pode causar problemas, como memória ou deadlock violações de acesso ocorrem em seu aplicativo.

Por exemplo, quando você cria um objeto de tempo de execução de simultaneidade, o tempo de execução cria um agendador padrão para você, se um ainda não foi criado. Um objeto de tempo de execução que é criado durante a construção do objeto global adequadamente fará com que o tempo de execução criar este agendador padrão. No entanto, esse processo leva um bloqueio interno, o que pode interferir com a inicialização de outros objetos que dão suporte a infraestrutura de tempo de execução de simultaneidade. Esse bloqueio interno pode ser necessário por outro objeto de infraestrutura que ainda não foi inicializado e, portanto, pode causar um deadlock ocorrer em seu aplicativo.

O exemplo a seguir demonstra a criação de uma global [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) objeto. Esse padrão se aplica não só para o `Scheduler` classe, mas todos os outros tipos que são fornecidos pelo tempo de execução de simultaneidade. É recomendável que você não seguir esse padrão porque isso pode causar um comportamento inesperado em seu aplicativo.

[!code-cpp[concrt-global-scheduler#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_6.cpp)]

Para obter exemplos de maneira correta de criar `Scheduler` objetos, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

[[Top](#top)]

##  <a name="shared-data"></a> Não Use objetos de simultaneidade em segmentos de dados compartilhados

O tempo de execução de simultaneidade não suporta o uso de objetos de simultaneidade em uma seção de dados compartilhados, por exemplo, uma seção de dados que é criada pela [data_seg](../../preprocessor/data-seg.md) `#pragma` diretiva. Um objeto de simultaneidade que é compartilhado entre os limites do processo pode colocar o tempo de execução em um estado inconsistente ou inválido.

[[Top](#top)]

## <a name="see-also"></a>Consulte também

[Práticas recomendadas do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-best-practices.md)<br/>
[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)<br/>
[Comparando estruturas de dados de sincronização com a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md)<br/>
[Como: Usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)<br/>
[Como: Usar excesso de assinatura para compensar a latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)<br/>
[Como: Usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)<br/>
[Passo a passo: Removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)<br/>
[Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)<br/>
[Práticas recomendadas na biblioteca de agentes assíncronos](../../parallel/concrt/best-practices-in-the-asynchronous-agents-library.md)
