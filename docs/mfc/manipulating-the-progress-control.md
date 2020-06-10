---
title: Manipulando o controle de progresso
ms.date: 11/04/2016
helpviewer_keywords:
- CProgressCtrl class [MFC], working with
- progress controls [MFC], manipulating
- CProgressCtrl class [MFC], manipulating
- controlling progress controls [MFC]
- CProgressCtrl class [MFC], using
ms.assetid: 9af561d1-980b-4003-a6da-ff79be15bf23
ms.openlocfilehash: 3e3521a82854a85062f9b06bc33eb268d4b9c7a6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622426"
---
# <a name="manipulating-the-progress-control"></a>Manipulando o controle de progresso

Há três maneiras de alterar a posição atual de um controle de progresso ([CProgressCtrl](reference/cprogressctrl-class.md)).

- A posição pode ser alterada por um valor de incremento predefinido.

- A posição pode ser alterada por um valor arbitrário.

- A posição pode ser alterada para um valor específico.

### <a name="to-change-the-position-by-a-preset-amount"></a>Para alterar a posição por um valor predefinido

1. Use a função de membro [SetStep](reference/cprogressctrl-class.md#setstep) para definir o valor de incremento. Por padrão, esse valor é 10. Esse valor é normalmente definido como uma das configurações iniciais do controle. O valor da etapa pode ser negativo.

1. Use a função de membro [StepIt](reference/cprogressctrl-class.md#stepit) para incrementar a posição. Isso faz com que o controle seja redesenhado.

    > [!NOTE]
    >  `StepIt`fará com que a posição seja encapsulada. Por exemplo, dado um intervalo de 1 -100, uma etapa de 20 e uma posição de 90, `StepIt` definirá a posição como 10.

### <a name="to-change-the-position-by-an-arbitrary-amount"></a>Para alterar a posição por um valor arbitrário

1. Use a função de membro [OffsetPos](reference/cprogressctrl-class.md#offsetpos) para alterar a posição. `OffsetPos`aceitará valores negativos.

    > [!NOTE]
    >  `OffsetPos`ao contrário `StepIt` , o não encapsulará a posição. A nova posição é ajustada para permanecer dentro do intervalo.

### <a name="to-change-the-position-to-a-specific-value"></a>Para alterar a posição para um valor específico

1. Use a função de membro [SetPos](reference/cprogressctrl-class.md#setpos) para definir a posição como um valor específico. Se necessário, a nova posição é ajustada para estar dentro do intervalo.

Normalmente, o controle de progresso é usado somente para saída. Para obter a posição atual sem especificar um novo valor, use [GetPos](reference/cprogressctrl-class.md#getpos).

## <a name="see-also"></a>Consulte também

[Usando CProgressCtrl](using-cprogressctrl.md)<br/>
[Controles](controls-mfc.md)
