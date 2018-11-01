---
title: Dando suporte a arrastar e soltar para itens de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- HDS_DRAGDROP style
- header items in header controls
- CHeaderCtrl class [MFC], drag and drop support
- HDN_ notifications [MFC]
ms.assetid: 93a152ec-804f-488f-b260-b3a438d0dc0f
ms.openlocfilehash: 21ff14982baac93fac1cf3ee441353c079f4f760
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602963"
---
# <a name="providing-drag-and-drop-support-for-header-items"></a>Dando suporte a arrastar e soltar para itens de cabeçalho

Para oferecer suporte a arrastar e soltar para itens de cabeçalho, especifique o estilo HDS_DRAGDROP. Suporte de arrastar e soltar para itens de cabeçalho fornece ao usuário a capacidade de reordenar os itens de cabeçalho de um controle de cabeçalho. O comportamento padrão fornece uma imagem de arrastar semitransparente do item de cabeçalho que estão sendo arrastado e um indicador visual da nova posição, se o item de cabeçalho é descartado.

Como com funcionalidade comum de arrastar e soltar, você pode estender o comportamento de arrastar e soltar do padrão ao manipular as notificações de HDN_BEGINDRAG e HDN_ENDDRAG. Você também pode personalizar a aparência da imagem de arrastar, substituindo o [CHeaderCtrl::CreateDragImage](../mfc/reference/cheaderctrl-class.md#createdragimage) função de membro.

> [!NOTE]
>  Se você estiver fornecendo suporte a arrastar e soltar para um controle de cabeçalho incorporado em um controle de lista, consulte a seção estilo estendido a [alterando estilos de controle de lista](../mfc/changing-list-control-styles.md) tópico.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)

