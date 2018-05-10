---
title: 'Como: manipular eventos com WRL | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 1c77543f-7b0c-4a94-93bf-e3225885ed76
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a3c1666d1c79414beddc5b5e3ccc03953c92e902
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="how-to-handle-events-using-wrl"></a>Como manipular eventos com WRL
Este documento mostra como usar a biblioteca de modelo (WRL) do Windows em tempo de execução C++ para assinar e tratar os eventos de um objeto de tempo de execução do Windows.  
  
 Para obter um exemplo mais simples que cria uma instância do componente e recupera um valor de propriedade, consulte [como: ativar e usar um componente de tempo de execução do Windows](../windows/how-to-activate-and-use-a-windows-runtime-component-using-wrl.md).  
  
## <a name="subscribing-to-and-handling-events"></a>Assinar e manipulação de eventos  
 Iniciar as etapas a seguir um `ABI::Windows::System::Threading::IDeviceWatcher` do objeto e usar manipuladores de eventos para monitorar o progresso. O `IDeviceWatcher` interface permite enumerar dispositivos, de forma assíncrona ou no plano de fundo e receber notificação quando os dispositivos são adicionados, removidos ou alterados. O [retorno de chamada](../windows/callback-function-windows-runtime-cpp-template-library.md) função é uma parte importante deste exemplo porque permite que ele Especifique manipuladores de eventos que processam os resultados da operação em segundo plano. O exemplo completo segue.  
  
> [!WARNING]
>  Embora você costumar usar a biblioteca de modelos de C++ de tempo de execução do Windows em um aplicativo de plataforma Universal do Windows, este exemplo usa um aplicativo de console para fins ilustrativos. Funções como `wprintf_s` não estão disponíveis de um aplicativo de plataforma Universal do Windows. Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo de plataforma Universal do Windows, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) e [Win32 e COM para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).  
  
1.  Incluir (`#include`) os necessários do Windows Runtime, biblioteca de modelos C++ do Windows Runtime ou cabeçalhos de biblioteca padrão C++.  
  
     [!code-cpp[wrl-consume-event#2](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_1.cpp)]  
  
     Windows.Devices.Enumeration.h declara os tipos que são necessárias para enumerar os dispositivos.  
  
     É recomendável que você utiliza o `using namespace` diretiva no arquivo. cpp para tornar o código mais legível.  
  
2.  Declare as variáveis locais para o aplicativo. Este exemplo contém a contagem do número de dispositivos enumerados e tokens de registro que habilitá-lo mais tarde, cancelar a assinatura de eventos.  
  
     [!code-cpp[wrl-consume-event#7](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_2.cpp)]  
  
3.  Inicialize o tempo de execução do Windows.  
  
     [!code-cpp[wrl-consume-event#3](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_3.cpp)]  
  
4.  Criar um [evento](../windows/event-class-windows-runtime-cpp-template-library.md) objeto que sincroniza a conclusão do processo de enumeração para o aplicativo principal.  
  
     [!code-cpp[wrl-consume-event#4](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_4.cpp)]  
  
    > [!NOTE]
    >  Esse evento é para demonstração somente como parte de um aplicativo de console. Este exemplo usa o evento para garantir que uma operação assíncrona é concluída antes do aplicativo sai. Na maioria dos aplicativos, você normalmente não esperam para operações assíncronas sejam concluídas.  
  
5.  Criar uma fábrica de ativação para o `IDeviceWatcher` interface.  
  
     [!code-cpp[wrl-consume-event#5](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_5.cpp)]  
  
     O tempo de execução do Windows usa nomes totalmente qualificados para identificar tipos. O `RuntimeClass_Windows_Devices_Enumeration_DeviceInformation` parâmetro é uma cadeia de caracteres que é fornecida pelo Windows Runtime e contém o nome de classe de tempo de execução necessários.  
  
6.  Criar o `IDeviceWatcher` objeto.  
  
     [!code-cpp[wrl-consume-event#6](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_6.cpp)]  
  
7.  Use o `Callback` função para assinar o `Added`, `EnumerationCompleted`, e `Stopped` eventos.  
  
     [!code-cpp[wrl-consume-event#8](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_7.cpp)]  
  
     O `Added` manipulador de eventos incrementa a contagem de dispositivos enumerados. Ele interrompe o processo de enumeração após dez dispositivos são encontrados.  
  
     O `Stopped` remove os manipuladores de eventos de manipulador de eventos e define o evento de conclusão.  
  
     O `EnumerationCompleted` manipulador de eventos interrompe o processo de enumeração. Podemos manipular esse evento, caso haja menos de dez dispositivos.  
  
    > [!TIP]
    >  Este exemplo usa uma expressão lambda para definir os retornos de chamada. Você também pode usar objetos de função (functors), os ponteiros de função, ou [std:: Function](../standard-library/function-class.md) objetos. Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../cpp/lambda-expressions-in-cpp.md).  
  
8.  Inicie o processo de enumeração.  
  
     [!code-cpp[wrl-consume-event#9](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_8.cpp)]  
  
9. Aguarde o processo de enumeração concluir e, em seguida, imprima uma mensagem. Todos os `ComPtr` e objetos RAII deixam o escopo e são liberados automaticamente.  
  
     [!code-cpp[wrl-consume-event#10](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_9.cpp)]  
  
 Aqui está o exemplo completo:  
  
 [!code-cpp[wrl-consume-event#1](../windows/codesnippet/CPP/how-to-handle-events-using-wrl_10.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `wrl-consume-events.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe wrl-consume-events.cpp runtimeobject.lib**  
  
## <a name="see-also"></a>Consulte também  
 [WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md)