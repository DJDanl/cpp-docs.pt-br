---
title: Como manipular eventos com WRL
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 1c77543f-7b0c-4a94-93bf-e3225885ed76
ms.openlocfilehash: 0e13212d7cb481bc72a903a31fb170fd1ff8b7ec
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213922"
---
# <a name="how-to-handle-events-using-wrl"></a>Como manipular eventos com WRL

Este documento mostra como usar a WRL ( C++ biblioteca de modelos de Windows Runtime) para assinar e manipular os eventos de um objeto de Windows Runtime.

Para obter um exemplo mais básico que cria uma instância desse componente e recupera um valor de propriedade, consulte [como: ativar e usar um componente de Windows Runtime](how-to-activate-and-use-a-windows-runtime-component-using-wrl.md).

## <a name="subscribing-to-and-handling-events"></a>Inscrevendo e manipulando eventos

As etapas a seguir iniciam um objeto `ABI::Windows::System::Threading::IDeviceWatcher` e usam manipuladores de eventos para monitorar o progresso. A interface `IDeviceWatcher` permite que você enumere dispositivos de forma assíncrona, ou em segundo plano, e receba notificações quando os dispositivos forem adicionados, removidos ou alterados. A função de [retorno de chamada](callback-function-wrl.md) é uma parte importante deste exemplo porque ela permite especificar manipuladores de eventos que processam os resultados da operação em segundo plano. Veja a seguir o exemplo completo.

> [!WARNING]
> Embora você normalmente use a Windows Runtime C++ biblioteca de modelos em um aplicativo plataforma universal do Windows, este exemplo usa um aplicativo de console para ilustração. Funções como `wprintf_s` não estão disponíveis em um aplicativo Plataforma Universal do Windows. Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo Plataforma Universal do Windows, consulte [funções CRT sem suporte em aplicativos plataforma universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) e [Win32 e com para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).

1. Incluir (`#include`) qualquer Windows Runtime necessário, Windows Runtime C++ biblioteca de modelos ou C++ cabeçalhos de biblioteca padrão.

   [!code-cpp[wrl-consume-event#2](../codesnippet/CPP/how-to-handle-events-using-wrl_1.cpp)]

   `Windows.Devices.Enumeration.h` declara os tipos necessários para enumerar dispositivos.

   Recomendamos que você utilize a diretiva `using namespace` em seu arquivo. cpp para tornar o código mais legível.

2. Declare as variáveis locais para o aplicativo. Este exemplo mantém a contagem do número de dispositivos enumerados e tokens de registro que o habilitam a cancelar a assinatura posterior de eventos.

   [!code-cpp[wrl-consume-event#7](../codesnippet/CPP/how-to-handle-events-using-wrl_2.cpp)]

3. Inicialize o Windows Runtime.

   [!code-cpp[wrl-consume-event#3](../codesnippet/CPP/how-to-handle-events-using-wrl_3.cpp)]

4. Crie um objeto de [evento](event-class-wrl.md) que sincroniza a conclusão do processo de enumeração para o aplicativo principal.

   [!code-cpp[wrl-consume-event#4](../codesnippet/CPP/how-to-handle-events-using-wrl_4.cpp)]

   > [!NOTE]
   > Esse evento é para demonstração somente como parte de um aplicativo de console. Este exemplo usa o evento para garantir que uma operação assíncrona seja concluída antes de o aplicativo ser encerrado. Na maioria dos aplicativos, normalmente você não espera que as operações assíncronas sejam concluídas.

5. Crie uma fábrica de ativação para a interface `IDeviceWatcher`.

   [!code-cpp[wrl-consume-event#5](../codesnippet/CPP/how-to-handle-events-using-wrl_5.cpp)]

   O Windows Runtime usa nomes totalmente qualificados para identificar tipos. O parâmetro `RuntimeClass_Windows_Devices_Enumeration_DeviceInformation` é uma cadeia de caracteres fornecida pelo Windows Runtime e contém o nome de classe de tempo de execução necessário.

6. Crie o objeto `IDeviceWatcher`.

   [!code-cpp[wrl-consume-event#6](../codesnippet/CPP/how-to-handle-events-using-wrl_6.cpp)]

7. Use a função `Callback` para assinar os eventos `Added`, `EnumerationCompleted`e `Stopped`.

   [!code-cpp[wrl-consume-event#8](../codesnippet/CPP/how-to-handle-events-using-wrl_7.cpp)]

   O manipulador de eventos `Added` incrementa a contagem de dispositivos enumerados. Ele interrompe o processo de enumeração depois que dez dispositivos são encontrados.

   O manipulador de eventos `Stopped` remove os manipuladores de eventos e define o evento de conclusão.

   O manipulador de eventos `EnumerationCompleted` para o processo de enumeração. Tratamos desse evento caso haja menos de dez dispositivos.

   > [!TIP]
   > Este exemplo usa uma expressão lambda para definir os retornos de chamada. Você também pode usar objetos de função (transmissão functors), ponteiros de função ou objetos [std:: function](../../standard-library/function-class.md) . Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

8. Inicie o processo de enumeração.

   [!code-cpp[wrl-consume-event#9](../codesnippet/CPP/how-to-handle-events-using-wrl_8.cpp)]

9. Aguarde até que o processo de enumeração seja concluído e, em seguida, imprima uma mensagem. Todos os objetos `ComPtr` e RAII deixam o escopo e são liberados automaticamente.

   [!code-cpp[wrl-consume-event#10](../codesnippet/CPP/how-to-handle-events-using-wrl_9.cpp)]

Aqui está o exemplo completo:

[!code-cpp[wrl-consume-event#1](../codesnippet/CPP/how-to-handle-events-using-wrl_10.cpp)]

## <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `wrl-consume-events.cpp` e, em seguida, execute o comando a seguir em uma janela de **prompt de comando do Visual Studio** .

`cl.exe wrl-consume-events.cpp runtimeobject.lib`

## <a name="see-also"></a>Confira também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](windows-runtime-cpp-template-library-wrl.md)
