---
title: Manipulando notificações da dica de ferramenta
ms.date: 11/04/2016
helpviewer_keywords:
- TOOLTIPTEXT structure [MFC]
- CToolBarCtrl class [MFC], handling notifications
- notifications [MFC], tool tips
- tool tips [MFC], notifications
ms.assetid: ddb93b5f-2e4f-4537-8053-3453c86e2bbb
ms.openlocfilehash: 41e3dbfc2269f5fbf3c12dc00c19f8a2253fd16a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626441"
---
# <a name="handling-tool-tip-notifications"></a>Manipulando notificações da dica de ferramenta

Quando você especifica o estilo de **TBSTYLE_TOOLTIPS** , a barra de ferramentas cria e gerencia um controle de dica de ferramenta. Uma dica de ferramenta é uma pequena janela pop-up que contém uma linha de texto que descreve um botão da barra de ferramentas. A dica de ferramenta está oculta, aparecendo somente quando o usuário coloca o cursor em um botão da barra de ferramentas e o deixa lá por aproximadamente um meio segundo. A dica de ferramenta é exibida perto do cursor.

Antes de a dica de ferramenta ser exibida, a **TTN_NEEDTEXT** mensagem de notificação é enviada à janela do proprietário da barra de ferramentas para recuperar o texto descritivo do botão. Se a janela do proprietário da barra de ferramentas for uma `CFrameWnd` janela, as dicas de ferramenta serão exibidas sem nenhum esforço extra, pois `CFrameWnd` o tem um manipulador padrão para a notificação de **TTN_NEEDTEXT** . Se a janela do proprietário da barra de ferramentas não for derivada de `CFrameWnd` , como uma caixa de diálogo ou modo de exibição de formulário, você deverá adicionar uma entrada ao mapa de mensagens da janela do proprietário e fornecer um manipulador de notificação no mapa de mensagens. A entrada para o mapa de mensagens da janela do proprietário é a seguinte:

[!code-cpp[NVC_MFCControlLadenDialog#40](codesnippet/cpp/handling-tool-tip-notifications_1.cpp)]

## <a name="remarks"></a>Comentários

*memberFxn*<br/>
A função de membro a ser chamada quando o texto for necessário para esse botão.

Observe que a ID de uma dica de ferramenta é sempre 0.

Além da notificação de **TTN_NEEDTEXT** , um controle de dica de ferramenta pode enviar as seguintes notificações para um controle de barra de ferramentas:

|Notificação|Significado|
|------------------|-------------|
|**TTN_NEEDTEXTA**|O controle de dica de ferramenta requer texto ASCII (somente Windows 95)|
|**TTN_NEEDTEXTW**|O controle de dica de ferramenta requer texto UNICODE (somente Windows NT)|
|**TBN_HOTITEMCHANGE**|Indica que o item ativo (realçado) foi alterado.|
|**NM_RCLICK**|Indica que o usuário clicou com o botão direito do mouse em um botão.|
|**TBN_DRAGOUT**|Indica que o usuário clicou no botão e arrastou o ponteiro para fora do botão. Ele permite que um aplicativo implemente o recurso arrastar e soltar de um botão da barra de ferramentas. Ao receber essa notificação, o aplicativo iniciará a operação de arrastar e soltar.|
|**TBN_DROPDOWN**|Indica que o usuário clicou em um botão que usa o estilo de **TBSTYLE_DROPDOWN** .|
|**TBN_GETOBJECT**|Indica que o usuário moveu o ponteiro sobre um botão que usa o estilo de **TBSTYLE_DROPPABLE** .|

Para obter um exemplo de função de manipulador e mais informações sobre como habilitar dicas de ferramenta, consulte [dicas de ferramenta](tool-tips-in-windows-not-derived-from-cframewnd.md).

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](using-ctoolbarctrl.md)<br/>
[Controles](controls-mfc.md)
