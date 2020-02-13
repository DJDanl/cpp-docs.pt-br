---
title: 'Instruções passo a passo: criando um bloco de mensagens personalizado'
ms.date: 04/25/2019
helpviewer_keywords:
- creating custom message blocks Concurrency Runtime]
- custom message blocks, creating [Concurrency Runtime]
ms.assetid: 4c6477ad-613c-4cac-8e94-2c9e63cd43a1
ms.openlocfilehash: a29ed382d67b91443bd13e029af2a37c42ee834d
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142822"
---
# <a name="walkthrough-creating-a-custom-message-block"></a>Instruções passo a passo: criando um bloco de mensagens personalizado

Este documento descreve como criar um tipo de bloco de mensagens personalizado que ordena mensagens de entrada por prioridade.

Embora os tipos de bloco de mensagens internos forneçam uma ampla gama de funcionalidades, você pode criar seu próprio tipo de bloco de mensagens e personalizá-lo para atender aos requisitos do seu aplicativo. Para obter uma descrição dos tipos de bloco de mensagens internos fornecidos pela biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

Leia os seguintes documentos antes de iniciar este passo a passos:

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

## <a name="top"></a>As

Este passo a passo contém as seguintes seções:

- [Criando um bloco de mensagem personalizado](#design)

- [Definindo a classe de priority_buffer](#class)

- [O exemplo completo](#complete)

## <a name="design"></a>Criando um bloco de mensagem personalizado

Os blocos de mensagens participam do ato de enviar e receber mensagens. Um bloco de mensagens que envia mensagens é conhecido como um *bloco de origem*. Um bloco de mensagens que recebe mensagens é conhecido como um *bloco de destino*. Um bloco de mensagens que envia e recebe mensagens é conhecido como um *bloco propagador*. A biblioteca de agentes usa a classe abstrata [Concurrency:: as](../../parallel/concrt/reference/isource-class.md) para representar os blocos de origem e a classe abstrata [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md) para representar os blocos de destino. Tipos de bloco de mensagens que atuam como fontes derivam de `ISource`; tipos de bloco de mensagens que atuam como destinos derivam de `ITarget`.

Embora você possa derivar seu tipo de bloco de mensagens diretamente de `ISource` e `ITarget`, a biblioteca de agentes define três classes base que executam grande parte da funcionalidade que é comum a todos os tipos de bloco de mensagens, por exemplo, tratamento de erros e conexão de blocos de mensagens juntos de maneira segura e em simultaneidade. A classe [Concurrency:: source_block](../../parallel/concrt/reference/source-block-class.md) deriva de `ISource` e envia mensagens para outros blocos. A classe [Concurrency:: target_block](../../parallel/concrt/reference/target-block-class.md) deriva de `ITarget` e recebe mensagens de outros blocos. A classe [Concurrency::p ropagator_block](../../parallel/concrt/reference/propagator-block-class.md) deriva de `ISource` e `ITarget` e envia mensagens a outros blocos e recebe mensagens de outros blocos. Recomendamos que você use essas três classes base para manipular detalhes da infraestrutura para que você possa se concentrar no comportamento do seu bloco de mensagens.

As classes `source_block`, `target_block`e `propagator_block` são modelos que são parametrizados em um tipo que gerencia as conexões, ou links, entre os blocos de origem e de destino e em um tipo que gerencia como as mensagens são processadas. A biblioteca de agentes define dois tipos que executam o gerenciamento de links, [Concurrency:: single_link_registry](../../parallel/concrt/reference/single-link-registry-class.md) e [concurrency:: multi_link_registry](../../parallel/concrt/reference/multi-link-registry-class.md). A classe `single_link_registry` permite que um bloco de mensagem seja vinculado a uma origem ou a um destino. A classe `multi_link_registry` permite que um bloco de mensagens seja vinculado a várias fontes ou a vários destinos. A biblioteca de agentes define uma classe que executa o gerenciamento de mensagens, [Concurrency:: ordered_message_processor](../../parallel/concrt/reference/ordered-message-processor-class.md). A classe `ordered_message_processor` permite que os blocos de mensagens processem as mensagens na ordem em que são recebidas.

Para entender melhor como os blocos de mensagens se relacionam com suas origens e destinos, considere o exemplo a seguir. Este exemplo mostra a declaração da classe [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) .

[!code-cpp[concrt-priority-buffer#20](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_1.cpp)]

A classe `transformer` deriva de `propagator_block`e, portanto, atua como um bloco de origem e como um bloco de destino. Ele aceita mensagens do tipo `_Input` e envia mensagens do tipo `_Output`. A classe `transformer` especifica `single_link_registry` como o Gerenciador de links para qualquer bloco de destino e `multi_link_registry` como o Gerenciador de links para qualquer bloco de origem. Portanto, um objeto `transformer` pode ter até um destino e um número ilimitado de fontes.

Uma classe derivada de `source_block` deve implementar seis métodos: [propagate_to_any_targets](reference/source-block-class.md#propagate_to_any_targets), [accept_message](reference/source-block-class.md#accept_message), [reserve_message](reference/source-block-class.md#reserve_message), [consume_message](reference/source-block-class.md#consume_message), [release_message](reference/source-block-class.md#release_message)e [resume_propagation](reference/source-block-class.md#resume_propagation). Uma classe que deriva de `target_block` deve implementar o método [propagate_message](reference/propagator-block-class.md#propagate_message) e, opcionalmente, pode implementar o método [send_message](reference/propagator-block-class.md#send_message) . Derivar de `propagator_block` é funcionalmente equivalente a derivar de `source_block` e `target_block`.

O método `propagate_to_any_targets` é chamado pelo tempo de execução para processar de forma assíncrona ou síncrona as mensagens de entrada e propagar quaisquer mensagens de saída. O método `accept_message` é chamado por blocos de destino para aceitar mensagens. Muitos tipos de bloco de mensagens, como `unbounded_buffer`, enviam mensagens somente para o primeiro destino que a receberia. Portanto, ele transfere a propriedade da mensagem para o destino. Outros tipos de bloco de mensagens, como [Concurrency:: overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md), oferecem mensagens a cada um de seus blocos de destino. Portanto, `overwrite_buffer` cria uma cópia da mensagem para cada um de seus destinos.

Os métodos `reserve_message`, `consume_message`, `release_message`e `resume_propagation` permitem que os blocos de mensagens participem da reserva de mensagens. Os blocos de destino chamam o método `reserve_message` quando são oferecidos uma mensagem e precisam reservar a mensagem para uso posterior. Depois que um bloco de destino reserva uma mensagem, ele pode chamar o método `consume_message` para consumir essa mensagem ou o método `release_message` para cancelar a reserva. Assim como com o método `accept_message`, a implementação do `consume_message` pode transferir a propriedade da mensagem ou retornar uma cópia da mensagem. Depois que um bloco de destino consome ou libera uma mensagem reservada, o tempo de execução chama o método `resume_propagation`. Normalmente, esse método continua a propagação de mensagens, começando com a próxima mensagem na fila.

O tempo de execução chama o método `propagate_message` para transferir de forma assíncrona uma mensagem de outro bloco para o atual. O método `send_message` é semelhante a `propagate_message`, exceto que, de forma síncrona, em vez de assincronamente, envia a mensagem para os blocos de destino. A implementação padrão de `send_message` rejeita todas as mensagens de entrada. O tempo de execução não chamará nenhum desses métodos se a mensagem não passar a função de filtro opcional que está associada ao bloco de destino. Para obter mais informações sobre filtros de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).

[[Superior](#top)]

## <a name="class"></a>Definindo a classe de priority_buffer

A classe `priority_buffer` é um tipo de bloco de mensagens personalizado que ordena mensagens de entrada primeiro por prioridade e, em seguida, pela ordem em que as mensagens são recebidas. A classe `priority_buffer` é semelhante à classe [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) porque contém uma fila de mensagens e também porque atua como um bloco de mensagens de origem e de destino e pode ter várias origens e vários destinos. No entanto, `unbounded_buffer` baseia a propagação de mensagens somente na ordem em que recebe mensagens de suas fontes.

A classe `priority_buffer` recebe mensagens do tipo std::[tupla](../../standard-library/tuple-class.md) que contêm `PriorityType` e `Type` elementos. `PriorityType` refere-se ao tipo que contém a prioridade de cada mensagem; `Type` refere-se à parte de dados da mensagem. A classe `priority_buffer` envia mensagens do tipo `Type`. A classe `priority_buffer` também gerencia duas filas de mensagens: um objeto [std::p riority_queue](../../standard-library/priority-queue-class.md) para mensagens de entrada e um objeto std::[Queue](../../standard-library/queue-class.md) para mensagens de saída. A ordenação de mensagens por prioridade é útil quando um objeto `priority_buffer` recebe várias mensagens simultaneamente ou quando recebe várias mensagens antes que qualquer mensagem seja lida pelos consumidores.

Além dos sete métodos que uma classe derivada de `propagator_block` deve implementar, a classe `priority_buffer` também substitui os métodos `link_target_notification` e `send_message`. A classe `priority_buffer` também define dois métodos auxiliares públicos, `enqueue` e `dequeue`, e um método auxiliar privado, `propagate_priority_order`.

O procedimento a seguir descreve como implementar a classe `priority_buffer`.

#### <a name="to-define-the-priority_buffer-class"></a>Para definir a classe priority_buffer

1. Crie um C++ arquivo de cabeçalho e nomeie-o `priority_buffer.h`. Como alternativa, você pode usar um arquivo de cabeçalho existente que faz parte do seu projeto.

1. Em `priority_buffer.h`, adicione o código a seguir.

[!code-cpp[concrt-priority-buffer#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_2.h)]

1. No namespace `std`, defina especializações de [std:: less](../../standard-library/less-struct.md) e [std:: Great](../../standard-library/greater-struct.md) que agem em objetos Concurrency::[Message](../../parallel/concrt/reference/message-class.md) .

[!code-cpp[concrt-priority-buffer#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_3.h)]

   A classe `priority_buffer` armazena `message` objetos em um objeto `priority_queue`. Essas especializações de tipo permitem que a fila de prioridade classifique mensagens de acordo com sua prioridade. A prioridade é o primeiro elemento do objeto `tuple`.

1. No namespace `concurrencyex`, declare a classe `priority_buffer`.

[!code-cpp[concrt-priority-buffer#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_4.h)]

   O `priority_buffer` classe deriva de `propagator_block`. Portanto, ele pode enviar e receber mensagens. A classe `priority_buffer` pode ter vários destinos que recebem mensagens do tipo `Type`. Ele também pode ter várias fontes que enviam mensagens do tipo `tuple<PriorityType, Type>`.

1. Na seção `private` da classe `priority_buffer`, adicione as seguintes variáveis de membro.

[!code-cpp[concrt-priority-buffer#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_5.h)]

   O objeto `priority_queue` contém mensagens de entrada; o objeto `queue` mantém as mensagens de saída. Um objeto `priority_buffer` pode receber várias mensagens simultaneamente; o objeto `critical_section` sincroniza o acesso à fila de mensagens de entrada.

1. Na seção `private`, defina o construtor de cópia e o operador de atribuição. Isso impede que `priority_queue` objetos sejam atribuíveis.

[!code-cpp[concrt-priority-buffer#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_6.h)]

1. Na seção `public`, defina os construtores que são comuns a muitos tipos de bloco de mensagens. Defina também o destruidor.

[!code-cpp[concrt-priority-buffer#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_7.h)]

1. Na seção `public`, defina os métodos `enqueue` e `dequeue`. Esses métodos auxiliares fornecem uma maneira alternativa de enviar e receber mensagens de um objeto `priority_buffer`.

[!code-cpp[concrt-priority-buffer#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_8.h)]

9. Na seção `protected`, defina o método `propagate_to_any_targets`.

[!code-cpp[concrt-priority-buffer#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_9.h)]

   O método `propagate_to_any_targets` transfere a mensagem que está na frente da fila de entrada para a fila de saída e propaga todas as mensagens na fila de saída.

10. Na seção `protected`, defina o método `accept_message`.

[!code-cpp[concrt-priority-buffer#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_10.h)]

   Quando um bloco de destino chama o método `accept_message`, a classe `priority_buffer` transfere a propriedade da mensagem para o primeiro bloco de destino que a aceita. (Isso se assemelha ao comportamento de `unbounded_buffer`.)

11. Na seção `protected`, defina o método `reserve_message`.

[!code-cpp[concrt-priority-buffer#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_11.h)]

   A classe `priority_buffer` permite que um bloco de destino Reserve uma mensagem quando o identificador de mensagem fornecido corresponde ao identificador da mensagem que está na frente da fila. Em outras palavras, um destino poderá reservar a mensagem se o objeto de `priority_buffer` ainda não tiver recebido uma mensagem adicional e ainda não tiver propagado o mesmo.

12. Na seção `protected`, defina o método `consume_message`.

[!code-cpp[concrt-priority-buffer#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_12.h)]

   Um bloco de destino chama `consume_message` para transferir a propriedade da mensagem que ele reservou.

13. Na seção `protected`, defina o método `release_message`.

[!code-cpp[concrt-priority-buffer#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_13.h)]

   Um bloco de destino chama `release_message` para cancelar sua reserva para uma mensagem.

14. Na seção `protected`, defina o método `resume_propagation`.

[!code-cpp[concrt-priority-buffer#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_14.h)]

   O tempo de execução chama `resume_propagation` depois que um bloco de destino consome ou libera uma mensagem reservada. Esse método propaga todas as mensagens que estão na fila de saída.

15. Na seção `protected`, defina o método `link_target_notification`.

[!code-cpp[concrt-priority-buffer#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_15.h)]

   A variável de membro `_M_pReservedFor` é definida pela classe base, `source_block`. Essa variável de membro aponta para o bloco de destino, se houver, que está mantendo uma reserva para a mensagem que está na frente da fila de saída. O tempo de execução chama `link_target_notification` quando um novo destino é vinculado ao objeto `priority_buffer`. Esse método propaga todas as mensagens que estão na fila de saída se nenhum destino estiver segurando uma reserva.

16. Na seção `private`, defina o método `propagate_priority_order`.

[!code-cpp[concrt-priority-buffer#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_16.h)]

   Esse método propaga todas as mensagens da fila de saída. Cada mensagem na fila é oferecida a cada bloco de destino até que um dos blocos de destino aceite a mensagem. A classe `priority_buffer` preserva a ordem das mensagens de saída. Portanto, a primeira mensagem na fila de saída deve ser aceita por um bloco de destino antes que esse método ofereça qualquer outra mensagem aos blocos de destino.

17. Na seção `protected`, defina o método `propagate_message`.

[!code-cpp[concrt-priority-buffer#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_17.h)]

   O método `propagate_message` permite que a classe `priority_buffer` atue como um receptor de mensagens ou destino. Esse método recebe a mensagem que é oferecida pelo bloco de origem fornecido e insere essa mensagem na fila de prioridade. O método `propagate_message`, em seguida, envia de forma assíncrona todas as mensagens de saída para os blocos de destino.

   O tempo de execução chama esse método quando você chama a função [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) ou quando o bloco de mensagens está conectado a outros blocos de mensagens.

18. Na seção `protected`, defina o método `send_message`.

[!code-cpp[concrt-priority-buffer#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_18.h)]

   O método `send_message` é semelhante a `propagate_message`. No entanto, ele envia as mensagens de saída de forma síncrona em vez de assíncrona.

   O tempo de execução chama esse método durante uma operação de envio síncrona, como quando você chama a função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) .

A classe `priority_buffer` contém sobrecargas de construtor que são típicas em muitos tipos de bloco de mensagens. Algumas sobrecargas de Construtor usam objetos [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) ou [Concurrency:: Schedule](../../parallel/concrt/reference/schedulegroup-class.md) , que permitem que o bloco de mensagens seja gerenciado por um Agendador de tarefas específico. Outras sobrecargas de Construtor tomam uma função de filtro. As funções de filtro permitem que os blocos de mensagens aceitem ou rejeitem uma mensagem com base em sua carga. Para obter mais informações sobre filtros de mensagens, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md). Para obter mais informações sobre agendadores de tarefas, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

Como a classe `priority_buffer` ordena as mensagens por prioridade e, em seguida, pela ordem em que as mensagens são recebidas, essa classe é mais útil quando recebe mensagens de forma assíncrona, por exemplo, quando você chama a função [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) ou quando o bloco de mensagens está conectado a outros blocos de mensagens.

[[Superior](#top)]

## <a name="complete"></a>O exemplo completo

O exemplo a seguir mostra a definição completa da classe `priority_buffer`.

[!code-cpp[concrt-priority-buffer#18](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_19.h)]

O exemplo a seguir executa simultaneamente uma série de operações de `asend` e [simultaneidade: Receive](reference/concurrency-namespace-functions.md#receive) em um objeto `priority_buffer`.

[!code-cpp[concrt-priority-buffer#19](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_20.cpp)]

Este exemplo produz a seguinte saída de exemplo.

```Output
36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36
24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24
12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
```

A classe `priority_buffer` ordena as mensagens primeiro por prioridade e, em seguida, pela ordem em que recebe as mensagens. Neste exemplo, as mensagens com maior prioridade numérica são inseridas em direção à frente da fila.

[[Superior](#top)]

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio, ou cole a definição da classe `priority_buffer` em um arquivo chamado `priority_buffer.h` e o programa de teste em um arquivo chamado `priority_buffer.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**CL. exe/EHsc priority_buffer. cpp**

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
