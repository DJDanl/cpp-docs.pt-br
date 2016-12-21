---
title: "Biblioteca de Agentes Ass&#237;ncronos | Microsoft Docs"
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
  - "Biblioteca de Agentes"
  - "Biblioteca de Agentes Assíncronos"
ms.assetid: d2a72a31-8ba6-4220-ad7a-e403a6acaa42
caps.latest.revision: 33
caps.handback.revision: 33
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Biblioteca de Agentes Ass&#237;ncronos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Biblioteca de agentes assíncronos (ou apenas *biblioteca de agentes*) fornece um modelo de programação que permite que você aumente a eficiência do desenvolvimento de aplicativos habilitados para simultaneidade. A biblioteca de agentes é uma biblioteca de modelos C++ que promova a um modelo de programação baseada em ator e mensagens em processo passando para o fluxo de dados de alta granularidade e processamento de tarefas. A biblioteca de agentes amplia os componentes de gerenciamento de recursos e agendamento do tempo de execução de simultaneidade.  
  
## <a name="programming-model"></a>Modelo de Programação  
 A biblioteca de agentes fornece alternativas para o estado compartilhado, permitindo que você se conectar componentes isolados por meio de um modelo de comunicação assíncrona com base no fluxo de dados em vez de fluxo de controle. *Fluxo de dados* refere-se a programação em que os cálculos são feitos quando todos os dados necessários do modelo está disponível; *fluxo de controle* refere-se a um modelo de programação em que os cálculos são feitos em uma ordem predeterminada.  
  
 O modelo de programação de fluxo de dados está relacionado ao conceito de *mensagem passando*, onde componentes independentes de um programa se comunicar uns com os outros enviando mensagens.  
  
 A biblioteca de agentes é composta de três componentes: *agentes assíncronos*, *blocos de mensagens assíncronos*, e *funções de transmissão de mensagens*. Agentes de mantém o estado e usam blocos de mensagens e funções de transmissão de mensagens para se comunicar entre si e com componentes externos. Funções de transmissão de mensagens permitem que agentes para enviar e receber mensagens de e para os componentes externos. Blocos de mensagens assíncronos mantêm as mensagens e habilitar os agentes para se comunicar de forma sincronizada.  
  
 A ilustração a seguir mostra como dois agentes de blocos de mensagens de uso e funções de transmissão de mensagens para se comunicar. Nesta ilustração, `agent1` envia uma mensagem para `agent2` usando o [concurrency::send](../Topic/send%20Function.md) função e uma [concurrency::unbounded_buffer](../Topic/unbounded_buffer%20Class.md) objeto. `agent2` usa o [concurrency::receive](../Topic/receive%20Function.md) função para ler a mensagem. `agent2` usa o mesmo método para enviar uma mensagem para `agent1`. Setas tracejadas representam o fluxo de dados entre os agentes. As setas sólidas conectam os agentes para os blocos de mensagem que gravar ou ler.  
  
 ![Os componentes da biblioteca de agentes](../../parallel/concrt/media/agent_librarycomp.png "Agent_LibraryComp")  
  
 Um exemplo de código que implementa esta ilustração é mostrado posteriormente neste tópico.  
  
 O modelo de programação do agente tem várias vantagens sobre outros mecanismos de simultaneidade e sincronização, por exemplo, eventos. Uma vantagem é que usando a passagem de mensagens para transmitir as alterações de estado entre objetos, você pode isolar o acesso a recursos compartilhados e, assim, melhorar a escalabilidade. Uma vantagem para transmissão de mensagens é que ela vincula a sincronização de dados em vez de ligá-lo a um objeto de sincronização externa. Isso simplifica a transmissão de dados entre componentes e pode eliminar erros de programação em seus aplicativos.  
  
## <a name="when-to-use-the-agents-library"></a>Quando Usar a Biblioteca de Agentes  
 Use a biblioteca de agentes quando você tem várias operações devem se comunicar uns com os outros assincronamente. Funções de transmissão de mensagens e blocos de mensagens permitem escrever aplicativos paralelos sem a necessidade de mecanismos de sincronização, como bloqueios. Isso permite que você se concentre na lógica do aplicativo.  
  
 O modelo de programação do agente é frequentemente usado para criar *pipelines de dados* ou *redes*. Um pipeline de dados é uma série de componentes, cada uma das quais executa uma tarefa específica que contribui para um objetivo maior. Cada componente em um pipeline de fluxo de dados executa o trabalho quando ele recebe uma mensagem de outro componente. O resultado desse trabalho é passado para outros componentes no pipeline ou rede. Os componentes podem usar mais funcionalidade de simultaneidade refinada de outras bibliotecas, por exemplo, o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir implementa a ilustração mostrada anteriormente neste tópico.  
  
 [!code-cpp[concrt-basic-agents#1](../../parallel/concrt/codesnippet/CPP/asynchronous-agents-library_1.cpp)]  
  
 Este exemplo produz a seguinte saída:  
  
```Output  
agent1: sending request...  
agent2: received 'request'.  
agent2: sending response...  
agent1: received '42'.  
```  
  
 Os tópicos a seguir descrevem a funcionalidade usada neste exemplo.  
  
## <a name="related-topics"></a>Tópicos relacionados  
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
 Descreve a função dos agentes assíncronos para solucionar tarefas maiores de computação.  
  
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
 Descreve os vários tipos de bloco de mensagens que são fornecidos pela biblioteca de agentes.  
  
 [Funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md)  
 Descreve as rotinas de passar várias mensagem fornecidos pela biblioteca de agentes.  
  
 [Como: implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)  
 Descreve como implementar o padrão de produtor-consumidor em seu aplicativo.  
  
 [Como: fornecer funções de trabalho para as Classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)  
 Ilustra várias maneiras de fornecer funções de trabalho para o [concurrency::call](../../parallel/concrt/reference/call-class.md) e [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) classes.  
  
 [Como: usar transformador em um Pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)  
 Mostra como usar o [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) classe em um pipeline de dados.  
  
 [Como: selecionar tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)  
 Mostra como usar o [concurrency::choice](../../parallel/concrt/reference/choice-class.md) e [concurrency::join](../Topic/join%20Class.md) classes para selecionar a primeira tarefa para concluir um algoritmo de pesquisa.  
  
 [Como: enviar uma mensagem em um intervalo Regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)  
 Mostra como usar o [concurrency::timer](../../parallel/concrt/reference/timer-class.md) para enviar uma mensagem em intervalos regulares.  
  
 [Como: usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)  
 Demonstra como usar um filtro para habilitar um bloco de mensagens assíncronas aceitar ou rejeitar as mensagens.  
  
 [Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)  
 Descreve como usar vários padrões paralelos, como algoritmos paralelos, em seus aplicativos.  
  
 [Tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime.md)  
 Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.

