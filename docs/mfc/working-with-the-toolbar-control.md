---
title: Trabalhando com o controle de barra de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- GetToolBarCtrl method [MFC]
- toolbars [MFC], accessing common control
- CToolBarCtrl class [MFC], accessing toolbar
- toolbar controls [MFC], accessing
ms.assetid: b19409d5-3831-42c7-80ae-195c49dc9085
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 32d3cc6244bc2f928c8d1d0c6e46d1bc5a57aa3b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="working-with-the-toolbar-control"></a>Trabalhando com o controle da barra de ferramentas
Este artigo explica como é possível acessar o [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objeto subjacente um [CToolBar](../mfc/reference/ctoolbar-class.md) para maior controle sobre as barras de ferramentas. Este é um tópico avançado.  
  
## <a name="procedures"></a>Procedimentos  
  
#### <a name="to-access-the-toolbar-common-control-underlying-your-ctoolbar-object"></a>Para acessar o controle de barra de ferramentas comuns subjacente de seu objeto CToolBar  
  
1.  Chamar [CToolBar::GetToolBarCtrl](../mfc/reference/ctoolbar-class.md#gettoolbarctrl).  
  
 `GetToolBarCtrl` Retorna uma referência a um [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objeto. Você pode usar a referência para chamar funções de membro da classe de controle de barra de ferramentas.  
  
> [!CAUTION]
>  Ao chamar `CToolBarCtrl` **obter** funções é seguro, tenha cuidado se você chamar o **definir** funções. Este é um tópico avançado. Normalmente, você não deve precisa acessar o controle de barra de ferramentas subjacente.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Controles (controles comuns do Windows)](../mfc/controls-mfc.md)  
  
-   [Fundamentos da barra de ferramentas](../mfc/toolbar-fundamentals.md)  
  
-   [Encaixando e flutuando barras de ferramentas](../mfc/docking-and-floating-toolbars.md)  
  
-   [Redimensionar dinamicamente a barra de ferramentas](../mfc/docking-and-floating-toolbars.md)  
  
-   [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)  
  
-   [Atualizações da barra de status flyby](../mfc/toolbar-tool-tips.md)  
  
-   [Manipulando notificações da dica de ferramenta](../mfc/handling-tool-tip-notifications.md)  
  
-   O [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) classes  
  
-   [Manipulando notificações de personalização](../mfc/handling-customization-notifications.md)  
  
-   [Várias barras de ferramentas](../mfc/toolbar-fundamentals.md)  
  
-   [Usando as barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)  
  
-   [Barras de controle](../mfc/control-bars.md)  
  
 Para obter informações gerais sobre o uso de controles comuns do Windows, consulte [controles comuns do](http://msdn.microsoft.com/library/windows/desktop/bb775493).  
  
## <a name="see-also"></a>Consulte também  
 [Implementação da barra de ferramentas do MFC](../mfc/mfc-toolbar-implementation.md)

