---
title: Fornecendo suporte de arrastar e soltar para itens de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- HDS_DRAGDROP style
- header items in header controls
- CHeaderCtrl class [MFC], drag and drop support
- HDN_ notifications [MFC]
ms.assetid: 93a152ec-804f-488f-b260-b3a438d0dc0f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b2eaa5040d34a442868a8fa6cb9f2aae08b0a6f3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407693"
---
# <a name="providing-drag-and-drop-support-for-header-items"></a>Dando suporte a arrastar e soltar para itens de cabeçalho

Para oferecer suporte a arrastar e soltar para itens de cabeçalho, especifique o estilo HDS_DRAGDROP. Suporte de arrastar e soltar para itens de cabeçalho fornece ao usuário a capacidade de reordenar os itens de cabeçalho de um controle de cabeçalho. O comportamento padrão fornece uma imagem de arrastar semitransparente do item de cabeçalho que estão sendo arrastado e um indicador visual da nova posição, se o item de cabeçalho é descartado.

Como com funcionalidade comum de arrastar e soltar, você pode estender o comportamento de arrastar e soltar do padrão ao manipular as notificações de HDN_BEGINDRAG e HDN_ENDDRAG. Você também pode personalizar a aparência da imagem de arrastar, substituindo o [CHeaderCtrl::CreateDragImage](../mfc/reference/cheaderctrl-class.md#createdragimage) função de membro.

> [!NOTE]
>  Se você estiver fornecendo suporte a arrastar e soltar para um controle de cabeçalho incorporado em um controle de lista, consulte a seção estilo estendido a [alterando estilos de controle de lista](../mfc/changing-list-control-styles.md) tópico.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)

