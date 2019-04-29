---
title: Manipulando notificações da dica de ferramenta
ms.date: 11/04/2016
helpviewer_keywords:
- TOOLTIPTEXT structure [MFC]
- CToolBarCtrl class [MFC], handling notifications
- notifications [MFC], tool tips
- tool tips [MFC], notifications
ms.assetid: ddb93b5f-2e4f-4537-8053-3453c86e2bbb
ms.openlocfilehash: 079dc26fdd355c5b5e3f89f28219902e5fd74a79
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62240220"
---
# <a name="handling-tool-tip-notifications"></a>Manipulando notificações da dica de ferramenta

Quando você especifica o **TBSTYLE_TOOLTIPS** estilo, a barra de ferramentas cria e gerencia um controle de dica de ferramenta. Uma dica de ferramenta é uma pequena janela pop-up que contém uma linha de texto que descreve um botão de barra de ferramentas. A dica de ferramenta está oculto, que aparecem somente quando o usuário coloca o cursor em um botão de barra de ferramentas e deixa-lo lá para aproximadamente metade em segundo lugar. A dica de ferramenta é exibida próximo ao cursor.

Antes que a dica de ferramenta é exibida, o **TTN_NEEDTEXT** mensagem de notificação é enviada à janela do proprietário da barra de ferramentas para recuperar o texto descritivo para o botão. Se a janela do proprietário da barra de ferramentas é uma `CFrameWnd` janela, a ferramenta de dicas são exibidas sem nenhum esforço extra, porque `CFrameWnd` tem um manipulador padrão para o **TTN_NEEDTEXT** notificação. Se a janela do proprietário da barra de ferramentas não é derivada de `CFrameWnd`, como uma exibição de formulário ou caixa de diálogo, você deve adicionar uma entrada para mapa de mensagens da janela do proprietário e fornecer um manipulador de notificação no mapa de mensagens. A entrada para mapa de mensagens da janela do proprietário é da seguinte maneira:

[!code-cpp[NVC_MFCControlLadenDialog#40](../mfc/codesnippet/cpp/handling-tool-tip-notifications_1.cpp)]

## <a name="remarks"></a>Comentários

*memberFxn*<br/>
A função de membro a ser chamado quando o texto é necessário para que esse botão.

Observe que a id de uma dica de ferramenta é sempre 0.

Além de **TTN_NEEDTEXT** notificação, um controle de dica de ferramenta pode enviar as notificações a seguir para um controle de barra de ferramentas:

|Notificação|Significado|
|------------------|-------------|
|**TTN_NEEDTEXTA**|Controle da dica de ferramenta requer um texto ASCII (apenas no Windows 95)|
|**TTN_NEEDTEXTW**|Controle da dica de ferramenta requer um texto UNICODE (somente no Windows NT)|
|**TBN_HOTITEMCHANGE**|Indica que o item (realçado) ativo foi alterado.|
|**NM_RCLICK**|Indica que o usuário tem pequeno um botão.|
|**TBN_DRAGOUT**|Indica que o usuário clicou no botão e arrastar o ponteiro fora do botão. Ele permite que um aplicativo implementar o arrastar e soltar de um botão de barra de ferramentas. Ao receber essa notificação, o aplicativo começará a operação de arrastar e operação de remoção.|
|**TBN_DROPDOWN**|Indica que o usuário tenha clicado em um botão que usa o **TBSTYLE_DROPDOWN** estilo.|
|**TBN_GETOBJECT**|Indica que o usuário moveu o ponteiro sobre um botão que usa o **TBSTYLE_DROPPABLE** estilo.|

Para uma função de manipulador de exemplo e obter mais informações sobre como habilitar dicas de ferramenta, consulte [dicas de ferramenta](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md).

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
