---
title: "Criando opera&#231;&#245;es ass&#237;ncronas n C++ para aplicativos da Windows Store | Microsoft Docs"
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
  - "Aplicativos da Windows Store, Criando operações assíncronas em C++"
  - "Criando operações assíncronas em C++"
ms.assetid: a57cecf4-394a-4391-a957-1d52ed2e5494
caps.latest.revision: 31
caps.handback.revision: 30
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando opera&#231;&#245;es ass&#237;ncronas n C++ para aplicativos da Windows Store
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve alguns dos principais pontos para ter em mente ao usar a classe task para produzir operações assíncronas baseadas em Windows ThreadPool em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo.  
  
 O uso de programação assíncrona é um componente fundamental de [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] modelo de aplicativo porque ele permite que os aplicativos continuem respondendo à entrada do usuário. Você pode iniciar uma tarefa demorada sem bloquear o thread da interface do usuário, e você pode receber os resultados da tarefa mais tarde. Você também pode cancelar tarefas e receber notificações de progresso como as tarefas executadas em segundo plano. O documento [programação assíncrona em C\+\+](http://msdn.microsoft.com/library/windows/apps/Hh780559.aspx) fornece uma visão geral do padrão assíncrono que está disponível no Visual C\+\+ para criar [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Esse documento ensina como consumir e criar cadeias de assíncrono [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] operações. Esta seção descreve como usar os tipos em ppltasks.h para produzir operações assíncronas que podem ser consumidas por outro [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] componente e como controlar o trabalho assíncrono como é executado. Considere a leitura [padrões de programação assíncrona e dicas no Hilo \(aplicativos da Windows Store usando C\+\+ e XAML\)](http://msdn.microsoft.com/library/windows/apps/jj160321.aspx) para saber como usamos a classe de tarefa para implementar operações assíncronas no Hilo, um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo usando o C\+\+ e XAML.  
  
> [!NOTE]
>  Você pode usar o [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) \(PPL\) e [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md) em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo. No entanto, você não pode usar o Agendador de tarefas ou o Gerenciador de recursos. Este documento descreve os recursos adicionais que fornece a PPL que estão disponíveis apenas para um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo e não a um aplicativo de desktop.  
  
## Principais pontos  
  
-   Use [concurrency::create\_async](../Topic/create_async%20Function.md) criar operações assíncronas que podem ser usadas por outros componentes \(que podem ser escritos em idiomas diferentes do C\+\+\).  
  
-   Use [concurrency::progress\_reporter](../../parallel/concrt/reference/progress-reporter-class.md) notificações de andamento do relatório para componentes que chamam operações assíncronas.  
  
-   Use tokens de cancelamento para habilitar operações assíncronas internas Cancelar.  
  
-   O comportamento do `create_async` função depende do tipo de retorno da função de trabalho que é passado para ele. Uma função de trabalho que retorna uma tarefa \(em `task<T>` ou `task<void>`\) é executado de forma síncrona no contexto de chamada `create_async`. Uma função de trabalho que retorna `T` ou `void` é executado em um contexto arbitrário.  
  
-   Você pode usar o [concurrency::task::then](../Topic/task::then%20Method.md) método para criar uma cadeia de tarefas que são executadas uma após a outra. Em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo, o contexto padrão para a continuação da tarefa depende de como essa tarefa foi criada. Se a tarefa foi criada, passando uma ação assíncrona para o construtor task ou passando uma expressão lambda que retorna uma ação assíncrona, o contexto padrão para todas as continuações de tarefa é o contexto atual. Se a tarefa não é criada com uma ação assíncrona, um contexto arbitrário é usado por padrão para a continuação da tarefa. Você pode substituir o contexto padrão com o [concurrency::task\_continuation\_context](../../parallel/concrt/reference/task-continuation-context-class.md) classe.  
  
## Neste documento  
  
-   [Criando operações assíncronas](#create-async)  
  
-   [Exemplo: Criando um componente de tempo de execução C\+\+ do Windows](#example-component)  
  
-   [Controlando o Thread de execução](#exethread)  
  
-   [Exemplo: Controlando a execução em um aplicativo da Windows Store com C\+\+ e XAML](#example-app)  
  
##  <a name="create-async"></a> Criando operações assíncronas  
 Você pode usar o modelo de tarefa e continuação na paralela padrões PPL \(biblioteca\) para definir as tarefas em segundo plano, bem como tarefas adicionais que são executados quando a tarefa anterior seja concluída. Essa funcionalidade é fornecida pelo [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md) classe. Para obter mais informações sobre esse modelo e o `task` de classe, consulte [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 O [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] é uma interface de programação que você pode usar para criar [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos que são executados somente em um ambiente especial do sistema operacional. Esses aplicativos usam funções autorizadas, tipos de dados e dispositivos, além de serem distribuídos a partir da [!INCLUDE[win8_appstore_long](../../build/reference/includes/win8_appstore_long_md.md)]. O [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] é representado pela *Interface Binária de Aplicativo* \(ABI\). ABI é um contrato binário subjacente que torna as APIs do [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] disponíveis para as linguagens de programação como Visual C\+\+.  
  
 Usando o [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)], você pode usar os melhores recursos de várias linguagens de programação e combiná\-los em um aplicativo. Por exemplo, você pode criar sua interface do usuário em JavaScript e executar a lógica de aplicativo intensiva em um componente do C\+\+. A capacidade de executar essas operações intensiva em segundo plano é um fator essencial para manter a interface do usuário responsiva. Porque o `task` classe é específica para o C\+\+, você deve usar um [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] interface para se comunicar operações assíncronas para outros componentes \(que podem ser escritos em idiomas diferentes do C\+\+\). O [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] fornece quatro interfaces que você pode usar para representar operações assíncronas:  
  
 [Windows::Foundation::IAsyncAction](http://msdn.microsoft.com/library/windows/apps/windows.foundation.iasyncaction.aspx)  
 Representa uma ação assíncrona.  
  
 [Windows::Foundation::IAsyncActionWithProgress \< TProgress \>](http://msdn.microsoft.com/library/windows/apps/br206581.aspx)  
 Representa uma ação assíncrona que relata o progresso.  
  
 [Windows::Foundation::IAsyncOperation \< TResult \>](http://msdn.microsoft.com/library/windows/apps/br206598.aspx)  
 Representa uma operação assíncrona que retorna um resultado.  
  
 [Windows::Foundation::IAsyncOperationWithProgress \< TResult, TProgress \>](http://msdn.microsoft.com/library/windows/apps/br206594.aspx)  
 Representa uma operação assíncrona que retorna um resultado e relatórios de andamento.  
  
 A noção de um *ação* significa que a tarefa assíncrona não produz um valor \(pense em uma função que retorna `void`\). A noção de um *operação* significa que a tarefa assíncrona produzir um valor. A noção de *progresso* significa que a tarefa pode relatar mensagens de progresso para o chamador. JavaScript, o .NET Framework e Visual C\+\+ fornece sua própria maneira de criar instâncias dessas interfaces para uso pelo limite de ABI. Para Visual C\+\+, a PPL fornece o [concurrency::create\_async](../Topic/create_async%20Function.md) função. Esta função cria um [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] ação ou operação que representa a conclusão de uma tarefa assíncrona. O `create_async` função usa uma função de trabalho \(normalmente uma expressão lambda\), cria internamente uma `task` objeto e encapsula a tarefa em um dos quatro assíncrona [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] interfaces.  
  
> [!NOTE]
>  Use `create_async` somente quando você precisa criar a funcionalidade que pode ser acessada de outro idioma ou outro [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] componente. Use o `task` classe diretamente quando você souber que a operação foi produzida e consumida por código C\+\+ no mesmo componente.  
  
 O tipo de retorno de `create_async` é determinado pelo tipo de seus argumentos. Por exemplo, se sua função de trabalho não retorna um valor e não relatar o andamento, `create_async` retorna `IAsyncAction`. Se sua função de trabalho não retorna um valor e também relata o progresso, `create_async` retorna `IAsyncActionWithProgress`. Para relatar o progresso, forneça um [concurrency::progress\_reporter](../../parallel/concrt/reference/progress-reporter-class.md) objeto como o parâmetro para a função de trabalho. A capacidade para relatar o progresso permite que você relate que quantidade de trabalho foi executada e que valor ainda permanece \(por exemplo, como uma porcentagem\). Ele também permite relatar os resultados assim que estiverem disponíveis.  
  
 As interfaces `IAsyncAction`, `IAsyncActionWithProgress<TProgress>`, `IAsyncOperation<TResult>` e `IAsyncActionOperationWithProgress<TProgress, TProgress>` fornecem um método `Cancel` que permite cancelar a operação assíncrona. O `task` classe funciona com tokens de cancelamento. Quando você usa um token de cancelamento para cancelar o trabalho, o tempo de execução não inicia um novo trabalho assina esse token. Trabalho que já está ativo pode monitorar seu token de cancelamento e interromper quando possível. Esse mecanismo é descrito mais detalhadamente no documento [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md). Você pode conectar o cancelamento da tarefa com o [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]`Cancel` métodos de duas maneiras. Primeiro, é possível definir a função de trabalho que você transmite a `create_async` para usar um objeto [concurrency::cancellation\_token](cancellation_token). Quando o `Cancel` método é chamado, esse token de cancelamento será cancelada e as regras normais de cancelamento se aplicam subjacente `task` objeto que ofereça suporte a `create_async` chamar. Se você não fornecer um objeto `cancellation_token`, o objeto `task` subjacente define um de forma implícita. Defina um objeto `cancellation_token` quando você precisa responder de forma cooperativa ao cancelamento na sua função de trabalho. A seção [exemplo: controlando a execução em um aplicativo da Windows Store com C\+\+ e XAML](#example-app) mostra um exemplo de como executar o cancelamento em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo com c\# e XAML que usa um personalizado [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] componente C\+\+.  
  
> [!WARNING]
>  Em uma cadeia de continuações de tarefa, sempre Limpar estado e, em seguida, chame [concurrency::cancel\_current\_task](../Topic/cancel_current_task%20Function.md) quando o token de cancelamento é cancelado. Se você retornar no início, em vez de chamar `cancel_current_task`, as transições de operação para o estado concluído, em vez de estado cancelado.  
  
 A tabela a seguir resume as combinações que você pode usar para definir as operações assíncronas em seu aplicativo.  
  
|Para criar esse [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] interface|Retornar esse tipo de `create_async`|Passar esses tipos de parâmetro para a função de trabalho para usar um token de cancelamento implícita|Passar esses tipos de parâmetro para a função de trabalho para usar um token de cancelamento explícita|  
|-----------------------------------------------------------------------------------|------------------------------------------|------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|  
|`IAsyncAction`|`void` ou `task<void>`|\(nenhum\)|\(`cancellation_token`\)|  
|`IAsyncActionWithProgress<TProgress>`|`void` ou `task<void>`|\(`progress_reporter`\)|\(`progress_reporter`, `cancellation_token`\)|  
|`IAsyncOperation<TResult>`|`T` ou `task<T>`|\(nenhum\)|\(`cancellation_token`\)|  
|`IAsyncActionOperationWithProgress<TProgress, TProgress>`|`T` ou `task<T>`|\(`progress_reporter`\)|\(`progress_reporter`, `cancellation_token`\)|  
  
 Você pode retornar um valor ou uma `task` objeto da função de trabalho que você passa para o `create_async` função. Essas variações produzem comportamentos diferentes. Ao retornar um valor, a função de trabalho é encapsulada em um `task` para que ele pode ser executado em um thread em segundo plano. Além disso, subjacente `task` usa um token de cancelamento implícita. Por outro lado, se você retornar um `task` do objeto, a função de trabalho é executado de forma síncrona. Portanto, se você retornar um `task` de objeto, certifique\-se de que quaisquer operações longas em sua função de trabalho também executar como tarefas para habilitar seu aplicativo permaneça responsivo. Além disso, subjacente `task` não usa um token de cancelamento implícita. Portanto, você precisa definir sua função de trabalho tenham um `cancellation_token` objeto se você precisar de suporte para cancelamento ao retornar um `task` de objeto `create_async`.  
  
 O exemplo a seguir mostra várias maneiras de criar um `IAsyncAction` que pode ser consumido por outro objeto [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] componente.  
  
 [!code-cpp[concrt-windowsstore-primes#100](../../parallel/concrt/codesnippet/CPP/creating-asynchronous-operations-in-cpp-for-windows-store-apps_1.cpp)]  
  
##  <a name="example-component"></a> Exemplo: Criando um componente de tempo de execução do Windows C\+\+ e consumindo\-o em c\#  
 Considere um aplicativo que usa XAML e c\# para definir a interface do usuário e um C\+\+ [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] componente para executar operações com uso intensivo de computação. Neste exemplo, o componente C\+\+ calcula os números em um determinado intervalo são primos. Para ilustrar as diferenças entre os quatro [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] interfaces de tarefa assíncrona, iniciar, no Visual Studio, criando um **solução em branco** e nomeá\-lo `Primes`. Em seguida, adicionar à solução um **o componente de tempo de execução do Windows** do projeto e nomeá\-lo `PrimesLibrary`. Adicione o seguinte código para o arquivo de cabeçalho C\+\+ gerado \(Este exemplo renomeia Class1.h para Primes.h\). Cada `public` método define uma das quatro interfaces assíncronas. Os métodos que retornam um valor de retorno um [Windows::Foundation::Collections::IVector \< int \>](http://msdn.microsoft.com/library/windows/apps/br206631.aspx) objeto. Os métodos que informam o andamento produzem `double` valores que definem a porcentagem de trabalho geral que foi concluída.  
  
 [!code-cpp[concrt-windowsstore-primes#1](../../parallel/concrt/codesnippet/CPP/creating-asynchronous-operations-in-cpp-for-windows-store-apps_2.h)]  
  
> [!NOTE]
>  Por convenção, nomes de método assíncrono no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] geralmente terminam com "Async".  
  
 Adicione o seguinte código para o arquivo de origem C\+\+ gerado \(Este exemplo renomeia Class1.cpp para Primes.cpp\). O `is_prime` função determina se a entrada é primo. Implementam os métodos restantes de `Primes` classe. Cada chamada para `create_async` usa uma assinatura compatível com o método do qual ele é chamado. Por exemplo, porque `Primes::ComputePrimesAsync` retorna `IAsyncAction`, a função de trabalho que é fornecida para `create_async` não retorna um valor e não exige uma `progress_reporter` objeto como seu parâmetro.  
  
 [!code-cpp[concrt-windowsstore-primes#2](../../parallel/concrt/codesnippet/CPP/creating-asynchronous-operations-in-cpp-for-windows-store-apps_3.cpp)]  
  
 Cada método primeiro executa validação para garantir que os parâmetros de entrada são não\-negativo. Se um valor de entrada for negativo, o método gerará [Platform:: invalidargumentexception](http://msdn.microsoft.com/library/windows/apps/hh755794\(v=vs.110\).aspx). Tratamento de erros é explicado posteriormente nesta seção.  
  
 Para consumir esses métodos de um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo, use o Visual C\# **aplicativo em branco \(XAML\)** modelo para adicionar um segundo projeto à solução do Visual Studio. Este exemplo denomina o projeto `Primes`. Depois do `Primes` do projeto, adicione uma referência para o `PrimesLibrary` projeto.  
  
 Adicione o seguinte código de MainPage. XAML. Esse código define a interface do usuário para que você possa chamar o componente de C\+\+ e exibir resultados.  
  
 [!code-xml[concrt-windowsstore-primes#3](../../parallel/concrt/codesnippet/Xaml/creating-asynchronous-operations-in-cpp-for-windows-store-apps_4.xaml)]  
  
 Adicione o seguinte código para o `MainPage` classe MainPage. XAML. Esse código define uma `Primes` objeto e os manipuladores de eventos do botão.  
  
 [!code-cs[concrt-windowsstore-primes#4](../../parallel/concrt/codesnippet/CSharp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_5.cs)]  
  
 Esses métodos usam o `async` e `await` palavras\-chave para atualizar a interface do usuário depois de concluir as operações assíncronas. Para obter informações sobre os padrões assíncronos que estão disponíveis para c\# e Visual Basic, consulte [padrões assíncronos em aplicativos da Windows Store com c\#](http://msdn.microsoft.com/library/windows/apps/hh464924.aspx) e [padrões assíncronos em aplicativos da Windows Store com VB](http://msdn.microsoft.com/library/windows/apps/hh464924.aspx).  
  
 O `getPrimesCancellation` e `cancelGetPrimes` métodos funcionam juntos para permitir que o usuário cancelar a operação. Quando o usuário escolhe o **Cancelar** botão, o `cancelGetPrimes` chamadas de método [IAsyncOperationWithProgress \< TResult, TProgress \>:: Cancelar](http://msdn.microsoft.com/library/windows/apps/windows.foundation.iasyncinfo.cancel.aspx) para cancelar a operação. O tempo de execução de simultaneidade, que gerencia a operação assíncrona subjacente, gera um tipo de exceção interna detectada pelo [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] para comunicar\-se de que o cancelamento foi concluído. Para obter mais informações sobre o modelo de cancelamento, consulte [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md).  
  
> [!IMPORTANT]
>  Para habilitar a PPL relate corretamente para o [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] que ele cancelou a operação, não detectar esse tipo de exceção interna. Isso significa que você deve também não capturar todas as exceções \(`catch (...)`\). Se você deve capturar todas as exceções, relançar a exceção para garantir que o [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] pode concluir a operação de cancelamento.  
  
 A ilustração a seguir mostra o `Primes` aplicativo depois de cada opção foi escolhida.  
  
 ![O armazenamento do Windows Primes app](../../parallel/concrt/media/concrt_windows_primes.png "ConcRT\_windows\_Primes")  
  
 Para obter exemplos que usam `create_async` para criar tarefas assíncronas que podem ser consumidas por outros idiomas, consulte [usando C\+\+ no exemplo do Bing Maps Trip Optimizer](http://msdn.microsoft.com/library/windows/apps/hh699891\(v=vs.110\).aspx) e [operações assíncronas do Windows 8 em C\+\+ com PPL](http://code.msdn.microsoft.com/windowsapps/Windows-8-Asynchronous-08009a0d).  
  
##  <a name="exethread"></a> Controlando o Thread de execução  
 O [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] usa o modelo de threading de COM. Nesse modelo, os objetos são hospedados em apartments diferentes, dependendo de como eles lidam com suas sincronizações. Objetos de thread\-safe são hospedados no multi\-threaded apartment \(MTA\). Objetos que devem ser acessados por um único thread são hospedados em um single\-threaded apartment \(STA\).  
  
 Em um aplicativo que tenha uma interface do usuário, o thread ASTA \(aplicativo STA\) é responsável por bombeando mensagens de janela e é o único thread no processo que pode atualizar os controles de interface hospedado STA. Isso tem duas consequências. Primeiro, para permitir que o aplicativo permaneça responsivo, todas as operações de e\/s e uso intensivo de CPU devem não ser executadas no thread ASTA. Em segundo lugar, os resultados que vêm de threads em segundo plano devem ser empacotados para ASTA para atualizar a interface do usuário. No C\+\+ [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo, `MainPage` e executam todas as outras páginas de XAML a ATSA. Portanto, o continuações de tarefa que são declaradas no ASTA são executadas lá por padrão, para que você possa atualizar controles diretamente no corpo da continuação. No entanto, se você aninhar uma tarefa em outra tarefa, todas as continuações nessa tarefa aninhada executar no MTA. Portanto, você precisa considerar se deve especificar explicitamente em qual contexto executar esses continuações.  
  
 Uma tarefa que é criada a partir de uma operação assíncrona, como `IAsyncOperation<TResult>`, usa semânticas especiais que podem ajudar a ignoram os detalhes de threads. Embora uma operação pode ser executado em um thread em segundo plano \(ou ele não pode ser feito por um thread em todos os\), as continuações são por padrão sempre executado no apartment que iniciou as operações de continuação \(em outras palavras, a partir de apartment chamado `task::then`\). Você pode usar o [concurrency::task\_continuation\_context](../../parallel/concrt/reference/task-continuation-context-class.md) classe para controlar o contexto de execução de uma continuação. Use esses métodos auxiliares estáticos para criar `task_continuation_context` objetos:  
  
-   Use [concurrency::task\_continuation\_context::use\_arbitrary](../Topic/task_continuation_context::use_arbitrary%20Method.md) para especificar que a continuação é executado em um thread em segundo plano.  
  
-   Use [concurrency::task\_continuation\_context::use\_current](../Topic/task_continuation_context::use_current%20Method.md) para especificar que a continuação é executado no thread de chamada `task::then`.  
  
 Você pode passar um `task_continuation_context` do objeto para o [Task:: Then](../Topic/task::then%20Method.md) método para controlar explicitamente o contexto de execução da continuação ou você pode passar a tarefa para outra apartment e, em seguida, chamar o `task::then` método para controlar implicitamente o contexto de execução.  
  
> [!IMPORTANT]
>  Porque o thread da interface do usuário principal de [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos executados em STA, continuações que você cria em que STA por padrão são executados no STA. Da mesma forma, continuações que você cria no MTA execute no MTA.  
  
 A seção a seguir mostra um aplicativo que lê um arquivo no disco, localiza as palavras mais comuns desse arquivo e, em seguida, mostra os resultados na interface do usuário. A operação final, a interface do usuário, a atualização ocorre no thread da interface do usuário.  
  
> [!IMPORTANT]
>  Esse comportamento é específico para [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Para aplicativos de desktop, você não controlar onde continuações executam. Em vez disso, o agendador escolherá um thread de trabalho para executar cada continuação.  
  
> [!IMPORTANT]
>  Não chame [concurrency::task::wait](../Topic/task::wait%20Method.md) no corpo de uma continuação que é executado no STA. Caso contrário, o tempo de execução lança [concurrency::invalid\_operation](../Topic/invalid_operation%20Class.md) porque esse método bloqueia o segmento atual e pode fazer com que o aplicativo pare de responder. No entanto, você pode chamar o [concurrency::task::get](../Topic/task::get%20Method.md) método para receber o resultado da tarefa antecedente em uma continuação baseado em tarefa.  
  
##  <a name="example-app"></a> Exemplo: Controlando a execução em um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo com C\+\+ e XAML  
 Considere um aplicativo XAML de C\+\+ que lê um arquivo no disco, localiza as palavras mais comuns desse arquivo e, em seguida, mostra os resultados na interface do usuário. Para criar esse aplicativo, iniciar, no Visual Studio, criando uma [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]**aplicativo em branco \(XAML\)** do projeto e nomeá\-lo `CommonWords`. Em seu manifesto de aplicativo, especifique o **biblioteca de documentos** capacidade de permitir que o aplicativo acessar a pasta de documentos. Adicione também o tipo de arquivo de texto \(. txt\) à seção declarations do manifesto do aplicativo. Para obter mais informações sobre declarações e os recursos de aplicativo, consulte [pacotes de aplicativo e implantação](http://msdn.microsoft.com/library/windows/apps/hh464929.aspx).  
  
 Atualizar o `Grid` elemento em MainPage. XAML para incluir um `ProgressRing` elemento e um `TextBlock` elemento. O `ProgressRing` indica que a operação está em andamento e o `TextBlock` mostra os resultados do cálculo.  
  
 [!code-xml[concrt-windowsstore-commonwords#1](../../parallel/concrt/codesnippet/Xaml/creating-asynchronous-operations-in-cpp-for-windows-store-apps_6.xaml)]  
  
 Adicione o seguinte `#include` instruções pch.  
  
 [!code-cpp[concrt-windowsstore-commonwords#2](../../parallel/concrt/codesnippet/CPP/creating-asynchronous-operations-in-cpp-for-windows-store-apps_7.h)]  
  
 Adicione as seguintes declarações de método para o `MainPage` classe \(MainPage. H\).  
  
 [!code-cpp[concrt-windowsstore-commonwords#3](../../parallel/concrt/codesnippet/CPP/creating-asynchronous-operations-in-cpp-for-windows-store-apps_8.h)]  
  
 Adicione o seguinte `using` instruções MainPage.cpp.  
  
 [!code-cpp[concrt-windowsstore-commonwords#4](../../parallel/concrt/codesnippet/CPP/creating-asynchronous-operations-in-cpp-for-windows-store-apps_9.cpp)]  
  
 No MainPage.cpp, implemente o `MainPage::MakeWordList`, `MainPage::FindCommonWords`, e `MainPage::ShowResults` métodos. O `MainPage::MakeWordList` e `MainPage::FindCommonWords` executar operações intensiva. O `MainPage::ShowResults` método exibe o resultado do cálculo na interface do usuário.  
  
 [!code-cpp[concrt-windowsstore-commonwords#5](../../parallel/concrt/codesnippet/CPP/creating-asynchronous-operations-in-cpp-for-windows-store-apps_10.cpp)]  
  
 Modificar o `MainPage` construtor para criar uma cadeia de tarefas de continuação que exibe na interface do usuário de palavras comuns no catálogo de *a Ilíada* por Homer. As tarefas de dois continuação primeiro, qual dividir o texto em palavras individuais e localizar palavras comuns, podem ser demoradas e, portanto, são definidas explicitamente para executar em segundo plano. A tarefa final de continuação, que atualiza a interface do usuário, não especifica nenhum contexto de continuação e, portanto, segue o regras de segmentação de compartimento.  
  
 [!code-cpp[concrt-windowsstore-commonwords#6](../../parallel/concrt/codesnippet/CPP/creating-asynchronous-operations-in-cpp-for-windows-store-apps_11.cpp)]  
  
> [!NOTE]
>  Este exemplo demonstra como especificar os contextos de execução e como compor uma cadeia de continuações. Lembre\-se de que por padrão uma tarefa que é criada a partir de uma operação assíncrona é executado as continuações de apartment chamado `task::then`. Portanto, este exemplo usa `task_continuation_context::use_arbitrary` para especificar que as operações que envolvem a interface do usuário seja executada em um thread em segundo plano.  
  
 A ilustração a seguir mostra os resultados de `CommonWords` aplicativo.  
  
 ![Os Windows armazenam app CommonWords](../../parallel/concrt/media/concrt_windows_common_words.png "ConcRT\_windows\_Common\_Words")  
  
 Neste exemplo, é possível oferecer suporte ao cancelamento porque o `task` objetos que oferecem suporte a `create_async` usar um token de cancelamento implícita. Definir sua função de trabalho tenham um `cancellation_token` se suas tarefas precisam responder ao cancelamento de forma cooperativa do objeto. Para obter mais informações sobre cancelamento no PPL, consulte [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)  
  
## Consulte também  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)