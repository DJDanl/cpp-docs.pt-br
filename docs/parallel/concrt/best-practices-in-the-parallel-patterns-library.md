---
title: "Pr&#225;ticas recomendadas na Biblioteca de Padr&#245;es Paralelos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Biblioteca de padrões paralelos, práticas recomendadas para evitar"
  - "práticas recomendadas para evitar a biblioteca de padrões paralelos"
  - "práticas recomendadas, biblioteca de padrões paralelos"
  - "Biblioteca de padrões paralelos, práticas recomendadas"
ms.assetid: e43e0304-4d54-4bd8-a3b3-b8673559a9d7
caps.latest.revision: 24
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pr&#225;ticas recomendadas na Biblioteca de Padr&#245;es Paralelos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve a melhor maneira para fazer uso efetivo da paralela padrões PPL (biblioteca). A PPL fornece algoritmos, objetos e contêineres de finalidade geral para executar o paralelismo refinado.  
  
 Para obter mais informações sobre a PPL, consulte [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).  
  
##  <a name="a-nametopa-sections"></a><a name="top"></a> Seções  
 Este documento contém as seguintes seções:  
  
- [Não paralelizar corpos de Loop pequenos](#small-loops)  
  
- [Expressar paralelismo no nível mais alto possível](#highest)  
  
- [Usar parallel_invoke para solucionar problemas de dividir e conquistar](#divide-and-conquer)  
  
- [Usar cancelamento ou tratamento de exceções para quebra de um loop paralelo](#breaking-loops)  
  
- [Compreender como cancelamento e manipulação de exceção afetam a destruição de objeto](#object-destruction)  
  
- [Não bloquear repetidamente em um Loop paralelo](#repeated-blocking)  
  
- [Não execute operações de bloqueio ao cancelar o trabalho paralelo](#blocking)  
  
- [Não gravar dados compartilhados em um Loop paralelo](#shared-writes)  
  
- [Quando possível, evitar o falso compartilhamento](#false-sharing)  
  
- [Certifique-se de que as variáveis são válidas durante a vida útil de uma tarefa](#lifetime)  
  
##  <a name="a-namesmall-loopsa-do-not-parallelize-small-loop-bodies"></a><a name="small-loops"></a> Não paralelizar corpos de Loop pequenos  
 A paralelização de corpos de loop relativamente pequeno pode causar o associado sobrecarga de agendamento para superar os benefícios do processamento paralelo. Considere o exemplo a seguir, que adiciona cada par de elementos em duas matrizes.  
  
 [!code-cpp[concrt-small-loops#1](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_1.cpp)]  
  
 A carga de trabalho para cada iteração do loop paralelo é muito pequena para se beneficiar com a sobrecarga de processamento paralelo. Você pode melhorar o desempenho desse loop executando mais trabalho no corpo do loop ou executando o loop em série.  
  
 [[Top](#top)]  
  
##  <a name="a-namehighesta-express-parallelism-at-the-highest-possible-level"></a><a name="highest"></a> Expressar paralelismo no nível mais alto possível  
 Quando você paralelizar código apenas no nível inferior, você pode introduzir uma construção de bifurcação-junção não é dimensionado conforme o número de processadores. Um *de bifurcação-junção* construção é uma construção em que uma tarefa divide seu trabalho em subtarefas paralelas menores e aguarda as subtarefas concluir. Cada subtarefa pode dividir recursivamente em si em subtarefas adicionais.  
  
 Embora o modelo de bifurcação-junção pode ser útil para solucionar vários problemas, há situações em que a sobrecarga de sincronização pode diminuir a escalabilidade. Por exemplo, considere o seguinte código serial que processa os dados de imagem.  
  
 [!code-cpp[concrt-image-processing-filter#20](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_2.cpp)]  
  
 Como cada iteração do loop é independente, você consegue paralelizar tão grande parte do trabalho, conforme mostrado no exemplo a seguir. Este exemplo usa o [concurrency::parallel_for](../Topic/parallel_for%20Function.md) algoritmo em paralelo o loop externo.  
  
 [!code-cpp[concrt-image-processing-filter#3](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_3.cpp)]  
  
 O exemplo a seguir ilustra uma construção de bifurcação-junção chamando o `ProcessImage` função em um loop. Cada chamada para `ProcessImage` não retorna até que termine a cada subtarefa.  
  
 [!code-cpp[concrt-image-processing-filter#21](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_4.cpp)]  
  
 Se cada iteração do loop paralelo seja executa quase nenhum trabalho ou o trabalho realizado pelo loop paralelo é desequilibrada, ou seja, algumas iterações de loop demoram mais do que outros, a sobrecarga de agendamento que é necessário para bifurcação com frequência e trabalho de junção pode superar o benefício para execução paralela. Essa sobrecarga aumenta à medida que o número de processadores aumentar.  
  
 Para reduzir a quantidade de agendamento de sobrecarga neste exemplo, você consegue paralelizar loops externas antes de paralelizar loops internos ou usar outra construção paralela como pipeline. O exemplo a seguir modifica o `ProcessImages` função para usar o [concurrency::parallel_for_each](../Topic/parallel_for_each%20Function.md) algoritmo em paralelo o loop externo.  
  
 [!code-cpp[concrt-image-processing-filter#22](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_5.cpp)]  
  
 Para obter um exemplo semelhante que usa um pipeline para realizar processamento de imagens em paralelo, consulte [passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).  
  
 [[Top](#top)]  
  
##  <a name="a-namedivide-and-conquera-use-parallelinvoke-to-solve-divide-and-conquer-problems"></a><a name="divide-and-conquer"></a> Usar parallel_invoke para solucionar problemas de dividir e conquistar  
 Um *"dividir e conquistar"* problema é uma forma da construção de bifurcação-junção que usa a recursão para dividir uma tarefa em subtarefas. Além de [concurrency::task_group](../Topic/task_group%20Class.md) e [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes, você também pode usar o [concurrency::parallel_invoke](../Topic/parallel_invoke%20Function.md) algoritmo para resolver problemas dividir e conquistar. O `parallel_invoke` algoritmo tem uma sintaxe mais sucinta que objetos de grupo de tarefas e é útil quando você tem um número fixo de tarefas paralelas.  
  
 O exemplo a seguir ilustra o uso do `parallel_invoke` algoritmo para implementar o bitonic algoritmo de classificação.  
  
 [!CODE [concrt-parallel-bitonic-sort#12](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#12)]  
  
 Para reduzir a sobrecarga, o `parallel_invoke` algoritmo executa o último da série de tarefas no contexto de chamada.  
  
 Para obter a versão completa deste exemplo, consulte [como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md). Para obter mais informações sobre o `parallel_invoke` algoritmo, consulte [algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
 [[Top](#top)]  
  
##  <a name="a-namebreaking-loopsa-use-cancellation-or-exception-handling-to-break-from-a-parallel-loop"></a><a name="breaking-loops"></a> Usar cancelamento ou tratamento de exceções para quebra de um loop paralelo  
 A PPL fornece duas maneiras para cancelar o trabalho paralelo executado por um grupo de tarefas ou o algoritmo paralelo. Uma maneira é usar o mecanismo de cancelamento é fornecido pelo [concurrency::task_group](../Topic/task_group%20Class.md) e [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) classes. Outra maneira é lançar uma exceção no corpo de uma função de trabalho da tarefa. O mecanismo de cancelamento é mais eficiente do que no cancelamento de uma árvore de trabalho paralela de manipulação de exceção. Um *trabalho paralelo árvore* é um grupo de grupos de tarefas relacionadas no qual alguns grupos de tarefas contenham outros grupos de tarefas. O mecanismo de cancelamento cancela um grupo de tarefas e seus grupos de tarefas filho de uma maneira de cima para baixo. Por outro lado, a manipulação de exceção funciona de forma ascendente e deve cancelar a cada grupo de tarefas filho independentemente como a exceção se propaga para cima.  
  
 Quando você trabalha diretamente com um objeto de grupo de tarefas, use o [concurrency::task_group::cancel](../Topic/task_group::cancel%20Method.md) ou [concurrency::structured_task_group::cancel](../Topic/structured_task_group::cancel%20Method.md) métodos para cancelar o trabalho que pertence a esse grupo de tarefas. Para cancelar um algoritmo paralelo, por exemplo, `parallel_for`, crie um grupo de tarefa pai e cancelar esse grupo de tarefas. Por exemplo, considere a seguinte função, `parallel_find_any`, que procura um valor em uma matriz em paralelo.  
  
 [!code-cpp[concrt-parallel-array-search#2](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_6.cpp)]  
  
 Como algoritmos paralelos usam grupos de tarefas quando uma das iterações paralelas cancela o grupo de tarefas do pai, a tarefa foi cancelada. Para obter a versão completa deste exemplo, consulte [como: usar cancelamento para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md).  
  
 Embora o tratamento de exceção é uma maneira menos eficiente para cancelar o trabalho paralelo que o mecanismo de cancelamento, há casos em que a manipulação de exceção é apropriada. Por exemplo, o seguinte método, `for_all`, recursivamente executa uma função de trabalho em cada nó de um `tree` estrutura. Neste exemplo, o `_children` membro de dados é um [std:: List](../../standard-library/list-class.md) que contém `tree` objetos.  
  
 [!CODE [concrt-task-tree-search#6](../CodeSnippet/VS_Snippets_ConcRT/concrt-task-tree-search#6)]  
  
 O chamador de `tree::for_all` método pode lançar uma exceção se ele não requer a função de trabalho seja chamado em cada elemento da árvore. A exemplo a seguir mostra o `search_for_value` função, que procura um valor fornecidos `tree` objeto. O `search_for_value` função usa uma função de trabalho que gera uma exceção quando o elemento atual da árvore corresponde ao valor fornecido. O `search_for_value` função usa um `try-catch` bloco para capturar a exceção e imprimirá o resultado no console.  
  
 [!CODE [concrt-task-tree-search#3](../CodeSnippet/VS_Snippets_ConcRT/concrt-task-tree-search#3)]  
  
 Para obter a versão completa deste exemplo, consulte [como: usar tratamento de exceções para parar um loop paralelo](../Topic/How%20to:%20Use%20Exception%20Handling%20to%20Break%20from%20a%20Parallel%20Loop.md).  
  
 Para obter mais informações sobre o cancelamento e mecanismos de tratamento de exceções que são fornecidos pelo PPL, consulte [cancelamento](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md#cancellation_in_the_ppl) e [Exception Handling](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
 [[Top](#top)]  
  
##  <a name="a-nameobject-destructiona-understand-how-cancellation-and-exception-handling-affect-object-destruction"></a><a name="object-destruction"></a> Compreender como cancelamento e manipulação de exceção afetam a destruição de objeto  
 Em uma árvore de trabalho paralelo, uma tarefa que é cancelada impede que tarefas filho em execução. Isso pode causar problemas se uma das tarefas filho executa uma operação que é importante para seu aplicativo, como liberar um recurso. Além disso, o cancelamento da tarefa pode causar uma exceção propagar através de um destruidor de objeto e causar um comportamento indefinido em seu aplicativo.  
  
 No exemplo a seguir, a `Resource` classe descreve um recurso e o `Container` classe descreve um contêiner que mantém os recursos. Em seu destruidor, a `Container` classe chamadas a `cleanup` método em dois dos seus `Resource` membros em paralelo e, em seguida, chama o `cleanup` método em sua terceira `Resource` membro.  
  
 [!code-cpp[concrt-parallel-resource-destruction#1](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_7.h)]  
  
 Embora esse padrão não tem problemas por conta própria, considere o seguinte código que executa duas tarefas em paralelo. A primeira tarefa cria uma `Container` objeto e a segunda tarefa cancela a tarefa. Para fins de ilustração, o exemplo usa dois [concurrency::event](../Topic/event%20Class.md) objetos para certificar-se de que o cancelamento ocorrerá após o `Container` objeto é criado e que o `Container` objeto é destruído após a operação de cancelamento.  
  
 [!code-cpp[concrt-parallel-resource-destruction#2](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_8.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
Container 1: Freeing resources...Exiting program...  
```  
  
 Este exemplo de código contém os seguintes problemas que podem fazer com que ele se comportam de maneira diferente do que o esperado:  
  
-   O cancelamento da tarefa pai faz com que a tarefa filho, a chamada para [concurrency::parallel_invoke](../Topic/parallel_invoke%20Function.md), também seja cancelada. Portanto, esses dois recursos não são liberados.  
  
-   O cancelamento da tarefa pai faz com que a tarefa filho lançar uma exceção interna. Porque o `Container` destruidor não tratar essa exceção, a exceção é propagada para cima e o terceiro recurso não é liberado.  
  
-   A exceção que é gerada pela tarefa filho se propaga por meio de `Container` destruidor. Lançar em um destruidor coloca o aplicativo em um estado indefinido.  
  
 É recomendável que você não realizar operações críticas, como a liberação dos recursos, tarefas, a menos que você possa garantir que essas tarefas não serão canceladas. Também recomendamos que você não use a funcionalidade de tempo de execução que pode lançar no destruidor de seus tipos.  
  
 [[Top](#top)]  
  
##  <a name="a-namerepeated-blockinga-do-not-block-repeatedly-in-a-parallel-loop"></a><a name="repeated-blocking"></a> Não bloquear repetidamente em um Loop paralelo  
 Um loop paralelo como [concurrency::parallel_for](../Topic/parallel_for%20Function.md) ou [concurrency::parallel_for_each](../Topic/parallel_for_each%20Function.md) que é dominado por bloqueio de operações podem fazer com que o tempo de execução criar muitos threads durante um curto período de tempo.  
  
 O tempo de execução de simultaneidade executa trabalho adicional quando uma tarefa termina ou cooperativamente bloqueia ou produz. Quando um paralelo blocos de iteração de loop, o tempo de execução pode começar outra iteração. Quando não há nenhum thread ocioso disponível, o tempo de execução cria um novo thread.  
  
 Quando o corpo de um paralelo ocasionalmente loop blocos, esse mecanismo ajuda a maximizar a produtividade geral da tarefa. No entanto, ao bloqueiam muitas iterações, o tempo de execução pode criar muitos threads para executar o trabalho adicional. Isso pode levar a subutilização de recursos de hardware ou condições de memória insuficiente.  
  
 Considere o exemplo a seguir que chama o [concurrency::send](../Topic/send%20Function.md) função em cada iteração de um `parallel_for` loop. Porque `send` bloqueia cooperativamente, o tempo de execução cria um novo segmento para executar o trabalho adicional sempre `send` é chamado.  
  
 [!CODE [concrt-repeated-blocking#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-repeated-blocking#1)]  
  
 É recomendável que você refatora seu código para evitar esse padrão. Neste exemplo, você pode evitar a criação de threads adicionais chamando `send` em uma série `for` loop.  
  
 [[Top](#top)]  
  
##  <a name="a-nameblockinga-do-not-perform-blocking-operations-when-you-cancel-parallel-work"></a><a name="blocking"></a> Não execute operações de bloqueio ao cancelar o trabalho paralelo  
 Quando possível, não execute operações de bloqueio antes de chamar o [concurrency::task_group::cancel](../Topic/task_group::cancel%20Method.md) ou [concurrency::structured_task_group::cancel](../Topic/structured_task_group::cancel%20Method.md) método para cancelar o trabalho paralelo.  
  
 Quando uma tarefa executa um cooperativo bloqueando a operação, o tempo de execução pode executar outro trabalho enquanto a primeira tarefa aguarda os dados. O tempo de execução reagenda a tarefa em espera quando ele desbloqueia. Normalmente, o tempo de execução reagenda tarefas que foram desbloqueadas mais recentemente antes de ele reagenda tarefas que foram desbloqueadas menos recentemente. Portanto, o tempo de execução pode agendar trabalho desnecessário durante a operação de bloqueio, o que leva à redução do desempenho. Da mesma forma, quando você executar uma operação de bloqueio antes de cancelar o trabalho paralelo, a operação de bloqueio pode atrasar a chamada para `cancel`. Isso faz com que outras tarefas Executar trabalho desnecessário.  
  
 Considere o seguinte exemplo define o `parallel_find_answer` função, que pesquisa um elemento da matriz fornecida que satisfaça a função de predicado fornecida. Quando a função de predicado retorna `true`, a função de trabalho paralela cria um `Answer` do objeto e cancela a tarefa.  
  
 [!code-cpp[concrt-blocking-cancel#1](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_9.cpp)]  
  
 O `new` operador executa uma alocação de heap pode bloquear. O tempo de execução executa outro trabalho somente quando a tarefa executa um cooperativo bloqueio de chamada, como uma chamada para [concurrency::critical_section::lock](../Topic/critical_section::lock%20Method.md).  
  
 O exemplo a seguir mostra como impedir que o trabalho desnecessário e, portanto, melhorar o desempenho. Este exemplo cancela o grupo de tarefas antes de alocar o armazenamento para o `Answer` objeto.  
  
 [!code-cpp[concrt-blocking-cancel#2](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_10.cpp)]  
  
 [[Top](#top)]  
  
##  <a name="a-nameshared-writesa-do-not-write-to-shared-data-in-a-parallel-loop"></a><a name="shared-writes"></a> Não gravar dados compartilhados em um Loop paralelo  
 O tempo de execução de simultaneidade fornece diversas estruturas de dados, por exemplo, [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md), que sincronizar o acesso simultâneo aos dados compartilhados. Essas estruturas de dados são úteis em muitos casos, por exemplo, quando várias tarefas com pouca frequência exigem acesso compartilhado a um recurso.  
  
 Considere o seguinte exemplo usa o [concurrency::parallel_for_each](../Topic/parallel_for_each%20Function.md) algoritmo e uma `critical_section` objeto para calcular a contagem de números primos em uma [std::array](../../standard-library/array-class-stl.md) objeto. Este exemplo não é dimensionado porque cada thread deve esperar para acessar a variável compartilhada `prime_sum`.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#2](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_11.cpp)]  
  
 Este exemplo também pode levar a um desempenho ruim porque a operação de bloqueio frequente efetivamente serializa o loop. Além disso, quando um objeto de tempo de execução de simultaneidade executa uma operação de bloqueio, o Agendador pode criar um thread adicional para realizar outras tarefas enquanto o primeiro thread aguarda os dados. Se o tempo de execução cria muitos threads porque muitas tarefas estão aguardando dados compartilhados, o aplicativo poderá insatisfatório ou entrar em um estado de poucos recursos.  
  
 Define a PPL o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe, que ajuda a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de forma livre de bloqueio. O `combinable` classe fornece armazenamento de thread local que permite realizar cálculos refinados e mescle os cálculos em um resultado final. Você pode pensar uma `combinable` objeto como uma variável de redução.  
  
 O exemplo a seguir modifica a uma anterior usando um `combinable` do objeto, em vez de um `critical_section` objeto para calcular a soma. Este exemplo dimensiona porque cada thread mantém sua própria cópia local da soma. Este exemplo usa o [concurrency::combinable::combine](../Topic/combinable::combine%20Method.md) método para mesclar as computações de locais com o resultado final.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#3](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_12.cpp)]  
  
 Para obter a versão completa deste exemplo, consulte [como: usar Combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md). Para obter mais informações sobre o `combinable` de classe, consulte [paralela contêineres e objetos](../../parallel/concrt/parallel-containers-and-objects.md).  
  
 [[Top](#top)]  
  
##  <a name="a-namefalse-sharinga-when-possible-avoid-false-sharing"></a><a name="false-sharing"></a> Quando possível, evitar o falso compartilhamento  
 *Falso compartilhamento* ocorre quando várias tarefas simultâneas que estão em execução em processadores separados gravar em variáveis que estão localizados na mesma linha de cache. Quando uma tarefa grava uma das variáveis, a linha de cache para ambas as variáveis é invalidada. Cada processador necessário recarregar a linha de cache sempre que a linha de cache é invalidada. Portanto, o falso compartilhamento pode causar redução no desempenho em seu aplicativo.  
  
 As seguinte exemplo básico mostra duas tarefas simultâneas que cada incrementa uma variável de contador compartilhado.  
  
 [!code-cpp[concrt-false-sharing#1](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_13.cpp)]  
  
 Para eliminar o compartilhamento de dados entre as duas tarefas, você pode modificar o exemplo para usar duas variáveis de contador. Esse exemplo calcula o valor do contador final após a conclusão das tarefas. No entanto, este exemplo ilustra o falso compartilhamento porque as variáveis `count1` e `count2` devem estar localizados na mesma linha de cache.  
  
 [!code-cpp[concrt-false-sharing#2](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_14.cpp)]  
  
 É uma forma de eliminar o falso compartilhamento certificar-se de que as variáveis de contador são linhas de cache separado. O exemplo a seguir alinha as variáveis `count1` e `count2` em limites de 64 bytes.  
  
 [!code-cpp[concrt-false-sharing#3](../../parallel/concrt/codesnippet/CPP/best-practices-in-the-parallel-patterns-library_15.cpp)]  
  
 Este exemplo assume que o tamanho do cache de memória é 64 ou menos bytes.  
  
 É recomendável que você use o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe quando você precisa compartilhar dados entre tarefas. O `combinable` classe cria variáveis locais de thread de forma que o falso compartilhamento é menos provável. Para obter mais informações sobre o `combinable` de classe, consulte [paralela contêineres e objetos](../../parallel/concrt/parallel-containers-and-objects.md).  
  
 [[Top](#top)]  
  
##  <a name="a-namelifetimea-make-sure-that-variables-are-valid-throughout-the-lifetime-of-a-task"></a><a name="lifetime"></a> Certifique-se de que as variáveis são válidas durante a vida útil de uma tarefa  
 Quando você fornece uma expressão lambda para um grupo de tarefas ou o algoritmo paralelo, a cláusula de captura Especifica se o corpo da expressão lambda acessa variáveis no escopo delimitador por valor ou por referência. Quando você passa variáveis em uma expressão lambda por referência, você deve assegurar que o tempo de vida da variável persiste até que a tarefa seja concluída.  
  
 Considere o seguinte exemplo define o `object` classe e o `perform_action` função. O `perform_action` função cria um `object` variável e executa alguma ação naquela variável de forma assíncrona. Porque não é garantida que a tarefa seja concluída antes do `perform_action` função retorna, o programa irá falhar ou apresentam o comportamento especificado se o `object` variável é destruída quando a execução da tarefa.  
  
 [!CODE [concrt-lambda-lifetime#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-lambda-lifetime#1)]  
  
 Dependendo dos requisitos do seu aplicativo, você pode usar uma das seguintes técnicas para garantir que as variáveis permanecem válidas durante a vida útil de cada tarefa.  
  
 O exemplo a seguir passa a `object` variável pelo valor para a tarefa. Portanto, a tarefa opera em sua própria cópia da variável.  
  
 [!CODE [concrt-lambda-lifetime#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-lambda-lifetime#2)]  
  
 Porque o `object` variável é passada por valor, as alterações de estado que ocorrem a essa variável não aparecem na cópia original.  
  
 O exemplo a seguir usa o [concurrency::task_group::wait](../Topic/task_group::wait%20Method.md) método para ter certeza de que a tarefa for concluída antes do `perform_action` retornos de função.  
  
 [!CODE [concrt-lambda-lifetime#3](../CodeSnippet/VS_Snippets_ConcRT/concrt-lambda-lifetime#3)]  
  
 Porque a tarefa agora termina antes que a função retorna, o `perform_action` função não se comporta de forma assíncrona.  
  
 O exemplo a seguir modifica o `perform_action` função para obter uma referência para o `object` variável. O chamador deve garantir que o tempo de vida do `object` variável será válida até que a tarefa for concluída.  
  
 [!CODE [concrt-lambda-lifetime#4](../CodeSnippet/VS_Snippets_ConcRT/concrt-lambda-lifetime#4)]  
  
 Você também pode usar um ponteiro para controlar o tempo de vida de um objeto que você passa para um grupo de tarefas ou o algoritmo paralelo.  
  
 Para obter mais informações sobre expressões lambda, consulte [expressões Lambda](../../cpp/lambda-expressions-in-cpp.md).  
  
 [[Top](#top)]  
  
## <a name="see-also"></a>Consulte também  
 [Práticas recomendadas de tempo de execução de simultaneidade](../Topic/Concurrency%20Runtime%20Best%20Practices.md)   
 [Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)   
 [Objetos e contêineres em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)   
 [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)   
 [Cancelamento](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md#cancellation_in_the_ppl)   
 [Tratamento de exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md)   
 [Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)   
 [Como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)   
 [Como: usar cancelamento para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)   
 [Como: usar Combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)   
 [Práticas recomendadas para a biblioteca de agentes assíncronos](../Topic/Best%20Practices%20in%20the%20Asynchronous%20Agents%20Library.md)   
 [Práticas recomendadas gerais no tempo de execução de simultaneidade](../../parallel/concrt/general-best-practices-in-the-concurrency-runtime.md)

