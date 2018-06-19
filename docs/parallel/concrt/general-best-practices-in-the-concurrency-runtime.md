---
title: Práticas recomendadas gerais no tempo de execução de simultaneidade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Concurrency Runtime, general best practices
ms.assetid: ce5c784c-051e-44a6-be84-8b3e1139c18b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a2cd9cffa76ce179f478422af9c8efce380a2465
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33694112"
---
# <a name="general-best-practices-in-the-concurrency-runtime"></a>Práticas recomendadas gerais no Tempo de Execução de Simultaneidade
Este documento descreve as práticas recomendadas que se aplicam a várias áreas do tempo de execução de simultaneidade.  
  
##  <a name="top"></a> Seções  
 Este documento contém as seguintes seções:  
  
- [Usar construções de sincronização cooperativo quando possível](#synchronization)  
  
- [Evitar longas tarefas que não geram](#yield)  
  
- [Use o excesso de assinatura para operações de deslocamentos que bloqueiem ou ter alta latência](#oversubscription)  
  
- [Usar funções de gerenciamento de memória simultâneas quando possível](#memory)  
  
- [Use RAII para gerenciar o tempo de vida de objetos de simultaneidade](#raii)  
  
- [Não crie objetos de simultaneidade no escopo Global](#global-scope)  
  
- [Não Use objetos de simultaneidade em segmentos de dados compartilhados](#shared-data)  
  
##  <a name="synchronization"></a> Usar construções de sincronização cooperativo quando possível  
 O tempo de execução de simultaneidade fornece muitas construções de prova de simultaneidade que não necessitam de um objeto de sincronização externo. Por exemplo, o [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) classe fornece append seguro de simultaneidade e operações de acesso do elemento. No entanto, para casos em que você precisa de acesso exclusivo a um recurso, o tempo de execução fornece a [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md), [concurrency::reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md), e [simultaneidade :: evento](../../parallel/concrt/reference/event-class.md) classes. Esses tipos de se comportar de forma cooperativa; Portanto, o Agendador de tarefas pode realocar recursos de processamento para outro contexto, como a primeira tarefa aguarda os dados. Quando possível, use esses tipos de sincronização em vez de outros mecanismos de sincronização, como as fornecidas pela API do Windows, que não se comportar de forma cooperativa. Para obter mais informações sobre esses tipos de sincronização e um exemplo de código, consulte [estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md) e [comparando estruturas de dados de sincronização para a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md).  
  
 [[Superior](#top)]  
  
##  <a name="yield"></a> Evitar longas tarefas que não geram  
 Porque o Agendador de tarefas se comporta de forma cooperativa, ele não fornece integridade entre tarefas. Portanto, uma tarefa pode impedir que outras tarefas de iniciar. Embora isto seja aceitável em alguns casos, em outros casos isso pode causar deadlock ou privação.  
  
 O exemplo a seguir executa as tarefas mais que o número de recursos de processamento alocado. A primeira tarefa não gera para o Agendador de tarefas e, portanto, a segunda tarefa não inicia até que a primeira tarefa seja concluída.  
  
 [!code-cpp[concrt-cooperative-tasks#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_1.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
 1: 250000000 1: 500000000 1: 750000000 1: 1000000000 2: 250000000 2: 500000000 2: 750000000 2: 1000000000  
  

 Há várias maneiras de habilitar cooperação entre as duas tarefas. Uma maneira é ocasionalmente yield para o Agendador de tarefas em uma tarefa de longa execução. O exemplo a seguir modifica o `task` a função para chamar o [concurrency::Context::Yield](reference/context-class.md#yield) método para produzir a execução para o Agendador de tarefas para que possa executar outra tarefa.  

  
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
  
 O `Context::Yield` método produz somente outro thread ativo no Agendador ao qual o thread atual pertence, uma tarefa simples ou outro thread do sistema operacional. Esse método não gera funcione agendado para ser executado um [concurrency::task_group](reference/task-group-class.md) ou [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) do objeto, mas ainda não foi iniciado.  
  
 Existem outras maneiras de habilitar cooperação entre tarefas de longa execução. Você pode dividir uma tarefa grande em subtarefas menores. Você também pode habilitar o excesso de assinatura durante uma tarefa demorada. O excesso de assinaturas lhe permite criar mais threads do que o número de threads de hardware disponíveis. Excesso de assinatura é especialmente útil quando uma tarefa demorada contém uma grande quantidade de latência, por exemplo, dados de leitura de disco ou de uma conexão de rede. Para obter mais informações sobre tarefas leves e excesso de assinatura, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
 [[Superior](#top)]  
  
##  <a name="oversubscription"></a> Use o excesso de assinatura para operações de deslocamentos que bloqueiem ou ter alta latência  
 O tempo de execução de simultaneidade oferece primitivos de sincronização, como [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md), que permitem a tarefas de forma cooperativa bloquear e geram uns aos outros. Quando uma tarefa de forma cooperativa bloqueia ou gera, o Agendador de tarefas pode realocar recursos de processamento para outro contexto como a primeira tarefa aguarda os dados.  
  
 Há casos em que você não pode usar o mecanismo de bloqueio cooperativo que é fornecido pelo tempo de execução de simultaneidade. Por exemplo, uma biblioteca externa que você usar pode usar um mecanismo de sincronização diferentes. Outro exemplo é quando você executar uma operação que pode ter uma grande quantidade de latência, por exemplo, quando você usa a API do Windows `ReadFile` função para ler dados de uma conexão de rede. Nesses casos, o excesso de assinatura pode habilitar outras tarefas sejam executadas quando outra tarefa está ociosa. O excesso de assinaturas lhe permite criar mais threads do que o número de threads de hardware disponíveis.  
  
 Considere a seguinte função, `download`, que baixa o arquivo na URL fornecida. Este exemplo usa o [concurrency::Context::Oversubscribe](reference/context-class.md#oversubscribe) método para aumentar temporariamente o número de threads ativos.  

 [!code-cpp[concrt-download-oversubscription#4](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_3.cpp)]  
  
 Porque o `GetHttpFile` função executa uma operação potencialmente latente, excesso de assinatura pode habilitar outras tarefas sejam executadas como a tarefa atual aguarda os dados. Para obter a versão completa deste exemplo, consulte [como: excesso de assinatura usado para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).  
  
 [[Superior](#top)]  
  
##  <a name="memory"></a> Usar funções de gerenciamento de memória simultâneas quando possível  

 Use as funções de gerenciamento de memória, [concurrency::Alloc](reference/concurrency-namespace-functions.md#alloc) e [concurrency::Free](reference/concurrency-namespace-functions.md#free), quando você tiver tarefas refinadas que frequentemente alocam pequenos objetos que têm uma vida útil relativamente curta. O tempo de execução de simultaneidade mantém um cache de memória separada para cada thread em execução. O `Alloc` e `Free` funções alocar e liberar memória desses caches sem o uso de bloqueios ou barreiras de memória.  
  
 Para obter mais informações sobre essas funções de gerenciamento de memória, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md). Para obter um exemplo que usa essas funções, consulte [como: usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md).  
  
 [[Superior](#top)]  
  
##  <a name="raii"></a> Use RAII para gerenciar o tempo de vida de objetos de simultaneidade  
 O tempo de execução de simultaneidade usa para implementar recursos como o cancelamento de tratamento de exceção. Portanto, grave o código de exceção segura quando você chamar o tempo de execução ou chamar outra biblioteca que chama em tempo de execução.  
  
 O *recurso aquisição é inicialização* padrão (RAII) é uma maneira de gerenciar com segurança o tempo de vida de um objeto de simultaneidade em um determinado escopo. Em padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor é chamado antes de sair do escopo delimitador. Esse padrão é útil quando uma função contém várias `return` instruções. Esse padrão também ajuda você a escrever código de exceção-safe. Quando um `throw` instrução faz com que a pilha de desenrolar o destruidor para o objeto RAII é chamado; portanto, o recurso sempre corretamente é excluído ou liberado.  
  
 O tempo de execução define várias classes que usam o padrão RAII, por exemplo, [concurrency::critical_section::scoped_lock](../../parallel/concrt/reference/critical-section-class.md#critical_section__scoped_lock_class) e [concurrency::reader_writer_lock::scoped_lock](reference/reader-writer-lock-class.md#scoped_lock_class). Essas classes auxiliares são conhecidas como *escopo bloqueios*. Essas classes fornecem vários benefícios ao trabalhar com [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md) ou [concurrency::reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) objetos. O construtor dessas classes adquire acesso ao fornecido `critical_section` ou `reader_writer_lock` objeto; o acesso de versões do destruidor para esse objeto. Porque um bloqueio no escopo libera automaticamente acesso ao seu objeto de exclusão mútua quando ele é destruído, você não desbloquear manualmente o objeto subjacente.  
  
 Considere a seguinte classe, `account`, que é definido por uma biblioteca externa e, portanto, não pode ser modificado.  
  
 [!code-cpp[concrt-account-transactions#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_4.h)]  
  
 O exemplo a seguir executa várias transações em um `account` objeto em paralelo. O exemplo usa um `critical_section` objeto para sincronizar o acesso a `account` porque o `account` classe não é seguro de simultaneidade. Cada operação paralela usa um `critical_section::scoped_lock` objeto para garantir que o `critical_section` objeto está desbloqueado quando a operação for bem-sucedida ou falhar. Quando o saldo da conta é negativo, o `withdraw` operação falhar, lançando uma exceção.  
  
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
  
 Para obter exemplos adicionais que usam o padrão RAII para gerenciar o tempo de vida de objetos de simultaneidade, consulte [passo a passo: Removendo trabalho de um Thread de Interface do usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md), [como: usar a classe de contexto para implementar um cooperativo Semáforo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md), e [como: usar o excesso de assinatura para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).  
  
 [[Superior](#top)]  
  
##  <a name="global-scope"></a> Não crie objetos de simultaneidade no escopo Global  
 Quando você cria um objeto de simultaneidade no escopo global pode causar problemas, como memória ou deadlock violações de acesso ocorrer em seu aplicativo.  
  
 Por exemplo, quando você cria um objeto de tempo de execução de simultaneidade, o tempo de execução cria um agendador padrão para você, se ainda não foi criado. Um objeto de tempo de execução que é criado durante a construção do objeto global adequadamente fará com que o tempo de execução criar o Agendador de padrão. No entanto, esse processo leva um bloqueio interno, que pode interferir com a inicialização de outros objetos que dão suporte a infraestrutura de tempo de execução de simultaneidade. Esse bloqueio interno pode ser necessário por outro objeto de infraestrutura que ainda não foi inicializado e, portanto, pode causar deadlock ocorrem em seu aplicativo.  
  
 O exemplo a seguir demonstra a criação de um global [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) objeto. Esse padrão se aplicam não só para o `Scheduler` classe, mas todos os outros tipos que são fornecidos pelo tempo de execução de simultaneidade. É recomendável que você não seguir esse padrão porque ele pode causar um comportamento inesperado no seu aplicativo.  
  
 [!code-cpp[concrt-global-scheduler#1](../../parallel/concrt/codesnippet/cpp/general-best-practices-in-the-concurrency-runtime_6.cpp)]  
  
 Para obter exemplos da maneira correta de criar `Scheduler` objetos, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
 [[Superior](#top)]  
  
##  <a name="shared-data"></a> Não Use objetos de simultaneidade em segmentos de dados compartilhados  
 O tempo de execução de simultaneidade não suporta o uso de simultaneidade objetos em uma seção de dados compartilhada, por exemplo, uma seção de dados que é criada pelo [data_seg](../../preprocessor/data-seg.md) `#pragma` diretiva. Um objeto de simultaneidade é compartilhado entre limites de processo incluir o tempo de execução em um estado inconsistente ou inválido.  
  
 [[Superior](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Práticas recomendadas de tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-best-practices.md)   
 [Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)   
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)   
 [Comparando estruturas de dados de sincronização para a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md)   
 [Como: usar Alloc e Free para melhorar o desempenho de memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)   
 [Como: usar o excesso de assinatura para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)   
 [Como: usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)   
 [Passo a passo: Removendo trabalho de um Thread de Interface do usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)   
 [Práticas recomendadas na biblioteca de padrões paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)   
 [Práticas recomendadas na biblioteca de agentes assíncronos](../../parallel/concrt/best-practices-in-the-asynchronous-agents-library.md)
