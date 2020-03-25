---
title: Como executar operações assíncronas com WRL
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 02173eae-731b-49bc-b412-f1f69388b99d
ms.openlocfilehash: 8e7e52342cf73a56c6c33d4d1f998f446d632ddd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213935"
---
# <a name="how-to-complete-asynchronous-operations-using-wrl"></a>Como executar operações assíncronas com WRL

Este documento mostra como usar a WRL ( C++ biblioteca de modelos de Windows Runtime) para iniciar operações assíncronas e executar o trabalho quando as operações forem concluídas.

Este documento mostra dois exemplos. O primeiro exemplo inicia um temporizador assíncrono e aguarda até que o temporizador expire. Neste exemplo, você especifica a ação assíncrona ao criar o objeto de timer. O segundo exemplo executa um thread de trabalho em segundo plano. Este exemplo mostra como trabalhar com um método Windows Runtime que retorna uma interface `IAsyncInfo`. A função de [retorno de chamada](callback-function-wrl.md) é uma parte importante dos dois exemplos, pois permite que eles especifiquem um manipulador de eventos para processar os resultados das operações assíncronas.

Para obter um exemplo mais básico que cria uma instância de um componente e recupera um valor de propriedade, consulte [como: ativar e usar um componente de Windows Runtime](how-to-activate-and-use-a-windows-runtime-component-using-wrl.md).

> [!TIP]
> Esses exemplos usam expressões lambda para definir os retornos de chamada. Você também pode usar objetos de função (transmissão functors), ponteiros de função ou objetos [std:: function](../../standard-library/function-class.md) . Para obter mais informações C++ sobre expressões lambda, consulte [expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

## <a name="example-working-with-a-timer"></a>Exemplo: trabalhando com um temporizador

As etapas a seguir iniciam um temporizador assíncrono e aguardam que o temporizador expire. Veja a seguir o exemplo completo.

> [!WARNING]
> Embora você normalmente use a Windows Runtime C++ biblioteca de modelos em um aplicativo plataforma universal do Windows (UWP), este exemplo usa um aplicativo de console para ilustração. Funções como `wprintf_s` não estão disponíveis em um aplicativo UWP. Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo UWP, consulte [funções CRT sem suporte em aplicativos plataforma universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) e [Win32 e com para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).

1. Incluir (`#include`) qualquer Windows Runtime necessário, Windows Runtime C++ biblioteca de modelos ou C++ cabeçalhos de biblioteca padrão.

   [!code-cpp[wrl-consume-async#2](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_1.cpp)]

   `Windows.System.Threading.h` declara os tipos necessários para usar um temporizador assíncrono.

   Recomendamos que você utilize a diretiva `using namespace` em seu arquivo. cpp para tornar o código mais legível.

2. Inicialize o Windows Runtime.

   [!code-cpp[wrl-consume-async#3](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_2.cpp)]

3. Crie uma fábrica de ativação para a interface `ABI::Windows::System::Threading::IThreadPoolTimer`.

   [!code-cpp[wrl-consume-async#4](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_3.cpp)]

   O Windows Runtime usa nomes totalmente qualificados para identificar tipos. O parâmetro `RuntimeClass_Windows_System_Threading_ThreadPoolTimer` é uma cadeia de caracteres fornecida pelo Windows Runtime e contém o nome de classe de tempo de execução necessário.

4. Crie um objeto de [evento](event-class-wrl.md) que sincroniza o retorno de chamada do temporizador para o aplicativo principal.

   [!code-cpp[wrl-consume-async#5](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_4.cpp)]

   > [!NOTE]
   > Esse evento é para demonstração somente como parte de um aplicativo de console. Este exemplo usa o evento para garantir que uma operação assíncrona seja concluída antes de o aplicativo ser encerrado. Na maioria dos aplicativos, normalmente você não espera que as operações assíncronas sejam concluídas.

5. Crie um objeto `IThreadPoolTimer` que expire após dois segundos. Use a função `Callback` para criar o manipulador de eventos (um objeto `ABI::Windows::System::Threading::ITimerElapsedHandler`).

   [!code-cpp[wrl-consume-async#6](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_5.cpp)]

6. Imprima uma mensagem no console e aguarde a conclusão do retorno de chamada do temporizador. Todos os objetos `ComPtr` e RAII deixam o escopo e são liberados automaticamente.

   [!code-cpp[wrl-consume-async#7](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_6.cpp)]

Aqui está o exemplo completo:

[!code-cpp[wrl-consume-async#1](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_7.cpp)]

### <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `wrl-consume-async.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

`cl.exe wrl-consume-async.cpp runtimeobject.lib`

## <a name="example-working-with-a-background-thread"></a>Exemplo: trabalhando com um thread em segundo plano

As etapas a seguir iniciam um thread de trabalho e definem a ação executada por esse thread. Veja a seguir o exemplo completo.

> [!TIP]
> Este exemplo demonstra como trabalhar com a interface `ABI::Windows::Foundation::IAsyncAction`. Você pode aplicar esse padrão a qualquer interface que implemente `IAsyncInfo`: `IAsyncAction`, `IAsyncActionWithProgress`, `IAsyncOperation`e `IAsyncOperationWithProgress`.

1. Incluir (`#include`) qualquer Windows Runtime necessário, Windows Runtime C++ biblioteca de modelos ou C++ cabeçalhos de biblioteca padrão.

   [!code-cpp[wrl-consume-asyncOp#2](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_8.cpp)]

   Windows. System. Threading. h declara os tipos que são necessários para usar um thread de trabalho.

   Recomendamos que você use a diretiva `using namespace` em seu arquivo. cpp para tornar o código mais legível.

2. Inicialize o Windows Runtime.

   [!code-cpp[wrl-consume-asyncOp#3](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_9.cpp)]

3. Crie uma fábrica de ativação para a interface `ABI::Windows::System::Threading::IThreadPoolStatics`.

   [!code-cpp[wrl-consume-asyncOp#4](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_10.cpp)]

4. Crie um objeto de [evento](event-class-wrl.md) que sincroniza a conclusão do thread de trabalho para o aplicativo principal.

   [!code-cpp[wrl-consume-asyncOp#5](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_11.cpp)]

   > [!NOTE]
   > Esse evento é para demonstração somente como parte de um aplicativo de console. Este exemplo usa o evento para garantir que uma operação assíncrona seja concluída antes de o aplicativo ser encerrado. Na maioria dos aplicativos, normalmente você não espera que as operações assíncronas sejam concluídas.

5. Chame o método `IThreadPoolStatics::RunAsync` para criar um thread de trabalho. Use a função `Callback` para definir a ação.

   [!code-cpp[wrl-consume-asyncOp#6](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_12.cpp)]

   A função `IsPrime` é definida no exemplo completo a seguir.

6. Imprima uma mensagem no console e aguarde a conclusão do thread. Todos os objetos `ComPtr` e RAII deixam o escopo e são liberados automaticamente.

   [!code-cpp[wrl-consume-asyncOp#7](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_13.cpp)]

Aqui está o exemplo completo:

[!code-cpp[wrl-consume-asyncOp#1](../codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_14.cpp)]

### <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `wrl-consume-asyncOp.cpp` e, em seguida, execute o comando a seguir em uma janela de **prompt de comando do Visual Studio** .

`cl.exe wrl-consume-asyncOp.cpp runtimeobject.lib`

## <a name="see-also"></a>Confira também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](windows-runtime-cpp-template-library-wrl.md)
