---
title: Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- tool tips [MFC], creating
- CToolTipCtrl class [MFC], using
ms.assetid: 0a34583f-f66d-46a1-a239-31b80ea395ad
ms.openlocfilehash: 37dc7bc5a411ebab3737b87fd6977b26cff68178
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79442210"
---
# <a name="using-ctooltipctrl-to-create-and-manipulate-a-ctooltipctrl-object"></a>Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl

Aqui está um exemplo de uso de [CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md) :

### <a name="to-create-and-manipulate-a-ctooltipctrl"></a>Para criar e manipular um CToolTipCtrl

1. Construa o objeto `CToolTipCtrl`.

1. Chame [Create](../mfc/reference/ctooltipctrl-class.md#create) para criar o controle comum de dica de ferramenta do Windows e anexe-o ao objeto `CToolTipCtrl`.

1. Chame [AddTool](../mfc/reference/ctooltipctrl-class.md#addtool) para registrar uma ferramenta com o controle de dica de ferramenta, para que as informações armazenadas na dica de ferramenta sejam exibidas quando o cursor estiver na ferramenta.

1. Chame [SetToolInfo](../mfc/reference/ctooltipctrl-class.md#settoolinfo) para definir as informações que uma dica de ferramenta mantém para uma ferramenta.

1. Chame [SetToolRect](../mfc/reference/ctooltipctrl-class.md#settoolrect) para definir um novo retângulo delimitador para uma ferramenta.

1. Chame o [HitTest](../mfc/reference/ctooltipctrl-class.md#hittest) para testar um ponto para determinar se ele está dentro do retângulo delimitador da ferramenta especificada e, em caso afirmativo, recuperar informações sobre a ferramenta.

1. Chame [GetToolCount](../mfc/reference/ctooltipctrl-class.md#gettoolcount) para recuperar uma contagem das ferramentas registradas com o controle de dica de ferramenta.

## <a name="see-also"></a>Consulte também

[Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
