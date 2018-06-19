---
title: Cancelamento no PPL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- parallel algorithms, canceling [Concurrency Runtime]
- canceling parallel algorithms [Concurrency Runtime]
- parallel tasks, canceling [Concurrency Runtime]
- cancellation in the PPL
- parallel work trees [Concurrency Runtime]
- canceling parallel tasks [Concurrency Runtime]
ms.assetid: baaef417-b2f9-470e-b8bd-9ed890725b35
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5a0c74ad5877a5b490414d96bf0f13b32309a21a
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33694830"
---
# <a name="cancellation-in-the-ppl"></a>Cancelamento no PPL
Este documento explica a função de cancelamento na biblioteca de padrões paralelos (PPL), como cancelar o trabalho paralelo e como determinar quando o trabalho paralelo foi cancelado.  
  
> [!NOTE]
>  O tempo de execução usa o tratamento de exceção para implementar o cancelamento. Não catch ou tratar essas exceções em seu código. Além disso, recomendamos que você escreva o código de exceção seguros nos corpos de função para suas tarefas. Por exemplo, você pode usar o *recurso aquisição é inicialização* padrão (RAII) para garantir que os recursos são tratados corretamente quando uma exceção é lançada no corpo de uma tarefa. Para obter um exemplo completo que usa o padrão RAII para limpar um recurso em uma tarefa pode ser cancelado, consulte [passo a passo: Removendo trabalho de um Thread de Interface do usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md).  
  
## <a name="key-points"></a>Pontos-chave  
  
-   Cancelamento é cooperativo e envolve coordenação entre o código que solicita o cancelamento e a tarefa responde ao cancelamento.  
  
-   Quando possível, use tokens de cancelamento para cancelar o trabalho. O [Concurrency](../../parallel/concrt/reference/cancellation-token-class.md) classe define um token de cancelamento.  
  

-   Quando você usa os tokens de cancelamento, use o [concurrency::cancellation_token_source::cancel](reference/cancellation-token-source-class.md#cancel) método para iniciar o cancelamento e a [concurrency::cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) função para responder a cancelamento. Use o [concurrency::cancellation_token::is_canceled](reference/cancellation-token-class.md#is_canceled) método para verificar se qualquer outra tarefa solicitou o cancelamento.
  
-   O cancelamento não ocorre imediatamente. Embora novos trabalhos não foi iniciado se uma tarefa ou um grupo de tarefas é cancelado, trabalho ativo deve verificar e responder ao cancelamento.  
  
-   Uma continuação de acordo com o valor herda o token de cancelamento da tarefa antecedente. Uma continuação baseado em tarefa nunca herda o token de sua tarefa antecedente.  
  
-   Use o [Concurrency:: none](reference/cancellation-token-class.md#none) método quando você chamar um construtor ou função que usa um `cancellation_token` objeto, mas você não deseja que a operação pode ser cancelado. Além disso, se você passar um token de cancelamento para o [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) construtor ou [concurrency::create_task](reference/concurrency-namespace-functions.md#create_task) função, essa tarefa não é possível cancelar.  


  
##  <a name="top"></a> Neste documento  
  
- [Árvores de trabalho paralelos](#trees)  
  
- [Cancelando tarefas paralelas](#tasks)  
  
    - [Usando um Token de cancelamento para cancelar o trabalho paralelo](#tokens)  
  
    - [Usando o método para Cancelar trabalho paralelos de cancelamento](#cancel)  
  
    - [Usando exceções para cancelar o trabalho paralelo](#exceptions)  
  
- [Cancelando algoritmos paralelos](#algorithms)  
  
- [Quando não usar o cancelamento](#when)  
  
##  <a name="trees"></a> Árvores de trabalho paralelos  
 PPL usa grupos de tarefas e tarefas para gerenciar tarefas refinadas e cálculos. Você pode aninhar grupos de tarefas para o formulário *árvores* de trabalho paralelo. A ilustração a seguir mostra uma árvore de trabalho paralelos. Nesta ilustração, `tg1` e `tg2` representar grupos de tarefas; `t1`, `t2`, `t3`, `t4`, e `t5` representar o trabalho que executam os grupos de tarefas.  
  
 ![Uma árvore de trabalho paralelas](../../parallel/concrt/media/parallelwork_trees.png "parallelwork_trees")  
  
 O exemplo a seguir mostra o código que é necessário para criar a árvore na ilustração. Neste exemplo, `tg1` e `tg2` são [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objetos; `t1`, `t2`, `t3`, `t4`, e `t5` são [concurrency::task_handle](../../parallel/concrt/reference/task-handle-class.md) objetos.  
  
 [!code-cpp[concrt-task-tree#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_1.cpp)]  
  
 Você também pode usar o [concurrency::task_group](reference/task-group-class.md) classe para criar uma árvore de trabalho semelhantes. O [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) classe também oferece suporte a noção de uma árvore de trabalho. No entanto, um `task` árvore é uma árvore de dependência. Em um `task` conclui o works futuras árvore, após o trabalho atual. Em uma árvore de grupo de tarefa trabalho interno é concluída antes de trabalho externo. Para obter mais informações sobre as diferenças entre grupos de tarefas e tarefas, consulte [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 [[Superior](#top)]  
  
##  <a name="tasks"></a> Cancelando tarefas paralelas  

 Há várias maneiras de cancelar o trabalho paralelo. O modo preferido é usar um token de cancelamento. Grupos de tarefas também suporte a [concurrency::task_group::cancel](reference/task-group-class.md#cancel) método e o [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) método. A forma final é lançar uma exceção no corpo de uma função de trabalho da tarefa. Não importa qual método de sua escolha, entenda o cancelamento não ocorre imediatamente. Embora novos trabalhos não foi iniciado se uma tarefa ou um grupo de tarefas é cancelado, trabalho ativo deve verificar e responder ao cancelamento.  

  
 Para obter mais exemplos que Cancelar tarefas paralelas, consulte [passo a passo: conectando usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md), [como: cancelamento de uso para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md), e [como: Use Tratamento de exceções para quebra de um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md).  
  
###  <a name="tokens"></a> Usando um Token de cancelamento para cancelar o trabalho paralelo  
 O `task`, `task_group`, e `structured_task_group` classes de suporte ao cancelamento com o uso de tokens de cancelamento. PPL define o [Concurrency:: cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md) e [Concurrency](../../parallel/concrt/reference/cancellation-token-class.md) classes para essa finalidade. Quando você usa um token de cancelamento para cancelar o trabalho, o tempo de execução não inicia um novo trabalho assina esse token. Um trabalho que já está ativo pode usar o [is_canceled](../../parallel/concrt/reference/cancellation-token-class.md#is_canceled) a função de membro para monitorar o token de cancelamento e parar quando possível.  
  

 Para iniciar o cancelamento, chame o [concurrency::cancellation_token_source::cancel](reference/cancellation-token-source-class.md#cancel) método. Responder ao cancelamento das seguintes maneiras:  
  
-   Para `task` objetos, use o [concurrency::cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) função. `cancel_current_task` Cancela a tarefa atual e qualquer um de seus continuações baseada em valor. (Não cancelará o cancelamento *token* que está associado com a tarefa ou seus continuações.)  
  
-   Para grupos de tarefas e os algoritmos paralelos, use o [concurrency::is_current_task_group_canceling](reference/concurrency-namespace-functions.md#is_current_task_group_canceling) função para detectar o cancelamento e retornar logo do corpo da tarefa quando esta função retorna `true`. (Não chame `cancel_current_task` de um grupo de tarefas.)  

  
 O exemplo a seguir mostra o padrão básico primeiro para o cancelamento da tarefa. O corpo da tarefa ocasionalmente verifica o cancelamento dentro de um loop.  
  
 [!code-cpp[concrt-task-basic-cancellation#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_2.cpp)]  
  
 O `cancel_current_task` função lança; portanto, você não precisa retornar explicitamente o loop atual ou a função.  
  
> [!TIP]

>  Como alternativa, você pode chamar o [concurrency::interruption_point](reference/concurrency-namespace-functions.md#interruption_point) de função em vez de `cancel_current_task`.  
  
 É importante chamar `cancel_current_task` quando você responder ao cancelamento porque ela faz a transição a tarefa para o estado cancelado. Se você retornar logo em vez de chamar `cancel_current_task`, a operação faz a transição para o estado concluído e quaisquer continuações baseada em valor são executadas.  
  
> [!CAUTION]
>  Nunca lançam `task_canceled` do seu código. Chame `cancel_current_task` em seu lugar.  
  
 Quando uma tarefa termina no estado cancelado, o [concurrency::task::get](reference/task-class.md#get) método lança [concurrency::task_canceled](../../parallel/concrt/reference/task-canceled-class.md). (Por outro lado, [concurrency::task::wait](reference/task-class.md#wait) retorna [task_status::canceled](reference/concurrency-namespace-enums.md#task_group_status) e não gerará.) O exemplo a seguir ilustra esse comportamento para uma continuação de tarefas. Uma continuação de tarefas sempre é chamada, mesmo quando a tarefa antecedente é cancelada.  

  
 [!code-cpp[concrt-task-canceled#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_3.cpp)]  
  
 Como baseada em valor continuações herdam o token de sua tarefa antecedente, a menos que eles foram criados com um token explícito, continuações inserem imediatamente o estado cancelado mesmo quando a tarefa antecedente ainda está em execução. Portanto, qualquer exceção que é gerada pela tarefa antecedente após o cancelamento não é propagada para as tarefas de continuação. Cancelamento sempre substitui o estado da tarefa antecedente. O exemplo a seguir é semelhante a anterior, mas ilustra o comportamento para uma continuação de acordo com o valor.  
  
 [!code-cpp[concrt-task-canceled#2](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_4.cpp)]  
  
> [!CAUTION]

>  Se você não passar um token de cancelamento para o `task` construtor ou [concurrency::create_task](reference/concurrency-namespace-functions.md#create_task) função, essa tarefa não é possível cancelar. Além disso, você deve passar o mesmo token de cancelamento para o construtor de quaisquer tarefas aninhadas (isto é, tarefas que são criadas no corpo da outra tarefa) para cancelar todas as tarefas simultaneamente.  
  
 Você talvez queira executar um código arbitrário quando um token de cancelamento é cancelado. Por exemplo, se o usuário escolhe um **Cancelar** botão na interface do usuário para cancelar a operação, você pode desabilitar o botão até que o usuário inicie outra operação. O exemplo a seguir mostra como usar o [concurrency::cancellation_token::register_callback](reference/cancellation-token-class.md#register_callback) método para registrar uma função de retorno de chamada que é executado quando um token de cancelamento é cancelado.  

  
 [!code-cpp[concrt-task-cancellation-callback#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_5.cpp)]  
  
 O documento [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md) explica a diferença entre continuações baseados em tarefas e valor. Se você não fornecer um `cancellation_token` do objeto para uma tarefa de continuação a continuação herda o token de cancelamento da tarefa antecedente das seguintes maneiras:  
  
-   Uma continuação de acordo com o valor sempre herda o token de cancelamento da tarefa antecedente.  
  
-   Uma continuação baseado em tarefa nunca herda o token de cancelamento da tarefa antecedente. É a única maneira de fazer uma continuação baseado em Tarefa cancelável explicitamente passe um token de cancelamento.  
  
 Esses comportamentos não são afetados por uma tarefa com falha (ou seja, uma que gera uma exceção). Nesse caso, uma continuação de acordo com o valor será cancelada; uma continuação de tarefas não foi cancelada.  
  
> [!CAUTION]
>  Uma tarefa que é criada em outra tarefa (em outras palavras, uma tarefa aninhada) não herdam o token de cancelamento da tarefa pai. Somente uma continuação de acordo com o valor herda o token de cancelamento da tarefa antecedente.  
  
> [!TIP]

>  Use o [Concurrency:: none](reference/cancellation-token-class.md#none) método quando você chamar um construtor ou função que usa um `cancellation_token` objeto e você não desejar que a operação pode ser cancelado.  
  
 Você também pode fornecer um token de cancelamento para o construtor de um `task_group` ou `structured_task_group` objeto. Um aspecto importante é que os grupos de tarefas filho herdam esse token de cancelamento. Para obter um exemplo que demonstra esse conceito usando o [concurrency::run_with_cancellation_token](reference/concurrency-namespace-functions.md#run_with_cancellation_token) função a ser executada para chamar `parallel_for`, consulte [Cancelando algoritmos paralelos](#algorithms) mais adiante neste documento.  
  
 [[Superior](#top)]  
  
#### <a name="cancellation-tokens-and-task-composition"></a>Tokens de Cancelamento e Composição da Tarefa  

 O [concurrency:: HYPERLINK "http://msdn.microsoft.com/library/system.threading.tasks.task.whenall(v=VS.110).aspx" when_all](reference/concurrency-namespace-functions.md#when_all) e [concurrency::when_any](reference/concurrency-namespace-functions.md#when_all) funções podem ajudá-lo a compor várias tarefas para implementar os padrões comuns. Esta seção descreve como funcionam essas funções com tokens de cancelamento.  
  
 Quando você fornecer um token de cancelamento como o `when_all` e `when_any` de função, que a função cancela somente quando esse token de cancelamento é cancelado ou quando um participante termina em um estado de cancelamento de tarefas ou gera uma exceção.  
  
 O `when_all` função herda o token de cancelamento de cada tarefa que compõe a operação total quando você não fornecer um token de cancelamento a ele. A tarefa retornada de `when_all` é cancelada quando qualquer esses tokens são cancelados e pelo menos uma das tarefas de participante ainda não foi iniciado ou está em execução. Um comportamento semelhante ocorre quando uma das tarefas lança uma exceção - a tarefa retornada de `when_all` imediatamente é cancelada com essa exceção.  
  
 O tempo de execução escolhe o token de cancelamento para a tarefa retornada de `when_any` função quando essa tarefa é concluída. Se nenhuma das tarefas participantes terminar em um estado concluído e uma ou mais das tarefas lança uma exceção, uma das tarefas que lançou é escolhida para concluir o `when_any` e seu token é escolhido como o token para a tarefa final. Se mais de uma tarefa termina no concluído de estado, a tarefa retornada de `when_any` tarefa termina em um estado concluído. O tempo de execução tenta selecionar tarefas concluídas cujo token não for cancelado no momento da conclusão, para que a tarefa que é retornado de `when_any` não for cancelado imediatamente, embora outras tarefas em execução podem ser concluída em um momento posterior.  
  
 [[Superior](#top)]  
  
###  <a name="cancel"></a> Usando o método para Cancelar trabalho paralelos de cancelamento  

 O [concurrency::task_group::cancel](reference/task-group-class.md#cancel) e [concurrency::structured_task_group::cancel](reference/structured-task-group-class.md#cancel) métodos definir um grupo de tarefas para o estado cancelado. Depois de chamar `cancel`, o grupo de tarefas não iniciar tarefas futuras. O `cancel` métodos podem ser chamados por várias tarefas filho. Faz com que uma tarefa cancelada a [concurrency::task_group::wait](reference/task-group-class.md#wait) e [concurrency::structured_task_group::wait](reference/structured-task-group-class.md#wait) métodos para retornar [concurrency::canceled](reference/concurrency-namespace-enums.md#task_group_status).  

  
 Se um grupo de tarefas for cancelado, chamadas de cada tarefa filho em tempo de execução podem disparar um *ponto de interrupção*, que faz com que o tempo de execução gerar e capturar um tipo de exceção interna para cancelar tarefas ativas. O tempo de execução de simultaneidade não definir pontos de interrupção específico. eles podem ocorrer em qualquer chamada para o tempo de execução. O tempo de execução deve tratar as exceções que ele gera para executar o cancelamento. Portanto, não lidar com exceções desconhecidas no corpo de uma tarefa.  
  
 Se uma tarefa filho executa uma operação demorada e não pode ser chamado em tempo de execução, ele deve verificar o cancelamento periodicamente e sair de maneira oportuna. O exemplo a seguir mostra uma maneira de determinar quando o trabalho foi cancelado. Tarefa `t4` cancela o grupo de tarefas pai quando encontra um erro. Tarefa `t5` ocasionalmente, chama o `structured_task_group::is_canceling` método para verificar o cancelamento. Se o grupo de tarefas pai for cancelado, a tarefa `t5` imprime uma mensagem e será encerrado.  
  
 [!code-cpp[concrt-task-tree#6](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_6.cpp)]  
  
 Este exemplo verifica o cancelamento em cada 100<sup>th</sup> iteração do loop de tarefa. A frequência com que você verificar o cancelamento depende da quantidade de trabalho que executa a tarefa e rapidez você precisa para responder ao cancelamento de tarefas.  
  
 Se você não tiver acesso ao objeto de grupo de tarefa pai, chame o [concurrency::is_current_task_group_canceling](reference/concurrency-namespace-functions.md#is_current_task_group_canceling) função para determinar se o grupo de tarefas do pai será cancelado.  

  
 O `cancel` método afeta somente tarefas filho. Por exemplo, se você cancelar o grupo de tarefas `tg1` na ilustração da árvore de trabalho paralelas, todas as tarefas na árvore (`t1`, `t2`, `t3`, `t4`, e `t5`) são afetadas. Se você cancelar o grupo de tarefas aninhadas, `tg2`, apenas as tarefas `t4` e `t5` são afetados.  
  
 Quando você chama o `cancel` método, todas as tarefas filho grupos também são cancelados. No entanto, o cancelamento não afeta pais do grupo de tarefas em uma árvore de trabalho paralelos. Os exemplos a seguir mostram isso criando na ilustração de árvore de trabalho paralelos.  
  
 O primeiro desses exemplos cria uma função de trabalho para a tarefa `t4`, que é um filho do grupo de tarefas `tg2`. A função de trabalho chama a função `work` em um loop. Se qualquer chamada para `work` falhar, a tarefa cancela o respectivo grupo pai de tarefa. Isso faz com que o grupo de tarefas `tg2` inserir o estado cancelado, mas não cancelar o grupo de tarefas `tg1`.  
  
 [!code-cpp[concrt-task-tree#2](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_7.cpp)]  
  
 Este segundo exemplo semelhante ao primeiro, exceto que a tarefa cancela o grupo de tarefas `tg1`. Isso afeta todas as tarefas na árvore (`t1`, `t2`, `t3`, `t4`, e `t5`).  
  
 [!code-cpp[concrt-task-tree#3](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_8.cpp)]  
  
 O `structured_task_group` classe não é thread-safe. Portanto, uma tarefa filho que chama um método de seu pai `structured_task_group` objeto produz o comportamento não especificado. As exceções a essa regra são o `structured_task_group::cancel` e [concurrency::structured_task_group::is_canceling](reference/structured-task-group-class.md#is_canceling) métodos. Uma tarefa filho pode chamar esses métodos para cancelar o grupo de tarefas pai e verificar o cancelamento.  

 
> [!CAUTION]
>  Embora você possa usar um token de cancelamento para cancelar o trabalho é executado por um grupo de tarefas é executado como um filho de um `task` do objeto, você não pode usar o `task_group::cancel` ou `structured_task_group::cancel` métodos Cancelar `task` objetos que são executados em um grupo de tarefas.  
  
 [[Superior](#top)]  
  
###  <a name="exceptions"></a> Usando exceções para cancelar o trabalho paralelo  
 O uso de tokens de cancelamento e a `cancel` método são mais eficientes do que no cancelamento de uma árvore de trabalho paralelos de tratamento de exceção. Tokens de cancelamento e a `cancel` método Cancelar uma tarefa e quaisquer tarefas filho de uma maneira de cima para baixo. Por outro lado, a manipulação de exceção funciona de forma ascendente e deve cancelar a cada grupo de tarefas filho independentemente como a exceção for propagada para cima. O tópico [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md) explica como o tempo de execução de simultaneidade usa exceções para comunicar erros. No entanto, nem todas as exceções indicam um erro. Por exemplo, um algoritmo de pesquisa pode cancelar a tarefa associada ao encontrar o resultado. No entanto, conforme mencionado anteriormente, manipulação de exceção é menos eficiente do que usando o `cancel` método para cancelar o trabalho paralelo.  
  
> [!CAUTION]
>  É recomendável que você use exceções para cancelar o trabalho paralelo somente quando necessário. O grupo de tarefas e tokens de cancelamento `cancel` métodos são mais eficientes e menos propenso a erro.  
  
 Quando você gera uma exceção no corpo de uma função de trabalho que você passa para um grupo de tarefas, o tempo de execução armazena essa exceção e empacota a exceção para o contexto de espera para o grupo de tarefas concluir. Assim como acontece com o `cancel` método, o tempo de execução descarta quaisquer tarefas que ainda não foram iniciados e não aceitam novas tarefas.  
  
 Este exemplo terceiro é semelhante o um segundo, com exceção de tarefa `t4` lança uma exceção para cancelar o grupo de tarefas `tg2`. Este exemplo usa um `try` - `catch` bloco para verificar o cancelamento quando o grupo de tarefas `tg2` aguarda para suas tarefas filho sejam concluídas. Como o primeiro exemplo, isso faz com que o grupo de tarefas `tg2` inserir o estado cancelado, mas não cancelar o grupo de tarefas `tg1`.  
  
 [!code-cpp[concrt-task-tree#4](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_9.cpp)]  
  
 Este exemplo quarto usa tratamento de exceção para cancelar a árvore de trabalho inteira. O exemplo captura a exceção quando a tarefa grupo `tg1` esperas para suas tarefas filho concluir em vez de ao grupo de tarefas `tg2` aguarda até que suas tarefas filho. Como o segundo exemplo, isso faz com que ambos os grupos de tarefas na árvore de `tg1` e `tg2`, entrar no estado cancelado.  
  
 [!code-cpp[concrt-task-tree#5](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_10.cpp)]  
  
 Porque o `task_group::wait` e `structured_task_group::wait` métodos lançam quando uma tarefa filho lança uma exceção, você não recebe um valor de retorno da parte deles.  
  
 [[Superior](#top)]  
  
##  <a name="algorithms"></a> Cancelando algoritmos paralelos  
 Paralelo algoritmos no PPL, por exemplo, `parallel_for`, criar grupos de tarefas. Portanto, você pode usar muitas das mesmas técnicas para cancelar um algoritmo em paralelo.  
  
 Os exemplos a seguir ilustram várias maneiras de cancelar um algoritmo em paralelo.  
  
 O exemplo a seguir usa o `run_with_cancellation_token` a função para chamar o `parallel_for` algoritmo. O `run_with_cancellation_token` função usa um cancelamento de token como um argumento e chama a função de trabalho fornecida de forma síncrona. Como os algoritmos paralelos são baseados em tarefas, eles herdam o token de cancelamento da tarefa pai. Portanto, `parallel_for` pode responder ao cancelamento.  
  
 [!code-cpp[concrt-cancel-parallel-for#1](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_11.cpp)]  
  

 O exemplo a seguir usa o [concurrency::structured_task_group::run_and_wait](reference/structured-task-group-class.md#run_and_wait) método para chamar o `parallel_for` algoritmo. O `structured_task_group::run_and_wait` método aguarda a tarefa fornecida seja concluída. O `structured_task_group` objeto permite que a função de trabalho Cancelar a tarefa.  
  
 [!code-cpp[concrt-task-tree#7](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_12.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
The task group status is: canceled.  
```  
  
 O exemplo a seguir usa a manipulação de exceção para cancelar um `parallel_for` loop. O tempo de execução empacota a exceção para o contexto de chamada.  
  
 [!code-cpp[concrt-task-tree#9](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_13.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Caught 50  
```  
  
 O exemplo a seguir usa um sinalizador booliano para coordenar o cancelamento em um `parallel_for` loop. Cada tarefa é executada como este exemplo não usa o `cancel` tratamento de exceção ou método para cancelar o conjunto geral de tarefas. Portanto, essa técnica pode ter mais sobrecarga de um mecanismo de cancelamento.  
  
 [!code-cpp[concrt-task-tree#8](../../parallel/concrt/codesnippet/cpp/cancellation-in-the-ppl_14.cpp)]  
  
 Cada método de cancelamento tem vantagens em relação a outras pessoas. Escolha o método que atenda às suas necessidades específicas.  
  
 [[Superior](#top)]  
  
##  <a name="when"></a> Quando não usar o cancelamento  
 O uso de cancelamento é apropriado quando cada membro de um grupo de tarefas relacionadas pode sair de maneira oportuna. No entanto, existem alguns cenários onde cancelamento pode não ser apropriado para seu aplicativo. Por exemplo, como o cancelamento da tarefa é cooperativo, o conjunto geral de tarefas não cancelará se qualquer tarefa individual está bloqueada. Por exemplo, se uma tarefa ainda não foi iniciado, mas ele desbloqueia outra tarefa ativa, ele não será iniciado se o grupo de tarefas é cancelado. Isso pode causar um deadlock ocorre no seu aplicativo. Um segundo exemplo de onde o uso de cancelamento pode não ser apropriado é quando uma tarefa é cancelada, mas sua tarefa filho executa uma operação importante, como a liberação de um recurso. Porque o conjunto geral de tarefas é cancelado quando a tarefa pai é cancelada, a operação não será executado. Para obter um exemplo que ilustra esse ponto, consulte o [compreender como cancelamento e destruição de tratamento afetam o objeto de exceção](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) seção práticas recomendadas no tópico da biblioteca de padrões paralelos.  
  
 [[Superior](#top)]  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Como usar cancelamento para interromper um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)|Mostra como usar cancelamento para implementar um algoritmo de pesquisa paralela.|  
|[Como usar tratamento de exceções para interromper um loop paralelo](../../parallel/concrt/how-to-use-exception-handling-to-break-from-a-parallel-loop.md)|Mostra como usar o `task_group` classe para gravar um algoritmo de pesquisa para uma estrutura de árvore básico.|  
|[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)|Descreve como o tempo de execução trata exceções geradas por agentes assíncronos, grupos de tarefas e tarefas leves e como responder a exceções em seus aplicativos.|  
|[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)|Descreve como tarefas se relacionam com grupos de tarefas e como você pode usar tarefas estruturadas e não estruturadas em seus aplicativos.|  
|[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)|Descreve os algoritmos paralelos, que realizam um trabalho simultaneamente em conjuntos de dados|  
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Fornece uma visão geral da biblioteca de padrões paralelos.|  
  
## <a name="reference"></a>Referência  
 [Classe task (Tempo de Execução de Simultaneidade)](../../parallel/concrt/reference/task-class.md)  
  
 [Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)  
  
 [Classe cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md)  
  
 [Classe task_group](reference/task-group-class.md)  
  
 [Classe structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md)  

 [Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)


