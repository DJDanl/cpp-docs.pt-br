---
title: 'Passo a passo: Usando join para evitar Deadlock | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- preventing deadlock with joins [Concurrency Runtime]
- deadlock, preventing [Concurrency Runtime]
- non-greedy joins, example
- join class, example
ms.assetid: d791f697-bb93-463e-84bd-5df1651b7446
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 45669b4838925ed671646ca1aad16a3fdbe6de77
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377273"
---
# <a name="walkthrough-using-join-to-prevent-deadlock"></a>Instruções passo a passo: usando join para Evitar Deadlock

Este tópico usa o problema de filósofos jantar para ilustrar como usar o [concurrency::join](../../parallel/concrt/reference/join-class.md) classe para evitar deadlocks em seu aplicativo. Em um aplicativo de software, o *deadlock* ocorre quando cada um dos dois ou mais processos mantiver um recurso e mutuamente aguardar até que outro processo libere algum outro recurso.

O problema de filósofos jantar é um exemplo específico do conjunto geral de problemas que podem ocorrer quando um conjunto de recursos for compartilhado entre vários processos simultâneos.

## <a name="prerequisites"></a>Pré-requisitos

Leia os tópicos a seguir antes de começar este passo a passo:

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

- [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)

##  <a name="top"></a> Seções

Este passo a passo contém as seguintes seções:

- [O problema de filósofos jantar](#problem)

- [Uma implementação ingênua](#deadlock)

- [Usando join para evitar Deadlock](#solution)

##  <a name="problem"></a> O problema de filósofos jantar

O problema de filósofos jantar ilustra como o deadlock ocorre em um aplicativo. Na solução desse problema, cinco filósofos ficam em uma mesa redonda. Cada filósofo alterna entre a concepção de ideias e comer. Cada filósofo deve compartilhar um chopstick com o vizinho para a esquerda e outro chopstick com o vizinho para a direita. A ilustração a seguir mostra esse layout.

![O problema de filósofos jantando](../../parallel/concrt/media/dining_philosophersproblem.png "dining_philosophersproblem")

Para comer um filósofo deve conter Pauzinhos dois japoneses. Se cada filósofo contém apenas um chopstick e está aguardando a outra, em seguida, não poderá consumir a nenhum filósofo e sentir falta de todos.

[[Superior](#top)]

##  <a name="deadlock"></a> Uma implementação ingênua

O exemplo a seguir mostra uma implementação ingênua do problema filósofos jantar. O `philosopher` classe, que deriva [concurrency::agent](../../parallel/concrt/reference/agent-class.md), permite que cada um deles agir de forma independente. O exemplo usa uma matriz compartilhada da [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md) objetos para dar a cada `philosopher` acesso exclusivo a um par de Pauzinhos japoneses do objeto.

Para relacionar a implementação para ilustração, o `philosopher` classe representa um filósofo. Um `int` variável representa cada chopstick. O `critical_section` objetos servem como reservados no qual os Pauzinhos japoneses rest. O `run` método simula a vida útil do que o filósofo. O `think` método simule o ato de pensar e o `eat` método simule o ato de comer.

Um `philosopher` objeto bloqueia ambas `critical_section` objetos simular a remoção dos Pauzinhos japoneses dos detentores antes que ele chama o `eat` método. Após a chamada para `eat`, o `philosopher` objeto retorna os Pauzinhos japoneses os detentores, definindo o `critical_section` objetos de volta para o estado desbloqueado.

O `pickup_chopsticks` método ilustra onde pode ocorrer deadlock. Se cada `philosopher` objeto obtém acesso a um dos bloqueios, então nenhuma `philosopher` objeto pode continuar porque o bloqueio de outro é controlado por outro `philosopher` objeto.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

### <a name="code"></a>Código

[!code-cpp[concrt-philosophers-deadlock#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_1.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `philosophers-deadlock.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc filósofos-deadlock.cpp**

[[Superior](#top)]

##  <a name="solution"></a> Usando join para evitar Deadlock

Esta seção mostra como usar funções de transmissão de mensagens e buffers de mensagens para eliminar a possibilidade de deadlock.

Para relacionar neste exemplo para o anterior, o `philosopher` classe substitui cada `critical_section` objeto usando uma [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) objeto e um `join` objeto. O `join` objeto serve como um arbitrador que fornece os Pauzinhos japoneses para o filósofo.

Este exemplo usa o `unbounded_buffer` classe porque quando um destino recebe uma mensagem de um `unbounded_buffer` do objeto, a mensagem é removida da fila de mensagens. Isso permite que um `unbounded_buffer` objeto que contém uma mensagem para indicar que o chopstick está disponível. Um `unbounded_buffer` o objeto que não mantém nenhuma mensagem indica que o chopstick está sendo usado.

Este exemplo usa um não greedy `join` porque uma junção não greedy dá a cada `philosopher` acesso a ambos os Pauzinhos japoneses do objeto apenas quando ambos `unbounded_buffer` objetos contêm uma mensagem. Uma junção greedy não impediria deadlock porque uma junção greedy aceita mensagens assim que elas forem disponibilizadas. Deadlock pode ocorrer se todos os greedy `join` objetos receber uma das mensagens, mas esperar pelo outro se torne disponível.

Para obter mais informações sobre junções greedy e não greedy e as diferenças entre os vários tipos de buffer de mensagem, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

#### <a name="to-prevent-deadlock-in-this-example"></a>Para evitar deadlock neste exemplo

1. Remova o código a seguir do exemplo.

[!code-cpp[concrt-philosophers-deadlock#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_2.cpp)]

1. Alterar o tipo dos `_left` e `_right` membros de dados de `philosopher` de classe para `unbounded_buffer`.

[!code-cpp[concrt-philosophers-join#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_3.cpp)]

1. Modificar a `philosopher` construtor entrem `unbounded_buffer` objetos como seus parâmetros.

[!code-cpp[concrt-philosophers-join#3](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_4.cpp)]

1. Modificar a `pickup_chopsticks` método a ser usado um não greedy `join` objeto para receber mensagens de buffers de mensagem para ambos os Pauzinhos japoneses.

[!code-cpp[concrt-philosophers-join#4](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_5.cpp)]

1. Modificar o `putdown_chopsticks` método para liberar o acesso para os Pauzinhos japoneses, enviando uma mensagem para os buffers de mensagem para ambos os Pauzinhos japoneses.

[!code-cpp[concrt-philosophers-join#5](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_6.cpp)]

1. Modificar a `run` método para armazenar os resultados do `pickup_chopsticks` método e passar esses resultados para o `putdown_chopsticks` método.

[!code-cpp[concrt-philosophers-join#6](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_7.cpp)]

1. Modifique a declaração do `chopsticks` variável o `wmain` função para ser uma matriz de `unbounded_buffer` objetos que mantêm uma mensagem.

[!code-cpp[concrt-philosophers-join#7](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_8.cpp)]

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

A seguir mostra o exemplo completo que usa não greedy `join` objetos para eliminar o risco de deadlock.

### <a name="code"></a>Código

[!code-cpp[concrt-philosophers-join#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_9.cpp)]

### <a name="comments"></a>Comentários

Este exemplo gerencia a seguinte saída.

```Output
aristotle ate 50 times.
descartes ate 50 times.
hobbes ate 50 times.
socrates ate 50 times.
plato ate 50 times.
```

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `philosophers-join.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc filósofos-join.cpp**

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)
