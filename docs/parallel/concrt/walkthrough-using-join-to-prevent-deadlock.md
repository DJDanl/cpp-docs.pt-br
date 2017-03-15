---
title: "Instru&#231;&#245;es passo a passo: usando join para Evitar Deadlock | Microsoft Docs"
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
  - "impedindo deadlock com junções [Tempo de Execução de Simultaneidade]"
  - "deadlock, impedindo [tempo de execução de simultaneidade]"
  - "junções não greedy, por exemplo:"
  - "classe, Join exemplo"
ms.assetid: d791f697-bb93-463e-84bd-5df1651b7446
caps.latest.revision: 16
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: usando join para Evitar Deadlock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico usa o problema de jantar de filósofos para ilustrar como usar a classe de [concurrency::join](../Topic/join%20Class.md) para evitar o deadlock em seu aplicativo.  Em um aplicativo de software, *o deadlock* ocorre quando duas ou mais processos cada propriedade um recurso e mutuamente espera para que outro processo libere qualquer outro recurso.  
  
 O problema de jantar de filósofos específico é um exemplo de conjunto geral de problemas que podem ocorrer quando um conjunto de recursos é compartilhado entre vários processos simultâneos.  
  
## Pré-requisitos  
 Leia os tópicos a seguir antes de começar este passo a passo:  
  
-   [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
  
-   [Instruções passo a passo: criando um aplicativo com base no agente](../../parallel/concrt/walkthrough-creating-an-agent-based-application.md)  
  
-   [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
-   [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)  
  
-   [Estruturas de dados de sincronização](../Topic/Synchronization%20Data%20Structures.md)  
  
##  <a name="top"></a> Seções  
 Essa explicação passo a passo contém as seguintes seções:  
  
-   [O Problema do Jantar dos Filósofos](#problem)  
  
-   [Uma Implementação Ingênua](#deadlock)  
  
-   [Usando join para Evitar Deadlock](#solution)  
  
##  <a name="problem"></a> O Problema do Jantar dos Filósofos  
 O problema de jantar de filósofos ilustra como o deadlock ocorre em um aplicativo.  Neste problema, cinco filósofos eles ficam em uma mesa redonda.  Cada filósofo alterna entre o pensamento e ter.  Cada filósofo deve compartilhar um hashi com o vizinho à esquerda e outro hashi com o vizinho à direita.  A ilustração a seguir mostra esse layout.  
  
 ![O problema de filósofos jantar](../../parallel/concrt/media/dining_philosophersproblem.png "Dining\_PhilosophersProblem")  
  
 Para ter, um filósofo deve manter dois hashis.  Se cada filósofo contém apenas um hashi e está aguardando outro, nenhum filósofo pode ter e todos morrem de fome.  
  
 \[[Superior](#top)\]  
  
##  <a name="deadlock"></a> Uma Implementação Ingênua  
 O exemplo a seguir mostra uma implementação de naïve do problema de jantar de filósofos.  A classe de `philosopher` , que se deriva de [concurrency::agent](../../parallel/concrt/reference/agent-class.md), permite que cada filósofo para atuar independente.  O exemplo usa uma matriz de objetos de [concurrency::critical\_section](../../parallel/concrt/reference/critical-section-class.md) compartilhada para dar a cada objeto de `philosopher` acesso exclusivo para um par de hashis.  
  
 Para relacionar a implementação à ilustração, a classe de `philosopher` representa um filósofo.  Uma variável de `int` representa cada hashi.  Os objetos de `critical_section` servem como o oferece suporte em que os hashis descansam.  O método de `run` simula a vida do filósofo.  O método de `think` simula o ato de pensamento e o método de `eat` simula o ato de ter.  
  
 Um objeto de `philosopher` bloqueia os dois objetos de `critical_section` para simular a remoção de hashis da suporte antes de chamar o método de `eat` .  Depois da chamada a `eat`, o objeto de `philosopher` retorna os hashis a suporte à definição dos objetos de `critical_section` de volta ao estado desbloqueado.  
  
 O método de `pickup_chopsticks` ilustra em que o deadlock pode ocorrer.  Se cada objeto de `philosopher` obtém acesso a um dos bloqueios, nenhum objeto de `philosopher` pode continuar porque o outro bloqueio é controlado por outro objeto de `philosopher` .  
  
## Exemplo  
  
### Descrição  
  
### Código  
 [!CODE [concrt-philosophers-deadlock#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-deadlock#1)]  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `philosophers-deadlock.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc philosophers\-deadlock.cpp**  
  
 \[[Superior](#top)\]  
  
##  <a name="solution"></a> Usando join para Evitar Deadlock  
 Esta seção mostra como usar buffers de mensagem e funções mensagem\- passar para eliminar a possibilidade de deadlock.  
  
 Para relacionar este exemplo a anterior, a classe de `philosopher` substitui cada objeto de `critical_section` usando um objeto de [concurrency::unbounded\_buffer](../Topic/unbounded_buffer%20Class.md) e um objeto de `join` .  O objeto de `join` serve como um árbitro que fornece os hashis ao filósofo.  
  
 Este exemplo usa a classe de `unbounded_buffer` porque quando um destino recebe uma mensagem de um objeto de `unbounded_buffer` , a mensagem será removida da fila de mensagens.  Isso permite que um objeto de `unbounded_buffer` que contém uma mensagem para indicar que o hashi está disponível.  Um objeto de `unbounded_buffer` que não contém nenhuma mensagem indica que o hashi está sendo usado.  
  
 Este exemplo usa um objeto não ávido de `join` como uma junção não ávido de cada acesso do objeto de `philosopher` a ambos os hashis somente quando os dois objetos de `unbounded_buffer` contêm uma mensagem.  Uma junção ávido não impede que exiba o deadlock como uma junção ávido aceita mensagens assim que se tornassem disponíveis.  O deadlock pode ocorrer se todos os objetos ávidos de `join` recebem uma das mensagens mas a esperar indefinidamente para que o outro se torna disponíveis.  
  
 Para obter mais informações sobre junções ávidos e não ávidos, e as diferenças entre os vários tipos de buffer de mensagem, consulte [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md).  
  
#### Para evitar deadlock neste exemplo  
  
1.  Remova o código de exemplo a seguir.  
  
     [!CODE [concrt-philosophers-deadlock#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-deadlock#2)]  
  
2.  Alterar o tipo de membros de dados de `_left` e de `_right` da classe de `philosopher` a `unbounded_buffer`.  
  
     [!CODE [concrt-philosophers-join#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-join#2)]  
  
3.  Modifique o construtor de `philosopher` para usar objetos de `unbounded_buffer` como seus parâmetros.  
  
     [!CODE [concrt-philosophers-join#3](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-join#3)]  
  
4.  Modifique o método de `pickup_chopsticks` para usar um objeto não ávido de `join` para receber mensagens dos buffers de mensagem para ambos os hashis.  
  
     [!CODE [concrt-philosophers-join#4](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-join#4)]  
  
5.  Modifique o método de `putdown_chopsticks` para liberar o acesso a hashis enviando uma mensagem aos buffers de mensagem para ambos os hashis.  
  
     [!CODE [concrt-philosophers-join#5](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-join#5)]  
  
6.  Modifique o método de `run` para manter os resultados do método de `pickup_chopsticks` e passar esses resultados ao método de `putdown_chopsticks` .  
  
     [!CODE [concrt-philosophers-join#6](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-join#6)]  
  
7.  Modifique a declaração de variável de `chopsticks` na função de `wmain` para ser uma matriz de objetos que `unbounded_buffer` cada mensagem de uma propriedade.  
  
     [!CODE [concrt-philosophers-join#7](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-join#7)]  
  
## Exemplo  
  
### Descrição  
 O exemplo a seguir mostra que o exemplo completo que usa `join` não ávido objetos para eliminar o risco de deadlock.  
  
### Código  
 [!CODE [concrt-philosophers-join#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-philosophers-join#1)]  
  
### Comentários  
 O exemplo produz a seguinte saída.  
  
  **aristotle comeu 50 vezes.**  
**descarta comeu 50 vezes.**  
**os hobbes comeram 50 vezes.**  
**Socrates comeu 50 vezes.**  
**plato comeu 50 vezes.**   
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `philosophers-join.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc philosophers\-join.cpp**  
  
 \[[Superior](#top)\]  
  
## Consulte também  
 [Instruções passo a passo do Tempo de Execução de Simultaneidade](../Topic/Concurrency%20Runtime%20Walkthroughs.md)   
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)   
 [Estruturas de dados de sincronização](../Topic/Synchronization%20Data%20Structures.md)