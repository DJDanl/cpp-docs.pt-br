---
title: "Biblioteca de agentes assíncronos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Agents Library
- Asynchronous Agents Library
ms.assetid: d2a72a31-8ba6-4220-ad7a-e403a6acaa42
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: be12f47a6fb33350137a8f9b1c78ff75519c8af7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="asynchronous-agents-library"></a>Biblioteca de Agentes Assíncronos
A biblioteca de agentes assíncrona (ou apenas *biblioteca de agentes*) fornece um modelo de programação que lhe permite aumentar a robustez de desenvolvimento de aplicativos habilitados para simultaneidade. A biblioteca de agentes é uma biblioteca de modelos do C++ que promova a um modelo de programação baseado em ator e a mensagem no processo passando para o fluxo de dados de alta granularidade e pipeline de tarefas. A biblioteca de agentes foi criado com os componentes de gerenciamento de recursos e agendamento de tempo de execução de simultaneidade.  
  
## <a name="programming-model"></a>Modelo de Programação  
 A biblioteca de agentes fornece alternativas para estado compartilhado, permitindo que você se conectar componentes isolados por meio de um modelo de comunicação assíncrona com base no fluxo de dados em vez de fluxo de controle. *Fluxo de dados* refere-se a uma programação em que os cálculos são feitos quando todos os dados necessários de modelo está disponível. *fluxo de controle* refere-se a um modelo de programação em que os cálculos são feitos em uma ordem predeterminada.  
  
 O modelo de programação de fluxo de dados está relacionado ao conceito de *transmissão de mensagens*, em que componentes independentes de um programa se comunicam uns com os outros pelo envio de mensagens.  
  
 A biblioteca de agentes é composta de três componentes: *agentes assíncronos*, *blocos de mensagens assíncronos*, e *funções de transmissão de mensagens*. Agentes de mantém o estado e usam funções de transmissão de mensagens e blocos de mensagens para se comunicar entre si e com componentes externos. Funções de transmissão de mensagens permitem que agentes para enviar e receber mensagens e para os componentes externos. Blocos de mensagens assíncronos manter as mensagens e habilitar os agentes para se comunicar de forma sincronizada.  
  
 A ilustração a seguir mostra como dois agentes de blocos de mensagem de uso e funções de transmissão de mensagens para se comunicar. Nesta ilustração, `agent1` envia uma mensagem para `agent2` usando o [concurrency::send](reference/concurrency-namespace-functions.md#send) função e uma [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) objeto. `agent2`usa o [concurrency::receive](reference/concurrency-namespace-functions.md#receive) função ler a mensagem. `agent2`usa o mesmo método para enviar uma mensagem para `agent1`. Setas tracejadas representam o fluxo de dados entre os agentes. Setas sólidas conecte-se os agentes nos blocos de mensagens que eles gravam ou leem.  
  
 ![Os componentes da biblioteca de agentes](../../parallel/concrt/media/agent_librarycomp.png "agent_librarycomp")  
  
 Um exemplo de código que implementa esta ilustração é mostrado posteriormente neste tópico.  
  
 O modelo de programação do agente tem várias vantagens em relação a outros mecanismos de simultaneidade e sincronização, por exemplo, os eventos. Uma vantagem é usando a passagem de mensagem de transmitir as alterações de estado entre objetos, você pode isolar o acesso a recursos compartilhados e, assim, melhorar a escalabilidade. Uma vantagem de transmissão de mensagens é que ele está associado a sincronização de dados em vez de ligá-lo a um objeto de sincronização externo. Isso simplifica a transmissão de dados entre os componentes e pode eliminar erros de programação em seus aplicativos.  
  
## <a name="when-to-use-the-agents-library"></a>Quando Usar a Biblioteca de Agentes  
 Use a biblioteca de agentes, quando você tem várias operações que precisam se comunicar uns com os outros assincronamente. Blocos de mensagens e funções de transmissão de mensagens permitem a você escrever aplicativos paralelos sem a necessidade de mecanismos de sincronização, como bloqueios. Isso permite que você se concentre na lógica do aplicativo.  
  
 O modelo de programação do agente geralmente é usado para criar *pipelines de dados* ou *redes*. Um pipeline de dados é uma série de componentes, cada uma delas executa uma tarefa específica que contribui para um objetivo maior. Cada componente em um pipeline de fluxo de dados executa o trabalho quando ele recebe uma mensagem de outro componente. O resultado desse trabalho é passado para outros componentes no pipeline ou rede. Os componentes podem usar mais funcionalidades de simultaneidade refinada de outras bibliotecas, por exemplo, o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir implementa a ilustração mostrada anteriormente neste tópico.  
  
 [!code-cpp[concrt-basic-agents#1](../../parallel/concrt/codesnippet/cpp/asynchronous-agents-library_1.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
agent1: sending request...  
agent2: received 'request'.  
agent2: sending response...  
agent1: received '42'.  
```  
  
 Os tópicos a seguir descrevem a funcionalidade usada neste exemplo.  
  
## <a name="related-topics"></a>Tópicos relacionados  
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
 Descreve a função de agentes assíncronos para a solução mais tarefas de computação.  
  
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
 Descreve os vários tipos de bloco de mensagens que são fornecidos pela biblioteca de agentes.  
  
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)  
 Descreve as rotinas de passando várias mensagens que são fornecidas pela biblioteca de agentes.  
  
 [Como implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)  
 Descreve como implementar o padrão de produtor-consumidor em seu aplicativo.  
  
 [Como fornecer funções de trabalho para as classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)  
 Ilustra várias maneiras de fornecer funções de trabalho para o [concurrency::call](../../parallel/concrt/reference/call-class.md) e [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) classes.  
  
 [Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)  
 Mostra como usar o [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) classe em um pipeline de dados.  
  
 [Como selecionar entre tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)  
 Mostra como usar o [concurrency::choice](../../parallel/concrt/reference/choice-class.md) e [concurrency::join](../../parallel/concrt/reference/join-class.md) classes para selecionar a primeira tarefa para concluir um algoritmo de pesquisa.  
  
 [Como enviar uma mensagem a um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)  
 Mostra como usar o [concurrency::timer](../../parallel/concrt/reference/timer-class.md) classe para enviar uma mensagem em intervalos regulares.  
  
 [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)  
 Demonstra como usar um filtro para habilitar um bloco de mensagens assíncronas aceitar ou rejeitar as mensagens.  
  
 [PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)  
 Descreve como usar vários padrões paralelos, como os algoritmos paralelos, em seus aplicativos.  
  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)  
 Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.

