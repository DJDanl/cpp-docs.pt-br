---
title: Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CStatusBarCtrl
dev_langs:
- C++
helpviewer_keywords:
- status bar controls [MFC], creating
- CStatusBarCtrl class [MFC], creating
ms.assetid: 365c2b65-12de-49e6-9a2e-416c6ee10d60
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3c68603eff0393d76af4e0617548e5bf1dd4aa63
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46413674"
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

