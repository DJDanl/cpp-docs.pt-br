---
title: "Manipulando notificação TTN_NEEDTEXT para dicas de ferramenta | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: TTN_NEEDTEXT
dev_langs: C++
helpviewer_keywords:
- TTN_NEEDTEXT message [MFC]
- notifications [MFC], tool tips
- tool tips [MFC], notifications
ms.assetid: d0370a65-21ba-4676-bcc5-8cf851bbb15c
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1a3ff274358a0c95ce5c8964115897b0b17c1635
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="handling-ttnneedtext-notification-for-tool-tips"></a>Manipulando notificação TTN_NEEDTEXT para dicas de ferramenta
Como parte do [habilitando dicas de ferramenta](../mfc/enabling-tool-tips.md), manipular o **TTN_NEEDTEXT** mensagem adicionando a seguinte entrada ao mapa de mensagem da janela do proprietário:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#40](../mfc/codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_1.cpp)]  
  
 `memberFxn`  
 A função de membro a ser chamado quando o texto é necessário para este botão.  
  
 Observe que a ID de uma dica de ferramenta será sempre 0.  
  
 Declare a função do manipulador na definição de classe da seguinte maneira:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#53](../mfc/codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_2.h)]  
  
 onde estão os parâmetros em itálico:  
  
 `id`  
 Identificador do controle que enviou a notificação. Não usado. A id do controle é obtida a **NMHDR** estrutura.  
  
 `pNMHDR`  
 Um ponteiro para o [NMTTDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb760258) estrutura. Essa estrutura também é discutida mais [a estrutura de TOOLTIPTEXT](../mfc/tooltiptext-structure.md).  
  
 `pResult`  
 Um ponteiro para o código de resultado que você pode definir antes de retornar. **TTN_NEEDTEXT** manipuladores podem ignorar o `pResult` parâmetro.  
  
 Como um exemplo de um manipulador de notificação de exibição de formulário:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#54](../mfc/codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_3.cpp)]  
  
 Chamar `EnableToolTips` (este fragmento obtido `OnInitDialog`):  
  
 [!code-cpp[NVC_MFCControlLadenDialog#55](../mfc/codesnippet/cpp/handling-ttn-needtext-notification-for-tool-tips_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de ferramenta no Windows não derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)

