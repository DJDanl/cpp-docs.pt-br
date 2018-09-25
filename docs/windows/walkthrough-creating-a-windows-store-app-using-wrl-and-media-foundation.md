---
title: 'Passo a passo: Criando um aplicativo UWP usando WRL e Media Foundation | Microsoft Docs'
ms.custom: ''
ms.date: 09/17/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 0336c550-fbeb-4dc4-aa9b-660f9fc45382
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9858ebe9affb47d61114bde072645f7002849ec7
ms.sourcegitcommit: edb46b0239a0e616af4ec58906e12338c3e8d2c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2018
ms.locfileid: "47169457"
---
# <a name="walkthrough-creating-a-uwp-app-using-wrl-and-media-foundation"></a>Passo a passo: Criando um aplicativo UWP usando WRL e Media Foundation

Saiba como usar a biblioteca de modelos do Windows em tempo de execução C++ (WRL) para criar um aplicativo de plataforma Universal do Windows (UWP) que usa [Microsoft Media Foundation](/windows/desktop/medfound/microsoft-media-foundation-sdk).

Este exemplo cria uma transformação personalizada do Media Foundation que se aplica a um efeito de escala de cinza para imagens que são capturadas de uma webcam. O aplicativo usa C++ para definir a transformação personalizada e o c# para usar o componente para transformar as imagens capturadas.

> [!NOTE]
> Em vez de c#, você também pode usar JavaScript, Visual Basic ou C++ para consumir o componente de transformação personalizados.

Na maioria dos casos, você pode usar C + + c++ /CX para criar o tempo de execução do Windows. No entanto, às vezes, você precisa usar a WRL. Por exemplo, quando você cria uma extensão de mídia para o Microsoft Media Foundation, você deve criar um componente que implementa as interfaces COM e o tempo de execução do Windows. Porque C + + c++ /CLI CX só pode criar objetos de tempo de execução do Windows, para criar uma extensão de mídia você deve usar a WRL porque ela permite que a implementação de interfaces COM e o tempo de execução do Windows.

> [!NOTE]
> Embora este exemplo de código for longo, ele demonstra o mínimo necessário para criar uma transformação do Media Foundation úteis. Você pode usá-lo como um ponto de partida para sua própria transformação personalizada. Este exemplo é adaptado do [exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096), quais extensões de mídia usa para aplicar efeitos de vídeo, decodificar vídeo e criar manipuladores de esquema que produzem fluxos de mídia.

## <a name="prerequisites"></a>Pré-requisitos

- Experiência com o [tempo de execução do Windows](https://msdn.microsoft.com/library/windows/apps/br211377.aspx).

- Experiência com COM.

- Uma webcam.

## <a name="key-points"></a>Pontos-chave

- Para criar um componente personalizado do Media Foundation, use um arquivo de definição de linguagem de definição de Interface da Microsoft (MIDL) para definir uma interface, implementar essa interface e, em seguida, torná-lo ativável de outros componentes.

- O `namespace` e `runtimeclass` atributos e o `NTDDI_WIN8` [versão](/windows/desktop/Midl/version) valor de atributo são partes importantes da definição do MIDL para um componente do Media Foundation que usa o WRL.

- [Microsoft::WRL::RuntimeClass](../windows/runtimeclass-class.md) é a classe base para o componente personalizado do Media Foundation. O [Microsoft::WRL::RuntimeClassType::WinRtClassicComMix](../windows/runtimeclasstype-enumeration.md) valor de enumeração, que é fornecido como um argumento de modelo, marca a classe para uso como uma classe de tempo de execução do Windows e como uma classe de tempo de execução do COM clássico.

- O [InspectableClass](../windows/inspectableclass-macro.md) macro implementa a funcionalidade básica de COM, como a contagem de referência e o `QueryInterface` método e define o tempo de execução do nome da classe e o nível de confiança.

- Usar o Microsoft:: wrl::[classe de módulo](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/b4acf5de-2f4c-4c8b-b5ff-9140d023ecbe) para implementar as funções de ponto de entrada DLL, como [DllGetActivationFactory](https://msdn.microsoft.com/library/br205771.aspx), [DllCanUnloadNow](/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow), e [ DllGetClassObject](/windows/desktop/api/combaseapi/nf-combaseapi-dllgetclassobject).

- Vincule seu DLL do componente a runtimeobject. Também especifique [/WINMD](../cppcx/compiler-and-linker-options-c-cx.md) na linha do vinculador para gerar os metadados do Windows.

- Usar referências de projeto para tornar os componentes da WRL acessível para aplicativos UWP.

### <a name="to-use-the-wrl-to-create-the-media-foundation-grayscale-transform-component"></a>Transformar o componente para usar a WRL para criar a escala de cinza do Media Foundation

1. No Visual Studio, crie uma **solução em branco** projeto. Nomeie o projeto, por exemplo, *MediaCapture*.

1. Adicionar um **DLL (Universal Windows)** projeto à solução. Nomeie o projeto, por exemplo, *GrayscaleTransform*.

1. Adicionar um **arquivo Midl (. idl)** arquivo ao projeto. Nomeie o arquivo, por exemplo, *GrayscaleTransform.idl*.

1. Adicione este código ao GrayscaleTransform.idl:

   [!code-cpp[wrl-media-capture#1](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_1.idl)]

1. Use o seguinte código para substituir o conteúdo de `pch.h`:

   [!code-cpp[wrl-media-capture#2](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_2.h)]

1. Adicione um novo arquivo de cabeçalho para o projeto, nomeie- `BufferLock.h`e, em seguida, substitua o conteúdo com este código:

   [!code-cpp[wrl-media-capture#3](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_3.h)]

1. `GrayscaleTransform.h` não é usado neste exemplo. Você pode removê-lo do projeto, se você quiser.

1. Use o seguinte código para substituir o conteúdo de `GrayscaleTransform.cpp`:

   [!code-cpp[wrl-media-capture#4](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_4.cpp)]

1. Adicione um novo arquivo de definição de módulo ao projeto, nomeie- `GrayscaleTransform.def`e, em seguida, adicione este código:

   ```
   EXPORTS
       DllCanUnloadNow                     PRIVATE
       DllGetActivationFactory             PRIVATE
       DllGetClassObject                   PRIVATE
   ```

1. Use o seguinte código para substituir o conteúdo de `dllmain.cpp`:

   [!code-cpp[wrl-media-capture#6](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_6.cpp)]

1. No projeto do **páginas de propriedades** diálogo caixa, defina o seguinte **vinculador** propriedades.

   1. Sob **entrada**, para o **arquivo de definição de módulo**, especifique `GrayScaleTransform.def`.

   1. Também no **entrada**, adicione `runtimeobject.lib`, `mfuuid.lib`, e `mfplat.lib` para o **dependências adicionais** propriedade.

   1. Sob **metadados do Windows**, defina **gerar metadados do Windows** para **Sim (/ WINMD)**.

### <a name="to-use-the-wrl-the-custom-media-foundation-component-from-a-c-app"></a>Para usar a WRL o componente personalizado do Media Foundation de um aplicativo c#

1. Adicione um novo **aplicativo em branco em C# (Windows Universal)** do projeto para o `MediaCapture` solução. Nomeie o projeto, por exemplo, *MediaCapture*.

1. No **MediaCapture** do projeto, adicione uma referência para o `GrayscaleTransform` projeto. Para saber como, consulte [como: Adicionar ou remover referências usando o Gerenciador de referências](/visualstudio/ide/how-to-add-or-remove-references-by-using-the-reference-manager).

1. No `Package.appxmanifest`diante de **funcionalidades** guia, selecione **microfone** e **Webcam**. Os dois recursos são necessários para capturar fotos de webcam.

1. Na `MainPage.xaml`, adicione este código para a raiz [grade](https://msdn.microsoft.com/library/windows/apps/xaml/windows.ui.xaml.controls.grid.aspx) elemento:

   [!code-xml[wrl-media-capture#7](../windows/codesnippet/Xaml/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_7.xaml)]

1. Use o seguinte código para substituir o conteúdo de `MainPage.xaml.cs`:

   [!code-cs[wrl-media-capture#8](../windows/codesnippet/CSharp/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_8.cs)]

A ilustração a seguir mostra o `MediaCapture app`.

![Aplicativo MediaCapture capturando uma foto](../windows/media/wrl_media_capture.png "WRL_Media_Capture")

## <a name="next-steps"></a>Próximas etapas

O exemplo mostra como capturar fotos da webcam padrão, um por vez. O [exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096) faz muito mais. Ele demonstra como enumerar os dispositivos de webcam e trabalhar com os manipuladores de esquema local e demonstra os efeitos de mídia adicionais que funcionam em fotos individuais e fluxos de vídeo.

## <a name="see-also"></a>Consulte também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md)<br/>
[Microsoft Media Foundation](/windows/desktop/medfound/microsoft-media-foundation-sdk)<br/>
[Exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096)