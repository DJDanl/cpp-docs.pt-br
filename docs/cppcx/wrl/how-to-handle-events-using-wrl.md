---
title: 'Como: Manipular eventos usando a WRL'
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 1c77543f-7b0c-4a94-93bf-e3225885ed76
ms.openlocfilehash: 959a85d6cf6de666ae56d09035acefe9a3828ae8
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59033171"
---
# <a name="how-to-handle-events-using-wrl"></a>Como: Manipular eventos usando a WRL

Este documento mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ (WRL) para assinar e manipular os eventos de um objeto de tempo de execução do Windows.

Para obter um exemplo mais simples que cria uma instância desse componente e recupera um valor de propriedade, consulte [como: Ativar e usar um componente de tempo de execução do Windows](how-to-activate-and-use-a-windows-runtime-component-using-wrl.md).

## <a name="subscribing-to-and-handling-events"></a>Assinando e manipulação de eventos

Iniciar as etapas a seguir um `ABI::Windows::System::Threading::IDeviceWatcher` de objeto e usar manipuladores de eventos para monitorar o progresso. O `IDeviceWatcher` interface permite enumerar dispositivos de forma assíncrona, ou em segundo plano e receber notificação quando dispositivos são adicionados, removidos ou alterados. O [retorno de chamada](callback-function-wrl.md) função é uma parte importante deste exemplo, porque ele habilita a especificar os manipuladores de eventos que processam os resultados da operação em segundo plano. Segue o exemplo completo.

> [!WARNING]
> Embora você normalmente usa a biblioteca de modelos de C++ de tempo de execução do Windows em um aplicativo da plataforma Universal do Windows, este exemplo usa um aplicativo de console para fins ilustrativos. As funções, como `wprintf_s` não estão disponíveis a partir de um aplicativo da plataforma Universal do Windows. Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo da plataforma Universal do Windows, consulte [funções de CRT sem suporte em aplicativos da plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) e [Win32 e COM para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).

1. Incluir (`#include`) todas as necessárias em tempo de execução do Windows, biblioteca de modelos de C++ de tempo de execução do Windows ou cabeçalhos de biblioteca padrão C++.

   [!code-cpp[wrl-consume-event#2](../codesnippet/CPP/how-to-handle-events-using-wrl_1.cpp)]

   `Windows.Devices.Enumeration.h` declara os tipos que são necessárias para enumerar os dispositivos.

   É recomendável que você utilize o `using namespace` diretiva em seu arquivo. cpp para tornar o código mais legível.

2. Declare as variáveis locais para o aplicativo. Este exemplo contém a contagem do número de dispositivos enumerados e tokens do registro que permitirão que ele mais tarde Cancelar assinatura de eventos.

   [!code-cpp[wrl-consume-event#7](../codesnippet/CPP/how-to-handle-events-using-wrl_2.cpp)]

3. Inicialize o tempo de execução do Windows.

   [!code-cpp[wrl-consume-event#3](../codesnippet/CPP/how-to-handle-events-using-wrl_3.cpp)]

4. Criar uma [evento](event-class-wrl.md) objeto que sincroniza a conclusão do processo de enumeração para o aplicativo principal.

   [!code-cpp[wrl-consume-event#4](../codesnippet/CPP/how-to-handle-events-using-wrl_4.cpp)]

   > [!NOTE]
   > Esse evento é para demonstração somente como parte de um aplicativo de console. Este exemplo usa o evento para garantir que uma operação assíncrona seja concluída antes de sair do aplicativo. Na maioria dos aplicativos, você normalmente não aguardar a conclusão das operações de async.

5. Criar uma fábrica de ativação para o `IDeviceWatcher` interface.

   [!code-cpp[wrl-consume-event#5](../codesnippet/CPP/how-to-handle-events-using-wrl_5.cpp)]

   O tempo de execução do Windows usa nomes totalmente qualificados para identificar tipos. O `RuntimeClass_Windows_Devices_Enumeration_DeviceInformation` parâmetro é uma cadeia de caracteres que é fornecida pelo tempo de execução do Windows e contém o nome de classe de tempo de execução necessários.

6. Criar o `IDeviceWatcher` objeto.

   [!code-cpp[wrl-consume-event#6](../codesnippet/CPP/how-to-handle-events-using-wrl_6.cpp)]

7. Use o `Callback` função para assinar o `Added`, `EnumerationCompleted`, e `Stopped` eventos.

   [!code-cpp[wrl-consume-event#8](../codesnippet/CPP/how-to-handle-events-using-wrl_7.cpp)]

   O `Added` manipulador de eventos incrementa a contagem de dispositivos enumerados. Ele interrompe o processo de enumeração após dez dispositivos forem encontrados.

   O `Stopped` remove os manipuladores de eventos de manipulador de eventos e define o evento de conclusão.

   O `EnumerationCompleted` manipulador de eventos interromperá o processo de enumeração. Podemos manipular esse evento, caso haja menos de dez dispositivos.

   > [!TIP]
   > Este exemplo usa uma expressão lambda para definir os retornos de chamada. Você também pode usar objetos de função (functors), ponteiros de função, ou [std:: Function](../../standard-library/function-class.md) objetos. Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

8. Inicie o processo de enumeração.

   [!code-cpp[wrl-consume-event#9](../codesnippet/CPP/how-to-handle-events-using-wrl_8.cpp)]

9. Aguarde o processo de enumeração concluir e, em seguida, imprima uma mensagem. Todos os `ComPtr` e há objetos RAII deixar o escopo e são liberados automaticamente.

   [!code-cpp[wrl-consume-event#10](../codesnippet/CPP/how-to-handle-events-using-wrl_9.cpp)]

Aqui está o exemplo completo:

[!code-cpp[wrl-consume-event#1](../codesnippet/CPP/how-to-handle-events-using-wrl_10.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `wrl-consume-events.cpp` e, em seguida, execute o seguinte comando um **Prompt de comando do Visual Studio** janela.

`cl.exe wrl-consume-events.cpp runtimeobject.lib`

## <a name="see-also"></a>Consulte também

[Biblioteca de Modelos C++ do Windows Runtime  (WRL)](windows-runtime-cpp-template-library-wrl.md)