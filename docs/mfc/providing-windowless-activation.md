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
ms.openlocfilehash: 8e8fc079921b3f2eddd117f93ee9d2f6cad60925
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46441220"
---
# <a name="providing-windowless-activation"></a>Fornecendo ativação sem janelas

Código de criação de janela (ou seja, tudo o que acontece quando você chama `CreateWindow`) é caro para executar. Um controle que mantém um virtual janela possui gerenciar mensagens da janela. Controles sem janelas, portanto, são mais rápidos que controles com o windows.

Uma vantagem adicional de controles sem janelas é que, ao contrário de controles em janelas, controles sem janelas dão suporte a pintura transparente e regiões não retangulares de tela. Um exemplo comum de um controle transparente é um controle de texto com um fundo transparente. Os controles pinta o texto, mas não o plano de fundo, portanto, tudo o que está sob o texto mostra por meio de. Formulários mais recentes geralmente fazem uso de controles não retangulares, como setas e botões de ida e volta.

Geralmente, um controle não precisa de sua própria janela e, em vez disso, pode usar os serviços do Windows de seu contêiner, desde que o contêiner foi escrito para dar suporte a objetos sem janelas. Controles sem janelas são compatíveis com os contêineres mais antigos. Contêineres mais antigos não escritos para dar suporte a controles sem janelas, os controles sem janelas cria uma janela quando ativo.

Como os controles sem janelas não têm suas próprias janelas, o contêiner (que têm uma janela) é responsável por fornecer os serviços que seriam caso contrário, foram fornecidos pela janela do controle. Por exemplo, se seu controle precisa consultar o foco do teclado, capturar o mouse ou obter um contexto de dispositivo, essas operações são gerenciadas pelo contêiner. O contêiner encaminha mensagens de entrada do usuário enviadas para sua janela para o controle sem janelas apropriado, usando o `IOleInPlaceObjectWindowless` interface. (Consulte a *ActiveX SDK* para obter uma descrição dessa interface.) `COleControl` esses serviços do contêiner de invocação de funções de membro.

Para tornar seu controle para usar a ativação sem janelas, inclua o **windowlessActivate** sinalizador no conjunto de sinalizadores retornado por [COleControl::GetControlFlags](../mfc/reference/colecontrol-class.md#getcontrolflags). Por exemplo:

[!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/cpp/providing-windowless-activation_1.cpp)]
[!code-cpp[NVC_MFC_AxOpt#6](../mfc/codesnippet/cpp/providing-windowless-activation_2.cpp)]
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/cpp/providing-windowless-activation_3.cpp)]

O código para incluir esse sinalizador é gerado automaticamente se você selecionar o **ativação sem janelas** opção a [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página do Assistente de controle de ActiveX do MFC.

Quando a ativação sem janelas estiver habilitada, o contêiner delegará a mensagens de entrada para o controle `IOleInPlaceObjectWindowless` interface. `COleControl`da implementação dessa interface despacha as mensagens pelo mapa de mensagens do seu controle, depois de ajustar o mouse coordena adequadamente. Você pode processar as mensagens como mensagens de janela normal, adicionando as entradas correspondentes no mapa de mensagem. Em seus manipuladores para essas mensagens, evite usar o *m_hWnd* variável de membro (ou qualquer função de membro que usa a ele) sem antes verificar se seu valor não é **nulo**.

`COleControl` fornece funções de membro que invocam a captura do mouse, o foco do teclado, rolagem e outros serviços de janela do contêiner conforme apropriado, incluindo:

- [GetFocus](../mfc/reference/colecontrol-class.md#getfocus), [SetFocus](../mfc/reference/colecontrol-class.md#setfocus)

- [GetCapture](../mfc/reference/colecontrol-class.md#getcapture), [SetCapture](../mfc/reference/colecontrol-class.md#setcapture), [ReleaseCapture](../mfc/reference/colecontrol-class.md#releasecapture)

- [GetDC](../mfc/reference/colecontrol-class.md#getdc), [ReleaseDC](../mfc/reference/colecontrol-class.md#releasedc)

- [InvalidateRgn](../mfc/reference/colecontrol-class.md#invalidatergn)

- [ScrollWindow](../mfc/reference/colecontrol-class.md#scrollwindow)

- [GetClientRect](../mfc/reference/colecontrol-class.md#getclientrect)

Em controles sem janelas, você sempre deve usar o `COleControl` funções de membro em vez de correspondente `CWnd` funções de membro ou as funções de API do Win32 relacionadas.

Convém um controle sem janelas para ser o destino de uma operação de arrastar e soltar OLE. Normalmente, isso exigiria que a janela do controle ser registrado como um destino de soltar. Uma vez que o controle não tem nenhuma janela de seu próprio, o contêiner usa sua própria janela como um destino de soltar. O controle fornece uma implementação do `IDropTarget` interface à qual o contêiner pode delegar chamadas no momento apropriado. Para expor essa interface para o contêiner, substitua [COleControl::GetWindowlessDropTarget](../mfc/reference/colecontrol-class.md#getwindowlessdroptarget). Por exemplo:

[!code-cpp[NVC_MFC_AxOpt#8](../mfc/codesnippet/cpp/providing-windowless-activation_4.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

