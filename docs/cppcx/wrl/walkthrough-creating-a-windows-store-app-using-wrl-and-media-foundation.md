---
title: 'Passo a passo: Cria um aplicativo UWP usando WRL e Media Foundation'
ms.date: 04/23/2019
ms.topic: reference
ms.assetid: 0336c550-fbeb-4dc4-aa9b-660f9fc45382
ms.openlocfilehash: fecfc83e674c418a920e3dd73149f4d6294090fa
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404919"
---
# <a name="walkthrough-creating-a-uwp-app-using-wrl-and-media-foundation"></a>Passo a passo: Cria um aplicativo UWP usando WRL e Media Foundation

> [!NOTE]
> Para novos aplicativos e componentes UWP, recomendamos que você use [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/), uma nova projeção de linguagem c++ 17 padrão para APIs de Windows Runtime. O C++/WinRT está disponível no SDK do Windows 10 da versão 1803 em diante. O C++/WinRT é implementado inteiramente em arquivos de cabeçalho e foi projetado para fornecer a você acesso de primeira classe à API moderna do Windows.

Neste tutorial, você aprenderá a usar o Windows Runtime WRL (biblioteca de modelos C++) para criar um aplicativo Plataforma Universal do Windows (UWP) que usa [Microsoft Media Foundation](/windows/win32/medfound/microsoft-media-foundation-sdk).

Este exemplo cria uma transformação de Media Foundation personalizada que aplica um efeito de escala de cinza às imagens que são capturadas de uma webcam. O aplicativo usa C++ para definir a transformação personalizada e o C# para usar o componente para transformar as imagens capturadas.

> [!NOTE]
> Em vez de C#, você também pode usar JavaScript, Visual Basic ou C++ para consumir o componente de transformação personalizado.

Na maioria dos casos, você pode usar C++/CX para criar Windows Runtime. No entanto, às vezes você precisa usar o WRL. Por exemplo, ao criar uma extensão de mídia para Microsoft Media Foundation, você deve criar um componente que implemente as interfaces COM e Windows Runtime. Como o C++/CX só pode criar Windows Runtime objetos, para criar uma extensão de mídia, você deve usar o WRL porque ele permite a implementação de interfaces COM e Windows Runtime.

> [!NOTE]
> Embora esse exemplo de código seja longo, ele demonstra o mínimo necessário para criar uma transformação Media Foundation útil. Você pode usá-lo como um ponto de partida para sua própria transformação personalizada. Este exemplo é adaptado do [exemplo de extensões de mídia](https://github.com/Microsoft/VCSamples/tree/master/VC2012Samples/Windows%208%20samples/C%2B%2B/Windows%208%20app%20samples), que usa extensões de mídia para aplicar efeitos a vídeo, decodificar vídeo e criar manipuladores de esquema que produzem fluxos de mídia.

## <a name="prerequisites"></a>Pré-requisitos

- No Visual Studio 2017 e posterior, o suporte a UWP é um componente opcional. Para instalá-lo, abra o Instalador do Visual Studio no menu Iniciar do Windows e localize sua versão do Visual Studio. Escolha **Modificar** e, em seguida, verifique se o bloco de **desenvolvimento de plataforma universal do Windows** está marcado. Em **componentes opcionais** , verifique as **ferramentas c++ para UWP (V141)** para Visual Studio 2017 ou **Ferramentas do c++ para UWP (v142)** para Visual Studio 2019. Em seguida, verifique a versão do SDK do Windows que você deseja usar.

- Experiência com o [Windows Runtime](/uwp/api/).

- Experiência com com.

- Uma Webcam.

## <a name="key-points"></a>Pontos-chave

- Para criar um componente de Media Foundation personalizado, use um arquivo de definição de linguagem IDL da Microsoft (MIDL) para definir uma interface, implemente essa interface e, em seguida, torne-a ativável de outros componentes.

- Os `namespace` `runtimeclass` atributos e, e o `NTDDI_WIN8` valor do atributo [version](/windows/win32/Midl/version) são partes importantes da definição de MIDL para um componente Media Foundation que usa WRL.

- [Microsoft:: WRL:: RuntimeClass](runtimeclass-class.md) é a classe base para o componente de Media Foundation personalizado. O valor de enumeração [Microsoft:: WRL:: RuntimeClassType:: WinRtClassicComMix](runtimeclasstype-enumeration.md) , que é fornecido como um argumento de modelo, marca a classe para uso como uma classe de Windows Runtime e como uma classe clássica de tempo de execução com.

- A macro [InspectableClass](inspectableclass-macro.md) implementa a funcionalidade com básica, como contagem de referência e o `QueryInterface` método, e define o nome da classe de tempo de execução e o nível de confiança.

- Use a[classe](module-class.md) Microsoft:: WRL:: Module para implementar funções de ponto de entrada de dll, como [DllGetActivationFactory](/windows/win32/winrt/functions), [DllCanUnloadNow](/windows/win32/api/combaseapi/nf-combaseapi-dllcanunloadnow)e [DllGetClassObject](/windows/win32/api/combaseapi/nf-combaseapi-dllgetclassobject).

- Vincule a DLL do componente ao runtimeobject. lib. Especifique também [/WINMD](../../cppcx/compiler-and-linker-options-c-cx.md) na linha do vinculador para gerar metadados do Windows.

- Use referências de projeto para tornar os componentes do WRL acessíveis aos aplicativos UWP.

### <a name="to-use-the-wrl-to-create-the-media-foundation-grayscale-transform-component"></a>Para usar o WRL para criar o componente de transformação de escala de cinza Media Foundation

1. No Visual Studio, crie um projeto de **solução em branco** . Nomeie o projeto, por exemplo, *MediaCapture*.

1. Adicione um projeto de **dll (universal do Windows)** à solução. Nomeie o projeto, por exemplo, *GrayscaleTransform*.

1. Adicione um arquivo **MIDL (. idl)** ao projeto. Nomeie o arquivo, por exemplo, *GrayscaleTransform. idl*.

1. Adicione este código a GrayscaleTransform. idl:

   [!code-cpp[wrl-media-capture#1](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_1.idl)]

1. Use o seguinte código para substituir o conteúdo de `pch.h` :

   [!code-cpp[wrl-media-capture#2](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_2.h)]

1. Adicione um novo arquivo de cabeçalho ao projeto, nomeie- `BufferLock.h` o e, em seguida, substitua o conteúdo por este código:

   [!code-cpp[wrl-media-capture#3](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_3.h)]

1. `GrayscaleTransform.h`Não é usado neste exemplo. Você pode removê-lo do projeto se desejar.

1. Use o seguinte código para substituir o conteúdo de `GrayscaleTransform.cpp` :

   [!code-cpp[wrl-media-capture#4](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_4.cpp)]

1. Adicione um novo arquivo de definição de módulo ao projeto, nomeie-o `GrayscaleTransform.def` e, em seguida, adicione este código:

   ```
   EXPORTS
       DllCanUnloadNow                     PRIVATE
       DllGetActivationFactory             PRIVATE
       DllGetClassObject                   PRIVATE
   ```

1. Use o seguinte código para substituir o conteúdo de `dllmain.cpp` :

   [!code-cpp[wrl-media-capture#6](../codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_6.cpp)]

1. Na caixa de diálogo **páginas de propriedades** do projeto, defina as propriedades do **vinculador** a seguir.

   1. Em **entrada**, para o **arquivo de definição de módulo**, especifique `GrayScaleTransform.def` .

   1. Também em **entrada**, adicionar `runtimeobject.lib` , `mfuuid.lib` e `mfplat.lib` à propriedade **dependências adicionais** .

   1. Em **metadados do Windows**, defina **gerar metadados do Windows** como **Sim (/WINMD)**.

### <a name="to-use-the-wrl-the-custom-media-foundation-component-from-a-c-app"></a>Para usar o componente de Media Foundation personalizado WRL de um aplicativo C#

1. Adicione um novo projeto de **aplicativo em branco do C# (universal do Windows)** à `MediaCapture` solução. Nomeie o projeto, por exemplo, *MediaCapture*.

1. No projeto **MediaCapture** , adicione uma referência ao `GrayscaleTransform` projeto. Para saber como, consulte [como: Adicionar ou remover referências usando o Gerenciador de referências](/visualstudio/ide/how-to-add-or-remove-references-by-using-the-reference-manager).

1. No `Package.appxmanifest` , na guia **recursos** , selecione **microfone** e **webcam**. Ambos os recursos são necessários para capturar fotos da webcam.

1. No `MainPage.xaml` , adicione este código ao elemento de [grade](/uwp/api/windows.ui.xaml.controls.grid) raiz:

   [!code-xml[wrl-media-capture#7](../codesnippet/Xaml/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_7.xaml)]

1. Use o seguinte código para substituir o conteúdo de `MainPage.xaml.cs` :

   [!code-cs[wrl-media-capture#8](../codesnippet/CSharp/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_8.cs)]

A ilustração a seguir mostra o `MediaCapture app` .

![Aplicativo MediaCapture capturando uma foto](../media/wrl_media_capture.png "WRL_Media_Capture")

## <a name="next-steps"></a>Próximas etapas

O exemplo mostra como capturar fotos da webcam padrão, uma de cada vez. O [exemplo de extensões de mídia](https://github.com/Microsoft/VCSamples/tree/master/VC2012Samples/Windows%208%20samples/C%2B%2B/Windows%208%20app%20samples) faz mais. Ele demonstra como enumerar dispositivos webcam e trabalhar com manipuladores de esquema locais e demonstra os efeitos de mídia adicionais que funcionam em fotos individuais e fluxos de vídeo.

## <a name="see-also"></a>Confira também

[Biblioteca de Modelos C++ do Windows Runtime  (WRL)](windows-runtime-cpp-template-library-wrl.md)<br/>
[Microsoft Media Foundation](/windows/win32/medfound/microsoft-media-foundation-sdk)
