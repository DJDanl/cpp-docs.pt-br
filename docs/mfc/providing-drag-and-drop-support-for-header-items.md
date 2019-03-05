---
title: Dando suporte a arrastar e soltar para itens de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- HDS_DRAGDROP style
- header items in header controls
- CHeaderCtrl class [MFC], drag and drop support
- HDN_ notifications [MFC]
ms.assetid: 93a152ec-804f-488f-b260-b3a438d0dc0f
ms.openlocfilehash: f30ad029742a01280abda85cbd1a81104d01d8cd
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57263707"
---
# <a name="providing-drag-and-drop-support-for-header-items"></a>Dando suporte a arrastar e soltar para itens de cabeçalho

Para oferecer suporte a arrastar e soltar para itens de cabeçalho, especifique o estilo HDS_DRAGDROP. Suporte de arrastar e soltar para itens de cabeçalho fornece ao usuário a capacidade de reordenar os itens de cabeçalho de um controle de cabeçalho. O comportamento padrão fornece uma imagem de arrastar semitransparente do item de cabeçalho que estão sendo arrastado e um indicador visual da nova posição, se o item de cabeçalho é descartado.

Como com funcionalidade comum de arrastar e soltar, você pode estender o comportamento de arrastar e soltar do padrão ao manipular as notificações de HDN_BEGINDRAG e HDN_ENDDRAG. Você também pode personalizar a aparência da imagem de arrastar, substituindo o [CHeaderCtrl::CreateDragImage](../mfc/reference/cheaderctrl-class.md#createdragimage) função de membro.

> [!NOTE]
>  Se você estiver fornecendo suporte a arrastar e soltar para um controle de cabeçalho incorporado em um controle de lista, consulte a seção estilo estendido a [alterando estilos de controle de lista](../mfc/changing-list-control-styles.md) tópico.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)
