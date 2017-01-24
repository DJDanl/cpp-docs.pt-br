---
title: "Instru&#231;&#245;es passo a passo: criando um aplicativo da Windows Store usando WRL e Media Foundation | Microsoft Docs"
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
ms.assetid: 0336c550-fbeb-4dc4-aa9b-660f9fc45382
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: criando um aplicativo da Windows Store usando WRL e Media Foundation
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Saiba como usar o [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] ([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]) para criar um [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativo que usa [Microsoft Media Foundation](http://msdn.microsoft.com/library/windows/apps/ms694197).  
  
 Este exemplo cria uma transformação personalizada do Media Foundation que aplica um efeito de escala de cinza para imagens que são capturadas de uma webcam. O aplicativo usa C++ para definir a transformação personalizada e c# para usar o componente para transformar as imagens capturadas.  
  
> [!NOTE]
>  Em vez de c#, você também pode usar JavaScript, Visual Basic ou C++ para consumir o componente de transformação personalizada.  
  
 Na maioria dos casos, você pode usar [!INCLUDE[cppwrt](../build/reference/includes/cppwrt_md.md)] ([!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)]) para criar [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] componentes. (Para obter mais informações, consulte [Referência de linguagem do Visual C++](../Topic/Visual%20C++%20Language%20Reference%20\(C++-CX\).md).) No entanto, às vezes você precisa usar o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]. Por exemplo, quando você cria uma extensão de mídia para o Microsoft Media Foundation, você deve criar um componente que implementa dois COM e [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] interfaces. Porque [!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)] só pode criar [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] objetos, para criar uma extensão de mídia, você deve usar o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] porque ela permite a implementação de dois COM e [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] interfaces.  
  
> [!NOTE]
>  Embora este exemplo de código é longo, ele demonstra o mínimo necessário para criar uma transformação Media Foundation útil. Você pode usá-lo como ponto de partida para sua própria transformação personalizada. Este exemplo é adaptado a [exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096), quais extensões de mídia usa para aplicar efeitos de vídeo, decodificação de vídeo e criar manipuladores de esquema que produzem fluxos de mídia.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Experiência com o [Windows Runtime](http://msdn.microsoft.com/library/windows/apps/br211377.aspx).  
  
-   Experiência com COM.  
  
-   Uma webcam.  
  
## <a name="key-points"></a>Pontos-chave  
  
-   Para criar um componente personalizado do Media Foundation, use um arquivo de definição do Microsoft Interface Definition Language (MIDL) para definir uma interface, implementar essa interface e, em seguida, fazer ativável de outros componentes.  
  
-   O `namespace` e `runtimeclass` atributos e o `NTDDI_WIN8`[versão](http://msdn.microsoft.com/pt-br/66ac5cf3-2230-44fd-aaf6-8013e4a4ae81) valor de atributo são partes importantes da definição do MIDL para um componente do Media Foundation que usa [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)].  
  
-   [Microsoft::WRL::RuntimeClass](../windows/runtimeclass-class.md) é a classe base para o componente personalizado do Media Foundation. O [Microsoft::WRL::RuntimeClassType::WinRtClassicComMix](../windows/runtimeclasstype-enumeration.md) o valor de enumeração, que é fornecido como um argumento de modelo, marca a classe para uso como um [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] classe e como uma classe de tempo de execução COM clássico.  
  
-   O [InspectableClass](../windows/inspectableclass-macro.md) macro implementa a funcionalidade básica de COM, como contagem de referência e o `QueryInterface` método e define o tempo de execução do nome da classe e nível de confiança.  
  
-   Usar o Microsoft:: wrl::[classe de módulo](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/b4acf5de-2f4c-4c8b-b5ff-9140d023ecbe/locales/en-US) para implementar funções de ponto de entrada DLL como [DllGetActivationFactory](http://msdn.microsoft.com/library/br205771.aspx), [DllCanUnloadNow](http://msdn.microsoft.com/library/windows/desktop/ms690368\(v=vs.85\).aspx), e [DllGetClassObject](http://msdn.microsoft.com/library/windows/desktop/ms680760\(v=vs.85\).aspx).  
  
-   Vincule a DLL do componente runtimeobject.lib. Também especifique [/WINMD](../Topic/Compiler%20and%20Linker%20options%20\(C++-CX\).md) na linha de vinculador para gerar os metadados do Windows.  
  
-   Usar referências de projeto para fazer [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] componentes acessíveis para [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos.  
  
### <a name="to-use-the-includecppwrlshorttokencppwrlshortmdmd-to-create-the-media-foundation-grayscale-transform-component"></a>Para usar o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] para criar o componente de transformação de escala de cinza do Media Foundation  
  
1.  No Visual Studio, crie um **solução em branco** projeto. Nomeie o projeto como, por exemplo, `MediaCapture`.  
  
2.  Adicione um **DLL (aplicativos da Windows Store)** projeto à solução. Nomeie o projeto como, por exemplo, `GrayscaleTransform`.  
  
3.  Adicione um **arquivo Midl (. idl)** arquivo ao projeto. Nomeie o arquivo, por exemplo, `GrayscaleTransform.idl`.  
  
4.  Adicione este código ao GrayscaleTransform.idl.  
  
     [!code-cpp[wrl-media-capture#1](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_1.idl)]  
  
5.  Use o código a seguir para substituir o conteúdo de pch.  
  
     [!code-cpp[wrl-media-capture#2](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_2.h)]  
  
6.  Adicione um novo arquivo de cabeçalho para o projeto, nomeie-o `BufferLock.h`, e, em seguida, adicione este código:  
  
     [!code-cpp[wrl-media-capture#3](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_3.h)]  
  
7.  GrayscaleTransform.h não é usado neste exemplo. Você poderá ser removido do projeto se desejar.  
  
8.  Use o código a seguir para substituir o conteúdo de GrayscaleTransform.cpp.  
  
     [!code-cpp[wrl-media-capture#4](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_4.cpp)]  
  
9. Adicionar um novo arquivo de definição de módulo ao projeto, nomeie-o `GrayscaleTransform.def`, e, em seguida, adicione este código:  
  
     [!CODE [wrl-media-capture#5](../CodeSnippet/VS_Snippets_Misc/wrl-media-capture#5)]  
  
10. Use o código a seguir para substituir o conteúdo de dllmain.cpp.  
  
     [!code-cpp[wrl-media-capture#6](../windows/codesnippet/CPP/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_6.cpp)]  
  
11. O projeto **páginas de propriedade** caixa de diálogo, defina o seguinte **vinculador** Propriedades.  
  
    1.  Em **entrada**, para o **Module Definition File**, especificar `GrayScaleTransform.def`.  
  
    2.  Também em **entrada**, adicionar `runtimeobject.lib`, `mfuuid.lib`, e `mfplatf.lib` para o **dependências adicionais** propriedade.  
  
    3.  Em **metadados Windows**, defina **Gerar metadados do Windows** para **Sim (/ WINMD)**.  
  
### <a name="to-use-the-includecppwrlshorttokencppwrlshortmdmd-the-custom-media-foundation-component-from-a-c-app"></a>Para usar o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] o componente personalizado do Media Foundation em um aplicativo c#  
  
1.  Adicione um novo **c# aplicativo em branco (XAML)** de projeto para o `MediaCapture` solução. Nomeie o projeto como, por exemplo, `MediaCapture`.  
  
2.  No **MediaCapture** de projeto, adicione uma referência para o `GrayscaleTransform` projeto. Para saber como, consulte [como: Adicionar ou remover referências usando o Gerenciador de referências](../Topic/How%20to:%20Add%20or%20Remove%20References%20By%20Using%20the%20Reference%20Manager.md).  
  
3.  Em Package. appxmanifest, no **recursos** Selecione **microfone** e **Webcam**. Os dois recursos são necessárias para capturar fotos de webcam.  
  
4.  Em MainPage. XAML, adicione este código para a raiz [grade](http://msdn.microsoft.com/library/windows/apps/xaml/windows.ui.xaml.controls.grid.aspx) elemento:  
  
     [!code-xml[wrl-media-capture#7](../windows/codesnippet/Xaml/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_7.xaml)]  
  
5.  Use o código a seguir para substituir o conteúdo do arquivo MainPage.xaml.cs.  
  
     [!code-cs[wrl-media-capture#8](../windows/codesnippet/CSharp/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation_8.cs)]  
  
 A ilustração a seguir mostra o aplicativo MediaCapture.  
  
 ![Aplicativo MediaCapture capturando uma foto](../windows/media/wrl_media_capture.png "WRL_Media_Capture")  
  
## <a name="next-steps"></a>Próximas etapas  
 O exemplo mostra como capturar fotos de webcam padrão um por vez. O [exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096) faz mais. Ele demonstra como enumerar os dispositivos de webcam e trabalhar com manipuladores de esquema local e demonstra os efeitos de mídia adicionais que funcionam em fotos individuais e fluxos de vídeo.  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de modelos C++ do Windows Runtime (WRL)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)   
 [Microsoft Media Foundation](http://msdn.microsoft.com/library/windows/apps/ms694197)   
 [Exemplo de extensões de mídia](http://code.msdn.microsoft.com/windowsapps/Media-extensions-sample-7b466096)