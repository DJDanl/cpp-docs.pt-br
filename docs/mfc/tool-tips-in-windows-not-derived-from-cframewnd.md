---
title: "Dicas de ferramenta no Windows derivadas de CFrameWnd | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles [MFC], dicas de ferramenta"
  - "habilitando dicas de ferramenta"
  - "funções de manipulador, dicas de ferramenta"
  - "Ajuda, dicas de ferramentas para controles"
  - "Estrutura TOOLTIPTEXT"
  - "TTN_NEEDTEXT (mensagem)"
ms.assetid: cad5ef0f-02e3-4151-ad0d-3d42e6932b0e
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Dicas de ferramenta no Windows derivadas de CFrameWnd
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta família do artigo abrange habilitar dicas de ferramenta para os controles contidos em uma janela que não seja derivada de [CFrameWnd](../mfc/reference/cframewnd-class.md).  O artigo [Dicas de ferramentas das barras de ferramentas](../Topic/Toolbar%20Tool%20Tips.md) fornece informações sobre dicas de ferramenta para controles em `CFrameWnd`.  
  
 Os tópicos abordados nesta família do artigo incluem:  
  
-   [Habilitando dicas de ferramenta](../mfc/enabling-tool-tips.md)  
  
-   [Notificação de manipulação TTN\_NEEDTEXT para dicas de ferramenta](../Topic/Handling%20TTN_NEEDTEXT%20Notification%20for%20Tool%20Tips.md)  
  
-   [A estrutura de TOOLTIPTEXT](../mfc/tooltiptext-structure.md)  
  
 As dicas de ferramenta são exibidas automaticamente para os botões e os outros controles contidos em uma janela pai derivada de `CFrameWnd`.  Isso ocorre porque `CFrameWnd` tem um manipulador padrão para a notificação de [TTN\_GETDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb760269) , que trata de notificações de **TTN\_NEEDTEXT** de controles de dica de ferramenta associados com os controles.  
  
 No entanto, esse manipulador padrão não é chamado quando a notificação de **TTN\_NEEDTEXT** será enviada de um controle da dica de ferramenta associado a um controle em uma janela que não seja `CFrameWnd`, como um controle em uma caixa de diálogo ou em uma exibição de formulário.  Consequentemente, é necessário que você forneça uma função de manipulador para a notificação de **TTN\_NEEDTEXT** para exibir dicas de ferramenta para controles filho.  
  
 As dicas de ferramenta padrão para as janelas fornecidas por [CWnd::EnableToolTips](../Topic/CWnd::EnableToolTips.md) não têm o texto associado a elas.  Para recuperar o texto da dica de ferramenta exibir, a notificação de **TTN\_NEEDTEXT** é enviada à janela pai do controle da dica de ferramenta imediatamente antes que a janela da dica de ferramenta é exibida.  Se não houver um manipulador para que essa mensagem atribui um valor ao membro de **pszText** da estrutura de **TOOLTIPTEXT** , não haverá nenhum texto exibido para a dica de ferramenta.  
  
## Consulte também  
 [Dicas de ferramenta](../mfc/tool-tips.md)