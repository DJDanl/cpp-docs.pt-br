---
title: "Comparando o Tempo de Execu&#231;&#227;o de Simultaneidade com outros modelos de simultaneidade | Microsoft Docs"
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
  - "Tempo de execução de simultaneidade, em comparação comparado outros modelos"
ms.assetid: d8b9a1f4-f15f-43c3-a5b4-c0991edf9c86
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Comparando o Tempo de Execu&#231;&#227;o de Simultaneidade com outros modelos de simultaneidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve as diferenças entre os recursos e modelos de programação de tempo de execução de simultaneidade e outras tecnologias. Compreendendo como as vantagens do Runtime de simultaneidade se comparam aos benefícios de outros modelos de programação, você pode selecionar a tecnologia que melhor atenda aos requisitos de seus aplicativos.  
  
 Se você estiver usando outro modelo de programação, como o pool de threads do Windows ou o OpenMP, há situações em que pode ser apropriado migrar para o tempo de execução de simultaneidade. Por exemplo, o tópico [Migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md) descreve quando pode ser adequado migrar de OpenMP no tempo de execução de simultaneidade. No entanto, se você estiver satisfeito com o desempenho do aplicativo e suporte de depuração atual, migração não é necessária.  
  
 Você pode usar os recursos e benefícios de produtividade do tempo de execução de simultaneidade para complementar seu aplicativo existente que usa outro modelo de simultaneidade. O tempo de execução de simultaneidade não garante o balanceamento de carga quando vários agendadores de tarefas disputam os mesmos recursos de computação. No entanto, quando as cargas de trabalho não se sobrepõem, esse efeito é mínimo.  
  
##  <a name="a-nametopa-sections"></a><a name="top"></a> Seções  
  
-   [Comparando o agendamento preventivo para agendamento cooperativo](#models)  
  
-   [Comparando o tempo de execução de simultaneidade para a API do Windows](#winapi)  
  
-   [Comparando o tempo de execução de simultaneidade para OpenMP](#openmp)  
  
##  <a name="a-namemodelsa-comparing-preemptive-scheduling-to-cooperative-scheduling"></a><a name="models"></a> Comparando o agendamento preventivo para agendamento cooperativo  
 O modelo preemptivo e cooperativo agendamento modelos são duas maneiras de habilitar várias tarefas compartilhar recursos de computação, por exemplo, processadores ou segmentos de hardware.  
  
### <a name="preemptive-and-cooperative-scheduling"></a>Agendamento preemptivo e cooperativo  
 *Agendamento preemptivo* é um mecanismo de rodízio, baseado em prioridade que fornece cada acesso exclusivo da tarefa para um recurso de computação para um determinado período de tempo e, em seguida, alterna para outra tarefa. Agendamento preemptivo é comum em sistemas operacionais de multitarefa, como Windows*. Agendando cooperativo* é um mecanismo que fornece cada acesso exclusivo da tarefa a um recurso de computação até que a tarefa seja concluída ou até que a tarefa gera seu acesso ao recurso. O tempo de execução de simultaneidade usa agendamento cooperativo junto com o Agendador preemptivo do sistema operacional para obter a utilização máxima dos recursos de processamento.  
  
### <a name="differences-between-preemptive-and-cooperative-schedulers"></a>Diferenças entre os agendadores Preemptivas e cooperativos  
 Buscam de agendadores PreEmptive fornecer vários threads acesso igual a recursos para garantir que cada thread progride de computação. Em computadores que têm muitos recursos de computação, garantindo o acesso razoável se torna menos problemático; No entanto, garantindo a utilização eficiente dos recursos se torna mais problemático.  
  
 Um agendador de modo de kernel preemptivo requer o código do aplicativo depender do sistema operacional para tomar decisões de planejamento. Por outro lado, um agendador cooperativo de modo de usuário permite que o código do aplicativo fazer sua próprias decisões de programação. Como agendar cooperativo permite muitas decisões de planejamento a serem feitas pelo aplicativo, reduz muito a sobrecarga associada com sincronização de modo kernel. Um agendador cooperativo adia geralmente decisões de programação ao kernel do sistema operacional quando nenhum outro trabalho para agendar. Um agendador cooperativo também passa para o programador do sistema operacional, quando há uma operação de bloqueio que é comunicada do kernel, mas que a operação não é comunicada ao Agendador do modo de usuário.  
  
### <a name="cooperative-scheduling-and-efficiency"></a>Agendamento cooperativo e eficiência  
 Para um programador preemptivo, todo o trabalho que tem o mesmo nível de prioridade é igual. Um agendador preemptivo normalmente agenda threads na ordem em que eles são criados. Além disso, um agendador preemptivo fornece todos os threads um intervalo de tempo de uma forma de rodízio, com base na prioridade de thread. Embora esse mecanismo fornece integridade (cada thread faz progresso), ele tem algum custo de eficiência. Por exemplo, muitos algoritmos de computação intensiva não exigem imparcialidade. Em vez disso, é importante que as tarefas relacionadas terminar no tempo menos geral. Agendando cooperativo permite que um aplicativo agendar o trabalho com mais eficiência. Por exemplo, considere um aplicativo que tenha vários threads. Agendamento de threads que não compartilham os recursos a serem executados simultaneamente pode reduzir a sobrecarga de sincronização e, assim, aumentar a eficiência. Outra maneira eficiente de agendar tarefas é executar pipelines de tarefas (onde cada tarefa atua na saída do anterior) no mesmo processador para que a entrada de cada estágio de pipeline já foi carregada no cache de memória.  
  
### <a name="using-preemptive-and-cooperative-scheduling-together"></a>Usar agendamento preemptivo e cooperativo juntos  
 Agendando cooperativo não resolve todos os problemas de agendamento. Por exemplo, tarefas que não geram bastante a outras tarefas podem consumir todos os recursos de computação disponíveis e impedir que outras tarefas progredindo. O tempo de execução de simultaneidade usa os benefícios de eficiência de programação cooperativo para complementar as garantias de imparcialidade de agendamento preemptivo. Por padrão, o tempo de execução de simultaneidade fornece um agendador cooperativo que usa um algoritmo de roubo de trabalho para distribuir o trabalho entre os recursos de computação de forma eficiente. No entanto, o Agendador de tempo de execução de simultaneidade também se baseia no Agendador do sistema operacional preemptivo bastante distribua recursos entre aplicativos. Você também pode criar políticas de agendador e agendadores personalizados em seus aplicativos para produzir um controle refinado sobre a execução do thread.  
  
 [[Top](#top)]  
  
##  <a name="a-namewinapia-comparing-the-concurrency-runtime-to-the-windows-api"></a><a name="winapi"></a> Comparando o tempo de execução de simultaneidade para a API do Windows  
 Interface de programação de aplicativo Microsoft Windows, que é normalmente conhecido como a API do Windows (e anteriormente conhecido como Win32), fornece um modelo de programação que permite a simultaneidade em seus aplicativos. O tempo de execução de simultaneidade se baseia na API do Windows para fornecer modelos de programação adicionais que não estão disponíveis no sistema operacional subjacente.  
  
 O tempo de execução de simultaneidade se baseia no modelo de thread de API do Windows para executar o trabalho paralelo. Ele também usa o gerenciamento de memória de API do Windows e mecanismos de armazenamento local de thread. No Windows 7 e Windows Server 2008 R2, ele usa o suporte à API do Windows para computadores que têm mais de 64 threads de hardware e usuário agendáveis threads. O tempo de execução de simultaneidade estende o modelo de API do Windows, fornecendo um agendador de tarefas cooperativo e um algoritmo de roubo de trabalho para maximizar o uso de recursos de computação e permitindo que várias instâncias simultâneas do Agendador.  
   
### <a name="programming-languages"></a>Linguagens de programação  
 A API do Windows usa a linguagem de programação C para expor o modelo de programação. O tempo de execução de simultaneidade fornece uma interface de programação do C++ que aproveita os recursos mais recentes na linguagem C++. Por exemplo, funções lambda fornecem um mecanismo sucinto, fortemente tipadas para definir funções de trabalho paralelas. Para obter mais informações sobre os recursos mais recentes do C++ que usa o tempo de execução de simultaneidade, consulte [Visão geral](../../parallel/concrt/asynchronous-message-blocks.md).  
  
### <a name="threads-and-thread-pools"></a>Threads e Pools de threads  
 O mecanismo de simultaneidade central na API do Windows é o thread. Você normalmente usa o [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) função criar threads. Embora os threads são relativamente fáceis de criar e usar, o sistema operacional aloca uma quantidade significativa de tempo e outros recursos para gerenciá-los. Além disso, embora cada thread garante a receber o mesmo tempo de execução como qualquer outro segmento no mesmo nível de prioridade, associado sobrecarga requer que você crie tarefas suficientemente grandes. As tarefas menores ou mais refinada, a sobrecarga associada a simultaneidade pode superar o benefício de executar as tarefas em paralelo.  
  
 Pools de threads são uma maneira de reduzir o custo de gerenciamento de threads. Pools de threads personalizado e a implementação de pool de thread é fornecida pela API do Windows, as duas habilitam a itens de trabalho pequenos para serem executados com eficiência em paralelo. O pool de threads do Windows mantém os itens de trabalho em uma fila primeiro a entrar, primeiro a sair (PEPS). Cada item de trabalho é iniciado na ordem em que foi adicionado ao pool.  
  
 O tempo de execução de simultaneidade implementa um algoritmo de roubo de trabalho para estender o FIFO mecanismo de agendamento. O algoritmo move tarefas que ainda não iniciaram a threads sem itens de trabalho. Embora o algoritmo de roubo de trabalho pode balancear cargas de trabalho, ele também pode causar itens de trabalho a ser reordenadas. Esse processo reordenação pode causar um item de trabalho Iniciar em uma ordem diferente do que foi enviado. Isso é útil com algoritmos recursivos, onde há uma melhor chance de que os dados são compartilhados entre tarefas mais recentes do que entre os mais antigos. Obter os novos itens para ser executado primeiro significa menos erros de cache e possivelmente menos falhas de página.  
  
 Da perspectiva do sistema operacional, é justo roubo de trabalho. No entanto, quando um aplicativo implementa um algoritmo ou a tarefa seja executada em paralelo, honestidade entre as subtarefas não é sempre importante. O que é importante é como rapidamente a tarefa termina. Para outros algoritmos FIFO é a estratégia apropriada de agendamento.  
  
### <a name="behavior-on-various-operating-systems"></a>Comportamento em vários sistemas operacionais  
 No Windows XP e Windows Vista, os aplicativos que usam o tempo de execução de simultaneidade se comportam da mesma forma, exceto que o desempenho de heap é aprimorado no Windows Vista.  
  
 No Windows 7 e Windows Server 2008 R2, o sistema operacional ainda mais dá suporte a simultaneidade e a escalabilidade. Por exemplo, esses sistemas operacionais oferecer suporte a computadores que têm mais de 64 threads de hardware. Um aplicativo existente que usa a API do Windows deve ser modificado para tirar proveito desses novos recursos. No entanto, um aplicativo que usa o tempo de execução de simultaneidade automaticamente usa esses recursos e não exigem modificações.  
  
 [base.User mode_scheduling](http://msdn.microsoft.com/library/windows/desktop/dd627187)  
  
 [[Top](#top)]  
  
##  <a name="a-nameopenmpa-comparing-the-concurrency-runtime-to-openmp"></a><a name="openmp"></a> Comparando o tempo de execução de simultaneidade para OpenMP  
 O tempo de execução de simultaneidade permite uma variedade de modelos de programação. Esses modelos podem se sobrepor ou complementam os modelos de outras bibliotecas. Esta seção compara o tempo de execução de simultaneidade para [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp_in_visual_c_add_add).  
  
 O modelo de programação OpenMP é definido por um padrão aberto e tem associações bem definidas para as linguagens de programação Fortran e C/C++. OpenMP versões 2.0 e 2.5 são adequadas para algoritmos paralelos são iterativos; ou seja, eles executam iteração paralela em uma matriz de dados. O OpenMP é mais eficiente quando o grau de paralelismo é predeterminado e corresponde os recursos disponíveis no sistema. O modelo de OpenMP é uma correspondência especialmente bons para computação de alto desempenho, onde muito grandes problemas computacionais são distribuídos entre os recursos de processamento de um único computador. Nesse cenário, o ambiente de hardware é conhecido e o desenvolvedor pode esperar ter acesso exclusivo aos recursos de computação quando o algoritmo é executado.  
  
 No entanto, outras, menos restrito ambientes de computação pode não ser uma boa correspondência para OpenMP. Por exemplo, problemas de recursiva (como o algoritmo quicksort ou pesquisar uma árvore de dados) são mais difíceis de implementar usando OpenMP. O tempo de execução de simultaneidade complementa os recursos do OpenMP fornecendo o [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL) e o [Asynchronous Agents Library](../../parallel/concrt/asynchronous-agents-library.md). Ao contrário de OpenMP, o tempo de execução de simultaneidade fornece um programador dinâmico que se adapta aos recursos disponíveis e ajusta o grau de paralelismo como alterar as cargas de trabalho.  
  
 Muitos dos recursos em tempo de execução de simultaneidade podem ser estendidos. Você também pode combinar recursos existentes para compor novas. Como OpenMP depende de diretivas de compilador, ele não pode ser estendido facilmente.  
  
 Para obter mais informações sobre como compara o tempo de execução de simultaneidade OpenMP e como migrar código OpenMP existente para usar o tempo de execução de simultaneidade, consulte [Migrando de OpenMP no tempo de execução de simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md).  
  
 [[Top](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime.md)     
 [Visão geral](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)   
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [OpenMP](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md#openmp_in_visual_c_add_add)
