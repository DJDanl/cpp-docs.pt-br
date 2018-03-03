---
title: Usando CSpinButtonCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CSpinButtonCtrl
dev_langs:
- C++
helpviewer_keywords:
- up-down controls [MFC], spin button control
- up-down controls
- spin button control
- CSpinButtonCtrl class [MFC], using
ms.assetid: a91db36b-e11e-42ef-8e89-51915cc486d2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bd1e652edb3501583624b068c604083f0c5d4165
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-cspinbuttonctrl"></a>Usando CSpinButtonCtrl
O *botão de rotação* controle (também conhecido como um *acima-abaixo* controle) fornece um par de setas que um usuário pode clicar para ajustar um valor. Esse valor é conhecido como o *posição atual*. A posição permanece dentro do intervalo do botão de rotação. Quando o usuário clica na seta para cima, a posição aproxima o máximo; e, quando o usuário clica na seta para baixo, a posição aproxima o mínimo.  
  
 O controle de botão de rotação é representado em MFC pelo [CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md) classe.  
  
> [!NOTE]
>  Por padrão, o intervalo para o botão de rotação tem o máximo definido como zero (0) e o mínimo definido como 100. Como o valor máximo é menor que o valor mínimo, clicando na seta para cima diminui a posição e clicando na seta para baixo aumenta a ele. Use [CSpinButtonCtrl::SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) ajustar esses valores.  
  
 Normalmente, a posição atual é exibida em um controle complementar. O controle complementar é conhecido como o *janela buddy*. Para obter uma ilustração de um controle de botão de rotação, consulte [sobre os controles para cima para baixo](http://msdn.microsoft.com/library/windows/desktop/bb759889) no SDK do Windows.  
  
 Para criar um controle de rotação e uma janela de buddy do controle de edição, no Visual Studio, arraste um controle de edição para a caixa de diálogo ou janela e, em seguida, arraste um controle de rotação. Selecione o controle de rotação e defina seu **Buddy automático** e **conjunto inteiro de amigo** propriedades **True**. Defina também a **alinhamento** propriedade; **Alinhar à direita** é mais comum. Com essas configurações, o controle de edição é definido como a janela buddy porque ela diretamente precede o controle de edição na ordem de tabulação. O controle de edição exibe números inteiros e o controle de rotação é inserido no lado direito do controle de edição. Opcionalmente, você pode definir o intervalo válido do controle de rotação usando o [CSpinButtonCtrl::SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) método. Não há manipuladores de eventos são necessárias para se comunicar entre o controle de rotação e a janela buddy porque eles trocam dados diretamente. Se você usar um controle de rotação para algum outro propósito, por exemplo, para ver uma sequência de janelas ou caixas de diálogo, em seguida, adicionar um manipulador para o `UDN_DELTAPOS` de mensagens e executar a ação personalizada.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Estilos de botão Girar](../mfc/spin-button-styles.md)  
  
-   [Funções membro do botão Girar](../mfc/spin-button-member-functions.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles](../mfc/controls-mfc.md)

