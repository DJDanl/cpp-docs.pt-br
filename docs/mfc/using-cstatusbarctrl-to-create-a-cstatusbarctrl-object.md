---
title: Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl
ms.date: 11/04/2016
f1_keywords:
- CStatusBarCtrl
helpviewer_keywords:
- status bar controls [MFC], creating
- CStatusBarCtrl class [MFC], creating
ms.assetid: 365c2b65-12de-49e6-9a2e-416c6ee10d60
ms.openlocfilehash: 05baf212f53956095af89377c0877db79b6e25ee
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50552757"
---
# <a name="using-cstatusbarctrl-to-create-a-cstatusbarctrl-object"></a>Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl

Aqui está um exemplo de um uso típico [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md):

### <a name="to-use-a-status-bar-control-with-parts"></a>Para usar um controle de barra de status com partes

1. Construir o `CStatusBarCtrl` objeto.

1. Chame [SetMinHeight](../mfc/reference/cstatusbarctrl-class.md#setminheight) se você deseja definir a altura mínima de controle de barra de status da área de desenho.

1. Chame [SetBkColor](../mfc/reference/cstatusbarctrl-class.md#setbkcolor) para definir a cor do plano de fundo do controle de barra de status.

1. Chame [SetParts](../mfc/reference/cstatusbarctrl-class.md#setparts) para definir o número de partes em um controle e a coordenada da borda direita de cada parte da barra de status.

1. Chame [SetText](../mfc/reference/cstatusbarctrl-class.md#settext) para definir o texto em uma determinada parte do controle de barra de status. A mensagem invalida a parte do controle que foi alterado, fazendo com que ele exibir o novo texto quando o controle, em seguida, recebe a mensagem WM_PAINT.

Em alguns casos, a barra de status só precisa para exibir uma linha de texto. Nesse caso, fazer uma chamada para [SetSimple](../mfc/reference/cstatusbarctrl-class.md#setsimple). Isso coloca o controle de barra de status no modo "simples", que exibe uma única linha de texto.

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

