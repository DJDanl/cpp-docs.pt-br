---
title: 'Como: Executar operações assíncronas com WRL'
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 02173eae-731b-49bc-b412-f1f69388b99d
ms.openlocfilehash: 321bb273f661ec16fe85443c449b425ae56b99e3
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783885"
---
# <a name="how-to-complete-asynchronous-operations-using-wrl"></a>Como: Executar operações assíncronas com WRL

Este documento mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ (WRL) para iniciar operações assíncronas e executar o trabalho quando as operações forem concluídas.

Este documento mostra dois exemplos. O primeiro exemplo inicia um cronômetro assíncrono e aguarda o timer para expirar. Neste exemplo, você especificar a ação assíncrona quando você cria o objeto de timer. O segundo exemplo executa um thread de trabalho em segundo plano. Este exemplo mostra como trabalhar com um método de tempo de execução do Windows que retorna um `IAsyncInfo` interface. O [retorno de chamada](callback-function-wrl.md) função é uma parte importante de ambos os exemplos porque ela permite especificar um manipulador de eventos para processar os resultados das operações assíncronas.

Para obter um exemplo mais simples que cria uma instância de um componente e recupera um valor de propriedade, consulte [como: Ativar e usar um componente de tempo de execução do Windows](how-to-activate-and-use-a-windows-runtime-component-using-wrl.md).

> [!TIP]
> Esses exemplos usam expressões lambda para definir os retornos de chamada. Você também pode usar objetos de função (functors), ponteiros de função, ou [std:: Function](../../standard-library/function-class.md) objetos. Para obter mais informações sobre expressões lambda de C++, consulte [expressões Lambda](../../cpp/lambda-expressions-in-cpp.md).

## <a name="example-working-with-a-timer"></a>Exemplo: Trabalhando com um temporizador

As etapas a seguir inicia um temporizador assíncrono e aguarde até que o temporizador expire. Segue o exemplo completo.

> [!WARNING]
> Embora você normalmente usa a biblioteca de modelos de C++ de tempo de execução do Windows em um aplicativo da plataforma Universal do Windows (UWP), este exemplo usa um aplicativo de console para fins ilustrativos. As funções, como `wprintf_s` não estão disponíveis de um aplicativo UWP. Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo UWP, consulte [funções de CRT sem suporte em aplicativos da plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) e [Win32 e COM para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).

1. Incluir (`#include`) todas as necessárias em tempo de execução do Windows, biblioteca de modelos de C++ de tempo de execução do Windows ou cabeçalhos de biblioteca padrão C++.

   [!code-cpp[wrl-consume-async#2](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_1.cpp)]

   `Windows.System.Threading.h` declara os tipos que são necessários para usar um temporizador de assíncrono.

   É recomendável que você utilize o `using namespace` diretiva em seu arquivo. cpp para tornar o código mais legível.

2. Inicialize o tempo de execução do Windows.

   [!code-cpp[wrl-consume-async#3](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_2.cpp)]

3. Criar uma fábrica de ativação para o `ABI::Windows::System::Threading::IThreadPoolTimer` interface.

   [!code-cpp[wrl-consume-async#4](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_3.cpp)]

   O tempo de execução do Windows usa nomes totalmente qualificados para identificar tipos. O `RuntimeClass_Windows_System_Threading_ThreadPoolTimer` parâmetro é uma cadeia de caracteres que é fornecida pelo tempo de execução do Windows e contém o nome de classe de tempo de execução necessários.

4. Criar uma [evento](event-class-wrl.md) objeto que sincroniza o retorno de chamada do temporizador para o aplicativo principal.

   [!code-cpp[wrl-consume-async#5](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_4.cpp)]

   > [!NOTE]
   > Esse evento é para demonstração somente como parte de um aplicativo de console. Este exemplo usa o evento para garantir que uma operação assíncrona seja concluída antes de sair do aplicativo. Na maioria dos aplicativos, você normalmente não aguardar a conclusão das operações de async.

5. Criar um `IThreadPoolTimer` objeto expira após dois segundos. Use o `Callback` função para criar o manipulador de eventos (um `ABI::Windows::System::Threading::ITimerElapsedHandler` objeto).

   [!code-cpp[wrl-consume-async#6](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_5.cpp)]

6. Imprimir uma mensagem no console e aguarde o retorno de chamada do temporizador ser concluída. Todos os `ComPtr` e há objetos RAII deixar o escopo e são liberados automaticamente.

   [!code-cpp[wrl-consume-async#7](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_6.cpp)]

Aqui está o exemplo completo:

[!code-cpp[wrl-consume-async#1](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_7.cpp)]

### <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `wrl-consume-async.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

`cl.exe wrl-consume-async.cpp runtimeobject.lib`

## <a name="example-working-with-a-background-thread"></a>Exemplo: Trabalhando com um Thread em segundo plano

As etapas a seguir iniciar um thread de trabalho e definem a ação que é executada por esse thread. Segue o exemplo completo.

> [!TIP]
> Este exemplo demonstra como trabalhar com o `ABI::Windows::Foundation::IAsyncAction` interface. Você pode aplicar esse padrão para qualquer interface que implementa `IAsyncInfo`: `IAsyncAction`, `IAsyncActionWithProgress`, `IAsyncOperation`, e `IAsyncOperationWithProgress`.

1. Incluir (`#include`) todas as necessárias em tempo de execução do Windows, biblioteca de modelos de C++ de tempo de execução do Windows ou cabeçalhos de biblioteca padrão C++.

   [!code-cpp[wrl-consume-asyncOp#2](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_8.cpp)]

   Windows.System.Threading.h declara os tipos que são necessários para usar um thread de trabalho.

   É recomendável que você use o `using namespace` diretiva em seu arquivo. cpp para tornar o código mais legível.

2. Inicialize o tempo de execução do Windows.

   [!code-cpp[wrl-consume-asyncOp#3](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_9.cpp)]

3. Criar uma fábrica de ativação para o `ABI::Windows::System::Threading::IThreadPoolStatics` interface.

   [!code-cpp[wrl-consume-asyncOp#4](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_10.cpp)]

4. Criar uma [evento](event-class-wrl.md) objeto que sincroniza a conclusão do thread de trabalho para o aplicativo principal.

   [!code-cpp[wrl-consume-asyncOp#5](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_11.cpp)]

   > [!NOTE]
   > Esse evento é para demonstração somente como parte de um aplicativo de console. Este exemplo usa o evento para garantir que uma operação assíncrona seja concluída antes de sair do aplicativo. Na maioria dos aplicativos, você normalmente não aguardar a conclusão das operações de async.

5. Chamar o `IThreadPoolStatics::RunAsync` método para criar um thread de trabalho. Use o `Callback` função para definir a ação.

   [!code-cpp[wrl-consume-asyncOp#6](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_12.cpp)]

   O `IsPrime` função é definida no exemplo completo que segue.

6. Imprimir uma mensagem no console e aguarde até que o thread concluir. Todos os `ComPtr` e há objetos RAII deixar o escopo e são liberados automaticamente.

   [!code-cpp[wrl-consume-asyncOp#7](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_13.cpp)]

Aqui está o exemplo completo:

[!code-cpp[wrl-consume-asyncOp#1](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_14.cpp)]

### <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `wrl-consume-asyncOp.cpp` e, em seguida, execute o seguinte comando um **Prompt de comando do Visual Studio** janela.

`cl.exe wrl-consume-asyncOp.cpp runtimeobject.lib`

## <a name="see-also"></a>Consulte também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](windows-runtime-cpp-template-library-wrl.md)