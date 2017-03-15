---
title: "Como manipular eventos com WRL | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: 1c77543f-7b0c-4a94-93bf-e3225885ed76
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como manipular eventos com WRL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este documento mostra como usar [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] \([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]\) para assinar e para tratar eventos de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] objeto.  
  
 Para obter um exemplo mais básico que cria uma instância desse componente e recupera um valor de propriedade, consulte [Como ativar e usar um componente de Tempo de Execução do Windows](../windows/how-to-activate-and-use-a-windows-runtime-component-using-wrl.md).  
  
## Assinar e tratar eventos  
 As etapas a seguir começam um objeto de `ABI::Windows::System::Threading::IDeviceWatcher` e manipuladores de eventos de uso para monitorar o andamento.  A interface de `IDeviceWatcher` permite enumerar de forma assíncrona dispositivos, ou no plano de fundo, e recebe\-à notificação quando os dispositivos são adicionados, removidos, ou alterados.  A função de [Retorno de chamada](../windows/callback-function-windows-runtime-cpp-template-library.md) é uma parte importante deste exemplo como a habilita para especificar os manipuladores de eventos que processam os resultados da operação em segundo plano.  O exemplo completo a seguir.  
  
> [!WARNING]
>  Embora você normalmente usa [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] , esse exemplo usa um aplicativo de console para ilustração.  Funções como `wprintf_s` não estão disponíveis em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] .  Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] , consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx) e [O Win32 e COM para aplicativos do Windows Store](http://msdn.microsoft.com/library/windows/apps/br205757.aspx).  
  
1.  Inclua \(\)`#include`qualquer [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]necessário, [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)], ou cabeçalhos de biblioteca padrão do C\+\+.  
  
     [!CODE [wrl-consume-event#2](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#2)]  
  
     Windows.Devices.Enumeration.h declara os tipos que são necessários para enumerar dispositivos.  
  
     Recomendamos que você utiliza a política de `using namespace` no arquivo .cpp para tornar código mais legível.  
  
2.  Declare variáveis locais para o aplicativo.  Este exemplo contém a contagem do número de dispositivos e tokens enumerados do registro que permitem para cancelar posteriormente de eventos.  
  
     [!CODE [wrl-consume-event#7](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#7)]  
  
3.  Inicializar [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  
  
     [!CODE [wrl-consume-event#3](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#3)]  
  
4.  Crie um objeto de [Evento](../windows/event-class-windows-runtime-cpp-template-library.md) que sincroniza a conclusão do processo de enumeração para o aplicativo principal.  
  
     [!CODE [wrl-consume-event#4](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#4)]  
  
    > [!NOTE]
    >  Esse evento é para demonstração somente como parte de um aplicativo de console.  Este exemplo usa o evento para assegurar que uma operação de async foi concluído antes que o aplicativo vai.  Na maioria dos aplicativos, você normalmente não espera operações de async para concluir.  
  
5.  Crie uma fábrica de ativação para a interface de `IDeviceWatcher` .  
  
     [!CODE [wrl-consume-event#5](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#5)]  
  
     Os nomes totalmente qualificados de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] para identificar tipos.  O parâmetro de `RuntimeClass_Windows_Devices_Enumeration_DeviceInformation` é uma cadeia de caracteres que é fornecida por [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e contém o nome da classe necessário em tempo de execução.  
  
6.  Crie o objeto de `IDeviceWatcher` .  
  
     [!CODE [wrl-consume-event#6](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#6)]  
  
7.  Use a função de `Callback` para assinar `Added`, a `EnumerationCompleted`, e eventos de `Stopped` .  
  
     [!CODE [wrl-consume-event#8](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#8)]  
  
     O manipulador de eventos de `Added` incrementa a contagem de dispositivos enumerados.  Para o processo de enumeração após dez dispositivos são encontrados.  
  
     O manipulador de eventos de `Stopped` remove os manipuladores de eventos e define o evento de conclusão.  
  
     O manipulador de eventos de `EnumerationCompleted` para o processo de enumeração.  Nós tratamos esse evento caso que haverá menos dispositivos do que dez.  
  
    > [!TIP]
    >  Este exemplo usa uma expressão de lambda para definir os retornos de chamada.  Você também pode usar objetos de função \(functors\), ponteiros de função, ou objetos de [std::function](../standard-library/function-class.md) .  Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../cpp/lambda-expressions-in-cpp.md).  
  
8.  Inicie o processo de enumeração.  
  
     [!CODE [wrl-consume-event#9](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#9)]  
  
9. Aguarde até que o processo de enumeração para concluir e depois imprimir uma mensagem.  Qualquer `ComPtr` e os objetos de RAII permitem o escopo e são liberados automaticamente.  
  
     [!CODE [wrl-consume-event#10](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#10)]  
  
 Aqui está o exemplo completo:  
  
 [!CODE [wrl-consume-event#1](../CodeSnippet/VS_Snippets_Misc/wrl-consume-event#1)]  
  
## Compilando o código  
 Para compilar o código, copie\-a e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `wrl-consume-events.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe wrl\-consume\-events.cpp runtimeobject.lib**  
  
## Consulte também  
 [Biblioteca de Modelos C\+\+ do Tempo de Execução do Windows \(WRL\)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)