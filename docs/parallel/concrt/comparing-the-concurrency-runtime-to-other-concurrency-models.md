---
title: "Comparando o tempo de execução de simultaneidade com outros modelos de simultaneidade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: Concurrency Runtime, compared to other models
ms.assetid: d8b9a1f4-f15f-43c3-a5b4-c0991edf9c86
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e20523eb8a2c78cfa72b6c3084e9ca9f620a916c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comparing-the-concurrency-runtime-to-other-concurrency-models"></a>Comparando o Tempo de Execução de Simultaneidade com outros modelos de simultaneidade
Este documento descreve as diferenças entre os recursos e modelos de programação de tempo de execução de simultaneidade e outras tecnologias. Compreendendo como as vantagens do tempo de execução de simultaneidade em comparação com os benefícios de outros modelos de programação, você pode selecionar a tecnologia que melhor satisfaz os requisitos de seus aplicativos.  
  
 Se você estiver usando outro modelo de programação, como o pool de threads do Windows ou OpenMP, há situações em que pode ser apropriado migrar para o tempo de execução de simultaneidade. Por exemplo, o tópico [migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md) descreve quando é apropriado migrar de OpenMP no tempo de execução de simultaneidade. No entanto, se você estiver satisfeito com o desempenho do aplicativo e suporte de depuração atual, migração não é necessária.  
  
 Você pode usar os recursos e benefícios de produtividade de tempo de execução de simultaneidade para complementar o aplicativo existente que usa outro modelo de simultaneidade. O tempo de execução de simultaneidade não garante o balanceamento de carga quando vários agendadores de tarefa disputam os mesmos recursos de computação. No entanto, quando as cargas de trabalho não se sobrepõem, esse efeito é mínimo.  
  
##  <a name="top"></a>Seções  
  
-   [Comparando o agendamento preventivo para agendamento cooperativo](#models)  
  
-   [Comparando o tempo de execução de simultaneidade para a API do Windows](#winapi)  
  
-   [Comparando o tempo de execução de simultaneidade para OpenMP](#openmp)  
  
##  <a name="models"></a>Comparando o agendamento preventivo para agendamento cooperativo  
 O modelo preemptivo e cooperativo agendamento modelos são duas maneiras de habilitar várias tarefas compartilhem recursos de computação, por exemplo, processadores ou segmentos de hardware.  
  
### <a name="preemptive-and-cooperative-scheduling"></a>Agendamento preventivo e cooperativo  
 *Agendamento preventivo* é um mecanismo baseado em prioridade, round-robin que oferece cada tarefa de acesso exclusivo a um recurso de computação para um determinado período de tempo e, em seguida, alterna para outra tarefa. Agendamento preventivo é comum em sistemas operacionais de multitarefa como o Windows*. Agendando cooperativo* é um mecanismo que fornece cada tarefa de acesso exclusivo a um recurso de computação até que a tarefa seja concluída ou até que a tarefa gera seu acesso ao recurso. O tempo de execução de simultaneidade usa agendamento cooperativo junto com o Agendador preemptivo do sistema operacional para obter o máximo uso dos recursos de processamento.  
  
### <a name="differences-between-preemptive-and-cooperative-schedulers"></a>Diferenças entre os agendadores preemptivo e cooperativos  
 Buscam de agendadores preventivos fornecer vários threads igual acesso a recursos para garantir que cada thread faz o progresso de computação. Em computadores que têm muitos recursos de computação, garantindo o acesso razoável se torna menos problemático; No entanto, garantir o uso eficiente dos recursos se torna mais problemático.  
  
 Um agendador de modo de kernel preemptivo requer o código do aplicativo depende do sistema operacional para tomar decisões de planejamento. Por outro lado, um agendador cooperativo do modo de usuário permite que o código de aplicativo tomar decisões seus próprio plano. Como agendar cooperativo permite que muitas decisões de planejamento a serem feitas pelo aplicativo, reduz muito a sobrecarga associada com a sincronização do modo kernel. Um agendador cooperativo adia geralmente as decisões de programação para o kernel do sistema operacional quando ele não tem nenhum outro trabalho agendar. Um agendador cooperativo também passa para o Agendador de sistema operacional quando há uma operação de bloqueio que é comunicada do kernel, mas que a operação não é comunicada ao Agendador do modo de usuário.  
  
### <a name="cooperative-scheduling-and-efficiency"></a>Cooperativa de agendamento e a eficiência  
 Para um agendador preemptivo, todo o trabalho que tem o mesmo nível de prioridade é igual. Normalmente, um agendador preemptivo agenda threads na ordem em que eles são criados. Além disso, um agendador preemptivo fornece cada thread de um intervalo de tempo de uma forma de rodízio, com base na prioridade de thread. Embora esse mecanismo fornece integridade (cada thread faz progresso), ele tem algumas custo de eficiência. Por exemplo, muitos algoritmos de computação intensa não exigem a integridade. Em vez disso, é importante que as tarefas relacionadas concluída no tempo menos geral. Agendando cooperativo permite que um aplicativo agendar o trabalho com mais eficiência. Por exemplo, considere um aplicativo que tenha o número de threads. Agendamento de threads que não compartilham os recursos para execução simultânea pode reduzir a sobrecarga de sincronização e, portanto, aumentar a eficiência. Outra maneira eficiente de agendar tarefas é executar pipelines de tarefas (onde cada tarefa atua na saída do anterior) no mesmo processador para que a entrada de cada estágio do pipeline já foi carregada no cache de memória.  
  
### <a name="using-preemptive-and-cooperative-scheduling-together"></a>Usar agendamento preventivo e cooperativo juntos  
 Agendando cooperativo não resolve todos os problemas de agendamento. Por exemplo, tarefas que não geram bastante para outras tarefas podem consumir todos os recursos de computação disponíveis e impedir que outras tarefas progredindo. O tempo de execução de simultaneidade usa os benefícios da eficiência de agendamento cooperativo para complementar as garantias de integridade de agendamento preemptivo. Por padrão, o tempo de execução de simultaneidade fornece um agendador cooperativo que usa um algoritmo de roubo de trabalho para distribuir o trabalho entre os recursos de computação com eficiência. No entanto, o Agendador de tempo de execução de simultaneidade também se baseia no Agendador do sistema operacional preemptivo bastante distribua recursos entre aplicativos. Você também pode criar políticas de agendador e agendadores personalizados em seus aplicativos para produzir um controle refinado sobre a execução do thread.  
  
 [[Superior](#top)]  
  
##  <a name="winapi"></a>Comparando o tempo de execução de simultaneidade para a API do Windows  
 Interface de programação de aplicativo Microsoft Windows, que é normalmente conhecido como a API do Windows (e anteriormente conhecido como Win32), fornece um modelo de programação que permite a simultaneidade em seus aplicativos. O tempo de execução de simultaneidade é baseado na API do Windows para fornecer modelos adicionais de programação que não estão disponíveis no sistema operacional subjacente.  
  
 O tempo de execução de simultaneidade desenvolve o modelo de thread de API do Windows para executar o trabalho paralelo. Ele também usa o gerenciamento de memória de API do Windows e os mecanismos de armazenamento local de thread. No Windows 7 e Windows Server 2008 R2, ele usa o suporte da API do Windows para computadores que têm mais de 64 threads de hardware e usuário agendáveis threads. O tempo de execução de simultaneidade estende o modelo de API do Windows, fornecendo um agendador de tarefas cooperativo e um algoritmo de roubo de trabalho para maximizar o uso de recursos de computação e permitindo que várias instâncias simultâneas do Agendador.  
   
### <a name="programming-languages"></a>Linguagens de programação  
 A API do Windows usa a linguagem de programação C para expor o modelo de programação. O tempo de execução de simultaneidade fornece uma interface de programação em C++ que aproveita os recursos mais recentes na linguagem do C++. Por exemplo, funções de lambda fornecem um mecanismo de sucinto, fortemente tipado para definir as funções de trabalho paralelas. Para obter mais informações sobre os recursos mais recentes do C++ que usa o tempo de execução de simultaneidade, consulte [visão geral](../../parallel/concrt/asynchronous-message-blocks.md).  
  
### <a name="threads-and-thread-pools"></a>Threads e Pools de threads  
 O mecanismo de simultaneidade central na API do Windows é o thread. Você normalmente usa o [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) função para criar threads. Embora os threads são relativamente fáceis de criar e usar, o sistema operacional aloca uma quantidade significativa de tempo e outros recursos para gerenciá-los. Além disso, embora cada thread é garantido para receber o mesmo tempo de execução como qualquer outro thread no mesmo nível de prioridade, associado sobrecarga requer que você crie tarefas grandes o suficiente. Para tarefas mais refinadas ou menores, a sobrecarga associada a simultaneidade pode sobrecarregar o benefício de executar as tarefas em paralelo.  
  
 Pools de threads são uma maneira de reduzir o custo de gerenciamento de threads. Pools de threads personalizados e a implementação de pool de threads é fornecida pela API do Windows, ambos habilitam os itens de trabalho executar com eficiência em paralelo. O pool de threads do Windows mantém os itens de trabalho em uma fila primeiro a entrar, primeiro a sair (PEPS). Cada item de trabalho é iniciado na ordem em que foi adicionado ao pool.  
  
 O tempo de execução de simultaneidade implementa um algoritmo de roubo de trabalho para estender o FIFO mecanismo de agendamento. O algoritmo move tarefas que ainda não foram iniciados para threads que executam o fora de itens de trabalho. Embora o algoritmo de roubo de trabalho pode equilibrar as cargas de trabalho, também pode causar itens de trabalho a ser reorganizado. Esse processo reordenação pode causar um item de trabalho Iniciar em uma ordem diferente do que foi enviado. Isso é útil com algoritmos recursivos, onde há uma melhor chance de que os dados são compartilhados entre as tarefas mais recentes que entre os mais antigos. Obter os novos itens para ser executado primeiro significa menos erros de cache e possivelmente menos falhas de página.  
  
 Da perspectiva do sistema operacional, é desleal roubo de trabalho. No entanto, quando um aplicativo implementa um algoritmo ou tarefa para ser executada em paralelo, integridade entre as subtarefas não é sempre importante. O que é importante é como rapidamente a tarefa for concluída. Para outros algoritmos FIFO é a estratégia de agendamento apropriada.  
  
### <a name="behavior-on-various-operating-systems"></a>Comportamento de vários sistemas operacionais  
 No Windows XP e Windows Vista, os aplicativos que usam o tempo de execução de simultaneidade se comportam da mesma forma, exceto que o desempenho de heap foi aprimorado no Windows Vista.  
  
 No Windows 7 e Windows Server 2008 R2, o sistema operacional mais dá suporte a simultaneidade e a escalabilidade. Por exemplo, esses sistemas operacionais oferecem suporte a computadores que têm mais de 64 threads de hardware. Um aplicativo existente que usa a API do Windows deve ser modificado para tirar proveito dos novos recursos. No entanto, um aplicativo que usa o tempo de execução de simultaneidade automaticamente usa esses recursos e não exigem modificações.  
  
 [base.User mode_scheduling](http://msdn.microsoft.com/library/windows/desktop/dd627187)  
  
 [[Superior](#top)]  
  
##  <a name="openmp"></a>Comparando o tempo de execução de simultaneidade para OpenMP  
 O tempo de execução de simultaneidade permite uma variedade de modelos de programação. Esses modelos podem se sobrepor ou complementar os modelos de outras bibliotecas. Esta seção compara o tempo de execução de simultaneidade para [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp).  
  
 O modelo de programação OpenMP é definido por um padrão aberto e tem associações bem definidas para as linguagens de programação Fortran e C/C++. Versões de OpenMP 2.0 e 2.5 são apropriadas para os algoritmos paralelos que estão iterativos; ou seja, eles executam a iteração paralela em uma matriz de dados. OpenMP é mais eficiente quando o grau de paralelismo é predeterminado e corresponde os recursos disponíveis no sistema. O modelo de OpenMP é um especialmente adequado para a computação de alto desempenho, em que grandes problemas computacionais são distribuídos entre os recursos de processamento de um único computador. Nesse cenário, o ambiente de hardware é conhecido e o desenvolvedor pode esperar tenham acesso exclusivo aos recursos de computação quando o algoritmo é executado.  
  
 No entanto, outras, menos restrito ambientes de computação pode não ser uma boa correspondência para OpenMP. Por exemplo, problemas de recursiva (como o algoritmo quicksort ou pesquisar uma árvore de dados) são mais difíceis de implementar usando OpenMP. O tempo de execução de simultaneidade complementa os recursos do OpenMP fornecendo o [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL) e o [biblioteca de agentes assíncrona](../../parallel/concrt/asynchronous-agents-library.md). Ao contrário do OpenMP, o tempo de execução de simultaneidade fornece um agendador dinâmico que se adapta a recursos disponíveis e ajusta o grau de paralelismo como alterar as cargas de trabalho.  
  
 Muitos dos recursos no tempo de execução de simultaneidade podem ser estendidos. Você também pode combinar os recursos existentes para compor novas. Como OpenMP depende de diretivas de compilador, ele não pode ser estendido facilmente.  
  
 Para obter mais informações sobre como compara o tempo de execução de simultaneidade OpenMP e como migrar o código OpenMP existente para usar o tempo de execução de simultaneidade, consulte [migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md).  
  
 [[Superior](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime.md)     
 [Visão geral](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)   
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp)
