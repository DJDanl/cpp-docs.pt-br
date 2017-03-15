---
title: "Paralelismo de tarefa (tempo de execu&#231;&#227;o de simultaneidade) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "grupos de tarefas estruturadas [Tempo de Execução de Simultaneidade]"
  - "grupos de tarefas estruturadas [Tempo de Execução de Simultaneidade]"
  - "grupos de tarefas [Tempo de Execução de Simultaneidade]"
  - "paralelismo da tarefa"
  - "tarefas [Tempo de Execução de Simultaneidade]"
ms.assetid: 42f05ac3-2098-494a-ba84-737fcdcad077
caps.latest.revision: 56
caps.handback.revision: 56
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Paralelismo de tarefa (tempo de execu&#231;&#227;o de simultaneidade)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

No tempo de execução de simultaneidade, um *tarefa* é uma unidade de trabalho que executa um trabalho específico e normalmente é executado em paralelo com outras tarefas. Uma tarefa pode ser decomposta em tarefas mais refinadas adicionais que são organizadas em um *grupo tarefas*.  
  
 Você usa tarefas quando você escrever código assíncrono e deseja alguma operação após a operação assíncrona for concluída. Por exemplo, você poderia usar uma tarefa para ler de um arquivo de forma assíncrona e, em seguida, usar outra tarefa — um *tarefa de continuação*, que é explicado mais adiante neste documento, para processar os dados depois que ele fica disponível. Por outro lado, você pode usar grupos de tarefas para decompor o trabalho paralelo em partes menores. Por exemplo, suponha que você tenha um algoritmo recursivo que divide o trabalho restante em duas partições. Você pode usar grupos de tarefas para executar essas partições simultaneamente e aguarde até que o trabalho dividido para ser concluído.  
  
> [!TIP]
>  Quando você deseja aplicar a mesma rotina para cada elemento de uma coleção em paralelo, use um algoritmo paralelo, como [concurrency::parallel_for](../Topic/parallel_for%20Function.md), em vez de uma tarefa ou um grupo de tarefas. Para obter mais informações sobre algoritmos paralelos, consulte [algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
## <a name="key-points"></a>Pontos-chave  
  
-   Quando você passa variáveis em uma expressão lambda por referência, você deve assegurar que o tempo de vida da variável persiste até que a tarefa seja concluída.  
  
-   Use tarefas (o [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md) classe) ao escrever o código assíncrono. A classe de tarefa usa o ThreadPool do Windows como seu Agendador, não o tempo de execução de simultaneidade.  
  
-   Use grupos de tarefas (o [concurrency::task_group](../Topic/task_group%20Class.md) classe ou o [concurrency::parallel_invoke](../Topic/parallel_invoke%20Function.md) algoritmo) quando quiser decompor o trabalho paralelo em partes menores e aguarde até que essas partes menores concluir.  
  
-   Use o [concurrency::task::then](../Topic/task::then%20Method.md) método para criar continuações. Um *continuação* é uma tarefa que executa de forma assíncrona, após a conclusão de outra tarefa. Você pode se conectar a qualquer número de continuações para formar uma cadeia de trabalho assíncrono.  
  
-   Uma continuação de tarefas sempre é agendada para execução quando a tarefa antecedente termina, mesmo quando a tarefa antecedente foi cancelada ou gera uma exceção.  
  
-   Use [concurrency:: HYPERLINK "http://msdn.microsoft.com/library/system.threading.tasks.task.whenall (v=VS.110).aspx" when_all](../Topic/when_all%20Function.md) para criar uma tarefa concluída após a conclusão de cada membro de um conjunto de tarefas. Use [concurrency::when_any](../Topic/when_all%20Function.md) para criar uma tarefa concluída após a conclusão de um membro de um conjunto de tarefas.  
  
-   Tarefas e grupos de tarefas podem participar no mecanismo de cancelamento da biblioteca de padrões paralelos (PPL). Para obter mais informações, consulte [cancelamento](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md#cancellation_in_the_ppl).  
  
-   Para saber como o runtime lida com exceções lançadas por tarefas e grupos de tarefas, consulte [Exception Handling](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
## <a name="in-this-document"></a>Neste Documento  
  
- [Usando expressões Lambda](#lambdas)  
  
- [A classe task](#task-class)  
  
- [Tarefas de continuação](#continuations)  
  
- [Com base em valor Versus continuações baseado em tarefas](#value-versus-task)  
  
- [Compondo tarefas](#composing-tasks)  
  
    - [A função when_all](#when-all)  
  
    - [A função when_any](#when-any)  
  
- [Execução de tarefa com atraso](#delayed-tasks)  
  
- [Grupos de tarefas](#task-groups)  
  
- [Comparando task_group a structured_task_group](#comparing-groups)  
  
- [Exemplo](#example)  
  
- [Programação robusta](#robust)  
  
##  <a name="a-namelambdasa-using-lambda-expressions"></a><a name="lambdas"></a> Usando expressões Lambda  
 Devido a sua sintaxe sucinta, expressões lambda são uma maneira comum de definir o trabalho que é executado por tarefas e grupos de tarefas. Aqui estão algumas dicas de uso:  
  
-   Como tarefas normalmente executados em threads em segundo plano, fique atento a vida útil do objeto quando você captura variáveis em expressões lambda. Quando você captura uma variável pelo valor, é feita uma cópia da variável no corpo do lambda. Ao capturar por referência, não é feita uma cópia. Portanto, certifique-se de que o tempo de vida de qualquer variável capturar por referência é maior que a tarefa que o utiliza.  
  
-   Quando você passar uma expressão lambda para uma tarefa, não capture variáveis que são alocados na pilha por referência.  
  
-   Ser explícito sobre as variáveis que você capturar em expressões lambda para que você possa identificar o que você está capturando por valor versus por referência. Por esse motivo, é recomendável que você não use o `[=]` ou `[&]` Opções de expressões lambda.  
  
 Um padrão comum é quando uma tarefa em uma cadeia de continuação atribui a uma variável, e outra tarefa lê essa variável. Você não pode capturar por valor, porque cada tarefa de continuação manterá uma cópia diferente da variável. Para variáveis alocado na pilha, você também não pode capturar por referência porque a variável pode não ser mais válida.  
  
 Para resolver esse problema, use um ponteiro inteligente, como [std::shared_ptr](../../standard-library/shared-ptr-class.md), para encapsular a variável e passar o ponteiro inteligente por valor. Dessa forma, o objeto subjacente pode ser atribuído a ler e irá durar mais que as tarefas que o utilizam. Usar essa técnica, mesmo quando a variável é um ponteiro ou um identificador de contagem de referência (`^`) a um objeto de tempo de execução do Windows. Aqui está um exemplo básico:  
  
 [!code-cpp[concrt-lambda-task-lifetime#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_1.cpp)]  
  
 Para obter mais informações sobre expressões lambda, consulte [expressões Lambda](../../cpp/lambda-expressions-in-cpp.md).  
  
##  <a name="a-nametask-classa-the-task-class"></a><a name="task-class"></a> A classe task  
 Você pode usar o [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md) classe para compor tarefas em um conjunto de operações dependentes. Esse modelo de composição tem suporte a noção de *continuações*. Um código de habilita continuação a ser executada quando o anterior, ou *antecedente*, tarefa seja concluída. O resultado da tarefa antecedente é passado como entrada para as tarefas de continuação de um ou mais. Quando uma tarefa antecedente for concluído, as tarefas de continuação que estão aguardando estiverem agendadas para execução. Cada tarefa de continuação recebe uma cópia do resultado da tarefa antecedente. Por sua vez, as tarefas de continuação também podem ser tarefas antecedente para outras continuações, criando uma cadeia de tarefas. Continuações ajudam a criar cadeias de comprimento arbitrário de tarefas que têm dependências específicas entre eles. Além disso, uma tarefa pode participar no cancelamento antes de uma lista de tarefas é iniciado ou de forma cooperativa durante a execução. Para obter mais informações sobre esse modelo de cancelamento, consulte [cancelamento](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md#cancellation_in_the_ppl).  
  
 `task` é uma classe de modelo. O parâmetro de tipo `T` é o tipo de resultado que é produzido pela tarefa. Esse tipo pode ser `void` se a tarefa não retornar um valor. `T` não é possível usar o `const` modificador.  
  
 Quando você cria uma tarefa, você fornece um *função de trabalho* que executa o corpo da tarefa. Essa função de trabalho vem na forma de uma função lambda, ponteiro de função ou objeto de função. Para aguardar uma tarefa seja concluída sem obter o resultado, chame o [concurrency::task::wait](../Topic/task::wait%20Method.md) método. O `task::wait` método retorna um [concurrency::task_status](../Topic/task_group_status%20Enumeration.md) valor que descreve se a tarefa foi concluída ou cancelada. Para obter o resultado da tarefa, chame o [concurrency::task::get](../Topic/task::get%20Method.md) método. Esse método chama `task::wait` para aguardar a tarefa para concluir e, portanto, bloqueará a execução do thread atual até que o resultado esteja disponível.  
  
 O exemplo a seguir mostra como criar uma tarefa, aguarde seu resultado e exibir seu valor. Os exemplos nesta documentação usam funções lambda porque elas fornecem uma sintaxe mais sucinta. No entanto, você também pode usar a ponteiros de função e objetos de função quando você usa tarefas.  
  
 [!code-cpp[concrt-basic-task#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_2.cpp)]  
  
 Quando você usa o [concurrency::create_task](../Topic/create_task%20Function.md) função, você pode usar o `auto` palavra-chave em vez de declarar o tipo. Por exemplo, considere este código que cria e imprime a matriz de identidade:  
  
 [!code-cpp[concrt-create-task#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_3.cpp)]  
  
 Você pode usar o `create_task` função para criar a operação equivalente.  
  
 [!code-cpp[concrt-create-task#2](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_4.cpp)]  
  
 Se uma exceção é lançada durante a execução de uma tarefa, o tempo de execução controla essa exceção em uma chamada subsequente para `task::get` ou `task::wait`, ou uma continuação baseado em tarefa. Para obter mais informações sobre o mecanismo de manipulação de exceção de tarefa, consulte [Exception Handling](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
 Para obter um exemplo que usa `task`, [concurrency::task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md), cancelamento, consulte [passo a passo: conectando usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md). (O `task_completion_event` classe é descrita mais adiante neste documento.)  
  
> [!TIP]
>  Para obter detalhes sobre o que são específicos a tarefas em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos, consulte [programação assíncrona em C++](http://msdn.microsoft.com/pt-br/512700b7-7863-44cc-93a2-366938052f31) e [Criando operações assíncronas em C++ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).  
  
##  <a name="a-namecontinuationsa-continuation-tasks"></a><a name="continuations"></a> Tarefas de continuação  
 Na programação assíncrona, é muito comum para uma operação assíncrona, após a conclusão, para invocar uma operação de segundo e passar dados para ele. Tradicionalmente, isso é feito usando os métodos de retorno de chamada. No tempo de execução de simultaneidade, a mesma funcionalidade é fornecida pelo *tarefas de continuação*. Uma tarefa de continuação (também conhecida como uma continuação) é uma tarefa assíncrona é invocada por outra tarefa, que é conhecida como o *antecedente*, quando antecedente é concluída. Usando continuações, você pode:  
  
-   Passe dados de antecedente para a continuação.  
  
-   Especifique as condições precisas sob a qual a continuação é chamada ou não chamada.  
  
-   Cancele uma continuação antes de iniciar ou cooperativamente enquanto ele é executado.  
  
-   Fornece dicas sobre como a continuação deve ser agendada. (Isso se aplica a [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] apenas os aplicativos. Para obter mais informações, consulte [Criando operações assíncronas em C++ para aplicativos da Windows Store](../../parallel/concrt/creating-asynchronous-operations-in-cpp-for-windows-store-apps.md).)  
  
-   Chama várias continuações da mesma antecedente.  
  
-   Solicite uma continuação quando todos ou qualquer um dos vários antecedentes concluída.  
  
-   Encadear continuações após o outro para qualquer tamanho.  
  
-   Use uma continuação para manipular exceções lançadas por antecedente.  
  
 Esses recursos permitem que você execute uma ou mais tarefas quando a primeira tarefa é concluída. Por exemplo, você pode criar uma continuação que compacta um arquivo após a primeira tarefa lê-lo do disco.  
  
 O exemplo a seguir modifica um anterior para usar o [concurrency::task::then](../Topic/task::then%20Method.md) método programar uma continuação que imprime o valor da tarefa antecedente quando ela estiver disponível.  
  
 [!code-cpp[concrt-basic-continuation#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_5.cpp)]  
  
 Você pode encadear e aninhar tarefas para qualquer tamanho. Uma tarefa também pode ter várias continuações. O exemplo a seguir ilustra uma cadeia de continuação básica que incrementa o valor da tarefa anterior três vezes.  
  
 [!CODE [concrt-continuation-chain#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-continuation-chain#1)]  
  
 Uma continuação também pode retornar a outra tarefa. Se não houver nenhum Cancelar, essa tarefa é executada antes da continuação subsequente. Essa técnica é conhecida como *desempacotamento assíncrona*. Desempacotamento assíncrona é útil quando você deseja realizar o trabalho adicional em segundo plano, mas não quiser que a tarefa atual para bloquear o thread atual. (Isso é comum em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos, onde continuações podem ser executado no thread da interface do Usuário). O exemplo a seguir mostra três tarefas. A primeira tarefa retorna outra tarefa que é executada antes de uma tarefa de continuação.  
  
 [!code-cpp[concrt-async-unwrapping#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_6.cpp)]  
  
> [!IMPORTANT]
>  Quando uma continuação da tarefa retorna uma tarefa aninhada do tipo `N`, a tarefa resultante tem o tipo `N`, não `task<N>`, e termina quando a tarefa aninhada é concluída. Em outras palavras, a continuação executa desempacotamento da tarefa aninhada.  
  
##  <a name="a-namevalue-versus-taska-value-based-versus-task-based-continuations"></a><a name="value-versus-task"></a> Com base em valor Versus continuações baseado em tarefas  
 Dado um `task` objeto cujo tipo de retorno é `T`, você pode fornecer um valor do tipo `T` ou `task<T>` para suas tarefas de continuação. Uma continuação que usa o tipo `T` é conhecido como um *continuação de acordo com o valor*. Uma continuação de acordo com o valor é agendada para execução quando a tarefa antecedente é concluído sem erros e não for cancelada. Uma continuação que usa o tipo `task<T>` como seu parâmetro é conhecido como um *baseado em tarefa continuação*. Uma continuação de tarefas sempre é agendada para execução quando a tarefa antecedente termina, mesmo quando a tarefa antecedente foi cancelada ou gera uma exceção. Você pode chamar `task::get` para obter o resultado da tarefa antecedente. Se a tarefa antecedente foi cancelada, `task::get` lança [concurrency::task_canceled](../../parallel/concrt/reference/task-canceled-class.md). Se a tarefa antecedente lançou uma exceção, `task::get` relança essa exceção. Uma continuação baseado em tarefa não é marcada como cancelada quando sua tarefa antecedente é cancelada.  
  
##  <a name="a-namecomposing-tasksa-composing-tasks"></a><a name="composing-tasks"></a> Compondo tarefas  
 Esta seção descreve o [concurrency::when_all](../Topic/when_all%20Function.md) e [concurrency::when_any](../Topic/when_all%20Function.md) funções, que podem ajudá-lo a composição de várias tarefas para implementar os padrões comuns.  
  
###  <a name="a-namewhen-alla-the-whenall-function"></a><a name="when-all"></a> A função when_all  
 O `when_all` função produz uma tarefa é concluída depois de concluir um conjunto de tarefas. Esta função retorna um std::[vetor](../../standard-library/vector-class.md) objeto que contém o resultado de cada tarefa no conjunto. O seguinte exemplo básico usa `when_all` para criar uma tarefa que representa a conclusão das três outras tarefas.  
  
 [!code-cpp[concrt-join-tasks#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_7.cpp)]  
  
> [!NOTE]
>  As tarefas que você passa para `when_all` deve ser uniforme. Em outras palavras, eles devem todos retornar o mesmo tipo.  
  
 Você também pode usar o `&&` sintaxe para produzir uma tarefa é concluída depois de concluir um conjunto de tarefas, conforme mostrado no exemplo a seguir.  
  
 `auto t = t1 && t2; // same as when_all`  
  
 É comum usar uma continuação junto com `when_all` para executar uma ação após a conclusão de um conjunto de tarefas. O exemplo a seguir modifica o um anterior para imprimir a soma dos três tarefas que cada um, produzir um `int` resultado.  
  
 [!code-cpp[concrt-join-tasks#2](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_8.cpp)]  
  
 Neste exemplo, você também pode especificar`task<vector<int>>` para produzir uma continuação baseado em tarefa.  
  
 Se qualquer tarefa em um conjunto de tarefas for cancelada ou gerar uma exceção `when_all` é concluída imediatamente e não espera para as tarefas restantes concluir. Se uma exceção for lançada, o tempo de execução Relança a exceção ao chamar `task::get` ou `task::wait` da tarefa do objeto que `when_all` retorna. Se mais de uma tarefa gera, o runtime decide que um deles. Portanto, certifique-se de que você observar todas as exceções depois de concluir todas as tarefas; uma exceção não tratada tarefa faz com que o aplicativo encerrar.  
  
 Aqui está uma função de utilitário que você pode usar para garantir que seu programa observa todas as exceções. Para cada tarefa no intervalo fornecido, `observe_all_exceptions` aciona uma exceção que ocorreu para ser emitida novamente e, em seguida, absorve essa exceção.  
  
 [!code-cpp[concrt-eh-when_all#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_9.cpp)]  
  
 Considere um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo que usa C++ e XAML e grava um conjunto de arquivos no disco. O exemplo a seguir mostra como usar `when_all` e `observe_all_exceptions` para garantir que o programa observa todas as exceções.  
  
 [!code-cpp[concrt-eh-when_all#2](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_10.cpp)]  
  
##### <a name="to-run-this-example"></a>Para executar este exemplo  
  
1.  Em MainPage. XAML, adicione um `Button` controle.  
  
 [!code-xml[concrt-eh-when_all#3](../../parallel/concrt/codesnippet/Xaml/task-parallelism-concurrency-runtime_11.xaml)]  
  
2.  Em MainPage.xaml.h, adicione estas declarações de encaminhamento para o `private` seção o `MainPage` declaração de classe.  
  
 [!code-cpp[concrt-eh-when_all#4](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_12.h)]  
  
3.  No MainPage.xaml.cpp, implemente o `Button_Click` manipulador de eventos.  
  
 [!code-cpp[concrt-eh-when_all#5](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_13.cpp)]  
  
4.  Em MainPage.xaml.cpp, implementar `WriteFilesAsync` conforme mostrado no exemplo.  
  
> [!TIP]
> `when_all` é uma função sem bloqueio que produz um `task` como resultado. Ao contrário de [Task:: wait](../Topic/task::wait%20Method.md), é seguro chamar essa função em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo no thread ASTA (aplicativo STA).  
  
###  <a name="a-namewhen-anya-the-whenany-function"></a><a name="when-any"></a> A função when_any  
 O `when_any` função produz uma tarefa concluída quando a primeira tarefa em um conjunto de tarefas seja concluída. Esta função retorna um [std::pair](../../standard-library/pair-structure.md) objeto que contém o resultado da tarefa concluída e o índice da tarefa no conjunto.  
  
 O `when_any` função é especialmente útil nas seguintes situações:  
  
-   Operações redundantes. Considere um algoritmo ou uma operação que possam ser executados de várias maneiras. Você pode usar o `when_any` função para selecionar a operação que termina primeiro e, em seguida, cancelar as operações restantes.  
  
-   Operações intercaladas. Você pode iniciar várias operações que todos devem concluir e usar o `when_any` função para processar os resultados que cada operação é concluída. Após uma operação ser concluída, você poderá começar uma ou mais tarefas adicionais.  
  
-   Operações controladas. Você pode usar o `when_any` função para estender o cenário anterior, limitando o número de operações simultâneas.  
  
-   Operações expiradas. Você pode usar o `when_any` função para selecionar entre uma ou mais tarefas e uma tarefa que termine após um tempo específico.  
  
 Assim como acontece com `when_all`, é comum usar uma continuação tem `when_any` para executar ações quando concluir o primeiro em um conjunto de tarefas. O seguinte exemplo básico usa `when_any` para criar uma tarefa concluída quando a primeira das três outras tarefas é concluída.  
  
 [!code-cpp[concrt-select-task#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_14.cpp)]  
  
 Neste exemplo, você também pode especificar `task<pair<int, size_t>>` para produzir uma continuação baseado em tarefa.  
  
> [!NOTE]
>  Assim como acontece com `when_all`, as tarefas que você passa para `when_any` todos devem retornar o mesmo tipo.  
  
 Você também pode usar o `||` sintaxe para produzir uma tarefa concluída após a primeira tarefa em um conjunto de tarefas, conforme mostrado no exemplo a seguir.  
  
 `auto t = t1 || t2; // same as when_any`  
  
> [!TIP]
>  Assim como acontece com `when_all`, `when_any` é desbloqueado e é seguro chamar um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo no thread ASTA.  
  
##  <a name="a-namedelayed-tasksa-delayed-task-execution"></a><a name="delayed-tasks"></a> Execução de tarefa com atraso  
 Às vezes é necessária para atrasar a execução de uma tarefa até que uma condição for atendida, ou para iniciar uma tarefa em resposta a um evento externo. Por exemplo, na programação assíncrona, você pode ter que iniciar uma tarefa em resposta a um evento de conclusão de e/s.  
  
 São duas maneiras de fazer isso para usar uma continuação ou iniciar uma tarefa e aguardar um evento dentro da função de trabalho da tarefa. No entanto, há casos em que ele não é possível usar uma dessas técnicas. Por exemplo, para criar uma continuação, você deve ter a tarefa antecedente. No entanto, se você não tiver a tarefa antecedente, você pode criar um *evento de conclusão de tarefas* e posteriormente encadear esse evento de conclusão da tarefa antecedente quando estiverem disponível. Além disso, como uma tarefa de espera também bloqueia um thread, você pode usar eventos de conclusão de tarefas para executar o trabalho quando uma operação assíncrona for concluída e, assim, liberar um thread.  
  
 O [concurrency::task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md) classe ajuda a simplificar tal composição de tarefas. Como o `task` de classe, o parâmetro de tipo `T` é o tipo de resultado que é produzido pela tarefa. Esse tipo pode ser `void` se a tarefa não retornar um valor. `T` não é possível usar o `const` modificador. Normalmente, um `task_completion_event` objeto é fornecido para um thread ou tarefa que será sinaliza quando o valor para que ele se torna disponível. Ao mesmo tempo, uma ou mais tarefas são definidas como ouvintes de evento. Quando o evento é definido, conclua as tarefas de ouvinte e seus continuações estão agendadas para execução.  
  
 Para obter um exemplo que usa `task_completion_event` para implementar uma tarefa concluída após um atraso, consulte [como: criar uma tarefa que é concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md).  
  
##  <a name="a-nametask-groupsa-task-groups"></a><a name="task-groups"></a> Grupos de tarefas  
 Um *grupo tarefas* organiza um conjunto de tarefas. Grupos de tarefas por push tarefas em uma fila de roubo de trabalho. O Agendador remove tarefas da fila e executa em recursos de computação disponíveis. Depois de adicionar tarefas a um grupo de tarefas, você pode esperar para todas as tarefas concluir ou Cancelar tarefas que ainda não iniciadas.  
  
 A PPL usa o [concurrency::task_group](../Topic/task_group%20Class.md) e [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes que representam grupos de tarefas e o [concurrency::task_handle](../../parallel/concrt/reference/task-handle-class.md) classe para representar as tarefas que executam esses grupos. O `task_handle` classe encapsula o código que executa o trabalho. Como o `task` classe, a função de trabalho vem na forma de uma função lambda, o ponteiro de função ou o objeto de função. Você normalmente não precisa trabalhar com `task_handle` objetos diretamente. Em vez disso, você passa as funções de trabalho para um grupo de tarefas e o grupo de tarefas cria e gerencia o `task_handle` objetos.  
  
 A PPL divide os grupos de tarefas em dessas duas categorias: *grupos de tarefas não estruturados* e *estruturado de grupos de tarefas*. A PPL usa o `task_group` classe para representar grupos de tarefas não estruturados e `structured_task_group` classe para representar grupos de tarefas estruturadas.  
  
> [!IMPORTANT]
>  A PPL também define o [concurrency::parallel_invoke](../Topic/parallel_invoke%20Function.md) algoritmo, que utiliza a `structured_task_group` classe para executar um conjunto de tarefas em paralelo. Porque o `parallel_invoke` algoritmo tem uma sintaxe mais sucinta, recomendamos que você usá-lo em vez do `structured_task_group` classe quando possível. O tópico [algoritmos paralelos](../Topic/Parallel%20Algorithms.md) descreve `parallel_invoke` mais detalhadamente.  
  
 Use `parallel_invoke` quando você tem várias tarefas independentes que você deseja executar ao mesmo tempo, e você deve aguardar para todas as tarefas sejam concluídas antes de continuar. Essa técnica é conhecida como *bifurcação e junção* paralelismo. Use `task_group` quando você tem várias tarefas independentes que você deseja executar ao mesmo tempo, mas deseja aguardar as finalização de tarefas em um momento posterior. Por exemplo, você pode adicionar tarefas a um `task_group` do objeto e esperar que as tarefas sejam concluídas em outra função ou de outro segmento.  
  
 Grupos de tarefas suportam o conceito de cancelamento. Cancelamento permite sinalizar para todas as tarefas ativas que você deseja cancelar a operação geral. Cancelamento também impede que a tarefas que ainda não iniciaram seja iniciado. Para obter mais informações sobre cancelamento, consulte [cancelamento](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md#cancellation_in_the_ppl).  
  
 O tempo de execução também fornece um modelo de manipulação de exceção que permite que você lance uma exceção de uma tarefa e tratar essa exceção ao aguardar o grupo de tarefas associadas ao fim. Para obter mais informações sobre esse modelo de manipulação de exceção, consulte [Exception Handling](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
##  <a name="a-namecomparing-groupsa-comparing-taskgroup-to-structuredtaskgroup"></a><a name="comparing-groups"></a> Comparando task_group a structured_task_group  
 Embora, recomendamos que você use `task_group` ou `parallel_invoke` em vez do `structured_task_group` da classe, há casos em que você deseja usar `structured_task_group`, por exemplo, quando você escreve um algoritmo paralelo que executa um número variável de tarefas ou requer suporte para cancelamento. Esta seção explica as diferenças entre o `task_group` e `structured_task_group` classes.  
  
 O `task_group` classe é thread-safe. Portanto, você pode adicionar tarefas a um `task_group` de objeto de vários threads e esperar ou cancelar uma `task_group` objeto de vários threads. A construção e destruição de um `structured_task_group` objeto deve ocorrer no mesmo escopo léxico. Além disso, todas as operações em um `structured_task_group` objeto deve ocorrer no mesmo thread. A exceção a essa regra é o [concurrency::structured_task_group::cancel](../Topic/structured_task_group::cancel%20Method.md) e [concurrency::structured_task_group::is_canceling](../Topic/structured_task_group::is_canceling%20Method.md) métodos. Uma tarefa filho pode chamar esses métodos para cancelar o grupo de tarefas do pai ou verificar se há cancelamento a qualquer momento.  
  
 Você pode executar tarefas adicionais em uma `task_group` objeto depois de chamar o [concurrency::task_group::wait](../Topic/task_group::wait%20Method.md) ou [concurrency::task_group::run_and_wait](../Topic/task_group::run_and_wait%20Method.md) método. Por outro lado, se você executar tarefas adicionais em uma `structured_task_group` objeto depois de chamar o [concurrency::structured_task_group::wait](../Topic/structured_task_group::wait%20Method.md) ou [concurrency::structured_task_group::run_and_wait](../Topic/structured_task_group::run_and_wait%20Method.md) métodos e, em seguida, o comportamento é indefinido.  
  
 Porque o `structured_task_group` classe não sincronizar entre threads, ele tem menos sobrecarga que a execução de `task_group` classe. Portanto, se o problema não exigir que você agenda o trabalho de vários threads e você não pode usar o `parallel_invoke` algoritmo, a `structured_task_group` classe pode ajudá-lo a escrever código melhor desempenho.  
  
 Se você usar um `structured_task_group` objeto dentro de outro `structured_task_group` objeto, o objeto interno deve ser concluída e ser destruído antes de concluir o objeto externo. O `task_group` classe não requer para grupos de tarefas aninhadas terminar antes do grupo externo termina.  
  
 Grupos de tarefas não estruturados e grupos de tarefas estruturadas funcionam com identificadores de tarefa de maneiras diferentes. Você pode passar as funções de trabalho diretamente para uma `task_group` objeto; o `task_group` objeto irá criar e gerenciar o identificador de tarefa para você. O `structured_task_group` classe requer que você gerencie um `task_handle` objeto para cada tarefa. Cada `task_handle` objeto deve permanecer válido durante a vida útil de seus associados `structured_task_group` objeto. Use o [concurrency::make_task](../Topic/make_task%20Function.md) função para criar um `task_handle` do objeto, conforme mostrado no seguinte exemplo básico:  
  
 [!code-cpp[concrt-make-task-structure#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_15.cpp)]  
  
 Para gerenciar os identificadores de tarefa para casos em que há um número variável de tarefas, use uma rotina de alocação da pilha, como [malloca](../../c-runtime-library/reference/malloca.md) ou uma classe de contêiner, como std::[vetor](../../standard-library/vector-class.md).  
  
 Ambos `task_group` e `structured_task_group` oferecem suporte ao cancelamento. Para obter mais informações sobre cancelamento, consulte [cancelamento](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md#cancellation_in_the_ppl).  
  
##  <a name="a-nameexamplea-example"></a><a name="example"></a> Exemplo  
 O exemplo básico a seguir mostra como trabalhar com grupos de tarefas. Este exemplo usa o `parallel_invoke` algoritmo para realizar duas tarefas simultaneamente. Cada tarefa adiciona subtarefas uma `task_group` objeto. Observe que o `task_group` classe permite várias tarefas adicionar tarefas nele simultaneamente.  
  
 [!code-cpp[concrt-using-task-groups#1](../../parallel/concrt/codesnippet/CPP/task-parallelism-concurrency-runtime_16.cpp)]  
  
 A seguir está a saída de exemplo para este exemplo:  
  
```Output  
Message from task: Hello  
Message from task: 3.14  
Message from task: 42  
```  
  
 Porque o `parallel_invoke` algoritmo executa tarefas simultaneamente, a ordem das mensagens de saída pode variar.  
  
 Para concluir exemplos que mostram como usar o `parallel_invoke` algoritmo, consulte [como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md) e [como: usar parallel_invoke para executar operações em paralelo](../Topic/How%20to:%20Use%20parallel_invoke%20to%20Execute%20Parallel%20Operations.md). Para obter um exemplo completo que usa o `task_group` classe implementar futuros assíncronos, consulte [passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md).  
  
##  <a name="a-namerobusta-robust-programming"></a><a name="robust"></a> Programação robusta  
 Certifique-se de que você compreenda a função de cancelamento e tratamento de exceções ao usar tarefas, grupos de tarefas e algoritmos paralelos. Por exemplo, em uma árvore de trabalho paralelo, uma tarefa que é cancelada impede tarefas filho em execução. Isso pode causar problemas se uma das tarefas filho executa uma operação que é importante para seu aplicativo, como liberar um recurso. Além disso, se uma tarefa filho lança uma exceção, essa exceção pode propagar através de um destruidor de objeto e causar um comportamento indefinido em seu aplicativo. Para obter um exemplo que ilustra esses pontos, consulte o [compreender como cancelamento e destruição de tratamento afetam objetos exceção](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) seção nas práticas recomendadas do documento da biblioteca de padrões paralelos. Para obter mais informações sobre o cancelamento e modelos de tratamento de exceção no PPL, consulte [cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md) e [Exception Handling](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho do algoritmo de classificação bitonic.|  
|[Como: usar parallel_invoke para executar operações em paralelo](../Topic/How%20to:%20Use%20parallel_invoke%20to%20Execute%20Parallel%20Operations.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada.|  
|[Como: criar uma tarefa seja concluída após um atraso](../../parallel/concrt/how-to-create-a-task-that-completes-after-a-delay.md)|Mostra como usar o `task`, `cancellation_token_source`, `cancellation_token`, e `task_completion_event` classes para criar uma tarefa seja concluída após um atraso.|  
|[Passo a passo: Implementando futuros](../../parallel/concrt/walkthrough-implementing-futures.md)|Mostra como combinar a funcionalidade existente em tempo de execução de simultaneidade em algo que faz mais.|  
|[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve a PPL, que fornece um modelo de programação imperativo para desenvolver aplicativos simultâneos.|  
  
## <a name="reference"></a>Referência  
 [tarefa de classe (tempo de execução de simultaneidade)](../../parallel/concrt/reference/task-class-concurrency-runtime.md)  
  
 [Classe task_completion_event](../../parallel/concrt/reference/task-completion-event-class.md)  
  
 [Função when_all](../Topic/when_all%20Function.md)  
  
 [Função when_any](../Topic/when_any%20Function.md)  
  
 [Classe task_group](../Topic/task_group%20Class.md)  
  
 [Função parallel_invoke](../Topic/parallel_invoke%20Function.md)  
  
 [Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)
