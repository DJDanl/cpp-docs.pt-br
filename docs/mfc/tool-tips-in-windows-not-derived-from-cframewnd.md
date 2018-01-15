---
title: Dicas de ferramenta no Windows derivadas de CFrameWnd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- enabling tool tips [MFC]
- TOOLTIPTEXT structure [MFC]
- Help [MFC], tool tips for controls
- TTN_NEEDTEXT message [MFC]
- controls [MFC], tool tips
- handler functions [MFC], tool tips
ms.assetid: cad5ef0f-02e3-4151-ad0d-3d42e6932b0e
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c27126954f72eb4a075d0741b0ec0faec94f381c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tool-tips-in-windows-not-derived-from-cframewnd"></a>Dicas de ferramenta no Windows derivadas de CFrameWnd
Família este artigo aborda habilitando dicas de ferramenta para controles contidos em uma janela que não é derivada de [CFrameWnd](../mfc/reference/cframewnd-class.md). O artigo [dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md) fornece informações sobre dicas de ferramenta para controles em um `CFrameWnd`.  
  
 Os tópicos abordados nesta família artigo incluem:  
  
-   [Habilitando dicas de ferramenta](../mfc/enabling-tool-tips.md)  
  
-   [Tratando a notificação TTN_NEEDTEXT para dicas de ferramenta](../mfc/handling-ttn-needtext-notification-for-tool-tips.md)  
  
-   [Estrutura TOOLTIPTEXT](../mfc/tooltiptext-structure.md)  
  
 Dicas de ferramenta são exibidas automaticamente para os botões e outros controles contidos em uma janela pai derivam de `CFrameWnd`. Isso ocorre porque `CFrameWnd` tem um manipulador padrão para o [TTN_GETDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb760269) notificação, que manipula **TTN_NEEDTEXT** controles associados a controles de dica de notificações da ferramenta.  
  
 No entanto, esse manipulador padrão não é chamado quando o **TTN_NEEDTEXT** notificação é enviada de um controle de dica de ferramenta associado a um controle em uma janela que não é um `CFrameWnd`, como um controle em uma caixa de diálogo ou uma exibição de formulário. Portanto, é necessário para fornecer uma função de manipulador para o **TTN_NEEDTEXT** mensagem de notificação para exibir dicas de ferramentas para controles filho.  
  
 As dicas de ferramenta padrão fornecidas para o windows por [CWnd::EnableToolTips](../mfc/reference/cwnd-class.md#enabletooltips) não tem texto associado a eles. Para recuperar o texto da dica de ferramenta a ser exibido, o **TTN_NEEDTEXT** notificação é enviada para a janela pai do controle de dica de ferramenta antes que a janela de dica de ferramenta é exibida. Se não houver nenhum manipulador para essa mensagem atribuir um valor para o **pszText** membro o **TOOLTIPTEXT** estrutura, não haverá nenhum texto exibido para a dica de ferramenta.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de ferramenta](../mfc/tool-tips.md)

