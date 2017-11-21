---
title: 'Passo a passo: Usando join para evitar Deadlock | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- preventing deadlock with joins [Concurrency Runtime]
- deadlock, preventing [Concurrency Runtime]
- non-greedy joins, example
- join class, example
ms.assetid: d791f697-bb93-463e-84bd-5df1651b7446
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3553ac8948e10271da449356bde20d2a9ae4378b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="walkthrough-using-join-to-prevent-deadlock"></a>Instruções passo a passo: usando join para Evitar Deadlock
Este tópico usa o problema filósofos restaurantes para ilustrar como usar o [concurrency::join](../../parallel/concrt/reference/join-class.md) classe para evitar deadlock em seu aplicativo. Em um aplicativo de software, *deadlock* ocorre quando dois ou mais processos cada mantenha um recurso e mutuamente Aguarde até que outro processo liberar algum outro recurso.  
  
 O problema de filósofos restaurantes é um exemplo específico do conjunto geral de problemas que podem ocorrer quando um conjunto de recursos é compartilhado entre vários processos simultâneos.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Leia os tópicos a seguir antes de iniciar esta explicação passo a passo:  
  
- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
  
- [Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)  
  
- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)  
  
- [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)  
  
##  <a name="top"></a>Seções  
 Este passo a passo contém as seguintes seções:  
  
- [O problema filósofos restaurantes](#problem)  
  
- [Uma implementação simples](#deadlock)  
  
- [Usando join para evitar Deadlock](#solution)  
  
##  <a name="problem"></a>O problema filósofos restaurantes  
 O problema filósofos restaurantes ilustra como o deadlock ocorre em um aplicativo. Esse problema, cinco filósofos sentar-se em uma tabela de turno. Cada filósofo alterna entre pensando e destruidores. Cada filósofo deve compartilhar um chopstick com o vizinho à esquerda e outro chopstick com o vizinho à direita. A ilustração a seguir mostra esse layout.  
  
 ![O problema de filósofos as refeições](../../parallel/concrt/media/dining_philosophersproblem.png "dining_philosophersproblem")  
  
 Para comer, um filósofo deve conter Pauzinhos dois japoneses. Se cada filósofo contém apenas um chopstick e está aguardando que outro, então nenhuma filósofo pode comer e todos enfraquecer.  
  
 [[Superior](#top)]  
  
##  <a name="deadlock"></a>Uma implementação simples  
 O exemplo a seguir mostra uma implementação simples do problema filósofos restaurantes. O `philosopher` classe que deriva de [concurrency::agent](../../parallel/concrt/reference/agent-class.md), permite que cada um deles agir de forma independente. O exemplo usa uma matriz compartilhada de [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md) objetos para fornecer a cada `philosopher` acesso exclusivo a um par de Pauzinhos japoneses do objeto.  
  
 Para relacionar a implementação para ilustração, a `philosopher` classe representa um filósofo. Um `int` variável representa cada chopstick. O `critical_section` objetos servem como proprietários, no qual os Pauzinhos japoneses rest. O `run` método simula a vida útil do filósofo. O `think` método simula o ato de pensar e `eat` método simula o ato de alimentação.  
  
 Um `philosopher` objeto bloqueia ambas `critical_section` objetos simular a remoção de Pauzinhos de japoneses de proprietários antes que ele chama o `eat` método. Após a chamada a `eat`, o `philosopher` object retorna os Pauzinhos japoneses aos detentores de definindo o `critical_section` objetos de volta para o estado desbloqueado.  
  
 O `pickup_chopsticks` método ilustra onde pode ocorrer deadlock. Se cada `philosopher` objeto obtiver acesso a um dos bloqueios e não `philosopher` objeto pode continuar porque o outro bloqueio é controlado por outro `philosopher` objeto.  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
  
### <a name="code"></a>Código  
 [!code-cpp[concrt-philosophers-deadlock#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_1.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `philosophers-deadlock.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc filósofos-deadlock.cpp**  
  
 [[Superior](#top)]  
  
##  <a name="solution"></a>Usando join para evitar Deadlock  
 Esta seção mostra como usar funções de transmissão de mensagens e buffers de mensagens para eliminar a chance de deadlock.  
  
 Para relacionar neste exemplo para o anterior, o `philosopher` classe substitui cada `critical_section` objeto usando um [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) objeto e um `join` objeto. O `join` objeto serve como um arbitrador que fornece os Pauzinhos japoneses o filósofo.  
  
 Este exemplo usa o `unbounded_buffer` classe porque quando um destino recebe uma mensagem de um `unbounded_buffer` do objeto, a mensagem é removida da fila de mensagens. Isso permite que um `unbounded_buffer` o objeto que contém uma mensagem para indicar que o chopstick está disponível. Um `unbounded_buffer` objeto que não mantém nenhuma mensagem indica que o chopstick está sendo usada.  
  
 Este exemplo usa um não greedy `join` porque uma junção não greedy dá a cada `philosopher` acesso a ambos os Pauzinhos japoneses do objeto apenas quando ambas `unbounded_buffer` objetos contêm uma mensagem. Uma junção greedy não impediria deadlock porque uma junção greedy aceita mensagens assim que elas estiverem disponíveis. Deadlock pode ocorrer se todos os greedy `join` objetos receber uma das mensagens, mas esperar para os outros se torne disponível.  
  
 Para obter mais informações sobre junções não greedy e greedy e as diferenças entre os vários tipos de buffer de mensagem, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).  
  
#### <a name="to-prevent-deadlock-in-this-example"></a>Para evitar deadlock neste exemplo  
  
1.  Remova o seguinte código do exemplo.  
  
 [!code-cpp[concrt-philosophers-deadlock#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_2.cpp)]  
  
2.  Alterar o tipo do `_left` e `_right` membros de dados de `philosopher` de classe para `unbounded_buffer`.  
  
 [!code-cpp[concrt-philosophers-join#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_3.cpp)]  
  
3.  Modificar o `philosopher` construtor sejam `unbounded_buffer` objetos como seus parâmetros.  
  
 [!code-cpp[concrt-philosophers-join#3](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_4.cpp)]  
  
4.  Modificar o `pickup_chopsticks` método a ser usado um não greedy `join` objeto para receber mensagens de buffers de mensagem para ambos os Pauzinhos japoneses.  
  
 [!code-cpp[concrt-philosophers-join#4](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_5.cpp)]  
  
5.  Modificar o `putdown_chopsticks` método para liberar o acesso para os Pauzinhos japoneses enviando uma mensagem para os buffers de mensagem para ambos os Pauzinhos japoneses.  
  
 [!code-cpp[concrt-philosophers-join#5](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_6.cpp)]  
  
6.  Modificar o `run` método para armazenar os resultados do `pickup_chopsticks` método e passar esses resultados para o `putdown_chopsticks` método.  
  
 [!code-cpp[concrt-philosophers-join#6](../../parallel/concrt/codesnippet/cpp/walkthrough-using-join-to-prevent-deadlock_7.cpp)]  
  
7.  Modificar a declaração de `chopsticks` variável o `wmain` função para ser uma matriz de `unbounded_buffer` objetos que cada mantém uma mensagem.  
  
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
 [Explicações passo a passo de tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)   
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md)   
 [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)
