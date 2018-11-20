---
title: Biblioteca de Agentes Assíncronos
ms.date: 11/19/2018
helpviewer_keywords:
- Agents Library
- Asynchronous Agents Library
ms.assetid: d2a72a31-8ba6-4220-ad7a-e403a6acaa42
ms.openlocfilehash: 8b4e8e6489e98aadb6ea41d32d5a9ba14efe2668
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52175854"
---
# <a name="asynchronous-agents-library"></a>Biblioteca de Agentes Assíncronos

A biblioteca de agentes assíncronos (ou simplesmente *biblioteca de agentes*) fornece um modelo de programação que lhe permite aumentar a robustez do desenvolvimento de aplicativos habilitados para simultaneidade. A biblioteca de agentes é uma biblioteca de modelos de C++ que promova a um modelo de programação baseado em ator e a mensagem no processo, passando para o fluxo de dados de alta granularidade e pipelining de tarefas. A biblioteca de agentes baseia-se os componentes de gerenciamento de recursos e agendamento de tempo de execução de simultaneidade.

## <a name="programming-model"></a>Modelo de Programação

A biblioteca de agentes fornece alternativas para estado compartilhado, permitindo que você se conectar componentes isolados por meio de um modelo de comunicação assíncrona baseada em fluxo de dados, em vez de fluxo de controle. *Fluxo de dados* refere-se para uma programação em que os cálculos são feitos quando todos os dados necessários do modelo está disponível. *fluxo de controle* refere-se a um modelo de programação em que os cálculos são feitos em uma ordem predeterminada.

O modelo de programação de fluxo de dados está relacionado ao conceito de *transmissão de mensagens*, em que componentes independentes de um programa se comunicam uns com os outros pelo envio de mensagens.

A biblioteca de agentes é composta de três componentes: *agentes assíncronos*, *blocos de mensagens assíncronos*, e *funções de transmissão de mensagens*. Agentes de mantenham o estado e usarem blocos de mensagem e funções de transmissão de mensagens para se comunicar entre si e com componentes externos. Funções de transmissão de mensagens permitem que os agentes enviar e receber mensagens e para os componentes externos. Blocos de mensagens assíncronos manter as mensagens e habilitar os agentes se comuniquem de forma sincronizada.

A ilustração a seguir mostra como dois agentes uso blocos de mensagem e funções de transmissão de mensagens para se comunicar. Nesta ilustração `agent1` envia uma mensagem à `agent2` usando o [Concurrency:: Send](reference/concurrency-namespace-functions.md#send) função e um [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) objeto. `agent2` usa o [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) função para ler a mensagem. `agent2` usa o mesmo método para enviar uma mensagem para `agent1`. Setas tracejadas representam o fluxo de dados entre os agentes. As setas sólidas conectam os agentes para os blocos de mensagem que eles gravar ou leiam.

![Os componentes da biblioteca de agentes](../../parallel/concrt/media/agent_librarycomp.png "os componentes da biblioteca de agentes")

Um exemplo de código que implementa esta ilustração é mostrado posteriormente neste tópico.

O modelo de programação do agente tem várias vantagens sobre outros mecanismos de sincronização e simultaneidade, por exemplo, eventos. Uma vantagem é que, usando a passagem de mensagem para transmitir as alterações de estado entre objetos, você pode isolar o acesso a recursos compartilhados e, assim, melhorar a escalabilidade. Uma vantagem de transmissão de mensagens é que ele liga a sincronização de dados, em vez de ligá-la a um objeto de sincronização externo. Isso simplifica a transmissão de dados entre os componentes e pode eliminar erros de programação em seus aplicativos.

## <a name="when-to-use-the-agents-library"></a>Quando Usar a Biblioteca de Agentes

Use a biblioteca de agentes quando você tem várias operações que devem se comunicar com uma outra forma assíncrona. Blocos de mensagens e funções de transmissão de mensagens permitem escrever aplicativos paralelos sem a necessidade de mecanismos de sincronização, como bloqueios. Isso permite que você se concentre na lógica do aplicativo.

O modelo de programação do agente geralmente é usado para criar *pipelines de dados* ou *redes*. Um pipeline de dados é uma série de componentes, cada uma delas executa uma tarefa específica que contribui para um objetivo maior. Todos os componentes em um pipeline de fluxo de dados executa o trabalho quando ele recebe uma mensagem de outro componente. O resultado desse trabalho é passado para outros componentes no pipeline ou rede. Os componentes podem usar mais funcionalidade de simultaneidade refinada de outras bibliotecas, por exemplo, o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).

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

[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br/>
Descreve a função de agentes assíncronos para resolver tarefas de computação maiores.

[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
Descreve os vários tipos de bloco de mensagem que são fornecidos pela biblioteca de agentes.

[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
Descreve as várias rotinas de passagem de mensagem que são fornecidas pela biblioteca de agentes.

[Como implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md)<br/>
Descreve como implementar o padrão de produtor-consumidor em seu aplicativo.

[Como fornecer funções de trabalho para as classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md)<br/>
Ilustra as várias maneiras de fornecer funções de trabalho para o [concurrency::call](../../parallel/concrt/reference/call-class.md) e [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) classes.

[Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)<br/>
Mostra como usar o [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) classe em um pipeline de dados.

[Como selecionar entre tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md)<br/>
Mostra como usar o [concurrency::choice](../../parallel/concrt/reference/choice-class.md) e [concurrency::join](../../parallel/concrt/reference/join-class.md) classes para selecionar a primeira tarefa para concluir um algoritmo de pesquisa.

[Como enviar uma mensagem a um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md)<br/>
Mostra como usar o [concurrency::timer](../../parallel/concrt/reference/timer-class.md) classe para enviar uma mensagem em intervalos regulares.

[Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)<br/>
Demonstra como usar um filtro para habilitar um bloco de mensagem assíncrona aceitar ou rejeitar as mensagens.

[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
Descreve como usar vários padrões paralelos, como algoritmos paralelos, em seus aplicativos.

[Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.

