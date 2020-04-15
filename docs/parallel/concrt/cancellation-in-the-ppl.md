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
ms.openlocfilehash: 27c0ea3cfcf62060800c1c0b034dde7de6357250
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368501"
---
# <a name="cancellation-in-the-ppl"></a>Cancelamento no PPL

Este documento explica o papel do cancelamento na Biblioteca de Padrões Paralelos (PPL), como cancelar trabalhos paralelos e como determinar quando o trabalho paralelo é cancelado.

> [!NOTE]
> O tempo de execução usa o tratamento de exceção para implementar o cancelamento. Não pegue ou manuseie essas exceções em seu código. Além disso, recomendamos que você escreva código seguro de exceção nos órgãos de função para suas tarefas. Por exemplo, você pode usar o padrão *RAII (Resource Acquisition Is Initialization, inicialização* de aquisição de recursos) para garantir que os recursos sejam tratados corretamente quando uma exceção é lançada no corpo de uma tarefa. Para obter um exemplo completo que usa o padrão RAII para limpar um recurso em uma tarefa cancelável, consulte [Passo a Passo: Removendo o trabalho de um segmento de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md).

## <a name="key-points"></a>Pontos Principais

- O cancelamento é cooperativo e envolve a coordenação entre o código que solicita o cancelamento e a tarefa que responde ao cancelamento.

- Quando possível, use tokens de cancelamento para cancelar o trabalho. A [classe de si00:cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md) define um token de cancelamento.

- Ao usar tokens de cancelamento, use o método [simultâneo::cancellation_token_source::cancele](reference/cancellation-token-source-class.md#cancel) para iniciar o cancelamento e a função [de concorrência::cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) para responder ao cancelamento. Use o método [simultu:cancellation_token:is_canceled](reference/cancellation-token-class.md#is_canceled) para verificar se alguma outra tarefa solicitou o cancelamento.

- O cancelamento não ocorre imediatamente. Embora o novo trabalho não seja iniciado se uma tarefa ou grupo de tarefas for cancelado, o trabalho ativo deve verificar e responder ao cancelamento.

- Uma continuação baseada em valor herda o token de cancelamento de sua tarefa antecedente. Uma continuação baseada em tarefas nunca herda o símbolo de sua tarefa antecedente.

- Use o método [simultuável::cancellation_token::nenhum](reference/cancellation-token-class.md#none) método quando `cancellation_token` você chama um construtor ou função que leva um objeto, mas você não quer que a operação seja cancelada. Além disso, se você não passar um token de cancelamento para a [moeda::construtor de tarefas](../../parallel/concrt/reference/task-class.md) ou a função [de concorrência::create_task,](reference/concurrency-namespace-functions.md#create_task) essa tarefa não será cancelada.

## <a name="in-this-document"></a><a name="top"></a>Neste Documento

- [Árvores de Trabalho Paralelas](#trees)

- [Cancelando Tarefas Paralelas](#tasks)

  - [Usando um Token de Cancelamento para Cancelar o Trabalho Paralelo](#tokens)

  - [Usando o Método cancel para Cancelar o Trabalho Paralelo](#cancel)

  - [Usando Exceções para Cancelar Trabalho Paralelo](#exceptions)

- [Cancelando Algoritmos Paralelos](#algorithms)

- [Quando Não Usar Cancelamento](#when)

## <a name="parallel-work-trees"></a><a name="trees"></a>Árvores de Trabalho Paralelas

O PPL usa tarefas e grupos de tarefas para gerenciar tarefas e cálculos de grãos finos. Você pode aninhar grupos de tarefas para formar *árvores* de trabalho paralelo. A ilustração a seguir mostra uma árvore de trabalho paralela. Nesta `tg1` ilustração, `tg2` e representar grupos de tarefas; `t1`, `t2` `t3`, `t4`, `t5` e representam o trabalho que os grupos de tarefas realizam.

![Uma árvore de trabalho paralela](../../parallel/concrt/media/parallelwork_trees.png "Uma árvore de trabalho paralela")

O exemplo a seguir mostra o código necessário para criar a árvore na ilustração. Neste exemplo, `tg1` `tg2` e são [simultâneos::objetos structured_task_group;](../../parallel/concrt/reference/structured-task-group-class.md) `t1`, `t2` `t3`, `t4`e `t5` são [simultâneos::task_handle](../../parallel/concrt/reference/task-handle-class.md) objetos.

[!code-cpp[concrt-task-tree#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_1.cpp)]

Você também pode usar a [classe simultuária::task_group](reference/task-group-class.md) para criar uma árvore de trabalho semelhante. A [classe de tarefas simultuária](../../parallel/concrt/reference/task-class.md) também suporta a noção de uma árvore de trabalho. No entanto, uma `task` árvore é uma árvore de dependência. Em `task` uma árvore, obras futuras são concluídas após o trabalho atual. Em uma árvore de grupo de tarefas, o trabalho interno é concluído antes do trabalho externo. Para obter mais informações sobre as diferenças entre tarefas e grupos de tarefas, consulte [O Paralelismo da Tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).

[[Top](#top)]

## <a name="canceling-parallel-tasks"></a><a name="tasks"></a>Cancelando tarefas paralelas

Existem várias maneiras de cancelar o trabalho paralelo. A maneira preferida é usar um token de cancelamento. Os grupos de tarefas também suportam o método [de concorrência::task_group::cancele](reference/task-group-class.md#cancel) e o método [de simultâneo::structured_task_group:cancele.](reference/structured-task-group-class.md#cancel) A última maneira é lançar uma exceção no corpo de uma função de trabalho de tarefa. Não importa qual método você escolher, entenda que o cancelamento não ocorre imediatamente. Embora o novo trabalho não seja iniciado se uma tarefa ou grupo de tarefas for cancelado, o trabalho ativo deve verificar e responder ao cancelamento.

Para mais exemplos que cancelam tarefas paralelas, consulte [Passo a Passo: Conectando Usando tarefas e solicitações HTTP XML,](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md) [como: Usar cancelamento para quebrar de um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)e [como: usar o tratamento de exceção para quebrar a partir de um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md).

### <a name="using-a-cancellation-token-to-cancel-parallel-work"></a><a name="tokens"></a>Usando um token de cancelamento para cancelar trabalhoparalelo

As `task` `task_group`aulas `structured_task_group` e as classes suportam o cancelamento através do uso de tokens de cancelamento. O PPL define as classes [de concorrência::cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md) e [simultâneo::cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md) para este fim. Quando você usa um token de cancelamento para cancelar o trabalho, o tempo de execução não inicia um novo trabalho que assina esse token. O trabalho que já está ativo pode usar a função de membro [is_canceled](../../parallel/concrt/reference/cancellation-token-class.md#is_canceled) para monitorar o token de cancelamento e parar quando puder.

Para iniciar o cancelamento, ligue para o método [simultuá-lo::cancellation_token_source:cancel.](reference/cancellation-token-source-class.md#cancel) Você responde ao cancelamento desta forma:

- Para `task` objetos, use a função [simultuá-cancel_current_task.: cancel_current_task.](reference/concurrency-namespace-functions.md#cancel_current_task) `cancel_current_task`cancela a tarefa atual e qualquer uma de suas continuações baseadas em valor. (Ele não cancela o *token de* cancelamento associado à tarefa ou às suas continuações.)

- Para grupos de tarefas e algoritmos paralelos, use a função [simultâneo::is_current_task_group_canceling](reference/concurrency-namespace-functions.md#is_current_task_group_canceling) para detectar cancelamento e retornar o mais rápido possível do corpo de tarefas quando essa função retornar **verdadeira**. (Não ligue `cancel_current_task` de um grupo de trabalho.)

O exemplo a seguir mostra o primeiro padrão básico para cancelamento de tarefas. O corpo de tarefas ocasionalmente verifica o cancelamento dentro de um loop.

[!code-cpp[concrt-task-basic-cancellation#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_2.cpp)]

A `cancel_current_task` função é arremessada; portanto, você não precisa retornar explicitamente do loop ou função atual.

> [!TIP]
> Alternativamente, você pode chamar a função de `cancel_current_task` [concorrência::interruption_point](reference/concurrency-namespace-functions.md#interruption_point) em vez de .

É importante ligar `cancel_current_task` quando você responder ao cancelamento porque ele transita a tarefa para o estado cancelado. Se você retornar mais `cancel_current_task`cedo em vez de ligar, a operação passa para o estado concluído e quaisquer continuações baseadas em valor são executadas.

> [!CAUTION]
> Nunca `task_canceled` jogue do seu código. Chame `cancel_current_task` em seu lugar.

Quando uma tarefa termina no estado cancelado, o método [de simultu::task::get](reference/task-class.md#get) lança [simultuá-lo::task_canceled](../../parallel/concrt/reference/task-canceled-class.md). (Por outro lado, [simultâneo::task::espera](reference/task-class.md#wait) retornos [task_status::cancelado](reference/concurrency-namespace-enums.md#task_group_status) e não joga.) O exemplo a seguir ilustra esse comportamento para uma continuação baseada em tarefas. Uma continuação baseada em tarefas é sempre chamada, mesmo quando a tarefa antecedente é cancelada.

[!code-cpp[concrt-task-canceled#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_3.cpp)]

Como as continuações baseadas em valor herdam o símbolo de sua tarefa antecedente, a menos que tenham sido criadas com um token explícito, as continuações entram imediatamente no estado cancelado mesmo quando a tarefa antecedente ainda está sendo executada. Portanto, qualquer exceção que seja lançada pela tarefa antecedente após o cancelamento não é propagada para as tarefas de continuação. O cancelamento sempre substitui o estado da tarefa anterior. O exemplo a seguir se assemelha ao anterior, mas ilustra o comportamento para uma continuação baseada em valor.

[!code-cpp[concrt-task-canceled#2](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_4.cpp)]

> [!CAUTION]
> Se você não passar um token de cancelamento para o `task` construtor ou a função de [concorrência::create_task,](reference/concurrency-namespace-functions.md#create_task) essa tarefa não será cancelada. Além disso, você deve passar o mesmo token de cancelamento para o construtor de quaisquer tarefas aninhadas (ou seja, tarefas que são criadas no corpo de outra tarefa) para cancelar todas as tarefas simultaneamente.

Você pode querer executar código arbitrário quando um token de cancelamento é cancelado. Por exemplo, se o usuário escolher um botão **Cancelar** na interface do usuário para cancelar a operação, você poderá desativar esse botão até que o usuário inicie outra operação. O exemplo a seguir mostra como usar o método [simultuário::cancellation_token::register_callback](reference/cancellation-token-class.md#register_callback) para registrar uma função de retorno de chamada que é executada quando um token de cancelamento é cancelado.

[!code-cpp[concrt-task-cancellation-callback#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_5.cpp)]

O [document Task Parallelism](../../parallel/concrt/task-parallelism-concurrency-runtime.md) explica a diferença entre continuações baseadas em valor e tarefas. Se você não `cancellation_token` fornecer um objeto para uma tarefa de continuação, a continuação herda o token de cancelamento da tarefa antecedente das seguintes maneiras:

- Uma continuação baseada em valor sempre herda o token de cancelamento da tarefa antecedente.

- Uma continuação baseada em tarefas nunca herda o símbolo de cancelamento da tarefa antecedente. A única maneira de tornar uma continuação baseada em tarefas cancelável é passar explicitamente um token de cancelamento.

Esses comportamentos não são afetados por uma tarefa defeituosa (ou seja, uma que abre uma exceção). Neste caso, uma continuação baseada em valor é cancelada; uma continuação baseada em tarefas não é cancelada.

> [!CAUTION]
> Uma tarefa criada em outra tarefa (em outras palavras, uma tarefa aninhada) não herda o símbolo de cancelamento da tarefa pai. Apenas uma continuação baseada em valor herda o token de cancelamento de sua tarefa antecedente.

> [!TIP]
> Use o método [simultâneo::cancellation_token::nenhum](reference/cancellation-token-class.md#none) método `cancellation_token` quando você chama um construtor ou função que leva um objeto e você não quer que a operação seja cancelada.

Você também pode fornecer um token de `task_group` `structured_task_group` cancelamento para o construtor de um ou objeto. Um aspecto importante disso é que grupos de tarefas infantis herdam esse token de cancelamento. Para um exemplo que demonstra esse conceito usando a função `parallel_for` [simultâneo::run_with_cancellation_token](reference/concurrency-namespace-functions.md#run_with_cancellation_token) para executar para chamar, consulte [Cancelando Algoritmos Paralelos](#algorithms) mais tarde neste documento.

[[Top](#top)]

#### <a name="cancellation-tokens-and-task-composition"></a>Tokens de Cancelamento e Composição da Tarefa

As funções [de concorrência::when_all](reference/concurrency-namespace-functions.md#when_all) e [concomção::when_any](reference/concurrency-namespace-functions.md#when_all) funções podem ajudá-lo a compor várias tarefas para implementar padrões comuns. Esta seção descreve como essas funções funcionam com tokens de cancelamento.

Quando você fornece um token `when_all` `when_any` de cancelamento para a função e a função, essa função só é cancelada quando esse token de cancelamento é cancelado ou quando uma das tarefas participantes termina em um estado cancelado ou lança uma exceção.

A `when_all` função herda o token de cancelamento de cada tarefa que compõe a operação geral quando você não fornece um token de cancelamento a ele. A tarefa de `when_all` que é devolvida é cancelada quando qualquer um desses tokens é cancelado e pelo menos uma das tarefas participantes ainda não foi iniciada ou está sendo executado. Um comportamento semelhante ocorre quando uma das tarefas abre uma `when_all` exceção - a tarefa de que é devolvida é imediatamente cancelada com essa exceção.

O tempo de execução escolhe o token de `when_any` cancelamento para a tarefa que é retornada da função quando essa tarefa for concluída. Se nenhuma das tarefas participantes terminar em um estado concluído e uma ou mais das tarefas `when_any` for uma exceção, uma das tarefas que jogou é escolhida para completar o token e seu token é escolhido como o token para a tarefa final. Se mais de uma tarefa for concluída, a tarefa `when_any` que é devolvida da tarefa termina em um estado completo. O tempo de `when_any` execução tenta escolher uma tarefa concluída cujo token não é cancelado no momento da conclusão para que a tarefa de que é devolvida não seja imediatamente cancelada, embora outras tarefas executoras possam ser concluídas em um momento posterior.

[[Top](#top)]

### <a name="using-the-cancel-method-to-cancel-parallel-work"></a><a name="cancel"></a>Usando o método de cancelamento para cancelar trabalho paralelo

Os [métodos de simultâneo::task_group::cancele::structured_task_group:cancele](reference/task-group-class.md#cancel) um grupo de tarefas para o estado cancelado. [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) Depois de `cancel`ligar, o grupo de tarefas não inicia tarefas futuras. Os `cancel` métodos podem ser chamados por múltiplas tarefas infantis. Uma tarefa cancelada causa a [concorrência::task_group::wait](reference/task-group-class.md#wait) e [simultâneo::structured_task_group::wait](reference/structured-task-group-class.md#wait) methods to return [concurrency::cancelou](reference/concurrency-namespace-enums.md#task_group_status).

Se um grupo de tarefas for cancelado, as chamadas de cada tarefa filho no tempo de execução podem desencadear um *ponto de interrupção,* o que faz com que o tempo de execução seja jogado e pegue um tipo de exceção interna para cancelar tarefas ativas. O Tempo de Execução de Concorrência não define pontos de interrupção específicos; eles podem ocorrer em qualquer chamada para o tempo de execução. O tempo de execução deve lidar com as exceções que ele lança para realizar o cancelamento. Portanto, não manuseie exceções desconhecidas no corpo de uma tarefa.

Se uma tarefa infantil realizar uma operação demorada e não ligar para o tempo de execução, ela deve verificar periodicamente se há cancelamento e saída em tempo hábil. O exemplo a seguir mostra uma maneira de determinar quando o trabalho é cancelado. A `t4` tarefa cancela o grupo de tarefas pai quando encontra um erro. A `t5` tarefa ocasionalmente chama o `structured_task_group::is_canceling` método para verificar o cancelamento. Se o grupo de tarefas-pai for cancelado, a tarefa `t5` imprime uma mensagem e sai.

[!code-cpp[concrt-task-tree#6](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_6.cpp)]

Este exemplo verifica o cancelamento<sup>th</sup> em cada 100ª iteração do loop de tarefas. A frequência com que você verifica o cancelamento depende da quantidade de trabalho que sua tarefa realiza e da rapidez com que você precisa de tarefas para responder ao cancelamento.

Se você não tiver acesso ao objeto do grupo de tarefas pai, chame a função [de concorrência::is_current_task_group_canceling](reference/concurrency-namespace-functions.md#is_current_task_group_canceling) para determinar se o grupo de tarefas-mãe foi cancelado.

O `cancel` método só afeta tarefas infantis. Por exemplo, se você `tg1` cancelar o grupo de tarefas na ilustração`t1` `t2`da `t3` `t4`árvore de trabalho paralela, todas as tarefas na árvore ( , , , e `t5`) são afetadas. Se você cancelar o grupo `tg2`de `t4` tarefas aninhado, apenas tarefas e `t5` serão afetados.

Quando você `cancel` chama o método, todos os grupos de tarefas infantis também são cancelados. No entanto, o cancelamento não afeta nenhum dos pais do grupo de trabalho em uma árvore de trabalho paralela. Os exemplos a seguir mostram isso construindo a ilustração da árvore de trabalho paralela.

O primeiro desses exemplos cria uma função `t4`de trabalho para a `tg2`tarefa , que é uma criança do grupo de tarefas . A função de `work` trabalho chama a função em um loop. Se alguma `work` chamada falhar, a tarefa cancelará seu grupo de tarefas-mãe. Isso faz `tg2` com que o grupo de tarefas entre `tg1`no estado cancelado, mas não cancela o grupo de tarefas .

[!code-cpp[concrt-task-tree#2](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_7.cpp)]

Este segundo exemplo se assemelha ao primeiro, exceto `tg1`que a tarefa cancela o grupo de tarefas . Isso afeta todas as tarefas `t3`na `t4`árvore `t5`( ,`t1` `t2`, e ).

[!code-cpp[concrt-task-tree#3](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_8.cpp)]

A `structured_task_group` classe não é segura para fios. Portanto, uma tarefa infantil que chama `structured_task_group` um método de seu objeto pai produz comportamento não especificado. As exceções a esta `structured_task_group::cancel` regra são os métodos e [a simultâneos::structured_task_group::is_canceling.](reference/structured-task-group-class.md#is_canceling) Uma tarefa filho pode chamar esses métodos para cancelar o grupo de trabalho dos pais e verificar se há cancelamento.

> [!CAUTION]
> Embora você possa usar um token de cancelamento para cancelar o trabalho `task` que é executado `task_group::cancel` por `structured_task_group::cancel` um grupo `task` de tarefas que é executado como filho de um objeto, você não pode usar ou métodos para cancelar objetos executados em um grupo de tarefas.

[[Top](#top)]

### <a name="using-exceptions-to-cancel-parallel-work"></a><a name="exceptions"></a>Usando exceções para cancelar trabalhos paralelos

O uso de tokens `cancel` de cancelamento e o método são mais eficientes do que o manuseio de exceções no cancelamento de uma árvore de trabalho paralela. Os tokens `cancel` de cancelamento e o método cancelam uma tarefa e quaisquer tarefas de criança de forma de cima para baixo. Por outro lado, o tratamento de exceções funciona de forma de baixo para cima e deve cancelar cada grupo de trabalho infantil independentemente, pois a exceção se propaga para cima. O tópico [Manipulação de Exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md) explica como o Tempo de Execução de Concurrency usa exceções para comunicar erros. No entanto, nem todas as exceções indicam um erro. Por exemplo, um algoritmo de pesquisa pode cancelar sua tarefa associada quando encontrar o resultado. No entanto, como mencionado anteriormente, o `cancel` manuseio de exceções é menos eficiente do que usar o método para cancelar trabalhos paralelos.

> [!CAUTION]
> Recomendamos que você use exceções para cancelar trabalhos paralelos somente quando necessário. Os tokens de `cancel` cancelamento e os métodos do grupo de tarefas são mais eficientes e menos propensos a erros.

Quando você lança uma exceção no corpo de uma função de trabalho que você passa para um grupo de tarefas, o tempo de execução armazena essa exceção e coloca a exceção ao contexto que espera o grupo de tarefas terminar. Assim como `cancel` no método, o tempo de execução descarta quaisquer tarefas que ainda não começaram e não aceita novas tarefas.

Este terceiro exemplo se assemelha ao `t4` segundo, exceto que `tg2`a tarefa abre uma exceção para cancelar o grupo de tarefas . Este exemplo `try` - `catch` usa um bloco para verificar `tg2` o cancelamento quando o grupo de trabalho espera que suas tarefas filho sejam concluídas. Como o primeiro exemplo, isso `tg2` faz com que o grupo de tarefas entre no estado cancelado, mas não cancela o grupo `tg1`de tarefas .

[!code-cpp[concrt-task-tree#4](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_9.cpp)]

Este quarto exemplo usa o manuseio de exceção para cancelar toda a árvore de trabalho. O exemplo captura a `tg1` exceção quando o grupo de tarefas `tg2` espera que suas tarefas filho sejam concluídas em vez de quando o grupo de tarefas espera por suas tarefas filho. Como o segundo exemplo, isso faz com `tg1` `tg2`que ambos os grupos de tarefas na árvore, e , para entrar no estado cancelado.

[!code-cpp[concrt-task-tree#5](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_10.cpp)]

Como `task_group::wait` os `structured_task_group::wait` métodos e métodos são jogados quando uma tarefa infantil abre uma exceção, você não recebe um valor de retorno deles.

[[Top](#top)]

## <a name="canceling-parallel-algorithms"></a><a name="algorithms"></a>Cancelando algoritmos paralelos

Algoritmos paralelos no PPL, `parallel_for`por exemplo, se baseiam em grupos de tarefas. Portanto, você pode usar muitas das mesmas técnicas para cancelar um algoritmo paralelo.

Os exemplos a seguir ilustram várias maneiras de cancelar um algoritmo paralelo.

O exemplo a `run_with_cancellation_token` seguir usa `parallel_for` a função para chamar o algoritmo. A `run_with_cancellation_token` função toma um token de cancelamento como argumento e chama a função de trabalho fornecida de forma sincronizada. Como algoritmos paralelos são construídos sobre tarefas, eles herdam o símbolo de cancelamento da tarefa pai. Portanto, `parallel_for` pode responder ao cancelamento.

[!code-cpp[concrt-cancel-parallel-for#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_11.cpp)]

O exemplo a seguir usa o método [simultâneo::structured_task_group::run_and_wait](reference/structured-task-group-class.md#run_and_wait) para chamar o `parallel_for` algoritmo. O `structured_task_group::run_and_wait` método aguarda o término da tarefa fornecida. O `structured_task_group` objeto permite que a função de trabalho cancele a tarefa.

[!code-cpp[concrt-task-tree#7](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_12.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
The task group status is: canceled.
```

O exemplo a seguir usa `parallel_for` o manuseio de exceção para cancelar um loop. O tempo de execução é a exceção ao contexto de chamada.

[!code-cpp[concrt-task-tree#9](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_13.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Caught 50
```

O exemplo a seguir usa uma bandeira `parallel_for` Boolean para coordenar o cancelamento em um loop. Cada tarefa é executada porque `cancel` este exemplo não usa o método ou o tratamento de exceção para cancelar o conjunto geral de tarefas. Portanto, essa técnica pode ter mais sobrecarga computacional do que um mecanismo de cancelamento.

[!code-cpp[concrt-task-tree#8](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_14.cpp)]

Cada método de cancelamento tem vantagens sobre os outros. Escolha o método que se adeque às suas necessidades específicas.

[[Top](#top)]

## <a name="when-not-to-use-cancellation"></a><a name="when"></a>Quando não usar cancelamento

O uso do cancelamento é apropriado quando cada membro de um grupo de tarefas relacionadas pode sair em tempo hábil. No entanto, existem alguns cenários em que o cancelamento pode não ser apropriado para sua aplicação. Por exemplo, como o cancelamento de tarefas é cooperativo, o conjunto geral de tarefas não será cancelado se qualquer tarefa individual for bloqueada. Por exemplo, se uma tarefa ainda não foi iniciada, mas ela desbloqueia outra tarefa ativa, ela não será iniciada se o grupo de tarefas for cancelado. Isso pode causar impasse em sua aplicação. Um segundo exemplo de onde o uso do cancelamento pode não ser apropriado é quando uma tarefa é cancelada, mas sua tarefa filho realiza uma operação importante, como liberar um recurso. Como o conjunto geral de tarefas é cancelado quando a tarefa pai é cancelada, essa operação não será executada. Para um exemplo que ilustra este ponto, consulte a seção Entenda como o cancelamento e o tratamento de exceções afetam a [destruição de objetos](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) no tópico Práticas recomendadas no tópico Biblioteca de Padrões Paralelos.

[[Top](#top)]

## <a name="related-topics"></a>Tópicos Relacionados

|Title|Descrição|
|-----------|-----------------|
|[Como usar cancelamento para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)|Mostra como usar o cancelamento para implementar um algoritmo de pesquisa paralelo.|
|[Como usar tratamento de exceções para parar um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md)|Mostra como usar `task_group` a classe para escrever um algoritmo de pesquisa para uma estrutura básica de árvore.|
|[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)|Descreve como o tempo de execução lida com exceções que são lançadas por grupos de tarefas, tarefas leves e agentes assíncronos e como responder a exceções em seus aplicativos.|
|[Paralelismo de Tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)|Descreve como as tarefas se relacionam com grupos de tarefas e como você pode usar tarefas não estruturadas e estruturadas em seus aplicativos.|
|[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)|Descreve os algoritmos paralelos, que realizam simultaneamente trabalhos em coletas de dados|
|[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Fornece uma visão geral da Biblioteca de Padrões Paralelos.|

## <a name="reference"></a>Referência

[classe de tarefa (Tempo de execução de concorrência)](../../parallel/concrt/reference/task-class.md)

[cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)

[cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md)

[Classe task_group](reference/task-group-class.md)

[Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)

[função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)
