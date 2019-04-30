---
title: Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl
ms.date: 11/04/2016
f1_keywords:
- CToolTipCtrl
helpviewer_keywords:
- tool tips [MFC], creating
- CToolTipCtrl class [MFC], using
ms.assetid: 0a34583f-f66d-46a1-a239-31b80ea395ad
ms.openlocfilehash: b0f008c70eeb43455408e5b0ad302df6b923608e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62411637"
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
