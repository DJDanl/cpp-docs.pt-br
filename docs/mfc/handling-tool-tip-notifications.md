---
title: "Manipulando notificações da dica de ferramenta | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- TOOLTIPTEXT structure [MFC]
- CToolBarCtrl class [MFC], handling notifications
- notifications [MFC], tool tips
- tool tips [MFC], notifications
ms.assetid: ddb93b5f-2e4f-4537-8053-3453c86e2bbb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2b7668420b849dc08215a4fc309edf86e9171462
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="handling-tool-tip-notifications"></a>Manipulando notificações da dica de ferramenta
Quando você especifica o `TBSTYLE_TOOLTIPS` estilo, a barra de ferramentas cria e gerencia um controle de dica de ferramenta. Uma dica de ferramenta é uma pequena janela pop-up que contém uma linha de texto que descreve um botão de barra de ferramentas. A dica de ferramenta está oculto, que aparecem somente quando o usuário coloca o cursor em um botão de barra de ferramentas e deixa-lo para aproximadamente metade de segundo. A dica de ferramenta é exibida próximo ao cursor.  
  
 Antes da dica de ferramenta é exibida, o **TTN_NEEDTEXT** mensagem de notificação é enviada à janela do proprietário da barra de ferramentas para recuperar o texto descritivo para o botão. Se a janela do proprietário da barra de ferramentas é um `CFrameWnd` janela de ferramenta dicas são exibidas sem qualquer esforço extra, porque `CFrameWnd` tem um manipulador padrão para o **TTN_NEEDTEXT** notificação. Se a janela do proprietário da barra de ferramentas não é derivada de `CFrameWnd`, como uma exibição de formulário ou uma caixa de diálogo, você deve adicionar uma entrada para mapa de mensagem da janela do proprietário e fornecer um manipulador de notificação no mapa de mensagem. A entrada de mapa de mensagem da janela do proprietário é o seguinte:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#40](../mfc/codesnippet/cpp/handling-tool-tip-notifications_1.cpp)]  
  
## <a name="remarks"></a>Comentários  
 `memberFxn`  
 A função de membro a ser chamado quando o texto é necessário para este botão.  
  
 Observe que a id de uma dica de ferramenta será sempre 0.  
  
 Além de **TTN_NEEDTEXT** notificação, um controle de dica de ferramenta pode enviar as seguintes notificações para um controle de barra de ferramentas:  
  
|Notificação|Significado|  
|------------------|-------------|  
|**TTN_NEEDTEXTA**|Controle de dica de ferramenta requer um texto ASCII (apenas Windows 95)|  
|**TTN_NEEDTEXTW**|Controle de dica de ferramenta requer um texto UNICODE (somente Windows NT)|  
|**TBN_HOTITEMCHANGE**|Indica que o item (destacado) ativo foi alterado.|  
|**NM_RCLICK**|Indica que o usuário tem pequeno um botão.|  
|**TBN_DRAGOUT**|Indica que o usuário clicou no botão e arrastar o ponteiro fora do botão. Ele permite que um aplicativo implementar arrastar e soltar de um botão de barra de ferramentas. Ao receber esta notificação, o aplicativo Iniciar a operação de arrastar e soltar a operação.|  
|**TBN_DROPDOWN**|Indica que o usuário clicou em um botão que usa o **TBSTYLE_DROPDOWN** estilo.|  
|**TBN_GETOBJECT**|Indica que o usuário moveu o ponteiro sobre um botão que usa o **TBSTYLE_DROPPABLE** estilo.|  
  
 Para uma função de manipulador de exemplo e obter mais informações sobre como ativar dicas de ferramenta, consulte [dicas de ferramenta](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

