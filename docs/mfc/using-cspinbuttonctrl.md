---
title: Usando CSpinButtonCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- up-down controls [MFC], spin button control
- up-down controls
- spin button control
- CSpinButtonCtrl class [MFC], using
ms.assetid: a91db36b-e11e-42ef-8e89-51915cc486d2
ms.openlocfilehash: 775668426cd11e20a4c863f07a964935d0d5420f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447180"
---
# <a name="using-cspinbuttonctrl"></a>Usando CSpinButtonCtrl

O controle do *botão de rotação* (também conhecido como controle *de cima para baixo* ) fornece um par de setas que um usuário pode clicar para ajustar um valor. Esse valor é conhecido como a *posição atual*. A posição permanece dentro do intervalo do botão de rotação. Quando o usuário clica na seta para cima, a posição se move para o máximo; e quando o usuário clica na seta para baixo, a posição é movida para o mínimo.

O controle botão de rotação é representado no MFC pela classe [CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md) .

> [!NOTE]
>  Por padrão, o intervalo para o botão de rotação tem o máximo definido como zero (0) e o mínimo definido como 100. Como o valor máximo é menor que o valor mínimo, clicar na seta para cima diminui a posição e clicar na seta para baixo aumenta. Use [CSpinButtonCtrl:: SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) para ajustar esses valores.

Normalmente, a posição atual é exibida em um controle complementar. O controle complementar é conhecido como a *janela do Buddy*. Para obter uma ilustração de um controle de botão de rotação, consulte [sobre controles de cima para baixo](/windows/win32/Controls/up-down-controls) na SDK do Windows.

Para criar um controle de rotação e uma janela de amigo do controle de edição, no Visual Studio, primeiro arraste um controle de edição para a caixa de diálogo ou janela e, em seguida, arraste um controle de rotação. Selecione o controle de rotação e defina seu **amigo automático** e defina propriedades de **inteiro Buddy** como **true**. Defina também a propriedade **Alignment** ; O **alinhamento à direita** é mais comum. Com essas configurações, o controle de edição é definido como a janela Buddy porque precede diretamente o controle de edição na ordem de tabulação. O controle de edição exibe inteiros e o controle de rotação é inserido no lado direito do controle de edição. Opcionalmente, você pode definir o intervalo válido do controle de rotação usando o método [CSpinButtonCtrl:: SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) . Nenhum manipulador de eventos é necessário para se comunicar entre o controle de rotação e a janela de amigo porque eles trocam dados diretamente. Se você usar um controle de rotação para alguma outra finalidade, por exemplo, para paginar uma sequência de janelas ou caixas de diálogo, adicione um manipulador para a mensagem de UDN_DELTAPOS e execute a ação personalizada ali.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Estilos de botão Girar](../mfc/spin-button-styles.md)

- [Funções membro do botão Girar](../mfc/spin-button-member-functions.md)

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)
