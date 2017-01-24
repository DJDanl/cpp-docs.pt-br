---
title: "Habilitando dicas de ferramenta | Microsoft Docs"
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
  - "habilitando dicas de ferramenta"
  - "inicializando dicas de ferramenta"
  - "dicas de ferramenta [C++], ativando"
  - "dicas de ferramenta [C++], inicializando"
ms.assetid: 06b7c889-7722-4ce6-8b88-9efa50fe6369
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Habilitando dicas de ferramenta
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode habilitar o suporte da dica de ferramenta para os controles filho de uma janela \(como os controles em uma exibição ou em uma caixa de diálogo de formulário\).  
  
### Para habilitar dicas de ferramenta para os controles filho de uma janela  
  
1.  Chame `EnableToolTips` para a janela para a qual você deseja fornecer dicas de ferramenta.  
  
2.  Forneça uma cadeia de caracteres para cada controle no manipulador de [Notificação de TTN\_NEEDTEXT](../Topic/Handling%20TTN_NEEDTEXT%20Notification%20for%20Tool%20Tips.md) .  O manipulador está no mapa da mensagem da janela que contém os controles filho \(por exemplo, sua classe da exibição de formulário\).  Este manipulador deve chamar uma função que identifica o controle e definir **pszText** para especificar o texto usado pelo controle da dica de ferramenta.  
  
## Consulte também  
 [Dicas de ferramenta no Windows derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)