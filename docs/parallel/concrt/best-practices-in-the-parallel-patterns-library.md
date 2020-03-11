---
title: Práticas recomendadas na Biblioteca de Padrões Paralelos
ms.date: 11/04/2016
helpviewer_keywords:
- Parallel Patterns Library, practices to avoid
- practices to avoid, Parallel Patterns Library
- best practices, Parallel Patterns Library
- Parallel Patterns Library, best practices
ms.assetid: e43e0304-4d54-4bd8-a3b3-b8673559a9d7
ms.openlocfilehash: 641d85b03fca13a6592610d87563e3e701ad3e3e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78854106"
---
# <a name="best-practices-in-the-parallel-patterns-library"></a>Práticas recomendadas na Biblioteca de Padrões Paralelos

Este documento descreve a melhor maneira de fazer uso efetivo da PPL (biblioteca de padrões paralelos). A PPL fornece contêineres, objetos e algoritmos de uso geral para a execução de paralelismo refinado.

Para obter mais informações sobre a PPL, consulte [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).

## <a name="top"></a>As

Este documento contém as seguintes seções:

- [Não paralelizar corpos pequenos de loop](#small-loops)

- [Paralelismo expresso no nível mais alto possível](#highest)

- [Usar parallel_invoke para resolver problemas de divisão e conquista](#divide-and-conquer)

- [Usar o cancelamento ou tratamento de exceção para interromper de um loop paralelo](#breaking-loops)

- [Entenda como o cancelamento e o tratamento de exceções afetam a destruição de objetos](#object-destruction)

- [Não bloquear repetidamente em um loop paralelo](#repeated-blocking)

- [Não executar operações de bloqueio ao cancelar o trabalho paralelo](#blocking)

- [Não gravar em dados compartilhados em um loop paralelo](#shared-writes)

- [Quando possível, evite o falso compartilhamento](#false-sharing)

- [Verifique se as variáveis são válidas durante todo o tempo de vida de uma tarefa](#lifetime)

## <a name="small-loops"></a>Não paralelizar corpos pequenos de loop

A paralelização de corpos de loop relativamente pequenos pode fazer com que a sobrecarga de agendamento associada supere os benefícios do processamento paralelo. Considere o exemplo a seguir, que adiciona cada par de elementos em duas matrizes.

[!code-cpp[concrt-small-loops#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_1.cpp)]

A carga de trabalho para cada iteração de loop paralelo é muito pequena para se beneficiar da sobrecarga do processamento paralelo. Você pode melhorar o desempenho desse loop executando mais trabalho no corpo do loop ou executando o loop em série.

[[Superior](#top)]

## <a name="highest"></a>Paralelismo expresso no nível mais alto possível

Quando você paraleliza o código somente no nível inferior, pode introduzir uma construção de bifurcação que não é dimensionada conforme o número de processadores aumenta. Uma construção de *bifurcação de junção* é um constructo em que uma tarefa divide seu trabalho em subtarefas paralelas menores e aguarda que essas subtarefas sejam concluídas. Cada subtarefa pode se dividir recursivamente em subtarefas adicionais.

Embora o modelo de junção de bifurcação possa ser útil para resolver uma variedade de problemas, há situações em que a sobrecarga de sincronização pode diminuir a escalabilidade. Por exemplo, considere o código de série a seguir que processa dados de imagem.

[!code-cpp[concrt-image-processing-filter#20](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_2.cpp)]

Como cada iteração de loop é independente, você pode paralelizar grande parte do trabalho, conforme mostrado no exemplo a seguir. Este exemplo usa o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) para paralelizar o loop externo.

[!code-cpp[concrt-image-processing-filter#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_3.cpp)]

O exemplo a seguir ilustra uma construção de bifurcação de junção chamando a função `ProcessImage` em um loop. Cada chamada para `ProcessImage` não retorna até que cada subtarefa seja concluída.

[!code-cpp[concrt-image-processing-filter#21](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_4.cpp)]

Se cada iteração do loop paralelo não executar quase nenhum trabalho ou se o trabalho executado pelo loop paralelo for desequilibrado, ou seja, algumas iterações de loop demorarão mais do que outras, a sobrecarga de agendamento necessária para bifurcar e ingressar no trabalho pode Supere o benefício para a execução paralela. Essa sobrecarga aumenta à medida que o número de processadores aumenta.

Para reduzir a quantidade de sobrecarga de agendamento neste exemplo, você pode paralelizar loops externos antes de paralelizar loops internos ou usar outra construção paralela, como o pipeline. O exemplo a seguir modifica a função `ProcessImages` para usar o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) para paralelizar o loop externo.

[!code-cpp[concrt-image-processing-filter#22](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_5.cpp)]

Para obter um exemplo semelhante que usa um pipeline para executar o processamento de imagens em paralelo, consulte [passo a passos: criando uma rede de processamento de imagens](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

[[Superior](#top)]

## <a name="divide-and-conquer"></a>Usar parallel_invoke para resolver problemas de divisão e conquista

Um problema de *dividir e conquistar* é uma forma da construção de bifurcação que usa a recursão para dividir uma tarefa em subtarefas. Além das classes [Concurrency:: task_group](reference/task-group-class.md) e [concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) , você também pode usar o algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) para resolver problemas de divisão e conquista. O algoritmo `parallel_invoke` tem uma sintaxe mais sucinta que os objetos do grupo de tarefas e é útil quando você tem um número fixo de tarefas paralelas.

O exemplo a seguir ilustra o uso do algoritmo `parallel_invoke` para implementar o algoritmo de classificação bitônico.

[!code-cpp[concrt-parallel-bitonic-sort#12](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_6.cpp)]

Para reduzir a sobrecarga, o algoritmo de `parallel_invoke` executa o último da série de tarefas no contexto de chamada.

Para obter a versão completa deste exemplo, consulte [como: usar parallel_invoke para gravar uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md). Para obter mais informações sobre o algoritmo `parallel_invoke`, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

[[Superior](#top)]

## <a name="breaking-loops"></a>Usar o cancelamento ou tratamento de exceção para interromper de um loop paralelo

A PPL fornece duas maneiras de cancelar o trabalho paralelo que é executado por um grupo de tarefas ou um algoritmo paralelo. Uma maneira é usar o mecanismo de cancelamento que é fornecido pelas classes [Concurrency:: task_group](reference/task-group-class.md) e [concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) . A outra maneira é lançar uma exceção no corpo de uma função de trabalho de tarefa. O mecanismo de cancelamento é mais eficiente do que a manipulação de exceções no cancelamento de uma árvore de trabalho paralelo. Uma *árvore de trabalho paralela* é um grupo de grupos de tarefas relacionados em que alguns grupos de tarefas contêm outros grupos de tarefas. O mecanismo de cancelamento cancela um grupo de tarefas e seus grupos de tarefas filho de maneira superior. Por outro lado, a manipulação de exceção funciona de maneira inferior e deve cancelar cada grupo de tarefas filho de forma independente, pois a exceção se propaga para cima.

Quando você trabalha diretamente com um objeto de grupo de tarefas, use os métodos [Concurrency:: task_group:: Cancel](reference/task-group-class.md#cancel) ou [concurrency:: structured_task_group:: Cancel](reference/structured-task-group-class.md#cancel) para cancelar o trabalho que pertence a esse grupo de tarefas. Para cancelar um algoritmo paralelo, por exemplo, `parallel_for`, crie um grupo de tarefas pai e cancele esse grupo de tarefas. Por exemplo, considere a seguinte função, `parallel_find_any`, que procura um valor em uma matriz em paralelo.

[!code-cpp[concrt-parallel-array-search#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_7.cpp)]

Como os algoritmos paralelos usam grupos de tarefas, quando uma das iterações paralelas cancela o grupo de tarefas pai, a tarefa geral é cancelada. Para obter a versão completa deste exemplo, consulte [como: usar o cancelamento para interromper de um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md).

Embora a manipulação de exceções seja uma maneira menos eficiente de cancelar o trabalho paralelo do que o mecanismo de cancelamento, há casos em que o tratamento de exceções é apropriado. Por exemplo, o método a seguir, `for_all`, executa recursivamente uma função de trabalho em cada nó de uma estrutura de `tree`. Neste exemplo, o membro de dados de `_children` é uma [lista std::](../../standard-library/list-class.md) que contém `tree` objetos.

[!code-cpp[concrt-task-tree-search#6](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_8.cpp)]

O chamador do método `tree::for_all` poderá gerar uma exceção se não exigir que a função de trabalho seja chamada em cada elemento da árvore. O exemplo a seguir mostra a função `search_for_value`, que procura um valor no objeto `tree` fornecido. A função `search_for_value` usa uma função de trabalho que gera uma exceção quando o elemento atual da árvore corresponde ao valor fornecido. A função `search_for_value` usa um bloco de `try-catch` para capturar a exceção e imprimir o resultado no console.

[!code-cpp[concrt-task-tree-search#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_9.cpp)]

Para a versão completa deste exemplo, consulte [como usar a manipulação de exceção para interromper a partir de um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md).

Para obter mais informações gerais sobre os mecanismos de cancelamento e tratamento de exceção que são fornecidos pela PPL, consulte [cancelamento na ppl e no](cancellation-in-the-ppl.md) [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

[[Superior](#top)]

## <a name="object-destruction"></a>Entenda como o cancelamento e o tratamento de exceções afetam a destruição de objetos

Em uma árvore de trabalho paralelo, uma tarefa cancelada impede a execução de tarefas filho. Isso pode causar problemas se uma das tarefas filho executar uma operação que é importante para seu aplicativo, como liberar um recurso. Além disso, o cancelamento de tarefas pode fazer com que uma exceção seja propagada por meio de um destruidor de objeto e cause um comportamento indefinido em seu aplicativo.

No exemplo a seguir, a classe `Resource` descreve um recurso e a classe `Container` descreve um contêiner que contém recursos. Em seu destruidor, a classe `Container` chama o método `cleanup` em dois de seus membros `Resource` em paralelo e, em seguida, chama o método `cleanup` em seu terceiro membro `Resource`.

[!code-cpp[concrt-parallel-resource-destruction#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_10.h)]

Embora esse padrão não tenha nenhum problema, considere o código a seguir que executa duas tarefas em paralelo. A primeira tarefa cria um objeto `Container` e a segunda tarefa cancela a tarefa geral. Para ilustração, o exemplo usa dois objetos [Concurrency:: Event](../../parallel/concrt/reference/event-class.md) para garantir que o cancelamento ocorra após a criação do objeto de `Container` e que o objeto `Container` seja destruído depois que a operação de cancelamento ocorrer.

[!code-cpp[concrt-parallel-resource-destruction#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_11.cpp)]

Esse exemplo gera a saída a seguir:

```Output
Container 1: Freeing resources...Exiting program...
```

Este exemplo de código contém os seguintes problemas que podem fazer com que ele se comporte de forma diferente do esperado:

- O cancelamento da tarefa pai faz com que a tarefa filho, a chamada para [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke), também seja cancelada. Portanto, esses dois recursos não são liberados.

- O cancelamento da tarefa pai faz com que a tarefa filho gere uma exceção interna. Como o destruidor `Container` não trata essa exceção, a exceção é propagada para cima e o terceiro recurso não é liberado.

- A exceção gerada pela tarefa filho é propagada por meio do destruidor `Container`. O lançamento de um destruidor coloca o aplicativo em um estado indefinido.

Recomendamos que você não execute operações críticas, como a liberação de recursos, em tarefas, a menos que você possa garantir que essas tarefas não serão canceladas. Também recomendamos que você não use a funcionalidade de tempo de execução que possa gerar o destruidor de seus tipos.

[[Superior](#top)]

## <a name="repeated-blocking"></a>Não bloquear repetidamente em um loop paralelo

Um loop paralelo como [simultaneidade::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) ou [concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) que é dominado por operações de bloqueio pode fazer com que o tempo de execução crie vários threads em um curto período de tempo.

O Tempo de Execução de Simultaneidade executa trabalho adicional quando uma tarefa é concluída ou é bloqueada ou produzida cooperante. Quando uma iteração de loop paralelo é bloqueada, o tempo de execução pode iniciar outra iteração. Quando não há threads ociosos disponíveis, o tempo de execução cria um novo thread.

Quando o corpo de um loop paralelo é eventualmente bloqueado, esse mecanismo ajuda a maximizar a taxa de transferência geral da tarefa. No entanto, quando muitas iterações são bloqueadas, o tempo de execução pode criar vários threads para executar o trabalho adicional. Isso pode levar a condições de pouca memória ou má utilização de recursos de hardware.

Considere o seguinte exemplo que chama a função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) em cada iteração de um loop de `parallel_for`. Como o `send` bloqueia de cooperativa, o tempo de execução cria um novo thread para executar trabalho adicional sempre que `send` é chamado.

[!code-cpp[concrt-repeated-blocking#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_12.cpp)]

Recomendamos que você refatore seu código para evitar esse padrão. Neste exemplo, você pode evitar a criação de threads adicionais chamando `send` em um loop de `for` serial.

[[Superior](#top)]

## <a name="blocking"></a>Não executar operações de bloqueio ao cancelar o trabalho paralelo

Quando possível, não execute operações de bloqueio antes de chamar o método [Concurrency:: task_group:: Cancel](reference/task-group-class.md#cancel) ou [concurrency:: structured_task_group:: Cancel](reference/structured-task-group-class.md#cancel) para cancelar o trabalho paralelo.

Quando uma tarefa executa uma operação de bloqueio cooperativo, o tempo de execução pode executar outro trabalho enquanto a primeira tarefa aguarda dados. O tempo de execução reagenda a tarefa em espera quando ela é desbloqueada. O tempo de execução normalmente reagenda tarefas que foram desbloqueadas mais recentemente antes de reagendar tarefas que foram desbloqueadas menos recentemente. Portanto, o tempo de execução pode agendar trabalho desnecessário durante a operação de bloqueio, o que leva a um desempenho reduzido. Da mesma forma, quando você executa uma operação de bloqueio antes de cancelar o trabalho paralelo, a operação de bloqueio pode atrasar a chamada para `cancel`. Isso faz com que outras tarefas executem trabalhos desnecessários.

Considere o exemplo a seguir que define a função `parallel_find_answer`, que procura um elemento da matriz fornecida que satisfaça a função de predicado fornecida. Quando a função de predicado retorna **true**, a função de trabalho paralela cria um objeto `Answer` e cancela a tarefa geral.

[!code-cpp[concrt-blocking-cancel#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_13.cpp)]

O operador de `new` executa uma alocação de heap, que pode bloquear. O tempo de execução executa outro trabalho somente quando a tarefa executa uma chamada de bloqueio cooperativo, como uma chamada para [Concurrency:: critical_section:: Lock](reference/critical-section-class.md#lock).

O exemplo a seguir mostra como impedir o trabalho desnecessário e, assim, melhorar o desempenho. Este exemplo cancela o grupo de tarefas antes de alocar o armazenamento para o objeto `Answer`.

[!code-cpp[concrt-blocking-cancel#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_14.cpp)]

[[Superior](#top)]

## <a name="shared-writes"></a>Não gravar em dados compartilhados em um loop paralelo

O Tempo de Execução de Simultaneidade fornece várias estruturas de dados, por exemplo, [Concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md), que sincronizam o acesso simultâneo a dados compartilhados. Essas estruturas de dados são úteis em muitos casos, por exemplo, quando várias tarefas raramente exigem acesso compartilhado a um recurso.

Considere o exemplo a seguir que usa o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) e um objeto `critical_section` para calcular a contagem de números primos em um objeto [std:: array](../../standard-library/array-class-stl.md) . Este exemplo não é dimensionado porque cada thread deve aguardar para acessar a variável compartilhada `prime_sum`.

[!code-cpp[concrt-parallel-sum-of-primes#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_15.cpp)]

Este exemplo também pode levar a um desempenho insatisfatório porque a operação de bloqueio frequente serializa efetivamente o loop. Além disso, quando um objeto de Tempo de Execução de Simultaneidade executa uma operação de bloqueio, o Agendador pode criar um thread adicional para executar outro trabalho enquanto o primeiro segmento aguarda dados. Se o tempo de execução criar muitos threads porque muitas tarefas estão aguardando dados compartilhados, o aplicativo poderá funcionar insatisfatoriamente ou entrar em um estado de baixo recurso.

A PPL define a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) , que ajuda você a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de maneira sem bloqueio. A classe `combinable` fornece armazenamento local de thread que permite executar computações refinadas e, em seguida, mesclar esses cálculos em um resultado final. Você pode considerar um objeto `combinable` como uma variável de redução.

O exemplo a seguir modifica o anterior usando um objeto `combinable` em vez de um objeto `critical_section` para computar a soma. Este exemplo é dimensionado porque cada thread mantém sua própria cópia local da soma. Este exemplo usa o método [Concurrency:: combinável:: Combine](reference/combinable-class.md#combine) para mesclar os cálculos locais com o resultado final.

[!code-cpp[concrt-parallel-sum-of-primes#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_16.cpp)]

Para obter a versão completa deste exemplo, consulte [como: usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md). Para obter mais informações sobre a classe `combinable`, consulte [contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md).

[[Superior](#top)]

## <a name="false-sharing"></a>Quando possível, evite o falso compartilhamento

O *falso compartilhamento* ocorre quando várias tarefas simultâneas que estão sendo executadas em processadores separados gravam em variáveis que estão localizadas na mesma linha de cache. Quando uma tarefa grava em uma das variáveis, a linha de cache para ambas as variáveis é invalidada. Cada processador deve recarregar a linha de cache toda vez que a linha de cache é invalidada. Portanto, o falso compartilhamento pode causar desempenho reduzido em seu aplicativo.

O exemplo básico a seguir mostra duas tarefas simultâneas que incrementam uma variável de contador compartilhado.

[!code-cpp[concrt-false-sharing#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_17.cpp)]

Para eliminar o compartilhamento de dados entre as duas tarefas, você pode modificar o exemplo para usar duas variáveis de contador. Este exemplo computa o valor final do contador depois que as tarefas são concluídas. No entanto, este exemplo ilustra o falso compartilhamento porque as variáveis `count1` e `count2` provavelmente estarão localizadas na mesma linha de cache.

[!code-cpp[concrt-false-sharing#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_18.cpp)]

Uma maneira de eliminar o falso compartilhamento é certificar-se de que as variáveis do contador estejam em linhas de cache separadas. O exemplo a seguir alinha as variáveis `count1` e `count2` nos limites de 64 bytes.

[!code-cpp[concrt-false-sharing#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_19.cpp)]

Este exemplo pressupõe que o tamanho do cache de memória seja 64 ou menos bytes.

É recomendável que você use a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) quando você deve compartilhar dados entre tarefas. A classe `combinable` cria variáveis de thread local de forma que o falso compartilhamento seja menos provável. Para obter mais informações sobre a classe `combinable`, consulte [contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md).

[[Superior](#top)]

## <a name="lifetime"></a>Verifique se as variáveis são válidas durante todo o tempo de vida de uma tarefa

Quando você fornece uma expressão lambda a um grupo de tarefas ou a um algoritmo paralelo, a cláusula Capture especifica se o corpo da expressão lambda acessa variáveis no escopo delimitador por valor ou por referência. Ao passar variáveis para uma expressão lambda por referência, você deve garantir que o tempo de vida dessa variável persista até que a tarefa seja concluída.

Considere o exemplo a seguir que define a classe `object` e a função `perform_action`. A função `perform_action` cria uma variável `object` e executa alguma ação nessa variável de forma assíncrona. Como a tarefa não é garantida para ser concluída antes de a função `perform_action` retornar, o programa falhará ou apresentará comportamento não especificado se a variável `object` for destruída quando a tarefa estiver em execução.

[!code-cpp[concrt-lambda-lifetime#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_20.cpp)]

Dependendo dos requisitos do seu aplicativo, você pode usar uma das técnicas a seguir para garantir que as variáveis permaneçam válidas durante todo o tempo de vida de cada tarefa.

O exemplo a seguir passa a `object` variável por valor para a tarefa. Portanto, a tarefa opera em sua própria cópia da variável.

[!code-cpp[concrt-lambda-lifetime#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_21.cpp)]

Como a variável `object` é passada por valor, quaisquer alterações de estado que ocorram nessa variável não aparecerão na cópia original.

O exemplo a seguir usa o método [Concurrency:: task_group:: Wait](reference/task-group-class.md#wait) para garantir que a tarefa seja concluída antes que a função `perform_action` retorne.

[!code-cpp[concrt-lambda-lifetime#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_22.cpp)]

Como a tarefa agora é concluída antes de a função retornar, a função `perform_action` não se comporta de forma assíncrona.

O exemplo a seguir modifica a função `perform_action` para obter uma referência à variável `object`. O chamador deve garantir que o tempo de vida da variável de `object` seja válido até que a tarefa seja concluída.

[!code-cpp[concrt-lambda-lifetime#4](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_23.cpp)]

Você também pode usar um ponteiro para controlar o tempo de vida de um objeto passado para um grupo de tarefas ou um algoritmo paralelo.

Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

[[Superior](#top)]

## <a name="see-also"></a>Confira também

[Práticas recomendadas do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-best-practices.md)<br/>
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
[Práticas recomendadas gerais no runtime de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)
