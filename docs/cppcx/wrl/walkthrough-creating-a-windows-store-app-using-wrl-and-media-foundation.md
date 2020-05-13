---
title: 'Passo a passo: criando um aplicativo UWP usando WRL e Media Foundation'
ms.date: 04/23/2019
ms.topic: reference
ms.assetid: 0336c550-fbeb-4dc4-aa9b-660f9fc45382
ms.openlocfilehash: 272092982c5e9cc57f52043e08c8bd384c43ea96
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82031505"
---
# <a name="walkthrough-creating-a-uwp-app-using-wrl-and-media-foundation"></a>Passo a passo: criando um aplicativo UWP usando WRL e Media Foundation

> [!NOTE]
> Para novos aplicativos e componentes uwp, recomendamos que você use [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/), uma nova projeção padrão de linguagem C++17 para APIs do Windows Runtime. C++/WinRT está disponível no SDK do Windows 10 a partir da versão 1803. C++/WinRT é implementado inteiramente em arquivos de cabeçalho, e foi projetado para fornecer acesso de primeira classe à API moderna do Windows.

Neste tutorial, você aprenderá a usar a Biblioteca de Modelos C++ do Windows Runtime (WRL) para criar um aplicativo Universal Windows Platform (UWP) que usa [o Microsoft Media Foundation](/windows/win32/medfound/microsoft-media-foundation-sdk).

Este exemplo cria uma transformação personalizada da Media Foundation que aplica um efeito em escala de cinza a imagens capturadas de uma webcam. O aplicativo usa C++ para definir a transformação personalizada e C# para usar o componente para transformar as imagens capturadas.

> [!NOTE]
> Em vez de C#, você também pode usar JavaScript, Visual Basic ou C++ para consumir o componente de transformação personalizado.

Na maioria dos casos, você pode usar C++/CX para criar o Windows Runtime. No entanto, às vezes você tem que usar o WRL. Por exemplo, quando você cria uma extensão de mídia para o Microsoft Media Foundation, você deve criar um componente que implemente interfaces COM e Windows Runtime. Como o C++/CX só pode criar objetos do Windows Runtime, para criar uma extensão de mídia, você deve usar o WRL porque permite a implementação de interfaces COM e Windows Runtime.

> [!NOTE]
> Embora este exemplo de código seja longo, ele demonstra o mínimo necessário para criar uma transformação útil da Media Foundation. Você pode usá-lo como ponto de partida para sua própria transformação personalizada. Este exemplo é adaptado da [amostra de extensões de mídia](https://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096), que usa extensões de mídia para aplicar efeitos em vídeo, decodificar vídeo e criar manipuladores de esquemaque produzem fluxos de mídia.

## <a name="prerequisites"></a>Pré-requisitos

- No Visual Studio 2017 e posterior, o suporte ao UWP é um componente opcional. Para instalá-lo, abra o Visual Studio Installer no menu Windows Start e encontre sua versão do Visual Studio. Escolha **Modificar** e, em seguida, certifique-se de que o bloco **de desenvolvimento de plataforma universal do Windows** seja verificado. Em **Componentes Opcionais,** verifique **as ferramentas C++ para UWP (v141)** para visual studio 2017, ou **C++ Tools for UWP (v142)** para Visual Studio 2019. Em seguida, verifique a versão do Windows SDK que você deseja usar.

- Experiência com o [Windows Runtime](/uwp/api/).

- Experiência com COM.

- Uma Webcam.

## <a name="key-points"></a>Pontos-chave

- Para criar um componente personalizado da Media Foundation, use um arquivo de definição de definição de interface microsoft (MIDL) para definir uma interface, implementar essa interface e, em seguida, torná-la ativada a partir de outros componentes.

- Os `namespace` `runtimeclass` atributos e `NTDDI_WIN8`o valor do atributo da [versão](/windows/win32/Midl/version) são partes importantes da definição MIDL para um componente da Media Foundation que usa WRL.

- [Microsoft::WRL::RuntimeClass](runtimeclass-class.md) é a classe base do componente personalizado da Media Foundation. O valor de enum [da Microsoft::WRL:RuntimeClassType::WinRtClassicComMix,](runtimeclasstype-enumeration.md) que é fornecido como um argumento de modelo, marca a classe para uso tanto como uma classe de tempo de execução do Windows quanto como uma classe clássica de tempo de execução COM.

- A macro [InspectableClass](inspectableclass-macro.md) implementa a funcionalidade BÁSICA `QueryInterface` COM, como contagem de referência e o método, e define o nome da classe de tempo de execução e o nível de confiança.

- Use a classe Microsoft::WRL::[Módulo](module-class.md) para implementar funções de ponto de entrada do DLL, como [DllGetActivationFactory,](/windows/win32/winrt/functions) [DllCanUnloadNow](/windows/win32/api/combaseapi/nf-combaseapi-dllcanunloadnow)e [DllGetClassObject](/windows/win32/api/combaseapi/nf-combaseapi-dllgetclassobject).

- Vincule o dLL do componente ao runtimeobject.lib. Também especifique [/WINMD](../../cppcx/compiler-and-linker-options-c-cx.md) na linha linker para gerar metadados do Windows.

- Use referências de projeto para tornar os componentes WRL acessíveis a aplicativos UWP.

### <a name="to-use-the-wrl-to-create-the-media-foundation-grayscale-transform-component"></a>Para usar o WRL para criar o componente de transformação em escala de cinza da Media Foundation

1. No Visual Studio, crie um projeto **de Solução em Branco.** Nomeie o projeto, por exemplo, *MediaCapture*.

1. Adicione um projeto **DLL (Universal Windows)** à solução. Nomeie o projeto, por exemplo, *GrayscaleTransform*.

1. Adicione um **arquivo Midl File (.idl)** ao projeto. Nomeie o arquivo, por exemplo, *GrayscaleTransform.idl*.

1. Adicione este código a GrayscaleTransform.idl:

   [!code-cpp[wrl-media-capture#1](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_1.idl)]

1. Use o seguinte código para `pch.h`substituir o conteúdo de :

   [!code-cpp[wrl-media-capture#2](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_2.h)]

1. Adicione um novo arquivo de cabeçalho ao projeto, nomeie-o `BufferLock.h`e substitua o conteúdo por este código:

   [!code-cpp[wrl-media-capture#3](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_3.h)]

1. `GrayscaleTransform.h`não é usado neste exemplo. Você pode removê-lo do projeto se quiser.

1. Use o seguinte código para `GrayscaleTransform.cpp`substituir o conteúdo de :

   [!code-cpp[wrl-media-capture#4](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_4.cpp)]

1. Adicione um novo arquivo de definição de `GrayscaleTransform.def`módulo ao projeto, nomeie-o e adicione este código:

   ```
   EXPORTS
       DllCanUnloadNow                     PRIVATE
       DllGetActivationFactory             PRIVATE
       DllGetClassObject                   PRIVATE
   ```

1. Use o seguinte código para `dllmain.cpp`substituir o conteúdo de :

   [!code-cpp[wrl-media-capture#6](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_6.cpp)]

1. Na caixa de diálogo Páginas de **propriedade** do projeto, defina as seguintes propriedades **do Linker.**

   1. Em **Input**, para o `GrayScaleTransform.def`arquivo de definição do **módulo,** especifique .

   1. Também em **Entrada,** `runtimeobject.lib`adicionar e `mfuuid.lib` `mfplat.lib` à propriedade **Dependências Adicionais.**

   1. Em **Metadados do Windows,** defina **Gerar Metadados do Windows** para Sim **(/WINMD)**.

### <a name="to-use-the-wrl-the-custom-media-foundation-component-from-a-c-app"></a>Para usar o WRL, o componente personalizado da Media Foundation a partir de um aplicativo C#

1. Adicione um novo projeto **c# blank app (Universal Windows)** à `MediaCapture` solução. Nomeie o projeto, por exemplo, *MediaCapture*.

1. No projeto **MediaCapture,** adicione uma `GrayscaleTransform` referência ao projeto. Para saber como, [veja Como: Adicionar ou remover referências usando o gerenciador de referências](/visualstudio/ide/how-to-add-or-remove-references-by-using-the-reference-manager).

1. Na `Package.appxmanifest`guia **Recursos,** selecione **Microfone** e **Webcam**. Ambos os recursos são necessários para capturar fotos da webcam.

1. Em `MainPage.xaml`, adicionar este código ao elemento [grade](/uwp/api/windows.ui.xaml.controls.grid) raiz:

   [!code-xml[wrl-media-capture#7](../codesnippet/Xaml/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_7.xaml)]

1. Use o seguinte código para `MainPage.xaml.cs`substituir o conteúdo de :

   [!code-cs[wrl-media-capture#8](../codesnippet/CSharp/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_8.cs)]

A ilustração `MediaCapture app`a seguir mostra o .

![Aplicativo MediaCapture capturando uma foto](../media/wrl_media_capture.png "WRL_Media_Capture")

## <a name="next-steps"></a>Próximas etapas

O exemplo mostra como capturar fotos da webcam padrão uma de cada vez. A [amostra de extensões de mídia](https://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096) faz mais. Ele demonstra como enumerar dispositivos de webcam e trabalhar com manipuladores de esquemalocais, e demonstra efeitos adicionais de mídia que funcionam tanto em fotos individuais quanto em fluxos de vídeo.

## <a name="see-also"></a>Confira também

[Biblioteca de Modelos C++ do Windows Runtime  (WRL)](windows-runtime-cpp-template-library-wrl.md)<br/>
[Microsoft Media Foundation](/windows/win32/medfound/microsoft-media-foundation-sdk)<br/>
[Amostra de extensões de mídia](https://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096)
