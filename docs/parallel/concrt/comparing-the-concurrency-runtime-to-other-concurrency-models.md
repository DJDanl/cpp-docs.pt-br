---
title: Comparando o tempo de execução de simultaneidade com outros modelos de simultaneidade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Concurrency Runtime, compared to other models
ms.assetid: d8b9a1f4-f15f-43c3-a5b4-c0991edf9c86
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4c0647b05f0f9dce7c3f9b9b1b79668646dbb874
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46423345"
---
# <a name="comparing-the-concurrency-runtime-to-other-concurrency-models"></a>Comparando o Tempo de Execução de Simultaneidade com outros modelos de simultaneidade

Este documento descreve as diferenças entre os recursos e modelos de programação de tempo de execução de simultaneidade e outras tecnologias. Ao entender como os benefícios do tempo de execução de simultaneidade se comparam com os benefícios de outros modelos de programação, você pode selecionar a tecnologia que melhor satisfaz os requisitos de seus aplicativos.

Se você estiver usando outro modelo de programação, como o pool de threads do Windows ou o OpenMP, há situações em que pode ser apropriado migrar para o tempo de execução de simultaneidade. Por exemplo, o tópico [migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md) descreve quando pode ser apropriado migrar de OpenMP no tempo de execução de simultaneidade. No entanto, se você estiver satisfeito com o desempenho do aplicativo e o suporte de depuração atual, migração não é necessária.

Você pode usar os recursos e benefícios de produtividade do tempo de execução de simultaneidade para complementar seu aplicativo existente que usa outro modelo de simultaneidade. O tempo de execução de simultaneidade não pode garantir o balanceamento de carga quando vários agendadores de tarefas competem pelos mesmos recursos de computação. No entanto, quando as cargas de trabalho não se sobrepõem, esse efeito é mínimo.

##  <a name="top"></a> Seções

- [Comparando o agendamento preemptivo ao agendamento cooperativo](#models)

- [Comparando o tempo de execução de simultaneidade para o API do Windows](#winapi)

- [Comparando o tempo de execução de simultaneidade para OpenMP](#openmp)

##  <a name="models"></a> Comparando o agendamento preemptivo ao agendamento cooperativo

O modelo preemptive e o cooperativo agendamento modelos são duas maneiras comuns de permitem que várias tarefas compartilhar recursos de computação, por exemplo, processadores ou segmentos de hardware.

### <a name="preemptive-and-cooperative-scheduling"></a>Agendamento preemptivo e cooperativo

*Agendamento preemptivo* é um mecanismo round-robin, com base em prioridade que oferece cada acesso exclusivo da tarefa a um recurso de computação para um determinado período de tempo e, em seguida, alterna para outra tarefa. Agendamento preventivo é comum em sistemas operacionais de multitarefa, como Windows *. Agendando cooperativo* é um mecanismo que fornece cada acesso exclusivo da tarefa a um recurso de computação até que a tarefa seja concluída ou até que a tarefa gera seu acesso ao recurso. O tempo de execução de simultaneidade usa agendamento cooperativo junto com o Agendador preemptive do sistema operacional para alcançar a utilização máxima dos recursos de processamento.

### <a name="differences-between-preemptive-and-cooperative-schedulers"></a>Diferenças entre os agendadores Preemptive e cooperativos

Buscam de agendadores PreEmptive conceder acesso igual de vários threads a computação recursos para garantir que cada thread progride. Em computadores que têm muitos recursos de computação, garantir acesso razoável se torna menos problemático; No entanto, garantir uma utilização eficiente dos recursos se torna mais problemático.

Um agendador de modo de kernel preemptive exige que o código do aplicativo depender do sistema operacional para tomar decisões de agendamento. Por outro lado, um agendador cooperativo de modo de usuário permite que o código do aplicativo tomar decisões de seus próprio agendamento. Como cooperativo de agendamento permite que muitas decisões de programação sejam feitas pelo aplicativo, ele reduz muito a sobrecarga associada com a sincronização do modo kernel. Um agendador cooperativo normalmente adia decisões de programação para o kernel do sistema operacional quando ele não tem nenhum outro trabalho para agendar. Um agendador cooperativo também passa para o Agendador de sistema operacional quando há uma operação de bloqueio que é comunicada para o kernel, mas que a operação não é comunicada para o Agendador de modo de usuário.

### <a name="cooperative-scheduling-and-efficiency"></a>Cooperativo de agendamento e a eficiência

Para um agendador preemptivo, todo o trabalho que tem o mesmo nível de prioridade é igual. Normalmente, um agendador preemptive agenda threads na ordem em que eles são criados. Além disso, um agendador preemptive fornece todos os threads uma fração de tempo de forma round-robin, com base na prioridade de thread. Embora esse mecanismo fornece imparcialidade (cada thread faz progresso progressivo), ele vem com algum custo de eficiência. Por exemplo, muitos algoritmos de computação intensiva não exigem a imparcialidade. Em vez disso, é importante que as tarefas relacionadas terminar no tempo menos geral. Agendando cooperativo permite que um aplicativo agendar o trabalho com mais eficiência. Por exemplo, considere um aplicativo que tenha vários threads. Agendamento de threads que não compartilham os recursos sejam executadas simultaneamente pode reduzir a sobrecarga de sincronização e, assim, aumentar a eficiência. Outra maneira eficiente de agendar tarefas é executar pipelines de tarefas (em que cada tarefa atua na saída anterior) no mesmo processador para que a entrada de cada estágio de pipeline já foi carregada no cache de memória.

### <a name="using-preemptive-and-cooperative-scheduling-together"></a>Usar agendamento preemptivo e cooperativo juntos

Agendando cooperativo não resolve todos os problemas de agendamento. Por exemplo, tarefas que não produzam bastante a outras tarefas podem consumir todos os recursos de computação disponíveis e impedir que outras tarefas de progredir. O tempo de execução de simultaneidade usa os benefícios de eficiência do agendamento cooperativo para complementar as garantias de imparcialidade de agendamento preemptivo. Por padrão, o tempo de execução de simultaneidade fornece um agendador cooperativo que usa um algoritmo de roubo de trabalho para distribuir o trabalho entre os recursos de computação com eficiência. No entanto, o Agendador de tempo de execução de simultaneidade também utiliza o Agendador preemptive do sistema operacional para distribuir bastante recursos entre os aplicativos. Você também pode criar políticas de agendador e agendadores personalizados em seus aplicativos para produzir um controle refinado sobre a execução do thread.

[[Superior](#top)]

##  <a name="winapi"></a> Comparando o tempo de execução de simultaneidade para o API do Windows

Interface de programação de aplicativo Microsoft Windows, que é normalmente conhecida como a API do Windows (e conhecida como Win32), fornece um modelo de programação que permite a simultaneidade em seus aplicativos. O tempo de execução de simultaneidade se baseia na API do Windows para fornecer modelos de programação adicionais que não estão disponíveis no sistema operacional subjacente.

O tempo de execução de simultaneidade desenvolve o modelo de thread de API do Windows para executar o trabalho paralelo. Ele também usa os mecanismos de armazenamento local de thread e o gerenciamento de memória de API do Windows. No Windows 7 e Windows Server 2008 R2, ele usa o suporte da API do Windows para computadores que têm mais de 64 threads de hardware e threads agendáveis ao usuário. O tempo de execução de simultaneidade estende o modelo de API do Windows, fornecendo um agendador de tarefas cooperativo e um algoritmo de roubo de trabalho para maximizar o uso de recursos de computação e permitindo que várias instâncias simultâneas do Agendador.

### <a name="programming-languages"></a>Linguagens de programação

A API do Windows usa a linguagem de programação C para expor o modelo de programação. O tempo de execução de simultaneidade fornece uma interface de programação de C++ que tira proveito dos recursos mais recentes na linguagem C++. Por exemplo, as funções lambda fornecem um mecanismo de sucinto, fortemente tipada para definir funções de trabalho paralelas. Para obter mais informações sobre os recursos mais recentes do C++ que usa o tempo de execução de simultaneidade, consulte [visão geral](../../parallel/concrt/asynchronous-message-blocks.md).

### <a name="threads-and-thread-pools"></a>Threads e Pools de threads

O mecanismo de simultaneidade central na API do Windows é o thread. Normalmente, você usa o [CreateThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) função para criar threads. Embora os threads são relativamente fáceis de criar e usar, o sistema operacional aloca uma quantidade significativa de tempo e outros recursos para gerenciá-los. Além disso, embora cada thread é garantido para receber o mesmo tempo de execução como qualquer outro thread no mesmo nível de prioridade, associado sobrecarga requer que você crie tarefas grandes o suficiente. Para tarefas mais refinadas ou menores, a sobrecarga associada a simultaneidade pode superar o benefício de executar as tarefas em paralelo.

Pools de threads são uma maneira de reduzir o custo de gerenciamento de threads. Pools de threads personalizado e a implementação do pool de thread é fornecida pela API do Windows, as duas habilitam a itens de trabalho pequeno executar com eficiência em paralelo. O pool de threads do Windows mantém os itens de trabalho em uma fila primeiro a entrar, primeiro a sair (PEPS). Cada item de trabalho é iniciado na ordem em que foi adicionado ao pool.

O tempo de execução de simultaneidade implementa um algoritmo de roubo de trabalho para estender o mecanismo de agendamento de PEPS. O algoritmo move as tarefas que ainda não começou para threads que executam o fora de itens de trabalho. Embora o algoritmo de roubo de trabalho pode balancear cargas de trabalho, ele também pode causar os itens de trabalho a ser reorganizado. Esse processo reordenação pode causar um item de trabalho Iniciar em uma ordem diferente do que ele foi enviado. Isso é útil com algoritmos recursivos, onde há uma melhor chance de que os dados são compartilhados entre tarefas mais recentes do que entre os mais antigos. Obter os novos itens para serem executados primeiro significa menos erros de cache e, possivelmente, menos falhas de página.

Da perspectiva do sistema operacional, o roubo de trabalho é injusto. No entanto, quando um aplicativo implementa um algoritmo ou a tarefa seja executada em paralelo, honestidade entre as subtarefas não é sempre importante. O que é importante é o quão rapidamente a tarefa geral for concluída. Para outros algoritmos FIFO é a estratégia apropriada de agendamento.

### <a name="behavior-on-various-operating-systems"></a>Comportamento em vários sistemas operacionais

No Windows XP e no Windows Vista, aplicativos que usam o tempo de execução de simultaneidade se comportam da mesma forma, exceto que o desempenho de heap é aprimorado no Windows Vista.

No Windows 7 e Windows Server 2008 R2, o sistema operacional ainda mais dá suporte à simultaneidade e escalabilidade. Por exemplo, esses sistemas operacionais dão suporte a computadores que têm mais de 64 threads de hardware. Um aplicativo existente que usa a API do Windows deve ser modificado para tirar proveito desses novos recursos. No entanto, um aplicativo que usa o tempo de execução de simultaneidade automaticamente usa esses recursos e não requer modificações.

[base.User mode_scheduling](https://msdn.microsoft.com/library/windows/desktop/dd627187)

[[Superior](#top)]

##  <a name="openmp"></a> Comparando o tempo de execução de simultaneidade para OpenMP

O tempo de execução de simultaneidade permite que uma variedade de modelos de programação. Esses modelos podem se sobrepor ou complementar os modelos de outras bibliotecas. Esta seção compara o tempo de execução de simultaneidade para [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp).

O modelo de programação OpenMP é definido por um padrão aberto e tem associações bem definidas para as linguagens de programação Fortran e C/C++. Versões do OpenMP 2.0 e 2.5 são destinadas para algoritmos paralelos são iterativos; ou seja, eles executam a iteração paralela em uma matriz de dados. OpenMP é mais eficiente quando o grau de paralelismo é predeterminado e corresponde os recursos disponíveis no sistema. O modelo de OpenMP é uma correspondência especialmente bons para computação de alto desempenho, em que grandes problemas computacionais são distribuídos entre os recursos de processamento de um único computador. Nesse cenário, o ambiente de hardware é conhecido e o desenvolvedor razoável pode esperar ter acesso exclusivo aos recursos de computação quando o algoritmo é executado.

No entanto, outros, menos restrito ambientes de computação pode não ser uma boa correspondência para OpenMP. Por exemplo, problemas de recursiva (como o algoritmo quicksort ou pesquisar uma árvore de dados) são mais difíceis de implementar usando OpenMP. O tempo de execução de simultaneidade complementa os recursos do OpenMP, fornecendo o [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL) e o [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md). Ao contrário de OpenMP, o tempo de execução de simultaneidade fornece um agendador dinâmico que se adapta aos recursos disponíveis e ajusta o grau de paralelismo como alterar as cargas de trabalho.

Muitos dos recursos no tempo de execução de simultaneidade podem ser estendidos. Você também pode combinar os recursos existentes para redigir novas marcas. Como OpenMP depende de diretivas de compilador, ele não pode ser estendido facilmente.

Para obter mais informações sobre como compara o tempo de execução de simultaneidade para OpenMP e como migrar o código de OpenMP existente para usar o tempo de execução de simultaneidade, consulte [migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md).

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
[Visão geral](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp)
