---
title: Dando suporte a arrastar e soltar para itens de cabeçalho | Microsoft Docs
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
ms.openlocfilehash: 50cd19d4828269d0591afd0b46768e9917b96906
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="providing-drag-and-drop-support-for-header-items"></a>Dando suporte a arrastar e soltar para itens de cabeçalho
Para fornecer suporte a arrastar e soltar para itens de cabeçalho, especifique o `HDS_DRAGDROP` estilo. Suporte a arrastar e soltar para itens de cabeçalho dá ao usuário a capacidade para reordenar os itens de cabeçalho de um controle de cabeçalho. O comportamento padrão fornece uma imagem de arrastar semitransparente do item de cabeçalho que está sendo arrastado e um indicador visual de que a nova posição, se o item de cabeçalho é descartado.  
  
 Como com a funcionalidade de arrastar e soltar comum, você pode estender o comportamento de arrastar e soltar padrão manipulando o **HDN_BEGINDRAG** e **HDN_ENDDRAG** notificações. Você também pode personalizar a aparência da imagem de arrastar, substituindo o [CHeaderCtrl::CreateDragImage](../mfc/reference/cheaderctrl-class.md#createdragimage) função de membro.  
  
> [!NOTE]
>  Se você fornecer suporte a arrastar e soltar para um controle de cabeçalho inseridos em um controle de lista, consulte a seção estilo estendido a [alterando estilos de controle de lista](../mfc/changing-list-control-styles.md) tópico.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)

