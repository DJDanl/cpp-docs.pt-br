---
title: Configurações para o controle de progresso
ms.date: 11/04/2016
helpviewer_keywords:
- CProgressCtrl class [MFC], settings
- progress controls [MFC], settings
ms.assetid: f4616e91-74fa-4000-ba0d-d3ddc0ee075b
ms.openlocfilehash: 1960b15c2f76d7cbfc9f249a77481b795e6a27ea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62307673"
---
# <a name="settings-for-the-progress-control"></a>Configurações para o controle de progresso

As configurações básicas para o controle de progresso ([CProgressCtrl](../mfc/reference/cprogressctrl-class.md)) são o intervalo e a posição atual. O intervalo representa a duração inteira da operação. A posição atual representa o progresso que seu aplicativo fez para concluir a operação. As alterações para o intervalo ou a posição fazem o controle de progresso para redesenhar a mesmo.

Por padrão, o intervalo é definido como 0 - 100 e a posição inicial é definido como 0. Para recuperar as configurações atuais de intervalo para o controle de progresso, use o [GetRange](../mfc/reference/cprogressctrl-class.md#getrange) função de membro. Para alterar o intervalo, use o [SetRange](../mfc/reference/cprogressctrl-class.md#setrange) função de membro.

Para definir a posição, use [SetPos](../mfc/reference/cprogressctrl-class.md#setpos). Para recuperar a posição atual sem especificar um novo valor, use [GetPos](../mfc/reference/cprogressctrl-class.md#getpos). Por exemplo, talvez você queira simplesmente consultar o status da operação atual.

Para depurar a posição atual do controle de progresso, use [StepIt](../mfc/reference/cprogressctrl-class.md#stepit). Para definir a quantidade de cada etapa, use [SetStep](../mfc/reference/cprogressctrl-class.md#setstep)

## <a name="see-also"></a>Consulte também

[Usando CProgressCtrl](../mfc/using-cprogressctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
