---
title: "Manipulando notifica&#231;&#245;es da dica de ferramenta | Microsoft Docs"
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
  - "Classe CToolBarCtrl, manipulando notificações"
  - "notificações, dicas de ferramenta"
  - "dicas de ferramenta [C++], notificações"
  - "Estrutura TOOLTIPTEXT"
ms.assetid: ddb93b5f-2e4f-4537-8053-3453c86e2bbb
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipulando notifica&#231;&#245;es da dica de ferramenta
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você especifica o estilo de `TBSTYLE_TOOLTIPS` , a barra de ferramentas cria e gerencia um controle da dica de ferramenta.  Uma dica de ferramenta é uma janela pop\-up pequeno que contém uma linha de texto que descreve um botão da barra de ferramentas.  A dica de ferramenta é ocultada, aparecendo apenas quando o usuário coloca o cursor em um botão da barra de ferramentas e em planilhas nele para aproximadamente um meio de segundo.  A dica de ferramenta é exibida pelo cursor.  
  
 Antes que a dica de ferramenta é exibida, a notificação de **TTN\_NEEDTEXT** é enviada à janela do proprietário da barra de ferramentas para recuperar o texto descritivo para o botão.  Se a janela do proprietário da barra de ferramentas é uma janela de `CFrameWnd` , as dicas de ferramenta é exibida sem esforço adicional, porque `CFrameWnd` tem um manipulador padrão para a notificação de **TTN\_NEEDTEXT** .  Se a janela do proprietário da barra de ferramentas não é derivada de `CFrameWnd`, como uma exibição da caixa de diálogo ou do formulário, adicione uma entrada para mapa de mensagem da janela do proprietário e forneça um manipulador de notificação da mensagem.  A entrada para mapa de mensagem da janela do proprietário é a seguinte:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#40](../mfc/codesnippet/CPP/handling-tool-tip-notifications_1.cpp)]  
  
## Comentários  
 `memberFxn`  
 A função de membro a ser chamada quando o texto é necessário para esse botão.  
  
 Observe que a ID de uma dica de ferramenta é sempre 0.  
  
 Além da notificação de **TTN\_NEEDTEXT** , um controle da dica de ferramenta pode enviar as seguintes notificações a um controle da barra de ferramentas:  
  
|Notificação|Significado|  
|-----------------|-----------------|  
|**TTN\_NEEDTEXTA**|O controle da dica de ferramenta requer o texto ASCII \(Windows somente 95\)|  
|**TTN\_NEEDTEXTW**|O controle da dica de ferramenta requer o texto Unicode \(Windows NT somente\)|  
|**TBN\_HOTITEMCHANGE**|Indica que o item realçado \(quente\) foi alterado.|  
|**NM\_RCLICK**|Indica que o usuário clique com o botão direito do mouse em um botão.|  
|**TBN\_DRAGOUT**|Indica que o usuário clicou o botão e arrastou o ponteiro fora do botão.  Permite que um aplicativo implementar o arraste e solte de um botão da barra de ferramentas.  Ao receber essa notificação, o aplicativo iniciará à direita e removerá a operação.|  
|**TBN\_DROPDOWN**|Indica que o usuário clicou um botão que usa o estilo de **TBSTYLE\_DROPDOWN** .|  
|**TBN\_GETOBJECT**|Indica que o usuário moveu o ponteiro sobre um botão que usa o estilo de **TBSTYLE\_DROPPABLE** .|  
  
 Para uma função de manipulador de exemplo e mais informações sobre como ativar dicas de ferramenta, consulte [Dicas de ferramenta](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md).  
  
## Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)