---
title: Cancelamento no PPL
ms.date: 11/19/2018
helpviewer_keywords:
- parallel algorithms, canceling [Concurrency Runtime]
- canceling parallel algorithms [Concurrency Runtime]
- parallel tasks, canceling [Concurrency Runtime]
- cancellation in the PPL
- parallel work trees [Concurrency Runtime]
- canceling parallel tasks [Concurrency Runtime]
ms.assetid: baaef417-b2f9-470e-b8bd-9ed890725b35
ms.openlocfilehash: 3a7f9c5720c4bd6a43a1a95f9bc19680ba0a9c1e
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "69631720"
---
# <a name="cancellation-in-the-ppl"></a>Cancelamento no PPL

Este documento explica a função de cancelamento na PPL (biblioteca de padrões paralelos), como cancelar o trabalho paralelo e como determinar quando o trabalho paralelo é cancelado.

> [!NOTE]
>  O tempo de execução usa tratamento de exceções para implementar o cancelamento. Não pegue nem manipule essas exceções em seu código. Além disso, recomendamos que você escreva código de exceção segura nos corpos de função para suas tarefas. Por exemplo, você pode usar o padrão RAII ( *aquisição de recursos é inicialização* ) para garantir que os recursos sejam manipulados corretamente quando uma exceção for lançada no corpo de uma tarefa. Para obter um exemplo completo que usa o padrão RAII para limpar um recurso em uma tarefa cancelável, [consulte Passo a passos: Removendo o trabalho de um thread](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md)de interface do usuário.

## <a name="key-points"></a>Pontos-chave

- O cancelamento é cooperativo e envolve a coordenação entre o código que solicita o cancelamento e a tarefa que responde ao cancelamento.

- Quando possível, use tokens de cancelamento para cancelar o trabalho. A classe [Concurrency:: cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md) define um token de cancelamento.

- Quando você usa tokens de cancelamento, use o método [Concurrency:: cancellation_token_source:: Cancel](reference/cancellation-token-source-class.md#cancel) para iniciar o cancelamento e a função [Concurrency:: cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) para responder ao cancelamento. Use o método [Concurrency:: cancellation_token:: is_canceled](reference/cancellation-token-class.md#is_canceled) para verificar se alguma outra tarefa solicitou o cancelamento.

- O cancelamento não ocorre imediatamente. Embora o novo trabalho não seja iniciado se uma tarefa ou grupo de tarefas for cancelado, o trabalho ativo deverá verificar e responder ao cancelamento.

- Uma continuação baseada em valor herda o token de cancelamento de sua tarefa Antecedent. Uma continuação baseada em tarefa nunca herda o token de sua tarefa antecedente.

- Use o método [Concurrency:: cancellation_token:: None](reference/cancellation-token-class.md#none) ao chamar um construtor ou uma função que usa um `cancellation_token` objeto, mas que você não deseja que a operação seja cancelada. Além disso, se você não passar um token de cancelamento para o construtor [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) ou a função [Concurrency:: create_task](reference/concurrency-namespace-functions.md#create_task) , essa tarefa não poderá ser cancelada.

##  <a name="top"></a>Neste documento

- [Árvores de trabalho paralelas](#trees)

- [Cancelando tarefas paralelas](#tasks)

    - [Usando um token de cancelamento para cancelar o trabalho paralelo](#tokens)

    - [Usando o método Cancel para cancelar o trabalho paralelo](#cancel)

    - [Usando exceções para cancelar o trabalho paralelo](#exceptions)

- [Cancelando algoritmos paralelos](#algorithms)

- [Quando não usar o cancelamento](#when)

##  <a name="trees"></a>Árvores de trabalho paralelas

A PPL usa tarefas e grupos de tarefas para gerenciar tarefas e cálculos refinados. Você pode aninhar grupos de tarefas para formar *árvores* de trabalho paralelo. A ilustração a seguir mostra uma árvore de trabalho paralela. Nesta ilustração, `tg1` e `tg2` representam grupos de tarefas; `t1` ,,,`t5` e representam o trabalho que os grupos de tarefas executam. `t2` `t3` `t4`

![Uma árvore de trabalho paralela](../../parallel/concrt/media/parallelwork_trees.png "Uma árvore de trabalho paralela")

O exemplo a seguir mostra o código necessário para criar a árvore na ilustração. Neste exemplo, `tg1` e `tg2` são objetos [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) ; `t1` ,`t2`, ,`t4`e são`t5` objetos [Concurrency:: task_handle](../../parallel/concrt/reference/task-handle-class.md) . `t3`

[!code-cpp[concrt-task-tree#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_1.cpp)]

Você também pode usar a classe [Concurrency:: task_group](reference/task-group-class.md) para criar uma árvore de trabalho semelhante. A classe [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) também dá suporte à noção de uma árvore de trabalho. No entanto `task` , uma árvore é uma árvore de dependência. Em uma `task` árvore, os trabalhos futuros são concluídos após o trabalho atual. Em uma árvore de grupo de tarefas, o trabalho interno é concluído antes do trabalho externo. Para obter mais informações sobre as diferenças entre tarefas e grupos de tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md).

[[Superior](#top)]

##  <a name="tasks"></a>Cancelando tarefas paralelas

Há várias maneiras de cancelar o trabalho paralelo. A maneira preferida é usar um token de cancelamento. Os grupos de tarefas também dão suporte aos métodos [Concurrency:: task_group:: Cancel](reference/task-group-class.md#cancel) e [Concurrency:: structured_task_group:: Cancel](reference/structured-task-group-class.md#cancel) . A maneira final é lançar uma exceção no corpo de uma função de trabalho de tarefa. Não importa qual método você escolher, entenda que o cancelamento não ocorre imediatamente. Embora o novo trabalho não seja iniciado se uma tarefa ou grupo de tarefas for cancelado, o trabalho ativo deverá verificar e responder ao cancelamento.

Para obter mais exemplos que cancelam tarefas [paralelas, consulte Walkthrough: Conectar-se usando tarefas e solicitações](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)http [XML, como: Use o cancelamento para interromper a partir de](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)um loop [paralelo e como: Use o tratamento de exceções para interromper um loop](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md)paralelo.

###  <a name="tokens"></a>Usando um token de cancelamento para cancelar o trabalho paralelo

As `task`classes `task_group`, e`structured_task_group` oferecem suporte ao cancelamento por meio do uso de tokens de cancelamento. A PPL define as classes [Concurrency:: cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md) e [Concurrency:: cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md) para essa finalidade. Quando você usa um token de cancelamento para cancelar o trabalho, o tempo de execução não inicia um novo trabalho que assina esse token. O trabalho que já está ativo pode usar a função de membro [is_canceled](../../parallel/concrt/reference/cancellation-token-class.md#is_canceled) para monitorar o token de cancelamento e parar quando puder.

Para iniciar o cancelamento, chame o método [Concurrency:: cancellation_token_source:: Cancel](reference/cancellation-token-source-class.md#cancel) . Você responde ao cancelamento das seguintes maneiras:

- Para `task` objetos, use a função [Concurrency:: cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) . `cancel_current_task`Cancela a tarefa atual e qualquer uma de suas continuaçãos baseadas em valor. (Ele não cancela o *token* de cancelamento associado à tarefa ou a suas continuaçãos.)

- Para grupos de tarefas e algoritmos paralelos, use a função [Concurrency:: is_current_task_group_canceling](reference/concurrency-namespace-functions.md#is_current_task_group_canceling) para detectar o cancelamento e retornar assim que possível no corpo da tarefa quando essa função retornar **true**. (Não chame `cancel_current_task` de um grupo de tarefas.)

O exemplo a seguir mostra o primeiro padrão básico para cancelamento de tarefa. O corpo da tarefa verifica ocasionalmente o cancelamento dentro de um loop.

[!code-cpp[concrt-task-basic-cancellation#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_2.cpp)]

A `cancel_current_task` função gera; portanto, você não precisa retornar explicitamente do loop ou da função atual.

> [!TIP]
> Como alternativa, você pode chamar a função [Concurrency:: interruption_point](reference/concurrency-namespace-functions.md#interruption_point) em vez `cancel_current_task`de.

É importante chamar `cancel_current_task` quando você responde ao cancelamento porque ele faz a transição da tarefa para o estado cancelado. Se você retornar antecipadamente em vez `cancel_current_task`de chamar, a operação passará para o estado concluído e qualquer continuação baseada em valor será executada.

> [!CAUTION]
> Nunca jogue `task_canceled` do seu código. Chame `cancel_current_task` em seu lugar.

Quando uma tarefa termina no estado cancelado, o método [Concurrency:: Task:: Get](reference/task-class.md#get) gera [Concurrency:: task_canceled](../../parallel/concrt/reference/task-canceled-class.md). (Por outro lado, [Concurrency:: tarefa:: Wait](reference/task-class.md#wait) retorna [task_status:: cancelado](reference/concurrency-namespace-enums.md#task_group_status) e não gera.) O exemplo a seguir ilustra esse comportamento para uma continuação baseada em tarefa. Uma continuação baseada em tarefa é sempre chamada, mesmo quando a tarefa Antecedent é cancelada.

[!code-cpp[concrt-task-canceled#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_3.cpp)]

Como as continuações baseadas em valor herdam o token de sua tarefa antecedente, a menos que tenham sido criadas com um token explícito, as continuaçãos entram imediatamente no estado cancelado mesmo quando a tarefa Antecedent ainda está em execução. Portanto, qualquer exceção gerada pela tarefa antecedente após o cancelamento não é propagada para as tarefas de continuação. O cancelamento sempre substitui o estado da tarefa Antecedent. O exemplo a seguir é semelhante ao anterior, mas ilustra o comportamento de uma continuação baseada em valor.

[!code-cpp[concrt-task-canceled#2](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_4.cpp)]

> [!CAUTION]
> Se você não passar um token de cancelamento para o `task` Construtor ou a função [Concurrency:: create_task](reference/concurrency-namespace-functions.md#create_task) , essa tarefa não poderá ser cancelada. Além disso, você deve passar o mesmo token de cancelamento para o construtor de quaisquer tarefas aninhadas (ou seja, tarefas que são criadas no corpo de outra tarefa) para cancelar todas as tarefas simultaneamente.

Talvez você queira executar código arbitrário quando um token de cancelamento for cancelado. Por exemplo, se o usuário escolher um botão **Cancelar** na interface do usuário para cancelar a operação, você poderá desabilitar esse botão até que o usuário inicie outra operação. O exemplo a seguir mostra como usar o método [Concurrency:: cancellation_token:: register_callback](reference/cancellation-token-class.md#register_callback) para registrar uma função de retorno de chamada que é executada quando um token de cancelamento é cancelado.

[!code-cpp[concrt-task-cancellation-callback#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_5.cpp)]

O [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md) de documentos explica a diferença entre as continuações baseadas em valor e com base em tarefas. Se você não fornecer um `cancellation_token` objeto para uma tarefa de continuação, a continuação herdará o token de cancelamento da tarefa Antecedent das seguintes maneiras:

- Uma continuação baseada em valor sempre herda o token de cancelamento da tarefa Antecedent.

- Uma continuação baseada em tarefa nunca herda o token de cancelamento da tarefa Antecedent. A única maneira de tornar um cancelamento de continuação baseada em tarefa é passar explicitamente um token de cancelamento.

Esses comportamentos não são afetados por uma tarefa com falha (ou seja, um que gera uma exceção). Nesse caso, uma continuação baseada em valor é cancelada; uma continuação baseada em tarefa não é cancelada.

> [!CAUTION]
> Uma tarefa que é criada em outra tarefa (em outras palavras, uma tarefa aninhada) não herda o token de cancelamento da tarefa pai. Somente uma continuação baseada em valor herda o token de cancelamento de sua tarefa Antecedent.

> [!TIP]
> Use o método [Concurrency:: cancellation_token:: None](reference/cancellation-token-class.md#none) ao chamar um construtor ou uma função que usa um `cancellation_token` objeto e você não deseja que a operação seja cancelada.

Você também pode fornecer um token de cancelamento para o construtor de `task_group` um `structured_task_group` objeto ou. Um aspecto importante disso é que os grupos de tarefas filho herdam esse token de cancelamento. Para obter um exemplo que demonstra esse conceito usando a função [Concurrency:: run_with_cancellation_token](reference/concurrency-namespace-functions.md#run_with_cancellation_token) para executar para chamar `parallel_for`, consulte [cancelando algoritmos paralelos](#algorithms) mais adiante neste documento.

[[Superior](#top)]

#### <a name="cancellation-tokens-and-task-composition"></a>Tokens de Cancelamento e Composição da Tarefa

As funções [Concurrency:: when_all](reference/concurrency-namespace-functions.md#when_all) e [Concurrency:: when_any](reference/concurrency-namespace-functions.md#when_all) podem ajudá-lo a compor várias tarefas para implementar padrões comuns. Esta seção descreve como essas funções funcionam com tokens de cancelamento.

Quando você fornece um token de cancelamento para a `when_all` função `when_any` e, essa função cancela somente quando esse token de cancelamento é cancelado ou quando uma das tarefas do participante termina em um estado cancelado ou gera uma exceção.

A `when_all` função herda o token de cancelamento de cada tarefa que compõe a operação geral quando você não fornece um token de cancelamento a ele. A tarefa retornada por `when_all` é cancelada quando qualquer um desses tokens é cancelado e pelo menos uma das tarefas do participante ainda não foi iniciada ou está em execução. Um comportamento semelhante ocorre quando uma das tarefas gera uma exceção – a tarefa retornada `when_all` é imediatamente cancelada com essa exceção.

O tempo de execução escolhe o token de cancelamento para a tarefa que `when_any` é retornada da função quando essa tarefa é concluída. Se nenhuma das tarefas do participante terminar em um estado concluído e uma ou mais das tarefas lançar uma exceção, uma das tarefas emitidas será escolhida para concluir o `when_any` e seu token será escolhido como o token para a tarefa final. Se mais de uma tarefa for concluída no estado concluído, a tarefa retornada da `when_any` tarefa terminará em um estado concluído. O tempo de execução tenta escolher uma tarefa concluída cujo token não é cancelado no momento da conclusão, de forma que a tarefa `when_any` retornada por não seja cancelada imediatamente, mesmo que outras tarefas em execução possam ser concluídas em um ponto posterior.

[[Superior](#top)]

###  <a name="cancel"></a>Usando o método Cancel para cancelar o trabalho paralelo

Os métodos [Concurrency:: task_group:: Cancel](reference/task-group-class.md#cancel) e [Concurrency:: structured_task_group:: Cancel](reference/structured-task-group-class.md#cancel) definem um grupo de tarefas para o estado cancelado. Depois de chamar `cancel`, o grupo de tarefas não inicia as tarefas futuras. Os `cancel` métodos podem ser chamados por várias tarefas filho. Uma tarefa cancelada faz com que os métodos [Concurrency:: task_group:: Wait](reference/task-group-class.md#wait) e [Concurrency:: structured_task_group:: Wait](reference/structured-task-group-class.md#wait) retornem [Concurrency:: cancelado](reference/concurrency-namespace-enums.md#task_group_status).

Se um grupo de tarefas for cancelado, as chamadas de cada tarefa filho para o tempo de execução poderão disparar um *ponto de interrupção*, o que fará com que o tempo de execução gere e pegue um tipo de exceção interna para cancelar as tarefas ativas. O Tempo de Execução de Simultaneidade não define pontos de interrupção específicos; Eles podem ocorrer em qualquer chamada para o tempo de execução. O tempo de execução deve lidar com as exceções que ele gera para executar o cancelamento. Portanto, não manipule exceções desconhecidas no corpo de uma tarefa.

Se uma tarefa filho executar uma operação demorada e não chamar o tempo de execução, ela deverá verificar periodicamente o cancelamento e a saída em tempo hábil. O exemplo a seguir mostra uma maneira de determinar quando o trabalho é cancelado. A `t4` tarefa cancela o grupo de tarefas pai quando encontra um erro. Ocasionalmente `t5` , a tarefa `structured_task_group::is_canceling` chama o método para verificar o cancelamento. Se o grupo de tarefas pai for cancelado, a tarefa `t5` imprimirá uma mensagem e será encerrada.

[!code-cpp[concrt-task-tree#6](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_6.cpp)]

Este exemplo verifica o cancelamento em<sup>cada 100 da</sup> iteração do loop de tarefa. A frequência com a qual você verifica o cancelamento depende da quantidade de trabalho que sua tarefa executa e da rapidez necessária para que as tarefas respondam ao cancelamento.

Se você não tiver acesso ao objeto do grupo de tarefas pai, chame a função [Concurrency:: is_current_task_group_canceling](reference/concurrency-namespace-functions.md#is_current_task_group_canceling) para determinar se o grupo de tarefas pai foi cancelado.

O `cancel` método só afeta tarefas filho. Por exemplo, se `tg1` você cancelar o grupo de tarefas na ilustração da árvore de trabalho paralela, todas as tarefas na árvore (`t1`, `t2` `t3` `t4`,, e `t5`) serão afetadas. Se você cancelar o grupo de tarefas aninhado, `tg2`somente as tarefas `t4` e `t5` serão afetadas.

Quando você chama o `cancel` método, todos os grupos de tarefas filho também são cancelados. No entanto, o cancelamento não afeta os pais do grupo de tarefas em uma árvore de trabalho paralela. Os exemplos a seguir mostram isso criando na ilustração da árvore de trabalho paralela.

O primeiro desses exemplos cria uma função de trabalho para a tarefa `t4`, que é um filho do grupo `tg2`de tarefas. A função de trabalho chama a `work` função em um loop. Se qualquer chamada a `work` falhar, a tarefa cancelará seu grupo de tarefas pai. Isso faz com que `tg2` o grupo de tarefas entre no estado cancelado, mas não `tg1`cancela o grupo de tarefas.

[!code-cpp[concrt-task-tree#2](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_7.cpp)]

Esse segundo exemplo é semelhante ao primeiro, exceto que a tarefa cancela o grupo `tg1`de tarefas. Isso afeta todas as tarefas na árvore (`t1` `t3`, `t2` `t4`,, e `t5`).

[!code-cpp[concrt-task-tree#3](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_8.cpp)]

A `structured_task_group` classe não é thread-safe. Portanto, uma tarefa filho que chama um método de seu objeto `structured_task_group` pai produz um comportamento não especificado. As exceções a essa regra são os `structured_task_group::cancel` métodos e [Concurrency:: structured_task_group:: is_canceling](reference/structured-task-group-class.md#is_canceling) . Uma tarefa filho pode chamar esses métodos para cancelar o grupo de tarefas pai e verificar o cancelamento.

> [!CAUTION]
>  Embora você possa usar um token de cancelamento para cancelar o trabalho que é executado por um grupo de tarefas que é executado como `task` um filho de um objeto, `task_group::cancel` não é possível usar `task` os métodos ou `structured_task_group::cancel` para cancelar objetos executados em um grupo de tarefas.

[[Superior](#top)]

###  <a name="exceptions"></a>Usando exceções para cancelar o trabalho paralelo

O uso de tokens de cancelamento `cancel` e do método é mais eficiente do que a manipulação de exceção no cancelamento de uma árvore de trabalho paralela. Os tokens de cancelamento e o `cancel` método cancelam uma tarefa e todas as tarefas filho de maneira superior. Por outro lado, a manipulação de exceção funciona de maneira inferior e deve cancelar cada grupo de tarefas filho de forma independente, pois a exceção se propaga para cima. O tópico [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md) explica como a tempo de execução de simultaneidade usa exceções para comunicar erros. No entanto, nem todas as exceções indicam um erro. Por exemplo, um algoritmo de pesquisa pode cancelar sua tarefa associada quando encontra o resultado. No entanto, como mencionado anteriormente, o tratamento de exceções é menos `cancel` eficiente do que usar o método para cancelar o trabalho paralelo.

> [!CAUTION]
>  É recomendável que você use exceções para cancelar o trabalho paralelo somente quando necessário. Os tokens de cancelamento e `cancel` os métodos do grupo de tarefas são mais eficientes e menos propensos a erros.

Quando você lança uma exceção no corpo de uma função de trabalho que passa para um grupo de tarefas, o tempo de execução armazena essa exceção e realiza o marshaling da exceção para o contexto que aguarda a conclusão do grupo de tarefas. Assim como acontece `cancel` com o método, o tempo de execução descarta todas as tarefas que ainda não foram iniciadas e não aceita novas tarefas.

Esse terceiro exemplo é semelhante ao segundo, exceto que a tarefa `t4` gera uma exceção para cancelar o grupo `tg2`de tarefas. Este exemplo usa um `try` - `catch` bloco para verificar o cancelamento quando o grupo `tg2` de tarefas aguarda a conclusão de suas tarefas filho. Como no primeiro exemplo, isso faz com que o `tg2` grupo de tarefas entre no estado cancelado, mas não cancela `tg1`o grupo de tarefas.

[!code-cpp[concrt-task-tree#4](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_9.cpp)]

Este quarto exemplo usa manipulação de exceção para cancelar toda a árvore de trabalho. O exemplo captura a exceção quando o grupo `tg1` de tarefas aguarda que suas tarefas filho sejam concluídas em vez de quando o grupo `tg2` de tarefas aguarda suas tarefas filho. Assim como o segundo exemplo, isso causa os grupos de tarefas na árvore `tg1` e `tg2`, para inserir o estado cancelado.

[!code-cpp[concrt-task-tree#5](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_10.cpp)]

Como os `task_group::wait` métodos `structured_task_group::wait` e geram quando uma tarefa filho gera uma exceção, você não recebe um valor de retorno deles.

[[Superior](#top)]

##  <a name="algorithms"></a>Cancelando algoritmos paralelos

Algoritmos paralelos na ppl, por exemplo `parallel_for`,, são criados em grupos de tarefas. Portanto, você pode usar muitas das mesmas técnicas para cancelar um algoritmo paralelo.

Os exemplos a seguir ilustram várias maneiras de cancelar um algoritmo paralelo.

O exemplo a seguir usa `run_with_cancellation_token` a função para chamar `parallel_for` o algoritmo. A `run_with_cancellation_token` função usa um token de cancelamento como um argumento e chama a função de trabalho fornecida de forma síncrona. Como os algoritmos paralelos se baseiam em tarefas, eles herdam o token de cancelamento da tarefa pai. Portanto, `parallel_for` o pode responder ao cancelamento.

[!code-cpp[concrt-cancel-parallel-for#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_11.cpp)]

O exemplo a seguir usa o método [Concurrency:: structured_task_group:: run_and_wait](reference/structured-task-group-class.md#run_and_wait) para chamar `parallel_for` o algoritmo. O `structured_task_group::run_and_wait` método aguarda a conclusão da tarefa fornecida. O `structured_task_group` objeto permite que a função de trabalho cancele a tarefa.

[!code-cpp[concrt-task-tree#7](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_12.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
The task group status is: canceled.
```

O exemplo a seguir usa manipulação de exceção para `parallel_for` cancelar um loop. O tempo de execução realiza marshaling da exceção para o contexto de chamada.

[!code-cpp[concrt-task-tree#9](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_13.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Caught 50
```

O exemplo a seguir usa um sinalizador booliano para coordenar o cancelamento em um `parallel_for` loop. Cada tarefa é executada porque este exemplo não usa o `cancel` método ou manipulação de exceção para cancelar o conjunto geral de tarefas. Portanto, essa técnica pode ter mais sobrecarga computacional do que um mecanismo de cancelamento.

[!code-cpp[concrt-task-tree#8](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_14.cpp)]

Cada método de cancelamento tem vantagens em relação às outras. Escolha o método que atenda às suas necessidades específicas.

[[Superior](#top)]

##  <a name="when"></a>Quando não usar o cancelamento

O uso do cancelamento é apropriado quando cada membro de um grupo de tarefas relacionadas pode ser encerrado em tempo hábil. No entanto, há alguns cenários em que o cancelamento pode não ser apropriado para seu aplicativo. Por exemplo, como o cancelamento da tarefa é cooperativo, o conjunto geral de tarefas não será cancelado se qualquer tarefa individual for bloqueada. Por exemplo, se uma tarefa ainda não tiver sido iniciada, mas desbloquear outra tarefa ativa, ela não será iniciada se o grupo de tarefas for cancelado. Isso pode fazer com que o deadlock ocorra em seu aplicativo. Um segundo exemplo de onde o uso do cancelamento pode não ser apropriado é quando uma tarefa é cancelada, mas sua tarefa filho executa uma operação importante, como liberar um recurso. Como o conjunto geral de tarefas é cancelado quando a tarefa pai é cancelada, essa operação não será executada. Para obter um exemplo que ilustra esse ponto, consulte a seção [entender como o cancelamento e o tratamento de exceções afetam a destruição de objetos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) nas práticas recomendadas no tópico da biblioteca de padrões paralelos.

[[Superior](#top)]

## <a name="related-topics"></a>Tópicos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Como: Usar cancelamento para interromper um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)|Mostra como usar o cancelamento para implementar um algoritmo de pesquisa paralela.|
|[Como: Usar tratamento de exceções para interromper um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md)|Mostra como usar a `task_group` classe para gravar um algoritmo de pesquisa para uma estrutura de árvore básica.|
|[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)|Descreve como o tempo de execução manipula exceções que são geradas por grupos de tarefas, tarefas leves e agentes assíncronos e como responder a exceções em seus aplicativos.|
|[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)|Descreve como as tarefas se relacionam a grupos de tarefas e como você pode usar tarefas não estruturadas e estruturadas em seus aplicativos.|
|[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)|Descreve os algoritmos paralelos, que executam simultaneamente o trabalho em coleções de dados|
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Fornece uma visão geral da biblioteca de padrões paralelos.|

## <a name="reference"></a>Referência

[Classe task (Tempo de Execução de Simultaneidade)](../../parallel/concrt/reference/task-class.md)

[Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)

[Classe cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md)

[Classe task_group](reference/task-group-class.md)

[Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)

[Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)
