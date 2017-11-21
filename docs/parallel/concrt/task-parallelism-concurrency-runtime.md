---
title: "Tarefa de paralelismo (tempo de execução de simultaneidade) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- structured task groups [Concurrency Runtime]
- structured tasks [Concurrency Runtime]
- task groups [Concurrency Runtime]
- task parallelism
- tasks [Concurrency Runtime]
ms.assetid: 42f05ac3-2098-494a-ba84-737fcdcad077
caps.latest.revision: "56"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 26b41c4fa3f3cdc9840eecbd31790b7cf82d7659
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="task-parallelism-concurrency-runtime"></a>Paralelismo de tarefa (tempo de execução de simultaneidade)
No tempo de execução de simultaneidade, um *tarefa* é uma unidade de trabalho que executa um trabalho específico e normalmente é executado em paralelo com outras tarefas. Uma tarefa pode ser decomposta em tarefas mais refinadas adicionais que são organizadas em uma *grupo tarefas*.  
  
 Tarefas são usadas quando você escreve código assíncrono e deseja que algumas operações ocorrem após a conclusão da operação assíncrona. Por exemplo, você pode usar uma tarefa assíncrona ler de um arquivo e, em seguida, usar outra tarefa — um *tarefa de continuação*, que é explicado mais adiante neste documento, para processar os dados depois que ele fica disponível. Por outro lado, você pode usar grupos de tarefas para decompor trabalho paralelos em partes menores. Por exemplo, suponha que você tenha um algoritmo recursiva que divide o trabalho restante em duas partições. Você pode usar grupos de tarefas para executar essas partições ao mesmo tempo e, em seguida, aguarde a conclusão do trabalho dividido.  
  
> [!TIP]

>  Quando você deseja aplicar a mesma rotina para cada elemento de uma coleção em paralelo, use um algoritmo em paralelo, como [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for), em vez de uma tarefa ou um grupo de tarefas. Para obter mais informações sobre os algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  

  
## <a name="key-points"></a>Pontos-chave  
  
-   Quando você passar variáveis em uma expressão lambda por referência, você deve assegurar que o tempo de vida da variável persiste até que a tarefa seja concluída.  
  
-   Usar tarefas (o [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) classe) quando você escreve código assíncrono. A classe task usa o ThreadPool do Windows como seu Agendador, não o tempo de execução de simultaneidade.  
  
-   Use grupos de tarefas (o [concurrency::task_group](reference/task-group-class.md) classe ou o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo) quando quiser decompor trabalho paralelos em partes menores e aguarde até que os menores peças para concluir.  
  
-   Use o [concurrency::task::then](reference/task-class.md#then) método para criar continuações. Um *continuação* é uma tarefa que executa de forma assíncrona, após a conclusão de outra tarefa. Você pode se conectar a qualquer número de continuações para formar uma cadeia de trabalho assíncrono.  
  
-   Uma continuação de tarefas sempre é agendada para execução quando a tarefa antecedente for concluída, mesmo quando a tarefa antecedente foi cancelada ou gera uma exceção.  
  
-   Use [when_all](reference/concurrency-namespace-functions.md#when_all) para criar uma tarefa que conclui após a conclusão de todos os membros de um conjunto de tarefas. Use [concurrency::when_any](reference/concurrency-namespace-functions.md#when_any) para criar uma tarefa que conclui após a conclusão de um membro de um conjunto de tarefas.  

  
-   Tarefas e grupos de tarefas podem participar no mecanismo de cancelamento de biblioteca de padrões paralelos (PPL). Para obter mais informações, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).  
  
-   Para saber como o tempo de execução trata exceções lançadas por tarefas e grupos de tarefas, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
## <a name="in-this-document"></a>Neste Documento  
  
- [Usando expressões Lambda](#lambdas)  
  
- [A classe de tarefa](#task-class)  
  
- [Tarefas de continuação](#continuations)  
  
- [Com base em valor Versus continuações baseado em tarefa](#value-versus-task)  
  
- [Composição de tarefas](#composing-tasks)  
  
    - [A função when_all](#when-all)  
  
    - [A função when_any](#when-any)  
  
- [Execução da tarefa atrasada](#delayed-tasks)  
  
- [Grupos de tarefas](#task-groups)  
  
- [Comparando task_group para structured_task_group](#comparing-groups)  
  
- [Exemplo](#example)  
  
- [Programação robusta](#robust)  
  
##  <a name="lambdas"></a>Usando expressões Lambda  
 Devido a sua sintaxe sucinta, expressões lambda são uma maneira comum de definir o trabalho que é executado por tarefas e grupos de tarefas. Aqui estão algumas dicas de uso:  
  
-   Porque normalmente executar tarefas em threads em segundo plano, lembre-se do tempo de vida de objeto quando você captura variáveis em expressões lambda. Quando você captura uma variável pelo valor, é feita uma cópia da variável no corpo lambda. Quando você captura por referência, não é feita uma cópia. Portanto, certifique-se de que o tempo de vida de qualquer variável capturada por referência sobrevivem a tarefa que utiliza.  
  
-   Quando você passar uma expressão lambda para uma tarefa, não capture variáveis que estão alocados na pilha por referência.  
  
-   Ser explícito sobre as variáveis de que captura em expressões lambda, para que você possa identificar o que você está capturando por valor e por referência. Por esse motivo, é recomendável que você não use o `[=]` ou `[&]` opções de expressões lambda.  
  
 Um padrão comum é quando uma tarefa em uma cadeia de continuação atribui a uma variável, e outra tarefa lê essa variável. Você não pode capturar por valor, porque cada tarefa de continuação deve manter uma cópia diferente da variável. Para variáveis alocado na pilha, você também não é possível capturar por referência porque a variável pode não ser mais válida.  
  
 Para resolver esse problema, use um ponteiro inteligente, como [std:: shared_ptr](../../standard-library/shared-ptr-class.md)para encapsular a variável e passar o ponteiro inteligente por valor. Dessa forma, o objeto subjacente pode ser atribuído a ler e será duram mais tempo as tarefas que usá-lo. Use essa técnica, mesmo quando a variável é um ponteiro ou um identificador contado por referência (`^`) a um objeto de tempo de execução do Windows. Aqui está um exemplo básico:  
  
 [!code-cpp[concrt-lambda-task-lifetime#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_1.cpp)]  
  
 Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).  
  
##  <a name="task-class"></a>A classe de tarefa  
 Você pode usar o [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) classe para compor tarefas em um conjunto de operações dependentes. Esse modelo de composição há suporte para a noção de *continuações*. Um código de ativa de continuação a ser executado quando o anterior, ou *antecessor*, concluir a tarefa. O resultado da tarefa antecedente é passado como entrada para as tarefas de continuação de uma ou mais. Quando uma tarefa antecedente for concluído, as tarefas de continuação que estão esperando nele são agendadas para execução. Cada tarefa de continuação recebe uma cópia do resultado da tarefa antecedente. Por sua vez, as tarefas de continuação também podem ser tarefas antecedente para outros continuações, criando assim uma cadeia de tarefas. As continuações ajudam a criar cadeias de comprimento arbitrário de tarefas que têm dependências específicas entre eles. Além disso, uma tarefa pode participar antes de uma lista de tarefas é iniciado de cancelamento ou de forma cooperativa enquanto ele está em execução. Para obter mais informações sobre esse modelo de cancelamento, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).  
  
 `task`é uma classe de modelo. O parâmetro de tipo `T` é o tipo de resultado que é produzido pela tarefa. Esse tipo pode ser `void` se a tarefa não retornar um valor. `T`não é possível usar o `const` modificador.  
  
 Quando você cria uma tarefa, você fornece um *função de trabalho* que executa o corpo da tarefa. Essa função de trabalho vem na forma de uma função lambda, o ponteiro de função ou o objeto de função. Para aguardar a conclusão sem obter o resultado de uma tarefa, chame o [concurrency::task::wait](reference/task-class.md#wait) método. O `task::wait` método retorna um [concurrency::task_status](reference/concurrency-namespace-enums.md#task_group_status) valor que descreve se a tarefa foi concluída ou cancelada. Para obter o resultado da tarefa, chame o [concurrency::task::get](reference/task-class.md#get) método. Este método chama `task::wait` de espera para a tarefa para concluir e, portanto, bloqueia a execução do thread atual até que o resultado estiver disponível.  
  
 O exemplo a seguir mostra como criar uma tarefa, aguarde até que o resultado e exibir seu valor. Os exemplos nesta documentação usam funções lambda porque eles fornecem uma sintaxe mais sucinta. No entanto, você também pode usar a ponteiros de função e objetos de função quando você usa as tarefas.  
  
 [!code-cpp[concrt-basic-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_2.cpp)]  
  

 Quando você usa o [concurrency::create_task](reference/concurrency-namespace-functions.md#create_task) função, você pode usar o `auto` palavra-chave em vez de declarar o tipo. Por exemplo, considere este código que cria e imprime a matriz de identidade:  

  
 [!code-cpp[concrt-create-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_3.cpp)]  
  
 Você pode usar o `create_task` função para criar a operação equivalente.  
  
 [!code-cpp[concrt-create-task#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_4.cpp)]  
  
 Se uma exceção é lançada durante a execução de uma tarefa, o tempo de execução controla essa exceção na chamada subsequente para `task::get` ou `task::wait`, ou uma continuação de tarefas. Para obter mais informações sobre o mecanismo de tratamento de exceções de tarefa, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
 Para obter um exemplo que usa `task`, [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), cancelamento, consulte [passo a passo: conectando usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md). (O `task_completion_event` classe é descrita posteriormente neste documento.)  
  
> [!TIP]
>  Para obter detalhes sobre o que são específicas para tarefas em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos, consulte [programação assíncrona em C++](http://msdn.microsoft.com/en-us/512700b7-7863-44cc-93a2-366938052f31) e [Criando operações assíncronas em C++ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).  
  
##  <a name="continuations"></a>Tarefas de continuação  
 Na programação assíncrona, é muito comum para uma operação assíncrona, após a conclusão, invocar uma segunda operação e passar dados para ela. Tradicionalmente, isso é feito usando os métodos de retorno de chamada. O tempo de execução de simultaneidade, a mesma funcionalidade é fornecida por *tarefas de continuação*. Uma tarefa de continuação (também conhecida como uma continuação) é uma tarefa assíncrona é invocado por outra tarefa, que é conhecida como o *antecessor*, quando o antecessor é concluída. Usando continuações, você pode:  
  
-   Passe dados da antecessora para a continuação.  
  
-   Especifica as condições precisas sob a qual a continuação é chamada ou não foi invocada.  
  
-   Cancele uma continuação antes de iniciar ou trabalhem de forma enquanto ele está em execução.  
  
-   Forneça dicas sobre como a continuação deve ser agendada. (Isso se aplica a [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] apenas os aplicativos. Para obter mais informações, consulte [Criando operações assíncronas em C++ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).)  
  
-   Invoque várias continuações da mesma antecessora.  
  
-   Invocar uma continuação quando concluir todas ou algumas das várias antecedentes.  
  
-   Continuação de cadeia após o outro para qualquer comprimento.  
  
-   Use uma continuação para manipular exceções lançadas pelo antecessor.  
  
 Esses recursos permitem que você execute uma ou mais tarefas quando a primeira tarefa é concluída. Por exemplo, você pode criar uma continuação que compacta um arquivo após a primeira tarefa lê-lo a partir do disco.  
  


 O exemplo a seguir modifica uma anterior para usar o [concurrency::task::then](reference/task-class.md#then) método para agendar uma continuação que imprime o valor da tarefa antecedente quando ele estiver disponível.  


  
 [!code-cpp[concrt-basic-continuation#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_5.cpp)]  
  
 Você pode encadear e aninhar qualquer comprimento de tarefas. Uma tarefa também pode ter vários continuações. O exemplo a seguir ilustra uma cadeia de continuação básico que incrementa o valor da tarefa anterior três vezes.  
  
 [!code-cpp[concrt-continuation-chain#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_6.cpp)]  
  
 Uma continuação também pode retornar a outra tarefa. Se não houver nenhum cancelamento, essa tarefa é executada antes da continuação subsequente. Essa técnica é conhecida como *desencapsulamento assíncrona*. Desempacotamento assíncrona é útil quando você deseja executar o trabalho adicional em segundo plano, mas não quiser que a tarefa atual para bloquear o thread atual. (Isso é comum em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos, onde continuações podem ser executado no thread da interface do usuário). O exemplo a seguir mostra três tarefas. A primeira tarefa retorna outra tarefa que é executada antes de uma tarefa de continuação.  
  
 [!code-cpp[concrt-async-unwrapping#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_7.cpp)]  
  
> [!IMPORTANT]
>  Quando uma continuação de uma tarefa retorna uma tarefa aninhada de tipo `N`, a tarefa resultante tem o tipo `N`, não `task<N>`e termina quando a tarefa aninhada é concluída. Em outras palavras, a continuação executa o desencapsulamento da tarefa aninhada.  
  
##  <a name="value-versus-task"></a>Com base em valor Versus continuações baseado em tarefa  
 Dado um `task` objeto cujo tipo de retorno é `T`, você pode fornecer um valor do tipo `T` ou `task<T>` para suas tarefas de continuação. Uma continuação que usa o tipo `T` é conhecido como um *continuação de acordo com o valor*. Uma continuação de acordo com o valor é agendada para execução quando a tarefa antecedente for concluída sem erros e não for cancelada. Uma continuação que usa o tipo `task<T>` como seu parâmetro é conhecido como um *baseado em tarefa de continuação*. Uma continuação de tarefas sempre é agendada para execução quando a tarefa antecedente for concluída, mesmo quando a tarefa antecedente foi cancelada ou gera uma exceção. Em seguida, você pode chamar `task::get` para obter o resultado da tarefa antecedente. Se a tarefa antecedente foi cancelada, `task::get` lança [concurrency::task_canceled](../../parallel/concrt/reference/task-canceled-class.md). Se a tarefa antecedente lançou uma exceção, `task::get` relança essa exceção. Uma continuação de tarefas não é marcada como cancelada quando sua tarefa antecedente é cancelada.  
  
##  <a name="composing-tasks"></a>Composição de tarefas  
 Esta seção descreve o [when_all](reference/concurrency-namespace-functions.md#when_all) e [concurrency::when_any](reference/concurrency-namespace-functions.md#when_all) funções, que podem ajudá-lo a compõem várias tarefas para implementar os padrões comuns.  

  
###  <a name="when-all"></a>A função when_all  
 O `when_all` função produz uma tarefa que é concluída depois de concluir um conjunto de tarefas. Essa função retorna um std::[vetor](../../standard-library/vector-class.md) objeto que contém o resultado de cada tarefa no conjunto. O seguinte exemplo básico usa `when_all` para criar uma tarefa que representa a conclusão das três outras tarefas.  
  
 [!code-cpp[concrt-join-tasks#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_8.cpp)]  
  
> [!NOTE]
>  As tarefas que você passa para `when_all` deve ser uniforme. Em outras palavras, eles devem todos retornam o mesmo tipo.  
  
 Você também pode usar o `&&` sintaxe para produzir uma tarefa que é concluída depois de concluir um conjunto de tarefas, conforme mostrado no exemplo a seguir.  
  
 `auto t = t1 && t2; // same as when_all`  
  
 É comum usar uma continuação junto com `when_all` para executar uma ação após a conclusão de um conjunto de tarefas. O exemplo a seguir modifica um anterior para imprimir a soma dos três tarefas que cada produzir um `int` resultados.  
  
 [!code-cpp[concrt-join-tasks#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_9.cpp)]  
  
 Neste exemplo, você também pode especificar `task<vector<int>>` para produzir uma continuação de tarefas.  
  
 Se qualquer tarefa em um conjunto de tarefas for cancelada ou gera uma exceção, `when_all` é concluída imediatamente e não espera que as tarefas restantes concluir. Se uma exceção for lançada, o tempo de execução lança novamente a exceção ao chamar `task::get` ou `task::wait` na tarefa do objeto que `when_all` retorna. Se mais de uma tarefa gera, o tempo de execução escolhe um deles. Portanto, certifique-se de que você observar todas as exceções depois de concluir todas as tarefas; uma exceção sem tratamento tarefa faz com que o aplicativo seja finalizado.  
  
 Esta é uma função de utilitário que você pode usar para garantir que seu programa observa todas as exceções. Para cada tarefa no intervalo fornecido, `observe_all_exceptions` dispara qualquer exceção que ocorreu para ser lançada novamente e, em seguida, absorve essa exceção.  
  
 [!code-cpp[concrt-eh-when_all#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_10.cpp)]  
  
 Considere um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo que usa C++ e XAML e grava um conjunto de arquivos no disco. O exemplo a seguir mostra como usar `when_all` e `observe_all_exceptions` para garantir que o programa observa todas as exceções.  
  
 [!code-cpp[concrt-eh-when_all#2](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_11.cpp)]  
  
##### <a name="to-run-this-example"></a>Para executar este exemplo  
  
1.  Em MainPage. XAML, adicione um `Button` controle.  
  
 [!code-xml[concrt-eh-when_all#3](../../parallel/concrt/codesnippet/xaml/task-parallelism-concurrency-runtime_12.xaml)]  
  
2.  No MainPage.xaml.h, adicione estas declarações de encaminhamento para o `private` seção o `MainPage` declaração de classe.  
  
 [!code-cpp[concrt-eh-when_all#4](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_13.h)]  
  
3.  MainPage.xaml.cpp, implementar a `Button_Click` manipulador de eventos.  
  
 [!code-cpp[concrt-eh-when_all#5](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_14.cpp)]  
  
4.  MainPage.xaml.cpp, implementar `WriteFilesAsync` conforme mostrado no exemplo.  
  
> [!TIP]

> `when_all`é uma função sem bloqueio que produz um `task` como resultado. Ao contrário de [Task:: wait](reference/task-class.md#wait), é seguro chamar essa função em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo no thread de ASTA (aplicativo STA).  

  
###  <a name="when-any"></a>A função when_any  
 O `when_any` função produz uma tarefa que conclui quando a primeira tarefa em um conjunto de tarefas é concluída. Essa função retorna um [STD](../../standard-library/pair-structure.md) objeto que contém o resultado da tarefa concluída e o índice da tarefa no conjunto.  
  
 O `when_any` função é especialmente útil nas seguintes situações:  
  
-   Operações redundantes. Considere um algoritmo ou uma operação que possam ser executados de várias maneiras. Você pode usar o `when_any` função para selecionar a operação for concluída primeiro e, em seguida, cancele as operações restantes.  
  
-   Operações intercaladas. Você pode iniciar várias operações de todos os devem concluir e usar o `when_any` função para processar os resultados que cada operação é concluída. Após uma operação ser concluída, você poderá começar uma ou mais tarefas adicionais.  
  
-   Operações controladas. Você pode usar o `when_any` função para estender o cenário anterior, limitando o número de operações simultâneas.  
  
-   Operações expiradas. Você pode usar o `when_any` para selecionar entre uma ou mais tarefas e uma tarefa que termina após um tempo específico.  
  
 Assim como acontece com `when_all`, é comum usar uma continuação com `when_any` para executar a ação quando terminar o primeiro em um conjunto de tarefas. O seguinte exemplo básico usa `when_any` para criar uma tarefa que conclui quando a primeira das três outras tarefas é concluída.  
  
 [!code-cpp[concrt-select-task#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_15.cpp)]  
  
 Neste exemplo, você também pode especificar `task<pair<int, size_t>>` para produzir uma continuação de tarefas.  
  
> [!NOTE]
>  Assim como acontece com `when_all`, as tarefas que você passa para `when_any` todos devem retornar o mesmo tipo.  
  
 Você também pode usar o `||` sintaxe para produzir uma tarefa que conclui após a primeira tarefa em um conjunto de tarefas, conforme mostrado no exemplo a seguir.  
  
 `auto t = t1 || t2; // same as when_any`  
  
> [!TIP]
>  Assim como acontece com `when_all`, `when_any` é desbloqueado e é seguro chamar um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo no thread de ASTA.  
  
##  <a name="delayed-tasks"></a>Execução da tarefa atrasada  
 Às vezes, é necessário para atrasar a execução de uma tarefa até que uma condição é atendida ou iniciar uma tarefa em resposta a um evento externo. Por exemplo, em programação assíncrona, você talvez precise iniciar uma tarefa em resposta a um evento de conclusão de e/s.  
  
 Duas maneiras de fazer isso são para usar uma continuação ou para iniciar uma tarefa e aguardar um evento dentro da função de trabalho da tarefa. No entanto, há casos em que não é possível usar uma dessas técnicas. Por exemplo, para criar uma continuação, você deve ter a tarefa antecedente. No entanto, se você não tem a tarefa antecedente, você pode criar um *evento de conclusão de tarefa* e encadear mais tarde esse evento de conclusão da tarefa antecedente quando estiverem disponível. Além disso, como uma tarefa espera também bloqueia um thread, você pode usar eventos de conclusão de tarefas para executar o trabalho quando uma operação assíncrona é concluída e, assim, liberar um thread.  
  
 O [Concurrency:: task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) classe ajuda a simplificar tal composição de tarefas. Como o `task` de classe, o parâmetro de tipo `T` é o tipo de resultado que é produzido pela tarefa. Esse tipo pode ser `void` se a tarefa não retornar um valor. `T`não é possível usar o `const` modificador. Normalmente, um `task_completion_event` objeto é fornecido para um thread ou uma tarefa que ele sinalizará quando o valor para que ele se torna disponível. Ao mesmo tempo, uma ou mais tarefas são definidas como ouvintes de evento. Quando o evento é definido, conclua as tarefas de ouvinte e seus continuações estão agendadas para execução.  
  
 Para obter um exemplo que usa `task_completion_event` para implementar uma tarefa que seja concluída após um atraso, consulte [como: criar uma tarefa que é concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md).  
  
##  <a name="task-groups"></a>Grupos de tarefas  
 Um *grupo tarefas* organiza uma coleção de tarefas. Grupos de tarefas por push tarefas em uma fila de roubo de trabalho. O Agendador remove tarefas dessa fila e executa-los nos recursos de computação disponíveis. Depois de adicionar tarefas a um grupo de tarefas, você pode esperar para todas as tarefas concluir ou Cancelar tarefas que ainda não foram iniciados.  
  
 PPL usa o [concurrency::task_group](reference/task-group-class.md) e [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes para representar grupos de tarefas e o [concurrency::task_handle](../../parallel/concrt/reference/task-handle-class.md) classe para representar as tarefas que são executados nesses grupos. O `task_handle` classe encapsula o código que executa o trabalho. Como o `task` classe, a função de trabalho vem na forma de uma função lambda, o ponteiro de função ou o objeto de função. Você normalmente não precisa trabalhar com `task_handle` objetos diretamente. Em vez disso, você passa a funções de trabalho para um grupo de tarefas, e o grupo de tarefas cria e gerencia o `task_handle` objetos.  
  
 PPL divide os grupos de tarefas nessas duas categorias: *grupos de tarefas não estruturados* e *estruturado grupos de tarefas*. PPL usa o `task_group` classe para representar grupos de tarefas não estruturados e `structured_task_group` classe para representar grupos de tarefas estruturadas.  
  
> [!IMPORTANT]

>  PPL também define o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo, que utiliza o `structured_task_group` classe para executar um conjunto de tarefas em paralelo. Porque o `parallel_invoke` algoritmo possui uma sintaxe mais sucinta, recomendamos que você usá-lo em vez da `structured_task_group` classe quando possível. O tópico [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md) descreve `parallel_invoke` mais detalhadamente.  
  
 Use `parallel_invoke` quando você tem várias tarefas independentes que você deseja executar ao mesmo tempo, e você deve esperar para todas as tarefas sejam concluídas antes de continuar. Essa técnica é conhecida como *bifurcação e junção* paralelismo. Use `task_group` quando você tem várias tarefas independentes que você deseja executar ao mesmo tempo, mas você desejar esperar para as tarefas sejam concluídas mais tarde. Por exemplo, você pode adicionar tarefas para um `task_group` de objeto e aguarde até que as tarefas sejam concluídas em outra função ou de outro thread.  
  
 Grupos de tarefas suportam o conceito de cancelamento. Cancelamento permite sinalizar para todas as tarefas ativas que deseja cancelar a operação total. Cancelamento também impede que a tarefas que ainda não foram iniciadas seja iniciado. Para obter mais informações sobre cancelamento, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).  
  
 O tempo de execução também fornece um modelo de tratamento de exceção que permite que você lançar uma exceção de uma tarefa e tratar essa exceção quando você esperar que o grupo de tarefas associada a conclusão. Para obter mais informações sobre esse modelo de tratamento de exceção, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
##  <a name="comparing-groups"></a>Comparando task_group para structured_task_group  
 Embora, recomendamos que você use `task_group` ou `parallel_invoke` em vez do `structured_task_group` classe, há casos em que você deseja usar `structured_task_group`, por exemplo, quando você escreve um algoritmo parallel que executa um número variável de tarefas ou exige suporte para cancelamento. Esta seção explica as diferenças entre o `task_group` e `structured_task_group` classes.  
  
 O `task_group` classe é thread-safe. Portanto, você pode adicionar tarefas para um `task_group` de objeto de vários threads e aguardar ou cancelar uma `task_group` objeto a partir de vários threads. A construção e a destruição de um `structured_task_group` objeto deve ocorrer no mesmo escopo léxico. Além disso, todas as operações em um `structured_task_group` objeto deve ocorrer no mesmo thread. A exceção a essa regra é o [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) e [concurrency::structured_task_group::is_canceling](reference/structured-task-group-class.md#is_canceling) métodos. Uma tarefa filho pode chamar esses métodos para cancelar o grupo de tarefas do pai ou verificar o cancelamento a qualquer momento.  
  
 Você pode executar tarefas adicionais em um `task_group` objeto depois de chamar o [concurrency::task_group::wait](reference/task-group-class.md#wait) ou [concurrency::task_group::run_and_wait](reference/task-group-class.md#run_and_wait) método. Por outro lado, se você executar tarefas adicionais em um `structured_task_group` objeto depois de chamar o [concurrency::structured_task_group::wait](reference/structured-task-group-class.md#wait) ou [concurrency::structured_task_group::run_and_wait](reference/structured-task-group-class.md#run_and_wait) métodos , em seguida, o comportamento será indefinido.  
  
 Porque o `structured_task_group` classe não sincronizar entre threads, ela tem menos sobrecarga que a execução de `task_group` classe. Portanto, se o problema não exigir que você agenda o trabalho de vários threads e não é possível usar o `parallel_invoke` algoritmo, o `structured_task_group` classe pode ajudá-lo a escrever código melhor desempenho.  
  
 Se você usar um `structured_task_group` objeto dentro de outro `structured_task_group` objeto, o objeto interno deve ser concluído e ser destruído antes de concluir o objeto externo. O `task_group` classe não requer para grupos de tarefas aninhadas concluir antes de concluir o grupo externo.  
  
 Grupos de tarefas não estruturados e grupos de tarefas estruturadas funcionam com identificadores de tarefa de maneiras diferentes. Você pode passar as funções de trabalho diretamente para um `task_group` objeto; o `task_group` objeto criará e gerenciará o identificador de tarefa para você. O `structured_task_group` classe requer que você gerencie um `task_handle` objeto para cada tarefa. Cada `task_handle` objeto deve permanecer válido durante toda a vida útil de seus associados `structured_task_group` objeto. Use o [concurrency::make_task](reference/concurrency-namespace-functions.md#make_task) função para criar um `task_handle` do objeto, como mostrado no exemplo básico a seguir:  
  
 [!code-cpp[concrt-make-task-structure#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_16.cpp)]  
  
 Para gerenciar os identificadores de tarefa para casos em que há um número variável de tarefas, use uma rotina de alocação da pilha, como [malloca](../../c-runtime-library/reference/malloca.md) ou uma classe de contêiner, como std::[vetor](../../standard-library/vector-class.md).  
  
 Ambos `task_group` e `structured_task_group` oferecer suporte ao cancelamento. Para obter mais informações sobre cancelamento, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).  
  
##  <a name="example"></a> Exemplo  
 O exemplo básico a seguir mostra como trabalhar com grupos de tarefas. Este exemplo usa o `parallel_invoke` algoritmo para realizar duas tarefas simultaneamente. Cada tarefa adiciona subtarefas um `task_group` objeto. Observe que o `task_group` classe permite que várias tarefas adicionar tarefas a ela, ao mesmo tempo.  
  
 [!code-cpp[concrt-using-task-groups#1](../../parallel/concrt/codesnippet/cpp/task-parallelism-concurrency-runtime_17.cpp)]  
  
 Saída de exemplo para este exemplo é o seguinte:  
  
```Output  
Message from task: Hello  
Message from task: 3.14  
Message from task: 42  
```  
  
 Porque o `parallel_invoke` algoritmo executa tarefas simultaneamente, a ordem das mensagens de saída pode variar.  
  
 Para concluir exemplos que mostram como usar o `parallel_invoke` algoritmo, consulte [como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md) e [como: usar parallel_invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md). Para obter um exemplo completo que usa o `task_group` classe para implementar futuros assíncronos, consulte [passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md).  
  
##  <a name="robust"></a>Programação robusta  
 Certifique-se de que você compreenda a função de cancelamento e tratamento de exceção quando você usa tarefas, grupos de tarefas e os algoritmos paralelos. Por exemplo, em uma árvore de trabalho paralela, uma tarefa que é cancelada impede tarefas filho em execução. Isso pode causar problemas se uma das tarefas filho executa uma operação que é importante para seu aplicativo, como a liberação de um recurso. Além disso, se uma tarefa filho lança uma exceção, essa exceção pode propagar através de um destruidor de objeto e causar um comportamento indefinido em seu aplicativo. Para obter um exemplo que ilustra esses pontos, consulte o [compreender como cancelamento e destruição de tratamento afetam o objeto de exceção](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) seção práticas recomendadas no documento de biblioteca de padrões paralelos. Para obter mais informações sobre o cancelamento e modelos de manipulação de exceção no PPL, consulte [cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md) e [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Como usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho do algoritmo de classificação bitonic.|  
|[Como usar Parallel.Invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada.|  
|[Como criar uma tarefa que seja concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md)|Mostra como usar o `task`, `cancellation_token_source`, `cancellation_token`, e `task_completion_event` classes para criar uma tarefa que seja concluída após um atraso.|  
|[Instruções passo a passo: implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)|Mostra como combinar a funcionalidade existente no tempo de execução de simultaneidade em algo que faz mais.|  
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve a PPL, que fornece um modelo de programação imperativo para desenvolver aplicativos simultâneos.|  
  
## <a name="reference"></a>Referência  
 [Classe task (Tempo de Execução de Simultaneidade)](../../parallel/concrt/reference/task-class.md)  
  
 [Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)  

 [Função when_all](reference/concurrency-namespace-functions.md#when_all)  
  
 [Função when_any](reference/concurrency-namespace-functions.md#when_any)  
  
 [Classe task_group](reference/task-group-class.md)  
  
 [Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)  
  
 [Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)
