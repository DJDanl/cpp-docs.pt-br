---
title: Dicas de ferramenta no Windows derivadas de CFrameWnd
ms.date: 11/04/2016
helpviewer_keywords:
- enabling tool tips [MFC]
- TOOLTIPTEXT structure [MFC]
- Help [MFC], tool tips for controls
- TTN_NEEDTEXT message [MFC]
- controls [MFC], tool tips
- handler functions [MFC], tool tips
ms.assetid: cad5ef0f-02e3-4151-ad0d-3d42e6932b0e
ms.openlocfilehash: 1f68fb62335219ea498163e6124c8e91e49f2938
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511029"
---
# <a name="tool-tips-in-windows-not-derived-from-cframewnd"></a>Dicas de ferramenta no Windows derivadas de CFrameWnd

Esta família de artigos aborda a habilitação de dicas de ferramenta para controles contidos em uma janela que não é derivada de [CFrameWnd](../mfc/reference/cframewnd-class.md). As barras de ferramentas do artigo [dicas de ferramenta](../mfc/toolbar-tool-tips.md) fornecem informações sobre dicas de ferramenta `CFrameWnd`para controles em um.

Os tópicos abordados nesta família de artigos incluem:

- [Habilitando dicas de ferramenta](../mfc/enabling-tool-tips.md)

- [Tratando a notificação TTN_NEEDTEXT para dicas de ferramenta](../mfc/handling-ttn-needtext-notification-for-tool-tips.md)

- [A estrutura TOOLTIPTEXT](../mfc/tooltiptext-structure.md)

Dicas de ferramenta são exibidas automaticamente para botões e outros controles contidos em uma janela pai derivada `CFrameWnd`de. Isso ocorre porque `CFrameWnd` o tem um manipulador padrão para a notificação [TTN_GETDISPINFO](/windows/win32/Controls/ttn-getdispinfo) , que manipula notificações **TTN_NEEDTEXT** de controles de dica de ferramenta associados a controles.

No entanto, esse manipulador padrão não é chamado quando a notificação **TTN_NEEDTEXT** é enviada de um controle de dica de ferramenta associado a um controle em uma janela `CFrameWnd`que não é um, como um controle em uma caixa de diálogo ou um modo de exibição de formulário. Portanto, é necessário fornecer uma função de manipulador para a mensagem de notificação **TTN_NEEDTEXT** a fim de exibir dicas de ferramenta para controles filho.

As dicas de ferramenta padrão fornecidas para suas janelas de [CWnd:: EnableToolTips](../mfc/reference/cwnd-class.md#enabletooltips) não têm texto associado a elas. Para recuperar o texto da dica de ferramenta a ser exibida, a notificação **TTN_NEEDTEXT** é enviada para a janela pai do controle de dica de ferramenta logo antes de a janela de dica de ferramenta ser exibida. Se não houver nenhum manipulador para essa mensagem para atribuir algum valor ao membro *pszText* da estrutura **ToolTipText** , não haverá nenhum texto exibido para a dica de ferramenta.

## <a name="see-also"></a>Consulte também

[Dicas de ferramenta](../mfc/tool-tips.md)
