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
ms.openlocfilehash: 584649a2bb2d9a118e390aebf9f7411c3123b1a3
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620720"
---
# <a name="classes-related-to-rich-edit-controls"></a>Classes relacionadas a controles de edição avançada

As classes [CRichEditView](reference/cricheditview-class.md), [CRichEditDoc](reference/cricheditdoc-class.md)e [CRichEditCntrItem](reference/cricheditcntritem-class.md) fornecem a funcionalidade do[CRichEditCtrl](reference/cricheditctrl-class.md)(Rich Edit Control) no contexto da arquitetura de documento/exibição do MFC. `CRichEditView`mantém a característica de texto e formatação do texto. `CRichEditDoc`mantém a lista de itens de cliente OLE que estão na exibição. `CRichEditCntrItem`fornece acesso do lado do contêiner ao item do cliente OLE. Para modificar o conteúdo de um `CRichEditView` , use [CRichEditView:: GetRichEditCtrl](reference/cricheditview-class.md#getricheditctrl) para acessar o controle de edição rica subjacente.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](using-cricheditctrl.md)<br/>
[Controles](controls-mfc.md)
