---
title: Blocos de mensagens assíncronos
ms.date: 11/04/2016
helpviewer_keywords:
- non-greedy join [Concurrency Runtime]
- asynchronous message blocks
- greedy join [Concurrency Runtime]
ms.assetid: 79c456c0-1692-480c-bb67-98f2434c1252
ms.openlocfilehash: ef6f6f56a82cc76c2c270817ed40d15418960dc1
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141954"
---
# <a name="asynchronous-message-blocks"></a>Blocos de mensagens assíncronos

A biblioteca de agentes fornece vários tipos de bloco de mensagens que permitem que você propague mensagens entre componentes de aplicativos de maneira segura para thread. Esses tipos de bloco de mensagens geralmente são usados com várias rotinas de passagem de mensagens, como [Concurrency:: send](reference/concurrency-namespace-functions.md#send), [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend), [Concurrency:: receive](reference/concurrency-namespace-functions.md#receive)e [Concurrency:: try_receive](reference/concurrency-namespace-functions.md#try_receive). Para obter mais informações sobre as rotinas de transmissão de mensagens que são definidas pela biblioteca de agentes, consulte [funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md).

## <a name="top"></a>As

Este tópico contém as seguintes seções:

- [Origens e destinos](#sources_and_targets)

- [Propagação de mensagem](#propagation)

- [Visão geral dos tipos de bloco de mensagem](#overview)

- [Classe unbounded_buffer](#unbounded_buffer)

- [Classe overwrite_buffer](#overwrite_buffer)

- [Classe single_assignment](#single_assignment)

- [Classe call](#call)

- [Classe transformer](#transformer)

- [Classe choice](#choice)

- [Classes Join e multitype_join](#join)

- [Classe timer](#timer)

- [Filtragem de mensagens](#filtering)

- [Reserva de mensagens](#reservation)

## <a name="sources_and_targets"></a>Origens e destinos

Origens e destinos são dois participantes importantes na transmissão de mensagens. Uma *origem* refere-se a um ponto de extremidade de comunicação que envia mensagens. Um *destino* refere-se a um ponto de extremidade de comunicação que recebe mensagens. Você pode considerar uma fonte como um ponto de extremidade que você leu e um destino como um ponto de extremidade no qual você escreve. Os aplicativos conectam fontes e destinos para formar *redes de mensagens*.

A biblioteca de agentes usa duas classes abstratas para representar origens e destinos: [Concurrency:: as](../../parallel/concrt/reference/isource-class.md) e [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md). Tipos de bloco de mensagens que atuam como fontes derivam de `ISource`; tipos de bloco de mensagens que atuam como destinos derivam de `ITarget`. Tipos de bloco de mensagens que atuam como origens e destinos derivam de `ISource` e `ITarget`.

[[Superior](#top)]

## <a name="propagation"></a>Propagação de mensagem

A *propagação de mensagens* é o ato de enviar uma mensagem de um componente para outro. Quando uma mensagem é oferecida por um bloco de mensagens, ela pode aceitar, recusar ou adiar essa mensagem. Cada tipo de bloco de mensagens armazena e transmite mensagens de maneiras diferentes. Por exemplo, a classe `unbounded_buffer` armazena um número ilimitado de mensagens, a classe `overwrite_buffer` armazena uma única mensagem por vez, e a classe transformadora armazena uma versão alterada de cada mensagem. Esses tipos de bloco de mensagens são descritos mais detalhadamente mais adiante neste documento.

Quando um bloco de mensagens aceita uma mensagem, ele pode, opcionalmente, executar o trabalho e, se o bloco de mensagens for uma origem, passar a mensagem resultante para outro membro da rede. Um bloco de mensagens pode usar uma função de filtro para recusar mensagens que não deseja receber. Os filtros são descritos mais detalhadamente mais adiante neste tópico, na seção [filtragem de mensagens](#filtering). Um bloco de mensagens que adia uma mensagem pode reservar essa mensagem e consumi-la mais tarde. A reserva de mensagens é descrita em mais detalhes posteriormente neste tópico, na seção [reserva de mensagem](#reservation).

A biblioteca de agentes permite que os blocos de mensagens passem mensagens de forma assíncrona ou síncrona. Quando você passa uma mensagem para um bloco de mensagens de forma síncrona, por exemplo, usando a função `send`, o tempo de execução bloqueia o contexto atual até que o bloco de destino aceite ou rejeite a mensagem. Quando você passa uma mensagem para um bloco de mensagens de forma assíncrona, por exemplo, usando a função `asend`, o tempo de execução oferece a mensagem para o destino e, se o destino aceitar a mensagem, o tempo de execução agenda uma tarefa assíncrona que propaga a mensagem para o receptor. O tempo de execução usa tarefas leves para propagar mensagens de maneira cooperativa. Para obter mais informações sobre tarefas leves, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

Os aplicativos conectam fontes e destinos para formar redes de mensagens. Normalmente, você vincula a rede e chama `send` ou `asend` para passar dados para a rede. Para conectar um bloco de mensagem de origem a um destino, chame o método [Concurrency:: as:: link_target](reference/isource-class.md#link_target) . Para desconectar um bloco de origem de um destino, chame o método [Concurrency:: as:: unlink_target](reference/isource-class.md#unlink_target) . Para desconectar um bloco de origem de todos os seus destinos, chame o método [Concurrency:: as:: unlink_targets](reference/isource-class.md#unlink_targets) . Quando um dos tipos de bloco de mensagens predefinidos deixa o escopo ou é destruído, ele se desconecta automaticamente de qualquer bloco de destino. Alguns tipos de bloco de mensagens restringem o número máximo de destinos nos quais eles podem gravar. A seção a seguir descreve as restrições que se aplicam aos tipos de bloco de mensagens predefinidos.

[[Superior](#top)]

## <a name="overview"></a>Visão geral dos tipos de bloco de mensagem

A tabela a seguir descreve brevemente a função dos tipos de bloco de mensagens importantes.

[unbounded_buffer](#unbounded_buffer)<br/>
Armazena uma fila de mensagens.

[overwrite_buffer](#overwrite_buffer)<br/>
Armazena uma mensagem que pode ser gravada e lida de várias vezes.

[single_assignment](#single_assignment)<br/>
Armazena uma mensagem que pode ser gravada uma vez e lida de várias vezes.

[ligação](#call)<br/>
Executa o trabalho quando recebe uma mensagem.

[transformador](#transformer)<br/>
Executa o trabalho quando recebe dados e envia o resultado desse trabalho para outro bloco de destino. A classe `transformer` pode agir em diferentes tipos de entrada e saída.

[desejada](#choice)<br/>
Seleciona a primeira mensagem disponível de um conjunto de fontes.

[junção de junção e multitipo](#join)<br/>
Aguarde até que todas as mensagens sejam recebidas de um conjunto de fontes e, em seguida, combine as mensagens em uma mensagem para outro bloco de mensagens.

[tempo](#timer)<br/>
Envia uma mensagem para um bloco de destino em um intervalo regular.

Esses tipos de bloco de mensagens têm características diferentes que os tornam úteis para diferentes situações. Estas são algumas das características:

- *Tipo de propagação*: se o bloco de mensagem atua como uma fonte de dados, um receptor de dados ou ambos.

- *Ordenação de mensagens*: se o bloco de mensagens mantém a ordem original na qual as mensagens são enviadas ou recebidas. Cada tipo de bloco de mensagem predefinido mantém a ordem original na qual ele envia ou recebe mensagens.

- *Contagem de origem*: o número máximo de fontes das quais o bloco de mensagens pode ser lido.

- *Contagem de destino*: o número máximo de destinos que o bloco de mensagens pode gravar.

A tabela a seguir mostra como essas características se relacionam aos vários tipos de bloco de mensagens.

|Tipo de bloco de mensagens|Tipo de propagação (origem, destino ou ambos)|Ordenação de mensagens (ordenada ou não ordenada)|Contagem de origem|Contagem de destino|
|------------------------|--------------------------------------------------|-----------------------------------------------|------------------|------------------|
|`unbounded_buffer`|Ambos|Encomendado|Unbounded|Unbounded|
|`overwrite_buffer`|Ambos|Encomendado|Unbounded|Unbounded|
|`single_assignment`|Ambos|Encomendado|Unbounded|Unbounded|
|`call`|Destino|Encomendado|Unbounded|Não Aplicável|
|`transformer`|Ambos|Encomendado|Unbounded|1|
|`choice`|Ambos|Encomendado|10|1|
|`join`|Ambos|Encomendado|Unbounded|1|
|`multitype_join`|Ambos|Encomendado|10|1|
|`timer`|Origem|Não Aplicável|Não Aplicável|1|

As seções a seguir descrevem os tipos de bloco de mensagens em mais detalhes.

[[Superior](#top)]

## <a name="unbounded_buffer"></a>Classe unbounded_buffer

A classe [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) representa uma estrutura de mensagens assíncrona de uso geral. Essa classe armazena uma fila PEPS (primeiro a entrar, primeiro a sair) de mensagens que podem ser gravadas por várias origens ou lidas por vários destinos. Quando um destino recebe uma mensagem de um objeto `unbounded_buffer`, essa mensagem é removida da fila de mensagens. Portanto, embora um objeto `unbounded_buffer` possa ter vários destinos, apenas um destino receberá cada mensagem. A classe `unbounded_buffer` é útil quando você deseja passar várias mensagens para outro componente e esse componente deve receber cada uma das mensagens.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a estrutura básica de como trabalhar com a classe `unbounded_buffer`. Este exemplo envia três valores para um objeto `unbounded_buffer` e, em seguida, lê esses valores de volta do mesmo objeto.

[!code-cpp[concrt-unbounded_buffer-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_1.cpp)]

Esse exemplo gera a saída a seguir:

```Output
334455
```

Para obter um exemplo completo que mostra como usar a classe `unbounded_buffer`, consulte [como implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md).

[[Superior](#top)]

## <a name="overwrite_buffer"></a>Classe overwrite_buffer

A classe [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) se assemelha à classe `unbounded_buffer`, exceto que um objeto `overwrite_buffer` armazena apenas uma mensagem. Além disso, quando um destino recebe uma mensagem de um objeto `overwrite_buffer`, essa mensagem não é removida do buffer. Portanto, vários destinos recebem uma cópia da mensagem.

A classe `overwrite_buffer` é útil quando você deseja passar várias mensagens para outro componente, mas esse componente precisa apenas do valor mais recente. Essa classe também é útil quando você deseja difundir uma mensagem para vários componentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a estrutura básica de como trabalhar com a classe `overwrite_buffer`. Este exemplo envia três valores para um objeto `overwrite _buffer` e, em seguida, lê o valor atual do mesmo objeto três vezes. Este exemplo é semelhante ao exemplo para a classe `unbounded_buffer`. No entanto, a classe `overwrite_buffer` armazena apenas uma mensagem. Além disso, o tempo de execução não remove a mensagem de um objeto `overwrite_buffer` depois que ele é lido.

[!code-cpp[concrt-overwrite_buffer-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_2.cpp)]

Esse exemplo gera a saída a seguir:

```Output
555555
```

Para obter um exemplo completo que mostra como usar a classe `overwrite_buffer`, consulte [como implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md).

[[Superior](#top)]

## <a name="single_assignment"></a>Classe single_assignment

A classe [Concurrency:: single_assignment](../../parallel/concrt/reference/single-assignment-class.md) se assemelha à classe `overwrite_buffer`, exceto que um objeto `single_assignment` pode ser gravado apenas uma vez. Como na classe `overwrite_buffer`, quando um destino recebe uma mensagem de um objeto `single_assignment`, essa mensagem não é removida do objeto. Portanto, vários destinos recebem uma cópia da mensagem. A classe `single_assignment` é útil quando você deseja difundir uma mensagem para vários componentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a estrutura básica de como trabalhar com a classe `single_assignment`. Este exemplo envia três valores para um objeto `single_assignment` e, em seguida, lê o valor atual do mesmo objeto três vezes. Este exemplo é semelhante ao exemplo para a classe `overwrite_buffer`. Embora as classes `overwrite_buffer` e `single_assignment` armazenem uma única mensagem, a classe `single_assignment` pode ser gravada apenas uma vez.

[!code-cpp[concrt-single_assignment-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_3.cpp)]

Esse exemplo gera a saída a seguir:

```Output
333333
```

Para obter um exemplo completo que mostra como usar a classe de `single_assignment`, consulte [Walkthrough: Implementing Futures](../../parallel/concrt/walkthrough-implementing-futures.md).

[[Superior](#top)]

## <a name="call"></a>Classe Call

A classe [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) atua como um receptor de mensagem que executa uma função de trabalho quando recebe dados. Essa função de trabalho pode ser uma expressão lambda, um objeto de função ou um ponteiro de função. Um objeto `call` se comporta de maneira diferente de uma chamada de função comum porque atua em paralelo a outros componentes que enviam mensagens para ele. Se um objeto `call` estiver executando o trabalho quando receber uma mensagem, ele adicionará essa mensagem a uma fila. Cada objeto de `call` processa mensagens em fila na ordem em que elas são recebidas.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a estrutura básica de como trabalhar com a classe `call`. Este exemplo cria um objeto `call` que imprime cada valor que ele recebe para o console. Em seguida, o exemplo envia três valores para o objeto `call`. Como o objeto `call` processa mensagens em um thread separado, este exemplo também usa uma variável de contador e um objeto de [evento](../../parallel/concrt/reference/event-class.md) para garantir que o objeto `call` processe todas as mensagens antes que a função `wmain` retorne.

[!code-cpp[concrt-call-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_4.cpp)]

Esse exemplo gera a saída a seguir:

```Output
334455
```

Para obter um exemplo completo que mostra como usar a classe `call`, consulte [como: fornecer funções de trabalho para as classes Call e transformador](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md).

[[Superior](#top)]

## <a name="transformer"></a>Classe de transformador

A classe [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) atua como um receptor de mensagens e como um remetente da mensagem. A classe `transformer` se assemelha à classe `call` porque ela executa uma função de trabalho definida pelo usuário quando recebe dados. No entanto, a classe `transformer` também envia o resultado da função de trabalho para objetos receptores. Como um objeto `call`, um objeto `transformer` atua em paralelo a outros componentes que enviam mensagens para ele. Se um objeto `transformer` estiver executando o trabalho quando receber uma mensagem, ele adicionará essa mensagem a uma fila. Cada objeto de `transformer` processa suas mensagens em fila na ordem em que elas são recebidas.

A classe `transformer` envia sua mensagem a um destino. Se você definir o parâmetro `_PTarget` no construtor como `NULL`, você poderá especificar o destino mais tarde chamando o método [Concurrency:: link_target](reference/source-block-class.md#link_target) .

Ao contrário de todos os outros tipos de bloco de mensagens assíncronas que são fornecidos pela biblioteca de agentes, a classe `transformer` pode atuar em diferentes tipos de entrada e saída. Essa capacidade de transformar dados de um tipo para outro torna o `transformer` classe um componente fundamental em muitas redes simultâneas. Além disso, você pode adicionar funcionalidade paralela mais refinada na função de trabalho de um objeto `transformer`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a estrutura básica de como trabalhar com a classe `transformer`. Este exemplo cria um objeto `transformer` que várias cada entrada `int` valor por 0,33 para produzir um valor de `double` como saída. Em seguida, o exemplo recebe os valores transformados do mesmo objeto `transformer` e os imprime no console do.

[!code-cpp[concrt-transformer-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_5.cpp)]

Esse exemplo gera a saída a seguir:

```Output
10.8914.5218.15
```

Para obter um exemplo completo que mostra como usar a classe `transformer`, consulte [como: usar o transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md).

[[Superior](#top)]

## <a name="choice"></a>Classe Choice

A classe [Concurrency:: Choice](../../parallel/concrt/reference/choice-class.md) seleciona a primeira mensagem disponível de um conjunto de fontes. A classe `choice` representa um mecanismo de fluxo de controle em vez de um mecanismo de fluxo de fluxos (o tópico [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) descreve as diferenças entre Dataflow e fluxo de controle).

A leitura de um objeto Choice se assemelha a chamar a função da API do Windows `WaitForMultipleObjects` quando tem o parâmetro `bWaitAll` definido como `FALSE`. No entanto, a classe `choice` associa dados ao próprio evento, em vez de a um objeto de sincronização externo.

Normalmente, você usa a classe `choice` junto com a função [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) para direcionar o fluxo de controle em seu aplicativo. Use a classe `choice` quando precisar selecionar entre os buffers de mensagens que têm tipos diferentes. Use a classe `single_assignment` quando precisar selecionar entre os buffers de mensagens que têm o mesmo tipo.

A ordem na qual você vincula fontes a um objeto `choice` é importante porque ela pode determinar qual mensagem está selecionada. Por exemplo, considere o caso em que você vincula vários buffers de mensagens que já contêm uma mensagem a um objeto `choice`. O objeto `choice` seleciona a mensagem da primeira fonte à qual ele está vinculado. Depois de vincular todas as fontes, o objeto `choice` preserva a ordem em que cada fonte recebe uma mensagem.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a estrutura básica de como trabalhar com a classe `choice`. Este exemplo usa a função [Concurrency:: make_choice](reference/concurrency-namespace-functions.md#make_choice) para criar um objeto `choice` que seleciona entre três blocos de mensagens. Em seguida, o exemplo computa vários números Fibonacci e armazena cada resultado em um bloco de mensagens diferente. O exemplo, em seguida, imprime no console uma mensagem com base na operação que foi concluída primeiro.

[!code-cpp[concrt-choice-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_6.cpp)]

Este exemplo produz a seguinte saída de exemplo:

```Output
fib35 received its value first. Result = 9227465
```

Como a tarefa que computa o número de<sup>35 Fibonacci</sup> não é garantida para concluir primeiro, a saída desse exemplo pode variar.

Este exemplo usa o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) para calcular os números Fibonacci em paralelo. Para obter mais informações sobre `parallel_invoke`, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

Para obter um exemplo completo que mostra como usar a classe `choice`, consulte [como: selecionar entre as tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md).

[[Superior](#top)]

## <a name="join"></a>Classes Join e multitype_join

As classes [Concurrency:: join](../../parallel/concrt/reference/join-class.md) e [concurrency:: multitype_join](../../parallel/concrt/reference/multitype-join-class.md) permitem aguardar a espera de cada membro de um conjunto de fontes para receber uma mensagem. A classe `join` atua em objetos de origem que têm um tipo de mensagem comum. A classe `multitype_join` atua em objetos de origem que podem ter tipos de mensagem diferentes.

A leitura de um objeto `join` ou `multitype_join` se assemelha a chamar a função da API do Windows `WaitForMultipleObjects` quando ele tem o parâmetro `bWaitAll` definido como `TRUE`. No entanto, assim como um objeto `choice`, os objetos `join` e `multitype_join` usam um mecanismo de eventos que associa dados ao próprio evento, em vez de a um objeto de sincronização externo.

A leitura de um objeto `join` produz um objeto std::[vector](../../standard-library/vector-class.md) . A leitura de um objeto `multitype_join` produz um objeto std::[tupla](../../standard-library/tuple-class.md) . Os elementos aparecem nesses objetos na mesma ordem em que os buffers de origem correspondentes estão vinculados ao objeto `join` ou `multitype_join`. Como a ordem na qual você vincula os buffers de origem a um objeto `join` ou `multitype_join` está associada à ordem dos elementos no objeto `vector` resultante ou `tuple`, recomendamos que você não Desvincule um buffer de origem existente de uma junção. Fazer isso pode resultar em um comportamento não especificado.

### <a name="greedy-versus-non-greedy-joins"></a>Junções Greedy Contra Não Greedy

As classes `join` e `multitype_join` dão suporte ao conceito de junções de ávido e não-ávido. Uma *junção* de disponibilidade aceita uma mensagem de cada uma de suas fontes à medida que as mensagens ficam disponíveis até que todas as mensagens estejam disponíveis. Uma *junção não-ávido* recebe mensagens em duas fases. Primeiro, uma junção não-ávido aguarda até receber uma mensagem de cada uma de suas origens. Em segundo lugar, depois que todas as mensagens de origem estiverem disponíveis, uma junção não-ávido tentará reservar cada uma dessas mensagens. Se ele puder reservar cada mensagem, ele consumirá todas as mensagens e as propagará para seu destino. Caso contrário, ele libera ou cancela, as reservas de mensagem e, novamente, aguarda cada fonte para receber uma mensagem.

As junções de alto desempenho funcionam melhor do que as junções não-ávidos porque aceitam mensagens imediatamente. No entanto, em casos raros, as junções de ávido podem levar a deadlocks. Use uma junção não-ávido quando tiver várias junções que contenham um ou mais objetos de origem compartilhados.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a estrutura básica de como trabalhar com a classe `join`. Este exemplo usa a função [Concurrency:: make_join](reference/concurrency-namespace-functions.md#make_join) para criar um objeto `join` que recebe de três objetos `single_assignment`. Este exemplo computa vários números de Fibonacci, armazena cada resultado em um objeto `single_assignment` diferente e, em seguida, imprime no console cada resultado que o objeto `join` mantém. Este exemplo é semelhante ao exemplo para a classe `choice`, exceto que a classe `join` aguarda que todos os blocos de mensagens de origem recebam uma mensagem.

[!code-cpp[concrt-join-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_7.cpp)]

Esse exemplo gera a saída a seguir:

```Output
fib35 = 9227465fib37 = 24157817half_of_fib42 = 1.33957e+008
```

Este exemplo usa o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) para calcular os números Fibonacci em paralelo. Para obter mais informações sobre `parallel_invoke`, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

Para obter exemplos completos que mostram como usar a classe `join`, confira [como: selecionar entre as tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md) e [instruções passo a passos: usando Join para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).

[[Superior](#top)]

## <a name="timer"></a>Classe Timer

A classe Concurrency::[timer](../../parallel/concrt/reference/timer-class.md) atua como uma fonte de mensagem. Um objeto `timer` envia uma mensagem para um destino após um período de tempo especificado. A classe `timer` é útil quando você deve atrasar o envio de uma mensagem ou deseja enviar uma mensagem em um intervalo regular.

A classe `timer` envia sua mensagem a apenas um destino. Se você definir o parâmetro `_PTarget` no construtor como `NULL`, você poderá especificar o destino mais tarde chamando o método [Concurrency:: as:: link_target](reference/source-block-class.md#link_target) .

Um objeto `timer` pode ser repetido ou não repetido. Para criar um temporizador repetitivo, passe **true** para o parâmetro `_Repeating` ao chamar o construtor. Caso contrário, passe **false** para o parâmetro `_Repeating` para criar um temporizador não repetitivo. Se o temporizador for repetido, ele enviará a mesma mensagem para seu destino após cada intervalo.

A biblioteca de agentes cria `timer` objetos no estado não iniciado. Para iniciar um objeto de timer, chame o método [Concurrency:: timer:: Start](reference/timer-class.md#start) . Para interromper um objeto `timer`, destrua o objeto ou chame o método [Concurrency:: timer:: Stop](reference/timer-class.md#stop) . Para pausar um temporizador repetitivo, chame o método [Concurrency:: timer::p ause](reference/timer-class.md#pause) .

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a estrutura básica de como trabalhar com a classe `timer`. O exemplo usa objetos `timer` e `call` para relatar o progresso de uma operação demorada.

[!code-cpp[concrt-timer-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_8.cpp)]

Este exemplo produz a seguinte saída de exemplo:

```Output
Computing fib(42)..................................................result is 267914296
```

Para obter um exemplo completo que mostra como usar a classe `timer`, consulte [como: Enviar uma mensagem em um intervalo regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md).

[[Superior](#top)]

## <a name="filtering"></a>Filtragem de mensagens

Ao criar um objeto de bloco de mensagens, você pode fornecer uma *função de filtro* que determina se o bloco de mensagens aceita ou rejeita uma mensagem. Uma função de filtro é uma maneira útil de garantir que um bloco de mensagens receba apenas determinados valores.

O exemplo a seguir mostra como criar um objeto `unbounded_buffer` que usa uma função de filtro para aceitar apenas números pares. O objeto `unbounded_buffer` rejeita números ímpares e, portanto, não propaga números ímpares para seus blocos de destino.

[!code-cpp[concrt-filter-function#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_9.cpp)]

Esse exemplo gera a saída a seguir:

```Output
0 2 4 6 8
```

Uma função de filtro pode ser uma função lambda, um ponteiro de função ou um objeto de função. Cada função de filtro usa um dos formulários a seguir.

```Output
bool (T)
bool (T const &)
```

Para eliminar a cópia desnecessária de dados, use o segundo formulário quando você tiver um tipo de agregação propagado por valor.

A filtragem de mensagens dá suporte ao modelo de programação de *fluxo* de dados, no qual os componentes executam cálculos quando recebem dados. Para obter exemplos que usam funções de filtro para controlar o fluxo de dados em uma mensagem passando por uma rede, consulte [como: usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md), [Walkthrough: Criando um agente de fluxo](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)de dados, e [passo a passos: criando uma rede de processamento de imagens](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

[[Superior](#top)]

## <a name="reservation"></a>Reserva de mensagens

A *reserva de mensagens* permite que um bloco de mensagens Reserve uma mensagem para uso posterior. Normalmente, a reserva de mensagens não é usada diretamente. No entanto, compreender a reserva de mensagens pode ajudá-lo a entender melhor o comportamento de alguns dos tipos de bloco de mensagens predefinidos.

Considere junções que não são ávidos e ávidos. Ambos usam reserva de mensagem para reservar mensagens para uso posterior. Um descrito anteriormente, uma junção não-ávido recebe mensagens em duas fases. Durante a primeira fase, um objeto de `join` não-ávido aguarda que cada uma de suas fontes receba uma mensagem. Uma junção não-ávido tenta reservar cada uma dessas mensagens. Se ele puder reservar cada mensagem, ele consumirá todas as mensagens e as propagará para seu destino. Caso contrário, ele libera ou cancela, as reservas de mensagem e, novamente, aguarda cada fonte para receber uma mensagem.

Uma junção de disponibilidade, que também lê mensagens de entrada de várias fontes, usa a reserva de mensagens para ler mensagens adicionais enquanto aguarda a recepção de uma mensagem de cada fonte. Por exemplo, considere uma junção de ávido que recebe mensagens de blocos de mensagem `A` e `B`. Se a junção de ávido receber duas mensagens de B, mas ainda não tiver recebido uma mensagem de `A`, a junção de ávido salva o identificador de mensagem exclusivo da segunda mensagem de `B`. Após a junção de ávido receber uma mensagem de `A` e propagar essas mensagens, ele usará o identificador de mensagem salva para ver se a segunda mensagem do `B` ainda está disponível.

Você pode usar a reserva de mensagens ao implementar seus próprios tipos de bloco de mensagens personalizados. Para obter um exemplo de como criar um tipo de bloco de mensagens personalizado, consulte [passo a passos: Criando um bloco de mensagens personalizado](../../parallel/concrt/walkthrough-creating-a-custom-message-block.md).

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)
