---
title: Classes relacionadas a controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- rich edit controls [MFC], and CRichEditItem
- CRichEditCtrl class [MFC], related classes
- CRichEditDoc class [MFC], Rich Edit controls
- rich edit controls [MFC], classes related to
- classes [MFC], related to rich edit controls
- rich edit controls [MFC], and CRichEditView
- CRichEditCtrlItem class and CRichEditCtrl
- rich edit controls [MFC], and CRichEditDoc
- CRichEditView class [MFC], and CRichEditCtrl
ms.assetid: 4b31c2cc-6ea1-4146-b7c5-b0b5b419f14d
ms.openlocfilehash: 92134d0bd4d02bff7aeadd5e9ca7438c61de3bec
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50586154"
---
# <a name="classes-related-to-rich-edit-controls"></a>Classes relacionadas a controles de edição avançada

O [CRichEditView](../mfc/reference/cricheditview-class.md), [CRichEditDoc](../mfc/reference/cricheditdoc-class.md), e [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md) classes fornecem a funcionalidade do controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) dentro do contexto da arquitetura de documento/exibição do MFC. `CRichEditView` mantém o texto e as características de formatação de texto. `CRichEditDoc` mantém a lista de itens de cliente OLE que estão no modo de exibição. `CRichEditCntrItem` fornece acesso de lado do contêiner para o item de cliente OLE. Para modificar o conteúdo de um `CRichEditView`, use [CRichEditView::GetRichEditCtrl](../mfc/reference/cricheditview-class.md#getricheditctrl) acessar subjacente controle edição avançada.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

