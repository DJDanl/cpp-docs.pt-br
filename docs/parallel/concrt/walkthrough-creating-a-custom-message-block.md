---
title: 'Instruções passo a passo: criando um bloco de mensagens personalizado'
ms.date: 04/25/2019
helpviewer_keywords:
- creating custom message blocks Concurrency Runtime]
- custom message blocks, creating [Concurrency Runtime]
ms.assetid: 4c6477ad-613c-4cac-8e94-2c9e63cd43a1
ms.openlocfilehash: 3386994dce68812cf3ed0852a24d8910cb903acf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368565"
---
# <a name="walkthrough-creating-a-custom-message-block"></a>Instruções passo a passo: criando um bloco de mensagens personalizado

Este documento descreve como criar um tipo de bloco de mensagem personalizado que ordena mensagens recebidas por prioridade.

Embora os tipos de blocos de mensagens incorporados forneçam uma ampla gama de funcionalidades, você pode criar seu próprio tipo de bloco de mensagem e personalizá-lo para atender aos requisitos do seu aplicativo. Para obter uma descrição dos tipos de blocos de mensagens incorporados fornecidos pela Biblioteca de Agentes Assíncronos, consulte Blocos de [mensagens Assíncronos](../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="prerequisites"></a>Pré-requisitos

Leia os seguintes documentos antes de iniciar este passo a passo:

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

## <a name="sections"></a><a name="top"></a>Seções

Este passo a passo contém as seguintes seções:

- [Projetando um Bloco de Mensagem Personalizado](#design)

- [Definindo a Classe priority_buffer](#class)

- [O exemplo completo](#complete)

## <a name="designing-a-custom-message-block"></a><a name="design"></a>Projetando um bloco de mensagens personalizado

Blocos de mensagens participam do ato de envio e recebimento de mensagens. Um bloco de mensagens que envia mensagens é conhecido como um *bloco de origem*. Um bloco de mensagens que recebe mensagens é conhecido como um *bloco de destino*. Um bloco de mensagens que envia e recebe mensagens é conhecido como *um bloco propagador*. A Biblioteca de agentes usa a classe abstrata [simultâneo::ISource](../../parallel/concrt/reference/isource-class.md) para representar blocos de origem e a classe abstrata [simultâneo::ITarget](../../parallel/concrt/reference/itarget-class.md) para representar blocos de destino. Os tipos de blocos `ISource`de mensagens que agem como fontes derivam; tipos de blocos de mensagem que agem como alvos derivam de `ITarget`.

Embora você possa derivar seu `ISource` `ITarget`tipo de bloco de mensagem diretamente e , a Biblioteca de agentes define três classes base que executam grande parte da funcionalidade que é comum a todos os tipos de blocos de mensagens, por exemplo, manipulação de erros e conexão de blocos de mensagens de forma segura. A [classe de si00::source_block](../../parallel/concrt/reference/source-block-class.md) deriva `ISource` e envia mensagens para outros blocos. A [classe de si0::target_block](../../parallel/concrt/reference/target-block-class.md) deriva `ITarget` e recebe mensagens de outros blocos. A [classe simultâneo::propagator_block](../../parallel/concrt/reference/propagator-block-class.md) deriva `ISource` e `ITarget` envia mensagens para outros blocos e recebe mensagens de outros blocos. Recomendamos que você use essas três classes básicas para lidar com detalhes de infra-estrutura para que você possa se concentrar no comportamento do seu bloco de mensagens.

As `source_block` `target_block`classes `propagator_block` e classes são modelos parametrizados em um tipo que gerencia as conexões, ou links, entre blocos de origem e destino e em um tipo que gerencia como as mensagens são processadas. A Biblioteca de Agentes define dois tipos que executam o gerenciamento de links, [simultâneo::single_link_registry](../../parallel/concrt/reference/single-link-registry-class.md) e [simultâneo::multi_link_registry](../../parallel/concrt/reference/multi-link-registry-class.md). A `single_link_registry` classe permite que um bloco de mensagens seja vinculado a uma fonte ou a um alvo. A `multi_link_registry` classe permite que um bloco de mensagens seja vinculado a várias fontes ou vários alvos. A Biblioteca de Agentes define uma classe que executa o gerenciamento [de mensagens, simultuou::ordered_message_processor](../../parallel/concrt/reference/ordered-message-processor-class.md). A `ordered_message_processor` classe permite que blocos de mensagens processem mensagens na ordem em que as recebe.

Para entender melhor como os blocos de mensagens se relacionam com suas fontes e alvos, considere o seguinte exemplo. Este exemplo mostra a declaração da [classe simultuária::transformer.](../../parallel/concrt/reference/transformer-class.md)

[!code-cpp[concrt-priority-buffer#20](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_1.cpp)]

A `transformer` classe deriva `propagator_block`, e, portanto, age como um bloco de origem e como um bloco de destino. Aceita mensagens de `_Input` tipo e envia `_Output`mensagens do tipo . A `transformer` classe `single_link_registry` especifica como o gerenciador `multi_link_registry` de links para quaisquer blocos de destino e como o gerenciador de link para quaisquer blocos de origem. Portanto, um `transformer` objeto pode ter até um alvo e um número ilimitado de fontes.

Uma classe derivada `source_block` deve implementar seis métodos: [propagate_to_any_targets,](reference/source-block-class.md#propagate_to_any_targets) [accept_message](reference/source-block-class.md#accept_message), [reserve_message](reference/source-block-class.md#reserve_message), [consume_message](reference/source-block-class.md#consume_message), [release_message](reference/source-block-class.md#release_message)e [resume_propagation](reference/source-block-class.md#resume_propagation). Uma classe derivada `target_block` deve implementar o método [propagate_message](reference/propagator-block-class.md#propagate_message) e pode, opcionalmente, implementar o método [send_message.](reference/propagator-block-class.md#send_message) O derivado `propagator_block` é funcionalmente equivalente ao `source_block` `target_block`derivado de ambos e .

O `propagate_to_any_targets` método é chamado pelo tempo de execução para processar assíncrona ou sincronizadamente quaisquer mensagens recebidas e propagar quaisquer mensagens de saída. O `accept_message` método é chamado por blocos de destino para aceitar mensagens. Muitos tipos de blocos de mensagens, como `unbounded_buffer`, enviar mensagens apenas para o primeiro alvo que iria recebê-lo. Portanto, transfere a propriedade da mensagem para o alvo. Outros tipos de blocos de mensagens, como [simultu:overwrite_buffer,](../../parallel/concrt/reference/overwrite-buffer-class.md)oferecem mensagens a cada um de seus blocos-alvo. Portanto, `overwrite_buffer` cria uma cópia da mensagem para cada um de seus alvos.

Os `reserve_message` `consume_message`métodos `release_message` `resume_propagation` e os métodos permitem que blocos de mensagens participem da reserva de mensagens. Os blocos `reserve_message` de destino chamam o método quando são oferecidas uma mensagem e têm que reservar a mensagem para uso posterior. Depois que um bloco de destino `consume_message` reserva uma mensagem, `release_message` ele pode chamar o método para consumir essa mensagem ou o método para cancelar a reserva. Assim como `accept_message` no método, `consume_message` a implementação pode transferir a propriedade da mensagem ou devolver uma cópia da mensagem. Depois que um bloco de destino consome ou libera `resume_propagation` uma mensagem reservada, o tempo de execução chama o método. Normalmente, esse método continua a propagação de mensagens, começando com a próxima mensagem na fila.

O tempo de `propagate_message` execução chama o método para transferir assíncronamente uma mensagem de outro bloco para a atual. O `send_message` método `propagate_message`se assemelha, exceto que ele sincronizadamente, em vez de assíncronamente, envia a mensagem para os blocos de destino. A implementação `send_message` padrão de rejeita todas as mensagens recebidas. O tempo de execução não liga para nenhum desses métodos se a mensagem não passar na função de filtro opcional associada ao bloco de destino. Para obter mais informações sobre filtros de mensagens, consulte [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md).

[[Top](#top)]

## <a name="defining-the-priority_buffer-class"></a><a name="class"></a>Definindo a Classe priority_buffer

A `priority_buffer` classe é um tipo de bloco de mensagem personalizado que encomenda mensagens recebidas primeiro por prioridade e, em seguida, pela ordem em que as mensagens são recebidas. A `priority_buffer` classe se assemelha à [classe de concorrência::unbounded_buffer](reference/unbounded-buffer-class.md) classe porque mantém uma fila de mensagens, e também porque age como uma fonte e um bloco de mensagem de destino e pode ter várias fontes e vários alvos. No `unbounded_buffer` entanto, baseia a propagação de mensagens apenas na ordem em que recebe mensagens de suas fontes.

A `priority_buffer` classe recebe mensagens do tipo std:: `Type` [tuple](../../standard-library/tuple-class.md) que contêm `PriorityType` e elementos. `PriorityType`refere-se ao tipo que detém a prioridade de cada mensagem; `Type` refere-se à parte de dados da mensagem. A `priority_buffer` classe envia mensagens do tipo `Type`. A `priority_buffer` classe também gerencia duas filas de mensagens: um objeto [std::priority_queue](../../standard-library/priority-queue-class.md) para mensagens recebidas e um objeto de[fila](../../standard-library/queue-class.md) para mensagens de saída. O pedido de mensagens `priority_buffer` por prioridade é útil quando um objeto recebe várias mensagens simultaneamente ou quando recebe várias mensagens antes de qualquer mensagem ser lida pelos consumidores.

Além dos sete métodos que uma classe `propagator_block` que deriva `priority_buffer` deve implementar, `link_target_notification` `send_message` a classe também substitui os métodos. A `priority_buffer` classe também define dois métodos `enqueue` `dequeue`de ajuda pública, e `propagate_priority_order`, e um método auxiliar privado, .

O procedimento a seguir descreve `priority_buffer` como implementar a classe.

#### <a name="to-define-the-priority_buffer-class"></a>Para definir a classe priority_buffer

1. Crie um arquivo de cabeçalho C++ e nomeie-o `priority_buffer.h`. Alternativamente, você pode usar um arquivo de cabeçalho existente que faz parte do seu projeto.

1. Em `priority_buffer.h`, adicione o seguinte código.

    [!code-cpp[concrt-priority-buffer#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_2.h)]

1. No `std` namespace, defina especializações de [std::less](../../standard-library/less-struct.md) e [std::maior](../../standard-library/greater-struct.md) estocadas em simultâneos:: objetos[de mensagem.](../../parallel/concrt/reference/message-class.md)

    [!code-cpp[concrt-priority-buffer#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_3.h)]

   A `priority_buffer` classe `message` armazena `priority_queue` objetos em um objeto. Essas especializações do tipo permitem que a fila de prioridades classifique as mensagens de acordo com sua prioridade. A prioridade é o `tuple` primeiro elemento do objeto.

1. No `concurrencyex` namespace, declare `priority_buffer` a classe.

    [!code-cpp[concrt-priority-buffer#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_4.h)]

   O `priority_buffer` classe deriva de `propagator_block`. Portanto, ele pode enviar e receber mensagens. A `priority_buffer` classe pode ter vários alvos que `Type`recebem mensagens do tipo . Ele também pode ter várias fontes `tuple<PriorityType, Type>`que enviam mensagens do tipo .

1. Na `private` seção `priority_buffer` da classe, adicione as seguintes variáveis de membro.

    [!code-cpp[concrt-priority-buffer#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_5.h)]

   O `priority_queue` objeto contém mensagens recebidas; o `queue` objeto contém mensagens de saída. Um `priority_buffer` objeto pode receber várias mensagens simultaneamente; o `critical_section` objeto sincroniza o acesso à fila de mensagens de entrada.

1. Na `private` seção, defina o construtor de cópias e o operador de atribuição. Isso evita `priority_queue` que objetos sejam atribuídos.

    [!code-cpp[concrt-priority-buffer#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_6.h)]

1. Na `public` seção, defina os construtores que são comuns a muitos tipos de blocos de mensagem. Também defina o destruidor.

    [!code-cpp[concrt-priority-buffer#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_7.h)]

1. Na `public` seção, defina `enqueue` `dequeue`os métodos e . Esses métodos auxiliares fornecem uma maneira alternativa de enviar `priority_buffer` mensagens e receber mensagens de um objeto.

    [!code-cpp[concrt-priority-buffer#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_8.h)]

1. Na `protected` seção, `propagate_to_any_targets` defina o método.

    [!code-cpp[concrt-priority-buffer#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_9.h)]

   O `propagate_to_any_targets` método transfere a mensagem que está na frente da fila de entrada para a fila de saída e propaga todas as mensagens na fila de saída.

1. Na `protected` seção, `accept_message` defina o método.

    [!code-cpp[concrt-priority-buffer#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_10.h)]

   Quando um bloco `accept_message` de destino `priority_buffer` chama o método, a classe transfere a propriedade da mensagem para o primeiro bloco de destino que a aceita. (Isso se assemelha `unbounded_buffer`ao comportamento de .)

1. Na `protected` seção, `reserve_message` defina o método.

    [!code-cpp[concrt-priority-buffer#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_11.h)]

   A `priority_buffer` classe permite que um bloco de destino reserve uma mensagem quando o identificador de mensagem fornecido corresponder ao identificador da mensagem que está na frente da fila. Em outras palavras, um alvo `priority_buffer` pode reservar a mensagem se o objeto ainda não recebeu uma mensagem adicional e ainda não propagou a atual.

1. Na `protected` seção, `consume_message` defina o método.

    [!code-cpp[concrt-priority-buffer#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_12.h)]

   Um bloco `consume_message` de destino chama para transferir a propriedade da mensagem que ele reservou.

1. Na `protected` seção, `release_message` defina o método.

    [!code-cpp[concrt-priority-buffer#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_13.h)]

   Um bloco `release_message` de destino liga para cancelar sua reserva para uma mensagem.

1. Na `protected` seção, `resume_propagation` defina o método.

    [!code-cpp[concrt-priority-buffer#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_14.h)]

   O tempo `resume_propagation` de execução é chamada após um bloco de destino consumir ou liberar uma mensagem reservada. Este método propaga todas as mensagens que estão na fila de saída.

1. Na `protected` seção, `link_target_notification` defina o método.

    [!code-cpp[concrt-priority-buffer#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_15.h)]

   A `_M_pReservedFor` variável membro é definida `source_block`pela classe base, . Esta variável de membro aponta para o bloco de destino, se houver, que está segurando uma reserva para a mensagem que está na frente da fila de saída. O tempo `link_target_notification` de execução é call `priority_buffer` quando um novo alvo está vinculado ao objeto. Este método propaga todas as mensagens que estão na fila de saída se nenhum alvo estiver segurando uma reserva.

1. Na `private` seção, `propagate_priority_order` defina o método.

    [!code-cpp[concrt-priority-buffer#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_16.h)]

   Este método propaga todas as mensagens da fila de saída. Todas as mensagens na fila são oferecidas a cada bloco de destino até que um dos blocos de destino aceite a mensagem. A `priority_buffer` classe preserva a ordem das mensagens de saída. Portanto, a primeira mensagem na fila de saída deve ser aceita por um bloco de destino antes que este método ofereça qualquer outra mensagem aos blocos de destino.

1. Na `protected` seção, `propagate_message` defina o método.

    [!code-cpp[concrt-priority-buffer#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_17.h)]

   O `propagate_message` método `priority_buffer` permite que a classe atue como um receptor de mensagem ou alvo. Este método recebe a mensagem oferecida pelo bloco de origem fornecido e insere essa mensagem na fila de prioridade. O `propagate_message` método então envia assíncronamente todas as mensagens de saída para os blocos de destino.

   O tempo de execução chama esse método quando você chama a [função de concorrência::asend](reference/concurrency-namespace-functions.md#asend) ou quando o bloco de mensagens está conectado a outros blocos de mensagens.

1. Na `protected` seção, `send_message` defina o método.

    [!code-cpp[concrt-priority-buffer#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_18.h)]

   O `send_message` método `propagate_message`se assemelha. No entanto, ele envia as mensagens de saída sincronicamente em vez de assíncronamente.

   O tempo de execução chama esse método durante uma operação de envio síncrono, como quando você chama a [função de concorrência::enviar.](reference/concurrency-namespace-functions.md#send)

A `priority_buffer` classe contém sobrecargas de construtores que são típicas em muitos tipos de blocos de mensagens. Algumas sobrecargas de construtores tomam [simultuável::Scheduler](../../parallel/concrt/reference/scheduler-class.md) ou [simultuável::Agendar](../../parallel/concrt/reference/schedulegroup-class.md) objetos, que permitem que o bloco de mensagens seja gerenciado por um agendador de tarefas específico. Outras sobrecargas de construtores tomam uma função de filtro. As funções de filtro permitem que os blocos de mensagens aceitem ou rejeitem uma mensagem com base em sua carga útil. Para obter mais informações sobre filtros de mensagens, consulte [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md). Para obter mais informações sobre agendadores de tarefas, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

Como `priority_buffer` a classe ordena mensagens por prioridade e, em seguida, pela ordem em que as mensagens são recebidas, essa classe é mais útil quando recebe mensagens assíncronamente, por exemplo, quando você chama a [função de concorrência::asend](reference/concurrency-namespace-functions.md#asend) ou quando o bloco de mensagens está conectado a outros blocos de mensagens.

[[Top](#top)]

## <a name="the-complete-example"></a><a name="complete"></a>O Exemplo Completo

O exemplo a seguir mostra `priority_buffer` a definição completa da classe.

[!code-cpp[concrt-priority-buffer#18](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_19.h)]

O exemplo a seguir executa `asend` simultaneamente um número e `priority_buffer` [simultâneo::receber](reference/concurrency-namespace-functions.md#receive) operações em um objeto.

[!code-cpp[concrt-priority-buffer#19](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_20.cpp)]

Este exemplo produz a seguinte saída de amostra.

```Output
36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36
24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24
12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
```

A `priority_buffer` classe ordena mensagens primeiro por prioridade e depois pela ordem em que recebe mensagens. Neste exemplo, mensagens com maior prioridade numérica são inseridas na frente da fila.

[[Top](#top)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto `priority_buffer` do Visual Studio `priority_buffer.h` ou cole a definição da `priority_buffer.cpp` classe em um arquivo nomeado e o programa de teste em um arquivo nomeado e execute o seguinte comando em uma janela Visual Studio Command Prompt.

**cl.exe /EHsc priority_buffer.cpp**

## <a name="see-also"></a>Confira também

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
