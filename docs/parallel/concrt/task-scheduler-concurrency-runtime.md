---
title: "Agendador de tarefas (Tempo de Execu&#231;&#227;o de Simultaneidade) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
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
  - "tarefas leves [Tempo de Execução de Simultaneidade]"
  - "excesso de assinatura [Tempo de Execução de Simultaneidade]"
  - "grupos de agendas [Tempo de Execução de Simultaneidade]"
  - "instâncias de agendador [Tempo de Execução de Simultaneidade]"
  - "políticas de agendador [Tempo de Execução de Simultaneidade]"
  - "agendador de tarefas [Tempo de Execução de Simultaneidade]"
  - "agendador de tarefas [Tempo de Execução de Simultaneidade], tarefas leves"
  - "agendador de tarefas [Tempo de Execução de Simultaneidade], excesso de assinatura"
  - "agendador de tarefas [Tempo de Execução de Simultaneidade], grupos de agendas"
  - "agendador de tarefas [Tempo de Execução de Simultaneidade], instâncias de agendador"
  - "agendador de tarefas [Tempo de Execução de Simultaneidade], políticas de agendador"
  - "agendador de tarefas [Tempo de Execução de Simultaneidade], Função wait"
  - "Função wait [Tempo de Execução de Simultaneidade]"
ms.assetid: 9aba278c-e0c9-4ede-b7c6-fedf7a365d90
caps.latest.revision: 42
caps.handback.revision: 41
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Agendador de tarefas (Tempo de Execu&#231;&#227;o de Simultaneidade)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os tópicos nesta parte da documentação descrevem os recursos importantes do Agendador de tarefas de tempo de execução de simultaneidade.  O Agendador de tarefas é útil quando você deseja ajustar o desempenho do seu código existente que usa o tempo de execução de simultaneidade.  
  
> [!IMPORTANT]
>  O Agendador de tarefas não está disponível em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo.  Para obter mais informações, consulte [Criando operações assíncronas n C\+\+ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).  
>   
>  No Visual Studio de 2015 e posterior, o [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md) classe e tipos relacionados em ppltasks usam o ThreadPool do Windows como seu Agendador.  Este tópico não se aplica a tipos que são definidos em ppltasks.  Algoritmos paralelos, como parallel\_for continuam a usar o tempo de execução de simultaneidade como o agendador padrão.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá\-lo em seu aplicativo.  Como o Agendador de tarefas Ajuda você a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver familiarizado com o tempo de execução de simultaneidade.  
  
 O Agendador de tarefas agenda e coordena as tarefas em tempo de execução.  Um *tarefa* é uma unidade de trabalho que executa um trabalho específico.  Uma tarefa normalmente pode ser executados em paralelo com outras tarefas.  O trabalho é executado por agentes assíncronos de itens do grupo de tarefas e algoritmos paralelos são exemplos de tarefas.  
  
 O Agendador de tarefas gerencia os detalhes relacionados à eficiência agendamento de tarefas em computadores que possuem vários recursos de computação.  O Agendador de tarefas também usa os recursos mais recentes do sistema operacional subjacente.  Portanto, os aplicativos que usam o tempo de execução de simultaneidade automaticamente dimensionado e melhorar no hardware que tem recursos expandidos.  
  
 [Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md) descreve as diferenças entre os mecanismos de agendamento preemptivas e cooperativas.  O Agendador de tarefas usa cooperativo de agendamento e um algoritmo de roubo de trabalho junto com o Agendador preemptivo do sistema operacional para obter a utilização máxima de recursos de processamento.  
  
 O tempo de execução de simultaneidade fornece um agendador padrão para que você não precisa gerenciar detalhes da infra\-estrutura.  Portanto, você normalmente não usar o Agendador de tarefas diretamente.  No entanto, para atender às necessidades de qualidade do seu aplicativo, você pode usar o Agendador de tarefas para fornecer seus próprio agendamento agendadores de política ou associar tarefas específicas.  Por exemplo, suponha que você tenha um paralelo classificação rotina que não ultrapassará quatro processadores.  Você pode usar *políticas de Agendador* para criar um agendador que gera mais de quatro tarefas simultâneas.  Executar a rotina de classificação neste Agendador permite que outros agendadores ativos usar quaisquer recursos de processamento restantes.  
  
## Tópicos relacionados  
  
|Título|Descrição|  
|------------|---------------|  
|[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)|Descreve instâncias de agendador e como usar o `concurrency::Scheduler` e `concurrency::CurrentScheduler` classes para gerenciá\-los.  Use instâncias de Agendador quando você deseja associar políticas de agendamento explícitas com tipos específicos de cargas de trabalho.|  
|[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)|Descreve a função de políticas de Agendador.  Use políticas de Agendador quando quiser controlar a estratégia que o Agendador usa ao gerenciar tarefas.|  
|[Grupos de agendas](../../parallel/concrt/schedule-groups.md)|Descreve a função de grupos de agendamento.  Usar grupos de programação quando você requer um alto grau de localidade entre tarefas, por exemplo, quando um grupo de tarefas relacionadas se beneficiar da execução no mesmo nó do processador.|  
|[Tarefas leves](../../parallel/concrt/lightweight-tasks.md)|Descreve a função de tarefas leves.  Tarefas leves são úteis quando você adaptar o código existente para usar a funcionalidade de agendamento de tempo de execução de simultaneidade.|  
|[Contextos](../../parallel/concrt/contexts.md)|Descreve a função dos contextos, a `concurrency::wait` função e o `concurrency::Context` classe.  Use essa funcionalidade quando você precisa ter controle sobre quando contextos bloquear, desbloquear e produzem ou quando você deseja habilitar assinaturas em excesso em seu aplicativo.|  
|[Funções de gerenciamento da memória](../Topic/Memory%20Management%20Functions.md)|Descreve o `concurrency::Alloc` e `concurrency::Free` funções.  Essas funções podem melhorar o desempenho de memória por alocar e liberar memória de forma simultânea.|  
|[Comparando com outros modelos de simultaneidade](../../parallel/concrt/comparing-the-concurrency-runtime-to-other-concurrency-models.md)|Descreve as diferenças entre os mecanismos de agendamento preemptivas e cooperativas.|  
|[Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve como usar vários padrões paralelos, por exemplo, os algoritmos paralelos, em seus aplicativos.|  
|[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)|Descreve como usar agentes assíncronos em seus aplicativos.|  
|[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)|Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.|