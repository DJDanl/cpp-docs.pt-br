---
title: "Pr&#225;ticas recomendadas gerais no Tempo de Execu&#231;&#227;o de Simultaneidade | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Tempo de execução de simultaneidade, práticas recomendadas gerais"
ms.assetid: ce5c784c-051e-44a6-be84-8b3e1139c18b
caps.latest.revision: 16
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pr&#225;ticas recomendadas gerais no Tempo de Execu&#231;&#227;o de Simultaneidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve as práticas recomendadas que se aplicam a várias áreas de tempo de execução de simultaneidade.  
  
##  <a name="top"></a> Seções  
 Este documento contém as seções a seguir:  
  
-   [Usar Constructos de Sincronização Cooperativos Quando Possível](#synchronization)  
  
-   [Evitar Tarefas Longas que não Produzam](#yield)  
  
-   [Usar Excesso de Assinatura para Deslocar Operações que Bloqueiam ou Têm Alta Latência](#oversubscription)  
  
-   [Usar Funções de Gerenciamento de Memória Simultâneas Quando Possível](#memory)  
  
-   [Usar RAII para Gerenciar o Tempo de Vida de Objetos de Simultaneidade](#raii)  
  
-   [Não Criar Objetos de Simultaneidade em Escopo Global](#global-scope)  
  
-   [Não Usar Objetos de Simultaneidade em Segmentos de Dados Compartilhados](#shared-data)  
  
##  <a name="synchronization"></a> Usar Constructos de Sincronização Cooperativos Quando Possível  
 O tempo de execução de simultaneidade fornece muitos as construções simultaneidade\- seguras que não exigem um objeto externo de sincronização.  Por exemplo, a classe de [concurrency::concurrent\_vector](../../parallel/concrt/reference/concurrent-vector-class.md) fornece simultaneidade\- seguro acrescenta e operações de acesso do elemento.  No entanto, para casos onde você requer acesso exclusivo a um recurso, o tempo de execução fornece [concurrency::critical\_section](../../parallel/concrt/reference/critical-section-class.md), [concurrency::reader\_writer\_lock](../Topic/reader_writer_lock%20Class.md), e classes de [concurrency::event](../Topic/event%20Class.md) .  Esses tipos se comportam cooperativa; em virtude disso, o agendador de tarefas pode realocar os recursos de processamento para outro contexto como a primeira tarefa espera dados.  Quando possível, use esses tipos de sincronização em vez de outros mecanismos de sincronização, como a fornecida pela API do windows, que não se comportam cooperativa.  Para obter mais informações sobre esses tipos de sincronização e um exemplo de código, consulte [Estruturas de dados de sincronização](../Topic/Synchronization%20Data%20Structures.md) e [Comparando estruturas de dados com a API do Windows](../Topic/Comparing%20Synchronization%20Data%20Structures%20to%20the%20Windows%20API.md).  
  
 \[[Superior](#top)\]  
  
##  <a name="yield"></a> Evitar Tarefas Longas que não Produzam  
 Como o agendador de tarefas se comporta cooperativa, o não fornece a equidade entre tarefas.  Em virtude disso, uma tarefa pode impedir que outras tarefas iniciem.  Embora isto seja aceitável em alguns casos, em outros casos isso pode causar um deadlock ou privação.  
  
 O exemplo a seguir executa tarefas mais do que o número de recursos processando atribuídos.  A primeira tarefa não gerencie ao agendador de tarefas e como consequência a segunda tarefa não for iniciado até que a primeira tarefa seja concluída.  
  
 [!code-cpp[concrt-cooperative-tasks#1](../../parallel/concrt/codesnippet/CPP/general-best-practices-in-the-concurrency-runtime_1.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
 1: 250000000 1: 500000000 1: 750000000 1: 1000000000 2: 250000000 2: 500000000 2: 750000000 2: 1000000000  
  
 Há várias maneiras de habilitar a cooperação entre as duas tarefas.  Um modo é produzir ocasionalmente ao agendador de tarefas em uma tarefa demorada.  O exemplo a seguir altera a função de `task` para chamar o método de [concurrency::Context::Yield](../Topic/Context::Yield%20Method.md) para produzir a execução no agendador de tarefas de modo que outra tarefa ser executada.  
  
 [!code-cpp[concrt-cooperative-tasks#2](../../parallel/concrt/codesnippet/CPP/general-best-practices-in-the-concurrency-runtime_2.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
  **1: 250000000**  
**2: 250000000**  
**1: 500000000**  
**2: 500000000**  
**1: 750000000**  
**2: 750000000**  
**1: 1000000000**  
**2: 1000000000** O método de `Context::Yield` gerencie somente outro thread ativo no agendador a que o thread atual, em uma tarefa de peso leve, ou em outro thread do sistema operacional.  Esse método não gerencie que o trabalho foi agendado para ser executado em um objeto de [concurrency::task\_group](../Topic/task_group%20Class.md) ou de [concurrency::structured\_task\_group](../../parallel/concrt/reference/structured-task-group-class.md) mas ainda não foi iniciado.  
  
 Há outras maneiras de habilitar a cooperação entre tarefas demoradas.  Você pode dividir uma grande tarefa em subtarefas menores.  Você também pode habilitar a sobresubscrição durante uma tarefa demorada.  A sobresubscrição permite criar mais threads que o número de threads de hardware disponível.  A sobresubscrição é especialmente útil quando uma tarefa demorada contém uma quantidade de alta latência, por exemplo, ler dados de disco ou de uma conexão de rede.  Para obter mais informações sobre as tarefas e de sobresubscrição superficial, consulte [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
 \[[Superior](#top)\]  
  
##  <a name="oversubscription"></a> Usar Excesso de Assinatura para Deslocar Operações que Bloqueiam ou Têm Alta Latência  
 O tempo de execução de simultaneidade fornece as primitivas de sincronização, como [concurrency::critical\_section](../../parallel/concrt/reference/critical-section-class.md), que permitem tarefas bloqueio e gerar cooperativa entre si.  Quando os blocos ou os vai de uma tarefa cooperativa, o agendador de tarefas possam realocar os recursos de processamento para outro contexto como a primeira tarefa espera dados.  
  
 Há casos nos quais você não pode usar o mecanismo cooperativo de bloqueio que é fornecido em tempo de execução de simultaneidade.  Por exemplo, uma biblioteca externo que você usa pode usar um mecanismo diferente de sincronização.  Outro exemplo é quando você executa uma operação que pode ter uma quantidade de alta latência, por exemplo, quando você usa a função de API `ReadFile` do windows para ler dados de uma conexão de rede.  Nesses casos, a sobresubscrição pode habilitar outras tarefas executar enquanto outra tarefa está ocioso.  A sobresubscrição permite criar mais threads que o número de threads de hardware disponível.  
  
 Considere a seguinte função, `download`, que carrega o arquivo na URL fornecido.  Este exemplo usa o método de [concurrency::Context::Oversubscribe](../Topic/Context::Oversubscribe%20Method.md) temporariamente para aumentar o número de threads ativos.  
  
 [!CODE [concrt-download-oversubscription#4](../CodeSnippet/VS_Snippets_ConcRT/concrt-download-oversubscription#4)]  
  
 Como a função de `GetHttpFile` executa uma operação potencialmente latente, a sobresubscrição pode habilitar outras tarefas executar enquanto a tarefa espera dados atual.  Para a versão completo deste exemplo, consulte [Como usar excesso de assinatura para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).  
  
 \[[Superior](#top)\]  
  
##  <a name="memory"></a> Usar Funções de Gerenciamento de Memória Simultâneas Quando Possível  
 Use as funções, [concurrency::Alloc](../Topic/Alloc%20Function.md) e [concurrency::Free](../Topic/Free%20Function.md)de gerenciamento de memória, quando você tem as tarefas refinados que atribuem que frequência os objetos pequenos que têm um tempo de vida relativamente curto.  O tempo de execução de simultaneidade mantém um cachê de memória separado para cada thread em execução.  As funções de `Alloc` e de `Free` atribuem e liberar a memória desses caches sem o uso de bloqueios ou de barreiras de memória.  
  
 Para obter mais informações sobre essas funções de gerenciamento de memória, consulte [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  Para obter um exemplo que usa essas funções, consulte [Como usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md).  
  
 \[[Superior](#top)\]  
  
##  <a name="raii"></a> Usar RAII para Gerenciar o Tempo de Vida de Objetos de Simultaneidade  
 O tempo de execução de simultaneidade usa a manipulação de exceção para implementar recursos como o cancelamento.  Consequentemente, escreva o código exceções gerais seguro quando você chama em tempo de execução chama ou outra biblioteca que chama em tempo de execução.  
  
 O padrão *Aquisição de recurso é inicialização* \(RAII\) é uma maneira de gerenciar a segurança do tempo de vida de um objeto de simultaneidade em um escopo fornecido.  No padrão de RAII, uma estrutura de dados é atribuída na pilha.  Se a estrutura de dados inicializa ou adquire um recurso quando é criada e destrói o ou versões esse recurso quando a estrutura de dados é destruída.  O padrão de RAII garante que o destruidor é chamado antes que o escopo inclusive encerrado.  Esse padrão é útil quando uma função contém várias instruções de `return` .  Ajuda desse padrão também você escreve o código seguro. exceções gerais  Quando uma instrução de `throw` faz com que a pilha desenrole, o destruidor para o objeto de RAII é chamado; em virtude disso, o recurso sempre corretamente é excluído ou liberado.  
  
 O tempo de execução define várias classes que usam o padrão de RAII, por exemplo, [concurrency::critical\_section::scoped\_lock](../Topic/critical_section::scoped_lock%20Class.md) e [concurrency::reader\_writer\_lock::scoped\_lock](../Topic/reader_writer_lock::scoped_lock%20Class.md).  Essas classes auxiliares são conhecidas como *bloqueios o escopo*.  Essas classes fornecem vários benefícios quando você trabalha com [concurrency::critical\_section](../../parallel/concrt/reference/critical-section-class.md) ou objetos de [concurrency::reader\_writer\_lock](../Topic/reader_writer_lock%20Class.md) .  O construtor dessas classes adquire o acesso a `critical_section` ou ao objeto fornecido de `reader_writer_lock` ; o acesso das versões de destruidor a esse objeto.  Como um acesso o escopo das versões de bloqueio ao objeto de exclusão mútua automaticamente quando é destruído, não desbloqueia manualmente o objeto subjacente.  
  
 Considere a seguinte classe, `account`, que é definida por uma biblioteca externo e não pode ser alterada em virtude disso.  
  
 [!CODE [concrt-account-transactions#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-account-transactions#1)]  
  
 O exemplo a seguir executa várias transações em um objeto de `account` em paralelo.  O exemplo usa um objeto de `critical_section` para sincronizar o acesso ao objeto de `account` como a classe de `account` não é simultaneidade\- segura.  Cada operação paralela usa um objeto de `critical_section::scoped_lock` para garantir que o objeto de `critical_section` está desbloqueado quando a operação é bem\-sucedida ou falha.  Quando o balanço de contas for negativo, a operação de `withdraw` falha se lançar uma exceção.  
  
 [!CODE [concrt-account-transactions#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-account-transactions#2)]  
  
 Este exemplo gerencia a seguinte saída de exemplo:  
  
  **Saldo antes do warehouse: 1924**  
**Saldo após o depósito: 2924**  
**Saldo antes de remover: 2924**  
**Saldo depois de remover: \-76**  
**Saldo antes de remover: \-76**  
**Detalhes do erro:**  
 **saldo negativo: \-76** Para obter exemplos adicionais que usam o padrão de RAII para gerenciar o tempo de vida de objetos de simultaneidade, consulte [Instruções passo a passo: removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md), [Como usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md), e [Como usar excesso de assinatura para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).  
  
 \[[Superior](#top)\]  
  
##  <a name="global-scope"></a> Não Criar Objetos de Simultaneidade em Escopo Global  
 Quando você cria um objeto de simultaneidade no escopo global você pode fazer com que os problemas como violações de acesso de deadlock ou de memória lógica em seu aplicativo.  
  
 Por exemplo, quando você cria um objeto de tempo de execução de simultaneidade, o tempo de execução cria um agendador padrão para um se você ainda não foi criado.  Um objeto de tempo de execução que é criado durante a compilação do objeto global adequadamente fará com que o tempo de execução criar este agendador padrão.  No entanto, esse processo leva um bloqueio interno, que poderão interferir na inicialização de outros objetos que oferecem suporte à infraestrutura de tempo de execução de simultaneidade.  Esse bloqueio interno pode ser necessário por outro objeto de infraestrutura que não foi inicializado, e isso pode fazer com que o deadlock ocorre em seu aplicativo.  
  
 O exemplo a seguir demonstra a criação de um objeto global de [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) .  Esse padrão é válido não só para a classe de `Scheduler` mas a todos os outros tipos que são fornecidos em tempo de execução de simultaneidade.  É recomendável não segue esse padrão porque pode provocar comportamento inesperado em seu aplicativo.  
  
 [!code-cpp[concrt-global-scheduler#1](../../parallel/concrt/codesnippet/CPP/general-best-practices-in-the-concurrency-runtime_3.cpp)]  
  
 Para obter exemplos da forma correta de criar objetos de `Scheduler` , consulte [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
 \[[Superior](#top)\]  
  
##  <a name="shared-data"></a> Não Usar Objetos de Simultaneidade em Segmentos de Dados Compartilhados  
 O tempo de execução de simultaneidade não oferece suporte ao uso de objetos de simultaneidade em uma seção compartilhada de dados, por exemplo, uma seção de dados que foi criada pela política de [data\_seg](../../preprocessor/data-seg.md)`#pragma` .  Um objeto de simultaneidade que é compartilhado entre limites de processo pode colocar o tempo de execução em um estado inconsistente ou inválido.  
  
 \[[Superior](#top)\]  
  
## Consulte também  
 [Práticas recomendadas do Tempo de Execução de Simultaneidade](../Topic/Concurrency%20Runtime%20Best%20Practices.md)   
 [Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md)   
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Estruturas de dados de sincronização](../Topic/Synchronization%20Data%20Structures.md)   
 [Comparando estruturas de dados com a API do Windows](../Topic/Comparing%20Synchronization%20Data%20Structures%20to%20the%20Windows%20API.md)   
 [Como usar Alloc e Free para melhorar o desempenho da memória](../../parallel/concrt/how-to-use-alloc-and-free-to-improve-memory-performance.md)   
 [Como usar excesso de assinatura para deslocar latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)   
 [Como usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)   
 [Instruções passo a passo: removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)   
 [Práticas recomendadas na Biblioteca de Padrões Paralelos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md)   
 [Práticas recomendadas na Biblioteca de Agentes Assíncrona](../Topic/Best%20Practices%20in%20the%20Asynchronous%20Agents%20Library.md)