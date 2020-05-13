---
title: Usando CSpinButtonCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- up-down controls [MFC], spin button control
- up-down controls
- spin button control
- CSpinButtonCtrl class [MFC], using
ms.assetid: a91db36b-e11e-42ef-8e89-51915cc486d2
ms.openlocfilehash: 6f72601d3813f36e4a99b9ab04f2e9383c58df94
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366479"
---
# <a name="using-cspinbuttonctrl"></a>Usando CSpinButtonCtrl

O controle *do botão de giro* (também conhecido como controle para *cima)* fornece um par de setas que um usuário pode clicar para ajustar um valor. Esse valor é conhecido como a *posição atual.* A posição permanece dentro do intervalo do botão de giro. Quando o usuário clica na seta para cima, a posição se move em direção ao máximo; e quando o usuário clica na seta para baixo, a posição se move em direção ao mínimo.

O controle do botão de giro é representado em MFC pela classe [CSpinButtonCtrl.](../mfc/reference/cspinbuttonctrl-class.md)

> [!NOTE]
> Por padrão, o intervalo para o botão de giro tem o máximo definido para zero (0) e o mínimo definido para 100. Como o valor máximo é menor que o valor mínimo, clicar na seta para cima diminui a posição e clicar na seta para baixo aumenta-a. Use [CSpinButtonCtrl::SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) para ajustar esses valores.

Normalmente, a posição atual é exibida em um controle de companheiro. O controle do companheiro é conhecido como a *janela do amigo.* Para obter uma ilustração de um controle de botão de giro, consulte [Controles sobre a repressão](/windows/win32/Controls/up-down-controls) no SDK do Windows.

Para criar um controle de rotação e uma janela de controle de edição, no Visual Studio, primeiro arraste um controle de edição para a caixa de diálogo ou janela e arraste um controle de giro. Selecione o controle de giro e defina as propriedades **Auto Buddy** e **Set Buddy Integer** como **True**. Também defina a propriedade **Alignment;** **Right Align** é o mais típico. Com essas configurações, o controle de edição é definido como a janela buddy porque precede diretamente o controle de edição na ordem de guia. O controle de edição exibe inteiros e o controle de giro é incorporado no lado direito do controle de edição. Opcionalmente, você pode definir o intervalo válido do controle de spin usando o método [CSpinButtonCtrl::SetRange.](../mfc/reference/cspinbuttonctrl-class.md#setrange) Nenhum manipulador de eventos é obrigado a se comunicar entre o controle de rotação e a janela de amigos porque eles trocam dados diretamente. Se você usar um controle de rotação para algum outro propósito, por exemplo, para fazer uma página através de uma seqüência de janelas ou caixas de diálogo, adicione um manipulador para a mensagem UDN_DELTAPOS e execute sua ação personalizada lá.

## <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Estilos de botão Girar](../mfc/spin-button-styles.md)

- [Funções membro do botão Girar](../mfc/spin-button-member-functions.md)

## <a name="see-also"></a>Confira também

[Controles](../mfc/controls-mfc.md)
