---
title: Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- status bar controls [MFC], creating
- CStatusBarCtrl class [MFC], creating
ms.assetid: 365c2b65-12de-49e6-9a2e-416c6ee10d60
ms.openlocfilehash: 12d5664b9fc59c4569ec2ee7db4ae883911f7bcd
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79442388"
---
# <a name="using-cstatusbarctrl-to-create-a-cstatusbarctrl-object"></a>Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl

Aqui está um exemplo de uso típico de [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md):

### <a name="to-use-a-status-bar-control-with-parts"></a>Para usar um controle da barra de status com partes

1. Construa o objeto `CStatusBarCtrl`.

1. Chame [SetMinHeight](../mfc/reference/cstatusbarctrl-class.md#setminheight) se desejar definir a altura mínima da área de desenho do controle da barra de status.

1. Chame [SetBkColor](../mfc/reference/cstatusbarctrl-class.md#setbkcolor) para definir a cor do plano de fundo do controle da barra de status.

1. Chame [SetParts](../mfc/reference/cstatusbarctrl-class.md#setparts) para definir o número de partes em um controle de barra de status e a coordenada da borda direita de cada parte.

1. Chame [SetText](../mfc/reference/cstatusbarctrl-class.md#settext) para definir o texto em uma determinada parte do controle da barra de status. A mensagem invalida a parte do controle que foi alterada, fazendo com que ela exiba o novo texto quando o próximo controle receber a mensagem de WM_PAINT.

Em alguns casos, a barra de status só precisa exibir uma linha de texto. Nesse caso, faça uma chamada para [SetSimple](../mfc/reference/cstatusbarctrl-class.md#setsimple). Isso coloca o controle da barra de status no modo "simples", que exibe uma única linha de texto.

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
