---
title: Formatação de parágrafo em controles de edição avançada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- rich edit controls [MFC], paragraph formatting in
- paragraph formatting in CRichEditCtrl [MFC]
- CRichEditCtrl class [MFC], paragraph formatting in
- formatting [MFC], paragraphs
ms.assetid: 0df2e4c9-2074-4e41-b913-87cb8c1b4d43
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8258ff95fc91f6f29d424e77be95ce1b44f621ac
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215815"
---
# <a name="paragraph-formatting-in-rich-edit-controls"></a>Formatação de parágrafo em controles de edição avançada
Você pode usar funções de membro do controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) para formatar parágrafos e recuperar informações de formatação. Atributos de formatação de parágrafo incluem alinhamento, guias, recuos e numeração.  
  
 Você pode aplicar formatação por meio de parágrafo a [SetParaFormat](../mfc/reference/cricheditctrl-class.md#setparaformat) função de membro. Para determinar a formatação para o texto selecionado do parágrafo atual, use o [GetParaFormat](../mfc/reference/cricheditctrl-class.md#getparaformat) função de membro. O [PARAFORMAT](/windows/desktop/api/richedit/ns-richedit-_paraformat) com essas funções de membro, a estrutura é usada para especificar atributos de parágrafo. Um dos membros importantes da **PARAFORMAT** é *dwMask*. Na `SetParaFormat`, *dwMask* Especifica quais atributos de parágrafo serão definidos por essa chamada de função. `GetParaFormat` informa os atributos do primeiro parágrafo na seleção; *dwMask* Especifica os atributos que são consistentes em toda a seleção.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

