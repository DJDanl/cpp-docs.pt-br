---
title: 'Instruções passo a passo: criando um bloco de mensagens personalizado'
ms.date: 04/25/2019
helpviewer_keywords:
- creating custom message blocks Concurrency Runtime]
- custom message blocks, creating [Concurrency Runtime]
ms.assetid: 4c6477ad-613c-4cac-8e94-2c9e63cd43a1
ms.openlocfilehash: f95eaf7e1da41bd473ab15d12330d0177b98ccdf
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219489"
---
# <a name="walkthrough-creating-a-custom-message-block"></a>Instruções passo a passo: criando um bloco de mensagens personalizado

Este documento descreve como criar um tipo de bloco de mensagens personalizado que ordena mensagens de entrada por prioridade.

Embora os tipos de bloco de mensagens internos forneçam uma ampla gama de funcionalidades, você pode criar seu próprio tipo de bloco de mensagens e personalizá-lo para atender aos requisitos do seu aplicativo. Para obter uma descrição dos tipos de bloco de mensagens internos fornecidos pela biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="prerequisites"></a>Pré-requisitos

Leia os seguintes documentos antes de iniciar este passo a passos:

- [Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md)

## <a name="sections"></a><a name="top"></a>As

Este passo a passo contém as seguintes seções:

- [Projetando um Bloco de Mensagem Personalizado](#design)

- [Definindo a Classe priority_buffer](#class)

- [O exemplo completo](#complete)

## <a name="designing-a-custom-message-block"></a><a name="design"></a>Criando um bloco de mensagem personalizado

Os blocos de mensagens participam do ato de enviar e receber mensagens. Um bloco de mensagens que envia mensagens é conhecido como um *bloco de origem*. Um bloco de mensagens que recebe mensagens é conhecido como um *bloco de destino*. Um bloco de mensagens que envia e recebe mensagens é conhecido como um *bloco propagador*. A biblioteca de agentes usa a classe abstrata [Concurrency:: as](../../parallel/concrt/reference/isource-class.md) para representar os blocos de origem e a classe abstrata [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md) para representar os blocos de destino. Tipos de bloco de mensagens que atuam como fontes derivam de `ISource` ; tipos de bloco de mensagens que atuam como destinos derivam de `ITarget` .

Embora você possa derivar seu tipo de bloco de mensagens diretamente de `ISource` e `ITarget` , a biblioteca de agentes define três classes base que executam grande parte da funcionalidade que é comum a todos os tipos de bloco de mensagens, por exemplo, tratamento de erros e conexão de blocos de mensagens juntos de maneira segura. A classe [Concurrency:: source_block](../../parallel/concrt/reference/source-block-class.md) deriva de `ISource` e envia mensagens para outros blocos. A classe [Concurrency:: target_block](../../parallel/concrt/reference/target-block-class.md) deriva de `ITarget` e recebe mensagens de outros blocos. A classe [Concurrency::p ropagator_block](../../parallel/concrt/reference/propagator-block-class.md) deriva de `ISource` e `ITarget` e envia mensagens para outros blocos e recebe mensagens de outros blocos. Recomendamos que você use essas três classes base para manipular detalhes da infraestrutura para que você possa se concentrar no comportamento do seu bloco de mensagens.

As `source_block` `target_block` classes, e `propagator_block` são modelos que são parametrizados em um tipo que gerencia as conexões, ou links, entre os blocos de origem e de destino e em um tipo que gerencia como as mensagens são processadas. A biblioteca de agentes define dois tipos que executam o gerenciamento de links, [Concurrency:: single_link_registry](../../parallel/concrt/reference/single-link-registry-class.md) e [concurrency:: multi_link_registry](../../parallel/concrt/reference/multi-link-registry-class.md). A `single_link_registry` classe permite que um bloco de mensagens seja vinculado a uma origem ou a um destino. A `multi_link_registry` classe permite que um bloco de mensagens seja vinculado a várias fontes ou a vários destinos. A biblioteca de agentes define uma classe que executa o gerenciamento de mensagens, [Concurrency:: ordered_message_processor](../../parallel/concrt/reference/ordered-message-processor-class.md). A `ordered_message_processor` classe permite que os blocos de mensagens processem mensagens na ordem em que são recebidas.

Para entender melhor como os blocos de mensagens se relacionam com suas origens e destinos, considere o exemplo a seguir. Este exemplo mostra a declaração da classe [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) .

[!code-cpp[concrt-priority-buffer#20](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_1.cpp)]

A `transformer` classe deriva de `propagator_block` e, portanto, atua como um bloco de origem e como um bloco de destino. Ele aceita mensagens do tipo `_Input` e envia mensagens do tipo `_Output` . A `transformer` classe especifica `single_link_registry` como o Gerenciador de links para qualquer bloco de destino e `multi_link_registry` como o Gerenciador de links para qualquer bloco de origem. Portanto, um `transformer` objeto pode ter até um destino e um número ilimitado de fontes.

Uma classe derivada de `source_block` deve implementar seis métodos: [propagate_to_any_targets](reference/source-block-class.md#propagate_to_any_targets), [accept_message](reference/source-block-class.md#accept_message), [reserve_message](reference/source-block-class.md#reserve_message), [consume_message](reference/source-block-class.md#consume_message), [release_message](reference/source-block-class.md#release_message)e [resume_propagation](reference/source-block-class.md#resume_propagation). Uma classe derivada de `target_block` deve implementar o método [propagate_message](reference/propagator-block-class.md#propagate_message) e, opcionalmente, pode implementar o método [send_message](reference/propagator-block-class.md#send_message) . Derivar de `propagator_block` é funcionalmente equivalente a derivar de `source_block` e `target_block` .

O `propagate_to_any_targets` método é chamado pelo tempo de execução para processar de forma assíncrona ou síncrona as mensagens de entrada e propagar todas as mensagens de saída. O `accept_message` método é chamado por blocos de destino para aceitar mensagens. Muitos tipos de bloco de mensagens, como `unbounded_buffer` , enviam mensagens somente para o primeiro destino que o receberia. Portanto, ele transfere a propriedade da mensagem para o destino. Outros tipos de bloco de mensagens, como [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md), oferecem mensagens a cada um de seus blocos de destino. Portanto, `overwrite_buffer` o cria uma cópia da mensagem para cada um de seus destinos.

Os `reserve_message` `consume_message` métodos,, e `release_message` `resume_propagation` permitem que os blocos de mensagens participem da reserva de mensagens. Os blocos de destino chamam o `reserve_message` método quando são oferecidos uma mensagem e precisam reservar a mensagem para uso posterior. Depois que um bloco de destino reserva uma mensagem, ele pode chamar o `consume_message` método para consumir essa mensagem ou o `release_message` método para cancelar a reserva. Assim como acontece com o `accept_message` método, a implementação do `consume_message` pode transferir a propriedade da mensagem ou retornar uma cópia da mensagem. Depois que um bloco de destino consome ou libera uma mensagem reservada, o tempo de execução chama o `resume_propagation` método. Normalmente, esse método continua a propagação de mensagens, começando com a próxima mensagem na fila.

O tempo de execução chama o `propagate_message` método para transferir de forma assíncrona uma mensagem de outro bloco para o atual. O `send_message` método é semelhante `propagate_message` , exceto que, de forma síncrona, em vez de assíncrona, envia a mensagem para os blocos de destino. A implementação padrão de `send_message` rejeita todas as mensagens de entrada. O tempo de execução não chamará nenhum desses métodos se a mensagem não passar a função de filtro opcional que está associada ao bloco de destino. Para obter mais informações sobre filtros de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

[[Superior](#top)]

## <a name="defining-the-priority_buffer-class"></a><a name="class"></a>Definindo a classe de priority_buffer

A `priority_buffer` classe é um tipo de bloco de mensagens personalizado que ordena mensagens de entrada primeiro por prioridade e, em seguida, pela ordem em que as mensagens são recebidas. A `priority_buffer` classe é semelhante à classe [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) porque contém uma fila de mensagens e também porque atua como um bloco de mensagens de origem e de destino e pode ter várias origens e vários destinos. No entanto, `unbounded_buffer` o baseia a propagação de mensagens somente na ordem em que recebe mensagens de suas fontes.

A `priority_buffer` classe recebe mensagens do tipo std::[tupla](../../standard-library/tuple-class.md) que contém `PriorityType` `Type` elementos e. `PriorityType`refere-se ao tipo que contém a prioridade de cada mensagem; `Type`refere-se à parte de dados da mensagem. A `priority_buffer` classe envia mensagens do tipo `Type` . A `priority_buffer` classe também gerencia duas filas de mensagens: um objeto [std::p riority_queue](../../standard-library/priority-queue-class.md) para mensagens de entrada e um objeto std::[Queue](../../standard-library/queue-class.md) para mensagens de saída. A ordenação de mensagens por prioridade é útil quando um `priority_buffer` objeto recebe várias mensagens simultaneamente ou recebe várias mensagens antes de qualquer mensagem ser lida pelos consumidores.

Além dos sete métodos que uma classe derivada de `propagator_block` deve implementar, a `priority_buffer` classe também substitui os `link_target_notification` `send_message` métodos e. A `priority_buffer` classe também define dois métodos auxiliares públicos, `enqueue` e `dequeue` , e um método auxiliar privado, `propagate_priority_order` .

O procedimento a seguir descreve como implementar a `priority_buffer` classe.

#### <a name="to-define-the-priority_buffer-class"></a>Para definir a classe priority_buffer

1. Crie um arquivo de cabeçalho do C++ e nomeie-o `priority_buffer.h` . Como alternativa, você pode usar um arquivo de cabeçalho existente que faz parte do seu projeto.

1. No `priority_buffer.h` , adicione o código a seguir.

    [!code-cpp[concrt-priority-buffer#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_2.h)]

1. No `std` namespace, defina especializações de [std:: less](../../standard-library/less-struct.md) e [std:: Great](../../standard-library/greater-struct.md) que agem em objetos Concurrency::[Message](../../parallel/concrt/reference/message-class.md) .

    [!code-cpp[concrt-priority-buffer#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_3.h)]

   A `priority_buffer` classe armazena `message` objetos em um `priority_queue` objeto. Essas especializações de tipo permitem que a fila de prioridade classifique mensagens de acordo com sua prioridade. A prioridade é o primeiro elemento do `tuple` objeto.

1. No `concurrencyex` namespace, declare a `priority_buffer` classe.

    [!code-cpp[concrt-priority-buffer#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_4.h)]

   A classe `priority_buffer` deriva de `propagator_block`. Portanto, ele pode enviar e receber mensagens. A `priority_buffer` classe pode ter vários destinos que recebem mensagens do tipo `Type` . Ele também pode ter várias fontes que enviam mensagens do tipo `tuple<PriorityType, Type>` .

1. Na **`private`** seção da `priority_buffer` classe, adicione as seguintes variáveis de membro.

    [!code-cpp[concrt-priority-buffer#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_5.h)]

   O `priority_queue` objeto contém mensagens de entrada; o `queue` objeto mantém mensagens de saída. Um `priority_buffer` objeto pode receber várias mensagens simultaneamente; o `critical_section` objeto sincroniza o acesso à fila de mensagens de entrada.

1. Na **`private`** seção, defina o construtor de cópia e o operador de atribuição. Isso impede que os `priority_queue` objetos sejam atribuíveis.

    [!code-cpp[concrt-priority-buffer#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_6.h)]

1. Na **`public`** seção, defina os construtores que são comuns a muitos tipos de bloco de mensagens. Defina também o destruidor.

    [!code-cpp[concrt-priority-buffer#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_7.h)]

1. Na **`public`** seção, defina os métodos `enqueue` e `dequeue` . Esses métodos auxiliares fornecem uma maneira alternativa de enviar e receber mensagens de um `priority_buffer` objeto.

    [!code-cpp[concrt-priority-buffer#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_8.h)]

1. Na **`protected`** seção, defina o `propagate_to_any_targets` método.

    [!code-cpp[concrt-priority-buffer#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_9.h)]

   O `propagate_to_any_targets` método transfere a mensagem que está na frente da fila de entrada para a fila de saída e propaga todas as mensagens na fila de saída.

1. Na **`protected`** seção, defina o `accept_message` método.

    [!code-cpp[concrt-priority-buffer#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_10.h)]

   Quando um bloco de destino chama o `accept_message` método, a `priority_buffer` classe transfere a propriedade da mensagem para o primeiro bloco de destino que o aceita. (Isso se assemelha ao comportamento de `unbounded_buffer` .)

1. Na **`protected`** seção, defina o `reserve_message` método.

    [!code-cpp[concrt-priority-buffer#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_11.h)]

   A `priority_buffer` classe permite que um bloco de destino Reserve uma mensagem quando o identificador de mensagem fornecido corresponde ao identificador da mensagem que está na frente da fila. Em outras palavras, um destino poderá reservar a mensagem se o `priority_buffer` objeto ainda não tiver recebido uma mensagem adicional e ainda não tiver propagado o mesmo.

1. Na **`protected`** seção, defina o `consume_message` método.

    [!code-cpp[concrt-priority-buffer#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_12.h)]

   Um bloco de destino chama `consume_message` para transferir a propriedade da mensagem que ele reservou.

1. Na **`protected`** seção, defina o `release_message` método.

    [!code-cpp[concrt-priority-buffer#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_13.h)]

   Um bloco de destino chama `release_message` para cancelar sua reserva para uma mensagem.

1. Na **`protected`** seção, defina o `resume_propagation` método.

    [!code-cpp[concrt-priority-buffer#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_14.h)]

   As chamadas de tempo de execução `resume_propagation` depois de um bloco de destino consomem ou liberam uma mensagem reservada. Esse método propaga todas as mensagens que estão na fila de saída.

1. Na **`protected`** seção, defina o `link_target_notification` método.

    [!code-cpp[concrt-priority-buffer#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_15.h)]

   A `_M_pReservedFor` variável de membro é definida pela classe base, `source_block` . Essa variável de membro aponta para o bloco de destino, se houver, que está mantendo uma reserva para a mensagem que está na frente da fila de saída. O tempo de execução chama `link_target_notification` quando um novo destino é vinculado ao `priority_buffer` objeto. Esse método propaga todas as mensagens que estão na fila de saída se nenhum destino estiver segurando uma reserva.

1. Na **`private`** seção, defina o `propagate_priority_order` método.

    [!code-cpp[concrt-priority-buffer#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_16.h)]

   Esse método propaga todas as mensagens da fila de saída. Cada mensagem na fila é oferecida a cada bloco de destino até que um dos blocos de destino aceite a mensagem. A `priority_buffer` classe preserva a ordem das mensagens de saída. Portanto, a primeira mensagem na fila de saída deve ser aceita por um bloco de destino antes que esse método ofereça qualquer outra mensagem aos blocos de destino.

1. Na **`protected`** seção, defina o `propagate_message` método.

    [!code-cpp[concrt-priority-buffer#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_17.h)]

   O `propagate_message` método permite que a `priority_buffer` classe atue como um receptor de mensagem ou destino. Esse método recebe a mensagem que é oferecida pelo bloco de origem fornecido e insere essa mensagem na fila de prioridade. `propagate_message`Em seguida, o método envia de forma assíncrona todas as mensagens de saída para os blocos de destino.

   O tempo de execução chama esse método quando você chama a função [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) ou quando o bloco de mensagens está conectado a outros blocos de mensagens.

1. Na **`protected`** seção, defina o `send_message` método.

    [!code-cpp[concrt-priority-buffer#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_18.h)]

   O `send_message` método é semelhante `propagate_message` . No entanto, ele envia as mensagens de saída de forma síncrona em vez de assíncrona.

   O tempo de execução chama esse método durante uma operação de envio síncrona, como quando você chama a função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) .

A `priority_buffer` classe contém sobrecargas de construtor que são típicas em muitos tipos de bloco de mensagens. Algumas sobrecargas de Construtor usam objetos [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) ou [Concurrency:: Schedule](../../parallel/concrt/reference/schedulegroup-class.md) , que permitem que o bloco de mensagens seja gerenciado por um Agendador de tarefas específico. Outras sobrecargas de Construtor tomam uma função de filtro. As funções de filtro permitem que os blocos de mensagens aceitem ou rejeitem uma mensagem com base em sua carga. Para obter mais informações sobre filtros de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md). Para obter mais informações sobre agendadores de tarefas, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

Como a `priority_buffer` classe ordena as mensagens por prioridade e, em seguida, pela ordem em que as mensagens são recebidas, essa classe é mais útil quando recebe mensagens de forma assíncrona, por exemplo, quando você chama a função [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) ou quando o bloco de mensagens está conectado a outros blocos de mensagens.

[[Superior](#top)]

## <a name="the-complete-example"></a><a name="complete"></a>O exemplo completo

O exemplo a seguir mostra a definição completa da `priority_buffer` classe.

[!code-cpp[concrt-priority-buffer#18](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_19.h)]

O exemplo a seguir executa simultaneamente uma série de `asend` operações de [simultaneidade:: Receive](reference/concurrency-namespace-functions.md#receive) em um `priority_buffer` objeto.

[!code-cpp[concrt-priority-buffer#19](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_20.cpp)]

Este exemplo produz a seguinte saída de exemplo.

```Output
36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36
24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24
12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
```

A `priority_buffer` classe ordena as mensagens primeiro por prioridade e, em seguida, pela ordem em que recebe mensagens. Neste exemplo, as mensagens com maior prioridade numérica são inseridas em direção à frente da fila.

[[Superior](#top)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole a definição da `priority_buffer` classe em um arquivo chamado `priority_buffer.h` e o programa de teste em um arquivo chamado `priority_buffer.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**cl.exe/EHsc priority_buffer. cpp**

## <a name="see-also"></a>Confira também

[Orientações Tempo de Execução de Simultaneidades](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md)
