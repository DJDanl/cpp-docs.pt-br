---
title: 'Instruções passo a passo: usando join para Evitar Deadlock'
ms.date: 04/25/2019
helpviewer_keywords:
- preventing deadlock with joins [Concurrency Runtime]
- deadlock, preventing [Concurrency Runtime]
- non-greedy joins, example
- join class, example
ms.assetid: d791f697-bb93-463e-84bd-5df1651b7446
ms.openlocfilehash: 4df83e944552fd6c0d2482efa72883d87cd45f8c
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140651"
---
# <a name="walkthrough-using-join-to-prevent-deadlock"></a>Instruções passo a passo: usando join para Evitar Deadlock

Este tópico usa o problema do jantar filósofos para ilustrar como usar a classe [Concurrency:: join](../../parallel/concrt/reference/join-class.md) para evitar o deadlock em seu aplicativo. Em um aplicativo de software, o *deadlock* ocorre quando cada um dos dois ou mais processos mantiver um recurso e mutuamente aguardar até que outro processo libere algum outro recurso.

O problema do jantar filósofos é um exemplo específico do conjunto geral de problemas que podem ocorrer quando um conjunto de recursos é compartilhado entre vários processos simultâneos.

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

Leia os tópicos a seguir antes de iniciar este passo a passos:

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

- [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)

## <a name="top"></a>As

Este passo a passo contém as seguintes seções:

- [O problema do jantar filósofos](#problem)

- [Uma implementação ingênua](#deadlock)

- [Usando Join para evitar deadlock](#solution)

## <a name="problem"></a>O problema do jantar filósofos

O problema do jantar filósofos ilustra como o deadlock ocorre em um aplicativo. Nesse problema, cinco filósofos ficam em uma tabela redonda. Cada filósofo alterna entre o pensamento e o comer. Cada filósofo deve compartilhar um Chopstick com o vizinho à esquerda e outro Chopstick com o vizinho à direita. A ilustração a seguir mostra esse layout.

![O problema do jantar filósofos](../../parallel/concrt/media/dining_philosophersproblem.png "O Problema do Jantar dos Filósofos")

Para comer, um filósofo deve conter duas chopsticks. Se todos os filósofos contiverem apenas um chopstick e estiver esperando por outro, nenhum filósofo poderá comer e todos os demais.

[[Superior](#top)]

## <a name="deadlock"></a>Uma implementação ingênua

O exemplo a seguir mostra uma implementação ingênua do problema do jantar filósofos. A classe `philosopher`, que deriva de [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md), permite que cada filósofo atue de forma independente. O exemplo usa uma matriz compartilhada de objetos [Concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md) para fornecer a cada objeto `philosopher` acesso exclusivo a um par de Chopsticks.

Para relacionar a implementação à ilustração, a classe `philosopher` representa um filósofo. Uma variável `int` representa cada Chopstick. Os objetos `critical_section` servem como contentores nos quais o chopsticks REST. O método `run` simula a vida útil do filósofo. O método `think` simula o ato de pensar e o método `eat` simula o ato de comer.

Um objeto `philosopher` bloqueia `critical_section` objetos para simular a remoção do chopsticks dos detentores antes de chamar o método `eat`. Após a chamada para `eat`, o objeto `philosopher` retorna o chopsticks para os detentores definindo os objetos `critical_section` de volta para o estado desbloqueado.

O método `pickup_chopsticks` ilustra onde o deadlock pode ocorrer. Se cada objeto de `philosopher` obtém acesso a um dos bloqueios, nenhum objeto de `philosopher` pode continuar porque o outro bloqueio é controlado por outro objeto de `philosopher`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[concrt-philosophers-deadlock#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_1.cpp)]

### <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `philosophers-deadlock.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Philosophers-deadlock. cpp**

[[Superior](#top)]

## <a name="solution"></a>Usando Join para evitar deadlock

Esta seção mostra como usar buffers de mensagens e funções de passagem de mensagens para eliminar a chance de deadlock.

Para relacionar este exemplo ao anterior, a classe `philosopher` substitui cada objeto `critical_section` por meio de um objeto [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) e um objeto `join`. O objeto `join` serve como um arbitrador que fornece o chopsticks para o filósofo.

Este exemplo usa a classe `unbounded_buffer` porque quando um destino recebe uma mensagem de um objeto `unbounded_buffer`, a mensagem é removida da fila de mensagens. Isso permite que um objeto `unbounded_buffer` que contém uma mensagem para indicar que o chopstick está disponível. Um objeto `unbounded_buffer` que não contém nenhuma mensagem indica que o chopstick está sendo usado.

Este exemplo usa um objeto de `join` não-ávido porque uma junção não-alta fornece acesso a cada objeto `philosopher` para ambos os chopsticks somente quando ambos os objetos `unbounded_buffer` contêm uma mensagem. Uma junção de disponibilidade não impediria o deadlock porque uma junção de ávidos aceita mensagens assim que elas ficam disponíveis. O deadlock pode ocorrer se todas as `join` objetos receberem uma das mensagens, mas aguardar para que o outro fique disponível.

Para obter mais informações sobre junções de ávido e não-alto e as diferenças entre os vários tipos de buffer de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

### <a name="to-prevent-deadlock-in-this-example"></a>Para evitar deadlock neste exemplo

1. Remova o código a seguir do exemplo.

[!code-cpp[concrt-philosophers-deadlock#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_2.cpp)]

1. Altere o tipo do `_left` e `_right` membros de dados da classe `philosopher` para `unbounded_buffer`.

[!code-cpp[concrt-philosophers-join#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_3.cpp)]

1. Modifique o Construtor `philosopher` para tirar `unbounded_buffer` objetos como seus parâmetros.

[!code-cpp[concrt-philosophers-join#3](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_4.cpp)]

1. Modifique o método de `pickup_chopsticks` para usar um objeto de `join` não-ávido para receber mensagens dos buffers de mensagens para ambos os chopsticks.

[!code-cpp[concrt-philosophers-join#4](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_5.cpp)]

1. Modifique o método `putdown_chopsticks` para liberar acesso ao chopsticks enviando uma mensagem para os buffers de mensagens para ambos os chopsticks.

[!code-cpp[concrt-philosophers-join#5](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_6.cpp)]

1. Modifique o método `run` para manter os resultados do método `pickup_chopsticks` e passar esses resultados para o método `putdown_chopsticks`.

[!code-cpp[concrt-philosophers-join#6](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_7.cpp)]

1. Modifique a declaração da variável de `chopsticks` na função `wmain` para ser uma matriz de objetos `unbounded_buffer` que cada um tem uma mensagem.

[!code-cpp[concrt-philosophers-join#7](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_8.cpp)]

### <a name="description"></a>Descrição

Veja a seguir o exemplo concluído que usa objetos de `join` não-ávido para eliminar o risco de deadlock.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[concrt-philosophers-join#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_9.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
aristotle ate 50 times.
descartes ate 50 times.
hobbes ate 50 times.
socrates ate 50 times.
plato ate 50 times.
```

### <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `philosophers-join.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Philosophers-join. cpp**

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)
