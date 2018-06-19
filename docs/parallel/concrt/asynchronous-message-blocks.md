---
title: Blocos de mensagens assíncronos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- non-greedy join [Concurrency Runtime]
- asynchronous message blocks
- greedy join [Concurrency Runtime]
ms.assetid: 79c456c0-1692-480c-bb67-98f2434c1252
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5de4a9ed20e20c03f44f8b8d421a628f220099f7
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33695025"
---
# <a name="asynchronous-message-blocks"></a>Blocos de mensagens assíncronos

A biblioteca de agentes fornece vários tipos de bloco de mensagens que permitem que você propague mensagens entre componentes de aplicativos de uma forma thread-safe. Esses tipos de bloco de mensagens são geralmente usados com vários rotinas de transmissão de mensagens, como [concurrency::send](reference/concurrency-namespace-functions.md#send), [concurrency::asend](reference/concurrency-namespace-functions.md#asend), [concurrency::receive](reference/concurrency-namespace-functions.md#receive), e [concurrency::try_receive](reference/concurrency-namespace-functions.md#try_receive). Para obter mais informações sobre a mensagem passando rotinas que são definidas pela biblioteca de agentes, consulte [funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md).  
  
##  <a name="top"></a> Seções  
 Esse tópico contém as seguintes seções:  
  
- [Origens e destinos](#sources_and_targets)  
  
- [Propagação de mensagem](#propagation)  
  
- [Visão geral dos tipos de bloco de mensagens](#overview)  
  
- [Classe unbounded_buffer](#unbounded_buffer)  
  
- [Classe overwrite_buffer](#overwrite_buffer)  
  
- [Classe single_assignment](#single_assignment)  
  
- [Classe call](#call)  
  
- [Classe transformer](#transformer)  
  
- [Classe choice](#choice)  
  
- [Classes de junção e multitype_join](#join)  
  
- [Classe timer](#timer)  
  
- [Filtragem de mensagens](#filtering)  
  
- [Reserva de mensagem](#reservation)  
  
##  <a name="sources_and_targets"></a> Origens e destinos  
 Origens e destinos são dois participantes importantes na transmissão de mensagens. Um *fonte* refere-se a um ponto de extremidade de comunicação que envia mensagens. Um *destino* refere-se a um ponto de extremidade de comunicação que recebe mensagens. Você pode considerar uma fonte de um ponto de extremidade que ler do e um destino como um ponto de extremidade que você gravar. Aplicativos se conectam a fontes e destinos juntos ao formulário *redes de mensagens*.  
  
 A biblioteca de agentes usa duas classes abstratas para representar fontes e destinos: [concurrency::ISource](../../parallel/concrt/reference/isource-class.md) e [concurrency::ITarget](../../parallel/concrt/reference/itarget-class.md). Tipos de bloco de mensagens que agem como fontes de derivam de `ISource`; tipos de bloco de mensagens que agem como destinos derivam `ITarget`. Bloco de mensagens de tipos que agem como origens e destinos derivam `ISource` e `ITarget`.  
  
 [[Superior](#top)]  
  
##  <a name="propagation"></a> Propagação de mensagem  
 *Propagação de mensagem* é o ato de enviar uma mensagem de um componente para outro. Quando um bloco de mensagens é oferecido uma mensagem, ele pode aceitar, recusar ou adiar essa mensagem. Cada tipo de bloco de mensagens armazena e transmite mensagens de diferentes maneiras. Por exemplo, o `unbounded_buffer` classe armazena um número ilimitado de mensagens, o `overwrite_buffer` classe armazena uma única mensagem por vez, e a classe transformer armazena uma versão alterada de cada mensagem. Esses tipos de bloco de mensagens são descritos em mais detalhes posteriormente neste documento.  
  
 Quando um bloco de mensagens aceita uma mensagem, ele pode, opcionalmente, executar o trabalho e, se o protocolo SMB é uma origem, transmitir a mensagem resultante para outro membro da rede. Um bloco de mensagens pode usar uma função de filtro para recusar as mensagens que não deseja receber. Os filtros são descritos em mais detalhes posteriormente neste tópico, na seção [filtragem de mensagens](#filtering). Um bloco de mensagens que adia uma mensagem pode reservar essa mensagem e consumi-lo mais tarde. Reserva de mensagem é descrita em mais detalhes posteriormente neste tópico, na seção [mensagem reserva](#reservation).  
  
 A biblioteca de agentes permite blocos de mensagens de forma assíncrona ou síncrona passar mensagens. Ao passar uma mensagem para um bloco de mensagens de forma síncrona, por exemplo, usando o `send` função, o tempo de execução bloqueia o contexto atual até que o bloco de destino aceita ou rejeita a mensagem. Ao passar uma mensagem para um bloco de mensagens de forma assíncrona, por exemplo, usando o `asend` função, o tempo de execução oferece a mensagem para o destino, e se o destino de aceitar a mensagem, o tempo de execução agenda uma tarefa assíncrona que propaga a mensagem para o receptor. O tempo de execução usa tarefas leves para propagar as mensagens de forma cooperativa. Para obter mais informações sobre tarefas leves, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  

 Aplicativos conectam origens e destinos juntos para formar redes de mensagens. Normalmente, você vincular a rede e a chamada `send` ou `asend` para passar dados para a rede. Para se conectar a um bloco de mensagens de origem para um destino, chame o [concurrency::ISource::link_target](reference/isource-class.md#link_target) método. Para desconectar um bloco de origem de um destino, chame o [concurrency::ISource::unlink_target](reference/isource-class.md#unlink_target) método. Para desconectar um bloco de origem de todos os seus destinos, chame o [concurrency::ISource::unlink_targets](reference/isource-class.md#unlink_targets) método. Quando um dos tipos de bloco de mensagens predefinidas sai do escopo ou é destruído, ele automaticamente desconecta se qualquer bloco de destino. Alguns tipos de bloco de mensagens restringem o número máximo de destinos podem gravar em. A seção a seguir descreve as restrições que se aplicam aos tipos de bloco de mensagem predefinidos.  
  
 [[Superior](#top)]  
  
##  <a name="overview"></a> Visão geral dos tipos de bloco de mensagens  
 A tabela a seguir descreve resumidamente a função dos tipos de bloco de mensagens importantes.  
  
 [unbounded_buffer](#unbounded_buffer)  
 Armazena uma fila de mensagens.  
  
 [overwrite_buffer](#overwrite_buffer)  
 Armazena uma mensagem que pode ser gravada e lidos de várias vezes.  
  
 [single_assignment](#single_assignment)  
 Armazena uma mensagem que pode ser gravada uma vez e ler várias vezes.  
  
 [call](#call)  
 Executa o trabalho quando ele recebe uma mensagem.  
  
 [transformer](#transformer)  
 Executa o trabalho quando ele recebe dados e envia o resultado desse trabalho para outro bloco de destino. O `transformer` classe pode agir em tipos de saída e entrada diferente.  
  
 [Escolha](#choice)  
 Seleciona a primeira mensagem disponível de um conjunto de fontes.  
  
 [junção e junção múltiplo](#join)  
 Aguarde até que todas as mensagens ser recebida de um conjunto de fontes e, em seguida, combinar as mensagens em uma mensagem para outro bloco de mensagens.  
  
 [Timer](#timer)  
 Envia uma mensagem para um bloco de destino em um intervalo regular.  
  
 Esses tipos de bloco de mensagens têm diferentes características que tornam úteis em situações diferentes. Estas são algumas das características:  
  
- *Tipo de propagação*: se o bloco de mensagens atua como uma fonte de dados, um receptor de dados ou ambos.  
  
- *Classificação de mensagem*: se o bloco de mensagens mantém a ordem original na qual as mensagens são enviadas ou recebidas. Cada tipo de bloco de mensagens predefinidas mantém a ordem original em que ele envia ou recebe mensagens.  
  
- *Contagem de origem*: O número máximo de fontes que o protocolo SMB pode ler a partir de.  
  
- *Contagem de destino*: O número máximo de destinos que o protocolo SMB pode gravar.  
  
 A tabela a seguir mostra como as seguintes características se relacionam com os vários tipos de bloco de mensagens.  
  
|Tipo de mensagem de bloco|Tipo de propagação (origem, destino ou ambos)|Mensagem de pedidos (Ordered ou desordenadas)|Contagem de origem|Contagem de destino|  
|------------------------|--------------------------------------------------|-----------------------------------------------|------------------|------------------|  
|`unbounded_buffer`|Ambos|Ordenada|não vinculado|não vinculado|  
|`overwrite_buffer`|Ambos|Ordenada|não vinculado|não vinculado|  
|`single_assignment`|Ambos|Ordenada|não vinculado|não vinculado|  
|`call`|Destino|Ordenada|não vinculado|Não Aplicável|  
|`transformer`|Ambos|Ordenada|não vinculado|1|  
|`choice`|Ambos|Ordenada|10|1|  
|`join`|Ambos|Ordenada|não vinculado|1|  
|`multitype_join`|Ambos|Ordenada|10|1|  
|`timer`|Origem|Não Aplicável|Não Aplicável|1|  
  
 As seções a seguir descrevem os tipos de bloco de mensagens em mais detalhes.  
  
 [[Superior](#top)]  
  
##  <a name="unbounded_buffer"></a> Classe unbounded_buffer  
 O [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) classe representa uma estrutura de mensagens assíncrona para fins gerais. Essa classe armazena uma fila PEPS (primeiro a entrar, primeiro a sair) de mensagens que podem ser gravadas por várias origens ou lidas por vários destinos. Quando um destino recebe uma mensagem de um `unbounded_buffer` de objeto, essa mensagem é removida da fila de mensagens. Portanto, embora um `unbounded_buffer` objeto pode ter vários destinos, cada mensagem será exibida apenas um destino. A classe `unbounded_buffer` é útil quando você deseja passar várias mensagens para outro componente e esse componente deve receber cada uma das mensagens.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica de como trabalhar com o `unbounded_buffer` classe. Este exemplo envia três valores para um `unbounded_buffer` do objeto e, em seguida, lê os valores do mesmo objeto.  
  
 [!code-cpp[concrt-unbounded_buffer-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_1.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
334455  
```  
  
 Para obter um exemplo completo que mostra como usar o `unbounded_buffer` de classe, consulte [como: implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md).  
  
 [[Superior](#top)]  
  
##  <a name="overwrite_buffer"></a> Classe overwrite_buffer  
 O [concurrency::overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md) é semelhante a `unbounded_buffer` classe, exceto que um `overwrite_buffer` objeto armazena apenas uma mensagem. Além disso, quando um destino recebe uma mensagem de um `overwrite_buffer` de objeto, essa mensagem não é removida do buffer. Portanto, vários destinos recebem uma cópia da mensagem.  
  
 O `overwrite_buffer` classe é útil quando você deseja passar várias mensagens para outro componente, mas esse componente precisa apenas o valor mais recente. Essa classe também é útil quando você deseja difundir uma mensagem para vários componentes.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica de como trabalhar com o `overwrite_buffer` classe. Este exemplo envia três valores para um `overwrite _buffer` do objeto e, em seguida, lê o valor atual do mesmo objeto de três vezes. Este exemplo é semelhante ao exemplo para o `unbounded_buffer` classe. No entanto, a `overwrite_buffer` classe armazena apenas uma mensagem. Além disso, o tempo de execução não remove a mensagem de um `overwrite_buffer` depois da leitura do objeto.  
  
 [!code-cpp[concrt-overwrite_buffer-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_2.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
555555  
```  
  
 Para obter um exemplo completo que mostra como usar o `overwrite_buffer` de classe, consulte [como: implementar vários padrões de produtor-consumidor](../../parallel/concrt/how-to-implement-various-producer-consumer-patterns.md).  
  
 [[Superior](#top)]  
  
##  <a name="single_assignment"></a> Classe single_assignment  
 O [concurrency::single_assignment](../../parallel/concrt/reference/single-assignment-class.md) é semelhante a `overwrite_buffer` classe, exceto que um `single_assignment` objeto pode ser gravado apenas uma vez. Como na classe `overwrite_buffer`, quando um destino recebe uma mensagem de um objeto `single_assignment`, essa mensagem não é removida do objeto. Portanto, vários destinos recebem uma cópia da mensagem. O `single_assignment` classe é útil quando você deseja transmitir uma mensagem a vários componentes.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica de como trabalhar com o `single_assignment` classe. Este exemplo envia três valores para um `single_assignment` do objeto e, em seguida, lê o valor atual do mesmo objeto de três vezes. Este exemplo é semelhante ao exemplo para o `overwrite_buffer` classe. Embora tanto o `overwrite_buffer` e `single_assignment` classes armazenam uma única mensagem, o `single_assignment` classe pode ser gravada apenas uma vez.  
  
 [!code-cpp[concrt-single_assignment-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_3.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
333333  
```  
  
 Para obter um exemplo completo que mostra como usar o `single_assignment` de classe, consulte [passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md).  
  
 [[Superior](#top)]  
  
##  <a name="call"></a> Classe da chamada  
 O [concurrency::call](../../parallel/concrt/reference/call-class.md) classe atua como um destinatário da mensagem que executa uma função de trabalho quando ele recebe dados. Essa função de trabalho pode ser uma expressão lambda, um objeto de função ou um ponteiro de função. Um `call` objeto se comporta de forma diferente de uma chamada de função comum porque ele atua em paralelo para outros componentes que enviam mensagens a ele. Se um `call` objeto está executando um trabalho quando ele recebe uma mensagem, ele adiciona essa mensagem para uma fila. Cada `call` processos de objeto na fila de mensagens na ordem em que são recebidos.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica de como trabalhar com o `call` classe. Este exemplo cria um `call` objeto que imprime cada valor que recebe o console. O exemplo envia, em seguida, três valores para o `call` objeto. Porque o `call` objeto processa as mensagens em um thread separado, este exemplo também usa uma variável de contador e um [evento](../../parallel/concrt/reference/event-class.md) objeto para garantir que o `call` objeto processa todas as mensagens antes do `wmain` função retorna.  
  
 [!code-cpp[concrt-call-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_4.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
334455  
```  
  
 Para obter um exemplo completo que mostra como usar o `call` de classe, consulte [como: fornecer funções de trabalho para as Classes call e transformer](../../parallel/concrt/how-to-provide-work-functions-to-the-call-and-transformer-classes.md).  
  
 [[Superior](#top)]  
  
##  <a name="transformer"></a> Classe Transformer  
 O [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) classe atua como ambos um destinatário da mensagem e como um remetente da mensagem. O `transformer` é semelhante a `call` porque ele executa uma função de trabalho definida pelo usuário quando ele recebe dados de classe. No entanto, a `transformer` classe também envia o resultado da função de trabalho para objetos de destinatário. Como um `call` objeto, um `transformer` objeto atua em paralelo para outros componentes que enviam mensagens a ele. Se um `transformer` objeto está executando um trabalho quando ele recebe uma mensagem, ele adiciona essa mensagem para uma fila. Cada `transformer` objeto processar suas mensagens em fila na ordem em que são recebidos.  
  
 O `transformer` classe envia a mensagem para um destino. Se você definir o `_PTarget` parâmetro no construtor para `NULL`, mais tarde você pode especificar o destino chamando o [concurrency::link_target](reference/source-block-class.md#link_target) método.  
  
 Ao contrário de todos os outros tipos de bloco de mensagens assíncronas que são fornecidos pela biblioteca de agentes, a `transformer` classe pode agir em tipos de saída e entrada diferente. Essa capacidade de transformar dados de um tipo para outro torna o `transformer` classe um componente fundamental em várias redes simultâneos. Além disso, você pode adicionar mais funcionalidade paralela refinada na função de trabalho de um `transformer` objeto.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica de como trabalhar com o `transformer` classe. Este exemplo cria um `transformer` que múltiplos cada entrada de objeto `int` valor 0,33 para produzir um `double` valor como saída. O exemplo então recebe os valores transformados da mesma `transformer` do objeto e imprime no console.  
  
 [!code-cpp[concrt-transformer-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_5.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
10.8914.5218.15  
```  
  
 Para obter um exemplo completo que mostra como usar o `transformer` de classe, consulte [como: usar transformador em um Pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md).  
  
 [[Superior](#top)]  
  
##  <a name="choice"></a> Classe Choice  
 O [concurrency::choice](../../parallel/concrt/reference/choice-class.md) classe seleciona a primeira mensagem disponível de um conjunto de fontes. O `choice` classe representa um mecanismo de fluxo de controle, em vez de um mecanismo de fluxo de dados (o tópico [biblioteca de agentes assíncrona](../../parallel/concrt/asynchronous-agents-library.md) descreve as diferenças entre fluxos de controle e fluxo de dados).  
  
 Leitura de um objeto de opção é semelhante a chamar a função de API do Windows `WaitForMultipleObjects` quando ele tem o `bWaitAll` parâmetro definido como `FALSE`. No entanto, a `choice` classe associa dados para o evento em si, em vez de um objeto de sincronização externo.  
  

 Normalmente, você usa o `choice` classe junto com o [concurrency::receive](reference/concurrency-namespace-functions.md#receive) função para impulsionar o fluxo de controle em seu aplicativo. Use o `choice` classe quando você precisa selecionar entre os buffers de mensagens que têm tipos diferentes. Use o `single_assignment` classe quando você precisa selecionar entre os buffers de mensagens que têm o mesmo tipo.  

  
 A ordem na qual você vincula fontes para um `choice` objeto é importante porque ele pode determinar qual mensagem está selecionada. Por exemplo, considere o caso em que você pode vincular vários buffers de mensagens que já contêm uma mensagem para um `choice` objeto. O `choice` objeto seleciona a mensagem da primeira fonte que é vinculado. Depois de vincular todas as fontes, o `choice` objeto preserva a ordem em que cada fonte recebe uma mensagem.  
  
### <a name="example"></a>Exemplo  

 O exemplo a seguir mostra a estrutura básica de como trabalhar com o `choice` classe. Este exemplo usa o [concurrency::make_choice](reference/concurrency-namespace-functions.md#make_choice) função para criar um `choice` objeto seleciona entre três blocos de mensagem. O exemplo, em seguida, calcula vários números de Fibonacci e armazena os resultados em um bloco de mensagens diferentes. O exemplo, em seguida, imprime no console uma mensagem que se baseia a operação concluída pela primeira vez.  

  
 [!code-cpp[concrt-choice-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_6.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir:  
  
```Output  
fib35 received its value first. Result = 9227465  
```  
  
 Porque a tarefa que calcula a 35<sup>th</sup> Fibonacci número não é garantia de ser concluído primeiro, a saída deste exemplo pode variar.  
  

 Este exemplo usa o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para calcular os números Fibonacci em paralelo. Para obter mais informações sobre `parallel_invoke`, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
 Para obter um exemplo completo que mostra como usar o `choice` de classe, consulte [como: selecionar entre tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md).  
  
 [[Superior](#top)]  
  
##  <a name="join"></a> Classes de junção e multitype_join  
 O [concurrency::join](../../parallel/concrt/reference/join-class.md) e [concurrency::multitype_join](../../parallel/concrt/reference/multitype-join-class.md) classes permitem que você aguarde para cada membro de um conjunto de fontes receber uma mensagem. O `join` classe atua em objetos de origem que têm um tipo de mensagem comum. O `multitype_join` classe atua em objetos de fonte que podem ter diferentes tipos de mensagens.  
  
 Lendo de um `join` ou `multitype_join` objeto é semelhante a chamar a função de API do Windows `WaitForMultipleObjects` quando ele tem o `bWaitAll` parâmetro definido como `TRUE`. No entanto, assim como um `choice` objeto, `join` e `multitype_join` objetos usam um mecanismo de evento que associa dados para o evento em si, em vez de um objeto de sincronização externo.  
  
 Lendo de um `join` objeto produz um std::[vetor](../../standard-library/vector-class.md) objeto. Lendo de um `multitype_join` objeto produz um std::[tupla](../../standard-library/tuple-class.md) objeto. Elementos aparecem nesses objetos na mesma ordem conforme seus buffers de origem correspondentes são vinculados para o `join` ou `multitype_join` objeto. Porque a ordem na qual você vincula fonte armazena em buffer para um `join` ou `multitype_join` objeto é associado com a ordem dos elementos no resultante `vector` ou `tuple` do objeto, é recomendável que você não desvincular um buffer de origem existente de um junção. Isso pode resultar em comportamento não especificado.  
  
### <a name="greedy-versus-non-greedy-joins"></a>Junções Greedy Contra Não Greedy  
 O `join` e `multitype_join` classes de suporte ao conceito de junções não greedy e greedy. Um *junção greedy* aceita uma mensagem de cada uma das suas fontes, como mensagens se tornar disponíveis até que todas as mensagens estão disponíveis. Um *junção não greedy* recebe mensagens em duas fases. Primeiro, uma junção não greedy aguarda até que ela é oferecida uma mensagem de cada uma das suas fontes. Em seguida, depois que todas as mensagens de origem estão disponíveis, uma junção não greedy tenta reservar cada uma dessas mensagens. Se ele pode reservar cada mensagem, ele consome todas as mensagens e os propaga para seu destino. Caso contrário, ele libera, ou cancela, as reservas de mensagem e aguarda novamente para cada fonte receber uma mensagem.  
  
 Junções greedy executam melhor junções não greedy porque eles aceitam mensagens imediatamente. No entanto, em casos raros, junções greedy podem levar a deadlocks. Use uma junção não greedy quando você tiver várias junções que contêm um ou mais objetos de origem compartilhada.  
  
### <a name="example"></a>Exemplo  

 O exemplo a seguir mostra a estrutura básica de como trabalhar com o `join` classe. Este exemplo usa o [concurrency::make_join](reference/concurrency-namespace-functions.md#make_join) função para criar um `join` objeto que recebe de três `single_assignment` objetos. Este exemplo calcula vários números de Fibonacci, armazena os resultados em um local diferente `single_assignment` objeto e, em seguida, imprime no console de resultados que o `join` mantém do objeto. Este exemplo é semelhante ao exemplo para o `choice` classe, exceto que o `join` classe aguarda até que todos os blocos de mensagem de origem receber uma mensagem.  
  
 [!code-cpp[concrt-join-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_7.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
fib35 = 9227465fib37 = 24157817half_of_fib42 = 1.33957e+008  
```  

 Este exemplo usa o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para calcular os números Fibonacci em paralelo. Para obter mais informações sobre `parallel_invoke`, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
 Para concluir exemplos que mostram como usar o `join` de classe, consulte [como: selecionar entre tarefas concluídas](../../parallel/concrt/how-to-select-among-completed-tasks.md) e [passo a passo: usando join para evitar Deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).  
  
 [[Superior](#top)]  
  
##  <a name="timer"></a> Classe Timer  
 A simultaneidade::[classe timer](../../parallel/concrt/reference/timer-class.md) atua como uma origem de mensagem. Um `timer` objeto envia uma mensagem para um destino após um período de tempo especificado tiver decorrido. O `timer` classe é útil quando você deve adiar envio de uma mensagem ou você deseja enviar uma mensagem em intervalos regulares.  
  

 O `timer` classe envia a mensagem para apenas um destino. Se você definir o `_PTarget` parâmetro no construtor para `NULL`, mais tarde você pode especificar o destino chamando o [concurrency::ISource::link_target](reference/source-block-class.md#link_target) método.  

  
 Um `timer` objeto pode ser de repetição ou não repetitivo. Para criar um timer de repetição, passe `true` para o `_Repeating` parâmetro ao chamar o construtor. Caso contrário, passe `false` para o `_Repeating` parâmetro para criar um timer de não repetição. Se o timer está repetindo, ele envia a mesma mensagem ao destino após cada intervalo.  
  
 Cria a biblioteca de agentes `timer` objetos no estado não iniciado. Para iniciar um objeto de timer, chame o [concurrency::timer::start](reference/timer-class.md#start) método. Para interromper um `timer` de objeto, destruir o objeto ou a chamada a [concurrency::timer::stop](reference/timer-class.md#stop) método. Para pausar um timer de repetição, chame o [concurrency::timer::pause](reference/timer-class.md#pause) método.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica de como trabalhar com o `timer` classe. O exemplo usa `timer` e `call` objetos para relatar o progresso de uma operação demorada.  
  
 [!code-cpp[concrt-timer-structure#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_8.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir:  
  
```Output  
Computing fib(42)..................................................result is 267914296  
```  
  
 Para obter um exemplo completo que mostra como usar o `timer` de classe, consulte [como: enviar uma mensagem em um intervalo Regular](../../parallel/concrt/how-to-send-a-message-at-a-regular-interval.md).  
  
 [[Superior](#top)]  
  
##  <a name="filtering"></a> Filtragem de mensagens  
 Quando você cria um objeto de bloqueio de mensagem, você pode fornecer um *função filter* que determina se o protocolo SMB aceita ou rejeita uma mensagem. Uma função de filtro é uma maneira útil para garantir que um bloco de mensagem recebe somente determinados valores.  
  
 O exemplo a seguir mostra como criar um `unbounded_buffer` objeto que usa uma função de filtro para aceitar apenas os números pares. O `unbounded_buffer` objeto rejeita números ímpares e, portanto, não se propaga números ímpares para seus blocos de destino.  
  
 [!code-cpp[concrt-filter-function#1](../../parallel/concrt/codesnippet/cpp/asynchronous-message-blocks_9.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
0 2 4 6 8  
```  
  
 Uma função de filtro pode ser uma função lambda, um ponteiro de função ou um objeto de função. Cada função de filtro usa uma das formas a seguir.  
  
```Output  
bool (T)  
bool (T const &)  
```  
  
 Para eliminar o desnecessária cópia de dados, use o segundo formulário quando você tem um tipo de agregação que é propagado por valor.  
  
 Mensagem filtragem oferece suporte a *fluxo de dados* modelo de programação, no qual componentes executam cálculos ao receber dados. Para obter exemplos que usam funções de filtro para controlar o fluxo de dados em uma rede de transmissão de mensagem, consulte [como: usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md), [passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md), e [ Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).  
  
 [[Superior](#top)]  
  
##  <a name="reservation"></a> Reserva de mensagem  
 *Reserva de mensagem* permite que um bloco de mensagens reservar uma mensagem para uso posterior. Normalmente, a reserva de mensagem não é usada diretamente. No entanto, mensagem de Noções básicas sobre reserva pode ajudá-lo a melhor entender o comportamento de alguns dos tipos de bloco de mensagens predefinidas.  
  
 Considere a possibilidade de junções não greedy e greedy. Ambos usam reserva de mensagem para reservar as mensagens para uso posterior. Um descrito anteriormente, uma junção não greedy recebe mensagens em duas fases. Durante a primeira fase, um não greedy `join` objeto aguarda para cada uma das suas fontes para receber uma mensagem. Uma junção não greedy, em seguida, tenta reservar cada uma dessas mensagens. Se ele pode reservar cada mensagem, ele consome todas as mensagens e os propaga para seu destino. Caso contrário, ele libera, ou cancela, as reservas de mensagem e aguarda novamente para cada fonte receber uma mensagem.  
  
 Uma junção greedy, que também lê mensagens de entrada de um número de fontes, usa a reserva de mensagem para ler mensagens adicionais enquanto ele espera para receber uma mensagem de cada fonte. Por exemplo, considere uma junção greedy que recebe mensagens do protocolo SMB `A` e `B`. Se a junção greedy recebe duas mensagens de B, mas ainda não recebeu uma mensagem de `A`, a junção greedy salva o identificador exclusivo de mensagem para a segunda mensagem de `B`. Depois que a junção greedy recebe uma mensagem de `A` e propaga essas mensagens, ele usa o identificador da mensagem salva para ver se a segunda mensagem de `B` ainda está disponível.  
  
 Você pode usar a reserva de mensagem quando você implementar seus próprios tipos de bloco da mensagem personalizada. Para obter um exemplo sobre como criar um tipo de bloco de mensagens personalizadas, consulte [passo a passo: Criando um bloco de mensagens personalizadas](../../parallel/concrt/walkthrough-creating-a-custom-message-block.md).  
  
 [[Superior](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)

