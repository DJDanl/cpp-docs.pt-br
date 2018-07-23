---
title: 'Passo a passo: Criando um aplicativo UWP usando WRL e Media Foundation | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 1c9e3f678a65b3dacfc5bba012656118b6fe2fa1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891679"
---
# <a name="walkthrough-creating-a-uwp-app-using-wrl-and-media-foundation"></a>Passo a passo: Criando um aplicativo UWP usando WRL e Media Foundation
Saiba como usar a biblioteca de modelo (WRL) do Windows em tempo de execução C++ para criar um aplicativo do Windows UWP (plataforma Universal) que usa [Microsoft Media Foundation](http://msdn.microsoft.com/library/windows/apps/ms694197).  
  
 Este exemplo cria uma transformação Media Foundation personalizada que se aplica a um efeito de escala de cinza para imagens que são capturadas de uma webcam. O aplicativo usa C++ para definir a transformação personalizada e c# para usar o componente para transformar as imagens capturadas.  
  
> [!NOTE]
>  Em vez de c#, você também pode usar JavaScript, Visual Basic ou C++ para consumir o componente de transformação personalizada.  
  

 Na maioria dos casos, você pode usar C + c++ /CX para criar o tempo de execução do Windows). No entanto, às vezes, você precisa usar o WRL. Por exemplo, quando você cria uma extensão de mídia para o Microsoft Media Foundation, você deve criar um componente que implementa as interfaces COM e tempo de execução do Windows. Porque C + + CX só pode criar objetos de tempo de execução do Windows, para criar uma extensão de mídia é necessário usar o WRL porque ela permite que a implementação de interfaces COM e tempo de execução do Windows.  

  
> [!NOTE]
>  Embora este exemplo de código for longo, ele demonstra o mínimo necessário para criar uma transformação Media Foundation útil. Você pode usá-lo como um ponto de partida para sua próprias transformação personalizada. Este exemplo é adaptado a [exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096), quais extensões de mídia usa para aplicar efeitos de vídeo, decodificação de vídeo e criar manipuladores de esquema que produzem fluxos de mídia.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Experiência com o [tempo de execução do Windows](http://msdn.microsoft.com/library/windows/apps/br211377.aspx).  
  
-   Experiência com COM.  
  
-   Uma webcam.  
  
## <a name="key-points"></a>Pontos-chave  
  
-   Para criar um componente personalizado do Media Foundation, use um arquivo de definição de linguagem de definição de Interface da Microsoft (MIDL) para definir uma interface, implementar essa interface e, em seguida, fazer ativável de outros componentes.  
  
-   O `namespace` e `runtimeclass` atributos e o `NTDDI_WIN8` [versão](http://msdn.microsoft.com/en-us/66ac5cf3-2230-44fd-aaf6-8013e4a4ae81) valor de atributo são partes importantes da definição de MIDL para um componente do Media Foundation que usa WRL.  
  
-   [Microsoft::WRL::RuntimeClass](../windows/runtimeclass-class.md) é a classe base para o componente personalizado do Media Foundation. O [Microsoft::WRL::RuntimeClassType::WinRtClassicComMix](../windows/runtimeclasstype-enumeration.md) marca de valor de enumeração, que é fornecido como um argumento de modelo, a classe para uso como uma classe de tempo de execução do Windows e uma classe de tempo de execução COM clássico.  
  
-   O [InspectableClass](../windows/inspectableclass-macro.md) macro implementa a funcionalidade básica de COM, como contagem de referência e o `QueryInterface` método e define o tempo de execução do nome da classe e o nível de confiança.  
  
-   Use o Microsoft:: wrl::[classe de módulo](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/b4acf5de-2f4c-4c8b-b5ff-9140d023ecbe/locales/en-US) para implementar funções de ponto de entrada DLL como [DllGetActivationFactory](http://msdn.microsoft.com/library/br205771.aspx), [DllCanUnloadNow](http://msdn.microsoft.com/library/windows/desktop/ms690368\(v=vs.85\).aspx), e [ DllGetClassObject](http://msdn.microsoft.com/library/windows/desktop/ms680760\(v=vs.85\).aspx).  
  
-   Vincule a DLL do componente runtimeobject.lib. Também especifique [/WINMD](../cppcx/compiler-and-linker-options-c-cx.md) na linha de vinculador gerar metadados do Windows.  
  
-   Usar referências de projeto para tornar os componentes WRL acessível para aplicativos UWP.  
  
### <a name="to-use-the-wrl-to-create-the-media-foundation-grayscale-transform-component"></a>Para usar o WRL para criar a escala de cinza Media Foundation transformar o componente  
  
1.  No Visual Studio, crie um **solução em branco** projeto. Nome do projeto, por exemplo, `MediaCapture`.  
  
2.  Adicionar um **DLL (Universal do Windows)** projeto à solução. Nome do projeto, por exemplo, `GrayscaleTransform`.  
  
3.  Adicionar um **arquivo Midl (. idl)** arquivo ao projeto. Nomeie o arquivo, por exemplo, `GrayscaleTransform.idl`.  
  
4.  Adicione esse código GrayscaleTransform.idl.  
  
     [!code-cpp[wrl-media-capture#1](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_1.idl)]  
  
5.  Use o código a seguir para substituir o conteúdo de pch. h.  
  
     [!code-cpp[wrl-media-capture#2](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_2.h)]  
  
6.  Adicionar um novo arquivo de cabeçalho para o projeto, nomeie-o `BufferLock.h`e, em seguida, adicione este código:  
  
     [!code-cpp[wrl-media-capture#3](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_3.h)]  
  
7.  GrayscaleTransform.h não é usado neste exemplo. Você pode removê-lo do projeto, se desejar.  
  
8.  Use o código a seguir para substituir o conteúdo de GrayscaleTransform.cpp.  
  
     [!code-cpp[wrl-media-capture#4](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_4.cpp)]  
  
9. Adicionar um novo arquivo de definição de módulo para o projeto, nomeie-o `GrayscaleTransform.def`e, em seguida, adicione este código:  
  
   ```
   EXPORTS
       DllCanUnloadNow                     PRIVATE
       DllGetActivationFactory             PRIVATE
       DllGetClassObject                   PRIVATE
   ```   
  
10. Use o código a seguir para substituir o conteúdo de dllmain.cpp.  
  
     [!code-cpp[wrl-media-capture#6](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_6.cpp)]  
  
11. O projeto **páginas de propriedade** caixa de diálogo caixa, defina o seguinte **vinculador** propriedades.  
  
    1.  Em **entrada**, para o **arquivo de definição de módulo**, especifique `GrayScaleTransform.def`.  
  
    2.  Também em **entrada**, adicionar `runtimeobject.lib`, `mfuuid.lib`, e `mfplatf.lib` para o **dependências adicionais** propriedade.  
  
    3.  Em **metadados do Windows**, defina **gerar metadados do Windows** para **Sim (/ WINMD)**.  
  
### <a name="to-use-the-wrl-the-custom-media-foundation-component-from-a-c-app"></a>Para usar o componente personalizado Media Foundation de um aplicativo c# WRL  
  
1.  Adicionar um novo **c# aplicativo em branco (XAML)** de projeto para o `MediaCapture` solução. Nome do projeto, por exemplo, `MediaCapture`.  
  
2.  No **MediaCapture** de projeto, adicione uma referência para o `GrayscaleTransform` projeto. Para saber mais, consulte [como: Adicionar ou remover referências usando o Gerenciador de referências](/visualstudio/ide/how-to-add-or-remove-references-by-using-the-reference-manager).  
  
3.  Em Package. appxmanifest, sobre o **recursos** guia, selecione **microfone** e **Webcam**. Os dois recursos são necessários para capturar fotos de webcam.  
  
4.  Em MainPage. XAML, adicione este código para a raiz [grade](http://msdn.microsoft.com/library/windows/apps/xaml/windows.ui.xaml.controls.grid.aspx) elemento:  
  
     [!code-xml[wrl-media-capture#7](../windows/codesnippet/Xaml/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_7.xaml)]  
  
5.  Use o código a seguir para substituir o conteúdo de MainPage.xaml.cs.  
  
     [!code-cs[wrl-media-capture#8](../windows/codesnippet/CSharp/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_8.cs)]  
  
 A ilustração a seguir mostra o aplicativo MediaCapture.  
  
 ![Aplicativo MediaCapture capturando uma foto](../windows/media/wrl_media_capture.png "WRL_Media_Capture")  
  
## <a name="next-steps"></a>Próximas etapas  
 O exemplo mostra como capturar fotos de webcam padrão, um por vez. O [exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096) faz mais. Ele demonstra como enumerar os dispositivos de webcam e trabalhar com os manipuladores de local de esquema e demonstra os efeitos de uma mídia adicional que funcionam em fotos individuais e fluxos de vídeo.  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de modelos C++ do Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md)   
 [Microsoft Media Foundation](http://msdn.microsoft.com/library/windows/apps/ms694197)   
 [Exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096)