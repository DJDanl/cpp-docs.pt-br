---
title: 'Instruções passo a passo: usando join para Evitar Deadlock'
ms.date: 04/25/2019
helpviewer_keywords:
- preventing deadlock with joins [Concurrency Runtime]
- deadlock, preventing [Concurrency Runtime]
- non-greedy joins, example
- join class, example
ms.assetid: d791f697-bb93-463e-84bd-5df1651b7446
ms.openlocfilehash: 5bdd6cd81051d224714dd66d4604cbdec4ddb552
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217877"
---
# <a name="walkthrough-using-join-to-prevent-deadlock"></a>Instruções passo a passo: usando join para Evitar Deadlock

Este tópico usa o problema do jantar filósofos para ilustrar como usar a classe [Concurrency:: join](../../parallel/concrt/reference/join-class.md) para evitar o deadlock em seu aplicativo. Em um aplicativo de software, o *deadlock* ocorre quando cada um dos dois ou mais processos mantiver um recurso e mutuamente aguardar até que outro processo libere algum outro recurso.

O problema do jantar filósofos é um exemplo específico do conjunto geral de problemas que podem ocorrer quando um conjunto de recursos é compartilhado entre vários processos simultâneos.

## <a name="prerequisites"></a>Pré-requisitos

Leia os tópicos a seguir antes de iniciar este passo a passos:

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Walkthrough: Criando um aplicativo baseado em agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)

- [Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md)

- [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)

## <a name="sections"></a><a name="top"></a>As

Este passo a passo contém as seguintes seções:

- [O Problema do Jantar dos Filósofos](#problem)

- [Uma implementação ingênua](#deadlock)

- [Usando Join para evitar deadlock](#solution)

## <a name="the-dining-philosophers-problem"></a><a name="problem"></a>O problema do jantar filósofos

O problema do jantar filósofos ilustra como o deadlock ocorre em um aplicativo. Nesse problema, cinco filósofos ficam em uma tabela redonda. Cada filósofo alterna entre o pensamento e o comer. Cada filósofo deve compartilhar um Chopstick com o vizinho à esquerda e outro Chopstick com o vizinho à direita. A ilustração a seguir mostra esse layout.

![O Problema do Jantar dos Filósofos](../../parallel/concrt/media/dining_philosophersproblem.png "O Problema do Jantar dos Filósofos")

Para comer, um filósofo deve conter duas chopsticks. Se todos os filósofos contiverem apenas um chopstick e estiver esperando por outro, nenhum filósofo poderá comer e todos os demais.

[[Superior](#top)]

## <a name="a-nave-implementation"></a><a name="deadlock"></a>Uma implementação ingênua

O exemplo a seguir mostra uma implementação ingênua do problema do jantar filósofos. A `philosopher` classe, que deriva de [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md), permite que cada filósofo atue de forma independente. O exemplo usa uma matriz compartilhada de objetos [Concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md) para dar a cada `philosopher` objeto acesso exclusivo a um par de Chopsticks.

Para relacionar a implementação à ilustração, a `philosopher` classe representa um filósofo. Uma **`int`** variável representa cada Chopstick. Os `critical_section` objetos servem como contentores nos quais o chopsticks REST. O `run` método simula a vida útil do filósofo. O `think` método simula o ato de pensar e o `eat` método simula o ato de comer.

Um `philosopher` objeto bloqueia ambos os `critical_section` objetos para simular a remoção do chopsticks dos detentores antes de chamar o `eat` método. Após a chamada para `eat` , o `philosopher` objeto retorna o chopsticks para os contentores definindo os `critical_section` objetos de volta para o estado desbloqueado.

O `pickup_chopsticks` método ilustra onde o deadlock pode ocorrer. Se todos `philosopher` os objetos obtiverem acesso a um dos bloqueios, nenhum `philosopher` objeto poderá continuar porque o outro bloqueio será controlado por outro `philosopher` objeto.

### <a name="example"></a>Exemplo

[!code-cpp[concrt-philosophers-deadlock#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_1.cpp)]

### <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `philosophers-deadlock.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc Philosophers-deadlock. cpp**

[[Superior](#top)]

## <a name="using-join-to-prevent-deadlock"></a><a name="solution"></a>Usando Join para evitar deadlock

Esta seção mostra como usar buffers de mensagens e funções de passagem de mensagens para eliminar a chance de deadlock.

Para relacionar este exemplo ao anterior, a `philosopher` classe substitui cada `critical_section` objeto usando um objeto [concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) e um `join` objeto. O `join` objeto serve como um arbitrador que fornece o chopsticks para o filósofo.

Este exemplo usa a `unbounded_buffer` classe porque quando um destino recebe uma mensagem de um `unbounded_buffer` objeto, a mensagem é removida da fila de mensagens. Isso permite que um `unbounded_buffer` objeto que contém uma mensagem indique que o chopstick está disponível. Um `unbounded_buffer` objeto que não contém nenhuma mensagem indica que o chopstick está sendo usado.

Este exemplo usa um objeto não-ávido `join` porque uma junção não-ávido fornece a cada `philosopher` objeto acesso a ambos os chopsticks somente quando ambos os `unbounded_buffer` objetos contêm uma mensagem. Uma junção de disponibilidade não impediria o deadlock porque uma junção de ávidos aceita mensagens assim que elas ficam disponíveis. O deadlock pode ocorrer se todos os objetos ávidos `join` receberem uma das mensagens, mas aguardar para que o outro fique disponível.

Para obter mais informações sobre junções de ávido e não-alto e as diferenças entre os vários tipos de buffer de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

### <a name="to-prevent-deadlock-in-this-example"></a>Para evitar deadlock neste exemplo

1. Remova o código a seguir do exemplo.

[!code-cpp[concrt-philosophers-deadlock#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_2.cpp)]

1. Altere o tipo dos `_left` membros de `_right` dados e da `philosopher` classe para `unbounded_buffer` .

[!code-cpp[concrt-philosophers-join#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_3.cpp)]

1. Modifique o `philosopher` construtor para assumir `unbounded_buffer` objetos como seus parâmetros.

[!code-cpp[concrt-philosophers-join#3](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_4.cpp)]

1. Modifique o `pickup_chopsticks` método para usar um objeto não-ávido `join` para receber mensagens dos buffers de mensagens para ambos os chopsticks.

[!code-cpp[concrt-philosophers-join#4](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_5.cpp)]

1. Modifique o `putdown_chopsticks` método para liberar acesso ao chopsticks enviando uma mensagem para os buffers de mensagens para ambos os chopsticks.

[!code-cpp[concrt-philosophers-join#5](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_6.cpp)]

1. Modifique o `run` método para manter os resultados do `pickup_chopsticks` método e passar esses resultados para o `putdown_chopsticks` método.

[!code-cpp[concrt-philosophers-join#6](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_7.cpp)]

1. Modifique a declaração da `chopsticks` variável na `wmain` função para que ela seja uma matriz de `unbounded_buffer` objetos que cada uma delas tenha uma mensagem.

[!code-cpp[concrt-philosophers-join#7](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_8.cpp)]

### <a name="description"></a>Descrição

Veja a seguir o exemplo concluído que usa objetos não-ávidos `join` para eliminar o risco de deadlock.

### <a name="example"></a>Exemplo

[!code-cpp[concrt-philosophers-join#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_9.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
aristotle ate 50 times.
descartes ate 50 times.
hobbes ate 50 times.
socrates ate 50 times.
plato ate 50 times.
```

### <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `philosophers-join.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc Philosophers-join. cpp**

[[Superior](#top)]

## <a name="see-also"></a>Confira também

[Orientações Tempo de Execução de Simultaneidades](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)
