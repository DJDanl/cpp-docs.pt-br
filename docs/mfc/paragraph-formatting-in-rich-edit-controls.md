---
title: "Formatação de parágrafo em controles de edição avançada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- rich edit controls [MFC], paragraph formatting in
- paragraph formatting in CRichEditCtrl [MFC]
- CRichEditCtrl class [MFC], paragraph formatting in
- formatting [MFC], paragraphs
ms.assetid: 0df2e4c9-2074-4e41-b913-87cb8c1b4d43
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0f0dc12d923f6f424fe84768b0d934d8dd7ff20b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="paragraph-formatting-in-rich-edit-controls"></a>Formatação de parágrafo em controles de edição avançada
Você pode usar funções de membro do controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) para formatar parágrafos e recuperar informações de formatação. Atributos de formatação de parágrafo incluem alinhamento, tabulações, recuos e numeração.  
  
 Você pode aplicar formatação por meio de parágrafo o [SetParaFormat](../mfc/reference/cricheditctrl-class.md#setparaformat) função de membro. Para determinar a formatação do texto selecionado do parágrafo atual, use o [GetParaFormat](../mfc/reference/cricheditctrl-class.md#getparaformat) função de membro. O [PARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787940) com essas funções de membro, a estrutura é usada para especificar atributos de parágrafo. Um dos membros importantes do **PARAFORMAT** é **dwMask**. Em `SetParaFormat`, **dwMask** Especifica quais atributos de parágrafo serão definidos pela chamada de função. `GetParaFormat`informa os atributos do primeiro parágrafo na seleção. **dwMask** Especifica os atributos que estão consistentes em toda a seleção.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

