---
title: "Cancelamento no PPL | Microsoft Docs"
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
  - "cancelando algoritmos paralelos [Tempo de Execução de Simultaneidade]"
  - "cancelando tarefas paralelas [Tempo de Execução de Simultaneidade]"
  - "cancelamento no PPL"
  - "algoritmos paralelos, cancelando [Tempo de Execução de Simultaneidade]"
  - "tarefas paralelas, cancelando [Tempo de Execução de Simultaneidade]"
  - "árvores de trabalho paralelas [Tempo de Execução de Simultaneidade]"
ms.assetid: baaef417-b2f9-470e-b8bd-9ed890725b35
caps.latest.revision: 31
caps.handback.revision: 28
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cancelamento no PPL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento explica a função de cancelamento na paralela padrões PPL \(biblioteca\), como cancelar o trabalho paralelo e como determinar quando o trabalho paralelo é cancelado.  
  
> [!NOTE]
>  O tempo de execução usa o tratamento de exceções para implementar o cancelamento.  Não catch ou tratar essas exceções em seu código.  Além disso, recomendamos que você escreva o código de exceção segura nos corpos de função para suas tarefas.  Por exemplo, você pode usar o *recurso aquisição é inicialização* padrão \(RAII\) para garantir que os recursos são tratados corretamente quando uma exceção é lançada no corpo de uma tarefa.  Para um exemplo completo que usa o padrão RAII para limpar um recurso em uma tarefa cancelável, consulte [Instruções passo a passo: removendo trabalho de um thread de interface de usuário](../../parallel/concrt/walkthrough-removing-work-from-a-user-interface-thread.md).  
  
## Pontos\-chave  
  
-   Cancelamento é cooperativo e envolve coordenação entre o código que solicita o cancelamento e a tarefa responde ao cancelamento.  
  
-   Quando possível, use tokens de cancelamento para cancelar o trabalho.  O [Concurrency:: cancellation\_token](../../parallel/concrt/reference/cancellation-token-class.md) classe define um token de cancelamento.  
  
-   Quando você usa tokens de cancelamento, use o [concurrency::cancellation\_token\_source::cancel](../Topic/cancellation_token_source::cancel%20Method.md) método para iniciar o cancelamento e a [concurrency::cancel\_current\_task](../Topic/cancel_current_task%20Function.md) função responder ao cancelamento.  
  
-   O cancelamento não ocorre imediatamente.  Embora o novo trabalho não for iniciado, se uma tarefa ou um grupo de tarefas é cancelado, trabalho ativo deve verificar e responder ao cancelamento.  
  
-   Uma continuação de acordo com o valor herda o token de cancelamento da tarefa antecedente.  Uma continuação baseado em tarefa nunca se herda o token da tarefa antecedente.  
  
-   Use o [Concurrency:: cancellation\_token:: nenhum](../Topic/cancellation_token::none%20Method.md) método quando você chamar um construtor ou função que usa um `cancellation_token` objeto, mas você não quiser que a operação cancelável.  Além disso, se você passar um token de cancelamento para o [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md) construtor ou [concurrency::create\_task](../Topic/create_task%20Function.md) função, essa tarefa não é cancelável.  
  
##  <a name="top"></a> Neste Documento  
  
-   [Árvores de Trabalho Paralelas](#trees)  
  
-   [Cancelando Tarefas Paralelas](#tasks)  
  
    -   [Usando um Token de Cancelamento para Cancelar o Trabalho Paralelo](#tokens)  
  
    -   [Usando o Método cancel para Cancelar o Trabalho Paralelo](#cancel)  
  
    -   [Usando Exceções para Cancelar Trabalho Paralelo](#exceptions)  
  
-   [Cancelando Algoritmos Paralelos](#algorithms)  
  
-   [Quando Não Usar Cancelamento](#when)  
  
##  <a name="trees"></a> Árvores de Trabalho Paralelas  
 A PPL usa tarefas e grupos de tarefas para gerenciar tarefas refinadas e cálculos.  Você pode aninhar grupos de tarefas para o formulário *árvores* de trabalho paralelo.  A ilustração a seguir mostra uma árvore de trabalho paralelos.  Nesta ilustração, `tg1` e `tg2` representam grupos de tarefas; `t1`, `t2`, `t3`, `t4`, e `t5` representam o trabalho que executam os grupos de tarefas.  
  
 ![Uma árvore de trabalho paralelos](../Image/ParallelWork_Trees.png "ParallelWork\_Trees")  
  
 O exemplo a seguir mostra o código que é necessário para criar a árvore na ilustração.  Neste exemplo, `tg1` e `tg2` são [concurrency::structured\_task\_group](../../parallel/concrt/reference/structured-task-group-class.md) objetos; `t1`, `t2`, `t3`, `t4`, e `t5` são [concurrency::task\_handle](../../parallel/concrt/reference/task-handle-class.md) objetos.  
  
 [!code-cpp[concrt-task-tree#1](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_1.cpp)]  
  
 Você também pode usar o [concurrency::task\_group](../Topic/task_group%20Class.md) classe para criar uma árvore de trabalho semelhantes.  O [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md) classe também oferece suporte a noção de uma árvore de trabalho.  No entanto, um `task` árvore é uma árvore de dependência.  Em um `task` árvore, works futuro seja concluída após o trabalho atual.  Em uma árvore de grupo de tarefas, trabalho interno é concluída antes do trabalho externo.  Para obter mais informações sobre as diferenças entre grupos de tarefas e tarefas, consulte [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 \[[Top](#top)\]  
  
##  <a name="tasks"></a> Cancelando Tarefas Paralelas  
 Há várias maneiras de cancelar o trabalho paralelo.  A melhor maneira é usar um token de cancelamento.  Grupos de tarefas também suporte a [concurrency::task\_group::cancel](../Topic/task_group::cancel%20Method.md) método e o [concurrency::structured\_task\_group::cancel](../Topic/structured_task_group::cancel%20Method.md) método.  A forma final é lançar uma exceção no corpo de uma função de trabalho da tarefa.  Independentemente do método escolhido, entenda que o cancelamento não ocorre imediatamente.  Embora o novo trabalho não for iniciado, se uma tarefa ou um grupo de tarefas é cancelado, trabalho ativo deve verificar e responder ao cancelamento.  
  
 Para obter mais exemplos que Cancelar tarefas paralelas, consulte [Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md), [Como usar cancelamento para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md), e [Como usar tratamento de exceções para parar um loop paralelo](../Topic/How%20to:%20Use%20Exception%20Handling%20to%20Break%20from%20a%20Parallel%20Loop.md).  
  
###  <a name="tokens"></a> Usando um Token de Cancelamento para Cancelar o Trabalho Paralelo  
 O `task`, `task_group`, e `structured_task_group` classes de suporte ao cancelamento por meio do uso de tokens de cancelamento.  Define a PPL o [Concurrency:: cancellation\_token\_source](../../parallel/concrt/reference/cancellation-token-source-class.md) e [Concurrency:: cancellation\_token](../../parallel/concrt/reference/cancellation-token-class.md) classes para essa finalidade.  Quando você usa um token de cancelamento para cancelar o trabalho, o tempo de execução não inicia um novo trabalho assina esse token.  Trabalho que já está ativo pode monitorar seu token de cancelamento e interromper quando possível.  
  
 Para iniciar o cancelamento, chame o [concurrency::cancellation\_token\_source::cancel](../Topic/cancellation_token_source::cancel%20Method.md) método.  Responder ao cancelamento das seguintes maneiras:  
  
-   Para `task` objetos, use o [concurrency::cancel\_current\_task](../Topic/cancel_current_task%20Function.md) função.  `cancel_current_task` Cancela a tarefa atual e qualquer um dos seus continuações baseada em valor.  \(Ele não cancelará o cancelamento *token* que está associado com a tarefa ou seus continuações.\)  
  
-   Para grupos de tarefas e algoritmos paralelos, use o [concurrency::is\_current\_task\_group\_canceling](../Topic/is_current_task_group_canceling%20Function.md) função para detectar o cancelamento e assim que possível retornar do corpo da tarefa quando esta função retorna `true`.  \(Não chamar `cancel_current_task` de um grupo de tarefas.\)  
  
 O exemplo a seguir mostra o primeiro padrão básico para o cancelamento da tarefa.  O corpo da tarefa ocasionalmente verifica o cancelamento dentro de um loop.  
  
 [!code-cpp[concrt-task-basic-cancellation#1](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_2.cpp)]  
  
 O `cancel_current_task` função gera; portanto, você não precisa retornar explicitamente o loop atual ou função.  
  
> [!TIP]
>  Como alternativa, você pode chamar o [concurrency::interruption\_point](../Topic/interruption_point%20Function.md) de função em vez de `cancel_current_task`.  
  
 É importante chamar `cancel_current_task` quando você responde ao cancelamento porque ela faz a transição de tarefas para o estado cancelado.  Se você retornar antecipadamente em vez de chamar `cancel_current_task`, a operação faz a transição para o estado concluído e todas as continuações baseada em valor são executadas.  
  
> [!CAUTION]
>  Nunca geram `task_canceled` do seu código.  Chame `cancel_current_task` em seu lugar.  
  
 Quando uma tarefa termina em estado cancelado, o [concurrency::task::get](../Topic/task::get%20Method.md) método lança [concurrency::task\_canceled](../../parallel/concrt/reference/task-canceled-class.md).  \(Por outro lado, [concurrency::task::wait](../Topic/task::wait%20Method.md) retorna [task\_status::canceled](../Topic/task_group_status%20Enumeration.md) e não gerará.\) O exemplo a seguir ilustra esse comportamento para uma continuação baseado em tarefa.  Uma continuação baseado em tarefas é chamada, mesmo quando a tarefa antecedente é cancelada.  
  
 [!code-cpp[concrt-task-canceled#1](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_3.cpp)]  
  
 Como continuações baseada em valor herdam o token de sua tarefa antecedente, a menos que tenham sido criados com um token explícito, continuações insira imediatamente o estado cancelado mesmo quando a tarefa antecedente ainda está em execução.  Portanto, qualquer exceção gerada pela tarefa antecedente após o cancelamento não é propagada para as tarefas de continuação.  Cancelamento sempre substitui o estado da tarefa antecedente.  O exemplo a seguir é semelhante a anterior, mas ilustra o comportamento para uma continuação de acordo com o valor.  
  
 [!code-cpp[concrt-task-canceled#2](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_4.cpp)]  
  
> [!CAUTION]
>  Se você não passar um token de cancelamento para o `task` construtor ou [concurrency::create\_task](../Topic/create_task%20Function.md) função, essa tarefa não é cancelável.  Além disso, você deve passar o mesmo token de cancelamento para o construtor de quaisquer tarefas aninhadas \(isto é, tarefas que são criadas no corpo de outra tarefa\) para cancelar todas as tarefas simultaneamente.  
  
 Você talvez queira executar códigos arbitrários quando um token de cancelamento é cancelado.  Por exemplo, se o usuário escolhe um **Cancelar** botão na interface do usuário para cancelar a operação, você pode desabilitar o botão até que o usuário inicie outra operação.  O exemplo a seguir mostra como usar o [concurrency::cancellation\_token::register\_callback](../Topic/cancellation_token::register_callback%20Method.md) método para registrar uma função de retorno de chamada que é executado quando um token de cancelamento é cancelado.  
  
 [!CODE [concrt-task-cancellation-callback#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-task-cancellation-callback#1)]  
  
 O documento [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md) explica a diferença entre as continuações baseados em tarefas e valor.  Se você não fornecer um `cancellation_token` do objeto para uma tarefa de continuação, a continuação herda o token de cancelamento da tarefa antecedente das seguintes maneiras:  
  
-   Uma continuação de acordo com o valor sempre herda o token de cancelamento da tarefa antecedente.  
  
-   Uma continuação baseado em tarefa nunca se herda o token de cancelamento da tarefa antecedente.  A única maneira de fazer uma continuação baseado em Tarefa cancelável é explicitamente passar um token de cancelamento.  
  
 Esses comportamentos não são afetados por uma tarefa com falha \(ou seja, aquele que gera uma exceção\).  Nesse caso, uma continuação de acordo com o valor será cancelada; uma continuação baseado em tarefa não foi cancelada.  
  
> [!CAUTION]
>  Uma tarefa que é criada em outra tarefa \(em outras palavras, uma tarefa aninhada\) não herdam o token de cancelamento da tarefa pai.  Somente uma continuação de acordo com o valor herda o token de cancelamento da tarefa antecedente.  
  
> [!TIP]
>  Use o [Concurrency:: cancellation\_token:: nenhum](../Topic/cancellation_token::none%20Method.md) método quando você chamar um construtor ou função que usa um `cancellation_token` objeto e você não quiser que a operação cancelável.  
  
 Você também pode fornecer um token de cancelamento para o construtor de um `task_group` ou `structured_task_group` objeto.  Um aspecto importante é que os grupos de tarefas filho herdam esse token de cancelamento.  Para obter um exemplo que demonstra esse conceito usando o [concurrency::run\_with\_cancellation\_token](../Topic/run_with_cancellation_token%20Function.md) função a ser executada para chamar `parallel_for`, consulte [Cancelando algoritmos paralelos](#algorithms) mais adiante neste documento.  
  
 \[[Top](#top)\]  
  
#### Tokens de Cancelamento e Composição da Tarefa  
 O [when\_all](../Topic/when_all%20Function.md) e [concurrency::when\_any](../Topic/when_all%20Function.md) funções podem ajudá\-lo a composição de várias tarefas para implementar padrões comuns.  Esta seção descreve como essas funções funcionam com tokens de cancelamento.  
  
 Quando você fornece um token de cancelamento como o `when_all` e `when_any` funcione, que função cancela somente quando esse token de cancelamento é cancelado ou quando um participante de tarefas termina em um estado cancelado ou gera uma exceção.  
  
 O `when_all` função herda o token de cancelamento de cada tarefa que compõe a operação geral, quando você não fornecer um token de cancelamento para ele.  A tarefa que é retornada de `when_all` é cancelada quando qualquer um desses tokens são canceladas e pelo menos uma das tarefas participantes ainda não foi iniciado ou está em execução.  Um comportamento semelhante ocorre quando uma das tarefas lança uma exceção – a tarefa retornada de `when_all` é imediatamente cancelada com essa exceção.  
  
 O runtime decide o token de cancelamento da tarefa que é retornado de `when_any` funcionar quando essa tarefa é concluída.  Se nenhuma das tarefas participantes terminar em um estado concluído e uma ou mais das tarefas lança uma exceção, uma das tarefas que lançou é escolhida para concluir o `when_any` e seu token é escolhido como o token para a tarefa final.  Se mais de uma tarefa termina no concluídas de estado, a tarefa retornada de `when_any` tarefa termina em um estado concluído.  O tempo de execução tenta selecionar tarefas concluídas cujo token não for cancelado no momento da conclusão, para que a tarefa que é retornado de `when_any` não seja cancelado imediatamente, embora outras tarefas em execução podem ser concluídas em um momento posterior.  
  
 \[[Top](#top)\]  
  
###  <a name="cancel"></a> Usando o Método cancel para Cancelar o Trabalho Paralelo  
 O [concurrency::task\_group::cancel](../Topic/task_group::cancel%20Method.md) e [concurrency::structured\_task\_group::cancel](../Topic/structured_task_group::cancel%20Method.md) métodos definir um grupo de tarefas com o estado cancelado.  Depois de você chamar `cancel`, o grupo de tarefas não inicia tarefas futuras.  O `cancel` métodos podem ser chamados por várias tarefas filho.  Faz com que uma tarefa cancelada a [concurrency::task\_group::wait](../Topic/task_group::wait%20Method.md) e [concurrency::structured\_task\_group::wait](../Topic/structured_task_group::wait%20Method.md) métodos para retornar [concurrency::canceled](../Topic/task_group_status%20Enumeration.md).  
  
 Se um grupo de tarefas é cancelado, chamadas de cada tarefa filho em tempo de execução podem disparar um *ponto de interrupção*, que faz com que o tempo de execução lançar e capturar um tipo de exceção interna para cancelar tarefas ativas.  O tempo de execução de simultaneidade não definir pontos de interrupção específico; elas podem ocorrer em qualquer chamada para o tempo de execução.  O tempo de execução deve tratar as exceções que ele gera para executar o cancelamento.  Portanto, não manipule exceções desconhecidas no corpo de uma tarefa.  
  
 Se uma tarefa filho executa uma operação demorada e não chama em tempo de execução, ele deve periodicamente verificar o cancelamento e sair de maneira oportuna.  O exemplo a seguir mostra uma maneira de determinar quando o trabalho é cancelado.  Tarefa `t4` cancela o grupo de tarefas pai quando ele encontra um erro.  Tarefa `t5` ocasionalmente chama o `structured_task_group::is_canceling` método para verificar o cancelamento.  Se o grupo de tarefas pai é cancelado, tarefa `t5` imprime uma mensagem e é encerrado.  
  
 [!code-cpp[concrt-task-tree#6](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_5.cpp)]  
  
 Este exemplo verifica o cancelamento em cada 100<sup>th</sup> iteração do loop de tarefa.  A frequência com que você verificar o cancelamento depende da quantidade de trabalho que executa sua tarefa e rapidez é necessário a responder ao cancelamento de tarefas.  
  
 Se você não tiver acesso ao objeto de grupo de tarefa pai, chame o [concurrency::is\_current\_task\_group\_canceling](../Topic/is_current_task_group_canceling%20Function.md) função para determinar se o grupo de tarefa pai foi cancelado.  
  
 O `cancel` método afeta somente tarefas filho.  Por exemplo, se você cancelar o grupo de tarefas `tg1` na ilustração da árvore trabalho paralelo, todas as tarefas na árvore \(`t1`, `t2`, `t3`, `t4`, e `t5`\) são afetados.  Se você cancelar o grupo de tarefas aninhadas, `tg2`, apenas as tarefas `t4` e `t5` são afetados.  
  
 Quando você chama o `cancel` método, todas as tarefas filho grupos também são cancelados.  No entanto, o cancelamento não afeta pais do grupo de tarefas em uma árvore de trabalho paralelo.  Os exemplos a seguir mostram isso com base em árvore mostrada a trabalho paralelo.  
  
 O primeiro desses exemplos cria uma função de trabalho para a tarefa `t4`, que é um filho do grupo de tarefas `tg2`.  A função de trabalho chama a função `work` em um loop.  Se qualquer chamada para `work` falhar, a tarefa cancela seu grupo de tarefa pai.  Isso faz com que o grupo de tarefas `tg2` Inserir o estado cancelado, mas ele não está cancelando o grupo de tarefas `tg1`.  
  
 [!code-cpp[concrt-task-tree#2](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_6.cpp)]  
  
 Este segundo exemplo semelhante ao primeiro, exceto que a tarefa cancela o grupo de tarefas `tg1`.  Isso afeta todas as tarefas na árvore \(`t1`, `t2`, `t3`, `t4`, e `t5`\).  
  
 [!code-cpp[concrt-task-tree#3](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_7.cpp)]  
  
 O `structured_task_group` classe não é thread\-safe.  Portanto, uma tarefa filho que chama um método de seu pai `structured_task_group` objeto gera um comportamento não especificado.  As exceções a essa regra são o `structured_task_group::cancel` e [concurrency::structured\_task\_group::is\_canceling](../Topic/structured_task_group::is_canceling%20Method.md) métodos.  Uma tarefa filho pode chamar esses métodos para cancelar o grupo de tarefa pai e verificar o cancelamento.  
  
> [!CAUTION]
>  Embora você possa usar um token de cancelamento para cancelar o trabalho realizado por um grupo de tarefas é executado como um filho de um `task` do objeto, você não pode usar o `task_group::cancel` ou `structured_task_group::cancel` métodos Cancelar `task` objetos que são executados em um grupo de tarefas.  
  
 \[[Top](#top)\]  
  
###  <a name="exceptions"></a> Usando Exceções para Cancelar Trabalho Paralelo  
 O uso de tokens de cancelamento e o `cancel` método são mais eficientes do que no cancelamento de uma árvore de trabalho paralelo de manipulação de exceção.  Tokens de cancelamento e o `cancel` método Cancelar uma tarefa e todas as tarefas filho de uma maneira de cima para baixo.  Por outro lado, a manipulação de exceção funciona de uma maneira de baixo para cima e deve cancelar a cada grupo de tarefas filho independentemente como a exceção se propaga para cima.  O tópico [Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md) explica como o tempo de execução de simultaneidade usa exceções para comunicar erros.  No entanto, nem todas as exceções indicam um erro.  Por exemplo, um algoritmo de pesquisa pode cancelar a tarefa associada ao encontrar o resultado.  No entanto, como mencionado anteriormente, tratamento de exceções é menos eficiente do que usando o `cancel` método para cancelar o trabalho paralelo.  
  
> [!CAUTION]
>  É recomendável que você use exceções para cancelar o trabalho paralelo somente quando necessário.  Tokens de cancelamento e o grupo de tarefas `cancel` métodos são mais eficiente e menos propensa a erros.  
  
 Quando você lançar uma exceção no corpo de uma função de trabalho que você passar para um grupo de tarefas, o tempo de execução armazena essa exceção e empacota a exceção para o contexto que espera que o grupo de tarefas concluir.  Assim como acontece com o `cancel` método, o tempo de execução descarta quaisquer tarefas que ainda não foram iniciadas e não aceitam novas tarefas.  
  
 Neste terceiro exemplo é semelhante o um segundo, exceto que a tarefa `t4` lança uma exceção para cancelar o grupo de tarefas `tg2`.  Este exemplo usa um `try`\-`catch` bloco para verificar o cancelamento quando o grupo de tarefas `tg2` aguarda suas tarefas filho concluir.  Como o primeiro exemplo, isso faz com que o grupo de tarefas `tg2` Inserir o estado cancelado, mas ele não está cancelando o grupo de tarefas `tg1`.  
  
 [!code-cpp[concrt-task-tree#4](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_8.cpp)]  
  
 Este exemplo quarto usa o tratamento de exceções para cancelar a árvore inteira de trabalho.  O exemplo captura a exceção quando a tarefa grupo `tg1` esperas seus filho a conclusão de tarefas, em vez de ao grupo de tarefas `tg2` aguarda suas tarefas filhas.  Como o segundo exemplo, isso faz com que ambos os grupos de tarefas na árvore de `tg1` e `tg2`, para entrar no estado cancelado.  
  
 [!code-cpp[concrt-task-tree#5](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_9.cpp)]  
  
 Como o `task_group::wait` e `structured_task_group::wait` métodos geram quando uma tarefa filho lança uma exceção, você não recebe um valor de retorno deles.  
  
 \[[Top](#top)\]  
  
##  <a name="algorithms"></a> Cancelando Algoritmos Paralelos  
 Paralelo de algoritmos na PPL, por exemplo, `parallel_for`, criar grupos de tarefas.  Portanto, você pode usar muitas das mesmas técnicas para cancelar um algoritmo paralelo.  
  
 Os exemplos a seguir ilustram várias maneiras de cancelar um algoritmo paralelo.  
  
 O exemplo a seguir usa o `run_with_cancellation_token` função a ser chamada a `parallel_for` algoritmo.  O `run_with_cancellation_token` função usa um cancelamento token como um argumento e chama a função de trabalho fornecida de forma síncrona.  Como os algoritmos paralelos são baseados em tarefas, eles herdam o token de cancelamento da tarefa pai.  Portanto, `parallel_for` pode responder ao cancelamento.  
  
 [!CODE [concrt-cancel-parallel-for#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-cancel-parallel-for#1)]  
  
 O exemplo a seguir usa o [concurrency::structured\_task\_group::run\_and\_wait](../Topic/structured_task_group::run_and_wait%20Method.md) método para chamar o `parallel_for` algoritmo.  O `structured_task_group::run_and_wait` método aguarda a tarefa fornecida seja concluída.  O `structured_task_group` objeto permite que a função de trabalho Cancelar a tarefa.  
  
 [!code-cpp[concrt-task-tree#7](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_10.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
  **O status do grupo de tarefas é: cancelado.** O exemplo a seguir usa o tratamento de exceções para cancelar um `parallel_for` loop.  O tempo de execução empacota a exceção para o contexto de chamada.  
  
 [!code-cpp[concrt-task-tree#9](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_11.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
  **50 capturada** O exemplo a seguir usa um sinalizador booleano para coordenar o cancelamento em um `parallel_for` loop.  Cada tarefa é executada porque este exemplo não usa o `cancel` manipulação de método ou uma exceção para cancelar o conjunto geral de tarefas.  Portanto, essa técnica pode ter mais sobrecarga de um mecanismo de cancelamento.  
  
 [!code-cpp[concrt-task-tree#8](../../parallel/concrt/codesnippet/CPP/cancellation-in-the-ppl_12.cpp)]  
  
 Cada método de cancelamento tem vantagens em relação a outras pessoas.  Escolha o método que atenda às suas necessidades específicas.  
  
 \[[Top](#top)\]  
  
##  <a name="when"></a> Quando Não Usar Cancelamento  
 O uso de cancelamento é apropriado quando cada membro de um grupo de tarefas relacionadas pode sair de maneira oportuna.  No entanto, existem alguns cenários onde cancelamento pode não ser apropriado para seu aplicativo.  Por exemplo, como o cancelamento da tarefa é cooperativo, o conjunto geral de tarefas não cancelará se qualquer tarefa individual está bloqueada.  Por exemplo, se uma tarefa ainda não foi iniciado, mas ele desbloqueia outra tarefa ativa, ele não será iniciado se o grupo de tarefas é cancelado.  Isso pode provocar o deadlock ocorre no seu aplicativo.  Um segundo exemplo de onde o uso de cancelamento pode não ser apropriado é quando uma tarefa é cancelada, mas sua tarefa filho executa uma operação importante, como liberar um recurso.  Porque o conjunto geral de tarefas é cancelado quando a tarefa pai é cancelada, a operação não será executado.  Para obter um exemplo que ilustra essa questão, consulte o [Compreender como Cancelamento e Tratamento de Exceção Afetam a Destruição do Objeto](../../parallel/concrt/best-practices-in-the-parallel-patterns-library.md#object-destruction) seção práticas recomendadas no tópico da biblioteca de padrões paralelos.  
  
 \[[Top](#top)\]  
  
## Tópicos relacionados  
  
|Título|Descrição|  
|------------|---------------|  
|[Como usar cancelamento para parar um loop paralelo](../../parallel/concrt/how-to-use-cancellation-to-break-from-a-parallel-loop.md)|Mostra como usar cancelamento para implementar um algoritmo de pesquisa paralela.|  
|[Como usar tratamento de exceções para parar um loop paralelo](../Topic/How%20to:%20Use%20Exception%20Handling%20to%20Break%20from%20a%20Parallel%20Loop.md)|Mostra como usar o `task_group` classe para escrever um algoritmo de pesquisa para uma estrutura de árvore básica.|  
|[Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md)|Descreve como o runtime lida com exceções que são geradas por grupos de tarefas, tarefas leves e agentes assíncronos e como responder às exceções em seus aplicativos.|  
|[Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)|Descreve como tarefas se relacionam com os grupos de tarefas e como você pode usar tarefas estruturadas e não estruturadas em seus aplicativos.|  
|[Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)|Descreve os algoritmos paralelos, que realizam um trabalho simultaneamente em conjuntos de dados|  
|[Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Fornece uma visão geral da biblioteca de padrões paralelos.|  
  
## Referência  
 [Classe task \(Tempo de Execução de Simultaneidade\)](../../parallel/concrt/reference/task-class-concurrency-runtime.md)  
  
 [Classe cancellation\_token\_source](../../parallel/concrt/reference/cancellation-token-source-class.md)  
  
 [Classe cancellation\_token](../../parallel/concrt/reference/cancellation-token-class.md)  
  
 [Classe task\_group](../Topic/task_group%20Class.md)  
  
 [Classe structured\_task\_group](../../parallel/concrt/reference/structured-task-group-class.md)  
  
 [Função parallel\_for](../Topic/parallel_for%20Function.md)