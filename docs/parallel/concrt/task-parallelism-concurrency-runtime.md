---
title: Paralelismo de tarefa (runtime de simultaneidade)
ms.date: 11/04/2016
helpviewer_keywords:
- structured task groups [Concurrency Runtime]
- structured tasks [Concurrency Runtime]
- task groups [Concurrency Runtime]
- task parallelism
- tasks [Concurrency Runtime]
ms.assetid: 42f05ac3-2098-494a-ba84-737fcdcad077
ms.openlocfilehash: f65521771db3eb0fe19dc863b1b49e9627fc60e6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368584"
---
# <a name="task-parallelism-concurrency-runtime"></a>Paralelismo de tarefa (runtime de simultaneidade)

No Tempo de Execução de Concurrency, uma *tarefa* é uma unidade de trabalho que realiza um trabalho específico e normalmente é executada em paralelo com outras tarefas. Uma tarefa pode ser decomposta em tarefas adicionais e mais finas que são organizadas em um *grupo de tarefas*.

Você usa tarefas quando escreve código assíncrono e deseja que alguma operação ocorra após a operação assíncrona ser concluída. Por exemplo, você pode usar uma tarefa para ler assíncronamente de um arquivo e, em seguida, usar outra tarefa — uma *tarefa de continuação*, que é explicada mais tarde neste documento — para processar os dados depois que ele estiver disponível. Por outro lado, você pode usar grupos de tarefas para decompor trabalhos paralelos em pedaços menores. Por exemplo, suponha que você tenha um algoritmo recursivo que divide o trabalho restante em duas partições. Você pode usar grupos de tarefas para executar essas partições simultaneamente e, em seguida, esperar que o trabalho dividido seja concluído.

> [!TIP]
> Quando você quiser aplicar a mesma rotina a cada elemento de uma coleção em paralelo, use um algoritmo paralelo, como [simultâneo::parallel_for](reference/concurrency-namespace-functions.md#parallel_for), em vez de uma tarefa ou grupo de tarefas. Para obter mais informações sobre algoritmos paralelos, consulte [Algoritmos Paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="key-points"></a>Pontos Principais

- Quando você passa variáveis para uma expressão lambda por referência, você deve garantir que a vida útil dessa variável persiste até que a tarefa termine.

- Use tarefas (a [simultânea::classe de tarefas)](../../parallel/concrt/reference/task-class.md) quando você escrever código assíncrono. A classe de tarefas usa o Windows ThreadPool como seu agendador, não o Tempo de Execução de Concurrency.

- Use grupos de tarefas (a [classe de conmoeda::task_group](reference/task-group-class.md) ou a [simultânea::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algorithm) quando você quiser decompor o trabalho paralelo em pedaços menores e, em seguida, esperar que essas peças menores se completem.

- Use o [método simultu/retenções:::então](reference/task-class.md#then) para criar continuações. Uma *continuação* é uma tarefa que é executada de forma assíncrona após a conclusão de outra tarefa. Você pode conectar qualquer número de continuações para formar uma cadeia de trabalho assíncrono.

- Uma continuação baseada em tarefas é sempre programada para execução quando a tarefa antecedente termina, mesmo quando a tarefa antecedente é cancelada ou lança uma exceção.

- Use [a moeda::when_all](reference/concurrency-namespace-functions.md#when_all) para criar uma tarefa que seja concluída após cada membro de um conjunto de tarefas ser concluída. Use [a moeda::when_any](reference/concurrency-namespace-functions.md#when_any) para criar uma tarefa que seja concluída após um membro de um conjunto de tarefas ser concluído.

- Tarefas e grupos de tarefas podem participar do mecanismo de cancelamento da Biblioteca de Padrões Paralelos (PPL). Para obter mais informações, consulte [Cancelamento no PPL](cancellation-in-the-ppl.md).

- Para saber como o tempo de execução lida com exceções lançadas por tarefas e grupos de tarefas, consulte [Manipulação de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="in-this-document"></a>Neste Documento

- [Usando Expressões Lambda](#lambdas)

- [A Classe task](#task-class)

- [Tarefas de Continuação](#continuations)

- [Continuações com Base no Valor Contra com Base na Tarefa](#value-versus-task)

- [Compondo tarefas](#composing-tasks)

  - [A Função when_all](#when-all)

  - [A Função when_any](#when-any)

- [Execução da Tarefa com Atraso](#delayed-tasks)

- [Grupos de Tarefas](#task-groups)

- [Comparando task_group a structured_task_group](#comparing-groups)

- [Exemplo](#example)

- [Programação robusta](#robust)

## <a name="using-lambda-expressions"></a><a name="lambdas"></a>Usando expressões lambda

Por causa de sua sintaxe sucinta, as expressões lambda são uma maneira comum de definir o trabalho que é realizado por tarefas e grupos de tarefas. Aqui estão algumas dicas de uso:

- Como as tarefas normalmente são executadas em segmentos de fundo, esteja ciente da vida útil do objeto quando você capturar variáveis em expressões lambda. Quando você captura uma variável por valor, uma cópia dessa variável é feita no corpo lambda. Quando você captura por referência, uma cópia não é feita. Portanto, certifique-se de que a vida útil de qualquer variável que você capturar por referência sobrevive à tarefa que a usa.

- Quando você passar uma expressão lambda para uma tarefa, não capture variáveis que são alocadas na pilha por referência.

- Seja explícito sobre as variáveis que você captura em expressões lambda para que você possa identificar o que você está capturando por valor versus por referência. Por esta razão recomendamos que `[=]` você `[&]` não use as ou opções para expressões lambda.

Um padrão comum é quando uma tarefa em uma cadeia de continuação atribui a uma variável, e outra tarefa lê essa variável. Você não pode capturar por valor porque cada tarefa de continuação teria uma cópia diferente da variável. Para variáveis alocadas em pilha, você também não pode capturar por referência porque a variável pode não ser mais válida.

Para resolver esse problema, use um ponteiro inteligente, como [std::shared_ptr](../../standard-library/shared-ptr-class.md), para envolver a variável e passar o ponteiro inteligente por valor. Desta forma, o objeto subjacente pode ser atribuído e lido, e sobreviverá às tarefas que o utilizam. Use essa técnica mesmo quando a variável for um`^`ponteiro ou uma alça contada com referência ( ) para um objeto Windows Runtime. Este é um exemplo básico:

[!code-cpp[concrt-lambda-task-lifetime#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_1.cpp)]

Para obter mais informações sobre expressões lambda, consulte [Lambda Expressions](../../cpp/lambda-expressions-in-cpp.md).

## <a name="the-task-class"></a><a name="task-class"></a>A classe de tarefas

Você pode usar a [classe de tarefas simultu/2006](../../parallel/concrt/reference/task-class.md) para compor tarefas em um conjunto de operações dependentes. Este modelo de composição é apoiado pela noção de *continuações.* Uma continuação permite que o código seja executado quando a tarefa anterior, *ou anterior,* for concluída. O resultado da tarefa antecedente é passado como a entrada para uma ou mais tarefas de continuação. Quando uma tarefa antecedente é concluída, todas as tarefas de continuação que a aguardam são programadas para execução. Cada tarefa de continuação recebe uma cópia do resultado da tarefa anterior. Por sua vez, essas tarefas de continuação também podem ser tarefas antecedentes para outras continuações, criando assim uma cadeia de tarefas. As continuações ajudam você a criar cadeias arbitrárias de tarefas que têm dependências específicas entre elas. Além disso, uma tarefa pode participar do cancelamento antes de uma tarefa começar ou de forma cooperativa enquanto estiver em execução. Para obter mais informações sobre este modelo de cancelamento, consulte [Cancelamento no PPL](cancellation-in-the-ppl.md).

`task`é uma classe de modelo. O parâmetro `T` tipo é o tipo de resultado que é produzido pela tarefa. Esse tipo `void` pode ser se a tarefa não retornar um valor. `T`não pode `const` usar o modificador.

Quando você cria uma tarefa, você fornece uma *função de trabalho* que executa o corpo de tarefas. Esta função de trabalho vem na forma de uma função lambda, ponteiro de função ou objeto de função. Para esperar que uma tarefa seja concluída sem obter o resultado, ligue para o método [de simultu::task::: wait.](reference/task-class.md#wait) O `task::wait` método retorna uma [simultuà::task_status](reference/concurrency-namespace-enums.md#task_group_status) valor que descreve se a tarefa foi concluída ou cancelada. Para obter o resultado da tarefa, ligue para o [método simultuá-lo::task::get.](reference/task-class.md#get) Este método `task::wait` exige que a tarefa seja concluída e, portanto, bloqueia a execução do segmento atual até que o resultado esteja disponível.

O exemplo a seguir mostra como criar uma tarefa, esperar pelo seu resultado e exibir seu valor. Os exemplos nesta documentação usam funções lambda porque fornecem uma sintaxe mais sucinta. No entanto, você também pode usar ponteiros de função e objetos de função quando você usa tarefas.

[!code-cpp[concrt-basic-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_2.cpp)]

Quando você usa a função [simultuá-lo::create_task,](reference/concurrency-namespace-functions.md#create_task) você pode usar a `auto` palavra-chave em vez de declarar o tipo. Por exemplo, considere este código que cria e imprime a matriz de identidade:

[!code-cpp[concrt-create-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_3.cpp)]

Você pode `create_task` usar a função para criar a operação equivalente.

[!code-cpp[concrt-create-task#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_4.cpp)]

Se uma exceção for lançada durante a execução de uma tarefa, `task::get` `task::wait`os marshals em tempo de execução excedem a chamada subseqüente para ou , ou para uma continuação baseada em tarefas. Para obter mais informações sobre o mecanismo de manipulação de exceções de tarefas, consulte [Manipulação de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

Para um exemplo `task`que usa , [simultâneo::task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), cancelamento, consulte [Passo a passo: Conectando usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md). (A `task_completion_event` classe é descrita mais tarde neste documento.)

> [!TIP]
> Para saber detalhes específicos para tarefas em aplicativos UWP, consulte [programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) e [Criando Operações Assíncronas em C++ para Aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).

## <a name="continuation-tasks"></a><a name="continuations"></a>Tarefas de continuação

Na programação assíncrona, é muito comum para uma operação assíncrona, após a conclusão, invocar uma segunda operação e passar dados para ela. Tradicionalmente, isso é feito usando métodos de retorno de chamada. No Tempo de Execução de Concurrency, a mesma funcionalidade é fornecida por *tarefas de continuação*. Uma tarefa de continuação (também conhecida apenas como continuação) é uma tarefa assíncrona que é invocada por outra tarefa, que é conhecida como *antecedente,* quando o antecedente completa. Usando continuações, você pode:

- Passe dados da antecessora para a continuação.

- Especifique as condições precisas sob as quais a continuação é invocada ou não invocada.

- Cancele uma continuação antes de começar ou cooperativamente enquanto estiver em execução.

- Forneça dicas sobre como a continuação deve ser agendada. (Isso se aplica apenas aos aplicativos Universal Windows Platform (UWP). Para obter mais informações, consulte [Criando Operações Assíncronas em C++ para Aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).)

- Invoque várias continuações da mesma antecessora.

- Invoque uma continuação quando todos ou qualquer um dos antecedentes múltiplos estiver completo.

- Continuações da cadeia uma após a outra a qualquer comprimento.

- Use uma continuação para lidar com exceções que são lançadas pelo antecedente.

Esses recursos permitem que você execute uma ou mais tarefas quando a primeira tarefa for concluída. Por exemplo, você pode criar uma continuação que comprime um arquivo após a primeira tarefa lê-lo a partir do disco.

O exemplo a seguir modifica o anterior para usar o [método simultuável::task:::então](reference/task-class.md#then) para agendar uma continuação que imprime o valor da tarefa antecedente quando ela estiver disponível.

[!code-cpp[concrt-basic-continuation#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_5.cpp)]

Você pode acorrentar e aninhar tarefas a qualquer comprimento. Uma tarefa também pode ter várias continuações. O exemplo a seguir ilustra uma cadeia de continuação básica que incrementa o valor da tarefa anterior três vezes.

[!code-cpp[concrt-continuation-chain#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_6.cpp)]

Uma continuação também pode retornar outra tarefa. Se não houver cancelamento, então esta tarefa será executada antes da continuação subseqüente. Esta técnica é conhecida como *desembrulhamento assíncrono.* O desembrulhamento assíncrono é útil quando você deseja executar trabalho adicional em segundo plano, mas não deseja que a tarefa atual bloqueie o segmento atual. (Isso é comum em aplicativos UWP, onde continuações podem ser executadas no segmento de interface do usuário). O exemplo a seguir mostra três tarefas. A primeira tarefa retorna outra tarefa que é executada antes de uma tarefa de continuação.

[!code-cpp[concrt-async-unwrapping#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_7.cpp)]

> [!IMPORTANT]
> Quando uma continuação de uma tarefa `N`retorna uma tarefa aninhada de tipo, a tarefa resultante tem o tipo `N`, não `task<N>`, e é concluída quando a tarefa aninhada é concluída. Em outras palavras, a continuação realiza o desembrulhamento da tarefa aninhada.

## <a name="value-based-versus-task-based-continuations"></a><a name="value-versus-task"></a>Continuações baseadas em valor versus tarefas

Dado `task` um objeto `T`cujo tipo de retorno `T` é, você pode fornecer um valor de tipo ou `task<T>` para suas tarefas de continuação. Uma continuação `T` que leva o tipo é conhecida como uma *continuação baseada em valor*. Uma continuação baseada em valor é programada para execução quando a tarefa antecedente é concluída sem erro e não é cancelada. Uma continuação `task<T>` que toma o tipo como seu parâmetro é conhecida como uma *continuação baseada em tarefas*. Uma continuação baseada em tarefas é sempre programada para execução quando a tarefa antecedente termina, mesmo quando a tarefa antecedente é cancelada ou lança uma exceção. Você pode `task::get` então ligar para obter o resultado da tarefa antecedente. Se a tarefa antecedente `task::get` foi cancelada, lança [simultas::task_canceled](../../parallel/concrt/reference/task-canceled-class.md). Se a tarefa antecedente for `task::get` uma exceção, rejogue essa exceção. Uma continuação baseada em tarefas não é marcada como cancelada quando sua tarefa antecedente é cancelada.

## <a name="composing-tasks"></a><a name="composing-tasks"></a>Compondo tarefas

Esta seção descreve as funções [de concorrência::when_all](reference/concurrency-namespace-functions.md#when_all) e [concurrency::when_any,](reference/concurrency-namespace-functions.md#when_all) que podem ajudá-lo a compor várias tarefas para implementar padrões comuns.

### <a name="the-when_all-function"></a><a name="when-all"></a>A função when_all

A `when_all` função produz uma tarefa que se completa após um conjunto de tarefas concluídas. Esta função retorna um objeto[vetorial](../../standard-library/vector-class.md) std:: que contém o resultado de cada tarefa no conjunto. O exemplo básico `when_all` a seguir é usar para criar uma tarefa que represente a conclusão de três outras tarefas.

[!code-cpp[concrt-join-tasks#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_8.cpp)]

> [!NOTE]
> As tarefas para `when_all` as as qual você passa devem ser uniformes. Em outras palavras, todos eles devem retornar do mesmo tipo.

Você também pode `&&` usar a sintaxe para produzir uma tarefa que é concluída após um conjunto de tarefas concluídas, como mostrado no exemplo a seguir.

`auto t = t1 && t2; // same as when_all`

É comum usar uma `when_all` continuação em conjunto para executar uma ação após o término de um conjunto de tarefas. O exemplo a seguir modifica o anterior para imprimir a `int` soma de três tarefas que cada uma produz um resultado.

[!code-cpp[concrt-join-tasks#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_9.cpp)]

Neste exemplo, você também `task<vector<int>>` pode especificar para produzir uma continuação baseada em tarefas.

Se qualquer tarefa em um conjunto de tarefas `when_all` for cancelada ou lançar uma exceção, será concluída imediatamente e não esperar que as tarefas restantes sejam concluídas. Se uma exceção for lançada, o tempo `task::get` de `task::wait` execução relança a exceção quando você chama ou no objeto de tarefa que `when_all` retorna. Se mais de uma tarefa for executada, o tempo de execução escolhe uma delas. Portanto, certifique-se de observar todas as exceções após todas as tarefas concluídas; uma exceção de tarefa não tratada faz com que o aplicativo seja encerrado.

Aqui está uma função de utilidade que você pode usar para garantir que seu programa observe todas as exceções. Para cada tarefa no intervalo `observe_all_exceptions` fornecido, dispara qualquer exceção que ocorreu para ser relançada e, em seguida, engole essa exceção.

[!code-cpp[concrt-eh-when_all#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_10.cpp)]

Considere um aplicativo UWP que usa C++ e XAML e grava um conjunto de arquivos em disco. O exemplo a seguir `when_all` `observe_all_exceptions` mostra como usar e garantir que o programa observe todas as exceções.

[!code-cpp[concrt-eh-when_all#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_11.cpp)]

##### <a name="to-run-this-example"></a>Para executar este exemplo

1. No MainPage.xaml, `Button` adicione um controle.

[!code-xml[concrt-eh-when_all#3](../../parallel/concrt/codesnippet/xaml/task-parallelism-concurrency-runtime_12.xaml)]

1. No MainPage.xaml.h, adicione essas declarações de encaminhamento à `private` seção da `MainPage` declaração de classe.

[!code-cpp[concrt-eh-when_all#4](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_13.h)]

1. No MainPage.xaml.cpp, `Button_Click` implemente o manipulador de eventos.

[!code-cpp[concrt-eh-when_all#5](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_14.cpp)]

1. No MainPage.xaml.cpp, `WriteFilesAsync` implemente como mostrado no exemplo.

> [!TIP]
> `when_all`é uma função de não `task` bloqueio que produz um como resultado. Ao contrário [da tarefa::wait](reference/task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no segmento ASTA (Application STA).

### <a name="the-when_any-function"></a><a name="when-any"></a>A função when_any

A `when_any` função produz uma tarefa que é concluída quando a primeira tarefa em um conjunto de tarefas é concluída. Esta função retorna um objeto [std::pair](../../standard-library/pair-structure.md) que contém o resultado da tarefa concluída e o índice dessa tarefa no conjunto.

A `when_any` função é especialmente útil nos seguintes cenários:

- Operações redundantes. Considere um algoritmo ou uma operação que possam ser executados de várias maneiras. Você pode `when_any` usar a função para selecionar a operação que termina primeiro e, em seguida, cancelar as operações restantes.

- Operações intercaladas. Você pode iniciar várias operações `when_any` que todos devem terminar e usar a função para processar resultados à medida que cada operação termina. Após uma operação ser concluída, você poderá começar uma ou mais tarefas adicionais.

- Operações controladas. Você pode `when_any` usar a função para estender o cenário anterior limitando o número de operações simultâneas.

- Operações expiradas. Você pode `when_any` usar a função para selecionar entre uma ou mais tarefas e uma tarefa que termina após um tempo específico.

Como `when_all`acontece, é comum usar `when_any` uma continuação que tem que executar a ação quando a primeira em um conjunto de tarefas terminar. O exemplo básico `when_any` a seguir é usar para criar uma tarefa que é concluída quando a primeira de três outras tarefas é concluída.

[!code-cpp[concrt-select-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_15.cpp)]

Neste exemplo, você também `task<pair<int, size_t>>` pode especificar para produzir uma continuação baseada em tarefas.

> [!NOTE]
> Como `when_all`com , as tarefas para `when_any` as as que você passa devem retornar todos do mesmo tipo.

Você também pode `||` usar a sintaxe para produzir uma tarefa que é concluída após a primeira tarefa em um conjunto de tarefas concluídas, como mostrado no exemplo a seguir.

`auto t = t1 || t2; // same as when_any`

> [!TIP]
> Como `when_all`acontece, `when_any` não é bloqueador e é seguro chamar um aplicativo UWP no segmento ASTA.

## <a name="delayed-task-execution"></a><a name="delayed-tasks"></a>Execução de tarefa atrasada

Às vezes é necessário atrasar a execução de uma tarefa até que uma condição seja satisfeita, ou iniciar uma tarefa em resposta a um evento externo. Por exemplo, na programação assíncrona, você pode ter que iniciar uma tarefa em resposta a um evento de conclusão de I/O.

Duas maneiras de conseguir isso são usar uma continuação ou iniciar uma tarefa e aguardar um evento dentro da função de trabalho da tarefa. No entanto, há casos em que não é possível usar uma dessas técnicas. Por exemplo, para criar uma continuação, você deve ter a tarefa antecedente. No entanto, se você não tiver a tarefa antecedente, você pode criar um *evento de conclusão de tarefas* e, posteriormente, acorrentar esse evento de conclusão para a tarefa antecedente quando ele estiver disponível. Além disso, como uma tarefa de espera também bloqueia um segmento, você pode usar eventos de conclusão de tarefas para executar o trabalho quando uma operação assíncrona for concluída e, assim, liberar um thread.

A [classe de si00::task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) ajuda a simplificar essa composição de tarefas. Como `task` a classe, o `T` parâmetro de tipo é o tipo de resultado que é produzido pela tarefa. Esse tipo `void` pode ser se a tarefa não retornar um valor. `T`não pode `const` usar o modificador. Normalmente, `task_completion_event` um objeto é fornecido a um segmento ou tarefa que o sinalizará quando o valor para ele estiver disponível. Ao mesmo tempo, uma ou mais tarefas são definidas como ouvintes desse evento. Quando o evento é definido, as tarefas do ouvinte são concluídas e suas continuações estão programadas para serem executadas.

Para um exemplo `task_completion_event` que usa para implementar uma tarefa que é concluída após um atraso, consulte [Como: Criar uma tarefa que é concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md).

## <a name="task-groups"></a><a name="task-groups"></a>Grupos de tarefas

Um *grupo de tarefas* organiza uma coleção de tarefas. Grupos de tarefas empurram tarefas para uma fila de roubo de trabalho. O agendador remove tarefas dessa fila e as executa em recursos de computação disponíveis. Depois de adicionar tarefas a um grupo de tarefas, você pode esperar que todas as tarefas sejam concluídas ou cancele tarefas que ainda não foram iniciadas.

O PPL usa as classes [de concorrência::task_group](reference/task-group-class.md) e [concomição::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) para representar grupos de tarefas e a classe [de task_handle para](../../parallel/concrt/reference/task-handle-class.md) representar as tarefas executadas nesses grupos. A `task_handle` classe encapsula o código que realiza o trabalho. Como `task` a classe, a função de trabalho vem na forma de uma função lambda, ponteiro de função ou objeto de função. Você normalmente não precisa `task_handle` trabalhar diretamente com objetos. Em vez disso, você passa funções de trabalho para um `task_handle` grupo de tarefas e o grupo de tarefas cria e gerencia os objetos.

O PPL divide os grupos de tarefas nessas duas categorias: *grupos de tarefas não estruturados* e *grupos de tarefas estruturados*. O PPL `task_group` usa a classe para representar `structured_task_group` grupos de tarefas não estruturados e a classe para representar grupos de tarefas estruturados.

> [!IMPORTANT]
> O PPL também define o algoritmo [de concurrency::parallel_invoke,](reference/concurrency-namespace-functions.md#parallel_invoke) que usa a `structured_task_group` classe para executar um conjunto de tarefas em paralelo. Como `parallel_invoke` o algoritmo tem uma sintaxe mais sucinta, `structured_task_group` recomendamos que você use em vez da classe quando puder. O tópico [Algoritmos Paralelos](../../parallel/concrt/parallel-algorithms.md) descreve com mais detalhes. `parallel_invoke`

Use `parallel_invoke` quando você tiver várias tarefas independentes que deseja executar ao mesmo tempo, e você deve esperar que todas as tarefas sejam concluídas antes de continuar. Esta técnica é muitas vezes referida como *garfo e unir* paralelismo. Use `task_group` quando você tiver várias tarefas independentes que deseja executar ao mesmo tempo, mas deseja esperar que as tarefas sejam concluídas posteriormente. Por exemplo, você pode `task_group` adicionar tarefas a um objeto e esperar que as tarefas sejam concluídas em outra função ou de outro segmento.

Grupos de tarefas apoiam o conceito de cancelamento. O cancelamento permite que você sinalize para todas as tarefas ativas que deseja cancelar a operação geral. O cancelamento também impede que tarefas que ainda não começaram comecem. Para obter mais informações sobre cancelamento, consulte [Cancelamento no PPL](cancellation-in-the-ppl.md).

O tempo de execução também fornece um modelo de manipulação de exceções que permite que você lance uma exceção de uma tarefa e manuseie essa exceção quando você espera que o grupo de tarefas associado seja concluído. Para obter mais informações sobre este modelo de tratamento de exceções, consulte [Manipulação de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="comparing-task_group-to-structured_task_group"></a><a name="comparing-groups"></a>Comparando task_group com structured_task_group

Embora recomendamos que `task_group` `parallel_invoke` você use `structured_task_group` ou em vez da classe, há casos em que você deseja usar, `structured_task_group`por exemplo, quando você escreve um algoritmo paralelo que executa um número variável de tarefas ou requer suporte para cancelamento. Esta seção explica `task_group` as `structured_task_group` diferenças entre as classes e as classes.

A `task_group` aula é segura para fios. Portanto, você pode adicionar `task_group` tarefas a um objeto a `task_group` partir de vários threads e esperar ou cancelar um objeto de vários segmentos. A construção e `structured_task_group` destruição de um objeto deve ocorrer no mesmo escopo léxico. Além disso, todas `structured_task_group` as operações em um objeto devem ocorrer no mesmo segmento. A exceção a esta regra é a [simultânea::structured_task_group::cancele](reference/structured-task-group-class.md#cancel) e [conemana:structured_task_group::is_canceling](reference/structured-task-group-class.md#is_canceling) métodos. Uma tarefa filho pode chamar esses métodos para cancelar o grupo de tarefas dos pais ou verificar se há cancelamento a qualquer momento.

Você pode executar tarefas adicionais em um `task_group` objeto depois de chamar a [concorrência::task_group::esperar](reference/task-group-class.md#wait) ou [concorrer::task_group:run_and_wait](reference/task-group-class.md#run_and_wait) método. Por outro lado, se você `structured_task_group` executar tarefas adicionais em um objeto depois de chamar a [concorrência::structured_task_group::esperar](reference/structured-task-group-class.md#wait) ou [concorrer::structured_task_group:run_and_wait](reference/structured-task-group-class.md#run_and_wait) métodos, o comportamento é indefinido.

Como `structured_task_group` a classe não sincroniza entre os segmentos, `task_group` ela tem menos sobrecarga de execução do que a classe. Portanto, se o seu problema não exigir que você agende `parallel_invoke` o `structured_task_group` trabalho a partir de vários threads e você não puder usar o algoritmo, a classe pode ajudá-lo a escrever um código de melhor desempenho.

Se você `structured_task_group` usar um `structured_task_group` objeto dentro de outro objeto, o objeto interno deve ser finalizado e destruído antes que o objeto externo termine. A `task_group` classe não exige que grupos de tarefas aninhados terminem antes que o grupo externo termine.

Grupos de tarefas não estruturados e grupos de tarefas estruturados trabalham com alças de tarefas de diferentes maneiras. Você pode passar funções `task_group` de trabalho diretamente para um objeto; o `task_group` objeto criará e gerenciará a alça de tarefa para você. A `structured_task_group` classe exige que `task_handle` você gerencie um objeto para cada tarefa. Cada `task_handle` objeto deve permanecer válido durante `structured_task_group` toda a vida útil de seu objeto associado. Use a [função simultuou::make_task](reference/concurrency-namespace-functions.md#make_task) para criar um `task_handle` objeto, conforme mostrado no exemplo básico a seguir:

[!code-cpp[concrt-make-task-structure#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_16.cpp)]

Para gerenciar as alças de tarefas para casos em que você tenha um número variável de tarefas, use uma rotina de alocação de pilhas, como [_malloca](../../c-runtime-library/reference/malloca.md) ou uma classe de contêiner, como std::[vector](../../standard-library/vector-class.md).

Ambos `task_group` `structured_task_group` e cancelamento de suporte. Para obter mais informações sobre cancelamento, consulte [Cancelamento no PPL](cancellation-in-the-ppl.md).

## <a name="example"></a><a name="example"></a>Exemplo

O exemplo básico a seguir mostra como trabalhar com grupos de tarefas. Este exemplo `parallel_invoke` usa o algoritmo para executar duas tarefas simultaneamente. Cada tarefa adiciona subtarefas a um `task_group` objeto. Observe que `task_group` a classe permite que várias tarefas adicionem tarefas a ela simultaneamente.

[!code-cpp[concrt-using-task-groups#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_17.cpp)]

A seguir está a saída de amostra para este exemplo:

```Output
Message from task: Hello
Message from task: 3.14
Message from task: 42
```

Como `parallel_invoke` o algoritmo executa tarefas simultaneamente, a ordem das mensagens de saída pode variar.

Para exemplos completos que mostram `parallel_invoke` como usar o algoritmo, veja [Como: Usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md) e [como: Usar parallel_invoke para executar operações paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md). Para um exemplo completo `task_group` que usa a classe para implementar futuros assíncronos, consulte [Passo a Passo: Implementando Futuros](../../parallel/concrt/walkthrough-implementing-futures.md).

## <a name="robust-programming"></a><a name="robust"></a>Programação Robusta

Certifique-se de entender o papel do cancelamento e do tratamento de exceções quando você usa tarefas, grupos de tarefas e algoritmos paralelos. Por exemplo, em uma árvore de trabalho paralelo, uma tarefa que é cancelada impede que tarefas de crianças sejam executados. Isso pode causar problemas se uma das tarefas da criança realizar uma operação que é importante para a sua aplicação, como liberar um recurso. Além disso, se uma tarefa infantil lançar uma exceção, essa exceção pode se propagar através de um destructor de objeto e causar comportamento indefinido em sua aplicação. Para um exemplo que ilustra esses pontos, consulte a seção Entender como o cancelamento e o tratamento de exceções afetam a [destruição de objetos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) na seção Práticas recomendadas no documento da Biblioteca de Padrões Paralelos. Para obter mais informações sobre os modelos de cancelamento e de manipulação de exceções no PPL, consulte [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md) e [Tratamento de Exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="related-topics"></a>Tópicos Relacionados

|Title|Descrição|
|-----------|-----------------|
|[Como usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)|Mostra como usar `parallel_invoke` o algoritmo para melhorar o desempenho do algoritmo bitônico.|
|[Como: Usar parallel_invoke para executar operações paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)|Mostra como usar `parallel_invoke` o algoritmo para melhorar o desempenho de um programa que realiza várias operações em uma fonte de dados compartilhada.|
|[Como criar uma tarefa que seja concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md)|Mostra como usar `task` `cancellation_token_source`as `cancellation_token`classes `task_completion_event` e as classes para criar uma tarefa que se completa após um atraso.|
|[Instruções passo a passo: implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)|Mostra como combinar a funcionalidade existente no Tempo de Execução de Concorrência em algo que faz mais.|
|[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve o PPL, que fornece um modelo de programação imperativo para o desenvolvimento de aplicações simultâneas.|

## <a name="reference"></a>Referência

[classe de tarefa (Tempo de execução de concorrência)](../../parallel/concrt/reference/task-class.md)

[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)

[Função when_all](reference/concurrency-namespace-functions.md#when_all)

[função when_any](reference/concurrency-namespace-functions.md#when_any)

[Classe task_group](reference/task-group-class.md)

[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)

[Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)
