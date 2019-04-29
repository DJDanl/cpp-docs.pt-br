---
title: Funções de membro do botão Girar
ms.date: 11/04/2016
helpviewer_keywords:
- spin button control, methods
- CSpinButtonCtrl class [MFC], methods
ms.assetid: a08a26fd-b803-4cbe-a509-395fa357d057
ms.openlocfilehash: 5ad6f529762e77e1cf1c00f41eea0add5d196fbb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62307257"
---
# <a name="spin-button-member-functions"></a>Funções de membro do botão Girar

Há várias funções de membro disponível para o controle de rotação ([CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)). Use essas funções para alterar os seguintes atributos do botão de rotação.

- **Aceleração** você pode ajustar a taxa na qual a posição muda quando o usuário mantém pressionado o botão de seta. Para trabalhar com aceleração, use o [SetAccel](../mfc/reference/cspinbuttonctrl-class.md#setaccel) e [GetAccel](../mfc/reference/cspinbuttonctrl-class.md#getaccel) funções de membro.

- **Base** você pode alterar a base (10 ou 16) usada para exibir a posição da legenda da janela buddy. Para trabalhar com a base, use o [GetBase](../mfc/reference/cspinbuttonctrl-class.md#getbase) e [SetBase](../mfc/reference/cspinbuttonctrl-class.md#setbase) funções de membro.

- **Janela de amigo** dinamicamente, você pode definir a janela buddy. Para consultar ou alterar o controle que é a janela buddy, use o [GetBuddy](../mfc/reference/cspinbuttonctrl-class.md#getbuddy) e [SetBuddy](../mfc/reference/cspinbuttonctrl-class.md#setbuddy) funções de membro.

- **Posição** você pode consultar e alterar a posição. Para trabalhar diretamente com a posição, use o [GetPos](../mfc/reference/cspinbuttonctrl-class.md#getpos) e [SetPos](../mfc/reference/cspinbuttonctrl-class.md#setpos) funções de membro. Uma vez que a legenda do controle buddy pode ter sido alterado (por exemplo, no caso que o amigo é um controle de edição), `GetPos` recupera a legenda atual e ajustará a posição de acordo.

- **Intervalo** você pode alterar as posições de mínimas e máxima para o botão de rotação. Por padrão, o máximo é definido como 0 e o mínimo é definido como 100. Uma vez que o máximo padrão é menor que o mínimo padrão, as ações dos botões de seta é contraintuitivos. Normalmente, você definirá o intervalo usando o [SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) função de membro. Para consultar o uso de intervalo [GetRange](../mfc/reference/cspinbuttonctrl-class.md#getrange).

## <a name="see-also"></a>Consulte também

[Usando CSpinButtonCtrl](../mfc/using-cspinbuttonctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
