---
title: Fornecendo ativação sem janelas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- windowless activation of MFC ActiveX controls
- activation [MFC], MFC ActiveX controls
- MFC ActiveX controls [MFC], activate options
- activation [MFC], windowless
ms.assetid: 094903b5-c344-42fa-96ff-ce01e16891c5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dbe72fcaf26a245d40544acaf59def9e24e0fa6e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="providing-windowless-activation"></a>Fornecendo ativação sem janelas
Código de criação de janela (ou seja, tudo o que acontece quando você chamar **CreateWindow**) é caro para executar. Um controle que mantém uma tela janela tem que gerenciar as mensagens da janela. Controles sem janelas, portanto, são mais rápidos que os controles com o windows.  
  
 Uma vantagem adicional de controles sem janela é que, ao contrário de controles de janela, controles sem janela suportam pintura transparente e regiões da tela não retangulares. Um exemplo comum de um controle transparente é um controle de texto com um plano de fundo transparente. Os controles pinta o texto, mas não o plano de fundo, para que tudo o que está sob o texto aparece. Formulários mais recentes geralmente tornam o uso de controles não retangulares, como setas e botões de ida e volta.  
  
 Geralmente, um controle não precisa de sua própria janela e, em vez disso, pode usar os serviços do Windows de seu contêiner, desde que o contêiner foi gravado para dar suporte a objetos sem janelas. Controles sem janelas são compatíveis com contêineres mais antigos. Em contêineres mais antigos não são gravados para oferecer suporte a controles sem janelas, os controles sem janela criar uma janela quando ativo.  
  
 Porque os controles sem janela não tem suas próprias janelas, o contêiner (que têm uma janela) é responsável por fornecer serviços caso contrário, terá sido fornecidos pela janela do controle. Por exemplo, se o seu controle precisa consultar o foco do teclado, captura o mouse ou obter um contexto de dispositivo, essas operações são gerenciadas pelo contêiner. O contêiner roteia mensagens de entrada de usuário enviadas para sua janela para o controle sem janelas apropriado, usando o `IOleInPlaceObjectWindowless` interface. (Consulte o *ActiveX SDK* para obter uma descrição dessa interface.) `COleControl` esses serviços do contêiner de invocação de funções de membro.  
  
 Para tornar o seu controle usar ativação sem janelas, incluem o **windowlessActivate** sinalizador no conjunto de sinalizadores retornado por [COleControl::GetControlFlags](../mfc/reference/colecontrol-class.md#getcontrolflags). Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/cpp/providing-windowless-activation_1.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#6](../mfc/codesnippet/cpp/providing-windowless-activation_2.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/cpp/providing-windowless-activation_3.cpp)]  
  
 O código para incluir esse sinalizador é gerado automaticamente se você selecionar o **ativação sem janelas** opção o [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página do Assistente de controle ActiveX do MFC.  
  
 Quando a ativação sem janelas é habilitada, o contêiner delegará a mensagens de entrada para o controle `IOleInPlaceObjectWindowless` interface. `COleControl`da implementação dessa interface envia as mensagens pelo mapa de mensagem do controle, depois de ajustar o mouse coordena adequadamente. Você pode processar as mensagens como mensagens de janela comum, adicionando as entradas correspondentes no mapa de mensagem. Em seus manipuladores para essas mensagens, evite usar o `m_hWnd` variável de membro (ou qualquer função de membro que utiliza) sem antes conferir que seu valor não é **nulo**.  
  
 `COleControl` fornece funções de membro que invocam a captura do mouse, o foco do teclado, rolar e outros serviços do Windows do contêiner conforme apropriado, incluindo:  
  
-   [GetFocus](../mfc/reference/colecontrol-class.md#getfocus), [SetFocus](../mfc/reference/colecontrol-class.md#setfocus)  
  
-   [GetCapture](../mfc/reference/colecontrol-class.md#getcapture), [SetCapture](../mfc/reference/colecontrol-class.md#setcapture), [ReleaseCapture](../mfc/reference/colecontrol-class.md#releasecapture)  
  
-   [GetDC](../mfc/reference/colecontrol-class.md#getdc), [ReleaseDC](../mfc/reference/colecontrol-class.md#releasedc)  
  
-   [InvalidateRgn](../mfc/reference/colecontrol-class.md#invalidatergn)  
  
-   [ScrollWindow](../mfc/reference/colecontrol-class.md#scrollwindow)  
  
-   [GetClientRect](../mfc/reference/colecontrol-class.md#getclientrect)  
  
 Em controles sem janela, você sempre deve usar o `COleControl` funções de membro em vez de correspondente `CWnd` funções de membro ou as funções de API do Win32 relacionadas.  
  
 Será necessário um controle sem janelas para ser o destino de uma operação de arrastar e soltar OLE. Normalmente, isso requer que a janela do controle ser registrado como um destino de soltar. Desde que o controle não tem nenhuma janela de seu próprio, o contêiner usa sua própria janela como um destino de soltar. O controle fornece uma implementação do `IDropTarget` interface para o qual o contêiner pode delegar chamadas no momento apropriado. Para expor essa interface para o contêiner, substituir [COleControl::GetWindowlessDropTarget](../mfc/reference/colecontrol-class.md#getwindowlessdroptarget). Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxOpt#8](../mfc/codesnippet/cpp/providing-windowless-activation_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

