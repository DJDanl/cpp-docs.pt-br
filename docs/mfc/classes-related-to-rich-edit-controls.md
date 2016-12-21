---
title: "Classes relacionadas a controles de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++], relacionado a controles de edição avançada"
  - "Classe CRichEditCtrl, classes relacionadas"
  - "Classe CRichEditCtrlItem e CRichEditCtrl"
  - "Classe CRichEditDoc, Controles de Edição Avançada"
  - "Classe CRichEditView, e CRichEditCtrl"
  - "controles de edição avançada, e CRichEditDoc"
  - "controles de edição avançada, e CRichEditItem"
  - "controles de edição avançada, e CRichEditView"
  - "controles de edição avançada, classes relacionadas a"
ms.assetid: 4b31c2cc-6ea1-4146-b7c5-b0b5b419f14d
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes relacionadas a controles de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[CRichEditView](../mfc/reference/cricheditview-class.md), [CRichEditDoc](../mfc/reference/cricheditdoc-class.md), e as classes de [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md) fornecem a funcionalidade de controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\) no contexto do documento MFC\/arquitetura de exibição.  `CRichEditView` mantém a característica de texto e formatação de texto.  `CRichEditDoc` mantém a lista de itens com OLE DB do cliente que estão na exibição.  `CRichEditCntrItem` fornece acesso ao item do lado do cliente OLE.  Para alterar o conteúdo de `CRichEditView`, use [CRichEditView::GetRichEditCtrl](../Topic/CRichEditView::GetRichEditCtrl.md) para acessar o controle de edição rico subjacente.  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)