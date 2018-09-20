---
title: Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CToolTipCtrl
dev_langs:
- C++
helpviewer_keywords:
- tool tips [MFC], creating
- CToolTipCtrl class [MFC], using
ms.assetid: 0a34583f-f66d-46a1-a239-31b80ea395ad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 186972164496889b471ebfc11e19017129ad943b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378976"
---
# <a name="using-ctooltipctrl-to-create-and-manipulate-a-ctooltipctrl-object"></a>Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl

Aqui está um exemplo de [CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md) uso:

### <a name="to-create-and-manipulate-a-ctooltipctrl"></a>Para criar e manipular um CToolTipCtrl

1. Construir o `CToolTipCtrl` objeto.

1. Chame [Create](../mfc/reference/ctooltipctrl-class.md#create) para criar o controle comum de dica de ferramenta Windows e anexá-lo para o `CToolTipCtrl` objeto.

1. Chame [AddTool](../mfc/reference/ctooltipctrl-class.md#addtool) para registrar uma ferramenta com o controle da dica de ferramenta, para que as informações armazenadas na dica de ferramenta são exibidas quando o cursor estiver sobre a ferramenta.

1. Chame [SetToolInfo](../mfc/reference/ctooltipctrl-class.md#settoolinfo) para definir as informações que uma dica de ferramenta mantém para uma ferramenta.

1. Chame [SetToolRect](../mfc/reference/ctooltipctrl-class.md#settoolrect) para definir um novo retângulo delimitador para uma ferramenta.

1. Chame [HitTest](../mfc/reference/ctooltipctrl-class.md#hittest) para testar um ponto para determinar se ele está dentro do retângulo delimitador da ferramenta determinado e, nesse caso, recuperar informações sobre a ferramenta.

1. Chame [GetToolCount](../mfc/reference/ctooltipctrl-class.md#gettoolcount) recuperar uma contagem das ferramentas registrado com o controle da dica de ferramenta.

## <a name="see-also"></a>Consulte também

[Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

