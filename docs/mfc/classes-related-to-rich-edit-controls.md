---
title: Classes relacionadas a controles de edição avançada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f428242ac84adaf36ea0263f8e193dfeca7d0609
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="classes-related-to-rich-edit-controls"></a>Classes relacionadas a controles de edição avançada
O [CRichEditView](../mfc/reference/cricheditview-class.md), [CRichEditDoc](../mfc/reference/cricheditdoc-class.md), e [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md) classes fornecem a funcionalidade do controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) dentro do contexto de arquitetura de documento/exibição do MFC. `CRichEditView` mantém a característica de formatação de texto e texto. `CRichEditDoc` mantém a lista de itens de cliente OLE que estão no modo de exibição. `CRichEditCntrItem` fornece acesso do lado do contêiner para o item de cliente OLE. Para modificar o conteúdo de um `CRichEditView`, use [CRichEditView::GetRichEditCtrl](../mfc/reference/cricheditview-class.md#getricheditctrl) para acessar a base de controle edição avançada.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

