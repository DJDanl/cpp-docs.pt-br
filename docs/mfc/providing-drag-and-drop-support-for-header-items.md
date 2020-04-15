---
title: Dando suporte a arrastar e soltar para itens de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- HDS_DRAGDROP style
- header items in header controls
- CHeaderCtrl class [MFC], drag and drop support
- HDN_ notifications [MFC]
ms.assetid: 93a152ec-804f-488f-b260-b3a438d0dc0f
ms.openlocfilehash: 8dfaabf3da62c216d3da662f59c57b63e695d9ad
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371157"
---
# <a name="providing-drag-and-drop-support-for-header-items"></a>Dando suporte a arrastar e soltar para itens de cabeçalho

Para fornecer suporte de arrastar e soltar itens de cabeçalho, especifique o estilo HDS_DRAGDROP. O suporte para arrastar e soltar itens de cabeçalho dá ao usuário a capacidade de reordenar os itens de cabeçalho de um controle de cabeçalho. O comportamento padrão fornece uma imagem de arrasto semitransparente do item de cabeçalho sendo arrastado e um indicador visual da nova posição, se o item do cabeçalho for descartado.

Como acontece com a funcionalidade comum de arrastar e soltar, você pode estender o comportamento padrão de arrastar e soltar, manuseando as notificações HDN_BEGINDRAG e HDN_ENDDRAG. Você também pode personalizar a aparência da imagem de arrasto substituindo a função [cheaderctrl::CreateDragImage](../mfc/reference/cheaderctrl-class.md#createdragimage) membro.

> [!NOTE]
> Se você estiver fornecendo suporte para arrastar e soltar para um controle de cabeçalho incorporado em um controle de lista, consulte a seção Estilo estendido no tópico [''''''Estilos de controle de listas'.](../mfc/changing-list-control-styles.md)

## <a name="see-also"></a>Confira também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)
