---
title: Práticas recomendadas na Biblioteca de Padrões Paralelos
ms.date: 11/04/2016
helpviewer_keywords:
- Parallel Patterns Library, practices to avoid
- practices to avoid, Parallel Patterns Library
- best practices, Parallel Patterns Library
- Parallel Patterns Library, best practices
ms.assetid: e43e0304-4d54-4bd8-a3b3-b8673559a9d7
ms.openlocfilehash: 153dbf461176ee62f42dbe41a1c426a8c34ae716
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50503271"
---
# <a name="best-practices-in-the-parallel-patterns-library"></a>Práticas recomendadas na Biblioteca de Padrões Paralelos

Este documento descreve a melhor maneira para fazer uso eficiente da paralela padrões PPL (biblioteca). O PPL fornece algoritmos, objetos e contêineres para fins gerais para executar o paralelismo refinado.

Para obter mais informações sobre o PPL, consulte [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).

##  <a name="top"></a> Seções

Este documento contém as seguintes seções:

- [Não paralelizar corpos de Loop pequenos](#small-loops)

- [Expressar paralelismo no nível mais alto possível](#highest)

- [Usar parallel_invoke para solucionar problemas de "dividir e conquistar"](#divide-and-conquer)

- [Usar cancelamento ou tratamento de exceções para quebra de um loop paralelo](#breaking-loops)

- [Compreender como cancelamento e tratamento de exceção afetam a destruição de objeto](#object-destruction)

- [Não bloquear repetidamente em um Loop paralelo](#repeated-blocking)

- [Não execute operações de bloqueio ao cancelar o trabalho paralelo](#blocking)

- [Não gravam dados compartilhados em um Loop paralelo](#shared-writes)

- [Quando possível, evitar compartilhamento falso](#false-sharing)

- [Certifique-se de que as variáveis são válidas em todo o tempo de vida de uma tarefa](#lifetime)

##  <a name="small-loops"></a> Não paralelizar corpos de Loop pequenos

A paralelização de corpos de loop relativamente pequeno pode causar o associado sobrecarga de agendamento para superar os benefícios do processamento paralelo. Considere o exemplo a seguir, que adiciona cada par de elementos em duas matrizes.

[!code-cpp[concrt-small-loops#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_1.cpp)]

A carga de trabalho para cada iteração do loop paralelo é pequena demais para se beneficiar com a sobrecarga de processamento paralelo. Você pode melhorar o desempenho desse loop, executando mais de trabalho no corpo do loop ou executando o loop em série.

[[Superior](#top)]

##  <a name="highest"></a> Expressar paralelismo no nível mais alto possível

Ao paralelizar código somente no nível inferior, você pode introduzir uma construção de bifurcação-junção que não são dimensionadas como o número de processadores aumentar. Um *bifurcação-junção* construção é uma construção em que uma tarefa divide seu trabalho em menores subtarefas paralelas e espera que essas subtarefas concluir. Cada subtarefa pode dividir recursivamente em si em subtarefas adicionais.

Embora o modelo de bifurcação-junção pode ser útil para solucionar uma variedade de problemas, há situações em que a sobrecarga de sincronização pode diminuir a escalabilidade. Por exemplo, considere o seguinte código serial que processa dados de imagem.

[!code-cpp[concrt-image-processing-filter#20](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_2.cpp)]

Como cada iteração do loop é independente, você consegue paralelizar tão grande parte do trabalho, conforme mostrado no exemplo a seguir. Este exemplo usa o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo para paralelizar o loop externo.

[!code-cpp[concrt-image-processing-filter#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_3.cpp)]

O exemplo a seguir ilustra um constructo de bifurcação-junção chamando o `ProcessImage` função em um loop. Cada chamada para `ProcessImage` não retorna até que termine a cada subtarefa.

[!code-cpp[concrt-image-processing-filter#21](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_4.cpp)]

Se cada iteração do loop paralelo a executa quase nenhum trabalho ou o trabalho que é executado pelo loop paralelo é desequilibrada, ou seja, algumas iterações do loop demoram mais do que outras pessoas, a sobrecarga de agendamento que é necessário para bifurcar com frequência e o trabalho de junção pode supera o benefício para execução paralela. Essa sobrecarga aumenta à medida que o número de processadores aumentar.

Para reduzir a quantidade de agendamento de sobrecarga neste exemplo, você pode paralelizar loops externas antes de paralelizar loops internos ou usar outro constructo paralelo como pipelining. O exemplo a seguir modifica o `ProcessImages` função para usar o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo para paralelizar o loop externo.

[!code-cpp[concrt-image-processing-filter#22](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_5.cpp)]

Para obter um exemplo semelhante que usa um pipeline para executar o processamento de imagens em paralelo, consulte [instruções passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

[[Superior](#top)]

##  <a name="divide-and-conquer"></a> Usar parallel_invoke para solucionar problemas de "dividir e conquistar"

Um *dividir e conquistar* problema é uma forma da construção de bifurcação-junção que usa a recursão para dividir uma tarefa em subtarefas. Além de [Concurrency:: task_group](reference/task-group-class.md) e [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes, você também pode usar o [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo para Solucione problemas de "dividir e conquistar". O `parallel_invoke` algoritmo tem uma sintaxe mais sucinta que os objetos de grupo de tarefas e é útil quando você tem um número fixo de tarefas paralelas.

O exemplo a seguir ilustra o uso do `parallel_invoke` algoritmo para implementar o algoritmo de classificação de bitonic.

[!code-cpp[concrt-parallel-bitonic-sort#12](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_6.cpp)]

Para reduzir a sobrecarga, o `parallel_invoke` algoritmo executa o último da série de tarefas no contexto de chamada.

Para obter a versão completa deste exemplo, consulte [como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md). Para obter mais informações sobre o `parallel_invoke` algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

[[Superior](#top)]

##  <a name="breaking-loops"></a> Usar cancelamento ou tratamento de exceções para quebra de um loop paralelo

O PPL fornece duas maneiras de cancelar o trabalho paralelo executado por um grupo de tarefas ou o algoritmo paralelo. Uma maneira é usar o mecanismo de cancelamento é fornecido pelos [Concurrency:: task_group](reference/task-group-class.md) e [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes. A outra maneira é gerar uma exceção no corpo de uma função de trabalho da tarefa. O mecanismo de cancelamento é mais eficiente do que em uma árvore de trabalho em paralelo o cancelamento de tratamento de exceções. Um *árvore de trabalho paralelo* é um grupo de grupos de tarefas relacionadas no qual alguns grupos de tarefas contêm outros grupos de tarefas. O mecanismo de cancelamento cancela um grupo de tarefas e seus grupos de tarefas filho de uma maneira de cima para baixo. Por outro lado, o tratamento de exceção funciona de uma maneira de baixo para cima e deve cancelar a cada grupo de tarefas filho independentemente como a exceção for propagada para cima.

Quando você trabalha diretamente com um objeto de grupo de tarefas, use o [concurrency::task_group::cancel](reference/task-group-class.md#cancel) ou [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) métodos para cancelar o trabalho que pertence a esse grupo de tarefas . Para cancelar um algoritmo paralelo, por exemplo, `parallel_for`, crie um grupo de tarefas pai e cancelar a esse grupo de tarefas. Por exemplo, considere a seguinte função, `parallel_find_any`, que procura um valor em uma matriz em paralelo.

[!code-cpp[concrt-parallel-array-search#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_7.cpp)]

Como os algoritmos paralelos usam grupos de tarefas, quando uma das iterações paralelas cancela o grupo de tarefas pai, a tarefa geral é cancelada. Para obter a versão completa deste exemplo, consulte [como: Use o cancelamento para interromper um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md).

Embora o tratamento de exceções é uma maneira menos eficiente para cancelar o trabalho paralelo que o mecanismo de cancelamento, há casos em que a manipulação de exceção é apropriada. Por exemplo, o seguinte método, `for_all`, recursivamente executa uma função de trabalho em cada nó de um `tree` estrutura. Neste exemplo, o `_children` membro de dados é um [std:: List](../../standard-library/list-class.md) que contém `tree` objetos.

[!code-cpp[concrt-task-tree-search#6](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_8.cpp)]

O chamador do `tree::for_all` método pode lançar uma exceção se ele não requer a função de trabalho a ser chamado em cada elemento da árvore. A exemplo a seguir mostra a `search_for_value` função, que procura um valor fornecido `tree` objeto. O `search_for_value` função usa uma função de trabalho que gera uma exceção quando o elemento atual da árvore corresponde ao valor fornecido. O `search_for_value` função usa um `try-catch` bloco para capturar a exceção e imprimir o resultado no console.

[!code-cpp[concrt-task-tree-search#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_9.cpp)]

Para obter a versão completa deste exemplo, consulte [como: usar tratamento de exceções para interromper um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md).

Para obter mais informações gerais sobre o cancelamento e mecanismos de tratamento de exceções que são fornecidos da PPL, consulte [cancelamento no PPL](cancellation-in-the-ppl.md) e [Exception Handling](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

[[Superior](#top)]

##  <a name="object-destruction"></a> Compreender como cancelamento e tratamento de exceção afetam a destruição de objeto

Em uma árvore de trabalho em paralelo, uma tarefa cancelada impede que tarefas filho em execução. Isso pode causar problemas se uma das tarefas filho executa uma operação que é importante para seu aplicativo, como liberar um recurso. Além disso, o cancelamento da tarefa pode causar uma exceção propagar através de um destruidor de objeto e causar um comportamento indefinido em seu aplicativo.

No exemplo a seguir, o `Resource` classe descreve um recurso e o `Container` classe descreve um contêiner que mantém os recursos. Em seu destruidor, o `Container` chamado pela classe de `cleanup` método em dois dos seus `Resource` membros em paralelo e, em seguida, chama o `cleanup` método em sua terceira `Resource` membro.

[!code-cpp[concrt-parallel-resource-destruction#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_10.h)]

Embora esse padrão não tem problemas por conta própria, considere o seguinte código que executa duas tarefas em paralelo. A primeira tarefa cria uma `Container` objeto e a segunda tarefa cancela a tarefa geral. Para fins ilustrativos, o exemplo usa duas [concurrency::event](../../parallel/concrt/reference/event-class.md) objetos para certificar-se de que o cancelamento ocorrerá após o `Container` objeto é criado e que o `Container` objeto é destruído depois do cancelamento operação ocorre.

[!code-cpp[concrt-parallel-resource-destruction#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_11.cpp)]

Este exemplo gera a seguinte saída:

```Output
Container 1: Freeing resources...Exiting program...
```

Este exemplo de código contém os seguintes problemas que podem fazer com que ele se comportam diferentemente do que o esperado:

- O cancelamento da tarefa pai faz com que a tarefa filho, a chamada para [Concurrency:: parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke), também seja cancelada. Portanto, esses dois recursos não são liberados.

- O cancelamento da tarefa pai faz com que a tarefa filho lançar uma exceção interna. Porque o `Container` destruidor não tratar essa exceção, a exceção é propagada para cima e o terceiro recurso não é liberado.

- A exceção que é gerada pela tarefa filho se propaga por meio de `Container` destruidor. Geração de um destruidor coloca o aplicativo em um estado indefinido.

É recomendável que você não realizar operações críticas, como a liberação de recursos, em tarefas, a menos que você possa garantir que essas tarefas não serão canceladas. Também recomendamos que você não use a funcionalidade de tempo de execução que pode lançar no destruidor de seus tipos.

[[Superior](#top)]

##  <a name="repeated-blocking"></a> Não bloquear repetidamente em um Loop paralelo

Um loop paralelo, como [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) ou [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) que é dominado por bloqueio de operações podem fazer com que o tempo de execução criar muitos threads em um curto período.

O tempo de execução de simultaneidade executa o trabalho adicional quando uma tarefa for concluída ou cooperativamente bloqueia ou produz. Quando um paralelo blocos de iteração de loop, o tempo de execução pode começar a outra iteração. Quando não há nenhum thread ocioso disponível, o tempo de execução cria um novo thread.

Quando o corpo de um paralelo ocasionalmente loop blocos, esse mecanismo ajuda a maximizar a produtividade geral da tarefa. No entanto, quando bloqueiam muitas iterações, o tempo de execução pode criar muitos threads para executar o trabalho adicional. Isso pode levar a condições de pouca memória ou subutilização de recursos de hardware.

Considere o exemplo a seguir que chama o [Concurrency:: Send](reference/concurrency-namespace-functions.md#send) função em cada iteração de um `parallel_for` loop. Porque `send` bloqueia cooperativamente, o tempo de execução cria um novo thread para executar o trabalho adicional sempre `send` é chamado.

[!code-cpp[concrt-repeated-blocking#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_12.cpp)]

É recomendável que você refatora seu código para evitar esse padrão. Neste exemplo, você pode evitar a criação de threads adicionais, chamando `send` em uma série `for` loop.

[[Superior](#top)]

##  <a name="blocking"></a> Não execute operações de bloqueio ao cancelar o trabalho paralelo

Quando possível, não execute operações de bloqueio antes de chamar o [concurrency::task_group::cancel](reference/task-group-class.md#cancel) ou [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) método para cancelar o trabalho paralelo.

Quando uma tarefa executa a operação de bloqueio cooperativo, o tempo de execução pode executar outro trabalho enquanto a primeira tarefa aguarda os dados. O tempo de execução reagendará a tarefa de espera quando ele desbloqueia. Normalmente, o tempo de execução reagenda as tarefas que foram desbloqueadas mais recentemente, antes de ele reagenda as tarefas que foram desbloqueadas menos recentemente. Portanto, o tempo de execução foi possível agendar o trabalho desnecessário durante a operação de bloqueio, o que leva à redução do desempenho. Da mesma forma, quando você executa uma operação de bloqueio antes de cancelar o trabalho paralelo, a operação de bloqueio pode atrasar a chamada para `cancel`. Isso faz com que outras tarefas executar o trabalho desnecessário.

Considere o seguinte exemplo define o `parallel_find_answer` função, que pesquisa um elemento da matriz fornecida que satisfaz a função de predicado fornecida. Quando a função de predicado retorna **verdadeira**, a função de trabalho paralela cria um `Answer` de objeto e cancela a tarefa geral.

[!code-cpp[concrt-blocking-cancel#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_13.cpp)]

O `new` operador executa uma alocação de heap, que pode bloquear. O tempo de execução execute outro trabalho somente quando a tarefa executa a chamada, como uma chamada para o bloqueio cooperativo [concurrency::critical_section::lock](reference/critical-section-class.md#lock).

O exemplo a seguir mostra como evitar que o trabalho desnecessário e, assim, melhorar o desempenho. Este exemplo cancela o grupo de tarefas antes de alocar o armazenamento para o `Answer` objeto.

[!code-cpp[concrt-blocking-cancel#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_14.cpp)]

[[Superior](#top)]

##  <a name="shared-writes"></a> Não gravam dados compartilhados em um Loop paralelo

O tempo de execução de simultaneidade fornece várias estruturas de dados, por exemplo, [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md), sincronizar o acesso simultâneo aos dados compartilhados. Essas estruturas de dados são úteis em muitos casos, por exemplo, quando várias tarefas com pouca frequência exigem acesso compartilhado a um recurso.

Considere o exemplo a seguir que usa o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo e uma `critical_section` objeto para calcular a contagem de números primos em um [std:: array](../../standard-library/array-class-stl.md) objeto. Este exemplo não são dimensionadas porque cada thread deve aguardar para acessar a variável compartilhada `prime_sum`.

[!code-cpp[concrt-parallel-sum-of-primes#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_15.cpp)]

Este exemplo também pode levar a um desempenho ruim, porque a operação de bloqueio frequente efetivamente serializa o loop. Além disso, quando um objeto de tempo de execução de simultaneidade executa uma operação de bloqueio, o Agendador pode criar um thread adicional para realizar outro trabalho enquanto o primeiro thread aguarda os dados. Se o tempo de execução cria muitos threads porque muitas tarefas estão aguardando dados compartilhados, o aplicativo pode ser um desempenho insatisfatório ou entrar em um estado de poucos recursos.

O PPL define o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe, que ajuda a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de maneira sem bloqueio. O `combinable` classe fornece armazenamento local de thread que lhe permite realizar cálculos refinados e, em seguida, mesclar esses cálculos em um resultado final. Você pode pensar uma `combinable` objeto como uma variável de redução.

O exemplo a seguir modifica o exemplo anterior, usando um `combinable` do objeto, em vez de um `critical_section` objeto para calcular a soma. Este exemplo dimensiona porque cada thread mantém sua própria cópia local da soma. Este exemplo usa o [concurrency::combinable::combine](reference/combinable-class.md#combine) método para mesclar os cálculos de locais para o resultado final.

[!code-cpp[concrt-parallel-sum-of-primes#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_16.cpp)]

Para obter a versão completa deste exemplo, consulte [como: usar Combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md). Para obter mais informações sobre o `combinable` classe, consulte [paralela contêineres e objetos](../../parallel/concrt/parallel-containers-and-objects.md).

[[Superior](#top)]

##  <a name="false-sharing"></a> Quando possível, evitar compartilhamento falso

*Falso compartilhamento* ocorre quando várias tarefas simultâneas que são executados em processadores separados gravam em variáveis que estão localizadas na mesma linha de cache. Quando uma tarefa grava uma das variáveis, a linha de cache para as duas variáveis é invalidada. Cada processador necessário recarregar a linha de cache toda vez que a linha de cache é invalidada. Portanto, o falso compartilhamento pode causar redução no desempenho em seu aplicativo.

Exemplo básico mostra duas tarefas a seguir simultâneas que cada incremento uma variável de contador compartilhado.

[!code-cpp[concrt-false-sharing#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_17.cpp)]

Para eliminar o compartilhamento de dados entre as duas tarefas, você pode modificar o exemplo para usar duas variáveis de contador. Esse exemplo calcula o valor do contador final depois de concluir as tarefas. No entanto, este exemplo ilustra o falso compartilhamento porque as variáveis `count1` e `count2` devem estar localizados na mesma linha de cache.

[!code-cpp[concrt-false-sharing#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_18.cpp)]

Uma forma de eliminar o falso compartilhamento é certificar-se de que as variáveis de contador são nas linhas de cache separado. O exemplo a seguir alinha as variáveis `count1` e `count2` em limites de 64 bytes.

[!code-cpp[concrt-false-sharing#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_19.cpp)]

Este exemplo supõe que o tamanho do cache de memória é 64 ou menos bytes.

É recomendável que você use o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe quando você deve compartilhar dados entre tarefas. O `combinable` classe cria variáveis locais de thread de tal forma que o falso compartilhamento é menos provável. Para obter mais informações sobre o `combinable` classe, consulte [paralela contêineres e objetos](../../parallel/concrt/parallel-containers-and-objects.md).

[[Superior](#top)]

##  <a name="lifetime"></a> Certifique-se de que as variáveis são válidas em todo o tempo de vida de uma tarefa

Quando você fornece uma expressão lambda para um grupo de tarefas ou o algoritmo paralelo, a cláusula catch Especifica se o corpo da expressão lambda acessa variáveis no escopo delimitador por valor ou por referência. Ao passar as variáveis para uma expressão lambda por referência, você deve assegurar que o tempo de vida da variável persiste até que a tarefa seja concluída.

Considere o seguinte exemplo define o `object` classe e o `perform_action` função. O `perform_action` função cria um `object` variável e executa alguma ação nessa variável de forma assíncrona. Porque não é garantido que a tarefa seja concluída antes do `perform_action` função retornar, o programa irá falhar ou apresentam comportamento não especificado, se o `object` variável é destruída quando a tarefa está em execução.

[!code-cpp[concrt-lambda-lifetime#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_20.cpp)]

Dependendo dos requisitos do seu aplicativo, você pode usar uma das seguintes técnicas para garantir que as variáveis permaneçam válidas durante a vida útil de cada tarefa.

O exemplo a seguir passa o `object` variável pelo valor para a tarefa. Portanto, a tarefa opera em sua própria cópia da variável.

[!code-cpp[concrt-lambda-lifetime#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_21.cpp)]

Porque o `object` variável é passada por valor, as alterações de estado que ocorrem para essa variável não aparecem na cópia original.

O exemplo a seguir usa o [concurrency::task_group::wait](reference/task-group-class.md#wait) método para certificar-se de que a tarefa seja concluída antes do `perform_action` retornos de função.

[!code-cpp[concrt-lambda-lifetime#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_22.cpp)]

Porque a tarefa agora seja concluída antes da função retorna, o `perform_action` função não se comporta de forma assíncrona.

O exemplo a seguir modifica o `perform_action` função para obter uma referência para o `object` variável. O chamador deve garantir que o tempo de vida do `object` variável é válida até que a tarefa seja concluída.

[!code-cpp[concrt-lambda-lifetime#4](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_23.cpp)]

Você também pode usar um ponteiro para controlar o tempo de vida de um objeto que você passa para um grupo de tarefas ou o algoritmo paralelo.

Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

[[Superior](#top)]

## <a name="see-also"></a>Consulte também

[Práticas recomendadas do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-best-practices.md)<br/>
[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)<br/>
[Como usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)<br/>
[Como usar cancelamento para interromper um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)<br/>
[Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)<br/>
[Práticas recomendadas na biblioteca de agentes assíncronos](../../parallel/concrt/best-practices-in-the-asynchronous-agents-library.md)<br/>
[Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)

