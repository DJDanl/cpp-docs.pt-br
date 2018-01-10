---
title: "Práticas recomendadas na biblioteca padrões paralelos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Parallel Patterns Library, practices to avoid
- practices to avoid, Parallel Patterns Library
- best practices, Parallel Patterns Library
- Parallel Patterns Library, best practices
ms.assetid: e43e0304-4d54-4bd8-a3b3-b8673559a9d7
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 40629b25ebcc954ac19389fbc0abb3aef6e9374a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="best-practices-in-the-parallel-patterns-library"></a>Práticas recomendadas na Biblioteca de Padrões Paralelos
Este documento descreve a melhor maneira para fazer uso eficiente de biblioteca de padrões paralelos (PPL). PPL fornece algoritmos, objetos e contêineres para fins gerais para executar o paralelismo refinado.  
  
 Para obter mais informações sobre a PPL, consulte [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).  
  
##  <a name="top"></a>Seções  
 Este documento contém as seguintes seções:  
  
- [Não paralelizar corpos de Loop pequenos](#small-loops)  
  
- [Express paralelismo no nível mais alto possível](#highest)  
  
- [Usar parallel_invoke para solucionar problemas de divisão e superar](#divide-and-conquer)  
  
- [Use o cancelamento ou tratamento de exceções para quebra de um loop paralelo](#breaking-loops)  
  
- [Entender como o cancelamento e manipulação de exceção afetam destruição de objeto](#object-destruction)  
  
- [Não bloqueiam repetidamente em um Loop paralelo](#repeated-blocking)  
  
- [Não execute operações de bloqueio quando você cancela o trabalho paralelos](#blocking)  
  
- [Não gravam dados compartilhados em um Loop paralelo](#shared-writes)  
  
- [Quando possível, evite falso compartilhamento](#false-sharing)  
  
- [Certifique-se de que as variáveis são válidas em todo o tempo de vida de uma tarefa](#lifetime)  
  
##  <a name="small-loops"></a>Não paralelizar corpos de Loop pequenos  
 A paralelização de corpos de loop relativamente pequeno pode causar associado agendamento de sobrecarga para superar os benefícios de processamento paralelo. Considere o exemplo a seguir, que adiciona cada par de elementos em duas matrizes.  
  
 [!code-cpp[concrt-small-loops#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_1.cpp)]  
  
 A carga de trabalho para cada iteração do loop paralelo é muito pequena para se beneficiar com a sobrecarga de processamento paralelo. Você pode melhorar o desempenho desse loop executando mais trabalho no corpo do loop ou executando o loop em série.  
  
 [[Superior](#top)]  
  
##  <a name="highest"></a>Express paralelismo no nível mais alto possível  
 Quando você paralelizar código somente no nível inferior, você pode introduzir uma construção bifurcada que não podem ser expandidos conforme o número de processadores. Um *bifurcada* construção é uma construção em que uma tarefa divide seu trabalho em menores subtarefas paralelas e aguarda até que essas subtarefas concluir. Cada subtarefa pode dividir recursivamente em si em subtarefas adicionais.  
  
 Embora o modelo de associação de bifurcação pode ser útil para solucionar vários problemas, há situações em que a sobrecarga de sincronização pode diminuir a escalabilidade. Por exemplo, considere o seguinte código serial que processa os dados de imagem.  
  
 [!code-cpp[concrt-image-processing-filter#20](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_2.cpp)]  
  
 Como cada iteração do loop é independente, paralelizar muito do trabalho, conforme mostrado no exemplo a seguir. Este exemplo usa o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo em paralelo o loop externo.  

  
 [!code-cpp[concrt-image-processing-filter#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_3.cpp)]  
  
 O exemplo a seguir ilustra uma construção bifurcada chamando o `ProcessImage` função em um loop. Cada chamada para `ProcessImage` não retorna até que cada subtarefa seja concluído.  
  
 [!code-cpp[concrt-image-processing-filter#21](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_4.cpp)]  
  
 Se cada iteração do loop paralelo a executa quase nenhum trabalho ou o trabalho realizado pelo loop paralelo é desequilibrada, ou seja, alguns iterações do loop demorar mais do que outras pessoas, o agendamento de sobrecarga que é necessário para bifurcação com frequência e trabalho de junção pode superam os benefícios para execução paralela. Essa sobrecarga aumenta conforme o número de processadores.  
  
 Para reduzir a quantidade de agendamento de sobrecarga neste exemplo, você pode paralelizar loops externas antes de paralelizar loops internas ou usar outra construção paralela como pipeline. O exemplo a seguir modifica o `ProcessImages` função deve usar o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo em paralelo o loop externo.  

  
 [!code-cpp[concrt-image-processing-filter#22](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_5.cpp)]  
  
 Para obter um exemplo semelhante que usa um pipeline para executar o processamento de imagens em paralelo, consulte [passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).  
  
 [[Superior](#top)]  
  
##  <a name="divide-and-conquer"></a>Usar parallel_invoke para solucionar problemas de divisão e superar  

 Um *divisão e superar* problema é uma forma da construção de bifurcação-junção que usa a recursão para dividir uma tarefa em subtarefas. Além de [concurrency::task_group](reference/task-group-class.md) e [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes, você também pode usar o [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo Solucione problemas de divisão e superar. O `parallel_invoke` algoritmo possui uma sintaxe mais sucinta que objetos de grupo de tarefas e é útil quando você tem um número fixo de tarefas paralelas.  
  
 O exemplo a seguir ilustra o uso do `parallel_invoke` algoritmo para implementar o bitonic algoritmo de classificação.  
  
 [!code-cpp[concrt-parallel-bitonic-sort#12](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_6.cpp)]  
  
 Para reduzir a sobrecarga de `parallel_invoke` algoritmo executa o último da série de tarefas no contexto do chamador.  
  
 Para obter a versão completa deste exemplo, consulte [como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md). Para obter mais informações sobre o `parallel_invoke` algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
 [[Superior](#top)]  
  
##  <a name="breaking-loops"></a>Use o cancelamento ou tratamento de exceções para quebra de um loop paralelo  
 PPL fornece duas maneiras de cancelar o trabalho paralelo que é executado por um grupo de tarefas ou o algoritmo paralelo. Uma maneira é usar o mecanismo de cancelamento é fornecido pelo [concurrency::task_group](reference/task-group-class.md) e [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes. A outra maneira é lançar uma exceção no corpo de uma função de trabalho da tarefa. O mecanismo de cancelamento é mais eficiente do que no cancelamento de uma árvore de trabalho paralela de tratamento de exceção. Um *trabalho paralelo árvore* é um grupo de grupos de tarefas relacionadas no qual alguns grupos de tarefas contenham outros grupos de tarefas. O mecanismo de cancelamento cancela um grupo de tarefas e seus grupos de tarefas filho de uma maneira de cima para baixo. Por outro lado, a manipulação de exceção funciona de forma ascendente e deve cancelar a cada grupo de tarefas filho independentemente como a exceção for propagada para cima.  
  

 Quando você trabalha diretamente com um objeto de grupo de tarefas, use o [concurrency::task_group::cancel](reference/task-group-class.md#cancel) ou [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) métodos para cancelar o trabalho que pertence a esse grupo de tarefas . Para cancelar um algoritmo paralelo, por exemplo, `parallel_for`, crie um grupo de tarefas pai e cancelar a esse grupo de tarefas. Por exemplo, considere a seguinte função, `parallel_find_any`, que procura um valor em uma matriz em paralelo.  


  
 [!code-cpp[concrt-parallel-array-search#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_7.cpp)]  
  
 Como os algoritmos paralelos usam grupos de tarefas quando uma das iterações paralelas cancela o grupo pai de tarefas, a tarefa foi cancelada. Para obter a versão completa deste exemplo, consulte [como: cancelamento de uso para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md).  
  
 Embora o tratamento de exceção é uma maneira menos eficiente para cancelar o trabalho paralelo que o mecanismo de cancelamento, há casos em que o tratamento de exceção é apropriado. Por exemplo, o seguinte método `for_all`, recursivamente executa uma função de trabalho em cada nó de um `tree` estrutura. Neste exemplo, o `_children` membro de dados é um [std:: List](../../standard-library/list-class.md) que contém `tree` objetos.  
  
 [!code-cpp[concrt-task-tree-search#6](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_8.cpp)]  
  
 O chamador de `tree::for_all` método pode lançar uma exceção se ele não requer que a função de trabalho a ser chamado em cada elemento da árvore. A exemplo a seguir mostra o `search_for_value` função, que procura um valor em fornecidos `tree` objeto. O `search_for_value` função usa uma função de trabalho que gera uma exceção quando o elemento atual da árvore corresponde ao valor fornecido. O `search_for_value` função usa um `try-catch` bloco para capturar a exceção e imprimir o resultado para o console.  
  
 [!code-cpp[concrt-task-tree-search#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_9.cpp)]  
  
 Para obter a versão completa deste exemplo, consulte [como: usar tratamento de exceção para parar um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md).  
  
 Para obter mais informações sobre o cancelamento e mecanismos de tratamento de exceções que são fornecidos pelo PPL, consulte [cancelamento no PPL](cancellation-in-the-ppl.md) e [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
 [[Superior](#top)]  
  
##  <a name="object-destruction"></a>Entender como o cancelamento e manipulação de exceção afetam destruição de objeto  
 Em uma árvore de trabalho paralela, uma tarefa que é cancelada impede tarefas filho em execução. Isso pode causar problemas se uma das tarefas filho executa uma operação que é importante para seu aplicativo, como a liberação de um recurso. Além disso, o cancelamento da tarefa pode causar uma exceção ao propagar através de um destruidor de objeto e causar um comportamento indefinido em seu aplicativo.  
  
 No exemplo a seguir, o `Resource` classe descreve um recurso e o `Container` classe descreve um contêiner que mantém os recursos. Em seu destruidor, o `Container` classe chamadas a `cleanup` método em dois dos seus `Resource` membros em paralelo e, em seguida, chama o `cleanup` método em sua terceira `Resource` membro.  
  
 [!code-cpp[concrt-parallel-resource-destruction#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_10.h)]  
  
 Embora esse padrão não tenha nenhum problema por conta própria, considere o seguinte código que executa duas tarefas em paralelo. A primeira tarefa cria uma `Container` objeto e a segunda tarefa cancela a tarefa. Para fins ilustrativos, o exemplo usa dois [concurrency::event](../../parallel/concrt/reference/event-class.md) objetos para certificar-se de que o cancelamento ocorrerá após o `Container` objeto é criado e que o `Container` objeto é destruído depois do cancelamento operação ocorre.  
  
 [!code-cpp[concrt-parallel-resource-destruction#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_11.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
Container 1: Freeing resources...Exiting program...  
```  
  
 Este exemplo de código contém os seguintes problemas que podem fazer com que ele se comportam de forma diferente do que o esperado:  
  
-   O cancelamento da tarefa pai faz com que a tarefa filho, a chamada para [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke), também ser cancelada. Portanto, esses dois recursos não são liberados.  

  
-   O cancelamento da tarefa pai faz com que a tarefa filho lançar uma exceção interna. Porque o `Container` destruidor não tratar essa exceção, a exceção é propagada para cima e o terceiro recurso não é liberado.  
  
-   A exceção que é gerada pela tarefa filho se propaga por meio de `Container` destruidor. Emitindo de um destruidor coloca o aplicativo em um estado indefinido.  
  
 É recomendável que você não realizar operações importantes, como a liberação de recursos, em tarefas, a menos que você possa garantir que essas tarefas não serão canceladas. Também recomendamos que você não use a funcionalidade de tempo de execução que pode gerar no destruidor de seus tipos.  
  
 [[Superior](#top)]  
  
##  <a name="repeated-blocking"></a>Não bloqueiam repetidamente em um Loop paralelo  

 Um loop paralelo como [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) ou [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) que é influenciado pelo bloqueio de operações podem fazer com que o tempo de execução criar vários threads durante um curto período de tempo.  

  
 O tempo de execução de simultaneidade executa trabalho adicional quando uma tarefa for concluída ou blocos de forma cooperativa ou gera. Quando um paralelo blocos de iteração de loop, o tempo de execução pode começar outra iteração. Quando não há nenhum thread ocioso disponível, o tempo de execução cria um novo thread.  
  
 Quando o corpo de um paralelo ocasionalmente loop blocos, esse mecanismo ajuda a maximizar a produtividade geral de tarefa. No entanto, ao bloqueiam a muitas iterações, o tempo de execução pode criar muitos threads para executar o trabalho adicional. Isso pode levar a subutilização de recursos de hardware ou condições de memória insuficiente.  
  
 Considere o exemplo a seguir que chama o [concurrency::send](reference/concurrency-namespace-functions.md#send) função em cada iteração de um `parallel_for` loop. Porque `send` blocos de forma cooperativa, o tempo de execução cria um novo thread para executar o trabalho adicional sempre `send` é chamado.  
  
 [!code-cpp[concrt-repeated-blocking#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_12.cpp)]  
  
 É recomendável que você refatorar o código para evitar esse padrão. Neste exemplo, você pode evitar a criação de threads adicionais chamando `send` em uma série `for` loop.  
  
 [[Superior](#top)]  
  
##  <a name="blocking"></a>Não execute operações de bloqueio quando você cancela o trabalho paralelos  

 Quando possível, não execute operações de bloqueio antes de chamar o [concurrency::task_group::cancel](reference/task-group-class.md#cancel) ou [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) método para cancelar o trabalho paralelo.  


  
 Quando uma tarefa executa um cooperativo bloqueando a operação, o tempo de execução pode executar outras tarefas enquanto a primeira tarefa aguarda os dados. O tempo de execução reagenda a tarefa de espera quando ele desbloqueia. Normalmente, o tempo de execução reagenda tarefas que foram desbloqueadas mais recentemente antes de ele reagenda tarefas que foram desbloqueadas menos recentemente. Portanto, o tempo de execução foi possível agendar o trabalho desnecessário durante a operação de bloqueio, o que leva à redução do desempenho. Da mesma forma, quando você executa uma operação de bloqueio antes de cancelar o trabalho paralelo, a operação de bloqueio pode atrasar a chamada para `cancel`. Isso faz com que outras tarefas Executar trabalho desnecessário.  
  
 Considere o seguinte exemplo define o `parallel_find_answer` função, que procura por um elemento da matriz fornecida que satisfaz a função de predicado fornecida. Quando a função de predicado retorna `true`, a função de trabalho paralela cria um `Answer` de objeto e cancela a tarefa.  
  
 [!code-cpp[concrt-blocking-cancel#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_13.cpp)]  
  


 O `new` operador executa uma alocação de heap pode bloquear. O tempo de execução executa outro trabalho somente quando a tarefa executa um cooperativo bloqueio de chamada, como uma chamada para [concurrency::critical_section::lock](reference/critical-section-class.md#lock).  


  
 O exemplo a seguir mostra como impedir que o trabalho desnecessário e, assim, melhorar o desempenho. Este exemplo cancela o grupo de tarefas antes de alocar armazenamento para o `Answer` objeto.  
  
 [!code-cpp[concrt-blocking-cancel#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_14.cpp)]  
  
 [[Superior](#top)]  
  
##  <a name="shared-writes"></a>Não gravam dados compartilhados em um Loop paralelo  
 O tempo de execução de simultaneidade fornece várias estruturas de dados, por exemplo, [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md), que sincronizar o acesso simultâneo aos dados compartilhados. Essas estruturas de dados são úteis em muitos casos, por exemplo, quando várias tarefas raramente necessitam de acesso compartilhado a um recurso.  
  
 Considere o seguinte exemplo usa o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo e uma `critical_section` objeto para calcular a contagem de números primos em uma [std:: array](../../standard-library/array-class-stl.md) objeto. Este exemplo não é escalado porque cada thread deve esperar para acessar a variável compartilhada `prime_sum`.  

  
 [!code-cpp[concrt-parallel-sum-of-primes#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_15.cpp)]  
  
 Este exemplo também pode resultar em desempenho baixo porque a operação de bloqueio frequente efetivamente serializa o loop. Além disso, quando um objeto de tempo de execução de simultaneidade executa uma operação de bloqueio, o Agendador pode criar um thread adicional para realizar outro trabalho enquanto o primeiro thread aguarda os dados. Se o tempo de execução cria muitos threads porque muitas tarefas estão aguardando dados compartilhados, o aplicativo pode insatisfatório ou entrar em um estado de poucos recursos.  
  
 PPL define o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe, que ajuda a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de forma livre de bloqueios. O `combinable` classe fornece armazenamento local de thread que permite executar computações refinadas e, em seguida, mesclar os cálculos em um resultado final. Você pode pensar uma `combinable` objeto como uma variável de redução.  
  
 O exemplo a seguir modifica um anterior usando um `combinable` do objeto, em vez de um `critical_section` objeto para calcular a soma. Este exemplo dimensiona porque cada thread mantém sua própria cópia local da soma. Este exemplo usa o [concurrency::combinable::combine](reference/combinable-class.md#combine) método para mesclar os cálculos de locais para o resultado final.  

  
 [!code-cpp[concrt-parallel-sum-of-primes#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_16.cpp)]  
  
 Para obter a versão completa deste exemplo, consulte [como: usar Combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md). Para obter mais informações sobre o `combinable` de classe, consulte [objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md).  
  
 [[Superior](#top)]  
  
##  <a name="false-sharing"></a>Quando possível, evite falso compartilhamento  
 *Falso compartilhamento* ocorre quando várias tarefas simultâneas que são executados em processadores separados de gravação para variáveis que estão localizados na mesma linha de cache. Quando uma tarefa grava uma das variáveis, a linha de cache para ambas as variáveis é invalidada. Cada processador deve recarregar a linha de cache sempre que a linha de cache é invalidada. Portanto, falso compartilhamento pode causar redução no desempenho em seu aplicativo.  
  
 Exemplo básico mostra duas tarefas a seguir simultâneas que cada incrementa uma variável de contador compartilhado.  
  
 [!code-cpp[concrt-false-sharing#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_17.cpp)]  
  
 Para eliminar o compartilhamento de dados entre as duas tarefas, você pode modificar o exemplo para usar duas variáveis de contador. Esse exemplo calcula o valor final do contador depois de concluir as tarefas. No entanto, este exemplo ilustra falso compartilhamento porque as variáveis `count1` e `count2` devem estar localizados na mesma linha de cache.  
  
 [!code-cpp[concrt-false-sharing#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_18.cpp)]  
  
 Uma forma de eliminar falso compartilhamento é certificar-se de que as variáveis de contador estiverem em linhas de cache separado. O exemplo a seguir alinha as variáveis `count1` e `count2` em limites de 64 bytes.  
  
 [!code-cpp[concrt-false-sharing#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_19.cpp)]  
  
 Este exemplo supõe que o tamanho do cache de memória é menos ou 64 bytes.  
  
 Recomendamos que você use o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe quando você deve compartilhar dados entre tarefas. O `combinable` classe cria variáveis locais de thread de forma que é menos provável falso compartilhamento. Para obter mais informações sobre o `combinable` de classe, consulte [objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md).  
  
 [[Superior](#top)]  
  
##  <a name="lifetime"></a>Certifique-se de que as variáveis são válidas em todo o tempo de vida de uma tarefa  
 Quando você fornece uma expressão lambda para um grupo de tarefas ou o algoritmo paralelo, a cláusula de captura Especifica se o corpo da expressão lambda acessa variáveis no escopo delimitador por valor ou por referência. Quando você passar variáveis em uma expressão lambda por referência, você deve assegurar que o tempo de vida da variável persiste até que a tarefa seja concluída.  
  
 Considere o seguinte exemplo define o `object` classe e o `perform_action` função. O `perform_action` função cria uma `object` variável e executa uma ação nessa variável de forma assíncrona. Porque não é garantida que a tarefa antes de encerrar o `perform_action` função retornar, o programa será falhar ou apresentar comportamento não especificado se o `object` variável é destruída quando a execução da tarefa.  
  
 [!code-cpp[concrt-lambda-lifetime#1](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_20.cpp)]  
  
 Dependendo dos requisitos do seu aplicativo, você pode usar uma das seguintes técnicas para garantir que as variáveis permaneçam válidas durante o tempo de vida de cada tarefa.  
  
 O exemplo a seguir passa o `object` variável pelo valor para a tarefa. Portanto, a tarefa funciona em sua própria cópia da variável.  
  
 [!code-cpp[concrt-lambda-lifetime#2](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_21.cpp)]  
  
 Porque o `object` variável é transmitida por valor, qualquer alteração de estado que ocorrem para essa variável não aparecem na cópia original.  
  
 O exemplo a seguir usa o [concurrency::task_group::wait](reference/task-group-class.md#wait) método para certificar-se de que a tarefa for concluída antes do `perform_action` função retorna.  


  
 [!code-cpp[concrt-lambda-lifetime#3](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_22.cpp)]  
  
 Porque a tarefa agora é concluída antes da função retorna, o `perform_action` função não se comporta de forma assíncrona.  
  
 O exemplo a seguir modifica o `perform_action` função seja uma referência para o `object` variável. O chamador deve garantir que o tempo de vida de `object` variável é válida até o término da tarefa.  
  
 [!code-cpp[concrt-lambda-lifetime#4](../../parallel/concrt/codesnippet/cpp/best-practices-in-the-parallel-patterns-library_23.cpp)]  
  
 Você também pode usar um ponteiro para controlar o tempo de vida de um objeto que você passa para um grupo de tarefas ou o algoritmo paralelo.  
  
 Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).  
  
 [[Superior](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Práticas recomendadas de tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-best-practices.md)   
 [Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)   
 [Objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md)   
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Cancelamento no PPL](cancellation-in-the-ppl.md)   
 [Tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)   
 [Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)   
 [Como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)   
 [Como: usar cancelamento para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)   
 [Como: usar Combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)   
 [Práticas recomendadas para a biblioteca de agentes assíncronos](../../parallel/concrt/best-practices-in-the-asynchronous-agents-library.md)   
 [Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)

