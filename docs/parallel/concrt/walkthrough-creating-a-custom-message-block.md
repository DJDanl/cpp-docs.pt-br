---
title: 'Passo a passo: Criar um bloco de mensagem personalizada'
ms.date: 11/04/2016
helpviewer_keywords:
- creating custom message blocks Concurrency Runtime]
- custom message blocks, creating [Concurrency Runtime]
ms.assetid: 4c6477ad-613c-4cac-8e94-2c9e63cd43a1
ms.openlocfilehash: e897163a1d394228ac1d8f566e4b0d761fbeeb42
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57272731"
---
# <a name="walkthrough-creating-a-custom-message-block"></a>Passo a passo: Criar um bloco de mensagem personalizada

Este documento descreve como criar um tipo de bloco de mensagem personalizado que ordena as mensagens de entrada por prioridade.

Embora os tipos de bloco de mensagem incorporada fornecem um intervalo de toda a funcionalidade, você pode criar seu próprio tipo de bloco de mensagem e personalizá-lo para atender aos requisitos do seu aplicativo. Para obter uma descrição dos tipos de bloco interno de mensagens que são fornecidos pela biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="prerequisites"></a>Pré-requisitos

Leia os documentos a seguir antes de começar este passo a passo:

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

##  <a name="top"></a> Seções

Este passo a passo contém as seguintes seções:

- [Criando um bloco de mensagem personalizado](#design)

- [Definindo a classe priority_buffer](#class)

- [O exemplo completo](#complete)

##  <a name="design"></a> Criando um bloco de mensagem personalizado

Blocos de mensagem participam o ato de enviar e receber mensagens. Um bloco de mensagem que envia mensagens é conhecido como um *bloco de origem*. Um bloco de mensagens que recebe mensagens é conhecido como um *bloco de destino*. Um bloco de mensagem que envia e recebe mensagens é conhecido como um *bloco propagador*. A biblioteca de agentes usa a classe abstrata [Concurrency:: ISource](../../parallel/concrt/reference/isource-class.md) para representar blocos de origem e a classe abstrata [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md) para representar blocos de destino. Tipos de bloco de mensagem que atuam como fontes derivam de `ISource`; tipos de bloco de mensagem que atuam como destinos derivam de `ITarget`.

Embora você possa derivar seu tipo de bloco de mensagem diretamente a partir `ISource` e `ITarget`, a biblioteca de agentes define três classes base que executam grande parte da funcionalidade que é comum a todos os tipos de bloco de mensagem, por exemplo, tratamento de erros e conectar blocos de mensagem juntos de maneira segura de simultaneidade. O [Concurrency:: source_block](../../parallel/concrt/reference/source-block-class.md) classe deriva de `ISource` e envia mensagens para outros blocos. O [Concurrency:: target_block](../../parallel/concrt/reference/target-block-class.md) classe deriva de `ITarget` e recebe mensagens de outros blocos. O [Concurrency:: propagator_block](../../parallel/concrt/reference/propagator-block-class.md) classe deriva `ISource` e `ITarget` e envia mensagens para outros blocos e ele recebe mensagens de outros blocos. É recomendável que você use essas três classes base para lidar com os detalhes da infraestrutura para que você possa se concentrar no comportamento do seu bloco de mensagem.

O `source_block`, `target_block`, e `propagator_block` classes são modelos que são parametrizados em um tipo que gerencia as conexões ou links entre os blocos de origem e de destino e em um tipo que gerencia como as mensagens são processadas. A biblioteca de agentes define dois tipos que executam o gerenciamento de link [Concurrency:: single_link_registry](../../parallel/concrt/reference/single-link-registry-class.md) e [Concurrency:: multi_link_registry](../../parallel/concrt/reference/multi-link-registry-class.md). O `single_link_registry` classe permite que um bloco de mensagem a ser vinculado a uma origem ou para um destino. O `multi_link_registry` classe permite que um bloco de mensagem a ser vinculado às várias origens ou vários destinos. A biblioteca de agentes define uma classe que realiza o gerenciamento de mensagem [Concurrency:: ordered_message_processor](../../parallel/concrt/reference/ordered-message-processor-class.md). O `ordered_message_processor` classe permite que os blocos de mensagem processar mensagens na ordem em que ele recebe.

Para entender melhor como os blocos de mensagem se relacionam às origens e destinos, considere o exemplo a seguir. Este exemplo mostra a declaração do [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) classe.

[!code-cpp[concrt-priority-buffer#20](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_1.cpp)]

O `transformer` deriva de classe `propagator_block`e, portanto, atua como um bloco de origem e um bloco de destino. Ele aceita mensagens do tipo `_Input` e envia mensagens do tipo `_Output`. O `transformer` classe especifica `single_link_registry` como o Gerenciador de link para os blocos de destino e `multi_link_registry` como o Gerenciador de link para os blocos de código-fonte. Portanto, um `transformer` objeto pode ter até um destino e um número ilimitado de fontes.

Uma classe que deriva de `source_block` deve implementar seis métodos: [propagate_to_any_targets](reference/source-block-class.md#propagate_to_any_targets), [accept_message](reference/source-block-class.md#accept_message), [reserve_message](reference/source-block-class.md#reserve_message), [ consume_message](reference/source-block-class.md#consume_message), [release_message](reference/source-block-class.md#release_message), e [resume_propagation](reference/source-block-class.md#resume_propagation). Uma classe que deriva de `target_block` deve implementar a [propagate_message](reference/propagator-block-class.md#propagate_message) método e pode, opcionalmente, implemente o [send_message](reference/propagator-block-class.md#send_message) método. Derivando de `propagator_block` é funcionalmente equivalente à derivação de `source_block` e `target_block`.

O `propagate_to_any_targets` método é chamado pelo tempo de execução de forma assíncrona ou síncrona processar quaisquer mensagens de entrada e propagar qualquer mensagem de saída. O `accept_message` método é chamado por blocos de destino para aceitar mensagens. Muitos tipos de bloco de mensagem, como `unbounded_buffer`, enviam mensagens somente para o primeiro destino que recebe o serviço. Portanto, ele transfere a propriedade da mensagem ao destino. Bloco de mensagens de outros tipos, como [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md), oferecem mensagens a cada um dos seus blocos de destino. Portanto, `overwrite_buffer` cria uma cópia da mensagem para cada um dos seus destinos.

O `reserve_message`, `consume_message`, `release_message`, e `resume_propagation` métodos permitem que blocos de mensagem participem de reserva de mensagem. Blocos de destino chamam o `reserve_message` método quando eles são oferecidos a uma mensagem e precisam reservar a mensagem para uso posterior. Depois que um bloco de destino reserva uma mensagem, ele pode chamar o `consume_message` método para consumir aquela mensagem ou o `release_message` método cancelar a reserva. Assim como acontece com o `accept_message` método, a implementação de `consume_message` pode transferir a propriedade da mensagem ou retornar uma cópia da mensagem. Depois que um bloco de destino consome ou libera uma mensagem reservada, o tempo de execução chama o `resume_propagation` método. Normalmente, esse método continua a propagação da mensagem, começando com a próxima mensagem na fila.

A tempo de execução chama o `propagate_message` método para transferir de forma assíncrona uma mensagem de outro bloco para a atual. O `send_message` é semelhante ao método `propagate_message`, exceto que ele de forma síncrona, em vez de forma assíncrona, envia a mensagem aos blocos de destino. A implementação padrão de `send_message` rejeita todas as mensagens recebidas. O tempo de execução não chamará nenhum desses métodos se a mensagem não passar a função de filtro opcional que está associada com o bloco de destino. Para obter mais informações sobre filtros de mensagem, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

[[Top](#top)]

##  <a name="class"></a> Definindo a classe priority_buffer

O `priority_buffer` classe é um tipo de bloco de mensagem personalizado que ordena as mensagens de entrada primeiro por prioridade e, em seguida, pela ordem na qual as mensagens são recebidas. O `priority_buffer` é semelhante a [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) pois contém uma fila de mensagens e também porque atua como uma origem e um bloco de mensagem de destino e pode ter várias fontes e vários destinos. No entanto, `unbounded_buffer` bases da propagação somente na ordem em que ele recebe mensagens de suas fontes de mensagem.

O `priority_buffer` classe recebe mensagens do tipo std::[tupla](../../standard-library/tuple-class.md) que contêm `PriorityType` e `Type` elementos. `PriorityType` refere-se para o tipo que contém a prioridade de cada mensagem; `Type` refere-se para a parte de dados da mensagem. O `priority_buffer` classe envia mensagens do tipo `Type`. O `priority_buffer` classe também gerencia duas filas de mensagens: um [std:: priority_queue](../../standard-library/priority-queue-class.md) objeto mensagens de entrada e um std::[fila](../../standard-library/queue-class.md) objeto para mensagens de saída. Ordenar mensagens por prioridade é útil quando um `priority_buffer` objeto recebe várias mensagens simultaneamente ou quando ele recebe várias mensagens antes delas serem lidas pelos consumidores.

Além dos sete métodos que uma classe que deriva de `propagator_block` deve implementar, o `priority_buffer` classe também substitui o `link_target_notification` e `send_message` métodos. O `priority_buffer` classe também define dois métodos auxiliares públicos, `enqueue` e `dequeue`e um método auxiliar particular, `propagate_priority_order`.

O procedimento a seguir descreve como implementar o `priority_buffer` classe.

#### <a name="to-define-the-prioritybuffer-class"></a>Para definir a classe priority_buffer

1. Crie um arquivo de cabeçalho do C++ e nomeie- `priority_buffer.h`. Como alternativa, você pode usar um arquivo de cabeçalho existente que faz parte do seu projeto.

1. No `priority_buffer.h`, adicione o seguinte código.

[!code-cpp[concrt-priority-buffer#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_2.h)]

1. No `std` namespace, defina as especializações de [std:: Less](../../standard-library/less-struct.md) e [std:: greater](../../standard-library/greater-struct.md) que atuam em simultaneidade::[mensagem](../../parallel/concrt/reference/message-class.md) objetos.

[!code-cpp[concrt-priority-buffer#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_3.h)]

   O `priority_buffer` classe armazenamentos `message` objetos em um `priority_queue` objeto. Essas especializações de tipo permitem que a fila de prioridade classifique mensagens de acordo com a prioridade. A prioridade é o primeiro elemento do `tuple` objeto.

1. No `concurrencyex` namespace, declare o `priority_buffer` classe.

[!code-cpp[concrt-priority-buffer#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_4.h)]

   O `priority_buffer` classe deriva de `propagator_block`. Portanto, ele pode tanto enviar e receber mensagens. O `priority_buffer` classe pode ter vários destinos que recebem mensagens do tipo `Type`. Ele também pode ter várias fontes que enviam mensagens do tipo `tuple<PriorityType, Type>`.

1. No `private` seção o `priority_buffer` de classe, adicione as seguintes variáveis de membro.

[!code-cpp[concrt-priority-buffer#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_5.h)]

   O `priority_queue` objeto contém mensagens de entrada; o `queue` objeto contém mensagens de saída. Um `priority_buffer` objeto pode receber várias mensagens simultaneamente; o `critical_section` objeto sincroniza o acesso à fila de mensagens de entrada.

1. No `private` seção, defina o construtor de cópia e o operador de atribuição. Isso impede que `priority_queue` objetos sejam atribuíveis.

[!code-cpp[concrt-priority-buffer#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_6.h)]

1. No `public` seção, defina os construtores que são comuns a muitos tipos de bloco de mensagem. Também define o destruidor.

[!code-cpp[concrt-priority-buffer#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_7.h)]

1. No `public` seção, defina os métodos `enqueue` e `dequeue`. Esses métodos auxiliares fornecem uma maneira alternativa para enviar e receber mensagens de um `priority_buffer` objeto.

[!code-cpp[concrt-priority-buffer#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_8.h)]

9. No `protected` seção, defina o `propagate_to_any_targets` método.

[!code-cpp[concrt-priority-buffer#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_9.h)]

   O `propagate_to_any_targets` método transfere a mensagem que está à frente da fila de entrada para a fila de saída e propaga todas as mensagens na fila de saída.

10. No `protected` seção, defina o `accept_message` método.

[!code-cpp[concrt-priority-buffer#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_10.h)]

   Quando um bloco de destino chama o `accept_message` método, o `priority_buffer` classe transfere a propriedade da mensagem para o primeiro bloco de destino que aceita a ele. (Isso se parece com o comportamento de `unbounded_buffer`.)

11. No `protected` seção, defina o `reserve_message` método.

[!code-cpp[concrt-priority-buffer#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_11.h)]

   O `priority_buffer` classe permite que um bloco de destino Reserve uma mensagem quando o identificador da mensagem fornecido corresponde ao identificador da mensagem que está no início da fila. Em outras palavras, um destino pode reservar a mensagem se o `priority_buffer` objeto ainda não recebeu uma mensagem adicional e ainda não tiver propagado à atual.

12. No `protected` seção, defina o `consume_message` método.

[!code-cpp[concrt-priority-buffer#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_12.h)]

   Um bloco de destino chama `consume_message` para transferir a propriedade da mensagem que ele reservou.

13. No `protected` seção, defina o `release_message` método.

[!code-cpp[concrt-priority-buffer#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_13.h)]

   Um bloco de destino chama `release_message` para cancelar sua reserva para uma mensagem.

14. No `protected` seção, defina o `resume_propagation` método.

[!code-cpp[concrt-priority-buffer#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_14.h)]

   A tempo de execução chama `resume_propagation` depois que um bloco de destino consome ou libera uma mensagem reservada. Esse método propaga todas as mensagens que estão na fila de saída.

15. No `protected` seção, defina o `link_target_notification` método.

[!code-cpp[concrt-priority-buffer#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_15.h)]

   O `_M_pReservedFor` variável de membro é definido pela classe base, `source_block`. Essa variável de membro aponta para o bloco de destino, se houver, que está mantendo uma reserva para a mensagem que está à frente da fila de saída. A tempo de execução chama `link_target_notification` quando um novo destino está vinculado ao `priority_buffer` objeto. Esse método propaga todas as mensagens que estão na fila de saída se nenhum destino estiver mantendo uma reserva.

16. No `private` seção, defina o `propagate_priority_order` método.

[!code-cpp[concrt-priority-buffer#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_16.h)]

   Esse método propaga todas as mensagens da fila de saída. Todas as mensagens na fila é oferecida para cada bloco de destino até que um dos blocos de destino aceita a mensagem. O `priority_buffer` classe preserva a ordem das mensagens de saída. Portanto, a primeira mensagem na fila de saída deve ser aceitos por um bloco de destino antes desse método ofereça qualquer outra mensagem aos blocos de destino.

17. No `protected` seção, defina o `propagate_message` método.

[!code-cpp[concrt-priority-buffer#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_17.h)]

   O `propagate_message` método habilita o `priority_buffer` de classe para atuar como um destinatário da mensagem ou de destino. Esse método recebe a mensagem que é oferecida pelo bloco de origem fornecido e insere essa mensagem na fila de prioridade. O `propagate_message` método, em seguida, envia de forma assíncrona todas as mensagens de saída aos blocos de destino.

   O tempo de execução chama esse método quando você chama o [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) função ou quando o bloco de mensagens está conectado a outros blocos de mensagem.

18. No `protected` seção, defina o `send_message` método.

[!code-cpp[concrt-priority-buffer#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_18.h)]

   O `send_message` é semelhante ao método `propagate_message`. No entanto, ele envia mensagens de saída de forma síncrona em vez de forma assíncrona.

   O tempo de execução chama esse método durante uma operação de envio síncrona, como quando você chama o [Concurrency:: Send](reference/concurrency-namespace-functions.md#send) função.

O `priority_buffer` classe contém sobrecargas de construtor que são comuns em muitos tipos de bloco de mensagem. Algumas sobrecargas do construtor take [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) ou [Concurrency:: schedulegroup](../../parallel/concrt/reference/schedulegroup-class.md) objetos, que permitem que o bloco de mensagens a serem gerenciados por um agendador de tarefas específica. Outras sobrecargas do construtor têm uma função de filtro. Funções de filtro permitem que blocos de mensagem aceitar ou rejeitar uma mensagem com base em sua carga. Para obter mais informações sobre filtros de mensagem, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md). Para obter mais informações sobre os agendadores de tarefa, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

Porque o `priority_buffer` classe ordena as mensagens por prioridade e, em seguida, pela ordem na qual as mensagens são recebidas, essa classe é mais útil quando recebe mensagens de forma assíncrona, por exemplo, quando você chama o [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend)função ou quando o bloco de mensagens está conectado a outros blocos de mensagem.

[[Top](#top)]

##  <a name="complete"></a> O exemplo completo

O exemplo a seguir mostra a definição completa da `priority_buffer` classe.

[!code-cpp[concrt-priority-buffer#18](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_19.h)]

O exemplo a seguir executa simultaneamente várias `asend` e [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) operações em um `priority_buffer` objeto.

[!code-cpp[concrt-priority-buffer#19](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_20.cpp)]

Este exemplo produz a saída de exemplo a seguir.

```Output
36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36
24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24
12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
```

O `priority_buffer` classe ordena as mensagens primeiro por prioridade e, em seguida, pela ordem em que ele recebe mensagens. Neste exemplo, as mensagens com maior prioridade numérica são inseridas à frente da fila.

[[Top](#top)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colar a definição do `priority_buffer` classe em um arquivo chamado `priority_buffer.h` e o programa de teste em um arquivo chamado `priority_buffer.cpp` e, em seguida, execute o seguinte comando em um Visual Studio Janela de Prompt de comando.

**cl.exe /EHsc priority_buffer. cpp**

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
