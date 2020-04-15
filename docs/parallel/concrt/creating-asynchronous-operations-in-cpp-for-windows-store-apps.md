---
title: Criando operações assíncronas em C++ para aplicativos UWP
ms.date: 11/19/2018
helpviewer_keywords:
- Windows 8.x apps, creating C++ async operations
- Creating C++ async operations
ms.assetid: a57cecf4-394a-4391-a957-1d52ed2e5494
ms.openlocfilehash: 8e1183464d3ecf9b12fabcc6fb4f1fd99b7b0083
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81353403"
---
# <a name="creating-asynchronous-operations-in-c-for-uwp-apps"></a>Criando operações assíncronas em C++ para aplicativos UWP

Este documento descreve alguns dos pontos-chave a serem alertados quando você usa a classe de tarefas para produzir operações assíncronas baseadas no Windows ThreadPool em um aplicativo Universal Windows Runtime (UWP).

O uso de programação assíncrona é um componente-chave no modelo de aplicativo do Windows Runtime porque permite que os aplicativos permaneçam responsivos à entrada do usuário. Você pode iniciar uma tarefa de longa duração sem bloquear o segmento de ia de ui e pode receber os resultados da tarefa mais tarde. Você também pode cancelar tarefas e receber notificações de progresso à medida que as tarefas são executadas em segundo plano. O documento [Programação Assíncrona no C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps) fornece uma visão geral do padrão assíncrono disponível no Visual C++ para criar aplicativos UWP. Esse documento ensina como consumir e criar cadeias de operações assíncronas do Windows Runtime. Esta seção descreve como usar os tipos em ppltasks.h para produzir operações assíncronas que podem ser consumidas por outro componente do Windows Runtime e como controlar como o trabalho assíncrono é executado. Considere também a leitura [de padrões e dicas de programação do Async em Hilo (aplicativos do Windows Store usando C++ e XAML)](/previous-versions/windows/apps/jj160321(v=win.10)) para saber como usamos a classe de tarefas para implementar operações assíncronas em Hilo, um aplicativo do Windows Runtime usando C++ e XAML.

> [!NOTE]
> Você pode usar a [Biblioteca de Padrões Paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL) e a Biblioteca de [Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md) em um aplicativo UWP. No entanto, não é possível usar o Agendador de tarefas ou o Gerenciador de recursos. Este documento descreve recursos adicionais que o PPL fornece que estão disponíveis apenas para um aplicativo UWP, e não para um aplicativo de desktop.

## <a name="key-points"></a>Pontos-chave

- Use [a moeda::create_async](reference/concurrency-namespace-functions.md#create_async) para criar operações assíncronas que podem ser usadas por outros componentes (que podem ser escritos em idiomas diferentes de C++).

- Use [simultâneo::progress_reporter](../../parallel/concrt/reference/progress-reporter-class.md) para relatar notificações de progresso para componentes que chamam suas operações assíncronas.

- Use tokens de cancelamento para permitir o cancelamento de operações assíncronas internas.

- O comportamento `create_async` da função depende do tipo de retorno da função de trabalho que é passada a ela. Uma função de trabalho que `task<T>` `task<void>`retorna uma tarefa (ou ) `create_async`é executada sincronizadamente no contexto que se chama . Uma função de `T` `void` trabalho que retorna ou é executada em um contexto arbitrário.

- Você pode usar o método [simultu:task:::para](reference/task-class.md#then) criar uma cadeia de tarefas que executam uma após a outra. Em um aplicativo UWP, o contexto padrão para as continuações de uma tarefa depende de como essa tarefa foi construída. Se a tarefa foi criada passando uma ação assíncrona para o construtor de tarefas, ou passando uma expressão lambda que retorna uma ação assíncrona, então o contexto padrão para todas as continuações dessa tarefa é o contexto atual. Se a tarefa não for construída a partir de uma ação assíncrona, então um contexto arbitrário é usado por padrão para as continuações da tarefa. Você pode substituir o contexto padrão com a classe [simultuá-task_continuation_context.](../../parallel/concrt/reference/task-continuation-context-class.md)

## <a name="in-this-document"></a>Neste documento

- [Criando Operações Assíncronas](#create-async)

- [Exemplo: Criando um componente de tempo de execução do C++ Windows](#example-component)

- [Controlando o Thread de Execução](#exethread)

- [Exemplo: Controlando a execução em um aplicativo de tempo de execução do Windows com C++ e XAML](#example-app)

## <a name="creating-asynchronous-operations"></a><a name="create-async"></a>Criando Operações Assíncronas

Você pode usar o modelo de tarefa e continuação na Biblioteca de Padrões Paralelos (PPL) para definir tarefas em segundo plano, bem como tarefas adicionais que são executadas quando a tarefa anterior é concluída. Essa funcionalidade é fornecida pela [classe de tarefas simultuária::.task.](../../parallel/concrt/reference/task-class.md) Para obter mais informações `task` sobre este modelo e a classe, consulte [O Paralelismo da Tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).

O Windows Runtime é uma interface de programação que você pode usar para criar aplicativos UWP que são executados apenas em um ambiente de sistema operacional especial. Esses aplicativos usam funções autorizadas, tipos de dados e dispositivos e são distribuídos a partir da Microsoft Store. O Tempo de Execução do Windows é representado pela *Interface Binária* do Aplicativo (ABI). O ABI é um contrato binário subjacente que disponibiliza apis de tempo de execução do Windows para linguagem de programação, como visual C++.

Usando o Windows Runtime, você pode usar os melhores recursos de várias linguagens de programação e combiná-los em um aplicativo. Por exemplo, você pode criar sua iu em JavaScript e executar a lógica do aplicativo computação intensiva em um componente C++. A capacidade de executar essas operações computacionalmente intensivas em segundo plano é um fator-chave para manter sua iu urao responsiva. Como `task` a classe é específica para C++, você deve usar uma interface do Windows Runtime para comunicar operações assíncronas para outros componentes (que podem ser escritos em idiomas diferentes de C++). O Windows Runtime fornece quatro interfaces que você pode usar para representar operações assíncronas:

[Windows::Fundação::IAsyncAction](/uwp/api/windows.foundation.iasyncaction)<br/>
Representa uma ação assíncrona.

[Windows::Foundation::IAsyncActionWithProgress\<TProgress>](/uwp/api/Windows.Foundation.IAsyncActionWithProgress_TProgress_)<br/>
Representa uma ação assíncrona que relata o progresso.

[Windows::Fundação::IAsyncOperação\<TResult>](/uwp/api/windows.foundation.iasyncoperation_tresult_)<br/>
Representa uma operação assíncrona que retorna um resultado.

[Windows::Foundation::IAsyncOperationWithProgress\<Tresult, TProgress>](/uwp/api/windows.foundation.iasyncoperationwithprogress_tresult_tprogress_)<br/>
Representa uma operação assíncrona que retorna um resultado e relata progresso.

A noção de *ação* significa que a tarefa assíncrona não produz `void`um valor (pense em uma função que retorna ). A noção de uma *operação* significa que a tarefa assíncrona produz um valor. A noção de *progresso* significa que a tarefa pode relatar mensagens de progresso ao chamador. JavaScript, o .NET Framework e o Visual C++ cada um fornece sua própria maneira de criar instâncias dessas interfaces para uso através do limite ABI. Para Visual C++, o PPL fornece a função [de simultuá-lo::create_async.](reference/concurrency-namespace-functions.md#create_async) Essa função cria uma ação assíncrona do Windows Runtime ou uma operação que representa a conclusão de uma tarefa. A `create_async` função assume uma função de trabalho (tipicamente `task` uma expressão lambda), cria internamente um objeto e envolve essa tarefa em uma das quatro interfaces assíncronas do Windows Runtime.

> [!NOTE]
> Use `create_async` somente quando tiver que criar funcionalidades que podem ser acessadas a partir de outro idioma ou outro componente do Windows Runtime. Use `task` a classe diretamente quando souber que a operação é produzida e consumida pelo código C++ no mesmo componente.

O tipo `create_async` de retorno é determinado pelo tipo de seus argumentos. Por exemplo, se sua função de trabalho não retornar um `create_async` `IAsyncAction`valor e não relatar progresso, retorna . Se sua função de trabalho não retornar um `create_async` `IAsyncActionWithProgress`valor e também relatar progresso, retorna . Para relatar o progresso, forneça um objeto [concurrency::progress_reporter](../../parallel/concrt/reference/progress-reporter-class.md) como parâmetro para sua função de trabalho. A capacidade de relatar o progresso permite informar qual a quantidade de trabalho realizada e qual a quantidade ainda permanece (por exemplo, em percentagem). Ele também permite que você reporte resultados à medida que eles se tornam disponíveis.

As interfaces `IAsyncAction`, `IAsyncActionWithProgress<TProgress>`, `IAsyncOperation<TResult>` e `IAsyncActionOperationWithProgress<TProgress, TProgress>` fornecem um método `Cancel` que permite cancelar a operação assíncrona. A `task` classe trabalha com tokens de cancelamento. Quando você usa um token de cancelamento para cancelar o trabalho, o tempo de execução não inicia um novo trabalho que assina esse token. O trabalho que já está ativo pode monitorar seu token de cancelamento e parar quando puder. Este mecanismo é descrito em maior detalhe no [documento Cancelamento no PPL](cancellation-in-the-ppl.md). Você pode conectar o cancelamento`Cancel` de tarefas com os métodos do Windows Runtime de duas maneiras. Primeiro, você pode definir a função `create_async` de trabalho que você passa para pegar uma [simultisa::cancellation_token](../../parallel/concrt/reference/cancellation-token-class.md) objeto. Quando `Cancel` o método é chamado, este token de cancelamento é cancelado `task` e as `create_async` regras normais de cancelamento se aplicam ao objeto subjacente que suporta a chamada. Se você não fornecer um objeto `cancellation_token`, o objeto `task` subjacente define um de forma implícita. Defina um objeto `cancellation_token` quando você precisa responder de forma cooperativa ao cancelamento na sua função de trabalho. A seção [Exemplo: Controlando a Execução em um aplicativo de tempo de execução do Windows com C++ e XAML](#example-app) mostra um exemplo de como realizar o cancelamento em um aplicativo Universal Windows Platform (UWP) com C# e XAML que usa um componente C++ personalizado do Windows Runtime.

> [!WARNING]
> Em uma cadeia de continuações de tarefas, sempre limpe o estado e ligue [para a concorrência::cancel_current_task](reference/concurrency-namespace-functions.md#cancel_current_task) quando o token de cancelamento for cancelado. Se você retornar mais `cancel_current_task`cedo em vez de ligar, a operação passa para o estado completo em vez do estado cancelado.

A tabela a seguir resume as combinações que você pode usar para definir operações assíncronas em seu aplicativo.

|Para criar esta interface do Windows Runtime|Retornar este tipo de`create_async`|Passe esses tipos de parâmetros para sua função de trabalho para usar um token de cancelamento implícito|Passe esses tipos de parâmetros para sua função de trabalho para usar um token de cancelamento explícito|
|----------------------------------------------------------------------------------|------------------------------------------|--------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
|`IAsyncAction`|`void` ou `task<void>`|(nenhum)|(`cancellation_token`)|
|`IAsyncActionWithProgress<TProgress>`|`void` ou `task<void>`|(`progress_reporter`)|(`progress_reporter`, `cancellation_token`)|
|`IAsyncOperation<TResult>`|`T` ou `task<T>`|(nenhum)|(`cancellation_token`)|
|`IAsyncActionOperationWithProgress<TProgress, TProgress>`|`T` ou `task<T>`|(`progress_reporter`)|(`progress_reporter`, `cancellation_token`)|

Você pode devolver um `task` valor ou um objeto da `create_async` função de trabalho que você passa para a função. Essas variações produzem comportamentos diferentes. Quando você retorna um valor, a `task` função de trabalho é embrulhada em um para que possa ser executada em um segmento de fundo. Além disso, o `task` subjacente usa um token de cancelamento implícito. Por outro lado, `task` se você retornar um objeto, a função de trabalho será executada ssincronizadamente. Portanto, se você `task` retornar um objeto, certifique-se de que quaisquer operações longas em sua função de trabalho também sejam executadas como tarefas para permitir que seu aplicativo permaneça responsivo. Além disso, o `task` fisiona não usa um token de cancelamento implícito. Portanto, você precisa definir sua função `cancellation_token` de trabalho para levar um objeto `task` se `create_async`você precisar de suporte para cancelamento quando você retornar um objeto de .

O exemplo a seguir mostra `IAsyncAction` as várias maneiras de criar um objeto que pode ser consumido por outro componente do Windows Runtime.

[!code-cpp[concrt-windowsstore-primes#100](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_1.cpp)]

## <a name="example-creating-a-c-windows-runtime-component-and-consuming-it-from-c"></a><a name="example-component"></a>Exemplo: Criar um componente de tempo de execução do C++ Windows e consumi-lo a partir de C\#

Considere um aplicativo que usa XAML e C# para definir a ui e um componente C++ Windows Runtime para executar operações com uso intensivo de computação. Neste exemplo, o componente C++ calcula quais números em um determinado intervalo são primos. Para ilustrar as diferenças entre as quatro interfaces de tarefa assíncronas do Windows `Primes`Runtime, inicie, no Visual Studio, criando uma solução em **branco** e nomeando-a . Em seguida, adicione à solução um projeto **do Windows Runtime Component** e nomeie-o `PrimesLibrary`. Adicione o seguinte código ao arquivo de cabeçalho C++ gerado (este exemplo renomeia Class1.h para Primes.h). Cada `public` método define uma das quatro interfaces assíncronas. Os métodos que retornam um valor retornam um [objeto Windows::Foundation::Collections::IVector\<int>.](/uwp/api/Windows.Foundation.Collections.IVector_T_) Os métodos que `double` relatam o progresso produzem valores que definem o percentual do trabalho global que foi concluído.

[!code-cpp[concrt-windowsstore-primes#1](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_2.h)]

> [!NOTE]
> Por convenção, nomes de métodos assíncronos no Windows Runtime normalmente terminam com "Assync".

Adicione o seguinte código ao arquivo de origem C++ gerado (este exemplo renomeia Class1.cpp para Primes.cpp). A `is_prime` função determina se sua entrada é primo. Os demais métodos implementam a `Primes` classe. Cada chamada `create_async` para usar uma assinatura compatível com o método do qual é chamada. Por exemplo, `Primes::ComputePrimesAsync` `IAsyncAction`porque retorna, a função de `create_async` trabalho que é fornecida não retorna `progress_reporter` um valor e não toma um objeto como parâmetro.

[!code-cpp[concrt-windowsstore-primes#2](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_3.cpp)]

Cada método primeiro realiza a validação para garantir que os parâmetros de entrada não sejam negativos. Se um valor de entrada for negativo, o método será inserido [plataforma::InvalidArgumentException](../../cppcx/platform-invalidargumentexception-class.md). O manuseio de erros é explicado mais tarde nesta seção.

Para consumir esses métodos a partir de um aplicativo UWP, use o modelo Visual C# **Blank App (XAML)** para adicionar um segundo projeto à solução Visual Studio. Este exemplo nomeia o projeto `Primes`. Em seguida, `Primes` a partir do `PrimesLibrary` projeto, adicione uma referência ao projeto.

Adicione o seguinte código ao MainPage.xaml. Este código define a ui para que você possa chamar o componente C++ e exibir resultados.

[!code-xml[concrt-windowsstore-primes#3](../../parallel/concrt/codesnippet/xaml/creating-asynchronous-operations-in-cpp-for-windows-store-apps_4.xaml)]

Adicione o seguinte `MainPage` código à classe em MainPage.xaml. Este código define `Primes` um objeto e os manipuladores de eventos do botão.

[!code-cs[concrt-windowsstore-primes#4](../../parallel/concrt/codesnippet/csharp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_5.cs)]

Esses métodos `async` usam `await` as palavras-chave para atualizar a ui após a conclusão das operações assíncronas. Para obter informações sobre codificação assíncrona em aplicativos UWP, consulte [Threading e programação assíncrona](/windows/uwp/threading-async).

Os `getPrimesCancellation` `cancelGetPrimes` métodos e métodos trabalham em conjunto para permitir que o usuário cancele a operação. Quando o usuário escolhe o `cancelGetPrimes` botão **Cancelar,** o método chama [IAsyncOperationWithProgress\<TResult, TProgress>::Cancele](/uwp/api/windows.foundation.iasyncinfo.cancel) para cancelar a operação. O Concurrency Runtime, que gerencia a operação assíncrona subjacente, lança um tipo de exceção interna que é capturado pelo Windows Runtime para comunicar que o cancelamento foi concluído. Para obter mais informações sobre o modelo de cancelamento, consulte [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md).

> [!IMPORTANT]
> Para permitir que o PPL informe corretamente ao Windows Runtime que ele cancelou a operação, não pegue esse tipo de exceção interna. Isso significa que você também não`catch (...)`deve pegar todas as exceções ( . Se você tiver que pegar todas as exceções, rejogue a exceção para garantir que o Windows Runtime possa concluir a operação de cancelamento.

A ilustração `Primes` a seguir mostra o aplicativo após cada opção ter sido escolhida.

![Aplicativo Windows Runtime Primes](../../parallel/concrt/media/concrt_windows_primes.png "Aplicativo Windows Runtime Primes")

Para exemplos que `create_async` usam para criar tarefas assíncronas que podem ser consumidas por outros idiomas, consulte [Usando C++ na amostra Bing Maps Trip Optimizer](/previous-versions/windows/apps/hh699891(v=vs.140)) e [Windows 8 Operações Assíncronas em C++ com PPL](https://code.msdn.microsoft.com/windowsapps/windows-8-asynchronous-08009a0d).

## <a name="controlling-the-execution-thread"></a><a name="exethread"></a>Controlando o segmento de execução

O Windows Runtime usa o modelo de rosca COM. Neste modelo, os objetos são hospedados em diferentes apartamentos, dependendo de como lidam com sua sincronização. Objetos seguros para rosca estão hospedados no apartamento multi-threaded (MTA). Os objetos que devem ser acessados por um único segmento estão hospedados em um apartamento de um único segmento (STA).

Em um aplicativo que tem uma interface do usuário, o segmento ASTA (Application STA) é responsável por bombear mensagens de janela e é o único segmento no processo que pode atualizar os controles de interface do usuário hospedados pela STA. Isso tem duas consequências. Primeiro, para permitir que o aplicativo permaneça responsivo, todas as operações de I/O intensivas em CPU e Não devem ser executadas no segmento ASTA. Em segundo lugar, os resultados provenientes de threads de fundo devem ser recolocados de volta à ASTA para atualizar a ui. Em um aplicativo C++ `MainPage` UWP e em outras páginas XAML, todas são executadas no ATSA. Portanto, as continuações de tarefas que são declaradas no ASTA são executadas lá por padrão para que você possa atualizar os controles diretamente no corpo de continuação. No entanto, se você aninhar uma tarefa em outra tarefa, quaisquer continuações nessa tarefa aninhada são executadas no MTA. Portanto, você precisa considerar se deve especificar explicitamente em que contexto essas continuações são executadas.

Uma tarefa criada a partir de uma operação assíncrona, como, `IAsyncOperation<TResult>`usa semântica especial que pode ajudá-lo a ignorar os detalhes de rosca. Embora uma operação possa ser executada em um segmento de fundo (ou pode não ser apoiada por um segmento em tudo), suas continuações `task::then`são por padrão garantidas para executar no apartamento que iniciou as operações de continuação (em outras palavras, a partir do apartamento que chamou ). Você pode usar a [classe de concorrência::task_continuation_context](../../parallel/concrt/reference/task-continuation-context-class.md) para controlar o contexto de execução de uma continuação. Use esses métodos de `task_continuation_context` ajuda estática para criar objetos:

- Use [simultu:task_continuation_context::use_arbitrary](reference/task-continuation-context-class.md#use_arbitrary) para especificar que a continuação é executada em um segmento de fundo.

- Use [a moeda:task_continuation_context::use_current](reference/task-continuation-context-class.md#use_current) para especificar que a `task::then`continuação é executada no segmento chamado .

Você pode `task_continuation_context` passar um objeto para a [tarefa::então](reference/task-class.md#then) o método para controlar explicitamente o contexto de `task::then` execução da continuação ou você pode passar a tarefa para outro apartamento e, em seguida, chamar o método para controlar implicitamente o contexto de execução.

> [!IMPORTANT]
> Como o segmento principal de interface do ui dos aplicativos UWP é executado em STA, as continuações que você cria nesse STA por padrão são executadas no STA. Assim, as continuações que você cria no MTA são executadas no MTA.

A seção a seguir mostra um aplicativo que lê um arquivo de disco, encontra as palavras mais comuns nesse arquivo e, em seguida, mostra os resultados na ui. A operação final, atualizando a ui, ocorre no segmento de IA.

> [!IMPORTANT]
> Esse comportamento é específico para aplicativos UWP. Para aplicativos de desktop, você não controla onde as continuações são executadas. Em vez disso, o agendador escolhe um segmento de trabalhador no qual executar cada continuação.

> [!IMPORTANT]
> Não chame [simultu::task::wait](reference/task-class.md#wait) in the body of a continuation que é executado no STA. Caso contrário, o tempo de execução joga [simultâneo::invalid_operation](../../parallel/concrt/reference/invalid-operation-class.md) porque este método bloqueia o segmento atual e pode fazer com que o aplicativo fique sem resposta. No entanto, você pode chamar o método [de concorrência::task::get](reference/task-class.md#get) para receber o resultado da tarefa antecedente em uma continuação baseada em tarefas.

## <a name="example-controlling-execution-in-a-windows-runtime-app-with-c-and-xaml"></a><a name="example-app"></a>Exemplo: Controlando a execução em um aplicativo de tempo de execução do Windows com C++ e XAML

Considere um aplicativo C++ XAML que lê um arquivo de disco, encontra as palavras mais comuns nesse arquivo e, em seguida, mostra os resultados na ui. Para criar este aplicativo, inicie, no Visual Studio, criando um projeto `CommonWords`de Aplicativo em Branco **(Universal Windows)** e nomeando-o . No manifesto do aplicativo, especifique o recurso **Biblioteca de Documentos** para permitir que o aplicativo acesse a pasta Documentos. Adicione também o tipo de arquivo Texto (.txt) à seção de declarações do manifesto do aplicativo. Para obter mais informações sobre os recursos e declarações do aplicativo, consulte [Embalagem, implantação e consulta de aplicativos windows](/windows/win32/appxpkg/appx-portal).

Atualize `Grid` o elemento em MainPage.xaml para incluir um `ProgressRing` elemento e um `TextBlock` elemento. O `ProgressRing` indica que a operação `TextBlock` está em andamento e mostra os resultados do cálculo.

[!code-xml[concrt-windowsstore-commonwords#1](../../parallel/concrt/codesnippet/xaml/creating-asynchronous-operations-in-cpp-for-windows-store-apps_6.xaml)]

Adicione as `#include` seguintes instruções a *pch.h*.

[!code-cpp[concrt-windowsstore-commonwords#2](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_7.h)]

Adicione as seguintes declarações de método à `MainPage` classe (MainPage.h).

[!code-cpp[concrt-windowsstore-commonwords#3](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_8.h)]

Adicione as `using` seguintes instruções ao MainPage.cpp.

[!code-cpp[concrt-windowsstore-commonwords#4](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_9.cpp)]

No MainPage.cpp, `MainPage::MakeWordList`implemente os `MainPage::FindCommonWords`métodos e `MainPage::ShowResults` métodos. E `MainPage::MakeWordList` `MainPage::FindCommonWords` realizar operações computacionalmente intensivas. O `MainPage::ShowResults` método exibe o resultado da computação na ui.

[!code-cpp[concrt-windowsstore-commonwords#5](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_10.cpp)]

Modifique `MainPage` o construtor para criar uma cadeia de tarefas de continuação que exibe na UI as palavras comuns no livro *A Ilíada* por Homero. As duas primeiras tarefas de continuação, que dividem o texto em palavras individuais e encontram palavras comuns, podem ser demoradas e, portanto, são explicitamente definidas para serem executadas em segundo plano. A tarefa final de continuação, que atualiza a interface do usuário, não especifica nenhum contexto de continuação e, portanto, segue as regras de threading do apartamento.

[!code-cpp[concrt-windowsstore-commonwords#6](../../parallel/concrt/codesnippet/cpp/creating-asynchronous-operations-in-cpp-for-windows-store-apps_11.cpp)]

> [!NOTE]
> Este exemplo demonstra como especificar contextos de execução e como compor uma cadeia de continuações. Lembre-se que, por padrão, uma tarefa criada a partir de uma operação `task::then`assíncrona executa suas continuações no apartamento que chamou . Portanto, este exemplo `task_continuation_context::use_arbitrary` usa para especificar que as operações que não envolvem a ui serão executadas em um segmento de fundo.

A ilustração a seguir `CommonWords` mostra os resultados do aplicativo.

![Aplicativo Windows Runtime CommonWords](../../parallel/concrt/media/concrt_windows_common_words.png "Aplicativo Windows Runtime CommonWords")

Neste exemplo, é possível suportar o `task` cancelamento porque `create_async` os objetos que suportam usam um token de cancelamento implícito. Defina sua função `cancellation_token` de trabalho para levar um objeto se suas tarefas precisarem responder ao cancelamento de forma cooperativa. Para obter mais informações sobre o cancelamento no PPL, consulte [Cancelamento no PPL](cancellation-in-the-ppl.md)

## <a name="see-also"></a>Confira também

[Runtime de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)
