---
title: Paralelismo de tarefa (tempo de execução de simultaneidade)
ms.date: 11/04/2016
helpviewer_keywords:
- structured task groups [Concurrency Runtime]
- structured tasks [Concurrency Runtime]
- task groups [Concurrency Runtime]
- task parallelism
- tasks [Concurrency Runtime]
ms.assetid: 42f05ac3-2098-494a-ba84-737fcdcad077
ms.openlocfilehash: c9f18dfd1498538ce3700fd73a27ce6f6088ee42
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62180037"
---
# <a name="task-parallelism-concurrency-runtime"></a>Paralelismo de tarefa (tempo de execução de simultaneidade)

No tempo de execução de simultaneidade, uma *tarefa* é uma unidade de trabalho que executa um trabalho específico e normalmente é executado em paralelo com outras tarefas. Uma tarefa pode ser decomposta em tarefas adicionais mais refinadas que são organizadas em uma *grupo de tarefas*.

Use tarefas quando você escrever código assíncrono e deseja que qualquer operação ocorra após a conclusão da operação assíncrona. Por exemplo, você poderia usar uma tarefa para ler de um arquivo de forma assíncrona e, em seguida, usar outra tarefa — uma *tarefa de continuação*, que é explicado mais adiante neste documento — para processar os dados, ela fica disponível. Por outro lado, você pode usar grupos de tarefas para decompo trabalho paralelo em partes menores. Por exemplo, suponha que você tenha um algoritmo recursivo que divide o trabalho restante em duas partições. Você pode usar grupos de tarefas para executar simultaneamente esses partições e, em seguida, aguarde o trabalho dividido se conclua.

> [!TIP]
> Quando você deseja aplicar a mesma rotina para cada elemento de uma coleção em paralelo, use um algoritmo paralelo, como [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for), em vez de uma tarefa ou um grupo de tarefas. Para obter mais informações sobre os algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="key-points"></a>Pontos-chave

- Ao passar as variáveis para uma expressão lambda por referência, você deve assegurar que o tempo de vida da variável persiste até que a tarefa seja concluída.

- Use tarefas (a [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) classe) ao escrever código assíncrono. A classe de tarefa usa o pool de threads do Windows como seu Agendador, não o tempo de execução de simultaneidade.

- Usar grupos de tarefas (a [Concurrency:: task_group](reference/task-group-class.md) classe ou o [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo) quando você deseja decompor o trabalho paralelo em partes menores e, em seguida, aguarde os menores peças para ser concluída.

- Use o [concurrency::task::then](reference/task-class.md#then) método para criar continuações. Um *continuação* é uma tarefa que executa de forma assíncrona após outra tarefa terminar. Você pode se conectar a qualquer número de continuações para formar uma cadeia de trabalho assíncrono.

- Uma continuação baseada em tarefa sempre é agendada para execução quando a tarefa antecedente é concluída, mesmo quando a tarefa antecedente é cancelada ou gera uma exceção.

- Use [when_all](reference/concurrency-namespace-functions.md#when_all) para criar uma tarefa que termine após a conclusão de todos os membros de um conjunto de tarefas. Use [Concurrency:: when_any](reference/concurrency-namespace-functions.md#when_any) para criar uma tarefa que termine após a conclusão de um membro de um conjunto de tarefas.

- Tarefas e grupos de tarefas podem participar do mecanismo de cancelamento da biblioteca de padrões paralelos (PPL). Para obter mais informações, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).

- Para saber como o tempo de execução trata exceções que são geradas por tarefas e grupos de tarefas, consulte [tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="in-this-document"></a>Neste Documento

- [Usando expressões Lambda](#lambdas)

- [A classe task](#task-class)

- [Tarefas de continuação](#continuations)

- [Com base no valor Versus continuações de tarefa](#value-versus-task)

- [Compondo tarefas](#composing-tasks)

    - [A função when_all](#when-all)

    - [A função when_any](#when-any)

- [Execução de tarefa com atraso](#delayed-tasks)

- [Grupos de tarefas](#task-groups)

- [Comparando task_group a structured_task_group](#comparing-groups)

- [Exemplo](#example)

- [Programação robusta](#robust)

##  <a name="lambdas"></a> Usando expressões Lambda

Por causa de sua sintaxe sucinta, expressões lambda são uma maneira comum de definir o trabalho que é executado por tarefas e grupos de tarefas. Aqui estão algumas dicas de uso:

- Como as tarefas normalmente executadas em threads em segundo plano, lembre-se de que o tempo de vida do objeto ao capturar variáveis em expressões lambda. Quando você captura uma variável por valor, é feita uma cópia da variável no corpo do lambda. Ao capturar por referência, não é feita uma cópia. Portanto, certifique-se de que o tempo de vida de qualquer variável que você capture por referência dura mais do que a tarefa que o utiliza.

- Quando você passa uma expressão lambda para uma tarefa, não capture variáveis que são alocadas na pilha por referência.

- Seja explícito sobre as variáveis que você captura nas expressões lambda para que você possa identificar o que você está capturando por valor versus por referência. Por esse motivo, é recomendável que você não use o `[=]` ou `[&]` opções para expressões lambda.

Um padrão comum é quando uma tarefa em uma cadeia de continuação atribui a uma variável, e outra tarefa lê a variável. Você não pode capturar por valor porque cada tarefa de continuação seria manter uma cópia diferente da variável. Para variáveis alocadas de pilha, você também não é possível capturar por referência porque a variável pode não ser mais válida.

Para resolver esse problema, use um ponteiro inteligente, como [std:: shared_ptr](../../standard-library/shared-ptr-class.md), para envolver a variável e passar o ponteiro inteligente por valor. Dessa forma, o objeto subjacente pode ser atribuído a ler e irá sobreviver além as tarefas que usá-lo. Use essa técnica mesmo quando a variável é um ponteiro ou um identificador contado por referência (`^`) a um objeto de tempo de execução do Windows. Aqui está um exemplo básico:

[!code-cpp[concrt-lambda-task-lifetime#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_1.cpp)]

Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

##  <a name="task-class"></a> A classe task

Você pode usar o [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) classe para compor tarefas em um conjunto de operações dependentes. Esse modelo de composição é compatível com a noção de *continuações*. Um continuação permite o código a ser executado quando o anterior, ou *antecedente*, tarefa é concluída. O resultado da tarefa antecedente é passado como entrada para as tarefas de continuação de um ou mais. Quando uma tarefa antecedente é concluída, as tarefas de continuação que estão aguardando estão agendadas para execução. Cada tarefa de continuação recebe uma cópia do resultado da tarefa antecedente. Por sua vez, essas tarefas de continuação também podem ser tarefas antecedentes para outras continuações, criando em uma cadeia de tarefas. As continuações ajudam você a criar cadeias de comprimento arbitrário de tarefas que têm dependências específicas entre elas. Além disso, uma tarefa pode participar no cancelamento antes de uma lista de tarefas é iniciado ou de forma cooperativa durante a execução. Para obter mais informações sobre esse modelo de cancelamento, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).

`task` é uma classe de modelo. O parâmetro de tipo `T` é o tipo do resultado produzido pela tarefa. Esse tipo pode ser `void` se a tarefa não retornar um valor. `T` não é possível usar o `const` modificador.

Quando você cria uma tarefa, você fornece um *função de trabalho* que executa o corpo da tarefa. Essa função de trabalho vem na forma de uma função lambda, um ponteiro de função ou um objeto de função. Para aguardar uma tarefa terminar sem obter o resultado, chame o [concurrency::task::wait](reference/task-class.md#wait) método. O `task::wait` método retorna um [Concurrency:: task_status](reference/concurrency-namespace-enums.md#task_group_status) valor que descreve se a tarefa foi concluída ou cancelada. Para obter o resultado da tarefa, chame o [concurrency::task::get](reference/task-class.md#get) método. Este método chama `task::wait` para aguardar a tarefa para concluir e, portanto, bloqueia a execução do thread atual até que o resultado esteja disponível.

O exemplo a seguir mostra como criar uma tarefa, esperar seu resultado e exibir seu valor. Os exemplos nesta documentação usam funções lambda porque elas fornecem uma sintaxe mais sucinta. No entanto, você também pode usar a ponteiros de função e objetos de função quando você usa tarefas.

[!code-cpp[concrt-basic-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_2.cpp)]

Quando você usa o [Concurrency:: create_task](reference/concurrency-namespace-functions.md#create_task) função, você pode usar o `auto` palavra-chave em vez de declarar o tipo. Por exemplo, considere este código que cria e imprime a matriz de identidade:

[!code-cpp[concrt-create-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_3.cpp)]

Você pode usar o `create_task` função para criar a operação equivalente.

[!code-cpp[concrt-create-task#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_4.cpp)]

Se uma exceção for gerada durante a execução de uma tarefa, o tempo de execução efetua marshaling dessa exceção na chamada subsequente para `task::get` ou `task::wait`, ou para uma continuação baseada em tarefa. Para obter mais informações sobre o mecanismo de tratamento de exceção de tarefa, consulte [tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

Para obter um exemplo que usa `task`, [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), cancelamento, consulte [passo a passo: Conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md). (O `task_completion_event` classe é descrita posteriormente neste documento.)

> [!TIP]
>  Para saber detalhes que são específicos para tarefas em aplicativos UWP, consulte [programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) e [criando a operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).

##  <a name="continuations"></a> Tarefas de continuação

Na programação assíncrona, é muito comum para uma operação assíncrona, após a conclusão, invocar uma segunda operação e passar dados para ela. Tradicionalmente, isso é feito usando métodos de retorno de chamada. No tempo de execução de simultaneidade, a mesma funcionalidade é fornecida pela *tarefas de continuação*. Uma tarefa de continuação (também conhecida apenas como uma continuação) é uma tarefa assíncrona que é invocada por outra tarefa, que é conhecida como o *antecedente*, quando o antecedente é concluído. Usando continuações, você pode:

- Passe dados da antecessora para a continuação.

- Especifica as condições precisas sob as quais a continuação é ou não invocada.

- Cancele uma continuação antes que ele inicie ou cooperativamente enquanto ela está em execução.

- Forneça dicas sobre como a continuação deve ser agendada. (Isso se aplica somente a aplicativos de plataforma Universal do Windows (UWP). Para obter mais informações, consulte [criando a operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).)

- Invoque várias continuações da mesma antecessora.

- Invoque uma continuação quando todos ou qualquer um dos vários antecedentes forem concluídas.

- Continuações de encadeamento uma após a outra para qualquer comprimento.

- Use uma continuação para manipular exceções geradas pelo antecedente.

Esses recursos permitem que você execute uma ou mais tarefas quando a primeira tarefa é concluída. Por exemplo, você pode criar uma continuação que compacte um arquivo depois que a primeira tarefa o ler no disco.

O exemplo a seguir modifica o exemplo anterior para usar o [concurrency::task::then](reference/task-class.md#then) método para agendar uma continuação que imprime o valor da tarefa antecedente quando ele estiver disponível.

[!code-cpp[concrt-basic-continuation#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_5.cpp)]

Você pode encadear e aninhar as tarefas para qualquer comprimento. Uma tarefa também pode ter várias continuações. O exemplo a seguir ilustra uma cadeia básica de continuação que incrementa o valor da tarefa anterior três vezes.

[!code-cpp[concrt-continuation-chain#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_6.cpp)]

Uma continuação também pode retornar outra tarefa. Se não houver cancelamento, essa tarefa é executada antes da continuação subsequente. Essa técnica é conhecida como *desempacotamento assíncrono*. O desempacotamento assíncrono é útil quando você deseja realizar o trabalho adicional em segundo plano, mas não quiser que a tarefa atual bloqueie o thread atual. (Isso é comum em aplicativos UWP, onde as continuações podem ser executado no thread da interface do usuário). O exemplo a seguir mostra três tarefas. A primeira tarefa retorna outra tarefa é executada antes de uma tarefa de continuação.

[!code-cpp[concrt-async-unwrapping#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_7.cpp)]

> [!IMPORTANT]
>  Quando uma continuação de uma tarefa retorna uma tarefa aninhada do tipo `N`, a tarefa resultante tem o tipo `N`, e não `task<N>`e termina quando a tarefa aninhada completa. Em outras palavras, a continuação executa o desempacotamento da tarefa aninhada.

##  <a name="value-versus-task"></a> Com base no valor Versus continuações de tarefa

Considerando um `task` objeto cujo tipo de retorno é `T`, você pode fornecer um valor do tipo `T` ou `task<T>` a suas tarefas de continuação. Uma continuação que usa o tipo `T` é conhecido como um *continuação baseada em valor*. Uma continuação baseada em valor é agendada para execução quando a tarefa antecedente é concluído sem erros e não for cancelada. Uma continuação que usa o tipo `task<T>` como seu parâmetro é conhecido como um *continuação baseada em tarefa*. Uma continuação baseada em tarefa sempre é agendada para execução quando a tarefa antecedente é concluída, mesmo quando a tarefa antecedente é cancelada ou gera uma exceção. Em seguida, você pode chamar `task::get` para obter o resultado da tarefa antecedente. Se a tarefa antecedente tiver sido cancelada, `task::get` lança [Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md). Se a tarefa antecedente gerou uma exceção, `task::get` gerará novamente a exceção. Uma continuação baseada em tarefa não é marcada como cancelada quando sua tarefa antecedente é cancelada.

##  <a name="composing-tasks"></a> Compondo tarefas

Esta seção descreve o [when_all](reference/concurrency-namespace-functions.md#when_all) e [Concurrency:: when_any](reference/concurrency-namespace-functions.md#when_all) funções, que podem ajudá-lo a compõem várias tarefas para implementar padrões comuns.

###  <a name="when-all"></a> A função when_all

O `when_all` função produz uma tarefa que termine após a conclusão de um conjunto de tarefas. Essa função retorna um std::[vetor](../../standard-library/vector-class.md) objeto que contém o resultado de cada tarefa no conjunto. O exemplo básico a seguir usa `when_all` para criar uma tarefa que representa a conclusão de três outras tarefas.

[!code-cpp[concrt-join-tasks#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_8.cpp)]

> [!NOTE]
>  As tarefas que você passa para `when_all` devem ser uniformes. Em outras palavras, eles devem todas retornar o mesmo tipo.

Você também pode usar o `&&` sintaxe para gerar uma tarefa que termine após a conclusão de um conjunto de tarefas, conforme mostrado no exemplo a seguir.

`auto t = t1 && t2; // same as when_all`

É comum usar uma continuação junto com `when_all` para executar uma ação após a conclusão de um conjunto de tarefas. O exemplo a seguir modifica o exemplo anterior para imprimir a soma das três tarefas que cada um, produzir um `int` resultado.

[!code-cpp[concrt-join-tasks#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_9.cpp)]

Neste exemplo, você também pode especificar `task<vector<int>>` para produzir uma continuação baseada em tarefa.

Se qualquer tarefa em um conjunto de tarefas for cancelada ou lançar uma exceção, `when_all` concluído imediatamente e não aguarda a conclusão das tarefas restantes. Se uma exceção for lançada, o tempo de execução gera novamente a exceção ao chamar `task::get` ou `task::wait` no objeto de tarefa que `when_all` retorna. Se mais de uma tarefa for gerada, o tempo de execução escolherá um deles. Portanto, certifique-se de que você observa todas as exceções depois de concluir todas as tarefas; uma exceção sem tratamento tarefa faz com que o aplicativo seja finalizado.

Aqui está uma função de utilitário que você pode usar para garantir que seu programa Observe todas as exceções. Para cada tarefa no intervalo fornecido, `observe_all_exceptions` dispara qualquer exceção que ocorreu para ser relançada e então engole essa exceção.

[!code-cpp[concrt-eh-when_all#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_10.cpp)]

Considere um aplicativo UWP que usa C++ e XAML e grava um conjunto de arquivos no disco. O exemplo a seguir mostra como usar `when_all` e `observe_all_exceptions` para garantir que o programa Observe todas as exceções.

[!code-cpp[concrt-eh-when_all#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_11.cpp)]

##### <a name="to-run-this-example"></a>Para executar este exemplo

1. Em MainPage. XAML, adicione um `Button` controle.

[!code-xml[concrt-eh-when_all#3](../../parallel/concrt/codesnippet/xaml/task-parallelism-concurrency-runtime_12.xaml)]

1. Em MainPage, adicione estas declarações de encaminhamento para o `private` seção o `MainPage` declaração de classe.

[!code-cpp[concrt-eh-when_all#4](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_13.h)]

1. Em MainPage, implemente o `Button_Click` manipulador de eventos.

[!code-cpp[concrt-eh-when_all#5](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_14.cpp)]

1. Em MainPage, implementar `WriteFilesAsync` conforme mostrado no exemplo.

> [!TIP]
> `when_all` é uma função sem bloqueio que produz um `task` como resultado. Diferentemente [Task:: wait](reference/task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no thread de ASTA (aplicativo STA).

###  <a name="when-any"></a> A função when_any

O `when_any` função produz uma tarefa que termina quando a primeira tarefa em um conjunto de tarefas é concluída. Essa função retorna um [std:: Pair](../../standard-library/pair-structure.md) objeto que contém o resultado da tarefa concluída e o índice da tarefa no conjunto.

O `when_any` função é especialmente útil nos seguintes cenários:

- Operações redundantes. Considere um algoritmo ou uma operação que possam ser executados de várias maneiras. Você pode usar o `when_any` função para selecionar a operação que termina primeiro e, em seguida, cancelar as operações restantes.

- Operações intercaladas. Você pode iniciar várias operações que devem ser concluídas e usar o `when_any` função para processar resultados à medida que cada operação é concluída. Após uma operação ser concluída, você poderá começar uma ou mais tarefas adicionais.

- Operações controladas. Você pode usar o `when_any` função para estender o cenário anterior limitando o número de operações simultâneas.

- Operações expiradas. Você pode usar o `when_any` para selecionar entre uma ou mais tarefas e uma tarefa que termine após um tempo específico.

Assim como acontece com `when_all`, é comum usar uma continuação que tem `when_any` para executar a ação quando concluir o primeiro em um conjunto de tarefas. O exemplo básico a seguir usa `when_any` para criar uma tarefa que é concluída quando a primeira de três outras tarefas é concluída.

[!code-cpp[concrt-select-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_15.cpp)]

Neste exemplo, você também pode especificar `task<pair<int, size_t>>` para produzir uma continuação baseada em tarefa.

> [!NOTE]
> Assim como acontece com `when_all`, as tarefas que você passa para `when_any` devem todas retornar o mesmo tipo.

Você também pode usar o `||` sintaxe para produzir uma tarefa que termine após a primeira tarefa em um conjunto de tarefas, conforme mostrado no exemplo a seguir.

`auto t = t1 || t2; // same as when_any`

> [!TIP]
> Assim como acontece com `when_all`, `when_any` é desbloqueado e é seguro chamar em um aplicativo UWP no segmento de ASTA.

##  <a name="delayed-tasks"></a> Execução de tarefa com atraso

Às vezes, é necessário para atrasar a execução de uma tarefa até que uma condição seja atendida ou para iniciar uma tarefa em resposta a um evento externo. Por exemplo, na programação assíncrona, você talvez precise iniciar uma tarefa em resposta a um evento de conclusão de e/s.

Duas maneiras de fazer isso são usar uma continuação ou iniciar uma tarefa e aguardar um evento dentro da função de trabalho da tarefa. No entanto, há casos em que ele não é possível usar uma dessas técnicas. Por exemplo, para criar uma continuação, você deve ter a tarefa antecedente. No entanto, se você não tiver a tarefa antecedente, você pode criar uma *evento de conclusão de tarefa* e uma cadeia posterior que concluirá o evento para a tarefa antecedente quando ele estiver disponível. Além disso, como uma tarefa de espera também bloqueia um thread, você pode usar eventos de conclusão de tarefas para executar o trabalho quando uma operação assíncrona é concluída e gratuito, portanto, um thread.

O [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) classe ajuda a simplificar tal composição de tarefas. Como o `task` classe, o parâmetro de tipo `T` é o tipo do resultado produzido pela tarefa. Esse tipo pode ser `void` se a tarefa não retornar um valor. `T` não é possível usar o `const` modificador. Normalmente, um `task_completion_event` objeto é fornecido para um thread ou tarefa que sinalizará quando o valor para que ele se torna disponível. Ao mesmo tempo, uma ou mais tarefas são definidas como ouvintes do evento. Quando o evento é definido, as tarefas de ouvinte completam e suas continuações são agendadas para execução.

Para obter um exemplo que usa `task_completion_event` para implementar uma tarefa que termine após um atraso, consulte [como: Criar uma tarefa que termine após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md).

##  <a name="task-groups"></a> Grupos de tarefas

Um *grupo de tarefas* organiza uma coleção de tarefas. Grupos de tarefas enviam tarefas para uma fila de roubo de trabalho. O Agendador remove tarefas dessa fila e as executa nos recursos de computação disponíveis. Depois de adicionar tarefas a um grupo de tarefas, você pode esperar para todas as tarefas concluir ou cancelar as tarefas que ainda não iniciaram.

O PPL usa a [Concurrency:: task_group](reference/task-group-class.md) e [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes para representar grupos de tarefas e o [Concurrency:: task_handle](../../parallel/concrt/reference/task-handle-class.md) classe para representar as tarefas executadas nesses grupos. O `task_handle` classe encapsula o código que executa o trabalho. Como o `task` classe, a função de trabalho vem na forma de uma função lambda, um ponteiro de função ou um objeto de função. Você normalmente não é necessário trabalhar com `task_handle` objetos diretamente. Em vez disso, você passa funções de trabalho para um grupo de tarefas, e o grupo de tarefas cria e gerencia o `task_handle` objetos.

O PPL divide grupos de tarefas nessas duas categorias: *grupos de tarefas não estruturados* e *estruturado de grupos de tarefas*. O PPL usa a `task_group` classe para representar grupos de tarefas não estruturados e o `structured_task_group` classe para representar grupos de tarefas estruturados.

> [!IMPORTANT]
> O PPL também define o [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo, que utiliza o `structured_task_group` classe para executar um conjunto de tarefas em paralelo. Porque o `parallel_invoke` algoritmo tem uma sintaxe mais sucinta, recomendamos que você usá-lo em vez do `structured_task_group` classe quando possível. O tópico [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md) descreve `parallel_invoke` mais detalhadamente.

Use `parallel_invoke` quando você tiver várias tarefas independentes que você deseja executar ao mesmo tempo, e você deve aguardar todas as tarefas sejam concluídas antes de continuar. Essa técnica é conhecida como *bifurcação e junção* paralelismo. Use `task_group` quando você tem várias tarefas independentes que você deseja executar ao mesmo tempo, mas você deseja esperar as tarefas sejam concluídas em um momento posterior. Por exemplo, você pode adicionar tarefas para um `task_group` de objeto e aguarde até que as tarefas sejam finalizadas em outra função ou de outro thread.

Grupos de tarefas suportam o conceito de cancelamento. Cancelamento permite que você sinalize a todas as tarefas ativas que você deseja cancelar a operação geral. Cancelamento também impede que as tarefas que ainda não iniciaram seja iniciado. Para obter mais informações sobre cancelamento, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).

O tempo de execução também fornece um modelo de tratamento de exceção que permite que você lance uma exceção de uma tarefa e tratar essa exceção quando espera para o grupo de tarefas associada ao fim. Para obter mais informações sobre esse modelo de tratamento de exceções, consulte [tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

##  <a name="comparing-groups"></a> Comparando task_group a structured_task_group

Embora seja recomendável que você use `task_group` ou `parallel_invoke` em vez da `structured_task_group` da classe, há casos em que você deseja usar `structured_task_group`, por exemplo, quando você escreve um algoritmo paralelo que executa um número variável de tarefas ou requer suporte ao cancelamento. Esta seção explica as diferenças entre o `task_group` e `structured_task_group` classes.

O `task_group` classe é thread-safe. Portanto, você pode adicionar tarefas para um `task_group` do objeto de vários threads e aguardar ou cancelar um `task_group` objeto de vários threads. A construção e destruição de um `structured_task_group` objeto deve ocorrer no mesmo escopo léxico. Além disso, todas as operações em um `structured_task_group` objeto deve ocorrer no mesmo thread. A exceção a essa regra é o [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) e [concurrency::structured_task_group::is_canceling](reference/structured-task-group-class.md#is_canceling) métodos. Uma tarefa filho pode chamar esses métodos para cancelar o grupo de tarefas pai ou verificar se há cancelamento a qualquer momento.

Você pode executar tarefas adicionais em uma `task_group` do objeto depois de chamar o [concurrency::task_group::wait](reference/task-group-class.md#wait) ou [concurrency::task_group::run_and_wait](reference/task-group-class.md#run_and_wait) método. Por outro lado, se você executar tarefas adicionais em uma `structured_task_group` do objeto depois de chamar o [concurrency::structured_task_group::wait](reference/structured-task-group-class.md#wait) ou [concurrency::structured_task_group::run_and_wait](reference/structured-task-group-class.md#run_and_wait) métodos , em seguida, o comportamento será indefinido.

Porque o `structured_task_group` classe não sincroniza entre threads, ele tem menos sobrecarga da execução de `task_group` classe. Portanto, se o problema não exigir que você agende o trabalho de vários threads e não é possível usar o `parallel_invoke` algoritmo, o `structured_task_group` classe pode ajudá-lo a escrever código de melhor desempenho.

Se você usar um `structured_task_group` objeto dentro de outro `structured_task_group` objeto, o objeto interno deverá ser concluído e destruído antes que o objeto externo conclua. O `task_group` classe não exige grupos de trabalho aninhados concluir antes do grupo externo concluir.

Grupos de tarefas não estruturados e grupos de tarefas estruturados funcionam com alças de tarefa de maneiras diferentes. Você pode passar funções de trabalho diretamente para um `task_group` do objeto; o `task_group` objeto criará e gerenciará o identificador de tarefa para você. O `structured_task_group` classe requer que você gerencie um `task_handle` objeto para cada tarefa. Cada `task_handle` objeto deve permanecer válido durante toda a vida útil de seus associados `structured_task_group` objeto. Use o [Concurrency:: make_task](reference/concurrency-namespace-functions.md#make_task) função para criar um `task_handle` do objeto, conforme mostrado no exemplo básico a seguir:

[!code-cpp[concrt-make-task-structure#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_16.cpp)]

Para gerenciar a manipulação de tarefas nos casos em que você tem um número variável de tarefas, use uma rotina de alocação da pilha, como [malloca](../../c-runtime-library/reference/malloca.md) ou uma classe de contêiner, como std::[vetor](../../standard-library/vector-class.md).

Ambos `task_group` e `structured_task_group` dão suporte ao cancelamento. Para obter mais informações sobre cancelamento, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).

##  <a name="example"></a> Exemplo

O exemplo básico a seguir mostra como trabalhar com grupos de tarefas. Este exemplo usa o `parallel_invoke` algoritmo para executar duas tarefas simultaneamente. Cada tarefa adiciona subtarefas a um `task_group` objeto. Observe que o `task_group` classe permite que várias tarefas adicionar tarefas nele simultaneamente.

[!code-cpp[concrt-using-task-groups#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_17.cpp)]

A seguir está a saída de exemplo para este exemplo:

```Output
Message from task: Hello
Message from task: 3.14
Message from task: 42
```

Porque o `parallel_invoke` algoritmo executa tarefas simultaneamente, a ordem das mensagens de saída pode variar.

Para obter exemplos completos que mostram como usar o `parallel_invoke` algoritmo, consulte [como: Usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md) e [como: Usar parallel_invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md). Para obter um exemplo completo que usa o `task_group` classe para implementar futuros assíncronos, consulte [passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md).

##  <a name="robust"></a> Programação robusta

Certifique-se de que você entenda a função de cancelamento e tratamento de exceções ao usar tarefas, grupos de tarefas e algoritmos paralelos. Por exemplo, em uma árvore de trabalho em paralelo, uma tarefa cancelada impede que tarefas filho em execução. Isso pode causar problemas se uma das tarefas filho executa uma operação que é importante para seu aplicativo, como liberar um recurso. Além disso, se uma tarefa filho lançar uma exceção, essa exceção poderia se propagar por meio de um destruidor de objeto e causar um comportamento indefinido em seu aplicativo. Para obter um exemplo que ilustra esses pontos, consulte a [compreender como cancelamento e destruição de tratamento afetam o objeto de exceção](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) seção práticas recomendadas no documento de biblioteca de padrões paralelos. Para obter mais informações sobre o cancelamento e modelos de tratamento de exceções no PPL, consulte [cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md) e [Exception Handling](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="related-topics"></a>Tópicos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Como: Usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho do algoritmo de classificação bitonic.|
|[Como: Usar parallel_invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada.|
|[Como: Criar uma tarefa que seja concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md)|Mostra como usar o `task`, `cancellation_token_source`, `cancellation_token`, e `task_completion_event` classes para criar uma tarefa que termine após um atraso.|
|[Passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)|Mostra como combinar a funcionalidade existente no tempo de execução de simultaneidade em algo mais útil.|
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve o PPL, que fornece um modelo imperativo de programação para desenvolver aplicativos simultâneos.|

## <a name="reference"></a>Referência

[Classe task (Tempo de Execução de Simultaneidade)](../../parallel/concrt/reference/task-class.md)

[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)

[Função when_all](reference/concurrency-namespace-functions.md#when_all)

[Função when_any](reference/concurrency-namespace-functions.md#when_any)

[Classe task_group](reference/task-group-class.md)

[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)

[Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)
