---
title: Usando CSpinButtonCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3768cda94eb0adda8562c46124be8e9b2d4a2501
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215086"
---
# <a name="using-cspinbuttonctrl"></a>Usando CSpinButtonCtrl
O *botão de rotação* controle (também conhecido como um *up-down* controle) fornece um par de setas em que um usuário pode clicar para ajustar um valor. Esse valor é conhecido como o *posição atual*. A posição permanece dentro do intervalo do botão de rotação. Quando o usuário clica na seta para cima, a posição se move em direção ao máximo; e quando o usuário clica na seta para baixo, a posição se move em direção ao mínimo.  
  
 O controle de botão de rotação é representado no MFC com o [CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md) classe.  
  
> [!NOTE]
>  Por padrão, o intervalo para o botão de rotação tem o máximo definido como zero (0) e o mínimo definido como 100. Como o valor máximo é menor que o valor mínimo, clicando na seta para cima diminui a posição e clicando na seta para baixo aumenta a ele. Use [CSpinButtonCtrl::SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) para ajustar esses valores.  
  
 Normalmente, a posição atual é exibida em um controle complementar. O controle complementar é conhecido como o *janela buddy*. Para obter uma ilustração de um controle de botão de rotação, consulte [sobre controles de cima para baixo](/windows/desktop/Controls/up-down-controls) no SDK do Windows.  
  
 Para criar um controle de rotação e uma janela de buddy do controle de edição, no Visual Studio, arraste um controle de edição para a caixa de diálogo ou janela e, em seguida, arraste um controle de rotação. Selecione o controle de rotação e defina suas **Buddy automático** e **conjunto inteiro de amigo** propriedades a serem **verdadeiro**. Também defina as **alinhamento** propriedade; **Alinhar à direita** é mais comum. Com essas configurações, o controle de edição é definido como a janela buddy porque precede diretamente o controle de edição na ordem de tabulação. O controle de edição exibe números inteiros e o controle de rotação é inserido no lado direito do controle de edição. Opcionalmente, você pode definir o intervalo válido de controle de rotação usando a [CSpinButtonCtrl::SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) método. Não há manipuladores de eventos são necessárias para se comunicar entre o controle de rotação e a janela buddy porque eles trocam dados diretamente. Se você usar um controle de rotação para algum outro propósito, por exemplo, para a página por meio de uma sequência de janelas ou caixas de diálogo, em seguida, adicione um manipulador para a mensagem UDN_DELTAPOS e executar sua ação de personalizado.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Estilos de botão Girar](../mfc/spin-button-styles.md)  
  
-   [Funções membro do botão Girar](../mfc/spin-button-member-functions.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles](../mfc/controls-mfc.md)

