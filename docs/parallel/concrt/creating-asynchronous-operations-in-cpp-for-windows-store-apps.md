---
title: Criando operações assíncronas em C++ para aplicativos UWP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows 8.x apps, creating C++ async operations
- Creating C++ async operations
ms.assetid: a57cecf4-394a-4391-a957-1d52ed2e5494
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 24ea9cc47ea9fa78c5efaf6c922f9f01dd3ff963
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="creating-asynchronous-operations-in-c-for-uwp-apps"></a>Criando operações assíncronas em C++ para aplicativos UWP
Este documento descreve alguns dos principais pontos para ter em mente quando você usar a classe de tarefa para gerar operações assíncronas com base em Windows ThreadPool em um aplicativo de UWP Universal do Windows Runtime ().  
  
 O uso de programação assíncrona é um componente fundamental no modelo de aplicativo do Windows Runtime porque ela permite que aplicativos continuem respondendo à entrada do usuário. Você pode iniciar uma tarefa de longa execução sem bloquear o thread de interface do usuário, e você pode receber os resultados da tarefa mais tarde. Você também pode cancelar tarefas e receber notificações de progresso como tarefas executadas em segundo plano. O documento [programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) fornece uma visão geral do padrão assíncrono está disponível no Visual C++ para criar aplicativos UWP. Esse documento ensina como consumir e criar cadeias de operações assíncronas do tempo de execução do Windows. Esta seção descreve como usar os tipos em ppltasks para gerar operações assíncronas que podem ser consumidas por outro componente de tempo de execução do Windows e como controlar o trabalho assíncrono como é executado. Além disso, considere leitura [padrões de programação assíncrona e dicas em Hilo (aplicativos da Windows Store usando C++ e XAML)](http://msdn.microsoft.com/library/windows/apps/jj160321.aspx) para saber como usamos a classe task para implementar operações assíncronas em Hilo, um aplicativo de tempo de execução do Windows usando o C++ e XAML.  
  
> [!NOTE]
>  Você pode usar o [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL) e [biblioteca de agentes assíncrona](../../parallel/concrt/asynchronous-agents-library.md) em um aplicativo UWP. No entanto, você não pode usar o Agendador de tarefas ou o Gerenciador de recursos. Este documento descreve os recursos adicionais que fornece a PPL que estão disponíveis somente para um aplicativo UWP e não um aplicativo de área de trabalho.  
  
## <a name="key-points"></a>Pontos-chave  

-   Use [Concurrency:: create_async](reference/concurrency-namespace-functions.md#create_async) para criar operações assíncronas que podem ser usadas por outros componentes (que podem ser escritos em idiomas diferentes do C++).  

  
-   Use [Concurrency:: progress_reporter](../../parallel/concrt/reference/progress-reporter-class.md) notificações de andamento do relatório para componentes que chamam as operações assíncronas.  
  
-   Use tokens de cancelamento para habilitar operações assíncronas internas Cancelar.  
  
-   O comportamento do `create_async` função depende do tipo de retorno da função de trabalho que é passada para ele. Uma função de trabalho que retorna uma tarefa (a `task<T>` ou `task<void>`) é executada modo síncrono no contexto de chamado `create_async`. Uma função de trabalho que retorna `T` ou `void` é executado em um contexto arbitrário.  
  
-   Você pode usar o [concurrency::task::then](reference/task-class.md#then) método para criar uma cadeia de tarefas que executam um após o outro. Em um aplicativo UWP, o contexto padrão para continuações de uma tarefa depende de como essa tarefa foi construída. Se a tarefa foi criada, passando uma ação assíncrona para o construtor de tarefa ou passando uma expressão lambda que retorna uma ação assíncrona, o contexto padrão para todas as continuações dessa tarefa é o contexto atual. Se a tarefa não foi construída a partir uma ação assíncrona, um contexto arbitrário é usado por padrão para continuações da tarefa. Você pode substituir o contexto padrão com o [concurrency::task_continuation_context](../../parallel/concrt/reference/task-continuation-context-class.md) classe.  

  
## <a name="in-this-document"></a>Neste documento  
  
-   [Criando operações assíncronas](#create-async)  
  
-   [Exemplo: Criando um componente de tempo de execução do Windows](#example-component)  
  
-   [Controlando o Thread de execução](#exethread)  
  
-   [Exemplo: Controlando a execução em um aplicativo de tempo de execução do Windows com C++ e XAML](#example-app)  
  
##  <a name="create-async"></a> Criando operações assíncronas  
 Você pode usar o modelo de tarefa e continuação em biblioteca de padrões paralelos (PPL) para definir as tarefas em segundo plano, bem como tarefas adicionais que são executados quando a tarefa anterior é concluída. Essa funcionalidade é fornecida pelo [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) classe. Para obter mais informações sobre esse modelo e o `task` de classe, consulte [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 O tempo de execução do Windows é uma interface de programação que você pode usar para criar aplicativos da UWP que são executados somente em um ambiente de sistema operacional especial. Esses aplicativos usam funções autorizadas, tipos de dados e dispositivos e são distribuídos da Microsoft Store. O tempo de execução do Windows é representado pelo *Interface binária de aplicativo* (ABI). A ABI é um contrato binário subjacente que torna as APIs do Windows Runtime disponíveis para linguagens de programação como Visual C++.  
  
 Usando o tempo de execução do Windows, você pode usar os melhores recursos de várias linguagens de programação e combiná-los em um aplicativo. Por exemplo, você pode criar sua interface do usuário em JavaScript e executar a lógica do aplicativo de computação intensa em um componente C++. A capacidade de executar essas operações de computação intensa em segundo plano é um fator essencial manter a interface do usuário responsivo. Porque o `task` classe é específica para C++, você deve usar uma interface de tempo de execução do Windows para se comunicar operações assíncronas para outros componentes (que podem ser escritos em idiomas diferentes do C++). O tempo de execução do Windows fornece quatro interfaces que você pode usar para representar operações assíncronas:  
  
 [Windows::Foundation::IAsyncAction](http://msdn.microsoft.com/library/windows/apps/windows.foundation.iasyncaction.aspx)  
 Representa uma ação assíncrona.  
  
 [Windows::Foundation::IAsyncActionWithProgress\<TProgress>](http://msdn.microsoft.com/library/windows/apps/br206581.aspx)  
 Representa uma ação assíncrona que relata progresso.  
  
 [Windows::Foundation::IAsyncOperation\<TResult>](http://msdn.microsoft.com/library/windows/apps/br206598.aspx)  
 Representa uma operação assíncrona que retorna um resultado.  
  
 [Windows::Foundation::IAsyncOperationWithProgress\<TResult, TProgress >](http://msdn.microsoft.com/library/windows/apps/br206594.aspx)  
 Representa uma operação assíncrona que retorna um resultado e relatórios de progresso.  
  
 A noção de um *ação* significa que a tarefa assíncrona não produz um valor (pense em uma função que retorna `void`). A noção de um *operação* significa que a tarefa assíncrona produzir um valor. A noção de *andamento* significa que a tarefa pode relatar mensagens de andamento ao chamador. JavaScript, o .NET Framework e Visual C++ fornece sua própria maneira de criar instâncias dessas interfaces para uso pelo limite da ABI. Para Visual C++, PPL fornece o [Concurrency:: create_async](reference/concurrency-namespace-functions.md#create_async) função. Esta função cria uma operação que representa a conclusão de uma tarefa ou ação assíncrona do tempo de execução do Windows. O `create_async` função usa uma função de trabalho (normalmente uma expressão lambda), cria internamente uma `task` objeto e encapsula a tarefa em uma das quatro interfaces de tempo de execução do Windows assíncronas.  
  
> [!NOTE]
>  Use `create_async` somente quando você precisa criar a funcionalidade que pode ser acessada de outro idioma ou outro componente de tempo de execução do Windows. Use o `task` classe diretamente quando você sabe que a operação é produzida e consumida pelo código do C++ no mesmo componente.  
  
 O tipo de retorno de `create_async` é determinado pelo tipo de seus argumentos. Por exemplo, se sua função de trabalho não retorna um valor e não informa o progresso, `create_async` retorna `IAsyncAction`. Se sua função de trabalho não retorna um valor e também relatórios de andamento, `create_async` retorna `IAsyncActionWithProgress`. Para relatar o andamento, forneça um [Concurrency:: progress_reporter](../../parallel/concrt/reference/progress-reporter-class.md) objeto como o parâmetro para a função de trabalho. A capacidade de relatar o andamento permite relatar que quantidade de trabalho foi executada e o valor ainda permanece (por exemplo, como uma porcentagem). Ele também permite relatar os resultados conforme elas se tornam disponíveis.  
  
 As interfaces `IAsyncAction`, `IAsyncActionWithProgress<TProgress>`, `IAsyncOperation<TResult>` e `IAsyncActionOperationWithProgress<TProgress, TProgress>` fornecem um método `Cancel` que permite cancelar a operação assíncrona. O `task` classe funciona com tokens de cancelamento. Quando você usa um token de cancelamento para cancelar o trabalho, o tempo de execução não inicia um novo trabalho assina esse token. Um trabalho que já está ativo pode monitorar seu token de cancelamento e parar quando possível. Esse mecanismo é descrito mais detalhadamente no documento [cancelamento no PPL](cancellation-in-the-ppl.md). Você pode conectar o cancelamento da tarefa com o tempo de execução do Windows`Cancel` métodos de duas maneiras. Primeiro, você pode definir a função de trabalho que você passa para `create_async` tenham um [Concurrency](../../parallel/concrt/reference/cancellation-token-class.md) objeto. Quando o `Cancel` método é chamado, esse token de cancelamento é cancelado e as regras de cancelamento normais são aplicadas para subjacente `task` objeto que ofereça suporte a `create_async` chamar. Se você não fornecer um objeto `cancellation_token`, o objeto `task` subjacente define um de forma implícita. Defina um objeto `cancellation_token` quando você precisa responder de forma cooperativa ao cancelamento na sua função de trabalho. A seção [exemplo: controlando a execução em um App do tempo de execução do Windows com C++ e XAML](#example-app) mostra um exemplo de como executar o cancelamento em um aplicativo do Windows UWP (plataforma Universal) com c# e XAML que usa um C++ personalizado de tempo de execução do Windows componente.  
  
> [!WARNING]
>  Em uma cadeia de continuação de tarefas, sempre limpar o estado e, em seguida, chame [concurrency::cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) quando o token de cancelamento é cancelado. Se você retornar logo em vez de chamar `cancel_current_task`, as transições de operação para o estado concluído em vez do estado cancelado.  

  
 A tabela a seguir resume as combinações que você pode usar para definir as operações assíncronas em seu aplicativo.  
  
|Para criar a interface de tempo de execução do Windows|Esse tipo de retorno `create_async`|Transmitir esses tipos de parâmetro para a função de trabalho para usar um token de cancelamento implícita|Transmitir esses tipos de parâmetro para a função de trabalho para usar um token de cancelamento explícita|  
|----------------------------------------------------------------------------------|------------------------------------------|--------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|  
|`IAsyncAction`|`void` ou `task<void>`|(nenhum)|(`cancellation_token`)|  
|`IAsyncActionWithProgress<TProgress>`|`void` ou `task<void>`|(`progress_reporter`)|(`progress_reporter`, `cancellation_token`)|  
|`IAsyncOperation<TResult>`|`T` ou `task<T>`|(nenhum)|(`cancellation_token`)|  
|`IAsyncActionOperationWithProgress<TProgress, TProgress>`|`T` ou `task<T>`|(`progress_reporter`)|(`progress_reporter`, `cancellation_token`)|  
  
 Você pode retornar um valor ou uma `task` objeto da função de trabalho que você passa para o `create_async` função. Essas variações produzem comportamentos diferentes. Quando você retornar um valor, a função de trabalho é encapsulada em um `task` para que ele possa ser executado em um thread em segundo plano. Além disso, subjacente `task` usa um token de cancelamento implícita. Por outro lado, se você retornar um `task` do objeto, a função de trabalho é executado de forma síncrona. Portanto, se você retornar um `task` de objeto, certifique-se de que também executar quaisquer operações longas em sua função de trabalho como tarefas para habilitar o aplicativo continue responsivo. Além disso, subjacente `task` não usa um token de cancelamento implícita. Portanto, você precisa definir sua função de trabalho seja um `cancellation_token` objeto se você precisar do suporte de cancelamento ao retornar um `task` de objeto `create_async`.  
  
 O exemplo a seguir mostra várias maneiras de criar um `IAsyncAction` objeto que pode ser consumido por outro componente de tempo de execução do Windows.  
  
 [!code-cpp[concrt-windowsstore-primes#100](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_1.cpp)]  
  
##  <a name="example-component"></a> Exemplo: Criando um componente de tempo de execução do Windows e consumi-las do c#  
 Considere um aplicativo que use XAML e c# para definir a interface do usuário e um componente de tempo de execução C++ Windows para executar operações de computação intensa. Neste exemplo, o componente C++ calcula os números em um determinado intervalo são primos. Para ilustrar as diferenças entre as quatro interfaces de tarefa assíncrona de tempo de execução do Windows, iniciar, no Visual Studio, criando uma **solução em branco** e nomeá-lo `Primes`. Em seguida, adicionar à solução um **o componente de tempo de execução do Windows** do projeto e nomeá-lo `PrimesLibrary`. Adicione o seguinte código ao arquivo de cabeçalho de C++ gerado (Este exemplo renomeia Class1. h para Primes.h). Cada `public` método define uma das quatro interfaces assíncronas. Os métodos que retornam um valor de retorno um [Windows::Foundation::Collections::IVector\<int >](http://msdn.microsoft.com/library/windows/apps/br206631.aspx) objeto. Os métodos que informam o andamento produzem `double` valores que definem a porcentagem de trabalho geral que foi concluída.  
  
 [!code-cpp[concrt-windowsstore-primes#1](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_2.h)]  
  
> [!NOTE]
>  Por convenção, os nomes de método assíncrono no tempo de execução do Windows geralmente terminam com "Async".  
  
 Adicione o seguinte código para o arquivo de origem C++ gerado (Este exemplo renomeia o Class1.cpp para Primes.cpp). O `is_prime` função determina se a sua entrada é primos. Implementam os métodos restantes de `Primes` classe. Cada chamada para `create_async` usa uma assinatura que é compatível com o método do qual ele é chamado. Por exemplo, porque `Primes::ComputePrimesAsync` retorna `IAsyncAction`, a função de trabalho que é fornecida para `create_async` não retorna um valor e não tem um `progress_reporter` objeto como seu parâmetro.  
  
 [!code-cpp[concrt-windowsstore-primes#2](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_3.cpp)]  
  
 Cada método primeiro executa validação para garantir que os parâmetros de entrada são não-negativo. Se um valor de entrada for negativo, o método gera [Platform:: invalidargumentexception](http://msdn.microsoft.com/library/windows/apps/hh755794\(v=vs.110\).aspx). Tratamento de erros será explicado posteriormente nesta seção.  
  
 Para consumir esses métodos de um aplicativo UWP, use o Visual c# **aplicativo em branco (XAML)** modelo para adicionar um segundo projeto à solução do Visual Studio. Este exemplo denomina o projeto `Primes`. Depois do `Primes` de projeto, adicione uma referência para o `PrimesLibrary` projeto.  
  
 Adicione o seguinte código para MainPage. XAML. Esse código define a interface do usuário para que você possa chamar o componente C++ e exibir resultados.  
  
 [!code-xml[concrt-windowsstore-primes#3](../../parallel/concrt/codesnippet/xaml/creating-asynchronous-operations-in-cpp-for-windows-store-apps_4.xaml)]  
  
 Adicione o seguinte código para o `MainPage` classe MainPage. XAML. Esse código define uma `Primes` objeto e os manipuladores de eventos do botão.  
  
 [!code-cs[concrt-windowsstore-primes#4](../../parallel/concrt/codesnippet/csharp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_5.cs)]  
  
 Esses métodos usam o `async` e `await` palavras-chave para atualizar a interface do usuário depois de concluir as operações assíncronas. Para obter informações sobre codificação assíncrona em aplicativos UWP, consulte [Threading e programação assíncrona](/windows/uwp/threading-async).  
  
 O `getPrimesCancellation` e `cancelGetPrimes` métodos funcionam em conjunto para permitir que o usuário cancelar a operação. Quando o usuário escolhe o **Cancelar** botão, o `cancelGetPrimes` chamadas de método [IAsyncOperationWithProgress\<TResult, TProgress >:: Cancelar](http://msdn.microsoft.com/library/windows/apps/windows.foundation.iasyncinfo.cancel.aspx) para cancelar a operação. O tempo de execução de simultaneidade, que gerencia a operação assíncrona Base, gera um tipo de exceção interna que é detectado pelo Windows Runtime para comunicar-se de que o cancelamento foi concluído. Para obter mais informações sobre o modelo de cancelamento, consulte [cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md).  
  
> [!IMPORTANT]
>  Para habilitar a PPL reportar corretamente no tempo de execução do Windows que ele cancelou a operação, não captura esse tipo de exceção interna. Isso significa que você também não deve capturar todas as exceções (`catch (...)`). Se você deve capturar todas as exceções, relançamos a exceção para garantir que o tempo de execução do Windows pode concluir a operação de cancelamento.  
  
 A ilustração a seguir mostra o `Primes` aplicativo depois de cada opção foi escolhida.  
  
 ![Aplicativo de números primos de tempo de execução do Windows](../../parallel/concrt/media/concrt_windows_primes.png "concrt_windows_primes")  
  
 Para obter exemplos que usam `create_async` para criar tarefas assíncronas que podem ser consumidas por outros idiomas, consulte [usando C++ no exemplo do Bing Maps Trip Optimizer](http://msdn.microsoft.com/library/windows/apps/hh699891\(v=vs.110\).aspx) e [operações assíncronas do Windows 8 em C++ com PPL](http://code.msdn.microsoft.com/windowsapps/windows-8-asynchronous-08009a0d).  
  
##  <a name="exethread"></a> Controlando o Thread de execução  
 O tempo de execução do Windows usa o modelo de threading COM. Nesse modelo, os objetos são hospedados em apartments diferentes, dependendo de como eles tratam sua sincronização. Objetos de thread-safe são hospedados no multi-threaded apartment (MTA). Objetos que devem ser acessados por um único thread são hospedados em um single-threaded apartment (STA).  
  
 Em um aplicativo que tenha uma interface de usuário, o thread ASTA (aplicativo STA) é responsável por bombeamento de mensagens de janela e é o único thread no processo que pode atualizar os controles de interface do usuário hospedado STA. Isso tem duas consequências. Primeiro, para permitir que o aplicativo continue responsivo, todas as operações de e/s e de uso intensivo de CPU não devem ser executar no thread de ASTA. Em segundo lugar, os resultados que vêm de threads em segundo plano devem ser empacotados para ASTA para atualizar a interface do usuário. Em um aplicativo C++ UWP, `MainPage` e executam todas as outras páginas de XAML no ATSA. Portanto, o continuações de tarefas que são declaradas no ASTA são executadas existe por padrão, para que você possa atualizar controles diretamente no corpo de continuação. No entanto, se você aninha uma tarefa em outra tarefa, qualquer continuações nessa tarefa aninhada executar no MTA. Portanto, você precisa considerar a possibilidade de especificar explicitamente em que contexto esses continuações executado.  
  
 Uma tarefa que é criada a partir de uma operação assíncrona, como `IAsyncOperation<TResult>`, usa semântica especial que pode ajudá-lo a ignora os detalhes de threads. Embora uma operação pode ser executado em um thread em segundo plano (ou ele não pode ser feito por um thread em todos os), seus continuações são por padrão sempre executado no compartimento de que as operações de continuação foi iniciado (em outras palavras, a partir de apartment que chamou `task::then`). Você pode usar o [concurrency::task_continuation_context](../../parallel/concrt/reference/task-continuation-context-class.md) classe para controlar o contexto de execução de uma continuação. Use esses métodos auxiliares estáticos para criar `task_continuation_context` objetos:  
  
-   Use [concurrency::task_continuation_context::use_arbitrary](reference/task-continuation-context-class.md#use_arbitrary) para especificar que a continuação é executada em um thread em segundo plano.  
  
-   Use [concurrency::task_continuation_context::use_current](reference/task-continuation-context-class.md#use_current) para especificar que a continuação é executada no thread de chamada `task::then`.  

  
 Você pode passar um `task_continuation_context` o objeto para o [Task:: Then](reference/task-class.md#then) método para controlar explicitamente o contexto de execução da continuação ou você pode passar a tarefa para outra apartment e, em seguida, chamar o `task::then` método para controlar implicitamente o contexto de execução.  
  
> [!IMPORTANT]
>  Como executar o thread de interface do usuário principal de aplicativos UWP em STA, continuações que você cria no que STA por padrão executados no STA. Da mesma forma, continuações que você cria no MTA execute no MTA.  
  
 A seção a seguir mostra um aplicativo que lê um arquivo no disco, localiza as palavras mais comuns no arquivo e, em seguida, mostra os resultados na interface de usuário. A operação final, a interface do usuário, a atualização ocorre no thread da interface do usuário.  
  
> [!IMPORTANT]
>  Esse comportamento é específico para aplicativos UWP. Para aplicativos de área de trabalho, você não controla onde continuações executam. Em vez disso, o agendador escolherá um thread de trabalho no qual executar cada continuação.  
  
> [!IMPORTANT]

>  Não chame [concurrency::task::wait](reference/task-class.md#wait) no corpo de uma continuação compatível com o STA. Caso contrário, o tempo de execução gera [concurrency::invalid_operation](../../parallel/concrt/reference/invalid-operation-class.md) porque esse método bloqueia o thread atual e pode fazer com que o aplicativo pare de responder. No entanto, você pode chamar o [concurrency::task::get](reference/task-class.md#get) método para receber o resultado da tarefa antecedente em uma continuação de tarefas.  
  
##  <a name="example-app"></a> Exemplo: Controlando a execução em um aplicativo de tempo de execução do Windows com C++ e XAML  
 Considere um aplicativo XAML do C++ que lê um arquivo no disco, localiza as palavras mais comuns no arquivo e, em seguida, mostra os resultados na interface de usuário. Para criar esse aplicativo, iniciar, no Visual Studio, criando uma **(Universal do Windows) do aplicativo em branco** do projeto e nomeá-lo `CommonWords`. Em seu manifesto de aplicativo, especifique o **biblioteca de documentos** capacidade de permitir que o aplicativo acessar a pasta de documentos. Também adicione o tipo de arquivo de texto (. txt) para a seção de declarações do manifesto do aplicativo. Para obter mais informações sobre os recursos do aplicativo e declarações, consulte [pacotes de aplicativos e implantação](http://msdn.microsoft.com/library/windows/apps/hh464929.aspx).  
  
 Atualização de `Grid` elemento em MainPage. XAML para incluir um `ProgressRing` elemento e um `TextBlock` elemento. O `ProgressRing` indica que a operação está em andamento e o `TextBlock` mostra os resultados da computação.  
  
 [!code-xml[concrt-windowsstore-commonwords#1](../../parallel/concrt/codesnippet/xaml/creating-asynchronous-operations-in-cpp-for-windows-store-apps_6.xaml)]  
  
 Adicione o seguinte `#include` instruções para pch. h.  
  
 [!code-cpp[concrt-windowsstore-commonwords#2](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_7.h)]  
  
 Adicione as seguintes declarações de método para o `MainPage` classe (MainPage.h).  
  
 [!code-cpp[concrt-windowsstore-commonwords#3](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_8.h)]  
  
 Adicione o seguinte `using` instruções MainPage.cpp.  
  
 [!code-cpp[concrt-windowsstore-commonwords#4](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_9.cpp)]  
  
 MainPage.cpp, implementar a `MainPage::MakeWordList`, `MainPage::FindCommonWords`, e `MainPage::ShowResults` métodos. O `MainPage::MakeWordList` e `MainPage::FindCommonWords` executar operações de computação intensa. O `MainPage::ShowResults` método exibe o resultado da computação na interface de usuário.  
  
 [!code-cpp[concrt-windowsstore-commonwords#5](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_10.cpp)]  
  
 Modificar o `MainPage` construtor para criar uma cadeia de tarefas de continuação que exibe na interface de usuário de palavras comuns no catálogo de *Ilíada o* por Homer. As tarefas de dois continuação primeiro, o qual dividir o texto em palavras individuais e palavras comuns, podem ser demoradas e, portanto, são definidas explicitamente para ser executado em segundo plano. A tarefa de continuação final, que atualiza a interface do usuário, não especifica nenhum contexto de continuação e, portanto, segue o apartment threading regras.  
  
 [!code-cpp[concrt-windowsstore-commonwords#6](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_11.cpp)]  
  
> [!NOTE]
>  Este exemplo demonstra como especificar contextos de execução e como compor uma cadeia de continuação. Lembre-se de que por padrão uma tarefa que é criada a partir de uma operação assíncrona é executado seus continuações de apartment chamado `task::then`. Portanto, este exemplo usa `task_continuation_context::use_arbitrary` para especificar que as operações que não envolvem a interface do usuário seja executada em um thread em segundo plano.  
  
 A ilustração a seguir mostra os resultados da `CommonWords` aplicativo.  
  
 ![Aplicativo do Windows Runtime CommonWords](../../parallel/concrt/media/concrt_windows_common_words.png "concrt_windows_common_words")  
  
 Neste exemplo, é possível oferecer suporte ao cancelamento, porque o `task` objetos que dão suporte a `create_async` usar um token de cancelamento implícita. Definir sua função de trabalho seja um `cancellation_token` se suas tarefas precisam responder ao cancelamento de forma cooperativa do objeto. Para obter mais informações sobre cancelamento no PPL, consulte [cancelamento no PPL](cancellation-in-the-ppl.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)
