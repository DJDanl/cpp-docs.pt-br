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
ms.openlocfilehash: 75850dbf92587cf654d4f7a39ea54af1fd9dd5bd
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620074"
---
# <a name="handling-ttn_needtext-notification-for-tool-tips"></a>Manipulando notificação TTN_NEEDTEXT para dicas de ferramenta

Como parte da [habilitação de dicas de ferramenta](enabling-tool-tips.md), você manipula a mensagem de **TTN_NEEDTEXT** adicionando a seguinte entrada ao mapa de mensagens da sua janela do proprietário:

[!code-cpp[NVC_MFCControlLadenDialog#40](codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_1.cpp)]

*memberFxn*<br/>
A função de membro a ser chamada quando o texto for necessário para esse botão.

Observe que a ID de uma dica de ferramenta é sempre 0.

Declare sua função de manipulador na definição de classe da seguinte maneira:

[!code-cpp[NVC_MFCControlLadenDialog#53](codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_2.h)]

onde os parâmetros em itálico são:

*id*<br/>
Identificador do controle que enviou a notificação. Não usado. A ID de controle é obtida da estrutura **NMHDR** .

*pNMHDR*<br/>
Um ponteiro para a estrutura [NMTTDISPINFO](/windows/win32/api/commctrl/ns-commctrl-nmttdispinfow) . Essa estrutura também é discutida mais detalhadamente na [estrutura TOOLTIPTEXT](tooltiptext-structure.md).

*pResult*<br/>
Um ponteiro para o código de resultado que você pode definir antes de retornar. **TTN_NEEDTEXT** manipuladores podem ignorar o parâmetro *pResult* .

Como um exemplo de um manipulador de notificação de exibição de formulário:

[!code-cpp[NVC_MFCControlLadenDialog#54](codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_3.cpp)]

Chamada `EnableToolTips` (este fragmento tirado de `OnInitDialog` ):

[!code-cpp[NVC_MFCControlLadenDialog#55](codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_4.cpp)]

## <a name="see-also"></a>Consulte também

[Dicas de ferramenta no Windows derivadas de CFrameWnd](tool-tips-in-windows-not-derived-from-cframewnd.md)
