---
title: Manipulando notificação TTN_NEEDTEXT para dicas de ferramenta
ms.date: 11/04/2016
f1_keywords:
- TTN_NEEDTEXT
helpviewer_keywords:
- TTN_NEEDTEXT message [MFC]
- notifications [MFC], tool tips
- tool tips [MFC], notifications
ms.assetid: d0370a65-21ba-4676-bcc5-8cf851bbb15c
ms.openlocfilehash: a63154f3da539676f31709899568b6486dc6017e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508525"
---
# <a name="handling-ttn_needtext-notification-for-tool-tips"></a>Manipulando notificação TTN_NEEDTEXT para dicas de ferramenta

Como parte da [habilitação das dicas de ferramenta](../mfc/enabling-tool-tips.md), você manipula a mensagem **TTN_NEEDTEXT** adicionando a seguinte entrada ao mapa de mensagens da sua janela do proprietário:

[!code-cpp[NVC_MFCControlLadenDialog#40](../mfc/codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_1.cpp)]

*memberFxn*<br/>
A função de membro a ser chamada quando o texto for necessário para esse botão.

Observe que a ID de uma dica de ferramenta é sempre 0.

Declare sua função de manipulador na definição de classe da seguinte maneira:

[!code-cpp[NVC_MFCControlLadenDialog#53](../mfc/codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_2.h)]

onde os parâmetros em itálico são:

*id*<br/>
Identificador do controle que enviou a notificação. Não usado. A ID de controle é obtida da estrutura **NMHDR** .

*pNMHDR*<br/>
Um ponteiro para a estrutura [NMTTDISPINFO](/windows/win32/api/commctrl/ns-commctrl-nmttdispinfow) . Essa estrutura também é discutida mais detalhadamente na [estrutura TOOLTIPTEXT](../mfc/tooltiptext-structure.md).

*pResult*<br/>
Um ponteiro para o código de resultado que você pode definir antes de retornar. Os manipuladores **TTN_NEEDTEXT** podem ignorar o parâmetro *pResult* .

Como um exemplo de um manipulador de notificação de exibição de formulário:

[!code-cpp[NVC_MFCControlLadenDialog#54](../mfc/codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_3.cpp)]

Chamada `EnableToolTips` (este fragmento tirado `OnInitDialog`de):

[!code-cpp[NVC_MFCControlLadenDialog#55](../mfc/codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_4.cpp)]

## <a name="see-also"></a>Consulte também

[Dicas de ferramenta no Windows não derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)
