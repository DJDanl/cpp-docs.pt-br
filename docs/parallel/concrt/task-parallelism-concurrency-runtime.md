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
ms.openlocfilehash: 09c6153a1440684156226acbda909ca8b0398989
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224923"
---
# <a name="task-parallelism-concurrency-runtime"></a>Paralelismo de tarefa (runtime de simultaneidade)

Na Tempo de Execução de Simultaneidade, uma *tarefa* é uma unidade de trabalho que executa um trabalho específico e normalmente é executada em paralelo com outras tarefas. Uma tarefa pode ser decomposta em tarefas adicionais e mais refinadas que são organizadas em um *grupo de tarefas*.

Você usa tarefas quando escreve código assíncrono e deseja que alguma operação ocorra após a conclusão da operação assíncrona. Por exemplo, você pode usar uma tarefa para ler de forma assíncrona de um arquivo e, em seguida, usar outra tarefa — uma *tarefa de continuação*, que é explicada mais adiante neste documento — para processar os dados depois que ele se tornar disponível. Por outro lado, você pode usar grupos de tarefas para decompor trabalho paralelo em partes menores. Por exemplo, suponha que você tenha um algoritmo recursivo que divide o trabalho restante em duas partições. Você pode usar grupos de tarefas para executar essas partições simultaneamente e aguardar a conclusão do trabalho dividido.

> [!TIP]
> Quando você deseja aplicar a mesma rotina a todos os elementos de uma coleção em paralelo, use um algoritmo paralelo, como [simultaneidade::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for), em vez de uma tarefa ou grupo de tarefas. Para obter mais informações sobre algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="key-points"></a>Pontos Principais

- Ao passar variáveis para uma expressão lambda por referência, você deve garantir que o tempo de vida dessa variável persista até que a tarefa seja concluída.

- Use tarefas (a classe [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) ) ao escrever código assíncrono. A classe Task usa o ThreadPool do Windows como seu Agendador, não o Tempo de Execução de Simultaneidade.

- Use grupos de tarefas (a classe [Concurrency:: task_group](reference/task-group-class.md) ou o algoritmo [concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) ) quando desejar decompor um trabalho paralelo em partes menores e, em seguida, esperar que essas partes menores sejam concluídas.

- Use o método [Concurrency:: Task:: then](reference/task-class.md#then) para criar continuações. Uma *continuação* é uma tarefa executada de forma assíncrona após a conclusão de outra tarefa. Você pode conectar qualquer número de continuações para formar uma cadeia de trabalho assíncrono.

- Uma continuação baseada em tarefas é sempre agendada para execução quando a tarefa antecedente é concluída, mesmo quando a tarefa Antecedent é cancelada ou gera uma exceção.

- Use [Concurrency:: when_all](reference/concurrency-namespace-functions.md#when_all) para criar uma tarefa que é concluída após a conclusão de cada membro de um conjunto de tarefas. Use [Concurrency:: when_any](reference/concurrency-namespace-functions.md#when_any) para criar uma tarefa que é concluída após a conclusão de um membro de um conjunto de tarefas.

- Tarefas e grupos de tarefas podem participar do mecanismo de cancelamento da PPL (biblioteca de padrões paralelos). Para obter mais informações, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

- Para saber como o tempo de execução manipula exceções que são geradas por tarefas e grupos de tarefas, consulte [manipulação de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="in-this-document"></a>Neste Documento

- [Usando Expressões Lambda](#lambdas)

- [A Classe task](#task-class)

- [Tarefas de Continuação](#continuations)

- [Continuações com Base no Valor Contra com Base na Tarefa](#value-versus-task)

- [Compondo tarefas](#composing-tasks)

  - [A Função when_all](#when-all)

  - [A Função when_any](#when-any)

- [Execução da Tarefa com Atraso](#delayed-tasks)

- [Grupos de tarefas](#task-groups)

- [Comparando task_group a structured_task_group](#comparing-groups)

- [Exemplo](#example)

- [Programação robusta](#robust)

## <a name="using-lambda-expressions"></a><a name="lambdas"></a>Usando expressões lambda

Devido à sua sintaxe sucinta, as expressões lambda são uma maneira comum de definir o trabalho que é executado por tarefas e grupos de tarefas. Aqui estão algumas dicas de uso:

- Como as tarefas normalmente são executadas em threads em segundo plano, lembre-se do tempo de vida do objeto quando você captura variáveis em expressões lambda. Quando você captura uma variável por valor, uma cópia dessa variável é feita no corpo lambda. Quando você captura por referência, uma cópia não é feita. Portanto, certifique-se de que o tempo de vida de qualquer variável capturada por referência providará a tarefa que a utiliza.

- Quando você passa uma expressão lambda para uma tarefa, não Capture variáveis que são alocadas na pilha por referência.

- Seja explícito sobre as variáveis capturadas em expressões lambda para que você possa identificar o que está capturando por valor versus referência. Por esse motivo, recomendamos que você não use as `[=]` `[&]` Opções ou para expressões lambda.

Um padrão comum é quando uma tarefa em uma cadeia de continuação é atribuída a uma variável, e outra tarefa lê essa variável. Não é possível capturar por valor porque cada tarefa de continuação manteria uma cópia diferente da variável. Para variáveis alocadas para pilha, você também não pode capturar por referência porque a variável pode não ser mais válida.

Para resolver esse problema, use um ponteiro inteligente, como [std:: shared_ptr](../../standard-library/shared-ptr-class.md), para encapsular a variável e passar o ponteiro inteligente por valor. Dessa forma, o objeto subjacente pode ser atribuído e lido e sobreviver além as tarefas que o utilizam. Use essa técnica mesmo quando a variável for um ponteiro ou um identificador contado por referência ( `^` ) para um objeto Windows Runtime. Este é um exemplo básico:

[!code-cpp[concrt-lambda-task-lifetime#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_1.cpp)]

Para obter mais informações sobre expressões lambda, consulte [expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

## <a name="the-task-class"></a><a name="task-class"></a>A classe Task

Você pode usar a classe [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) para compor tarefas em um conjunto de operações dependentes. Esse modelo de composição tem suporte pela noção de *continuações*. Uma continuação permite que o código seja executado quando a tarefa anterior, ou *antecedente*, for concluída. O resultado da tarefa Antecedent é passado como a entrada para uma ou mais tarefas de continuação. Quando uma tarefa Antecedent é concluída, todas as tarefas de continuação que estão aguardando nela são agendadas para execução. Cada tarefa de continuação recebe uma cópia do resultado da tarefa Antecedent. Por sua vez, essas tarefas de continuação também podem ser tarefas antecedentes para outras continuações, criando assim uma cadeia de tarefas. As continuações ajudam a criar cadeias de comprimento arbitrário de tarefas que têm dependências específicas entre elas. Além disso, uma tarefa pode participar do cancelamento antes que as tarefas sejam iniciadas ou de maneira cooperativa enquanto estiverem em execução. Para obter mais informações sobre esse modelo de cancelamento, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

`task`é uma classe de modelo. O parâmetro de tipo `T` é o tipo do resultado que é produzido pela tarefa. Esse tipo pode ser **`void`** se a tarefa não retornar um valor. `T`Não é possível usar o **`const`** modificador.

Ao criar uma tarefa, você fornece uma *função de trabalho* que executa o corpo da tarefa. Essa função de trabalho vem na forma de uma função lambda, um ponteiro de função ou um objeto de função. Para aguardar a conclusão de uma tarefa sem obter o resultado, chame o método [Concurrency:: Task:: Wait](reference/task-class.md#wait) . O `task::wait` método retorna um valor [Concurrency:: task_status](reference/concurrency-namespace-enums.md#task_group_status) que descreve se a tarefa foi concluída ou cancelada. Para obter o resultado da tarefa, chame o método [Concurrency:: Task:: Get](reference/task-class.md#get) . Esse método chama `task::wait` para aguardar a conclusão da tarefa e, portanto, bloqueia a execução do thread atual até que o resultado esteja disponível.

O exemplo a seguir mostra como criar uma tarefa, aguardar seu resultado e exibir seu valor. Os exemplos nesta documentação usam funções lambda porque fornecem uma sintaxe mais sucinta. No entanto, você também pode usar ponteiros de função e objetos de função ao usar tarefas.

[!code-cpp[concrt-basic-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_2.cpp)]

Ao usar a função [Concurrency:: create_task](reference/concurrency-namespace-functions.md#create_task) , você pode usar a **`auto`** palavra-chave em vez de declarar o tipo. Por exemplo, considere esse código que cria e imprime a matriz de identidade:

[!code-cpp[concrt-create-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_3.cpp)]

Você pode usar a `create_task` função para criar a operação equivalente.

[!code-cpp[concrt-create-task#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_4.cpp)]

Se uma exceção for lançada durante a execução de uma tarefa, o tempo de execução realizará marshaling dessa exceção na chamada subsequente para `task::get` ou `task::wait` , ou para uma continuação baseada em tarefa. Para obter mais informações sobre o mecanismo de manipulação de exceção de tarefa, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

Para obter um exemplo que usa `task` , [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), o cancelamento, consulte [passo a passos: conectando-se usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md). (A `task_completion_event` classe é descrita mais adiante neste documento.)

> [!TIP]
> Para saber detalhes que são específicos para tarefas em aplicativos UWP, consulte [programação assíncrona em c++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) e [criando operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).

## <a name="continuation-tasks"></a><a name="continuations"></a>Tarefas de continuação

Na programação assíncrona, é muito comum para uma operação assíncrona, após a conclusão, invocar uma segunda operação e passar dados para ela. Tradicionalmente, isso é feito usando métodos de retorno de chamada. Na Tempo de Execução de Simultaneidade, a mesma funcionalidade é fornecida pelas *tarefas de continuação*. Uma tarefa de continuação (também conhecida como uma continuação) é uma tarefa assíncrona que é invocada por outra tarefa, que é conhecida como *Antecedent*, quando o Antecedent é concluído. Usando as continuações, você pode:

- Passe dados da antecessora para a continuação.

- Especifique as condições precisas sob as quais a continuação é invocada ou não é invocada.

- Cancele uma continuação antes que ela seja iniciada ou cooperante enquanto estiver em execução.

- Forneça dicas sobre como a continuação deve ser agendada. (Isso se aplica somente a aplicativos Plataforma Universal do Windows (UWP). Para obter mais informações, consulte [criando operações assíncronas em C++ para aplicativos UWP](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).)

- Invoque várias continuações da mesma antecessora.

- Invoque uma continuação quando toda ou qualquer um de vários antecedentes for concluído.

- As continuações de cadeia uma após a outra para qualquer comprimento.

- Use uma continuação para tratar as exceções que são geradas pelo Antecedent.

Esses recursos permitem que você execute uma ou mais tarefas quando a primeira tarefa é concluída. Por exemplo, você pode criar uma continuação que compacta um arquivo após a primeira tarefa lê-lo do disco.

O exemplo a seguir modifica o anterior para usar o método [Concurrency:: Task:: then](reference/task-class.md#then) para agendar uma continuação que imprime o valor da tarefa Antecedent quando ela estiver disponível.

[!code-cpp[concrt-basic-continuation#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_5.cpp)]

Você pode encadear e aninhar tarefas para qualquer comprimento. Uma tarefa também pode ter várias continuações. O exemplo a seguir ilustra uma cadeia de continuação básica que incrementa o valor da tarefa anterior três vezes.

[!code-cpp[concrt-continuation-chain#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_6.cpp)]

Uma continuação também pode retornar outra tarefa. Se não houver nenhum cancelamento, essa tarefa será executada antes da continuação subsequente. Essa técnica é conhecida como *desencapsulamento assíncrono*. O desencapsulamento assíncrono é útil quando você deseja executar trabalho adicional em segundo plano, mas não deseja que a tarefa atual bloqueie o thread atual. (Isso é comum em aplicativos UWP, onde as continuaçãos podem ser executadas no thread da interface do usuário). O exemplo a seguir mostra três tarefas. A primeira tarefa retorna outra tarefa que é executada antes de uma tarefa de continuação.

[!code-cpp[concrt-async-unwrapping#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_7.cpp)]

> [!IMPORTANT]
> Quando uma continuação de uma tarefa retorna uma tarefa aninhada do tipo `N` , a tarefa resultante tem o tipo `N` , não `task<N>` e é concluída quando a tarefa aninhada é concluída. Em outras palavras, a continuação executa o desencapsulamento da tarefa aninhada.

## <a name="value-based-versus-task-based-continuations"></a><a name="value-versus-task"></a>Continuação baseada em valor versus com base em tarefas

Dado um `task` objeto cujo tipo de retorno é `T` , você pode fornecer um valor do tipo `T` ou `task<T>` para suas tarefas de continuação. Uma continuação que recebe `T` o tipo é conhecida como uma *continuação baseada em valor*. Uma continuação baseada em valor é agendada para execução quando a tarefa antecedente é concluída sem erros e não é cancelada. Uma continuação que usa `task<T>` o tipo como seu parâmetro é conhecida como uma *continuação baseada em tarefa*. Uma continuação baseada em tarefas é sempre agendada para execução quando a tarefa antecedente é concluída, mesmo quando a tarefa Antecedent é cancelada ou gera uma exceção. Em seguida, você pode chamar `task::get` para obter o resultado da tarefa antecedente. Se a tarefa Antecedent foi cancelada, o `task::get` gera [Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md). Se a tarefa antecedenta gerou uma exceção, o `task::get` relança essa exceção. Uma continuação baseada em tarefa não é marcada como cancelada quando sua tarefa Antecedent é cancelada.

## <a name="composing-tasks"></a><a name="composing-tasks"></a>Compondo tarefas

Esta seção descreve as funções [Concurrency:: when_all](reference/concurrency-namespace-functions.md#when_all) e [concurrency:: when_any](reference/concurrency-namespace-functions.md#when_all) , que podem ajudá-lo a compor várias tarefas para implementar padrões comuns.

### <a name="the-when_all-function"></a><a name="when-all"></a>A função when_all

A `when_all` função produz uma tarefa concluída após a conclusão de um conjunto de tarefas. Essa função retorna um objeto std::[vector](../../standard-library/vector-class.md) que contém o resultado de cada tarefa no conjunto. O exemplo básico a seguir usa `when_all` para criar uma tarefa que representa a conclusão de três outras tarefas.

[!code-cpp[concrt-join-tasks#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_8.cpp)]

> [!NOTE]
> As tarefas que você passa para `when_all` devem ser uniformes. Em outras palavras, todos eles devem retornar o mesmo tipo.

Você também pode usar a `&&` sintaxe para produzir uma tarefa concluída após a conclusão de um conjunto de tarefas, conforme mostrado no exemplo a seguir.

`auto t = t1 && t2; // same as when_all`

É comum usar uma continuação em conjunto com o `when_all` para executar uma ação após a conclusão de um conjunto de tarefas. O exemplo a seguir modifica o anterior para imprimir a soma de três tarefas que produzem um **`int`** resultado.

[!code-cpp[concrt-join-tasks#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_9.cpp)]

Neste exemplo, você também pode especificar `task<vector<int>>` para produzir uma continuação baseada em tarefa.

Se qualquer tarefa em um conjunto de tarefas for cancelada ou lançar uma exceção, `when_all` o será imediatamente concluído e não aguardará a conclusão das tarefas restantes. Se uma exceção for lançada, o tempo de execução relançará a exceção quando você chamar `task::get` ou `task::wait` no objeto de tarefa que `when_all` retorna. Se mais de uma tarefa for lançada, o tempo de execução escolherá uma delas. Portanto, certifique-se de observar todas as exceções após a conclusão de todas as tarefas; uma exceção de tarefa sem tratamento faz com que o aplicativo seja encerrado.

Aqui está uma função de utilitário que você pode usar para garantir que seu programa Observe todas as exceções. Para cada tarefa no intervalo fornecido, `observe_all_exceptions` dispara qualquer exceção que ocorreu para ser relançada e, em seguida, assimila essa exceção.

[!code-cpp[concrt-eh-when_all#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_10.cpp)]

Considere um aplicativo UWP que usa C++ e XAML e grava um conjunto de arquivos em disco. O exemplo a seguir mostra como usar `when_all` `observe_all_exceptions` o e o para garantir que o programa Observe todas as exceções.

[!code-cpp[concrt-eh-when_all#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_11.cpp)]

##### <a name="to-run-this-example"></a>Para executar este exemplo

1. Em MainPage. XAML, adicione um `Button` controle.

[!code-xml[concrt-eh-when_all#3](../../parallel/concrt/codesnippet/xaml/task-parallelism-concurrency-runtime_12.xaml)]

1. Em MainPage. XAML. h, adicione essas declarações de encaminhamento à **`private`** seção da `MainPage` declaração de classe.

[!code-cpp[concrt-eh-when_all#4](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_13.h)]

1. Em MainPage. XAML. cpp, implemente o `Button_Click` manipulador de eventos.

[!code-cpp[concrt-eh-when_all#5](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_14.cpp)]

1. Em MainPage. XAML. cpp, implemente `WriteFilesAsync` conforme mostrado no exemplo.

> [!TIP]
> `when_all`é uma função sem bloqueio que produz a `task` como resultado. Ao contrário da [tarefa:: Wait](reference/task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no thread Asta (Application STA).

### <a name="the-when_any-function"></a><a name="when-any"></a>A função when_any

A `when_any` função produz uma tarefa que é concluída quando a primeira tarefa em um conjunto de tarefas é concluída. Essa função retorna um objeto [std::p Air](../../standard-library/pair-structure.md) que contém o resultado da tarefa concluída e o índice dessa tarefa no conjunto.

A `when_any` função é especialmente útil nos seguintes cenários:

- Operações redundantes. Considere um algoritmo ou uma operação que possam ser executados de várias maneiras. Você pode usar a `when_any` função para selecionar a operação que é concluída primeiro e, em seguida, cancelar as operações restantes.

- Operações intercaladas. Você pode iniciar várias operações que todas devem ser concluídas e usar a `when_any` função para processar os resultados à medida que cada operação é concluída. Após uma operação ser concluída, você poderá começar uma ou mais tarefas adicionais.

- Operações controladas. Você pode usar a `when_any` função para estender o cenário anterior limitando o número de operações simultâneas.

- Operações expiradas. Você pode usar a `when_any` função para selecionar entre uma ou mais tarefas e uma tarefa que é concluída após uma hora específica.

Assim como acontece com `when_all` o, é comum usar uma continuação que tenha que `when_any` executar a ação quando o primeiro de um conjunto de tarefas for concluído. O exemplo básico a seguir usa `when_any` para criar uma tarefa que é concluída quando a primeira das três outras tarefas é concluída.

[!code-cpp[concrt-select-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_15.cpp)]

Neste exemplo, você também pode especificar `task<pair<int, size_t>>` para produzir uma continuação baseada em tarefa.

> [!NOTE]
> Assim como acontece com `when_all` , as tarefas que você passa para `when_any` devem retornar o mesmo tipo.

Você também pode usar a `||` sintaxe para produzir uma tarefa concluída após a primeira tarefa em um conjunto de tarefas ser concluída, conforme mostrado no exemplo a seguir.

`auto t = t1 || t2; // same as when_any`

> [!TIP]
> Assim como com `when_all` , o `when_any` é sem bloqueio e é seguro chamar em um aplicativo UWP no thread Asta.

## <a name="delayed-task-execution"></a><a name="delayed-tasks"></a>Execução de tarefa atrasada

Às vezes, é necessário atrasar a execução de uma tarefa até que uma condição seja satisfeita ou iniciar uma tarefa em resposta a um evento externo. Por exemplo, em programação assíncrona, talvez seja necessário iniciar uma tarefa em resposta a um evento de conclusão de e/s.

Duas maneiras de fazer isso é usar uma continuação ou iniciar uma tarefa e aguardar um evento dentro da função de trabalho da tarefa. No entanto, há casos em que não é possível usar uma dessas técnicas. Por exemplo, para criar uma continuação, você deve ter a tarefa antecedente. No entanto, se você não tiver a tarefa Antecedent, poderá criar um *evento de conclusão de tarefa* e depois encadear esse evento de conclusão para a tarefa Antecedent quando ela se tornar disponível. Além disso, como uma tarefa em espera também bloqueia um thread, você pode usar eventos de conclusão de tarefas para executar o trabalho quando uma operação assíncrona for concluída e, portanto, liberar um thread.

A classe [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) ajuda a simplificar a composição de tarefas. Assim como a `task` classe, o parâmetro de tipo `T` é o tipo do resultado produzido pela tarefa. Esse tipo pode ser **`void`** se a tarefa não retornar um valor. `T`Não é possível usar o **`const`** modificador. Normalmente, um `task_completion_event` objeto é fornecido a um thread ou a uma tarefa que o sinalizará quando o valor para ele ficar disponível. Ao mesmo tempo, uma ou mais tarefas são definidas como ouvintes desse evento. Quando o evento é definido, as tarefas do ouvinte são concluídas e suas continuaçãos são agendadas para execução.

Para obter um exemplo que usa o `task_completion_event` para implementar uma tarefa que é concluída após um atraso, consulte [como: criar uma tarefa que é concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md).

## <a name="task-groups"></a><a name="task-groups"></a>Grupos de tarefas

Um *grupo de tarefas* organiza uma coleção de tarefas. Os grupos de tarefas enviam tarefas por push para uma fila de roubo de trabalho. O Agendador remove as tarefas dessa fila e as executa nos recursos de computação disponíveis. Depois de adicionar tarefas a um grupo de tarefas, você pode aguardar a conclusão de todas as tarefas ou cancelar tarefas que ainda não foram iniciadas.

A PPL usa as classes [Concurrency:: task_group](reference/task-group-class.md) e [concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) para representar grupos de tarefas e a classe [Concurrency:: task_handle](../../parallel/concrt/reference/task-handle-class.md) para representar as tarefas que são executadas nesses grupos. A `task_handle` classe encapsula o código que executa o trabalho. Assim como a `task` classe, a função Work vem na forma de uma função lambda, um ponteiro de função ou um objeto de função. Normalmente, você não precisa trabalhar com `task_handle` objetos diretamente. Em vez disso, você passa funções de trabalho para um grupo de tarefas e o grupo de tarefas cria e gerencia os `task_handle` objetos.

A PPL divide grupos de tarefas nessas duas categorias: *grupos de tarefas não estruturados* e *grupos de tarefas estruturados*. A PPL usa a `task_group` classe para representar grupos de tarefas não estruturados e a `structured_task_group` classe para representar grupos de tarefas estruturados.

> [!IMPORTANT]
> A PPL também define o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) , que usa a `structured_task_group` classe para executar um conjunto de tarefas em paralelo. Como o `parallel_invoke` algoritmo tem uma sintaxe mais sucinta, recomendamos que você o use em vez da `structured_task_group` classe quando puder. O tópico [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md) descreve `parallel_invoke` mais detalhadamente.

Use `parallel_invoke` quando você tiver várias tarefas independentes que deseja executar ao mesmo tempo e precisar aguardar a conclusão de todas as tarefas antes de continuar. Essa técnica geralmente é conhecida como paralelismo de *bifurcação e junção* . Use `task_group` quando você tiver várias tarefas independentes que deseja executar ao mesmo tempo, mas quiser aguardar até que as tarefas sejam concluídas posteriormente. Por exemplo, você pode adicionar tarefas a um `task_group` objeto e aguardar que as tarefas sejam concluídas em outra função ou em outro thread.

Os grupos de tarefas dão suporte ao conceito de cancelamento. O cancelamento permite sinalizar a todas as tarefas ativas que você deseja cancelar a operação geral. O cancelamento também impede que as tarefas que ainda não começaram a ser iniciadas. Para obter mais informações sobre cancelamento, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

O tempo de execução também fornece um modelo de tratamento de exceções que permite lançar uma exceção de uma tarefa e lidar com essa exceção quando você aguarda a conclusão do grupo de tarefas associado. Para obter mais informações sobre esse modelo de tratamento de exceções, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="comparing-task_group-to-structured_task_group"></a><a name="comparing-groups"></a>Comparando task_group a structured_task_group

Embora seja recomendável usar `task_group` ou, `parallel_invoke` em vez da `structured_task_group` classe, há casos em que você deseja usar `structured_task_group` , por exemplo, quando você escreve um algoritmo paralelo que executa um número variável de tarefas ou requer suporte para cancelamento. Esta seção explica as diferenças entre as `task_group` `structured_task_group` classes e.

A `task_group` classe é thread-safe. Portanto, você pode adicionar tarefas a um `task_group` objeto de vários threads e aguardar ou cancelar um `task_group` objeto de vários threads. A construção e a destruição de um `structured_task_group` objeto devem ocorrer no mesmo escopo léxico. Além disso, todas as operações em um `structured_task_group` objeto devem ocorrer no mesmo thread. A exceção a essa regra são os métodos [Concurrency:: structured_task_group:: Cancel](reference/structured-task-group-class.md#cancel) e [concurrency:: structured_task_group:: is_canceling](reference/structured-task-group-class.md#is_canceling) . Uma tarefa filho pode chamar esses métodos para cancelar o grupo de tarefas pai ou verificar a cancelamento a qualquer momento.

Você pode executar tarefas adicionais em um `task_group` objeto depois de chamar o método [Concurrency:: task_group:: Wait](reference/task-group-class.md#wait) ou [Concurrency:: task_group:: run_and_wait](reference/task-group-class.md#run_and_wait) . Por outro lado, se você executar tarefas adicionais em um `structured_task_group` objeto depois de chamar os métodos [Concurrency:: structured_task_group:: Wait](reference/structured-task-group-class.md#wait) ou [Concurrency:: structured_task_group:: run_and_wait](reference/structured-task-group-class.md#run_and_wait) , o comportamento será indefinido.

Como a `structured_task_group` classe não é sincronizada entre threads, ela tem menos sobrecarga de execução do que a `task_group` classe. Portanto, se o problema não exigir que você agende o trabalho de vários threads e não possa usar o `parallel_invoke` algoritmo, a `structured_task_group` classe poderá ajudá-lo a escrever um código de melhor desempenho.

Se você usar um `structured_task_group` objeto dentro de outro `structured_task_group` objeto, o objeto interno deverá ser concluído e destruído antes que o objeto externo seja concluído. A `task_group` classe não exige que os grupos de tarefas aninhados sejam concluídos antes de o grupo externo ser concluído.

Grupos de tarefas não estruturados e grupos de tarefas estruturados funcionam com identificadores de tarefas de maneiras diferentes. Você pode passar funções de trabalho diretamente para um `task_group` objeto; o `task_group` objeto criará e gerenciará o identificador de tarefa para você. A `structured_task_group` classe requer que você gerencie um `task_handle` objeto para cada tarefa. Cada `task_handle` objeto deve permanecer válido durante o tempo de vida de seu `structured_task_group` objeto associado. Use a função [Concurrency:: make_task](reference/concurrency-namespace-functions.md#make_task) para criar um `task_handle` objeto, conforme mostrado no exemplo básico a seguir:

[!code-cpp[concrt-make-task-structure#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_16.cpp)]

Para gerenciar identificadores de tarefas para casos em que você tem um número variável de tarefas, use uma rotina de alocação de pilha, como [_malloca](../../c-runtime-library/reference/malloca.md) ou uma classe de contêiner, como std::[vector](../../standard-library/vector-class.md).

O `task_group` e o `structured_task_group` cancelamento de suporte. Para obter mais informações sobre cancelamento, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

## <a name="example"></a><a name="example"></a> Exemplo

O exemplo básico a seguir mostra como trabalhar com grupos de tarefas. Este exemplo usa o `parallel_invoke` algoritmo para executar duas tarefas simultaneamente. Cada tarefa adiciona as subtarefas a um `task_group` objeto. Observe que a `task_group` classe permite que várias tarefas adicionem tarefas a ela simultaneamente.

[!code-cpp[concrt-using-task-groups#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_17.cpp)]

Veja a seguir um exemplo de saída para este exemplo:

```Output
Message from task: Hello
Message from task: 3.14
Message from task: 42
```

Como o `parallel_invoke` algoritmo executa tarefas simultaneamente, a ordem das mensagens de saída pode variar.

Para obter exemplos completos que mostram como usar o `parallel_invoke` algoritmo, consulte [como: usar Parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md) e [como usar Parallel_invoke para executar operações paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md). Para obter um exemplo completo que usa a `task_group` classe para implementar futuros assíncronos, consulte [Walkthrough: Implementing Futures](../../parallel/concrt/walkthrough-implementing-futures.md).

## <a name="robust-programming"></a><a name="robust"></a>Programação robusta

Certifique-se de entender a função de cancelamento e tratamento de exceções ao usar tarefas, grupos de tarefas e algoritmos paralelos. Por exemplo, em uma árvore de trabalho paralelo, uma tarefa cancelada impede a execução de tarefas filho. Isso pode causar problemas se uma das tarefas filho executar uma operação que é importante para seu aplicativo, como liberar um recurso. Além disso, se uma tarefa filho lançar uma exceção, essa exceção poderá se propagar por meio de um destruidor de objeto e causar um comportamento indefinido em seu aplicativo. Para obter um exemplo que ilustra esses pontos, consulte a seção [entender como o cancelamento e o tratamento de exceções afetam a destruição de objetos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) nas práticas recomendadas no documento da biblioteca de padrões paralelos. Para obter mais informações sobre os modelos de cancelamento e tratamento de exceção na PPL, consulte [cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md) e [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="related-topics"></a>Tópicos Relacionados

|Título|Descrição|
|-----------|-----------------|
|[Como: usar parallel_invoke para gravar uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho do algoritmo de classificação bitônico.|
|[Como: usar parallel_invoke para executar operações paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada.|
|[Como: criar uma tarefa que é concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md)|Mostra como usar as `task` classes, `cancellation_token_source` , `cancellation_token` e `task_completion_event` para criar uma tarefa que é concluída após um atraso.|
|[Walkthrough: implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)|Mostra como combinar a funcionalidade existente no Tempo de Execução de Simultaneidade em algo que faz mais.|
|[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve a PPL, que fornece um modelo de programação imperativo para o desenvolvimento de aplicativos simultâneos.|

## <a name="reference"></a>Referência

[Classe Task (Tempo de Execução de Simultaneidade)](../../parallel/concrt/reference/task-class.md)

[Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)

[Função when_all](reference/concurrency-namespace-functions.md#when_all)

[Função when_any](reference/concurrency-namespace-functions.md#when_any)

[Classe task_group](reference/task-group-class.md)

[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)

[Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)
