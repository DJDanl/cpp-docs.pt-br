---
title: Fornecendo interação do mouse enquanto inativo
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], mouse interaction
ms.assetid: b09106bf-44c7-4b9b-a6d9-0d624f16f5b3
ms.openlocfilehash: bb4b5059e9a3a712a63d5693f3f3ffe95d14ecf0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50584659"
---
# <a name="providing-mouse-interaction-while-inactive"></a>Fornecendo interação do mouse enquanto inativo

Se o controle não estiver ativado imediatamente, ainda convém-lo ao processo WM_SETCURSOR e WM_MOUSEMOVE mensagens mesmo que o controle não tem nenhuma janela de seu próprio. Isso pode ser feito habilitando `COleControl`da implementação do `IPointerInactive` interface, que é desabilitado por padrão. (Consulte a *ActiveX SDK* para obter uma descrição dessa interface.) Para habilitá-lo, incluir o sinalizador pointerInactive no conjunto de sinalizadores retornado por [COleControl::GetControlFlags](../mfc/reference/colecontrol-class.md#getcontrolflags):

[!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_1.cpp)]
[!code-cpp[NVC_MFC_AxOpt#10](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_2.cpp)]
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_3.cpp)]

O código para incluir esse sinalizador é gerado automaticamente se você selecionar o **Mouse ponteiro notificações quando inativa** opção a [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página durante a criação de seu controle com o **Assistente de controle ActiveX do MFC**.

Quando o `IPointerInactive` interface está habilitada, o contêiner delega WM_SETCURSOR e WM_MOUSEMOVE mensagens para ela. `COleControl`da implementação de `IPointerInactive` despacha as mensagens pelo mapa de mensagens do seu controle depois de ajustar o mouse coordena adequadamente. Você pode processar as mensagens assim como as mensagens de janela normal, adicionando as entradas correspondentes no mapa de mensagem. Em seus manipuladores para essas mensagens, evite usar o *m_hWnd* variável de membro (ou qualquer função de membro que usa a ele) sem antes verificar se seu valor não é **nulo**.

Talvez você queira um controle inativo para ser o destino de uma operação de arrastar e soltar OLE. Isso requer ativando o controle no momento em que o usuário arrasta um objeto sobre ele, para que a janela do controle pode ser registrada como um destino de soltar. Para fazer com que a ativação ocorrer durante uma operação de arrastar, substitua [COleControl::GetActivationPolicy](../mfc/reference/colecontrol-class.md#getactivationpolicy)e retornam o sinalizador POINTERINACTIVE_ACTIVATEONDRAG:

[!code-cpp[NVC_MFC_AxOpt#11](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_4.cpp)]

Habilitando o `IPointerInactive` interface normalmente significa que você deseja que o controle para ser capaz de processar mensagens do mouse em todos os momentos. Para obter esse comportamento em um contêiner que não oferece suporte a `IPointerInactive` interface, você precisa ter seu controle sempre ativado quando visível, que significa que o controle deve incluir o sinalizador OLEMISC_ACTIVATEWHENVISIBLE entre seus diversos sinalizadores. No entanto, para impedir que esse sinalizador de entrarem em vigor em um contêiner que dá suporte `IPointerInactive`, você também pode especificar o sinalizador OLEMISC_IGNOREACTIVATEWHENVISIBLE:

[!code-cpp[NVC_MFC_AxOpt#12](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_5.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

