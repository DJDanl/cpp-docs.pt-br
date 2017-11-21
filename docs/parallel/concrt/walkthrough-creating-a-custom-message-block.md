---
title: 'Passo a passo: Criando um bloco de mensagens personalizadas | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- creating custom message blocks Concurrency Runtime]
- custom message blocks, creating [Concurrency Runtime]
ms.assetid: 4c6477ad-613c-4cac-8e94-2c9e63cd43a1
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a49250dabf1f58f9933a296db87d951e75d8f187
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="walkthrough-creating-a-custom-message-block"></a>Instruções passo a passo: criando um bloco de mensagens personalizado
Este documento descreve como criar um tipo de bloco de mensagem personalizada que ordena as mensagens de entrada por prioridade.  
  
 Embora os tipos de bloco de mensagens internas fornecem uma variedade de toda a funcionalidade, você pode criar seu próprio tipo de bloco de mensagens e personalizá-la para atender aos requisitos do seu aplicativo. Para obter uma descrição dos tipos de bloco de mensagem interno que são fornecidas pela biblioteca de agentes assíncronos, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Leia os documentos a seguir antes de iniciar esta explicação passo a passo:  
  
- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)  
  
##  <a name="top"></a>Seções  
 Este passo a passo contém as seguintes seções:  
  
- [Criando um bloco de mensagens personalizadas](#design)  
  
- [Definindo a classe priority_buffer](#class)  
  
- [O exemplo completo](#complete)  
  
##  <a name="design"></a>Criando um bloco de mensagens personalizadas  
 Blocos de mensagens participarem o ato de enviar e receber mensagens. Um bloco de mensagens que envia mensagens é conhecido como um *bloco origem*. Um bloco de mensagens que recebe mensagens é conhecido como um *bloco de destino*. Um bloco de mensagens que envia e recebe mensagens é conhecido como um *bloco propagador*. A biblioteca de agentes usa a classe abstrata [concurrency::ISource](../../parallel/concrt/reference/isource-class.md) representar blocos de origem e a classe abstrata [concurrency::ITarget](../../parallel/concrt/reference/itarget-class.md) representar blocos de destino. Tipos de bloco de mensagens que agem como fontes de derivam de `ISource`; tipos de bloco de mensagens que agem como destinos derivam `ITarget`.  
  
 Embora você possa derivar o tipo de bloco de mensagem diretamente do `ISource` e `ITarget`, a biblioteca de agentes define três classes base que executam muitas das funcionalidades que são comuns a todos os tipos de bloco de mensagens, por exemplo, tratamento de erros e Conectando blocos de mensagens juntas de maneira segura de simultaneidade. O [concurrency::source_block](../../parallel/concrt/reference/source-block-class.md) classe derivada de `ISource` e envia mensagens para outros blocos. O [concurrency::target_block](../../parallel/concrt/reference/target-block-class.md) classe derivada de `ITarget` e recebe mensagens a partir de outros blocos. O [concurrency::propagator_block](../../parallel/concrt/reference/propagator-block-class.md) classe derivada de `ISource` e `ITarget` e envia mensagens a outros blocos e recebe mensagens de outros blocos. É recomendável que você use essas três classes de base para manipular detalhes de infraestrutura para que você possa se concentrar no comportamento do seu bloco de mensagens.  
  
 O `source_block`, `target_block`, e `propagator_block` classes são modelos que são parametrizados em um tipo que gerencia as conexões ou links entre blocos de origem e de destino e em um tipo que gerencia como as mensagens são processadas. A biblioteca de agentes define dois tipos que executam o gerenciamento de link [concurrency::single_link_registry](../../parallel/concrt/reference/single-link-registry-class.md) e [concurrency::multi_link_registry](../../parallel/concrt/reference/multi-link-registry-class.md). O `single_link_registry` classe permite que um bloco de mensagens a ser vinculado a uma fonte ou um destino. O `multi_link_registry` classe permite que um bloco de mensagens a ser vinculado a vários destinos ou de várias fontes. A biblioteca de agentes define uma classe que executa o gerenciamento de mensagem, [concurrency::ordered_message_processor](../../parallel/concrt/reference/ordered-message-processor-class.md). O `ordered_message_processor` classe permite que os blocos de mensagens processar mensagens na ordem em que ele recebe.  
  
 Para entender melhor como blocos de mensagens se relacionam com suas fontes e destinos, considere o exemplo a seguir. Este exemplo mostra a declaração de [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) classe.  
  
 [!code-cpp[concrt-priority-buffer#20](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_1.cpp)]  
  
 O `transformer` classe derivada de `propagator_block`e, portanto, atua como ambos um bloco de origem e um bloco de destino. Ele aceita mensagens do tipo `_Input` e envia mensagens do tipo `_Output`. O `transformer` classe especifica `single_link_registry` como o Gerenciador de link de qualquer bloco de destino e `multi_link_registry` como o Gerenciador de link de qualquer bloco de código-fonte. Portanto, um `transformer` objeto pode ter até um destino e um número ilimitado de fontes.  
  

 Uma classe que deriva de `source_block` devem implementar seis métodos: [propagate_to_any_targets](reference/source-block-class.md#propagate_to_any_targets), [accept_message](reference/source-block-class.md#accept_message), [reserve_message](reference/source-block-class.md#reserve_message), [ consume_message](reference/source-block-class.md#consume_message), [release_message](reference/source-block-class.md#release_message), e [resume_propagation](reference/source-block-class.md#resume_propagation). Uma classe que deriva de `target_block` deve implementar o [propagate_message](reference/propagator-block-class.md#propagate_message) método e pode implementar o [send_message](reference/propagator-block-class.md#send_message) método. Derivando de `propagator_block` é funcionalmente equivalente a derivação de ambos `source_block` e `target_block`.  


  
 O `propagate_to_any_targets` método é chamado pelo tempo de execução de forma assíncrona ou síncrona processar quaisquer mensagens de entrada e propagar quaisquer mensagens de saída. O `accept_message` método é chamado por blocos de destino para aceitar mensagens. Muitos tipos de bloco de mensagens, como `unbounded_buffer`, enviar mensagens somente para o primeiro destino que deve receber a ele. Portanto, ele transfere a propriedade da mensagem para o destino. Bloco de mensagens de outros tipos, como [concurrency::overwrite_buffer](../../parallel/concrt/reference/overwrite-buffer-class.md), oferecer mensagens para cada um dos seus blocos de destino. Portanto, `overwrite_buffer` cria uma cópia da mensagem para cada um de seus destinos.  
  
 O `reserve_message`, `consume_message`, `release_message`, e `resume_propagation` métodos permitem que os blocos de mensagens participar de reserva de mensagem. Destino bloqueará a chamada a `reserve_message` método quando eles recebem uma mensagem e precisam reservar a mensagem para uso posterior. Depois que um bloco de destino reserva uma mensagem, ele pode chamar o `consume_message` método consumir mensagem ou o `release_message` método cancelar a reserva. Assim como acontece com o `accept_message` método, a implementação de `consume_message` pode transferir a propriedade da mensagem ou retornar uma cópia da mensagem. Depois de um bloco de destino consome ou libera uma mensagem reservada, o tempo de execução chama o `resume_propagation` método. Normalmente, esse método continua a propagação de mensagem, começando com a próxima mensagem na fila.  
  
 O tempo de execução chama o `propagate_message` método assincronamente transferir uma mensagem de outro bloco para a atual. O `send_message` método semelhante `propagate_message`, exceto pelo fato de forma síncrona, em vez de forma assíncrona, envia a mensagem para os blocos de destino. A implementação padrão de `send_message` rejeita todas as mensagens recebidas. O tempo de execução não chamar qualquer um desses métodos se a mensagem não passar para a função de filtro opcional que está associada com o bloco de destino. Para obter mais informações sobre filtros de mensagem, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md).  
  
 [[Superior](#top)]  
  
##  <a name="class"></a>Definindo a classe priority_buffer  
 O `priority_buffer` classe é um tipo de bloco de mensagem personalizada que ordena as mensagens de entrada primeiro por prioridade e, em seguida, pela ordem na qual as mensagens são recebidas. O `priority_buffer` é semelhante a [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) classe porque ele mantém uma fila de mensagens e também porque ele atua como uma origem e um bloco de mensagens de destino e pode ter várias fontes e múltiplo destinos. No entanto, `unbounded_buffer` propagação apenas na ordem em que ele recebe mensagens de suas fontes de mensagens de bases de dados.  
  
 O `priority_buffer` classe recebe mensagens do tipo std::[tupla](../../standard-library/tuple-class.md) que contêm `PriorityType` e `Type` elementos. `PriorityType`refere-se para o tipo que contém a prioridade de cada mensagem. `Type` refere-se à parte de dados da mensagem. O `priority_buffer` classe envia mensagens do tipo `Type`. O `priority_buffer` classe também gerencia duas filas de mensagens: um [std::priority_queue](../../standard-library/priority-queue-class.md) objeto para mensagens de entrada e um std::[fila](../../standard-library/queue-class.md) objeto mensagens de saída. Ordenação de mensagens por prioridade é útil quando um `priority_buffer` objeto receber várias mensagens simultaneamente ou ao receber várias mensagens antes de todas as mensagens são lidas pelos consumidores.  
  
 Além dos sete métodos que uma classe que deriva de `propagator_block` deve implementar, o `priority_buffer` classe também substitui o `link_target_notification` e `send_message` métodos. O `priority_buffer` classe também define dois métodos auxiliares pública, `enqueue` e `dequeue`e um método auxiliar privada, `propagate_priority_order`.  
  
 O procedimento a seguir descreve como implementar a `priority_buffer` classe.  
  
#### <a name="to-define-the-prioritybuffer-class"></a>Para definir a classe priority_buffer  
  
1.  Crie um arquivo de cabeçalho do C++ e nomeie- `priority_buffer.h`. Como alternativa, você pode usar um arquivo de cabeçalho existente que faz parte do seu projeto.  
  
2.  Em `priority_buffer.h`, adicione o seguinte código.  
  
 [!code-cpp[concrt-priority-buffer#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_2.h)]  
  
3.  No `std` namespace, definir especializações de [STD](../../standard-library/less-struct.md) e [std::greater](../../standard-library/greater-struct.md) que atuam em simultaneidade::[mensagem](../../parallel/concrt/reference/message-class.md) objetos.  
  
 [!code-cpp[concrt-priority-buffer#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_3.h)]  
  
     O `priority_buffer` classe repositórios `message` objetos em um `priority_queue` objeto. Esses especializações tipo permitem que a fila de prioridade classificar mensagens de acordo com sua prioridade. A prioridade é o primeiro elemento do `tuple` objeto.  
  
4.  No `concurrencyex` namespace, declare o `priority_buffer` classe.  
  
 [!code-cpp[concrt-priority-buffer#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_4.h)]  
  
     O `priority_buffer` classe deriva de `propagator_block`. Portanto, ele pode enviar e receber mensagens. O `priority_buffer` classe pode ter vários destinos que recebem mensagens do tipo `Type`. Ele também pode ter várias origens que enviam mensagens do tipo `tuple<PriorityType, Type>`.  
  
5.  No `private` seção o `priority_buffer` de classe, adicione as seguintes variáveis de membro.  
  
 [!code-cpp[concrt-priority-buffer#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_5.h)]  
  
     O `priority_queue` objeto contém as mensagens de entrada; o `queue` objeto contém mensagens de saída. Um `priority_buffer` objeto pode receber várias mensagens simultaneamente; o `critical_section` objeto sincroniza o acesso à fila de mensagens de entrada.  
  
6.  No `private` seção, defina o construtor de cópia e o operador de atribuição. Isso impede que `priority_queue` objetos do que está sendo atribuído.  
  
 [!code-cpp[concrt-priority-buffer#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_6.h)]  
  
7.  No `public` seção, defina os construtores que são comuns a vários tipos de bloco de mensagens. Também defina o destruidor.  
  
 [!code-cpp[concrt-priority-buffer#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_7.h)]  
  
8.  No `public` seção, defina os métodos `enqueue` e `dequeue`. Esses métodos auxiliares fornecem uma maneira alternativa para enviar e receber mensagens de uma `priority_buffer` objeto.  
  
 [!code-cpp[concrt-priority-buffer#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_8.h)]  
  
9. No `protected` seção, defina o `propagate_to_any_targets` método.  
  
 [!code-cpp[concrt-priority-buffer#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_9.h)]  
  
     O `propagate_to_any_targets` método transfere a mensagem que está na frente da fila de entrada para a fila de saída e propagará todas as mensagens na fila de saída.  
  
10. No `protected` seção, defina o `accept_message` método.  
  
 [!code-cpp[concrt-priority-buffer#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_10.h)]  
  
     Quando um bloco de destino chama o `accept_message` método, o `priority_buffer` classe transfere a propriedade da mensagem para o primeiro bloco de destino que aceita. (Isso é parecido com o comportamento de `unbounded_buffer`.)  
  
11. No `protected` seção, defina o `reserve_message` método.  
  
 [!code-cpp[concrt-priority-buffer#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_11.h)]  
  
     O `priority_buffer` classe permite que um bloco de destino para reservar uma mensagem quando o identificador de mensagem fornecido corresponde ao identificador da mensagem que está na frente da fila. Em outras palavras, um destino pode reservar a mensagem se o `priority_buffer` objeto ainda não recebeu uma mensagem adicional e ainda não propagadas out atual.  
  
12. No `protected` seção, defina o `consume_message` método.  
  
 [!code-cpp[concrt-priority-buffer#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_12.h)]  
  
     Um bloco de destino chama `consume_message` para transferir a propriedade da mensagem que ele está reservado.  
  
13. No `protected` seção, defina o `release_message` método.  
  
 [!code-cpp[concrt-priority-buffer#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_13.h)]  
  
     Um bloco de destino chama `release_message` para cancelar sua reserva para uma mensagem.  
  
14. No `protected` seção, defina o `resume_propagation` método.  
  
 [!code-cpp[concrt-priority-buffer#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_14.h)]  
  
     O tempo de execução chama `resume_propagation` depois que um bloco de destino consome ou libera uma mensagem reservada. Esse método propaga quaisquer mensagens que estão na fila de saída.  
  
15. No `protected` seção, defina o `link_target_notification` método.  
  
 [!code-cpp[concrt-priority-buffer#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_15.h)]  
  
     O `_M_pReservedFor` variável de membro é definido pela classe base, `source_block`. Essa variável de membro aponta para o bloco de destino, se houver, que está mantendo uma reserva para a mensagem que está na frente da fila de saída. O tempo de execução chama `link_target_notification` quando um novo destino está vinculado a `priority_buffer` objeto. Esse método propaga quaisquer mensagens que estão na fila de saída, se nenhum destino está segurando uma reserva.  
  
16. No `private` seção, defina o `propagate_priority_order` método.  
  
 [!code-cpp[concrt-priority-buffer#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_16.h)]  
  
     Esse método propaga todas as mensagens da fila de saída. Todas as mensagens na fila é oferecida para cada bloco de destino até que um dos blocos de destino aceita a mensagem. O `priority_buffer` classe preserva a ordem das mensagens de saída. Portanto, a primeira mensagem na fila de saída deve ser aceitos por um bloco de destino para que este método oferece qualquer outra mensagem para os blocos de destino.  
  
17. No `protected` seção, defina o `propagate_message` método.  
  
 [!code-cpp[concrt-priority-buffer#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_17.h)]  
  
     O `propagate_message` método habilita o `priority_buffer` de classe para agir como um destinatário da mensagem ou de destino. Este método recebe a mensagem que é oferecida pelo bloco de origem fornecido e insere essa mensagem na fila de prioridade. O `propagate_message` método assincronamente envia todas as mensagens de saída para os blocos de destino.  
  

     O tempo de execução chama este método quando você chamar o [concurrency::asend](reference/concurrency-namespace-functions.md#asend) função ou quando o bloco de mensagens está conectado aos outros blocos de mensagem.  

  
18. No `protected` seção, defina o `send_message` método.  
  
 [!code-cpp[concrt-priority-buffer#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_18.h)]  
  
     O `send_message` método semelhante `propagate_message`. No entanto, ele envia as mensagens de saída síncrona em vez de forma assíncrona.  
  

     O tempo de execução chama esse método durante uma operação de envio síncrono, como quando você chama o [concurrency::send](reference/concurrency-namespace-functions.md#send) função.  
  
 O `priority_buffer` classe contém sobrecargas de construtor que são comuns em muitos tipos de bloco de mensagens. Alguns construtor sobrecargas take [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) ou [concurrency::ScheduleGroup](../../parallel/concrt/reference/schedulegroup-class.md) objetos, que permitem que o bloco de mensagens a serem gerenciados por um agendador de tarefas específicas. Outras sobrecargas de construtor levam a uma função de filtro. Funções de filtro permitem blocos de mensagem aceitar ou rejeitar uma mensagem com base em sua carga. Para obter mais informações sobre filtros de mensagem, consulte [blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md). Para obter mais informações sobre agendadores de tarefa, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
 Porque o `priority_buffer` classe pedidos mensagens por prioridade e, em seguida, pela ordem na qual as mensagens são recebidas, essa classe é mais útil quando recebe mensagens de forma assíncrona, por exemplo, quando você chama o [concurrency::asend](reference/concurrency-namespace-functions.md#asend)função ou quando o bloco de mensagens está conectado aos outros blocos de mensagem.  
  
 [[Superior](#top)]  
  
##  <a name="complete"></a>O exemplo completo  
 O exemplo a seguir mostra a definição completa do `priority_buffer` classe.  
  
 [!code-cpp[concrt-priority-buffer#18](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_19.h)]  
  
 O exemplo a seguir executa simultaneamente um número de `asend` e [concurrency::receive](reference/concurrency-namespace-functions.md#receive) operações em um `priority_buffer` objeto.  

  
 [!code-cpp[concrt-priority-buffer#19](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-a-custom-message-block_20.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir.  
  
```Output  
36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36  
24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24 24  
12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12  
```  
  
 O `priority_buffer` classe ordena mensagens primeiro por prioridade e, em seguida, pela ordem em que ele recebe mensagens. Neste exemplo, as mensagens com maior prioridade numérica são inseridas para o início da fila.  
  
 [[Superior](#top)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colar a definição do `priority_buffer` classe em um arquivo chamado `priority_buffer.h` e o programa de teste em um arquivo chamado `priority_buffer.cpp` e, em seguida, execute o seguinte comando em um Visual Studio Janela de Prompt de comando.  
  
 **cl.exe /EHsc priority_buffer.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Explicações passo a passo de tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)
