---
title: Comparando o Runtime de Simultaneidade com outros modelos de simultaneidade
ms.date: 11/04/2016
helpviewer_keywords:
- Concurrency Runtime, compared to other models
ms.assetid: d8b9a1f4-f15f-43c3-a5b4-c0991edf9c86
ms.openlocfilehash: 5bc6691f6d0b166bb3084091ee6af70474937568
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79422251"
---
# <a name="comparing-the-concurrency-runtime-to-other-concurrency-models"></a>Comparando o Runtime de Simultaneidade com outros modelos de simultaneidade

Este documento descreve as diferenças entre os recursos e modelos de programação do Tempo de Execução de Simultaneidade e outras tecnologias. Ao compreender como os benefícios do Tempo de Execução de Simultaneidade se comparam aos benefícios de outros modelos de programação, você pode selecionar a tecnologia que melhor atenda aos requisitos de seus aplicativos.

Se você estiver usando outro modelo de programação, como o pool de threads do Windows ou OpenMP, há situações em que pode ser apropriado migrar para o Tempo de Execução de Simultaneidade. Por exemplo, o tópico [migrando de OpenMP para o tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md) descreve quando pode ser apropriado migrar de OpenMP para o tempo de execução de simultaneidade. No entanto, se você estiver satisfeito com o desempenho do aplicativo e com o suporte à depuração atual, a migração não será necessária.

Você pode usar os recursos e os benefícios de produtividade do Tempo de Execução de Simultaneidade para complementar seu aplicativo existente que usa outro modelo de simultaneidade. O Tempo de Execução de Simultaneidade não pode garantir o balanceamento de carga quando vários agendadores de tarefas conpetem para os mesmos recursos de computação. No entanto, quando as cargas de trabalho não se sobrepõem, esse efeito é mínimo.

## <a name="top"></a>As

- [Comparando agendamento preventivo com agendamento cooperativo](#models)

- [Comparando o Tempo de Execução de Simultaneidade à API do Windows](#winapi)

- [Comparando o Tempo de Execução de Simultaneidade ao OpenMP](#openmp)

## <a name="models"></a>Comparando agendamento preventivo com agendamento cooperativo

O modelo preventivo e os modelos de agendamento cooperativos são duas maneiras comuns de habilitar várias tarefas para compartilhar recursos de computação, por exemplo, processadores ou threads de hardware.

### <a name="preemptive-and-cooperative-scheduling"></a>Agendamento preventivo e cooperativo

O *agendamento preventivo* é um mecanismo baseado em prioridade e Round Robin que fornece a cada tarefa acesso exclusivo a um recurso de computação para um determinado período de tempo e, em seguida, alterna para outra tarefa. O agendamento preventivo é comum em sistemas operacionais multitarefas, como o Windows. O *agendamento de cooperação* é um mecanismo que dá a cada tarefa acesso exclusivo a um recurso de computação até que a tarefa seja concluída ou até que a tarefa resulte em seu acesso ao recurso. O Tempo de Execução de Simultaneidade usa o agendamento cooperativo junto com o Agendador preventivo do sistema operacional para obter o uso máximo de recursos de processamento.

### <a name="differences-between-preemptive-and-cooperative-schedulers"></a>Diferenças entre os agendadores Preemptive e cooperativos

Os agendadores preemptivos buscam fornecer a vários threads acesso igual aos recursos de computação para garantir que cada thread faça o progresso. Em computadores que têm muitos recursos de computação, garantindo que o acesso justo se torne menos problemático; no entanto, garantir uma utilização eficiente dos recursos se torna mais problemático.

Um Agendador de modo de kernel preemptivo requer que o código do aplicativo dependa do sistema operacional para tomar decisões de agendamento. Por outro lado, um Agendador cooperativo de modo de usuário permite que o código do aplicativo faça suas próprias decisões de agendamento. Como o agendamento de cooperação permite que muitas decisões de agendamento sejam feitas pelo aplicativo, ele reduz grande parte da sobrecarga associada à sincronização no modo kernel. Um Agendador cooperativo normalmente adia as decisões de agendamento para o kernel do sistema operacional quando ele não tem nenhum outro trabalho para agendar. Um Agendador cooperativo também adia o Agendador do sistema operacional quando há uma operação de bloqueio que é comunicada ao kernel, mas essa operação não é comunicada ao agendador do modo de usuário.

### <a name="cooperative-scheduling-and-efficiency"></a>Eficiência e agendamento de cooperação

Para um Agendador preventivo, todo o trabalho que tem o mesmo nível de prioridade é igual. Um Agendador preventivo normalmente agenda threads na ordem em que são criados. Além disso, um Agendador preventivo fornece a cada thread uma fatia de tempo de uma forma Round Robin, com base na prioridade do thread. Embora esse mecanismo forneça imparcialidade (cada thread faz o progresso), ele vem a um custo de eficiência. Por exemplo, muitos algoritmos de computação intensiva não exigem imparcialidade. Em vez disso, é importante que as tarefas relacionadas sejam concluídas no menor tempo geral. O agendamento de cooperação permite que um aplicativo agende trabalho com mais eficiência. Por exemplo, considere um aplicativo que tem muitos threads. O agendamento de threads que não compartilham recursos para execução simultânea pode reduzir a sobrecarga de sincronização e, assim, aumentar a eficiência. Outra maneira eficiente de agendar tarefas é executar pipelines de tarefas (em que cada tarefa atua na saída da anterior) no mesmo processador para que a entrada de cada estágio de pipeline já esteja carregada no cache de memória.

### <a name="using-preemptive-and-cooperative-scheduling-together"></a>Usando o programa de programação preemptivo e cooperativo juntos

O agendamento cooperativo não resolve todos os problemas de agendamento. Por exemplo, as tarefas que não produzem com certeza a outras tarefas podem consumir todos os recursos de computação disponíveis e impedir que outras tarefas façam progressos. O Tempo de Execução de Simultaneidade usa os benefícios de eficiência do agendamento cooperativo para complementar as garantias de imparcialidade do agendamento preventivo. Por padrão, o Tempo de Execução de Simultaneidade fornece um Agendador cooperativo que usa um algoritmo de roubo de trabalho para distribuir o trabalho com eficiência entre os recursos de computação. No entanto, o Agendador de Tempo de Execução de Simultaneidade também se baseia no Agendador preventivo do sistema operacional para distribuir os recursos de forma justa entre os aplicativos. Você também pode criar agendadores personalizados e políticas do Agendador em seus aplicativos para produzir um controle refinado sobre a execução do thread.

[[Superior](#top)]

## <a name="winapi"></a>Comparando o Tempo de Execução de Simultaneidade à API do Windows

A interface de programação de aplicativos do Microsoft Windows, que normalmente é chamada de API do Windows (e anteriormente conhecida como Win32), fornece um modelo de programação que permite a simultaneidade em seus aplicativos. O Tempo de Execução de Simultaneidade se baseia na API do Windows para fornecer modelos de programação adicionais que não estão disponíveis no sistema operacional subjacente.

O Tempo de Execução de Simultaneidade se baseia no modelo de thread da API do Windows para executar o trabalho paralelo. Ele também usa os mecanismos de gerenciamento de memória da API do Windows e armazenamento local de thread. No Windows 7 e no Windows Server 2008 R2, ele usa o suporte de API do Windows para threads agendáveis e computadores com mais de 64 threads de hardware. O Tempo de Execução de Simultaneidade estende o modelo da API do Windows fornecendo um Agendador de tarefas cooperativo e um algoritmo de roubo de trabalho para maximizar o uso de recursos de computação e habilitando várias instâncias simultâneas do Agendador.

### <a name="programming-languages"></a>Linguagens de Programação

A API do Windows usa a linguagem de programação C para expor o modelo de programação. O Tempo de Execução de Simultaneidade fornece uma C++ interface de programação que aproveita os recursos mais recentes do C++ idioma. Por exemplo, as funções lambda fornecem um mecanismo sucinto de tipo seguro para definir funções de trabalho paralelas. Para obter mais informações sobre os C++ recursos mais recentes que o tempo de execução de simultaneidade usa, consulte [visão geral](../../parallel/concrt/asynchronous-message-blocks.md).

### <a name="threads-and-thread-pools"></a>Threads e pools de threads

O mecanismo de simultaneidade central na API do Windows é o thread. Normalmente, você usa a função [CreateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) para criar threads. Embora os threads sejam relativamente fáceis de criar e usar, o sistema operacional aloca uma quantidade significativa de tempo e outros recursos para gerenciá-los. Além disso, embora cada thread tenha a garantia de receber o mesmo tempo de execução que qualquer outro thread no mesmo nível de prioridade, a sobrecarga associada exige que você crie tarefas suficientemente grandes. Para tarefas menores ou mais refinadas, a sobrecarga associada à simultaneidade pode superar o benefício de executar as tarefas em paralelo.

Os pools de threads são uma maneira de reduzir o custo do gerenciamento de threads. Os pools de threads personalizados e a implementação do pool de threads fornecidos pela API do Windows permitem que pequenos itens de trabalho sejam executados de forma eficiente em paralelo. O pool de threads do Windows mantém itens de trabalho em uma fila PEPS (primeiro a entrar, primeiro a sair). Cada item de trabalho é iniciado na ordem em que foi adicionado ao pool.

O Tempo de Execução de Simultaneidade implementa um algoritmo de roubo de trabalho para estender o mecanismo de agendamento de FIFO. O algoritmo move as tarefas que ainda não foram iniciadas para os threads que ficam sem itens de trabalho. Embora o algoritmo de roubo de trabalho possa balancear cargas de trabalhos, ele também pode fazer com que os itens de trabalho sejam reordenados. Esse processo de reordenação pode fazer com que um item de trabalho inicie em uma ordem diferente da que foi enviado. Isso é útil com algoritmos recursivos, em que há uma chance melhor de que os dados sejam compartilhados entre as tarefas mais recentes do que entre os anteriores. Obter os novos itens para execução primeiro significa menos erros de cache e, possivelmente, menos falhas de página.

Da perspectiva do sistema operacional, o roubo de trabalho é injusto. No entanto, quando um aplicativo implementa um algoritmo ou uma tarefa para ser executado em paralelo, a imparcialidade entre as subtarefas nem sempre é importante. O que importa é a rapidez de conclusão da tarefa geral. Para outros algoritmos, PEPS é a estratégia de agendamento apropriada.

### <a name="behavior-on-various-operating-systems"></a>Comportamento em vários sistemas operacionais

No Windows XP e no Windows Vista, os aplicativos que usam o Tempo de Execução de Simultaneidade se comportam de forma semelhante, exceto pelo fato de que o desempenho do heap é melhorado no Windows Vista.

No Windows 7 e no Windows Server 2008 R2, o sistema operacional dá suporte adicional à simultaneidade e escalabilidade. Por exemplo, esses sistemas operacionais dão suporte a computadores que têm mais de 64 threads de hardware. Um aplicativo existente que usa a API do Windows deve ser modificado para aproveitar esses novos recursos. No entanto, um aplicativo que usa o Tempo de Execução de Simultaneidade usa esses recursos automaticamente e não requer modificações.

[base. usuário-mode_scheduling](/windows/win32/procthread/user-mode-scheduling)

[[Superior](#top)]

## <a name="openmp"></a>Comparando o Tempo de Execução de Simultaneidade ao OpenMP

O Tempo de Execução de Simultaneidade permite uma variedade de modelos de programação. Esses modelos podem sobrepor ou complementar os modelos de outras bibliotecas. Esta seção compara o Tempo de Execução de Simultaneidade com o [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp).

O modelo de programação de OpenMP é definido por um padrão aberto e tem associações bem definidas para as linguagens Fortran eC++ C/de programação. As versões de OpenMP 2,0 e 2,5 são bem adequadas para algoritmos paralelos que são iterativos; ou seja, eles executam iteração paralela em uma matriz de dados. O OpenMP é mais eficiente quando o grau de paralelismo é predeterminado e corresponde aos recursos disponíveis no sistema. O modelo de OpenMP é uma correspondência especialmente boa para computação de alto desempenho, em que problemas computacionais muito grandes são distribuídos entre os recursos de processamento de um único computador. Nesse cenário, o ambiente de hardware é conhecido e o desenvolvedor pode esperar ter acesso exclusivo aos recursos de computação quando o algoritmo é executado.

No entanto, outros ambientes de computação menos restritos podem não ser uma boa correspondência para OpenMP. Por exemplo, problemas recursivos (como o algoritmo quicksort ou a pesquisa de uma árvore de dados) são mais difíceis de implementar usando OpenMP. O Tempo de Execução de Simultaneidade complementa os recursos de OpenMP fornecendo a PPL ( [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) ) e a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md). Ao contrário do OpenMP, o Tempo de Execução de Simultaneidade fornece um Agendador dinâmico que se adapta aos recursos disponíveis e ajusta o grau de paralelismo à medida que as cargas de trabalho mudam.

Muitos dos recursos do Tempo de Execução de Simultaneidade podem ser estendidos. Você também pode combinar recursos existentes para compor novos. Como o OpenMP se baseia em diretivas de compilador, ele não pode ser estendido facilmente.

Para obter mais informações sobre como o Tempo de Execução de Simultaneidade se compara a OpenMP e como migrar o código de OpenMP existente para usar o Tempo de Execução de Simultaneidade, consulte [migrando de OpenMP para o tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md).

[[Superior](#top)]

## <a name="see-also"></a>Confira também

[Runtime de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
[Visão geral](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp)
